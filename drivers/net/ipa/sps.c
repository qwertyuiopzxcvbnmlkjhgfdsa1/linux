// SPDX-License-Identifier: GPL-2.0

/* Copyright (c) 2020, The Linux Foundation. All rights reserved.
 */

#include <linux/types.h>
#include <linux/bits.h>
#include <linux/bitfield.h>
#include <linux/dma-mapping.h>
#include <linux/dmaengine.h>
#include <linux/dma/qcom_bam_dma.h>
#include <linux/mutex.h>
#include <linux/completion.h>
#include <linux/io.h>
#include <linux/bug.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/netdevice.h>

#include "sps.h"
#include "ipa_gsi.h"
#include "sps_trans.h"
#include "ipa_trans.h"
#include "ipa_data.h"

/**
 * DOC: The IPA Smart Peripheral System Interface
 *
 * The Smart Peripheral System is a means to communicate over BAM pipes to
 * the IPA block. The Modem also uses BAM pipes to communicate with the IPA
 * core.
 *
 * Refer the GSI documentation, because SPS is a precursor to GSI and more or less
 * the same, conceptually (maybe, IDK, I have no docs to go through).
 *
 * Each channel here corresponds to 1 BAM pipe configured in BAM2BAM mode
 *
 * IPA cmds are transferred one at a time, each in one BAM transfer.
 */

/* Get and configure the BAM DMA channel */
int sps_channel_init_one(struct sps *sps,
				const struct ipa_gsi_endpoint_data *data,
				bool command)
{
	struct dma_slave_config sps_config;
	u32 channel_id = data->channel_id;
	struct sps_channel *channel = &sps->channel[channel_id];
	int ret;

	/*TODO: if (!sps_channel_data_valid(sps, data))
		return -EINVAL;*/

	channel->chan = dma_request_chan(sps->dev,
			data->channel_name);
	if (IS_ERR(channel->chan)) {
		dev_err(sps->dev, "failed to request SPS channel %s: %d\n",
				data->channel_name,
				(int) PTR_ERR(channel->chan));
		return PTR_ERR(channel->chan);
	}

	ret = sps_channel_trans_init(sps, data->channel_id);
	if (ret)
		goto err_dma_chan_free;

	sps_config.direction = data->toward_ipa ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM;
	sps_config.src_maxburst = SPS_MAX_BURST_SIZE;

	channel->toward_ipa = data->toward_ipa;

	dmaengine_slave_config(channel->chan, &sps_config);

	if (command)
		ret = ipa_cmd_pool_init(sps->dev, &channel->trans_info, 256, 20);

	if (!ret)
		return 0;

err_dma_chan_free:
	dma_release_channel(channel->chan);
	return ret;
}

static void sps_channel_exit_one(struct sps_channel* channel)
{
	if (!channel->chan)
		return;
	dmaengine_terminate_sync(channel->chan);
	dma_release_channel(channel->chan);
}

/* Get channels from BAM_DMA */
int sps_channel_init(struct sps *sps, u32 count,
		const struct ipa_gsi_endpoint_data *data)
{
	int ret = 0;
	u32 i;

	for (i = 0; i < count; ++i) {
		bool command = i == IPA_ENDPOINT_AP_COMMAND_TX;

		if (!data[i].channel_name || data[i].ee_id == GSI_EE_MODEM)
			continue;

		ret = sps_channel_init_one(sps, &data[i], command);
		if (ret)
			goto err_unwind;
	}

	return ret;

err_unwind:
	while (i--) {
		if (ipa_gsi_endpoint_data_empty(&data[i]))
			continue;

		sps_channel_exit_one(&sps->channel[i]);
	}
	return ret;
}

/* Inverse of sps_channel_init() */
void sps_channel_exit(struct sps *sps)
{
	u32 channel_id = SPS_CHANNEL_COUNT_MAX - 1;

	do
		sps_channel_exit_one(&sps->channel[channel_id]);
	while (channel_id--);
}

/* Initialize the BAM DMA channels
 * Actual hw init is handled by the BAM_DMA driver
 */
int sps_init(struct sps *sps, struct platform_device *pdev, u32 count,
		const struct ipa_gsi_endpoint_data *data)
{
	int ret;
	struct device *dev = &pdev->dev;

	sps->dev = dev;
	init_dummy_netdev(&sps->dummy_dev);

	ret = sps_channel_init(sps, count, data);
	if (ret)
		return ret;

	mutex_init(&sps->mutex);

	return 0;
}

/* Inverse of sps_init() */
void sps_exit(struct sps *sps)
{
	mutex_destroy(&sps->mutex);
	sps_channel_exit(sps);
}

/* Return the oldest completed transaction for a channel (or null) */
struct ipa_trans *sps_channel_trans_complete(struct sps_channel *channel)
{
	return list_first_entry_or_null(&channel->trans_info.complete,
					struct ipa_trans, links);
}

/* Return the channel id associated with a given channel */
static u32 sps_channel_id(struct sps_channel *channel)
{
	return channel - &channel->sps->channel[0];
}

static void
sps_channel_tx_update(struct sps_channel *channel, struct ipa_trans *trans)
{
	u64 byte_count = trans->byte_count + trans->len;
	u64 trans_count = trans->trans_count + 1;

	byte_count -= channel->compl_byte_count;
	channel->compl_byte_count += byte_count;
	trans_count -= channel->compl_trans_count;
	channel->compl_trans_count += trans_count;

	ipa_sps_channel_tx_completed(channel->sps, sps_channel_id(channel),
				     trans_count, byte_count);
}

static void
sps_channel_rx_update(struct sps_channel *channel, struct ipa_trans *trans)
{
	/* FIXME */
	u64 byte_count = trans->byte_count + trans->len;

	channel->byte_count += byte_count;
	channel->trans_count++;
}

/* Consult hardware, move any newly completed transactions to completed list */
static void sps_channel_update(struct sps_channel *channel)
{
	struct ipa_trans *trans;

	list_for_each_entry(trans, &channel->trans_info.pending, links) {
		enum dma_status trans_status =
				dma_async_is_tx_complete(channel->chan,
					trans->cookie, NULL, NULL);
		if (trans_status == DMA_COMPLETE)
			break;
	}

	/* Get the transaction for the latest completed event.  Take a
	 * reference to keep it from completing before we give the events
	 * for this and previous transactions back to the hardware.
	 */
	refcount_inc(&trans->refcount);

	/* For RX channels, update each completed transaction with the number
	 * of bytes that were actually received.  For TX channels, report
	 * the number of transactions and bytes this completion represents
	 * up the network stack.
	 */
	if (channel->toward_ipa)
		sps_channel_tx_update(channel, trans);
	else
		sps_channel_rx_update(channel, trans);

	ipa_trans_move_complete(trans);

	ipa_trans_free(trans);
}

/**
 * sps_channel_poll_one() - Return a single completed transaction on a channel
 * @channel:	Channel to be polled
 *
 * Return:	Transaction pointer, or null if none are available
 *
 * This function returns the first entry on a channel's completed transaction
 * list.  If that list is empty, the hardware is consulted to determine
 * whether any new transactions have completed.  If so, they're moved to the
 * completed list and the new first entry is returned.  If there are no more
 * completed transactions, a null pointer is returned.
 */
static struct ipa_trans *sps_channel_poll_one(struct sps_channel *channel)
{
	struct ipa_trans *trans;

	/* Get the first transaction from the completed list */
	trans = sps_channel_trans_complete(channel);
	if (!trans) {
		sps_channel_update(channel);
		trans = sps_channel_trans_complete(channel);
	}

	if (trans)
		ipa_trans_move_polled(trans);

	return trans;
}

/**
 * sps_channel_poll() - NAPI poll function for a channel
 * @napi:	NAPI structure for the channel
 * @budget:	Budget supplied by NAPI core
 *
 * Return:	Number of items polled (<= budget)
 *
 * Single transactions completed by hardware are polled until either
 * the budget is exhausted, or there are no more.  Each transaction
 * polled is passed to ipa_trans_complete(), to perform remaining
 * completion processing and retire/free the transaction.
 */
static int sps_channel_poll(struct napi_struct *napi, int budget)
{
	struct sps_channel *channel;
	int count = 0;

	channel = container_of(napi, struct sps_channel, napi);
	while (count < budget) {
		struct ipa_trans *trans;

		count++;
		trans = sps_channel_poll_one(channel);
		if (!trans)
			break;
		ipa_trans_complete(trans);
	}

	if (count < budget)
		napi_complete(&channel->napi);

	return count;
}


/* Setup function for a single channel */
static void sps_channel_setup_one(struct sps *sps, u32 channel_id)
{
	struct sps_channel *channel = &sps->channel[channel_id];

	if (!channel->sps)
		return;	/* Ignore uninitialized channels */

	if (channel->toward_ipa)
		netif_tx_napi_add(&sps->dummy_dev, &channel->napi,
				  sps_channel_poll, NAPI_POLL_WEIGHT);
	else
		netif_napi_add(&sps->dummy_dev, &channel->napi,
			       sps_channel_poll, NAPI_POLL_WEIGHT);

	napi_enable(&channel->napi);
	/*TODO: investigate NAPI */
}

static void sps_channel_teardown_one(struct sps *sps, u32 channel_id)
{
	struct sps_channel *channel = &sps->channel[channel_id];

	if (!channel->sps)
		return;		/* Ignore uninitialized channels */

	netif_napi_del(&channel->napi);
}

/* Setup function for channels */
static int sps_channel_setup(struct sps *sps)
{
	u32 channel_id = 0;
	int ret;

	mutex_lock(&sps->mutex);

	do
		sps_channel_setup_one(sps, channel_id);
	while (++channel_id < SPS_CHANNEL_COUNT_MAX);

	/* Make sure no channels were defined that hardware does not support */
	while (channel_id < SPS_CHANNEL_COUNT_MAX) {
		struct sps_channel *channel = &sps->channel[channel_id++];

		if (!channel->sps)
			continue;	/* Ignore uninitialized channels */

		dev_err(sps->dev, "channel %u not supported by hardware\n",
			channel_id - 1);
		channel_id = SPS_CHANNEL_COUNT_MAX;
		goto err_unwind;
	}

	mutex_unlock(&sps->mutex);

	return 0;

err_unwind:
	while (channel_id--)
		sps_channel_teardown_one(sps, channel_id);

	mutex_unlock(&sps->mutex);

	return ret;
}

/* Inverse of sps_channel_setup() */
static void sps_channel_teardown(struct sps *sps)
{
	u32 channel_id;

	mutex_lock(&sps->mutex);

	channel_id = SPS_CHANNEL_COUNT_MAX;
	do
		sps_channel_teardown_one(sps, channel_id);
	while (channel_id--);

	mutex_unlock(&sps->mutex);
}

int sps_setup(struct sps *sps)
{
	return sps_channel_setup(sps);
}

void sps_teardown(struct sps *sps)
{
	sps_channel_teardown(sps);
}

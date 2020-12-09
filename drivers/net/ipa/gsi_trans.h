/* SPDX-License-Identifier: GPL-2.0 */

/* Copyright (c) 2012-2018, The Linux Foundation. All rights reserved.
 * Copyright (C) 2019-2020 Linaro Ltd.
 */
#ifndef _GSI_TRANS_H_
#define _GSI_TRANS_H_

#include <linux/types.h>
#include <linux/refcount.h>
#include <linux/completion.h>
#include <linux/dma-direction.h>

#include "gsi.h"
#include "ipa_cmd.h"

struct scatterlist;
struct device;
struct sk_buff;

struct gsi;
struct gsi_trans_pool;

/**
 * struct gsi_trans - a GSI transaction
 *
 * Most fields in this structure for internal use by the transaction core code:
 * @links:	Links for channel transaction lists by state
 * @gsi:	GSI pointer
 * @channel_id: Channel number transaction is associated with
 * @cancelled:	If set by the core code, transaction was cancelled
 * @tre_count:	Number of TREs reserved for this transaction
 * @used:	Number of TREs *used* (could be less than tre_count)
 * @len:	Total # of transfer bytes represented in sgl[] (set by core)
 * @data:	Preserved but not touched by the core transaction code
 * @sgl:	An array of scatter/gather entries managed by core code
 * @info:	Array of command information structures (command channel)
 * @direction:	DMA transfer direction (DMA_NONE for commands)
 * @refcount:	Reference count used for destruction
 * @completion:	Completed when the transaction completes
 * @byte_count:	TX channel byte count recorded when transaction committed
 * @trans_count: Channel transaction count when committed (for BQL accounting)
 *
 * The size used for some fields in this structure were chosen to ensure
 * the full structure size is no larger than 128 bytes.
 */
#if 0
struct gsi_trans {
	struct list_head links;		/* gsi_channel lists */

	struct gsi *gsi;
	u8 channel_id;

	bool cancelled;			/* true if transaction was cancelled */

	u8 tre_count;			/* # TREs requested */
	u8 used;			/* # entries used in sgl[] */
	u32 len;			/* total # bytes across sgl[] */

	void *data;
	struct scatterlist *sgl;
	struct ipa_cmd_info *info;	/* array of entries, or null */
	enum dma_data_direction direction;

	refcount_t refcount;
	struct completion completion;

	u64 byte_count;			/* channel byte_count when committed */
	u64 trans_count;		/* channel trans_count when committed */
};
#endif

/**
 * gsi_channel_trans_alloc() - Allocate a GSI transaction on a channel
 * @gsi:	GSI pointer
 * @channel_id:	Channel the transaction is associated with
 * @tre_count:	Number of elements in the transaction
 * @direction:	DMA direction for entire SGL (or DMA_NONE)
 *
 * Return:	A GSI transaction structure, or a null pointer if all
 *		available transactions are in use
 */
struct ipa_trans *gsi_channel_trans_alloc(struct gsi *gsi, u32 channel_id,
					  u32 tre_count,
					  enum dma_data_direction direction);

/**
 * gsi_trans_free() - Free a previously-allocated GSI transaction
 * @trans:	Transaction to be freed
 */
void gsi_trans_free(struct ipa_trans *trans);

/**
 * gsi_trans_commit() - Commit a GSI transaction
 * @trans:	Transaction to commit
 * @ring_db:	Whether to tell the hardware about these queued transfers
 */
void gsi_trans_commit(struct ipa_trans *trans, bool ring_db);

/**
 * gsi_trans_commit_wait() - Commit a GSI transaction and wait for it
 *			     to complete
 * @trans:	Transaction to commit
 */
void gsi_trans_commit_wait(struct ipa_trans *trans);

/**
 * gsi_trans_commit_wait_timeout() - Commit a GSI transaction and wait for
 *				     it to complete, with timeout
 * @trans:	Transaction to commit
 * @timeout:	Timeout period (in milliseconds)
 */
int gsi_trans_commit_wait_timeout(struct ipa_trans *trans,
				  unsigned long timeout);

/**
 * gsi_trans_read_byte() - Issue a single byte read TRE on a channel
 * @gsi:	GSI pointer
 * @channel_id:	Channel on which to read a byte
 * @addr:	DMA address into which to transfer the one byte
 *
 * This is not a transaction operation at all.  It's defined here because
 * it needs to be done in coordination with other transaction activity.
 */
int gsi_trans_read_byte(struct gsi *gsi, u32 channel_id, dma_addr_t addr);

/**
 * gsi_trans_read_byte_done() - Clean up after a single byte read TRE
 * @gsi:	GSI pointer
 * @channel_id:	Channel on which byte was read
 *
 * This function needs to be called to signal that the work related
 * to reading a byte initiated by gsi_trans_read_byte() is complete.
 */
void gsi_trans_read_byte_done(struct gsi *gsi, u32 channel_id);

void gsi_trans_tre_release(struct ipa_trans_info *trans_info, u32 tre_count);

#endif /* _GSI_TRANS_H_ */

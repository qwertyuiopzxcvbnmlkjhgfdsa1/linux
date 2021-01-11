/* SPDX-License-Identifier: GPL-2.0 */

/* Copyright (c) 2018, The Linux Foundation. All rights reserved.
 * Copyright (C) 2018-2020 Linaro Ltd.
 */
#ifndef _IPA_QMI_MSG_H_
#define _IPA_QMI_MSG_H_

/* === Only "ipa_qmi" and "ipa_qmi_msg.c" should include this file === */

#include <linux/types.h>
#include <linux/soc/qcom/qmi.h>

/* Request/response/indication QMI message ids used for IPA.  Receiving
 * end issues a response for requests; indications require no response.
 */
#define IPA_QMI_INDICATION_REGISTER	0x20	/* modem -> AP request */
#define IPA_QMI_INIT_DRIVER		0x21	/* AP -> modem request */
#define IPA_QMI_INIT_COMPLETE		0x22	/* AP -> modem indication */
#define IPA_QMI_DRIVER_INIT_COMPLETE	0x35	/* modem -> AP request */
#define IPA_QMI_CONFIG_REQUEST		0x27	/* modem -> AP request */
#define IPA_QMI_INSTALL_FILTER_RULE	0x23	/* modem -> AP request */
#define IPA_QMI_NOTIFY_FILTER_INSTALLED	0x24	/* modem -> AP request */

/* The maximum size required for message types.  These sizes include
 * the message data, along with type (1 byte) and length (2 byte)
 * information for each field.  The qmi_send_*() interfaces require
 * the message size to be provided.
 */
#define IPA_QMI_INDICATION_REGISTER_REQ_SZ	12	/* -> server handle */
#define IPA_QMI_INDICATION_REGISTER_RSP_SZ	7	/* <- server handle */
#define IPA_QMI_INIT_DRIVER_REQ_SZ		162	/* client handle -> */
#define IPA_QMI_INIT_DRIVER_RSP_SZ		25	/* client handle <- */
#define IPA_QMI_INIT_COMPLETE_IND_SZ		7	/* <- server handle */
#define IPA_QMI_DRIVER_INIT_COMPLETE_REQ_SZ	4	/* -> server handle */
#define IPA_QMI_DRIVER_INIT_COMPLETE_RSP_SZ	7	/* <- server handle */
#define IPA_QMI_CONFIG_REQ_SZ			102
#define IPA_QMI_CONFIG_RSP_SZ			7
#define IPA_QMI_INSTALL_FILTER_RULE_REQ_SZ	22369
#define IPA_QMI_INSTALL_FILTER_RULE_RSP_SZ	783
#define IPA_QMI_NOTIFY_FILTER_INSTALLED_REQ_SZ	870
#define IPA_QMI_NOTIFY_FILTER_INSTALLED_RSP_SZ	7

/* Maximum size of messages we expect the AP to receive (max of above) */
#define IPA_QMI_SERVER_MAX_RCV_SZ		8
#define IPA_QMI_CLIENT_MAX_RCV_SZ		25

#define QMI_IPA_IPFLTR_NUM_IHL_RANGE_16_EQNS_V01	2
#define QMI_IPA_IPFLTR_NUM_MEQ_32_EQNS_V01		2
#define QMI_IPA_IPFLTR_NUM_IHL_MEQ_32_EQNS_V01		2
#define QMI_IPA_IPFLTR_NUM_MEQ_128_EQNS_V01		2
#define QMI_IPA_MAX_FILTERS_V01				64
#define QMI_IPA_MAX_FILTERS_EX_V01			128
#define QMI_IPA_MAX_PIPES_V01				20
#define QMI_IPA_MAX_APN_V01				8
#define QMI_IPA_MAX_PER_CLIENTS_V01			64

/* Currently max we can use is only 1. But for scalability purpose
 * we are having max value as 8.
 */
#define QMI_IPA_MAX_CLIENT_DST_PIPES_V01 8
#define QMI_IPA_MAX_UL_FIREWALL_RULES_V01 64
/* Request message for the IPA_QMI_INDICATION_REGISTER request */
struct ipa_indication_register_req {
	u8 master_driver_init_complete_valid;
	u8 master_driver_init_complete;
	u8 data_usage_quota_reached_valid;
	u8 data_usage_quota_reached;
	u8 ipa_mhi_ready_ind_valid;
	u8 ipa_mhi_ready_ind;
};

/* The response to a IPA_QMI_INDICATION_REGISTER request consists only of
 * a standard QMI response.
 */
struct ipa_indication_register_rsp {
	struct qmi_response_type_v01 rsp;
};

/* Request message for the IPA_QMI_DRIVER_INIT_COMPLETE request */
struct ipa_driver_init_complete_req {
	u8 status;
};

/* The response to a IPA_QMI_DRIVER_INIT_COMPLETE request consists only
 * of a standard QMI response.
 */
struct ipa_driver_init_complete_rsp {
	struct qmi_response_type_v01 rsp;
};

/* The message for the IPA_QMI_INIT_COMPLETE_IND indication consists
 * only of a standard QMI response.
 */
struct ipa_init_complete_ind {
	struct qmi_response_type_v01 status;
};

/* The AP tells the modem its platform type.  We assume Android. */
enum ipa_platform_type {
	IPA_QMI_PLATFORM_TYPE_INVALID		= 0x0,	/* Invalid */
	IPA_QMI_PLATFORM_TYPE_TN		= 0x1,	/* Data card */
	IPA_QMI_PLATFORM_TYPE_LE		= 0x2,	/* Data router */
	IPA_QMI_PLATFORM_TYPE_MSM_ANDROID	= 0x3,	/* Android MSM */
	IPA_QMI_PLATFORM_TYPE_MSM_WINDOWS	= 0x4,	/* Windows MSM */
	IPA_QMI_PLATFORM_TYPE_MSM_QNX_V01	= 0x5,	/* QNX MSM */
};

/* This defines the start and end offset of a range of memory.  Both
 * fields are offsets relative to the start of IPA shared memory.
 * The end value is the last addressable byte *within* the range.
 */
struct ipa_mem_bounds {
	u32 start;
	u32 end;
};

/* This defines the location and size of an array.  The start value
 * is an offset relative to the start of IPA shared memory.  The
 * size of the array is implied by the number of entries (the entry
 * size is assumed to be known).
 */
struct ipa_mem_array {
	u32 start;
	u32 count;
};

/* This defines the location and size of a range of memory.  The
 * start is an offset relative to the start of IPA shared memory.
 * This differs from the ipa_mem_bounds structure in that the size
 * (in bytes) of the memory region is specified rather than the
 * offset of its last byte.
 */
struct ipa_mem_range {
	u32 start;
	u32 size;
};

/* The message for the IPA_QMI_INIT_DRIVER request contains information
 * from the AP that affects modem initialization.
 */
struct ipa_init_modem_driver_req {
	u8			platform_type_valid;
	u32			platform_type;	/* enum ipa_platform_type */

	/* Modem header table information.  This defines the IPA shared
	 * memory in which the modem may insert header table entries.
	 */
	u8			hdr_tbl_info_valid;
	struct ipa_mem_bounds	hdr_tbl_info;

	/* Routing table information.  These define the location and size of
	 * non-hashable IPv4 and IPv6 filter tables.  The start values are
	 * offsets relative to the start of IPA shared memory.
	 */
	u8			v4_route_tbl_info_valid;
	struct ipa_mem_array	v4_route_tbl_info;
	u8			v6_route_tbl_info_valid;
	struct ipa_mem_array	v6_route_tbl_info;

	/* Filter table information.  These define the location of the
	 * non-hashable IPv4 and IPv6 filter tables.  The start values are
	 * offsets relative to the start of IPA shared memory.
	 */
	u8			v4_filter_tbl_start_valid;
	u32			v4_filter_tbl_start;
	u8			v6_filter_tbl_start_valid;
	u32			v6_filter_tbl_start;

	/* Modem memory information.  This defines the location and
	 * size of memory available for the modem to use.
	 */
	u8			modem_mem_info_valid;
	struct ipa_mem_range	modem_mem_info;

	/* This defines the destination endpoint on the AP to which
	 * the modem driver can send control commands.  Must be less
	 * than ipa_endpoint_max().
	 */
	u8			ctrl_comm_dest_end_pt_valid;
	u32			ctrl_comm_dest_end_pt;

	/* This defines whether the modem should load the microcontroller
	 * or not.  It is unnecessary to reload it if the modem is being
	 * restarted.
	 *
	 * NOTE: this field is named "is_ssr_bootup" elsewhere.
	 */
	u8			skip_uc_load_valid;
	u8			skip_uc_load;

	/* Processing context memory information.  This defines the memory in
	 * which the modem may insert header processing context table entries.
	 */
	u8			hdr_proc_ctx_tbl_info_valid;
	struct ipa_mem_bounds	hdr_proc_ctx_tbl_info;

	/* Compression command memory information.  This defines the memory
	 * in which the modem may insert compression/decompression commands.
	 */
	u8			zip_tbl_info_valid;
	struct ipa_mem_bounds	zip_tbl_info;

	/* Routing table information.  These define the location and size
	 * of hashable IPv4 and IPv6 filter tables.  The start values are
	 * offsets relative to the start of IPA shared memory.
	 */
	u8			v4_hash_route_tbl_info_valid;
	struct ipa_mem_array	v4_hash_route_tbl_info;
	u8			v6_hash_route_tbl_info_valid;
	struct ipa_mem_array	v6_hash_route_tbl_info;

	/* Filter table information.  These define the location and size
	 * of hashable IPv4 and IPv6 filter tables.  The start values are
	 * offsets relative to the start of IPA shared memory.
	 */
	u8			v4_hash_filter_tbl_start_valid;
	u32			v4_hash_filter_tbl_start;
	u8			v6_hash_filter_tbl_start_valid;
	u32			v6_hash_filter_tbl_start;

	/* Statistics information.  These define the locations of the
	 * first and last statistics sub-regions.  (IPA v4.0 and above)
	 */
	u8			hw_stats_quota_base_addr_valid;
	u32			hw_stats_quota_base_addr;
	u8			hw_stats_quota_size_valid;
	u32			hw_stats_quota_size;
	u8			hw_stats_drop_base_addr_valid;
	u32			hw_stats_drop_base_addr;
	u8			hw_stats_drop_size_valid;
	u32			hw_stats_drop_size;
};

/* The response to a IPA_QMI_INIT_DRIVER request begins with a standard
 * QMI response, but contains other information as well.  Currently we
 * simply wait for the the INIT_DRIVER transaction to complete and
 * ignore any other data that might be returned.
 */
struct ipa_init_modem_driver_rsp {
	struct qmi_response_type_v01	rsp;

	/* This defines the destination endpoint on the modem to which
	 * the AP driver can send control commands.  Must be less than
	 * ipa_endpoint_max().
	 */
	u8				ctrl_comm_dest_end_pt_valid;
	u32				ctrl_comm_dest_end_pt;

	/* This defines the default endpoint.  The AP driver is not
	 * required to configure the hardware with this value.  Must
	 * be less than ipa_endpoint_max().
	 */
	u8				default_end_pt_valid;
	u32				default_end_pt;

	/* This defines whether a second handshake is required to complete
	 * initialization.
	 */
	u8				modem_driver_init_pending_valid;
	u8				modem_driver_init_pending;
};

/* The message from teh IPA_CONFIG request contains information on how the AP
 * should configure the IPA.
 */
struct ipa_config_req_msg_v01 {
	/*  Peripheral Type */
	u8 peripheral_type_valid;
	/* Must be set to true if peripheral_type is being passed */
	u32 peripheral_type;
	/* Informs the remote driver about the perhipheral for
	 * which this configuration information is relevant. Values:
	 *	- QMI_IPA_PERIPHERAL_USB (1) -- Specifies a USB peripheral
	 *	- QMI_IPA_PERIPHERAL_HSIC(2) -- Specifies an HSIC peripheral
	 *	- QMI_IPA_PERIPHERAL_PCIE(3) -- Specifies a PCIe peripheral
	 */

	/*  HW Deaggregation Support */
	u8 hw_deaggr_supported_valid;
	/* Must be set to true if hw_deaggr_supported is being passed */
	u8 hw_deaggr_supported;
	/* Informs the remote driver whether the local IPA driver
	 * allows de-aggregation to be performed in the hardware
	 */

	/*  Maximum Aggregation Frame Size */
	u8 max_aggr_frame_size_valid;
	/* Must be set to true if max_aggr_frame_size is being passed */
	u32 max_aggr_frame_size;
	/* Specifies the maximum size of the aggregated frame that
	 * the remote driver can expect from this execution environment
	 *	- Valid range: 128 bytes to 32768 bytes
	 */

	/*  IPA Ingress Pipe Mode */
	u8 ipa_ingress_pipe_mode_valid;
	/* Must be set to true if ipa_ingress_pipe_mode is being passed */

	u32 ipa_ingress_pipe_mode;
	/* Indicates to the remote driver if the ingress pipe into the
	 *	IPA is in direct connection with another hardware block or
	 *	if the producer of data to this ingress pipe is a software
	 *  module. Values:
	 *	-QMI_IPA_PIPE_MODE_HW(1) --Pipe is connected with hardware block
	 *	-QMI_IPA_PIPE_MODE_SW(2) --Pipe is controlled by the software
	 */

	/*  Peripheral Speed Info */
	u8 peripheral_speed_info_valid;
	/* Must be set to true if peripheral_speed_info is being passed */

	u32 peripheral_speed_info;
	/* Indicates the speed that the peripheral connected to the IPA supports
	 * Values:
	 *	- QMI_IPA_PER_USB_FS (1) --  Full-speed USB connection
	 *	- QMI_IPA_PER_USB_HS (2) --  High-speed USB connection
	 *	- QMI_IPA_PER_USB_SS (3) --  Super-speed USB connection
	 *  - QMI_IPA_PER_WLAN   (4) --  WLAN connection
	 */

	/*  Downlink Accumulation Time limit */
	u8 dl_accumulation_time_limit_valid;
	/* Must be set to true if dl_accumulation_time_limit is being passed */
	u32 dl_accumulation_time_limit;
	/* Informs the remote driver about the time for which data
	 * is accumulated in the downlink direction before it is pushed into the
	 * IPA (downlink is with respect to the WWAN air interface)
	 * - Units: milliseconds
	 * - Maximum value: 255
	 */

	/*  Downlink Accumulation Packet limit */
	u8 dl_accumulation_pkt_limit_valid;
	/* Must be set to true if dl_accumulation_pkt_limit is being passed */
	u32 dl_accumulation_pkt_limit;
	/* Informs the remote driver about the number of packets
	 * that are to be accumulated in the downlink direction before it is
	 * pushed into the IPA - Maximum value: 1023
	 */

	/*  Downlink Accumulation Byte Limit */
	u8 dl_accumulation_byte_limit_valid;
	/* Must be set to true if dl_accumulation_byte_limit is being passed */
	u32 dl_accumulation_byte_limit;
	/* Inform the remote driver about the number of bytes
	 * that are to be accumulated in the downlink direction before it
	 * is pushed into the IPA - Maximum value: TBD
	 */

	/*  Uplink Accumulation Time Limit */
	u8 ul_accumulation_time_limit_valid;
	/* Must be set to true if ul_accumulation_time_limit is being passed */
	u32 ul_accumulation_time_limit;
	/* Inform thes remote driver about the time for which data
	 * is to be accumulated in the uplink direction before it is pushed into
	 * the IPA (downlink is with respect to the WWAN air interface).
	 * - Units: milliseconds
	 * - Maximum value: 255
	 */

	/*  HW Control Flags */
	u8 hw_control_flags_valid;
	/* Must be set to true if hw_control_flags is being passed */
	u32 hw_control_flags;
	/* Informs the remote driver about the hardware control flags:
	 *	- Bit 0: IPA_HW_FLAG_HALT_SYSTEM_ON_NON_TERMINAL_FAILURE --
	 *	Indicates to the hardware that it must not continue with
	 *	any subsequent operation even if the failure is not terminal
	 *	- Bit 1: IPA_HW_FLAG_NO_REPORT_MHI_CHANNEL_ERORR --
	 *	Indicates to the hardware that it is not required to report
	 *	channel errors to the host.
	 *	- Bit 2: IPA_HW_FLAG_NO_REPORT_MHI_CHANNEL_WAKE_UP --
	 *	Indicates to the hardware that it is not required to generate
	 *	wake-up events to the host.
	 *	- Bit 4: IPA_HW_FLAG_WORK_OVER_DDR --
	 *	Indicates to the hardware that it is accessing addresses in
	 *  the DDR and not over PCIe
	 *	- Bit 5: IPA_HW_FLAG_INTERRUPT_MODE_CTRL_FLAG --
	 *	Indicates whether the device must
	 *	raise an event to let the host know that it is going into an
	 *	interrupt mode (no longer polling for data/buffer availability)
	 */

	/*  Uplink MSI Event Threshold */
	u8 ul_msi_event_threshold_valid;
	/* Must be set to true if ul_msi_event_threshold is being passed */
	u32 ul_msi_event_threshold;
	/* Informs the remote driver about the threshold that will
	 * cause an interrupt (MSI) to be fired to the host. This ensures
	 * that the remote driver does not accumulate an excesive number of
	 * events before firing an interrupt.
	 * This threshold is applicable for data moved in the UL direction.
	 * - Maximum value: 65535
	 */

	/*  Downlink MSI Event Threshold */
	u8 dl_msi_event_threshold_valid;
	/* Must be set to true if dl_msi_event_threshold is being passed */
	u32 dl_msi_event_threshold;
	/* Informs the remote driver about the threshold that will
	 * cause an interrupt (MSI) to be fired to the host. This ensures
	 * that the remote driver does not accumulate an excesive number of
	 * events before firing an interrupt
	 * This threshold is applicable for data that is moved in the
	 * DL direction - Maximum value: 65535
	 */

	/*  Uplink Fifo Size */
	u8 ul_fifo_size_valid;
	/* Must be set to true if ul_fifo_size is being passed */
	u32 ul_fifo_size;
	/*
	 * Informs the remote driver about the total Uplink xDCI
	 *	buffer size that holds the complete aggregated frame
	 *	or BAM data fifo size of the peripheral channel/pipe(in Bytes).
	 *	This deprecates the max_aggr_frame_size field. This TLV
	 *	deprecates max_aggr_frame_size TLV from version 1.9 onwards
	 *	and the max_aggr_frame_size TLV will be ignored in the presence
	 *	of this TLV.
	 */

	/*  Downlink Fifo Size */
	u8 dl_fifo_size_valid;
	/* Must be set to true if dl_fifo_size is being passed */
	u32 dl_fifo_size;
	/*
	 * Informs the remote driver about the total Downlink xDCI buffering
	 *	capacity or BAM data fifo size of the peripheral channel/pipe.
	 *	(In Bytes). dl_fifo_size = n * dl_buf_size. This deprecates the
	 *	max_aggr_frame_size field. If this value is set
	 *	max_aggr_frame_size is ignored.
	 */

	/*  Downlink Buffer Size */
	u8 dl_buf_size_valid;
	/* Must be set to true if dl_buf_size is being passed */
	u32 dl_buf_size;
	/* Informs the remote driver about the single xDCI buffer size.
	* This is applicable only in GSI mode(in Bytes).\n
	*/
};

/* The response to a IPA_CONFIG request consists only
 * of a standard QMI response.
 */
struct ipa_config_rsp {
	struct qmi_response_type_v01 rsp;
};

struct ipa_ipfltr_range_eq_16_type_v01 {
	u8 offset;
	/*	Specifies the offset from the IHL (Internet Header length) */

	u16 range_low;
	/*	Specifies the lower bound of the range */

	u16 range_high;
	/*	Specifies the upper bound of the range */
};

struct ipa_ipfltr_mask_eq_32_type_v01 {
	u8 offset;
	/*	Specifies the offset either from IHL or from the start of
	 *	the IP packet. This depends on the equation that this structure
	 *	is used in.
	 */

	u32 mask;
	/*	Specifies the mask that has to be used in the comparison.
	 *	The field is ANDed with the mask and compared against the value.
	 */

	u32 value;
	/*	Specifies the 32 bit value that used in the comparison. */
};

struct ipa_ipfltr_mask_eq_128_type_v01 {
	u8 offset;
	/* Specifies the offset into the packet */

	u8 mask[16];
	/*  Specifies the mask that has to be used in the comparison.
	 *	The field is ANDed with the mask and compared against the value.
	 */

	u8 value[16];
	/* Specifies the 128 bit value that should be used in the comparison. */
};

struct ipa_ipfltr_eq_16_type_v01 {
	u8 offset;
	/*  Specifies the offset into the packet */

	u16 value;
	/* Specifies the 16 bit value that should be used in the comparison. */
};

struct ipa_ipfltr_eq_32_type_v01 {
	u8 offset;
	/* Specifies the offset into the packet */

	u32 value;
	/* Specifies the 32 bit value that should be used in the comparison. */
};

struct ipa_filter_rule_type_v01 {
	u16 rule_eq_bitmap;
	/* 16-bit Bitmask to indicate how many eqs are valid in this rule */

	u8 tos_eq_present;
	/* Specifies if a type of service check rule is present */

	u8 tos_eq;
	/* The value to check against the type of service (ipv4) field */

	u8 protocol_eq_present;
	/* Specifies if a protocol check rule is present */

	u8 protocol_eq;
	/* The value to check against the protocol field */

	u8 num_ihl_offset_range_16;
	/*  The number of 16 bit range check rules at the location
	 *	determined by IP header length plus a given offset offset
	 *	in this rule. See the definition of the ipa_filter_range_eq_16
	 *	for better understanding. The value of this field cannot exceed
	 *	IPA_IPFLTR_NUM_IHL_RANGE_16_EQNS which is set as 2
	 */

	struct ipa_ipfltr_range_eq_16_type_v01
		ihl_offset_range_16[QMI_IPA_IPFLTR_NUM_IHL_RANGE_16_EQNS_V01];
	/*	Array of the registered IP header length offset 16 bit range
	 *	check rules.
	 */

	u8 num_offset_meq_32;
	/*  The number of 32 bit masked comparison rules present
	 *  in this rule
	 */

	struct ipa_ipfltr_mask_eq_32_type_v01
		offset_meq_32[QMI_IPA_IPFLTR_NUM_MEQ_32_EQNS_V01];
	/*  An array of all the possible 32bit masked comparison rules
	 *	in this rule
	 */

	u8 tc_eq_present;
	/*  Specifies if the traffic class rule is present in this rule */

	u8 tc_eq;
	/* The value against which the IPV4 traffic class field has to
	* be checked
	*/

	u8 flow_eq_present;
	/* Specifies if the "flow equals" rule is present in this rule */

	u32 flow_eq;
	/* The value against which the IPV6 flow field has to be checked */

	u8 ihl_offset_eq_16_present;
	/*	Specifies if there is a 16 bit comparison required at the
	 *	location in	the packet determined by "Intenet Header length
	 *	+ specified offset"
	 */

	struct ipa_ipfltr_eq_16_type_v01 ihl_offset_eq_16;
	/* The 16 bit comparison equation */

	u8 ihl_offset_eq_32_present;
	/*	Specifies if there is a 32 bit comparison required at the
	 *	location in the packet determined by "Intenet Header length
	 *	+ specified offset"
	 */

	struct ipa_ipfltr_eq_32_type_v01 ihl_offset_eq_32;
	/*	The 32 bit comparison equation */

	u8 num_ihl_offset_meq_32;
	/*	The number of 32 bit masked comparison equations in this
	 *	rule. The location of the packet to be compared is
	 *	determined by the IP Header length + the give offset
	 */

	struct ipa_ipfltr_mask_eq_32_type_v01
		ihl_offset_meq_32[QMI_IPA_IPFLTR_NUM_IHL_MEQ_32_EQNS_V01];
	/*	Array of 32 bit masked comparison equations.
	*/

	u8 num_offset_meq_128;
	/*	The number of 128 bit comparison equations in this rule */

	struct ipa_ipfltr_mask_eq_128_type_v01
		offset_meq_128[QMI_IPA_IPFLTR_NUM_MEQ_128_EQNS_V01];
	/*	Array of 128 bit comparison equations. The location in the
	 *	packet is determined by the specified offset
	 */

	u8 metadata_meq32_present;
	/*  Boolean indicating if the 32 bit masked comparison equation
	 *	is present or not. Comparison is done against the metadata
	 *	in IPA. Metadata can either be extracted from the packet
	 *	header or from the "metadata" register.
	 */

	struct ipa_ipfltr_mask_eq_32_type_v01
			metadata_meq32;
	/* The metadata  32 bit masked comparison equation */

	u8 ipv4_frag_eq_present;
	/* Specifies if the IPv4 Fragment equation is present in this rule */
};

struct ipa_filter_spec_ex_type_v01 {
	u32 ip_type;
	/*	This field identifies the IP type for which this rule is
	 *	applicable. The driver needs to identify the filter table
	 *	(V6 or V4) and this field is essential for that
	 */

	struct ipa_filter_rule_type_v01 filter_rule;
	/*	This field specifies the rules in the filter spec. These rules
	 *	are the ones that are matched against fields in the packet.
	 */

	u32 filter_action;
	/*	This field specifies the action to be taken when a filter match
	 *	occurs. The remote side should install this information into the
	 *	hardware along with the filter equations.
	 */

	u8 is_routing_table_index_valid;
	/*	Specifies whether the routing table index is present or not.
	 *	If the action is "QMI_IPA_FILTER_ACTION_EXCEPTION", this
	 *	parameter need not be provided.
	 */

	u32 route_table_index;
	/*	This is the index in the routing table that should be used
	 *	to route the packets if the filter rule is hit
	 */

	u8 is_mux_id_valid;
	/*	Specifies whether the mux_id is valid */

	u32 mux_id;
	/*	This field identifies the QMAP MUX ID. As a part of QMAP
	 *	protocol, several data calls may be multiplexed over the
	 *	same physical transport channel. This identifier is used to
	 *	identify one such data call. The maximum value for this
	 *	identifier is 255.
	 */

	u32 rule_id;
	/* Rule Id of the given filter. The Rule Id is populated in the rule
	* header when installing the rule in IPA.
	*/

	u8 is_rule_hashable;
	/** Specifies whether the given rule is hashable.
	*/
};

struct ipa_filter_spec_type_v01 {
	uint32_t filter_spec_identifier;
	/*	This field is used to identify a filter spec in the list
	 *	of filter specs being sent from the client. This field
	 *	is applicable only in the filter install request and response.
	 */

	u32 ip_type;
	/*	This field identifies the IP type for which this rule is
	 *	applicable. The driver needs to identify the filter table
	 *	(V6 or V4) and this field is essential for that
	 */

	struct ipa_filter_rule_type_v01 filter_rule;
	/*	This field specifies the rules in the filter spec. These rules
	 *	are the ones that are matched against fields in the packet.
	 */

	u32 filter_action;
	/*	This field specifies the action to be taken when a filter match
	 *	occurs. The remote side should install this information into the
	 *	hardware along with the filter equations.
	 */

	uint8_t is_routing_table_index_valid;
	/*	Specifies whether the routing table index is present or not.
	 *	If the action is "QMI_IPA_FILTER_ACTION_EXCEPTION", this
	 *	parameter need not be provided.
	 */

	uint32_t route_table_index;
	/*	This is the index in the routing table that should be used
	 *	to route the packets if the filter rule is hit
	 */

	uint8_t is_mux_id_valid;
	/*	Specifies whether the mux_id is valid */

	uint32_t mux_id;
	/*	This field identifies the QMAP MUX ID. As a part of QMAP
	 *	protocol, several data calls may be multiplexed over the
	 *	same physical transport channel. This identifier is used to
	 *	identify one such data call. The maximum value for this
	 *	identifier is 255.
	 */
};  /* Type */
/*  Request Message; This is the message that is exchanged between the
 *	control point and the service in order to request the installation
 *	of filtering rules in the hardware block by the remote side.
 */
struct ipa_install_fltr_rule_req_msg_v01 {
	/* Optional
	* IP type that this rule applies to
	* Filter specification to be installed in the hardware
	*/
	uint8_t filter_spec_list_valid;
	/* Must be set to true if filter_spec_list is being passed */
	uint32_t filter_spec_list_len;
	/* Must be set to # of elements in filter_spec_list */
	struct ipa_filter_spec_type_v01
		filter_spec_list[QMI_IPA_MAX_FILTERS_V01];
	/*	This structure defines the list of filters that have
	 *		to be installed in the hardware. The driver installing
	 *		these rules shall do so in the same order as specified
	 *		in this list.
	 */

	/* Optional */
	/*  Pipe index to intall rule */
	uint8_t source_pipe_index_valid;
	/* Must be set to true if source_pipe_index is being passed */
	uint32_t source_pipe_index;
	/*	This is the source pipe on which the filter rule is to be
	 *	installed. The requestor may always not know the pipe
	 *	indices. If not specified, the receiver shall install
	 *	this rule on all the pipes that it controls through
	 *	which data may be fed into IPA.
	 */

	/* Optional */
	/*  Total number of IPv4 filters in the filter spec list */
	uint8_t num_ipv4_filters_valid;
	/* Must be set to true if num_ipv4_filters is being passed */
	uint32_t num_ipv4_filters;
	/*   Number of IPv4 rules included in filter spec list */

	/* Optional */
	/*  Total number of IPv6 filters in the filter spec list */
	uint8_t num_ipv6_filters_valid;
	/* Must be set to true if num_ipv6_filters is being passed */
	uint32_t num_ipv6_filters;
	/* Number of IPv6 rules included in filter spec list */

	/* Optional */
	/*  List of XLAT filter indices in the filter spec list */
	uint8_t xlat_filter_indices_list_valid;
	/* Must be set to true if xlat_filter_indices_list
	 * is being passed
	 */
	uint32_t xlat_filter_indices_list_len;
	/* Must be set to # of elements in xlat_filter_indices_list */
	uint32_t xlat_filter_indices_list[QMI_IPA_MAX_FILTERS_V01];
	/* List of XLAT filter indices. Filter rules at specified indices
	 * will need to be modified by the receiver if the PDN is XLAT
	 * before installing them on the associated IPA consumer pipe.
	 */

	/* Optional */
	/*  Extended Filter Specification  */
	uint8_t filter_spec_ex_list_valid;
	/* Must be set to true if filter_spec_ex_list is being passed */
	uint32_t filter_spec_ex_list_len;
	/* Must be set to # of elements in filter_spec_ex_list */
	struct ipa_filter_spec_ex_type_v01
		filter_spec_ex_list[QMI_IPA_MAX_FILTERS_V01];
	/*
	 * List of filter specifications of filters that must be installed in
	 *	the IPAv3.x hardware.
	 *	The driver installing these rules must do so in the same
	 *	order as specified in this list.
	 */
};

/* Request Message; Request from Modem IPA driver to set DPL peripheral pipe */
struct ipa_install_fltr_rule_req_ex_msg_v01 {
	/*  Extended Filter Specification  */
	u8 filter_spec_ex_list_valid;
	u32 filter_spec_ex_list_len;
	struct ipa_filter_spec_ex_type_v01
		filter_spec_ex_list[QMI_IPA_MAX_FILTERS_EX_V01];
	/* List of filter specifications of filters that must be installed in
	 * the IPAv3.x hardware.
	 * The driver installing these rules must do so in the same order as
	 * specified in this list.
	 */

	/* Pipe Index to Install Rule */
	u8 source_pipe_index_valid;
	u32 source_pipe_index;
	/* Pipe index to install the filter rule.
	 * The requester may not always know the pipe indices. If not specified,
	 * the receiver must install this rule on all pipes that it controls,
	 * through which data may be fed into the IPA.
	 */

	/* Total Number of IPv4 Filters in the Filter Spec List */
	u8 num_ipv4_filters_valid;
	u32 num_ipv4_filters;
	/* Number of IPv4 rules included in the filter specification list. */

	/* Total Number of IPv6 Filters in the Filter Spec List */
	u8 num_ipv6_filters_valid;
	u32 num_ipv6_filters;
	/* Number of IPv6 rules included in the filter specification list. */

	/* List of XLAT Filter Indices in the Filter Spec List */
	u8 xlat_filter_indices_list_valid;
	u32 xlat_filter_indices_list_len;
	u32 xlat_filter_indices_list[QMI_IPA_MAX_FILTERS_EX_V01];
	/* List of XLAT filter indices.
	 * Filter rules at specified indices must be modified by the
	 * receiver if the PDN is XLAT before installing them on the associated
	 * IPA consumer pipe.
	 */
};

struct ipa_filter_rule_identifier_to_handle_map_v01 {
	uint32_t filter_spec_identifier;
	/*	This field is used to identify a filter spec in the list of
	 *	filter specs being sent from the client. This field is
	 *	applicable only in the filter install request and response.
	 */
	uint32_t filter_handle;
	/*  This field is used to identify a rule in any subsequent message.
	 *	This is a value that is provided by the server to the control
	 *	point
	 */
};

/* Response Message; This is the message that is exchanged between the
 * control point and the service in order to request the
 * installation of filtering rules in the hardware block by
 * the remote side.
 */
struct ipa_install_fltr_rule_rsp {
	struct qmi_response_type_v01 rsp;

	/* Optional */
	/*  Filter Handle List */
	uint8_t filter_handle_list_valid;
	/* Must be set to true if filter_handle_list is being passed */
	uint32_t filter_handle_list_len;
	/* Must be set to # of elements in filter_handle_list */
	struct ipa_filter_rule_identifier_to_handle_map_v01
		filter_handle_list[QMI_IPA_MAX_FILTERS_V01];
	/*
	 * List of handles returned to the control point. Each handle is
	 *	mapped to the rule identifier that was specified in the
	 *	request message. Any further reference to the rule is done
	 *	using the filter handle.
	 */

	/* Optional */
	/*  Rule id List */
	uint8_t rule_id_valid;
	/* Must be set to true if rule_id is being passed */
	uint32_t rule_id_len;
	/* Must be set to # of elements in rule_id */
	uint32_t rule_id[QMI_IPA_MAX_FILTERS_V01];
	/*
	 * List of rule ids returned to the control point.
	 *	Any further reference to the rule is done using the
	 *	filter rule id specified in this list.
	 */
};


struct ipa_filter_handle_to_index_map_v01 {
	u32 filter_handle;
	/*	This is a handle that was given to the remote client that
	 *	requested the rule addition.
	 */
	u32 filter_index;
	/*	This index denotes the location in a filter table, where the
	 *	filter rule has been installed. The maximum value of this
	 *	field is 64.
	 */
};

/* Request Message; This is the message that is exchanged between the
 * control point and the service in order to notify the remote driver
 * of the installation of the filter rule supplied earlier by the
 * remote driver.
 */
struct ipa_fltr_installed_notif_req_msg_v01 {
	/*	Mandatory	*/
	/*  Pipe index	*/
	u32 source_pipe_index;
	/*	This is the source pipe on which the filter rule has been
	 *	installed or was attempted to be installed
	 */

	/* Mandatory */
	/*  Installation Status */
	u32 install_status;
	/*	This is the status of installation. If this indicates
	 *	SUCCESS, other optional fields carry additional
	 *	information
	 */

	/* Mandatory */
	/*  List of Filter Indices */
	u32 filter_index_list_len;
	/* Must be set to # of elements in filter_index_list */
	struct ipa_filter_handle_to_index_map_v01
		filter_index_list[QMI_IPA_MAX_FILTERS_V01];
	/*
	 * Provides the list of filter indices and the corresponding
	 *	filter handle. If the installation_status indicates a
	 *	failure, the filter indices must be set to a reserve
	 *	index (255).
	 */

	/* Optional */
	/*  Embedded pipe index */
	u8 embedded_pipe_index_valid;
	/* Must be set to true if embedded_pipe_index is being passed */
	u32 embedded_pipe_index;
	/*	This index denotes the embedded pipe number on which a call to
	 *	the same PDN has been made. If this field is set, it denotes
	 *	that this is a use case where PDN sharing is happening. The
	 *	embedded pipe is used to send data from the embedded client
	 *	in the device
	 */

	/* Optional */
	/*  Retain Header Configuration */
	u8 retain_header_valid;
	/* Must be set to true if retain_header is being passed */
	u8 retain_header;
	/*	This field indicates if the driver installing the rule has
	 *	turned on the "retain header" bit. If this is true, the
	 *	header that is removed by IPA is reinserted after the
	 *	packet processing is completed.
	 */

	/* Optional */
	/*  Embedded call Mux Id */
	u8 embedded_call_mux_id_valid;
	/**< Must be set to true if embedded_call_mux_id is being passed */
	u32 embedded_call_mux_id;
	/*	This identifies one of the many calls that have been originated
	 *	on the embedded pipe. This is how we identify the PDN gateway
	 *	to which traffic from the source pipe has to flow.
	 */

	/* Optional */
	/*  Total number of IPv4 filters in the filter index list */
	u8 num_ipv4_filters_valid;
	/* Must be set to true if num_ipv4_filters is being passed */
	u32 num_ipv4_filters;
	/* Number of IPv4 rules included in filter index list */

	/* Optional */
	/*  Total number of IPv6 filters in the filter index list */
	u8 num_ipv6_filters_valid;
	/* Must be set to true if num_ipv6_filters is being passed */
	u32 num_ipv6_filters;
	/* Number of IPv6 rules included in filter index list */

	/* Optional */
	/*  Start index on IPv4 filters installed on source pipe */
	u8 start_ipv4_filter_idx_valid;
	/* Must be set to true if start_ipv4_filter_idx is being passed */
	u32 start_ipv4_filter_idx;
	/* Start index of IPv4 rules in filter index list */

	/* Optional */
	/*  Start index on IPv6 filters installed on source pipe */
	u8 start_ipv6_filter_idx_valid;
	/* Must be set to true if start_ipv6_filter_idx is being passed */
	u32 start_ipv6_filter_idx;
	/* Start index of IPv6 rules in filter index list */

	/* Optional */
	/*  List of Rule Ids */
	u8 rule_id_valid;
	/* Must be set to true if rule_id is being passed */
	u32 rule_id_len;
	/* Must be set to # of elements in rule_id */
	u32 rule_id[QMI_IPA_MAX_FILTERS_V01];
	/*
	 * Provides the list of Rule Ids of rules added in IPA on the given
	 *	source pipe index. If the install_status TLV indicates a
	 *	failure, the Rule Ids in this list must be set to a reserved
	 *	index (255).
	 */

	/* Optional */
	/*	List of destination pipe IDs. */
	u8 dst_pipe_id_valid;
	/* Must be set to true if dst_pipe_id is being passed. */
	u32 dst_pipe_id_len;
	/* Must be set to # of elements in dst_pipe_id. */
	u32 dst_pipe_id[QMI_IPA_MAX_CLIENT_DST_PIPES_V01];
	/* Provides the list of destination pipe IDs for a source pipe. */

};

struct ipa_fltr_installed_notif_rsp {
	struct qmi_response_type_v01 rsp;
};

/* Message structure definitions defined in "ipa_qmi_msg.c" */
extern struct qmi_elem_info ipa_indication_register_req_ei[];
extern struct qmi_elem_info ipa_indication_register_rsp_ei[];
extern struct qmi_elem_info ipa_driver_init_complete_req_ei[];
extern struct qmi_elem_info ipa_driver_init_complete_rsp_ei[];
extern struct qmi_elem_info ipa_init_complete_ind_ei[];
extern struct qmi_elem_info ipa_mem_bounds_ei[];
extern struct qmi_elem_info ipa_mem_array_ei[];
extern struct qmi_elem_info ipa_mem_range_ei[];
extern struct qmi_elem_info ipa_init_modem_driver_req_ei[];
extern struct qmi_elem_info ipa_init_modem_driver_rsp_ei[];
extern struct qmi_elem_info ipa_config_req_ei[];
extern struct qmi_elem_info ipa_install_fltr_rule_req_ei[];
extern struct qmi_elem_info ipa_install_fltr_rule_rsp_ei[];
extern struct qmi_elem_info ipa_qmi_notify_filter_installed_ei[];
extern struct qmi_elem_info ipa_install_fltr_rule_req_ei[];

#endif /* !_IPA_QMI_MSG_H_ */

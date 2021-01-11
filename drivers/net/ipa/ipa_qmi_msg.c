// SPDX-License-Identifier: GPL-2.0

/* Copyright (c) 2018, The Linux Foundation. All rights reserved.
 * Copyright (C) 2018-2020 Linaro Ltd.
 */
#include <linux/stddef.h>
#include <linux/soc/qcom/qmi.h>

#include "ipa_qmi_msg.h"

/* QMI message structure definition for struct ipa_indication_register_req */
struct qmi_elem_info ipa_indication_register_req_ei[] = {
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_indication_register_req,
				     master_driver_init_complete_valid),
		.tlv_type	= 0x10,
		.offset		= offsetof(struct ipa_indication_register_req,
					   master_driver_init_complete_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_indication_register_req,
				     master_driver_init_complete),
		.tlv_type	= 0x10,
		.offset		= offsetof(struct ipa_indication_register_req,
					   master_driver_init_complete),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_indication_register_req,
				     data_usage_quota_reached_valid),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_indication_register_req,
					   data_usage_quota_reached_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_indication_register_req,
				     data_usage_quota_reached),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_indication_register_req,
					   data_usage_quota_reached),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_indication_register_req,
				     ipa_mhi_ready_ind_valid),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_indication_register_req,
					   ipa_mhi_ready_ind_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_indication_register_req,
				     ipa_mhi_ready_ind),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_indication_register_req,
					   ipa_mhi_ready_ind),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_indication_register_rsp */
struct qmi_elem_info ipa_indication_register_rsp_ei[] = {
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_indication_register_rsp,
				     rsp),
		.tlv_type	= 0x02,
		.offset		= offsetof(struct ipa_indication_register_rsp,
					   rsp),
		.ei_array	= qmi_response_type_v01_ei,
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_driver_init_complete_req */
struct qmi_elem_info ipa_driver_init_complete_req_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_driver_init_complete_req,
				     status),
		.tlv_type	= 0x01,
		.offset		= offsetof(struct ipa_driver_init_complete_req,
					   status),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_driver_init_complete_rsp */
struct qmi_elem_info ipa_driver_init_complete_rsp_ei[] = {
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_driver_init_complete_rsp,
				     rsp),
		.tlv_type	= 0x02,
		.offset		= offsetof(struct ipa_driver_init_complete_rsp,
					   rsp),
		.ei_array	= qmi_response_type_v01_ei,
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_init_complete_ind */
struct qmi_elem_info ipa_init_complete_ind_ei[] = {
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_complete_ind,
				     status),
		.tlv_type	= 0x02,
		.offset		= offsetof(struct ipa_init_complete_ind,
					   status),
		.ei_array	= qmi_response_type_v01_ei,
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_mem_bounds */
struct qmi_elem_info ipa_mem_bounds_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_mem_bounds, start),
		.offset		= offsetof(struct ipa_mem_bounds, start),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_mem_bounds, end),
		.offset		= offsetof(struct ipa_mem_bounds, end),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_mem_array */
struct qmi_elem_info ipa_mem_array_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_mem_array, start),
		.offset		= offsetof(struct ipa_mem_array, start),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_mem_array, count),
		.offset		= offsetof(struct ipa_mem_array, count),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_mem_range */
struct qmi_elem_info ipa_mem_range_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_mem_range, start),
		.offset		= offsetof(struct ipa_mem_range, start),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_mem_range, size),
		.offset		= offsetof(struct ipa_mem_range, size),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_init_modem_driver_req */
struct qmi_elem_info ipa_init_modem_driver_req_ei[] = {
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     platform_type_valid),
		.tlv_type	= 0x10,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   platform_type_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     platform_type),
		.tlv_type	= 0x10,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   platform_type),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hdr_tbl_info_valid),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hdr_tbl_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hdr_tbl_info),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hdr_tbl_info),
		.ei_array	= ipa_mem_bounds_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_route_tbl_info_valid),
		.tlv_type	= 0x12,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_route_tbl_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_route_tbl_info),
		.tlv_type	= 0x12,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_route_tbl_info),
		.ei_array	= ipa_mem_array_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_route_tbl_info_valid),
		.tlv_type	= 0x13,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_route_tbl_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_route_tbl_info),
		.tlv_type	= 0x13,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_route_tbl_info),
		.ei_array	= ipa_mem_array_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_filter_tbl_start_valid),
		.tlv_type	= 0x14,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_filter_tbl_start_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_filter_tbl_start),
		.tlv_type	= 0x14,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_filter_tbl_start),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_filter_tbl_start_valid),
		.tlv_type	= 0x15,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_filter_tbl_start_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_filter_tbl_start),
		.tlv_type	= 0x15,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_filter_tbl_start),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     modem_mem_info_valid),
		.tlv_type	= 0x16,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   modem_mem_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     modem_mem_info),
		.tlv_type	= 0x16,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   modem_mem_info),
		.ei_array	= ipa_mem_range_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     ctrl_comm_dest_end_pt_valid),
		.tlv_type	= 0x17,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   ctrl_comm_dest_end_pt_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     ctrl_comm_dest_end_pt),
		.tlv_type	= 0x17,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   ctrl_comm_dest_end_pt),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     skip_uc_load_valid),
		.tlv_type	= 0x18,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   skip_uc_load_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     skip_uc_load),
		.tlv_type	= 0x18,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   skip_uc_load),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hdr_proc_ctx_tbl_info_valid),
		.tlv_type	= 0x19,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hdr_proc_ctx_tbl_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hdr_proc_ctx_tbl_info),
		.tlv_type	= 0x19,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hdr_proc_ctx_tbl_info),
		.ei_array	= ipa_mem_bounds_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     zip_tbl_info_valid),
		.tlv_type	= 0x1a,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   zip_tbl_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     zip_tbl_info),
		.tlv_type	= 0x1a,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   zip_tbl_info),
		.ei_array	= ipa_mem_bounds_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_hash_route_tbl_info_valid),
		.tlv_type	= 0x1b,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_hash_route_tbl_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_hash_route_tbl_info),
		.tlv_type	= 0x1b,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_hash_route_tbl_info),
		.ei_array	= ipa_mem_array_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_hash_route_tbl_info_valid),
		.tlv_type	= 0x1c,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_hash_route_tbl_info_valid),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_hash_route_tbl_info),
		.tlv_type	= 0x1c,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_hash_route_tbl_info),
		.ei_array	= ipa_mem_array_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_hash_filter_tbl_start_valid),
		.tlv_type	= 0x1d,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_hash_filter_tbl_start_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v4_hash_filter_tbl_start),
		.tlv_type	= 0x1d,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v4_hash_filter_tbl_start),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_hash_filter_tbl_start_valid),
		.tlv_type	= 0x1e,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_hash_filter_tbl_start_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     v6_hash_filter_tbl_start),
		.tlv_type	= 0x1e,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   v6_hash_filter_tbl_start),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hw_stats_quota_base_addr_valid),
		.tlv_type	= 0x1f,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hw_stats_quota_base_addr_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hw_stats_quota_base_addr),
		.tlv_type	= 0x1f,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hw_stats_quota_base_addr),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hw_stats_quota_size_valid),
		.tlv_type	= 0x1f,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hw_stats_quota_size_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hw_stats_quota_size),
		.tlv_type	= 0x1f,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hw_stats_quota_size),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hw_stats_drop_size_valid),
		.tlv_type	= 0x1f,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hw_stats_drop_size_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_req,
				     hw_stats_drop_size),
		.tlv_type	= 0x1f,
		.offset		= offsetof(struct ipa_init_modem_driver_req,
					   hw_stats_drop_size),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

struct qmi_elem_info ipa_config_req_ei[] = {
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof_field(struct ipa_config_req_msg_v01,
					       peripheral_type_valid),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			peripheral_type_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			peripheral_type),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x11,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			hw_deaggr_supported_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x11,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			hw_deaggr_supported),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x12,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			max_aggr_frame_size_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x12,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
					max_aggr_frame_size),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x13,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			ipa_ingress_pipe_mode_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x13,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			ipa_ingress_pipe_mode),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x14,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			peripheral_speed_info_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x14,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			peripheral_speed_info),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x15,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_accumulation_time_limit_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x15,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_accumulation_time_limit),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x16,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_accumulation_pkt_limit_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x16,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_accumulation_pkt_limit),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x17,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_accumulation_byte_limit_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x17,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_accumulation_byte_limit),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x18,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			ul_accumulation_time_limit_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x18,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			ul_accumulation_time_limit),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x19,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			hw_control_flags_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x19,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			hw_control_flags),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x1A,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			ul_msi_event_threshold_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x1A,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			ul_msi_event_threshold),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x1B,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_msi_event_threshold_valid),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x1B,
		.offset		= offsetof(
			struct ipa_config_req_msg_v01,
			dl_msi_event_threshold),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info ipa_filter_handle_to_index_map_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_filter_handle_to_index_map_v01,
			filter_handle),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_filter_handle_to_index_map_v01,
			filter_index),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info ipa_ipfltr_range_eq_16_type_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_range_eq_16_type_v01,
			offset),
	},
	{
		.data_type	= QMI_UNSIGNED_2_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint16_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_range_eq_16_type_v01,
			range_low),
	},
	{
		.data_type	= QMI_UNSIGNED_2_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint16_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_range_eq_16_type_v01,
			range_high),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info ipa_ipfltr_mask_eq_32_type_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
				struct ipa_ipfltr_mask_eq_32_type_v01,
				offset),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
				struct ipa_ipfltr_mask_eq_32_type_v01,
				mask),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_mask_eq_32_type_v01,
			value),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info ipa_ipfltr_mask_eq_128_type_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_mask_eq_128_type_v01,
			offset),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 16,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_mask_eq_128_type_v01,
			mask),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 16,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_mask_eq_128_type_v01,
			value),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info ipa_ipfltr_eq_16_type_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_ipfltr_eq_16_type_v01,
			offset),
	},
	{
		.data_type	= QMI_UNSIGNED_2_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint16_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_ipfltr_eq_16_type_v01,
					value),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info ipa_ipfltr_eq_32_type_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_ipfltr_eq_32_type_v01,
					offset),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_ipfltr_eq_32_type_v01,
					value),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info ipa_filter_rule_type_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_2_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint16_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_filter_rule_type_v01,
			rule_eq_bitmap),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_filter_rule_type_v01,
			tos_eq_present),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					tos_eq),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					protocol_eq_present),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					protocol_eq),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					num_ihl_offset_range_16),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= QMI_IPA_IPFLTR_NUM_IHL_RANGE_16_EQNS_V01,
		.elem_size	= sizeof(
			struct ipa_ipfltr_range_eq_16_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					ihl_offset_range_16),
		.ei_array	= ipa_ipfltr_range_eq_16_type_data_v01_ei,
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					num_offset_meq_32),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= QMI_IPA_IPFLTR_NUM_MEQ_32_EQNS_V01,
		.elem_size	= sizeof(struct ipa_ipfltr_mask_eq_32_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					offset_meq_32),
		.ei_array	= ipa_ipfltr_mask_eq_32_type_data_v01_ei,
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					tc_eq_present),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					tc_eq),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					flow_eq_present),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					flow_eq),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					ihl_offset_eq_16_present),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	= sizeof(struct ipa_ipfltr_eq_16_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					ihl_offset_eq_16),
		.ei_array	= ipa_ipfltr_eq_16_type_data_v01_ei,
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					ihl_offset_eq_32_present),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	= sizeof(struct ipa_ipfltr_eq_32_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					ihl_offset_eq_32),
		.ei_array	= ipa_ipfltr_eq_32_type_data_v01_ei,
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					num_ihl_offset_meq_32),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= QMI_IPA_IPFLTR_NUM_IHL_MEQ_32_EQNS_V01,
		.elem_size	= sizeof(struct ipa_ipfltr_mask_eq_32_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					ihl_offset_meq_32),
		.ei_array	= ipa_ipfltr_mask_eq_32_type_data_v01_ei,
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					num_offset_meq_128),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	=
			QMI_IPA_IPFLTR_NUM_MEQ_128_EQNS_V01,
		.elem_size	= sizeof(
			struct ipa_ipfltr_mask_eq_128_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_filter_rule_type_v01,
			offset_meq_128),
		.ei_array	= ipa_ipfltr_mask_eq_128_type_data_v01_ei,
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					metadata_meq32_present),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	= sizeof(struct ipa_ipfltr_mask_eq_32_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					metadata_meq32),
		.ei_array	= ipa_ipfltr_mask_eq_32_type_data_v01_ei,
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_rule_type_v01,
					ipv4_frag_eq_present),
	},
	{
		.data_type	= QMI_EOTI,
		.tlv_type	= QMI_COMMON_TLV_TYPE,
	},
};

static struct qmi_elem_info ipa_filter_spec_type_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					filter_spec_identifier),
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					ip_type),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	= sizeof(struct ipa_filter_rule_type_v01),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					filter_rule),
		.ei_array	= ipa_filter_rule_type_data_v01_ei,
	},
	{
		.data_type	= QMI_SIGNED_4_BYTE_ENUM,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					filter_action),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					is_routing_table_index_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					route_table_index),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					is_mux_id_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(struct ipa_filter_spec_type_v01,
					mux_id),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

struct qmi_elem_info ipa_install_fltr_rule_req_ei[] = {
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			filter_spec_list_valid),
	},
	{
		.data_type	= QMI_DATA_LEN,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			filter_spec_list_len),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= QMI_IPA_MAX_FILTERS_V01,
		.elem_size	= sizeof(struct ipa_filter_spec_type_v01),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			filter_spec_list),
		.ei_array	= ipa_filter_spec_type_data_v01_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x11,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			source_pipe_index_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x11,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			source_pipe_index),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x12,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			num_ipv4_filters_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x12,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			num_ipv4_filters),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x13,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			num_ipv6_filters_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x13,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			num_ipv6_filters),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x14,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			xlat_filter_indices_list_valid),
	},
	{
		.data_type	= QMI_DATA_LEN,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x14,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			xlat_filter_indices_list_len),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= QMI_IPA_MAX_FILTERS_V01,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x14,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_req_msg_v01,
			xlat_filter_indices_list),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

static struct qmi_elem_info
	ipa_filter_rule_identifier_to_handle_map_data_v01_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_filter_rule_identifier_to_handle_map_v01,
			filter_spec_identifier),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= QMI_COMMON_TLV_TYPE,
		.offset		= offsetof(
			struct ipa_filter_rule_identifier_to_handle_map_v01,
			filter_handle),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

struct qmi_elem_info ipa_install_fltr_rule_rsp_ei[] = {
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	= sizeof(struct qmi_response_type_v01),
		.tlv_type	= 0x02,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_rsp,
			rsp),
		.ei_array       = qmi_response_type_v01_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_rsp,
			filter_handle_list_valid),
	},
	{
		.data_type	= QMI_DATA_LEN,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_rsp,
			filter_handle_list_len),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= QMI_IPA_MAX_FILTERS_V01,
		.elem_size	= sizeof(
			struct ipa_filter_rule_identifier_to_handle_map_v01),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_install_fltr_rule_rsp,
			filter_handle_list),
		.ei_array	=
			ipa_filter_rule_identifier_to_handle_map_data_v01_ei,
	},
	{
		.data_type	= QMI_EOTI,
	},
};

struct qmi_elem_info ipa_qmi_notify_filter_installed_ei[] = {
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x01,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			source_pipe_index),
	},
	{
		.data_type	= QMI_UNSIGNED_2_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint16_t),
		.tlv_type	= 0x02,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			install_status),
	},
	{
		.data_type	= QMI_DATA_LEN,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x03,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			filter_index_list_len),
	},
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= QMI_IPA_MAX_FILTERS_V01,
		.elem_size	= sizeof(
			struct ipa_filter_handle_to_index_map_v01),
		.tlv_type	= 0x03,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			filter_index_list),
		.ei_array	= ipa_filter_handle_to_index_map_data_v01_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			embedded_pipe_index_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x10,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			embedded_pipe_index),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x11,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			retain_header_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x11,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			retain_header),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x12,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			embedded_call_mux_id_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x12,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			embedded_call_mux_id),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x13,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			num_ipv4_filters_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x13,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			num_ipv4_filters),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x14,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			num_ipv6_filters_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x14,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			num_ipv6_filters),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x15,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			start_ipv4_filter_idx_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x15,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			start_ipv4_filter_idx),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x16,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			start_ipv6_filter_idx_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x16,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			start_ipv6_filter_idx),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x17,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			rule_id_valid),
	},
	{
		.data_type	= QMI_DATA_LEN,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x17,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			rule_id_len),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= QMI_IPA_MAX_FILTERS_V01,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x17,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			rule_id),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x18,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			dst_pipe_id_valid),
	},
	{
		.data_type	= QMI_DATA_LEN,
		.elem_len	= 1,
		.elem_size	= sizeof(uint8_t),
		.tlv_type	= 0x18,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			dst_pipe_id_len),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= QMI_IPA_MAX_CLIENT_DST_PIPES_V01,
		.elem_size	= sizeof(uint32_t),
		.tlv_type	= 0x18,
		.offset		= offsetof(
			struct ipa_fltr_installed_notif_req_msg_v01,
			dst_pipe_id),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

/* QMI message structure definition for struct ipa_init_modem_driver_rsp */
struct qmi_elem_info ipa_init_modem_driver_rsp_ei[] = {
	{
		.data_type	= QMI_STRUCT,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_rsp,
				     rsp),
		.tlv_type	= 0x02,
		.offset		= offsetof(struct ipa_init_modem_driver_rsp,
					   rsp),
		.ei_array	= qmi_response_type_v01_ei,
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_rsp,
				     ctrl_comm_dest_end_pt_valid),
		.tlv_type	= 0x10,
		.offset		= offsetof(struct ipa_init_modem_driver_rsp,
					   ctrl_comm_dest_end_pt_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_rsp,
				     ctrl_comm_dest_end_pt),
		.tlv_type	= 0x10,
		.offset		= offsetof(struct ipa_init_modem_driver_rsp,
					   ctrl_comm_dest_end_pt),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_rsp,
				     default_end_pt_valid),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_init_modem_driver_rsp,
					   default_end_pt_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_4_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_rsp,
				     default_end_pt),
		.tlv_type	= 0x11,
		.offset		= offsetof(struct ipa_init_modem_driver_rsp,
					   default_end_pt),
	},
	{
		.data_type	= QMI_OPT_FLAG,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_rsp,
				     modem_driver_init_pending_valid),
		.tlv_type	= 0x12,
		.offset		= offsetof(struct ipa_init_modem_driver_rsp,
					   modem_driver_init_pending_valid),
	},
	{
		.data_type	= QMI_UNSIGNED_1_BYTE,
		.elem_len	= 1,
		.elem_size	=
			sizeof_field(struct ipa_init_modem_driver_rsp,
				     modem_driver_init_pending),
		.tlv_type	= 0x12,
		.offset		= offsetof(struct ipa_init_modem_driver_rsp,
					   modem_driver_init_pending),
	},
	{
		.data_type	= QMI_EOTI,
	},
};

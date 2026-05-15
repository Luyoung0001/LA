SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

REPO_ROOT := ..
RTL_DIR   := $(REPO_ROOT)/rtl
SIM_DIR   := $(REPO_ROOT)/sim
LA_DIR    := $(REPO_ROOT)/mycpu_env/myCPU
TEST_DIR  := tests

OBJ_DIR    = obj_dir_sv/$(if $(filter 1 yes true on,$(PERF_MONI)),perf,default)
OUTPUT_DIR := output
VERILATOR ?= verilator
EXTRA_PLUSARGS ?=
DEBUG_LEVEL ?= 1
DEBUG_WINDOW ?= 256
DEBUG_FATAL ?= 0
PERF_MONI ?= 0
DIFFTEST_EN ?= 0
DEBUG_FATAL_PLUSARG := $(if $(filter 1 yes true on,$(DEBUG_FATAL)),+DEBUG_FATAL,)
PERF_MONI_FLAG := $(if $(filter 1 yes true on,$(PERF_MONI)),-DPERF_MONI,)
DIFFTEST_EN_FLAG := $(if $(filter 1 yes true on,$(DIFFTEST_EN)),-DDIFFTEST_EN,)

TESTS := \
	axi_arbiter_tb \
	backend_branch_resolve_tb \
	backend_stage_valid_regs_tb \
	backend_slot1_activity_tb \
	backend_slot1_decode_pipe_regs_tb \
	backend_slot1_result_pipe_regs_tb \
	backend_slot1_stage_emit_tb \
	backend_lane_alu_tb \
	backend_operand_mux_tb \
	backend_lane_feedback_match_tb \
	backend_lane_status_tb \
	cpu_bpu_tb \
	cpu_csr_tb \
	cpu_l1_dcache_tb \
	cpu_l1_icache_tb \
	cpu_l2_cache_tb \
	cpu_primitives_tb \
	la_bpu_adapter_tb \
	cpu_regfile_2w_tb \
	cpu_regfile_tb \
	cpu_tlb_tb \
	fetch_buffer_tb \
	la_fetch_buffer_adapter_tb \
	frontend_icache_request_boundary_tb \
	frontend_lookup_packet_tb \
	frontend_lookup_request_boundary_tb \
	frontend_lookup_response_regs_tb \
	frontend_control_tb \
	fpga_pipeline_cpu_core_tb \
	fpga_pipeline_cpu_top_tb \
	ramb36e1_model_tb \
	redirect_token_arbiter_tb \
	s1_if0_stage_ctrl_tb \
	s1_if0_pc_update_tb \
	s1_if0_event_packet_tb \
	s1_frontend_if0_tb \
	s2_if1_stage_ctrl_tb \
	s2_if1_event_packet_tb \
	s2_frontend_if1_tb \
	s3_if2_accept_ctrl_tb \
	s3_if2_event_packet_tb \
	s3_frontend_if2_registered_tb \
	s3_frontend_if2_tb \
	s4_id0_stage_ctrl_tb \
	s4_id0_event_packet_tb \
	s4_backend_id0_tb \
	s5_issue_pair_tb \
	s5_slot0_lane_class_tb \
	s5_slot0_source_select_tb \
	s5_slot1_source_select_tb \
	s5_slot1_lane_class_tb \
	s5_slot0_issue_packet_tb \
	s5_slot1_issue_packet_tb \
	s5_issue_queue_tb \
	s5_issue_queue_ctrl_tb \
	s5_issue_queue_event_packet_tb \
	s5_issue_queue_flow_packet_tb \
	s5_issue_queue_status_packet_tb \
	s5_issue_queue_state_tb \
	s5_stage_valid_regs_tb \
	s5_issue_hold_packet_tb \
	s5_issue_hold_rf_base_tb \
	s5_operand_hold_regs_tb \
	s5_issue_state_flow_tb \
	s5_branch_resolve_tb \
	s5_issue_select_tb \
	s5_issue_decision_packet_tb \
	s5_issue_lane_dispatch_tb \
	s5_issue_event_packet_tb \
	s5_issue_policy_tb \
	s5_rf_base_s10_update_tb \
	s5_slot1_promote_packet_tb \
	s5_slot0_state_regs_tb \
	s5_slot1_state_regs_tb \
	s5_scoreboard_producer_match_tb \
	s5_scoreboard_s10_match_tb \
	s5_issue_scoreboard_tb \
	s5_backend_id1_tb \
	s6_slot0_issue_packet_tb \
	s6_slot0_lane_bank_tb \
	s6_slot0_pipe_regs_tb \
	s6_slot1_lane_bank_tb \
	s6_slot1_pipe_regs_tb \
	s6_slot1_issue_packet_tb \
	s6_rr_hazard_matrix_tb \
	s6_rr_issue_gate_tb \
	s6_rr_event_packet_tb \
	s6_backend_rr_tb \
	s7_slot0_issue_packet_tb \
	s7_slot0_pipe_regs_tb \
	s7_slot1_pipe_regs_tb \
	s7_slot1_issue_packet_tb \
	s7_ex_event_packet_tb \
	s7_operand_feedback_match_tb \
	s7_operand_stage_ctrl_tb \
	s7_operand_hold_regs_tb \
	s7_backend_ex_tb \
	s8_slot0_result_packet_tb \
	s8_slot0_pipe_regs_tb \
	s8_slot1_operand_bypass_tb \
	s8_ex_event_packet_tb \
	s8_exec_stage_ctrl_tb \
	s8_slot1_exec_class_tb \
	s8_slot1_exec_bank_tb \
	s8_redirect_owner_select_tb \
	s8_redirect_payload_select_tb \
	s8_redirect_sideband_tb \
	s8_slot1_pipe_regs_tb \
	s8_slot1_issue_packet_tb \
	s8_backend_ex_tb \
	s9_slot0_result_packet_tb \
	s9_slot0_pipe_regs_tb \
	s9_slot1_result_packet_tb \
	s9_slot1_owner_packet_tb \
	s9_slot1_pipe_regs_tb \
	s9_lsu_lane_select_tb \
	s9_dcache_req_packet_tb \
	s9_shared_mem_request_packet_tb \
	s9_mem_event_packet_tb \
	s9_mem_stage_ctrl_tb \
	s9_backend_mem_tb \
	s10_load_data_format_tb \
	s10_slot0_pipe_regs_tb \
	s10_slot0_wb_packet_tb \
	s10_slot1_commit_packet_tb \
	s10_slot1_pipe_regs_tb \
	s10_slot1_wb_packet_tb \
	s10_slot1_mem_ctrl_tb \
	s10_shared_mem_outcome_tb \
	s10_wb_stage_ctrl_tb \
	s10_feedback_packet_tb \
	s10_raw_mem_event_select_tb \
	s10_difftest_mem_select_tb \
	s10_commit_select_tb \
	s10_wb_select_tb \
	s10_ordered_commit_bank_tb \
	s10_commit_event_packet_tb \
	s10_commit_output_packet_tb \
	s10_backend_wb_tb \
	sram_wrap_tb \
	verilator_top_tb

CASES := $(patsubst %_tb,%,$(TESTS))
CASE ?=
CASE_TB := $(if $(CASE),$(if $(filter %_tb,$(CASE)),$(CASE),$(CASE)_tb))
CASE_NAME := $(patsubst %_tb,%,$(CASE_TB))

ifneq ($(CASE),)
ifeq ($(filter $(CASE_TB),$(TESTS)),)
$(error Unknown CASE '$(CASE)'. Use 'make list' to show supported CASE values)
endif
endif

VFLAGS := \
	--binary \
	--sv \
	--timing \
	--trace \
	-DTB_DEBUG \
	-DCPU_DEBUG_CYCLE_DIV=4 \
	$(PERF_MONI_FLAG) \
	$(DIFFTEST_EN_FLAG) \
	-I$(RTL_DIR) \
	-I$(TEST_DIR) \
	--x-initial 0 \
	--x-assign 0 \
	-Wno-fatal \
	-Wno-DECLFILENAME \
	-Wno-UNUSED \
	-Wno-WIDTH \
	-Wno-PINCONNECTEMPTY \
	-Wno-PINMISSING \
	-Wno-BLKSEQ \
	-Wno-SYNCASYNCNET \
	-Wno-CASEINCOMPLETE

PIPELINE_RTL := \
	$(SIM_DIR)/ramb36e1_model.v \
	$(RTL_DIR)/cpu_primitives.v \
	$(RTL_DIR)/axi_arbiter.v \
	$(RTL_DIR)/cpu_bpu.v \
	$(RTL_DIR)/cpu_csr.v \
	$(RTL_DIR)/cpu_l1_dcache.v \
	$(RTL_DIR)/cpu_l1_icache.v \
	$(RTL_DIR)/cpu_l2_cache.v \
	$(RTL_DIR)/cpu_regfile.v \
	$(RTL_DIR)/cpu_regfile_2w.v \
	$(RTL_DIR)/cpu_tlb.v \
	$(RTL_DIR)/fetch_buffer.v \
	$(RTL_DIR)/frontend_icache_request_boundary.v \
	$(RTL_DIR)/frontend_lookup_packet.v \
	$(RTL_DIR)/frontend_lookup_request_boundary.v \
	$(RTL_DIR)/frontend_lookup_response_regs.v \
	$(RTL_DIR)/frontend_control.v \
	$(RTL_DIR)/redirect_token_arbiter.v \
	$(RTL_DIR)/backend_branch_resolve.v \
	$(RTL_DIR)/backend_lane_alu.v \
	$(RTL_DIR)/backend_operand_mux.v \
	$(RTL_DIR)/backend_lane_feedback_match.v \
	$(RTL_DIR)/backend_lane_status.v \
	$(RTL_DIR)/backend_stage_valid_regs.v \
	$(RTL_DIR)/backend_slot1_activity.v \
	$(RTL_DIR)/backend_slot1_decode_pipe_regs.v \
	$(RTL_DIR)/backend_slot1_result_pipe_regs.v \
	$(RTL_DIR)/backend_slot1_issue_packet.v \
	$(RTL_DIR)/backend_slot1_stage_emit.v \
	$(RTL_DIR)/s1_if0_stage_ctrl.v \
	$(RTL_DIR)/s1_if0_pc_update.v \
	$(RTL_DIR)/s1_if0_event_packet.v \
	$(RTL_DIR)/s1_frontend_if0.v \
	$(RTL_DIR)/s2_if1_stage_ctrl.v \
	$(RTL_DIR)/s2_if1_event_packet.v \
	$(RTL_DIR)/s2_frontend_if1.v \
	$(RTL_DIR)/s3_if2_accept_ctrl.v \
	$(RTL_DIR)/s3_if2_event_packet.v \
	$(RTL_DIR)/s3_frontend_if2.v \
	$(RTL_DIR)/s4_id0_stage_ctrl.v \
	$(RTL_DIR)/s4_id0_event_packet.v \
	$(RTL_DIR)/s4_backend_id0.v \
	$(RTL_DIR)/s5_slot0_lane_class.v \
	$(RTL_DIR)/s5_slot0_source_select.v \
	$(RTL_DIR)/s5_slot1_source_select.v \
	$(RTL_DIR)/s5_slot0_state_bank.v \
	$(RTL_DIR)/s5_slot1_state_bank.v \
	$(RTL_DIR)/s5_slot1_lane_class.v \
	$(RTL_DIR)/s5_issue_pair.v \
	$(RTL_DIR)/s5_slot0_issue_packet.v \
	$(RTL_DIR)/s5_slot1_issue_packet.v \
	$(RTL_DIR)/s5_issue_queue.v \
	$(RTL_DIR)/s5_issue_queue_ctrl.v \
	$(RTL_DIR)/s5_issue_queue_event_packet.v \
	$(RTL_DIR)/s5_issue_queue_flow_packet.v \
	$(RTL_DIR)/s5_issue_queue_status_packet.v \
	$(RTL_DIR)/s5_issue_queue_state.v \
	$(RTL_DIR)/s5_stage_valid_regs.v \
	$(RTL_DIR)/s5_issue_hold_packet.v \
	$(RTL_DIR)/s5_issue_hold_rf_base.v \
	$(RTL_DIR)/s5_operand_hold_regs.v \
	$(RTL_DIR)/s5_issue_state_flow.v \
	$(RTL_DIR)/s5_branch_resolve.v \
	$(RTL_DIR)/s5_issue_select.v \
	$(RTL_DIR)/s5_issue_decision_packet.v \
	$(RTL_DIR)/s5_issue_lane_dispatch.v \
	$(RTL_DIR)/s5_issue_event_packet.v \
	$(RTL_DIR)/s5_issue_policy.v \
	$(RTL_DIR)/s5_rf_base_s10_update.v \
	$(RTL_DIR)/s5_slot1_promote_packet.v \
	$(RTL_DIR)/s5_slot0_state_regs.v \
	$(RTL_DIR)/s5_slot1_state_regs.v \
	$(RTL_DIR)/s5_scoreboard_producer_match.v \
	$(RTL_DIR)/s5_scoreboard_s10_match.v \
	$(RTL_DIR)/s5_issue_scoreboard.v \
	$(RTL_DIR)/s5_backend_id1.v \
	$(RTL_DIR)/s6_slot0_issue_packet.v \
	$(RTL_DIR)/s6_slot0_pipe_regs.v \
	$(RTL_DIR)/s6_slot0_lane_bank.v \
	$(RTL_DIR)/s6_slot1_pipe_regs.v \
	$(RTL_DIR)/s6_slot1_issue_packet.v \
	$(RTL_DIR)/s6_slot1_lane_bank.v \
	$(RTL_DIR)/s6_rr_hazard_matrix.v \
	$(RTL_DIR)/s6_rr_issue_gate.v \
	$(RTL_DIR)/s6_rr_event_packet.v \
	$(RTL_DIR)/s6_backend_rr.v \
	$(RTL_DIR)/s7_slot0_lane_bank.v \
	$(RTL_DIR)/s7_slot1_lane_bank.v \
	$(RTL_DIR)/s7_slot0_issue_packet.v \
	$(RTL_DIR)/s7_slot0_pipe_regs.v \
	$(RTL_DIR)/s7_slot1_pipe_regs.v \
	$(RTL_DIR)/s7_slot1_issue_packet.v \
	$(RTL_DIR)/s7_ex_event_packet.v \
	$(RTL_DIR)/s7_operand_feedback_match.v \
	$(RTL_DIR)/s7_operand_stage_ctrl.v \
	$(RTL_DIR)/s7_operand_hold_regs.v \
	$(RTL_DIR)/s7_backend_ex.v \
	$(RTL_DIR)/s8_slot0_result_packet.v \
	$(RTL_DIR)/s8_slot0_exec_bank.v \
	$(RTL_DIR)/s8_slot0_pipe_regs.v \
	$(RTL_DIR)/s8_slot1_operand_bypass.v \
	$(RTL_DIR)/s8_slot1_exec_bank.v \
	$(RTL_DIR)/s8_redirect_owner_select.v \
	$(RTL_DIR)/s8_redirect_payload_select.v \
	$(RTL_DIR)/s8_redirect_sideband.v \
	$(RTL_DIR)/s8_ex_event_packet.v \
	$(RTL_DIR)/s8_exec_stage_ctrl.v \
	$(RTL_DIR)/s8_slot1_exec_class.v \
	$(RTL_DIR)/s8_slot1_pipe_regs.v \
	$(RTL_DIR)/s8_slot1_issue_packet.v \
	$(RTL_DIR)/s8_backend_ex.v \
	$(RTL_DIR)/s9_slot0_result_packet.v \
	$(RTL_DIR)/s9_slot0_pipe_regs.v \
	$(RTL_DIR)/s9_slot1_result_packet.v \
	$(RTL_DIR)/s9_slot1_owner_packet.v \
	$(RTL_DIR)/s9_slot1_pipe_regs.v \
	$(RTL_DIR)/s9_lsu_lane_select.v \
	$(RTL_DIR)/s9_dcache_req_packet.v \
	$(RTL_DIR)/s9_shared_mem_request_packet.v \
	$(RTL_DIR)/s9_mem_event_packet.v \
	$(RTL_DIR)/s9_mem_stage_ctrl.v \
	$(RTL_DIR)/s9_backend_mem.v \
	$(RTL_DIR)/s10_load_data_format.v \
	$(RTL_DIR)/s10_slot0_pipe_regs.v \
	$(RTL_DIR)/s10_slot0_wb_packet.v \
	$(RTL_DIR)/s10_slot1_commit_packet.v \
	$(RTL_DIR)/s10_slot1_pipe_regs.v \
	$(RTL_DIR)/s10_slot1_wb_packet.v \
	$(RTL_DIR)/s10_slot1_mem_ctrl.v \
	$(RTL_DIR)/s10_dcache_resp_owner.v \
	$(RTL_DIR)/s10_shared_mem_outcome.v \
	$(RTL_DIR)/s10_shared_mem_pipe_regs.v \
	$(RTL_DIR)/s10_wb_stage_ctrl.v \
	$(RTL_DIR)/s10_feedback_packet.v \
	$(RTL_DIR)/s10_raw_mem_event_select.v \
	$(RTL_DIR)/s10_difftest_mem_select.v \
	$(RTL_DIR)/s10_commit_select.v \
	$(RTL_DIR)/s10_wb_select.v \
	$(RTL_DIR)/s10_ordered_commit_bank.v \
	$(RTL_DIR)/s10_commit_event_packet.v \
	$(RTL_DIR)/s10_commit_output_packet.v \
	$(RTL_DIR)/s10_backend_wb.v \
	$(RTL_DIR)/fpga_pipeline_cpu_core.v

SRC_axi_arbiter_tb            := $(RTL_DIR)/axi_arbiter.v
SRC_backend_branch_resolve_tb := $(RTL_DIR)/backend_branch_resolve.v
SRC_backend_stage_valid_regs_tb := $(RTL_DIR)/backend_stage_valid_regs.v
SRC_backend_slot1_activity_tb := $(RTL_DIR)/backend_slot1_activity.v
SRC_backend_slot1_decode_pipe_regs_tb := $(RTL_DIR)/backend_slot1_decode_pipe_regs.v
SRC_backend_slot1_result_pipe_regs_tb := $(RTL_DIR)/backend_slot1_result_pipe_regs.v
SRC_backend_slot1_stage_emit_tb := $(RTL_DIR)/backend_slot1_stage_emit.v
SRC_backend_lane_alu_tb       := $(RTL_DIR)/backend_lane_alu.v
SRC_backend_operand_mux_tb    := $(RTL_DIR)/backend_operand_mux.v
SRC_backend_lane_feedback_match_tb := $(RTL_DIR)/backend_lane_feedback_match.v
SRC_backend_lane_status_tb    := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_lane_status.v
SRC_cpu_bpu_tb                := $(RTL_DIR)/cpu_bpu.v
SRC_cpu_csr_tb                := $(RTL_DIR)/cpu_csr.v
SRC_cpu_l1_dcache_tb          := $(SIM_DIR)/ramb36e1_model.v $(RTL_DIR)/cpu_l1_dcache.v
SRC_cpu_l1_icache_tb          := $(SIM_DIR)/ramb36e1_model.v $(RTL_DIR)/cpu_l1_icache.v
SRC_cpu_l2_cache_tb           := $(SIM_DIR)/ramb36e1_model.v $(RTL_DIR)/cpu_l2_cache.v
SRC_cpu_primitives_tb         := $(RTL_DIR)/cpu_primitives.v
SRC_la_bpu_adapter_tb         := $(RTL_DIR)/cpu_bpu.v $(RTL_DIR)/la_bpu_adapter.v
SRC_cpu_regfile_2w_tb         := $(RTL_DIR)/cpu_regfile_2w.v
SRC_cpu_regfile_tb            := $(SIM_DIR)/ramb36e1_model.v $(RTL_DIR)/cpu_regfile.v
SRC_cpu_tlb_tb                := $(RTL_DIR)/cpu_tlb.v
SRC_fetch_buffer_tb           := $(RTL_DIR)/fetch_buffer.v
SRC_la_fetch_buffer_adapter_tb := $(RTL_DIR)/fetch_buffer.v $(RTL_DIR)/la_fetch_buffer_adapter.v
SRC_frontend_icache_request_boundary_tb := $(RTL_DIR)/frontend_icache_request_boundary.v
SRC_frontend_lookup_packet_tb := $(RTL_DIR)/frontend_lookup_packet.v
SRC_frontend_lookup_request_boundary_tb := $(RTL_DIR)/frontend_lookup_request_boundary.v
SRC_frontend_lookup_response_regs_tb := $(RTL_DIR)/frontend_lookup_response_regs.v
SRC_frontend_control_tb       := $(RTL_DIR)/frontend_lookup_packet.v $(RTL_DIR)/frontend_control.v
SRC_fpga_pipeline_cpu_core_tb := $(PIPELINE_RTL)
SRC_fpga_pipeline_cpu_top_tb  := $(PIPELINE_RTL) $(RTL_DIR)/fpga_pipeline_cpu_top.v
SRC_ramb36e1_model_tb         := $(SIM_DIR)/ramb36e1_model.v
SRC_redirect_token_arbiter_tb := $(RTL_DIR)/redirect_token_arbiter.v
SRC_s1_if0_stage_ctrl_tb      := $(RTL_DIR)/s1_if0_stage_ctrl.v
SRC_s1_if0_pc_update_tb       := $(RTL_DIR)/s1_if0_pc_update.v
SRC_s1_if0_event_packet_tb    := $(RTL_DIR)/s1_if0_event_packet.v
SRC_s1_frontend_if0_tb        := $(RTL_DIR)/s1_if0_stage_ctrl.v $(RTL_DIR)/s1_if0_pc_update.v $(RTL_DIR)/s1_if0_event_packet.v $(RTL_DIR)/s1_frontend_if0.v
SRC_s2_if1_stage_ctrl_tb      := $(RTL_DIR)/s2_if1_stage_ctrl.v
SRC_s2_if1_event_packet_tb    := $(RTL_DIR)/s2_if1_event_packet.v
SRC_s2_frontend_if1_tb        := $(RTL_DIR)/s2_if1_stage_ctrl.v $(RTL_DIR)/s2_if1_event_packet.v $(RTL_DIR)/s2_frontend_if1.v
SRC_s3_if2_accept_ctrl_tb     := $(RTL_DIR)/s3_if2_accept_ctrl.v
SRC_s3_if2_event_packet_tb    := $(RTL_DIR)/s3_if2_event_packet.v
SRC_s3_frontend_if2_registered_tb := $(RTL_DIR)/s3_if2_accept_ctrl.v $(RTL_DIR)/s3_if2_event_packet.v $(RTL_DIR)/s3_frontend_if2.v
SRC_s3_frontend_if2_tb        := $(RTL_DIR)/s3_if2_accept_ctrl.v $(RTL_DIR)/s3_if2_event_packet.v $(RTL_DIR)/s3_frontend_if2.v
SRC_s4_id0_stage_ctrl_tb      := $(RTL_DIR)/s4_id0_stage_ctrl.v
SRC_s4_id0_event_packet_tb    := $(RTL_DIR)/s4_id0_event_packet.v
SRC_s4_backend_id0_tb         := $(RTL_DIR)/s4_id0_stage_ctrl.v $(RTL_DIR)/s4_id0_event_packet.v $(RTL_DIR)/s4_backend_id0.v
SRC_s5_issue_pair_tb          := $(RTL_DIR)/s5_slot1_lane_class.v $(RTL_DIR)/s5_issue_pair.v
SRC_s5_slot0_lane_class_tb    := $(RTL_DIR)/s5_slot0_lane_class.v
SRC_s5_slot0_source_select_tb := $(RTL_DIR)/s5_slot0_source_select.v
SRC_s5_slot1_source_select_tb := $(RTL_DIR)/s5_slot1_source_select.v
SRC_s5_slot1_lane_class_tb    := $(RTL_DIR)/s5_slot1_lane_class.v
SRC_s5_slot0_issue_packet_tb  := $(RTL_DIR)/s5_slot0_issue_packet.v
SRC_s5_slot1_issue_packet_tb  := $(RTL_DIR)/backend_slot1_issue_packet.v $(RTL_DIR)/s5_slot1_issue_packet.v
SRC_s5_issue_queue_tb         := $(RTL_DIR)/s5_issue_queue_ctrl.v $(RTL_DIR)/s5_issue_queue_event_packet.v $(RTL_DIR)/s5_issue_state_flow.v $(RTL_DIR)/s5_issue_queue_flow_packet.v $(RTL_DIR)/s5_issue_queue_status_packet.v $(RTL_DIR)/s5_issue_queue_state.v $(RTL_DIR)/s5_issue_queue.v
SRC_s5_issue_queue_ctrl_tb    := $(RTL_DIR)/s5_issue_queue_ctrl.v
SRC_s5_issue_queue_state_tb   := $(RTL_DIR)/s5_issue_queue_state.v
SRC_s5_stage_valid_regs_tb    := $(RTL_DIR)/s5_stage_valid_regs.v
SRC_s5_issue_hold_packet_tb   := $(RTL_DIR)/s5_issue_hold_packet.v
SRC_s5_issue_hold_rf_base_tb  := $(RTL_DIR)/s5_issue_hold_rf_base.v
SRC_s5_operand_hold_regs_tb   := $(RTL_DIR)/s5_operand_hold_regs.v
SRC_s5_issue_state_flow_tb    := $(RTL_DIR)/s5_issue_state_flow.v
SRC_s5_branch_resolve_tb      := $(RTL_DIR)/s5_branch_resolve.v
SRC_s5_issue_select_tb        := $(RTL_DIR)/s5_issue_select.v
SRC_s5_issue_decision_packet_tb := $(RTL_DIR)/s5_issue_decision_packet.v
SRC_s5_issue_lane_dispatch_tb := $(RTL_DIR)/s5_issue_lane_dispatch.v
SRC_s5_issue_event_packet_tb  := $(RTL_DIR)/s5_issue_event_packet.v
SRC_s5_issue_policy_tb        := $(RTL_DIR)/s5_issue_policy.v
SRC_s5_rf_base_s10_update_tb  := $(RTL_DIR)/s5_rf_base_s10_update.v
SRC_s5_slot1_promote_packet_tb := $(RTL_DIR)/s5_slot1_promote_packet.v
SRC_s5_slot0_state_regs_tb    := $(RTL_DIR)/s5_slot0_state_regs.v
SRC_s5_slot1_state_regs_tb    := $(RTL_DIR)/s5_slot1_source_select.v $(RTL_DIR)/s5_slot1_state_regs.v
SRC_s5_scoreboard_producer_match_tb := $(RTL_DIR)/backend_lane_feedback_match.v $(RTL_DIR)/s5_scoreboard_producer_match.v
SRC_s5_scoreboard_s10_match_tb := $(RTL_DIR)/backend_lane_feedback_match.v $(RTL_DIR)/s5_scoreboard_s10_match.v
SRC_s5_issue_queue_event_packet_tb := $(RTL_DIR)/s5_issue_queue_event_packet.v
SRC_s5_issue_queue_flow_packet_tb := $(RTL_DIR)/s5_issue_queue_flow_packet.v
SRC_s5_issue_queue_status_packet_tb := $(RTL_DIR)/s5_issue_queue_status_packet.v
SRC_s5_issue_scoreboard_tb    := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_lane_feedback_match.v $(RTL_DIR)/backend_lane_status.v $(RTL_DIR)/s5_scoreboard_producer_match.v $(RTL_DIR)/s5_scoreboard_s10_match.v $(RTL_DIR)/s5_issue_scoreboard.v
SRC_s5_backend_id1_tb         := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_lane_feedback_match.v $(RTL_DIR)/backend_lane_status.v $(RTL_DIR)/backend_slot1_issue_packet.v $(RTL_DIR)/s5_slot0_lane_class.v $(RTL_DIR)/s5_slot0_source_select.v $(RTL_DIR)/s5_slot1_source_select.v $(RTL_DIR)/s5_slot0_state_bank.v $(RTL_DIR)/s5_slot1_state_bank.v $(RTL_DIR)/s5_slot1_lane_class.v $(RTL_DIR)/s5_issue_pair.v $(RTL_DIR)/s5_slot0_issue_packet.v $(RTL_DIR)/s5_slot1_issue_packet.v $(RTL_DIR)/s5_issue_queue_ctrl.v $(RTL_DIR)/s5_issue_queue_event_packet.v $(RTL_DIR)/s5_issue_queue_flow_packet.v $(RTL_DIR)/s5_issue_queue_status_packet.v $(RTL_DIR)/s5_issue_queue_state.v $(RTL_DIR)/s5_stage_valid_regs.v $(RTL_DIR)/s5_issue_hold_packet.v $(RTL_DIR)/s5_issue_hold_rf_base.v $(RTL_DIR)/s5_operand_hold_regs.v $(RTL_DIR)/s5_issue_state_flow.v $(RTL_DIR)/s5_issue_queue.v $(RTL_DIR)/s5_branch_resolve.v $(RTL_DIR)/s5_issue_select.v $(RTL_DIR)/s5_issue_decision_packet.v $(RTL_DIR)/s5_issue_lane_dispatch.v $(RTL_DIR)/s5_issue_event_packet.v $(RTL_DIR)/s5_issue_policy.v $(RTL_DIR)/s5_rf_base_s10_update.v $(RTL_DIR)/s5_slot1_promote_packet.v $(RTL_DIR)/s5_slot0_state_regs.v $(RTL_DIR)/s5_slot1_state_regs.v $(RTL_DIR)/s5_scoreboard_producer_match.v $(RTL_DIR)/s5_scoreboard_s10_match.v $(RTL_DIR)/s5_issue_scoreboard.v $(RTL_DIR)/s5_backend_id1.v
SRC_s6_slot0_issue_packet_tb  := $(RTL_DIR)/s6_slot0_issue_packet.v
SRC_s6_slot0_lane_bank_tb     := $(RTL_DIR)/s6_slot0_issue_packet.v $(RTL_DIR)/s6_slot0_pipe_regs.v $(RTL_DIR)/s6_slot0_lane_bank.v
SRC_s6_slot0_pipe_regs_tb     := $(RTL_DIR)/s6_slot0_pipe_regs.v
SRC_s6_slot1_lane_bank_tb     := $(RTL_DIR)/backend_slot1_issue_packet.v $(RTL_DIR)/backend_slot1_decode_pipe_regs.v $(RTL_DIR)/s6_slot1_pipe_regs.v $(RTL_DIR)/s6_slot1_issue_packet.v $(RTL_DIR)/s6_slot1_lane_bank.v
SRC_s6_slot1_pipe_regs_tb     := $(RTL_DIR)/backend_slot1_decode_pipe_regs.v $(RTL_DIR)/s6_slot1_pipe_regs.v
SRC_s6_slot1_issue_packet_tb  := $(RTL_DIR)/backend_slot1_issue_packet.v $(RTL_DIR)/s6_slot1_issue_packet.v
SRC_s6_rr_hazard_matrix_tb    := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_lane_status.v $(RTL_DIR)/s6_rr_hazard_matrix.v
SRC_s6_rr_issue_gate_tb       := $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s6_rr_issue_gate.v
SRC_s6_rr_event_packet_tb     := $(RTL_DIR)/s6_rr_event_packet.v
SRC_s6_backend_rr_tb          := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_lane_status.v $(RTL_DIR)/backend_slot1_issue_packet.v $(RTL_DIR)/backend_slot1_decode_pipe_regs.v $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s6_rr_hazard_matrix.v $(RTL_DIR)/s6_slot0_issue_packet.v $(RTL_DIR)/s6_slot0_pipe_regs.v $(RTL_DIR)/s6_slot0_lane_bank.v $(RTL_DIR)/s6_slot1_pipe_regs.v $(RTL_DIR)/s6_slot1_issue_packet.v $(RTL_DIR)/s6_slot1_lane_bank.v $(RTL_DIR)/backend_stage_valid_regs.v $(RTL_DIR)/s6_rr_issue_gate.v $(RTL_DIR)/s6_rr_event_packet.v $(RTL_DIR)/s6_backend_rr.v
SRC_s7_slot0_issue_packet_tb  := $(RTL_DIR)/s7_slot0_issue_packet.v
SRC_s7_slot0_pipe_regs_tb     := $(RTL_DIR)/s7_slot0_pipe_regs.v
SRC_s7_slot1_pipe_regs_tb     := $(RTL_DIR)/backend_slot1_decode_pipe_regs.v $(RTL_DIR)/s7_slot1_pipe_regs.v
SRC_s7_slot1_issue_packet_tb  := $(RTL_DIR)/s7_slot1_issue_packet.v
SRC_s7_ex_event_packet_tb     := $(RTL_DIR)/s7_ex_event_packet.v
SRC_s7_operand_feedback_match_tb := $(RTL_DIR)/backend_lane_feedback_match.v $(RTL_DIR)/s7_operand_feedback_match.v
SRC_s7_operand_stage_ctrl_tb  := $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s7_operand_stage_ctrl.v
SRC_s7_operand_hold_regs_tb   := $(RTL_DIR)/s7_operand_hold_regs.v
SRC_s7_backend_ex_tb          := $(RTL_DIR)/backend_branch_resolve.v $(RTL_DIR)/backend_operand_mux.v $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_lane_feedback_match.v $(RTL_DIR)/backend_slot1_decode_pipe_regs.v $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s7_slot0_issue_packet.v $(RTL_DIR)/s7_slot0_pipe_regs.v $(RTL_DIR)/s7_slot0_lane_bank.v $(RTL_DIR)/s7_slot1_pipe_regs.v $(RTL_DIR)/s7_slot1_lane_bank.v $(RTL_DIR)/s7_slot1_issue_packet.v $(RTL_DIR)/backend_stage_valid_regs.v $(RTL_DIR)/s7_operand_feedback_match.v $(RTL_DIR)/s7_operand_stage_ctrl.v $(RTL_DIR)/s7_operand_hold_regs.v $(RTL_DIR)/s7_ex_event_packet.v $(RTL_DIR)/s7_backend_ex.v
SRC_s8_slot0_result_packet_tb := $(RTL_DIR)/s8_slot0_result_packet.v
SRC_s8_slot0_pipe_regs_tb     := $(RTL_DIR)/s8_slot0_pipe_regs.v
SRC_s8_slot1_operand_bypass_tb := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s8_slot1_operand_bypass.v
SRC_s8_ex_event_packet_tb := $(RTL_DIR)/s8_ex_event_packet.v
SRC_s8_exec_stage_ctrl_tb := $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s8_exec_stage_ctrl.v
SRC_s8_slot1_exec_class_tb := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s8_slot1_exec_class.v
SRC_s8_slot1_exec_bank_tb := $(RTL_DIR)/backend_branch_resolve.v $(RTL_DIR)/backend_lane_alu.v $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s8_slot1_operand_bypass.v $(RTL_DIR)/s8_slot1_exec_class.v $(RTL_DIR)/s8_slot1_issue_packet.v $(RTL_DIR)/s8_slot1_exec_bank.v
SRC_s8_redirect_owner_select_tb := $(RTL_DIR)/s8_redirect_owner_select.v
SRC_s8_redirect_payload_select_tb := $(RTL_DIR)/s8_redirect_payload_select.v
SRC_s8_redirect_sideband_tb := $(RTL_DIR)/s8_redirect_owner_select.v $(RTL_DIR)/s8_redirect_payload_select.v $(RTL_DIR)/s8_redirect_sideband.v
SRC_s8_slot1_pipe_regs_tb    := $(RTL_DIR)/s8_slot1_pipe_regs.v
SRC_s8_slot1_issue_packet_tb  := $(RTL_DIR)/s8_slot1_issue_packet.v
SRC_s8_backend_ex_tb          := $(RTL_DIR)/backend_branch_resolve.v $(RTL_DIR)/backend_lane_alu.v $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s8_slot0_result_packet.v $(RTL_DIR)/s8_slot0_exec_bank.v $(RTL_DIR)/s8_slot0_pipe_regs.v $(RTL_DIR)/s8_slot1_operand_bypass.v $(RTL_DIR)/s8_slot1_exec_bank.v $(RTL_DIR)/s8_redirect_owner_select.v $(RTL_DIR)/s8_redirect_payload_select.v $(RTL_DIR)/s8_redirect_sideband.v $(RTL_DIR)/s8_ex_event_packet.v $(RTL_DIR)/s8_exec_stage_ctrl.v $(RTL_DIR)/backend_stage_valid_regs.v $(RTL_DIR)/s8_slot1_exec_class.v $(RTL_DIR)/s8_slot1_pipe_regs.v $(RTL_DIR)/s8_slot1_issue_packet.v $(RTL_DIR)/s8_backend_ex.v
SRC_s9_slot0_result_packet_tb := $(RTL_DIR)/s9_slot0_result_packet.v
SRC_s9_slot0_pipe_regs_tb     := $(RTL_DIR)/s9_slot0_pipe_regs.v
SRC_s9_slot1_result_packet_tb := $(RTL_DIR)/s9_slot1_result_packet.v
SRC_s9_slot1_owner_packet_tb  := $(RTL_DIR)/s9_slot1_result_packet.v $(RTL_DIR)/s9_lsu_lane_select.v $(RTL_DIR)/s9_slot1_owner_packet.v
SRC_s9_slot1_pipe_regs_tb     := $(RTL_DIR)/backend_slot1_result_pipe_regs.v $(RTL_DIR)/s9_slot1_pipe_regs.v
SRC_s9_lsu_lane_select_tb     := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s9_lsu_lane_select.v
SRC_s9_dcache_req_packet_tb   := $(RTL_DIR)/s9_dcache_req_packet.v
SRC_s9_shared_mem_request_packet_tb := $(RTL_DIR)/s9_shared_mem_request_packet.v
SRC_s9_mem_event_packet_tb    := $(RTL_DIR)/s9_mem_event_packet.v
SRC_s9_mem_stage_ctrl_tb      := $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s9_mem_stage_ctrl.v
SRC_s9_backend_mem_tb         := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/backend_slot1_stage_emit.v $(RTL_DIR)/s9_slot0_result_packet.v $(RTL_DIR)/s9_slot0_pipe_regs.v $(RTL_DIR)/s9_slot1_result_packet.v $(RTL_DIR)/s9_slot1_owner_packet.v $(RTL_DIR)/backend_slot1_result_pipe_regs.v $(RTL_DIR)/s9_slot1_pipe_regs.v $(RTL_DIR)/s9_lsu_lane_select.v $(RTL_DIR)/s9_dcache_req_packet.v $(RTL_DIR)/s9_shared_mem_request_packet.v $(RTL_DIR)/s9_mem_event_packet.v $(RTL_DIR)/s9_mem_stage_ctrl.v $(RTL_DIR)/s9_backend_mem.v
SRC_s10_load_data_format_tb   := $(RTL_DIR)/s10_load_data_format.v
SRC_s10_slot0_pipe_regs_tb    := $(RTL_DIR)/s10_slot0_pipe_regs.v
SRC_s10_slot0_wb_packet_tb    := $(RTL_DIR)/s10_slot0_wb_packet.v
SRC_s10_slot1_commit_packet_tb := $(RTL_DIR)/s10_slot1_commit_packet.v
SRC_s10_slot1_pipe_regs_tb    := $(RTL_DIR)/backend_slot1_result_pipe_regs.v $(RTL_DIR)/s10_slot1_pipe_regs.v
SRC_s10_slot1_wb_packet_tb    := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s10_slot1_wb_packet.v
SRC_s10_slot1_mem_ctrl_tb     := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s10_slot1_mem_ctrl.v
SRC_s10_shared_mem_outcome_tb := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s10_slot1_mem_ctrl.v $(RTL_DIR)/s10_dcache_resp_owner.v $(RTL_DIR)/s10_slot1_wb_packet.v $(RTL_DIR)/s10_shared_mem_outcome.v
SRC_s10_wb_stage_ctrl_tb      := $(RTL_DIR)/s10_wb_stage_ctrl.v
SRC_s10_feedback_packet_tb    := $(RTL_DIR)/s10_feedback_packet.v
SRC_s10_raw_mem_event_select_tb := $(RTL_DIR)/s10_raw_mem_event_select.v
SRC_s10_difftest_mem_select_tb := $(RTL_DIR)/s10_difftest_mem_select.v
SRC_s10_commit_select_tb      := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s10_commit_select.v
SRC_s10_wb_select_tb          := $(RTL_DIR)/s10_wb_select.v
SRC_s10_ordered_commit_bank_tb := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s10_feedback_packet.v $(RTL_DIR)/s10_difftest_mem_select.v $(RTL_DIR)/s10_commit_select.v $(RTL_DIR)/s10_wb_select.v $(RTL_DIR)/s10_ordered_commit_bank.v $(RTL_DIR)/s10_commit_event_packet.v $(RTL_DIR)/s10_commit_output_packet.v
SRC_s10_commit_event_packet_tb := $(RTL_DIR)/s10_commit_event_packet.v
SRC_s10_commit_output_packet_tb := $(RTL_DIR)/s10_commit_output_packet.v
SRC_s10_backend_wb_tb         := $(RTL_DIR)/backend_slot1_activity.v $(RTL_DIR)/s10_load_data_format.v $(RTL_DIR)/s10_slot0_pipe_regs.v $(RTL_DIR)/s10_slot0_wb_packet.v $(RTL_DIR)/s10_slot1_commit_packet.v $(RTL_DIR)/backend_slot1_result_pipe_regs.v $(RTL_DIR)/s10_slot1_pipe_regs.v $(RTL_DIR)/s10_slot1_wb_packet.v $(RTL_DIR)/s10_slot1_mem_ctrl.v $(RTL_DIR)/s10_dcache_resp_owner.v $(RTL_DIR)/s10_shared_mem_outcome.v $(RTL_DIR)/s10_shared_mem_pipe_regs.v $(RTL_DIR)/s10_wb_stage_ctrl.v $(RTL_DIR)/s10_feedback_packet.v $(RTL_DIR)/s10_raw_mem_event_select.v $(RTL_DIR)/s10_difftest_mem_select.v $(RTL_DIR)/s10_commit_select.v $(RTL_DIR)/s10_wb_select.v $(RTL_DIR)/s10_ordered_commit_bank.v $(RTL_DIR)/s10_commit_event_packet.v $(RTL_DIR)/s10_commit_output_packet.v $(RTL_DIR)/s10_backend_wb.v
SRC_sram_wrap_tb              := $(LA_DIR)/DPIC/sram_wrap.v
SRC_verilator_top_tb          := $(PIPELINE_RTL) $(RTL_DIR)/verilator_top.v

BUILD_TARGETS := $(foreach test,$(TESTS),$(OBJ_DIR)/$(test)/V$(test))
RUN_TARGETS   := $(addprefix run-,$(CASES))

.PHONY: all build run clean list $(RUN_TARGETS) $(addprefix run-,$(TESTS))

all: run

build: $(BUILD_TARGETS)

ifneq ($(CASE),)
run: run-$(CASE_NAME)
else
run: $(RUN_TARGETS)
endif

list:
	@printf '%s\n' $(CASES)

define TEST_RULE
$(OBJ_DIR)/$(1)/V$(1): $(TEST_DIR)/$(1).sv $$(SRC_$(1)) $(TEST_DIR)/tb_common.svh $(RTL_DIR)/rtl_debug.vh Makefile
	@mkdir -p $(OBJ_DIR)/$(1)
	$(VERILATOR) $(VFLAGS) --top-module $(1) --Mdir $(OBJ_DIR)/$(1) $(TEST_DIR)/$(1).sv $$(SRC_$(1))

run-$(patsubst %_tb,%,$(1)): $(OBJ_DIR)/$(1)/V$(1)
	@mkdir -p $(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))
	@./$(OBJ_DIR)/$(1)/V$(1) +WAVE=$(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))/wave.vcd +TB_DEBUG +DEBUG_LEVEL=$(DEBUG_LEVEL) +DEBUG_WINDOW=$(DEBUG_WINDOW) $(DEBUG_FATAL_PLUSARG) $(EXTRA_PLUSARGS) 2>&1 \
		| tee >(awk '/^\[RTL-/{print}' > $(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))/debug.txt) \
		| awk '!/^\[RTL-/{print}' \
		| tee $(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))/log.txt

run-$(1): run-$(patsubst %_tb,%,$(1))
endef

$(foreach test,$(TESTS),$(eval $(call TEST_RULE,$(test))))

clean:
	rm -rf $(OBJ_DIR) obj_dir $(OUTPUT_DIR) logs wave.vcd wave.fst

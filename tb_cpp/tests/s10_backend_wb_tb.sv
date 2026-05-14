`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s10_backend_wb_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, in_valid, allowin;
    logic wb_en_i, is_load_i, is_store_i, mem_uncached_i, mem_sign_ext_i, exception_i;
    logic is_csr_i, csr_we_i, csr_xchg_i, is_syscall_i, is_ertn_i;
    logic dc_valid, dc_fault, rf_we, commit_valid, commit1_valid, valid_o, wb_en_raw_o, load_wait_o, slot1_load_wait_o, load_uncached_o;
    logic csr_we_o, excp_flush_o, ertn_flush_o, idle_flush_o, ibar_flush_o, excp_badv_valid_i, excp_badv_valid_o;
    logic tlbsrch_valid_o, tlbrd_valid_o, tlbwr_valid_o, tlbfill_valid_o, invtlb_valid_o;
    logic cacop_ready_i, cacop_done_i, cacop_valid_o, cacop_is_icache_o, cacop_is_dcache_o, icacop_flush_o;
    logic dual_commit_enable_i, debug_unknown_inst_i;
    logic wb0_we_o, wb1_we_o, commit_event0_valid_o, commit_event1_valid_o, commit_event1_accept_o, commit_event_dual_commit_o;
    logic commit_event_wb0_we_o, commit_event_wb1_we_o, commit_event_dual_wb_o;
    logic fb_valid_o, fb_wb_en_o, fb_load_wait_o, fb_load_uncached_o, fb_slot1_issue_valid_o, fb_slot1_wb_en_o, fb_slot1_load_wait_o;
    logic debug_wb_rf_wen_o, debug1_wb_rf_wen_o, debug_unknown_inst_o;
    logic commit_event_slot1_commit_held_o, commit_event_slot1_wb_held_o;
    logic [31:0] pc_i, instr_i, wb_pre_i, dc_data, rf_wdata, commit_pc, commit_instr, commit1_pc, commit1_instr, wb_data_raw_o;
    logic [31:0] slot1_pc_i, instr1_i, slot1_imm_i, slot1_alu_result_i, slot1_store_data_i;
    logic [31:0] slot1_pc_o, instr1_o, slot1_imm_o, slot1_alu_result_o, slot1_store_data_o;
    logic [31:0] wb0_wdata_o, wb1_wdata_o, fb_result_o, fb_slot1_result_o, debug_wb_pc_o, debug_wb_rf_wdata_o, debug1_wb_pc_o, debug1_wb_rf_wdata_o;
    logic slot1_mem_lsu_o;
    logic [31:0] csr_rdata_i, csr_wdata_i, csr_wmask_i, csr_wdata_o, excp_pc_o;
    logic [31:0] cacop_addr_o;
    logic [31:0] excp_badv_i, excp_badv_o;
    logic [1:0] epoch_i, epoch_o;
    logic [13:0] csr_addr_i, csr_raddr_o, csr_waddr_o;
    logic [5:0] excp_ecode_i, excp_ecode_o;
    logic [8:0] excp_esubcode_i, excp_esubcode_o;
    logic [4:0] rd_i, rf_waddr, rd_raw_o, invtlb_op_o, wb0_waddr_o, wb1_waddr_o, fb_rd_o, fb_slot1_rd_o, debug_wb_rf_wnum_o, debug1_wb_rf_wnum_o;
    logic [4:0] slot1_op_19_15_i, slot1_rs1_i, slot1_rs2_i, slot1_rd_i;
    logic [4:0] slot1_op_19_15_o, slot1_rs1_o, slot1_rs2_o, slot1_rd_o;
    logic [9:0] invtlb_asid_o;
    logic [18:0] invtlb_vpn_o;
    logic [3:0] commit_event_select_reason_o, commit_event_wb_reason_o;
    logic [7:0] commit_event_reason_o;
    logic [1:0] mem_size_i, cacop_mode_o;
    logic [1:0] slot1_src_a_sel_i, slot1_src_b_sel_i, slot1_mem_size_i;
    logic [1:0] slot1_src_a_sel_o, slot1_src_b_sel_o, slot1_mem_size_o;
    logic [3:0] slot1_alu_op_i, slot1_alu_op_o;
    logic s9_is_ll_i, s9_is_sc_i, s9_sc_success_i;
    logic slot1_valid_i, slot1_is_branch_i, slot1_is_jal_i, slot1_is_jalr_i, slot1_is_load_i, slot1_is_store_i, slot1_is_lui_i, slot1_is_auipc_i, slot1_unknown_i;
    logic slot1_wb_en_i, slot1_uses_rs1_i, slot1_uses_rs2_i, slot1_issue_valid_i;
    logic slot1_valid_o, slot1_is_branch_o, slot1_is_jal_o, slot1_is_jalr_o, slot1_is_load_o, slot1_is_store_o, slot1_is_lui_o, slot1_is_auipc_o, slot1_unknown_o;
    logic slot1_wb_en_o, slot1_uses_rs1_o, slot1_uses_rs2_o, slot1_issue_valid_o;
    logic [3:0] slot1_issue_class_i, slot1_issue_class_o;
    logic slot1_exception_i, slot1_excp_badv_valid_i;
    logic slot1_exception_o, slot1_excp_badv_valid_o;
    logic [5:0] slot1_excp_ecode_i, slot1_excp_ecode_o;
    logic [8:0] slot1_excp_esubcode_i, slot1_excp_esubcode_o;
    logic [31:0] slot1_excp_badv_i, slot1_excp_badv_o;
    logic slot1_refetch_o;
    logic [31:0] slot1_refetch_pc_o;
    logic slot1_rf_we_candidate_o;
    logic [4:0] slot1_rf_waddr_candidate_o;
    logic [31:0] slot1_rf_wdata_candidate_o;
    logic [6:0] slot1_opcode_i, slot1_funct7_i, slot1_opcode_o, slot1_funct7_o;
    logic [2:0] slot1_funct3_i, slot1_funct3_o;
    logic llbit_set_o, llbit_value_o, lladdr_set_o;
    logic [27:0] lladdr_value_o;
    logic [31:0] s9_mem_paddr_i;
    wire slot1_mem_lsu_i =
        slot1_valid_i && slot1_issue_valid_i &&
        (slot1_is_load_i || slot1_is_store_i) &&
        !is_load_i && !is_store_i && !exception_i;
    wire shared_mem_owner_slot1_i = slot1_mem_lsu_i;
    wire shared_mem_owner_slot0_i =
        (is_load_i || is_store_i) && !shared_mem_owner_slot1_i;
    wire shared_mem_valid_i =
        shared_mem_owner_slot0_i || shared_mem_owner_slot1_i;
    wire shared_mem_slot0_req_i =
        shared_mem_owner_slot0_i && !exception_i &&
        (is_load_i || (is_store_i && (!s9_is_sc_i || s9_sc_success_i)));
    wire shared_mem_slot1_req_i =
        shared_mem_owner_slot1_i && !slot1_exception_i;
    wire shared_mem_slot1_load_i =
        shared_mem_owner_slot1_i && slot1_is_load_i;
    wire shared_mem_slot1_store_i =
        shared_mem_owner_slot1_i && slot1_is_store_i;
`ifdef DIFFTEST_EN
    logic [31:0] diff_mem_vaddr_i, diff_mem_paddr_i, diff_store_data_i;
    logic [7:0] diff_load_valid_o, diff_store_valid_o;
    logic [31:0] diff_load_paddr_o, diff_load_vaddr_o;
    logic [31:0] diff_store_paddr_o, diff_store_vaddr_o, diff_store_data_o;
    logic diff_csr_rstat_o;
    logic [31:0] diff_csr_data_o;
    logic [7:0] diff_commit_load_valid_o, diff_commit_store_valid_o;
    logic [31:0] diff_commit_load_paddr_o, diff_commit_load_vaddr_o;
    logic [31:0] diff_commit_store_paddr_o, diff_commit_store_vaddr_o, diff_commit_store_data_o;
`endif

    function automatic [31:0] la_tlb_barrier(input [4:0] rk);
        la_tlb_barrier = {6'h01, 4'h9, 2'h0, 5'h10, rk, 5'd0, 5'd0};
    endfunction

    function automatic [31:0] la_invtlb(input [4:0] op, input [4:0] rj, input [4:0] rk);
        la_invtlb = {6'h01, 4'h9, 2'h0, 5'h13, rk, rj, op};
    endfunction

    function automatic [31:0] la_cacop(input [4:0] op, input [4:0] rj, input [11:0] imm);
        la_cacop = {6'h01, 4'h8, imm, rj, op};
    endfunction
    function automatic [31:0] la_special(input [5:0] op31_26, input [3:0] op25_22,
                                          input [1:0] op21_20, input [4:0] op19_15,
                                          input [4:0] rk, input [4:0] rj, input [4:0] rd);
        la_special = {op31_26, op25_22, op21_20, op19_15, rk, rj, rd};
    endfunction
    function automatic [31:0] la_sc_w(input [4:0] rd, input [4:0] rj, input [13:0] imm14);
        la_sc_w = {6'h08, 1'b0, 1'b1, imm14, rj, rd};
    endfunction

    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction

    always_comb begin
        slot1_issue_class_i = 4'd0;
        if (slot1_issue_valid_i) begin
            if (slot1_is_load_i)
                slot1_issue_class_i = 4'b0100;
            else if (slot1_is_store_i)
                slot1_issue_class_i = 4'b0010;
            else if (slot1_is_branch_i || slot1_is_jal_i || slot1_is_jalr_i)
                slot1_issue_class_i = 4'b0001;
            else
                slot1_issue_class_i = 4'b1000;
        end
    end

    s10_backend_wb #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .s9_to_s10_valid(in_valid),
        .s10_allowin(allowin), .s9_pc_i(pc_i), .s9_instr_i(instr_i), .s9_rd_i(rd_i),
        .s9_epoch_i(epoch_i),
        .s9_wb_en_i(wb_en_i), .s9_wb_data_pre_i(wb_pre_i), .s9_is_load_i(is_load_i),
        .s9_is_store_i(is_store_i), .s9_mem_uncached_i(mem_uncached_i),
        .s9_mem_size_i(mem_size_i), .s9_mem_sign_ext_i(mem_sign_ext_i),
        .s9_exception_i(exception_i),
        .s9_excp_ecode_i(excp_ecode_i), .s9_excp_esubcode_i(excp_esubcode_i),
        .s9_excp_badv_valid_i(excp_badv_valid_i), .s9_excp_badv_i(excp_badv_i),
        .dc_resp_valid_i(dc_valid), .dc_resp_data_i(dc_data),
        .dual_commit_enable_i(dual_commit_enable_i),
        .debug_unknown_inst_i(debug_unknown_inst_i),
        .s9_is_csr_i(is_csr_i), .s9_csr_we_i(csr_we_i), .s9_csr_xchg_i(csr_xchg_i),
        .s9_csr_addr_i(csr_addr_i), .s9_csr_wdata_i(csr_wdata_i), .s9_csr_wmask_i(csr_wmask_i),
        .s9_is_syscall_i(is_syscall_i), .s9_is_ertn_i(is_ertn_i),
        .s9_is_ll_i(s9_is_ll_i), .s9_is_sc_i(s9_is_sc_i),
        .s9_sc_success_i(s9_sc_success_i), .s9_mem_paddr_i(s9_mem_paddr_i),
        .s9_slot1_pc_i(slot1_pc_i), .s9_instr1_i(instr1_i), .s9_slot1_valid_i(slot1_valid_i),
        .s9_slot1_opcode_i(slot1_opcode_i), .s9_slot1_funct3_i(slot1_funct3_i),
        .s9_slot1_funct7_i(slot1_funct7_i), .s9_slot1_op_19_15_i(slot1_op_19_15_i),
        .s9_slot1_rs1_i(slot1_rs1_i), .s9_slot1_rs2_i(slot1_rs2_i), .s9_slot1_rd_i(slot1_rd_i),
        .s9_slot1_imm_i(slot1_imm_i), .s9_slot1_is_branch_i(slot1_is_branch_i),
        .s9_slot1_is_jal_i(slot1_is_jal_i), .s9_slot1_is_jalr_i(slot1_is_jalr_i),
        .s9_slot1_is_load_i(slot1_is_load_i), .s9_slot1_is_store_i(slot1_is_store_i),
        .s9_slot1_is_lui_i(slot1_is_lui_i), .s9_slot1_is_auipc_i(slot1_is_auipc_i),
        .s9_slot1_unknown_inst_i(slot1_unknown_i),
        .s9_slot1_wb_en_i(slot1_wb_en_i), .s9_slot1_uses_rs1_i(slot1_uses_rs1_i),
        .s9_slot1_uses_rs2_i(slot1_uses_rs2_i), .s9_slot1_src_a_sel_i(slot1_src_a_sel_i),
        .s9_slot1_src_b_sel_i(slot1_src_b_sel_i), .s9_slot1_alu_op_i(slot1_alu_op_i),
        .s9_slot1_alu_result_i(slot1_alu_result_i),
        .s9_slot1_mem_size_i(slot1_mem_size_i),
        .s9_slot1_store_data_i(slot1_store_data_i),
        .s9_slot1_mem_lsu_i(slot1_mem_lsu_i),
        .s9_slot1_exception_i(slot1_exception_i),
        .s9_slot1_excp_ecode_i(slot1_excp_ecode_i),
        .s9_slot1_excp_esubcode_i(slot1_excp_esubcode_i),
        .s9_slot1_excp_badv_valid_i(slot1_excp_badv_valid_i),
        .s9_slot1_excp_badv_i(slot1_excp_badv_i),
        .s9_slot1_issue_valid_i(slot1_issue_valid_i),
        .s9_slot1_issue_class_i(slot1_issue_class_i),
        .s9_shared_mem_valid_i(shared_mem_valid_i),
        .s9_shared_mem_req_valid_i(shared_mem_slot0_req_i || shared_mem_slot1_req_i),
        .s9_shared_mem_mem_req_i(shared_mem_slot0_req_i || shared_mem_slot1_req_i),
        .s9_shared_mem_preld_req_i(1'b0),
        .s9_shared_mem_owner_slot0_i(shared_mem_owner_slot0_i),
        .s9_shared_mem_owner_slot1_i(shared_mem_owner_slot1_i),
        .s9_shared_mem_slot0_req_i(shared_mem_slot0_req_i),
        .s9_shared_mem_slot1_req_i(shared_mem_slot1_req_i),
        .s9_shared_mem_slot1_load_i(shared_mem_slot1_load_i),
        .s9_shared_mem_slot1_store_i(shared_mem_slot1_store_i),
        .s9_shared_mem_lane1_exception_i(shared_mem_owner_slot1_i && slot1_exception_i),
        .s9_shared_mem_lane0_tlb_exception_i(1'b0),
        .s9_shared_mem_lane1_tlb_exception_i(1'b0),
`ifdef DIFFTEST_EN
        .s9_diff_mem_vaddr_i(diff_mem_vaddr_i),
        .s9_diff_mem_paddr_i(diff_mem_paddr_i),
        .s9_diff_store_data_i(diff_store_data_i),
`endif
        .dc_resp_fault_i(dc_fault),
        .cacop_ready_i(cacop_ready_i), .cacop_done_i(cacop_done_i),
        .cacop_valid_o(cacop_valid_o), .cacop_is_icache_o(cacop_is_icache_o),
        .cacop_is_dcache_o(cacop_is_dcache_o), .cacop_mode_o(cacop_mode_o),
        .cacop_addr_o(cacop_addr_o), .icacop_flush_o(icacop_flush_o),
        .csr_rdata_i(csr_rdata_i), .csr_raddr_o(csr_raddr_o), .csr_we_o(csr_we_o),
        .csr_waddr_o(csr_waddr_o), .csr_wdata_o(csr_wdata_o),
        .excp_flush_o(excp_flush_o), .ertn_flush_o(ertn_flush_o),
        .idle_flush_o(idle_flush_o), .ibar_flush_o(ibar_flush_o),
        .slot1_refetch_o(slot1_refetch_o),
        .slot1_refetch_pc_o(slot1_refetch_pc_o),
        .excp_pc_o(excp_pc_o), .excp_ecode_o(excp_ecode_o), .excp_esubcode_o(excp_esubcode_o),
        .excp_badv_valid_o(excp_badv_valid_o), .excp_badv_o(excp_badv_o),
        .llbit_set_o(llbit_set_o), .llbit_value_o(llbit_value_o),
        .lladdr_set_o(lladdr_set_o), .lladdr_value_o(lladdr_value_o),
        .tlbsrch_valid_o(tlbsrch_valid_o), .tlbrd_valid_o(tlbrd_valid_o),
        .tlbwr_valid_o(tlbwr_valid_o), .tlbfill_valid_o(tlbfill_valid_o),
        .invtlb_valid_o(invtlb_valid_o), .invtlb_op_o(invtlb_op_o),
        .invtlb_asid_o(invtlb_asid_o), .invtlb_vpn_o(invtlb_vpn_o),
        .rf_we_o(rf_we), .rf_waddr_o(rf_waddr), .rf_wdata_o(rf_wdata),
        .commit_valid_o(commit_valid), .commit_pc_o(commit_pc), .commit_instr_o(commit_instr),
        .commit1_valid_o(commit1_valid), .commit1_pc_o(commit1_pc), .commit1_instr_o(commit1_instr),
        .s10_slot1_pc_o(slot1_pc_o), .s10_instr1_o(instr1_o), .s10_slot1_valid_o(slot1_valid_o),
        .s10_slot1_opcode_o(slot1_opcode_o), .s10_slot1_funct3_o(slot1_funct3_o),
        .s10_slot1_funct7_o(slot1_funct7_o), .s10_slot1_op_19_15_o(slot1_op_19_15_o),
        .s10_slot1_rs1_o(slot1_rs1_o), .s10_slot1_rs2_o(slot1_rs2_o), .s10_slot1_rd_o(slot1_rd_o),
        .s10_slot1_imm_o(slot1_imm_o), .s10_slot1_is_branch_o(slot1_is_branch_o),
        .s10_slot1_is_jal_o(slot1_is_jal_o), .s10_slot1_is_jalr_o(slot1_is_jalr_o),
        .s10_slot1_is_load_o(slot1_is_load_o), .s10_slot1_is_store_o(slot1_is_store_o),
        .s10_slot1_is_lui_o(slot1_is_lui_o), .s10_slot1_is_auipc_o(slot1_is_auipc_o),
        .s10_slot1_unknown_inst_o(slot1_unknown_o),
        .s10_slot1_wb_en_o(slot1_wb_en_o), .s10_slot1_uses_rs1_o(slot1_uses_rs1_o),
        .s10_slot1_uses_rs2_o(slot1_uses_rs2_o), .s10_slot1_src_a_sel_o(slot1_src_a_sel_o),
        .s10_slot1_src_b_sel_o(slot1_src_b_sel_o), .s10_slot1_alu_op_o(slot1_alu_op_o),
        .s10_slot1_alu_result_o(slot1_alu_result_o),
        .s10_slot1_mem_size_o(slot1_mem_size_o),
        .s10_slot1_store_data_o(slot1_store_data_o),
        .s10_slot1_mem_lsu_o(slot1_mem_lsu_o),
        .s10_slot1_exception_o(slot1_exception_o),
        .s10_slot1_excp_ecode_o(slot1_excp_ecode_o),
        .s10_slot1_excp_esubcode_o(slot1_excp_esubcode_o),
        .s10_slot1_excp_badv_valid_o(slot1_excp_badv_valid_o),
        .s10_slot1_excp_badv_o(slot1_excp_badv_o),
        .s10_slot1_rf_we_candidate_o(slot1_rf_we_candidate_o),
        .s10_slot1_rf_waddr_candidate_o(slot1_rf_waddr_candidate_o),
        .s10_slot1_rf_wdata_candidate_o(slot1_rf_wdata_candidate_o),
        .s10_slot1_issue_valid_o(slot1_issue_valid_o),
        .s10_slot1_issue_class_o(slot1_issue_class_o),
        .wb0_we_o(wb0_we_o), .wb0_waddr_o(wb0_waddr_o), .wb0_wdata_o(wb0_wdata_o),
        .wb1_we_o(wb1_we_o), .wb1_waddr_o(wb1_waddr_o), .wb1_wdata_o(wb1_wdata_o),
        .commit_event0_valid_o(commit_event0_valid_o),
        .commit_event1_valid_o(commit_event1_valid_o),
        .commit_event1_accept_o(commit_event1_accept_o),
        .commit_event_dual_commit_o(commit_event_dual_commit_o),
        .commit_event_select_reason_o(commit_event_select_reason_o),
        .commit_event_wb0_we_o(commit_event_wb0_we_o),
        .commit_event_wb1_we_o(commit_event_wb1_we_o),
        .commit_event_dual_wb_o(commit_event_dual_wb_o),
        .commit_event_wb_reason_o(commit_event_wb_reason_o),
        .commit_event_slot1_commit_held_o(commit_event_slot1_commit_held_o),
        .commit_event_slot1_wb_held_o(commit_event_slot1_wb_held_o),
        .commit_event_reason_o(commit_event_reason_o),
        .fb_valid_o(fb_valid_o), .fb_wb_en_o(fb_wb_en_o),
        .fb_load_wait_o(fb_load_wait_o), .fb_load_uncached_o(fb_load_uncached_o),
        .fb_rd_o(fb_rd_o), .fb_result_o(fb_result_o),
        .fb_slot1_issue_valid_o(fb_slot1_issue_valid_o),
        .fb_slot1_wb_en_o(fb_slot1_wb_en_o),
        .fb_slot1_load_wait_o(fb_slot1_load_wait_o),
        .fb_slot1_rd_o(fb_slot1_rd_o),
        .fb_slot1_result_o(fb_slot1_result_o),
        .debug_wb_rf_wen_o(debug_wb_rf_wen_o),
        .debug_wb_rf_wnum_o(debug_wb_rf_wnum_o),
        .debug_wb_pc_o(debug_wb_pc_o),
        .debug_wb_rf_wdata_o(debug_wb_rf_wdata_o),
        .debug1_wb_rf_wen_o(debug1_wb_rf_wen_o),
        .debug1_wb_rf_wnum_o(debug1_wb_rf_wnum_o),
        .debug1_wb_pc_o(debug1_wb_pc_o),
        .debug1_wb_rf_wdata_o(debug1_wb_rf_wdata_o),
        .debug_unknown_inst_o(debug_unknown_inst_o),
`ifdef DIFFTEST_EN
        .diff_load_valid_o(diff_load_valid_o),
        .diff_load_paddr_o(diff_load_paddr_o),
        .diff_load_vaddr_o(diff_load_vaddr_o),
        .diff_store_valid_o(diff_store_valid_o),
        .diff_store_paddr_o(diff_store_paddr_o),
        .diff_store_vaddr_o(diff_store_vaddr_o),
        .diff_store_data_o(diff_store_data_o),
        .diff_csr_rstat_o(diff_csr_rstat_o),
        .diff_csr_data_o(diff_csr_data_o),
        .diff_commit_load_valid_o(diff_commit_load_valid_o),
        .diff_commit_load_paddr_o(diff_commit_load_paddr_o),
        .diff_commit_load_vaddr_o(diff_commit_load_vaddr_o),
        .diff_commit_store_valid_o(diff_commit_store_valid_o),
        .diff_commit_store_paddr_o(diff_commit_store_paddr_o),
        .diff_commit_store_vaddr_o(diff_commit_store_vaddr_o),
        .diff_commit_store_data_o(diff_commit_store_data_o),
`endif
        .s10_valid_o(valid_o), .s10_wb_en_raw_o(wb_en_raw_o), .s10_rd_raw_o(rd_raw_o),
        .s10_wb_data_raw_o(wb_data_raw_o), .s10_load_wait_o(load_wait_o),
        .s10_slot1_load_wait_o(slot1_load_wait_o),
        .s10_load_uncached_o(load_uncached_o), .s10_epoch_o(epoch_o)
    );

    initial begin
        tb_start();
        flush = 0; in_valid = 0; pc_i = 32'h1c010000; instr_i = 32'h0;
        epoch_i = 2'd3; rd_i = 5'd4; wb_en_i = 1; wb_pre_i = 32'h50;
        is_load_i = 0; is_store_i = 0; mem_uncached_i = 0; mem_size_i = 2'b10; mem_sign_ext_i = 0; exception_i = 0; dc_valid = 0; dc_data = 0; dc_fault = 0;
        excp_ecode_i = 0; excp_esubcode_i = 0; excp_badv_valid_i = 0; excp_badv_i = 0;
        is_csr_i = 0; csr_we_i = 0; csr_xchg_i = 0; csr_addr_i = 0; csr_wdata_i = 0; csr_wmask_i = 0;
        is_syscall_i = 0; is_ertn_i = 0; csr_rdata_i = 0;
        cacop_ready_i = 1; cacop_done_i = 0;
        dual_commit_enable_i = 1'b0; debug_unknown_inst_i = 1'b0;
        s9_is_ll_i = 0; s9_is_sc_i = 0; s9_sc_success_i = 0; s9_mem_paddr_i = 32'h0;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h0; slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_alu_result_i = 32'd0;
        slot1_mem_size_i = 2'd0; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_ecode_i = 6'd0; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b0; slot1_excp_badv_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h0; diff_mem_paddr_i = 32'h0; diff_store_data_i = 32'h0;
`endif
        reset_dut();
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 ALU commit", commit_valid && rf_we);
        `check("S10 epoch latch", epoch_o == 2'd3);
        `check32("S10 ALU writeback", rf_wdata, 32'h50);
        `check("S10 slot0-only keeps commit1 closed", !commit1_valid && !wb1_we_o && !commit_event1_valid_o);
        `check("S10 slot0-only ordered wb/debug stay on lane0",
               wb0_we_o && commit_event0_valid_o && debug_wb_rf_wen_o &&
               !debug1_wb_rf_wen_o && !debug_unknown_inst_o);
        `check32("S10 slot0-only wb0 addr", {27'd0, wb0_waddr_o}, 32'd4);
        `check32("S10 slot0-only feedback rd", {27'd0, fb_rd_o}, 32'd4);
        `check32("S10 slot0-only feedback result", fb_result_o, 32'h50);

        wb_en_i = 1'b1; rd_i = 5'd4; wb_pre_i = 32'h60;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        dc_valid = 1'b0; dc_fault = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 stale DCache fault does not poison ALU commit",
               commit_valid && rf_we && !excp_flush_o);
        `check32("S10 stale DCache fault ALU writeback", rf_wdata, 32'h60);
        dc_fault = 1'b0;

        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h02801085;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd4; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd5; slot1_imm_i = 32'h4;
        slot1_alu_result_i = 32'h1234_0008;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 slot1 sideband pass-through",
               slot1_valid_o && slot1_pc_o == 32'h1c010004 && instr1_o == 32'h02801085);
        `check32("S10 slot1 rs1 pass", {27'h0, slot1_rs1_o}, 32'd4);
        `check32("S10 slot1 rd pass", {27'h0, slot1_rd_o}, 32'd5);
        `check32("S10 slot1 imm pass", slot1_imm_o, 32'h4);
        `check("S10 slot1 kind pass",
               !slot1_unknown_o && !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check("S10 slot1 simple ALU payload pass",
               slot1_wb_en_o && slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 && slot1_src_b_sel_o == `CPU_SRC_B_IMM &&
               slot1_alu_op_o == `CPU_ALU_ADD);
        `check32("S10 slot1 shadow ALU result pass", slot1_alu_result_o, 32'h1234_0008);
        `check("S10 slot1 issue sideband stays off in phase1", !slot1_issue_valid_o);
        `check32("S10 slot1 issue class stays off in phase1", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S10 slot1 ALU does not own LSU in phase1", !slot1_mem_lsu_o);
        `check("S10 slot1 shadow RF candidate stays off in phase1", !slot1_rf_we_candidate_o);
        `check32("S10 slot1 shadow RF candidate addr clears when off",
                 {27'd0, slot1_rf_waddr_candidate_o}, 32'd0);
        `check32("S10 slot1 shadow RF candidate data clears when off",
                 slot1_rf_wdata_candidate_o, 32'd0);
        slot1_issue_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 slot1 shadow RF candidate can be formed",
               slot1_issue_valid_o && slot1_rf_we_candidate_o);
        `check32("S10 selected slot1 ALU carries compute class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        `check("S10 selected slot1 ALU still does not own LSU", !slot1_mem_lsu_o);
        `check("S10 real RF write still belongs to slot0",
               rf_we && rf_waddr == rd_i && rf_wdata == wb_pre_i);
        `check32("S10 slot1 shadow RF candidate addr",
                 {27'd0, slot1_rf_waddr_candidate_o}, 32'd5);
        `check32("S10 slot1 shadow RF candidate data",
                 slot1_rf_wdata_candidate_o, 32'h1234_0008);
        `check32("S10 selected slot1 ALU has no store size sideband",
                 {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("S10 selected slot1 ALU has no store data sideband", slot1_store_data_o, 32'd0);
        `check("S10 phase1 holds slot1 ordered visibility",
               !commit1_valid && !wb1_we_o && !commit_event1_valid_o &&
               !commit_event1_accept_o && !commit_event_dual_commit_o &&
               !fb_slot1_issue_valid_o && !fb_slot1_wb_en_o &&
               !debug1_wb_rf_wen_o);
        `check("S10 phase1 slot1 hold reason is explicit",
               commit_event_slot1_commit_held_o && commit_event_slot1_wb_held_o);

        dual_commit_enable_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 dual-enabled accepts ordered slot1 commit",
               commit_valid && commit1_valid && wb0_we_o && wb1_we_o &&
               commit_event0_valid_o && commit_event1_valid_o &&
               commit_event1_accept_o && commit_event_dual_commit_o &&
               debug_wb_rf_wen_o && debug1_wb_rf_wen_o);
        `check("S10 dual-enabled raises dual writeback event",
               commit_event_wb0_we_o && commit_event_wb1_we_o &&
               commit_event_dual_wb_o && fb_slot1_issue_valid_o &&
               fb_slot1_wb_en_o);
        `check32("S10 dual-enabled commit1 pc", commit1_pc, 32'h1c010004);
        `check32("S10 dual-enabled commit1 instr", commit1_instr, 32'h02801085);
        `check32("S10 dual-enabled wb1 addr", {27'd0, wb1_waddr_o}, 32'd5);
        `check32("S10 dual-enabled wb1 data", wb1_wdata_o, 32'h1234_0008);
        `check32("S10 dual-enabled feedback slot1 rd", {27'd0, fb_slot1_rd_o}, 32'd5);
        `check32("S10 dual-enabled feedback slot1 result", fb_slot1_result_o, 32'h1234_0008);
        `check32("S10 dual-enabled debug1 pc", debug1_wb_pc_o, 32'h1c010004);
        `check32("S10 dual-enabled debug1 wnum", {27'd0, debug1_wb_rf_wnum_o}, 32'd5);
        `check32("S10 dual-enabled debug1 wdata", debug1_wb_rf_wdata_o, 32'h1234_0008);
        dual_commit_enable_i = 1'b0;

        wb_en_i = 1'b0; rd_i = 5'd0; wb_pre_i = 32'h0;
        is_load_i = 1'b0; is_store_i = 1'b0; mem_uncached_i = 1'b0;
        exception_i = 1'b0; dc_valid = 1'b0; dc_fault = 1'b0;
        slot1_issue_valid_i = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c010008; instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h008);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd12; slot1_rd_i = 5'd12; slot1_imm_i = 32'h8;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_alu_result_i = 32'h0000_8808;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h1357_9bdf;
        slot1_exception_i = 1'b0; slot1_excp_ecode_i = 6'd0; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b0; slot1_excp_badv_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 unissued slot1 store commits lane0 bubble without waiting",
               commit_valid && allowin && !load_wait_o);
        `check("S10 slot1 store prepare remains sideband-only",
               slot1_valid_o && slot1_is_store_o && !slot1_issue_valid_o &&
               !slot1_wb_en_o && !slot1_rf_we_candidate_o);
        `check32("S10 unissued slot1 store clears issue class",
                 {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S10 unissued slot1 store does not own LSU", !slot1_mem_lsu_o);
        `check32("S10 slot1 store prepare address pass", slot1_alu_result_o, 32'h0000_8808);
        `check32("S10 slot1 store prepare size pass", {30'd0, slot1_mem_size_o}, 32'd2);
        `check32("S10 slot1 store prepare data pass", slot1_store_data_o, 32'h1357_9bdf);
        `check("S10 aligned slot1 store prepare has no exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check("S10 unissued slot1 store has no lane0 side effects",
               !rf_we && !csr_we_o && !excp_flush_o && !ertn_flush_o && !cacop_valid_o);
`ifdef DIFFTEST_EN
        `check("S10 unissued slot1 store has no difftest store event",
               diff_store_valid_o == 8'h00);
`endif

        slot1_issue_valid_i = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c010008; instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_imm_i = 32'h6;
        slot1_alu_result_i = 32'h0000_8806;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h1357_9bdf;
        slot1_exception_i = 1'b1; slot1_excp_ecode_i = `CPU_ECODE_ALE; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b1; slot1_excp_badv_i = 32'h0000_8806;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 unissued unaligned slot1 store carries exception candidate",
               commit_valid && slot1_valid_o && slot1_is_store_o && !slot1_issue_valid_o &&
               slot1_exception_o && slot1_excp_badv_valid_o);
        `check("S10 unissued slot1 store ALE does not own LSU", !slot1_mem_lsu_o);
        `check32("S10 slot1 store ALE ecode", {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S10 slot1 store ALE badv", slot1_excp_badv_o, 32'h0000_8806);
        `check("S10 unissued slot1 store ALE has no lane0 side effects",
               !rf_we && !csr_we_o && !excp_flush_o && !ertn_flush_o && !cacop_valid_o);
`ifdef DIFFTEST_EN
        `check("S10 unissued slot1 store ALE has no difftest store event",
               diff_store_valid_o == 8'h00);
`endif

        slot1_issue_valid_i = 1'b0;
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_opcode_i = 7'h7f; slot1_funct3_i = 3'h7; slot1_funct7_i = 7'h7f; slot1_op_19_15_i = 5'h1f;
        slot1_rs1_i = 5'd31; slot1_rs2_i = 5'd30; slot1_rd_i = 5'd29; slot1_imm_i = 32'hffff_ffff;
        slot1_is_branch_i = 1'b1; slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b1; slot1_unknown_i = 1'b1;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_PC; slot1_src_b_sel_i = `CPU_SRC_B_FOUR; slot1_alu_op_i = `CPU_ALU_XOR;
        slot1_alu_result_i = 32'hffff_0000;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'hffff_ffff;
        slot1_exception_i = 1'b1; slot1_excp_ecode_i = `CPU_ECODE_ALE; slot1_excp_esubcode_i = 9'h1ff;
        slot1_excp_badv_valid_i = 1'b1; slot1_excp_badv_i = 32'hffff_0000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 slot1 invalid clears outputs",
               !slot1_valid_o && !slot1_unknown_o && !slot1_is_branch_o &&
               !slot1_is_load_o && !slot1_is_store_o);
        `check("S10 slot1 invalid clears issue sideband", !slot1_issue_valid_o);
        `check32("S10 slot1 invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S10 slot1 invalid clears LSU ownership", !slot1_mem_lsu_o);
        `check("S10 slot1 invalid clears shadow RF candidate", !slot1_rf_we_candidate_o);
        `check32("S10 slot1 invalid clears shadow RF candidate addr",
                 {27'd0, slot1_rf_waddr_candidate_o}, 32'd0);
        `check32("S10 slot1 invalid clears shadow RF candidate data",
                 slot1_rf_wdata_candidate_o, 32'd0);
        `check("S10 slot1 invalid clears simple ALU payload",
               !slot1_wb_en_o && !slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == 2'd0 && slot1_src_b_sel_o == 2'd0 && slot1_alu_op_o == 4'd0);
        `check32("S10 slot1 invalid clears shadow ALU result", slot1_alu_result_o, 32'd0);
        `check32("S10 slot1 invalid clears store size", {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("S10 slot1 invalid clears store data", slot1_store_data_o, 32'd0);
        `check("S10 slot1 invalid clears exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check32("S10 slot1 invalid clears exception badv", slot1_excp_badv_o, 32'd0);
        `check32("S10 slot1 invalid clears rs1", {27'h0, slot1_rs1_o}, 32'd0);
        `check32("S10 slot1 invalid clears rd", {27'h0, slot1_rd_o}, 32'd0);
        `check32("S10 slot1 invalid clears imm", slot1_imm_o, 32'd0);
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_alu_result_i = 32'd0;
        slot1_mem_size_i = 2'd0; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_ecode_i = 6'd0; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b0; slot1_excp_badv_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;

        is_csr_i = 1; csr_we_i = 0; csr_xchg_i = 0; csr_addr_i = `CPU_CSR_CRMD; csr_rdata_i = 32'h0000_0008;
        wb_en_i = 1; rd_i = 5'd12; is_load_i = 0; is_store_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 csrrd commits old CSR to GPR", commit_valid && rf_we && !csr_we_o);
        `check32("S10 CSR read addr", {18'd0, csr_raddr_o}, 32'h0);
        `check32("S10 csrrd writeback data", rf_wdata, 32'h0000_0008);

        csr_we_i = 1; csr_xchg_i = 1; csr_addr_i = `CPU_CSR_PRMD;
        csr_rdata_i = 32'haaaa_000f; csr_wdata_i = 32'h0000_0003; csr_wmask_i = 32'h0000_0007;
        rd_i = 5'd13; wb_en_i = 1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 csrxchg writes masked CSR and returns old CSR", commit_valid && rf_we && csr_we_o);
        `check32("S10 csrxchg write addr", {18'd0, csr_waddr_o}, 32'h1);
        `check32("S10 csrxchg new CSR data", csr_wdata_o, 32'haaaa_000b);
        `check32("S10 csrxchg RF old CSR", rf_wdata, 32'haaaa_000f);

        is_csr_i = 0; csr_we_i = 0; csr_xchg_i = 0; wb_en_i = 0; rd_i = 5'd0;
        exception_i = 1; is_syscall_i = 1; pc_i = 32'h1c010080; instr_i = 32'h002b_0000;
        excp_ecode_i = `CPU_ECODE_SYS; excp_esubcode_i = 9'd0; excp_badv_valid_i = 0; excp_badv_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 syscall commits without RF write and flushes", commit_valid && !rf_we && excp_flush_o && !ertn_flush_o);
        `check32("S10 syscall exception PC", excp_pc_o, 32'h1c010080);
        `check32("S10 syscall ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_SYS});
        `check("S10 syscall does not write BADV", !excp_badv_valid_o);

        exception_i = 1; is_syscall_i = 0; pc_i = 32'h1c010084; instr_i = 32'h0;
        excp_ecode_i = `CPU_ECODE_ALE; excp_badv_valid_i = 1; excp_badv_i = 32'h1d00_0001;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 ALE flushes", commit_valid && excp_flush_o && !rf_we);
        `check32("S10 ALE ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check("S10 ALE writes BADV", excp_badv_valid_o);
        `check32("S10 ALE BADV value", excp_badv_o, 32'h1d00_0001);

        exception_i = 0; is_syscall_i = 0; is_ertn_i = 1; pc_i = 32'h1c008020; instr_i = 32'h0648_3800;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 ertn flushes without exception", commit_valid && !rf_we && !excp_flush_o && ertn_flush_o);
        is_ertn_i = 0;

        instr_i = la_special(6'h0e, 4'h1, 2'h3, 5'h05, 5'd0, 5'd0, 5'd0); wb_en_i = 0; exception_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 ibar commits as refetch barrier", commit_valid && ibar_flush_o && !rf_we);

        wb_en_i = 0; exception_i = 0; is_csr_i = 0; is_load_i = 0; is_store_i = 0; rd_i = 5'd0;
        instr_i = la_tlb_barrier(5'h0a); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 TLBSRCH precise commit pulse", commit_valid && tlbsrch_valid_o && !rf_we);
        instr_i = la_tlb_barrier(5'h0b); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 TLBRD precise commit pulse", commit_valid && tlbrd_valid_o && !rf_we);
        instr_i = la_tlb_barrier(5'h0c); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 TLBWR precise commit pulse", commit_valid && tlbwr_valid_o && !rf_we);
        instr_i = la_tlb_barrier(5'h0d); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 TLBFILL precise commit pulse", commit_valid && tlbfill_valid_o && !rf_we);
        instr_i = la_invtlb(5'd5, 5'd12, 5'd13);
        csr_wdata_i = 32'h0000_0155;
        csr_wmask_i = 32'h2468_a000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 INVTLB precise commit pulse", commit_valid && invtlb_valid_o && !rf_we);
        `check32("S10 INVTLB op", {27'd0, invtlb_op_o}, 32'd5);
        `check32("S10 INVTLB ASID from carried rj value", {22'd0, invtlb_asid_o}, 32'h155);
        `check32("S10 INVTLB VPN from carried rk value", {13'd0, invtlb_vpn_o}, 32'h12345);

        instr_i = la_cacop(5'b00000, 5'd3, 12'h040);
        wb_pre_i = 32'h1c01_0040; wb_en_i = 0; exception_i = 0; is_load_i = 0; is_store_i = 0;
        cacop_done_i = 0; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 icacop waits for cache done", cacop_valid_o && cacop_is_icache_o && !commit_valid && !allowin);
        `check32("S10 icacop mode0", {30'd0, cacop_mode_o}, 32'd0);
        `check32("S10 icacop addr", cacop_addr_o, 32'h1c01_0040);
        cacop_done_i = 1'b1; #1;
        `check("S10 icacop commits and flushes frontend", commit_valid && icacop_flush_o && !rf_we);
        tick(); cacop_done_i = 1'b0; #1;

        instr_i = la_cacop(5'b10001, 5'd4, 12'h080);
        wb_pre_i = 32'h0000_2080; wb_en_i = 0; exception_i = 0; is_load_i = 0; is_store_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 dcacop waits for cache done", cacop_valid_o && cacop_is_dcache_o && !commit_valid && !icacop_flush_o);
        `check32("S10 dcacop mode2", {30'd0, cacop_mode_o}, 32'd2);
        cacop_done_i = 1'b1; #1;
        `check("S10 dcacop commits without icache flush", commit_valid && !icacop_flush_o && !rf_we);
        tick(); cacop_done_i = 1'b0; #1;

        instr_i = la_cacop(5'b00010, 5'd4, 12'h000);
        wb_pre_i = 32'h0000_3000; wb_en_i = 0; exception_i = 0; is_load_i = 0; is_store_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 unsupported CACOP target commits as cache NOP", commit_valid && !cacop_valid_o && !icacop_flush_o && !rf_we);

        instr_i = la_cacop(5'b11000, 5'd4, 12'h000);
        wb_pre_i = 32'h0000_3000; wb_en_i = 0; exception_i = 0; is_load_i = 0; is_store_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 CACOP mode3 commits as cache NOP", commit_valid && !cacop_valid_o && !icacop_flush_o && !rf_we);

        instr_i = la_cacop(5'b00000, 5'd3, 12'h040);
        wb_pre_i = 32'h1c01_0040; wb_en_i = 0; exception_i = 1; excp_ecode_i = `CPU_ECODE_IPE;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 CACOP exception blocks cache side effect", commit_valid && excp_flush_o && !cacop_valid_o && !icacop_flush_o);
        exception_i = 0; excp_ecode_i = 0;

        instr_i = 32'h0;
        wb_en_i = 1; exception_i = 0; is_csr_i = 0; is_load_i = 1; is_store_i = 0;
        mem_size_i = 2'b00; mem_sign_ext_i = 1; wb_pre_i = 32'h3; rd_i = 5'd8; dc_valid = 1; dc_data = 32'h807f01ff; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 load commit", commit_valid && rf_we);
        `check32("S10 signed byte load", rf_wdata, 32'hffffff80);
        mem_size_i = 2'b01; mem_sign_ext_i = 1; wb_pre_i = 32'h2; rd_i = 5'd9; dc_valid = 1; dc_data = 32'h8001_7fff; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S10 signed half load", rf_wdata, 32'hffff_8001);
        mem_size_i = 2'b00; mem_sign_ext_i = 0; wb_pre_i = 32'h1; rd_i = 5'd10; dc_valid = 1; dc_data = 32'h0000_ab00; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S10 unsigned byte load", rf_wdata, 32'h0000_00ab);
        mem_size_i = 2'b01; mem_sign_ext_i = 0; wb_pre_i = 32'h0; rd_i = 5'd11; dc_valid = 1; dc_data = 32'h0000_ffee; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S10 unsigned half load", rf_wdata, 32'h0000_ffee);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        instr_i = 32'h28bf02de; // ld.w r30, r22, -64
        is_load_i = 1'b1; is_store_i = 1'b0; wb_en_i = 1'b1; rd_i = 5'd30;
        wb_pre_i = 32'h0; dc_valid = 1'b0; dc_fault = 1'b0;
        mem_size_i = 2'b10; mem_sign_ext_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 pending load remains visible for interlock", valid_o && load_wait_o);
        `check("S10 pending load is not bypass-qualified", !wb_en_raw_o);
        dc_data = 32'h0000_001a; dc_valid = 1'b1; #1;
        `check("S10 load bypass qualifies only when data returns", wb_en_raw_o && commit_valid);
        `check32("S10 returned load data is bypass-visible", wb_data_raw_o, 32'h0000_001a);
        tick(); dc_valid = 1'b0; #1;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        instr_i = la_sc_w(5'd6, 5'd9, 14'h0000);
        dc_valid = 0; dc_fault = 0; is_csr_i = 0; csr_we_i = 0; csr_xchg_i = 0;
        is_syscall_i = 0; is_ertn_i = 0; exception_i = 0;
        is_load_i = 0; is_store_i = 1; wb_en_i = 1; rd_i = 5'd6; wb_pre_i = 32'h0;
        mem_uncached_i = 0; mem_size_i = 2'b10; mem_sign_ext_i = 0;
        s9_is_ll_i = 0; s9_is_sc_i = 1; s9_sc_success_i = 0; s9_mem_paddr_i = 32'h1d00_0004;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 failed SC commits without waiting for DCache", commit_valid && rf_we && !load_wait_o && allowin);
        `check32("S10 failed SC writes zero", rf_wdata, 32'h0);
        `check("S10 failed SC clears llbit without lladdr update", llbit_set_o && !llbit_value_o && !lladdr_set_o);
        s9_is_sc_i = 0; s9_sc_success_i = 0; is_store_i = 0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        instr_i = la_sc_w(5'd6, 5'd9, 14'h0000);
        dc_valid = 1'b0; dc_fault = 1'b1; is_csr_i = 0; csr_we_i = 0; csr_xchg_i = 0;
        is_syscall_i = 0; is_ertn_i = 0; exception_i = 0;
        is_load_i = 0; is_store_i = 1; wb_en_i = 1; rd_i = 5'd6; wb_pre_i = 32'h0;
        mem_uncached_i = 0; mem_size_i = 2'b10; mem_sign_ext_i = 0;
        s9_is_ll_i = 0; s9_is_sc_i = 1; s9_sc_success_i = 0; s9_mem_paddr_i = 32'h1d00_0004;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 stale DCache fault does not poison failed SC",
               commit_valid && rf_we && !excp_flush_o && allowin);
        `check32("S10 failed SC with stale fault writes zero", rf_wdata, 32'h0);
        dc_fault = 1'b0;
        s9_is_sc_i = 0; s9_sc_success_i = 0; is_store_i = 0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        is_load_i = 1'b0; is_store_i = 1'b1; wb_en_i = 1'b0; rd_i = 5'd0;
        dc_valid = 1'b0; dc_fault = 1'b0; exception_i = 1'b0;
        mem_size_i = 2'b10; mem_sign_ext_i = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_wb_en_i = 1'b1;
        slot1_rd_i = 5'd11;
        slot1_alu_result_i = 32'hffff_ffff;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 pending store blocks commit", !commit_valid && !allowin);
        `check("S10 pending store remains visible to bypass", valid_o);
        `check("S10 pending store exposes slot1 issued producer", slot1_issue_valid_o);
        `check32("S10 pending slot1 producer carries compute class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        `check32("S10 pending slot1 producer result is bypass-visible",
                 slot1_alu_result_o, 32'hffff_ffff);
        dc_valid = 1'b1; #1;
        `check("S10 pending store commits when DCache responds", commit_valid && allowin);
        dc_valid = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c01f000; instr_i = la_mem(4'ha, 5'd9, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd9; wb_pre_i = 32'h0000_0101;
        is_load_i = 1'b0; is_store_i = 1'b0; mem_size_i = 2'b10;
        exception_i = 1'b0; dc_valid = 1'b0; dc_fault = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c01f004;
        instr1_i = la_mem(4'h2, 5'd12, 5'd13, 12'h004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0; slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd12;
        slot1_alu_result_i = 32'h4000_9804;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_9804;
        diff_mem_paddr_i = 32'h0000_9804;
        diff_store_data_i = 32'd0;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 load waits for DCache without committing slot0",
               !commit_valid && !allowin && valid_o && !slot1_refetch_o);
        `check32("S10 issued slot1 load carries load class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0100});
        `check("S10 issued slot1 load carries LSU ownership", slot1_mem_lsu_o);
        dc_data = 32'hfeed_c0de; dc_valid = 1'b1; #1;
        `check("S10 issued slot1 load commits slot0 when DCache responds",
               commit_valid && allowin && rf_we && rf_waddr == 5'd9);
        `check("S10 issued slot1 load produces slot1 RF write candidate from DCache data",
               slot1_rf_we_candidate_o && slot1_rf_waddr_candidate_o == 5'd12 &&
               slot1_rf_wdata_candidate_o == 32'hfeed_c0de &&
               !slot1_refetch_o && !excp_flush_o);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 load emits difftest load event",
               diff_load_valid_o == 8'h10 &&
               diff_load_vaddr_o == 32'h4000_9804 &&
               diff_load_paddr_o == 32'h0000_9804);
        `check("S10 phase1 keeps committed slot1 load event suppressed",
               diff_commit_load_valid_o == 8'h00 &&
               diff_commit_load_paddr_o == 32'h0000_0000 &&
               diff_commit_load_vaddr_o == 32'h0000_0000);
`endif
        dc_valid = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c01f008; instr_i = la_mem(4'ha, 5'd10, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd10; wb_pre_i = 32'h0000_0108;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c01f00c;
        instr1_i = la_mem(4'h0, 5'd12, 5'd13, 12'h010);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0; slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd12;
        slot1_alu_result_i = 32'h4000_9810;
        slot1_mem_size_i = 2'b00; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_9810;
        diff_mem_paddr_i = 32'h0000_9810;
        diff_store_data_i = 32'd0;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 ld.b waits for DCache without committing slot0",
               !commit_valid && !allowin && valid_o && !slot1_refetch_o);
        dc_data = 32'h0000_0080; dc_valid = 1'b1; #1;
        `check("S10 issued slot1 ld.b sign-extends load byte",
               commit_valid && slot1_rf_we_candidate_o &&
               slot1_rf_waddr_candidate_o == 5'd12 &&
               slot1_rf_wdata_candidate_o == 32'hffff_ff80);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 ld.b emits signed-byte difftest load event",
               diff_load_valid_o == 8'h01 &&
               diff_load_vaddr_o == 32'h4000_9810 &&
               diff_load_paddr_o == 32'h0000_9810);
        `check("S10 phase1 keeps committed signed-byte load suppressed",
               diff_commit_load_valid_o == 8'h00);
`endif
        dc_valid = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c01f00c; instr_i = la_mem(4'ha, 5'd11, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd11; wb_pre_i = 32'h0000_010c;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c01f010;
        instr1_i = la_mem(4'h9, 5'd12, 5'd13, 12'h012);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0; slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd12;
        slot1_alu_result_i = 32'h4000_9812;
        slot1_mem_size_i = 2'b01; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_9812;
        diff_mem_paddr_i = 32'h0000_9812;
        diff_store_data_i = 32'd0;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 ld.hu waits for DCache without committing slot0",
               !commit_valid && !allowin && valid_o && !slot1_refetch_o);
        dc_data = 32'h8001_1234; dc_valid = 1'b1; #1;
        `check("S10 issued slot1 ld.hu zero-extends load half",
               commit_valid && slot1_rf_we_candidate_o &&
               slot1_rf_waddr_candidate_o == 5'd12 &&
               slot1_rf_wdata_candidate_o == 32'h0000_8001);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 ld.hu emits unsigned-half difftest load event",
               diff_load_valid_o == 8'h08 &&
               diff_load_vaddr_o == 32'h4000_9812 &&
               diff_load_paddr_o == 32'h0000_9812);
        `check("S10 phase1 keeps committed unsigned-half load suppressed",
               diff_commit_load_valid_o == 8'h00);
`endif
        dc_valid = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c01f010; instr_i = la_mem(4'ha, 5'd8, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd8; wb_pre_i = 32'h0000_0110;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c01f014;
        instr1_i = la_mem(4'h2, 5'd12, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_mem_size_i = 2'b10;
        slot1_alu_result_i = 32'h4000_9806;
        slot1_exception_i = 1'b1;
        slot1_excp_ecode_i = `CPU_ECODE_ALE;
        slot1_excp_badv_valid_i = 1'b1;
        slot1_excp_badv_i = 32'h4000_9806;
        dc_valid = 1'b0; dc_fault = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 load ALE commits slot0 then refetches slot1",
               commit_valid && rf_we && slot1_refetch_o && !excp_flush_o &&
               !slot1_rf_we_candidate_o);
        `check32("S10 issued slot1 load ALE refetch PC",
                 slot1_refetch_pc_o, 32'h1c01f014);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 load ALE suppresses difftest load event",
               diff_load_valid_o == 8'h00);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c01f020; instr_i = la_mem(4'ha, 5'd7, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd7; wb_pre_i = 32'h0000_0120;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c01f024;
        instr1_i = la_mem(4'h2, 5'd12, 5'd13, 12'h000);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_mem_size_i = 2'b10;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        slot1_alu_result_i = 32'h4000_9800;
        dc_valid = 1'b1; dc_fault = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 load fault refetches slot1 without lane0 exception",
               commit_valid && rf_we && slot1_refetch_o && !excp_flush_o &&
               !slot1_rf_we_candidate_o);
        `check32("S10 issued slot1 load fault refetch PC",
                 slot1_refetch_pc_o, 32'h1c01f024);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 load fault suppresses difftest load event",
               diff_load_valid_o == 8'h00);
`endif
        dc_valid = 1'b0; dc_fault = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020000; instr_i = la_mem(4'ha, 5'd9, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd9; wb_pre_i = 32'h0000_0001;
        is_load_i = 1'b0; is_store_i = 1'b0; mem_size_i = 2'b10;
        exception_i = 1'b0; dc_valid = 1'b0; dc_fault = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020004;
        instr1_i = la_mem(4'h5, 5'd12, 5'd13, 12'h002);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1; slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_rd_i = 5'd12;
        slot1_alu_result_i = 32'h4000_9002;
        slot1_mem_size_i = 2'b01; slot1_store_data_i = 32'h0000_abcd;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_9002;
        diff_mem_paddr_i = 32'h0000_9002;
        diff_store_data_i = 32'h0000_abcd;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 store waits for DCache without committing slot0",
               !commit_valid && !allowin && valid_o && !slot1_refetch_o);
        `check32("S10 issued slot1 store carries store class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0010});
        `check("S10 issued slot1 store carries LSU ownership", slot1_mem_lsu_o);
        dc_valid = 1'b1; #1;
        `check("S10 issued slot1 store commits slot0 when DCache responds",
               commit_valid && allowin && rf_we && rf_waddr == 5'd9);
        `check("S10 issued slot1 store keeps slot1 RF write disabled",
               !slot1_rf_we_candidate_o && !slot1_refetch_o && !excp_flush_o);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 half store emits difftest store event",
               diff_store_valid_o == 8'h02);
        `check32("S10 issued slot1 half store difftest data",
                 diff_store_data_o, 32'habcd_0000);
        `check32("S10 issued slot1 half store difftest paddr",
                 diff_store_paddr_o, 32'h0000_9002);
        `check("S10 phase1 keeps committed slot1 store event suppressed",
               diff_commit_store_valid_o == 8'h00 &&
               diff_commit_store_paddr_o == 32'h0000_0000 &&
               diff_commit_store_vaddr_o == 32'h0000_0000 &&
               diff_commit_store_data_o == 32'h0000_0000);
`endif
        dc_valid = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020010; instr_i = la_mem(4'ha, 5'd8, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd8; wb_pre_i = 32'h0000_0010;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020014;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_store_i = 1'b1; slot1_is_load_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_mem_size_i = 2'b10;
        slot1_store_data_i = 32'h1357_2468;
        slot1_exception_i = 1'b1;
        slot1_excp_ecode_i = `CPU_ECODE_ALE;
        slot1_excp_badv_valid_i = 1'b1;
        slot1_excp_badv_i = 32'h4000_9006;
        dc_valid = 1'b0; dc_fault = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 store ALE commits slot0 then refetches slot1",
               commit_valid && rf_we && slot1_refetch_o && !excp_flush_o &&
               !commit1_valid && !commit_event1_accept_o &&
               commit_event_select_reason_o == 4'h9);
        `check32("S10 issued slot1 store ALE refetch PC",
                 slot1_refetch_pc_o, 32'h1c020014);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 store ALE suppresses difftest store event",
               diff_store_valid_o == 8'h00 &&
               diff_commit_store_valid_o == 8'h00 &&
               diff_commit_store_paddr_o == 32'h0000_0000 &&
               diff_commit_store_vaddr_o == 32'h0000_0000 &&
               diff_commit_store_data_o == 32'h0000_0000);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020020; instr_i = la_mem(4'ha, 5'd7, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd7; wb_pre_i = 32'h0000_0020;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020024;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h000);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_store_i = 1'b1; slot1_is_load_i = 1'b0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h89ab_cdef;
        dc_valid = 1'b1; dc_fault = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 store fault refetches slot1 without lane0 exception",
               commit_valid && rf_we && slot1_refetch_o && !excp_flush_o &&
               !commit1_valid && !commit_event1_accept_o &&
               commit_event_select_reason_o == 4'h9);
        `check32("S10 issued slot1 store fault refetch PC",
                 slot1_refetch_pc_o, 32'h1c020024);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 store fault suppresses difftest store event",
               diff_store_valid_o == 8'h00 &&
               diff_commit_store_valid_o == 8'h00 &&
               diff_commit_store_paddr_o == 32'h0000_0000 &&
               diff_commit_store_vaddr_o == 32'h0000_0000 &&
               diff_commit_store_data_o == 32'h0000_0000);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020030; instr_i = la_mem(4'ha, 5'd6, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd6; wb_pre_i = 32'h0000_0030;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020034;
        instr1_i = la_mem(4'h8, 5'd14, 5'd13, 12'h001);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd14;
        slot1_alu_result_i = 32'h4000_9001;
        slot1_mem_size_i = 2'b00; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        dc_valid = 1'b0; dc_fault = 1'b0; dc_data = 32'h0000_ab00;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_9001;
        diff_mem_paddr_i = 32'h0000_9001;
        diff_store_data_i = 32'd0;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 load waits for DCache without committing slot0",
               !commit_valid && !allowin && valid_o && slot1_load_wait_o &&
               !slot1_rf_we_candidate_o);
`ifdef DIFFTEST_EN
        `check("S10 pending slot1 load suppresses difftest load event",
               diff_load_valid_o == 8'h00);
`endif
        dc_valid = 1'b1; #1;
        `check("S10 issued slot1 load commits when DCache responds",
               commit_valid && allowin && rf_we && rf_waddr == 5'd6 &&
               !slot1_load_wait_o && !slot1_refetch_o && !excp_flush_o);
        `check("S10 issued slot1 load forms RF candidate",
               slot1_rf_we_candidate_o && slot1_rf_waddr_candidate_o == 5'd14);
        `check32("S10 issued slot1 unsigned byte load candidate data",
                 slot1_rf_wdata_candidate_o, 32'h0000_00ab);
        `check32("S10 issued slot1 unsigned byte load keeps address sideband",
                 slot1_alu_result_o, 32'h4000_9001);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 byte unsigned load emits difftest load event",
               diff_load_valid_o == 8'h02);
        `check32("S10 issued slot1 load difftest paddr",
                 diff_load_paddr_o, 32'h0000_9001);
        `check32("S10 issued slot1 load difftest vaddr",
                 diff_load_vaddr_o, 32'h4000_9001);
`endif
        dc_valid = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020040; instr_i = la_mem(4'ha, 5'd5, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd5; wb_pre_i = 32'h0000_0040;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020044;
        instr1_i = la_mem(4'h1, 5'd15, 5'd13, 12'h002);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd15;
        slot1_alu_result_i = 32'h4000_9002;
        slot1_mem_size_i = 2'b01; slot1_exception_i = 1'b0;
        dc_valid = 1'b1; dc_fault = 1'b0; dc_data = 32'h8001_7fff;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_9002;
        diff_mem_paddr_i = 32'h0000_9002;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 load can commit immediately with returned data",
               commit_valid && allowin && slot1_rf_we_candidate_o);
        `check32("S10 issued slot1 signed half load candidate data",
                 slot1_rf_wdata_candidate_o, 32'hffff_8001);
        `check32("S10 issued slot1 signed half load keeps address sideband",
                 slot1_alu_result_o, 32'h4000_9002);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 signed half load emits difftest load event",
               diff_load_valid_o == 8'h04);
`endif
        dc_valid = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020050; instr_i = la_mem(4'ha, 5'd4, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd4; wb_pre_i = 32'h0000_0050;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020054;
        instr1_i = la_mem(4'h2, 5'd16, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd16;
        slot1_mem_size_i = 2'b10;
        slot1_exception_i = 1'b1;
        slot1_excp_ecode_i = `CPU_ECODE_ALE;
        slot1_excp_badv_valid_i = 1'b1;
        slot1_excp_badv_i = 32'h4000_9006;
        dc_valid = 1'b0; dc_fault = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 load ALE commits slot0 then refetches slot1",
               commit_valid && rf_we && slot1_refetch_o && !excp_flush_o &&
               !slot1_rf_we_candidate_o && !slot1_load_wait_o);
        `check32("S10 issued slot1 load ALE refetch PC",
                 slot1_refetch_pc_o, 32'h1c020054);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 load ALE suppresses difftest load event",
               diff_load_valid_o == 8'h00);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020060; instr_i = la_mem(4'ha, 5'd3, 5'd4, 12'h001);
        wb_en_i = 1'b1; rd_i = 5'd3; wb_pre_i = 32'h0000_0060;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020064;
        instr1_i = la_mem(4'h2, 5'd17, 5'd13, 12'h000);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd17;
        slot1_alu_result_i = 32'h4000_9010;
        slot1_mem_size_i = 2'b10;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        dc_valid = 1'b1; dc_fault = 1'b1; dc_data = 32'h1234_5678;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 issued slot1 load fault refetches slot1 without lane0 exception",
               commit_valid && rf_we && slot1_refetch_o && !excp_flush_o &&
               !slot1_rf_we_candidate_o);
        `check32("S10 issued slot1 load fault refetch PC",
                 slot1_refetch_pc_o, 32'h1c020064);
`ifdef DIFFTEST_EN
        `check("S10 issued slot1 load fault suppresses difftest load event",
               diff_load_valid_o == 8'h00);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020070; instr_i = 32'h0;
        wb_en_i = 1'b1; rd_i = 5'd2; wb_pre_i = 32'h0000_0070;
        is_load_i = 1'b0; is_store_i = 1'b0;
        exception_i = 1'b1; excp_ecode_i = `CPU_ECODE_ALE;
        excp_badv_valid_i = 1'b1; excp_badv_i = 32'h1c02_0070;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020074;
        instr1_i = la_mem(4'h2, 5'd18, 5'd13, 12'h000);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_rd_i = 5'd18;
        slot1_alu_result_i = 32'h4000_9020;
        slot1_mem_size_i = 2'b10;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        dc_valid = 1'b1; dc_fault = 1'b0; dc_data = 32'hdead_beef;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 slot0 exception suppresses issued slot1 load effects",
               commit_valid && excp_flush_o && !rf_we && !slot1_refetch_o &&
               !slot1_rf_we_candidate_o && !slot1_load_wait_o);
        `check32("S10 slot0 exception wins over slot1 load PC",
                 excp_pc_o, 32'h1c020070);
`ifdef DIFFTEST_EN
        `check("S10 slot0 exception suppresses slot1 load difftest event",
               diff_load_valid_o == 8'h00);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c020080; instr_i = 32'h0;
        wb_en_i = 1'b1; rd_i = 5'd2; wb_pre_i = 32'h0000_0080;
        is_load_i = 1'b0; is_store_i = 1'b0;
        exception_i = 1'b1; excp_ecode_i = `CPU_ECODE_ALE;
        excp_badv_valid_i = 1'b1; excp_badv_i = 32'h1c02_0080;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020084;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h000);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1;
        slot1_wb_en_i = 1'b0; slot1_rd_i = 5'd12;
        slot1_alu_result_i = 32'h4000_9030;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'hfeed_cafe;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        dc_valid = 1'b1; dc_fault = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 slot0 exception suppresses issued slot1 store effects",
               commit_valid && excp_flush_o && !rf_we && !slot1_refetch_o &&
               !slot1_rf_we_candidate_o);
        `check32("S10 slot0 exception wins over slot1 store PC",
                 excp_pc_o, 32'h1c020080);
`ifdef DIFFTEST_EN
        `check("S10 slot0 exception suppresses slot1 store difftest event",
               diff_store_valid_o == 8'h00);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        dual_commit_enable_i = 1'b1;
        pc_i = 32'h1c020090; instr_i = 32'h0012_3456;
        wb_en_i = 1'b1; rd_i = 5'd19; wb_pre_i = 32'h0000_0090;
        is_load_i = 1'b0; is_store_i = 1'b0; mem_size_i = 2'b10; mem_sign_ext_i = 1'b0;
        exception_i = 1'b0; excp_ecode_i = 6'd0; excp_badv_valid_i = 1'b0; excp_badv_i = 32'd0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c020094;
        instr1_i = la_mem(4'h2, 5'd20, 5'd13, 12'h004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd20; slot1_rd_i = 5'd20; slot1_imm_i = 32'h4;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0; slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_alu_result_i = 32'h4000_9094;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_ecode_i = 6'd0; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b0; slot1_excp_badv_i = 32'd0;
        dc_valid = 1'b1; dc_fault = 1'b0; dc_data = 32'hcafe_babe;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_9094;
        diff_mem_paddr_i = 32'h0000_9094;
        diff_store_data_i = 32'd0;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 dual-enabled slot1 load closes ordered dual commit",
               commit_valid && commit1_valid && rf_we && wb0_we_o && wb1_we_o &&
               commit_event1_accept_o && commit_event_dual_commit_o &&
               commit_event_dual_wb_o && debug1_wb_rf_wen_o);
        `check32("S10 dual-enabled slot1 load wb1 addr", {27'd0, wb1_waddr_o}, 32'd20);
        `check32("S10 dual-enabled slot1 load wb1 data", wb1_wdata_o, 32'hcafe_babe);
        `check32("S10 dual-enabled slot1 load feedback rd", {27'd0, fb_slot1_rd_o}, 32'd20);
        `check32("S10 dual-enabled slot1 load feedback data", fb_slot1_result_o, 32'hcafe_babe);
        `check32("S10 dual-enabled slot1 load debug1 pc", debug1_wb_pc_o, 32'h1c020094);
`ifdef DIFFTEST_EN
        `check("S10 dual-enabled slot1 load forwards committed difftest event",
               diff_load_valid_o == 8'h10 &&
               diff_commit_load_valid_o == 8'h10 &&
               diff_commit_load_paddr_o == 32'h0000_9094 &&
               diff_commit_load_vaddr_o == 32'h4000_9094);
`endif

        flush = 1'b1; tick(); flush = 1'b0; #1;
        pc_i = 32'h1c0200a0; instr_i = 32'h00aa_5500;
        wb_en_i = 1'b1; rd_i = 5'd21; wb_pre_i = 32'h0000_00a0;
        is_load_i = 1'b0; is_store_i = 1'b0; exception_i = 1'b0;
        slot1_valid_i = 1'b1; slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c0200a4;
        instr1_i = la_mem(4'h6, 5'd0, 5'd13, 12'h004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd12; slot1_rd_i = 5'd0; slot1_imm_i = 32'h4;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_alu_result_i = 32'h4000_90a4;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h5566_7788;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        dc_valid = 1'b1; dc_fault = 1'b0;
`ifdef DIFFTEST_EN
        diff_mem_vaddr_i = 32'h4000_90a4;
        diff_mem_paddr_i = 32'h0000_90a4;
        diff_store_data_i = 32'h5566_7788;
`endif
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 dual-enabled slot1 store closes ordered commit without wb1",
               commit_valid && commit1_valid && rf_we && wb0_we_o &&
               !wb1_we_o && commit_event1_accept_o && commit_event_dual_commit_o &&
               !commit_event_dual_wb_o && !debug1_wb_rf_wen_o &&
               fb_slot1_issue_valid_o && !fb_slot1_wb_en_o);
        `check32("S10 dual-enabled slot1 store commit1 pc", commit1_pc, 32'h1c0200a4);
`ifdef DIFFTEST_EN
        `check("S10 dual-enabled slot1 store forwards committed difftest event",
               diff_store_valid_o == 8'h04 &&
               diff_commit_store_valid_o == 8'h04 &&
               diff_commit_store_paddr_o == 32'h0000_90a4 &&
               diff_commit_store_vaddr_o == 32'h4000_90a4 &&
               diff_commit_store_data_o == 32'h5566_7788);
`endif
        dual_commit_enable_i = 1'b0;

        dc_valid = 1'b0; dc_fault = 1'b0;
        exception_i = 1'b0; excp_ecode_i = 6'd0;
        excp_badv_valid_i = 1'b0; excp_badv_i = 32'd0;
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0;
        slot1_rd_i = 5'd0;
        slot1_alu_result_i = 32'd0;
`ifdef DIFFTEST_EN
        is_load_i = 0; is_store_i = 1; wb_en_i = 0; dc_valid = 1; exception_i = 0;
        diff_mem_vaddr_i = 32'hbfe0_01e2; diff_mem_paddr_i = 32'h1fe0_01e2;
        diff_store_data_i = 32'h0000_0007; mem_size_i = 2'b00;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 byte store emits difftest store event", commit_valid && diff_store_valid_o == 8'h01);
        `check32("S10 byte store difftest data is lane-aligned", diff_store_data_o, 32'h0007_0000);
        `check32("S10 byte store difftest paddr", diff_store_paddr_o, 32'h1fe0_01e2);
        `check32("S10 byte store difftest vaddr", diff_store_vaddr_o, 32'hbfe0_01e2);

        diff_mem_vaddr_i = 32'hbfe0_01e2; diff_mem_paddr_i = 32'h1fe0_01e2;
        diff_store_data_i = 32'h0000_55aa; mem_size_i = 2'b01;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 half store emits difftest store event", commit_valid && diff_store_valid_o == 8'h02);
        `check32("S10 half store difftest data is lane-aligned", diff_store_data_o, 32'h55aa_0000);

        diff_mem_vaddr_i = 32'hbfe0_01e0; diff_mem_paddr_i = 32'h1fe0_01e0;
        diff_store_data_i = 32'h1234_5678; mem_size_i = 2'b10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S10 word store emits difftest store event", commit_valid && diff_store_valid_o == 8'h04);
        `check32("S10 word store difftest data is unshifted", diff_store_data_o, 32'h1234_5678);
`endif
        finish_tb();
    end
endmodule

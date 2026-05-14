`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s8_backend_ex_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    function automatic [31:0] la_alu_3r(input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] rk);
        la_alu_3r = {6'h00, 4'h0, 2'h1, op19_15, rk, rj, rd};
    endfunction

    function automatic [31:0] la_div_3r(input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] rk);
        la_div_3r = {6'h00, 4'h0, 2'h2, op19_15, rk, rj, rd};
    endfunction

    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_branch(input [5:0] op31_26, input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_branch = {op31_26, imm, rj, rd};
    endfunction

    function automatic [31:0] la_csr(input [4:0] rd, input [4:0] rj, input [13:0] csr);
        la_csr = {6'h01, 2'b00, csr, rj, rd};
    endfunction

    function automatic [31:0] la_syscall();
        la_syscall = {6'h00, 4'h0, 2'h2, 5'h16, 15'd0};
    endfunction
    function automatic [31:0] la_break();
        la_break = {6'h00, 4'h0, 2'h2, 5'h14, 15'd0};
    endfunction
    function automatic [31:0] la_rdcntid(input [4:0] rj);
        la_rdcntid = {6'h00, 4'h0, 2'h0, 5'h00, 5'h18, rj, 5'd0};
    endfunction
    function automatic [31:0] la_rdcntvl(input [4:0] rd);
        la_rdcntvl = {6'h00, 4'h0, 2'h0, 5'h00, 5'h18, 5'd0, rd};
    endfunction
    function automatic [31:0] la_rdcntvh(input [4:0] rd);
        la_rdcntvh = {6'h00, 4'h0, 2'h0, 5'h00, 5'h19, 5'd0, rd};
    endfunction

    function automatic [31:0] la_ertn();
        la_ertn = {6'h01, 4'h9, 2'h0, 5'h10, 5'h0e, 5'd0, 5'd0};
    endfunction

    logic flush, in_valid, allowin, s9_allowin, out_valid;
    logic pred_taken_i, fault_i, wb_en_i, is_branch_i, is_jal_i, is_jalr_i, is_load_i, is_store_i, mem_sign_ext_i, unknown_inst_i;
    logic s7_branch_redirected_i;
    logic op_a_late_s10_i, op_b_late_s10_i, rs1_late_s10_i, rs2_late_s10_i;
    logic s10_late_valid_i, s10_late_wb_en_i;
    logic slot1_op_a_late_s10_i, slot1_op_b_late_s10_i;
    logic slot1_rs1_late_s10_i, slot1_rs2_late_s10_i;
    logic csr_has_int_i;
    logic [5:0] fault_ecode_i;
    logic [31:0] pc_i, instr_i, pred_target_i, imm_i, op_a_i, op_b_i, rs1_val_i, rs2_val_i;
    logic [31:0] slot1_pc_i, instr1_i, slot1_imm_i, slot1_rs1_val_i, slot1_rs2_val_i;
    logic [31:0] slot1_op_a_i, slot1_op_b_i;
    logic [31:0] s10_late_data_i;
    logic [31:0] fault_badv_i;
    logic [1:0] epoch_i, epoch_o;
    logic [63:0] csr_timer64_i;
    logic [31:0] csr_tid_i;
    logic [4:0] rd_i, late_s10_rd_i, s10_late_rd_i;
    logic [4:0] slot1_late_s10_rd_i;
    logic [4:0] slot1_op_19_15_i, slot1_rs1_i, slot1_rs2_i, slot1_rd_i;
    logic [1:0] mem_size_i;
    logic [1:0] slot1_src_a_sel_i, slot1_src_b_sel_i;
    logic [1:0] slot1_src_a_sel_o, slot1_src_b_sel_o, slot1_mem_size_o;
    logic [3:0] alu_op_i;
    logic [3:0] slot1_alu_op_i, slot1_alu_op_o;
    logic [2:0] branch_op_i;
    logic [31:0] pc_o, instr_o, mem_addr_o, store_data_o, wb_data_pre_o, redirect_pc_o, alu_result_o;
    logic [31:0] slot1_pc_o, instr1_o, slot1_imm_o, slot1_rs1_val_o, slot1_rs2_val_o;
    logic [31:0] slot1_op_a_o, slot1_op_b_o, slot1_alu_result_o, slot1_store_data_o;
    logic [31:0] bpu_update_pc_o, bpu_update_target_o;
    logic [4:0] rd_o;
    logic [4:0] slot1_op_19_15_o, slot1_rs1_o, slot1_rs2_o, slot1_rd_o;
    logic wb_en_o, is_load_o, is_store_o, mem_sign_ext_o, exception_o, redirect_valid_o, branch_taken_o, valid_o;
    logic slot1_valid_i, slot1_is_branch_i, slot1_is_jal_i, slot1_is_jalr_i, slot1_is_load_i, slot1_is_store_i, slot1_is_lui_i, slot1_is_auipc_i, slot1_unknown_i;
    logic slot1_wb_en_i, slot1_uses_rs1_i, slot1_uses_rs2_i, slot1_issue_valid_i;
    logic [3:0] slot1_issue_class_i, slot1_issue_class_o;
    logic [3:0] slot1_issue_class_auto;
    logic [3:0] slot1_issue_class_override;
    logic       slot1_issue_class_override_en;
    logic slot1_valid_o, slot1_is_branch_o, slot1_is_jal_o, slot1_is_jalr_o, slot1_is_load_o, slot1_is_store_o, slot1_is_lui_o, slot1_is_auipc_o, slot1_unknown_o;
    logic slot1_wb_en_o, slot1_uses_rs1_o, slot1_uses_rs2_o, slot1_issue_valid_o;
    logic slot1_emit_valid_o, slot1_fire_o;
    logic [3:0] slot1_emit_class_o;
    logic slot1_exception_o, slot1_excp_badv_valid_o;
    logic result_wait_o, slot1_result_wait_o;
    logic [5:0] excp_ecode_o, slot1_excp_ecode_o;
    logic [8:0] excp_esubcode_o, slot1_excp_esubcode_o;
    logic excp_badv_valid_o;
    logic [31:0] excp_badv_o, slot1_excp_badv_o;
    logic is_csr_o, csr_we_o, csr_xchg_o, is_syscall_o, is_ertn_o;
    logic [13:0] csr_addr_o;
    logic [31:0] csr_wdata_o, csr_wmask_o;
    logic bpu_update_valid_o, bpu_update_taken_o, bpu_update_is_call_o, bpu_update_is_ret_o;
    logic bpu_update_is_jmp_o, bpu_update_is_indirect_jmp_o;
    logic [6:0] slot1_opcode_i, slot1_funct7_i, slot1_opcode_o, slot1_funct7_o;
    logic [2:0] slot1_funct3_i, slot1_funct3_o;
`ifdef PERF_MONI
    logic bpu_perf_valid_o, bpu_perf_is_branch_o, bpu_perf_is_jump_o;
    logic bpu_perf_is_ret_jirl_o, bpu_perf_is_indirect_jirl_o;
    logic [31:0] bpu_perf_pc_o;
    logic bpu_perf_pred_taken_o, bpu_perf_actual_taken_o;
    logic bpu_perf_correct_o, bpu_perf_direction_miss_o, bpu_perf_target_miss_o, bpu_perf_exu_flush_o;
`endif
    logic [1:0] mem_size_o;

    always_comb begin
        slot1_issue_class_auto = 4'd0;
        if (slot1_issue_valid_i) begin
            if (slot1_is_branch_i || slot1_is_jal_i || slot1_is_jalr_i) begin
                slot1_issue_class_auto = 4'b0001;
            end else if (slot1_is_load_i) begin
                slot1_issue_class_auto = 4'b0100;
            end else if (slot1_is_store_i) begin
                slot1_issue_class_auto = 4'b0010;
            end else begin
                slot1_issue_class_auto = 4'b1000;
            end
        end
        slot1_issue_class_i =
            slot1_issue_class_override_en ?
                slot1_issue_class_override : slot1_issue_class_auto;
    end

    s8_backend_ex #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .s7_to_s8_valid(in_valid),
        .s8_allowin(allowin), .s9_allowin(s9_allowin), .s8_to_s9_valid(out_valid),
        .s7_pc_i(pc_i), .s7_instr_i(instr_i), .s7_pred_taken_i(pred_taken_i),
        .s7_epoch_i(epoch_i),
        .s7_pred_target_i(pred_target_i),
        .s7_fault_i(fault_i), .s7_fault_ecode_i(fault_ecode_i), .s7_fault_badv_i(fault_badv_i),
        .s7_rd_i(rd_i), .s7_imm_i(imm_i), .s7_wb_en_i(wb_en_i),
        .s7_is_branch_i(is_branch_i), .s7_is_jal_i(is_jal_i), .s7_is_jalr_i(is_jalr_i),
        .s7_is_load_i(is_load_i), .s7_is_store_i(is_store_i), .s7_mem_size_i(mem_size_i),
        .s7_mem_sign_ext_i(mem_sign_ext_i), .s7_alu_op_i(alu_op_i), .s7_branch_op_i(branch_op_i),
        .s7_op_a_i(op_a_i), .s7_op_b_i(op_b_i), .s7_rs1_val_i(rs1_val_i), .s7_rs2_val_i(rs2_val_i),
        .s7_op_a_late_s10_i(op_a_late_s10_i), .s7_op_b_late_s10_i(op_b_late_s10_i),
        .s7_rs1_late_s10_i(rs1_late_s10_i), .s7_rs2_late_s10_i(rs2_late_s10_i),
        .s7_late_s10_rd_i(late_s10_rd_i),
        .s7_unknown_inst_i(unknown_inst_i),
        .s7_branch_redirected_i(s7_branch_redirected_i),
        .s7_slot1_pc_i(slot1_pc_i), .s7_instr1_i(instr1_i), .s7_slot1_valid_i(slot1_valid_i),
        .s7_slot1_opcode_i(slot1_opcode_i), .s7_slot1_funct3_i(slot1_funct3_i),
        .s7_slot1_funct7_i(slot1_funct7_i), .s7_slot1_op_19_15_i(slot1_op_19_15_i),
        .s7_slot1_rs1_i(slot1_rs1_i), .s7_slot1_rs2_i(slot1_rs2_i), .s7_slot1_rd_i(slot1_rd_i),
        .s7_slot1_imm_i(slot1_imm_i), .s7_slot1_is_branch_i(slot1_is_branch_i),
        .s7_slot1_is_jal_i(slot1_is_jal_i), .s7_slot1_is_jalr_i(slot1_is_jalr_i),
        .s7_slot1_is_load_i(slot1_is_load_i), .s7_slot1_is_store_i(slot1_is_store_i),
        .s7_slot1_is_lui_i(slot1_is_lui_i), .s7_slot1_is_auipc_i(slot1_is_auipc_i),
        .s7_slot1_unknown_inst_i(slot1_unknown_i),
        .s7_slot1_wb_en_i(slot1_wb_en_i), .s7_slot1_uses_rs1_i(slot1_uses_rs1_i),
        .s7_slot1_uses_rs2_i(slot1_uses_rs2_i), .s7_slot1_src_a_sel_i(slot1_src_a_sel_i),
        .s7_slot1_src_b_sel_i(slot1_src_b_sel_i), .s7_slot1_alu_op_i(slot1_alu_op_i),
        .s7_slot1_rs1_val_i(slot1_rs1_val_i), .s7_slot1_rs2_val_i(slot1_rs2_val_i),
        .s7_slot1_op_a_i(slot1_op_a_i), .s7_slot1_op_b_i(slot1_op_b_i),
        .s7_slot1_op_a_late_s10_i(slot1_op_a_late_s10_i),
        .s7_slot1_op_b_late_s10_i(slot1_op_b_late_s10_i),
        .s7_slot1_rs1_late_s10_i(slot1_rs1_late_s10_i),
        .s7_slot1_rs2_late_s10_i(slot1_rs2_late_s10_i),
        .s7_slot1_late_s10_rd_i(slot1_late_s10_rd_i),
        .s7_slot1_issue_valid_i(slot1_issue_valid_i),
        .s7_slot1_issue_class_i(slot1_issue_class_i),
        .s10_late_valid_i(s10_late_valid_i), .s10_late_wb_en_i(s10_late_wb_en_i),
        .s10_late_rd_i(s10_late_rd_i), .s10_late_data_i(s10_late_data_i),
        .csr_has_int_i(csr_has_int_i), .csr_timer64_i(csr_timer64_i), .csr_tid_i(csr_tid_i),
        .s8_pc_o(pc_o), .s8_instr_o(instr_o), .s8_epoch_o(epoch_o),
        .s8_rd_o(rd_o), .s8_wb_en_o(wb_en_o),
        .s8_is_load_o(is_load_o), .s8_is_store_o(is_store_o), .s8_mem_size_o(mem_size_o),
        .s8_mem_sign_ext_o(mem_sign_ext_o), .s8_mem_addr_o(mem_addr_o), .s8_store_data_o(store_data_o),
        .s8_wb_data_pre_o(wb_data_pre_o), .s8_exception_o(exception_o),
        .s8_excp_ecode_o(excp_ecode_o), .s8_excp_esubcode_o(excp_esubcode_o),
        .s8_excp_badv_valid_o(excp_badv_valid_o), .s8_excp_badv_o(excp_badv_o),
        .s8_redirect_valid_o(redirect_valid_o),
        .s8_is_csr_o(is_csr_o), .s8_csr_we_o(csr_we_o), .s8_csr_xchg_o(csr_xchg_o),
        .s8_csr_addr_o(csr_addr_o), .s8_csr_wdata_o(csr_wdata_o), .s8_csr_wmask_o(csr_wmask_o),
        .s8_is_syscall_o(is_syscall_o), .s8_is_ertn_o(is_ertn_o),
        .s8_slot1_pc_o(slot1_pc_o), .s8_instr1_o(instr1_o), .s8_slot1_valid_o(slot1_valid_o),
        .s8_slot1_opcode_o(slot1_opcode_o), .s8_slot1_funct3_o(slot1_funct3_o),
        .s8_slot1_funct7_o(slot1_funct7_o), .s8_slot1_op_19_15_o(slot1_op_19_15_o),
        .s8_slot1_rs1_o(slot1_rs1_o), .s8_slot1_rs2_o(slot1_rs2_o), .s8_slot1_rd_o(slot1_rd_o),
        .s8_slot1_imm_o(slot1_imm_o), .s8_slot1_is_branch_o(slot1_is_branch_o),
        .s8_slot1_is_jal_o(slot1_is_jal_o), .s8_slot1_is_jalr_o(slot1_is_jalr_o),
        .s8_slot1_is_load_o(slot1_is_load_o), .s8_slot1_is_store_o(slot1_is_store_o),
        .s8_slot1_is_lui_o(slot1_is_lui_o), .s8_slot1_is_auipc_o(slot1_is_auipc_o),
        .s8_slot1_unknown_inst_o(slot1_unknown_o),
        .s8_slot1_wb_en_o(slot1_wb_en_o), .s8_slot1_uses_rs1_o(slot1_uses_rs1_o),
        .s8_slot1_uses_rs2_o(slot1_uses_rs2_o), .s8_slot1_src_a_sel_o(slot1_src_a_sel_o),
        .s8_slot1_src_b_sel_o(slot1_src_b_sel_o), .s8_slot1_alu_op_o(slot1_alu_op_o),
        .s8_slot1_rs1_val_o(slot1_rs1_val_o), .s8_slot1_rs2_val_o(slot1_rs2_val_o),
        .s8_slot1_op_a_o(slot1_op_a_o), .s8_slot1_op_b_o(slot1_op_b_o),
        .s8_slot1_alu_result_o(slot1_alu_result_o),
        .s8_slot1_mem_size_o(slot1_mem_size_o),
        .s8_slot1_store_data_o(slot1_store_data_o),
        .s8_slot1_exception_o(slot1_exception_o),
        .s8_slot1_excp_ecode_o(slot1_excp_ecode_o),
        .s8_slot1_excp_esubcode_o(slot1_excp_esubcode_o),
        .s8_slot1_excp_badv_valid_o(slot1_excp_badv_valid_o),
        .s8_slot1_excp_badv_o(slot1_excp_badv_o),
        .s8_slot1_issue_valid_o(slot1_issue_valid_o),
        .s8_slot1_issue_class_o(slot1_issue_class_o),
        .s8_slot1_emit_valid_o(slot1_emit_valid_o),
        .s8_slot1_fire_o(slot1_fire_o),
        .s8_slot1_emit_class_o(slot1_emit_class_o),
        .s8_redirect_pc_o(redirect_pc_o), .s8_branch_taken_o(branch_taken_o),
        .s8_bpu_update_valid_o(bpu_update_valid_o), .s8_bpu_update_taken_o(bpu_update_taken_o),
        .s8_bpu_update_pc_o(bpu_update_pc_o),
        .s8_bpu_update_target_o(bpu_update_target_o), .s8_bpu_update_is_call_o(bpu_update_is_call_o),
        .s8_bpu_update_is_ret_o(bpu_update_is_ret_o), .s8_bpu_update_is_jmp_o(bpu_update_is_jmp_o),
        .s8_bpu_update_is_indirect_jmp_o(bpu_update_is_indirect_jmp_o),
`ifdef PERF_MONI
        .s8_bpu_perf_valid_o(bpu_perf_valid_o), .s8_bpu_perf_is_branch_o(bpu_perf_is_branch_o),
        .s8_bpu_perf_is_jump_o(bpu_perf_is_jump_o), .s8_bpu_perf_pred_taken_o(bpu_perf_pred_taken_o),
        .s8_bpu_perf_is_ret_jirl_o(bpu_perf_is_ret_jirl_o),
        .s8_bpu_perf_is_indirect_jirl_o(bpu_perf_is_indirect_jirl_o),
        .s8_bpu_perf_pc_o(bpu_perf_pc_o),
        .s8_bpu_perf_actual_taken_o(bpu_perf_actual_taken_o), .s8_bpu_perf_correct_o(bpu_perf_correct_o),
        .s8_bpu_perf_direction_miss_o(bpu_perf_direction_miss_o),
        .s8_bpu_perf_target_miss_o(bpu_perf_target_miss_o),
        .s8_bpu_perf_exu_flush_o(bpu_perf_exu_flush_o),
`endif
        .s8_valid_o(valid_o),
        .s8_result_wait_o(result_wait_o),
        .s8_slot1_result_wait_o(slot1_result_wait_o),
        .s8_alu_result_o(alu_result_o)
    );

    initial begin
        tb_start();
        flush = 0; in_valid = 0; s9_allowin = 1; pc_i = 32'h1c010000; instr_i = 0;
        epoch_i = 2'd3; pred_taken_i = 0; pred_target_i = 0;
        fault_i = 0; fault_ecode_i = `CPU_ECODE_ADEF; fault_badv_i = 0;
        rd_i = 5'd4; imm_i = 32'h40; wb_en_i = 1; is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0;
        mem_size_i = 2'b10; mem_sign_ext_i = 1; alu_op_i = `CPU_ALU_ADD; branch_op_i = `CPU_BR_EQ;
        op_a_i = 32'h10; op_b_i = 32'h40; rs1_val_i = 32'h10; rs2_val_i = 32'h20;
        unknown_inst_i = 0; s7_branch_redirected_i = 0;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h0; slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'd0; slot1_rs2_val_i = 32'd0; slot1_op_a_i = 32'd0; slot1_op_b_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0;
        slot1_issue_class_override_en = 1'b0;
        slot1_issue_class_override = 4'd0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
        op_a_late_s10_i = 0; op_b_late_s10_i = 0; rs1_late_s10_i = 0; rs2_late_s10_i = 0;
        slot1_op_a_late_s10_i = 0; slot1_op_b_late_s10_i = 0;
        slot1_rs1_late_s10_i = 0; slot1_rs2_late_s10_i = 0; slot1_late_s10_rd_i = 0;
        late_s10_rd_i = 0; s10_late_valid_i = 0; s10_late_wb_en_i = 0; s10_late_rd_i = 0; s10_late_data_i = 0;
        csr_has_int_i = 0; csr_timer64_i = 64'h1234_5678_9abc_def0; csr_tid_i = 32'h55aa_33cc;
        reset_dut();
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 valid", out_valid && valid_o);
        `check("S8 epoch pass-through", epoch_o == 2'd3);
        `check32("S8 ALU ADD", alu_result_o, 32'h50);
        `check("S8 ADD has no multi-cycle wait", !result_wait_o);
        `check("S8 ADD has no slot1-local wait", !slot1_result_wait_o);
`ifdef PERF_MONI
        `check("S8 ALU has no BPU perf event", !bpu_perf_valid_o);
`endif
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h02801085;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd4; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd5; slot1_imm_i = 32'h4;
        slot1_rs1_val_i = 32'h1234_0004; slot1_rs2_val_i = 32'h5678_0000;
        slot1_op_a_i = 32'h1234_0004; slot1_op_b_i = 32'h4;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 sideband pass-through",
               slot1_valid_o && slot1_pc_o == 32'h1c010004 && instr1_o == 32'h02801085);
        `check32("S8 slot1 rs1 pass", {27'h0, slot1_rs1_o}, 32'd4);
        `check32("S8 slot1 rd pass", {27'h0, slot1_rd_o}, 32'd5);
        `check32("S8 slot1 imm pass", slot1_imm_o, 32'h4);
        `check("S8 slot1 kind pass",
               !slot1_unknown_o && !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check("S8 slot1 simple ALU payload pass",
               slot1_wb_en_o && slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 && slot1_src_b_sel_o == `CPU_SRC_B_IMM &&
               slot1_alu_op_o == `CPU_ALU_ADD);
        `check32("S8 slot1 rs1 value pass", slot1_rs1_val_o, 32'h1234_0004);
        `check32("S8 slot1 rs2 value pass", slot1_rs2_val_o, 32'h5678_0000);
        `check32("S8 slot1 op A pass", slot1_op_a_o, 32'h1234_0004);
        `check32("S8 slot1 op B pass", slot1_op_b_o, 32'h4);
        `check32("S8 slot1 shadow ALU ADD", slot1_alu_result_o, 32'h1234_0008);
        `check("S8 slot1 issue sideband stays off in phase1", !slot1_issue_valid_o);
        `check32("S8 slot1 issue class stays clear in phase1",
                 {28'd0, slot1_issue_class_o}, 32'd0);
        slot1_issue_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 issue sideband passes when selected",
               slot1_valid_o && slot1_issue_valid_o && slot1_rd_o == 5'd5);
        `check32("S8 selected slot1 ALU marks compute class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        `check("S8 selected slot1 ALU emits and fires to S9",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b1000);
        `check32("S8 selected slot1 ALU result applies slot0 RAW bypass when issued", slot1_alu_result_o, 32'h0000_0054);
        `check32("S8 selected slot1 ALU has no store size sideband",
                 {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("S8 selected slot1 ALU has no store data sideband", slot1_store_data_o, 32'd0);

        slot1_issue_valid_i = 1'b0;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h008);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd12; slot1_rd_i = 5'd12; slot1_imm_i = 32'h8;
        slot1_rs1_val_i = 32'h0000_8800; slot1_rs2_val_i = 32'h1357_9bdf;
        slot1_op_a_i = 32'h0000_8800; slot1_op_b_i = 32'h8;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 store prepare sideband remains unissued",
               slot1_valid_o && slot1_is_store_o && !slot1_issue_valid_o && !slot1_wb_en_o);
        `check("S8 slot1 store prepare keeps address and data source flags",
               slot1_uses_rs1_o && slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S8 slot1 store prepare address result", slot1_alu_result_o, 32'h0000_8808);
        `check32("S8 slot1 store prepare data pass", slot1_rs2_val_o, 32'h1357_9bdf);
        `check32("S8 slot1 store prepare size", {30'd0, slot1_mem_size_o}, 32'd2);
        `check32("S8 slot1 store prepare store data sideband", slot1_store_data_o, 32'h1357_9bdf);
        `check("S8 aligned slot1 store prepare has no exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check("S8 unissued slot1 store prepare has no redirect or BPU update",
               !redirect_valid_o && !bpu_update_valid_o);

        slot1_issue_valid_i = 1'b0;
        instr1_i = la_mem(4'h2, 5'd12, 5'd13, 12'h008);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd12; slot1_rd_i = 5'd12; slot1_imm_i = 32'h8;
        slot1_rs1_val_i = 32'h0000_9000; slot1_rs2_val_i = 32'h2468_ace0;
        slot1_op_a_i = 32'h0000_9000; slot1_op_b_i = 32'h8;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 load prepare sideband remains unissued",
               slot1_valid_o && slot1_is_load_o && !slot1_issue_valid_o && slot1_wb_en_o);
        `check("S8 slot1 load prepare keeps base address dependency",
               slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S8 slot1 load prepare address result", slot1_alu_result_o, 32'h0000_9008);
        `check32("S8 slot1 load prepare mem size", {30'd0, slot1_mem_size_o}, 32'd2);
        `check32("S8 slot1 load prepare has no store data sideband", slot1_store_data_o, 32'd0);
        `check("S8 aligned slot1 load prepare has no exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);

        slot1_issue_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 load keeps sideband issued",
               out_valid && slot1_valid_o && slot1_is_load_o && slot1_issue_valid_o &&
               slot1_wb_en_o && !slot1_exception_o);
        `check32("S8 selected slot1 load marks load class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0100});
        `check("S8 selected slot1 load emits and fires to S9",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b0100);
        `check32("S8 selected slot1 load address result", slot1_alu_result_o, 32'h0000_9008);
        `check32("S8 selected slot1 load mem size", {30'd0, slot1_mem_size_o}, 32'd2);

        slot1_issue_valid_i = 1'b0;
        instr1_i = la_mem(4'h9, 5'd12, 5'd13, 12'h00a);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd12; slot1_rd_i = 5'd12; slot1_imm_i = 32'ha;
        slot1_rs1_val_i = 32'h0000_9100; slot1_rs2_val_i = 32'h1122_3344;
        slot1_op_a_i = 32'h0000_9100; slot1_op_b_i = 32'ha;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 ld.hu prepare sideband remains unissued",
               slot1_valid_o && slot1_is_load_o && !slot1_issue_valid_o && slot1_wb_en_o);
        `check32("S8 slot1 ld.hu prepare address result", slot1_alu_result_o, 32'h0000_910a);
        `check32("S8 slot1 ld.hu prepare mem size", {30'd0, slot1_mem_size_o}, 32'd1);
        `check("S8 aligned slot1 ld.hu prepare has no exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);

        slot1_issue_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 ld.hu keeps sideband issued",
               out_valid && slot1_valid_o && slot1_is_load_o && slot1_issue_valid_o &&
               slot1_wb_en_o && !slot1_exception_o);
        `check32("S8 selected slot1 ld.hu mem size", {30'd0, slot1_mem_size_o}, 32'd1);

        slot1_issue_valid_i = 1'b0;
        instr1_i = la_mem(4'h2, 5'd12, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd12; slot1_rd_i = 5'd12;
        slot1_rs1_val_i = 32'h0000_9000; slot1_rs2_val_i = 32'h2468_ace0;
        slot1_op_a_i = 32'h0000_9000;
        slot1_imm_i = 32'h6;
        slot1_op_b_i = 32'h6;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 unissued unaligned slot1 load records exception candidate",
               slot1_valid_o && slot1_is_load_o && !slot1_issue_valid_o &&
               slot1_exception_o && slot1_excp_badv_valid_o);
        `check32("S8 slot1 load ALE ecode", {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S8 slot1 load ALE badv", slot1_excp_badv_o, 32'h0000_9006);
        `check("S8 unissued slot1 load ALE does not become lane0 exception",
               !exception_o && !redirect_valid_o && !bpu_update_valid_o);

        // slot1 load address can consume same-cycle slot0 ALU writeback by rs1 match.
        instr_i = 32'h0000_0000;
        rd_i = 5'd11;
        wb_en_i = 1'b1;
        is_branch_i = 1'b0;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        alu_op_i = `CPU_ALU_ADD;
        op_a_i = 32'h0000_0100;
        op_b_i = 32'h0000_0042;
        slot1_issue_valid_i = 1'b1;
        slot1_is_load_i = 1'b1;
        slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b0;
        slot1_imm_i = 32'h2;
        slot1_op_a_i = 32'h0000_8800;
        slot1_op_b_i = 32'h2;
        instr1_i = la_mem(4'h2, 5'd12, 5'd11, 12'h002);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd11;
        slot1_rs2_i = 5'd12;
        slot1_rs1_val_i = 32'haaaa_5555;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 RAW load keeps sideband issued",
               out_valid && slot1_valid_o && slot1_is_load_o &&
               slot1_issue_valid_o && !slot1_exception_o);
        `check32("S8 selected slot1 RAW load forwards slot0 ALU base",
                 slot1_op_a_o, 32'h0000_0142);
        `check32("S8 selected slot1 RAW load uses forwarded base for address",
                 slot1_alu_result_o, 32'h0000_0144);
        `check32("S8 selected slot1 RAW load mem size",
                 {30'd0, slot1_mem_size_o}, 32'd2);

        // slot1 ALU operands can consume same-cycle slot0 ALU writeback by rd match.
        instr_i = 32'h0000_0000;
        rd_i = 5'd11;
        wb_en_i = 1'b1;
        is_branch_i = 1'b0;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        alu_op_i = `CPU_ALU_ADD;
        op_a_i = 32'h0000_0100;
        op_b_i = 32'h0000_0042;
        slot1_issue_valid_i = 1'b1;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1;
        slot1_src_b_sel_i = `CPU_SRC_B_RS2;
        slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_imm_i = 32'd0;
        slot1_op_a_i = 32'h1111_2222;
        slot1_op_b_i = 32'h3333_4444;
        instr1_i = la_alu_3r(5'h00, 5'd12, 5'd11, 5'd11);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd11;
        slot1_rs2_i = 5'd11;
        slot1_rs1_val_i = 32'haaaa_5555;
        slot1_rs2_val_i = 32'h5555_aaaa;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 RAW compute keeps sideband issued",
               out_valid && slot1_valid_o && !slot1_is_load_o && !slot1_is_store_o &&
               slot1_issue_valid_o && slot1_wb_en_o && !slot1_exception_o);
        `check32("S8 selected slot1 RAW compute forwards slot0 ALU rs1",
                 slot1_op_a_o, 32'h0000_0142);
        `check32("S8 selected slot1 RAW compute forwards slot0 ALU rs2",
                 slot1_op_b_o, 32'h0000_0142);
        `check32("S8 selected slot1 RAW compute uses forwarded operands",
                 slot1_alu_result_o, 32'h0000_0284);

        // slot1 branch compare can consume same-cycle slot0 ALU writeback by rd match.
        instr_i = 32'h0000_0000;
        rd_i = 5'd11;
        wb_en_i = 1'b1;
        is_branch_i = 1'b0;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        alu_op_i = `CPU_ALU_ADD;
        op_a_i = 32'h0000_0100;
        op_b_i = 32'h0000_0042;
        slot1_pc_i = 32'h1c010200;
        slot1_issue_valid_i = 1'b1;
        slot1_is_branch_i = 1'b1;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b0;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1;
        slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_imm_i = 32'h10;
        slot1_op_a_i = 32'h0000_0001;
        slot1_op_b_i = 32'h0000_0010;
        instr1_i = la_branch(6'h16, 5'd11, 5'd11, 16'h0004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd11;
        slot1_rs2_i = 5'd11;
        slot1_rs1_val_i = 32'h0000_0001;
        slot1_rs2_val_i = 32'h0000_0002;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 RAW branch redirects on forwarded compare",
               out_valid && slot1_valid_o && slot1_issue_valid_o &&
               slot1_is_branch_o && redirect_valid_o &&
               bpu_update_valid_o && bpu_update_taken_o);
        `check32("S8 selected slot1 branch marks ctrl class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0001});
        `check32("S8 selected slot1 RAW branch redirect target",
                 redirect_pc_o, 32'h1c010210);
        `check32("S8 selected slot1 RAW branch BPU update target",
                 bpu_update_target_o, 32'h1c010210);

        // slot1 store-data can consume same-cycle slot0 ALU writeback by rd match.
        instr_i = 32'h0000_0000;
        rd_i = 5'd11;
        wb_en_i = 1'b1;
        is_branch_i = 1'b0;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        alu_op_i = `CPU_ALU_ADD;
        op_a_i = 32'h0000_0100;
        op_b_i = 32'h0000_0042;
        slot1_issue_valid_i = 1'b1;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b1;
        slot1_wb_en_i = 1'b0;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1;
        slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_imm_i = 32'h8;
        slot1_op_a_i = 32'h0000_8800;
        slot1_op_b_i = 32'h8;
        instr1_i = la_mem(4'h6, 5'd11, 5'd13, 12'h008);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd11;
        slot1_rs2_val_i = 32'haaaa_5555;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 store keeps sideband issued",
               out_valid && slot1_valid_o && slot1_is_store_o &&
               slot1_issue_valid_o && !slot1_exception_o);
        `check32("S8 selected slot1 store marks store class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0010});
        `check("S8 selected slot1 store emits and fires to S9",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b0010);
        `check32("S8 selected slot1 RAW store forwards slot0 ALU data",
                 slot1_store_data_o, 32'h0000_0142);
        `check32("S8 selected slot1 RAW store keeps original rs2 value sideband",
                 slot1_rs2_val_o, 32'haaaa_5555);

        slot1_issue_class_override_en = 1'b1;
        slot1_issue_class_override = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 store with non-store class is resource-silent",
               slot1_issue_valid_o && !slot1_is_store_o &&
               !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check32("S8 slot1 store with non-store class clears mem size",
                 {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("S8 slot1 store with non-store class clears store data",
                 slot1_store_data_o, 32'd0);
        `check32("S8 slot1 store keeps overridden issue class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        slot1_issue_class_override_en = 1'b0;
        slot1_issue_class_override = 4'd0;

        slot1_issue_valid_i = 1'b0;
        slot1_rs2_i = 5'd12;
        slot1_rs2_val_i = 32'h1357_9bdf;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_imm_i = 32'h6;
        slot1_op_a_i = 32'h0000_8800; slot1_op_b_i = 32'h6;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 unissued unaligned slot1 store records exception candidate",
               slot1_valid_o && slot1_is_store_o && !slot1_issue_valid_o &&
               slot1_exception_o && slot1_excp_badv_valid_o);
        `check32("S8 slot1 store ALE ecode", {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S8 slot1 store ALE badv", slot1_excp_badv_o, 32'h0000_8806);
        `check("S8 unissued slot1 store ALE does not become lane0 exception",
               !exception_o && !redirect_valid_o && !bpu_update_valid_o);

        slot1_issue_valid_i = 1'b0;
        instr1_i = la_mem(4'h9, 5'd14, 5'd13, 12'h002);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd14; slot1_imm_i = 32'h2;
        slot1_rs1_val_i = 32'h0000_8800; slot1_rs2_val_i = 32'h0;
        slot1_op_a_i = 32'h0000_8800; slot1_op_b_i = 32'h2;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 load prepare sideband remains unissued",
               slot1_valid_o && slot1_is_load_o && !slot1_is_store_o &&
               !slot1_issue_valid_o && slot1_wb_en_o);
        `check("S8 slot1 load prepare keeps address source flags",
               slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S8 slot1 load prepare address result", slot1_alu_result_o, 32'h0000_8802);
        `check32("S8 slot1 load prepare half size", {30'd0, slot1_mem_size_o}, 32'd1);
        `check32("S8 slot1 load prepare has no store data sideband", slot1_store_data_o, 32'd0);
        `check("S8 aligned slot1 load prepare has no exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);

        slot1_issue_valid_i = 1'b1;
        instr1_i = la_mem(4'h2, 5'd15, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rd_i = 5'd15; slot1_imm_i = 32'h6;
        slot1_op_a_i = 32'h0000_8800; slot1_op_b_i = 32'h6;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 issued unaligned slot1 load records exception candidate",
               slot1_valid_o && slot1_is_load_o && slot1_issue_valid_o &&
               slot1_exception_o && slot1_excp_badv_valid_o);
        `check32("S8 slot1 load ALE ecode", {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S8 slot1 load ALE badv", slot1_excp_badv_o, 32'h0000_8806);
        `check("S8 slot1 load ALE does not become lane0 exception",
               !exception_o && !redirect_valid_o && !bpu_update_valid_o);

        slot1_issue_valid_i = 1'b0;
        slot1_op_a_i = 32'ha5a5_0f0f; slot1_op_b_i = 32'h00ff_0ff0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs2_i = 1'b0;
        slot1_alu_op_i = `CPU_ALU_XOR;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S8 slot1 shadow ALU XOR", slot1_alu_result_o, 32'ha55a_00ff);
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_opcode_i = 7'h7f; slot1_funct3_i = 3'h7; slot1_funct7_i = 7'h7f; slot1_op_19_15_i = 5'h1f;
        slot1_rs1_i = 5'd31; slot1_rs2_i = 5'd30; slot1_rd_i = 5'd29; slot1_imm_i = 32'hffff_ffff;
        slot1_is_branch_i = 1'b1; slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b1; slot1_unknown_i = 1'b1;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_PC; slot1_src_b_sel_i = `CPU_SRC_B_FOUR; slot1_alu_op_i = `CPU_ALU_XOR;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 invalid clears outputs",
               !slot1_valid_o && !slot1_unknown_o && !slot1_is_branch_o &&
               !slot1_is_load_o && !slot1_is_store_o);
        `check("S8 slot1 invalid clears issue sideband", !slot1_issue_valid_o);
        `check32("S8 slot1 invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S8 slot1 invalid clears emit event",
               !slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'd0);
        `check("S8 slot1 invalid clears simple ALU payload",
               !slot1_wb_en_o && !slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == 2'd0 && slot1_src_b_sel_o == 2'd0 && slot1_alu_op_o == 4'd0);
        `check32("S8 slot1 invalid clears rs1 value", slot1_rs1_val_o, 32'd0);
        `check32("S8 slot1 invalid clears rs2 value", slot1_rs2_val_o, 32'd0);
        `check32("S8 slot1 invalid clears op A", slot1_op_a_o, 32'd0);
        `check32("S8 slot1 invalid clears op B", slot1_op_b_o, 32'd0);
        `check32("S8 slot1 invalid clears shadow ALU result", slot1_alu_result_o, 32'd0);
        `check32("S8 slot1 invalid clears store size", {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("S8 slot1 invalid clears store data", slot1_store_data_o, 32'd0);
        `check("S8 slot1 invalid clears exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check32("S8 slot1 invalid clears exception badv", slot1_excp_badv_o, 32'd0);
        `check32("S8 slot1 invalid clears rs1", {27'h0, slot1_rs1_o}, 32'd0);
        `check32("S8 slot1 invalid clears rd", {27'h0, slot1_rd_o}, 32'd0);
        `check32("S8 slot1 invalid clears imm", slot1_imm_o, 32'd0);
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'd0; slot1_rs2_val_i = 32'd0; slot1_op_a_i = 32'd0; slot1_op_b_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0;
        slot1_issue_class_override_en = 1'b0;
        slot1_issue_class_override = 4'd0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;

        in_valid = 1'b0;
        tick(); #1;
        s9_allowin = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_issue_class_override_en = 1'b1;
        slot1_issue_class_override = 4'b1000;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_branch_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 emits but does not fire under S9 backpressure",
               slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'b1000);
        s9_allowin = 1'b1;
        slot1_issue_class_override_en = 1'b0;
        slot1_issue_class_override = 4'd0;
        slot1_issue_valid_i = 1'b0;

        reset_dut();
        pc_i = 32'h1c0100f0; instr_i = 32'h0000_0000; imm_i = 32'h4;
        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0;
        fault_i = 0; unknown_inst_i = 0; wb_en_i = 1; pred_taken_i = 0; pred_target_i = 32'h0;
        alu_op_i = `CPU_ALU_ADD; op_a_i = 32'h1; op_b_i = 32'h2;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b0;
        slot1_pc_i = 32'h1c010100;
        instr1_i = {6'h16, 16'h0008, 5'd3, 5'd2};
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd3; slot1_rs2_i = 5'd2; slot1_rd_i = 5'd2;
        slot1_imm_i = 32'h20;
        slot1_rs1_val_i = 32'h0000_0055; slot1_rs2_val_i = 32'h0000_0055;
        slot1_op_a_i = 32'd0; slot1_op_b_i = 32'd0;
        slot1_is_branch_i = 1'b1; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0; slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 unissued slot1 branch does not redirect", !redirect_valid_o);
        `check("S8 unissued slot1 branch does not train BPU", !bpu_update_valid_o);

        slot1_issue_valid_i = 1'b1;
        slot1_rs1_val_i = 32'h0000_0011; slot1_rs2_val_i = 32'h0000_0022;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 not-taken branch does not redirect", !redirect_valid_o);
        `check("S8 selected slot1 not-taken branch trains BPU", bpu_update_valid_o && !bpu_update_taken_o);
        `check32("S8 selected slot1 not-taken branch update PC", bpu_update_pc_o, 32'h1c010100);
        `check32("S8 selected slot1 not-taken branch update target", bpu_update_target_o, 32'h1c010120);
        `check("S8 selected slot1 not-taken branch update type", !bpu_update_is_jmp_o && !bpu_update_is_call_o && !bpu_update_is_ret_o);

        slot1_rs1_val_i = 32'h0000_0033; slot1_rs2_val_i = 32'h0000_0033;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 taken branch redirects", redirect_valid_o);
        `check32("S8 selected slot1 redirect target", redirect_pc_o, 32'h1c010120);
        `check("S8 selected slot1 taken branch trains BPU", bpu_update_valid_o && bpu_update_taken_o);
        `check32("S8 selected slot1 taken branch update PC", bpu_update_pc_o, 32'h1c010100);
        `check32("S8 selected slot1 taken branch update target", bpu_update_target_o, 32'h1c010120);

        slot1_issue_class_override_en = 1'b1;
        slot1_issue_class_override = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 branch with non-ctrl class is resource-silent",
               slot1_issue_valid_o && !redirect_valid_o && !bpu_update_valid_o);
        `check32("S8 slot1 branch keeps overridden issue class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        slot1_issue_class_override_en = 1'b0;
        slot1_issue_class_override = 4'd0;

        slot1_pc_i = 32'h1c010140;
        instr1_i = {6'h15, 16'h0008, 5'd0, 5'd0};
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd1;
        slot1_imm_i = 32'h20;
        slot1_rs1_val_i = 32'd0; slot1_rs2_val_i = 32'd0;
        slot1_op_a_i = 32'h1c01_0140; slot1_op_b_i = 32'd4;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b1; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_PC; slot1_src_b_sel_i = `CPU_SRC_B_FOUR; slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_issue_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 BL redirects", redirect_valid_o);
        `check32("S8 selected slot1 BL redirect target", redirect_pc_o, 32'h1c010160);
        `check("S8 selected slot1 BL trains BPU", bpu_update_valid_o && bpu_update_taken_o);
        `check32("S8 selected slot1 BL update PC", bpu_update_pc_o, 32'h1c010140);
        `check32("S8 selected slot1 BL update target", bpu_update_target_o, 32'h1c010160);
        `check("S8 selected slot1 BL marks call jump", bpu_update_is_call_o && bpu_update_is_jmp_o && !bpu_update_is_ret_o);
        `check("S8 slot1 BL keeps writeback sideband", slot1_wb_en_o && slot1_issue_valid_o);
        `check32("S8 slot1 BL link result is PC+4", slot1_alu_result_o, 32'h1c010144);

        slot1_pc_i = 32'h1c010180;
        instr1_i = {6'h13, 16'h0020, 5'd7, 5'd1};
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd7; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd1;
        slot1_imm_i = 32'h20;
        slot1_rs1_val_i = 32'h1c02_0000; slot1_rs2_val_i = 32'd0;
        slot1_op_a_i = 32'h1c01_0180; slot1_op_b_i = 32'd4;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b1;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_PC; slot1_src_b_sel_i = `CPU_SRC_B_FOUR; slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_issue_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 selected slot1 JIRL redirects", redirect_valid_o);
        `check32("S8 selected slot1 JIRL redirect target", redirect_pc_o, 32'h1c020020);
        `check("S8 selected slot1 JIRL trains BPU", bpu_update_valid_o && bpu_update_taken_o);
        `check32("S8 selected slot1 JIRL update PC", bpu_update_pc_o, 32'h1c010180);
        `check32("S8 selected slot1 JIRL update target", bpu_update_target_o, 32'h1c020020);
        `check("S8 selected slot1 JIRL marks indirect jump",
               !bpu_update_is_call_o && !bpu_update_is_ret_o &&
               !bpu_update_is_jmp_o && bpu_update_is_indirect_jmp_o);
        `check("S8 slot1 JIRL keeps writeback sideband", slot1_wb_en_o && slot1_issue_valid_o);
        `check32("S8 slot1 JIRL link result is PC+4", slot1_alu_result_o, 32'h1c010184);

        pc_i = 32'h1c010200; imm_i = 32'h20; is_branch_i = 1'b1; wb_en_i = 1'b0;
        rs1_val_i = 32'h0000_0077; rs2_val_i = 32'h0000_0077; branch_op_i = `CPU_BR_EQ;
        slot1_pc_i = 32'h1c010300; slot1_imm_i = 32'h40;
        slot1_rs1_val_i = 32'h0000_0088; slot1_rs2_val_i = 32'h0000_0088;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 lane0 redirect wins over same-packet slot1 redirect", redirect_valid_o);
        `check32("S8 lane0 redirect priority target", redirect_pc_o, 32'h1c010220);

        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b0;
        slot1_is_branch_i = 1'b0;
        slot1_uses_rs1_i = 1'b0;
        slot1_uses_rs2_i = 1'b0;
        is_branch_i = 1'b0;
        wb_en_i = 1'b1;
        pc_i = 32'h1c010004;
        imm_i = 32'h40;

        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; wb_en_i = 1; pred_taken_i = 0; pred_target_i = 0;
        instr_i = la_alu_3r(5'h18, 5'd4, 5'd5, 5'd6); op_a_i = 32'hffff_fffe; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 mul.w completes in one EX2 cycle", out_valid && !result_wait_o);
        `check32("S8 mul.w low 32 bits", alu_result_o, 32'hffff_fffa);

        instr_i = la_alu_3r(5'h19, 5'd4, 5'd5, 5'd6); op_a_i = 32'hffff_fffe; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S8 mulh.w signed high 32 bits", alu_result_o, 32'hffff_ffff);

        instr_i = la_alu_3r(5'h1a, 5'd4, 5'd5, 5'd6); op_a_i = 32'hffff_fffe; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S8 mulh.wu unsigned high 32 bits", alu_result_o, 32'h0000_0002);

        instr_i = la_alu_3r(5'h00, 5'd4, 5'd5, 5'd6);
        op_a_i = 32'h0000_0001; op_b_i = 32'h0000_0002;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_pc_i = 32'h1c010008;
        instr1_i = la_alu_3r(5'h18, 5'd9, 5'd10, 5'd11);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd10; slot1_rs2_i = 5'd11; slot1_rd_i = 5'd9;
        slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'hffff_fffe; slot1_rs2_val_i = 32'h0000_0003;
        slot1_op_a_i = 32'hffff_fffe; slot1_op_b_i = 32'h0000_0003;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_RS2; slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 mul.w keeps issue/writeback sideband",
               slot1_issue_valid_o && slot1_wb_en_o &&
               slot1_uses_rs1_o && slot1_uses_rs2_o);
        `check32("S8 slot1 mul.w low 32 bits", slot1_alu_result_o, 32'hffff_fffa);

        instr1_i = la_alu_3r(5'h19, 5'd9, 5'd10, 5'd11);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_op_a_i = 32'hffff_fffe; slot1_op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S8 slot1 mulh.w signed high 32 bits", slot1_alu_result_o, 32'hffff_ffff);

        instr1_i = la_alu_3r(5'h1a, 5'd9, 5'd10, 5'd11);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_op_a_i = 32'hffff_fffe; slot1_op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S8 slot1 mulh.wu unsigned high 32 bits", slot1_alu_result_o, 32'h0000_0002);

        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0;
        slot1_op_a_i = 32'd0; slot1_op_b_i = 32'd0;

        reset_dut();
        instr_i = {6'h00, 4'hd, 12'h020, 5'd12, 5'd12}; // andi r12,r12,0x20
        rd_i = 5'd12; wb_en_i = 1'b1;
        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0;
        alu_op_i = `CPU_ALU_AND; op_a_i = 32'h0; op_b_i = 32'h20;
        op_a_late_s10_i = 1'b1; rs1_late_s10_i = 1'b1;
        late_s10_rd_i = 5'd12;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 late S10 operand waits until data arrives", valid_o && !out_valid && !allowin && result_wait_o);
        s10_late_valid_i = 1'b1; s10_late_wb_en_i = 1'b1; s10_late_rd_i = 5'd13; s10_late_data_i = 32'hffff_ffff; #1;
        `check("S8 late S10 ignores mismatched rd", valid_o && !out_valid && !allowin && result_wait_o);
        s10_late_rd_i = 5'd12; #1;
        `check("S8 late S10 operand emits when data arrives", out_valid && allowin);
        `check32("S8 late S10 operand feeds ALU", alu_result_o, 32'h0000_0020);
        tick(); #1;
        s10_late_valid_i = 1'b0; s10_late_wb_en_i = 1'b0; s10_late_rd_i = 5'd0; s10_late_data_i = 32'h0;
        op_a_late_s10_i = 1'b0; rs1_late_s10_i = 1'b0;
        op_b_late_s10_i = 1'b0; rs2_late_s10_i = 1'b0;
        late_s10_rd_i = 5'd0;
        alu_op_i = `CPU_ALU_ADD;
        `check("S8 late S10 issued instruction leaves EX2", !valid_o && allowin);

        reset_dut();
        instr_i = 32'h0000_0000;
        rd_i = 5'd1;
        wb_en_i = 1'b1;
        is_branch_i = 1'b0;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        alu_op_i = `CPU_ALU_ADD;
        op_a_i = 32'h0000_0001;
        op_b_i = 32'h0000_0002;
        op_a_late_s10_i = 1'b0;
        op_b_late_s10_i = 1'b0;
        rs1_late_s10_i = 1'b0;
        rs2_late_s10_i = 1'b0;
        late_s10_rd_i = 5'd0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1;
        slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_SRL;
        slot1_rs1_i = 5'd4;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd9;
        slot1_imm_i = 32'd1;
        slot1_rs1_val_i = 32'h0000_0068;
        slot1_rs2_val_i = 32'd0;
        slot1_op_a_i = 32'h0000_0068;
        slot1_op_b_i = 32'd1;
        slot1_op_a_late_s10_i = 1'b1;
        slot1_op_b_late_s10_i = 1'b0;
        slot1_rs1_late_s10_i = 1'b1;
        slot1_rs2_late_s10_i = 1'b0;
        slot1_late_s10_rd_i = 5'd4;
        s10_late_valid_i = 1'b0;
        s10_late_wb_en_i = 1'b0;
        s10_late_rd_i = 5'd0;
        s10_late_data_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 slot1 late S10 operand waits before data arrives",
               valid_o && !out_valid && !allowin && result_wait_o && slot1_result_wait_o);
        s10_late_valid_i = 1'b1;
        s10_late_wb_en_i = 1'b1;
        s10_late_rd_i = 5'd4;
        s10_late_data_i = 32'h0000_a069;
        #1;
        `check("S8 slot1 late S10 operand emits when data arrives",
               out_valid && allowin && slot1_issue_valid_o && !slot1_result_wait_o);
        `check32("S8 slot1 late S10 refreshes rs1 value",
                 slot1_rs1_val_o, 32'h0000_a069);
        `check32("S8 slot1 late S10 refreshes op A",
                 slot1_op_a_o, 32'h0000_a069);
        `check32("S8 slot1 late S10 feeds ALU result",
                 slot1_alu_result_o, 32'h0000_5034);
        tick(); #1;
        s10_late_valid_i = 1'b0;
        s10_late_wb_en_i = 1'b0;
        s10_late_rd_i = 5'd0;
        s10_late_data_i = 32'd0;
        slot1_op_a_late_s10_i = 1'b0;
        slot1_rs1_late_s10_i = 1'b0;
        slot1_late_s10_rd_i = 5'd0;
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0;

        reset_dut();
        instr_i = {6'h00, 4'hd, 12'h020, 5'd12, 5'd12}; // andi r12,r12,0x20
        rd_i = 5'd12;
        wb_en_i = 1'b1;
        is_branch_i = 1'b0;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        alu_op_i = `CPU_ALU_AND;
        op_a_i = 32'h0000_0000;
        op_b_i = 32'h0000_0020;
        op_a_late_s10_i = 1'b1;
        op_b_late_s10_i = 1'b0;
        rs1_late_s10_i = 1'b1;
        rs2_late_s10_i = 1'b0;
        late_s10_rd_i = 5'd12;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1;
        slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_SRL;
        slot1_rs1_i = 5'd4;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd9;
        slot1_imm_i = 32'd1;
        slot1_rs1_val_i = 32'h0000_0068;
        slot1_rs2_val_i = 32'd0;
        slot1_op_a_i = 32'h0000_0068;
        slot1_op_b_i = 32'd1;
        slot1_op_a_late_s10_i = 1'b1;
        slot1_op_b_late_s10_i = 1'b0;
        slot1_rs1_late_s10_i = 1'b1;
        slot1_rs2_late_s10_i = 1'b0;
        slot1_late_s10_rd_i = 5'd4;
        s10_late_valid_i = 1'b1;
        s10_late_wb_en_i = 1'b1;
        s10_late_rd_i = 5'd4;
        s10_late_data_i = 32'h0000_a068;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 dual-lane late S10 waits when only slot1 data arrived",
               valid_o && !out_valid && !allowin && result_wait_o && !slot1_result_wait_o);
        s10_late_rd_i = 5'd12;
        s10_late_data_i = 32'hffff_ffff;
        #1;
        `check("S8 dual-lane late S10 emits after both lanes have data",
               out_valid && allowin && slot1_issue_valid_o && !slot1_result_wait_o);
        `check32("S8 dual-lane late S10 lane0 uses its own data",
                 alu_result_o, 32'h0000_0020);
        `check32("S8 dual-lane late S10 slot1 keeps held data",
                 slot1_rs1_val_o, 32'h0000_a068);
        `check32("S8 dual-lane late S10 slot1 op A keeps held data",
                 slot1_op_a_o, 32'h0000_a068);
        `check32("S8 dual-lane late S10 slot1 ALU uses held data",
                 slot1_alu_result_o, 32'h0000_5034);
        tick(); #1;
        s10_late_valid_i = 1'b0;
        s10_late_wb_en_i = 1'b0;
        s10_late_rd_i = 5'd0;
        s10_late_data_i = 32'd0;
        op_a_late_s10_i = 1'b0;
        rs1_late_s10_i = 1'b0;
        late_s10_rd_i = 5'd0;
        slot1_op_a_late_s10_i = 1'b0;
        slot1_rs1_late_s10_i = 1'b0;
        slot1_late_s10_rd_i = 5'd0;
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0;

        reset_dut();
        s9_allowin = 1'b0;
        instr_i = {6'h00, 4'hd, 12'h020, 5'd12, 5'd12};
        rd_i = 5'd12; wb_en_i = 1'b1; alu_op_i = `CPU_ALU_AND;
        op_a_i = 32'h0; op_b_i = 32'h20;
        op_a_late_s10_i = 1'b1; rs1_late_s10_i = 1'b1; late_s10_rd_i = 5'd12;
        s10_late_valid_i = 1'b1; s10_late_wb_en_i = 1'b1; s10_late_rd_i = 5'd12;
        s10_late_data_i = 32'hffff_ffff;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 late S10 holds data while S9 backpressures", valid_o && out_valid && !allowin);
        s10_late_valid_i = 1'b0; s10_late_wb_en_i = 1'b0; s10_late_rd_i = 5'd0; s10_late_data_i = 32'h0;
        s9_allowin = 1'b1; #1;
        `check("S8 late S10 emits held data after backpressure clears", out_valid && allowin);
        `check32("S8 late S10 held data feeds ALU", alu_result_o, 32'h0000_0020);
        tick(); #1;
        op_a_late_s10_i = 1'b0; rs1_late_s10_i = 1'b0; late_s10_rd_i = 5'd0;
        alu_op_i = `CPU_ALU_ADD;
        s9_allowin = 1'b1;

        instr_i = la_div_3r(5'h00, 5'd4, 5'd5, 5'd6); op_a_i = 32'hffff_fff6; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 div.w starts multi-cycle wait", result_wait_o && !out_valid && !allowin);
        `check("S8 div.w does not mark slot1-local wait", !slot1_result_wait_o);
        `wait_signal("S8 div.w eventually completes", 40, out_valid);
        #1;
        `check("S8 div.w clears result wait", !result_wait_o);
        `check32("S8 div.w signed quotient", alu_result_o, 32'hffff_fffd);

        instr_i = la_div_3r(5'h01, 5'd4, 5'd5, 5'd6); op_a_i = 32'hffff_fff6; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `wait_signal("S8 mod.w eventually completes", 40, out_valid);
        #1;
        `check32("S8 mod.w signed remainder", alu_result_o, 32'hffff_ffff);

        instr_i = la_div_3r(5'h02, 5'd4, 5'd5, 5'd6); op_a_i = 32'h0000_000a; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `wait_signal("S8 div.wu eventually completes", 40, out_valid);
        #1;
        `check32("S8 div.wu quotient", alu_result_o, 32'h0000_0003);

        instr_i = la_div_3r(5'h03, 5'd4, 5'd5, 5'd6); op_a_i = 32'h0000_000a; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `wait_signal("S8 mod.wu eventually completes", 40, out_valid);
        #1;
        `check32("S8 mod.wu remainder", alu_result_o, 32'h0000_0001);

        instr_i = la_div_3r(5'h00, 5'd4, 5'd5, 5'd6); op_a_i = 32'h0000_0064; op_b_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 div.w busy before flush", result_wait_o && !out_valid && !allowin);
        flush = 1'b1; tick(); flush = 1'b0; #1;
        `check("S8 flush kills busy div immediately", !valid_o && !out_valid && allowin && !result_wait_o);
        repeat (40) tick();
        #1;
        `check("S8 flushed div never emits later", !out_valid && !valid_o);
        in_valid = 1'b0;
        reset_dut();

        pc_i = 32'h1c010004; instr_i = la_csr(5'd12, 5'd0, 14'h000); rd_i = 5'd12;
        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0;
        wb_en_i = 1; rs1_val_i = 32'h1111_1111; rs2_val_i = 32'h2222_2222;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 csrrd is CSR result-waiting op", out_valid && is_csr_o && !csr_we_o && result_wait_o);
        `check32("S8 csrrd CSR addr", {18'd0, csr_addr_o}, 32'h0000_0000);

        instr_i = la_csr(5'd13, 5'd1, 14'h006); rd_i = 5'd13; rs2_val_i = 32'h1c00_8120;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 csrwr writes full CSR", out_valid && is_csr_o && csr_we_o && !csr_xchg_o);
        `check32("S8 csrwr addr ERA", {18'd0, csr_addr_o}, 32'h0000_0006);
        `check32("S8 csrwr data uses rd source", csr_wdata_o, 32'h1c00_8120);
        `check32("S8 csrwr mask all ones", csr_wmask_o, 32'hffff_ffff);

        instr_i = la_csr(5'd14, 5'd15, 14'h001); rd_i = 5'd14;
        rs1_val_i = 32'h0000_0007; rs2_val_i = 32'h0000_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 csrxchg writes masked CSR", out_valid && is_csr_o && csr_we_o && csr_xchg_o);
        `check32("S8 csrxchg addr PRMD", {18'd0, csr_addr_o}, 32'h0000_0001);
        `check32("S8 csrxchg data uses rd source", csr_wdata_o, 32'h0000_0003);
        `check32("S8 csrxchg mask uses rj source", csr_wmask_o, 32'h0000_0007);

        instr_i = la_syscall(); wb_en_i = 0; fault_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 syscall raises exception sideband", out_valid && exception_o && is_syscall_o && !is_ertn_o);
        `check32("S8 syscall ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_SYS});

        instr_i = la_break(); wb_en_i = 0; fault_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 break raises exception sideband", out_valid && exception_o && !is_syscall_o && !is_ertn_o);
        `check32("S8 break ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_BRK});

        instr_i = 32'hffff_ffff; wb_en_i = 0; unknown_inst_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 unknown instruction raises INE", out_valid && exception_o);
        `check32("S8 INE ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_INE});
        unknown_inst_i = 1'b0;

        instr_i = la_rdcntvl(5'd8); wb_en_i = 1; rd_i = 5'd8;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 rdcntvl writes without exception", out_valid && !exception_o && wb_en_o);
        `check32("S8 rdcntvl result low timer", wb_data_pre_o, 32'h9abc_def0);

        instr_i = la_rdcntvh(5'd9); rd_i = 5'd9;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S8 rdcntvh result high timer", wb_data_pre_o, 32'h1234_5678);

        instr_i = la_rdcntid(5'd10); rd_i = 5'd10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S8 rdcntid result TID", wb_data_pre_o, 32'h55aa_33cc);

        instr_i = 32'h0000_0000; wb_en_i = 1; fault_i = 1'b1; pc_i = 32'h227f_9789;
        fault_ecode_i = `CPU_ECODE_ADEF; fault_badv_i = 32'h227f_9789;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 fetch fault raises ADEF", out_valid && exception_o && excp_badv_valid_o);
        `check32("S8 ADEF ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_ADEF});
        `check32("S8 ADEF BADV is PC", excp_badv_o, 32'h227f_9789);

        instr_i = 32'h0000_0000; wb_en_i = 1; fault_i = 1'b1; pc_i = 32'h1c010000;
        fault_ecode_i = `CPU_ECODE_PIF; fault_badv_i = 32'h4000_1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 fetch TLB fault preserves ecode", out_valid && exception_o && excp_badv_valid_o);
        `check32("S8 PIF ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_PIF});
        `check32("S8 PIF BADV sideband", excp_badv_o, 32'h4000_1000);
        `check32("S8 non-ADEF fault has zero esubcode", {23'd0, excp_esubcode_o}, 32'h0);
        fault_i = 1'b0; pc_i = 32'h1c010004;

        instr_i = 32'h0000_0000; is_load_i = 1'b1; is_store_i = 1'b0; mem_size_i = 2'b10;
        op_a_i = 32'h1d00_0000; op_b_i = 32'h0000_0002; wb_en_i = 1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 unaligned word load raises ALE", out_valid && exception_o && excp_badv_valid_o);
        `check32("S8 ALE ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S8 ALE BADV is effective address", excp_badv_o, 32'h1d00_0002);
        is_load_i = 1'b0; mem_size_i = 2'b10; op_a_i = 32'h10; op_b_i = 32'h40;

        instr_i = 32'h0000_0000; csr_has_int_i = 1'b1; wb_en_i = 1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 pending interrupt raises INT", out_valid && exception_o && !excp_badv_valid_o);
        `check32("S8 INT ECODE", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_INT});
        csr_has_int_i = 1'b0;

        instr_i = la_ertn(); wb_en_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 ertn sideband without exception", out_valid && is_ertn_o && !exception_o);

        instr_i = 32'h0000_0000;
        pc_i = 32'h1c010010; imm_i = 32'h10; is_branch_i = 1; wb_en_i = 0; op_a_i = 32'h0; op_b_i = 32'h0;
        rs1_val_i = 32'h55; rs2_val_i = 32'h55; pred_taken_i = 0; branch_op_i = `CPU_BR_EQ; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 redirect", redirect_valid_o);
        `check32("S8 redirect target", redirect_pc_o, 32'h1c010020);
        `check("S8 branch BPU update valid", bpu_update_valid_o);
        `check("S8 branch BPU update taken", bpu_update_taken_o);
        `check32("S8 branch BPU update target", bpu_update_target_o, 32'h1c010020);
`ifdef PERF_MONI
        `check("S8 branch BPU perf valid", bpu_perf_valid_o && bpu_perf_is_branch_o && !bpu_perf_is_jump_o);
        `check("S8 branch BPU perf direction miss", bpu_perf_direction_miss_o && bpu_perf_exu_flush_o && !bpu_perf_correct_o);
        `check("S8 branch BPU perf target hit", !bpu_perf_target_miss_o);
        `check("S8 branch BPU perf taken fields", !bpu_perf_pred_taken_o && bpu_perf_actual_taken_o);
`endif

        pc_i = 32'h1c010024; imm_i = 32'h10; is_branch_i = 1; wb_en_i = 0;
        rs1_val_i = 32'h66; rs2_val_i = 32'h66; pred_taken_i = 0; branch_op_i = `CPU_BR_EQ;
        s7_branch_redirected_i = 1'b1; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 suppresses branch redirect already issued by S7", !redirect_valid_o);
        `check("S8 still trains BPU for S7-corrected branch", bpu_update_valid_o && bpu_update_taken_o);
`ifdef PERF_MONI
        `check("S8 keeps original prediction stats for S7-corrected branch",
               bpu_perf_valid_o && bpu_perf_direction_miss_o && bpu_perf_exu_flush_o && !bpu_perf_correct_o);
`endif
        s7_branch_redirected_i = 1'b0;

        reset_dut();
        s7_branch_redirected_i = 1'b0;
        s9_allowin = 1'b0;
        flush = 1'b0;
        pc_i = 32'h1c010030; instr_i = 32'h0000_0000; imm_i = 32'h10;
        is_branch_i = 1; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0;
        wb_en_i = 0; pred_taken_i = 0; pred_target_i = 32'h0;
        rs1_val_i = 32'h1234_5678; rs2_val_i = 32'h1234_5678; branch_op_i = `CPU_BR_EQ;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 stalled redirect keeps branch valid", valid_o && out_valid && redirect_valid_o && !allowin);
        `check("S8 stalled branch does not update BPU twice", !bpu_update_valid_o);
`ifdef PERF_MONI
        `check("S8 stalled branch does not count perf event", !bpu_perf_valid_o);
`endif
        s9_allowin = 1'b1; #1;
        `check("S8 branch updates BPU when it fires to S9", bpu_update_valid_o && bpu_update_taken_o);
`ifdef PERF_MONI
        `check("S8 branch perf counts when it fires to S9", bpu_perf_valid_o && bpu_perf_direction_miss_o);
`endif
        tick(); #1;
        `check("S8 fired stalled branch leaves EX2", !valid_o && allowin);

        pc_i = 32'h1c010014; imm_i = 32'h8; is_branch_i = 1; pred_taken_i = 1; pred_target_i = 32'h1c01001c;
        rs1_val_i = 32'hffff_ffff; rs2_val_i = 32'h0000_0001; branch_op_i = `CPU_BR_LT;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 blt signed compare", branch_taken_o && !redirect_valid_o);

        pc_i = 32'h1c010018; imm_i = 32'h8; pred_target_i = 32'h1c010020;
        rs1_val_i = 32'h0000_0005; rs2_val_i = 32'hffff_ffff; branch_op_i = `CPU_BR_GE;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 bge signed compare", branch_taken_o && !redirect_valid_o);

        pc_i = 32'h1c01001c; imm_i = 32'h8; pred_target_i = 32'h1c010024;
        rs1_val_i = 32'h0000_0001; rs2_val_i = 32'h0000_0002; branch_op_i = `CPU_BR_LTU;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 bltu unsigned compare", branch_taken_o && !redirect_valid_o);

        pc_i = 32'h1c010020; imm_i = 32'h8; pred_target_i = 32'h1c010028;
        rs1_val_i = 32'hffff_ffff; rs2_val_i = 32'h0000_0001; branch_op_i = `CPU_BR_GEU;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 bgeu unsigned compare", branch_taken_o && !redirect_valid_o);

        pc_i = 32'h1c010020; imm_i = 32'h20; is_branch_i = 1; is_jal_i = 0; is_jalr_i = 0;
        rs1_val_i = 32'h77; rs2_val_i = 32'h77; pred_taken_i = 1; pred_target_i = 32'h1c010040;
        branch_op_i = `CPU_BR_EQ; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 predicted taken branch avoids redirect", !redirect_valid_o);
        `check("S8 predicted branch still updates BPU", bpu_update_valid_o);
`ifdef PERF_MONI
        `check("S8 predicted branch perf correct", bpu_perf_valid_o && bpu_perf_correct_o);
        `check("S8 predicted branch has no miss", !bpu_perf_direction_miss_o && !bpu_perf_target_miss_o && !bpu_perf_exu_flush_o);
`endif

        pc_i = 32'h1c010040; instr_i = 32'h54000000; imm_i = 32'h10; is_branch_i = 0; is_jal_i = 1; is_jalr_i = 0;
        pred_taken_i = 1; pred_target_i = 32'h1c010050; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 predicted jump avoids redirect", !redirect_valid_o);
        `check("S8 direct jump BPU update valid", bpu_update_valid_o && bpu_update_is_jmp_o);
        `check("S8 direct jump is not indirect JIRL", !bpu_update_is_indirect_jmp_o);
        `check("S8 BL marks call", bpu_update_is_call_o && !bpu_update_is_ret_o);
`ifdef PERF_MONI
        `check("S8 jump BPU perf correct", bpu_perf_valid_o && bpu_perf_is_jump_o && bpu_perf_correct_o);
        `check("S8 direct jump perf split", !bpu_perf_is_ret_jirl_o && !bpu_perf_is_indirect_jirl_o);
        `check32("S8 jump perf PC", bpu_perf_pc_o, 32'h1c010040);
`endif

        pc_i = 32'h1c010080; instr_i = 32'h4c000020; imm_i = 32'h0; is_jal_i = 0; is_jalr_i = 1;
        rs1_val_i = 32'h1c0100c0; pred_taken_i = 1; pred_target_i = 32'h1c0100c0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 predicted ret avoids redirect", !redirect_valid_o);
        `check("S8 ret BPU update valid", bpu_update_valid_o && !bpu_update_is_jmp_o && !bpu_update_is_indirect_jmp_o);
        `check("S8 JIRL return marks ret", bpu_update_is_ret_o && !bpu_update_is_call_o);
        `check32("S8 ret update target", bpu_update_target_o, 32'h1c0100c0);
`ifdef PERF_MONI
        `check("S8 ret JIRL perf split", bpu_perf_valid_o && bpu_perf_is_jump_o &&
                                         bpu_perf_is_ret_jirl_o && !bpu_perf_is_indirect_jirl_o);
        `check32("S8 ret JIRL perf PC", bpu_perf_pc_o, 32'h1c010080);
`endif

        pc_i = 32'h1c0100a0; instr_i = 32'h4c000180; imm_i = 32'h0; is_jal_i = 0; is_jalr_i = 1;
        rs1_val_i = 32'h1c010120; pred_taken_i = 1; pred_target_i = 32'h1c010120;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 predicted indirect JIRL avoids redirect", !redirect_valid_o);
        `check("S8 indirect JIRL updates as indirect jump", bpu_update_valid_o &&
                                                       !bpu_update_is_jmp_o &&
                                                       bpu_update_is_indirect_jmp_o);
        `check("S8 indirect JIRL is not ret", !bpu_update_is_ret_o && !bpu_update_is_call_o);
        `check32("S8 indirect JIRL update target", bpu_update_target_o, 32'h1c010120);
`ifdef PERF_MONI
        `check("S8 indirect JIRL perf split", bpu_perf_valid_o && bpu_perf_is_jump_o &&
                                              !bpu_perf_is_ret_jirl_o && bpu_perf_is_indirect_jirl_o);
        `check("S8 indirect JIRL perf correct", bpu_perf_correct_o && !bpu_perf_direction_miss_o &&
                                                 !bpu_perf_target_miss_o && !bpu_perf_exu_flush_o);
        `check32("S8 indirect JIRL perf PC", bpu_perf_pc_o, 32'h1c0100a0);
`endif

        pc_i = 32'h1c010140; instr_i = 32'h4c0001e0; imm_i = 32'h0; is_jal_i = 0; is_jalr_i = 1;
        rs1_val_i = 32'h1c010144; pred_taken_i = 0; pred_target_i = 32'h0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S8 JIRL to sequential PC does not redirect", !redirect_valid_o);
        `check("S8 JIRL to sequential PC still trains BPU", bpu_update_valid_o && bpu_update_taken_o);
        `check32("S8 JIRL to sequential PC target", bpu_update_target_o, 32'h1c010144);
`ifdef PERF_MONI
        `check("S8 JIRL to sequential PC has no flush penalty", bpu_perf_valid_o &&
                                                              bpu_perf_correct_o &&
                                                              !bpu_perf_exu_flush_o);
        `check("S8 JIRL to sequential PC keeps semantic direction miss", bpu_perf_direction_miss_o);
`endif
        finish_tb();
    end
endmodule

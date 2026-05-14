`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s5_backend_id1_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    function automatic [31:0] la_i12(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_i12 = {6'h00, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_branch(input [5:0] op31_26, input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_branch = {op31_26, imm, rj, rd};
    endfunction

    function automatic [31:0] la_shift_imm(input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] imm);
        la_shift_imm = {6'h00, 4'h1, 2'h0, op19_15, imm, rj, rd};
    endfunction

    function automatic [31:0] la_alu_3r(input [1:0] op21_20, input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] rk);
        la_alu_3r = {6'h00, 4'h0, op21_20, op19_15, rk, rj, rd};
    endfunction
    function automatic [31:0] la_pcaddi(input [4:0] rd, input [19:0] imm);
        la_pcaddi = {6'h06, 1'b0, imm, rd};
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

    function automatic [31:0] la_ertn();
        la_ertn = {6'h01, 4'h9, 2'h0, 5'h10, 5'h0e, 5'd0, 5'd0};
    endfunction

    function automatic [31:0] la_tlb_barrier(input [4:0] rk);
        la_tlb_barrier = {6'h01, 4'h9, 2'h0, 5'h10, rk, 5'd0, 5'd0};
    endfunction

    function automatic [31:0] la_invtlb(input [4:0] op, input [4:0] rj, input [4:0] rk);
        la_invtlb = {6'h01, 4'h9, 2'h0, 5'h13, rk, rj, op};
    endfunction

    function automatic [31:0] la_cacop(input [4:0] op, input [4:0] rj, input [11:0] imm);
        la_cacop = {6'h01, 4'h8, imm, rj, op};
    endfunction
    function automatic [31:0] la_ll_w(input [4:0] rd, input [4:0] rj, input [13:0] imm14);
        la_ll_w = {6'h08, 1'b0, 1'b0, imm14, rj, rd};
    endfunction
    function automatic [31:0] la_sc_w(input [4:0] rd, input [4:0] rj, input [13:0] imm14);
        la_sc_w = {6'h08, 1'b0, 1'b1, imm14, rj, rd};
    endfunction

    logic flush, dual_issue_enable, in_valid, allowin, s6_allowin, out_valid;
    logic slot1_enable_alu, slot1_enable_branch, slot1_enable_mul, slot1_enable_load, slot1_enable_store;
    logic pred_taken_i, fault_i, is_branch_i, is_jal_i, is_jalr_i, is_load_i, is_store_i, is_lui_i, is_auipc_i, unknown_i;
    logic s6_valid_i, s6_wb_en_i, s7_valid_i, s7_is_load_i, s7_wb_en_i;
    logic s6_slot1_issue_valid_i, s6_slot1_wb_en_i;
    logic s7_slot1_issue_valid_i, s7_slot1_wb_en_i;
    logic s8_valid_i, s8_is_load_i, s8_wb_en_i, s8_result_wait_i, s8_slot1_result_wait_i;
    logic s8_slot1_issue_valid_i, s8_slot1_wb_en_i, s8_slot1_is_load_i;
    logic [3:0] s8_slot1_issue_class_i;
    logic s9_valid_i, s9_is_load_i, s9_wb_en_i;
    logic s9_slot1_issue_valid_i, s9_slot1_wb_en_i, s9_slot1_is_load_i;
    logic [3:0] s9_slot1_issue_class_i;
    logic s10_valid_i, s10_wb_en_i, s10_load_wait_i;
    logic s10_slot1_issue_valid_i, s10_slot1_wb_en_i;
    logic [5:0] fault_ecode_i, fault_ecode_o;
    logic [31:0] pc_i, instr_i, pred_target_i, fault_badv_i, imm_i;
    logic [31:0] slot1_pc_i, instr1_i, slot1_imm_i;
    logic [31:0] rf1_i, rf2_i, slot1_rf1_i, slot1_rf2_i;
    logic [31:0] s8_result_i, s9_result_i, s10_result_i;
    logic [31:0] s8_slot1_result_i, s9_slot1_result_i, s10_slot1_result_i;
    logic [1:0] epoch_i, epoch_o;
    logic [6:0] opcode_i, funct7_i;
    logic [6:0] slot1_opcode_i, slot1_funct7_i;
    logic [2:0] funct3_i;
    logic [2:0] slot1_funct3_i;
    logic [4:0] op_19_15_i, rs1_i, rs2_i, rd_i, s6_rd_i, s7_rd_i, s8_rd_i, s9_rd_i, s10_rd_i;
    logic [4:0] s6_slot1_rd_i, s7_slot1_rd_i, s8_slot1_rd_i, s9_slot1_rd_i, s10_slot1_rd_i;
    logic [4:0] slot1_op_19_15_i, slot1_rs1_i, slot1_rs2_i, slot1_rd_i;
    logic [31:0] pc_o, instr_o, pred_target_o, fault_badv_o, imm_o;
    logic [31:0] slot1_pc_o, instr1_o, slot1_imm_o;
    logic [4:0] rs1_o, rs2_o, rd_o, slot1_rs1_o, slot1_rs2_o, slot1_rd_o;
    logic [6:0] slot1_opcode_o, slot1_funct7_o;
    logic [2:0] slot1_funct3_o;
    logic [4:0] slot1_op_19_15_o;
    logic pred_taken_o, fault_o, wb_en_o, uses_rs1_o, uses_rs2_o, is_branch_o, is_jal_o, is_jalr_o, is_load_o, is_store_o, mem_sign_ext_o, unknown_o;
    logic slot1_valid_i, slot1_is_branch_i, slot1_is_jal_i, slot1_is_jalr_i, slot1_is_load_i, slot1_is_store_i, slot1_is_lui_i, slot1_is_auipc_i, slot1_unknown_i;
    logic slot1_valid_o, slot1_is_branch_o, slot1_is_jal_o, slot1_is_jalr_o, slot1_is_load_o, slot1_is_store_o, slot1_is_lui_o, slot1_is_auipc_o, slot1_unknown_o;
    logic slot1_wb_en_o, slot1_uses_rs1_o, slot1_uses_rs2_o, slot1_issue_valid_o;
    logic [3:0] slot1_issue_class_o;
    logic branch_redirect_valid_o, branch_redirected_o, valid_o, wb_en_raw_o;
    logic [31:0] rs1_val_o, rs2_val_o, slot1_rs1_val_o, slot1_rs2_val_o, branch_redirect_pc_o;
    logic [4:0] rd_raw_o;
    logic [1:0] mem_size_o, src_a_sel_o, src_b_sel_o;
    logic [1:0] slot1_src_a_sel_o, slot1_src_b_sel_o;
    logic [3:0] alu_op_o;
    logic [3:0] slot1_alu_op_o;
    logic [2:0] branch_op_o;

    task automatic drive_instr(input [31:0] inst);
        begin
            instr_i = inst;
            opcode_i = {1'b0, inst[31:26]};
            funct7_i = {3'b0, inst[25:22]};
            funct3_i = {1'b0, inst[21:20]};
            op_19_15_i = inst[19:15];
            rs2_i = inst[14:10];
            rs1_i = inst[9:5];
            rd_i = inst[4:0];
        end
    endtask

    task automatic drive_slot1_instr(input [31:0] inst);
        begin
            instr1_i = inst;
            slot1_opcode_i = {1'b0, inst[31:26]};
            slot1_funct3_i = {1'b0, inst[21:20]};
            slot1_funct7_i = {3'b0, inst[25:22]};
            slot1_op_19_15_i = inst[19:15];
            slot1_rs2_i = inst[14:10];
            slot1_rs1_i = inst[9:5];
            slot1_rd_i = inst[4:0];
        end
    endtask

    s5_backend_id1 #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .s4_to_s5_valid(in_valid),
        .dual_issue_enable_i(dual_issue_enable),
        .slot1_enable_alu_i(slot1_enable_alu),
        .slot1_enable_branch_i(slot1_enable_branch),
        .slot1_enable_mul_i(slot1_enable_mul),
        .slot1_enable_load_i(slot1_enable_load),
        .slot1_enable_store_i(slot1_enable_store),
        .s5_allowin(allowin), .s6_allowin(s6_allowin), .s5_to_s6_valid(out_valid),
        .s4_pc_i(pc_i), .s4_instr_i(instr_i), .s4_epoch_i(epoch_i), .s4_pred_taken_i(pred_taken_i),
        .s4_pred_target_i(pred_target_i), .s4_fault_i(fault_i),
        .s4_fault_ecode_i(fault_ecode_i), .s4_fault_badv_i(fault_badv_i), .s4_opcode_i(opcode_i),
        .s4_funct3_i(funct3_i), .s4_funct7_i(funct7_i), .s4_op_19_15_i(op_19_15_i),
        .s4_rs1_i(rs1_i), .s4_rs2_i(rs2_i), .s4_rd_i(rd_i), .s4_imm_i(imm_i),
        .s4_is_branch_i(is_branch_i), .s4_is_jal_i(is_jal_i), .s4_is_jalr_i(is_jalr_i),
        .s4_is_load_i(is_load_i), .s4_is_store_i(is_store_i), .s4_is_lui_i(is_lui_i),
        .s4_is_auipc_i(is_auipc_i), .s4_unknown_inst_i(unknown_i),
        .s4_slot1_pc_i(slot1_pc_i), .s4_instr1_i(instr1_i), .s4_slot1_valid_i(slot1_valid_i),
        .s4_slot1_opcode_i(slot1_opcode_i), .s4_slot1_funct3_i(slot1_funct3_i),
        .s4_slot1_funct7_i(slot1_funct7_i), .s4_slot1_op_19_15_i(slot1_op_19_15_i),
        .s4_slot1_rs1_i(slot1_rs1_i), .s4_slot1_rs2_i(slot1_rs2_i), .s4_slot1_rd_i(slot1_rd_i),
        .s4_slot1_imm_i(slot1_imm_i), .s4_slot1_is_branch_i(slot1_is_branch_i),
        .s4_slot1_is_jal_i(slot1_is_jal_i), .s4_slot1_is_jalr_i(slot1_is_jalr_i),
        .s4_slot1_is_load_i(slot1_is_load_i), .s4_slot1_is_store_i(slot1_is_store_i),
        .s4_slot1_is_lui_i(slot1_is_lui_i), .s4_slot1_is_auipc_i(slot1_is_auipc_i),
        .s4_slot1_unknown_inst_i(slot1_unknown_i), .s7_valid_i(s7_valid_i),
        .s7_is_load_i(s7_is_load_i), .s7_rd_i(s7_rd_i), .s8_valid_i(s8_valid_i),
        .s8_is_load_i(s8_is_load_i), .s8_rd_i(s8_rd_i), .s9_valid_i(s9_valid_i),
        .s9_is_load_i(s9_is_load_i), .s9_rd_i(s9_rd_i),
        .s6_valid_i(s6_valid_i), .s6_wb_en_i(s6_wb_en_i), .s6_rd_i(s6_rd_i),
        .s6_slot1_issue_valid_i(s6_slot1_issue_valid_i),
        .s6_slot1_wb_en_i(s6_slot1_wb_en_i),
        .s6_slot1_rd_i(s6_slot1_rd_i),
        .s7_wb_en_i(s7_wb_en_i),
        .s7_slot1_issue_valid_i(s7_slot1_issue_valid_i),
        .s7_slot1_wb_en_i(s7_slot1_wb_en_i),
        .s7_slot1_rd_i(s7_slot1_rd_i),
        .s8_wb_en_i(s8_wb_en_i), .s8_result_wait_i(s8_result_wait_i),
        .s8_slot1_result_wait_i(s8_slot1_result_wait_i),
        .s8_result_i(s8_result_i),
        .s8_slot1_issue_valid_i(s8_slot1_issue_valid_i),
        .s8_slot1_wb_en_i(s8_slot1_wb_en_i),
        .s8_slot1_issue_class_i(s8_slot1_issue_class_i),
        .s8_slot1_rd_i(s8_slot1_rd_i),
        .s8_slot1_result_i(s8_slot1_result_i),
        .s9_wb_en_i(s9_wb_en_i), .s9_result_i(s9_result_i),
        .s9_slot1_issue_valid_i(s9_slot1_issue_valid_i),
        .s9_slot1_wb_en_i(s9_slot1_wb_en_i),
        .s9_slot1_issue_class_i(s9_slot1_issue_class_i),
        .s9_slot1_rd_i(s9_slot1_rd_i),
        .s9_slot1_result_i(s9_slot1_result_i),
        .s10_valid_i(s10_valid_i), .s10_wb_en_i(s10_wb_en_i),
        .s10_load_wait_i(s10_load_wait_i), .s10_rd_i(s10_rd_i),
        .s10_result_i(s10_result_i),
        .s10_slot1_issue_valid_i(s10_slot1_issue_valid_i),
        .s10_slot1_wb_en_i(s10_slot1_wb_en_i),
        .s10_slot1_rd_i(s10_slot1_rd_i),
        .s10_slot1_result_i(s10_slot1_result_i),
        .rf_rdata1_i(rf1_i), .rf_rdata2_i(rf2_i),
        .slot1_rf_rdata1_i(slot1_rf1_i), .slot1_rf_rdata2_i(slot1_rf2_i),
        .s5_pc_o(pc_o),
        .s5_instr_o(instr_o), .s5_pred_taken_o(pred_taken_o), .s5_pred_target_o(pred_target_o),
        .s5_epoch_o(epoch_o),
        .s5_fault_o(fault_o), .s5_fault_ecode_o(fault_ecode_o), .s5_fault_badv_o(fault_badv_o),
        .s5_rs1_o(rs1_o), .s5_rs2_o(rs2_o), .s5_rd_o(rd_o),
        .s5_imm_o(imm_o), .s5_wb_en_o(wb_en_o), .s5_uses_rs1_o(uses_rs1_o),
        .s5_uses_rs2_o(uses_rs2_o), .s5_is_branch_o(is_branch_o), .s5_is_jal_o(is_jal_o),
        .s5_is_jalr_o(is_jalr_o), .s5_is_load_o(is_load_o), .s5_is_store_o(is_store_o),
        .s5_rs1_val_o(rs1_val_o), .s5_rs2_val_o(rs2_val_o),
        .s5_mem_size_o(mem_size_o), .s5_mem_sign_ext_o(mem_sign_ext_o),
        .s5_src_a_sel_o(src_a_sel_o), .s5_src_b_sel_o(src_b_sel_o), .s5_alu_op_o(alu_op_o),
        .s5_branch_op_o(branch_op_o), .s5_unknown_inst_o(unknown_o),
        .s5_slot1_pc_o(slot1_pc_o), .s5_instr1_o(instr1_o), .s5_slot1_valid_o(slot1_valid_o),
        .s5_slot1_opcode_o(slot1_opcode_o), .s5_slot1_funct3_o(slot1_funct3_o),
        .s5_slot1_funct7_o(slot1_funct7_o), .s5_slot1_op_19_15_o(slot1_op_19_15_o),
        .s5_slot1_rs1_o(slot1_rs1_o), .s5_slot1_rs2_o(slot1_rs2_o), .s5_slot1_rd_o(slot1_rd_o),
        .s5_slot1_imm_o(slot1_imm_o), .s5_slot1_is_branch_o(slot1_is_branch_o),
        .s5_slot1_is_jal_o(slot1_is_jal_o), .s5_slot1_is_jalr_o(slot1_is_jalr_o),
        .s5_slot1_is_load_o(slot1_is_load_o), .s5_slot1_is_store_o(slot1_is_store_o),
        .s5_slot1_is_lui_o(slot1_is_lui_o), .s5_slot1_is_auipc_o(slot1_is_auipc_o),
        .s5_slot1_unknown_inst_o(slot1_unknown_o), .s5_slot1_wb_en_o(slot1_wb_en_o),
        .s5_slot1_uses_rs1_o(slot1_uses_rs1_o), .s5_slot1_uses_rs2_o(slot1_uses_rs2_o),
        .s5_slot1_src_a_sel_o(slot1_src_a_sel_o), .s5_slot1_src_b_sel_o(slot1_src_b_sel_o),
        .s5_slot1_alu_op_o(slot1_alu_op_o),
        .s5_slot1_rs1_val_o(slot1_rs1_val_o), .s5_slot1_rs2_val_o(slot1_rs2_val_o),
        .s5_slot1_issue_valid_o(slot1_issue_valid_o),
        .s5_slot1_issue_class_o(slot1_issue_class_o),
        .s5_branch_redirected_o(branch_redirected_o),
        .s5_branch_redirect_valid_o(branch_redirect_valid_o),
        .s5_branch_redirect_pc_o(branch_redirect_pc_o),
        .s5_valid_o(valid_o), .s5_wb_en_raw_o(wb_en_raw_o), .s5_rd_raw_o(rd_raw_o)
    );

    initial begin
        tb_start();
        flush = 0; dual_issue_enable = 0; in_valid = 0; s6_allowin = 1; pc_i = 32'h1c010000; instr_i = 32'h02810084;
        slot1_enable_alu = 1'b1; slot1_enable_branch = 1'b1; slot1_enable_mul = 1'b1; slot1_enable_load = 1'b1; slot1_enable_store = 1'b1;
        epoch_i = 2'd3;
        pred_taken_i = 0; pred_target_i = 0; fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0; opcode_i = {1'b0, 6'h00}; funct7_i = {3'b0, 4'ha};
        funct3_i = 3'b0; op_19_15_i = 0; rs1_i = 5'd3; rs2_i = 5'd0; rd_i = 5'd4; imm_i = 32'h40;
        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0; is_lui_i = 0; is_auipc_i = 0; unknown_i = 0;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h0; slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0;
        rf1_i = 32'h10; rf2_i = 32'h20;
        slot1_rf1_i = 32'h30; slot1_rf2_i = 32'h40;
        s6_valid_i = 0; s6_wb_en_i = 0; s6_rd_i = 0;
        s6_slot1_issue_valid_i = 0; s6_slot1_wb_en_i = 0; s6_slot1_rd_i = 0;
        s7_valid_i = 0; s7_is_load_i = 0; s7_wb_en_i = 0; s7_rd_i = 0;
        s7_slot1_issue_valid_i = 0; s7_slot1_wb_en_i = 0; s7_slot1_rd_i = 0;
        s8_valid_i = 0; s8_is_load_i = 0; s8_wb_en_i = 0; s8_result_wait_i = 0; s8_slot1_result_wait_i = 0; s8_rd_i = 0; s8_result_i = 0;
        s8_slot1_issue_valid_i = 0; s8_slot1_wb_en_i = 0; s8_slot1_is_load_i = 0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 0; s8_slot1_result_i = 0;
        s9_valid_i = 0; s9_is_load_i = 0; s9_wb_en_i = 0; s9_rd_i = 0; s9_result_i = 0;
        s9_slot1_issue_valid_i = 0; s9_slot1_wb_en_i = 0; s9_slot1_is_load_i = 0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 0; s9_slot1_result_i = 0;
        s10_valid_i = 0; s10_wb_en_i = 0; s10_load_wait_i = 0; s10_rd_i = 0; s10_result_i = 0;
        s10_slot1_issue_valid_i = 0; s10_slot1_wb_en_i = 0; s10_slot1_rd_i = 0; s10_slot1_result_i = 0;
        reset_dut();
        instr1_i = la_i12(4'ha, 5'd5, 5'd6, 12'h004);
        slot1_valid_i = 1'b1;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd6;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd5;
        slot1_imm_i = 32'h4;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 valid", out_valid);
        `check("S5 epoch pass-through", epoch_o == 2'd3);
        `check("S5 addi wb", wb_en_o);
        `check("S5 addi uses rs1", uses_rs1_o && !uses_rs2_o);
        `check32("S5 ALU ADD", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_ADD});
        `check("S5 slot1 sideband pass-through",
               slot1_valid_o && slot1_pc_o == 32'h1c010004 &&
               instr1_o == la_i12(4'ha, 5'd5, 5'd6, 12'h004));
        `check32("S5 slot1 rs1 pass-through", {27'h0, slot1_rs1_o}, 32'd6);
        `check32("S5 slot1 rd pass-through", {27'h0, slot1_rd_o}, 32'd5);
        `check32("S5 slot1 imm pass-through", slot1_imm_o, 32'h4);
        `check("S5 slot1 kind pass-through",
               !slot1_unknown_o && !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check("S5 slot1 addi payload",
               slot1_wb_en_o && slot1_uses_rs1_o && !slot1_uses_rs2_o);
        `check32("S5 slot1 addi src A rs1", {30'd0, slot1_src_a_sel_o}, {30'd0, `CPU_SRC_A_RS1});
        `check32("S5 slot1 addi src B imm", {30'd0, slot1_src_b_sel_o}, {30'd0, `CPU_SRC_B_IMM});
        `check32("S5 slot1 addi ALU add", {28'd0, slot1_alu_op_o}, {28'd0, `CPU_ALU_ADD});
        `check32("S5 slot1 rs1 value sideband uses dedicated RF", slot1_rs1_val_o, 32'h30);
        `check32("S5 slot1 addi rs2 maps to x0 semantic zero", slot1_rs2_val_o, 32'h0);
        `check("S5 pair skeleton marks independent addi pair legal",
               u_dut.slot1_simple_alu_w && !u_dut.slot0_single_issue_w &&
               u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'd0));
        `check("S5 issue select keeps single issue in phase1",
               u_dut.issue_ready_go_w && u_dut.slot0_issue_valid_w &&
               !u_dut.slot1_issue_valid_w && !u_dut.dual_issue_w &&
               (u_dut.issue_select_reason_w == 5'h04));
        `check("S5 slot1 issue sideband stays off in phase1", !slot1_issue_valid_o);
        `check32("S5 slot1 issue class stays clear in phase1",
                 {28'd0, slot1_issue_class_o}, 32'd0);
        dual_issue_enable = 1'b1; #1;
        `check("S5 dual issue enable exposes ready legal slot1",
               u_dut.issue_ready_go_w && u_dut.slot0_issue_valid_w &&
               u_dut.slot1_issue_valid_w && u_dut.dual_issue_w &&
               slot1_issue_valid_o && (u_dut.issue_select_reason_w == 5'h10));
        `check32("S5 dual-issued addi marks slot1 compute class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        slot1_enable_alu = 1'b0; #1;
        `check("S5 slot1 ALU gate blocks otherwise legal dual issue",
               u_dut.issue_ready_go_w && u_dut.slot0_issue_valid_w &&
               !u_dut.pair_legal_w && !u_dut.slot1_issue_valid_w &&
               !slot1_issue_valid_o && !slot1_wb_en_o);
        slot1_enable_alu = 1'b1; #1;
        `check("S5 slot1 ALU gate can restore legal dual issue",
               u_dut.issue_ready_go_w && u_dut.slot0_issue_valid_w &&
               u_dut.pair_legal_w && u_dut.slot1_issue_valid_w &&
               slot1_issue_valid_o);
        dual_issue_enable = 1'b0; #1;
        `check32("S5 slot1 scoreboard rs1 uses dedicated RF fallback",
                 u_dut.slot1_rs1_val_live_w, 32'h30);
        rf1_i = 32'h0000_0020;
        rf2_i = 32'h0000_0021;
        slot1_rf1_i = 32'h0000_0022;
        slot1_rf2_i = 32'h0000_0023;
        #1;
        `check32("S5 newly accepted slot0 uses live RF before cache ready", rs1_val_o, 32'h20);
        `check32("S5 newly accepted slot1 uses live RF before cache ready", slot1_rs1_val_o, 32'h22);
        s6_allowin = 1'b0;
        tick(); #1;
        rf1_i = 32'h0000_0040;
        rf2_i = 32'h0000_0041;
        slot1_rf1_i = 32'h0000_0042;
        slot1_rf2_i = 32'h0000_0043;
        #1;
        `check32("S5 stalled slot0 keeps captured RF fallback", rs1_val_o, 32'h20);
        `check32("S5 stalled slot1 keeps captured RF fallback", slot1_rs1_val_o, 32'h22);
        s6_allowin = 1'b1;
        tick(); #1;
        slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'h7f; slot1_funct3_i = 3'h7; slot1_funct7_i = 7'h7f; slot1_op_19_15_i = 5'h1f;
        slot1_rs1_i = 5'd31; slot1_rs2_i = 5'd30; slot1_rd_i = 5'd29; slot1_imm_i = 32'hffff_ffff;
        slot1_is_branch_i = 1'b1; slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b1; slot1_unknown_i = 1'b1;
        fault_i = 1'b1; fault_ecode_i = `CPU_ECODE_PPI; fault_badv_i = 32'h4000_0040;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 fault sideband pass", out_valid && fault_o);
        `check32("S5 fault ecode pass", {26'd0, fault_ecode_o}, {26'd0, `CPU_ECODE_PPI});
        `check32("S5 fault badv pass", fault_badv_o, 32'h4000_0040);
        `check("S5 slot1 invalid clears outputs",
               !slot1_valid_o && !slot1_unknown_o && !slot1_is_branch_o &&
               !slot1_is_load_o && !slot1_is_store_o);
        `check32("S5 slot1 invalid clears rs1", {27'h0, slot1_rs1_o}, 32'd0);
        `check32("S5 slot1 invalid clears rd", {27'h0, slot1_rd_o}, 32'd0);
        `check32("S5 slot1 invalid clears imm", slot1_imm_o, 32'd0);
        `check("S5 slot1 invalid clears payload flags",
               !slot1_wb_en_o && !slot1_uses_rs1_o && !slot1_uses_rs2_o);
        `check32("S5 slot1 invalid clears src A", {30'd0, slot1_src_a_sel_o}, 32'd0);
        `check32("S5 slot1 invalid clears src B", {30'd0, slot1_src_b_sel_o}, 32'd0);
        `check32("S5 slot1 invalid clears ALU op", {28'd0, slot1_alu_op_o}, 32'd0);
        `check32("S5 slot1 invalid clears rs1 value", slot1_rs1_val_o, 32'd0);
        `check32("S5 slot1 invalid clears rs2 value", slot1_rs2_val_o, 32'd0);
        fault_i = 1'b0; fault_ecode_i = 0; fault_badv_i = 0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0;
        s7_valid_i = 1'b1; s7_is_load_i = 1'b1; s7_rd_i = 5'd3; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 load-use stalls", !out_valid);
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_rd_i = 5'd0; tick(); #1;

        drive_instr(la_i12(4'h8, 5'd7, 5'd6, 12'hfff)); imm_i = 32'hffff_ffff;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slti emits", out_valid && wb_en_o);
        `check("S5 slti uses only rs1", uses_rs1_o && !uses_rs2_o);
        `check32("S5 slti ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_SLT});
        `check32("S5 slti src B imm", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_IMM});

        drive_instr(la_i12(4'h9, 5'd7, 5'd6, 12'h001)); imm_i = 32'h1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 sltui ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_SLTU});

        drive_instr(la_i12(4'hd, 5'd7, 5'd6, 12'hf80)); imm_i = 32'h0000_0f80;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 andi ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_AND});

        drive_instr(la_i12(4'he, 5'd7, 5'd6, 12'h080)); imm_i = 32'h80;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 ori ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_OR});

        drive_instr(la_alu_3r(2'h1, 5'h0c, 5'd7, 5'd6, 5'd5)); imm_i = 32'h0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 orn ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_ORN});

        drive_instr(la_alu_3r(2'h1, 5'h0d, 5'd7, 5'd6, 5'd5)); imm_i = 32'h0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 andn ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_ANDN});

        drive_instr(la_i12(4'hf, 5'd7, 5'd6, 12'h080)); imm_i = 32'h80;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 xori ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_XOR});

        drive_instr(la_shift_imm(5'h09, 5'd7, 5'd6, 5'd4)); imm_i = 32'd4;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 srli uses immediate shift amount", uses_rs1_o && !uses_rs2_o);
        `check32("S5 srli ALU op", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_SRL});
        `check32("S5 srli src B imm", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_IMM});

        drive_instr(la_pcaddi(5'd7, 20'hfffff)); imm_i = 32'hffff_fffc;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 pcaddi uses PC source", uses_rs1_o == 1'b0);
        `check32("S5 pcaddi src A PC", {30'h0, src_a_sel_o}, {30'h0, `CPU_SRC_A_PC});
        `check32("S5 pcaddi src B imm", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_IMM});

        drive_instr(la_alu_3r(2'h1, 5'h18, 5'd9, 5'd10, 5'd11)); imm_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 mul.w uses both sources", out_valid && wb_en_o && uses_rs1_o && uses_rs2_o);
        `check32("S5 mul.w src B rs2", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_RS2});

        drive_instr(la_alu_3r(2'h2, 5'h00, 5'd9, 5'd10, 5'd11)); imm_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 div.w uses both sources", out_valid && wb_en_o && uses_rs1_o && uses_rs2_o);
        `check32("S5 div.w src B rs2", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_RS2});

        is_branch_i = 1'b0; is_load_i = 1'b0; is_store_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_lui_i = 1'b0; is_auipc_i = 1'b0; unknown_i = 1'b0;
        drive_instr(la_csr(5'd12, 5'd0, 14'h000)); rs2_i = 5'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 csrrd writes rd without source regs", out_valid && wb_en_o && !uses_rs1_o && !uses_rs2_o);

        drive_instr(la_csr(5'd13, 5'd1, 14'h006)); rs2_i = 5'd13;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 csrwr uses rd source only", out_valid && wb_en_o && !uses_rs1_o && uses_rs2_o);

        drive_instr(la_csr(5'd14, 5'd15, 14'h001)); rs2_i = 5'd14;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 csrxchg uses rj mask and rd source", out_valid && wb_en_o && uses_rs1_o && uses_rs2_o);

        drive_instr({6'h00, 4'h0, 2'h0, 5'h00, 5'h1b, 5'd6, 5'd7}); imm_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 cpucfg reads rs1 and writes rd", out_valid && wb_en_o && uses_rs1_o && !uses_rs2_o);

        drive_instr({6'h0a, 4'hb, 12'hffc, 5'd6, 5'd8}); imm_i = 32'hffff_fffc;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 preld is known no-write op", out_valid && !wb_en_o && uses_rs1_o && !uses_rs2_o);
        `check32("S5 preld src B imm", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_IMM});

        is_load_i = 1'b1; is_store_i = 1'b0;
        drive_instr(la_ll_w(5'd7, 5'd6, 14'h0004)); imm_i = 32'h10;
        slot1_valid_i = 1'b1;
        drive_slot1_instr(la_i12(4'ha, 5'd12, 5'd13, 12'h004));
        slot1_imm_i = 32'h4;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 ll.w is load with writeback", out_valid && wb_en_o && is_load_o && !is_store_o);
        `check("S5 ll.w blocks independent slot1 ALU despite memory ALU whitelist",
               u_dut.slot0_single_issue_w && !u_dut.pair_legal_w &&
               (u_dut.pair_block_reason_w == 5'h04));

        is_load_i = 1'b0; is_store_i = 1'b1;
        drive_instr(la_sc_w(5'd7, 5'd6, 14'h0004)); imm_i = 32'h10;
        slot1_valid_i = 1'b1;
        drive_slot1_instr(la_i12(4'ha, 5'd12, 5'd13, 12'h004));
        slot1_imm_i = 32'h4;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 sc.w is store with writeback", out_valid && wb_en_o && !is_load_o && is_store_o);
        `check("S5 sc.w blocks independent slot1 ALU despite memory ALU whitelist",
               u_dut.slot0_single_issue_w && !u_dut.pair_legal_w &&
               (u_dut.pair_block_reason_w == 5'h04));

        is_load_i = 1'b0; is_store_i = 1'b0;
        slot1_valid_i = 1'b0;
        drive_instr({6'h01, 4'h9, 2'h0, 5'h11, 5'd0, 5'd0, 5'd0}); imm_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 idle is known and no-write", out_valid && !wb_en_o);

        drive_instr({6'h0e, 4'h1, 2'h3, 5'h04, 5'd0, 5'd0, 5'd0}); imm_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 dbar is known and no-write", out_valid && !wb_en_o);
        `check("S5 dbar is classified as single-issue slot0", u_dut.slot0_single_issue_w);

        s6_valid_i = 1'b1;
        drive_instr({6'h0e, 4'h1, 2'h3, 5'h04, 5'd0, 5'd0, 5'd0}); imm_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 dbar waits for younger pipeline to drain", !out_valid);
        `check("S5 issue select reports policy block while barrier waits",
               !u_dut.issue_ready_go_w && !u_dut.slot0_issue_valid_w &&
               (u_dut.issue_select_reason_w == 5'h01));
        s6_valid_i = 1'b0;
        #1;
        `check("S5 dbar releases once pipeline drains", out_valid && !wb_en_o);
        tick(); #1;

        drive_instr({6'h0e, 4'h1, 2'h3, 5'h05, 5'd0, 5'd0, 5'd0}); imm_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 ibar is known and no-write", out_valid && !wb_en_o);

        drive_instr(la_syscall());
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 syscall has no RF write and no source dependency", out_valid && !wb_en_o && !uses_rs1_o && !uses_rs2_o);

        drive_instr(la_break());
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 break has no RF write and no source dependency", out_valid && !wb_en_o && !uses_rs1_o && !uses_rs2_o);

        drive_instr(la_rdcntid(5'd6)); rd_i = 5'd6; rs1_i = 5'd6; rs2_i = 5'h18;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 rdcntid writes target without source dependency", out_valid && wb_en_o && !uses_rs1_o && !uses_rs2_o);
        `check32("S5 rdcntid destination from S4 rj remap", {27'h0, rd_o}, 32'd6);

        drive_instr(la_rdcntvl(5'd7)); rd_i = 5'd7; rs1_i = 5'd0; rs2_i = 5'h18;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 rdcntvl writes rd without source dependency", out_valid && wb_en_o && !uses_rs1_o && !uses_rs2_o);

        drive_instr(la_ertn());
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 ertn has no RF write and no source dependency", out_valid && !wb_en_o && !uses_rs1_o && !uses_rs2_o);

        drive_instr(la_tlb_barrier(5'h0a)); rd_i = 5'd0; rs1_i = 5'd0; rs2_i = 5'h0a;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 tlbsrch has no RF write and no source dependency", out_valid && !wb_en_o && !uses_rs1_o && !uses_rs2_o);

        drive_instr(la_tlb_barrier(5'h0d)); rd_i = 5'd0; rs1_i = 5'd0; rs2_i = 5'h0d;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 tlbfill has no RF write and no source dependency", out_valid && !wb_en_o && !uses_rs1_o && !uses_rs2_o);

        drive_instr(la_invtlb(5'd5, 5'd12, 5'd13)); rd_i = 5'd5; rs1_i = 5'd12; rs2_i = 5'd13;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 invtlb uses ASID and VPN source regs without RF write", out_valid && !wb_en_o && uses_rs1_o && uses_rs2_o);

        drive_instr(la_cacop(5'b00000, 5'd6, 12'h040)); rd_i = 5'b00000; rs1_i = 5'd6; rs2_i = 5'd0;
        imm_i = 32'h40; is_branch_i = 0; is_load_i = 0; is_store_i = 0; unknown_i = 0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 valid CACOP uses rj and writes no GPR", out_valid && !wb_en_o && uses_rs1_o && !uses_rs2_o);
        `check32("S5 CACOP address uses immediate", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_IMM});
        `check32("S5 CACOP ALU ADD", {28'h0, alu_op_o}, {28'h0, `CPU_ALU_ADD});

        drive_instr(la_cacop(5'b00010, 5'd6, 12'h040)); rd_i = 5'b00010; rs1_i = 5'd6; rs2_i = 5'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 invalid CACOP target is dependency-free nop", out_valid && !wb_en_o && !uses_rs1_o && !uses_rs2_o);

        is_branch_i = 1'b1; is_load_i = 1'b0; is_store_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        drive_instr(la_branch(6'h18, 5'd5, 5'd6, 16'h0004)); rs2_i = 5'd5; imm_i = 32'h10;
        rf1_i = 32'hffff_fffe; rf2_i = 32'h0000_0001;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 blt branch control", out_valid && is_branch_o && !wb_en_o && uses_rs1_o && uses_rs2_o);
        `check32("S5 blt branch op", {29'h0, branch_op_o}, {29'h0, `CPU_BR_LT});
        `check32("S5 branch src B four", {30'h0, src_b_sel_o}, {30'h0, `CPU_SRC_B_FOUR});
        `check("S5 taken branch predicted not taken redirects", branch_redirect_valid_o && branch_redirected_o);
        `check32("S5 taken branch redirect target", branch_redirect_pc_o, 32'h1c010010);

        rf1_i = 32'h0000_0011; rf2_i = 32'h0000_0022; pred_taken_i = 1'b1; pred_target_i = 32'h1c010010;
        drive_instr(la_branch(6'h16, 5'd5, 5'd6, 16'h0004)); rs2_i = 5'd5; imm_i = 32'h10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 not-taken branch predicted taken redirects", branch_redirect_valid_o);
        `check32("S5 not-taken redirect target is PC+4", branch_redirect_pc_o, 32'h1c010004);
        pred_taken_i = 1'b0; pred_target_i = 32'h0;

        rf1_i = 32'h0000_0009; rf2_i = 32'h0000_0009;
        s6_valid_i = 1'b1; s6_wb_en_i = 1'b1; s6_rd_i = 5'd6;
        drive_instr(la_branch(6'h16, 5'd5, 5'd6, 16'h0004)); rs2_i = 5'd5; imm_i = 32'h10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 waits for unresolved S6 producer before early redirect", !branch_redirect_valid_o && out_valid);
        s6_valid_i = 1'b0; s6_wb_en_i = 1'b0; s6_rd_i = 5'd0;

        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b1; s10_rd_i = 5'd10;
        rf1_i = 32'hc822_c7e8; rf2_i = 32'h0000_0000;
        drive_instr(la_branch(6'h17, 5'd11, 5'd10, 16'h0004)); rs2_i = 5'd11; imm_i = 32'h10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 waits for pending S10 load even when S10 valid is not commit-ready", !branch_redirect_valid_o && out_valid);
        s10_load_wait_i = 1'b0; s10_rd_i = 5'd0;

        drive_instr(la_branch(6'h19, 5'd5, 5'd6, 16'h0004)); rs2_i = 5'd5;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 bge branch op", {29'h0, branch_op_o}, {29'h0, `CPU_BR_GE});

        drive_instr(la_branch(6'h1a, 5'd5, 5'd6, 16'h0004)); rs2_i = 5'd5;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 bltu branch op", {29'h0, branch_op_o}, {29'h0, `CPU_BR_LTU});

        drive_instr(la_branch(6'h1b, 5'd5, 5'd6, 16'h0004)); rs2_i = 5'd5;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 bgeu branch op", {29'h0, branch_op_o}, {29'h0, `CPU_BR_GEU});

        is_branch_i = 1'b0; is_load_i = 1'b1; is_store_i = 1'b0; imm_i = 32'h4;
        drive_instr(la_mem(4'h0, 5'd8, 5'd9, 12'h004));
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 ld.b byte signed load", out_valid && is_load_o && wb_en_o && uses_rs1_o && !uses_rs2_o);
        `check32("S5 ld.b mem size", {30'h0, mem_size_o}, 32'h0);
        `check("S5 ld.b sign extends", mem_sign_ext_o);

        drive_instr(la_mem(4'h1, 5'd8, 5'd9, 12'h004));
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 ld.h mem size", {30'h0, mem_size_o}, 32'h1);
        `check("S5 ld.h sign extends", mem_sign_ext_o);

        drive_instr(la_mem(4'h8, 5'd8, 5'd9, 12'h004));
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 ld.bu mem size", {30'h0, mem_size_o}, 32'h0);
        `check("S5 ld.bu zero extends", !mem_sign_ext_o);

        drive_instr(la_mem(4'h9, 5'd8, 5'd9, 12'h004));
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S5 ld.hu mem size", {30'h0, mem_size_o}, 32'h1);
        `check("S5 ld.hu zero extends", !mem_sign_ext_o);

        is_load_i = 1'b0; is_store_i = 1'b0;
        drive_instr(la_i12(4'ha, 5'd7, 5'd4, 12'h001)); imm_i = 32'h1;
        slot1_valid_i = 1'b1;
        instr1_i = la_branch(6'h16, 5'd6, 5'd7, 16'h0004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd7;
        slot1_rs2_i = 5'd6;
        slot1_rd_i = 5'd6;
        slot1_imm_i = 32'h10;
        slot1_is_branch_i = 1'b1;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 pair skeleton blocks slot1 branch RAW on slot0 compute rd",
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h08));
        slot1_valid_i = 1'b0;
        slot1_is_branch_i = 1'b0;

        drive_instr(la_i12(4'ha, 5'd11, 5'd4, 12'h001)); imm_i = 32'h1;
        slot1_valid_i = 1'b1;
        instr1_i = la_i12(4'ha, 5'd12, 5'd13, 12'h004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'h4;
        s8_valid_i = 1'b1;
        s8_wb_en_i = 1'b1;
        s8_is_load_i = 1'b1;
        s8_result_wait_i = 1'b1;
        s8_rd_i = 5'd13;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot1 scoreboard blocks future dual issue without stalling slot0",
               out_valid && u_dut.issue_ready_go_w && u_dut.slot0_issue_valid_w &&
               !u_dut.slot1_issue_valid_w && u_dut.pair_legal_w &&
               !u_dut.slot1_ready_w && (u_dut.slot1_block_reason_w == 3'h5) &&
               (u_dut.issue_select_reason_w == 5'h08));
        slot1_valid_i = 1'b0;
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0;

        dual_issue_enable = 1'b1;
        drive_instr(la_i12(4'ha, 5'd14, 5'd4, 12'h001)); imm_i = 32'h1;
        slot1_valid_i = 1'b1;
        instr1_i = la_branch(6'h16, 5'd16, 5'd15, 16'h0004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd15;
        slot1_rs2_i = 5'd16;
        slot1_rd_i = 5'd16;
        slot1_imm_i = 32'h10;
        slot1_is_branch_i = 1'b1;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_rf1_i = 32'h0000_5151;
        slot1_rf2_i = 32'h0000_6161;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot1 conditional branch can dual-issue when scoreboard is ready",
               out_valid && u_dut.issue_ready_go_w && u_dut.slot0_issue_valid_w &&
               u_dut.slot1_issue_valid_w && u_dut.pair_legal_w &&
               (u_dut.pair_block_reason_w == 5'h00) &&
               (u_dut.issue_select_reason_w == 5'h10));
        `check32("S5 dual-issued slot1 branch marks ctrl class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0001});
        `check("S5 slot1 branch keeps source usage and still has no slot1 writeback",
               slot1_is_branch_o && slot1_uses_rs1_o && slot1_uses_rs2_o &&
               !slot1_wb_en_o);
        `check32("S5 slot1 conditional branch rs1 value", slot1_rs1_val_o, 32'h0000_5151);
        `check32("S5 slot1 conditional branch rs2 value", slot1_rs2_val_o, 32'h0000_6161);

        drive_instr(la_i12(4'ha, 5'd17, 5'd4, 12'h001)); imm_i = 32'h1;
        instr1_i = la_branch(6'h17, 5'd18, 5'd19, 16'h0004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd19;
        slot1_rs2_i = 5'd18;
        slot1_rd_i = 5'd18;
        slot1_imm_i = 32'h10;
        s8_valid_i = 1'b1;
        s8_wb_en_i = 1'b1;
        s8_is_load_i = 1'b1;
        s8_result_wait_i = 1'b1;
        s8_rd_i = 5'd19;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot1 branch obeys scoreboard stall and degrades to single issue",
               out_valid && u_dut.slot0_issue_valid_w && !u_dut.slot1_issue_valid_w &&
               u_dut.pair_legal_w && !u_dut.slot1_ready_w &&
               (u_dut.slot1_block_reason_w == 3'h5) &&
               (u_dut.issue_select_reason_w == 5'h08));
        slot1_valid_i = 1'b0;
        slot1_is_branch_i = 1'b0;
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0;

        is_branch_i = 1'b1;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        rf1_i = 32'h0000_1234;
        rf2_i = 32'h0000_5678;
        pred_taken_i = 1'b0;
        pred_target_i = 32'd0;
        drive_instr(la_branch(6'h16, 5'd4, 5'd5, 16'h0002));
        slot1_valid_i = 1'b1;
        instr1_i = la_i12(4'ha, 5'd23, 5'd0, 12'h007);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd0;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd23;
        slot1_imm_i = 32'h7;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot0 conditional branch no longer forces single issue",
               out_valid && is_branch_o &&
               u_dut.issue_ready_go_w && !u_dut.slot0_single_issue_w &&
               u_dut.pair_legal_w && u_dut.slot1_issue_valid_w &&
               (u_dut.issue_select_reason_w == 5'h10) &&
               !branch_redirect_valid_o);
        `check("S5 slot0 branch dual issue keeps slot1 ALU payload",
               slot1_issue_valid_o && slot1_wb_en_o &&
               slot1_src_a_sel_o == 2'd0 && slot1_src_b_sel_o == 2'd1);
        slot1_valid_i = 1'b0;
        is_branch_i = 1'b0;

        is_branch_i = 1'b1;
        is_jal_i = 1'b0;
        is_jalr_i = 1'b0;
        is_load_i = 1'b0;
        is_store_i = 1'b0;
        rf1_i = 32'h0000_1234;
        rf2_i = 32'h0000_5678;
        pred_taken_i = 1'b0;
        pred_target_i = 32'd0;
        drive_instr(la_branch(6'h16, 5'd4, 5'd5, 16'h0002));
        slot1_valid_i = 1'b1;
        instr1_i = la_branch(6'h17, 5'd23, 5'd24, 16'h0004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd24;
        slot1_rs2_i = 5'd23;
        slot1_rd_i = 5'd23;
        slot1_imm_i = 32'h10;
        slot1_is_branch_i = 1'b1;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot0 control-flow keeps slot1 control-flow on promote path",
               out_valid && is_branch_o && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h02) &&
               u_dut.issue_hold_promote_slot1_w);
        slot1_valid_i = 1'b0;
        slot1_is_branch_i = 1'b0;
        is_branch_i = 1'b0;
        tick(); #1;
        `check("S5 blocked dual-control pair promotes slot1 before next input",
               out_valid && is_branch_o && !slot1_valid_o);

        is_load_i = 1'b0; is_store_i = 1'b1;
        drive_instr(la_mem(4'h6, 5'd10, 5'd9, 12'h004)); rs2_i = 5'd10; rd_i = 5'd10; imm_i = 32'h4;
        rf1_i = 32'h0000_7000;
        rf2_i = 32'hfeed_cafe;
        slot1_valid_i = 1'b1;
        instr1_i = la_i12(4'ha, 5'd24, 5'd0, 12'h009);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd0;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd24;
        slot1_imm_i = 32'h9;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot0 store can dual-issue independent slot1 ALU",
               out_valid && is_store_o && !wb_en_o &&
               u_dut.slot0_single_issue_w && u_dut.pair_legal_w &&
               slot1_issue_valid_o && slot1_wb_en_o &&
               (u_dut.issue_select_reason_w == 5'h10));
        `check32("S5 slot0 store dual issue keeps store data", rs2_val_o, 32'hfeed_cafe);
        slot1_valid_i = 1'b0;

        drive_instr(la_mem(4'h6, 5'd10, 5'd9, 12'h004)); rs2_i = 5'd10; rd_i = 5'd10; imm_i = 32'h4;
        rf1_i = 32'h0000_7000;
        rf2_i = 32'h0123_4567;
        slot1_valid_i = 1'b1;
        instr1_i = la_branch(6'h16, 5'd0, 5'd0, 16'h0004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd0;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd0;
        slot1_imm_i = 32'h10;
        slot1_is_branch_i = 1'b1;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot0 store keeps slot1 control-flow single-issued",
               out_valid && is_store_o && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h04));
        slot1_valid_i = 1'b0;
        slot1_is_branch_i = 1'b0;
        tick(); #1;
        `check("S5 blocked store/control-flow pair promotes slot1 before next input",
               out_valid && is_branch_o && !slot1_valid_o);

        drive_instr(la_mem(4'h4, 5'd10, 5'd9, 12'h004)); rs2_i = 5'd10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 st.b byte store", out_valid && is_store_o && !wb_en_o && uses_rs1_o && uses_rs2_o);
        `check32("S5 st.b mem size", {30'h0, mem_size_o}, 32'h0);

        drive_instr(la_mem(4'h5, 5'd10, 5'd9, 12'h004)); rs2_i = 5'd10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 st.h half store", out_valid && is_store_o && !wb_en_o && uses_rs1_o && uses_rs2_o);
        `check32("S5 st.h mem size", {30'h0, mem_size_o}, 32'h1);

        is_load_i = 1'b0; is_store_i = 1'b0;
        drive_instr(la_i12(4'ha, 5'd11, 5'd4, 12'h001)); imm_i = 32'h1;
        slot1_valid_i = 1'b1;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h008);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd12;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'h8;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b1;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_rf1_i = 32'h0000_8800;
        slot1_rf2_i = 32'h1357_9bdf;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 safe slot1 store can dual-issue into shared LSU path",
               out_valid && u_dut.slot0_issue_valid_w && slot1_issue_valid_o &&
               u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h00) &&
               !u_dut.issue_hold_promote_slot1_w);
        `check32("S5 dual-issued slot1 store marks store class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0010});
        `check("S5 slot1 store prepare carries address and data dependencies",
               slot1_is_store_o && slot1_uses_rs1_o && slot1_uses_rs2_o && !slot1_wb_en_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S5 slot1 store prepare rs1 base", slot1_rs1_val_o, 32'h0000_8800);
        `check32("S5 slot1 store prepare rs2 data", slot1_rs2_val_o, 32'h1357_9bdf);
        slot1_valid_i = 1'b0;
        slot1_is_store_i = 1'b0;

        is_load_i = 1'b0; is_store_i = 1'b0;
        drive_instr(la_i12(4'ha, 5'd11, 5'd4, 12'h001)); imm_i = 32'h1;
        slot1_valid_i = 1'b1;
        instr1_i = la_mem(4'h6, 5'd11, 5'd13, 12'h00c);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd11;
        slot1_rd_i = 5'd11;
        slot1_imm_i = 32'hc;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b1;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_rf1_i = 32'h0000_a000;
        slot1_rf2_i = 32'haaaa_5555;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 blocks slot0->slot1 RAW when slot1 is store data",
               out_valid && u_dut.slot0_issue_valid_w && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h08) &&
               u_dut.issue_hold_promote_slot1_w);
        `check("S5 slot1 RAW store still keeps rs2 dependency metadata",
               slot1_is_store_o && slot1_uses_rs1_o && slot1_uses_rs2_o &&
               !slot1_wb_en_o && slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S5 slot1 RAW store keeps original rs2 RF value at ID1",
                 slot1_rs2_val_o, 32'haaaa_5555);
        slot1_valid_i = 1'b0;
        slot1_is_store_i = 1'b0;
        reset_dut();

        is_load_i = 1'b0; is_store_i = 1'b0;
        drive_instr(la_i12(4'ha, 5'd11, 5'd4, 12'h001)); imm_i = 32'h1;
        slot1_valid_i = 1'b1;
        instr1_i = la_mem(4'h2, 5'd12, 5'd13, 12'h008);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd12;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'h8;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b1;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_rf1_i = 32'h0000_9000;
        slot1_rf2_i = 32'h2468_ace0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 safe slot1 load can dual-issue into shared LSU path",
               out_valid && u_dut.slot0_issue_valid_w && slot1_issue_valid_o &&
               u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h00) &&
               !u_dut.issue_hold_promote_slot1_w);
        `check32("S5 dual-issued slot1 load marks load class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0100});
        `check("S5 slot1 load prepare carries base dependency and writeback intent",
               slot1_is_load_o && slot1_uses_rs1_o && !slot1_uses_rs2_o && slot1_wb_en_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S5 slot1 load prepare rs1 base", slot1_rs1_val_o, 32'h0000_9000);

        instr1_i = la_mem(4'h8, 5'd12, 5'd13, 12'h00a);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_imm_i = 32'ha;
        slot1_rf1_i = 32'h0000_9010;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 safe slot1 ld.bu can dual-issue into shared LSU path",
               out_valid && u_dut.slot0_issue_valid_w && slot1_issue_valid_o &&
               u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h00) &&
               !u_dut.issue_hold_promote_slot1_w);
        `check("S5 slot1 ld.bu keeps load dependency and writeback intent",
               slot1_is_load_o && slot1_uses_rs1_o && !slot1_uses_rs2_o && slot1_wb_en_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S5 slot1 ld.bu prepare rs1 base", slot1_rs1_val_o, 32'h0000_9010);

        drive_instr(la_i12(4'ha, 5'd11, 5'd4, 12'h002)); imm_i = 32'h2;
        slot1_valid_i = 1'b1;
        instr1_i = la_mem(4'h2, 5'd12, 5'd11, 12'h004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd11;
        slot1_rs2_i = 5'd12;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'h4;
        slot1_is_load_i = 1'b1;
        slot1_is_store_i = 1'b0;
        slot1_rf1_i = 32'h0000_a000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 blocks slot0->slot1 RAW when slot1 is load base",
               out_valid && u_dut.slot0_issue_valid_w && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h08) &&
               u_dut.issue_hold_promote_slot1_w);
        `check("S5 slot1 RAW load keeps base dependency and writeback intent",
               slot1_is_load_o && slot1_uses_rs1_o && !slot1_uses_rs2_o && slot1_wb_en_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S5 slot1 RAW load keeps original rs1 RF value at ID1",
                 slot1_rs1_val_o, 32'h0000_a000);
        reset_dut();

        drive_instr(la_i12(4'ha, 5'd11, 5'd4, 12'h003)); imm_i = 32'h3;
        slot1_valid_i = 1'b1;
        instr1_i = la_alu_3r(2'h1, 5'h00, 5'd12, 5'd11, 5'd11);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd11;
        slot1_rs2_i = 5'd11;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'd0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_rf1_i = 32'h1111_2222;
        slot1_rf2_i = 32'h3333_4444;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 blocks slot0->slot1 RAW when slot1 is compute operands",
               out_valid && u_dut.slot0_issue_valid_w && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h08) &&
               u_dut.issue_hold_promote_slot1_w);
        `check("S5 slot1 RAW compute keeps 3R dependency metadata",
               slot1_wb_en_o && slot1_uses_rs1_o && slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_RS2);
        reset_dut();

        slot1_valid_i = 1'b0;
        slot1_is_load_i = 1'b0;

        is_load_i = 1'b0; is_store_i = 1'b0;
        drive_instr(la_i12(4'ha, 5'd11, 5'd4, 12'h001)); imm_i = 32'h1;
        slot1_valid_i = 1'b1;
        instr1_i = la_mem(4'h6, 5'd11, 5'd13, 12'h00c);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd11;
        slot1_rd_i = 5'd11;
        slot1_imm_i = 32'hc;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b1;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_rf1_i = 32'h0000_a000;
        slot1_rf2_i = 32'haaaa_5555;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 blocks slot0->slot1 RAW when slot1 is store data",
               out_valid && u_dut.slot0_issue_valid_w && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h08) &&
               u_dut.issue_hold_promote_slot1_w);
        `check("S5 slot1 RAW store still keeps rs2 dependency metadata",
               slot1_is_store_o && slot1_uses_rs1_o && slot1_uses_rs2_o &&
               !slot1_wb_en_o && slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S5 slot1 RAW store keeps original rs2 RF value at ID1",
                 slot1_rs2_val_o, 32'haaaa_5555);
        slot1_valid_i = 1'b0;
        slot1_is_store_i = 1'b0;

        reset_dut();
        flush = 0; dual_issue_enable = 1'b1; in_valid = 0; s6_allowin = 1'b1;
        pred_taken_i = 1'b0; pred_target_i = 32'd0; fault_i = 1'b0; fault_ecode_i = 6'd0; fault_badv_i = 32'd0;
        s6_valid_i = 1'b0; s6_wb_en_i = 1'b0; s6_rd_i = 5'd0;
        s6_slot1_issue_valid_i = 1'b0; s6_slot1_wb_en_i = 1'b0; s6_slot1_rd_i = 5'd0;
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_wb_en_i = 1'b0; s7_rd_i = 5'd0;
        s7_slot1_issue_valid_i = 1'b0; s7_slot1_wb_en_i = 1'b0; s7_slot1_rd_i = 5'd0;
        s8_valid_i = 1'b0; s8_is_load_i = 1'b0; s8_wb_en_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0;
        s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0; s8_slot1_is_load_i = 1'b0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0; s8_slot1_result_i = 32'd0;
        s9_valid_i = 1'b0; s9_is_load_i = 1'b0; s9_wb_en_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0; s9_slot1_is_load_i = 1'b0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0; s9_slot1_result_i = 32'd0;
        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b0; s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b0; s10_slot1_wb_en_i = 1'b0; s10_slot1_rd_i = 5'd0; s10_slot1_result_i = 32'd0;
        rf1_i = 32'h0000_1200; rf2_i = 32'h0000_3400;
        slot1_rf1_i = 32'h0000_5600; slot1_rf2_i = 32'h0000_7800;
        pc_i = 32'h1c020000; slot1_pc_i = 32'h1c020004; epoch_i = 2'd1;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0; is_lui_i = 1'b0; is_auipc_i = 1'b0; unknown_i = 1'b0;
        drive_instr(la_mem(4'h2, 5'd8, 5'd9, 12'h004));
        rs1_i = 5'd9; rd_i = 5'd8; imm_i = 32'h4;
        slot1_valid_i = 1'b1;
        instr1_i = la_i12(4'ha, 5'd12, 5'd13, 12'h005);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'h5;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot0 load can dual-issue independent slot1 ALU",
               out_valid && is_load_o && slot1_valid_o && slot1_issue_valid_o &&
               u_dut.slot0_single_issue_w && u_dut.pair_legal_w &&
               (u_dut.issue_select_reason_w == 5'h10) &&
               !u_dut.issue_hold_promote_slot1_w);
        `check32("S5 slot0 load dual issue keeps load address base", rs1_val_o, 32'h0000_1200);
        `check32("S5 slot0 load dual issue keeps slot1 rs1 value", slot1_rs1_val_o, 32'h0000_5600);
        `check32("S5 slot0 load dual issue keeps slot1 immediate", slot1_imm_o, 32'h5);

        reset_dut();
        flush = 0; dual_issue_enable = 1'b1; in_valid = 0; s6_allowin = 1'b1;
        pred_taken_i = 1'b0; pred_target_i = 32'd0; fault_i = 1'b0; fault_ecode_i = 6'd0; fault_badv_i = 32'd0;
        s6_valid_i = 1'b0; s6_wb_en_i = 1'b0; s6_rd_i = 5'd0;
        s6_slot1_issue_valid_i = 1'b0; s6_slot1_wb_en_i = 1'b0; s6_slot1_rd_i = 5'd0;
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_wb_en_i = 1'b0; s7_rd_i = 5'd0;
        s7_slot1_issue_valid_i = 1'b0; s7_slot1_wb_en_i = 1'b0; s7_slot1_rd_i = 5'd0;
        s8_valid_i = 1'b0; s8_is_load_i = 1'b0; s8_wb_en_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0;
        s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0; s8_slot1_is_load_i = 1'b0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0; s8_slot1_result_i = 32'd0;
        s9_valid_i = 1'b0; s9_is_load_i = 1'b0; s9_wb_en_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0; s9_slot1_is_load_i = 1'b0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0; s9_slot1_result_i = 32'd0;
        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b0; s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b0; s10_slot1_wb_en_i = 1'b0; s10_slot1_rd_i = 5'd0; s10_slot1_result_i = 32'd0;
        rf1_i = 32'h0000_1200; rf2_i = 32'h0000_3400;
        slot1_rf1_i = 32'hffff_fffe; slot1_rf2_i = 32'h0000_0003;
        pc_i = 32'h1c020080; slot1_pc_i = 32'h1c020084; epoch_i = 2'd1;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0; is_lui_i = 1'b0; is_auipc_i = 1'b0; unknown_i = 1'b0;
        drive_instr(la_mem(4'h2, 5'd8, 5'd9, 12'h004));
        rs1_i = 5'd9; rd_i = 5'd8; imm_i = 32'h4;
        slot1_valid_i = 1'b1;
        instr1_i = la_alu_3r(2'h1, 5'h18, 5'd12, 5'd13, 5'd14);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd14;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'd0;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot0 load can dual-issue independent slot1 mul",
               out_valid && is_load_o && slot1_valid_o && slot1_issue_valid_o &&
               u_dut.slot0_single_issue_w && u_dut.pair_legal_w &&
               !u_dut.slot1_simple_alu_w &&
               (u_dut.issue_select_reason_w == 5'h10) &&
               !u_dut.issue_hold_promote_slot1_w);
        `check("S5 slot1 mul payload uses both sources",
               slot1_wb_en_o && slot1_uses_rs1_o && slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_RS2);
        `check32("S5 slot1 mul rs1 value", slot1_rs1_val_o, 32'hffff_fffe);
        `check32("S5 slot1 mul rs2 value", slot1_rs2_val_o, 32'h0000_0003);

        reset_dut();
        flush = 0; dual_issue_enable = 1'b1; in_valid = 0; s6_allowin = 1'b1;
        pred_taken_i = 1'b0; pred_target_i = 32'd0; fault_i = 1'b0; fault_ecode_i = 6'd0; fault_badv_i = 32'd0;
        s6_valid_i = 1'b0; s6_wb_en_i = 1'b0; s6_rd_i = 5'd0;
        s6_slot1_issue_valid_i = 1'b0; s6_slot1_wb_en_i = 1'b0; s6_slot1_rd_i = 5'd0;
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_wb_en_i = 1'b0; s7_rd_i = 5'd0;
        s7_slot1_issue_valid_i = 1'b0; s7_slot1_wb_en_i = 1'b0; s7_slot1_rd_i = 5'd0;
        s8_valid_i = 1'b0; s8_is_load_i = 1'b0; s8_wb_en_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0;
        s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0; s8_slot1_is_load_i = 1'b0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0; s8_slot1_result_i = 32'd0;
        s9_valid_i = 1'b0; s9_is_load_i = 1'b0; s9_wb_en_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0; s9_slot1_is_load_i = 1'b0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0; s9_slot1_result_i = 32'd0;
        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b0; s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b0; s10_slot1_wb_en_i = 1'b0; s10_slot1_rd_i = 5'd0; s10_slot1_result_i = 32'd0;
        rf1_i = 32'h0000_2200; rf2_i = 32'h0000_0000;
        slot1_rf1_i = 32'hdead_beef; slot1_rf2_i = 32'h0000_7800;
        pc_i = 32'h1c020100; slot1_pc_i = 32'h1c020104; epoch_i = 2'd1;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0; is_lui_i = 1'b0; is_auipc_i = 1'b0; unknown_i = 1'b0;
        drive_instr(la_mem(4'h2, 5'd8, 5'd9, 12'h004));
        rs1_i = 5'd9; rd_i = 5'd8; imm_i = 32'h4;
        slot1_valid_i = 1'b1;
        instr1_i = la_i12(4'ha, 5'd12, 5'd8, 12'h005);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd8;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'h5;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 slot0 load blocks slot1 RAW consumer",
               out_valid && is_load_o && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h08) &&
               u_dut.issue_hold_promote_slot1_w);

        reset_dut();
        flush = 0; dual_issue_enable = 1'b1; in_valid = 0; s6_allowin = 1'b1;
        pred_taken_i = 1'b0; pred_target_i = 32'd0; fault_i = 1'b0; fault_ecode_i = 6'd0; fault_badv_i = 32'd0;
        s6_valid_i = 1'b0; s6_wb_en_i = 1'b0; s6_rd_i = 5'd0;
        s6_slot1_issue_valid_i = 1'b0; s6_slot1_wb_en_i = 1'b0; s6_slot1_rd_i = 5'd0;
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_wb_en_i = 1'b0; s7_rd_i = 5'd0;
        s7_slot1_issue_valid_i = 1'b0; s7_slot1_wb_en_i = 1'b0; s7_slot1_rd_i = 5'd0;
        s8_valid_i = 1'b0; s8_is_load_i = 1'b0; s8_wb_en_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0;
        s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0; s8_slot1_is_load_i = 1'b0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0; s8_slot1_result_i = 32'd0;
        s9_valid_i = 1'b0; s9_is_load_i = 1'b0; s9_wb_en_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0; s9_slot1_is_load_i = 1'b0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0; s9_slot1_result_i = 32'd0;
        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b0; s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b0; s10_slot1_wb_en_i = 1'b0; s10_slot1_rd_i = 5'd0; s10_slot1_result_i = 32'd0;
        rf1_i = 32'h0000_1200; rf2_i = 32'h0000_3400;
        slot1_rf1_i = 32'h0000_5600; slot1_rf2_i = 32'h0000_7800;
        pc_i = 32'h1c021000; slot1_pc_i = 32'h1c021004; epoch_i = 2'd1;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0; is_lui_i = 1'b0; is_auipc_i = 1'b0; unknown_i = 1'b0;
        drive_instr(la_mem(4'h2, 5'd8, 5'd9, 12'h004));
        rs1_i = 5'd9; rd_i = 5'd8; imm_i = 32'h4;
        slot1_valid_i = 1'b1;
        instr1_i = la_branch(6'h16, 5'd14, 5'd13, 16'h0004);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd14;
        slot1_rd_i = 5'd14;
        slot1_imm_i = 32'h10;
        slot1_is_branch_i = 1'b1;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); #1;
        `check("S5 slot0 load keeps slot1 control-flow on promote path",
               out_valid && is_load_o && !slot1_issue_valid_o &&
               !u_dut.pair_legal_w && (u_dut.pair_block_reason_w == 5'h04) &&
               u_dut.issue_hold_promote_slot1_w);
        pc_i = 32'h1c021008; slot1_pc_i = 32'h1c02100c;
        drive_instr(la_i12(4'ha, 5'd16, 5'd20, 12'h00a));
        rs1_i = 5'd20; rs2_i = 5'd0; rd_i = 5'd16; imm_i = 32'h0000_000a;
        rf1_i = 32'h1111_2222;
        is_load_i = 1'b0; is_store_i = 1'b0;
        slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'd0;
        slot1_funct3_i = 3'd0;
        slot1_funct7_i = 7'd0;
        slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd0;
        slot1_imm_i = 32'd0;
        slot1_is_branch_i = 1'b0;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        tick(); #1; in_valid = 1'b0;
        `check("S5 issue hold packet captures one upstream packet during hold",
               out_valid && pc_o == 32'h1c021004 && u_dut.held_packet_valid_r && !allowin);
        rf1_i = 32'h5566_7788;
        tick(); #1;
        `check("S5 issue hold packet waits one cycle for RF data alignment",
               !out_valid && u_dut.held_packet_valid_r && u_dut.held_packet_rf_ready_r);
        tick(); #1;
        `check("S5 issue hold packet drains captured packet in order",
               out_valid && pc_o == 32'h1c021008 &&
               instr_o == la_i12(4'ha, 5'd16, 5'd20, 12'h00a) &&
               !u_dut.held_packet_valid_r);
        `check32("S5 issue hold packet drain uses aligned RF value",
                 rs1_val_o, 32'h5566_7788);

        reset_dut();
        flush = 0; dual_issue_enable = 1'b1; in_valid = 0; s6_allowin = 1'b1;
        pred_taken_i = 1'b0; pred_target_i = 32'd0; fault_i = 1'b0; fault_ecode_i = 6'd0; fault_badv_i = 32'd0;
        s6_valid_i = 1'b0; s6_wb_en_i = 1'b0; s6_rd_i = 5'd0;
        s6_slot1_issue_valid_i = 1'b0; s6_slot1_wb_en_i = 1'b0; s6_slot1_rd_i = 5'd0;
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_wb_en_i = 1'b0; s7_rd_i = 5'd0;
        s7_slot1_issue_valid_i = 1'b0; s7_slot1_wb_en_i = 1'b0; s7_slot1_rd_i = 5'd0;
        s8_valid_i = 1'b0; s8_is_load_i = 1'b0; s8_wb_en_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0;
        s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0; s8_slot1_is_load_i = 1'b0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0; s8_slot1_result_i = 32'd0;
        s9_valid_i = 1'b0; s9_is_load_i = 1'b0; s9_wb_en_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0; s9_slot1_is_load_i = 1'b0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0; s9_slot1_result_i = 32'd0;
        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b0; s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b0; s10_slot1_wb_en_i = 1'b0; s10_slot1_rd_i = 5'd0; s10_slot1_result_i = 32'd0;
        rf1_i = 32'h0000_0007; rf2_i = 32'h0000_0000;
        slot1_rf1_i = 32'h0000_0007; slot1_rf2_i = 32'h0000_0004;
        pc_i = 32'h1c008024; slot1_pc_i = 32'h1c008028; epoch_i = 2'd1;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; is_lui_i = 1'b0; is_auipc_i = 1'b0; unknown_i = 1'b0;
        drive_instr(la_csr(5'd12, 5'd0, 14'h0000));
        imm_i = 32'h0;
        slot1_valid_i = 1'b1;
        instr1_i = la_branch(6'h16, 5'd12, 5'd13, 16'h0080);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13;
        slot1_rs2_i = 5'd12;
        slot1_rd_i = 5'd12;
        slot1_imm_i = 32'h200;
        slot1_is_branch_i = 1'b1;
        slot1_is_jal_i = 1'b0;
        slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0;
        slot1_is_store_i = 1'b0;
        slot1_is_lui_i = 1'b0;
        slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 promoted branch pair is split by slot0 single-issue RAW",
               out_valid && !slot1_issue_valid_o && !branch_redirect_valid_o &&
               u_dut.issue_hold_promote_slot1_w);
        s6_valid_i = 1'b1;
        s6_wb_en_i = 1'b1;
        s6_rd_i = 5'd12;
        tick(); #1;
        `check("S5 promoted slot1 branch waits for split slot0 producer in S6",
               !out_valid && u_dut.promoted_slot1_r && u_dut.issue_hold_promoted_raw_wait_w);
        s6_valid_i = 1'b0;
        s6_wb_en_i = 1'b0;
        s6_rd_i = 5'd0;
        s8_valid_i = 1'b1;
        s8_wb_en_i = 1'b1;
        s8_is_load_i = 1'b0;
        s8_result_wait_i = 1'b0;
        s8_rd_i = 5'd12;
        s8_result_i = 32'h0000_0004;
        #1;
        `check("S5 promoted slot1 branch suppresses stale early redirect",
               out_valid && is_branch_o && !slot1_valid_o &&
               !branch_redirect_valid_o && !branch_redirected_o &&
               u_dut.promoted_slot1_r);
        `check32("S5 promoted slot1 branch picks up split slot0 result",
                 rs2_val_o, 32'h0000_0004);
        tick(); #1;
        s8_valid_i = 1'b0;
        s8_wb_en_i = 1'b0;
        s8_rd_i = 5'd0;
        s8_result_i = 32'd0;

        reset_dut();
        flush = 1'b0; dual_issue_enable = 1'b1; s6_allowin = 1'b1;
        pred_taken_i = 1'b0; pred_target_i = 32'd0; fault_i = 1'b0;
        s6_valid_i = 1'b0; s6_wb_en_i = 1'b0; s6_rd_i = 5'd0;
        s6_slot1_issue_valid_i = 1'b0; s6_slot1_wb_en_i = 1'b0; s6_slot1_rd_i = 5'd0;
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_wb_en_i = 1'b0; s7_rd_i = 5'd0;
        s7_slot1_issue_valid_i = 1'b0; s7_slot1_wb_en_i = 1'b0; s7_slot1_rd_i = 5'd0;
        s8_valid_i = 1'b1; s8_is_load_i = 1'b0; s8_wb_en_i = 1'b0; s8_result_wait_i = 1'b0; s8_rd_i = 5'd0; s8_result_i = 32'd0;
        s8_slot1_issue_valid_i = 1'b1; s8_slot1_wb_en_i = 1'b1; s8_slot1_is_load_i = 1'b0;
        s8_slot1_issue_class_i = 4'b1000;
        s8_slot1_rd_i = 5'd4; s8_slot1_result_i = 32'h0000_3000;
        s9_valid_i = 1'b0; s9_is_load_i = 1'b0; s9_wb_en_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0; s9_slot1_is_load_i = 1'b0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0; s9_slot1_result_i = 32'd0;
        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b0; s10_rd_i = 5'd0; s10_result_i = 32'd0;
        s10_slot1_issue_valid_i = 1'b0; s10_slot1_wb_en_i = 1'b0; s10_slot1_rd_i = 5'd0; s10_slot1_result_i = 32'd0;
        rf1_i = 32'h0000_3000; rf2_i = 32'h0000_0000;
        pc_i = 32'h1c03398c; imm_i = 32'h0000_0ee8;
        is_branch_i = 1'b1; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; is_lui_i = 1'b0; is_auipc_i = 1'b0; unknown_i = 1'b0;
        drive_instr(la_branch(6'h17, 5'd4, 5'd12, 16'h0ee8));
        rs1_i = 5'd12; rs2_i = 5'd4; rd_i = 5'd4;
        slot1_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S5 branch consumes S8 lane1 forwarded operand without false redirect",
               out_valid && !branch_redirect_valid_o);
        `check32("S5 branch rs2 comes from S8 lane1", rs2_val_o, 32'h0000_3000);
        finish_tb();
    end
endmodule

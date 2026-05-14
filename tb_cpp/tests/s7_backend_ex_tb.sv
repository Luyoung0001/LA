`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s7_backend_ex_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, in_valid, allowin, s8_allowin, out_valid;
    logic pred_taken_i, fault_i, wb_en_i, uses_rs1_i, uses_rs2_i, unknown_inst_i;
    logic is_branch_i, is_jal_i, is_jalr_i, is_load_i, is_store_i, mem_sign_ext_i;
    logic [5:0] fault_ecode_i, fault_ecode_o;
    logic [31:0] pc_i, instr_i, pred_target_i, fault_badv_i, imm_i, rf1, rf2;
    logic [31:0] s6_rs1_val_i, s6_rs2_val_i;
    logic [31:0] slot1_pc_i, instr1_i, slot1_imm_i, slot1_rs1_val_i, slot1_rs2_val_i;
    logic [31:0] slot1_pc_o, instr1_o, slot1_imm_o, slot1_rs1_val_o, slot1_rs2_val_o;
    logic [31:0] slot1_op_a_o, slot1_op_b_o;
    logic [1:0] epoch_i, epoch_o;
    logic [4:0] rs1_i, rs2_i, rd_i;
    logic [4:0] slot1_op_19_15_i, slot1_rs1_i, slot1_rs2_i, slot1_rd_i;
    logic [4:0] slot1_op_19_15_o, slot1_rs1_o, slot1_rs2_o, slot1_rd_o;
    logic [1:0] mem_size_i, src_a_sel_i, src_b_sel_i;
    logic [1:0] slot1_src_a_sel_i, slot1_src_b_sel_i;
    logic [1:0] slot1_src_a_sel_o, slot1_src_b_sel_o;
    logic [3:0] alu_op_i;
    logic [3:0] slot1_alu_op_i, slot1_alu_op_o;
    logic [2:0] branch_op_i;
    logic [6:0] slot1_opcode_i, slot1_funct7_i, slot1_opcode_o, slot1_funct7_o;
    logic [2:0] slot1_funct3_i, slot1_funct3_o;
    logic s8_valid_i, s8_wb_en_i, s8_is_load_i, s8_result_wait_i, s8_slot1_result_wait_i;
    logic s9_valid_i, s9_wb_en_i, s9_is_load_i, s10_valid_i, s10_wb_en_i, s10_load_wait_i, s10_load_uncached_i;
    logic s8_slot1_issue_valid_i, s8_slot1_wb_en_i, s8_slot1_is_load_i;
    logic [3:0] s8_slot1_issue_class_i;
    logic s9_slot1_issue_valid_i, s9_slot1_wb_en_i, s9_slot1_is_load_i;
    logic [3:0] s9_slot1_issue_class_i;
    logic s10_slot1_issue_valid_i, s10_slot1_wb_en_i, s10_slot1_load_wait_i;
    logic [4:0] s8_rd_i, s9_rd_i, s10_rd_i;
    logic [4:0] s8_slot1_rd_i, s9_slot1_rd_i, s10_slot1_rd_i;
    logic [31:0] s8_alu_result_i, s9_result_i, s10_result_i;
    logic [31:0] s8_slot1_result_i, s9_slot1_result_i, s10_slot1_result_i;
    logic [31:0] pc_o, instr_o, pred_target_o, fault_badv_o, imm_o, op_a_o, op_b_o, rs1_val_o, rs2_val_o;
    logic pred_taken_o, fault_o, wb_en_o, is_branch_o, is_jal_o, is_jalr_o, is_load_o, is_store_o, mem_sign_ext_o, valid_o, load_raw_o, unknown_inst_o;
    logic slot1_valid_i, slot1_is_branch_i, slot1_is_jal_i, slot1_is_jalr_i, slot1_is_load_i, slot1_is_store_i, slot1_is_lui_i, slot1_is_auipc_i, slot1_unknown_i;
    logic slot1_wb_en_i, slot1_uses_rs1_i, slot1_uses_rs2_i, slot1_issue_valid_i;
    logic [3:0] slot1_issue_class_i;
    logic slot1_valid_o, slot1_is_branch_o, slot1_is_jal_o, slot1_is_jalr_o, slot1_is_load_o, slot1_is_store_o, slot1_is_lui_o, slot1_is_auipc_o, slot1_unknown_o;
    logic slot1_wb_en_o, slot1_uses_rs1_o, slot1_uses_rs2_o, slot1_issue_valid_o;
    logic [3:0] slot1_issue_class_o;
    logic slot1_emit_valid_o, slot1_fire_o;
    logic [3:0] slot1_emit_class_o;
    logic op_a_late_s10_o, op_b_late_s10_o, rs1_late_s10_o, rs2_late_s10_o;
    logic slot1_op_a_late_s10_o, slot1_op_b_late_s10_o;
    logic slot1_rs1_late_s10_o, slot1_rs2_late_s10_o;
    logic [4:0] late_s10_rd_o;
    logic [4:0] slot1_late_s10_rd_o;
    logic branch_redirect_valid_o, branch_redirected_i, branch_redirected_o;
    logic [31:0] branch_redirect_pc_o;
    logic [4:0] rd_o, rd_raw_o;
    logic [1:0] mem_size_o;
    logic [3:0] alu_op_o;
    logic [2:0] branch_op_o;

    s7_backend_ex #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .s6_to_s7_valid(in_valid),
        .s7_allowin(allowin), .s8_allowin(s8_allowin), .s7_to_s8_valid(out_valid),
        .s7_slot1_emit_valid_o(slot1_emit_valid_o),
        .s7_slot1_fire_o(slot1_fire_o),
        .s7_slot1_emit_class_o(slot1_emit_class_o),
        .s6_pc_i(pc_i), .s6_instr_i(instr_i), .s6_pred_taken_i(pred_taken_i),
        .s6_epoch_i(epoch_i),
        .s6_pred_target_i(pred_target_i), .s6_fault_i(fault_i),
        .s6_fault_ecode_i(fault_ecode_i), .s6_fault_badv_i(fault_badv_i), .s6_rs1_i(rs1_i),
        .s6_rs2_i(rs2_i), .s6_rd_i(rd_i), .s6_imm_i(imm_i), .s6_wb_en_i(wb_en_i),
        .s6_uses_rs1_i(uses_rs1_i), .s6_uses_rs2_i(uses_rs2_i), .s6_is_branch_i(is_branch_i),
        .s6_is_jal_i(is_jal_i), .s6_is_jalr_i(is_jalr_i), .s6_is_load_i(is_load_i),
        .s6_is_store_i(is_store_i), .s6_rs1_val_i(s6_rs1_val_i), .s6_rs2_val_i(s6_rs2_val_i),
        .s6_mem_size_i(mem_size_i), .s6_mem_sign_ext_i(mem_sign_ext_i),
        .s6_src_a_sel_i(src_a_sel_i), .s6_src_b_sel_i(src_b_sel_i), .s6_alu_op_i(alu_op_i),
        .s6_branch_op_i(branch_op_i), .s6_unknown_inst_i(unknown_inst_i),
        .s6_branch_redirected_i(branch_redirected_i),
        .s6_slot1_pc_i(slot1_pc_i), .s6_instr1_i(instr1_i), .s6_slot1_valid_i(slot1_valid_i),
        .s6_slot1_opcode_i(slot1_opcode_i), .s6_slot1_funct3_i(slot1_funct3_i),
        .s6_slot1_funct7_i(slot1_funct7_i), .s6_slot1_op_19_15_i(slot1_op_19_15_i),
        .s6_slot1_rs1_i(slot1_rs1_i), .s6_slot1_rs2_i(slot1_rs2_i), .s6_slot1_rd_i(slot1_rd_i),
        .s6_slot1_imm_i(slot1_imm_i), .s6_slot1_is_branch_i(slot1_is_branch_i),
        .s6_slot1_is_jal_i(slot1_is_jal_i), .s6_slot1_is_jalr_i(slot1_is_jalr_i),
        .s6_slot1_is_load_i(slot1_is_load_i), .s6_slot1_is_store_i(slot1_is_store_i),
        .s6_slot1_is_lui_i(slot1_is_lui_i), .s6_slot1_is_auipc_i(slot1_is_auipc_i),
        .s6_slot1_unknown_inst_i(slot1_unknown_i),
        .s6_slot1_wb_en_i(slot1_wb_en_i), .s6_slot1_uses_rs1_i(slot1_uses_rs1_i),
        .s6_slot1_uses_rs2_i(slot1_uses_rs2_i), .s6_slot1_src_a_sel_i(slot1_src_a_sel_i),
        .s6_slot1_src_b_sel_i(slot1_src_b_sel_i), .s6_slot1_alu_op_i(slot1_alu_op_i),
        .s6_slot1_rs1_val_i(slot1_rs1_val_i), .s6_slot1_rs2_val_i(slot1_rs2_val_i),
        .s6_slot1_issue_valid_i(slot1_issue_valid_i),
        .s6_slot1_issue_class_i(slot1_issue_class_i),
        .rf_rdata1_i(rf1), .rf_rdata2_i(rf2),
        .s8_valid_i(s8_valid_i), .s8_wb_en_i(s8_wb_en_i), .s8_is_load_i(s8_is_load_i),
        .s8_result_wait_i(s8_result_wait_i),
        .s8_slot1_result_wait_i(s8_slot1_result_wait_i),
        .s8_rd_i(s8_rd_i), .s8_alu_result_i(s8_alu_result_i), .s9_valid_i(s9_valid_i),
        .s8_slot1_issue_valid_i(s8_slot1_issue_valid_i),
        .s8_slot1_wb_en_i(s8_slot1_wb_en_i),
        .s8_slot1_issue_class_i(s8_slot1_issue_class_i),
        .s8_slot1_rd_i(s8_slot1_rd_i),
        .s8_slot1_result_i(s8_slot1_result_i),
        .s9_wb_en_i(s9_wb_en_i), .s9_is_load_i(s9_is_load_i), .s9_rd_i(s9_rd_i),
        .s9_result_i(s9_result_i), .s10_valid_i(s10_valid_i), .s10_wb_en_i(s10_wb_en_i),
        .s9_slot1_issue_valid_i(s9_slot1_issue_valid_i),
        .s9_slot1_wb_en_i(s9_slot1_wb_en_i),
        .s9_slot1_issue_class_i(s9_slot1_issue_class_i),
        .s9_slot1_rd_i(s9_slot1_rd_i),
        .s9_slot1_result_i(s9_slot1_result_i),
        .s10_rd_i(s10_rd_i), .s10_result_i(s10_result_i), .s10_load_wait_i(s10_load_wait_i),
        .s10_load_uncached_i(s10_load_uncached_i),
        .s10_slot1_issue_valid_i(s10_slot1_issue_valid_i),
        .s10_slot1_wb_en_i(s10_slot1_wb_en_i),
        .s10_slot1_load_wait_i(s10_slot1_load_wait_i),
        .s10_slot1_rd_i(s10_slot1_rd_i),
        .s10_slot1_result_i(s10_slot1_result_i),
        .s7_pc_o(pc_o), .s7_instr_o(instr_o), .s7_pred_taken_o(pred_taken_o),
        .s7_epoch_o(epoch_o),
        .s7_pred_target_o(pred_target_o), .s7_fault_o(fault_o),
        .s7_fault_ecode_o(fault_ecode_o), .s7_fault_badv_o(fault_badv_o),
        .s7_rd_o(rd_o), .s7_imm_o(imm_o), .s7_wb_en_o(wb_en_o), .s7_is_branch_o(is_branch_o),
        .s7_is_jal_o(is_jal_o), .s7_is_jalr_o(is_jalr_o), .s7_is_load_o(is_load_o),
        .s7_is_store_o(is_store_o), .s7_mem_size_o(mem_size_o), .s7_mem_sign_ext_o(mem_sign_ext_o),
        .s7_alu_op_o(alu_op_o), .s7_branch_op_o(branch_op_o), .s7_op_a_o(op_a_o),
        .s7_op_b_o(op_b_o), .s7_rs1_val_o(rs1_val_o), .s7_rs2_val_o(rs2_val_o),
        .s7_op_a_late_s10_o(op_a_late_s10_o), .s7_op_b_late_s10_o(op_b_late_s10_o),
        .s7_rs1_late_s10_o(rs1_late_s10_o), .s7_rs2_late_s10_o(rs2_late_s10_o),
        .s7_late_s10_rd_o(late_s10_rd_o),
        .s7_unknown_inst_o(unknown_inst_o),
        .s7_slot1_pc_o(slot1_pc_o), .s7_instr1_o(instr1_o), .s7_slot1_valid_o(slot1_valid_o),
        .s7_slot1_opcode_o(slot1_opcode_o), .s7_slot1_funct3_o(slot1_funct3_o),
        .s7_slot1_funct7_o(slot1_funct7_o), .s7_slot1_op_19_15_o(slot1_op_19_15_o),
        .s7_slot1_rs1_o(slot1_rs1_o), .s7_slot1_rs2_o(slot1_rs2_o), .s7_slot1_rd_o(slot1_rd_o),
        .s7_slot1_imm_o(slot1_imm_o), .s7_slot1_is_branch_o(slot1_is_branch_o),
        .s7_slot1_is_jal_o(slot1_is_jal_o), .s7_slot1_is_jalr_o(slot1_is_jalr_o),
        .s7_slot1_is_load_o(slot1_is_load_o), .s7_slot1_is_store_o(slot1_is_store_o),
        .s7_slot1_is_lui_o(slot1_is_lui_o), .s7_slot1_is_auipc_o(slot1_is_auipc_o),
        .s7_slot1_unknown_inst_o(slot1_unknown_o),
        .s7_slot1_wb_en_o(slot1_wb_en_o), .s7_slot1_uses_rs1_o(slot1_uses_rs1_o),
        .s7_slot1_uses_rs2_o(slot1_uses_rs2_o), .s7_slot1_src_a_sel_o(slot1_src_a_sel_o),
        .s7_slot1_src_b_sel_o(slot1_src_b_sel_o), .s7_slot1_alu_op_o(slot1_alu_op_o),
        .s7_slot1_rs1_val_o(slot1_rs1_val_o), .s7_slot1_rs2_val_o(slot1_rs2_val_o),
        .s7_slot1_op_a_o(slot1_op_a_o), .s7_slot1_op_b_o(slot1_op_b_o),
        .s7_slot1_op_a_late_s10_o(slot1_op_a_late_s10_o),
        .s7_slot1_op_b_late_s10_o(slot1_op_b_late_s10_o),
        .s7_slot1_rs1_late_s10_o(slot1_rs1_late_s10_o),
        .s7_slot1_rs2_late_s10_o(slot1_rs2_late_s10_o),
        .s7_slot1_late_s10_rd_o(slot1_late_s10_rd_o),
        .s7_slot1_issue_valid_o(slot1_issue_valid_o),
        .s7_slot1_issue_class_o(slot1_issue_class_o),
        .s7_branch_redirect_valid_o(branch_redirect_valid_o),
        .s7_branch_redirect_pc_o(branch_redirect_pc_o),
        .s7_branch_redirected_o(branch_redirected_o),
        .s7_valid_o(valid_o), .s7_is_load_raw_o(load_raw_o), .s7_rd_raw_o(rd_raw_o)
    );

    initial begin
        tb_start();
        flush = 0; in_valid = 0; s8_allowin = 1; pc_i = 32'h1c010000; instr_i = 32'h0;
        epoch_i = 2'd1; pred_taken_i = 1; pred_target_i = 32'h1c010080;
        fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        rs1_i = 5'd3; rs2_i = 5'd4; rd_i = 5'd5; imm_i = 32'h40; wb_en_i = 1; uses_rs1_i = 1; uses_rs2_i = 0;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h0; slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'd0; slot1_rs2_val_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_issue_class_i = 4'd0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0; mem_size_i = 2'b10; mem_sign_ext_i = 1;
        unknown_inst_i = 0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM; alu_op_i = `CPU_ALU_ADD; branch_op_i = `CPU_BR_EQ;
        rf1 = 32'h10; rf2 = 32'h20; s6_rs1_val_i = 32'h10; s6_rs2_val_i = 32'h20; branch_redirected_i = 1'b0;
        s8_valid_i = 0; s8_wb_en_i = 0; s8_is_load_i = 0; s8_result_wait_i = 0; s8_slot1_result_wait_i = 0; s8_rd_i = 0; s8_alu_result_i = 0;
        s8_slot1_issue_valid_i = 0; s8_slot1_wb_en_i = 0; s8_slot1_is_load_i = 0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 0; s8_slot1_result_i = 0;
        s9_valid_i = 0; s9_wb_en_i = 0; s9_is_load_i = 0; s9_rd_i = 0; s9_result_i = 0; s10_valid_i = 0; s10_wb_en_i = 0; s10_rd_i = 0; s10_result_i = 0; s10_load_wait_i = 0; s10_load_uncached_i = 0;
        s9_slot1_issue_valid_i = 0; s9_slot1_wb_en_i = 0; s9_slot1_is_load_i = 0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 0; s9_slot1_result_i = 0;
        s10_slot1_issue_valid_i = 0; s10_slot1_wb_en_i = 0; s10_slot1_load_wait_i = 0; s10_slot1_rd_i = 0; s10_slot1_result_i = 0;
        reset_dut();
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 valid", out_valid && valid_o);
        `check("S7 epoch pass-through", epoch_o == 2'd1);
        `check("S7 pred taken pass-through", pred_taken_o);
        `check32("S7 pred target pass-through", pred_target_o, 32'h1c010080);
        `check32("S7 op A", op_a_o, 32'h10);
        `check32("S7 op B imm", op_b_o, 32'h40);
        `check("S7 unknown sideband pass", !unknown_inst_o);
        `check("S7 non-branch does not redirect", !branch_redirect_valid_o);
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h02801085;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd4; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd5; slot1_imm_i = 32'h4;
        slot1_rs1_val_i = 32'h1234_0004; slot1_rs2_val_i = 32'h5678_0000;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 sideband pass-through",
               slot1_valid_o && slot1_pc_o == 32'h1c010004 && instr1_o == 32'h02801085);
        `check32("S7 slot1 rs1 pass", {27'h0, slot1_rs1_o}, 32'd4);
        `check32("S7 slot1 rd pass", {27'h0, slot1_rd_o}, 32'd5);
        `check32("S7 slot1 imm pass", slot1_imm_o, 32'h4);
        `check("S7 slot1 kind pass",
               !slot1_unknown_o && !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check("S7 slot1 simple ALU payload pass",
               slot1_wb_en_o && slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 && slot1_src_b_sel_o == `CPU_SRC_B_IMM &&
               slot1_alu_op_o == `CPU_ALU_ADD);
        `check32("S7 slot1 rs1 value pass", slot1_rs1_val_o, 32'h1234_0004);
        `check32("S7 slot1 rs2 value pass", slot1_rs2_val_o, 32'h5678_0000);
        `check32("S7 slot1 op A rs1 mux", slot1_op_a_o, 32'h1234_0004);
        `check32("S7 slot1 op B imm mux", slot1_op_b_o, 32'h4);
        `check("S7 slot1 issue sideband stays off in phase1", !slot1_issue_valid_o);
        `check32("S7 slot1 issue class stays clear in phase1",
                 {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S7 slot1 emit event stays off when slot1 is held but not issued",
               !slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'd0);
        slot1_issue_valid_i = 1'b1;
        slot1_issue_class_i = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 issue sideband passes when selected",
               slot1_valid_o && slot1_issue_valid_o && slot1_rd_o == 5'd5);
        `check32("S7 slot1 issue class passes when selected",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        `check("S7 slot1 emit event fires when selected and S8 accepts",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b1000);
        s8_allowin = 1'b0;
        #1;
        `check("S7 slot1 emit event remains valid but does not fire under S8 backpressure",
               slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'b1000);
        s8_allowin = 1'b1;
        slot1_issue_valid_i = 1'b0;
        slot1_issue_class_i = 4'd0;
        slot1_pc_i = 32'h1c010044;
        slot1_rs1_val_i = 32'h1111_2222; slot1_rs2_val_i = 32'hfeed_0002;
        slot1_src_a_sel_i = `CPU_SRC_A_PC; slot1_src_b_sel_i = `CPU_SRC_B_RS2;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check32("S7 slot1 op A PC mux", slot1_op_a_o, 32'h1c010044);
        `check32("S7 slot1 op B rs2 mux", slot1_op_b_o, 32'hfeed_0002);
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_issue_class_i = 4'b1000;
        slot1_opcode_i = 7'h7f; slot1_funct3_i = 3'h7; slot1_funct7_i = 7'h7f; slot1_op_19_15_i = 5'h1f;
        slot1_rs1_i = 5'd31; slot1_rs2_i = 5'd30; slot1_rd_i = 5'd29; slot1_imm_i = 32'hffff_ffff;
        slot1_is_branch_i = 1'b1; slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b1; slot1_unknown_i = 1'b1;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_PC; slot1_src_b_sel_i = `CPU_SRC_B_FOUR; slot1_alu_op_i = `CPU_ALU_XOR;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 invalid clears outputs",
               !slot1_valid_o && !slot1_unknown_o && !slot1_is_branch_o &&
               !slot1_is_load_o && !slot1_is_store_o);
        `check("S7 slot1 invalid clears issue sideband", !slot1_issue_valid_o);
        `check32("S7 slot1 invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S7 slot1 invalid clears emit event",
               !slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'd0);
        `check("S7 slot1 invalid clears simple ALU payload",
               !slot1_wb_en_o && !slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == 2'd0 && slot1_src_b_sel_o == 2'd0 && slot1_alu_op_o == 4'd0);
        `check32("S7 slot1 invalid clears rs1 value", slot1_rs1_val_o, 32'd0);
        `check32("S7 slot1 invalid clears rs2 value", slot1_rs2_val_o, 32'd0);
        `check32("S7 slot1 invalid clears op A", slot1_op_a_o, 32'd0);
        `check32("S7 slot1 invalid clears op B", slot1_op_b_o, 32'd0);
        `check32("S7 slot1 invalid clears rs1", {27'h0, slot1_rs1_o}, 32'd0);
        `check32("S7 slot1 invalid clears rd", {27'h0, slot1_rd_o}, 32'd0);
        `check32("S7 slot1 invalid clears imm", slot1_imm_o, 32'd0);
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'd0; slot1_rs2_val_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_issue_class_i = 4'd0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
        fault_i = 1'b1; fault_ecode_i = `CPU_ECODE_PIL; fault_badv_i = 32'h4000_0050;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 fault sideband pass", out_valid && fault_o);
        `check32("S7 fault ecode pass", {26'd0, fault_ecode_o}, {26'd0, `CPU_ECODE_PIL});
        `check32("S7 fault badv pass", fault_badv_o, 32'h4000_0050);
        fault_i = 1'b0; fault_ecode_i = 0; fault_badv_i = 0;
        s8_valid_i = 1'b1; s8_wb_en_i = 1'b1; s8_rd_i = 5'd3; s8_alu_result_i = 32'h1234; #1;
        `check32("S7 S8 forwarding", rs1_val_o, 32'h1234);
        s8_result_wait_i = 1'b1; #1;
        `check("S7 stalls behind pending S8 multi-cycle result", !out_valid && !allowin);
        `check32("S7 does not forward pending S8 result", rs1_val_o, 32'h10);
        s8_result_wait_i = 1'b0; #1;
        `check("S7 resumes when S8 result becomes ready", out_valid && allowin);
        `check32("S7 forwards ready S8 result", rs1_val_o, 32'h1234);

        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_rd_i = 5'd0; s8_alu_result_i = 32'h0;
        s8_result_wait_i = 1'b0; rf1 = 32'haaaa_1111; rf2 = 32'h2222_3333;
        s6_rs1_val_i = 32'haaaa_1111; s6_rs2_val_i = 32'h2222_3333;
        pc_i = 32'h1c00808c; instr_i = 32'h5c6fd36c;
        rs1_i = 5'd27; rs2_i = 5'd12; rd_i = 5'd12;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b1;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_RS2;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;

        s8_valid_i = 1'b1; s8_wb_en_i = 1'b1; s8_rd_i = 5'd12;
        s8_result_wait_i = 1'b1; s8_alu_result_i = 32'hbbbb_2222; #1;
        `check("S7 stalls while only rs2 is pending", !out_valid && !allowin);
        tick(); #1;
        rf1 = 32'hdead_bad0; #1;
        `check32("S7 keeps ready rs1 while rs2 waits", rs1_val_o, 32'haaaa_1111);
        s8_result_wait_i = 1'b0; #1;
        `check("S7 resumes after pending rs2 becomes ready", out_valid && allowin);
        `check32("S7 uses held rs1 with forwarded rs2", rs1_val_o, 32'haaaa_1111);
        `check32("S7 forwards late rs2", rs2_val_o, 32'hbbbb_2222);

        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_rd_i = 5'd0; s8_result_wait_i = 1'b0;
        rf1 = 32'h0000_0042; rf2 = 32'h0000_0042;
        s6_rs1_val_i = 32'h0000_0042; s6_rs2_val_i = 32'h0000_0042;
        pc_i = 32'h1c010100; pred_taken_i = 1'b0; pred_target_i = 32'h0; imm_i = 32'h20;
        rs1_i = 5'd3; rs2_i = 5'd4; rd_i = 5'd0; wb_en_i = 1'b0;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b1; is_branch_i = 1'b1; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_FOUR; branch_op_i = `CPU_BR_EQ;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 taken branch predicted not taken redirects", branch_redirect_valid_o);
        `check32("S7 taken branch redirect target", branch_redirect_pc_o, 32'h1c010120);
        `check("S7 early branch still emits to S8", out_valid && allowin);

        rf1 = 32'h0000_0011; rf2 = 32'h0000_0022;
        s6_rs1_val_i = 32'h0000_0011; s6_rs2_val_i = 32'h0000_0022;
        pc_i = 32'h1c010200; pred_taken_i = 1'b1; pred_target_i = 32'h1c010240; imm_i = 32'h40;
        branch_op_i = `CPU_BR_EQ;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 not-taken branch predicted taken redirects", branch_redirect_valid_o);
        `check32("S7 not-taken redirect target is PC+4", branch_redirect_pc_o, 32'h1c010204);

        s8_valid_i = 1'b1; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0; s8_alu_result_i = 32'd0;
        s8_slot1_issue_valid_i = 1'b1; s8_slot1_wb_en_i = 1'b1; s8_slot1_is_load_i = 1'b0;
        s8_slot1_issue_class_i = 4'b1000;
        s8_slot1_rd_i = 5'd4; s8_slot1_result_i = 32'h0000_3000;
        rf1 = 32'h0000_3000; rf2 = 32'h0000_0000;
        s6_rs1_val_i = 32'h0000_3000; s6_rs2_val_i = 32'h0000_0000;
        pc_i = 32'h1c03398c; pred_taken_i = 1'b0; pred_target_i = 32'h0; imm_i = 32'h0ee8;
        rs1_i = 5'd12; rs2_i = 5'd4; rd_i = 5'd0;
        branch_op_i = `CPU_BR_NE;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 branch consumes S8 lane1 forwarded operand without false redirect",
               out_valid && !branch_redirect_valid_o);
        `check32("S7 branch rs2 forwards S8 lane1 data", rs2_val_o, 32'h0000_3000);
        s8_valid_i = 1'b0; s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0;
        s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0; s8_slot1_result_i = 32'd0;

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_result_wait_i = 1'b0;
        s9_valid_i = 1'b1; s9_wb_en_i = 1'b0; s9_is_load_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b1;
        s9_slot1_wb_en_i = 1'b1;
        s9_slot1_issue_class_i = 4'b1000;
        s9_slot1_rd_i = 5'd6;
        s9_slot1_result_i = 32'h1c0f_fbd0;
        pc_i = 32'h1c002cb8; instr_i = 32'h284000cb;
        rs1_i = 5'd6; rs2_i = 5'd0; rd_i = 5'd11;
        wb_en_i = 1'b1; uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_ADD; imm_i = 32'd0;
        rf1 = 32'h0000_0009; s6_rs1_val_i = 32'h0000_0009;
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c002cbc; instr1_i = 32'h00105ccc;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd6; slot1_rs2_i = 5'd23; slot1_rd_i = 5'd12;
        slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'h0000_0009;
        slot1_rs2_val_i = 32'h0000_0012;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0; slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_RS2;
        slot1_alu_op_i = `CPU_ALU_ADD; slot1_issue_valid_i = 1'b1; slot1_issue_class_i = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 forwards S9 lane1 producer for CoreMark address add",
               out_valid && allowin && slot1_issue_valid_o);
        `check32("S7 slot1 CoreMark add uses forwarded r6",
                 slot1_op_a_o, 32'h1c0f_fbd0);
        `check32("S7 slot1 CoreMark add keeps r23 operand",
                 slot1_op_b_o, 32'h0000_0012);
        s9_valid_i = 1'b0; s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0;
        s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0; s9_slot1_result_i = 32'd0;
        slot1_valid_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_wb_en_i = 1'b0;

        reset_dut();
        s10_valid_i = 1'b1;
        s10_wb_en_i = 1'b0;
        s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b1;
        s10_slot1_wb_en_i = 1'b1;
        s10_slot1_load_wait_i = 1'b0;
        s10_slot1_rd_i = 5'd6;
        s10_slot1_result_i = 32'h1c0f_fbd0;
        tick();
        s10_valid_i = 1'b0;
        s10_slot1_issue_valid_i = 1'b0;
        s10_slot1_wb_en_i = 1'b0;
        s10_slot1_rd_i = 5'd0;
        s10_slot1_result_i = 32'd0;
        pc_i = 32'h1c002cb8; instr_i = 32'h284000cb;
        rs1_i = 5'd6; rs2_i = 5'd0; rd_i = 5'd11;
        wb_en_i = 1'b1; uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_ADD; imm_i = 32'd0;
        rf1 = 32'h0000_0009; s6_rs1_val_i = 32'h0000_0009;
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c002cbc; instr1_i = 32'h00105ccc;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd6; slot1_rs2_i = 5'd23; slot1_rd_i = 5'd12;
        slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'h0000_0009;
        slot1_rs2_val_i = 32'h0000_0012;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0; slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_RS2;
        slot1_alu_op_i = `CPU_ALU_ADD; slot1_issue_valid_i = 1'b1; slot1_issue_class_i = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 forwards recent S10 lane1 history for CoreMark address add",
               out_valid && allowin && slot1_issue_valid_o);
        `check32("S7 slot1 CoreMark add uses S10 lane1 history r6",
                 slot1_op_a_o, 32'h1c0f_fbd0);
        `check32("S7 slot1 CoreMark add keeps r23 operand from S10 lane1 history case",
                 slot1_op_b_o, 32'h0000_0012);
        slot1_valid_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_wb_en_i = 1'b0;

        reset_dut();
        s10_valid_i = 1'b1;
        s10_wb_en_i = 1'b0;
        s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b1;
        s10_slot1_wb_en_i = 1'b1;
        s10_slot1_load_wait_i = 1'b0;
        s10_slot1_rd_i = 5'd6;
        s10_slot1_result_i = 32'h1c0f_fbd0;
        tick();
        s10_slot1_issue_valid_i = 1'b0;
        s10_slot1_wb_en_i = 1'b0;
        s10_slot1_rd_i = 5'd0;
        s10_slot1_result_i = 32'd0;
        s10_wb_en_i = 1'b1;
        s10_rd_i = 5'd8;
        s10_result_i = 32'haaaa_0008;
        tick();
        s10_rd_i = 5'd9;
        s10_result_i = 32'haaaa_0009;
        tick();
        s10_rd_i = 5'd10;
        s10_result_i = 32'haaaa_000a;
        tick();
        s10_valid_i = 1'b0;
        s10_wb_en_i = 1'b0;
        s10_rd_i = 5'd0;
        s10_result_i = 32'd0;
        pc_i = 32'h1c002cb8; instr_i = 32'h284000cb;
        rs1_i = 5'd6; rs2_i = 5'd0; rd_i = 5'd11;
        wb_en_i = 1'b1; uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_ADD; imm_i = 32'd0;
        rf1 = 32'h0000_0009; s6_rs1_val_i = 32'h0000_0009;
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c002cbc; instr1_i = 32'h00105ccc;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd6; slot1_rs2_i = 5'd23; slot1_rd_i = 5'd12;
        slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'h0000_0009;
        slot1_rs2_val_i = 32'h0000_0012;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0; slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_RS2;
        slot1_alu_op_i = `CPU_ALU_ADD; slot1_issue_valid_i = 1'b1; slot1_issue_class_i = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 keeps deeper S10 lane1 history for delayed CoreMark address add",
               out_valid && allowin && slot1_issue_valid_o);
        `check32("S7 slot1 delayed CoreMark add still uses history r6",
                 slot1_op_a_o, 32'h1c0f_fbd0);
        `check32("S7 slot1 delayed CoreMark add keeps r23 operand",
                 slot1_op_b_o, 32'h0000_0012);
        slot1_valid_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_wb_en_i = 1'b0;

        reset_dut();
        s8_valid_i = 1'b1;
        s8_wb_en_i = 1'b1;
        s8_is_load_i = 1'b0;
        s8_result_wait_i = 1'b1;
        s8_slot1_result_wait_i = 1'b0;
        s8_rd_i = 5'd4;
        s8_alu_result_i = 32'h1111_0004;
        s8_slot1_issue_valid_i = 1'b1;
        s8_slot1_wb_en_i = 1'b1;
        s8_slot1_issue_class_i = 4'b1000;
        s8_slot1_rd_i = 5'd6;
        s8_slot1_result_i = 32'h1c0f_fbd0;
        pc_i = 32'h1c002cb8; instr_i = 32'h284000cb;
        rs1_i = 5'd0; rs2_i = 5'd0; rd_i = 5'd11;
        wb_en_i = 1'b1; uses_rs1_i = 1'b0; uses_rs2_i = 1'b0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b1; is_store_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_ADD; imm_i = 32'd0;
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c002cbc; instr1_i = 32'h00105ccc;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd6; slot1_rs2_i = 5'd23; slot1_rd_i = 5'd12;
        slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'h0000_0009;
        slot1_rs2_val_i = 32'h0000_0012;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0; slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_RS2;
        slot1_alu_op_i = `CPU_ALU_ADD; slot1_issue_valid_i = 1'b1; slot1_issue_class_i = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 does not stall behind unrelated S8 lane0 wait",
               out_valid && allowin && slot1_issue_valid_o);
        `check32("S7 slot1 forwards S8 lane1 while lane0 waits",
                 slot1_op_a_o, 32'h1c0f_fbd0);
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_result_wait_i = 1'b0;
        s8_slot1_result_wait_i = 1'b0; s8_rd_i = 5'd0; s8_alu_result_i = 32'd0;
        s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0;
        s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0; s8_slot1_result_i = 32'd0;
        slot1_valid_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_wb_en_i = 1'b0;

        rf1 = 32'h0000_0020; rf2 = 32'h0000_0000;
        s6_rs1_val_i = 32'h0000_0020; s6_rs2_val_i = 32'h0000_0000;
        pc_i = 32'h1c072174; instr_i = 32'h03803c13; // ori r19, r0, 0xf
        rs1_i = 5'd0; rs2_i = 5'd15; rd_i = 5'd19;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_OR; imm_i = 32'h0000_000f;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 x0 source ignores RF echo for rs1", out_valid && allowin);
        `check32("S7 x0 rs1 value is forced to zero", rs1_val_o, 32'h0000_0000);
        `check32("S7 x0 op_a is forced to zero", op_a_o, 32'h0000_0000);
        `check32("S7 ori immediate remains intact", op_b_o, 32'h0000_000f);

        rf1 = 32'h0000_0000; rf2 = 32'h0000_0000;
        s6_rs1_val_i = 32'h0000_0007; s6_rs2_val_i = 32'h0000_0000;
        pc_i = 32'h1c00f320; instr_i = 32'h5c000b20;
        pred_taken_i = 1'b0; pred_target_i = 32'h0; imm_i = 32'h0000_0008;
        rs1_i = 5'd25; rs2_i = 5'd0; rd_i = 5'd0;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b1;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_FOUR;
        alu_op_i = `CPU_ALU_ADD; branch_op_i = `CPU_BR_NE;
        is_branch_i = 1'b1; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        branch_redirected_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 redirected branch uses aligned RF operand, not stale S5 sideband",
               out_valid && !branch_redirect_valid_o);
        `check32("S7 redirected branch rs1 reloads zero from RF", rs1_val_o, 32'h0000_0000);
        branch_redirected_i = 1'b0;

        rf1 = 32'hffff_fffe; rf2 = 32'h0000_0001;
        s6_rs1_val_i = 32'hffff_fffe; s6_rs2_val_i = 32'h0000_0001;
        pc_i = 32'h1c010300; pred_taken_i = 1'b1; pred_target_i = 32'h1c010310; imm_i = 32'h10;
        branch_op_i = `CPU_BR_LT;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 correctly predicted signed branch does not redirect", !branch_redirect_valid_o);

        fault_i = 1'b1; fault_ecode_i = `CPU_ECODE_PIF; fault_badv_i = 32'h1c010400;
        rf1 = 32'h0000_0001; rf2 = 32'h0000_0001;
        s6_rs1_val_i = 32'h0000_0001; s6_rs2_val_i = 32'h0000_0001;
        pc_i = 32'h1c010400; pred_taken_i = 1'b0; pred_target_i = 32'h0; imm_i = 32'h20;
        branch_op_i = `CPU_BR_EQ;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 faulted branch does not early redirect", !branch_redirect_valid_o);
        fault_i = 1'b0; fault_ecode_i = 0; fault_badv_i = 0;

        branch_redirected_i = 1'b1;
        rf1 = 32'h0000_0009; rf2 = 32'h0000_0009;
        s6_rs1_val_i = 32'h0000_0009; s6_rs2_val_i = 32'h0000_0009;
        pc_i = 32'h1c010480; pred_taken_i = 1'b0; pred_target_i = 32'h0; imm_i = 32'h20;
        branch_op_i = `CPU_BR_EQ;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 suppresses branch already redirected by S5", !branch_redirect_valid_o && branch_redirected_o);
        branch_redirected_i = 1'b0;

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_result_wait_i = 1'b0; s9_valid_i = 1'b0; s9_wb_en_i = 1'b0;
        s9_is_load_i = 1'b0; s9_rd_i = 5'd0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b1;
        pc_i = 32'h1c010540; instr_i = {6'h00, 4'hd, 12'h020, 5'd12, 5'd12}; // andi r12,r12,0x20
        rs1_i = 5'd12; rs2_i = 5'd0; rd_i = 5'd12;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_AND; imm_i = 32'h20; rf1 = 32'h0; s6_rs1_val_i = 32'h0;
        s10_load_wait_i = 1'b1; s10_load_uncached_i = 1'b0; s10_rd_i = 5'd12; s10_wb_en_i = 1'b1; s10_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 simple ALU can issue with late S10 load operand", out_valid && allowin);
        `check("S7 marks late S10 op A", op_a_late_s10_o && rs1_late_s10_o &&
                                           !op_b_late_s10_o && !rs2_late_s10_o);
        `check32("S7 late S10 token carries source register", {27'd0, late_s10_rd_o}, 32'd12);
        s10_load_wait_i = 1'b0; s10_load_uncached_i = 1'b0; s10_rd_i = 5'd0; s10_wb_en_i = 1'b0;

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_result_wait_i = 1'b0; s9_valid_i = 1'b0; s9_wb_en_i = 1'b0;
        s9_is_load_i = 1'b0; s9_rd_i = 5'd0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b1;
        pc_i = 32'h1c00adc0; instr_i = {6'h00, 4'hd, 12'h020, 5'd12, 5'd12}; // andi r12,r12,0x20
        rs1_i = 5'd12; rs2_i = 5'd0; rd_i = 5'd12;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_AND; imm_i = 32'h20; rf1 = 32'h0; s6_rs1_val_i = 32'h0;
        s10_load_wait_i = 1'b1; s10_load_uncached_i = 1'b1; s10_rd_i = 5'd12; s10_wb_en_i = 1'b1; s10_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 uncached S10 load-use waits instead of late bypass", !out_valid && !allowin &&
                                                                  !op_a_late_s10_o && !rs1_late_s10_o);
        s10_load_wait_i = 1'b0; s10_load_uncached_i = 1'b0; s10_rd_i = 5'd0; s10_wb_en_i = 1'b0; #1;
        `check("S7 uncached wait releases after S10 load completes", out_valid && allowin);

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_slot1_issue_valid_i = 1'b0; s8_slot1_wb_en_i = 1'b0; s8_slot1_is_load_i = 1'b0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 5'd0;
        s8_result_wait_i = 1'b0; s9_valid_i = 1'b0; s9_wb_en_i = 1'b0;
        s9_is_load_i = 1'b0; s9_rd_i = 5'd0;
        s9_slot1_issue_valid_i = 1'b0; s9_slot1_wb_en_i = 1'b0; s9_slot1_is_load_i = 1'b0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 5'd0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b1;
        pc_i = 32'h1c010548; instr_i = {6'h00, 4'hd, 12'h00f, 5'd14, 5'd18}; // andi r18,r14,0xf
        rs1_i = 5'd14; rs2_i = 5'd0; rd_i = 5'd18;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_AND; imm_i = 32'hf; rf1 = 32'hdead_beef; s6_rs1_val_i = 32'hdead_beef;
        s10_valid_i = 1'b1;
        s10_wb_en_i = 1'b0; s10_load_wait_i = 1'b0; s10_load_uncached_i = 1'b0; s10_rd_i = 5'd0;
        s10_slot1_issue_valid_i = 1'b1;
        s10_slot1_wb_en_i = 1'b1;
        s10_slot1_load_wait_i = 1'b1;
        s10_slot1_rd_i = 5'd14;
        s10_slot1_result_i = 32'h0000_00a5;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 waits for pending S10 lane1 load producer",
               !out_valid && !allowin && !op_a_late_s10_o && !rs1_late_s10_o);
        s10_slot1_load_wait_i = 1'b0; #1;
        `check("S7 forwards ready S10 lane1 load producer",
               out_valid && allowin && !op_a_late_s10_o && !rs1_late_s10_o);
        `check32("S7 ready lane1 load feeds operand A", op_a_o, 32'h0000_00a5);
        s10_valid_i = 1'b0;
        s10_slot1_issue_valid_i = 1'b0;
        s10_slot1_wb_en_i = 1'b0;
        s10_slot1_load_wait_i = 1'b0;
        s10_slot1_rd_i = 5'd0;
        s10_slot1_result_i = 32'h0;

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_result_wait_i = 1'b0; s9_valid_i = 1'b0; s9_wb_en_i = 1'b0;
        s9_is_load_i = 1'b0; s9_rd_i = 5'd0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b1;
        pc_i = 32'h1c010554; instr_i = {6'h00, 4'hd, 12'h0f0, 5'd15, 5'd19}; // andi r19,r15,0xf0
        rs1_i = 5'd15; rs2_i = 5'd0; rd_i = 5'd19;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_AND; imm_i = 32'hf0; rf1 = 32'hdead_beef; s6_rs1_val_i = 32'hdead_beef;
        s10_valid_i = 1'b1;
        s10_wb_en_i = 1'b1;
        s10_load_wait_i = 1'b1;
        s10_load_uncached_i = 1'b0;
        s10_rd_i = 5'd15;
        s10_result_i = 32'h1111_0015;
        s10_slot1_issue_valid_i = 1'b1;
        s10_slot1_wb_en_i = 1'b1;
        s10_slot1_load_wait_i = 1'b0;
        s10_slot1_rd_i = 5'd15;
        s10_slot1_result_i = 32'h2222_00f5;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 younger S10 lane1 suppresses stale lane0 late token",
               out_valid && allowin && !op_a_late_s10_o && !rs1_late_s10_o);
        `check32("S7 younger S10 lane1 feeds operand A",
                 op_a_o, 32'h2222_00f5);
        `check32("S7 younger S10 lane1 case clears late rd",
                 {27'd0, late_s10_rd_o}, 32'd0);
        s10_valid_i = 1'b0;
        s10_wb_en_i = 1'b0;
        s10_load_wait_i = 1'b0;
        s10_load_uncached_i = 1'b0;
        s10_rd_i = 5'd0;
        s10_result_i = 32'h0;
        s10_slot1_issue_valid_i = 1'b0;
        s10_slot1_wb_en_i = 1'b0;
        s10_slot1_load_wait_i = 1'b0;
        s10_slot1_rd_i = 5'd0;
        s10_slot1_result_i = 32'h0;

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_result_wait_i = 1'b0; s9_valid_i = 1'b0; s9_wb_en_i = 1'b0;
        s9_is_load_i = 1'b0; s9_rd_i = 5'd0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b1;
        pc_i = 32'h1c010560; instr_i = {6'h00, 4'hd, 12'h002, 5'd23, 5'd25}; // andi r25,r23,0x2
        rs1_i = 5'd23; rs2_i = 5'd0; rd_i = 5'd25;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_AND; imm_i = 32'h2; rf1 = 32'h0000_0820; s6_rs1_val_i = 32'h0000_0820;
        s10_load_wait_i = 1'b1; s10_load_uncached_i = 1'b0; s10_rd_i = 5'd23; s10_wb_en_i = 1'b1; s10_valid_i = 1'b0;
        s8_allowin = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 holds late S10 token under S8 backpressure", out_valid && !allowin &&
                                                            op_a_late_s10_o && rs1_late_s10_o);
        rf1 = 32'hffff_ffff; tick(); #1;
        `check("S7 does not convert late S10 token into held stale rs1", out_valid && !allowin &&
                                                                  op_a_late_s10_o && rs1_late_s10_o);
        s8_allowin = 1'b1; #1;
        `check("S7 emits late S10 token after backpressure clears", out_valid && allowin &&
                                                               op_a_late_s10_o && rs1_late_s10_o);
        `check32("S7 backpressured late S10 token keeps rd", {27'd0, late_s10_rd_o}, 32'd23);
        tick(); #1;
        s10_load_wait_i = 1'b0; s10_load_uncached_i = 1'b0; s10_rd_i = 5'd0; s10_wb_en_i = 1'b0;

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_result_wait_i = 1'b0;
        s9_valid_i = 1'b1; s9_wb_en_i = 1'b1; s9_is_load_i = 1'b0;
        s9_rd_i = 5'd13; s9_result_i = 32'heeee_e000;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b1;
        pc_i = 32'h1c07cddc; instr_i = 32'h03bbb9ad; // ori r13,r13,0xeee
        rs1_i = 5'd13; rs2_i = 5'd0; rd_i = 5'd13;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_OR; imm_i = 32'h0000_0eee;
        rf1 = 32'hffff_ffff; s6_rs1_val_i = 32'hffff_ffff;
        s10_load_wait_i = 1'b1; s10_load_uncached_i = 1'b0;
        s10_rd_i = 5'd13; s10_wb_en_i = 1'b1; s10_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 newer S9 writer suppresses stale late S10 token",
               out_valid && allowin && !op_a_late_s10_o && !rs1_late_s10_o);
        `check32("S7 forwards newer S9 value over older S10 load", op_a_o, 32'heeee_e000);
        `check32("S7 newer writer case clears late rd", {27'd0, late_s10_rd_o}, 32'd0);
        s9_valid_i = 1'b0; s9_wb_en_i = 1'b0; s9_rd_i = 5'd0; s9_result_i = 32'h0;
        s10_load_wait_i = 1'b0; s10_load_uncached_i = 1'b0;
        s10_rd_i = 5'd0; s10_wb_en_i = 1'b0; s10_valid_i = 1'b0;

        reset_dut();
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; s8_rd_i = 5'd0;
        s8_result_wait_i = 1'b0;
        s9_valid_i = 1'b0; s9_wb_en_i = 1'b0; s9_is_load_i = 1'b0; s9_rd_i = 5'd0;
        s10_valid_i = 1'b1; s10_wb_en_i = 1'b1; s10_load_wait_i = 1'b0; s10_load_uncached_i = 1'b0;
        s10_rd_i = 5'd4; s10_result_i = 32'h0000_a069;
        tick();
        s10_valid_i = 1'b0; s10_wb_en_i = 1'b0; s10_rd_i = 5'd0; s10_result_i = 32'h0;
        is_branch_i = 1'b0; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b1;
        pc_i = 32'h1c004d98; instr_i = 32'h00448cce;
        rs1_i = 5'd6; rs2_i = 5'd0; rd_i = 5'd14;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM;
        alu_op_i = `CPU_ALU_SRL; imm_i = 32'd3; rf1 = 32'h0000_0052; s6_rs1_val_i = 32'h0000_0052;
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c004d9c; instr1_i = 32'h00448489;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd4; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd9; slot1_imm_i = 32'd1;
        slot1_rs1_val_i = 32'h0000_0068; slot1_rs2_val_i = 32'h0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0; slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_SRL; slot1_issue_valid_i = 1'b1; slot1_issue_class_i = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 slot1 uses recent S10 writeback history for CoreMark load consumer",
               out_valid && allowin && slot1_issue_valid_o);
        `check32("S7 slot1 CoreMark r4 operand refreshed from WB history",
                 slot1_op_a_o, 32'h0000_a069);
        `check32("S7 slot1 CoreMark rs1 value refreshed from WB history",
                 slot1_rs1_val_o, 32'h0000_a069);
        slot1_valid_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_wb_en_i = 1'b0;
        slot1_uses_rs1_i = 1'b0; slot1_rs1_i = 5'd0; slot1_rd_i = 5'd0;

        reset_dut();
        s10_load_wait_i = 1'b0; s10_load_uncached_i = 1'b0; s10_rd_i = 5'd0; s10_wb_en_i = 1'b0; s10_valid_i = 1'b0;
        s8_valid_i = 1'b1; s8_wb_en_i = 1'b1; s8_is_load_i = 1'b1; s8_rd_i = 5'd3;
        rf1 = 32'h0000_0009; rf2 = 32'h0000_0009;
        s6_rs1_val_i = 32'h0000_0009; s6_rs2_val_i = 32'h0000_0009;
        pc_i = 32'h1c010500; pred_taken_i = 1'b0; pred_target_i = 32'h0; imm_i = 32'h20;
        branch_op_i = `CPU_BR_EQ;
        is_branch_i = 1'b1; is_jal_i = 1'b0; is_jalr_i = 1'b0;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b0;
        uses_rs1_i = 1'b1; uses_rs2_i = 1'b1;
        rs1_i = 5'd3; rs2_i = 5'd4; rd_i = 5'd0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_FOUR;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S7 branch waits for load operand before redirect", !out_valid && !branch_redirect_valid_o);
        s8_valid_i = 1'b0; s8_wb_en_i = 1'b0; s8_is_load_i = 1'b0; #1;
        `check("S7 branch redirects after waited operand clears", out_valid && branch_redirect_valid_o);
        `check32("S7 waited branch redirect target", branch_redirect_pc_o, 32'h1c010520);
        finish_tb();
    end
endmodule

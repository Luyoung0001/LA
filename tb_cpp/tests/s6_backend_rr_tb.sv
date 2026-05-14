`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s6_backend_rr_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, in_valid, allowin, s7_allowin, out_valid;
    logic s7_valid_i, s7_is_load_i, s8_valid_i, s8_is_load_i, s9_valid_i, s9_is_load_i, s10_load_wait_i;
    logic s7_slot1_issue_valid_i, s7_slot1_wb_en_i, s7_slot1_is_load_i;
    logic [3:0] s7_slot1_issue_class_i;
    logic s8_slot1_issue_valid_i, s8_slot1_wb_en_i, s8_slot1_is_load_i;
    logic [3:0] s8_slot1_issue_class_i;
    logic s9_slot1_issue_valid_i, s9_slot1_wb_en_i, s9_slot1_is_load_i;
    logic [3:0] s9_slot1_issue_class_i;
    logic [4:0] s7_rd_i, s8_rd_i, s9_rd_i, s10_rd_i;
    logic [4:0] s7_slot1_rd_i, s8_slot1_rd_i, s9_slot1_rd_i;
    logic [5:0] fault_ecode_i, fault_ecode_o;
    logic [31:0] pc_i, instr_i, pred_target_i, fault_badv_i, imm_i, rs1_val_i, rs2_val_i;
    logic [31:0] slot1_pc_i, instr1_i, slot1_imm_i, slot1_rs1_val_i, slot1_rs2_val_i;
    logic [1:0] epoch_i, epoch_o;
    logic pred_taken_i, fault_i, wb_en_i, uses_rs1_i, uses_rs2_i, unknown_inst_i;
    logic slot1_valid_i, slot1_is_branch_i, slot1_is_jal_i, slot1_is_jalr_i, slot1_is_load_i, slot1_is_store_i, slot1_is_lui_i, slot1_is_auipc_i, slot1_unknown_i;
    logic slot1_wb_en_i, slot1_uses_rs1_i, slot1_uses_rs2_i;
    logic is_branch_i, is_jal_i, is_jalr_i, is_load_i, is_store_i, mem_sign_ext_i;
    logic [4:0] rs1_i, rs2_i, rd_i;
    logic [4:0] slot1_op_19_15_i, slot1_rs1_i, slot1_rs2_i, slot1_rd_i;
    logic [1:0] mem_size_i, src_a_sel_i, src_b_sel_i;
    logic [1:0] slot1_src_a_sel_i, slot1_src_b_sel_i;
    logic [3:0] alu_op_i;
    logic [3:0] slot1_alu_op_i;
    logic [2:0] branch_op_i;
    logic [31:0] pc_o, instr_o, pred_target_o, fault_badv_o, imm_o;
    logic [31:0] slot1_pc_o, instr1_o, slot1_imm_o, slot1_rs1_val_o, slot1_rs2_val_o;
    logic pred_taken_o, fault_o, wb_en_o, uses_rs1_o, uses_rs2_o, unknown_inst_o;
    logic slot1_valid_o, slot1_is_branch_o, slot1_is_jal_o, slot1_is_jalr_o, slot1_is_load_o, slot1_is_store_o, slot1_is_lui_o, slot1_is_auipc_o, slot1_unknown_o, slot1_issue_valid_i, slot1_issue_valid_o;
    logic [3:0] slot1_issue_class_i, slot1_issue_class_o;
    logic slot1_emit_valid_o, slot1_fire_o;
    logic [3:0] slot1_emit_class_o;
    logic slot1_wb_en_o, slot1_uses_rs1_o, slot1_uses_rs2_o;
    logic branch_redirected_i, branch_redirected_o, valid_o, wb_en_raw_o;
    logic [31:0] rs1_val_o, rs2_val_o;
    logic is_branch_o, is_jal_o, is_jalr_o, is_load_o, is_store_o, mem_sign_ext_o;
    logic [4:0] rs1_o, rs2_o, rd_o, rd_raw_o;
    logic [4:0] slot1_rs1_o, slot1_rs2_o, slot1_rd_o, slot1_op_19_15_o;
    logic [1:0] mem_size_o, src_a_sel_o, src_b_sel_o;
    logic [1:0] slot1_src_a_sel_o, slot1_src_b_sel_o;
    logic [3:0] alu_op_o;
    logic [3:0] slot1_alu_op_o;
    logic [2:0] branch_op_o;
    logic [6:0] slot1_opcode_i, slot1_funct7_i, slot1_opcode_o, slot1_funct7_o;
    logic [2:0] slot1_funct3_i, slot1_funct3_o;

    s6_backend_rr #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .s5_to_s6_valid(in_valid),
        .s6_allowin(allowin), .s7_allowin(s7_allowin), .s6_to_s7_valid(out_valid),
        .s6_slot1_emit_valid_o(slot1_emit_valid_o),
        .s6_slot1_fire_o(slot1_fire_o),
        .s6_slot1_emit_class_o(slot1_emit_class_o),
        .s7_valid_i(s7_valid_i), .s7_is_load_i(s7_is_load_i), .s7_rd_i(s7_rd_i),
        .s7_slot1_issue_valid_i(s7_slot1_issue_valid_i),
        .s7_slot1_wb_en_i(s7_slot1_wb_en_i),
        .s7_slot1_issue_class_i(s7_slot1_issue_class_i),
        .s7_slot1_rd_i(s7_slot1_rd_i),
        .s8_valid_i(s8_valid_i), .s8_is_load_i(s8_is_load_i), .s8_rd_i(s8_rd_i),
        .s8_slot1_issue_valid_i(s8_slot1_issue_valid_i),
        .s8_slot1_wb_en_i(s8_slot1_wb_en_i),
        .s8_slot1_issue_class_i(s8_slot1_issue_class_i),
        .s8_slot1_rd_i(s8_slot1_rd_i),
        .s9_valid_i(s9_valid_i), .s9_is_load_i(s9_is_load_i), .s9_rd_i(s9_rd_i),
        .s9_slot1_issue_valid_i(s9_slot1_issue_valid_i),
        .s9_slot1_wb_en_i(s9_slot1_wb_en_i),
        .s9_slot1_issue_class_i(s9_slot1_issue_class_i),
        .s9_slot1_rd_i(s9_slot1_rd_i),
        .s10_load_wait_i(s10_load_wait_i), .s10_rd_i(s10_rd_i), .s5_pc_i(pc_i),
        .s5_instr_i(instr_i), .s5_pred_taken_i(pred_taken_i), .s5_pred_target_i(pred_target_i),
        .s5_epoch_i(epoch_i),
        .s5_fault_i(fault_i), .s5_fault_ecode_i(fault_ecode_i), .s5_fault_badv_i(fault_badv_i),
        .s5_rs1_i(rs1_i), .s5_rs2_i(rs2_i), .s5_rd_i(rd_i),
        .s5_imm_i(imm_i), .s5_wb_en_i(wb_en_i), .s5_uses_rs1_i(uses_rs1_i),
        .s5_uses_rs2_i(uses_rs2_i), .s5_is_branch_i(is_branch_i), .s5_is_jal_i(is_jal_i),
        .s5_is_jalr_i(is_jalr_i), .s5_is_load_i(is_load_i), .s5_is_store_i(is_store_i),
        .s5_rs1_val_i(rs1_val_i), .s5_rs2_val_i(rs2_val_i),
        .s5_mem_size_i(mem_size_i), .s5_mem_sign_ext_i(mem_sign_ext_i),
        .s5_src_a_sel_i(src_a_sel_i), .s5_src_b_sel_i(src_b_sel_i), .s5_alu_op_i(alu_op_i),
        .s5_branch_op_i(branch_op_i), .s5_unknown_inst_i(unknown_inst_i),
        .s5_branch_redirected_i(branch_redirected_i),
        .s5_slot1_pc_i(slot1_pc_i), .s5_instr1_i(instr1_i), .s5_slot1_valid_i(slot1_valid_i),
        .s5_slot1_opcode_i(slot1_opcode_i), .s5_slot1_funct3_i(slot1_funct3_i),
        .s5_slot1_funct7_i(slot1_funct7_i), .s5_slot1_op_19_15_i(slot1_op_19_15_i),
        .s5_slot1_rs1_i(slot1_rs1_i), .s5_slot1_rs2_i(slot1_rs2_i), .s5_slot1_rd_i(slot1_rd_i),
        .s5_slot1_imm_i(slot1_imm_i), .s5_slot1_is_branch_i(slot1_is_branch_i),
        .s5_slot1_is_jal_i(slot1_is_jal_i), .s5_slot1_is_jalr_i(slot1_is_jalr_i),
        .s5_slot1_is_load_i(slot1_is_load_i), .s5_slot1_is_store_i(slot1_is_store_i),
        .s5_slot1_is_lui_i(slot1_is_lui_i), .s5_slot1_is_auipc_i(slot1_is_auipc_i),
        .s5_slot1_unknown_inst_i(slot1_unknown_i), .s5_slot1_wb_en_i(slot1_wb_en_i),
        .s5_slot1_uses_rs1_i(slot1_uses_rs1_i), .s5_slot1_uses_rs2_i(slot1_uses_rs2_i),
        .s5_slot1_src_a_sel_i(slot1_src_a_sel_i), .s5_slot1_src_b_sel_i(slot1_src_b_sel_i),
        .s5_slot1_alu_op_i(slot1_alu_op_i),
        .s5_slot1_rs1_val_i(slot1_rs1_val_i), .s5_slot1_rs2_val_i(slot1_rs2_val_i),
        .s5_slot1_issue_valid_i(slot1_issue_valid_i),
        .s5_slot1_issue_class_i(slot1_issue_class_i),
        .s6_pc_o(pc_o), .s6_instr_o(instr_o),
        .s6_epoch_o(epoch_o),
        .s6_pred_taken_o(pred_taken_o), .s6_pred_target_o(pred_target_o), .s6_fault_o(fault_o),
        .s6_fault_ecode_o(fault_ecode_o), .s6_fault_badv_o(fault_badv_o),
        .s6_rs1_o(rs1_o), .s6_rs2_o(rs2_o), .s6_rd_o(rd_o), .s6_imm_o(imm_o),
        .s6_wb_en_o(wb_en_o), .s6_uses_rs1_o(uses_rs1_o), .s6_uses_rs2_o(uses_rs2_o),
        .s6_is_branch_o(is_branch_o), .s6_is_jal_o(is_jal_o), .s6_is_jalr_o(is_jalr_o),
        .s6_is_load_o(is_load_o), .s6_is_store_o(is_store_o),
        .s6_rs1_val_o(rs1_val_o), .s6_rs2_val_o(rs2_val_o), .s6_mem_size_o(mem_size_o),
        .s6_mem_sign_ext_o(mem_sign_ext_o), .s6_src_a_sel_o(src_a_sel_o),
        .s6_src_b_sel_o(src_b_sel_o), .s6_alu_op_o(alu_op_o), .s6_branch_op_o(branch_op_o),
        .s6_unknown_inst_o(unknown_inst_o), .s6_branch_redirected_o(branch_redirected_o),
        .s6_slot1_pc_o(slot1_pc_o), .s6_instr1_o(instr1_o), .s6_slot1_valid_o(slot1_valid_o),
        .s6_slot1_opcode_o(slot1_opcode_o), .s6_slot1_funct3_o(slot1_funct3_o),
        .s6_slot1_funct7_o(slot1_funct7_o), .s6_slot1_op_19_15_o(slot1_op_19_15_o),
        .s6_slot1_rs1_o(slot1_rs1_o), .s6_slot1_rs2_o(slot1_rs2_o), .s6_slot1_rd_o(slot1_rd_o),
        .s6_slot1_imm_o(slot1_imm_o), .s6_slot1_is_branch_o(slot1_is_branch_o),
        .s6_slot1_is_jal_o(slot1_is_jal_o), .s6_slot1_is_jalr_o(slot1_is_jalr_o),
        .s6_slot1_is_load_o(slot1_is_load_o), .s6_slot1_is_store_o(slot1_is_store_o),
        .s6_slot1_is_lui_o(slot1_is_lui_o), .s6_slot1_is_auipc_o(slot1_is_auipc_o),
        .s6_slot1_unknown_inst_o(slot1_unknown_o), .s6_slot1_wb_en_o(slot1_wb_en_o),
        .s6_slot1_uses_rs1_o(slot1_uses_rs1_o), .s6_slot1_uses_rs2_o(slot1_uses_rs2_o),
        .s6_slot1_src_a_sel_o(slot1_src_a_sel_o), .s6_slot1_src_b_sel_o(slot1_src_b_sel_o),
        .s6_slot1_alu_op_o(slot1_alu_op_o),
        .s6_slot1_rs1_val_o(slot1_rs1_val_o), .s6_slot1_rs2_val_o(slot1_rs2_val_o),
        .s6_slot1_issue_valid_o(slot1_issue_valid_o),
        .s6_slot1_issue_class_o(slot1_issue_class_o),
        .s6_valid_o(valid_o), .s6_wb_en_raw_o(wb_en_raw_o), .s6_rd_raw_o(rd_raw_o)
    );

    initial begin
        tb_start();
        flush = 0; in_valid = 0; s7_allowin = 1; s7_valid_i = 0; s7_is_load_i = 0; s7_rd_i = 0;
        s7_slot1_issue_valid_i = 0; s7_slot1_wb_en_i = 0; s7_slot1_is_load_i = 0; s7_slot1_issue_class_i = 4'd0; s7_slot1_rd_i = 0;
        s8_valid_i = 0; s8_is_load_i = 0; s8_rd_i = 0;
        s8_slot1_issue_valid_i = 0; s8_slot1_wb_en_i = 0; s8_slot1_is_load_i = 0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 0;
        s9_valid_i = 0; s9_is_load_i = 0; s9_rd_i = 0;
        s9_slot1_issue_valid_i = 0; s9_slot1_wb_en_i = 0; s9_slot1_is_load_i = 0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 0;
        s10_load_wait_i = 0; s10_rd_i = 0;
        pc_i = 32'h1c010000; instr_i = 32'h02810084; epoch_i = 2'd2;
        pred_taken_i = 0; pred_target_i = 0; fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        rs1_i = 5'd3; rs2_i = 5'd5; rd_i = 5'd4; imm_i = 32'h40; wb_en_i = 1; uses_rs1_i = 1; uses_rs2_i = 0;
        rs1_val_i = 32'h1111_0003; rs2_val_i = 32'h2222_0005; branch_redirected_i = 1'b0;
        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0; mem_size_i = 2'b10; mem_sign_ext_i = 1;
        unknown_inst_i = 0;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h0; slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'd0; slot1_rs2_val_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
        slot1_issue_valid_i = 1'b0;
        slot1_issue_class_i = 4'd0;
        src_a_sel_i = `CPU_SRC_A_RS1; src_b_sel_i = `CPU_SRC_B_IMM; alu_op_i = `CPU_ALU_ADD; branch_op_i = `CPU_BR_EQ;
        reset_dut();
        instr1_i = 32'h02801085;
        slot1_valid_i = 1'b1;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd4;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd5;
        slot1_imm_i = 32'h4;
        slot1_rs1_val_i = 32'h3333_0004;
        slot1_rs2_val_i = 32'h4444_0000;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1;
        slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S6 valid", out_valid);
        `check("S6 epoch pass-through", epoch_o == 2'd2);
        `check32("S6 rs1 pass", {27'h0, rs1_o}, 32'd3);
        `check32("S6 imm pass", imm_o, 32'h40);
        `check32("S6 early rs1 value pass", rs1_val_o, 32'h1111_0003);
        `check("S6 slot1 sideband pass-through",
               slot1_valid_o && slot1_pc_o == 32'h1c010004 && instr1_o == 32'h02801085);
        `check32("S6 slot1 rs1 pass", {27'h0, slot1_rs1_o}, 32'd4);
        `check32("S6 slot1 rd pass", {27'h0, slot1_rd_o}, 32'd5);
        `check32("S6 slot1 imm pass", slot1_imm_o, 32'h4);
        `check("S6 slot1 kind pass",
               !slot1_unknown_o && !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check("S6 slot1 payload pass",
               slot1_wb_en_o && slot1_uses_rs1_o && !slot1_uses_rs2_o);
        `check32("S6 slot1 src A pass", {30'd0, slot1_src_a_sel_o}, {30'd0, `CPU_SRC_A_RS1});
        `check32("S6 slot1 src B pass", {30'd0, slot1_src_b_sel_o}, {30'd0, `CPU_SRC_B_IMM});
        `check32("S6 slot1 ALU op pass", {28'd0, slot1_alu_op_o}, {28'd0, `CPU_ALU_ADD});
        `check32("S6 slot1 rs1 value pass", slot1_rs1_val_o, 32'h3333_0004);
        `check32("S6 slot1 rs2 value pass", slot1_rs2_val_o, 32'h4444_0000);
        `check("S6 slot1 issue sideband stays off in phase1", !slot1_issue_valid_o);
        `check32("S6 slot1 issue class stays clear in phase1",
                 {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S6 slot1 emit event stays off when slot1 is held but not issued",
               !slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'd0);
        slot1_issue_valid_i = 1'b1;
        slot1_issue_class_i = 4'b1000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S6 slot1 issue sideband passes when selected",
               slot1_valid_o && slot1_issue_valid_o && slot1_rd_o == 5'd5);
        `check32("S6 slot1 issue class passes when selected",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        `check("S6 slot1 emit event fires when selected and S7 accepts",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b1000);
        s7_allowin = 1'b0;
        #1;
        `check("S6 slot1 emit event remains valid but does not fire under S7 backpressure",
               slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'b1000);
        s7_allowin = 1'b1;
        slot1_issue_valid_i = 1'b0;
        slot1_issue_class_i = 4'd0;
        `check("S6 raw status pass", valid_o && wb_en_raw_o && (rd_raw_o == 5'd4));
        `check("S6 unknown sideband pass", !unknown_inst_o);
        branch_redirected_i = 1'b1; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S6 branch redirected sideband pass", branch_redirected_o);
        branch_redirected_i = 1'b0;
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_issue_class_i = 4'b0100;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_PC;
        slot1_src_b_sel_i = `CPU_SRC_B_RS2;
        slot1_alu_op_i = `CPU_ALU_OR;
        slot1_opcode_i = 7'h7f; slot1_funct3_i = 3'h7; slot1_funct7_i = 7'h7f; slot1_op_19_15_i = 5'h1f;
        slot1_rs1_i = 5'd31; slot1_rs2_i = 5'd30; slot1_rd_i = 5'd29; slot1_imm_i = 32'hffff_ffff;
        slot1_is_branch_i = 1'b1; slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b1; slot1_unknown_i = 1'b1;
        fault_i = 1'b1; fault_ecode_i = `CPU_ECODE_TLBR; fault_badv_i = 32'h4000_0044;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S6 fault sideband pass", out_valid && fault_o);
        `check32("S6 fault ecode pass", {26'd0, fault_ecode_o}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S6 fault badv pass", fault_badv_o, 32'h4000_0044);
        `check("S6 slot1 invalid clears outputs",
               !slot1_valid_o && !slot1_unknown_o && !slot1_is_branch_o &&
               !slot1_is_load_o && !slot1_is_store_o);
        `check("S6 slot1 invalid clears issue sideband", !slot1_issue_valid_o);
        `check32("S6 slot1 invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S6 slot1 invalid clears emit event",
               !slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'd0);
        `check32("S6 slot1 invalid clears rs1", {27'h0, slot1_rs1_o}, 32'd0);
        `check32("S6 slot1 invalid clears rd", {27'h0, slot1_rd_o}, 32'd0);
        `check32("S6 slot1 invalid clears imm", slot1_imm_o, 32'd0);
        `check("S6 slot1 invalid clears payload flags",
               !slot1_wb_en_o && !slot1_uses_rs1_o && !slot1_uses_rs2_o);
        `check32("S6 slot1 invalid clears src A", {30'd0, slot1_src_a_sel_o}, 32'd0);
        `check32("S6 slot1 invalid clears src B", {30'd0, slot1_src_b_sel_o}, 32'd0);
        `check32("S6 slot1 invalid clears ALU op", {28'd0, slot1_alu_op_o}, 32'd0);
        `check32("S6 slot1 invalid clears rs1 value", slot1_rs1_val_o, 32'd0);
        `check32("S6 slot1 invalid clears rs2 value", slot1_rs2_val_o, 32'd0);
        fault_i = 1'b0; fault_ecode_i = 0; fault_badv_i = 0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_rs1_val_i = 32'd0; slot1_rs2_val_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0; slot1_issue_class_i = 4'd0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
        s7_valid_i = 1'b1; s7_is_load_i = 1'b1; s7_rd_i = 5'd3; #1;
        `check("S6 load-use stalls", !out_valid);
        s7_valid_i = 1'b0; s7_is_load_i = 1'b0; s7_rd_i = 5'd0;
        s8_valid_i = 1'b1;
        s8_is_load_i = 1'b0;
        s8_rd_i = 5'd0;
        s8_slot1_issue_valid_i = 1'b1;
        s8_slot1_wb_en_i = 1'b1;
        s8_slot1_is_load_i = 1'b1;
        s8_slot1_issue_class_i = 4'b0100;
        s8_slot1_rd_i = 5'd3;
        #1;
        `check("S6 load-use stalls on older S8 slot1 load producer", !out_valid);
        s8_valid_i = 1'b0;
        s8_slot1_issue_valid_i = 1'b0;
        s8_slot1_wb_en_i = 1'b0;
        s8_slot1_is_load_i = 1'b0;
        s8_slot1_issue_class_i = 4'd0;
        s8_slot1_rd_i = 5'd0;
        #1;
        `check("S6 releases after S8 slot1 load producer clears", out_valid);
        s10_load_wait_i = 1'b1; s10_rd_i = 5'd3; #1;
        `check("S6 lets S7 handle S10 load wait", out_valid);

        reset_dut();
        flush = 0; in_valid = 0; s7_allowin = 1;
        s7_valid_i = 0; s7_is_load_i = 0; s7_rd_i = 0;
        s7_slot1_issue_valid_i = 0; s7_slot1_wb_en_i = 0; s7_slot1_is_load_i = 0; s7_slot1_issue_class_i = 4'd0; s7_slot1_rd_i = 0;
        s8_valid_i = 0; s8_is_load_i = 0; s8_rd_i = 0;
        s8_slot1_issue_valid_i = 0; s8_slot1_wb_en_i = 0; s8_slot1_is_load_i = 0; s8_slot1_issue_class_i = 4'd0; s8_slot1_rd_i = 0;
        s9_valid_i = 0; s9_is_load_i = 0; s9_rd_i = 0;
        s9_slot1_issue_valid_i = 0; s9_slot1_wb_en_i = 0; s9_slot1_is_load_i = 0; s9_slot1_issue_class_i = 4'd0; s9_slot1_rd_i = 0;
        s10_load_wait_i = 0; s10_rd_i = 0;
        pc_i = 32'h1c020000; instr_i = 32'h02810084; epoch_i = 2'd1;
        fault_i = 0; wb_en_i = 1; uses_rs1_i = 1; uses_rs2_i = 0;
        rs1_i = 5'd3; rs2_i = 5'd0; rd_i = 5'd4; imm_i = 32'h8;
        rs1_val_i = 32'haaaa_0003; rs2_val_i = 32'd0;
        is_branch_i = 0; is_jal_i = 0; is_jalr_i = 0; is_load_i = 0; is_store_i = 0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_issue_class_i = 4'b1000;
        slot1_wb_en_i = 1'b1;
        slot1_uses_rs1_i = 1'b1;
        slot1_uses_rs2_i = 1'b0;
        slot1_rs1_i = 5'd6;
        slot1_rs2_i = 5'd0;
        slot1_rd_i = 5'd7;
        slot1_rs1_val_i = 32'hbbbb_0006;
        slot1_rs2_val_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S6 dual-issued packet emits when no slot1 load dependency", out_valid);
        `check32("S6 dual-issued packet keeps slot1 issue class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        `check("S6 dual-issued packet exposes slot1 emit event",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b1000);
        s8_valid_i = 1'b1;
        s8_slot1_issue_valid_i = 1'b1;
        s8_slot1_wb_en_i = 1'b1;
        s8_slot1_is_load_i = 1'b1;
        s8_slot1_issue_class_i = 4'b0100;
        s8_slot1_rd_i = 5'd6;
        #1;
        `check("S6 load-use stalls slot1 operand on older S8 slot1 load producer", !out_valid);
        s8_slot1_issue_valid_i = 1'b0;
        s8_slot1_wb_en_i = 1'b0;
        s8_slot1_is_load_i = 1'b0;
        s8_slot1_issue_class_i = 4'd0;
        s8_slot1_rd_i = 5'd0;
        s8_valid_i = 1'b0;
        #1;
        `check("S6 slot1 dependency releases after older slot1 load clears", out_valid);
        finish_tb();
    end
endmodule

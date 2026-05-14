`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s8_slot1_exec_bank_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [4:0]  slot0_rd;
    logic        slot0_wb_en;
    logic        slot0_is_load;
    logic        slot0_is_store;
    logic        slot0_is_branch;
    logic        slot0_is_jal;
    logic        slot0_is_jalr;
    logic [31:0] slot0_result;

    logic [31:0] slot1_pc;
    logic [31:0] instr1;
    logic        slot1_valid;
    logic [6:0]  slot1_opcode;
    logic [2:0]  slot1_funct3;
    logic [6:0]  slot1_funct7;
    logic [4:0]  slot1_op_19_15;
    logic [4:0]  slot1_rs1;
    logic [4:0]  slot1_rs2;
    logic [4:0]  slot1_rd;
    logic [31:0] slot1_imm;
    logic        slot1_is_branch;
    logic        slot1_is_jal;
    logic        slot1_is_jalr;
    logic        slot1_is_load;
    logic        slot1_is_store;
    logic        slot1_is_lui;
    logic        slot1_is_auipc;
    logic        slot1_unknown_inst;
    logic        slot1_wb_en;
    logic        slot1_uses_rs1;
    logic        slot1_uses_rs2;
    logic [1:0]  slot1_src_a_sel;
    logic [1:0]  slot1_src_b_sel;
    logic [3:0]  slot1_alu_op;
    logic [31:0] slot1_rs1_val;
    logic [31:0] slot1_rs2_val;
    logic [31:0] slot1_op_a;
    logic [31:0] slot1_op_b;
    logic        slot1_issue_valid;
    logic [3:0]  slot1_issue_class;

    logic        slot1_ctrl_flow;
    logic        slot1_actual_taken;
    logic [31:0] slot1_actual_target;
    logic [31:0] slot1_branch_target;
    logic [31:0] slot1_jump_target;
    logic        slot1_redirect_raw;
    logic        slot1_uncond_b;
    logic        slot1_uncond_bl;
    logic        slot1_uncond_jirl;
    logic        slot1_ret;
    logic        slot1_indirect_jirl;
    logic [31:0] s8_slot1_alu_result;
    logic [1:0]  s8_slot1_mem_size;
    logic [31:0] s8_slot1_store_data;
    logic        s8_slot1_exception;
    logic [5:0]  s8_slot1_excp_ecode;
    logic        s8_slot1_excp_badv_valid;
    logic [31:0] s8_slot1_excp_badv;
    logic        s8_slot1_issue_valid;
    logic [3:0]  s8_slot1_issue_class;
    logic        s8_slot1_is_load;
    logic        s8_slot1_is_store;

    s8_slot1_exec_bank u_dut (
        .slot0_rd_i(slot0_rd),
        .slot0_wb_en_i(slot0_wb_en),
        .slot0_is_load_i(slot0_is_load),
        .slot0_is_store_i(slot0_is_store),
        .slot0_is_branch_i(slot0_is_branch),
        .slot0_is_jal_i(slot0_is_jal),
        .slot0_is_jalr_i(slot0_is_jalr),
        .slot0_result_i(slot0_result),
        .slot1_pc_i(slot1_pc),
        .instr1_i(instr1),
        .slot1_valid_i(slot1_valid),
        .slot1_opcode_i(slot1_opcode),
        .slot1_funct3_i(slot1_funct3),
        .slot1_funct7_i(slot1_funct7),
        .slot1_op_19_15_i(slot1_op_19_15),
        .slot1_rs1_i(slot1_rs1),
        .slot1_rs2_i(slot1_rs2),
        .slot1_rd_i(slot1_rd),
        .slot1_imm_i(slot1_imm),
        .slot1_is_branch_i(slot1_is_branch),
        .slot1_is_jal_i(slot1_is_jal),
        .slot1_is_jalr_i(slot1_is_jalr),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
        .slot1_is_lui_i(slot1_is_lui),
        .slot1_is_auipc_i(slot1_is_auipc),
        .slot1_unknown_inst_i(slot1_unknown_inst),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_uses_rs1_i(slot1_uses_rs1),
        .slot1_uses_rs2_i(slot1_uses_rs2),
        .slot1_src_a_sel_i(slot1_src_a_sel),
        .slot1_src_b_sel_i(slot1_src_b_sel),
        .slot1_alu_op_i(slot1_alu_op),
        .slot1_rs1_val_i(slot1_rs1_val),
        .slot1_rs2_val_i(slot1_rs2_val),
        .slot1_op_a_i(slot1_op_a),
        .slot1_op_b_i(slot1_op_b),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_ctrl_flow_o(slot1_ctrl_flow),
        .slot1_actual_taken_o(slot1_actual_taken),
        .slot1_actual_target_o(slot1_actual_target),
        .slot1_branch_target_o(slot1_branch_target),
        .slot1_jump_target_o(slot1_jump_target),
        .slot1_redirect_raw_o(slot1_redirect_raw),
        .slot1_uncond_b_o(slot1_uncond_b),
        .slot1_uncond_bl_o(slot1_uncond_bl),
        .slot1_uncond_jirl_o(slot1_uncond_jirl),
        .slot1_ret_o(slot1_ret),
        .slot1_indirect_jirl_o(slot1_indirect_jirl),
        .s8_slot1_pc_o(),
        .s8_instr1_o(),
        .s8_slot1_valid_o(),
        .s8_slot1_opcode_o(),
        .s8_slot1_funct3_o(),
        .s8_slot1_funct7_o(),
        .s8_slot1_op_19_15_o(),
        .s8_slot1_rs1_o(),
        .s8_slot1_rs2_o(),
        .s8_slot1_rd_o(),
        .s8_slot1_imm_o(),
        .s8_slot1_is_branch_o(),
        .s8_slot1_is_jal_o(),
        .s8_slot1_is_jalr_o(),
        .s8_slot1_is_load_o(s8_slot1_is_load),
        .s8_slot1_is_store_o(s8_slot1_is_store),
        .s8_slot1_is_lui_o(),
        .s8_slot1_is_auipc_o(),
        .s8_slot1_unknown_inst_o(),
        .s8_slot1_wb_en_o(),
        .s8_slot1_uses_rs1_o(),
        .s8_slot1_uses_rs2_o(),
        .s8_slot1_src_a_sel_o(),
        .s8_slot1_src_b_sel_o(),
        .s8_slot1_alu_op_o(),
        .s8_slot1_rs1_val_o(),
        .s8_slot1_rs2_val_o(),
        .s8_slot1_op_a_o(),
        .s8_slot1_op_b_o(),
        .s8_slot1_alu_result_o(s8_slot1_alu_result),
        .s8_slot1_mem_size_o(s8_slot1_mem_size),
        .s8_slot1_store_data_o(s8_slot1_store_data),
        .s8_slot1_exception_o(s8_slot1_exception),
        .s8_slot1_excp_ecode_o(s8_slot1_excp_ecode),
        .s8_slot1_excp_esubcode_o(),
        .s8_slot1_excp_badv_valid_o(s8_slot1_excp_badv_valid),
        .s8_slot1_excp_badv_o(s8_slot1_excp_badv),
        .s8_slot1_issue_valid_o(s8_slot1_issue_valid),
        .s8_slot1_issue_class_o(s8_slot1_issue_class)
    );

    task automatic clear_inputs;
        begin
            slot0_rd = 5'd0;
            slot0_wb_en = 1'b0;
            slot0_is_load = 1'b0;
            slot0_is_store = 1'b0;
            slot0_is_branch = 1'b0;
            slot0_is_jal = 1'b0;
            slot0_is_jalr = 1'b0;
            slot0_result = 32'hcafe_beef;
            slot1_pc = 32'h1c01_0100;
            instr1 = 32'h0;
            slot1_valid = 1'b0;
            slot1_opcode = 7'd0;
            slot1_funct3 = 3'd0;
            slot1_funct7 = 7'd0;
            slot1_op_19_15 = 5'd0;
            slot1_rs1 = 5'd0;
            slot1_rs2 = 5'd0;
            slot1_rd = 5'd0;
            slot1_imm = 32'd0;
            slot1_is_branch = 1'b0;
            slot1_is_jal = 1'b0;
            slot1_is_jalr = 1'b0;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b0;
            slot1_is_lui = 1'b0;
            slot1_is_auipc = 1'b0;
            slot1_unknown_inst = 1'b0;
            slot1_wb_en = 1'b0;
            slot1_uses_rs1 = 1'b0;
            slot1_uses_rs2 = 1'b0;
            slot1_src_a_sel = `CPU_SRC_A_RS1;
            slot1_src_b_sel = `CPU_SRC_B_RS2;
            slot1_alu_op = `CPU_ALU_ADD;
            slot1_rs1_val = 32'h1111_1111;
            slot1_rs2_val = 32'h2222_2222;
            slot1_op_a = 32'h10;
            slot1_op_b = 32'h4;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S8 slot1 exec bank idle is silent",
               !slot1_ctrl_flow && !slot1_redirect_raw &&
               !s8_slot1_issue_valid && !s8_slot1_exception);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd5;
        slot0_result = 32'h1000_0000;
        slot1_valid = 1'b1;
        slot1_opcode = 7'h0a;
        slot1_funct7 = 7'h02;
        slot1_rs1 = 5'd5;
        slot1_rd = 5'd6;
        slot1_imm = 32'h4;
        slot1_is_load = 1'b1;
        slot1_wb_en = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_src_a_sel = `CPU_SRC_A_RS1;
        slot1_src_b_sel = `CPU_SRC_B_IMM;
        slot1_op_a = 32'h0;
        slot1_op_b = 32'h4;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        #1;
        `check("S8 slot1 exec bank issued load keeps sideband and issue class",
               s8_slot1_issue_valid && s8_slot1_is_load && !s8_slot1_is_store &&
               s8_slot1_issue_class == `CPU_SLOT1_CLASS_LOAD &&
               !s8_slot1_exception);
        `check32("S8 slot1 exec bank load address uses slot0 bypass", s8_slot1_alu_result,
                 32'h1000_0004);
        `check32("S8 slot1 exec bank load size decode", {30'd0, s8_slot1_mem_size}, 32'd2);
        `check32("S8 slot1 exec bank load store-data stays zero", s8_slot1_store_data, 32'd0);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd7;
        slot0_result = 32'hdead_beef;
        slot1_valid = 1'b1;
        slot1_opcode = 7'h0a;
        slot1_funct7 = 7'h06;
        slot1_rs2 = 5'd7;
        slot1_imm = 32'h8;
        slot1_is_store = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_src_a_sel = `CPU_SRC_A_RS1;
        slot1_src_b_sel = `CPU_SRC_B_IMM;
        slot1_op_a = 32'h0000_2000;
        slot1_op_b = 32'h8;
        slot1_rs1_val = 32'h0000_2000;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_STORE;
        #1;
        `check("S8 slot1 exec bank issued store keeps store sideband",
               s8_slot1_issue_valid && !s8_slot1_is_load && s8_slot1_is_store &&
               s8_slot1_issue_class == `CPU_SLOT1_CLASS_STORE &&
               !s8_slot1_exception);
        `check32("S8 slot1 exec bank store address", s8_slot1_alu_result, 32'h0000_2008);
        `check32("S8 slot1 exec bank store size decode", {30'd0, s8_slot1_mem_size}, 32'd2);
        `check32("S8 slot1 exec bank store data uses slot0 bypass", s8_slot1_store_data,
                 32'hdead_beef);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd8;
        slot0_result = 32'h0000_0055;
        slot1_valid = 1'b1;
        slot1_opcode = 7'h16;
        slot1_rs1 = 5'd8;
        slot1_rs2 = 5'd9;
        slot1_imm = 32'h20;
        slot1_is_branch = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs2_val = 32'h0000_0055;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_CTRL;
        #1;
        `check("S8 slot1 exec bank branch resolve can use slot0 compare bypass",
               slot1_ctrl_flow && slot1_actual_taken && slot1_redirect_raw &&
               !slot1_uncond_b && !slot1_uncond_bl && !slot1_uncond_jirl);
        `check32("S8 slot1 exec bank branch target", slot1_branch_target, 32'h1c01_0120);
        `check32("S8 slot1 exec bank branch actual target", slot1_actual_target, 32'h1c01_0120);
        `check32("S8 slot1 exec bank branch issue class", {28'd0, s8_slot1_issue_class},
                 {28'd0, `CPU_SLOT1_CLASS_CTRL});

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_opcode = 7'h00;
        slot1_funct3 = 3'h1;
        slot1_op_19_15 = 5'h18;
        slot1_op_a = 32'hffff_fffe;
        slot1_op_b = 32'h0000_0003;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_COMPUTE;
        #1;
        `check("S8 slot1 exec bank mul.w keeps compute issue class",
               s8_slot1_issue_valid &&
               s8_slot1_issue_class == `CPU_SLOT1_CLASS_COMPUTE &&
               !slot1_ctrl_flow && !s8_slot1_exception);
        `check32("S8 slot1 exec bank mul.w low result", s8_slot1_alu_result, 32'hffff_fffa);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_opcode = 7'h0a;
        slot1_funct7 = 7'h02;
        slot1_rs1 = 5'd3;
        slot1_rd = 5'd10;
        slot1_imm = 32'h1;
        slot1_is_load = 1'b1;
        slot1_wb_en = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_src_a_sel = `CPU_SRC_A_RS1;
        slot1_src_b_sel = `CPU_SRC_B_IMM;
        slot1_rs1_val = 32'h0000_0002;
        slot1_op_a = 32'h0000_0002;
        slot1_op_b = 32'h0000_0001;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        #1;
        `check("S8 slot1 exec bank unaligned load raises ALE sideband",
               s8_slot1_issue_valid && s8_slot1_exception &&
               s8_slot1_excp_badv_valid && s8_slot1_is_load);
        `check32("S8 slot1 exec bank unaligned load badv", s8_slot1_excp_badv, 32'h0000_0003);
        `check32("S8 slot1 exec bank unaligned load ALE ecode",
                 {26'd0, s8_slot1_excp_ecode}, {26'd0, `CPU_ECODE_ALE});

        finish_tb();
    end
endmodule

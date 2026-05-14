`timescale 1ns / 1ps

module s5_slot1_source_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        load_hold;
    logic [31:0] hold_slot1_pc;
    logic [31:0] hold_instr1;
    logic        hold_slot1_valid;
    logic [6:0]  hold_slot1_opcode;
    logic [2:0]  hold_slot1_funct3;
    logic [6:0]  hold_slot1_funct7;
    logic [4:0]  hold_slot1_op_19_15;
    logic [4:0]  hold_slot1_rs1;
    logic [4:0]  hold_slot1_rs2;
    logic [4:0]  hold_slot1_rd;
    logic [31:0] hold_slot1_imm;
    logic        hold_slot1_is_branch;
    logic        hold_slot1_is_jal;
    logic        hold_slot1_is_jalr;
    logic        hold_slot1_is_load;
    logic        hold_slot1_is_store;
    logic        hold_slot1_is_lui;
    logic        hold_slot1_is_auipc;
    logic        hold_slot1_unknown_inst;
    logic [31:0] hold_slot1_rf1_base;
    logic [31:0] hold_slot1_rf2_base;

    logic        load_s4;
    logic [31:0] s4_slot1_pc;
    logic [31:0] s4_instr1;
    logic        s4_slot1_valid;
    logic [6:0]  s4_slot1_opcode;
    logic [2:0]  s4_slot1_funct3;
    logic [6:0]  s4_slot1_funct7;
    logic [4:0]  s4_slot1_op_19_15;
    logic [4:0]  s4_slot1_rs1;
    logic [4:0]  s4_slot1_rs2;
    logic [4:0]  s4_slot1_rd;
    logic [31:0] s4_slot1_imm;
    logic        s4_slot1_is_branch;
    logic        s4_slot1_is_jal;
    logic        s4_slot1_is_jalr;
    logic        s4_slot1_is_load;
    logic        s4_slot1_is_store;
    logic        s4_slot1_is_lui;
    logic        s4_slot1_is_auipc;
    logic        s4_slot1_unknown_inst;
    logic [31:0] s4_slot1_rf1_base;
    logic [31:0] s4_slot1_rf2_base;

    logic        load;
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
    logic [31:0] slot1_rf1_base;
    logic [31:0] slot1_rf2_base;

    s5_slot1_source_select #(
        .XLEN(32),
        .ILEN(32)
    ) u_dut (
        .load_hold_i(load_hold),
        .hold_slot1_pc_i(hold_slot1_pc),
        .hold_instr1_i(hold_instr1),
        .hold_slot1_valid_i(hold_slot1_valid),
        .hold_slot1_opcode_i(hold_slot1_opcode),
        .hold_slot1_funct3_i(hold_slot1_funct3),
        .hold_slot1_funct7_i(hold_slot1_funct7),
        .hold_slot1_op_19_15_i(hold_slot1_op_19_15),
        .hold_slot1_rs1_i(hold_slot1_rs1),
        .hold_slot1_rs2_i(hold_slot1_rs2),
        .hold_slot1_rd_i(hold_slot1_rd),
        .hold_slot1_imm_i(hold_slot1_imm),
        .hold_slot1_is_branch_i(hold_slot1_is_branch),
        .hold_slot1_is_jal_i(hold_slot1_is_jal),
        .hold_slot1_is_jalr_i(hold_slot1_is_jalr),
        .hold_slot1_is_load_i(hold_slot1_is_load),
        .hold_slot1_is_store_i(hold_slot1_is_store),
        .hold_slot1_is_lui_i(hold_slot1_is_lui),
        .hold_slot1_is_auipc_i(hold_slot1_is_auipc),
        .hold_slot1_unknown_inst_i(hold_slot1_unknown_inst),
        .hold_slot1_rf1_base_i(hold_slot1_rf1_base),
        .hold_slot1_rf2_base_i(hold_slot1_rf2_base),
        .load_s4_i(load_s4),
        .s4_slot1_pc_i(s4_slot1_pc),
        .s4_instr1_i(s4_instr1),
        .s4_slot1_valid_i(s4_slot1_valid),
        .s4_slot1_opcode_i(s4_slot1_opcode),
        .s4_slot1_funct3_i(s4_slot1_funct3),
        .s4_slot1_funct7_i(s4_slot1_funct7),
        .s4_slot1_op_19_15_i(s4_slot1_op_19_15),
        .s4_slot1_rs1_i(s4_slot1_rs1),
        .s4_slot1_rs2_i(s4_slot1_rs2),
        .s4_slot1_rd_i(s4_slot1_rd),
        .s4_slot1_imm_i(s4_slot1_imm),
        .s4_slot1_is_branch_i(s4_slot1_is_branch),
        .s4_slot1_is_jal_i(s4_slot1_is_jal),
        .s4_slot1_is_jalr_i(s4_slot1_is_jalr),
        .s4_slot1_is_load_i(s4_slot1_is_load),
        .s4_slot1_is_store_i(s4_slot1_is_store),
        .s4_slot1_is_lui_i(s4_slot1_is_lui),
        .s4_slot1_is_auipc_i(s4_slot1_is_auipc),
        .s4_slot1_unknown_inst_i(s4_slot1_unknown_inst),
        .s4_slot1_rf1_base_i(s4_slot1_rf1_base),
        .s4_slot1_rf2_base_i(s4_slot1_rf2_base),
        .load_o(load),
        .slot1_pc_o(slot1_pc),
        .instr1_o(instr1),
        .slot1_valid_o(slot1_valid),
        .slot1_opcode_o(slot1_opcode),
        .slot1_funct3_o(slot1_funct3),
        .slot1_funct7_o(slot1_funct7),
        .slot1_op_19_15_o(slot1_op_19_15),
        .slot1_rs1_o(slot1_rs1),
        .slot1_rs2_o(slot1_rs2),
        .slot1_rd_o(slot1_rd),
        .slot1_imm_o(slot1_imm),
        .slot1_is_branch_o(slot1_is_branch),
        .slot1_is_jal_o(slot1_is_jal),
        .slot1_is_jalr_o(slot1_is_jalr),
        .slot1_is_load_o(slot1_is_load),
        .slot1_is_store_o(slot1_is_store),
        .slot1_is_lui_o(slot1_is_lui),
        .slot1_is_auipc_o(slot1_is_auipc),
        .slot1_unknown_inst_o(slot1_unknown_inst),
        .slot1_rf1_base_o(slot1_rf1_base),
        .slot1_rf2_base_o(slot1_rf2_base)
    );

    initial begin
        tb_start();

        load_hold = 1'b0;
        hold_slot1_pc = 32'h1c00_1104;
        hold_instr1 = 32'h1104_aaaa;
        hold_slot1_valid = 1'b1;
        hold_slot1_opcode = 7'h11;
        hold_slot1_funct3 = 3'h2;
        hold_slot1_funct7 = 7'h35;
        hold_slot1_op_19_15 = 5'h14;
        hold_slot1_rs1 = 5'd1;
        hold_slot1_rs2 = 5'd2;
        hold_slot1_rd = 5'd3;
        hold_slot1_imm = 32'h0000_0104;
        hold_slot1_is_branch = 1'b1;
        hold_slot1_is_jal = 1'b0;
        hold_slot1_is_jalr = 1'b1;
        hold_slot1_is_load = 1'b0;
        hold_slot1_is_store = 1'b1;
        hold_slot1_is_lui = 1'b0;
        hold_slot1_is_auipc = 1'b1;
        hold_slot1_unknown_inst = 1'b0;
        hold_slot1_rf1_base = 32'h1111_0001;
        hold_slot1_rf2_base = 32'h2222_0002;

        load_s4 = 1'b0;
        s4_slot1_pc = 32'h1c00_2208;
        s4_instr1 = 32'h2208_bbbb;
        s4_slot1_valid = 1'b1;
        s4_slot1_opcode = 7'h22;
        s4_slot1_funct3 = 3'h3;
        s4_slot1_funct7 = 7'h46;
        s4_slot1_op_19_15 = 5'h08;
        s4_slot1_rs1 = 5'd4;
        s4_slot1_rs2 = 5'd5;
        s4_slot1_rd = 5'd6;
        s4_slot1_imm = 32'h0000_0208;
        s4_slot1_is_branch = 1'b0;
        s4_slot1_is_jal = 1'b1;
        s4_slot1_is_jalr = 1'b0;
        s4_slot1_is_load = 1'b1;
        s4_slot1_is_store = 1'b0;
        s4_slot1_is_lui = 1'b1;
        s4_slot1_is_auipc = 1'b0;
        s4_slot1_unknown_inst = 1'b1;
        s4_slot1_rf1_base = 32'h3333_0003;
        s4_slot1_rf2_base = 32'h4444_0004;

        #1;
        `check("SRC idle keeps load low", !load);
        `check32("SRC idle clears pc", slot1_pc, 32'd0);
        `check("SRC idle clears valid", !slot1_valid);
        `check32("SRC idle clears rf1", slot1_rf1_base, 32'd0);
        `check32("SRC idle clears rf2", slot1_rf2_base, 32'd0);

        load_s4 = 1'b1;
        #1;
        `check("SRC s4 asserts load", load);
        `check32("SRC s4 pc", slot1_pc, 32'h1c00_2208);
        `check32("SRC s4 instr", instr1, 32'h2208_bbbb);
        `check32("SRC s4 regs", {17'd0, slot1_rs1, slot1_rs2, slot1_rd},
                 {17'd0, 5'd4, 5'd5, 5'd6});
        `check("SRC s4 valid", slot1_valid);
        `check("SRC s4 flags", !slot1_is_branch && slot1_is_jal &&
                               slot1_is_load && slot1_unknown_inst);
        `check32("SRC s4 rf1", slot1_rf1_base, 32'h3333_0003);
        `check32("SRC s4 rf2", slot1_rf2_base, 32'h4444_0004);

        load_hold = 1'b1;
        #1;
        `check("SRC hold has priority", load);
        `check32("SRC hold pc", slot1_pc, 32'h1c00_1104);
        `check32("SRC hold instr", instr1, 32'h1104_aaaa);
        `check32("SRC hold regs", {17'd0, slot1_rs1, slot1_rs2, slot1_rd},
                 {17'd0, 5'd1, 5'd2, 5'd3});
        `check("SRC hold flags", slot1_is_branch && !slot1_is_jal &&
                                 slot1_is_jalr && slot1_is_store && slot1_is_auipc);
        `check32("SRC hold rf1", slot1_rf1_base, 32'h1111_0001);
        `check32("SRC hold rf2", slot1_rf2_base, 32'h2222_0002);

        load_hold = 1'b0;
        load_s4 = 1'b0;
        #1;
        `check("SRC deassert clears load", !load);
        `check32("SRC deassert clears pc", slot1_pc, 32'd0);

        finish_tb();
    end

endmodule

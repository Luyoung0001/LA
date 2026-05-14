`timescale 1ns / 1ps

module s5_slot1_promote_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] slot1_pc;
    logic [31:0] instr1;
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
    logic [31:0] promoted_pc;
    logic [31:0] promoted_instr;
    logic        promoted_pred_taken;
    logic [31:0] promoted_pred_target;
    logic        promoted_fault;
    logic [5:0]  promoted_fault_ecode;
    logic [31:0] promoted_fault_badv;
    logic [6:0]  promoted_opcode;
    logic [2:0]  promoted_funct3;
    logic [6:0]  promoted_funct7;
    logic [4:0]  promoted_op_19_15;
    logic [4:0]  promoted_rs1;
    logic [4:0]  promoted_rs2;
    logic [4:0]  promoted_rd;
    logic [31:0] promoted_imm;
    logic        promoted_is_branch;
    logic        promoted_is_jal;
    logic        promoted_is_jalr;
    logic        promoted_is_load;
    logic        promoted_is_store;
    logic        promoted_is_lui;
    logic        promoted_is_auipc;
    logic        promoted_unknown_inst;
    logic [31:0] promoted_rf1_base;
    logic [31:0] promoted_rf2_base;

    s5_slot1_promote_packet #(
        .XLEN(32),
        .ILEN(32)
    ) u_dut (
        .slot1_pc_i(slot1_pc),
        .instr1_i(instr1),
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
        .slot1_rf1_base_i(slot1_rf1_base),
        .slot1_rf2_base_i(slot1_rf2_base),
        .promoted_pc_o(promoted_pc),
        .promoted_instr_o(promoted_instr),
        .promoted_pred_taken_o(promoted_pred_taken),
        .promoted_pred_target_o(promoted_pred_target),
        .promoted_fault_o(promoted_fault),
        .promoted_fault_ecode_o(promoted_fault_ecode),
        .promoted_fault_badv_o(promoted_fault_badv),
        .promoted_opcode_o(promoted_opcode),
        .promoted_funct3_o(promoted_funct3),
        .promoted_funct7_o(promoted_funct7),
        .promoted_op_19_15_o(promoted_op_19_15),
        .promoted_rs1_o(promoted_rs1),
        .promoted_rs2_o(promoted_rs2),
        .promoted_rd_o(promoted_rd),
        .promoted_imm_o(promoted_imm),
        .promoted_is_branch_o(promoted_is_branch),
        .promoted_is_jal_o(promoted_is_jal),
        .promoted_is_jalr_o(promoted_is_jalr),
        .promoted_is_load_o(promoted_is_load),
        .promoted_is_store_o(promoted_is_store),
        .promoted_is_lui_o(promoted_is_lui),
        .promoted_is_auipc_o(promoted_is_auipc),
        .promoted_unknown_inst_o(promoted_unknown_inst),
        .promoted_rf1_base_o(promoted_rf1_base),
        .promoted_rf2_base_o(promoted_rf2_base)
    );

    initial begin
        tb_start();
        rst_n = 1'b1;

        slot1_pc = 32'h1c00_0104;
        instr1 = 32'h0280_4445;
        slot1_opcode = 7'h12;
        slot1_funct3 = 3'h5;
        slot1_funct7 = 7'h3a;
        slot1_op_19_15 = 5'h17;
        slot1_rs1 = 5'd6;
        slot1_rs2 = 5'd7;
        slot1_rd = 5'd8;
        slot1_imm = 32'hffff_fabc;
        slot1_is_branch = 1'b1;
        slot1_is_jal = 1'b0;
        slot1_is_jalr = 1'b0;
        slot1_is_load = 1'b0;
        slot1_is_store = 1'b0;
        slot1_is_lui = 1'b0;
        slot1_is_auipc = 1'b0;
        slot1_unknown_inst = 1'b0;
        slot1_rf1_base = 32'h1111_2222;
        slot1_rf2_base = 32'h3333_4444;
        #1;

        `check32("PROMOTE pc maps from slot1", promoted_pc, slot1_pc);
        `check32("PROMOTE instr maps from slot1", promoted_instr, instr1);
        `check32("PROMOTE fault badv uses slot1 pc", promoted_fault_badv, slot1_pc);
        `check("PROMOTE clears prediction and fault metadata",
               !promoted_pred_taken && promoted_pred_target == 32'd0 &&
               !promoted_fault && promoted_fault_ecode == 6'd0);
        `check("PROMOTE decode metadata maps through",
               promoted_opcode == slot1_opcode &&
               promoted_funct3 == slot1_funct3 &&
               promoted_funct7 == slot1_funct7 &&
               promoted_op_19_15 == slot1_op_19_15);
        `check("PROMOTE register metadata maps through",
               promoted_rs1 == slot1_rs1 &&
               promoted_rs2 == slot1_rs2 &&
               promoted_rd == slot1_rd &&
               promoted_imm == slot1_imm);
        `check("PROMOTE class flags map through",
               promoted_is_branch && !promoted_is_jal && !promoted_is_jalr &&
               !promoted_is_load && !promoted_is_store &&
               !promoted_is_lui && !promoted_is_auipc &&
               !promoted_unknown_inst);
        `check32("PROMOTE rf1 base maps through",
                 promoted_rf1_base, slot1_rf1_base);
        `check32("PROMOTE rf2 base maps through",
                 promoted_rf2_base, slot1_rf2_base);

        slot1_is_branch = 1'b0;
        slot1_is_load = 1'b1;
        slot1_is_store = 1'b1;
        slot1_is_lui = 1'b1;
        slot1_is_auipc = 1'b1;
        slot1_unknown_inst = 1'b1;
        #1;
        `check("PROMOTE class flags update combinationally",
               !promoted_is_branch && promoted_is_load && promoted_is_store &&
               promoted_is_lui && promoted_is_auipc && promoted_unknown_inst);

        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module s8_slot1_issue_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

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
    logic [31:0] slot1_alu_result;
    logic [1:0]  slot1_mem_size;
    logic [31:0] slot1_store_data;
    logic        slot1_exception;
    logic [5:0]  slot1_excp_ecode;
    logic [8:0]  slot1_excp_esubcode;
    logic        slot1_excp_badv_valid;
    logic [31:0] slot1_excp_badv;
    logic        slot1_issue_valid;
    logic [3:0]  slot1_issue_class;

    logic [31:0] slot1_pc_o;
    logic [31:0] instr1_o;
    logic        slot1_valid_o;
    logic [6:0]  slot1_opcode_o;
    logic [2:0]  slot1_funct3_o;
    logic [6:0]  slot1_funct7_o;
    logic [4:0]  slot1_op_19_15_o;
    logic [4:0]  slot1_rs1_o;
    logic [4:0]  slot1_rs2_o;
    logic [4:0]  slot1_rd_o;
    logic [31:0] slot1_imm_o;
    logic        slot1_is_branch_o;
    logic        slot1_is_jal_o;
    logic        slot1_is_jalr_o;
    logic        slot1_is_load_o;
    logic        slot1_is_store_o;
    logic        slot1_is_lui_o;
    logic        slot1_is_auipc_o;
    logic        slot1_unknown_inst_o;
    logic        slot1_wb_en_o;
    logic        slot1_uses_rs1_o;
    logic        slot1_uses_rs2_o;
    logic [1:0]  slot1_src_a_sel_o;
    logic [1:0]  slot1_src_b_sel_o;
    logic [3:0]  slot1_alu_op_o;
    logic [31:0] slot1_rs1_val_o;
    logic [31:0] slot1_rs2_val_o;
    logic [31:0] slot1_op_a_o;
    logic [31:0] slot1_op_b_o;
    logic [31:0] slot1_alu_result_o;
    logic [1:0]  slot1_mem_size_o;
    logic [31:0] slot1_store_data_o;
    logic        slot1_exception_o;
    logic [5:0]  slot1_excp_ecode_o;
    logic [8:0]  slot1_excp_esubcode_o;
    logic        slot1_excp_badv_valid_o;
    logic [31:0] slot1_excp_badv_o;
    logic        slot1_issue_valid_o;
    logic [3:0]  slot1_issue_class_o;

    s8_slot1_issue_packet u_dut (
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
        .slot1_alu_result_i(slot1_alu_result),
        .slot1_mem_size_i(slot1_mem_size),
        .slot1_store_data_i(slot1_store_data),
        .slot1_exception_i(slot1_exception),
        .slot1_excp_ecode_i(slot1_excp_ecode),
        .slot1_excp_esubcode_i(slot1_excp_esubcode),
        .slot1_excp_badv_valid_i(slot1_excp_badv_valid),
        .slot1_excp_badv_i(slot1_excp_badv),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_pc_o(slot1_pc_o),
        .instr1_o(instr1_o),
        .slot1_valid_o(slot1_valid_o),
        .slot1_opcode_o(slot1_opcode_o),
        .slot1_funct3_o(slot1_funct3_o),
        .slot1_funct7_o(slot1_funct7_o),
        .slot1_op_19_15_o(slot1_op_19_15_o),
        .slot1_rs1_o(slot1_rs1_o),
        .slot1_rs2_o(slot1_rs2_o),
        .slot1_rd_o(slot1_rd_o),
        .slot1_imm_o(slot1_imm_o),
        .slot1_is_branch_o(slot1_is_branch_o),
        .slot1_is_jal_o(slot1_is_jal_o),
        .slot1_is_jalr_o(slot1_is_jalr_o),
        .slot1_is_load_o(slot1_is_load_o),
        .slot1_is_store_o(slot1_is_store_o),
        .slot1_is_lui_o(slot1_is_lui_o),
        .slot1_is_auipc_o(slot1_is_auipc_o),
        .slot1_unknown_inst_o(slot1_unknown_inst_o),
        .slot1_wb_en_o(slot1_wb_en_o),
        .slot1_uses_rs1_o(slot1_uses_rs1_o),
        .slot1_uses_rs2_o(slot1_uses_rs2_o),
        .slot1_src_a_sel_o(slot1_src_a_sel_o),
        .slot1_src_b_sel_o(slot1_src_b_sel_o),
        .slot1_alu_op_o(slot1_alu_op_o),
        .slot1_rs1_val_o(slot1_rs1_val_o),
        .slot1_rs2_val_o(slot1_rs2_val_o),
        .slot1_op_a_o(slot1_op_a_o),
        .slot1_op_b_o(slot1_op_b_o),
        .slot1_alu_result_o(slot1_alu_result_o),
        .slot1_mem_size_o(slot1_mem_size_o),
        .slot1_store_data_o(slot1_store_data_o),
        .slot1_exception_o(slot1_exception_o),
        .slot1_excp_ecode_o(slot1_excp_ecode_o),
        .slot1_excp_esubcode_o(slot1_excp_esubcode_o),
        .slot1_excp_badv_valid_o(slot1_excp_badv_valid_o),
        .slot1_excp_badv_o(slot1_excp_badv_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .slot1_issue_class_o(slot1_issue_class_o)
    );

    task automatic drive_payload(input logic valid, input logic issue_valid);
        begin
            slot1_pc = 32'h1c00_6004;
            instr1 = 32'h2988_0018;
            slot1_valid = valid;
            slot1_opcode = 7'h2a;
            slot1_funct3 = 3'h2;
            slot1_funct7 = 7'h06;
            slot1_op_19_15 = 5'h03;
            slot1_rs1 = 5'd12;
            slot1_rs2 = 5'd24;
            slot1_rd = 5'd0;
            slot1_imm = 32'h0000_0060;
            slot1_is_branch = 1'b0;
            slot1_is_jal = 1'b0;
            slot1_is_jalr = 1'b0;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b1;
            slot1_is_lui = 1'b0;
            slot1_is_auipc = 1'b0;
            slot1_unknown_inst = 1'b0;
            slot1_wb_en = 1'b0;
            slot1_uses_rs1 = 1'b1;
            slot1_uses_rs2 = 1'b1;
            slot1_src_a_sel = 2'd0;
            slot1_src_b_sel = 2'd1;
            slot1_alu_op = 4'h0;
            slot1_rs1_val = 32'h1000_0000;
            slot1_rs2_val = 32'hfeed_beef;
            slot1_op_a = 32'h1000_0000;
            slot1_op_b = 32'h0000_0060;
            slot1_alu_result = 32'h1000_0060;
            slot1_mem_size = 2'd2;
            slot1_store_data = 32'hfeed_beef;
            slot1_exception = 1'b1;
            slot1_excp_ecode = 6'h09;
            slot1_excp_esubcode = 9'h012;
            slot1_excp_badv_valid = 1'b1;
            slot1_excp_badv = 32'h1000_0062;
            slot1_issue_valid = issue_valid;
            slot1_issue_class = 4'b0010;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_payload(1'b0, 1'b1);
        #1;
        `check32("PKT invalid still passes pc for debug", slot1_pc_o, 32'h1c00_6004);
        `check("PKT invalid clears valid and issue", !slot1_valid_o && !slot1_issue_valid_o);
        `check32("PKT invalid clears decoded fields", {17'd0, slot1_rs1_o, slot1_rs2_o, slot1_rd_o}, 32'd0);
        `check32("PKT invalid clears result", slot1_alu_result_o, 32'd0);
        `check32("PKT invalid clears mem data", {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("PKT invalid clears store data", slot1_store_data_o, 32'd0);
        `check("PKT invalid clears exception", !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check32("PKT invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);

        drive_payload(1'b1, 1'b0);
        #1;
        `check("PKT valid without issue keeps issue low", slot1_valid_o && !slot1_issue_valid_o);
        `check32("PKT valid without issue clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("PKT valid keeps store sideband", slot1_is_store_o && !slot1_is_load_o);
        `check32("PKT valid opcode", {25'd0, slot1_opcode_o}, {25'd0, 7'h2a});
        `check32("PKT valid registers", {17'd0, slot1_rs1_o, slot1_rs2_o, slot1_rd_o}, {17'd0, 5'd12, 5'd24, 5'd0});
        `check32("PKT valid imm", slot1_imm_o, 32'h0000_0060);
        `check32("PKT valid op A", slot1_op_a_o, 32'h1000_0000);
        `check32("PKT valid op B", slot1_op_b_o, 32'h0000_0060);
        `check32("PKT valid ALU result", slot1_alu_result_o, 32'h1000_0060);
        `check32("PKT valid store data", slot1_store_data_o, 32'hfeed_beef);
        `check32("PKT valid mem size", {30'd0, slot1_mem_size_o}, 32'd2);
        `check("PKT valid exception pass",
               slot1_exception_o && slot1_excp_ecode_o == 6'h09 &&
               slot1_excp_esubcode_o == 9'h012 && slot1_excp_badv_valid_o);
        `check32("PKT valid badv pass", slot1_excp_badv_o, 32'h1000_0062);

        slot1_is_store = 1'b0;
        slot1_is_load = 1'b0;
        slot1_exception = 1'b0;
        slot1_excp_badv_valid = 1'b1;
        #1;
        `check32("PKT non-memory clears mem size", {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("PKT non-store clears store data", slot1_store_data_o, 32'd0);
        `check("PKT no exception clears ecode but can preserve explicit badv valid",
               !slot1_exception_o && slot1_excp_ecode_o == 6'd0 &&
               slot1_excp_badv_valid_o);

        drive_payload(1'b1, 1'b1);
        #1;
        `check("PKT valid and issue emits issue", slot1_valid_o && slot1_issue_valid_o);
        `check32("PKT valid and issue preserves issue class", {28'd0, slot1_issue_class_o}, {28'd0, 4'b0010});

        finish_tb();
    end
endmodule

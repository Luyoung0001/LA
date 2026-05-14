`timescale 1ns / 1ps

module s10_slot1_commit_packet_tb;
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
    logic [31:0] slot1_alu_result;
    logic [1:0]  slot1_mem_size;
    logic [31:0] slot1_store_data;
    logic        slot1_mem_lsu;
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
    logic [31:0] slot1_alu_result_o;
    logic [1:0]  slot1_mem_size_o;
    logic [31:0] slot1_store_data_o;
    logic        slot1_mem_lsu_o;
    logic        slot1_exception_o;
    logic [5:0]  slot1_excp_ecode_o;
    logic [8:0]  slot1_excp_esubcode_o;
    logic        slot1_excp_badv_valid_o;
    logic [31:0] slot1_excp_badv_o;
    logic        slot1_issue_valid_o;
    logic [3:0]  slot1_issue_class_o;

    s10_slot1_commit_packet u_dut (
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
        .slot1_alu_result_i(slot1_alu_result),
        .slot1_mem_size_i(slot1_mem_size),
        .slot1_store_data_i(slot1_store_data),
        .slot1_mem_lsu_i(slot1_mem_lsu),
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
        .slot1_alu_result_o(slot1_alu_result_o),
        .slot1_mem_size_o(slot1_mem_size_o),
        .slot1_store_data_o(slot1_store_data_o),
        .slot1_mem_lsu_o(slot1_mem_lsu_o),
        .slot1_exception_o(slot1_exception_o),
        .slot1_excp_ecode_o(slot1_excp_ecode_o),
        .slot1_excp_esubcode_o(slot1_excp_esubcode_o),
        .slot1_excp_badv_valid_o(slot1_excp_badv_valid_o),
        .slot1_excp_badv_o(slot1_excp_badv_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .slot1_issue_class_o(slot1_issue_class_o)
    );

    task automatic drive_valid_packet;
        begin
            slot1_pc = 32'h1c00_0104;
            instr1 = 32'h0280_0042;
            slot1_valid = 1'b1;
            slot1_opcode = 7'h2a;
            slot1_funct3 = 3'h5;
            slot1_funct7 = 7'h55;
            slot1_op_19_15 = 5'd19;
            slot1_rs1 = 5'd3;
            slot1_rs2 = 5'd4;
            slot1_rd = 5'd5;
            slot1_imm = 32'h1122_3344;
            slot1_is_branch = 1'b1;
            slot1_is_jal = 1'b1;
            slot1_is_jalr = 1'b1;
            slot1_is_load = 1'b1;
            slot1_is_store = 1'b0;
            slot1_is_lui = 1'b1;
            slot1_is_auipc = 1'b1;
            slot1_unknown_inst = 1'b1;
            slot1_wb_en = 1'b1;
            slot1_uses_rs1 = 1'b1;
            slot1_uses_rs2 = 1'b1;
            slot1_src_a_sel = 2'd2;
            slot1_src_b_sel = 2'd3;
            slot1_alu_op = 4'ha;
            slot1_alu_result = 32'h5566_7788;
            slot1_mem_size = 2'd1;
            slot1_store_data = 32'haabb_ccdd;
            slot1_mem_lsu = 1'b1;
            slot1_exception = 1'b1;
            slot1_excp_ecode = 6'h12;
            slot1_excp_esubcode = 9'h155;
            slot1_excp_badv_valid = 1'b1;
            slot1_excp_badv = 32'hdead_beef;
            slot1_issue_valid = 1'b1;
            slot1_issue_class = 4'b0100;
        end
    endtask

    task automatic check_zeroed_sideband(input string name);
        begin
            #1;
            `check(name,
                   slot1_pc_o == slot1_pc &&
                   instr1_o == instr1 &&
                   !slot1_valid_o &&
                   slot1_opcode_o == 7'd0 &&
                   slot1_funct3_o == 3'd0 &&
                   slot1_funct7_o == 7'd0 &&
                   slot1_op_19_15_o == 5'd0 &&
                   slot1_rs1_o == 5'd0 &&
                   slot1_rs2_o == 5'd0 &&
                   slot1_rd_o == 5'd0 &&
                   slot1_imm_o == 32'd0 &&
                   !slot1_is_branch_o &&
                   !slot1_is_jal_o &&
                   !slot1_is_jalr_o &&
                   !slot1_is_load_o &&
                   !slot1_is_store_o &&
                   !slot1_is_lui_o &&
                   !slot1_is_auipc_o &&
                   !slot1_unknown_inst_o &&
                   !slot1_wb_en_o &&
                   !slot1_uses_rs1_o &&
                   !slot1_uses_rs2_o &&
                   slot1_src_a_sel_o == 2'd0 &&
                   slot1_src_b_sel_o == 2'd0 &&
                   slot1_alu_op_o == 4'd0 &&
                   slot1_alu_result_o == 32'd0 &&
                   slot1_mem_size_o == 2'd0 &&
                   slot1_store_data_o == 32'd0 &&
                   !slot1_mem_lsu_o &&
                   !slot1_exception_o &&
                   slot1_excp_ecode_o == 6'd0 &&
                   slot1_excp_esubcode_o == 9'd0 &&
                   !slot1_excp_badv_valid_o &&
                   slot1_excp_badv_o == 32'd0 &&
                   !slot1_issue_valid_o &&
                   slot1_issue_class_o == 4'd0);
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_valid_packet();
        #1;
        `check("commit packet forwards valid sideband",
               slot1_pc_o == 32'h1c00_0104 &&
               instr1_o == 32'h0280_0042 &&
               slot1_valid_o &&
               slot1_opcode_o == 7'h2a &&
               slot1_funct3_o == 3'h5 &&
               slot1_funct7_o == 7'h55 &&
               slot1_op_19_15_o == 5'd19 &&
               slot1_rs1_o == 5'd3 &&
               slot1_rs2_o == 5'd4 &&
               slot1_rd_o == 5'd5 &&
               slot1_imm_o == 32'h1122_3344 &&
               slot1_is_branch_o &&
               slot1_is_jal_o &&
               slot1_is_jalr_o &&
               slot1_is_load_o &&
               !slot1_is_store_o &&
               slot1_is_lui_o &&
               slot1_is_auipc_o &&
               slot1_unknown_inst_o &&
               slot1_wb_en_o &&
               slot1_uses_rs1_o &&
               slot1_uses_rs2_o &&
               slot1_src_a_sel_o == 2'd2 &&
               slot1_src_b_sel_o == 2'd3 &&
               slot1_alu_op_o == 4'ha &&
               slot1_alu_result_o == 32'h5566_7788 &&
               slot1_mem_size_o == 2'd1 &&
               slot1_store_data_o == 32'd0 &&
               slot1_mem_lsu_o &&
               slot1_exception_o &&
               slot1_excp_ecode_o == 6'h12 &&
               slot1_excp_esubcode_o == 9'h155 &&
               slot1_excp_badv_valid_o &&
               slot1_excp_badv_o == 32'hdead_beef &&
               slot1_issue_valid_o &&
               slot1_issue_class_o == 4'b0100);

        drive_valid_packet();
        slot1_is_load = 1'b0;
        slot1_is_store = 1'b1;
        #1;
        `check("commit packet exposes store size and data only for store",
               slot1_mem_size_o == 2'd1 &&
               slot1_store_data_o == 32'haabb_ccdd &&
               slot1_mem_lsu_o);

        drive_valid_packet();
        slot1_is_load = 1'b0;
        slot1_is_store = 1'b0;
        slot1_issue_class = 4'b1000;
        #1;
        `check("commit packet clears mem size for non-memory",
               slot1_mem_size_o == 2'd0 &&
               slot1_store_data_o == 32'd0 &&
               !slot1_mem_lsu_o);

        drive_valid_packet();
        slot1_issue_class = 4'b1000;
        #1;
        `check("commit packet ignores memory payload without memory class",
               slot1_is_load_o &&
               !slot1_mem_lsu_o);

        drive_valid_packet();
        slot1_exception = 1'b0;
        #1;
        `check("commit packet clears exception code when no exception",
               !slot1_exception_o &&
               slot1_excp_ecode_o == 6'd0 &&
               slot1_excp_esubcode_o == 9'd0);

        drive_valid_packet();
        slot1_excp_badv_valid = 1'b0;
        #1;
        `check("commit packet clears badv payload when badv invalid",
               !slot1_excp_badv_valid_o &&
               slot1_excp_badv_o == 32'd0);

        drive_valid_packet();
        slot1_issue_valid = 1'b0;
        #1;
        `check("commit packet gates issue valid with slot valid",
               !slot1_issue_valid_o &&
               slot1_valid_o &&
               !slot1_mem_lsu_o &&
               slot1_issue_class_o == 4'd0);

        drive_valid_packet();
        slot1_valid = 1'b0;
        check_zeroed_sideband("commit packet zeroes sideband when invalid");

        finish_tb();
    end
endmodule

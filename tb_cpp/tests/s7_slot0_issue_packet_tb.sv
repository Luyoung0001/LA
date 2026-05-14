`timescale 1ns / 1ps

module s7_slot0_issue_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] pc;
    logic [31:0] instr;
    logic [1:0]  epoch;
    logic        pred_taken;
    logic [31:0] pred_target;
    logic        fault;
    logic [5:0]  fault_ecode;
    logic [31:0] fault_badv;
    logic [4:0]  rd;
    logic [31:0] imm;
    logic        wb_en;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic        is_load;
    logic        is_store;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic [3:0]  alu_op;
    logic [2:0]  branch_op;
    logic [31:0] op_a;
    logic [31:0] op_b;
    logic [31:0] rs1_val;
    logic [31:0] rs2_val;
    logic        op_a_late_s10;
    logic        op_b_late_s10;
    logic        rs1_late_s10;
    logic        rs2_late_s10;
    logic [4:0]  late_s10_rd;
    logic        unknown_inst;

    logic [31:0] pc_o;
    logic [31:0] instr_o;
    logic [1:0]  epoch_o;
    logic        pred_taken_o;
    logic [31:0] pred_target_o;
    logic        fault_o;
    logic [5:0]  fault_ecode_o;
    logic [31:0] fault_badv_o;
    logic [4:0]  rd_o;
    logic [31:0] imm_o;
    logic        wb_en_o;
    logic        is_branch_o;
    logic        is_jal_o;
    logic        is_jalr_o;
    logic        is_load_o;
    logic        is_store_o;
    logic [1:0]  mem_size_o;
    logic        mem_sign_ext_o;
    logic [3:0]  alu_op_o;
    logic [2:0]  branch_op_o;
    logic [31:0] op_a_o;
    logic [31:0] op_b_o;
    logic [31:0] rs1_val_o;
    logic [31:0] rs2_val_o;
    logic        op_a_late_s10_o;
    logic        op_b_late_s10_o;
    logic        rs1_late_s10_o;
    logic        rs2_late_s10_o;
    logic [4:0]  late_s10_rd_o;
    logic        unknown_inst_o;

    s7_slot0_issue_packet #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .pc_i(pc),
        .instr_i(instr),
        .epoch_i(epoch),
        .pred_taken_i(pred_taken),
        .pred_target_i(pred_target),
        .fault_i(fault),
        .fault_ecode_i(fault_ecode),
        .fault_badv_i(fault_badv),
        .rd_i(rd),
        .imm_i(imm),
        .wb_en_i(wb_en),
        .is_branch_i(is_branch),
        .is_jal_i(is_jal),
        .is_jalr_i(is_jalr),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .mem_size_i(mem_size),
        .mem_sign_ext_i(mem_sign_ext),
        .alu_op_i(alu_op),
        .branch_op_i(branch_op),
        .op_a_i(op_a),
        .op_b_i(op_b),
        .rs1_val_i(rs1_val),
        .rs2_val_i(rs2_val),
        .op_a_late_s10_i(op_a_late_s10),
        .op_b_late_s10_i(op_b_late_s10),
        .rs1_late_s10_i(rs1_late_s10),
        .rs2_late_s10_i(rs2_late_s10),
        .late_s10_rd_i(late_s10_rd),
        .unknown_inst_i(unknown_inst),
        .pc_o(pc_o),
        .instr_o(instr_o),
        .epoch_o(epoch_o),
        .pred_taken_o(pred_taken_o),
        .pred_target_o(pred_target_o),
        .fault_o(fault_o),
        .fault_ecode_o(fault_ecode_o),
        .fault_badv_o(fault_badv_o),
        .rd_o(rd_o),
        .imm_o(imm_o),
        .wb_en_o(wb_en_o),
        .is_branch_o(is_branch_o),
        .is_jal_o(is_jal_o),
        .is_jalr_o(is_jalr_o),
        .is_load_o(is_load_o),
        .is_store_o(is_store_o),
        .mem_size_o(mem_size_o),
        .mem_sign_ext_o(mem_sign_ext_o),
        .alu_op_o(alu_op_o),
        .branch_op_o(branch_op_o),
        .op_a_o(op_a_o),
        .op_b_o(op_b_o),
        .rs1_val_o(rs1_val_o),
        .rs2_val_o(rs2_val_o),
        .op_a_late_s10_o(op_a_late_s10_o),
        .op_b_late_s10_o(op_b_late_s10_o),
        .rs1_late_s10_o(rs1_late_s10_o),
        .rs2_late_s10_o(rs2_late_s10_o),
        .late_s10_rd_o(late_s10_rd_o),
        .unknown_inst_o(unknown_inst_o)
    );

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        pc = 32'h1c00_5000;
        instr = 32'h0280_0463;
        epoch = 2'd2;
        pred_taken = 1'b1;
        pred_target = 32'h1c00_5080;
        fault = 1'b1;
        fault_ecode = 6'h3f;
        fault_badv = 32'hbad0_0004;
        rd = 5'd3;
        imm = 32'h0000_0040;
        wb_en = 1'b1;
        is_branch = 1'b0;
        is_jal = 1'b0;
        is_jalr = 1'b0;
        is_load = 1'b1;
        is_store = 1'b0;
        mem_size = 2'd2;
        mem_sign_ext = 1'b1;
        alu_op = 4'h0;
        branch_op = 3'h1;
        op_a = 32'h1111_2222;
        op_b = 32'h3333_4444;
        rs1_val = 32'haaaa_0001;
        rs2_val = 32'hbbbb_0002;
        op_a_late_s10 = 1'b1;
        op_b_late_s10 = 1'b0;
        rs1_late_s10 = 1'b1;
        rs2_late_s10 = 1'b0;
        late_s10_rd = 5'd9;
        unknown_inst = 1'b0;
        #1;

        `check32("PKT pc pass", pc_o, 32'h1c00_5000);
        `check32("PKT instr pass", instr_o, 32'h0280_0463);
        `check32("PKT epoch pass", {30'd0, epoch_o}, 32'd2);
        `check("PKT prediction pass", pred_taken_o && pred_target_o == 32'h1c00_5080);
        `check("PKT fault pass", fault_o && fault_ecode_o == 6'h3f && fault_badv_o == 32'hbad0_0004);
        `check("PKT load sideband pass", wb_en_o && is_load_o && !is_store_o);
        `check32("PKT rd pass", {27'd0, rd_o}, 32'd3);
        `check32("PKT imm pass", imm_o, 32'h0000_0040);
        `check32("PKT mem bundle pass", {29'd0, mem_sign_ext_o, mem_size_o}, {29'd0, 1'b1, 2'd2});
        `check32("PKT alu branch ops pass", {25'd0, alu_op_o, branch_op_o}, {25'd0, 4'h0, 3'h1});
        `check32("PKT op A pass", op_a_o, 32'h1111_2222);
        `check32("PKT op B pass", op_b_o, 32'h3333_4444);
        `check32("PKT rs1 value pass", rs1_val_o, 32'haaaa_0001);
        `check32("PKT rs2 value pass", rs2_val_o, 32'hbbbb_0002);
        `check("PKT late S10 token pass",
               op_a_late_s10_o && !op_b_late_s10_o && rs1_late_s10_o &&
               !rs2_late_s10_o && late_s10_rd_o == 5'd9);

        is_load = 1'b0;
        is_store = 1'b1;
        is_branch = 1'b1;
        is_jal = 1'b1;
        is_jalr = 1'b1;
        unknown_inst = 1'b1;
        op_a_late_s10 = 1'b0;
        op_b_late_s10 = 1'b1;
        rs1_late_s10 = 1'b0;
        rs2_late_s10 = 1'b1;
        late_s10_rd = 5'd12;
        #1;

        `check("PKT control sideband pass",
               is_store_o && is_branch_o && is_jal_o && is_jalr_o && unknown_inst_o);
        `check("PKT late S10 token can move to operand B",
               !op_a_late_s10_o && op_b_late_s10_o && !rs1_late_s10_o &&
               rs2_late_s10_o && late_s10_rd_o == 5'd12);

        finish_tb();
    end
endmodule

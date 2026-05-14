`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s8_slot1_exec_class_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        slot1_valid;
    logic        slot1_issue_valid;
    logic [6:0]  slot1_opcode;
    logic [2:0]  slot1_funct3;
    logic [6:0]  slot1_funct7;
    logic [4:0]  slot1_op_19_15;
    logic [4:0]  slot1_rd;
    logic [4:0]  slot1_rs1;
    logic [31:0] slot1_imm;
    logic        slot1_is_branch;
    logic        slot1_is_jal;
    logic        slot1_is_jalr;
    logic        slot1_unknown_inst;

    logic        slot1_inst_mul_w;
    logic        slot1_inst_mulh_w;
    logic        slot1_inst_mulh_wu;
    logic        slot1_inst_mul_op;
    logic [1:0]  slot1_mem_size;
    logic [2:0]  slot1_branch_op;
    logic        slot1_cond_branch;
    logic        slot1_uncond_b;
    logic        slot1_uncond_bl;
    logic        slot1_uncond_jirl;
    logic        slot1_ret;
    logic        slot1_indirect_jirl;
    logic        slot1_ctrl_flow;

    s8_slot1_exec_class u_dut (
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_opcode_i(slot1_opcode),
        .slot1_funct3_i(slot1_funct3),
        .slot1_funct7_i(slot1_funct7),
        .slot1_op_19_15_i(slot1_op_19_15),
        .slot1_rd_i(slot1_rd),
        .slot1_rs1_i(slot1_rs1),
        .slot1_imm_i(slot1_imm),
        .slot1_is_branch_i(slot1_is_branch),
        .slot1_is_jal_i(slot1_is_jal),
        .slot1_is_jalr_i(slot1_is_jalr),
        .slot1_unknown_inst_i(slot1_unknown_inst),
        .slot1_inst_mul_w_o(slot1_inst_mul_w),
        .slot1_inst_mulh_w_o(slot1_inst_mulh_w),
        .slot1_inst_mulh_wu_o(slot1_inst_mulh_wu),
        .slot1_inst_mul_op_o(slot1_inst_mul_op),
        .slot1_mem_size_o(slot1_mem_size),
        .slot1_branch_op_o(slot1_branch_op),
        .slot1_cond_branch_o(slot1_cond_branch),
        .slot1_uncond_b_o(slot1_uncond_b),
        .slot1_uncond_bl_o(slot1_uncond_bl),
        .slot1_uncond_jirl_o(slot1_uncond_jirl),
        .slot1_ret_o(slot1_ret),
        .slot1_indirect_jirl_o(slot1_indirect_jirl),
        .slot1_ctrl_flow_o(slot1_ctrl_flow)
    );

    task automatic clear_inputs;
        begin
            slot1_valid = 1'b1;
            slot1_issue_valid = 1'b1;
            slot1_opcode = 7'd0;
            slot1_funct3 = 3'd0;
            slot1_funct7 = 7'd0;
            slot1_op_19_15 = 5'd0;
            slot1_rd = 5'd0;
            slot1_rs1 = 5'd0;
            slot1_imm = 32'd0;
            slot1_is_branch = 1'b0;
            slot1_is_jal = 1'b0;
            slot1_is_jalr = 1'b0;
            slot1_unknown_inst = 1'b0;
        end
    endtask

    task automatic check_mul(
        input [4:0] op_19_15,
        input logic exp_mul,
        input logic exp_mulh,
        input logic exp_mulhu
    );
        begin
            clear_inputs();
            slot1_opcode = 7'h00;
            slot1_funct7 = 7'h00;
            slot1_funct3 = 3'h1;
            slot1_op_19_15 = op_19_15;
            #1;
            `check("S8 slot1 mul.w class", slot1_inst_mul_w == exp_mul);
            `check("S8 slot1 mulh.w class", slot1_inst_mulh_w == exp_mulh);
            `check("S8 slot1 mulh.wu class", slot1_inst_mulh_wu == exp_mulhu);
            `check("S8 slot1 mul op aggregate",
                   slot1_inst_mul_op == (exp_mul || exp_mulh || exp_mulhu));
        end
    endtask

    task automatic check_mem_size(
        input [3:0] funct7_low,
        input [1:0] exp_size
    );
        begin
            clear_inputs();
            slot1_opcode = 7'h0a;
            slot1_funct7 = {3'd0, funct7_low};
            #1;
            `check32("S8 slot1 mem size", {30'd0, slot1_mem_size},
                     {30'd0, exp_size});
        end
    endtask

    task automatic drive_cond_branch(
        input [5:0] opcode_low,
        input [2:0] exp_branch_op
    );
        begin
            clear_inputs();
            slot1_opcode = {1'b0, opcode_low};
            slot1_is_branch = 1'b1;
            #1;
            `check("S8 slot1 cond branch class",
                   slot1_cond_branch && slot1_ctrl_flow);
            `check32("S8 slot1 branch op", {29'd0, slot1_branch_op},
                     {29'd0, exp_branch_op});
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        check_mul(5'h18, 1'b1, 1'b0, 1'b0);
        check_mul(5'h19, 1'b0, 1'b1, 1'b0);
        check_mul(5'h1a, 1'b0, 1'b0, 1'b1);
        check_mul(5'h1b, 1'b0, 1'b0, 1'b0);

        check_mem_size(4'h0, 2'b00);
        check_mem_size(4'h4, 2'b00);
        check_mem_size(4'h8, 2'b00);
        check_mem_size(4'h1, 2'b01);
        check_mem_size(4'h5, 2'b01);
        check_mem_size(4'h9, 2'b01);
        check_mem_size(4'h2, 2'b10);

        drive_cond_branch(6'h16, `CPU_BR_EQ);
        drive_cond_branch(6'h17, `CPU_BR_NE);
        drive_cond_branch(6'h18, `CPU_BR_LT);
        drive_cond_branch(6'h19, `CPU_BR_GE);
        drive_cond_branch(6'h1a, `CPU_BR_LTU);
        drive_cond_branch(6'h1b, `CPU_BR_GEU);

        clear_inputs();
        slot1_opcode = 7'h14;
        slot1_is_jal = 1'b1;
        #1;
        `check("S8 slot1 B class",
               slot1_uncond_b && !slot1_uncond_bl && !slot1_uncond_jirl &&
               slot1_ctrl_flow);

        clear_inputs();
        slot1_opcode = 7'h15;
        slot1_is_jal = 1'b1;
        #1;
        `check("S8 slot1 BL class",
               !slot1_uncond_b && slot1_uncond_bl && !slot1_uncond_jirl &&
               slot1_ctrl_flow);

        clear_inputs();
        slot1_opcode = 7'h13;
        slot1_is_jalr = 1'b1;
        slot1_rd = 5'd0;
        slot1_rs1 = 5'd1;
        slot1_imm = 32'd0;
        #1;
        `check("S8 slot1 RET class",
               slot1_uncond_jirl && slot1_ret && !slot1_indirect_jirl &&
               slot1_ctrl_flow);

        clear_inputs();
        slot1_opcode = 7'h13;
        slot1_is_jalr = 1'b1;
        slot1_rd = 5'd1;
        slot1_rs1 = 5'd5;
        slot1_imm = 32'h20;
        #1;
        `check("S8 slot1 indirect JIRL class",
               slot1_uncond_jirl && !slot1_ret && slot1_indirect_jirl &&
               slot1_ctrl_flow);

        clear_inputs();
        slot1_valid = 1'b0;
        slot1_opcode = 7'h16;
        slot1_is_branch = 1'b1;
        #1;
        `check("S8 slot1 invalid gates control flow", !slot1_ctrl_flow);

        clear_inputs();
        slot1_issue_valid = 1'b0;
        slot1_opcode = 7'h15;
        slot1_is_jal = 1'b1;
        #1;
        `check("S8 slot1 not issued gates control flow", !slot1_ctrl_flow);

        clear_inputs();
        slot1_unknown_inst = 1'b1;
        slot1_opcode = 7'h13;
        slot1_is_jalr = 1'b1;
        #1;
        `check("S8 slot1 unknown gates control flow", !slot1_ctrl_flow);

        finish_tb();
    end
endmodule

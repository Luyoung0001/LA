`timescale 1ns / 1ps
`include "cpu_defs.vh"

module backend_branch_resolve_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] pc;
    logic [31:0] imm;
    logic        pred_taken;
    logic [31:0] pred_target;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic [2:0]  branch_op;
    logic [31:0] rs1_val;
    logic [31:0] rs2_val;

    logic        branch_taken;
    logic        jump_taken;
    logic        control_flow;
    logic        actual_taken;
    logic [31:0] branch_target;
    logic [31:0] jump_target;
    logic [31:0] seq_next_pc;
    logic [31:0] actual_target;
    logic [31:0] predicted_next_pc;
    logic        pred_target_miss;
    logic        redirect;

    backend_branch_resolve u_dut (
        .pc_i(pc),
        .imm_i(imm),
        .pred_taken_i(pred_taken),
        .pred_target_i(pred_target),
        .is_branch_i(is_branch),
        .is_jal_i(is_jal),
        .is_jalr_i(is_jalr),
        .branch_op_i(branch_op),
        .rs1_val_i(rs1_val),
        .rs2_val_i(rs2_val),
        .branch_taken_o(branch_taken),
        .jump_taken_o(jump_taken),
        .control_flow_o(control_flow),
        .actual_taken_o(actual_taken),
        .branch_target_o(branch_target),
        .jump_target_o(jump_target),
        .seq_next_pc_o(seq_next_pc),
        .actual_target_o(actual_target),
        .predicted_next_pc_o(predicted_next_pc),
        .pred_target_miss_o(pred_target_miss),
        .redirect_o(redirect)
    );

    task automatic drive_base;
        begin
            pc = 32'h1c00_1000;
            imm = 32'h0000_0020;
            pred_taken = 1'b0;
            pred_target = 32'h0;
            is_branch = 1'b0;
            is_jal = 1'b0;
            is_jalr = 1'b0;
            branch_op = `CPU_BR_EQ;
            rs1_val = 32'h0;
            rs2_val = 32'h0;
            #1;
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        drive_base();

        `check("BR idle is not control flow", !control_flow && !actual_taken && !redirect);
        `check32("BR idle seq next PC", seq_next_pc, 32'h1c00_1004);

        is_branch = 1'b1;
        branch_op = `CPU_BR_EQ;
        rs1_val = 32'h55aa_0001;
        rs2_val = 32'h55aa_0001;
        #1;
        `check("BR beq taken", branch_taken && actual_taken && control_flow);
        `check32("BR taken target", actual_target, 32'h1c00_1020);
        `check("BR predicted not taken redirects", redirect);

        pred_taken = 1'b1;
        pred_target = 32'h1c00_1020;
        #1;
        `check("BR correct taken prediction does not redirect", !redirect && !pred_target_miss);

        pred_target = 32'h1c00_1040;
        #1;
        `check("BR taken wrong target redirects", redirect && pred_target_miss);

        pred_taken = 1'b0;
        pred_target = 32'h0;
        branch_op = `CPU_BR_NE;
        #1;
        `check("BR bne not taken", !branch_taken && !actual_taken);
        `check32("BR not-taken target is seq", actual_target, 32'h1c00_1004);
        `check("BR correct not-taken prediction does not redirect", !redirect);

        branch_op = `CPU_BR_LT;
        rs1_val = 32'hffff_fffe;
        rs2_val = 32'h0000_0001;
        #1;
        `check("BR signed lt handles negative", branch_taken && redirect);

        branch_op = `CPU_BR_LTU;
        #1;
        `check("BR unsigned lt handles same operands as not-taken", !branch_taken && !redirect);

        drive_base();
        is_jal = 1'b1;
        pred_taken = 1'b0;
        #1;
        `check("BR jal is taken jump", jump_taken && actual_taken && control_flow);
        `check32("BR jal target is pc plus imm", actual_target, 32'h1c00_1020);
        `check("BR jal predicted not taken redirects", redirect);

        pred_taken = 1'b1;
        pred_target = 32'h1c00_1020;
        #1;
        `check("BR jal correct target does not redirect", !redirect);

        drive_base();
        is_jalr = 1'b1;
        rs1_val = 32'h1c00_2000;
        imm = 32'h0000_0010;
        pred_taken = 1'b1;
        pred_target = 32'h1c00_2010;
        #1;
        `check("BR jirl is taken jump", jump_taken && actual_taken && control_flow);
        `check32("BR jirl target is rs1 plus imm", jump_target, 32'h1c00_2010);
        `check("BR jirl correct target does not redirect", !redirect);

        finish_tb();
    end
endmodule

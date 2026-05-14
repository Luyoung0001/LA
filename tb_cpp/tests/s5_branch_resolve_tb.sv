`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s5_branch_resolve_tb;
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
    logic [2:0]  branch_op;
    logic [31:0] rs1_val;
    logic [31:0] rs2_val;
    logic        uses_rs1;
    logic        uses_rs2;
    logic        rs1_ready;
    logic        rs2_ready;
    logic        rs1_hold_valid;
    logic        rs2_hold_valid;
    logic        promoted_slot1;

    logic        branch_taken;
    logic [31:0] branch_target;
    logic [31:0] seq_next_pc;
    logic [31:0] actual_target;
    logic [31:0] predicted_next_pc;
    logic        mismatch;
    logic        can_early_redirect;
    logic        operands_ready;

    s5_branch_resolve u_dut (
        .pc_i(pc),
        .imm_i(imm),
        .pred_taken_i(pred_taken),
        .pred_target_i(pred_target),
        .is_branch_i(is_branch),
        .branch_op_i(branch_op),
        .rs1_val_i(rs1_val),
        .rs2_val_i(rs2_val),
        .uses_rs1_i(uses_rs1),
        .uses_rs2_i(uses_rs2),
        .rs1_ready_i(rs1_ready),
        .rs2_ready_i(rs2_ready),
        .rs1_hold_valid_i(rs1_hold_valid),
        .rs2_hold_valid_i(rs2_hold_valid),
        .promoted_slot1_i(promoted_slot1),
        .branch_taken_o(branch_taken),
        .branch_target_o(branch_target),
        .seq_next_pc_o(seq_next_pc),
        .actual_target_o(actual_target),
        .predicted_next_pc_o(predicted_next_pc),
        .mismatch_o(mismatch),
        .can_early_redirect_o(can_early_redirect),
        .operands_ready_o(operands_ready)
    );

    task automatic drive_base;
        begin
            pc = 32'h1c00_2000;
            imm = 32'h0000_0010;
            pred_taken = 1'b0;
            pred_target = 32'h0;
            is_branch = 1'b1;
            branch_op = `CPU_BR_EQ;
            rs1_val = 32'h0;
            rs2_val = 32'h0;
            uses_rs1 = 1'b1;
            uses_rs2 = 1'b1;
            rs1_ready = 1'b1;
            rs2_ready = 1'b1;
            rs1_hold_valid = 1'b0;
            rs2_hold_valid = 1'b0;
            promoted_slot1 = 1'b0;
            #1;
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        drive_base();

        `check("S5BR beq taken", branch_taken);
        `check32("S5BR taken target", actual_target, 32'h1c00_2010);
        `check32("S5BR seq next", seq_next_pc, 32'h1c00_2004);
        `check("S5BR predicted not taken mismatches", mismatch);
        `check("S5BR normal branch can early redirect", can_early_redirect);

        pred_taken = 1'b1;
        pred_target = 32'h1c00_2010;
        #1;
        `check("S5BR correct taken prediction matches", !mismatch);

        branch_op = `CPU_BR_NE;
        #1;
        `check("S5BR bne not taken", !branch_taken);
        `check32("S5BR not-taken actual target", actual_target, 32'h1c00_2004);
        `check("S5BR predicted taken on not-taken mismatches", mismatch);

        pred_taken = 1'b0;
        branch_op = `CPU_BR_LT;
        rs1_val = 32'hffff_fffe;
        rs2_val = 32'h0000_0001;
        #1;
        `check("S5BR signed lt handles negative", branch_taken && mismatch);

        branch_op = `CPU_BR_LTU;
        #1;
        `check("S5BR unsigned ltu sees same operands not taken", !branch_taken && !mismatch);

        rs1_ready = 1'b0;
        #1;
        `check("S5BR waits when used rs1 is neither ready nor held", !operands_ready);

        rs1_hold_valid = 1'b1;
        #1;
        `check("S5BR held rs1 counts as ready", operands_ready);

        promoted_slot1 = 1'b1;
        #1;
        `check("S5BR promoted slot1 cannot early redirect", !can_early_redirect);

        is_branch = 1'b0;
        uses_rs1 = 1'b0;
        uses_rs2 = 1'b0;
        rs1_ready = 1'b0;
        rs2_ready = 1'b0;
        rs1_hold_valid = 1'b0;
        rs2_hold_valid = 1'b0;
        #1;
        `check("S5BR non-branch is not taken", !branch_taken && !can_early_redirect);
        `check("S5BR unused operands are ready", operands_ready);

        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module s10_commit_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        slot0_commit_valid;
    logic [31:0] slot0_commit_pc;
    logic [31:0] slot0_commit_instr;
    logic        slot0_exception;
    logic        slot0_refetch;
    logic        slot1_refetch;
    logic        slot1_valid;
    logic        slot1_issue_valid;
    logic [31:0] slot1_commit_pc;
    logic [31:0] slot1_commit_instr;
    logic        dual_commit_enable;
    logic        commit0_valid;
    logic [31:0] commit0_pc;
    logic [31:0] commit0_instr;
    logic        commit1_valid;
    logic        commit1_accept;
    logic [31:0] commit1_pc;
    logic [31:0] commit1_instr;
    logic        dual_commit;
    logic [3:0]  commit_select_reason;

    s10_commit_select u_dut (
        .slot0_commit_valid_i(slot0_commit_valid),
        .slot0_commit_pc_i(slot0_commit_pc),
        .slot0_commit_instr_i(slot0_commit_instr),
        .slot0_exception_i(slot0_exception),
        .slot0_refetch_i(slot0_refetch),
        .slot1_refetch_i(slot1_refetch),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_commit_pc_i(slot1_commit_pc),
        .slot1_commit_instr_i(slot1_commit_instr),
        .dual_commit_enable_i(dual_commit_enable),
        .commit0_valid_o(commit0_valid),
        .commit0_pc_o(commit0_pc),
        .commit0_instr_o(commit0_instr),
        .commit1_valid_o(commit1_valid),
        .commit1_accept_o(commit1_accept),
        .commit1_pc_o(commit1_pc),
        .commit1_instr_o(commit1_instr),
        .dual_commit_o(dual_commit),
        .commit_select_reason_o(commit_select_reason)
    );

    task automatic clear_inputs;
        begin
            slot0_commit_valid = 1'b0;
            slot0_commit_pc = 32'd0;
            slot0_commit_instr = 32'd0;
            slot0_exception = 1'b0;
            slot0_refetch = 1'b0;
            slot1_refetch = 1'b0;
            slot1_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_commit_pc = 32'd0;
            slot1_commit_instr = 32'd0;
            dual_commit_enable = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("CSEL idle commits nothing", !commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL idle clears commit0 pc", commit0_pc, 32'd0);
        `check32("CSEL idle clears commit1 pc", commit1_pc, 32'd0);
        `check32("CSEL idle reason clear", {28'd0, commit_select_reason}, 32'd0);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_1000;
        slot0_commit_instr = 32'h0280_0084;
        #1;
        `check("CSEL slot0 commit passes", commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL slot0 pc", commit0_pc, 32'h1c00_1000);
        `check32("CSEL slot0 instr", commit0_instr, 32'h0280_0084);
        `check32("CSEL slot0-only reason", {28'd0, commit_select_reason}, 32'h1);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_2000;
        slot0_commit_instr = 32'h0280_00a5;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_commit_pc = 32'h1c00_2004;
        slot1_commit_instr = 32'h0280_00c6;
        #1;
        `check("CSEL phase1 holds slot1 commit candidate",
               commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL phase1 clears commit1 pc", commit1_pc, 32'd0);
        `check32("CSEL phase1 clears commit1 instr", commit1_instr, 32'd0);
        `check32("CSEL phase1 reason marks held candidate",
                 {28'd0, commit_select_reason}, 32'h7);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_3000;
        slot0_commit_instr = 32'h0280_00e7;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_commit_pc = 32'h1c00_3004;
        slot1_commit_instr = 32'h0280_0108;
        dual_commit_enable = 1'b1;
        #1;
        `check("CSEL dual-enable commits both", commit0_valid && commit1_valid && commit1_accept && dual_commit);
        `check32("CSEL dual commit1 pc", commit1_pc, 32'h1c00_3004);
        `check32("CSEL dual commit1 instr", commit1_instr, 32'h0280_0108);
        `check32("CSEL dual reason", {28'd0, commit_select_reason}, 32'h3);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_3800;
        slot0_commit_instr = 32'h0280_0201;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        slot1_commit_pc = 32'h1c00_3804;
        slot1_commit_instr = 32'h0280_0222;
        dual_commit_enable = 1'b1;
        #1;
        `check("CSEL unissued slot1 sideband cannot commit",
               commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL unissued slot1 clears commit1 pc", commit1_pc, 32'd0);
        `check32("CSEL unissued slot1 has slot0-only reason",
                 {28'd0, commit_select_reason}, 32'h1);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_3900;
        slot0_commit_instr = 32'h0280_0243;
        slot0_exception = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        slot1_commit_pc = 32'h1c00_3904;
        slot1_commit_instr = 32'h0280_0264;
        dual_commit_enable = 1'b1;
        #1;
        `check("CSEL unissued slot1 is not a blocked younger commit",
               commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL unissued slot1 exception reason stays slot0-only",
                 {28'd0, commit_select_reason}, 32'h1);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_4000;
        slot0_commit_instr = 32'h0280_0129;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_commit_pc = 32'h1c00_4004;
        slot1_commit_instr = 32'h0280_014a;
        slot0_exception = 1'b1;
        dual_commit_enable = 1'b1;
        #1;
        `check("CSEL exception blocks younger commit",
               commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL exception reason", {28'd0, commit_select_reason}, 32'h9);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_5000;
        slot0_commit_instr = 32'h0280_016b;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_commit_pc = 32'h1c00_5004;
        slot1_commit_instr = 32'h0280_018c;
        slot0_refetch = 1'b1;
        dual_commit_enable = 1'b1;
        #1;
        `check("CSEL refetch blocks younger commit",
               commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL refetch clears commit1 pc", commit1_pc, 32'd0);
        `check32("CSEL refetch reason", {28'd0, commit_select_reason}, 32'h9);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_commit_pc = 32'h1c00_5800;
        slot0_commit_instr = 32'h0280_01a1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_commit_pc = 32'h1c00_5804;
        slot1_commit_instr = 32'h2880_01c2;
        slot1_refetch = 1'b1;
        dual_commit_enable = 1'b1;
        #1;
        `check("CSEL slot1 refetch blocks only younger commit",
               commit0_valid && !commit1_valid && !commit1_accept && !dual_commit);
        `check32("CSEL slot1 refetch keeps slot0 pc", commit0_pc, 32'h1c00_5800);
        `check32("CSEL slot1 refetch clears commit1 pc", commit1_pc, 32'd0);
        `check32("CSEL slot1 refetch reason", {28'd0, commit_select_reason}, 32'h9);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_commit_pc = 32'h1c00_6004;
        slot1_commit_instr = 32'h0280_01ad;
        dual_commit_enable = 1'b1;
        #1;
        `check("CSEL slot1 requires slot0 commit", !commit0_valid && !commit1_valid && !commit1_accept);
        `check32("CSEL no-slot0 reason clear", {28'd0, commit_select_reason}, 32'd0);

        finish_tb();
    end
endmodule

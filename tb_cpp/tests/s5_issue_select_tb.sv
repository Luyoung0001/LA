`timescale 1ns / 1ps

module s5_issue_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       slot0_valid;
    logic       policy_ready_go;
    logic       slot1_valid;
    logic       pair_legal;
    logic       slot1_ready;
    logic       dual_issue_enable;
    logic       issue_ready_go;
    logic       slot0_issue_valid;
    logic       slot1_issue_valid;
    logic       dual_issue;
    logic [4:0] issue_select_reason;

    s5_issue_select u_dut (
        .slot0_valid_i(slot0_valid),
        .policy_ready_go_i(policy_ready_go),
        .slot1_valid_i(slot1_valid),
        .pair_legal_i(pair_legal),
        .slot1_ready_i(slot1_ready),
        .dual_issue_enable_i(dual_issue_enable),
        .issue_ready_go_o(issue_ready_go),
        .slot0_issue_valid_o(slot0_issue_valid),
        .slot1_issue_valid_o(slot1_issue_valid),
        .dual_issue_o(dual_issue),
        .issue_select_reason_o(issue_select_reason)
    );

    task automatic clear_inputs;
        begin
            slot0_valid = 1'b0;
            policy_ready_go = 1'b1;
            slot1_valid = 1'b0;
            pair_legal = 1'b0;
            slot1_ready = 1'b1;
            dual_issue_enable = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("SEL idle keeps ready_go", issue_ready_go);
        `check("SEL idle issues nothing", !slot0_issue_valid && !slot1_issue_valid && !dual_issue);
        `check32("SEL idle reason clear", {27'd0, issue_select_reason}, 32'd0);

        clear_inputs();
        slot0_valid = 1'b1;
        policy_ready_go = 1'b0;
        #1;
        `check("SEL policy block stops slot0 issue", !issue_ready_go && !slot0_issue_valid);
        `check32("SEL policy block reason", {27'd0, issue_select_reason}, 32'h1);

        clear_inputs();
        slot0_valid = 1'b1;
        #1;
        `check("SEL slot0 issues alone when no slot1", issue_ready_go && slot0_issue_valid && !slot1_issue_valid);
        `check32("SEL no-slot1 reason", {27'd0, issue_select_reason}, 32'h2);

        clear_inputs();
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        pair_legal = 1'b1;
        #1;
        `check("SEL legal slot1 still stays single-issue in phase1", slot0_issue_valid && !slot1_issue_valid && !dual_issue);
        `check32("SEL phase-disabled reason", {27'd0, issue_select_reason}, 32'h4);

        clear_inputs();
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        pair_legal = 1'b0;
        #1;
        `check("SEL pair block keeps slot1 off", slot0_issue_valid && !slot1_issue_valid && !dual_issue);
        `check32("SEL pair-block reason", {27'd0, issue_select_reason}, 32'h8);

        clear_inputs();
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        pair_legal = 1'b0;
        #1;
        `check("SEL pair block is reported even without pair subreason",
               slot0_issue_valid && !slot1_issue_valid && !dual_issue);
        `check32("SEL pair-block fallback reason", {27'd0, issue_select_reason}, 32'h8);

        clear_inputs();
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        pair_legal = 1'b1;
        slot1_ready = 1'b0;
        #1;
        `check("SEL scoreboard block keeps slot1 off", slot0_issue_valid && !slot1_issue_valid && !dual_issue);
        `check32("SEL scoreboard-block reason", {27'd0, issue_select_reason}, 32'h8);

        clear_inputs();
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        pair_legal = 1'b1;
        slot1_ready = 1'b0;
        #1;
        `check("SEL scoreboard block is reported even without score subreason",
               slot0_issue_valid && !slot1_issue_valid && !dual_issue);
        `check32("SEL scoreboard-block fallback reason", {27'd0, issue_select_reason}, 32'h8);

        clear_inputs();
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        pair_legal = 1'b1;
        slot1_ready = 1'b0;
        dual_issue_enable = 1'b1;
        #1;
        `check("SEL dual-enable still honors slot1 scoreboard", slot0_issue_valid && !slot1_issue_valid && !dual_issue);
        `check32("SEL dual-enable scoreboard block reason", {27'd0, issue_select_reason}, 32'h8);

        clear_inputs();
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        pair_legal = 1'b1;
        dual_issue_enable = 1'b1;
        #1;
        `check("SEL dual-enable emits both slots", slot0_issue_valid && slot1_issue_valid && dual_issue);
        `check32("SEL dual-issued reason", {27'd0, issue_select_reason}, 32'h10);

        finish_tb();
    end
endmodule

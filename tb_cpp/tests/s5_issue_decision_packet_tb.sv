`timescale 1ns / 1ps

module s5_issue_decision_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       issue_ready_go;
    logic       slot0_issue_valid;
    logic       slot1_issue_valid;
    logic       dual_issue;
    logic [4:0] issue_select_reason;
    logic       pair_legal;
    logic       slot1_ready;
    logic [4:0] pair_block_reason;
    logic [2:0] slot1_block_reason;

    logic       issue_ready_go_o;
    logic       slot0_issue_valid_o;
    logic       slot1_issue_valid_o;
    logic       dual_issue_o;
    logic [4:0] issue_select_reason_o;
    logic       pair_legal_o;
    logic       slot1_ready_o;
    logic [4:0] pair_block_reason_o;
    logic [2:0] slot1_block_reason_o;

    s5_issue_decision_packet u_dut (
        .issue_ready_go_i(issue_ready_go),
        .slot0_issue_valid_i(slot0_issue_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .dual_issue_i(dual_issue),
        .issue_select_reason_i(issue_select_reason),
        .pair_legal_i(pair_legal),
        .slot1_ready_i(slot1_ready),
        .pair_block_reason_i(pair_block_reason),
        .slot1_block_reason_i(slot1_block_reason),
        .issue_ready_go_o(issue_ready_go_o),
        .slot0_issue_valid_o(slot0_issue_valid_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .dual_issue_o(dual_issue_o),
        .issue_select_reason_o(issue_select_reason_o),
        .pair_legal_o(pair_legal_o),
        .slot1_ready_o(slot1_ready_o),
        .pair_block_reason_o(pair_block_reason_o),
        .slot1_block_reason_o(slot1_block_reason_o)
    );

    task automatic clear_inputs;
        begin
            issue_ready_go = 1'b0;
            slot0_issue_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            dual_issue = 1'b0;
            issue_select_reason = 5'd0;
            pair_legal = 1'b0;
            slot1_ready = 1'b0;
            pair_block_reason = 5'd0;
            slot1_block_reason = 3'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("DECISION idle clears issue decisions",
               !issue_ready_go_o && !slot0_issue_valid_o &&
               !slot1_issue_valid_o && !dual_issue_o);
        `check32("DECISION idle diagnostics clear",
                 {19'd0, issue_select_reason_o, pair_block_reason_o, slot1_block_reason_o},
                 32'd0);
        `check("DECISION idle pair status clear", !pair_legal_o && !slot1_ready_o);

        clear_inputs();
        issue_ready_go = 1'b1;
        slot0_issue_valid = 1'b1;
        issue_select_reason = 5'h02;
        pair_legal = 1'b1;
        slot1_ready = 1'b0;
        pair_block_reason = 5'h11;
        slot1_block_reason = 3'h5;
        #1;
        `check("DECISION single issue forwards slot0",
               issue_ready_go_o && slot0_issue_valid_o &&
               !slot1_issue_valid_o && !dual_issue_o);
        `check("DECISION pair readiness forwards independently",
               pair_legal_o && !slot1_ready_o);
        `check32("DECISION single issue diagnostics",
                 {19'd0, issue_select_reason_o, pair_block_reason_o, slot1_block_reason_o},
                 {19'd0, 5'h02, 5'h11, 3'h5});

        clear_inputs();
        issue_ready_go = 1'b1;
        slot0_issue_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        dual_issue = 1'b1;
        issue_select_reason = 5'h10;
        pair_legal = 1'b1;
        slot1_ready = 1'b1;
        pair_block_reason = 5'h00;
        slot1_block_reason = 3'h0;
        #1;
        `check("DECISION dual issue forwards both slots",
               issue_ready_go_o && slot0_issue_valid_o &&
               slot1_issue_valid_o && dual_issue_o);
        `check("DECISION dual issue forwards ready pair",
               pair_legal_o && slot1_ready_o);
        `check32("DECISION dual issue diagnostics",
                 {19'd0, issue_select_reason_o, pair_block_reason_o, slot1_block_reason_o},
                 {19'd0, 5'h10, 5'h00, 3'h0});

        finish_tb();
    end
endmodule

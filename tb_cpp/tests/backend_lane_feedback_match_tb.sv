`timescale 1ns / 1ps

module backend_lane_feedback_match_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       c0_uses_rs1, c0_uses_rs2;
    logic [4:0] c0_rs1, c0_rs2;
    logic       c1_active, c1_uses_rs1, c1_uses_rs2;
    logic [4:0] c1_rs1, c1_rs2;
    logic       p0_match_valid, p0_wait_valid, p0_forward_ready;
    logic [4:0] p0_rd;
    logic       p1_match_valid, p1_wait_valid, p1_forward_ready;
    logic [4:0] p1_rd;

    logic c0_rs1_match_p0, c0_rs2_match_p0;
    logic c0_rs1_match_p1, c0_rs2_match_p1;
    logic c0_rs1_wait_p0, c0_rs2_wait_p0;
    logic c0_rs1_wait_p1, c0_rs2_wait_p1;
    logic c0_rs1_wait, c0_rs2_wait;
    logic c0_rs1_fwd_p0, c0_rs2_fwd_p0;
    logic c0_rs1_fwd_p1, c0_rs2_fwd_p1;
    logic c1_rs1_match_p0, c1_rs2_match_p0;
    logic c1_rs1_match_p1, c1_rs2_match_p1;
    logic c1_rs1_wait_p0, c1_rs2_wait_p0;
    logic c1_rs1_wait_p1, c1_rs2_wait_p1;
    logic c1_rs1_wait, c1_rs2_wait;
    logic c1_rs1_fwd_p0, c1_rs2_fwd_p0;
    logic c1_rs1_fwd_p1, c1_rs2_fwd_p1;

    backend_lane_feedback_match u_dut (
        .consumer_lane0_uses_rs1_i(c0_uses_rs1),
        .consumer_lane0_uses_rs2_i(c0_uses_rs2),
        .consumer_lane0_rs1_i(c0_rs1),
        .consumer_lane0_rs2_i(c0_rs2),
        .consumer_lane1_active_i(c1_active),
        .consumer_lane1_uses_rs1_i(c1_uses_rs1),
        .consumer_lane1_uses_rs2_i(c1_uses_rs2),
        .consumer_lane1_rs1_i(c1_rs1),
        .consumer_lane1_rs2_i(c1_rs2),
        .producer_lane0_match_valid_i(p0_match_valid),
        .producer_lane0_wait_valid_i(p0_wait_valid),
        .producer_lane0_forward_ready_i(p0_forward_ready),
        .producer_lane0_rd_i(p0_rd),
        .producer_lane1_match_valid_i(p1_match_valid),
        .producer_lane1_wait_valid_i(p1_wait_valid),
        .producer_lane1_forward_ready_i(p1_forward_ready),
        .producer_lane1_rd_i(p1_rd),
        .lane0_rs1_match_slot0_o(c0_rs1_match_p0),
        .lane0_rs2_match_slot0_o(c0_rs2_match_p0),
        .lane0_rs1_match_slot1_o(c0_rs1_match_p1),
        .lane0_rs2_match_slot1_o(c0_rs2_match_p1),
        .lane0_rs1_wait_slot0_o(c0_rs1_wait_p0),
        .lane0_rs2_wait_slot0_o(c0_rs2_wait_p0),
        .lane0_rs1_wait_slot1_o(c0_rs1_wait_p1),
        .lane0_rs2_wait_slot1_o(c0_rs2_wait_p1),
        .lane0_rs1_wait_o(c0_rs1_wait),
        .lane0_rs2_wait_o(c0_rs2_wait),
        .lane0_rs1_fwd_slot0_o(c0_rs1_fwd_p0),
        .lane0_rs2_fwd_slot0_o(c0_rs2_fwd_p0),
        .lane0_rs1_fwd_slot1_o(c0_rs1_fwd_p1),
        .lane0_rs2_fwd_slot1_o(c0_rs2_fwd_p1),
        .lane1_rs1_match_slot0_o(c1_rs1_match_p0),
        .lane1_rs2_match_slot0_o(c1_rs2_match_p0),
        .lane1_rs1_match_slot1_o(c1_rs1_match_p1),
        .lane1_rs2_match_slot1_o(c1_rs2_match_p1),
        .lane1_rs1_wait_slot0_o(c1_rs1_wait_p0),
        .lane1_rs2_wait_slot0_o(c1_rs2_wait_p0),
        .lane1_rs1_wait_slot1_o(c1_rs1_wait_p1),
        .lane1_rs2_wait_slot1_o(c1_rs2_wait_p1),
        .lane1_rs1_wait_o(c1_rs1_wait),
        .lane1_rs2_wait_o(c1_rs2_wait),
        .lane1_rs1_fwd_slot0_o(c1_rs1_fwd_p0),
        .lane1_rs2_fwd_slot0_o(c1_rs2_fwd_p0),
        .lane1_rs1_fwd_slot1_o(c1_rs1_fwd_p1),
        .lane1_rs2_fwd_slot1_o(c1_rs2_fwd_p1)
    );

    task automatic clear_inputs;
        begin
            c0_uses_rs1 = 1'b0; c0_uses_rs2 = 1'b0;
            c0_rs1 = 5'd0; c0_rs2 = 5'd0;
            c1_active = 1'b0; c1_uses_rs1 = 1'b0; c1_uses_rs2 = 1'b0;
            c1_rs1 = 5'd0; c1_rs2 = 5'd0;
            p0_match_valid = 1'b0; p0_wait_valid = 1'b0; p0_forward_ready = 1'b0; p0_rd = 5'd0;
            p1_match_valid = 1'b0; p1_wait_valid = 1'b0; p1_forward_ready = 1'b0; p1_rd = 5'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("feedback matcher idle has no matches",
               !c0_rs1_match_p0 && !c0_rs1_match_p1 && !c1_rs1_match_p0);
        `check("feedback matcher idle has no waits or forwards",
               !c0_rs1_wait && !c0_rs1_fwd_p0 && !c1_rs1_wait && !c1_rs1_fwd_p0);

        clear_inputs();
        c0_uses_rs1 = 1'b1; c0_rs1 = 5'd3;
        p0_match_valid = 1'b1; p0_forward_ready = 1'b1; p0_rd = 5'd3;
        #1;
        `check("lane0 consumer forwards producer lane0",
               c0_rs1_match_p0 && c0_rs1_fwd_p0 && !c0_rs1_wait);

        clear_inputs();
        c0_uses_rs2 = 1'b1; c0_rs2 = 5'd4;
        p1_match_valid = 1'b1; p1_wait_valid = 1'b1; p1_forward_ready = 1'b0; p1_rd = 5'd4;
        #1;
        `check("lane0 consumer waits on producer lane1",
               c0_rs2_match_p1 && c0_rs2_wait_p1 && c0_rs2_wait && !c0_rs2_fwd_p1);

        clear_inputs();
        c1_active = 1'b1; c1_uses_rs1 = 1'b1; c1_rs1 = 5'd5;
        p0_match_valid = 1'b1; p0_wait_valid = 1'b1; p0_forward_ready = 1'b0; p0_rd = 5'd5;
        #1;
        `check("lane1 consumer observes lane0 wait when active",
               c1_rs1_match_p0 && c1_rs1_wait_p0 && c1_rs1_wait && !c1_rs1_fwd_p0);

        clear_inputs();
        c1_uses_rs1 = 1'b1; c1_rs1 = 5'd6;
        p0_match_valid = 1'b1; p0_forward_ready = 1'b1; p0_rd = 5'd6;
        #1;
        `check("inactive lane1 consumer ignores producer",
               !c1_rs1_match_p0 && !c1_rs1_wait && !c1_rs1_fwd_p0);

        clear_inputs();
        c0_uses_rs1 = 1'b1; c0_rs1 = 5'd0;
        p0_match_valid = 1'b1; p0_wait_valid = 1'b1; p0_forward_ready = 1'b1; p0_rd = 5'd0;
        p1_match_valid = 1'b1; p1_wait_valid = 1'b1; p1_forward_ready = 1'b1; p1_rd = 5'd0;
        #1;
        `check("x0 producer never matches",
               !c0_rs1_match_p0 && !c0_rs1_match_p1 &&
               !c0_rs1_wait && !c0_rs1_fwd_p0 && !c0_rs1_fwd_p1);

        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module s5_scoreboard_producer_match_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic lane0_uses_rs1, lane0_uses_rs2;
    logic lane1_active, lane1_uses_rs1, lane1_uses_rs2;
    logic producer_valid, producer_lane0_wb_en, producer_lane0_wait;
    logic producer_lane1_issue_valid, producer_lane1_wb_en, producer_lane1_wait;
    logic [4:0] lane0_rs1, lane0_rs2, lane1_rs1, lane1_rs2;
    logic [4:0] producer_lane0_rd, producer_lane1_rd;

    logic lane0_rs1_match_slot0, lane0_rs2_match_slot0;
    logic lane0_rs1_match_slot1, lane0_rs2_match_slot1;
    logic lane0_rs1_wait, lane0_rs2_wait;
    logic lane0_rs1_fwd_slot0, lane0_rs2_fwd_slot0;
    logic lane0_rs1_fwd_slot1, lane0_rs2_fwd_slot1;
    logic lane1_rs1_match_slot0, lane1_rs2_match_slot0;
    logic lane1_rs1_match_slot1, lane1_rs2_match_slot1;
    logic lane1_rs1_wait, lane1_rs2_wait;
    logic lane1_rs1_fwd_slot0, lane1_rs2_fwd_slot0;
    logic lane1_rs1_fwd_slot1, lane1_rs2_fwd_slot1;

    s5_scoreboard_producer_match u_dut (
        .consumer_lane0_uses_rs1_i(lane0_uses_rs1),
        .consumer_lane0_uses_rs2_i(lane0_uses_rs2),
        .consumer_lane0_rs1_i(lane0_rs1),
        .consumer_lane0_rs2_i(lane0_rs2),
        .consumer_lane1_active_i(lane1_active),
        .consumer_lane1_uses_rs1_i(lane1_uses_rs1),
        .consumer_lane1_uses_rs2_i(lane1_uses_rs2),
        .consumer_lane1_rs1_i(lane1_rs1),
        .consumer_lane1_rs2_i(lane1_rs2),
        .producer_valid_i(producer_valid),
        .producer_lane0_wb_en_i(producer_lane0_wb_en),
        .producer_lane0_wait_i(producer_lane0_wait),
        .producer_lane0_rd_i(producer_lane0_rd),
        .producer_lane1_issue_valid_i(producer_lane1_issue_valid),
        .producer_lane1_wb_en_i(producer_lane1_wb_en),
        .producer_lane1_wait_i(producer_lane1_wait),
        .producer_lane1_rd_i(producer_lane1_rd),
        .lane0_rs1_match_slot0_o(lane0_rs1_match_slot0),
        .lane0_rs2_match_slot0_o(lane0_rs2_match_slot0),
        .lane0_rs1_match_slot1_o(lane0_rs1_match_slot1),
        .lane0_rs2_match_slot1_o(lane0_rs2_match_slot1),
        .lane0_rs1_wait_o(lane0_rs1_wait),
        .lane0_rs2_wait_o(lane0_rs2_wait),
        .lane0_rs1_fwd_slot0_o(lane0_rs1_fwd_slot0),
        .lane0_rs2_fwd_slot0_o(lane0_rs2_fwd_slot0),
        .lane0_rs1_fwd_slot1_o(lane0_rs1_fwd_slot1),
        .lane0_rs2_fwd_slot1_o(lane0_rs2_fwd_slot1),
        .lane1_rs1_match_slot0_o(lane1_rs1_match_slot0),
        .lane1_rs2_match_slot0_o(lane1_rs2_match_slot0),
        .lane1_rs1_match_slot1_o(lane1_rs1_match_slot1),
        .lane1_rs2_match_slot1_o(lane1_rs2_match_slot1),
        .lane1_rs1_wait_o(lane1_rs1_wait),
        .lane1_rs2_wait_o(lane1_rs2_wait),
        .lane1_rs1_fwd_slot0_o(lane1_rs1_fwd_slot0),
        .lane1_rs2_fwd_slot0_o(lane1_rs2_fwd_slot0),
        .lane1_rs1_fwd_slot1_o(lane1_rs1_fwd_slot1),
        .lane1_rs2_fwd_slot1_o(lane1_rs2_fwd_slot1)
    );

    task automatic clear_inputs;
        begin
            lane0_uses_rs1 = 1'b0;
            lane0_uses_rs2 = 1'b0;
            lane0_rs1 = 5'd0;
            lane0_rs2 = 5'd0;
            lane1_active = 1'b0;
            lane1_uses_rs1 = 1'b0;
            lane1_uses_rs2 = 1'b0;
            lane1_rs1 = 5'd0;
            lane1_rs2 = 5'd0;
            producer_valid = 1'b0;
            producer_lane0_wb_en = 1'b0;
            producer_lane0_wait = 1'b0;
            producer_lane0_rd = 5'd0;
            producer_lane1_issue_valid = 1'b0;
            producer_lane1_wb_en = 1'b0;
            producer_lane1_wait = 1'b0;
            producer_lane1_rd = 5'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;
        clear_inputs();
        #1;
        `check("producer matcher idle has no lane0 match",
               !lane0_rs1_match_slot0 && !lane0_rs2_match_slot0 &&
               !lane0_rs1_match_slot1 && !lane0_rs2_match_slot1);
        `check("producer matcher idle has no lane1 match",
               !lane1_rs1_match_slot0 && !lane1_rs2_match_slot0 &&
               !lane1_rs1_match_slot1 && !lane1_rs2_match_slot1);
        `check("producer matcher idle has no wait or fwd",
               !lane0_rs1_wait && !lane0_rs1_fwd_slot0 &&
               !lane1_rs1_wait && !lane1_rs1_fwd_slot0);

        clear_inputs();
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd8;
        producer_valid = 1'b1;
        producer_lane0_wb_en = 1'b1;
        producer_lane0_wait = 1'b0;
        producer_lane0_rd = 5'd8;
        #1;
        `check("lane0 rs1 forwards ready producer lane0",
               lane0_rs1_match_slot0 && lane0_rs1_fwd_slot0 && !lane0_rs1_wait);
        `check("lane0 rs1 does not falsely match producer lane1",
               !lane0_rs1_match_slot1 && !lane0_rs1_fwd_slot1);

        clear_inputs();
        lane0_uses_rs2 = 1'b1;
        lane0_rs2 = 5'd9;
        producer_valid = 1'b1;
        producer_lane1_issue_valid = 1'b1;
        producer_lane1_wb_en = 1'b1;
        producer_lane1_wait = 1'b1;
        producer_lane1_rd = 5'd9;
        #1;
        `check("lane0 rs2 waits for pending producer lane1",
               lane0_rs2_match_slot1 && lane0_rs2_wait && !lane0_rs2_fwd_slot1);

        clear_inputs();
        lane1_active = 1'b1;
        lane1_uses_rs1 = 1'b1;
        lane1_rs1 = 5'd10;
        producer_valid = 1'b1;
        producer_lane0_wb_en = 1'b1;
        producer_lane0_wait = 1'b0;
        producer_lane0_rd = 5'd10;
        #1;
        `check("consumer lane1 rs1 forwards producer lane0",
               lane1_rs1_match_slot0 && lane1_rs1_fwd_slot0 && !lane1_rs1_wait);

        clear_inputs();
        lane1_uses_rs1 = 1'b1;
        lane1_rs1 = 5'd11;
        producer_valid = 1'b1;
        producer_lane0_wb_en = 1'b1;
        producer_lane0_rd = 5'd11;
        #1;
        `check("inactive consumer lane1 cannot match",
               !lane1_rs1_match_slot0 && !lane1_rs1_wait && !lane1_rs1_fwd_slot0);

        clear_inputs();
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd0;
        producer_valid = 1'b1;
        producer_lane0_wb_en = 1'b1;
        producer_lane0_rd = 5'd0;
        producer_lane1_issue_valid = 1'b1;
        producer_lane1_wb_en = 1'b1;
        producer_lane1_rd = 5'd0;
        #1;
        `check("x0 producer is never considered valid",
               !lane0_rs1_match_slot0 && !lane0_rs1_match_slot1 &&
               !lane0_rs1_wait && !lane0_rs1_fwd_slot0 && !lane0_rs1_fwd_slot1);

        finish_tb();
    end
endmodule

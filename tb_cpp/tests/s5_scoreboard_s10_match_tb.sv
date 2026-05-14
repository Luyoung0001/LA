`timescale 1ns / 1ps

module s5_scoreboard_s10_match_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       lane0_uses_rs1;
    logic       lane0_uses_rs2;
    logic [4:0] lane0_rs1;
    logic [4:0] lane0_rs2;
    logic       lane1_active;
    logic       lane1_uses_rs1;
    logic       lane1_uses_rs2;
    logic [4:0] lane1_rs1;
    logic [4:0] lane1_rs2;
    logic       s10_valid;
    logic       s10_wb_en;
    logic       s10_load_wait;
    logic [4:0] s10_rd;
    logic       s10_slot1_issue_valid;
    logic       s10_slot1_wb_en;
    logic       s10_slot1_load_wait;
    logic [4:0] s10_slot1_rd;

    logic lane0_rs1_match_slot0;
    logic lane0_rs2_match_slot0;
    logic lane0_rs1_match_slot1;
    logic lane0_rs2_match_slot1;
    logic lane0_rs1_wait;
    logic lane0_rs2_wait;
    logic lane0_rs1_fwd_slot0;
    logic lane0_rs2_fwd_slot0;
    logic lane0_rs1_fwd_slot1;
    logic lane0_rs2_fwd_slot1;
    logic lane1_rs1_match_slot0;
    logic lane1_rs2_match_slot0;
    logic lane1_rs1_match_slot1;
    logic lane1_rs2_match_slot1;
    logic lane1_rs1_wait;
    logic lane1_rs2_wait;
    logic lane1_rs1_fwd_slot0;
    logic lane1_rs2_fwd_slot0;
    logic lane1_rs1_fwd_slot1;
    logic lane1_rs2_fwd_slot1;

    s5_scoreboard_s10_match u_dut (
        .consumer_lane0_uses_rs1_i(lane0_uses_rs1),
        .consumer_lane0_uses_rs2_i(lane0_uses_rs2),
        .consumer_lane0_rs1_i(lane0_rs1),
        .consumer_lane0_rs2_i(lane0_rs2),
        .consumer_lane1_active_i(lane1_active),
        .consumer_lane1_uses_rs1_i(lane1_uses_rs1),
        .consumer_lane1_uses_rs2_i(lane1_uses_rs2),
        .consumer_lane1_rs1_i(lane1_rs1),
        .consumer_lane1_rs2_i(lane1_rs2),
        .s10_valid_i(s10_valid),
        .s10_wb_en_i(s10_wb_en),
        .s10_load_wait_i(s10_load_wait),
        .s10_rd_i(s10_rd),
        .s10_slot1_issue_valid_i(s10_slot1_issue_valid),
        .s10_slot1_wb_en_i(s10_slot1_wb_en),
        .s10_slot1_load_wait_i(s10_slot1_load_wait),
        .s10_slot1_rd_i(s10_slot1_rd),
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
            s10_valid = 1'b0;
            s10_wb_en = 1'b0;
            s10_load_wait = 1'b0;
            s10_rd = 5'd0;
            s10_slot1_issue_valid = 1'b0;
            s10_slot1_wb_en = 1'b0;
            s10_slot1_load_wait = 1'b0;
            s10_slot1_rd = 5'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S10MATCH idle has no match wait or forward",
               !lane0_rs1_match_slot0 && !lane0_rs2_match_slot0 &&
               !lane0_rs1_match_slot1 && !lane0_rs2_match_slot1 &&
               !lane0_rs1_wait && !lane0_rs2_wait &&
               !lane0_rs1_fwd_slot0 && !lane0_rs2_fwd_slot0 &&
               !lane0_rs1_fwd_slot1 && !lane0_rs2_fwd_slot1 &&
               !lane1_rs1_wait && !lane1_rs2_wait);

        clear_inputs();
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd8;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_rd = 5'd8;
        #1;
        `check("S10MATCH lane0 rs1 sees ready S10 lane0 write",
               lane0_rs1_match_slot0 && lane0_rs1_fwd_slot0 &&
               !lane0_rs1_wait && !lane0_rs1_match_slot1);

        clear_inputs();
        lane0_uses_rs2 = 1'b1;
        lane0_rs2 = 5'd9;
        s10_valid = 1'b0;
        s10_wb_en = 1'b0;
        s10_load_wait = 1'b1;
        s10_rd = 5'd9;
        #1;
        `check("S10MATCH legacy lane0 load_wait blocks even without s10_valid",
               lane0_rs2_wait && !lane0_rs2_match_slot0 &&
               !lane0_rs2_fwd_slot0);

        clear_inputs();
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd10;
        s10_valid = 1'b1;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b1;
        s10_slot1_rd = 5'd10;
        #1;
        `check("S10MATCH pending S10 lane1 load waits without forwarding",
               lane0_rs1_match_slot1 && lane0_rs1_wait &&
               !lane0_rs1_fwd_slot1);

        clear_inputs();
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd11;
        s10_valid = 1'b1;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b0;
        s10_slot1_rd = 5'd11;
        #1;
        `check("S10MATCH ready S10 lane1 forwards",
               lane0_rs1_match_slot1 && lane0_rs1_fwd_slot1 &&
               !lane0_rs1_wait);

        clear_inputs();
        lane1_active = 1'b1;
        lane1_uses_rs2 = 1'b1;
        lane1_rs2 = 5'd12;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_load_wait = 1'b1;
        s10_rd = 5'd12;
        #1;
        `check("S10MATCH current lane1 rs2 sees S10 lane0 pending load",
               lane1_rs2_match_slot0 && lane1_rs2_wait &&
               lane1_rs2_fwd_slot0);

        clear_inputs();
        lane1_active = 1'b0;
        lane1_uses_rs1 = 1'b1;
        lane1_rs1 = 5'd13;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_rd = 5'd13;
        #1;
        `check("S10MATCH inactive lane1 suppresses matches",
               !lane1_rs1_match_slot0 && !lane1_rs1_wait &&
               !lane1_rs1_fwd_slot0);

        clear_inputs();
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd14;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_load_wait = 1'b0;
        s10_rd = 5'd14;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b0;
        s10_slot1_rd = 5'd14;
        #1;
        `check("S10MATCH same rd can report both lanes ready",
               lane0_rs1_match_slot0 && lane0_rs1_match_slot1 &&
               lane0_rs1_fwd_slot0 && lane0_rs1_fwd_slot1 &&
               !lane0_rs1_wait);

        finish_tb();
    end
endmodule

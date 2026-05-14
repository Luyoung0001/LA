`timescale 1ns / 1ps

module s7_operand_feedback_match_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic uses_rs1, uses_rs2;
    logic s8_valid, s8_wb_en, s8_is_load, s8_result_wait, s8_slot1_result_wait;
    logic s8_slot1_issue_valid, s8_slot1_wb_en, s8_slot1_is_load;
    logic [3:0] s8_slot1_issue_class;
    logic s9_valid, s9_wb_en, s9_is_load;
    logic s9_slot1_issue_valid, s9_slot1_wb_en, s9_slot1_is_load;
    logic [3:0] s9_slot1_issue_class;
    logic s10_valid, s10_wb_en, s10_load_wait;
    logic s10_slot1_issue_valid, s10_slot1_wb_en, s10_slot1_load_wait;
    logic [4:0] rs1, rs2, s8_rd, s8_slot1_rd, s9_rd, s9_slot1_rd, s10_rd, s10_slot1_rd;

    logic rs1_wait_s8, rs2_wait_s8, rs1_wait_s8_slot1, rs2_wait_s8_slot1;
    logic rs1_wait_s9, rs2_wait_s9, rs1_wait_s9_slot1, rs2_wait_s9_slot1;
    logic rs1_wait_s10, rs2_wait_s10, rs1_wait_s10_slot1, rs2_wait_s10_slot1;
    logic rs1_newer_than_s10_match, rs2_newer_than_s10_match;
    logic s8_fwd_rs1_slot0, s8_fwd_rs1_slot1, s9_fwd_rs1_slot0, s9_fwd_rs1_slot1;
    logic s10_fwd_rs1_slot0, s10_fwd_rs1_slot1;
    logic s8_fwd_rs2_slot0, s8_fwd_rs2_slot1, s9_fwd_rs2_slot0, s9_fwd_rs2_slot1;
    logic s10_fwd_rs2_slot0, s10_fwd_rs2_slot1;

    s7_operand_feedback_match u_dut (
        .uses_rs1_i(uses_rs1),
        .uses_rs2_i(uses_rs2),
        .rs1_i(rs1),
        .rs2_i(rs2),
        .s8_valid_i(s8_valid),
        .s8_wb_en_i(s8_wb_en),
        .s8_is_load_i(s8_is_load),
        .s8_result_wait_i(s8_result_wait),
        .s8_slot1_result_wait_i(s8_slot1_result_wait),
        .s8_rd_i(s8_rd),
        .s8_slot1_issue_valid_i(s8_slot1_issue_valid),
        .s8_slot1_wb_en_i(s8_slot1_wb_en),
        .s8_slot1_issue_class_i(s8_slot1_issue_class),
        .s8_slot1_rd_i(s8_slot1_rd),
        .s9_valid_i(s9_valid),
        .s9_wb_en_i(s9_wb_en),
        .s9_is_load_i(s9_is_load),
        .s9_rd_i(s9_rd),
        .s9_slot1_issue_valid_i(s9_slot1_issue_valid),
        .s9_slot1_wb_en_i(s9_slot1_wb_en),
        .s9_slot1_issue_class_i(s9_slot1_issue_class),
        .s9_slot1_rd_i(s9_slot1_rd),
        .s10_valid_i(s10_valid),
        .s10_wb_en_i(s10_wb_en),
        .s10_load_wait_i(s10_load_wait),
        .s10_rd_i(s10_rd),
        .s10_slot1_issue_valid_i(s10_slot1_issue_valid),
        .s10_slot1_wb_en_i(s10_slot1_wb_en),
        .s10_slot1_load_wait_i(s10_slot1_load_wait),
        .s10_slot1_rd_i(s10_slot1_rd),
        .rs1_wait_s8_o(rs1_wait_s8),
        .rs2_wait_s8_o(rs2_wait_s8),
        .rs1_wait_s8_slot1_o(rs1_wait_s8_slot1),
        .rs2_wait_s8_slot1_o(rs2_wait_s8_slot1),
        .rs1_wait_s9_o(rs1_wait_s9),
        .rs2_wait_s9_o(rs2_wait_s9),
        .rs1_wait_s9_slot1_o(rs1_wait_s9_slot1),
        .rs2_wait_s9_slot1_o(rs2_wait_s9_slot1),
        .rs1_wait_s10_o(rs1_wait_s10),
        .rs2_wait_s10_o(rs2_wait_s10),
        .rs1_wait_s10_slot1_o(rs1_wait_s10_slot1),
        .rs2_wait_s10_slot1_o(rs2_wait_s10_slot1),
        .rs1_newer_than_s10_match_o(rs1_newer_than_s10_match),
        .rs2_newer_than_s10_match_o(rs2_newer_than_s10_match),
        .s8_fwd_rs1_slot0_o(s8_fwd_rs1_slot0),
        .s8_fwd_rs1_slot1_o(s8_fwd_rs1_slot1),
        .s9_fwd_rs1_slot0_o(s9_fwd_rs1_slot0),
        .s9_fwd_rs1_slot1_o(s9_fwd_rs1_slot1),
        .s10_fwd_rs1_slot0_o(s10_fwd_rs1_slot0),
        .s10_fwd_rs1_slot1_o(s10_fwd_rs1_slot1),
        .s8_fwd_rs2_slot0_o(s8_fwd_rs2_slot0),
        .s8_fwd_rs2_slot1_o(s8_fwd_rs2_slot1),
        .s9_fwd_rs2_slot0_o(s9_fwd_rs2_slot0),
        .s9_fwd_rs2_slot1_o(s9_fwd_rs2_slot1),
        .s10_fwd_rs2_slot0_o(s10_fwd_rs2_slot0),
        .s10_fwd_rs2_slot1_o(s10_fwd_rs2_slot1)
    );

    task automatic clear_inputs;
        begin
            uses_rs1 = 1'b0; uses_rs2 = 1'b0; rs1 = 5'd0; rs2 = 5'd0;
            s8_valid = 1'b0; s8_wb_en = 1'b0; s8_is_load = 1'b0; s8_result_wait = 1'b0; s8_slot1_result_wait = 1'b0; s8_rd = 5'd0;
            s8_slot1_issue_valid = 1'b0; s8_slot1_wb_en = 1'b0; s8_slot1_is_load = 1'b0; s8_slot1_issue_class = 4'd0; s8_slot1_rd = 5'd0;
            s9_valid = 1'b0; s9_wb_en = 1'b0; s9_is_load = 1'b0; s9_rd = 5'd0;
            s9_slot1_issue_valid = 1'b0; s9_slot1_wb_en = 1'b0; s9_slot1_is_load = 1'b0; s9_slot1_issue_class = 4'd0; s9_slot1_rd = 5'd0;
            s10_valid = 1'b0; s10_wb_en = 1'b0; s10_load_wait = 1'b0; s10_rd = 5'd0;
            s10_slot1_issue_valid = 1'b0; s10_slot1_wb_en = 1'b0; s10_slot1_load_wait = 1'b0; s10_slot1_rd = 5'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S7 feedback idle has no waits",
               !rs1_wait_s8 && !rs1_wait_s9 && !rs1_wait_s10 && !rs1_wait_s10_slot1);
        `check("S7 feedback idle has no forwards",
               !s8_fwd_rs1_slot0 && !s9_fwd_rs1_slot0 && !s10_fwd_rs1_slot0);

        clear_inputs();
        uses_rs1 = 1'b1; rs1 = 5'd3;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_rd = 5'd3;
        #1;
        `check("S7 feedback forwards ready S8 lane0",
               s8_fwd_rs1_slot0 && !rs1_wait_s8 && rs1_newer_than_s10_match);

        clear_inputs();
        uses_rs1 = 1'b1; rs1 = 5'd4;
        s8_valid = 1'b1; s8_wb_en = 1'b0; s8_result_wait = 1'b1; s8_rd = 5'd4;
        #1;
        `check("S7 feedback preserves S8 wait without wb_en",
               rs1_wait_s8 && !s8_fwd_rs1_slot0 && !rs1_newer_than_s10_match);

        clear_inputs();
        uses_rs2 = 1'b1; rs2 = 5'd5;
        s9_valid = 1'b1; s9_wb_en = 1'b0; s9_is_load = 1'b1; s9_rd = 5'd5;
        #1;
        `check("S7 feedback preserves S9 load wait without wb_en",
               rs2_wait_s9 && !s9_fwd_rs2_slot0 && !rs2_newer_than_s10_match);

        clear_inputs();
        uses_rs1 = 1'b1; rs1 = 5'd6;
        s10_load_wait = 1'b1; s10_rd = 5'd6;
        #1;
        `check("S7 feedback preserves S10 lane0 load_wait without valid",
               rs1_wait_s10 && !s10_fwd_rs1_slot0 && !rs1_newer_than_s10_match);

        clear_inputs();
        uses_rs2 = 1'b1; rs2 = 5'd7;
        s10_valid = 1'b1; s10_slot1_issue_valid = 1'b1; s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b0; s10_slot1_rd = 5'd7;
        #1;
        `check("S7 feedback ready S10 lane1 is newer than S10 lane0",
               s10_fwd_rs2_slot1 && !rs2_wait_s10_slot1 && rs2_newer_than_s10_match);

        clear_inputs();
        uses_rs1 = 1'b1; rs1 = 5'd8;
        s8_valid = 1'b1; s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1; s8_slot1_is_load = 1'b1;
        s8_slot1_issue_class = 4'b1000; s8_slot1_rd = 5'd8;
        #1;
        `check("S7 feedback ignores lane1 load payload without load class",
               s8_fwd_rs1_slot1 && !rs1_wait_s8_slot1 && rs1_newer_than_s10_match);

        s8_slot1_issue_class = 4'b0100;
        #1;
        `check("S7 feedback waits on lane1 load class",
               !s8_fwd_rs1_slot1 && rs1_wait_s8_slot1 && rs1_newer_than_s10_match);

        clear_inputs();
        uses_rs1 = 1'b1; rs1 = 5'd8;
        s8_valid = 1'b1; s8_result_wait = 1'b1; s8_slot1_result_wait = 1'b0;
        s8_slot1_issue_valid = 1'b1; s8_slot1_wb_en = 1'b1;
        s8_slot1_issue_class = 4'b1000; s8_slot1_rd = 5'd8;
        #1;
        `check("S7 feedback forwards S8 lane1 even when lane0 waits",
               s8_fwd_rs1_slot1 && !rs1_wait_s8_slot1 && rs1_newer_than_s10_match);

        s8_slot1_result_wait = 1'b1;
        #1;
        `check("S7 feedback waits only when S8 lane1 itself waits",
               !s8_fwd_rs1_slot1 && rs1_wait_s8_slot1 && rs1_newer_than_s10_match);

        clear_inputs();
        uses_rs1 = 1'b1; rs1 = 5'd0;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_is_load = 1'b1; s8_rd = 5'd0;
        s10_load_wait = 1'b1; s10_rd = 5'd0;
        #1;
        `check("S7 feedback never waits or forwards x0",
               !rs1_wait_s8 && !rs1_wait_s10 && !s8_fwd_rs1_slot0 &&
               !s10_fwd_rs1_slot0 && !rs1_newer_than_s10_match);

        finish_tb();
    end
endmodule

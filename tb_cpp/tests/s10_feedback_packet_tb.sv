`timescale 1ns / 1ps

module s10_feedback_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        slot0_valid;
    logic        slot0_commit_valid;
    logic        slot0_wb_en;
    logic        slot0_load_wait;
    logic        slot0_load_uncached;
    logic [4:0]  slot0_rd;
    logic [31:0] slot0_result;
    logic        slot1_issue_valid;
    logic        slot1_wb_en;
    logic        slot1_load_wait;
    logic [4:0]  slot1_rd;
    logic [31:0] slot1_alu_result;
    logic        slot1_rf_we_candidate;
    logic [4:0]  slot1_rf_waddr_candidate;
    logic [31:0] slot1_rf_wdata_candidate;
    logic        slot1_commit_accept;
    logic        dual_commit_enable;

    logic        slot0_valid_o;
    logic        slot0_wb_en_o;
    logic        slot0_load_wait_o;
    logic        slot0_load_uncached_o;
    logic [4:0]  slot0_rd_o;
    logic [31:0] slot0_result_o;
    logic        slot1_issue_valid_o;
    logic        slot1_wb_en_o;
    logic        slot1_load_wait_o;
    logic [4:0]  slot1_rd_o;
    logic [31:0] slot1_result_o;

    s10_feedback_packet u_dut (
        .slot0_valid_i(slot0_valid),
        .slot0_commit_valid_i(slot0_commit_valid),
        .slot0_wb_en_i(slot0_wb_en),
        .slot0_load_wait_i(slot0_load_wait),
        .slot0_load_uncached_i(slot0_load_uncached),
        .slot0_rd_i(slot0_rd),
        .slot0_result_i(slot0_result),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_load_wait_i(slot1_load_wait),
        .slot1_rd_i(slot1_rd),
        .slot1_alu_result_i(slot1_alu_result),
        .slot1_rf_we_candidate_i(slot1_rf_we_candidate),
        .slot1_rf_waddr_candidate_i(slot1_rf_waddr_candidate),
        .slot1_rf_wdata_candidate_i(slot1_rf_wdata_candidate),
        .slot1_commit_accept_i(slot1_commit_accept),
        .dual_commit_enable_i(dual_commit_enable),
        .slot0_valid_o(slot0_valid_o),
        .slot0_wb_en_o(slot0_wb_en_o),
        .slot0_load_wait_o(slot0_load_wait_o),
        .slot0_load_uncached_o(slot0_load_uncached_o),
        .slot0_rd_o(slot0_rd_o),
        .slot0_result_o(slot0_result_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .slot1_wb_en_o(slot1_wb_en_o),
        .slot1_load_wait_o(slot1_load_wait_o),
        .slot1_rd_o(slot1_rd_o),
        .slot1_result_o(slot1_result_o)
    );

    task automatic drive_payload;
        begin
            slot0_valid = 1'b1;
            slot0_commit_valid = 1'b1;
            slot0_wb_en = 1'b1;
            slot0_load_wait = 1'b0;
            slot0_load_uncached = 1'b1;
            slot0_rd = 5'd9;
            slot0_result = 32'h1111_0009;
            slot1_issue_valid = 1'b1;
            slot1_wb_en = 1'b1;
            slot1_load_wait = 1'b0;
            slot1_rd = 5'd12;
            slot1_alu_result = 32'h2222_000c;
            slot1_rf_we_candidate = 1'b0;
            slot1_rf_waddr_candidate = 5'd0;
            slot1_rf_wdata_candidate = 32'd0;
            slot1_commit_accept = 1'b1;
            dual_commit_enable = 1'b1;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_payload();
        #1;
        `check("S10 feedback forwards slot0 controls",
               slot0_valid_o && slot0_wb_en_o && !slot0_load_wait_o &&
               slot0_load_uncached_o);
        `check32("S10 feedback forwards slot0 rd",
                 {27'd0, slot0_rd_o}, 32'd9);
        `check32("S10 feedback forwards slot0 result",
                 slot0_result_o, 32'h1111_0009);
        `check("S10 feedback forwards slot1 controls",
               slot1_issue_valid_o && slot1_wb_en_o && !slot1_load_wait_o);
        `check32("S10 feedback forwards slot1 rd",
                 {27'd0, slot1_rd_o}, 32'd12);
        `check32("S10 feedback forwards slot1 result",
                 slot1_result_o, 32'h2222_000c);

        drive_payload();
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd14;
        slot1_rf_wdata_candidate = 32'hfeed_c0de;
        #1;
        `check32("S10 feedback uses slot1 RF candidate rd",
                 {27'd0, slot1_rd_o}, 32'd14);
        `check32("S10 feedback uses slot1 RF candidate data",
                 slot1_result_o, 32'hfeed_c0de);

        drive_payload();
        slot1_commit_accept = 1'b0;
        slot0_commit_valid = 1'b1;
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd14;
        slot1_rf_wdata_candidate = 32'hfeed_c0de;
        #1;
        `check("S10 feedback suppresses unaccepted slot1 after slot0 commit boundary",
               !slot1_issue_valid_o && !slot1_wb_en_o && !slot1_load_wait_o);
        `check32("S10 feedback clears unaccepted slot1 rd",
                 {27'd0, slot1_rd_o}, 32'd0);
        `check32("S10 feedback clears unaccepted slot1 result",
                 slot1_result_o, 32'd0);

        drive_payload();
        slot0_commit_valid = 1'b0;
        slot1_commit_accept = 1'b0;
        slot1_rf_we_candidate = 1'b0;
        slot1_rd = 5'd15;
        slot1_alu_result = 32'h0000_1000;
        #1;
        `check("S10 feedback exposes unaccepted slot1 producer as pending",
               slot1_issue_valid_o && slot1_wb_en_o && slot1_load_wait_o);
        `check32("S10 pending slot1 carries raw producer rd",
                 {27'd0, slot1_rd_o}, 32'd15);
        `check32("S10 pending slot1 does not forward data before commit",
                 slot1_result_o, 32'd0);

        drive_payload();
        slot0_commit_valid = 1'b0;
        slot1_commit_accept = 1'b0;
        dual_commit_enable = 1'b0;
        #1;
        `check("S10 feedback does not create pending slot1 when dual commit is disabled",
               !slot1_issue_valid_o && !slot1_wb_en_o && !slot1_load_wait_o);

        slot0_valid = 1'b0;
        slot0_commit_valid = 1'b0;
        slot0_wb_en = 1'b0;
        slot0_load_wait = 1'b1;
        slot0_load_uncached = 1'b0;
        slot0_rd = 5'd0;
        slot0_result = 32'hdead_beef;
        slot1_issue_valid = 1'b0;
        slot1_wb_en = 1'b0;
        slot1_load_wait = 1'b1;
        slot1_rd = 5'd0;
        slot1_alu_result = 32'hcafe_babe;
        slot1_rf_we_candidate = 1'b0;
        slot1_rf_waddr_candidate = 5'd0;
        slot1_rf_wdata_candidate = 32'd0;
        slot1_commit_accept = 1'b1;
        dual_commit_enable = 1'b1;
        #1;
        `check("S10 feedback forwards blocked slot0 controls",
               !slot0_valid_o && !slot0_wb_en_o &&
               slot0_load_wait_o && !slot0_load_uncached_o);
        `check32("S10 feedback forwards raw blocked slot0 data",
                 slot0_result_o, 32'hdead_beef);
        `check("S10 feedback forwards blocked slot1 controls",
               !slot1_issue_valid_o && !slot1_wb_en_o &&
               slot1_load_wait_o);
        `check32("S10 feedback forwards raw blocked slot1 data",
                 slot1_result_o, 32'hcafe_babe);

        finish_tb();
    end
endmodule

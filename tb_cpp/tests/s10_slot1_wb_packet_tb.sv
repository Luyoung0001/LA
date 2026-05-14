`timescale 1ns / 1ps

module s10_slot1_wb_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        commit_ready;
    logic        slot1_valid;
    logic        slot1_issue_valid;
    logic        slot1_wb_en;
    logic [4:0]  slot1_rd;
    logic [31:0] slot1_wb_data;
    logic        any_exception;
    logic        slot1_mem_exception;
    logic        slot1_mem_fault;
    logic        rf_we_candidate;
    logic [4:0]  rf_waddr_candidate;
    logic [31:0] rf_wdata_candidate;

    s10_slot1_wb_packet u_dut (
        .commit_ready_i(commit_ready),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_rd_i(slot1_rd),
        .slot1_wb_data_i(slot1_wb_data),
        .any_exception_i(any_exception),
        .slot1_mem_exception_i(slot1_mem_exception),
        .slot1_mem_fault_i(slot1_mem_fault),
        .rf_we_candidate_o(rf_we_candidate),
        .rf_waddr_candidate_o(rf_waddr_candidate),
        .rf_wdata_candidate_o(rf_wdata_candidate)
    );

    task automatic drive_ready_candidate;
        begin
            commit_ready = 1'b1;
            slot1_valid = 1'b1;
            slot1_issue_valid = 1'b1;
            slot1_wb_en = 1'b1;
            slot1_rd = 5'd17;
            slot1_wb_data = 32'hcafe_babe;
            any_exception = 1'b0;
            slot1_mem_exception = 1'b0;
            slot1_mem_fault = 1'b0;
        end
    endtask

    task automatic check_blocked(input string name);
        begin
            #1;
            `check(name, !rf_we_candidate &&
                         rf_waddr_candidate == 5'd0 &&
                         rf_wdata_candidate == 32'd0);
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_ready_candidate();
        #1;
        `check("WB packet accepts clean slot1 candidate",
               rf_we_candidate &&
               rf_waddr_candidate == 5'd17 &&
               rf_wdata_candidate == 32'hcafe_babe);

        drive_ready_candidate();
        commit_ready = 1'b0;
        check_blocked("WB packet blocks before commit ready");

        drive_ready_candidate();
        slot1_valid = 1'b0;
        check_blocked("WB packet blocks invalid slot1");

        drive_ready_candidate();
        slot1_issue_valid = 1'b0;
        check_blocked("WB packet blocks non-issued slot1");

        drive_ready_candidate();
        slot1_wb_en = 1'b0;
        check_blocked("WB packet blocks no-writeback slot1");

        drive_ready_candidate();
        slot1_rd = 5'd0;
        check_blocked("WB packet blocks x0 write");

        drive_ready_candidate();
        any_exception = 1'b1;
        check_blocked("WB packet blocks slot0 exception");

        drive_ready_candidate();
        slot1_mem_exception = 1'b1;
        check_blocked("WB packet blocks slot1 mem exception");

        drive_ready_candidate();
        slot1_mem_fault = 1'b1;
        check_blocked("WB packet blocks slot1 mem fault");

        drive_ready_candidate();
        slot1_rd = 5'd3;
        slot1_wb_data = 32'h1234_5678;
        #1;
        `check("WB packet forwards alternate data",
               rf_we_candidate &&
               rf_waddr_candidate == 5'd3 &&
               rf_wdata_candidate == 32'h1234_5678);

        finish_tb();
    end
endmodule

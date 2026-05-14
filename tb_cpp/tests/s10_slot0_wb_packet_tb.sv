`timescale 1ns / 1ps

module s10_slot0_wb_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        commit_ready;
    logic        wb_en;
    logic [4:0]  rd;
    logic [31:0] wb_data;
    logic        any_exception;
    logic        rf_we;
    logic [4:0]  rf_waddr;
    logic [31:0] rf_wdata;

    s10_slot0_wb_packet u_dut (
        .commit_ready_i(commit_ready),
        .wb_en_i(wb_en),
        .rd_i(rd),
        .wb_data_i(wb_data),
        .any_exception_i(any_exception),
        .rf_we_o(rf_we),
        .rf_waddr_o(rf_waddr),
        .rf_wdata_o(rf_wdata)
    );

    task automatic drive_payload;
        begin
            commit_ready = 1'b1;
            wb_en = 1'b1;
            rd = 5'd8;
            wb_data = 32'h1234_5678;
            any_exception = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_payload();
        #1;
        `check("WB0 packet accepts clean writeback",
               rf_we && rf_waddr == 5'd8 && rf_wdata == 32'h1234_5678);

        drive_payload();
        commit_ready = 1'b0;
        #1;
        `check("WB0 packet blocks before commit ready", !rf_we);
        `check32("WB0 packet keeps raw addr while blocked",
                 {27'd0, rf_waddr}, 32'd8);
        `check32("WB0 packet keeps raw data while blocked",
                 rf_wdata, 32'h1234_5678);

        drive_payload();
        wb_en = 1'b0;
        #1;
        `check("WB0 packet blocks disabled writeback", !rf_we);

        drive_payload();
        rd = 5'd0;
        #1;
        `check("WB0 packet blocks x0 write", !rf_we && rf_waddr == 5'd0);

        drive_payload();
        any_exception = 1'b1;
        #1;
        `check("WB0 packet blocks exception writeback", !rf_we);
        `check32("WB0 packet preserves exception data sideband",
                 rf_wdata, 32'h1234_5678);

        drive_payload();
        rd = 5'd31;
        wb_data = 32'hffff_0001;
        #1;
        `check("WB0 packet forwards alternate writeback",
               rf_we && rf_waddr == 5'd31 && rf_wdata == 32'hffff_0001);

        finish_tb();
    end
endmodule

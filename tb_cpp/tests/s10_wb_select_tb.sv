`timescale 1ns / 1ps

module s10_wb_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        slot0_commit_valid;
    logic        slot0_rf_we;
    logic [4:0]  slot0_rf_waddr;
    logic [31:0] slot0_rf_wdata;
    logic        slot1_rf_we_candidate;
    logic [4:0]  slot1_rf_waddr_candidate;
    logic [31:0] slot1_rf_wdata_candidate;
    logic        slot1_commit_accept;
    logic        wb0_we;
    logic [4:0]  wb0_waddr;
    logic [31:0] wb0_wdata;
    logic        wb1_we;
    logic [4:0]  wb1_waddr;
    logic [31:0] wb1_wdata;
    logic        dual_wb;
    logic [3:0]  wb_select_reason;

    s10_wb_select u_dut (
        .slot0_commit_valid_i(slot0_commit_valid),
        .slot0_rf_we_i(slot0_rf_we),
        .slot0_rf_waddr_i(slot0_rf_waddr),
        .slot0_rf_wdata_i(slot0_rf_wdata),
        .slot1_rf_we_candidate_i(slot1_rf_we_candidate),
        .slot1_rf_waddr_candidate_i(slot1_rf_waddr_candidate),
        .slot1_rf_wdata_candidate_i(slot1_rf_wdata_candidate),
        .slot1_commit_accept_i(slot1_commit_accept),
        .wb0_we_o(wb0_we),
        .wb0_waddr_o(wb0_waddr),
        .wb0_wdata_o(wb0_wdata),
        .wb1_we_o(wb1_we),
        .wb1_waddr_o(wb1_waddr),
        .wb1_wdata_o(wb1_wdata),
        .dual_wb_o(dual_wb),
        .wb_select_reason_o(wb_select_reason)
    );

    task automatic clear_inputs;
        begin
            slot0_commit_valid = 1'b0;
            slot0_rf_we = 1'b0;
            slot0_rf_waddr = 5'd0;
            slot0_rf_wdata = 32'd0;
            slot1_rf_we_candidate = 1'b0;
            slot1_rf_waddr_candidate = 5'd0;
            slot1_rf_wdata_candidate = 32'd0;
            slot1_commit_accept = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("WBSEL idle writes nothing", !wb0_we && !wb1_we && !dual_wb);
        `check32("WBSEL idle reason clear", {28'd0, wb_select_reason}, 32'd0);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_rf_we = 1'b1;
        slot0_rf_waddr = 5'd3;
        slot0_rf_wdata = 32'h1111_0003;
        #1;
        `check("WBSEL slot0 write passes", wb0_we && !wb1_we && !dual_wb);
        `check32("WBSEL slot0 write addr", {27'd0, wb0_waddr}, 32'd3);
        `check32("WBSEL slot0 write data", wb0_wdata, 32'h1111_0003);
        `check32("WBSEL slot0-only reason", {28'd0, wb_select_reason}, 32'h1);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_rf_we = 1'b1;
        slot0_rf_waddr = 5'd4;
        slot0_rf_wdata = 32'h2222_0004;
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd5;
        slot1_rf_wdata_candidate = 32'h3333_0005;
        #1;
        `check("WBSEL masks slot1 until commit1 accepted", wb0_we && !wb1_we && !dual_wb);
        `check32("WBSEL held slot1 clears wb1 addr", {27'd0, wb1_waddr}, 32'd0);
        `check32("WBSEL held slot1 clears wb1 data", wb1_wdata, 32'd0);
        `check32("WBSEL held slot1 reason marks candidate", {28'd0, wb_select_reason}, 32'h7);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_rf_we = 1'b1;
        slot0_rf_waddr = 5'd9;
        slot0_rf_wdata = 32'h9999_0009;
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd9;
        slot1_rf_wdata_candidate = 32'haaaa_0009;
        #1;
        `check("WBSEL held WAW slot1 still cannot write before commit1",
               wb0_we && !wb1_we && !dual_wb);
        `check32("WBSEL held WAW keeps slot0 addr", {27'd0, wb0_waddr}, 32'd9);
        `check32("WBSEL held WAW clears wb1 addr", {27'd0, wb1_waddr}, 32'd0);
        `check32("WBSEL held WAW clears wb1 data", wb1_wdata, 32'd0);
        `check32("WBSEL held WAW reason marks hold and WAW",
                 {28'd0, wb_select_reason}, 32'hf);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_rf_we = 1'b1;
        slot0_rf_waddr = 5'd4;
        slot0_rf_wdata = 32'h2222_0004;
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd5;
        slot1_rf_wdata_candidate = 32'h3333_0005;
        slot1_commit_accept = 1'b1;
        #1;
        `check("WBSEL commit1 accepted emits both writes", wb0_we && wb1_we && dual_wb);
        `check32("WBSEL dual wb0 addr", {27'd0, wb0_waddr}, 32'd4);
        `check32("WBSEL dual wb0 data", wb0_wdata, 32'h2222_0004);
        `check32("WBSEL dual wb1 addr", {27'd0, wb1_waddr}, 32'd5);
        `check32("WBSEL dual wb1 data", wb1_wdata, 32'h3333_0005);
        `check32("WBSEL commit1 accepted reason", {28'd0, wb_select_reason}, 32'h3);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_rf_we = 1'b1;
        slot0_rf_waddr = 5'd6;
        slot0_rf_wdata = 32'h4444_0006;
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd6;
        slot1_rf_wdata_candidate = 32'h5555_0006;
        slot1_commit_accept = 1'b1;
        #1;
        `check("WBSEL WAW allows both writes; younger slot1 wins in regfile", wb0_we && wb1_we && dual_wb);
        `check32("WBSEL WAW keeps slot0 addr", {27'd0, wb0_waddr}, 32'd6);
        `check32("WBSEL WAW keeps slot1 addr", {27'd0, wb1_waddr}, 32'd6);
        `check32("WBSEL WAW keeps slot1 data", wb1_wdata, 32'h5555_0006);
        `check32("WBSEL WAW reason", {28'd0, wb_select_reason}, 32'hb);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_rf_we = 1'b1;
        slot0_rf_waddr = 5'd0;
        slot0_rf_wdata = 32'hffff_ffff;
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd7;
        slot1_rf_wdata_candidate = 32'h7777_0007;
        slot1_commit_accept = 1'b1;
        #1;
        `check("WBSEL slot0 r0 suppresses first write but allows slot1 candidate", !wb0_we && wb1_we && !dual_wb);
        `check32("WBSEL slot0 r0 clears wb0 data", wb0_wdata, 32'd0);
        `check32("WBSEL slot1 survives slot0 r0", {27'd0, wb1_waddr}, 32'd7);
        `check32("WBSEL slot1 survives data", wb1_wdata, 32'h7777_0007);

        clear_inputs();
        slot0_commit_valid = 1'b1;
        slot0_rf_we = 1'b1;
        slot0_rf_waddr = 5'd10;
        slot0_rf_wdata = 32'haaaa_0010;
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd0;
        slot1_rf_wdata_candidate = 32'hffff_ffff;
        slot1_commit_accept = 1'b1;
        #1;
        `check("WBSEL slot1 x0 candidate is suppressed",
               wb0_we && !wb1_we && !dual_wb);
        `check32("WBSEL slot1 x0 clears wb1 addr", {27'd0, wb1_waddr}, 32'd0);
        `check32("WBSEL slot1 x0 clears wb1 data", wb1_wdata, 32'd0);
        `check32("WBSEL slot1 x0 reason keeps slot0-only",
                 {28'd0, wb_select_reason}, 32'h1);

        clear_inputs();
        slot1_rf_we_candidate = 1'b1;
        slot1_rf_waddr_candidate = 5'd8;
        slot1_rf_wdata_candidate = 32'h8888_0008;
        slot1_commit_accept = 1'b1;
        #1;
        `check("WBSEL requires slot0 commit to accept slot1", !wb0_we && !wb1_we && !dual_wb);
        `check32("WBSEL no-commit reason clear", {28'd0, wb_select_reason}, 32'd0);

        finish_tb();
    end
endmodule

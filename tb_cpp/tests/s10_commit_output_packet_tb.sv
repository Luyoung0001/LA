`timescale 1ns / 1ps

module s10_commit_output_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        commit1_valid;
    logic [31:0] commit1_pc;
    logic [31:0] commit1_instr;
    logic        wb0_we;
    logic [4:0]  wb0_waddr;
    logic [31:0] wb0_wdata;
    logic [31:0] wb0_pc;
    logic        wb1_we;
    logic [4:0]  wb1_waddr;
    logic [31:0] wb1_wdata;
    logic [31:0] wb1_pc;
    logic        debug_unknown_inst;

    logic        commit1_valid_o;
    logic [31:0] commit1_pc_o;
    logic [31:0] commit1_instr_o;
    logic        debug_wb_rf_wen_o;
    logic [4:0]  debug_wb_rf_wnum_o;
    logic [31:0] debug_wb_pc_o;
    logic [31:0] debug_wb_rf_wdata_o;
    logic        debug1_wb_rf_wen_o;
    logic [4:0]  debug1_wb_rf_wnum_o;
    logic [31:0] debug1_wb_pc_o;
    logic [31:0] debug1_wb_rf_wdata_o;
    logic        debug_unknown_inst_o;

    s10_commit_output_packet u_dut (
        .commit1_valid_i(commit1_valid),
        .commit1_pc_i(commit1_pc),
        .commit1_instr_i(commit1_instr),
        .wb0_we_i(wb0_we),
        .wb0_waddr_i(wb0_waddr),
        .wb0_wdata_i(wb0_wdata),
        .wb0_pc_i(wb0_pc),
        .wb1_we_i(wb1_we),
        .wb1_waddr_i(wb1_waddr),
        .wb1_wdata_i(wb1_wdata),
        .wb1_pc_i(wb1_pc),
        .debug_unknown_inst_i(debug_unknown_inst),
        .commit1_valid_o(commit1_valid_o),
        .commit1_pc_o(commit1_pc_o),
        .commit1_instr_o(commit1_instr_o),
        .debug_wb_rf_wen_o(debug_wb_rf_wen_o),
        .debug_wb_rf_wnum_o(debug_wb_rf_wnum_o),
        .debug_wb_pc_o(debug_wb_pc_o),
        .debug_wb_rf_wdata_o(debug_wb_rf_wdata_o),
        .debug1_wb_rf_wen_o(debug1_wb_rf_wen_o),
        .debug1_wb_rf_wnum_o(debug1_wb_rf_wnum_o),
        .debug1_wb_pc_o(debug1_wb_pc_o),
        .debug1_wb_rf_wdata_o(debug1_wb_rf_wdata_o),
        .debug_unknown_inst_o(debug_unknown_inst_o)
    );

    task automatic clear_inputs;
        begin
            commit1_valid = 1'b0;
            commit1_pc = 32'd0;
            commit1_instr = 32'd0;
            wb0_we = 1'b0;
            wb0_waddr = 5'd0;
            wb0_wdata = 32'd0;
            wb0_pc = 32'd0;
            wb1_we = 1'b0;
            wb1_waddr = 5'd0;
            wb1_wdata = 32'd0;
            wb1_pc = 32'd0;
            debug_unknown_inst = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("COUT idle clears write enables",
               !debug_wb_rf_wen_o && !debug1_wb_rf_wen_o &&
               !commit1_valid_o && !debug_unknown_inst_o);
        `check32("COUT idle clears commit1 pc", commit1_pc_o, 32'd0);

        clear_inputs();
        commit1_valid = 1'b1;
        commit1_pc = 32'h1c00_2004;
        commit1_instr = 32'h0280_00a5;
        wb0_we = 1'b1;
        wb0_waddr = 5'd4;
        wb0_wdata = 32'h1111_0004;
        wb0_pc = 32'h1c00_2000;
        wb1_we = 1'b1;
        wb1_waddr = 5'd5;
        wb1_wdata = 32'h2222_0005;
        wb1_pc = 32'h1c00_2004;
        debug_unknown_inst = 1'b1;
        #1;
        `check("COUT forwards commit1 output", commit1_valid_o);
        `check32("COUT commit1 pc", commit1_pc_o, 32'h1c00_2004);
        `check32("COUT commit1 instr", commit1_instr_o, 32'h0280_00a5);
        `check("COUT forwards lane0 debug write", debug_wb_rf_wen_o);
        `check32("COUT lane0 debug rd", {27'd0, debug_wb_rf_wnum_o}, 32'd4);
        `check32("COUT lane0 debug pc", debug_wb_pc_o, 32'h1c00_2000);
        `check32("COUT lane0 debug data", debug_wb_rf_wdata_o, 32'h1111_0004);
        `check("COUT forwards lane1 debug write", debug1_wb_rf_wen_o);
        `check32("COUT lane1 debug rd", {27'd0, debug1_wb_rf_wnum_o}, 32'd5);
        `check32("COUT lane1 debug pc", debug1_wb_pc_o, 32'h1c00_2004);
        `check32("COUT lane1 debug data", debug1_wb_rf_wdata_o, 32'h2222_0005);
        `check("COUT forwards unknown-inst sideband", debug_unknown_inst_o);

        clear_inputs();
        commit1_pc = 32'h1c00_3004;
        commit1_instr = 32'h0280_00c6;
        wb0_pc = 32'h1c00_3000;
        wb1_pc = 32'h1c00_3004;
        #1;
        `check("COUT masks only enables, not observation payloads",
               !commit1_valid_o && !debug_wb_rf_wen_o && !debug1_wb_rf_wen_o);
        `check32("COUT keeps raw commit1 pc payload", commit1_pc_o, 32'h1c00_3004);
        `check32("COUT keeps raw lane0 debug pc payload", debug_wb_pc_o, 32'h1c00_3000);
        `check32("COUT keeps raw lane1 debug pc payload", debug1_wb_pc_o, 32'h1c00_3004);

        finish_tb();
    end
endmodule

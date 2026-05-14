`timescale 1ns / 1ps

module cpu_primitives_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic rst, wen;
    logic [7:0] din, reg_dout, async_dout, pipe_dout;
    logic pipe_flush, pipe_stall;
    Reg #(.WIDTH(8), .RESET_VAL(8'h5a)) u_reg (
        .clk(clk), .rst(rst), .din(din), .dout(reg_dout), .wen(wen)
    );
    RegAsyncRst #(.WIDTH(8), .RESET_VAL(8'ha5)) u_async (
        .clk(clk), .rst_n(rst_n), .din(din), .dout(async_dout), .wen(wen)
    );
    PipeReg #(.WIDTH(8), .RESET_VAL(8'hc3)) u_pipe (
        .clk(clk), .rst_n(rst_n), .flush(pipe_flush), .stall(pipe_stall),
        .din(din), .dout(pipe_dout)
    );

    logic sdp_we;
    logic [1:0] sdp_waddr, sdp_raddr;
    logic [15:0] sdp_wdata, sdp_rdata;
    BramSDP #(.DEPTH(4), .WIDTH(16), .ADDR_W(2)) u_sdp (
        .clk(clk), .we(sdp_we), .waddr(sdp_waddr), .wdata(sdp_wdata),
        .raddr(sdp_raddr), .rdata(sdp_rdata)
    );

    logic tdp_a_we, tdp_b_we;
    logic [1:0] tdp_a_addr, tdp_b_addr;
    logic [15:0] tdp_a_wdata, tdp_b_wdata, tdp_a_rdata, tdp_b_rdata;
    BramTDP #(.DEPTH(4), .WIDTH(16), .ADDR_W(2)) u_tdp (
        .clk(clk), .a_we(tdp_a_we), .a_addr(tdp_a_addr), .a_wdata(tdp_a_wdata),
        .a_rdata(tdp_a_rdata), .b_we(tdp_b_we), .b_addr(tdp_b_addr),
        .b_wdata(tdp_b_wdata), .b_rdata(tdp_b_rdata)
    );

    logic sat_rst, sat_en, sat_inc;
    logic [1:0] sat_cnt;
    SatCounter #(.WIDTH(2), .RESET_VAL(1)) u_sat (
        .clk(clk), .rst(sat_rst), .en(sat_en), .inc(sat_inc), .cnt(sat_cnt)
    );

    logic [7:0] onehot;
    logic [2:0] bin;
    logic oh_valid;
    OnehotToBin #(.WIDTH(8), .BIN_W(3)) u_oh2bin (.onehot(onehot), .bin(bin), .valid(oh_valid));

    logic b2o_en;
    logic [2:0] b2o_bin;
    logic [7:0] b2o_onehot;
    BinToOnehot #(.BIN_W(3), .WIDTH(8)) u_bin2oh (.bin(b2o_bin), .en(b2o_en), .onehot(b2o_onehot));

    logic [2:0] pm_sel;
    logic [23:0] pm_data;
    logic [7:0] pm_default, pm_out;
    PriorityMux #(.NR_INPUT(3), .DATA_LEN(8)) u_pm (
        .sel(pm_sel), .data_in(pm_data), .default_val(pm_default), .out(pm_out)
    );

    logic lfsr_en;
    logic [3:0] lfsr_val;
    LFSR #(.WIDTH(4)) u_lfsr (.clk(clk), .rst_n(rst_n), .en(lfsr_en), .val(lfsr_val));

    logic [1:0] mux_key;
    logic [7:0] mux_out, mux_def_out, mux2_out, mux4_out;
    logic mux2_sel;
    logic [1:0] mux4_sel;
    MuxKey #(.NR_KEY(2), .KEY_LEN(2), .DATA_LEN(8)) u_muxkey (
        .out(mux_out), .key(mux_key), .lut({2'd2, 8'h22, 2'd1, 8'h11})
    );
    MuxKeyWithDefault #(.NR_KEY(2), .KEY_LEN(2), .DATA_LEN(8)) u_muxkeyd (
        .out(mux_def_out), .key(mux_key), .default_out(8'hee),
        .lut({2'd2, 8'h22, 2'd1, 8'h11})
    );
    Mux2 #(.WIDTH(8)) u_mux2 (.sel(mux2_sel), .d0(8'h10), .d1(8'h20), .out(mux2_out));
    Mux4 #(.WIDTH(8)) u_mux4 (.sel(mux4_sel), .d0(8'h10), .d1(8'h20), .d2(8'h30), .d3(8'h40), .out(mux4_out));

    initial begin
        tb_start();
        rst = 1'b0; wen = 1'b0; din = 8'h0; pipe_flush = 1'b0; pipe_stall = 1'b0;
        sdp_we = 1'b0; sdp_waddr = 0; sdp_raddr = 0; sdp_wdata = 0;
        tdp_a_we = 0; tdp_b_we = 0; tdp_a_addr = 0; tdp_b_addr = 0; tdp_a_wdata = 0; tdp_b_wdata = 0;
        sat_rst = 0; sat_en = 0; sat_inc = 0; onehot = 0; b2o_en = 0; b2o_bin = 0;
        pm_sel = 0; pm_data = {8'h33, 8'h22, 8'h11}; pm_default = 8'hee;
        lfsr_en = 0; mux_key = 0; mux2_sel = 0; mux4_sel = 0;
        reset_dut();

        rst = 1'b1; tick(); rst = 1'b0;
        `check32("Reg reset", {24'h0, reg_dout}, 32'h5a);
        `check32("RegAsyncRst reset", {24'h0, async_dout}, 32'ha5);
        din = 8'h12; wen = 1'b0; tick();
        `check32("Reg hold", {24'h0, reg_dout}, 32'h5a);
        wen = 1'b1; tick(); wen = 1'b0;
        `check32("Reg write", {24'h0, reg_dout}, 32'h12);
        din = 8'h34; wen = 1'b1; tick(); wen = 1'b0;
        `check32("RegAsyncRst write", {24'h0, async_dout}, 32'h34);

        din = 8'h44; tick();
        `check32("PipeReg load", {24'h0, pipe_dout}, 32'h44);
        din = 8'h55; pipe_stall = 1'b1; tick(); pipe_stall = 1'b0;
        `check32("PipeReg stall", {24'h0, pipe_dout}, 32'h44);
        pipe_flush = 1'b1; tick(); pipe_flush = 1'b0;
        `check32("PipeReg flush", {24'h0, pipe_dout}, 32'hc3);

        sdp_we = 1'b1; sdp_waddr = 2'd2; sdp_wdata = 16'hbeef; sdp_raddr = 2'd2; tick();
        sdp_we = 1'b0; tick();
        `check32("BramSDP readback", {16'h0, sdp_rdata}, 32'hbeef);

        tdp_a_we = 1'b1; tdp_a_addr = 2'd1; tdp_a_wdata = 16'h1111;
        tdp_b_we = 1'b1; tdp_b_addr = 2'd2; tdp_b_wdata = 16'h2222; tick();
        tdp_a_we = 1'b0; tdp_b_we = 1'b0; tick();
        `check32("BramTDP A", {16'h0, tdp_a_rdata}, 32'h1111);
        `check32("BramTDP B", {16'h0, tdp_b_rdata}, 32'h2222);

        sat_rst = 1'b1; tick(); sat_rst = 1'b0;
        sat_en = 1'b1; sat_inc = 1'b1; repeat (4) tick();
        `check32("SatCounter high", {30'h0, sat_cnt}, 32'h3);
        sat_inc = 1'b0; repeat (5) tick(); sat_en = 1'b0;
        `check32("SatCounter low", {30'h0, sat_cnt}, 32'h0);

        onehot = 8'b0010_0000; #1;
        `check("OnehotToBin valid", oh_valid);
        `check32("OnehotToBin index", {29'h0, bin}, 32'h5);
        b2o_en = 1'b1; b2o_bin = 3'd6; #1;
        `check32("BinToOnehot", {24'h0, b2o_onehot}, 32'h40);
        pm_sel = 3'b110; #1;
        `check32("PriorityMux priority", {24'h0, pm_out}, 32'h22);
        lfsr_en = 1'b1; tick(); lfsr_en = 1'b0;
        `check("LFSR nonzero", lfsr_val != 4'h0);
        mux_key = 2'd2; #1;
        `check32("MuxKey hit", {24'h0, mux_out}, 32'h22);
        mux_key = 2'd3; #1;
        `check32("MuxKeyWithDefault miss", {24'h0, mux_def_out}, 32'hee);
        mux2_sel = 1'b1; mux4_sel = 2'd3; #1;
        `check32("Mux2", {24'h0, mux2_out}, 32'h20);
        `check32("Mux4", {24'h0, mux4_out}, 32'h40);
        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module sram_wrap_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic req, wr, addr_ok, data_ok, ram_en;
    logic [1:0] size;
    logic [3:0] wstrb, ram_we;
    logic [31:0] addr, wdata, rdata, ram_addr, ram_wdata, ram_rdata;
    sram_wrap u_dut (
        .clk(clk), .resetn(rst_n), .req(req), .wr(wr), .size(size), .wstrb(wstrb),
        .addr(addr), .wdata(wdata), .addr_ok(addr_ok), .data_ok(data_ok),
        .rdata(rdata), .ram_en(ram_en), .ram_we(ram_we), .ram_addr(ram_addr),
        .ram_wdata(ram_wdata), .ram_rdata(ram_rdata)
    );

    initial begin
        tb_start();
        req = 0; wr = 0; size = 2'd2; wstrb = 4'hf; addr = 0; wdata = 0; ram_rdata = 0;
        reset_dut();
        req = 1'b1; wr = 1'b1; size = 2'd0; addr = 32'h1003; wdata = 32'h12345678; ram_rdata = 32'haabbccdd; #1;
        `check("addr_ok accepts", addr_ok);
        `check("byte mask", ram_we == 4'b1000);
        tick();
        `check("data_ok next cycle", data_ok);
        req = 1'b0; wr = 1'b0; ram_rdata = 32'hfacefeed; #1;
        `check32("read data path", rdata, 32'hfacefeed);
        finish_tb();
    end
endmodule

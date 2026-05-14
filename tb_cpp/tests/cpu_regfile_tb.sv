`timescale 1ns / 1ps

module cpu_regfile_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic we;
    logic [4:0] waddr, raddr1, raddr2;
    logic [31:0] wdata, rdata1, rdata2;
    cpu_regfile u_dut (
        .clk(clk), .we_i(we), .waddr_i(waddr), .wdata_i(wdata),
        .raddr1_i(raddr1), .raddr2_i(raddr2), .rdata1_o(rdata1), .rdata2_o(rdata2)
    );

    initial begin
        tb_start();
        rst_n = 1'b1; we = 0; waddr = 0; wdata = 0; raddr1 = 0; raddr2 = 0;
        we = 1'b1; waddr = 5'd4; wdata = 32'h12345678; raddr1 = 5'd4; raddr2 = 5'd0; tick();
        we = 1'b0; tick();
        `check32("Regfile read-after-write", rdata1, 32'h12345678);
        `check32("Regfile r0 zero", rdata2, 32'h0);
        finish_tb();
    end
endmodule

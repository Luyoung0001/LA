`timescale 1ns / 1ps

module ramb36e1_model_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic we;
    logic [14:0] raddr, waddr;
    logic [31:0] wdata, rdata;
    RAMB36E1 #(.RAM_MODE("SDP"), .DOA_REG(0)) u_dut (
        .CLKARDCLK(clk), .ENARDEN(1'b1), .RSTRAMARSTRAM(1'b0), .RSTREGARSTREG(1'b0),
        .REGCEAREGCE(1'b1), .WEA(4'h0), .ADDRARDADDR(raddr), .DIADI(32'h0),
        .DIPADIP(4'h0), .DOADO(rdata), .DOBDO(), .DOPADOP(), .DOPBDOP(),
        .CLKBWRCLK(clk), .ENBWREN(1'b1), .WEBWE({4'h0, {4{we}}}),
        .ADDRBWRADDR(waddr), .DIBDI(wdata), .DIPBDIP(4'h0),
        .CASCADEINA(1'b0), .CASCADEINB(1'b0), .CASCADEOUTA(), .CASCADEOUTB(),
        .INJECTDBITERR(1'b0), .INJECTSBITERR(1'b0), .DBITERR(), .SBITERR(),
        .ECCPARITY(), .RDADDRECC()
    );

    initial begin
        tb_start();
        rst_n = 1'b1; we = 1'b0; raddr = 0; waddr = 0; wdata = 0;
        we = 1'b1; waddr = 15'd32; wdata = 32'hcafebabe; tick();
        we = 1'b0; raddr = 15'd32; tick();
        `check32("RAMB36E1 readback", rdata, 32'hcafebabe);
        finish_tb();
    end
endmodule

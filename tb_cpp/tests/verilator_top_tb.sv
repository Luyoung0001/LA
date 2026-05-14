`timescale 1ns / 1ps

module axi_ram (
    input wire clock, input wire reset,
    input wire [3:0] arid, input wire [31:0] araddr, input wire [7:0] arlen,
    input wire [2:0] arsize, input wire [1:0] arburst, input wire [1:0] arlock,
    input wire [3:0] arcache, input wire [2:0] arprot, input wire arvalid, output wire arready,
    output wire [3:0] rid, output wire [31:0] rdata, output wire [1:0] rresp, output wire rlast,
    output wire rvalid, input wire rready,
    input wire [3:0] awid, input wire [31:0] awaddr, input wire [7:0] awlen,
    input wire [2:0] awsize, input wire [1:0] awburst, input wire [1:0] awlock,
    input wire [3:0] awcache, input wire [2:0] awprot, input wire awvalid, output wire awready,
    input wire [3:0] wid, input wire [31:0] wdata, input wire [3:0] wstrb, input wire wlast,
    input wire wvalid, output wire wready,
    output wire [3:0] bid, output wire [1:0] bresp, output wire bvalid, input wire bready
);
    assign arready = 1'b0;
    assign rid = 4'h0;
    assign rdata = 32'h0;
    assign rresp = 2'b00;
    assign rlast = 1'b0;
    assign rvalid = 1'b0;
    assign awready = 1'b0;
    assign wready = 1'b0;
    assign bid = 4'h0;
    assign bresp = 2'b00;
    assign bvalid = 1'b0;
    wire unused = clock ^ reset ^ ^arid ^ ^araddr ^ ^arlen ^ ^arsize ^ ^arburst ^
                  ^arlock ^ ^arcache ^ ^arprot ^ arvalid ^ rready ^ ^awid ^
                  ^awaddr ^ ^awlen ^ ^awsize ^ ^awburst ^ ^awlock ^ ^awcache ^
                  ^awprot ^ awvalid ^ ^wid ^ ^wdata ^ ^wstrb ^ wlast ^ wvalid ^ bready;
endmodule

module verilator_top_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    verilator_top u_dut (.rst(~rst_n), .clk(clk));

    initial begin
        tb_start();
        reset_dut();
        repeat (4) tick();
        `check("verilator_top elaborates with AXI stub", 1'b1);
        finish_tb();
    end
endmodule

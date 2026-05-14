`timescale 1ns / 1ps

module axi_arbiter_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic m0_arvalid, m0_arready, m0_rvalid, m0_rready, m0_rlast;
    logic m1_arvalid, m1_arready, m1_rvalid, m1_rready, m1_rlast;
    logic m1_awvalid, m1_awready, m1_wvalid, m1_wready, m1_wlast, m1_bvalid, m1_bready;
    logic s_arvalid, s_arready, s_rvalid, s_rready, s_rlast;
    logic s_awvalid, s_awready, s_wvalid, s_wready, s_wlast, s_bvalid, s_bready;
    logic [31:0] m0_araddr, m0_rdata, m1_araddr, m1_awaddr, m1_wdata, m1_rdata;
    logic [31:0] s_araddr, s_rdata, s_awaddr, s_wdata;
    logic [3:0] m0_arid, m0_rid, m1_arid, m1_rid, m1_awid, m1_bid, s_arid, s_rid, s_awid, s_bid;
    logic [7:0] m0_arlen, m1_arlen, m1_awlen, s_arlen, s_awlen;
    logic [2:0] m0_arsize, m1_arsize, m1_awsize, s_arsize, s_awsize;
    logic [1:0] m0_arburst, m0_rresp, m1_arburst, m1_rresp, m1_awburst, m1_bresp;
    logic [1:0] s_arburst, s_rresp, s_awburst, s_bresp;
    logic [3:0] m1_wstrb, s_wstrb;

    axi_arbiter u_dut (
        .clk(clk), .rst_n(rst_n), .m0_axi_arvalid_i(m0_arvalid), .m0_axi_arready_o(m0_arready),
        .m0_axi_araddr_i(m0_araddr), .m0_axi_arid_i(m0_arid), .m0_axi_arlen_i(m0_arlen),
        .m0_axi_arsize_i(m0_arsize), .m0_axi_arburst_i(m0_arburst),
        .m0_axi_rvalid_o(m0_rvalid), .m0_axi_rready_i(m0_rready),
        .m0_axi_rdata_o(m0_rdata), .m0_axi_rresp_o(m0_rresp), .m0_axi_rid_o(m0_rid),
        .m0_axi_rlast_o(m0_rlast), .m1_axi_arvalid_i(m1_arvalid), .m1_axi_arready_o(m1_arready),
        .m1_axi_araddr_i(m1_araddr), .m1_axi_arid_i(m1_arid), .m1_axi_arlen_i(m1_arlen),
        .m1_axi_arsize_i(m1_arsize), .m1_axi_arburst_i(m1_arburst),
        .m1_axi_rvalid_o(m1_rvalid), .m1_axi_rready_i(m1_rready),
        .m1_axi_rdata_o(m1_rdata), .m1_axi_rresp_o(m1_rresp), .m1_axi_rid_o(m1_rid),
        .m1_axi_rlast_o(m1_rlast), .m1_axi_awvalid_i(m1_awvalid), .m1_axi_awready_o(m1_awready),
        .m1_axi_awaddr_i(m1_awaddr), .m1_axi_awid_i(m1_awid), .m1_axi_awlen_i(m1_awlen),
        .m1_axi_awsize_i(m1_awsize), .m1_axi_awburst_i(m1_awburst),
        .m1_axi_wvalid_i(m1_wvalid), .m1_axi_wready_o(m1_wready),
        .m1_axi_wdata_i(m1_wdata), .m1_axi_wstrb_i(m1_wstrb), .m1_axi_wlast_i(m1_wlast),
        .m1_axi_bvalid_o(m1_bvalid), .m1_axi_bready_i(m1_bready), .m1_axi_bresp_o(m1_bresp),
        .m1_axi_bid_o(m1_bid), .s_axi_arvalid_o(s_arvalid), .s_axi_arready_i(s_arready),
        .s_axi_araddr_o(s_araddr), .s_axi_arid_o(s_arid), .s_axi_arlen_o(s_arlen),
        .s_axi_arsize_o(s_arsize), .s_axi_arburst_o(s_arburst),
        .s_axi_rvalid_i(s_rvalid), .s_axi_rready_o(s_rready),
        .s_axi_rdata_i(s_rdata), .s_axi_rresp_i(s_rresp), .s_axi_rid_i(s_rid), .s_axi_rlast_i(s_rlast),
        .s_axi_awvalid_o(s_awvalid), .s_axi_awready_i(s_awready), .s_axi_awaddr_o(s_awaddr),
        .s_axi_awid_o(s_awid), .s_axi_awlen_o(s_awlen), .s_axi_awsize_o(s_awsize),
        .s_axi_awburst_o(s_awburst),
        .s_axi_wvalid_o(s_wvalid), .s_axi_wready_i(s_wready), .s_axi_wdata_o(s_wdata),
        .s_axi_wstrb_o(s_wstrb), .s_axi_wlast_o(s_wlast), .s_axi_bvalid_i(s_bvalid),
        .s_axi_bready_o(s_bready), .s_axi_bresp_i(s_bresp), .s_axi_bid_i(s_bid)
    );

    initial begin
        tb_start();
        m0_arvalid = 0; m0_araddr = 0; m0_arid = 0; m0_arlen = 0; m0_arsize = 3'b010; m0_arburst = 2'b01; m0_rready = 1;
        m1_arvalid = 0; m1_araddr = 0; m1_arid = 0; m1_arlen = 0; m1_arsize = 3'b010; m1_arburst = 2'b01; m1_rready = 1;
        m1_awvalid = 0; m1_awaddr = 0; m1_awid = 0; m1_awlen = 0; m1_awsize = 3'b010; m1_awburst = 2'b01; m1_wvalid = 0; m1_wdata = 0; m1_wstrb = 0; m1_wlast = 0; m1_bready = 1;
        s_arready = 1; s_rvalid = 0; s_rdata = 0; s_rresp = 0; s_rid = 0; s_rlast = 0; s_awready = 1; s_wready = 1; s_bvalid = 0; s_bresp = 0; s_bid = 0;
        reset_dut();
        m0_arvalid = 1; m0_araddr = 32'h1000; m0_arid = 4'h1; m0_arlen = 8'h3; m0_arsize = 3'b010;
        m1_arvalid = 1; m1_araddr = 32'h2000; m1_arid = 4'h2; m1_arsize = 3'b000; #1;
        `check("AXI M0 priority", s_arvalid && m0_arready && !m1_arready);
        `check32("AXI M0 addr", s_araddr, 32'h1000);
        `check("AXI M0 size", s_arsize == 3'b010);
        tick();
        s_rvalid = 1; s_rdata = 32'hfeedcafe; s_rid = 4'h1; s_rlast = 0; #1;
        `check("AXI R routes to M0", m0_rvalid && !m1_rvalid);
        tick(); s_rlast = 1; tick();
        m0_arvalid = 0; s_rvalid = 0; s_rlast = 0; tick();
        m1_awvalid = 1; m1_awaddr = 32'h3000; m1_awid = 4'h3; m1_awsize = 3'b000; m1_wvalid = 1; m1_wdata = 32'h55aa55aa; m1_wstrb = 4'hf; m1_wlast = 1; #1;
        `check("AXI AW pass", s_awvalid && m1_awready && s_awaddr == 32'h3000);
        `check("AXI AW size pass", s_awsize == 3'b000);
        `check("AXI W pass", s_wvalid && m1_wready && s_wdata == 32'h55aa55aa);
        s_bvalid = 1; s_bid = 4'h3; #1;
        `check("AXI B route", m1_bvalid && m1_bid == 4'h3);
        finish_tb();
    end
endmodule

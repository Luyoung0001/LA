`timescale 1ns / 1ps

module fpga_pipeline_cpu_top_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic commit_valid;
    logic [31:0] commit_pc, commit_instr;
    logic [7:0] interrupt_i;
    logic arvalid, arready, rvalid, rready, rlast, awvalid, awready, wvalid, wready, wlast, bvalid, bready;
    logic [31:0] araddr, rdata, awaddr, wdata;
    logic [3:0] arid, rid, awid, wstrb, bid;
    logic [7:0] arlen, awlen;
    logic [2:0] arsize, awsize;
    logic [1:0] arburst, rresp, awburst, bresp;

    fpga_pipeline_cpu_top u_dut (
        .clk(clk), .rst_n(rst_n), .interrupt_i(interrupt_i),
        .commit_valid_o(commit_valid), .commit_pc_o(commit_pc),
        .commit_instr_o(commit_instr), .axi_arvalid_o(arvalid), .axi_arready_i(arready),
        .axi_araddr_o(araddr), .axi_arid_o(arid), .axi_arlen_o(arlen),
        .axi_arsize_o(arsize), .axi_arburst_o(arburst),
        .axi_rvalid_i(rvalid), .axi_rready_o(rready), .axi_rdata_i(rdata), .axi_rresp_i(rresp),
        .axi_rid_i(rid), .axi_rlast_i(rlast), .axi_awvalid_o(awvalid), .axi_awready_i(awready),
        .axi_awaddr_o(awaddr), .axi_awid_o(awid), .axi_awlen_o(awlen),
        .axi_awsize_o(awsize), .axi_awburst_o(awburst),
        .axi_wvalid_o(wvalid), .axi_wready_i(wready), .axi_wdata_o(wdata), .axi_wstrb_o(wstrb),
        .axi_wlast_o(wlast), .axi_bvalid_i(bvalid), .axi_bready_o(bready), .axi_bresp_i(bresp),
        .axi_bid_i(bid)
    );

    wire safe_commit_valid;
    wire [31:0] safe_commit_pc;
    wire [31:0] safe_commit_instr;
    wire safe_arvalid, safe_rready, safe_awvalid, safe_wvalid, safe_wlast, safe_bready;
    wire [31:0] safe_araddr, safe_awaddr, safe_wdata;
    wire [3:0] safe_arid, safe_awid, safe_wstrb;
    wire [7:0] safe_arlen, safe_awlen;
    wire [2:0] safe_arsize, safe_awsize;
    wire [1:0] safe_arburst, safe_awburst;

    wire gated_commit_valid;
    wire [31:0] gated_commit_pc;
    wire [31:0] gated_commit_instr;
    wire gated_arvalid, gated_rready, gated_awvalid, gated_wvalid, gated_wlast, gated_bready;
    wire [31:0] gated_araddr, gated_awaddr, gated_wdata;
    wire [3:0] gated_arid, gated_awid, gated_wstrb;
    wire [7:0] gated_arlen, gated_awlen;
    wire [2:0] gated_arsize, gated_awsize;
    wire [1:0] gated_arburst, gated_awburst;

    fpga_pipeline_cpu_top #(
        .CORE_DUAL_ISSUE_ENABLE(1),
        .CORE_DUAL_COMMIT_ENABLE(0),
        .CORE_SLOT1_ALU_ENABLE(1),
        .CORE_SLOT1_BRANCH_ENABLE(1),
        .CORE_SLOT1_MUL_ENABLE(0),
        .CORE_SLOT1_LOAD_ENABLE(0),
        .CORE_SLOT1_STORE_ENABLE(1)
    ) u_safe_single (
        .clk(clk), .rst_n(rst_n), .interrupt_i(interrupt_i),
        .commit_valid_o(safe_commit_valid),
        .commit_pc_o(safe_commit_pc),
        .commit_instr_o(safe_commit_instr),
        .axi_arvalid_o(safe_arvalid),
        .axi_arready_i(arready),
        .axi_araddr_o(safe_araddr),
        .axi_arid_o(safe_arid),
        .axi_arlen_o(safe_arlen),
        .axi_arsize_o(safe_arsize),
        .axi_arburst_o(safe_arburst),
        .axi_rvalid_i(rvalid),
        .axi_rready_o(safe_rready),
        .axi_rdata_i(rdata),
        .axi_rresp_i(rresp),
        .axi_rid_i(rid),
        .axi_rlast_i(rlast),
        .axi_awvalid_o(safe_awvalid),
        .axi_awready_i(awready),
        .axi_awaddr_o(safe_awaddr),
        .axi_awid_o(safe_awid),
        .axi_awlen_o(safe_awlen),
        .axi_awsize_o(safe_awsize),
        .axi_awburst_o(safe_awburst),
        .axi_wvalid_o(safe_wvalid),
        .axi_wready_i(wready),
        .axi_wdata_o(safe_wdata),
        .axi_wstrb_o(safe_wstrb),
        .axi_wlast_o(safe_wlast),
        .axi_bvalid_i(bvalid),
        .axi_bready_o(safe_bready),
        .axi_bresp_i(bresp),
        .axi_bid_i(bid)
    );

    fpga_pipeline_cpu_top #(
        .CORE_DUAL_ISSUE_ENABLE(1),
        .CORE_DUAL_COMMIT_ENABLE(1),
        .CORE_SLOT1_ALU_ENABLE(1),
        .CORE_SLOT1_BRANCH_ENABLE(0),
        .CORE_SLOT1_MUL_ENABLE(0),
        .CORE_SLOT1_LOAD_ENABLE(0),
        .CORE_SLOT1_STORE_ENABLE(0)
    ) u_alu_only (
        .clk(clk), .rst_n(rst_n), .interrupt_i(interrupt_i),
        .commit_valid_o(gated_commit_valid),
        .commit_pc_o(gated_commit_pc),
        .commit_instr_o(gated_commit_instr),
        .axi_arvalid_o(gated_arvalid),
        .axi_arready_i(arready),
        .axi_araddr_o(gated_araddr),
        .axi_arid_o(gated_arid),
        .axi_arlen_o(gated_arlen),
        .axi_arsize_o(gated_arsize),
        .axi_arburst_o(gated_arburst),
        .axi_rvalid_i(rvalid),
        .axi_rready_o(gated_rready),
        .axi_rdata_i(rdata),
        .axi_rresp_i(rresp),
        .axi_rid_i(rid),
        .axi_rlast_i(rlast),
        .axi_awvalid_o(gated_awvalid),
        .axi_awready_i(awready),
        .axi_awaddr_o(gated_awaddr),
        .axi_awid_o(gated_awid),
        .axi_awlen_o(gated_awlen),
        .axi_awsize_o(gated_awsize),
        .axi_awburst_o(gated_awburst),
        .axi_wvalid_o(gated_wvalid),
        .axi_wready_i(wready),
        .axi_wdata_o(gated_wdata),
        .axi_wstrb_o(gated_wstrb),
        .axi_wlast_o(gated_wlast),
        .axi_bvalid_i(bvalid),
        .axi_bready_o(gated_bready),
        .axi_bresp_i(bresp),
        .axi_bid_i(bid)
    );

    initial begin
        tb_start();
        interrupt_i = 8'b0;
        arready = 0; rvalid = 0; rdata = 0; rresp = 0; rid = 0; rlast = 0; awready = 0; wready = 0; bvalid = 0; bresp = 0; bid = 0;
        reset_dut();
        repeat (4) tick();
        `check("top elaborates and waits without memory", !commit_valid);
        `check("top enables restricted dual issue by default", u_dut.u_core.core_dual_issue_enable_w);
        `check("top enables dual commit by default", u_dut.u_core.core_dual_commit_enable_w);
        `check("top routes default dual issue to fetch-buffer slot consume",
               u_dut.u_core.u_fb.dual_slot_consume_i);
        `check("top default keeps current accepted slot1 classes enabled",
               u_dut.u_core.core_slot1_alu_enable_w &&
               u_dut.u_core.core_slot1_branch_enable_w &&
               u_dut.u_core.core_slot1_store_enable_w);
        `check("top default keeps experimental slot1 mul/load disabled",
               !u_dut.u_core.core_slot1_mul_enable_w &&
               !u_dut.u_core.core_slot1_load_enable_w);
        `check("top disables dual commit when parameter requests single commit",
               !u_safe_single.u_core.core_dual_commit_enable_w);
        `check("top gates dual issue off without ordered dual commit",
               !u_safe_single.u_core.core_dual_issue_enable_w);
        `check("top issue-only config keeps fetch buffer single slot",
               !u_safe_single.u_core.u_fb.dual_slot_consume_i);
        `check("top issue-only config elaborates single-write regfile",
               u_safe_single.u_core.gen_single_write_regfiles.u_regfile.XLEN == 32);
        `check("top can reduce slot1 to ALU-only for acceptance experiments",
               u_alu_only.u_core.core_slot1_alu_enable_w &&
               !u_alu_only.u_core.core_slot1_branch_enable_w &&
               !u_alu_only.u_core.core_slot1_mul_enable_w &&
               !u_alu_only.u_core.core_slot1_load_enable_w &&
               !u_alu_only.u_core.core_slot1_store_enable_w);
        finish_tb();
    end
endmodule

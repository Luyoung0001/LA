`timescale 1ns / 1ps

module cpu_l2_cache_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic l1i_req_valid, l1i_prefetch, l1i_ready, l1i_resp_valid, l1i_pf_resp_valid;
    logic l1d_rd_valid, l1d_rd_uncached, l1d_rd_ready, l1d_resp_valid, l1d_wr_valid, l1d_wr_ready, l1d_wr_done;
    logic axi_arvalid, axi_arready, axi_rvalid, axi_rready, axi_rlast;
    logic axi_awvalid, axi_awready, axi_wvalid, axi_wready, axi_wlast, axi_bvalid, axi_bready;
    logic [31:0] l1i_addr, l1d_rd_addr, l1d_wr_addr, l1d_wr_data, l1i_pf_resp_addr;
    logic [31:0] l1i_r0, l1i_r1, l1i_r2, l1i_r3, l1d_r0, l1d_r1, l1d_r2, l1d_r3;
    logic [31:0] l1i_pf_r0, l1i_pf_r1, l1i_pf_r2, l1i_pf_r3;
    logic [31:0] axi_araddr, axi_rdata, axi_awaddr, axi_wdata;
    logic [3:0] l1d_wr_strb, axi_arid, axi_awid, axi_wstrb, axi_rid, axi_bid;
    logic [7:0] axi_arlen, axi_awlen;
    logic [2:0] axi_arsize, axi_awsize;
    logic [1:0] axi_arburst, axi_awburst, axi_rresp, axi_bresp;
    logic [1:0] l1d_rd_size;
    cpu_l2_cache #(
        .NUM_WAYS(4), .NUM_LINES(16), .LINE_SIZE(32), .L1_LINE_SIZE(16),
        .ENABLE_PREFETCH(1)
    ) u_dut (
        .clk(clk), .rst_n(rst_n), .l1i_req_valid_i(l1i_req_valid), .l1i_req_addr_i(l1i_addr),
        .l1i_req_is_prefetch_i(l1i_prefetch), .l1i_req_ready_o(l1i_ready),
        .l1i_resp_valid_o(l1i_resp_valid), .l1i_resp_data_o_0(l1i_r0),
        .l1i_resp_data_o_1(l1i_r1), .l1i_resp_data_o_2(l1i_r2), .l1i_resp_data_o_3(l1i_r3),
        .l1i_pf_resp_valid_o(l1i_pf_resp_valid), .l1i_pf_resp_addr_o(l1i_pf_resp_addr),
        .l1i_pf_resp_data_o_0(l1i_pf_r0), .l1i_pf_resp_data_o_1(l1i_pf_r1),
        .l1i_pf_resp_data_o_2(l1i_pf_r2), .l1i_pf_resp_data_o_3(l1i_pf_r3),
        .l1d_rd_valid_i(l1d_rd_valid), .l1d_rd_addr_i(l1d_rd_addr),
        .l1d_rd_size_i(l1d_rd_size), .l1d_rd_uncached_i(l1d_rd_uncached),
        .l1d_rd_ready_o(l1d_rd_ready),
        .l1d_resp_valid_o(l1d_resp_valid), .l1d_resp_data_o_0(l1d_r0), .l1d_resp_data_o_1(l1d_r1),
        .l1d_resp_data_o_2(l1d_r2), .l1d_resp_data_o_3(l1d_r3), .l1d_wr_valid_i(l1d_wr_valid),
        .l1d_wr_addr_i(l1d_wr_addr), .l1d_wr_data_i(l1d_wr_data), .l1d_wr_strb_i(l1d_wr_strb),
        .l1d_wr_ready_o(l1d_wr_ready), .l1d_wr_done_o(l1d_wr_done), .axi_arvalid_o(axi_arvalid),
        .axi_arready_i(axi_arready), .axi_araddr_o(axi_araddr), .axi_arid_o(axi_arid),
        .axi_arlen_o(axi_arlen), .axi_arsize_o(axi_arsize),
        .axi_arburst_o(axi_arburst), .axi_rvalid_i(axi_rvalid),
        .axi_rready_o(axi_rready), .axi_rdata_i(axi_rdata), .axi_rresp_i(axi_rresp),
        .axi_rid_i(axi_rid), .axi_rlast_i(axi_rlast), .axi_awvalid_o(axi_awvalid),
        .axi_awready_i(axi_awready), .axi_awaddr_o(axi_awaddr), .axi_awid_o(axi_awid),
        .axi_awlen_o(axi_awlen), .axi_awsize_o(axi_awsize),
        .axi_awburst_o(axi_awburst), .axi_wvalid_o(axi_wvalid),
        .axi_wready_i(axi_wready), .axi_wdata_o(axi_wdata), .axi_wstrb_o(axi_wstrb),
        .axi_wlast_o(axi_wlast), .axi_bvalid_i(axi_bvalid), .axi_bready_o(axi_bready),
        .axi_bresp_i(axi_bresp), .axi_bid_i(axi_bid)
    );

    integer i;
    bit saw_early_resp;
    bit saw_promoted_resp;
    bit saw_buddy_resp;
    bit saw_bgpf_lower_resp;
    bit saw_bgpf_upper_resp;
    bit saw_bgpf_hit_under_resp;
    bit saw_hazard_axi_read;
    initial begin
        tb_start();
        l1i_req_valid = 0; l1i_addr = 0; l1i_prefetch = 0; l1d_rd_valid = 0; l1d_rd_addr = 0;
        l1d_rd_size = 2'b10; l1d_rd_uncached = 0;
        l1d_wr_valid = 0; l1d_wr_addr = 0; l1d_wr_data = 0; l1d_wr_strb = 0;
        axi_arready = 1; axi_rvalid = 0; axi_rdata = 0; axi_rresp = 0; axi_rid = 4'hf; axi_rlast = 0;
        axi_awready = 1; axi_wready = 1; axi_bvalid = 0; axi_bresp = 0; axi_bid = 4'hf;
        saw_early_resp = 1'b0;
        saw_promoted_resp = 1'b0;
        saw_buddy_resp = 1'b0;
        saw_bgpf_lower_resp = 1'b0;
        saw_bgpf_upper_resp = 1'b0;
        saw_bgpf_hit_under_resp = 1'b0;
        reset_dut();

        l1d_rd_valid = 1; l1d_rd_uncached = 1; l1d_rd_size = 2'b00; l1d_rd_addr = 32'h1fe0_01e5;
        tick();
        l1d_rd_valid = 0; l1d_rd_uncached = 0; l1d_rd_size = 2'b10; #1;
        `check("L2 uncached read issues immediate AXI", axi_arvalid);
        `check32("L2 uncached exact addr", axi_araddr, 32'h1fe001e5);
        `check("L2 uncached single beat byte", axi_arlen == 8'h00 && axi_arsize == 3'b000);
        axi_rvalid = 1; axi_rdata = 32'h0000_ab00; axi_rlast = 1; tick();
        axi_rvalid = 0; axi_rlast = 0; #1;
        `check("L2 uncached L1D response", l1d_resp_valid);
        `check32("L2 uncached raw data", l1d_r0, 32'h0000ab00);

        l1d_rd_valid = 1; l1d_rd_addr = 32'h4000; tick(); l1d_rd_valid = 0;
        `check("L2 direct lookup waits exactly one BRAM cycle", !axi_arvalid);
        tick();
        `check("L2 direct lookup AXI read", axi_arvalid);
        `check32("L2 AXI line addr", axi_araddr, 32'h4000);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1; axi_rdata = 32'h9000_0000 + i[31:0]; axi_rlast = (i == 7); tick();
            if (i == 3) begin
                saw_early_resp = l1d_resp_valid;
                `check("L2 early L1D response", l1d_resp_valid);
                `check32("L2 early word0", l1d_r0, 32'h90000000);
                `check32("L2 early word3", l1d_r3, 32'h90000003);
            end
        end
        axi_rvalid = 0; axi_rlast = 0;
        `check("L2 response observed before rlast", saw_early_resp);

        repeat (4) begin
            tick();
            `check("L2 does not prefetch after L1D demand", !axi_arvalid);
        end

        l1i_req_valid = 1; l1i_addr = 32'h4020; tick(); l1i_req_valid = 0;
        `check("L2 L1I lookup waits exactly one BRAM cycle", !axi_arvalid);
        tick();
        `check("L2 L1I miss AXI read", axi_arvalid);
        `check32("L2 L1I miss line addr", axi_araddr, 32'h4020);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1; axi_rdata = 32'ha000_0000 + i[31:0]; axi_rlast = (i == 7);
            tick();
            if (i == 3) begin
                `check("L2 L1I early response", l1i_resp_valid);
                `check32("L2 L1I word0", l1i_r0, 32'ha0000000);
                `check32("L2 L1I word3", l1i_r3, 32'ha0000003);
            end
            if (i == 7) begin
                saw_buddy_resp = l1i_pf_resp_valid;
                `check("L2 buddy half response", l1i_pf_resp_valid);
                `check32("L2 buddy half addr", l1i_pf_resp_addr, 32'h4030);
                `check32("L2 buddy half word0", l1i_pf_r0, 32'ha0000004);
                `check32("L2 buddy half word3", l1i_pf_r3, 32'ha0000007);
            end
        end
        axi_rvalid = 0; axi_rlast = 0;
        `check("L2 buddy response at refill tail", saw_buddy_resp);

        `wait_signal("L2 auto L1I prefetch read", 20, axi_arvalid);
        `check32("L2 L1I prefetch line addr", axi_araddr, 32'h4040);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1; axi_rdata = 32'hb000_0000 + i[31:0]; axi_rlast = (i == 7);
            if (i == 1) begin
                l1i_req_valid = 1; l1i_addr = 32'h4040; #1;
                `check("L2 promotes in-flight L1I prefetch", l1i_ready);
            end
            tick();
            if (i == 1)
                l1i_req_valid = 0;
            if (i == 3) begin
                saw_promoted_resp = l1i_resp_valid;
                `check("L2 promoted L1I response", l1i_resp_valid);
                `check32("L2 promoted word0", l1i_r0, 32'hb0000000);
                `check32("L2 promoted word3", l1i_r3, 32'hb0000003);
            end
        end
        axi_rvalid = 0; axi_rlast = 0;
        `check("L2 promoted response before prefetch rlast", saw_promoted_resp);

        `wait_signal("L2 chained L1I background prefetch read", 20, axi_arvalid);
        `check32("L2 chained background prefetch line addr", axi_araddr, 32'h4060);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1; axi_rdata = 32'hc000_0000 + i[31:0]; axi_rlast = (i == 7);
            if (i == 1) begin
                l1i_req_valid = 1;
                l1i_addr = 32'h4020;
                #1;
                `check("L2 accepts L1I hit under background prefetch", l1i_ready);
            end
            tick();
            if (i == 1)
                l1i_req_valid = 0;
            if (l1i_resp_valid) begin
                saw_bgpf_hit_under_resp = 1'b1;
                `check32("L2 hit-under-bgpf word0", l1i_r0, 32'ha0000000);
                `check32("L2 hit-under-bgpf word3", l1i_r3, 32'ha0000003);
            end
            if (i == 3) begin
                saw_bgpf_lower_resp = l1i_pf_resp_valid;
                `check("L2 background prefetch lower sideband", l1i_pf_resp_valid);
                `check32("L2 background lower addr", l1i_pf_resp_addr, 32'h4060);
                `check32("L2 background lower word0", l1i_pf_r0, 32'hc0000000);
                `check32("L2 background lower word3", l1i_pf_r3, 32'hc0000003);
            end
            if (i == 7) begin
                saw_bgpf_upper_resp = l1i_pf_resp_valid;
                `check("L2 background prefetch upper sideband", l1i_pf_resp_valid);
                `check32("L2 background upper addr", l1i_pf_resp_addr, 32'h4070);
                `check32("L2 background upper word0", l1i_pf_r0, 32'hc0000004);
                `check32("L2 background upper word3", l1i_pf_r3, 32'hc0000007);
            end
        end
        axi_rvalid = 0; axi_rlast = 0;
        `check("L2 hit-under-bgpf response observed", saw_bgpf_hit_under_resp);
        `check("L2 background lower sideband observed", saw_bgpf_lower_resp);
        `check("L2 background upper sideband observed", saw_bgpf_upper_resp);

        l1i_prefetch = 1; l1i_req_valid = 1; l1i_addr = 32'h4020; tick();
        l1i_req_valid = 0; l1i_prefetch = 0;
        `wait_signal("L2 external L1I prefetch response", 8, l1i_resp_valid);
        `check32("L2 external prefetch word0", l1i_r0, 32'ha0000000);
        `check32("L2 external prefetch word3", l1i_r3, 32'ha0000003);

        l1d_wr_valid = 1; l1d_wr_addr = 32'h4008; l1d_wr_data = 32'hcafebabe; l1d_wr_strb = 4'hf; tick(); l1d_wr_valid = 0; #1;
        `check("L2 AW", axi_awvalid && axi_awaddr == 32'h4008);
        `check("L2 W", axi_wvalid && axi_wdata == 32'hcafebabe);
        axi_bvalid = 1; tick(); axi_bvalid = 0; #1;
        `check("L2 write done", l1d_wr_done);

        l1d_wr_valid = 1; l1d_wr_addr = 32'h6008; l1d_wr_data = 32'h1111_2222; l1d_wr_strb = 4'hf;
        tick(); l1d_wr_valid = 0; #1;
        `check("L2 hazard write accepted", axi_awvalid && axi_awaddr == 32'h6008 && axi_wvalid);

        l1d_rd_valid = 1; l1d_rd_addr = 32'h6010; #1;
        `check("L2 blocks same-line L1D read while write pending", !l1d_rd_ready);
        repeat (2) begin
            tick(); #1;
            `check("L2 keeps same-line L1D read blocked before B", !l1d_rd_ready);
            `check("L2 issues no same-line read before B", !axi_arvalid);
        end
        axi_bvalid = 1; tick(); axi_bvalid = 0; #1;
        `check("L2 completes pending write before same-line read", l1d_wr_done);
        `check("L2 releases same-line L1D read after B", l1d_rd_ready);
        tick(); l1d_rd_valid = 0;
        tick(); #1;
        `check("L2 same-line L1D read issues after B", axi_arvalid && axi_araddr == 32'h6000);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1;
            axi_rdata = 32'h6000_0000 + i[31:0];
            axi_rlast = (i == 7);
            tick();
        end
        axi_rvalid = 0; axi_rlast = 0;

        reset_dut();
        l1i_req_valid = 0; l1i_prefetch = 0; l1d_rd_valid = 0; l1d_rd_uncached = 0;
        l1d_wr_valid = 0; axi_arready = 1; axi_awready = 0; axi_wready = 0;
        axi_rvalid = 0; axi_rlast = 0; axi_bvalid = 0;
        l1d_wr_valid = 1; l1d_wr_addr = 32'h6108; l1d_wr_data = 32'h2222_3333; l1d_wr_strb = 4'hf;
        #1;
        `check("L2 blocks same-line L1D read while queued write not accepted",
               !l1d_rd_ready || !l1d_rd_valid);
        l1d_rd_valid = 1; l1d_rd_addr = 32'h6110; #1;
        `check("L2 blocks same-line L1D read before write accept", !l1d_rd_ready);
        l1d_rd_valid = 0;
        l1i_req_valid = 1; l1i_addr = 32'h6100; #1;
        `check("L2 blocks same-line L1I read before write accept", !l1i_ready);
        l1i_req_valid = 0;
        tick();
        `check("L2 queued write still valid under AXI backpressure", axi_awvalid && axi_wvalid);
        axi_awready = 1; axi_wready = 1; tick();
        l1d_wr_valid = 0; #1;
        `check("L2 accepts queued write after AXI ready", axi_awvalid || axi_wvalid || !l1d_wr_ready);
        l1d_rd_valid = 1; l1d_rd_addr = 32'h6110; #1;
        `check("L2 keeps same-line L1D read blocked after accept before B", !l1d_rd_ready);
        axi_bvalid = 1; tick(); axi_bvalid = 0; #1;
        `check("L2 releases same-line L1D read after queued write B", l1d_rd_ready);
        l1d_rd_valid = 0;
        axi_awready = 1; axi_wready = 1;

        l1d_wr_valid = 1; l1d_wr_addr = 32'h7020; l1d_wr_data = 32'h3333_4444; l1d_wr_strb = 4'hf;
        tick(); l1d_wr_valid = 0; #1;
        l1i_req_valid = 1; l1i_addr = 32'h7020; #1;
        `check("L2 blocks same-line L1I read while write pending", !l1i_ready);
        repeat (2) begin
            tick(); #1;
            `check("L2 keeps same-line L1I read blocked before B", !l1i_ready);
            `check("L2 issues no same-line L1I read before B", !axi_arvalid);
        end
        axi_bvalid = 1; tick(); axi_bvalid = 0; #1;
        `check("L2 releases same-line L1I read after B", l1i_ready);
        tick(); l1i_req_valid = 0;
        tick(); #1;
        `check("L2 same-line L1I read issues after B", axi_arvalid && axi_araddr == 32'h7020);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1;
            axi_rdata = 32'h7000_0000 + i[31:0];
            axi_rlast = (i == 7);
            if (i == 7) begin
                l1d_wr_valid = 1;
                l1d_wr_addr = 32'h7044;
                l1d_wr_data = 32'h5555_6666;
                l1d_wr_strb = 4'hf;
            end
            tick();
            if (i == 7)
                l1d_wr_valid = 0;
        end
        axi_rvalid = 0; axi_rlast = 0;
        #1;
        `check("L2 accepts store to pending background prefetch line", axi_awvalid && axi_awaddr == 32'h7044);
        saw_hazard_axi_read = 1'b0;
        repeat (4) begin
            tick(); #1;
            if (axi_arvalid)
                saw_hazard_axi_read = 1'b1;
        end
        `check("L2 blocks same-line background prefetch before B", !saw_hazard_axi_read);
        axi_bvalid = 1; tick(); axi_bvalid = 0; #1;
        `wait_signal("L2 releases same-line background prefetch after B", 8, axi_arvalid);
        `check32("L2 delayed background prefetch addr", axi_araddr, 32'h7040);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1;
            axi_rdata = 32'h7200_0000 + i[31:0];
            axi_rlast = (i == 7);
            tick();
        end
        axi_rvalid = 0; axi_rlast = 0;

        reset_dut();
        l1i_req_valid = 0; l1i_prefetch = 0; l1d_rd_valid = 0; l1d_rd_uncached = 0;
        l1d_wr_valid = 0; axi_arready = 1; axi_awready = 1; axi_wready = 1;
        axi_rvalid = 0; axi_rlast = 0; axi_bvalid = 0;

        l1d_rd_valid = 1; l1d_rd_addr = 32'h8000; tick(); l1d_rd_valid = 0;
        tick(); #1;
        `check("L2 killed-refill initial AXI read", axi_arvalid && axi_araddr == 32'h8000);
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1;
            axi_rdata = 32'hd000_0000 + i[31:0];
            axi_rlast = (i == 7);
            if (i == 4) begin
                l1d_wr_valid = 1;
                l1d_wr_addr = 32'h8018;
                l1d_wr_data = 32'h1234_5678;
                l1d_wr_strb = 4'hf;
            end
            tick();
            if (i == 4)
                l1d_wr_valid = 0;
        end
        axi_rvalid = 0; axi_rlast = 0;
        axi_bvalid = 1; tick(); axi_bvalid = 0; #1;
        `check("L2 killed-refill write completes", l1d_wr_done);

        l1d_rd_valid = 1; l1d_rd_addr = 32'h8010; tick(); l1d_rd_valid = 0;
        `wait_signal("L2 killed refill is not installed as hit", 8, axi_arvalid);
        `check32("L2 killed-refill reloads same AXI line", axi_araddr, 32'h8000);
        saw_early_resp = 1'b0;
        for (i = 0; i < 8; i = i + 1) begin
            axi_rvalid = 1;
            axi_rdata = 32'he000_0000 + i[31:0];
            axi_rlast = (i == 7);
            tick();
            if (i == 7) begin
                saw_early_resp = l1d_resp_valid;
                `check("L2 killed-refill high-half response", l1d_resp_valid);
                `check32("L2 killed-refill high-half word0", l1d_r0, 32'he000_0004);
                `check32("L2 killed-refill high-half word3", l1d_r3, 32'he000_0007);
            end
        end
        axi_rvalid = 0; axi_rlast = 0;
        `check("L2 killed-refill response observed", saw_early_resp);
        finish_tb();
    end
endmodule

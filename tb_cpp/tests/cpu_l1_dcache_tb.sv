`timescale 1ns / 1ps

module cpu_l1_dcache_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic req_valid, req_load, req_store, req_uncached, resp_valid, resp_fault, l2_rd_valid, l2_rd_uncached, l2_rd_ready, l2_resp_valid, l2_wr_valid, l2_wr_ready, l2_wr_done;
    logic cacop_valid, cacop_ready, cacop_done;
    logic [1:0] req_size, cacop_mode, l2_rd_size;
    logic [31:0] req_addr, req_store_data, resp_load_data, l2_rd_addr, d0, d1, d2, d3, l2_wr_addr, l2_wr_data, cacop_addr;
    logic [3:0] l2_wr_strb;
    cpu_l1_dcache #(.NUM_LINES(8)) u_dut (
        .clk(clk), .rst_n(rst_n), .req_valid_i(req_valid), .req_is_load_i(req_load),
        .req_is_store_i(req_store), .req_size_i(req_size), .req_addr_i(req_addr),
        .req_store_data_i(req_store_data), .req_uncached_i(req_uncached),
        .resp_valid_o(resp_valid), .resp_load_data_o(resp_load_data),
        .resp_fault_o(resp_fault), .l2_rd_valid_o(l2_rd_valid), .l2_rd_addr_o(l2_rd_addr),
        .l2_rd_size_o(l2_rd_size), .l2_rd_uncached_o(l2_rd_uncached),
        .cacop_valid_i(cacop_valid), .cacop_mode_i(cacop_mode), .cacop_addr_i(cacop_addr),
        .cacop_ready_o(cacop_ready), .cacop_done_o(cacop_done),
        .l2_rd_ready_i(l2_rd_ready), .l2_resp_valid_i(l2_resp_valid), .l2_resp_data_i_0(d0),
        .l2_resp_data_i_1(d1), .l2_resp_data_i_2(d2), .l2_resp_data_i_3(d3),
        .l2_wr_valid_o(l2_wr_valid), .l2_wr_addr_o(l2_wr_addr), .l2_wr_data_o(l2_wr_data),
        .l2_wr_strb_o(l2_wr_strb), .l2_wr_ready_i(l2_wr_ready), .l2_wr_done_i(l2_wr_done)
    );

    task automatic fill_load_line(input [31:0] addr, input [31:0] base_word);
        begin
            req_valid = 1'b1;
            req_load = 1'b1;
            req_addr = addr;
            req_size = 2'b10;
            tick();
            req_valid = 1'b0;
            req_load = 1'b0;
            `wait_signal($sformatf("DCache fill miss addr=0x%08x", addr), 8, l2_rd_valid);
            `check32($sformatf("DCache fill request addr=0x%08x", addr), l2_rd_addr, {addr[31:4], 4'b0});
            d0 = base_word;
            d1 = base_word + 32'd1;
            d2 = base_word + 32'd2;
            d3 = base_word + 32'd3;
            l2_resp_valid = 1'b1;
            tick();
            l2_resp_valid = 1'b0;
            #1;
            `check($sformatf("DCache fill response valid addr=0x%08x", addr), resp_valid);
            `check32($sformatf("DCache fill response data addr=0x%08x", addr), resp_load_data, base_word);
        end
    endtask

    task automatic issue_cacop(input [1:0] mode, input [31:0] addr);
        begin
            cacop_mode = mode;
            cacop_addr = addr;
            cacop_valid = 1'b1;
            #1;
            `check($sformatf("DCache CACOP ready mode=%0d addr=0x%08x", mode, addr), cacop_ready);
            tick();
            cacop_valid = 1'b0;
            `wait_signal("DCache CACOP done", 4, cacop_done);
            tick();
            #1;
            `check("DCache CACOP does not issue L2 read", !l2_rd_valid);
            `check("DCache CACOP does not issue L2 write", !l2_wr_valid);
        end
    endtask

    task automatic expect_load_hit(input string name, input [31:0] addr, input [31:0] exp_word);
        begin
            req_valid = 1'b1;
            req_load = 1'b1;
            req_store = 1'b0;
            req_size = 2'b10;
            req_addr = addr;
            tick();
            req_valid = 1'b0;
            req_load = 1'b0;
            #1;
            `check($sformatf("%s load hit early response", name), resp_valid);
            `check32($sformatf("%s load data", name), resp_load_data, exp_word);
            `check($sformatf("%s avoids L2 read", name), !l2_rd_valid);
            tick();
            #1;
            `check($sformatf("%s has no duplicate hit response", name), !resp_valid);
        end
    endtask

    task automatic expect_next_cycle_hit(input string name, input [31:0] exp_word);
        begin
            tick();
            #1;
            `check($sformatf("%s response", name), resp_valid);
            `check32($sformatf("%s data", name), resp_load_data, exp_word);
            `check($sformatf("%s avoids L2 read", name), !l2_rd_valid);
        end
    endtask

    initial begin
        tb_start();
        req_valid = 0; req_load = 0; req_store = 0; req_uncached = 0; req_size = 2'b10; req_addr = 0; req_store_data = 0;
        l2_rd_ready = 1; l2_resp_valid = 0; d0 = 0; d1 = 0; d2 = 0; d3 = 0; l2_wr_ready = 0; l2_wr_done = 0;
        cacop_valid = 0; cacop_mode = 0; cacop_addr = 0;
        reset_dut();
        req_valid = 1; req_load = 1; req_addr = 32'h2004; tick(); req_valid = 0; req_load = 0;
        `wait_signal("DCache L2 read", 8, l2_rd_valid);
        `check32("DCache aligned read", l2_rd_addr, 32'h2000);
        d0 = 32'hd0; d1 = 32'hd1; d2 = 32'hd2; d3 = 32'hd3; l2_resp_valid = 1; tick(); l2_resp_valid = 0; #1;
        `check("DCache load response", resp_valid);
        `check32("DCache word select", resp_load_data, 32'hd1);

        req_valid = 1; req_load = 1; req_uncached = 1; req_size = 2'b00; req_addr = 32'h1fe0_01e5;
        #1;
        `check("DCache uncached byte L2 read issued same cycle", l2_rd_valid);
        `check32("DCache uncached keeps exact addr", l2_rd_addr, 32'h1fe0_01e5);
        `check("DCache uncached read marks bypass", l2_rd_uncached && l2_rd_size == 2'b00);
        tick();
        req_valid = 0; req_load = 0; req_uncached = 0;
        #1;
        `check("DCache uncached accepted read drops request", !l2_rd_valid);
        d0 = 32'h0000_ab00; d1 = 32'hbad0_0001; d2 = 32'hbad0_0002; d3 = 32'hbad0_0003;
        l2_resp_valid = 1; #1;
        `check("DCache uncached response has no extra local bubble", resp_valid);
        `check32("DCache uncached raw bus data", resp_load_data, 32'h0000_ab00);
        tick(); l2_resp_valid = 0; #1;
        tick(); #1;
        `check("DCache uncached response is single-cycle", !resp_valid);

        req_valid = 1; req_load = 1; req_uncached = 1; req_size = 2'b01; req_addr = 32'h1fe0_01e6;
        l2_rd_ready = 0;
        #1;
        `check("DCache uncached read drives L2 while stalled", l2_rd_valid);
        tick();
        req_valid = 0; req_load = 0; req_uncached = 0;
        #1;
        `check("DCache uncached read holds while L2 not ready", l2_rd_valid);
        `check32("DCache uncached stalled addr stable", l2_rd_addr, 32'h1fe0_01e6);
        l2_rd_ready = 1;
        tick();
        #1;
        `check("DCache uncached read clears after L2 ready", !l2_rd_valid);
        d0 = 32'h0000_cd00;
        l2_resp_valid = 1; #1;
        `check("DCache stalled uncached response", resp_valid);
        `check32("DCache stalled uncached raw bus data", resp_load_data, 32'h0000_cd00);
        tick(); l2_resp_valid = 0; #1;
        tick(); #1;
        `check("DCache stalled uncached response is single-cycle", !resp_valid);

        req_valid = 1; req_store = 1; req_size = 2'b00; req_addr = 32'h2003; req_store_data = 32'h11223344; tick();
        req_valid = 0; req_store = 0;
        `wait_signal("DCache L2 write", 8, l2_wr_valid);
        `check32("DCache write addr", l2_wr_addr, 32'h2003);
        `check("DCache byte strobe", l2_wr_strb == 4'b1000);
        `check32("DCache byte store data aligned", l2_wr_data, 32'h4400_0000);
        `check("DCache cached store responds before L2 accept", resp_valid);
        `check("DCache queued store waits for L2 ready", l2_wr_valid);
        req_valid = 1; req_load = 1; req_size = 2'b10; req_addr = 32'h2000;
        tick();
        req_valid = 0; req_load = 0; #1;
        `check("DCache queued store still pending before ready", l2_wr_valid);
        `check("DCache store-forward hit response", resp_valid);
        `check32("DCache store-forward merged word", resp_load_data, 32'h4400_00d0);
        tick(); #1;
        `check("DCache store-forward hit has no duplicate response", !resp_valid);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check("DCache cached store L2 accept has no extra response", !resp_valid);
        l2_wr_done = 1; tick(); l2_wr_done = 0; #1;
        `check("DCache cached store ignores later write done", !resp_valid);
        req_valid = 1; req_store = 1; req_size = 2'b01; req_addr = 32'h2002; req_store_data = 32'haabb_ccdd; tick();
        req_valid = 0; req_store = 0;
        `wait_signal("DCache half L2 write", 8, l2_wr_valid);
        `check32("DCache half write addr", l2_wr_addr, 32'h2002);
        `check("DCache half strobe", l2_wr_strb == 4'b1100);
        `check32("DCache half store data aligned", l2_wr_data, 32'hccdd_0000);
        `check("DCache half cached store response before L2 accept", resp_valid);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check("DCache half cached store L2 accept has no extra response", !resp_valid);
        l2_wr_done = 1; tick(); l2_wr_done = 0; #1;
        `check("DCache half cached store ignores later write done", !resp_valid);

        l2_wr_ready = 1'b1;
        req_valid = 1; req_store = 1; req_uncached = 1; req_size = 2'b10;
        req_addr = 32'h1fe0_0200; req_store_data = 32'h5566_7788; tick();
        req_valid = 0; req_store = 0; req_uncached = 0;
        #1;
        `check("DCache uncached store direct accept responds", resp_valid);
        l2_wr_ready = 1'b0;

        req_valid = 1; req_load = 1; req_uncached = 1; req_size = 2'b10; req_addr = 32'h1fe0_0204;
        #1;
        `check("DCache uncached load waits behind outstanding store", !l2_rd_valid);
        tick();
        req_valid = 0; req_load = 0; req_uncached = 0; #1;
        `check("DCache blocked uncached load still waits before write done", !l2_rd_valid);
        l2_wr_done = 1; tick(); l2_wr_done = 0; #1;
        `check("DCache write done releases blocked uncached load", l2_rd_valid);
        `check32("DCache released uncached load exact addr", l2_rd_addr, 32'h1fe0_0204);
        tick(); #1;
        `check("DCache released uncached load clears after accept", !l2_rd_valid);
        d0 = 32'h1122_3344; l2_resp_valid = 1; #1;
        `check("DCache uncached load after store response", resp_valid);
        `check32("DCache uncached load after store data", resp_load_data, 32'h1122_3344);
        tick(); l2_resp_valid = 0; #1;
        tick(); #1;
        `check("DCache uncached load after store is single-cycle", !resp_valid);

        req_valid = 1; req_store = 1; req_uncached = 1; req_size = 2'b10;
        req_addr = 32'h1fe0_0208; req_store_data = 32'h99aa_bbcc;
        #1;
        `check("DCache uncached store drives L2 same cycle", l2_wr_valid);
        `check32("DCache uncached store exact addr", l2_wr_addr, 32'h1fe0_0208);
        `check32("DCache uncached store data", l2_wr_data, 32'h99aa_bbcc);
        tick();
        req_valid = 0; req_store = 0; req_uncached = 0;
        #1;
        `check("DCache uncached store holds while L2 not ready", l2_wr_valid);
        `check32("DCache uncached held store exact addr", l2_wr_addr, 32'h1fe0_0208);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check("DCache uncached stalled store responds on accept", resp_valid);
        l2_wr_done = 1; tick(); l2_wr_done = 0; #1;
        `check("DCache uncached stalled store ignores later write done", !resp_valid);

        req_valid = 1; req_store = 1; req_uncached = 1; req_size = 2'b10;
        req_addr = 32'h1fe0_0200; req_store_data = 32'h5566_7788; tick();
        req_valid = 0; req_store = 0; req_uncached = 0;
        `wait_signal("DCache uncached store L2 write", 8, l2_wr_valid);
        `check32("DCache uncached store exact addr", l2_wr_addr, 32'h1fe0_0200);
        `check32("DCache uncached store data", l2_wr_data, 32'h5566_7788);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check("DCache uncached store responds on L2 accept", resp_valid);
        req_valid = 1; req_load = 1; req_uncached = 1; req_size = 2'b10; req_addr = 32'h1fe0_0204;
        #1;
        `check("DCache uncached load waits behind outstanding store", !l2_rd_valid);
        tick();
        req_valid = 0; req_load = 0; req_uncached = 0; #1;
        `check("DCache blocked uncached load still waits before write done", !l2_rd_valid);
        l2_wr_done = 1; tick(); l2_wr_done = 0; #1;
        `check("DCache write done releases blocked uncached load", l2_rd_valid);
        `check32("DCache released uncached load exact addr", l2_rd_addr, 32'h1fe0_0204);
        tick(); #1;
        `check("DCache released uncached load clears after accept", !l2_rd_valid);
        d0 = 32'h1122_3344; l2_resp_valid = 1; #1;
        `check("DCache uncached load after store response", resp_valid);
        `check32("DCache uncached load after store data", resp_load_data, 32'h1122_3344);
        tick(); l2_resp_valid = 0; #1;
        tick(); #1;
        `check("DCache uncached load after store is single-cycle", !resp_valid);

        issue_cacop(2'b10, 32'h2004);
        req_valid = 1; req_load = 1; req_addr = 32'h2004; tick(); req_valid = 0; req_load = 0;
        `wait_signal("DCache miss after CACOP", 8, l2_rd_valid);
        `check32("DCache CACOP invalidated load line", l2_rd_addr, 32'h2000);
        d0 = 32'he0; d1 = 32'he1; d2 = 32'he2; d3 = 32'he3; l2_resp_valid = 1; tick(); l2_resp_valid = 0; #1;
        `check("DCache response after CACOP refill", resp_valid);
        `check32("DCache refilled word after CACOP", resp_load_data, 32'he1);

        reset_dut();
        req_valid = 0; req_load = 0; req_store = 0; req_size = 2'b10; req_addr = 0; req_store_data = 0;
        l2_rd_ready = 1; l2_resp_valid = 0; l2_wr_ready = 0; l2_wr_done = 0;
        fill_load_line(32'h3000, 32'h3000);
        fill_load_line(32'h3080, 32'h3080);
        fill_load_line(32'h3100, 32'h3100);
        fill_load_line(32'h3180, 32'h3180);
        issue_cacop(2'b00, 32'h3000);
        req_valid = 1; req_load = 1; req_addr = 32'h3180; tick(); req_valid = 0; req_load = 0;
        `wait_signal("DCache mode0 CACOP invalidates every way at index", 8, l2_rd_valid);
        `check32("DCache mode0 all-way miss address", l2_rd_addr, 32'h3180);

        reset_dut();
        req_valid = 0; req_load = 0; req_store = 0; req_size = 2'b10; req_addr = 0; req_store_data = 0;
        l2_rd_ready = 1; l2_resp_valid = 0; l2_wr_ready = 0; l2_wr_done = 0;
        fill_load_line(32'h4000, 32'h4000);
        fill_load_line(32'h4080, 32'h4080);
        fill_load_line(32'h4100, 32'h4100);
        fill_load_line(32'h4180, 32'h4180);
        issue_cacop(2'b10, 32'h4000);
        expect_load_hit("DCache mode2 keeps other way at same index", 32'h4180, 32'h4180);
        req_valid = 1; req_load = 1; req_addr = 32'h4000; tick(); req_valid = 0; req_load = 0;
        `wait_signal("DCache mode2 invalidates only target hit way", 8, l2_rd_valid);
        `check32("DCache mode2 target miss address", l2_rd_addr, 32'h4000);

        reset_dut();
        req_valid = 0; req_load = 0; req_store = 0; req_size = 2'b10; req_addr = 0; req_store_data = 0;
        l2_rd_ready = 1; l2_resp_valid = 0; l2_wr_ready = 0; l2_wr_done = 0;
        fill_load_line(32'h5000, 32'h5000);
        fill_load_line(32'h5080, 32'h5080);
        fill_load_line(32'h5100, 32'h5100);
        fill_load_line(32'h5180, 32'h5180);
        issue_cacop(2'b01, 32'h5000);
        req_valid = 1; req_load = 1; req_addr = 32'h5080; tick(); req_valid = 0; req_load = 0;
        `wait_signal("DCache mode1 CACOP invalidates every way at index", 8, l2_rd_valid);
        `check32("DCache mode1 all-way miss address", l2_rd_addr, 32'h5080);

        reset_dut();
        req_valid = 0; req_load = 0; req_store = 0; req_size = 2'b10; req_addr = 0; req_store_data = 0;
        l2_rd_ready = 1; l2_resp_valid = 0; l2_wr_ready = 0; l2_wr_done = 0;
        fill_load_line(32'h6000, 32'h6000);
        fill_load_line(32'h6040, 32'h6040);

        req_valid = 1; req_load = 1; req_store = 0; req_size = 2'b10; req_addr = 32'h6000;
        tick();
        #1;
        `check("DCache pipelined hit A early response", resp_valid);
        `check32("DCache pipelined hit A early data", resp_load_data, 32'h6000);

        req_addr = 32'h6040;
        tick();
        #1;
        `check("DCache pipelined hit B early response", resp_valid);
        `check32("DCache pipelined hit B early data", resp_load_data, 32'h6040);

        req_valid = 0; req_load = 0;
        tick(); #1;
        `check("DCache pipelined hit B has no duplicate response", !resp_valid);

        reset_dut();
        req_valid = 0; req_load = 0; req_store = 0; req_size = 2'b10; req_addr = 0; req_store_data = 0;
        l2_rd_ready = 1; l2_resp_valid = 0; l2_wr_ready = 0; l2_wr_done = 0;
        fill_load_line(32'h7000, 32'h7000);
        req_valid = 1; req_store = 1; req_size = 2'b00; req_addr = 32'h7000; req_store_data = 32'h0000_00aa; tick();
        req_addr = 32'h7001; req_store_data = 32'h0000_00bb; tick();
        #1;
        `check("DCache queued store0 responds without L2 ready", resp_valid);
        req_addr = 32'h7002; req_store_data = 32'h0000_00cc; tick();
        #1;
        `check("DCache queued store1 responds without L2 ready", resp_valid);
        req_addr = 32'h7003; req_store_data = 32'h0000_00dd; tick();
        #1;
        `check("DCache queued store2 responds without L2 ready", resp_valid);
        req_valid = 0; req_store = 0; #1;
        tick(); #1;
        `check("DCache queued store3 responds without L2 ready", resp_valid);
        `check("DCache store queue head drives L2 write", l2_wr_valid);
        req_valid = 1; req_load = 1; req_size = 2'b10; req_addr = 32'h7000; tick();
        req_valid = 0; req_load = 0;
        `wait_signal("DCache load forwards all queued stores", 8, resp_valid);
        `check32("DCache queued store merged word", resp_load_data, 32'hddcc_bbaa);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check32("DCache queued write0 addr", l2_wr_addr, 32'h7001);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check32("DCache queued write1 addr", l2_wr_addr, 32'h7002);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check32("DCache queued write2 addr", l2_wr_addr, 32'h7003);
        l2_wr_ready = 1; tick(); l2_wr_ready = 0; #1;
        `check("DCache store queue drains after accepts", !l2_wr_valid);

        finish_tb();
    end
endmodule

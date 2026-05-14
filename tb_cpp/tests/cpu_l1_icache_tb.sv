`timescale 1ns / 1ps

module cpu_l1_icache_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, req_valid, req_ready, resp_valid, resp_fault, resp_line_valid, l2_req_valid, l2_prefetch, l2_ready, l2_resp_valid;
    logic cacop_valid, cacop_ready, cacop_done;
    logic [1:0] cacop_mode;
    logic l2_pf_resp_valid;
    logic redirect_probe_valid, redirect_probe_hit, redirect_fast_valid, redirect_fast_line_valid, redirect_fast_consume;
    logic shadow_fetch_valid;
    logic [31:0] req_addr, resp_instr, l2_req_addr, d0, d1, d2, d3, cacop_addr;
    logic [31:0] resp_line_addr, resp_line_d0, resp_line_d1, resp_line_d2, resp_line_d3;
    logic [31:0] redirect_probe_addr, redirect_fast_addr, redirect_fast_instr, shadow_fetch_addr;
    logic [31:0] redirect_fast_line_addr, redirect_fast_line_d0, redirect_fast_line_d1;
    logic [31:0] redirect_fast_line_d2, redirect_fast_line_d3;
    logic [31:0] l2_pf_resp_addr, pd0, pd1, pd2, pd3;
    cpu_l1_icache #(.NUM_LINES(8), .ENABLE_REDIRECT_PROBE_LOOKUP(1)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .req_valid_i(req_valid), .req_ready_o(req_ready),
        .req_addr_i(req_addr), .resp_valid_o(resp_valid), .resp_instr_o(resp_instr),
        .shadow_fetch_valid_i(shadow_fetch_valid), .shadow_fetch_addr_i(shadow_fetch_addr),
        .redirect_probe_valid_i(redirect_probe_valid), .redirect_probe_addr_i(redirect_probe_addr),
        .redirect_probe_hit_o(redirect_probe_hit),
        .redirect_fast_valid_o(redirect_fast_valid), .redirect_fast_addr_o(redirect_fast_addr),
        .redirect_fast_instr_o(redirect_fast_instr),
        .redirect_fast_line_valid_o(redirect_fast_line_valid),
        .redirect_fast_line_addr_o(redirect_fast_line_addr),
        .redirect_fast_line_data_o_0(redirect_fast_line_d0),
        .redirect_fast_line_data_o_1(redirect_fast_line_d1),
        .redirect_fast_line_data_o_2(redirect_fast_line_d2),
        .redirect_fast_line_data_o_3(redirect_fast_line_d3),
        .redirect_fast_consume_i(redirect_fast_consume),
        .resp_fault_o(resp_fault),
        .resp_line_valid_o(resp_line_valid),
        .resp_line_addr_o(resp_line_addr),
        .resp_line_data_o_0(resp_line_d0),
        .resp_line_data_o_1(resp_line_d1),
        .resp_line_data_o_2(resp_line_d2),
        .resp_line_data_o_3(resp_line_d3),
        .l2_req_valid_o(l2_req_valid), .l2_req_addr_o(l2_req_addr),
        .cacop_valid_i(cacop_valid), .cacop_mode_i(cacop_mode), .cacop_addr_i(cacop_addr),
        .cacop_ready_o(cacop_ready), .cacop_done_o(cacop_done),
        .l2_req_is_prefetch_o(l2_prefetch), .l2_req_ready_i(l2_ready), .l2_resp_valid_i(l2_resp_valid),
        .l2_resp_data_i_0(d0), .l2_resp_data_i_1(d1), .l2_resp_data_i_2(d2), .l2_resp_data_i_3(d3),
        .l2_pf_resp_valid_i(l2_pf_resp_valid), .l2_pf_resp_addr_i(l2_pf_resp_addr),
        .l2_pf_resp_data_i_0(pd0), .l2_pf_resp_data_i_1(pd1),
        .l2_pf_resp_data_i_2(pd2), .l2_pf_resp_data_i_3(pd3)
    );

    task automatic issue_req(input [31:0] addr);
        begin
            req_addr = addr;
            req_valid = 1'b1;
            #1;
            `check($sformatf("ICache request ready addr=0x%08x", addr), req_ready);
            `tb_event($sformatf("ICACHE_REQ addr=0x%08x ready=%0d linebuf_hit=%0d",
                                addr, req_ready, u_dut.linebuf_hit_req));
            tick();
            req_valid = 1'b0;
        end
    endtask

    task automatic issue_req_expect_same_cycle(input string name, input [31:0] addr, input [31:0] exp_instr);
        begin
            req_addr = addr;
            req_valid = 1'b1;
            #1;
            `check($sformatf("%s ready addr=0x%08x", name, addr), req_ready);
            `check($sformatf("%s same-cycle resp valid", name), resp_valid);
            `check32($sformatf("%s same-cycle resp instr", name), resp_instr, exp_instr);
            `tb_event($sformatf("ICACHE_REQ_RESP_SAME name=\"%s\" addr=0x%08x instr=0x%08x",
                                name, addr, resp_instr));
            tick();
            req_valid = 1'b0;
        end
    endtask

    task automatic issue_req_wait_ready(input string name, input [31:0] addr);
        integer i;
        bit accepted;
        begin
            req_addr = addr;
            req_valid = 1'b1;
            accepted = 1'b0;
            for (i = 0; i < 8 && !accepted; i = i + 1) begin
                #1;
                accepted = req_ready;
                if (!accepted)
                    tick();
            end
            `check($sformatf("%s ready addr=0x%08x", name, addr), accepted);
            `tb_event($sformatf("ICACHE_REQ_WAIT name=\"%s\" addr=0x%08x ready=%0d waited=%0d linebuf_hit=%0d",
                                name, addr, req_ready, i, u_dut.linebuf_hit_req));
            tick();
            req_valid = 1'b0;
        end
    endtask

    task automatic expect_resp(input string name, input [31:0] exp_instr);
        begin
            if (!resp_valid)
                tick();
            #1;
            `check($sformatf("%s valid", name), resp_valid);
            `check32($sformatf("%s instr", name), resp_instr, exp_instr);
            `tb_event($sformatf("ICACHE_RESP name=\"%s\" instr=0x%08x", name, resp_instr));
            tick();
            #1;
        end
    endtask

    task automatic wait_resp(input string name, input [31:0] exp_instr);
        begin
            if (!resp_valid)
                `wait_signal($sformatf("%s response valid", name), 12, resp_valid);
            `check32($sformatf("%s instr", name), resp_instr, exp_instr);
            `tb_event($sformatf("ICACHE_RESP_WAIT name=\"%s\" instr=0x%08x", name, resp_instr));
            tick();
            #1;
        end
    endtask

    task automatic expect_l2_resp_same_cycle(input string name, input [31:0] exp_instr);
        begin
            l2_resp_valid = 1'b1;
            #1;
            `check($sformatf("%s valid", name), resp_valid);
            `check32($sformatf("%s instr", name), resp_instr, exp_instr);
            `tb_event($sformatf("ICACHE_L2_RESP_SAME name=\"%s\" instr=0x%08x",
                                name, resp_instr));
            tick();
            l2_resp_valid = 1'b0;
            #1;
        end
    endtask

    task automatic drain_stale_l2_resp(input string name);
        begin
            l2_resp_valid = 1'b1;
            #1;
            `check($sformatf("%s suppresses stale response same-cycle", name), !resp_valid);
            tick();
            l2_resp_valid = 1'b0;
            #1;
        end
    endtask

    task automatic issue_cacop(input [1:0] mode, input [31:0] addr);
        begin
            cacop_mode = mode;
            cacop_addr = addr;
            cacop_valid = 1'b1;
            #1;
            `check($sformatf("ICache CACOP ready addr=0x%08x mode=%0d", addr, mode), cacop_ready);
            `tb_event($sformatf("ICACHE_CACOP_REQ mode=%0d addr=0x%08x ready=%0d", mode, addr, cacop_ready));
            tick();
            cacop_valid = 1'b0;
            `wait_signal("ICache CACOP done", 8, cacop_done);
            tick();
            #1;
            `tb_event($sformatf("ICACHE_CACOP_DONE mode=%0d addr=0x%08x", mode, addr));
        end
    endtask

    task automatic fill_miss_line(input [31:0] addr, input [31:0] base_word);
        begin
            req_valid = 1'b1;
            req_addr = addr;
            tick();
            req_valid = 1'b0;
            `wait_signal($sformatf("ICache fill miss addr=0x%08x", addr), 12, l2_req_valid);
            `check32($sformatf("ICache fill request addr=0x%08x", addr), l2_req_addr, addr);
            d0 = base_word;
            d1 = base_word + 32'd1;
            d2 = base_word + 32'd2;
            d3 = base_word + 32'd3;
            l2_resp_valid = 1'b1;
            #1;
            `check($sformatf("ICache fill response valid addr=0x%08x", addr), resp_valid);
            `check32($sformatf("ICache fill response data addr=0x%08x", addr), resp_instr, base_word);
            tick();
            l2_resp_valid = 1'b0;
            #1;
        end
    endtask

    task automatic redirect_probe_line(input [31:0] addr);
        begin
            redirect_probe_valid = 1'b1;
            redirect_probe_addr = addr;
            flush = 1'b1;
            #1;
            `check($sformatf("ICache redirect probe hit addr=0x%08x", addr), redirect_probe_hit);
            tick();
            flush = 1'b0;
            redirect_probe_valid = 1'b0;
            #1;
            `check($sformatf("ICache redirect fast token addr=0x%08x", addr), redirect_fast_valid);
            `check($sformatf("ICache redirect fast packet addr=0x%08x", addr), redirect_fast_line_valid);
            redirect_fast_consume = 1'b1;
            tick();
            redirect_fast_consume = 1'b0;
            #1;
        end
    endtask

    task automatic shadow_probe_once(input [31:0] addr);
        begin
            shadow_fetch_valid = 1'b1;
            shadow_fetch_addr = addr;
            tick();
            shadow_fetch_valid = 1'b0;
            #1;
        end
    endtask

    initial begin
        tb_start();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0; d0 = 0; d1 = 0; d2 = 0; d3 = 0;
        cacop_valid = 0; cacop_mode = 0; cacop_addr = 0;
        redirect_probe_valid = 0; redirect_probe_addr = 0; redirect_fast_consume = 0;
        shadow_fetch_valid = 0; shadow_fetch_addr = 0;
        l2_pf_resp_valid = 0; l2_pf_resp_addr = 0; pd0 = 0; pd1 = 0; pd2 = 0; pd3 = 0;
        reset_dut();
        req_valid = 1; req_addr = 32'h1008; tick(); req_valid = 0;
        `wait_signal("ICache L2 request", 12, l2_req_valid);
        `check32("ICache miss addr", l2_req_addr, 32'h1008);
        d0 = 32'ha0; d1 = 32'ha1; d2 = 32'ha2; d3 = 32'ha3;
        l2_pf_resp_addr = 32'h1010; pd0 = 32'hb0; pd1 = 32'hb1; pd2 = 32'hb2; pd3 = 32'hb3;
        l2_resp_valid = 1; l2_pf_resp_valid = 1; #1;
        `check("ICache refill response bypass", resp_valid);
        `check32("ICache word select", resp_instr, 32'ha2);
        `check("ICache refill response carries line packet", resp_line_valid);
        `check32("ICache refill packet addr", resp_line_addr, 32'h1000);
        `check32("ICache refill packet word0", resp_line_d0, 32'ha0);
        `check32("ICache refill packet word3", resp_line_d3, 32'ha3);
        tick();
        l2_resp_valid = 0; l2_pf_resp_valid = 0; #1;
        `check("ICache line buffer filled by refill", u_dut.linebuf_valid_q);
        `check32("ICache line buffer word0", u_dut.linebuf_data_q[0], 32'ha0);
        `check32("ICache line buffer word3", u_dut.linebuf_data_q[3], 32'ha3);
        `check("ICache buddy pfbuf filled", u_dut.pfbuf_valid_q);
        `check32("ICache buddy pfbuf word0", u_dut.pfbuf_data_q[0], 32'hb0);
        `check32("ICache buddy pfbuf word3", u_dut.pfbuf_data_q[3], 32'hb3);

        l2_pf_resp_addr = 32'h1020; pd0 = 32'hc0; pd1 = 32'hc1; pd2 = 32'hc2; pd3 = 32'hc3;
        l2_pf_resp_valid = 1; tick(); l2_pf_resp_valid = 0; #1;
        `check("ICache second pfbuf filled", u_dut.pfbuf1_valid_q);
        `check32("ICache second pfbuf word0", u_dut.pfbuf1_data_q[0], 32'hc0);
        `check32("ICache second pfbuf word3", u_dut.pfbuf1_data_q[3], 32'hc3);

        issue_req_expect_same_cycle("ICache linebuf word3", 32'h100c, 32'ha3);
        `check("ICache linebuf hit avoids L2 request", !l2_req_valid);

        issue_req_expect_same_cycle("ICache linebuf word0", 32'h1000, 32'ha0);
        issue_req_expect_same_cycle("ICache linebuf word1", 32'h1004, 32'ha1);

        issue_req_expect_same_cycle("ICache pfbuf word0", 32'h1010, 32'hb0);
        `check("ICache pfbuf promoted to linebuf", u_dut.linebuf_valid_q && !u_dut.pfbuf_valid_q);
        `check32("ICache promoted linebuf word3", u_dut.linebuf_data_q[3], 32'hb3);

        issue_req_expect_same_cycle("ICache promoted linebuf word3", 32'h101c, 32'hb3);

        issue_req_expect_same_cycle("ICache second pfbuf word0", 32'h1020, 32'hc0);
        `check("ICache second pfbuf promoted", u_dut.linebuf_valid_q && !u_dut.pfbuf1_valid_q);

        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'h1024;
        flush = 1; #1;
        `check("ICache redirect probe hits preserved linebuf", redirect_probe_hit);
        tick();
        flush = 0; redirect_probe_valid = 1'b0; #1;
        `check("ICache captures redirect fast token on flush", redirect_fast_valid);
        `check32("ICache redirect fast token addr", redirect_fast_addr, 32'h1024);
        `check32("ICache redirect fast token instr", redirect_fast_instr, 32'hc1);
        `check("ICache redirect fast token carries line packet", redirect_fast_line_valid);
        `check32("ICache redirect fast packet addr", redirect_fast_line_addr, 32'h1020);
        `check32("ICache redirect fast packet word2", redirect_fast_line_d2, 32'hc2);
        redirect_fast_consume = 1'b1; tick(); redirect_fast_consume = 1'b0; #1;
        `check("ICache clears redirect fast token on consume", !redirect_fast_valid);
        `check("ICache clears redirect fast packet on consume", !redirect_fast_line_valid);

        flush = 1; tick(); flush = 0; #1;
        `check("ICache keeps linebuf across frontend flush", u_dut.linebuf_valid_q);
        issue_req_expect_same_cycle("ICache preserved linebuf after flush", 32'h1024, 32'hc1);

        l2_pf_resp_addr = 32'h1030; pd0 = 32'hd0; pd1 = 32'hd1; pd2 = 32'hd2; pd3 = 32'hd3;
        l2_pf_resp_valid = 1; tick(); l2_pf_resp_valid = 0; #1;
        `check("ICache standalone sideband fills pfbuf before flush",
               u_dut.pfbuf_valid_q || u_dut.pfbuf1_valid_q);
        flush = 1; tick(); flush = 0; #1;
        `check("ICache clears pfbuf on frontend flush",
               !u_dut.pfbuf_valid_q && !u_dut.pfbuf1_valid_q);
        req_valid = 1; req_addr = 32'h1030; tick(); req_valid = 0;
        `wait_signal("ICache flushed sideband address misses after flush", 12, l2_req_valid);
        `check32("ICache flushed sideband miss addr", l2_req_addr, 32'h1030);
        d0 = 32'hd100; d1 = 32'hd101; d2 = 32'hd102; d3 = 32'hd103;
        expect_l2_resp_same_cycle("ICache flushed sideband refill response", 32'hd100);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0; redirect_probe_valid = 0; redirect_fast_consume = 0;
        l2_pf_resp_addr = 32'h1040; pd0 = 32'he0; pd1 = 32'he1; pd2 = 32'he2; pd3 = 32'he3;
        l2_pf_resp_valid = 1; tick(); l2_pf_resp_valid = 0; #1;
        `check("ICache standalone sideband fills pfbuf for redirect probe",
               u_dut.pfbuf_valid_q || u_dut.pfbuf1_valid_q);
        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'h1048;
        flush = 1; #1;
        `check("ICache redirect probe hits pfbuf during flush", redirect_probe_hit);
        tick();
        flush = 0; redirect_probe_valid = 1'b0; #1;
        `check("ICache captures pfbuf redirect token", redirect_fast_valid);
        `check32("ICache pfbuf redirect token instr", redirect_fast_instr, 32'he2);
        `check("ICache promotes probed pfbuf to linebuf",
               u_dut.linebuf_valid_q &&
               !u_dut.pfbuf_valid_q && !u_dut.pfbuf1_valid_q);
        redirect_fast_consume = 1'b1; tick(); redirect_fast_consume = 1'b0; #1;
        `check("ICache clears pfbuf redirect token on consume", !redirect_fast_valid);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        d0 = 0; d1 = 0; d2 = 0; d3 = 0; pd0 = 0; pd1 = 0; pd2 = 0; pd3 = 0;

        req_valid = 1; req_addr = 32'h2000; tick(); req_valid = 0;
        `wait_signal("ICache warm line L2 request", 12, l2_req_valid);
        `check32("ICache warm line miss addr", l2_req_addr, 32'h2000);
        d0 = 32'h2000; d1 = 32'h2001; d2 = 32'h2002; d3 = 32'h2003;
        expect_l2_resp_same_cycle("ICache warm line response", 32'h2000);
        issue_cacop(2'b10, 32'h2000);
        `check("ICache CACOP clears line buffer", !u_dut.linebuf_valid_q);
        req_valid = 1; req_addr = 32'h2000; tick(); req_valid = 0;
        `wait_signal("ICache miss after CACOP", 12, l2_req_valid);
        `check32("ICache CACOP invalidated tag", l2_req_addr, 32'h2000);
        d0 = 32'h2100; d1 = 32'h2101; d2 = 32'h2102; d3 = 32'h2103;
        expect_l2_resp_same_cycle("ICache response after CACOP refill", 32'h2100);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0; cacop_valid = 0;
        fill_miss_line(32'hd000, 32'hd000);
        fill_miss_line(32'hd010, 32'hd010);
        fill_miss_line(32'hd020, 32'hd020);
        fill_miss_line(32'hd030, 32'hd030);
        fill_miss_line(32'hd040, 32'hd040);
        fill_miss_line(32'hd050, 32'hd050);
        fill_miss_line(32'hd060, 32'hd060);
        fill_miss_line(32'hd070, 32'hd070);
        fill_miss_line(32'hd090, 32'hd090);
        fill_miss_line(32'hd0a0, 32'hd0a0);
        fill_miss_line(32'hd0b0, 32'hd0b0);
        fill_miss_line(32'hd0c0, 32'hd0c0);
        fill_miss_line(32'hd0d0, 32'hd0d0);
        fill_miss_line(32'hd0e0, 32'hd0e0);
        fill_miss_line(32'hd0f0, 32'hd0f0);
        fill_miss_line(32'hd110, 32'hd110);
        fill_miss_line(32'hd120, 32'hd120);
        req_valid = 1'b1;
        req_addr = 32'hd000;
        #1;
        `check("ICache queues old lookup before CACOP", req_ready);
        tick();
        req_valid = 1'b0;
        #1;
        `check("ICache has pending response queue before CACOP", u_dut.resp_count_q != 0);
        cacop_mode = 2'b00;
        cacop_addr = 32'hd000;
        cacop_valid = 1'b1;
        #1;
        `check("ICache CACOP accepts with pending younger fetch response", cacop_ready);
        `check("ICache CACOP suppresses pending younger response", !resp_valid);
        tick();
        cacop_valid = 1'b0;
        #1;
        `check("ICache CACOP clears pending response queue", u_dut.resp_count_q == 0);
        `check("ICache CACOP clears pending lookup pipe",
               !u_dut.lookup_valid_q && !u_dut.lookup_valid_d1);
        `wait_signal("ICache pending-response CACOP done", 8, cacop_done);
        tick();
        #1;
        `check("ICache does not leak pre-CACOP response", !resp_valid);
        req_valid = 1'b1;
        req_addr = 32'hd000;
        tick();
        req_valid = 1'b0;
        `wait_signal("ICache pending-response CACOP invalidates target index", 12, l2_req_valid);
        `check32("ICache pending-response CACOP miss addr", l2_req_addr, 32'hd000);
        d0 = 32'hd200; d1 = 32'hd201; d2 = 32'hd202; d3 = 32'hd203;
        expect_l2_resp_same_cycle("ICache pending-response CACOP refill", 32'hd200);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        fill_miss_line(32'h6000, 32'h6000);
        fill_miss_line(32'h6080, 32'h6080);
        fill_miss_line(32'h6100, 32'h6100);
        fill_miss_line(32'h6180, 32'h6180);
        issue_cacop(2'b00, 32'h6000);
        req_valid = 1; req_addr = 32'h6180; tick(); req_valid = 0;
        `wait_signal("ICache mode0 CACOP invalidates every way at index", 12, l2_req_valid);
        `check32("ICache mode0 all-way miss address", l2_req_addr, 32'h6180);
        d0 = 32'h6200; d1 = 32'h6201; d2 = 32'h6202; d3 = 32'h6203;
        expect_l2_resp_same_cycle("ICache mode0 refill response", 32'h6200);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        fill_miss_line(32'h7000, 32'h7000);
        fill_miss_line(32'h7080, 32'h7080);
        fill_miss_line(32'h7100, 32'h7100);
        fill_miss_line(32'h7180, 32'h7180);
        issue_cacop(2'b10, 32'h7000);
        issue_req(32'h7180);
        wait_resp("ICache mode2 keeps other way at same index", 32'h7180);
        `check("ICache mode2 hit-way CACOP avoids L2 for other way", !l2_req_valid);
        req_valid = 1; req_addr = 32'h7000; tick(); req_valid = 0;
        `wait_signal("ICache mode2 invalidates only target hit way", 12, l2_req_valid);
        `check32("ICache mode2 target miss address", l2_req_addr, 32'h7000);
        d0 = 32'h7200; d1 = 32'h7201; d2 = 32'h7202; d3 = 32'h7203;
        expect_l2_resp_same_cycle("ICache mode2 target refill response", 32'h7200);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        fill_miss_line(32'h8000, 32'h8000);
        fill_miss_line(32'h8080, 32'h8080);
        fill_miss_line(32'h8100, 32'h8100);
        fill_miss_line(32'h8180, 32'h8180);
        issue_cacop(2'b01, 32'h8000);
        req_valid = 1; req_addr = 32'h8080; tick(); req_valid = 0;
        `wait_signal("ICache mode1 CACOP invalidates every way at index", 12, l2_req_valid);
        `check32("ICache mode1 all-way miss address", l2_req_addr, 32'h8080);
        d0 = 32'h8200; d1 = 32'h8201; d2 = 32'h8202; d3 = 32'h8203;
        expect_l2_resp_same_cycle("ICache mode1 refill response", 32'h8200);

        req_valid = 1; req_addr = 32'h5000; tick(); req_valid = 0;
        `wait_signal("ICache merge base L2 request", 12, l2_req_valid);
        `check32("ICache merge base miss addr", l2_req_addr, 32'h5000);
        tick(); #1;
        `check("ICache merge base request accepted", !l2_req_valid);
        issue_req(32'h5004);
        issue_req(32'h5008);
        d0 = 32'h5000; d1 = 32'h5001; d2 = 32'h5002; d3 = 32'h5003;
        expect_l2_resp_same_cycle("ICache merged base response", 32'h5000);
        expect_resp("ICache merged word1 response", 32'h5001);
        expect_resp("ICache merged word2 response", 32'h5002);
        `check("ICache merge uses one L2 request", !l2_req_valid);

        req_valid = 1; req_addr = 32'h3000; tick(); req_valid = 0;
        `wait_signal("ICache stale-drain L2 request", 12, l2_req_valid);
        `check32("ICache stale-drain old miss addr", l2_req_addr, 32'h3000);
        tick(); #1;
        `check("ICache old L2 request accepted", !l2_req_valid);

        flush = 1; tick(); flush = 0; #1;
        `check("ICache marks stale L2 response after flush", u_dut.stale_l2_resp_pending_q);
        issue_req_expect_same_cycle("ICache same-cycle linebuf hit during stale wait", 32'h5004, 32'h5001);
        req_valid = 1; req_addr = 32'h4000; #1;
        `check("ICache blocks new miss before stale response drains", !req_ready);
        req_valid = 0;

        d0 = 32'hde00; d1 = 32'hde01; d2 = 32'hde02; d3 = 32'hde03;
        drain_stale_l2_resp("ICache stale L2 response");
        `check("ICache drains stale L2 response", !u_dut.stale_l2_resp_pending_q);
        `check("ICache does not emit stale response", !resp_valid);

        issue_req(32'h4000);
        `wait_signal("ICache new L2 request after stale drain", 12, l2_req_valid);
        `check32("ICache new miss addr after stale drain", l2_req_addr, 32'h4000);
        d0 = 32'hc0; d1 = 32'hc1; d2 = 32'hc2; d3 = 32'hc3;
        expect_l2_resp_same_cycle("ICache new miss response after stale drain", 32'hc0);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        fill_miss_line(32'he000, 32'he000);
        fill_miss_line(32'he010, 32'he010);
        fill_miss_line(32'he020, 32'he020);
        fill_miss_line(32'he030, 32'he030);
        fill_miss_line(32'he040, 32'he040);
        fill_miss_line(32'he050, 32'he050);
        issue_req_expect_same_cycle("ICache recent linebuf hit line0", 32'he000, 32'he000);
        issue_req_expect_same_cycle("ICache recent linebuf hit line1", 32'he010, 32'he010);
        `check("ICache pipelined lookup hits avoid L2", !l2_req_valid);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        fill_miss_line(32'h9000, 32'h9000);
        fill_miss_line(32'h9010, 32'h9010);
        fill_miss_line(32'h9020, 32'h9020);
        fill_miss_line(32'h9030, 32'h9030);
        fill_miss_line(32'h9040, 32'h9040);
        fill_miss_line(32'h9050, 32'h9050);
        fill_miss_line(32'h9060, 32'h9060);
        fill_miss_line(32'h9070, 32'h9070);
        fill_miss_line(32'h9090, 32'h9090);
        fill_miss_line(32'h90a0, 32'h90a0);
        fill_miss_line(32'h90b0, 32'h90b0);
        fill_miss_line(32'h90c0, 32'h90c0);
        fill_miss_line(32'h90d0, 32'h90d0);
        fill_miss_line(32'h90e0, 32'h90e0);
        fill_miss_line(32'h90f0, 32'h90f0);
        fill_miss_line(32'h9110, 32'h9110);
        fill_miss_line(32'h9120, 32'h9120);
        issue_req(32'h9000);
        req_valid = 1'b1;
        req_addr = 32'h9004;
        #1;
        `check("ICache lookup-merge hit accepts word1 before hit resolves", req_ready);
        `check("ICache lookup-merge hit marks word1 as merged",
               u_dut.lookup_merge_req_w && !u_dut.cache_hit_comb);
        tick();
        req_valid = 1'b0;
        req_valid = 1'b1;
        req_addr = 32'h9008;
        #1;
        `check("ICache lookup-merge hit accepts word2 as lookup completes", req_ready);
        `check("ICache lookup-merge hit completes word2 same cycle",
               u_dut.req_lookup_merge_hit_complete_w);
        `check("ICache lookup-merge hit word0 same-cycle valid", resp_valid);
        `check32("ICache lookup-merge hit word0 same-cycle instr", resp_instr, 32'h9000);
        `tb_event($sformatf("ICACHE_RESP_SAME name=\"ICache lookup-merge hit word0\" instr=0x%08x",
                            resp_instr));
        tick();
        req_valid = 1'b0;
        req_valid = 1'b1;
        req_addr = 32'h900c;
        #1;
        `check("ICache lookup-merge hit accepts word3 from filled linebuf", req_ready);
        `check("ICache lookup-merge hit word1 same-cycle valid", resp_valid);
        `check32("ICache lookup-merge hit word1 same-cycle instr", resp_instr, 32'h9001);
        `tb_event($sformatf("ICACHE_RESP_SAME name=\"ICache lookup-merge hit word1\" instr=0x%08x",
                            resp_instr));
        tick();
        req_valid = 1'b0;
        expect_resp("ICache lookup-merge hit word2", 32'h9002);
        expect_resp("ICache lookup-merge hit word3", 32'h9003);
        `check("ICache lookup-merge hit avoids L2", !l2_req_valid);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        req_valid = 1'b1;
        req_addr = 32'ha000;
        tick();
        req_addr = 32'ha004;
        #1;
        `check("ICache lookup-merge miss accepts word1 before miss resolves", req_ready);
        `check("ICache lookup-merge miss marks word1 as speculative merge",
               u_dut.lookup_merge_req_w);
        tick();
        req_addr = 32'ha008;
        #1;
        `check("ICache lookup-merge miss accepts word2 before miss resolves", req_ready);
        `check("ICache lookup-merge miss marks word2 as speculative merge",
               u_dut.lookup_merge_req_w);
        tick();
        req_valid = 1'b0;
        `wait_signal("ICache lookup-merge miss L2 request", 12, l2_req_valid);
        `check32("ICache lookup-merge miss address", l2_req_addr, 32'ha000);
        tick(); #1;
        `check("ICache lookup-merge miss request accepted", !l2_req_valid);
        d0 = 32'ha000; d1 = 32'ha001; d2 = 32'ha002; d3 = 32'ha003;
        expect_l2_resp_same_cycle("ICache lookup-merge miss base response", 32'ha000);
        expect_resp("ICache lookup-merge miss word1", 32'ha001);
        expect_resp("ICache lookup-merge miss word2", 32'ha002);
        `check("ICache lookup-merge miss uses one L2 request", !l2_req_valid);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        fill_miss_line(32'h9000, 32'h9000);
        req_valid = 1; req_addr = 32'ha000; tick(); req_valid = 0;
        `wait_signal("ICache two-cycle flush old L2 request", 12, l2_req_valid);
        `check32("ICache two-cycle flush old miss addr", l2_req_addr, 32'ha000);
        tick(); #1;
        `check("ICache two-cycle flush old request accepted", !l2_req_valid);

        flush = 1; tick(); #1;
        `check("ICache marks stale after first flush cycle", u_dut.stale_l2_resp_pending_q);
        `check("ICache does not accept request during flush", !req_ready);
        tick(); #1;
        `check("ICache keeps stale marker across repeated flush", u_dut.stale_l2_resp_pending_q);
        flush = 0; #1;
        `check("ICache stale marker survives flush deassert", u_dut.stale_l2_resp_pending_q);

        issue_req_expect_same_cycle("ICache linebuf hit while two-cycle stale waits", 32'h9004, 32'h9001);
        req_valid = 1; req_addr = 32'hb000; #1;
        `check("ICache blocks new miss after two-cycle flush until stale drains", !req_ready);
        req_valid = 0;

        d0 = 32'hfa00; d1 = 32'hfa01; d2 = 32'hfa02; d3 = 32'hfa03;
        drain_stale_l2_resp("ICache two-cycle stale response");
        `check("ICache drains stale response after two-cycle flush", !u_dut.stale_l2_resp_pending_q);
        `check("ICache suppresses stale response after two-cycle flush", !resp_valid);

        issue_req(32'hb000);
        `wait_signal("ICache new miss after two-cycle stale drain", 12, l2_req_valid);
        `check32("ICache new miss addr after two-cycle stale drain", l2_req_addr, 32'hb000);
        d0 = 32'hb000; d1 = 32'hb001; d2 = 32'hb002; d3 = 32'hb003;
        expect_l2_resp_same_cycle("ICache new response after two-cycle stale drain", 32'hb000);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        req_valid = 1; req_addr = 32'hc000; tick(); req_valid = 0;
        `wait_signal("ICache stale sideband base L2 request", 12, l2_req_valid);
        `check32("ICache stale sideband base miss addr", l2_req_addr, 32'hc000);
        tick(); #1;
        `check("ICache stale sideband old request accepted", !l2_req_valid);

        flush = 1; tick(); flush = 0; #1;
        `check("ICache marks stale before stale sideband arrives", u_dut.stale_l2_resp_pending_q);
        l2_pf_resp_addr = 32'hc010; pd0 = 32'hee00; pd1 = 32'hee01; pd2 = 32'hee02; pd3 = 32'hee03;
        l2_pf_resp_valid = 1; tick(); l2_pf_resp_valid = 0; #1;
        `check("ICache ignores sideband while stale response waits",
               !u_dut.pfbuf_valid_q && !u_dut.pfbuf1_valid_q);

        d0 = 32'hc000; d1 = 32'hc001; d2 = 32'hc002; d3 = 32'hc003;
        drain_stale_l2_resp("ICache ignored-sideband stale response");
        `check("ICache drains stale after ignored sideband", !u_dut.stale_l2_resp_pending_q);
        `check("ICache ignored sideband does not emit stale response", !resp_valid);

        issue_req(32'hc010);
        `wait_signal("ICache ignored stale sideband address misses later", 12, l2_req_valid);
        `check32("ICache ignored stale sideband miss addr", l2_req_addr, 32'hc010);
        d0 = 32'hc100; d1 = 32'hc101; d2 = 32'hc102; d3 = 32'hc103;
        expect_l2_resp_same_cycle("ICache ignored stale sideband refill response", 32'hc100);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0;
        fill_miss_line(32'hd000, 32'hd000);
        fill_miss_line(32'hd010, 32'hd010);
        fill_miss_line(32'hd020, 32'hd020);
        fill_miss_line(32'hd030, 32'hd030);
        `check("ICache recent linebuf keeps third previous line", u_dut.linebuf2_valid_q);
        `check32("ICache recent linebuf2 word0", u_dut.linebuf2_data_q[0], 32'hd010);
        issue_req_expect_same_cycle("ICache recent linebuf2 hit", 32'hd014, 32'hd011);
        `check("ICache recent linebuf hit avoids L2", !l2_req_valid);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0; redirect_probe_valid = 0; redirect_fast_consume = 0;
        fill_miss_line(32'he100, 32'he100);
        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'he104;
        flush = 1'b1; #1;
        `check("ICache redirect target probe fills rtbuf", redirect_probe_hit);
        tick();
        flush = 1'b0; redirect_probe_valid = 1'b0; #1;
        `check("ICache rtbuf captures redirect target", u_dut.rtbuf_valid_q);
        `check32("ICache rtbuf captured target word1", u_dut.rtbuf_data_q[1], 32'he101);
        redirect_fast_consume = 1'b1; tick(); redirect_fast_consume = 1'b0; #1;
        fill_miss_line(32'he110, 32'he110);
        fill_miss_line(32'he120, 32'he120);
        fill_miss_line(32'he130, 32'he130);
        fill_miss_line(32'he140, 32'he140);
        fill_miss_line(32'he150, 32'he150);
        fill_miss_line(32'he160, 32'he160);
        fill_miss_line(32'he170, 32'he170);
        fill_miss_line(32'he180, 32'he180);
        fill_miss_line(32'he190, 32'he190);
        fill_miss_line(32'he1a0, 32'he1a0);
        fill_miss_line(32'he1b0, 32'he1b0);
        fill_miss_line(32'he1c0, 32'he1c0);
        fill_miss_line(32'he1d0, 32'he1d0);
        fill_miss_line(32'he1e0, 32'he1e0);
        fill_miss_line(32'he1f0, 32'he1f0);
        fill_miss_line(32'he200, 32'he200);
        l2_ready = 1'b0;
        tick(); #1;
        `check("ICache rtbuf test drains previous refill response", !resp_valid);
        req_addr = 32'he104; #1;
        `check("ICache rtbuf target evicted from recent linebuf",
               !u_dut.linebuf_hit_req);
        `check("ICache rtbuf target still matches request",
               u_dut.rtbuf_hit_req);
        issue_req_expect_same_cycle("ICache rtbuf survives recent eviction", 32'he104, 32'he101);
        `check("ICache rtbuf hit avoids L2 request", !l2_req_valid);
        l2_ready = 1'b1;

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0; redirect_probe_valid = 0; redirect_fast_consume = 0;
        fill_miss_line(32'he400, 32'he400);
        redirect_probe_line(32'he404);
        fill_miss_line(32'he410, 32'he410);
        redirect_probe_line(32'he414);
        fill_miss_line(32'he420, 32'he420);
        redirect_probe_line(32'he424);
        fill_miss_line(32'he430, 32'he430);
        redirect_probe_line(32'he434);
        fill_miss_line(32'he440, 32'he440);
        redirect_probe_line(32'he444);
        fill_miss_line(32'he450, 32'he450);
        redirect_probe_line(32'he454);
        fill_miss_line(32'he460, 32'he460);
        redirect_probe_line(32'he464);
        fill_miss_line(32'he470, 32'he470);
        redirect_probe_line(32'he474);
        `check("ICache rtbuf keeps eight redirect target entries",
               u_dut.rtbuf_valid_q && u_dut.rtbuf1_valid_q &&
               u_dut.rtbuf2_valid_q && u_dut.rtbuf3_valid_q &&
               u_dut.rtbuf4_valid_q && u_dut.rtbuf5_valid_q &&
               u_dut.rtbuf6_valid_q && u_dut.rtbuf7_valid_q);
        fill_miss_line(32'he480, 32'he480);
        fill_miss_line(32'he490, 32'he490);
        fill_miss_line(32'he4a0, 32'he4a0);
        fill_miss_line(32'he4b0, 32'he4b0);
        fill_miss_line(32'he4c0, 32'he4c0);
        fill_miss_line(32'he4d0, 32'he4d0);
        fill_miss_line(32'he4e0, 32'he4e0);
        fill_miss_line(32'he4f0, 32'he4f0);
        fill_miss_line(32'he500, 32'he500);
        fill_miss_line(32'he510, 32'he510);
        fill_miss_line(32'he520, 32'he520);
        fill_miss_line(32'he530, 32'he530);
        fill_miss_line(32'he540, 32'he540);
        fill_miss_line(32'he550, 32'he550);
        fill_miss_line(32'he560, 32'he560);
        fill_miss_line(32'he570, 32'he570);
        l2_ready = 1'b0;
        tick(); #1;
        req_addr = 32'he404; #1;
        `check("ICache rtbuf entry7 survives recent eviction",
               !u_dut.linebuf_hit_req && u_dut.rtbuf7_hit_req && u_dut.rtbuf_hit_req);
        issue_req_expect_same_cycle("ICache rtbuf entry7 same-cycle hit", 32'he404, 32'he401);
        issue_req_expect_same_cycle("ICache rtbuf entry6 target hit", 32'he414, 32'he411);
        issue_req_expect_same_cycle("ICache rtbuf entry5 target hit", 32'he424, 32'he421);
        issue_req_expect_same_cycle("ICache rtbuf entry4 target hit", 32'he434, 32'he431);
        issue_req_expect_same_cycle("ICache rtbuf entry3 target hit", 32'he444, 32'he441);
        issue_req_expect_same_cycle("ICache rtbuf entry2 target hit", 32'he454, 32'he451);
        issue_req_expect_same_cycle("ICache rtbuf entry1 target hit", 32'he464, 32'he461);
        issue_req_expect_same_cycle("ICache rtbuf newest target hit", 32'he474, 32'he471);
        `check("ICache eight-entry rtbuf hits avoid L2 requests", !l2_req_valid);
        l2_ready = 1'b1;
        issue_cacop(2'b10, 32'he400);
        `check("ICache CACOP clears eight-entry rtbuf",
               !u_dut.rtbuf_valid_q && !u_dut.rtbuf1_valid_q &&
               !u_dut.rtbuf2_valid_q && !u_dut.rtbuf3_valid_q &&
               !u_dut.rtbuf4_valid_q && !u_dut.rtbuf5_valid_q &&
               !u_dut.rtbuf6_valid_q && !u_dut.rtbuf7_valid_q);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0; redirect_probe_valid = 0; redirect_fast_consume = 0;
        fill_miss_line(32'hf080, 32'hf080);
        fill_miss_line(32'hf000, 32'hf000);
        fill_miss_line(32'hf010, 32'hf010);
        fill_miss_line(32'hf020, 32'hf020);
        fill_miss_line(32'hf030, 32'hf030);
        fill_miss_line(32'hf040, 32'hf040);
        fill_miss_line(32'hf050, 32'hf050);
        fill_miss_line(32'hf060, 32'hf060);
        fill_miss_line(32'hf070, 32'hf070);
        fill_miss_line(32'hf090, 32'hf090);
        fill_miss_line(32'hf0a0, 32'hf0a0);
        fill_miss_line(32'hf0b0, 32'hf0b0);
        fill_miss_line(32'hf0c0, 32'hf0c0);
        fill_miss_line(32'hf0d0, 32'hf0d0);
        fill_miss_line(32'hf0e0, 32'hf0e0);
        fill_miss_line(32'hf0f0, 32'hf0f0);
        fill_miss_line(32'hf110, 32'hf110);
        fill_miss_line(32'hf120, 32'hf120);
        issue_req(32'hf080);
        wait_resp("ICache delayed probe alias lookup hit", 32'hf080);
        `check("ICache delayed probe alias hit avoids L2", !l2_req_valid);
        req_addr = 32'hf004; #1;
        `check("ICache delayed probe target evicted from fast buffers",
               !u_dut.linebuf_hit_req && !u_dut.rtbuf_hit_req && !u_dut.pfbuf_hit_req);
        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'hf004;
        flush = 1'b1; #1;
        `check("ICache delayed probe initially misses fast buffers", !redirect_probe_hit);
        tick();
        flush = 1'b0; redirect_probe_valid = 1'b0; #1;
        `check("ICache delayed probe token not ready immediately", !redirect_fast_valid);
        `wait_signal("ICache delayed probe finds main cache line", 8, redirect_fast_valid);
        `check32("ICache delayed probe fast addr", redirect_fast_addr, 32'hf004);
        `check32("ICache delayed probe fast instr", redirect_fast_instr, 32'hf001);
        `check("ICache delayed probe fast token carries line packet", redirect_fast_line_valid);
        `check32("ICache delayed probe fast packet word2", redirect_fast_line_d2, 32'hf002);
        redirect_fast_consume = 1'b1; tick(); redirect_fast_consume = 1'b0; #1;
        `check("ICache delayed probe fills rtbuf", u_dut.rtbuf_hit_req);
        issue_req_expect_same_cycle("ICache delayed probe rtbuf hit", 32'hf004, 32'hf001);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0; redirect_probe_valid = 0; redirect_fast_consume = 0;
        fill_miss_line(32'hf380, 32'hf380);
        fill_miss_line(32'hf300, 32'hf300);
        fill_miss_line(32'hf310, 32'hf310);
        fill_miss_line(32'hf320, 32'hf320);
        fill_miss_line(32'hf330, 32'hf330);
        fill_miss_line(32'hf340, 32'hf340);
        fill_miss_line(32'hf350, 32'hf350);
        fill_miss_line(32'hf360, 32'hf360);
        fill_miss_line(32'hf370, 32'hf370);
        fill_miss_line(32'hf390, 32'hf390);
        fill_miss_line(32'hf3a0, 32'hf3a0);
        fill_miss_line(32'hf3b0, 32'hf3b0);
        fill_miss_line(32'hf3c0, 32'hf3c0);
        fill_miss_line(32'hf3d0, 32'hf3d0);
        fill_miss_line(32'hf3e0, 32'hf3e0);
        fill_miss_line(32'hf3f0, 32'hf3f0);
        fill_miss_line(32'hf410, 32'hf410);
        fill_miss_line(32'hf420, 32'hf420);
        issue_req(32'hf380);
        wait_resp("ICache delayed probe merge alias lookup hit", 32'hf380);
        `check("ICache delayed probe merge alias hit avoids L2", !l2_req_valid);
        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'hf304;
        flush = 1'b1; tick();
        flush = 1'b0; redirect_probe_valid = 1'b0; #1;
        req_valid = 1'b1;
        req_addr = 32'hf304;
        #1;
        `check("ICache redirect BRAM probe holds matching demand",
               !req_ready && u_dut.probe_lookup_blocks_req_w);
        tick();
        req_valid = 1'b0;
        `wait_signal("ICache redirect BRAM probe emits fast token", 8, redirect_fast_valid);
        `check32("ICache redirect BRAM probe token addr", redirect_fast_addr, 32'hf304);
        `check32("ICache redirect BRAM probe token instr", redirect_fast_instr, 32'hf301);
        `check("ICache redirect BRAM probe carries line packet", redirect_fast_line_valid);
        `check32("ICache redirect BRAM probe packet word2", redirect_fast_line_d2, 32'hf302);
        `check("ICache redirect BRAM probe avoids L2 miss", !l2_req_valid);
        redirect_fast_consume = 1'b1; tick(); redirect_fast_consume = 1'b0; #1;
        issue_req_expect_same_cycle("ICache redirect BRAM probe rtbuf hit", 32'hf304, 32'hf301);

        reset_dut();
        flush = 0; req_valid = 0; req_addr = 0; l2_ready = 1; l2_resp_valid = 0;
        l2_pf_resp_valid = 0; redirect_probe_valid = 0; redirect_fast_consume = 0;
        shadow_fetch_valid = 0; shadow_fetch_addr = 0;
        fill_miss_line(32'hf800, 32'hf800);
        fill_miss_line(32'hf810, 32'hf810);
        fill_miss_line(32'hf820, 32'hf820);
        fill_miss_line(32'hf830, 32'hf830);
        fill_miss_line(32'hf840, 32'hf840);
        fill_miss_line(32'hf850, 32'hf850);
        fill_miss_line(32'hf860, 32'hf860);
        fill_miss_line(32'hf870, 32'hf870);
        fill_miss_line(32'hf890, 32'hf890);
        fill_miss_line(32'hf8a0, 32'hf8a0);
        fill_miss_line(32'hf8b0, 32'hf8b0);
        fill_miss_line(32'hf8c0, 32'hf8c0);
        fill_miss_line(32'hf8d0, 32'hf8d0);
        fill_miss_line(32'hf8e0, 32'hf8e0);
        fill_miss_line(32'hf8f0, 32'hf8f0);
        fill_miss_line(32'hf910, 32'hf910);
        fill_miss_line(32'hf920, 32'hf920);
        fill_miss_line(32'hf930, 32'hf930);
        req_addr = 32'hf804; #1;
        `check("ICache shadow target evicted from fast buffers",
               !u_dut.linebuf_hit_req && !u_dut.rtbuf_hit_req &&
               !u_dut.pfbuf_hit_req);
        shadow_probe_once(32'hf804);
        `wait_signal("ICache shadow probe fills altbuf", 8, u_dut.altbuf_valid_q);
        `check32("ICache shadow altbuf word1", u_dut.altbuf_data_q[1], 32'hf801);
        shadow_probe_once(32'hf914);
        `check32("ICache shadow hit on existing altbuf keeps data",
                 u_dut.altbuf_data_q[1], 32'hf801);
        req_valid = 1'b1;
        req_addr = 32'hf940;
        shadow_fetch_valid = 1'b1;
        shadow_fetch_addr = 32'hf814;
        #1;
        `check("ICache shadow queue does not steal BRAM from demand lookup",
               req_ready && u_dut.req_lookup_fire_w && !u_dut.shadow_probe_lookup_start_w);
        tick();
        req_valid = 1'b0;
        shadow_fetch_valid = 1'b0;
        #1;
        `check32("ICache demand priority preserves shadow altbuf",
                 u_dut.altbuf_data_q[1], 32'hf801);
        `check("ICache blocked shadow hint is queued",
               u_dut.shadow_hint0_valid_q &&
               (u_dut.shadow_hint0_addr_q == 32'hf814));
        `wait_signal("ICache demand after shadow priority issues miss", 8, l2_req_valid);
        d0 = 32'hf940; d1 = 32'hf941; d2 = 32'hf942; d3 = 32'hf943;
        l2_resp_valid = 1'b1; #1;
        `check("ICache demand miss after shadow priority returns", resp_valid);
        `check32("ICache demand miss after shadow priority instr", resp_instr, 32'hf940);
        tick(); l2_resp_valid = 1'b0; #1;
        `wait_signal("ICache queued shadow fills second altbuf entry", 12, u_dut.altbuf1_valid_q);
        `check32("ICache queued shadow newest altbuf word1", u_dut.altbuf_data_q[1], 32'hf811);
        `check32("ICache queued shadow keeps older altbuf word1", u_dut.altbuf1_data_q[1], 32'hf801);
        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'hf804;
        flush = 1'b1; #1;
        `check("ICache redirect probe hits older shadow altbuf", redirect_probe_hit);
        tick();
        flush = 1'b0; redirect_probe_valid = 1'b0; #1;
        `check("ICache shadow altbuf creates redirect fast token", redirect_fast_valid);
        `check32("ICache shadow altbuf token instr", redirect_fast_instr, 32'hf801);
        `check("ICache shadow altbuf token carries line packet", redirect_fast_line_valid);
        `check32("ICache shadow altbuf packet word2", redirect_fast_line_d2, 32'hf802);
        redirect_fast_consume = 1'b1; tick(); redirect_fast_consume = 1'b0; #1;
        issue_req_expect_same_cycle("ICache shadow altbuf promoted line hit", 32'hf808, 32'hf802);

        issue_cacop(2'b10, 32'hd030);
        `check("ICache CACOP clears all recent line buffers",
               !u_dut.linebuf_valid_q && !u_dut.linebuf1_valid_q &&
               !u_dut.linebuf2_valid_q && !u_dut.linebuf3_valid_q &&
               !u_dut.linebuf4_valid_q && !u_dut.linebuf5_valid_q &&
               !u_dut.linebuf6_valid_q && !u_dut.linebuf7_valid_q &&
               !u_dut.linebuf8_valid_q && !u_dut.linebuf9_valid_q &&
               !u_dut.linebuf10_valid_q && !u_dut.linebuf11_valid_q &&
               !u_dut.linebuf12_valid_q && !u_dut.linebuf13_valid_q &&
               !u_dut.linebuf14_valid_q && !u_dut.linebuf15_valid_q &&
               !u_dut.rtbuf_valid_q && !u_dut.rtbuf1_valid_q &&
               !u_dut.rtbuf2_valid_q && !u_dut.rtbuf3_valid_q &&
               !u_dut.rtbuf4_valid_q && !u_dut.rtbuf5_valid_q &&
               !u_dut.rtbuf6_valid_q && !u_dut.rtbuf7_valid_q &&
               !u_dut.pfbuf_valid_q && !u_dut.pfbuf1_valid_q &&
               !u_dut.altbuf_valid_q && !u_dut.altbuf1_valid_q);
        finish_tb();
    end
endmodule

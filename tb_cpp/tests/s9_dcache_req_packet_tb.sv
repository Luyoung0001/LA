`timescale 1ns / 1ps

module s9_dcache_req_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s9_valid;
    logic        mem_access;
    logic        lsu_is_load;
    logic        lsu_is_store;
    logic        lane0_exception;
    logic        lane1_mem_exception;
    logic        tlb_exception;
    logic        inst_sc;
    logic        sc_success;
    logic        preld_req;
    logic [31:0] mapped_paddr;
    logic [1:0]  lsu_mem_size;
    logic [31:0] lsu_store_data;
    logic        direct_uncached;
    logic        dmw_uncached;
    logic        tlb_uncached;
    logic        mmio_uncached;

    logic [31:0] dcache_paddr;
    logic        dcache_req_valid;
    logic        dcache_is_load;
    logic        dcache_is_store;
    logic [1:0]  dcache_size;
    logic [31:0] dcache_store_data;
    logic        dcache_uncached;
    logic        dcache_mem_req;

    s9_dcache_req_packet u_dut (
        .s9_valid_i(s9_valid),
        .mem_access_i(mem_access),
        .lsu_is_load_i(lsu_is_load),
        .lsu_is_store_i(lsu_is_store),
        .lane0_exception_i(lane0_exception),
        .lane1_mem_exception_i(lane1_mem_exception),
        .tlb_exception_i(tlb_exception),
        .inst_sc_i(inst_sc),
        .sc_success_i(sc_success),
        .preld_req_i(preld_req),
        .mapped_paddr_i(mapped_paddr),
        .lsu_mem_size_i(lsu_mem_size),
        .lsu_store_data_i(lsu_store_data),
        .direct_uncached_i(direct_uncached),
        .dmw_uncached_i(dmw_uncached),
        .tlb_uncached_i(tlb_uncached),
        .mmio_uncached_i(mmio_uncached),
        .dcache_paddr_o(dcache_paddr),
        .dcache_req_valid_o(dcache_req_valid),
        .dcache_is_load_o(dcache_is_load),
        .dcache_is_store_o(dcache_is_store),
        .dcache_size_o(dcache_size),
        .dcache_store_data_o(dcache_store_data),
        .dcache_uncached_o(dcache_uncached),
        .dcache_mem_req_o(dcache_mem_req)
    );

    task automatic drive_base;
        begin
            s9_valid = 1'b1;
            mem_access = 1'b1;
            lsu_is_load = 1'b1;
            lsu_is_store = 1'b0;
            lane0_exception = 1'b0;
            lane1_mem_exception = 1'b0;
            tlb_exception = 1'b0;
            inst_sc = 1'b0;
            sc_success = 1'b0;
            preld_req = 1'b0;
            mapped_paddr = 32'h0abc_def0;
            lsu_mem_size = 2'b10;
            lsu_store_data = 32'h1234_5678;
            direct_uncached = 1'b0;
            dmw_uncached = 1'b0;
            tlb_uncached = 1'b0;
            mmio_uncached = 1'b0;
        end
    endtask

    task automatic check_blocked(input string name);
        begin
            #1;
            `check(name, !dcache_req_valid && !dcache_mem_req &&
                         !dcache_is_load && !dcache_is_store &&
                         !dcache_uncached);
            `check32({name, " paddr pass"}, dcache_paddr, 32'h0abc_def0);
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_base();
        #1;
        `check("S9 dcache packet issues load",
               dcache_req_valid && dcache_mem_req &&
               dcache_is_load && !dcache_is_store && !dcache_uncached);
        `check32("S9 dcache packet paddr", dcache_paddr, 32'h0abc_def0);
        `check32("S9 dcache packet size", {30'd0, dcache_size}, 32'd2);

        drive_base();
        lsu_is_load = 1'b0;
        lsu_is_store = 1'b1;
        lsu_mem_size = 2'b01;
        lsu_store_data = 32'hfeed_beef;
        #1;
        `check("S9 dcache packet issues store",
               dcache_req_valid && dcache_mem_req &&
               !dcache_is_load && dcache_is_store);
        `check32("S9 dcache packet store size", {30'd0, dcache_size}, 32'd1);
        `check32("S9 dcache packet store data", dcache_store_data, 32'hfeed_beef);

        drive_base();
        s9_valid = 1'b0;
        check_blocked("S9 dcache packet blocks invalid S9");

        drive_base();
        mem_access = 1'b0;
        check_blocked("S9 dcache packet blocks no memory access");

        drive_base();
        lane0_exception = 1'b1;
        check_blocked("S9 dcache packet blocks lane0 exception");

        drive_base();
        lane1_mem_exception = 1'b1;
        check_blocked("S9 dcache packet blocks lane1 memory exception");

        drive_base();
        tlb_exception = 1'b1;
        check_blocked("S9 dcache packet blocks TLB exception");

        drive_base();
        lsu_is_load = 1'b0;
        lsu_is_store = 1'b1;
        inst_sc = 1'b1;
        sc_success = 1'b0;
        check_blocked("S9 dcache packet blocks failed SC store");

        drive_base();
        lsu_is_load = 1'b0;
        lsu_is_store = 1'b1;
        inst_sc = 1'b1;
        sc_success = 1'b1;
        #1;
        `check("S9 dcache packet allows successful SC store",
               dcache_req_valid && dcache_mem_req && dcache_is_store);

        drive_base();
        direct_uncached = 1'b1;
        #1;
        `check("S9 dcache packet marks direct uncached", dcache_uncached);

        drive_base();
        dmw_uncached = 1'b1;
        #1;
        `check("S9 dcache packet marks DMW uncached", dcache_uncached);

        drive_base();
        tlb_uncached = 1'b1;
        #1;
        `check("S9 dcache packet marks TLB uncached", dcache_uncached);

        drive_base();
        mmio_uncached = 1'b1;
        #1;
        `check("S9 dcache packet marks MMIO uncached", dcache_uncached);

        drive_base();
        mem_access = 1'b0;
        lsu_is_load = 1'b0;
        preld_req = 1'b1;
        direct_uncached = 1'b1;
        #1;
        `check("S9 dcache packet preld emits load-like request",
               dcache_req_valid && !dcache_mem_req &&
               dcache_is_load && !dcache_is_store && !dcache_uncached);

        drive_base();
        tlb_exception = 1'b1;
        preld_req = 1'b1;
        #1;
        `check("S9 dcache packet trusts pre-gated preld input",
               dcache_req_valid && dcache_is_load && !dcache_mem_req);

        finish_tb();
    end
endmodule

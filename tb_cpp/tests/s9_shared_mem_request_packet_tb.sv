`timescale 1ns / 1ps

module s9_shared_mem_request_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s9_valid;
    logic        mem_access;
    logic        lsu_is_load;
    logic        lsu_is_store;
    logic        lsu_lane1_mem;
    logic        lane1_mem_exception;
    logic        lane0_tlb_exception;
    logic        lane1_tlb_exception;
    logic        preld_req;
    logic        dcache_mem_req;
    logic [31:0] mem_vaddr;
    logic [31:0] dcache_paddr;
    logic        dcache_req_valid;
    logic        dcache_is_load;
    logic        dcache_is_store;
    logic [1:0]  dcache_size;
    logic [31:0] dcache_store_data;
    logic        dcache_uncached;

    logic [31:0] dcache_paddr_o;
    logic        dcache_req_valid_o;
    logic        dcache_is_load_o;
    logic        dcache_is_store_o;
    logic [1:0]  dcache_size_o;
    logic [31:0] dcache_store_data_o;
    logic        dcache_uncached_o;
    logic        shared_mem_valid_o;
    logic        shared_mem_req_valid_o;
    logic        shared_mem_mem_req_o;
    logic        shared_mem_preld_req_o;
    logic        shared_mem_owner_slot0_o;
    logic        shared_mem_owner_slot1_o;
    logic        shared_mem_slot0_req_o;
    logic        shared_mem_slot1_req_o;
    logic        shared_mem_slot1_load_o;
    logic        shared_mem_slot1_store_o;
    logic        shared_mem_lane1_exception_o;
    logic        shared_mem_lane0_tlb_exception_o;
    logic        shared_mem_lane1_tlb_exception_o;
    logic [31:0] shared_mem_vaddr_o;
    logic [31:0] shared_mem_paddr_o;
    logic [31:0] shared_mem_store_data_o;
    logic [1:0]  shared_mem_size_o;

    s9_shared_mem_request_packet u_dut (
        .s9_valid_i(s9_valid),
        .mem_access_i(mem_access),
        .lsu_is_load_i(lsu_is_load),
        .lsu_is_store_i(lsu_is_store),
        .lsu_lane1_mem_i(lsu_lane1_mem),
        .lane1_mem_exception_i(lane1_mem_exception),
        .lane0_tlb_exception_i(lane0_tlb_exception),
        .lane1_tlb_exception_i(lane1_tlb_exception),
        .preld_req_i(preld_req),
        .dcache_mem_req_i(dcache_mem_req),
        .mem_vaddr_i(mem_vaddr),
        .dcache_paddr_i(dcache_paddr),
        .dcache_req_valid_i(dcache_req_valid),
        .dcache_is_load_i(dcache_is_load),
        .dcache_is_store_i(dcache_is_store),
        .dcache_size_i(dcache_size),
        .dcache_store_data_i(dcache_store_data),
        .dcache_uncached_i(dcache_uncached),
        .dcache_paddr_o(dcache_paddr_o),
        .dcache_req_valid_o(dcache_req_valid_o),
        .dcache_is_load_o(dcache_is_load_o),
        .dcache_is_store_o(dcache_is_store_o),
        .dcache_size_o(dcache_size_o),
        .dcache_store_data_o(dcache_store_data_o),
        .dcache_uncached_o(dcache_uncached_o),
        .shared_mem_valid_o(shared_mem_valid_o),
        .shared_mem_req_valid_o(shared_mem_req_valid_o),
        .shared_mem_mem_req_o(shared_mem_mem_req_o),
        .shared_mem_preld_req_o(shared_mem_preld_req_o),
        .shared_mem_owner_slot0_o(shared_mem_owner_slot0_o),
        .shared_mem_owner_slot1_o(shared_mem_owner_slot1_o),
        .shared_mem_slot0_req_o(shared_mem_slot0_req_o),
        .shared_mem_slot1_req_o(shared_mem_slot1_req_o),
        .shared_mem_slot1_load_o(shared_mem_slot1_load_o),
        .shared_mem_slot1_store_o(shared_mem_slot1_store_o),
        .shared_mem_lane1_exception_o(shared_mem_lane1_exception_o),
        .shared_mem_lane0_tlb_exception_o(shared_mem_lane0_tlb_exception_o),
        .shared_mem_lane1_tlb_exception_o(shared_mem_lane1_tlb_exception_o),
        .shared_mem_vaddr_o(shared_mem_vaddr_o),
        .shared_mem_paddr_o(shared_mem_paddr_o),
        .shared_mem_store_data_o(shared_mem_store_data_o),
        .shared_mem_size_o(shared_mem_size_o)
    );

    task automatic clear_inputs;
        begin
            s9_valid = 1'b0;
            mem_access = 1'b0;
            lsu_is_load = 1'b0;
            lsu_is_store = 1'b0;
            lsu_lane1_mem = 1'b0;
            lane1_mem_exception = 1'b0;
            lane0_tlb_exception = 1'b0;
            lane1_tlb_exception = 1'b0;
            preld_req = 1'b0;
            dcache_mem_req = 1'b0;
            mem_vaddr = 32'd0;
            dcache_paddr = 32'd0;
            dcache_req_valid = 1'b0;
            dcache_is_load = 1'b0;
            dcache_is_store = 1'b0;
            dcache_size = 2'd0;
            dcache_store_data = 32'd0;
            dcache_uncached = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S9SHM idle has no owner",
               !shared_mem_valid_o && !shared_mem_owner_slot0_o &&
               !shared_mem_owner_slot1_o && !shared_mem_req_valid_o);

        clear_inputs();
        s9_valid = 1'b1;
        mem_access = 1'b1;
        lsu_is_load = 1'b1;
        dcache_mem_req = 1'b1;
        dcache_req_valid = 1'b1;
        dcache_is_load = 1'b1;
        mem_vaddr = 32'h4000_0100;
        dcache_paddr = 32'h0abc_d100;
        dcache_size = 2'b10;
        #1;
        `check("S9SHM slot0 load owns response",
               shared_mem_valid_o && shared_mem_owner_slot0_o &&
               shared_mem_slot0_req_o && !shared_mem_owner_slot1_o);
        `check32("S9SHM forwards slot0 load vaddr", shared_mem_vaddr_o, 32'h4000_0100);
        `check32("S9SHM forwards slot0 load paddr", dcache_paddr_o, 32'h0abc_d100);

        clear_inputs();
        s9_valid = 1'b1;
        mem_access = 1'b1;
        lsu_is_store = 1'b1;
        lsu_lane1_mem = 1'b1;
        dcache_mem_req = 1'b1;
        dcache_req_valid = 1'b1;
        dcache_is_store = 1'b1;
        mem_vaddr = 32'h4000_0202;
        dcache_paddr = 32'h0abc_d202;
        dcache_size = 2'b01;
        dcache_store_data = 32'h0000_55aa;
        #1;
        `check("S9SHM slot1 store owns response",
               shared_mem_owner_slot1_o && shared_mem_slot1_req_o &&
               shared_mem_slot1_store_o && !shared_mem_owner_slot0_o);
        `check32("S9SHM forwards slot1 store data",
                 shared_mem_store_data_o, 32'h0000_55aa);
        `check32("S9SHM forwards slot1 store size",
                 {30'd0, shared_mem_size_o}, {30'd0, 2'b01});

        clear_inputs();
        s9_valid = 1'b1;
        mem_access = 1'b1;
        lsu_is_load = 1'b1;
        lsu_lane1_mem = 1'b1;
        lane1_tlb_exception = 1'b1;
        mem_vaddr = 32'h4000_0300;
        dcache_paddr = 32'h4000_0300;
        #1;
        `check("S9SHM slot1 TLB miss owns slot1 but not response",
               shared_mem_valid_o && shared_mem_owner_slot1_o &&
               shared_mem_slot1_load_o && !shared_mem_slot1_req_o &&
               shared_mem_lane1_tlb_exception_o && !dcache_req_valid_o);

        clear_inputs();
        s9_valid = 1'b1;
        preld_req = 1'b1;
        dcache_req_valid = 1'b1;
        dcache_is_load = 1'b1;
        dcache_paddr = 32'h1c00_3000;
        #1;
        `check("S9SHM preld is request-valid without mem owner",
               shared_mem_valid_o && shared_mem_req_valid_o &&
               shared_mem_preld_req_o && !shared_mem_mem_req_o &&
               !shared_mem_owner_slot0_o && !shared_mem_owner_slot1_o);

        finish_tb();
    end
endmodule

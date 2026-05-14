`timescale 1ns / 1ps

module s9_mem_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s9_valid;
    logic        s9_ready_go;
    logic        s9_allowin;
    logic        s9_to_s10_valid;
    logic        s9_fire;
    logic        mem_access;
    logic        lsu_is_load;
    logic        lsu_is_store;
    logic        lsu_lane1_mem;
    logic        lane1_mem_exception;
    logic        lane0_tlb_exception;
    logic        lane1_tlb_exception;
    logic        preld_req;
    logic        dcache_mem_req;
    logic [31:0] dcache_paddr;
    logic        dcache_req_valid;
    logic        dcache_is_load;
    logic        dcache_is_store;
    logic [1:0]  dcache_size;
    logic [31:0] dcache_store_data;
    logic        dcache_uncached;
    logic        slot1_emit_valid;
    logic        slot1_fire;
    logic [3:0]  slot1_emit_class;

    logic [31:0] dcache_paddr_o;
    logic        dcache_req_valid_o;
    logic        dcache_is_load_o;
    logic        dcache_is_store_o;
    logic [1:0]  dcache_size_o;
    logic [31:0] dcache_store_data_o;
    logic        dcache_uncached_o;
    logic        slot1_emit_valid_o;
    logic        slot1_fire_o;
    logic [3:0]  slot1_emit_class_o;
    logic [3:0]  stage_event_summary_o;
    logic [7:0]  lsu_event_summary_o;
    logic [15:0] mem_event_reason_o;

    s9_mem_event_packet u_dut (
        .s9_valid_i(s9_valid),
        .s9_ready_go_i(s9_ready_go),
        .s9_allowin_i(s9_allowin),
        .s9_to_s10_valid_i(s9_to_s10_valid),
        .s9_fire_i(s9_fire),
        .mem_access_i(mem_access),
        .lsu_is_load_i(lsu_is_load),
        .lsu_is_store_i(lsu_is_store),
        .lsu_lane1_mem_i(lsu_lane1_mem),
        .lane1_mem_exception_i(lane1_mem_exception),
        .lane0_tlb_exception_i(lane0_tlb_exception),
        .lane1_tlb_exception_i(lane1_tlb_exception),
        .preld_req_i(preld_req),
        .dcache_mem_req_i(dcache_mem_req),
        .dcache_paddr_i(dcache_paddr),
        .dcache_req_valid_i(dcache_req_valid),
        .dcache_is_load_i(dcache_is_load),
        .dcache_is_store_i(dcache_is_store),
        .dcache_size_i(dcache_size),
        .dcache_store_data_i(dcache_store_data),
        .dcache_uncached_i(dcache_uncached),
        .slot1_emit_valid_i(slot1_emit_valid),
        .slot1_fire_i(slot1_fire),
        .slot1_emit_class_i(slot1_emit_class),
        .dcache_paddr_o(dcache_paddr_o),
        .dcache_req_valid_o(dcache_req_valid_o),
        .dcache_is_load_o(dcache_is_load_o),
        .dcache_is_store_o(dcache_is_store_o),
        .dcache_size_o(dcache_size_o),
        .dcache_store_data_o(dcache_store_data_o),
        .dcache_uncached_o(dcache_uncached_o),
        .slot1_emit_valid_o(slot1_emit_valid_o),
        .slot1_fire_o(slot1_fire_o),
        .slot1_emit_class_o(slot1_emit_class_o),
        .stage_event_summary_o(stage_event_summary_o),
        .lsu_event_summary_o(lsu_event_summary_o),
        .mem_event_reason_o(mem_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            s9_valid = 1'b0;
            s9_ready_go = 1'b0;
            s9_allowin = 1'b0;
            s9_to_s10_valid = 1'b0;
            s9_fire = 1'b0;
            mem_access = 1'b0;
            lsu_is_load = 1'b0;
            lsu_is_store = 1'b0;
            lsu_lane1_mem = 1'b0;
            lane1_mem_exception = 1'b0;
            lane0_tlb_exception = 1'b0;
            lane1_tlb_exception = 1'b0;
            preld_req = 1'b0;
            dcache_mem_req = 1'b0;
            dcache_paddr = 32'd0;
            dcache_req_valid = 1'b0;
            dcache_is_load = 1'b0;
            dcache_is_store = 1'b0;
            dcache_size = 2'd0;
            dcache_store_data = 32'd0;
            dcache_uncached = 1'b0;
            slot1_emit_valid = 1'b0;
            slot1_fire = 1'b0;
            slot1_emit_class = 4'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S9EVT idle clears events",
               !dcache_req_valid_o && !slot1_emit_valid_o && !slot1_fire_o);
        `check32("S9EVT idle summaries clear",
                 {16'd0, stage_event_summary_o, lsu_event_summary_o,
                  slot1_emit_class_o}, 32'd0);

        clear_inputs();
        s9_valid = 1'b1;
        s9_ready_go = 1'b1;
        s9_allowin = 1'b1;
        s9_to_s10_valid = 1'b1;
        s9_fire = 1'b1;
        #1;
        `check32("S9EVT packs ready/fire summary",
                 {28'd0, stage_event_summary_o}, {28'd0, 4'b1111});
        `check32("S9EVT ready reason",
                 {16'd0, mem_event_reason_o}, 32'h000f);

        clear_inputs();
        s9_valid = 1'b1;
        mem_access = 1'b1;
        lsu_is_load = 1'b1;
        dcache_mem_req = 1'b1;
        dcache_req_valid = 1'b1;
        dcache_is_load = 1'b1;
        dcache_paddr = 32'h1c00_1000;
        dcache_size = 2'b10;
        dcache_store_data = 32'h1234_5678;
        dcache_uncached = 1'b1;
        #1;
        `check("S9EVT forwards DCache load request",
               dcache_req_valid_o && dcache_is_load_o &&
               !dcache_is_store_o && dcache_uncached_o);
        `check32("S9EVT forwards DCache paddr", dcache_paddr_o, 32'h1c00_1000);
        `check32("S9EVT forwards DCache size",
                 {30'd0, dcache_size_o}, {30'd0, 2'b10});
        `check32("S9EVT forwards DCache data",
                 dcache_store_data_o, 32'h1234_5678);
        `check32("S9EVT packs load LSU summary",
                 {24'd0, lsu_event_summary_o}, {24'd0, 8'b1000_0001});
        `check32("S9EVT packs DCache reason",
                 {16'd0, mem_event_reason_o}, 32'hc091);

        clear_inputs();
        s9_valid = 1'b1;
        mem_access = 1'b1;
        lsu_is_store = 1'b1;
        lsu_lane1_mem = 1'b1;
        slot1_emit_valid = 1'b1;
        slot1_fire = 1'b1;
        slot1_emit_class = 4'b0010;
        dcache_mem_req = 1'b1;
        dcache_req_valid = 1'b1;
        dcache_is_store = 1'b1;
        dcache_paddr = 32'h1c00_2000;
        dcache_size = 2'b01;
        dcache_store_data = 32'hcafe_beef;
        #1;
        `check("S9EVT forwards slot1 store event",
               slot1_emit_valid_o && slot1_fire_o &&
               slot1_emit_class_o == 4'b0010 &&
               dcache_req_valid_o && dcache_is_store_o);
        `check32("S9EVT forwards slot1 store paddr", dcache_paddr_o, 32'h1c00_2000);
        `check32("S9EVT forwards slot1 store data", dcache_store_data_o, 32'hcafe_beef);
        `check32("S9EVT packs slot1 store summary",
                 {24'd0, lsu_event_summary_o}, {24'd0, 8'b1000_0110});
        `check32("S9EVT packs slot1 store reason",
                 {16'd0, mem_event_reason_o}, 32'hc3e1);

        clear_inputs();
        s9_valid = 1'b1;
        preld_req = 1'b1;
        dcache_req_valid = 1'b1;
        dcache_is_load = 1'b1;
        dcache_paddr = 32'h1c00_3000;
        #1;
        `check("S9EVT forwards preld as load-like request",
               dcache_req_valid_o && dcache_is_load_o && !dcache_is_store_o);
        `check32("S9EVT preld summary",
                 {24'd0, lsu_event_summary_o}, {24'd0, 8'b0100_0000});

        clear_inputs();
        lane0_tlb_exception = 1'b1;
        lane1_tlb_exception = 1'b1;
        lane1_mem_exception = 1'b1;
        slot1_emit_class = 4'b1111;
        #1;
        `check("S9EVT masks invalid slot1 class",
               !slot1_emit_valid_o && !slot1_fire_o &&
               slot1_emit_class_o == 4'd0);
        `check32("S9EVT packs exception summary",
                 {24'd0, lsu_event_summary_o}, {24'd0, 8'b0011_1000});

        finish_tb();
    end
endmodule

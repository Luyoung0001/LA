`timescale 1ns / 1ps

module s10_raw_mem_event_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        commit_ready;
    logic        any_exception;
    logic        slot0_is_load;
    logic        slot0_is_store;
    logic        slot0_is_sc;
    logic        slot0_sc_success;
    logic [1:0]  slot0_mem_size;
    logic        slot0_mem_sign_ext;
    logic        slot1_load_active;
    logic        slot1_store_active;
    logic [1:0]  slot1_mem_size;
    logic        slot1_load_sign_ext;
    logic        slot1_store_exception;
    logic        slot1_store_fault;
    logic        slot1_mem_exception;
    logic        slot1_mem_fault;
    logic [31:0] diff_mem_vaddr;
    logic [31:0] diff_mem_paddr;
    logic [31:0] diff_store_data;

    logic [7:0]  load_valid;
    logic [31:0] load_paddr;
    logic [31:0] load_vaddr;
    logic [7:0]  store_valid;
    logic [31:0] store_paddr;
    logic [31:0] store_vaddr;
    logic [31:0] store_data;

    s10_raw_mem_event_select u_dut (
        .commit_ready_i(commit_ready),
        .any_exception_i(any_exception),
        .slot0_is_load_i(slot0_is_load),
        .slot0_is_store_i(slot0_is_store),
        .slot0_is_sc_i(slot0_is_sc),
        .slot0_sc_success_i(slot0_sc_success),
        .slot0_mem_size_i(slot0_mem_size),
        .slot0_mem_sign_ext_i(slot0_mem_sign_ext),
        .slot1_load_active_i(slot1_load_active),
        .slot1_store_active_i(slot1_store_active),
        .slot1_mem_size_i(slot1_mem_size),
        .slot1_load_sign_ext_i(slot1_load_sign_ext),
        .slot1_store_exception_i(slot1_store_exception),
        .slot1_store_fault_i(slot1_store_fault),
        .slot1_mem_exception_i(slot1_mem_exception),
        .slot1_mem_fault_i(slot1_mem_fault),
        .diff_mem_vaddr_i(diff_mem_vaddr),
        .diff_mem_paddr_i(diff_mem_paddr),
        .diff_store_data_i(diff_store_data),
        .load_valid_o(load_valid),
        .load_paddr_o(load_paddr),
        .load_vaddr_o(load_vaddr),
        .store_valid_o(store_valid),
        .store_paddr_o(store_paddr),
        .store_vaddr_o(store_vaddr),
        .store_data_o(store_data)
    );

    task automatic clear_inputs;
        begin
            commit_ready = 1'b0;
            any_exception = 1'b0;
            slot0_is_load = 1'b0;
            slot0_is_store = 1'b0;
            slot0_is_sc = 1'b0;
            slot0_sc_success = 1'b0;
            slot0_mem_size = 2'b10;
            slot0_mem_sign_ext = 1'b0;
            slot1_load_active = 1'b0;
            slot1_store_active = 1'b0;
            slot1_mem_size = 2'b10;
            slot1_load_sign_ext = 1'b0;
            slot1_store_exception = 1'b0;
            slot1_store_fault = 1'b0;
            slot1_mem_exception = 1'b0;
            slot1_mem_fault = 1'b0;
            diff_mem_vaddr = 32'h4000_9002;
            diff_mem_paddr = 32'h0000_9002;
            diff_store_data = 32'h1234_abcd;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("RMEM idle clears valid flags",
               load_valid == 8'h00 && store_valid == 8'h00);
        `check32("RMEM idle keeps raw load address sideband", load_paddr, 32'h0000_9002);
        `check32("RMEM idle keeps raw store sideband when no store is active",
                 store_data, 32'h1234_abcd);

        clear_inputs();
        commit_ready = 1'b1;
        slot0_is_load = 1'b1;
        slot0_mem_size = 2'b00;
        slot0_mem_sign_ext = 1'b1;
        #1;
        `check("RMEM slot0 signed byte load emits byte-signed kind", load_valid == 8'h01);
        `check32("RMEM slot0 load paddr pass-through", load_paddr, 32'h0000_9002);
        `check32("RMEM slot0 load vaddr pass-through", load_vaddr, 32'h4000_9002);

        clear_inputs();
        commit_ready = 1'b1;
        slot0_is_load = 1'b1;
        slot0_mem_size = 2'b01;
        slot0_mem_sign_ext = 1'b0;
        #1;
        `check("RMEM slot0 unsigned half load emits half-unsigned kind", load_valid == 8'h08);

        clear_inputs();
        commit_ready = 1'b1;
        slot1_load_active = 1'b1;
        slot1_mem_size = 2'b10;
        slot1_load_sign_ext = 1'b0;
        #1;
        `check("RMEM slot1 word load emits slot1 load kind", load_valid == 8'h10);

        clear_inputs();
        commit_ready = 1'b1;
        slot1_load_active = 1'b1;
        slot1_mem_exception = 1'b1;
        #1;
        `check("RMEM slot1 load exception suppresses raw load event", load_valid == 8'h00);

        clear_inputs();
        commit_ready = 1'b1;
        slot1_load_active = 1'b1;
        slot1_mem_fault = 1'b1;
        #1;
        `check("RMEM slot1 load fault suppresses raw load event", load_valid == 8'h00);

        clear_inputs();
        commit_ready = 1'b1;
        slot0_is_store = 1'b1;
        slot0_mem_size = 2'b00;
        #1;
        `check("RMEM slot0 byte store emits byte kind", store_valid == 8'h01);
        `check32("RMEM slot0 byte store aligns data by vaddr lane", store_data, 32'h00cd_0000);
        `check32("RMEM slot0 store paddr pass-through", store_paddr, 32'h0000_9002);
        `check32("RMEM slot0 store vaddr pass-through", store_vaddr, 32'h4000_9002);

        clear_inputs();
        commit_ready = 1'b1;
        slot0_is_store = 1'b1;
        slot0_is_sc = 1'b1;
        slot0_sc_success = 1'b0;
        slot0_mem_size = 2'b01;
        #1;
        `check("RMEM failed SC suppresses raw store event", store_valid == 8'h00);

        clear_inputs();
        commit_ready = 1'b1;
        slot0_is_store = 1'b1;
        slot0_is_sc = 1'b1;
        slot0_sc_success = 1'b1;
        slot0_mem_size = 2'b01;
        #1;
        `check("RMEM successful SC emits SC kind", store_valid == 8'h08);
        `check32("RMEM successful SC keeps halfword lane alignment", store_data, 32'habcd_0000);

        clear_inputs();
        commit_ready = 1'b1;
        slot1_store_active = 1'b1;
        slot1_mem_size = 2'b01;
        #1;
        `check("RMEM slot1 half store emits slot1 store kind", store_valid == 8'h02);
        `check32("RMEM slot1 half store aligns data", store_data, 32'habcd_0000);

        clear_inputs();
        commit_ready = 1'b1;
        slot1_store_active = 1'b1;
        slot1_store_exception = 1'b1;
        #1;
        `check("RMEM slot1 store exception suppresses raw store event", store_valid == 8'h00);

        clear_inputs();
        commit_ready = 1'b1;
        slot1_store_active = 1'b1;
        slot1_store_fault = 1'b1;
        #1;
        `check("RMEM slot1 store fault suppresses raw store event", store_valid == 8'h00);

        clear_inputs();
        commit_ready = 1'b1;
        any_exception = 1'b1;
        slot0_is_load = 1'b1;
        slot1_store_active = 1'b1;
        #1;
        `check("RMEM visible older exception suppresses all raw mem events",
               load_valid == 8'h00 && store_valid == 8'h00);

        finish_tb();
    end
endmodule

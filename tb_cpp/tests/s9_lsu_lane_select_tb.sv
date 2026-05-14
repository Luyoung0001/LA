`timescale 1ns / 1ps

module s9_lsu_lane_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s9_valid;
    logic        lane0_is_load;
    logic        lane0_is_store;
    logic        lane0_exception;
    logic [31:0] lane0_addr;
    logic [1:0]  lane0_mem_size;
    logic [31:0] lane0_store_data;
    logic        slot1_valid;
    logic        slot1_issue_valid;
    logic [3:0]  slot1_issue_class;
    logic        slot1_is_load;
    logic        slot1_is_store;
    logic        slot1_exception;
    logic [31:0] slot1_addr;
    logic [1:0]  slot1_mem_size;
    logic [31:0] slot1_store_data;

    logic        slot1_mem_lsu;
    logic        slot1_load_lsu;
    logic        slot1_store_lsu;
    logic        lane1_mem;
    logic        lane1_mem_exception;
    logic        lsu_is_load;
    logic        lsu_is_store;
    logic [31:0] lsu_addr;
    logic [1:0]  lsu_mem_size;
    logic [31:0] lsu_store_data;

    s9_lsu_lane_select u_dut (
        .s9_valid_i(s9_valid),
        .lane0_is_load_i(lane0_is_load),
        .lane0_is_store_i(lane0_is_store),
        .lane0_exception_i(lane0_exception),
        .lane0_addr_i(lane0_addr),
        .lane0_mem_size_i(lane0_mem_size),
        .lane0_store_data_i(lane0_store_data),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
        .slot1_exception_i(slot1_exception),
        .slot1_addr_i(slot1_addr),
        .slot1_mem_size_i(slot1_mem_size),
        .slot1_store_data_i(slot1_store_data),
        .slot1_mem_lsu_o(slot1_mem_lsu),
        .slot1_load_lsu_o(slot1_load_lsu),
        .slot1_store_lsu_o(slot1_store_lsu),
        .lane1_mem_o(lane1_mem),
        .lane1_mem_exception_o(lane1_mem_exception),
        .lsu_is_load_o(lsu_is_load),
        .lsu_is_store_o(lsu_is_store),
        .lsu_addr_o(lsu_addr),
        .lsu_mem_size_o(lsu_mem_size),
        .lsu_store_data_o(lsu_store_data)
    );

    task automatic clear_inputs;
        begin
            s9_valid = 1'b0;
            lane0_is_load = 1'b0;
            lane0_is_store = 1'b0;
            lane0_exception = 1'b0;
            lane0_addr = 32'h1000_0010;
            lane0_mem_size = 2'b10;
            lane0_store_data = 32'haaaa_0000;
            slot1_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b0;
            slot1_exception = 1'b0;
            slot1_addr = 32'h2000_0020;
            slot1_mem_size = 2'b01;
            slot1_store_data = 32'hbbbb_1111;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S9 LSU select idle has no memory op",
               !slot1_mem_lsu && !lsu_is_load && !lsu_is_store);
        `check32("S9 LSU select idle keeps lane0 address", lsu_addr, 32'h1000_0010);

        clear_inputs();
        s9_valid = 1'b1;
        lane0_is_load = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select lane0 load blocks slot1 store",
               lsu_is_load && !lsu_is_store && !slot1_mem_lsu);
        `check32("S9 LSU select lane0 load address wins", lsu_addr, 32'h1000_0010);

        clear_inputs();
        s9_valid = 1'b1;
        lane0_is_store = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        #1;
        `check("S9 LSU select lane0 store blocks slot1 load",
               !lsu_is_load && lsu_is_store && !slot1_mem_lsu);
        `check32("S9 LSU select lane0 store data wins", lsu_store_data, 32'haaaa_0000);

        clear_inputs();
        s9_valid = 1'b1;
        lane0_exception = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        #1;
        `check("S9 LSU select lane0 exception suppresses slot1 memory",
               !slot1_mem_lsu && !lsu_is_load && !lsu_is_store);

        clear_inputs();
        s9_valid = 1'b1;
        lane0_exception = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select lane0 exception suppresses slot1 store owner",
               !slot1_mem_lsu && !slot1_store_lsu && !lane1_mem &&
               !lane1_mem_exception && !lsu_is_load && !lsu_is_store);

        clear_inputs();
        s9_valid = 1'b1;
        lane0_is_store = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select lane0 store suppresses younger slot1 store owner",
               !slot1_mem_lsu && !slot1_store_lsu && !lane1_mem &&
               lsu_is_store);
        `check32("S9 LSU select older lane0 store data still wins",
                 lsu_store_data, 32'haaaa_0000);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        #1;
        `check("S9 LSU select issued slot1 load takes shared LSU",
               slot1_mem_lsu && slot1_load_lsu && lane1_mem &&
               lsu_is_load && !lsu_is_store);
        `check32("S9 LSU select slot1 load address", lsu_addr, 32'h2000_0020);
        `check32("S9 LSU select slot1 load size", {30'd0, lsu_mem_size}, 32'd1);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select issued slot1 store takes shared LSU",
               slot1_mem_lsu && slot1_store_lsu && lane1_mem &&
               !lsu_is_load && lsu_is_store);
        `check32("S9 LSU select slot1 store address", lsu_addr, 32'h2000_0020);
        `check32("S9 LSU select slot1 store data", lsu_store_data, 32'hbbbb_1111);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        slot1_exception = 1'b1;
        #1;
        `check("S9 LSU select preserves selected slot1 exception sideband",
               slot1_mem_lsu && slot1_store_lsu && lane1_mem_exception &&
               lsu_is_store);
        `check32("S9 LSU select exceptional slot1 store data",
                 lsu_store_data, 32'hbbbb_1111);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        #1;
        `check("S9 LSU select unissued slot1 memory remains sideband-only",
               !slot1_mem_lsu && !lsu_is_load && !lsu_is_store);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b0;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select invalid slot1 cannot take LSU",
               !slot1_mem_lsu && !lsu_is_store && !lane1_mem_exception);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        slot1_is_load = 1'b1;
        #1;
        `check("S9 LSU select ignores stale load payload without load class",
               !slot1_mem_lsu && !slot1_load_lsu && !lsu_is_load);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select rejects load class with store payload",
               !slot1_mem_lsu && !slot1_load_lsu && !slot1_store_lsu &&
               !lsu_is_load && !lsu_is_store);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0001;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select ignores stale store payload without store class",
               !slot1_mem_lsu && !slot1_store_lsu && !lsu_is_store);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_is_load = 1'b1;
        #1;
        `check("S9 LSU select rejects store class with load payload",
               !slot1_mem_lsu && !slot1_load_lsu && !slot1_store_lsu &&
               !lsu_is_load && !lsu_is_store);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0110;
        slot1_is_load = 1'b1;
        slot1_is_store = 1'b1;
        #1;
        `check("S9 LSU select rejects ambiguous slot1 memory class",
               !slot1_mem_lsu && !slot1_load_lsu && !slot1_store_lsu &&
               !lsu_is_load && !lsu_is_store);

        clear_inputs();
        s9_valid = 1'b0;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        #1;
        `check("S9 LSU select invalid stage blocks issued slot1 class",
               !slot1_mem_lsu && !slot1_load_lsu && !lsu_is_load);

        finish_tb();
    end
endmodule

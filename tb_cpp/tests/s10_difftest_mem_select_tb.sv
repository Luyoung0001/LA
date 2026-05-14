`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s10_difftest_mem_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [7:0] raw_load_valid;
    logic [31:0] raw_load_paddr;
    logic [31:0] raw_load_vaddr;
    logic [7:0] raw_store_valid;
    logic [31:0] raw_store_paddr;
    logic [31:0] raw_store_vaddr;
    logic [31:0] raw_store_data;
    logic slot1_issue_valid;
    logic [3:0] slot1_issue_class;
    logic slot1_mem_lsu;
    logic slot1_is_load;
    logic slot1_is_store;
    logic slot1_commit_accept;
    logic [7:0] load_valid;
    logic [31:0] load_paddr;
    logic [31:0] load_vaddr;
    logic [7:0] store_valid;
    logic [31:0] store_paddr;
    logic [31:0] store_vaddr;
    logic [31:0] store_data;

    s10_difftest_mem_select u_dut (
        .raw_load_valid_i(raw_load_valid),
        .raw_load_paddr_i(raw_load_paddr),
        .raw_load_vaddr_i(raw_load_vaddr),
        .raw_store_valid_i(raw_store_valid),
        .raw_store_paddr_i(raw_store_paddr),
        .raw_store_vaddr_i(raw_store_vaddr),
        .raw_store_data_i(raw_store_data),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_mem_lsu_i(slot1_mem_lsu),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
        .slot1_commit_accept_i(slot1_commit_accept),
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
            raw_load_valid = 8'h00;
            raw_load_paddr = 32'd0;
            raw_load_vaddr = 32'd0;
            raw_store_valid = 8'h00;
            raw_store_paddr = 32'd0;
            raw_store_vaddr = 32'd0;
            raw_store_data = 32'd0;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
            slot1_mem_lsu = 1'b0;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b0;
            slot1_commit_accept = 1'b0;
        end
    endtask

    task automatic drive_load_event;
        begin
            clear_inputs();
            raw_load_valid = 8'h10;
            raw_load_paddr = 32'h0000_9000;
            raw_load_vaddr = 32'h4000_9000;
        end
    endtask

    task automatic drive_store_event;
        begin
            clear_inputs();
            raw_store_valid = 8'h04;
            raw_store_paddr = 32'h0000_a000;
            raw_store_vaddr = 32'h4000_a000;
            raw_store_data = 32'hdead_beef;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("DMEMSEL idle clears events",
               load_valid == 8'h00 && store_valid == 8'h00 &&
               load_paddr == 32'd0 && store_data == 32'd0);

        drive_load_event();
        #1;
        `check("DMEMSEL slot0 load passes without slot1 ownership",
               load_valid == 8'h10 &&
               load_paddr == 32'h0000_9000 &&
               load_vaddr == 32'h4000_9000);

        drive_store_event();
        #1;
        `check("DMEMSEL slot0 store passes without slot1 ownership",
               store_valid == 8'h04 &&
               store_paddr == 32'h0000_a000 &&
               store_vaddr == 32'h4000_a000 &&
               store_data == 32'hdead_beef);

        drive_load_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        slot1_mem_lsu = 1'b1;
        slot1_is_load = 1'b1;
        slot1_commit_accept = 1'b0;
        #1;
        `check("DMEMSEL unaccepted slot1 load is hidden",
               load_valid == 8'h00 && load_paddr == 32'd0 &&
               load_vaddr == 32'd0);

        drive_load_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        slot1_mem_lsu = 1'b1;
        slot1_is_load = 1'b1;
        slot1_commit_accept = 1'b1;
        #1;
        `check("DMEMSEL accepted slot1 load passes",
               load_valid == 8'h10 &&
               load_paddr == 32'h0000_9000 &&
               load_vaddr == 32'h4000_9000);

        drive_store_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_STORE;
        slot1_mem_lsu = 1'b1;
        slot1_is_store = 1'b1;
        slot1_commit_accept = 1'b0;
        #1;
        `check("DMEMSEL unaccepted slot1 store is hidden",
               store_valid == 8'h00 && store_paddr == 32'd0 &&
               store_vaddr == 32'd0 && store_data == 32'd0);

        drive_store_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_STORE;
        slot1_mem_lsu = 1'b1;
        slot1_is_store = 1'b1;
        slot1_commit_accept = 1'b1;
        #1;
        `check("DMEMSEL accepted slot1 store passes",
               store_valid == 8'h04 &&
               store_paddr == 32'h0000_a000 &&
               store_vaddr == 32'h4000_a000 &&
               store_data == 32'hdead_beef);

        drive_load_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        slot1_mem_lsu = 1'b0;
        slot1_is_load = 1'b1;
        slot1_commit_accept = 1'b0;
        #1;
        `check("DMEMSEL no LSU ownership keeps raw load as slot0 event",
               load_valid == 8'h10 && load_paddr == 32'h0000_9000);

        drive_load_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_STORE;
        slot1_mem_lsu = 1'b1;
        slot1_is_load = 1'b1;
        slot1_commit_accept = 1'b1;
        #1;
        `check("DMEMSEL hides load when slot1 owner class mismatches payload",
               load_valid == 8'h00 && load_paddr == 32'd0 &&
               load_vaddr == 32'd0);

        drive_store_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        slot1_mem_lsu = 1'b1;
        slot1_is_store = 1'b1;
        slot1_commit_accept = 1'b1;
        #1;
        `check("DMEMSEL hides store when slot1 owner class mismatches payload",
               store_valid == 8'h00 && store_paddr == 32'd0 &&
               store_vaddr == 32'd0 && store_data == 32'd0);

        drive_store_event();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD | `CPU_SLOT1_CLASS_STORE;
        slot1_mem_lsu = 1'b1;
        slot1_is_load = 1'b1;
        slot1_is_store = 1'b1;
        slot1_commit_accept = 1'b1;
        #1;
        `check("DMEMSEL hides ambiguous slot1 memory owner event",
               store_valid == 8'h00 && store_paddr == 32'd0 &&
               store_vaddr == 32'd0 && store_data == 32'd0);

        finish_tb();
    end
endmodule

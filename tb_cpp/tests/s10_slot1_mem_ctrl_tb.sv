`timescale 1ns / 1ps

module s10_slot1_mem_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s10_valid;
    logic slot1_valid;
    logic slot1_issue_valid;
    logic [3:0] slot1_issue_class;
    logic slot1_is_load;
    logic slot1_is_store;
    logic slot1_mem_lsu;
    logic slot1_wb_en;
    logic [4:0] slot1_rd;
    logic slot1_exception;
    logic slot0_is_load;
    logic slot0_is_store;
    logic slot0_exception;
    logic shared_mem_valid;
    logic shared_mem_owner_slot1;
    logic shared_mem_slot1_req;
    logic shared_mem_slot1_load;
    logic shared_mem_slot1_store;
    logic dc_resp_valid;
    logic dc_resp_fault;
    logic commit_ready;
    logic any_exception;

    logic slot1_store_active;
    logic slot1_load_active;
    logic slot1_mem_active;
    logic slot1_store_exception;
    logic slot1_mem_exception;
    logic slot1_store_wait;
    logic slot1_load_wait;
    logic slot1_store_fault;
    logic slot1_load_fault;
    logic slot1_mem_fault;
    logic slot1_refetch;

    s10_slot1_mem_ctrl u_dut (
        .s10_valid_i(s10_valid),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
        .slot1_mem_lsu_i(slot1_mem_lsu),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_rd_i(slot1_rd),
        .slot1_exception_i(slot1_exception),
        .slot0_is_load_i(slot0_is_load),
        .slot0_is_store_i(slot0_is_store),
        .slot0_exception_i(slot0_exception),
        .shared_mem_valid_i(shared_mem_valid),
        .shared_mem_owner_slot1_i(shared_mem_owner_slot1),
        .shared_mem_slot1_req_i(shared_mem_slot1_req),
        .shared_mem_slot1_load_i(shared_mem_slot1_load),
        .shared_mem_slot1_store_i(shared_mem_slot1_store),
        .dc_resp_valid_i(dc_resp_valid),
        .dc_resp_fault_i(dc_resp_fault),
        .commit_ready_i(commit_ready),
        .any_exception_i(any_exception),
        .slot1_store_active_o(slot1_store_active),
        .slot1_load_active_o(slot1_load_active),
        .slot1_mem_active_o(slot1_mem_active),
        .slot1_store_exception_o(slot1_store_exception),
        .slot1_mem_exception_o(slot1_mem_exception),
        .slot1_store_wait_o(slot1_store_wait),
        .slot1_load_wait_o(slot1_load_wait),
        .slot1_store_fault_o(slot1_store_fault),
        .slot1_load_fault_o(slot1_load_fault),
        .slot1_mem_fault_o(slot1_mem_fault),
        .slot1_refetch_o(slot1_refetch)
    );

    task automatic drive_idle;
        begin
            s10_valid = 1'b1;
            slot1_valid = 1'b1;
            slot1_issue_valid = 1'b1;
            slot1_issue_class = 4'b1000;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b0;
            slot1_mem_lsu = 1'b1;
            slot1_wb_en = 1'b1;
            slot1_rd = 5'd7;
            slot1_exception = 1'b0;
            slot0_is_load = 1'b0;
            slot0_is_store = 1'b0;
            slot0_exception = 1'b0;
            shared_mem_valid = 1'b0;
            shared_mem_owner_slot1 = 1'b0;
            shared_mem_slot1_req = 1'b0;
            shared_mem_slot1_load = 1'b0;
            shared_mem_slot1_store = 1'b0;
            dc_resp_valid = 1'b1;
            dc_resp_fault = 1'b0;
            commit_ready = 1'b1;
            any_exception = 1'b0;
        end
    endtask

    task automatic drive_shared_slot1_load(input logic req);
        begin
            shared_mem_valid = 1'b1;
            shared_mem_owner_slot1 = 1'b1;
            shared_mem_slot1_req = req;
            shared_mem_slot1_load = 1'b1;
            shared_mem_slot1_store = 1'b0;
        end
    endtask

    task automatic drive_shared_slot1_store(input logic req);
        begin
            shared_mem_valid = 1'b1;
            shared_mem_owner_slot1 = 1'b1;
            shared_mem_slot1_req = req;
            shared_mem_slot1_load = 1'b0;
            shared_mem_slot1_store = 1'b1;
        end
    endtask

    task automatic check_no_mem(input string name);
        begin
            #1;
            `check(name, !slot1_store_active && !slot1_load_active &&
                         !slot1_mem_active && !slot1_store_wait &&
                         !slot1_load_wait && !slot1_mem_fault &&
                         !slot1_refetch);
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_idle();
        check_no_mem("slot1 non-memory stays inactive");

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_mem_lsu = 1'b0;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b0;
        check_no_mem("slot1 load without LSU ownership stays inactive");

        drive_idle();
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_mem_lsu = 1'b0;
        drive_shared_slot1_store(1'b1);
        dc_resp_valid = 1'b0;
        check_no_mem("slot1 store without LSU ownership stays inactive");

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 load waits for dcache response",
               slot1_load_active && slot1_mem_active &&
               slot1_store_wait && slot1_load_wait &&
               !slot1_mem_fault && !slot1_refetch);

        drive_idle();
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0010;
        drive_shared_slot1_store(1'b1);
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 store waits but is not load bypass wait",
               slot1_store_active && slot1_mem_active &&
               slot1_store_wait && !slot1_load_wait);

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_wb_en = 1'b0;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 load wait feedback requires writeback",
               slot1_load_active && slot1_store_wait && !slot1_load_wait);

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_rd = 5'd0;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 load wait feedback ignores r0",
               slot1_load_active && slot1_store_wait && !slot1_load_wait);

        drive_idle();
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_exception = 1'b1;
        drive_shared_slot1_store(1'b0);
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 store exception blocks wait and requests refetch",
               slot1_store_active && slot1_store_exception &&
               slot1_mem_exception && !slot1_store_wait &&
               !slot1_mem_fault && slot1_refetch);

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        dc_resp_fault = 1'b1;
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 stale DCache fault waits instead of refetching",
               slot1_load_active && slot1_store_wait && slot1_load_wait &&
               !slot1_mem_fault && !slot1_refetch);

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        dc_resp_fault = 1'b1;
        #1;
        `check("slot1 load fault requests refetch",
               slot1_load_active && slot1_load_fault && slot1_mem_fault &&
               !slot1_store_fault && slot1_refetch);

        drive_idle();
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0010;
        drive_shared_slot1_store(1'b1);
        dc_resp_fault = 1'b1;
        #1;
        `check("slot1 store fault requests refetch",
               slot1_store_active && slot1_store_fault && slot1_mem_fault &&
               !slot1_load_fault && slot1_refetch);

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        slot0_is_load = 1'b1;
        check_no_mem("slot0 load owns shared memory lane");

        drive_idle();
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0010;
        drive_shared_slot1_store(1'b1);
        slot0_is_store = 1'b1;
        check_no_mem("slot0 store owns shared memory lane");

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        slot0_exception = 1'b1;
        dc_resp_valid = 1'b0;
        #1;
        `check("slot0 exception blocks slot1 wait/refetch",
               slot1_load_active && !slot1_store_wait &&
               !slot1_load_wait && !slot1_mem_fault && !slot1_refetch);

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        dc_resp_fault = 1'b1;
        any_exception = 1'b1;
        #1;
        `check("slot0 visible exception suppresses slot1 refetch",
               slot1_mem_fault && !slot1_refetch);

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        dc_resp_fault = 1'b1;
        commit_ready = 1'b0;
        #1;
        `check("slot1 refetch waits for commit ready",
               slot1_mem_fault && !slot1_refetch);

        drive_idle();
        s10_valid = 1'b0;
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        check_no_mem("invalid s10 blocks slot1 memory");

        drive_idle();
        slot1_valid = 1'b0;
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        check_no_mem("invalid slot1 blocks memory");

        drive_idle();
        slot1_issue_valid = 1'b0;
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0010;
        drive_shared_slot1_store(1'b1);
        check_no_mem("non-issued slot1 blocks memory");

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b1000;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b0;
        check_no_mem("load payload without load class stays inactive");

        drive_idle();
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0001;
        drive_shared_slot1_store(1'b1);
        dc_resp_valid = 1'b0;
        check_no_mem("store payload without store class stays inactive");

        drive_idle();
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0100;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b0;
        check_no_mem("shared slot1 load owner rejects store payload mismatch");

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_issue_class = 4'b0010;
        drive_shared_slot1_store(1'b1);
        dc_resp_valid = 1'b0;
        check_no_mem("shared slot1 store owner rejects load payload mismatch");

        drive_idle();
        slot1_is_load = 1'b1;
        slot1_is_store = 1'b1;
        slot1_issue_class = 4'b0110;
        drive_shared_slot1_store(1'b1);
        dc_resp_valid = 1'b0;
        check_no_mem("shared slot1 owner rejects ambiguous memory class");

        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module s10_shared_mem_outcome_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s10_valid;
    logic        commit_ready;
    logic        slot0_is_load;
    logic        slot0_is_store;
    logic        slot0_is_sc;
    logic        slot0_sc_success;
    logic        slot0_exception;
    logic        slot1_valid;
    logic        slot1_issue_valid;
    logic [3:0]  slot1_issue_class;
    logic        slot1_is_load;
    logic        slot1_is_store;
    logic        slot1_mem_lsu;
    logic        slot1_wb_en;
    logic [4:0]  slot1_rd;
    logic [31:0] slot1_alu_result;
    logic [31:0] slot1_load_data;
    logic        slot1_exception;
    logic        shared_mem_valid;
    logic        shared_mem_owner_slot0;
    logic        shared_mem_owner_slot1;
    logic        shared_mem_slot0_req;
    logic        shared_mem_slot1_req;
    logic        shared_mem_slot1_load;
    logic        shared_mem_slot1_store;
    logic        dc_resp_valid;
    logic        dc_resp_fault;

    logic        slot1_store_active;
    logic        slot1_load_active;
    logic        slot1_mem_active;
    logic        slot1_store_exception;
    logic        slot1_mem_exception;
    logic        slot1_store_wait;
    logic        slot1_load_wait;
    logic        slot1_store_fault;
    logic        slot1_load_fault;
    logic        slot1_mem_fault;
    logic        slot1_refetch;
    logic        slot0_resp_owner;
    logic        slot0_mem_fault;
    logic        any_exception;
    logic [31:0] slot1_wb_data;
    logic        slot1_rf_we_candidate;
    logic [4:0]  slot1_rf_waddr_candidate;
    logic [31:0] slot1_rf_wdata_candidate;

    s10_shared_mem_outcome u_dut (
        .s10_valid_i(s10_valid),
        .commit_ready_i(commit_ready),
        .slot0_is_load_i(slot0_is_load),
        .slot0_is_store_i(slot0_is_store),
        .slot0_is_sc_i(slot0_is_sc),
        .slot0_sc_success_i(slot0_sc_success),
        .slot0_exception_i(slot0_exception),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
        .slot1_mem_lsu_i(slot1_mem_lsu),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_rd_i(slot1_rd),
        .slot1_alu_result_i(slot1_alu_result),
        .slot1_load_data_i(slot1_load_data),
        .slot1_exception_i(slot1_exception),
        .shared_mem_valid_i(shared_mem_valid),
        .shared_mem_owner_slot0_i(shared_mem_owner_slot0),
        .shared_mem_owner_slot1_i(shared_mem_owner_slot1),
        .shared_mem_slot0_req_i(shared_mem_slot0_req),
        .shared_mem_slot1_req_i(shared_mem_slot1_req),
        .shared_mem_slot1_load_i(shared_mem_slot1_load),
        .shared_mem_slot1_store_i(shared_mem_slot1_store),
        .dc_resp_valid_i(dc_resp_valid),
        .dc_resp_fault_i(dc_resp_fault),
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
        .slot1_refetch_o(slot1_refetch),
        .slot0_resp_owner_o(slot0_resp_owner),
        .slot0_mem_fault_o(slot0_mem_fault),
        .any_exception_o(any_exception),
        .slot1_wb_data_o(slot1_wb_data),
        .slot1_rf_we_candidate_o(slot1_rf_we_candidate),
        .slot1_rf_waddr_candidate_o(slot1_rf_waddr_candidate),
        .slot1_rf_wdata_candidate_o(slot1_rf_wdata_candidate)
    );

    task automatic drive_clean_slot1_alu;
        begin
            s10_valid = 1'b1;
            commit_ready = 1'b1;
            slot0_is_load = 1'b0;
            slot0_is_store = 1'b0;
            slot0_is_sc = 1'b0;
            slot0_sc_success = 1'b0;
            slot0_exception = 1'b0;
            slot1_valid = 1'b1;
            slot1_issue_valid = 1'b1;
            slot1_issue_class = 4'b1000;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b0;
            slot1_mem_lsu = 1'b0;
            slot1_wb_en = 1'b1;
            slot1_rd = 5'd9;
            slot1_alu_result = 32'h1234_5678;
            slot1_load_data = 32'hfeed_cafe;
            slot1_exception = 1'b0;
            shared_mem_valid = 1'b0;
            shared_mem_owner_slot0 = 1'b0;
            shared_mem_owner_slot1 = 1'b0;
            shared_mem_slot0_req = 1'b0;
            shared_mem_slot1_req = 1'b0;
            shared_mem_slot1_load = 1'b0;
            shared_mem_slot1_store = 1'b0;
            dc_resp_valid = 1'b0;
            dc_resp_fault = 1'b0;
        end
    endtask

    task automatic drive_shared_slot0(input logic req);
        begin
            shared_mem_valid = 1'b1;
            shared_mem_owner_slot0 = 1'b1;
            shared_mem_owner_slot1 = 1'b0;
            shared_mem_slot0_req = req;
            shared_mem_slot1_req = 1'b0;
            shared_mem_slot1_load = 1'b0;
            shared_mem_slot1_store = 1'b0;
        end
    endtask

    task automatic drive_shared_slot1_load(input logic req);
        begin
            shared_mem_valid = 1'b1;
            shared_mem_owner_slot0 = 1'b0;
            shared_mem_owner_slot1 = 1'b1;
            shared_mem_slot0_req = 1'b0;
            shared_mem_slot1_req = req;
            shared_mem_slot1_load = 1'b1;
            shared_mem_slot1_store = 1'b0;
        end
    endtask

    task automatic drive_shared_slot1_store(input logic req);
        begin
            shared_mem_valid = 1'b1;
            shared_mem_owner_slot0 = 1'b0;
            shared_mem_owner_slot1 = 1'b1;
            shared_mem_slot0_req = 1'b0;
            shared_mem_slot1_req = req;
            shared_mem_slot1_load = 1'b0;
            shared_mem_slot1_store = 1'b1;
        end
    endtask

    task automatic check_no_candidate(input string name);
        begin
            #1;
            `check(name, !slot1_rf_we_candidate &&
                         slot1_rf_waddr_candidate == 5'd0 &&
                         slot1_rf_wdata_candidate == 32'd0);
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_clean_slot1_alu();
        #1;
        `check("shared outcome forwards clean slot1 ALU candidate",
               slot1_rf_we_candidate &&
               slot1_rf_waddr_candidate == 5'd9 &&
               slot1_rf_wdata_candidate == 32'h1234_5678 &&
               !slot0_resp_owner && !any_exception);
        `check32("shared outcome ALU data selects lane1 ALU result",
                 slot1_wb_data, 32'h1234_5678);

        drive_clean_slot1_alu();
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b1;
        #1;
        `check("stale DCache fault does not poison non-memory outcome",
               slot1_rf_we_candidate && !slot0_resp_owner &&
               !slot0_mem_fault && !any_exception);

        drive_clean_slot1_alu();
        slot0_is_load = 1'b1;
        drive_shared_slot0(1'b1);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b1;
        #1;
        `check("slot0 load owns shared response fault",
               slot0_resp_owner && slot0_mem_fault && any_exception);
        check_no_candidate("slot0 fault blocks slot1 writeback candidate");

        drive_clean_slot1_alu();
        slot0_is_store = 1'b1;
        slot0_is_sc = 1'b1;
        slot0_sc_success = 1'b0;
        drive_shared_slot0(1'b0);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b1;
        #1;
        `check("failed SC does not own stale DCache fault",
               !slot0_resp_owner && !slot0_mem_fault && !any_exception &&
               slot1_rf_we_candidate);

        drive_clean_slot1_alu();
        commit_ready = 1'b0;
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        slot1_mem_lsu = 1'b1;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 load waits inside shared outcome",
               slot1_load_active && slot1_mem_active &&
               slot1_store_wait && slot1_load_wait &&
               !slot0_resp_owner && !slot1_mem_fault && !slot1_refetch);
        check_no_candidate("pending slot1 load has no writeback candidate");

        drive_clean_slot1_alu();
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        slot1_mem_lsu = 1'b1;
        slot1_load_data = 32'ha5a5_5a5a;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b0;
        #1;
        `check("slot1 load owns response without slot0 memory owner",
               slot1_load_active && slot1_mem_active && !slot0_resp_owner &&
               !slot1_store_wait && !slot1_mem_fault);
        `check("slot1 load forms RF candidate from formatted data",
               slot1_rf_we_candidate &&
               slot1_rf_waddr_candidate == 5'd9 &&
               slot1_rf_wdata_candidate == 32'ha5a5_5a5a);
        `check32("shared outcome load data selects lane1 load result",
                 slot1_wb_data, 32'ha5a5_5a5a);

        drive_clean_slot1_alu();
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        slot1_mem_lsu = 1'b1;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b1;
        #1;
        `check("slot1 load fault becomes precise slot1 refetch",
               slot1_load_fault && slot1_mem_fault && slot1_refetch &&
               !slot0_mem_fault && !any_exception);
        check_no_candidate("slot1 load fault blocks RF candidate");

        drive_clean_slot1_alu();
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        slot1_mem_lsu = 1'b1;
        drive_shared_slot1_store(1'b1);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b1;
        #1;
        `check("slot1 store fault becomes precise slot1 refetch",
               slot1_store_active && slot1_store_fault &&
               slot1_mem_fault && slot1_refetch &&
               !slot0_mem_fault && !any_exception);
        check_no_candidate("slot1 store fault keeps RF candidate disabled");

        drive_clean_slot1_alu();
        slot1_issue_class = 4'b0010;
        slot1_is_store = 1'b1;
        slot1_mem_lsu = 1'b1;
        slot1_wb_en = 1'b0;
        slot1_exception = 1'b1;
        drive_shared_slot1_store(1'b0);
        dc_resp_valid = 1'b0;
        #1;
        `check("slot1 store exception requests precise refetch",
               slot1_store_exception && slot1_mem_exception &&
               slot1_refetch && !slot1_store_wait);

        drive_clean_slot1_alu();
        slot0_exception = 1'b1;
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        slot1_mem_lsu = 1'b1;
        drive_shared_slot1_load(1'b0);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b1;
        #1;
        `check("slot0 exception suppresses younger slot1 refetch",
               any_exception && !slot1_refetch &&
               !slot1_rf_we_candidate && !slot0_resp_owner);

        drive_clean_slot1_alu();
        slot1_issue_class = 4'b0100;
        slot1_is_load = 1'b1;
        slot1_mem_lsu = 1'b1;
        slot0_is_store = 1'b1;
        drive_shared_slot0(1'b1);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b0;
        #1;
        `check("slot0 store owner blocks slot1 memory ownership",
               slot0_resp_owner && !slot1_mem_active &&
               !slot1_load_active && !slot1_store_wait);

        drive_clean_slot1_alu();
        slot1_issue_class = 4'b0100;
        slot1_is_store = 1'b1;
        slot1_mem_lsu = 1'b1;
        drive_shared_slot1_load(1'b1);
        dc_resp_valid = 1'b1;
        dc_resp_fault = 1'b1;
        #1;
        `check("shared outcome ignores inconsistent slot1 memory owner facts",
               !slot1_mem_active && !slot1_load_active &&
               !slot1_store_active && !slot1_mem_fault &&
               !slot1_refetch && slot1_rf_we_candidate);

        finish_tb();
    end
endmodule

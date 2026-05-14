`timescale 1ns / 1ps

module backend_slot1_activity_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       stage_valid;
    logic       slot1_valid;
    logic       slot1_issue_valid;
    logic       slot1_wb_en;
    logic       slot1_is_load;
    logic       slot1_is_store;
    logic [4:0] slot1_rd;
    logic       slot1_selected;
    logic       slot1_active;
    logic       slot1_wb_active;
    logic       slot1_load_active;
    logic       slot1_store_active;
    logic       slot1_load_pending;

    backend_slot1_activity u_dut (
        .stage_valid_i(stage_valid),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
        .slot1_rd_i(slot1_rd),
        .slot1_selected_o(slot1_selected),
        .slot1_active_o(slot1_active),
        .slot1_wb_active_o(slot1_wb_active),
        .slot1_load_active_o(slot1_load_active),
        .slot1_store_active_o(slot1_store_active),
        .slot1_load_pending_o(slot1_load_pending)
    );

    task automatic drive_active_load;
        begin
            stage_valid = 1'b1;
            slot1_valid = 1'b1;
            slot1_issue_valid = 1'b1;
            slot1_wb_en = 1'b1;
            slot1_is_load = 1'b1;
            slot1_is_store = 1'b0;
            slot1_rd = 5'd7;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_active_load();
        #1;
        `check("slot1 activity selected and active",
               slot1_selected && slot1_active);
        `check("slot1 activity load pending",
               slot1_wb_active && slot1_load_active &&
               !slot1_store_active && slot1_load_pending);

        stage_valid = 1'b0;
        #1;
        `check("slot1 selected is independent of stage valid",
               slot1_selected && !slot1_active && !slot1_load_pending);

        drive_active_load();
        slot1_valid = 1'b0;
        #1;
        `check("slot1 invalid clears selected activity",
               !slot1_selected && !slot1_active && !slot1_load_pending);

        drive_active_load();
        slot1_issue_valid = 1'b0;
        #1;
        `check("slot1 non-issued clears selected activity",
               !slot1_selected && !slot1_active && !slot1_load_pending);

        drive_active_load();
        slot1_wb_en = 1'b0;
        #1;
        `check("slot1 load without wb is active but not pending",
               slot1_active && slot1_load_active &&
               !slot1_wb_active && !slot1_load_pending);

        drive_active_load();
        slot1_rd = 5'd0;
        #1;
        `check("slot1 r0 load is active but not pending",
               slot1_active && slot1_load_active &&
               !slot1_wb_active && !slot1_load_pending);

        drive_active_load();
        slot1_is_load = 1'b0;
        slot1_is_store = 1'b1;
        #1;
        `check("slot1 store activity has no load pending",
               slot1_active && !slot1_load_active &&
               slot1_store_active && !slot1_load_pending);

        finish_tb();
    end
endmodule

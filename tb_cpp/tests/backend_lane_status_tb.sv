`timescale 1ns / 1ps

module backend_lane_status_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       producer_valid;
    logic       producer_lane0_load;
    logic [4:0] producer_lane0_rd;
    logic       producer_lane1_valid;
    logic       producer_lane1_issue_valid;
    logic       producer_lane1_wb_en;
    logic       producer_lane1_load;
    logic [3:0] producer_lane1_issue_class;
    logic [4:0] producer_lane1_rd;
    logic       consumer_lane0_uses_rs1;
    logic       consumer_lane0_uses_rs2;
    logic [4:0] consumer_lane0_rs1;
    logic [4:0] consumer_lane0_rs2;
    logic       consumer_lane1_active;
    logic       consumer_lane1_uses_rs1;
    logic       consumer_lane1_uses_rs2;
    logic [4:0] consumer_lane1_rs1;
    logic [4:0] consumer_lane1_rs2;
    logic       lane0_load_pending;
    logic       lane1_load_pending;
    logic       lane0_rs1_wait;
    logic       lane0_rs2_wait;
    logic       lane1_rs1_wait;
    logic       lane1_rs2_wait;
    logic       any_wait;

    backend_lane_status u_dut (
        .producer_valid_i(producer_valid),
        .producer_lane0_load_i(producer_lane0_load),
        .producer_lane0_rd_i(producer_lane0_rd),
        .producer_lane1_valid_i(producer_lane1_valid),
        .producer_lane1_issue_valid_i(producer_lane1_issue_valid),
        .producer_lane1_wb_en_i(producer_lane1_wb_en),
        .producer_lane1_issue_class_i(producer_lane1_issue_class),
        .producer_lane1_rd_i(producer_lane1_rd),
        .consumer_lane0_uses_rs1_i(consumer_lane0_uses_rs1),
        .consumer_lane0_uses_rs2_i(consumer_lane0_uses_rs2),
        .consumer_lane0_rs1_i(consumer_lane0_rs1),
        .consumer_lane0_rs2_i(consumer_lane0_rs2),
        .consumer_lane1_active_i(consumer_lane1_active),
        .consumer_lane1_uses_rs1_i(consumer_lane1_uses_rs1),
        .consumer_lane1_uses_rs2_i(consumer_lane1_uses_rs2),
        .consumer_lane1_rs1_i(consumer_lane1_rs1),
        .consumer_lane1_rs2_i(consumer_lane1_rs2),
        .producer_lane0_load_pending_o(lane0_load_pending),
        .producer_lane1_load_pending_o(lane1_load_pending),
        .consumer_lane0_rs1_wait_o(lane0_rs1_wait),
        .consumer_lane0_rs2_wait_o(lane0_rs2_wait),
        .consumer_lane1_rs1_wait_o(lane1_rs1_wait),
        .consumer_lane1_rs2_wait_o(lane1_rs2_wait),
        .any_wait_o(any_wait)
    );

    initial begin
        tb_start();
        producer_valid = 1'b0;
        producer_lane0_load = 1'b0;
        producer_lane0_rd = 5'd0;
        producer_lane1_valid = 1'b0;
        producer_lane1_issue_valid = 1'b0;
        producer_lane1_wb_en = 1'b0;
        producer_lane1_load = 1'b0;
        producer_lane1_issue_class = 4'd0;
        producer_lane1_rd = 5'd0;
        consumer_lane0_uses_rs1 = 1'b0;
        consumer_lane0_uses_rs2 = 1'b0;
        consumer_lane0_rs1 = 5'd0;
        consumer_lane0_rs2 = 5'd0;
        consumer_lane1_active = 1'b0;
        consumer_lane1_uses_rs1 = 1'b0;
        consumer_lane1_uses_rs2 = 1'b0;
        consumer_lane1_rs1 = 5'd0;
        consumer_lane1_rs2 = 5'd0;
        #1;

        `check("LANE idle has no waits", !lane0_load_pending &&
               !lane1_load_pending && !any_wait);

        producer_valid = 1'b1;
        producer_lane0_load = 1'b1;
        producer_lane0_rd = 5'd3;
        consumer_lane0_uses_rs1 = 1'b1;
        consumer_lane0_rs1 = 5'd3;
        #1;
        `check("LANE lane0 load blocks lane0 rs1",
               lane0_load_pending && lane0_rs1_wait && any_wait);

        consumer_lane0_rs1 = 5'd0;
        consumer_lane0_rs2 = 5'd3;
        consumer_lane0_uses_rs2 = 1'b1;
        #1;
        `check("LANE lane0 load blocks lane0 rs2",
               lane0_rs2_wait && any_wait && !lane0_rs1_wait);

        producer_lane0_load = 1'b0;
        producer_lane1_valid = 1'b1;
        producer_lane1_issue_valid = 1'b1;
        producer_lane1_wb_en = 1'b1;
        producer_lane1_load = 1'b1;
        producer_lane1_issue_class = 4'b0100;
        producer_lane1_rd = 5'd7;
        consumer_lane0_rs2 = 5'd7;
        #1;
        `check("LANE lane1 load blocks lane0 consumer",
               lane1_load_pending && lane0_rs2_wait && any_wait);

        consumer_lane0_uses_rs2 = 1'b0;
        consumer_lane1_active = 1'b1;
        consumer_lane1_uses_rs1 = 1'b1;
        consumer_lane1_rs1 = 5'd7;
        #1;
        `check("LANE lane1 load blocks lane1 rs1",
               lane1_rs1_wait && any_wait && !lane0_rs2_wait);

        producer_lane1_issue_class = 4'b1000;
        #1;
        `check("LANE payload load without load class does not block",
               !lane1_load_pending && !lane1_rs1_wait && !any_wait);

        producer_lane1_issue_class = 4'b0100;
        #1;

        consumer_lane1_active = 1'b0;
        #1;
        `check("LANE inactive lane1 consumer ignores matches",
               !lane1_rs1_wait && !any_wait);

        producer_lane1_wb_en = 1'b0;
        consumer_lane1_active = 1'b1;
        #1;
        `check("LANE lane1 producer without wb is not pending",
               !lane1_load_pending && !any_wait);

        producer_lane1_wb_en = 1'b1;
        producer_lane1_rd = 5'd0;
        consumer_lane1_rs1 = 5'd0;
        #1;
        `check("LANE x0 load destination does not block",
               !lane1_load_pending && !any_wait);

        producer_lane1_rd = 5'd9;
        consumer_lane1_rs1 = 5'd9;
        producer_lane1_valid = 1'b0;
        #1;
        `check("LANE invalid lane1 producer is not pending",
               !lane1_load_pending && !any_wait);

        finish_tb();
    end
endmodule

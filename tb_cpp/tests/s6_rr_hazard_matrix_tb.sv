`timescale 1ns / 1ps

module s6_rr_hazard_matrix_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       rr_valid;
    logic       s7_valid;
    logic       s7_is_load;
    logic [4:0] s7_rd;
    logic       s7_slot1_valid;
    logic       s7_slot1_issue_valid;
    logic       s7_slot1_wb_en;
    logic       s7_slot1_is_load;
    logic [3:0] s7_slot1_issue_class;
    logic [4:0] s7_slot1_rd;
    logic       s8_valid;
    logic       s8_is_load;
    logic [4:0] s8_rd;
    logic       s8_slot1_valid;
    logic       s8_slot1_issue_valid;
    logic       s8_slot1_wb_en;
    logic       s8_slot1_is_load;
    logic [3:0] s8_slot1_issue_class;
    logic [4:0] s8_slot1_rd;
    logic       s9_valid;
    logic       s9_is_load;
    logic [4:0] s9_rd;
    logic       s9_slot1_valid;
    logic       s9_slot1_issue_valid;
    logic       s9_slot1_wb_en;
    logic       s9_slot1_is_load;
    logic [3:0] s9_slot1_issue_class;
    logic [4:0] s9_slot1_rd;
    logic       lane0_uses_rs1;
    logic       lane0_uses_rs2;
    logic [4:0] lane0_rs1;
    logic [4:0] lane0_rs2;
    logic       lane1_active;
    logic       lane1_uses_rs1;
    logic       lane1_uses_rs2;
    logic [4:0] lane1_rs1;
    logic [4:0] lane1_rs2;
    logic       s7_lane0_load_pending;
    logic       s7_lane1_load_pending;
    logic       s8_lane0_load_pending;
    logic       s8_lane1_load_pending;
    logic       s9_lane0_load_pending;
    logic       s9_lane1_load_pending;
    logic       lane0_rs1_wait_s7;
    logic       lane0_rs2_wait_s7;
    logic       lane0_rs1_wait_s8;
    logic       lane0_rs2_wait_s8;
    logic       lane0_rs1_wait_s9;
    logic       lane0_rs2_wait_s9;
    logic       lane1_rs1_wait_s7;
    logic       lane1_rs2_wait_s7;
    logic       lane1_rs1_wait_s8;
    logic       lane1_rs2_wait_s8;
    logic       lane1_rs1_wait_s9;
    logic       lane1_rs2_wait_s9;
    logic       load_use_hazard;

    s6_rr_hazard_matrix u_dut (
        .rr_valid_i(rr_valid),
        .s7_valid_i(s7_valid),
        .s7_is_load_i(s7_is_load),
        .s7_rd_i(s7_rd),
        .s7_slot1_valid_i(s7_slot1_valid),
        .s7_slot1_issue_valid_i(s7_slot1_issue_valid),
        .s7_slot1_wb_en_i(s7_slot1_wb_en),
        .s7_slot1_issue_class_i(s7_slot1_issue_class),
        .s7_slot1_rd_i(s7_slot1_rd),
        .s8_valid_i(s8_valid),
        .s8_is_load_i(s8_is_load),
        .s8_rd_i(s8_rd),
        .s8_slot1_valid_i(s8_slot1_valid),
        .s8_slot1_issue_valid_i(s8_slot1_issue_valid),
        .s8_slot1_wb_en_i(s8_slot1_wb_en),
        .s8_slot1_issue_class_i(s8_slot1_issue_class),
        .s8_slot1_rd_i(s8_slot1_rd),
        .s9_valid_i(s9_valid),
        .s9_is_load_i(s9_is_load),
        .s9_rd_i(s9_rd),
        .s9_slot1_valid_i(s9_slot1_valid),
        .s9_slot1_issue_valid_i(s9_slot1_issue_valid),
        .s9_slot1_wb_en_i(s9_slot1_wb_en),
        .s9_slot1_issue_class_i(s9_slot1_issue_class),
        .s9_slot1_rd_i(s9_slot1_rd),
        .lane0_uses_rs1_i(lane0_uses_rs1),
        .lane0_uses_rs2_i(lane0_uses_rs2),
        .lane0_rs1_i(lane0_rs1),
        .lane0_rs2_i(lane0_rs2),
        .lane1_active_i(lane1_active),
        .lane1_uses_rs1_i(lane1_uses_rs1),
        .lane1_uses_rs2_i(lane1_uses_rs2),
        .lane1_rs1_i(lane1_rs1),
        .lane1_rs2_i(lane1_rs2),
        .s7_lane0_load_pending_o(s7_lane0_load_pending),
        .s7_lane1_load_pending_o(s7_lane1_load_pending),
        .s8_lane0_load_pending_o(s8_lane0_load_pending),
        .s8_lane1_load_pending_o(s8_lane1_load_pending),
        .s9_lane0_load_pending_o(s9_lane0_load_pending),
        .s9_lane1_load_pending_o(s9_lane1_load_pending),
        .lane0_rs1_wait_s7_o(lane0_rs1_wait_s7),
        .lane0_rs2_wait_s7_o(lane0_rs2_wait_s7),
        .lane0_rs1_wait_s8_o(lane0_rs1_wait_s8),
        .lane0_rs2_wait_s8_o(lane0_rs2_wait_s8),
        .lane0_rs1_wait_s9_o(lane0_rs1_wait_s9),
        .lane0_rs2_wait_s9_o(lane0_rs2_wait_s9),
        .lane1_rs1_wait_s7_o(lane1_rs1_wait_s7),
        .lane1_rs2_wait_s7_o(lane1_rs2_wait_s7),
        .lane1_rs1_wait_s8_o(lane1_rs1_wait_s8),
        .lane1_rs2_wait_s8_o(lane1_rs2_wait_s8),
        .lane1_rs1_wait_s9_o(lane1_rs1_wait_s9),
        .lane1_rs2_wait_s9_o(lane1_rs2_wait_s9),
        .load_use_hazard_o(load_use_hazard)
    );

    task automatic clear_inputs;
        begin
            rr_valid = 1'b1;
            s7_valid = 1'b0;
            s7_is_load = 1'b0;
            s7_rd = 5'd0;
            s7_slot1_valid = 1'b0;
            s7_slot1_issue_valid = 1'b0;
            s7_slot1_wb_en = 1'b0;
            s7_slot1_is_load = 1'b0;
            s7_slot1_issue_class = 4'd0;
            s7_slot1_rd = 5'd0;
            s8_valid = 1'b0;
            s8_is_load = 1'b0;
            s8_rd = 5'd0;
            s8_slot1_valid = 1'b0;
            s8_slot1_issue_valid = 1'b0;
            s8_slot1_wb_en = 1'b0;
            s8_slot1_is_load = 1'b0;
            s8_slot1_issue_class = 4'd0;
            s8_slot1_rd = 5'd0;
            s9_valid = 1'b0;
            s9_is_load = 1'b0;
            s9_rd = 5'd0;
            s9_slot1_valid = 1'b0;
            s9_slot1_issue_valid = 1'b0;
            s9_slot1_wb_en = 1'b0;
            s9_slot1_is_load = 1'b0;
            s9_slot1_issue_class = 4'd0;
            s9_slot1_rd = 5'd0;
            lane0_uses_rs1 = 1'b0;
            lane0_uses_rs2 = 1'b0;
            lane0_rs1 = 5'd0;
            lane0_rs2 = 5'd0;
            lane1_active = 1'b0;
            lane1_uses_rs1 = 1'b0;
            lane1_uses_rs2 = 1'b0;
            lane1_rs1 = 5'd0;
            lane1_rs2 = 5'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S6 hazard matrix idle", !load_use_hazard &&
               !s7_lane0_load_pending && !s8_lane0_load_pending && !s9_lane0_load_pending);

        s7_valid = 1'b1;
        s7_is_load = 1'b1;
        s7_rd = 5'd3;
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd3;
        #1;
        `check("S6 hazard matrix blocks lane0 rs1 from S7 lane0",
               s7_lane0_load_pending && lane0_rs1_wait_s7 && load_use_hazard);

        clear_inputs();
        s8_valid = 1'b1;
        s8_slot1_valid = 1'b1;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_is_load = 1'b1;
        s8_slot1_issue_class = 4'b0100;
        s8_slot1_rd = 5'd8;
        lane0_uses_rs2 = 1'b1;
        lane0_rs2 = 5'd8;
        #1;
        `check("S6 hazard matrix blocks lane0 rs2 from S8 lane1",
               s8_lane1_load_pending && lane0_rs2_wait_s8 && load_use_hazard);

        s8_slot1_issue_class = 4'b1000;
        #1;
        `check("S6 hazard matrix ignores lane1 load payload without load class",
               !s8_lane1_load_pending && !lane0_rs2_wait_s8 && !load_use_hazard);

        clear_inputs();
        s9_valid = 1'b1;
        s9_is_load = 1'b1;
        s9_rd = 5'd12;
        lane1_active = 1'b1;
        lane1_uses_rs1 = 1'b1;
        lane1_rs1 = 5'd12;
        #1;
        `check("S6 hazard matrix blocks lane1 rs1 from S9 lane0",
               s9_lane0_load_pending && lane1_rs1_wait_s9 && load_use_hazard);

        rr_valid = 1'b0;
        #1;
        `check("S6 hazard matrix wait bits remain visible while invalid",
               lane1_rs1_wait_s9 && !load_use_hazard);

        clear_inputs();
        s9_valid = 1'b1;
        s9_slot1_valid = 1'b1;
        s9_slot1_issue_valid = 1'b1;
        s9_slot1_wb_en = 1'b1;
        s9_slot1_is_load = 1'b1;
        s9_slot1_issue_class = 4'b0100;
        s9_slot1_rd = 5'd14;
        lane1_uses_rs2 = 1'b1;
        lane1_rs2 = 5'd14;
        #1;
        `check("S6 hazard matrix inactive lane1 does not block",
               s9_lane1_load_pending && !lane1_rs2_wait_s9 && !load_use_hazard);

        lane1_active = 1'b1;
        #1;
        `check("S6 hazard matrix active lane1 blocks on rs2",
               lane1_rs2_wait_s9 && load_use_hazard);

        s9_slot1_valid = 1'b0;
        #1;
        `check("S6 hazard matrix invalid lane1 producer does not block",
               !s9_lane1_load_pending && !lane1_rs2_wait_s9 && !load_use_hazard);

        clear_inputs();
        s7_valid = 1'b1;
        s7_is_load = 1'b1;
        s7_rd = 5'd0;
        lane0_uses_rs1 = 1'b1;
        lane0_rs1 = 5'd0;
        #1;
        `check("S6 hazard matrix x0 load destination does not block",
               !s7_lane0_load_pending && !lane0_rs1_wait_s7 && !load_use_hazard);

        finish_tb();
    end
endmodule

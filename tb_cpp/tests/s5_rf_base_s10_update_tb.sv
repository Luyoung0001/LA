`timescale 1ns / 1ps

module s5_rf_base_s10_update_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [4:0]  slot0_rs1;
    logic [4:0]  slot0_rs2;
    logic [4:0]  slot1_rs1;
    logic [4:0]  slot1_rs2;
    logic [31:0] slot0_rs1_base;
    logic [31:0] slot0_rs2_base;
    logic [31:0] slot1_rs1_base;
    logic [31:0] slot1_rs2_base;
    logic        s10_lane0_wb_valid;
    logic [4:0]  s10_lane0_rd;
    logic [31:0] s10_lane0_result;
    logic        s10_lane1_wb_valid;
    logic [4:0]  s10_lane1_rd;
    logic [31:0] s10_lane1_result;
    logic [31:0] slot0_rs1_base_out;
    logic [31:0] slot0_rs2_base_out;
    logic [31:0] slot1_rs1_base_out;
    logic [31:0] slot1_rs2_base_out;

    s5_rf_base_s10_update #(
        .XLEN(32)
    ) u_dut (
        .slot0_rs1_i(slot0_rs1),
        .slot0_rs2_i(slot0_rs2),
        .slot1_rs1_i(slot1_rs1),
        .slot1_rs2_i(slot1_rs2),
        .slot0_rs1_base_i(slot0_rs1_base),
        .slot0_rs2_base_i(slot0_rs2_base),
        .slot1_rs1_base_i(slot1_rs1_base),
        .slot1_rs2_base_i(slot1_rs2_base),
        .s10_lane0_wb_valid_i(s10_lane0_wb_valid),
        .s10_lane0_rd_i(s10_lane0_rd),
        .s10_lane0_result_i(s10_lane0_result),
        .s10_lane1_wb_valid_i(s10_lane1_wb_valid),
        .s10_lane1_rd_i(s10_lane1_rd),
        .s10_lane1_result_i(s10_lane1_result),
        .slot0_rs1_base_o(slot0_rs1_base_out),
        .slot0_rs2_base_o(slot0_rs2_base_out),
        .slot1_rs1_base_o(slot1_rs1_base_out),
        .slot1_rs2_base_o(slot1_rs2_base_out)
    );

    task automatic clear_inputs;
        begin
            slot0_rs1 = 5'd1;
            slot0_rs2 = 5'd2;
            slot1_rs1 = 5'd3;
            slot1_rs2 = 5'd4;
            slot0_rs1_base = 32'h1000_0001;
            slot0_rs2_base = 32'h1000_0002;
            slot1_rs1_base = 32'h1000_0003;
            slot1_rs2_base = 32'h1000_0004;
            s10_lane0_wb_valid = 1'b0;
            s10_lane0_rd = 5'd0;
            s10_lane0_result = 32'h2000_0000;
            s10_lane1_wb_valid = 1'b0;
            s10_lane1_rd = 5'd0;
            s10_lane1_result = 32'h3000_0000;
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check32("RFUPD idle keeps slot0 rs1", slot0_rs1_base_out, slot0_rs1_base);
        `check32("RFUPD idle keeps slot0 rs2", slot0_rs2_base_out, slot0_rs2_base);
        `check32("RFUPD idle keeps slot1 rs1", slot1_rs1_base_out, slot1_rs1_base);
        `check32("RFUPD idle keeps slot1 rs2", slot1_rs2_base_out, slot1_rs2_base);

        clear_inputs();
        s10_lane0_wb_valid = 1'b1;
        s10_lane0_rd = 5'd2;
        s10_lane0_result = 32'h2222_2222;
        #1;
        `check32("RFUPD lane0 updates matching slot0 rs2",
                 slot0_rs2_base_out, 32'h2222_2222);
        `check32("RFUPD lane0 leaves nonmatching slot1 rs1",
                 slot1_rs1_base_out, slot1_rs1_base);

        clear_inputs();
        s10_lane1_wb_valid = 1'b1;
        s10_lane1_rd = 5'd3;
        s10_lane1_result = 32'h3333_3333;
        #1;
        `check32("RFUPD lane1 updates matching slot1 rs1",
                 slot1_rs1_base_out, 32'h3333_3333);
        `check32("RFUPD lane1 leaves slot0 rs1",
                 slot0_rs1_base_out, slot0_rs1_base);

        clear_inputs();
        s10_lane0_wb_valid = 1'b1;
        s10_lane0_rd = 5'd0;
        s10_lane0_result = 32'hffff_ffff;
        slot0_rs1 = 5'd0;
        slot0_rs1_base = 32'haaaa_0000;
        #1;
        `check32("RFUPD zero register is ignored",
                 slot0_rs1_base_out, 32'haaaa_0000);

        clear_inputs();
        slot0_rs1 = 5'd8;
        slot0_rs2 = 5'd8;
        slot1_rs1 = 5'd8;
        slot1_rs2 = 5'd8;
        s10_lane0_wb_valid = 1'b1;
        s10_lane0_rd = 5'd8;
        s10_lane0_result = 32'h8888_0000;
        s10_lane1_wb_valid = 1'b1;
        s10_lane1_rd = 5'd8;
        s10_lane1_result = 32'h8888_1111;
        #1;
        `check32("RFUPD lane1 wins same-cycle same-rd slot0 rs1",
                 slot0_rs1_base_out, 32'h8888_1111);
        `check32("RFUPD lane1 wins same-cycle same-rd slot0 rs2",
                 slot0_rs2_base_out, 32'h8888_1111);
        `check32("RFUPD lane1 wins same-cycle same-rd slot1 rs1",
                 slot1_rs1_base_out, 32'h8888_1111);
        `check32("RFUPD lane1 wins same-cycle same-rd slot1 rs2",
                 slot1_rs2_base_out, 32'h8888_1111);

        finish_tb();
    end
endmodule

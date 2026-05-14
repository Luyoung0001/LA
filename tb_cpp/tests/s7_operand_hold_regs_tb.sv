`timescale 1ns / 1ps

module s7_operand_hold_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        flush;
    logic        clear;
    logic        track;
    logic        rs1_capture_ready;
    logic        rs2_capture_ready;
    logic [31:0] rs1_live;
    logic [31:0] rs2_live;
    logic        rs1_hold_valid;
    logic        rs2_hold_valid;
    logic [31:0] rs1_hold_value;
    logic [31:0] rs2_hold_value;
    logic [31:0] rs1_value;
    logic [31:0] rs2_value;

    s7_operand_hold_regs #(
        .XLEN(32)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .clear_i(clear),
        .track_i(track),
        .rs1_capture_ready_i(rs1_capture_ready),
        .rs2_capture_ready_i(rs2_capture_ready),
        .rs1_live_i(rs1_live),
        .rs2_live_i(rs2_live),
        .rs1_hold_valid_o(rs1_hold_valid),
        .rs2_hold_valid_o(rs2_hold_valid),
        .rs1_hold_value_o(rs1_hold_value),
        .rs2_hold_value_o(rs2_hold_value),
        .rs1_value_o(rs1_value),
        .rs2_value_o(rs2_value)
    );

    initial begin
        tb_start();
        flush = 1'b0;
        clear = 1'b0;
        track = 1'b0;
        rs1_capture_ready = 1'b0;
        rs2_capture_ready = 1'b0;
        rs1_live = 32'h1000_0001;
        rs2_live = 32'h1000_0002;
        reset_dut();

        `check("S7HOLD reset clears valid", !rs1_hold_valid && !rs2_hold_valid);
        `check32("S7HOLD reset clears rs1 data", rs1_hold_value, 32'd0);
        `check32("S7HOLD reset passes live rs1", rs1_value, 32'h1000_0001);

        track = 1'b1;
        rs1_capture_ready = 1'b1;
        rs2_capture_ready = 1'b0;
        tick();
        `check("S7HOLD captures ready rs1 only", rs1_hold_valid && !rs2_hold_valid);
        `check32("S7HOLD captures rs1 live", rs1_hold_value, 32'h1000_0001);
        `check32("S7HOLD rs2 still uses live", rs2_value, 32'h1000_0002);

        rs1_live = 32'h2000_0001;
        rs2_live = 32'h2000_0002;
        rs1_capture_ready = 1'b1;
        rs2_capture_ready = 1'b1;
        tick();
        `check("S7HOLD captures rs2 when it becomes ready", rs1_hold_valid && rs2_hold_valid);
        `check32("S7HOLD keeps old rs1", rs1_hold_value, 32'h1000_0001);
        `check32("S7HOLD captures rs2", rs2_hold_value, 32'h2000_0002);
        `check32("S7HOLD selected rs1 uses held value", rs1_value, 32'h1000_0001);
        `check32("S7HOLD selected rs2 uses held value", rs2_value, 32'h2000_0002);

        clear = 1'b1;
        rs1_live = 32'h3000_0001;
        rs2_live = 32'h3000_0002;
        tick();
        clear = 1'b0;
        `check("S7HOLD clear drops valids", !rs1_hold_valid && !rs2_hold_valid);
        `check32("S7HOLD clear selects live rs1", rs1_value, 32'h3000_0001);

        clear = 1'b1;
        track = 1'b1;
        rs1_capture_ready = 1'b1;
        rs2_capture_ready = 1'b1;
        rs1_live = 32'h4000_0001;
        rs2_live = 32'h4000_0002;
        tick();
        clear = 1'b0;
        track = 1'b0;
        `check("S7HOLD clear wins over track", !rs1_hold_valid && !rs2_hold_valid);
        `check32("S7HOLD clear priority keeps live selected", rs2_value, 32'h4000_0002);

        track = 1'b1;
        tick();
        track = 1'b0;
        `check("S7HOLD recaptures after clear", rs1_hold_valid && rs2_hold_valid);
        `check32("S7HOLD recapture rs1", rs1_hold_value, 32'h4000_0001);
        `check32("S7HOLD recapture rs2", rs2_hold_value, 32'h4000_0002);

        flush = 1'b1;
        tick();
        flush = 1'b0;
        `check("S7HOLD flush clears valids", !rs1_hold_valid && !rs2_hold_valid);
        `check32("S7HOLD flush clears rs1 data", rs1_hold_value, 32'd0);
        `check32("S7HOLD flush clears rs2 data", rs2_hold_value, 32'd0);

        finish_tb();
    end
endmodule

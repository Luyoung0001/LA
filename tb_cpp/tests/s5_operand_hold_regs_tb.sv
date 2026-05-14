`timescale 1ns / 1ps

module s5_operand_hold_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        flush;
    logic        clear;
    logic        track;
    logic        rs1_ready;
    logic        rs2_ready;
    logic [31:0] rs1_live;
    logic [31:0] rs2_live;
    logic        rs1_hold_valid;
    logic        rs2_hold_valid;
    logic [31:0] rs1_hold_value;
    logic [31:0] rs2_hold_value;
    logic [31:0] rs1_value;
    logic [31:0] rs2_value;

    s5_operand_hold_regs #(
        .XLEN(32)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .clear_i(clear),
        .track_i(track),
        .rs1_ready_i(rs1_ready),
        .rs2_ready_i(rs2_ready),
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
        rs1_ready = 1'b0;
        rs2_ready = 1'b0;
        rs1_live = 32'h1111_0001;
        rs2_live = 32'h1111_0002;
        reset_dut();

        `check("HOLD reset clears valid", !rs1_hold_valid && !rs2_hold_valid);
        `check32("HOLD reset clears rs1 value", rs1_hold_value, 32'd0);
        `check32("HOLD reset passes live rs1", rs1_value, 32'h1111_0001);

        track = 1'b1;
        rs1_ready = 1'b1;
        rs2_ready = 1'b0;
        tick();
        `check("HOLD captures ready rs1 only", rs1_hold_valid && !rs2_hold_valid);
        `check32("HOLD captures rs1 live", rs1_hold_value, 32'h1111_0001);
        `check32("HOLD rs2 still uses live", rs2_value, 32'h1111_0002);

        rs1_live = 32'h2222_0001;
        rs2_live = 32'h2222_0002;
        rs1_ready = 1'b1;
        rs2_ready = 1'b1;
        tick();
        `check("HOLD captures rs2 after it becomes ready", rs1_hold_valid && rs2_hold_valid);
        `check32("HOLD keeps old rs1", rs1_hold_value, 32'h1111_0001);
        `check32("HOLD captures rs2", rs2_hold_value, 32'h2222_0002);
        `check32("HOLD selected rs1 uses held value", rs1_value, 32'h1111_0001);
        `check32("HOLD selected rs2 uses held value", rs2_value, 32'h2222_0002);

        clear = 1'b1;
        tick();
        clear = 1'b0;
        rs1_live = 32'haaaa_0001;
        rs2_live = 32'h0000_1000;
        rs1_ready = 1'b0;
        rs2_ready = 1'b1;
        tick();
        `check("HOLD captures transient ready rs2 while rs1 waits", !rs1_hold_valid && rs2_hold_valid);
        `check32("HOLD latches transient forwarded rs2", rs2_hold_value, 32'h0000_1000);

        rs1_live = 32'h5000_ac00;
        rs2_live = 32'h0000_0001;
        rs1_ready = 1'b1;
        rs2_ready = 1'b1;
        tick();
        `check("HOLD captures late rs1 without losing held rs2", rs1_hold_valid && rs2_hold_valid);
        `check32("HOLD captures late load value", rs1_hold_value, 32'h5000_ac00);
        `check32("HOLD keeps transient rs2 after bypass window closes", rs2_value, 32'h0000_1000);

        clear = 1'b1;
        rs1_live = 32'h3333_0001;
        rs2_live = 32'h3333_0002;
        tick();
        clear = 1'b0;
        `check("HOLD clear drops valids", !rs1_hold_valid && !rs2_hold_valid);
        `check32("HOLD clear does not need to zero data", rs1_hold_value, 32'h5000_ac00);
        `check32("HOLD clear selects live rs1", rs1_value, 32'h3333_0001);

        clear = 1'b1;
        track = 1'b1;
        rs1_ready = 1'b1;
        rs2_ready = 1'b1;
        rs1_live = 32'h4444_0001;
        rs2_live = 32'h4444_0002;
        tick();
        clear = 1'b0;
        track = 1'b0;
        `check("HOLD clear wins over track", !rs1_hold_valid && !rs2_hold_valid);
        `check32("HOLD clear priority keeps live selected", rs2_value, 32'h4444_0002);

        track = 1'b1;
        tick();
        track = 1'b0;
        `check("HOLD recaptures after clear", rs1_hold_valid && rs2_hold_valid);
        `check32("HOLD recapture rs1", rs1_hold_value, 32'h4444_0001);
        `check32("HOLD recapture rs2", rs2_hold_value, 32'h4444_0002);

        flush = 1'b1;
        tick();
        flush = 1'b0;
        `check("HOLD flush clears valids", !rs1_hold_valid && !rs2_hold_valid);
        `check32("HOLD flush clears rs1 data", rs1_hold_value, 32'd0);
        `check32("HOLD flush clears rs2 data", rs2_hold_value, 32'd0);

        finish_tb();
    end
endmodule

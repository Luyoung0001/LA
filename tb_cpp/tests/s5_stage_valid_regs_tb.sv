`timescale 1ns / 1ps

module s5_stage_valid_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic promote_slot1;
    logic base_allowin;
    logic source_valid;
    logic valid;

    s5_stage_valid_regs u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .promote_slot1_i(promote_slot1),
        .base_allowin_i(base_allowin),
        .source_valid_i(source_valid),
        .valid_o(valid)
    );

    initial begin
        tb_start();
        flush = 1'b0;
        promote_slot1 = 1'b0;
        base_allowin = 1'b0;
        source_valid = 1'b0;
        reset_dut();

        `check("S5VALID reset clears valid", !valid);

        base_allowin = 1'b1;
        source_valid = 1'b1;
        tick();
        `check("S5VALID allowin loads selected source valid", valid);

        base_allowin = 1'b0;
        source_valid = 1'b0;
        tick();
        `check("S5VALID holds when not allowed in", valid);

        base_allowin = 1'b1;
        tick();
        `check("S5VALID allowin clears when no source", !valid);

        source_valid = 1'b1;
        tick();
        `check("S5VALID allowin loads queued source", valid);

        promote_slot1 = 1'b1;
        source_valid = 1'b0;
        tick();
        `check("S5VALID promote keeps stage valid", valid);

        promote_slot1 = 1'b1;
        flush = 1'b1;
        tick();
        `check("S5VALID flush wins over promote", !valid);

        flush = 1'b0;
        promote_slot1 = 1'b0;
        base_allowin = 1'b1;
        source_valid = 1'b1;
        tick();
        `check("S5VALID recovers after flush", valid);

        finish_tb();
    end
endmodule

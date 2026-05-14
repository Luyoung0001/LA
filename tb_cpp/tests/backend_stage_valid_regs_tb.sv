`timescale 1ns / 1ps

module backend_stage_valid_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic allowin;
    logic upstream_valid;
    logic valid;
    logic capture;

    backend_stage_valid_regs u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .allowin_i(allowin),
        .upstream_valid_i(upstream_valid),
        .valid_o(valid),
        .capture_o(capture)
    );

    initial begin
        tb_start();
        flush = 1'b0;
        allowin = 1'b0;
        upstream_valid = 1'b0;
        reset_dut();

        `check("STAGE valid reset clears", !valid);
        `check("STAGE capture idle low", !capture);

        upstream_valid = 1'b1;
        allowin = 1'b0;
        tick();
        `check("STAGE valid holds when not allowin", !valid);
        `check("STAGE capture blocked by allowin", !capture);

        allowin = 1'b1;
        tick();
        `check("STAGE valid captures upstream valid", valid);
        `check("STAGE capture fires on valid allowin", capture);

        upstream_valid = 1'b0;
        allowin = 1'b0;
        tick();
        `check("STAGE valid holds packet under backpressure", valid);
        `check("STAGE capture stays low without allowin", !capture);

        allowin = 1'b1;
        tick();
        `check("STAGE valid clears on empty allowin", !valid);

        upstream_valid = 1'b1;
        tick();
        `check("STAGE valid reloads", valid);

        flush = 1'b1;
        allowin = 1'b0;
        upstream_valid = 1'b1;
        tick();
        `check("STAGE valid flush clears even without allowin", !valid);
        `check("STAGE capture still reflects combinational request", !capture);

        finish_tb();
    end

endmodule

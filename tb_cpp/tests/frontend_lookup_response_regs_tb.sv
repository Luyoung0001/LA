`timescale 1ns / 1ps

module frontend_lookup_response_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] lookup_pc;
    logic [1:0]  lookup_source;
    logic        redirect_probe_valid;
    logic [1:0]  redirect_probe_source;
    logic [31:0] response_pc;
    logic [1:0]  response_source;
    logic        response_redirect_probe_valid;
    logic [1:0]  response_redirect_probe_source;

    frontend_lookup_response_regs #(
        .XLEN(32),
        .RESET_PC(32'h1c00_0000)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .lookup_pc_i(lookup_pc),
        .lookup_source_i(lookup_source),
        .redirect_probe_valid_i(redirect_probe_valid),
        .redirect_probe_source_i(redirect_probe_source),
        .response_pc_o(response_pc),
        .response_source_o(response_source),
        .response_redirect_probe_valid_o(response_redirect_probe_valid),
        .response_redirect_probe_source_o(response_redirect_probe_source)
    );

    initial begin
        tb_start();
        lookup_pc = 32'h8000_1000;
        lookup_source = 2'd1;
        redirect_probe_valid = 1'b1;
        redirect_probe_source = 2'd2;
        rst_n = 1'b0;
        tick();

        `check32("FE lookup response reset pc", response_pc, 32'h1c00_0000);
        `check32("FE lookup response reset source", {30'd0, response_source}, 32'd0);
        `check("FE lookup response reset probe clear", !response_redirect_probe_valid);
        `check32("FE lookup response reset probe source",
                 {30'd0, response_redirect_probe_source}, 32'd0);

        rst_n = 1'b1;
        lookup_pc = 32'h1c00_0100;
        lookup_source = 2'd0;
        redirect_probe_valid = 1'b0;
        redirect_probe_source = 2'd0;
        tick();
        `check32("FE lookup response captures S1 pc", response_pc, 32'h1c00_0100);
        `check32("FE lookup response captures S1 source",
                 {30'd0, response_source}, 32'd0);
        `check("FE lookup response captures no probe", !response_redirect_probe_valid);

        lookup_pc = 32'h1c00_2000;
        lookup_source = 2'd1;
        redirect_probe_valid = 1'b0;
        redirect_probe_source = 2'd0;
        tick();
        `check32("FE lookup response captures BPU pc", response_pc, 32'h1c00_2000);
        `check32("FE lookup response captures BPU source",
                 {30'd0, response_source}, 32'd1);

        lookup_pc = 32'h8000_0040;
        lookup_source = 2'd2;
        redirect_probe_valid = 1'b1;
        redirect_probe_source = 2'd3;
        tick();
        `check32("FE lookup response captures redirect pc", response_pc, 32'h8000_0040);
        `check32("FE lookup response captures redirect source",
                 {30'd0, response_source}, 32'd2);
        `check("FE lookup response captures probe valid", response_redirect_probe_valid);
        `check32("FE lookup response captures probe source",
                 {30'd0, response_redirect_probe_source}, 32'd3);

        finish_tb();
    end
endmodule

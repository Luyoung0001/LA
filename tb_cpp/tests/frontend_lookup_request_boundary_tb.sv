`timescale 1ns / 1ps

module frontend_lookup_request_boundary_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] lookup_pc;
    logic [1:0]  lookup_source;
    logic        redirect_probe_valid;
    logic [31:0] redirect_probe_addr;
    logic [1:0]  redirect_probe_source;

    logic [31:0] pass_lookup_pc;
    logic [1:0]  pass_lookup_source;
    logic        pass_probe_valid;
    logic [31:0] pass_probe_addr;
    logic [1:0]  pass_probe_source;

    logic [31:0] reg_lookup_pc;
    logic [1:0]  reg_lookup_source;
    logic        reg_probe_valid;
    logic [31:0] reg_probe_addr;
    logic [1:0]  reg_probe_source;

    frontend_lookup_request_boundary #(
        .XLEN(32),
        .REGISTER_REQUESTS(0),
        .RESET_PC(32'h1c00_0000)
    ) u_passthrough (
        .clk(clk),
        .rst_n(rst_n),
        .lookup_pc_i(lookup_pc),
        .lookup_source_i(lookup_source),
        .redirect_probe_valid_i(redirect_probe_valid),
        .redirect_probe_addr_i(redirect_probe_addr),
        .redirect_probe_source_i(redirect_probe_source),
        .resource_lookup_pc_o(pass_lookup_pc),
        .resource_lookup_source_o(pass_lookup_source),
        .resource_redirect_probe_valid_o(pass_probe_valid),
        .resource_redirect_probe_addr_o(pass_probe_addr),
        .resource_redirect_probe_source_o(pass_probe_source)
    );

    frontend_lookup_request_boundary #(
        .XLEN(32),
        .REGISTER_REQUESTS(1),
        .RESET_PC(32'h1c00_0000)
    ) u_registered (
        .clk(clk),
        .rst_n(rst_n),
        .lookup_pc_i(lookup_pc),
        .lookup_source_i(lookup_source),
        .redirect_probe_valid_i(redirect_probe_valid),
        .redirect_probe_addr_i(redirect_probe_addr),
        .redirect_probe_source_i(redirect_probe_source),
        .resource_lookup_pc_o(reg_lookup_pc),
        .resource_lookup_source_o(reg_lookup_source),
        .resource_redirect_probe_valid_o(reg_probe_valid),
        .resource_redirect_probe_addr_o(reg_probe_addr),
        .resource_redirect_probe_source_o(reg_probe_source)
    );

    initial begin
        tb_start();
        lookup_pc = 32'h8000_1000;
        lookup_source = 2'd2;
        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'h2000_1000;
        redirect_probe_source = 2'd3;

        rst_n = 1'b0;
        tick();
        `check32("FE request boundary passthrough ignores reset pc",
                 pass_lookup_pc, 32'h8000_1000);
        `check("FE request boundary passthrough keeps probe",
               pass_probe_valid && pass_probe_addr == 32'h2000_1000);
        `check32("FE request boundary registered reset pc",
                 reg_lookup_pc, 32'h1c00_0000);
        `check("FE request boundary registered reset probe clear",
               !reg_probe_valid);

        rst_n = 1'b1;
        lookup_pc = 32'h1c00_0100;
        lookup_source = 2'd0;
        redirect_probe_valid = 1'b0;
        redirect_probe_addr = 32'd0;
        redirect_probe_source = 2'd0;
        #1;
        `check32("FE request boundary passthrough updates immediately",
                 pass_lookup_pc, 32'h1c00_0100);
        tick();
        `check32("FE request boundary registered captures pc",
                 reg_lookup_pc, 32'h1c00_0100);
        `check32("FE request boundary registered captures source",
                 {30'd0, reg_lookup_source}, 32'd0);
        `check("FE request boundary registered captures no probe",
               !reg_probe_valid);

        lookup_pc = 32'h8000_0040;
        lookup_source = 2'd2;
        redirect_probe_valid = 1'b1;
        redirect_probe_addr = 32'h2000_0040;
        redirect_probe_source = 2'd2;
        tick();
        `check32("FE request boundary registered captures redirect pc",
                 reg_lookup_pc, 32'h8000_0040);
        `check32("FE request boundary registered captures probe addr",
                 reg_probe_addr, 32'h2000_0040);
        `check32("FE request boundary registered captures probe source",
                 {30'd0, reg_probe_source}, 32'd2);
        `check("FE request boundary registered captures probe valid",
               reg_probe_valid);

        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module frontend_control_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s10_idle_flush;
    logic        csr_has_int;
    logic        redirect_valid;
    logic [31:0] redirect_pc;
    logic [1:0]  redirect_epoch;
    logic        redirect_from_wb;
    logic        s2_bpu_redirect_valid;
    logic [31:0] s2_bpu_redirect_target;
    logic [31:0] s1_pc;
    logic [31:0] csr_crmd;
    logic [31:0] csr_dmw0;
    logic [31:0] csr_dmw1;

    logic        frontend_idle_lock;
    logic [1:0]  frontend_epoch;
    logic [1:0]  frontend_next_epoch;
    logic        redirect_fast_inject;
    logic [31:0] s1_redirect_pc;
    logic [31:0] s1_bpu_redirect_pc;
    logic [31:0] lookup_pc;
    logic [1:0]  lookup_source;
    logic        redirect_direct_map;
    logic        ic_redirect_probe_valid;
    logic [31:0] ic_redirect_probe_addr;
    logic [1:0]  ic_redirect_probe_source;

    localparam [1:0] LOOKUP_SRC_S1       = 2'd0;
    localparam [1:0] LOOKUP_SRC_BPU      = 2'd1;
    localparam [1:0] LOOKUP_SRC_REDIRECT = 2'd2;
    localparam [1:0] PROBE_SRC_NONE      = 2'd0;
    localparam [1:0] PROBE_SRC_DIRECT    = 2'd1;
    localparam [1:0] PROBE_SRC_DMW0      = 2'd2;

    frontend_control #(
        .XLEN(32),
        .EPOCH_WIDTH(2)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .s10_idle_flush_i(s10_idle_flush),
        .csr_has_int_i(csr_has_int),
        .redirect_valid_i(redirect_valid),
        .redirect_pc_i(redirect_pc),
        .redirect_epoch_i(redirect_epoch),
        .redirect_from_wb_i(redirect_from_wb),
        .s2_bpu_redirect_valid_i(s2_bpu_redirect_valid),
        .s2_bpu_redirect_target_i(s2_bpu_redirect_target),
        .s1_pc_i(s1_pc),
        .csr_crmd_i(csr_crmd),
        .csr_dmw0_i(csr_dmw0),
        .csr_dmw1_i(csr_dmw1),
        .frontend_idle_lock_o(frontend_idle_lock),
        .frontend_epoch_o(frontend_epoch),
        .frontend_next_epoch_o(frontend_next_epoch),
        .redirect_fast_inject_o(redirect_fast_inject),
        .s1_redirect_pc_o(s1_redirect_pc),
        .s1_bpu_redirect_pc_o(s1_bpu_redirect_pc),
        .lookup_pc_o(lookup_pc),
        .lookup_source_o(lookup_source),
        .redirect_direct_map_o(redirect_direct_map),
        .ic_redirect_probe_valid_o(ic_redirect_probe_valid),
        .ic_redirect_probe_addr_o(ic_redirect_probe_addr),
        .ic_redirect_probe_source_o(ic_redirect_probe_source)
    );

    initial begin
        tb_start();
        s10_idle_flush = 1'b0;
        csr_has_int = 1'b0;
        redirect_valid = 1'b0;
        redirect_pc = 32'h0;
        redirect_epoch = 2'd0;
        redirect_from_wb = 1'b0;
        s2_bpu_redirect_valid = 1'b0;
        s2_bpu_redirect_target = 32'h0;
        s1_pc = 32'h1c00_0000;
        csr_crmd = 32'h0000_0000;
        csr_dmw0 = 32'h0;
        csr_dmw1 = 32'h0;
        reset_dut();

        `check("FE control reset idle lock clear", !frontend_idle_lock);
        `check("FE control reset epoch zero", frontend_epoch == 2'd0);
        `check("FE control reset next epoch", frontend_next_epoch == 2'd1);
        `check32("FE control default lookup uses S1 PC", lookup_pc, 32'h1c00_0000);
        `check32("FE control default lookup source is S1",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_S1});
        `check("FE control idle has no redirect probe", !ic_redirect_probe_valid);
        `check32("FE control default probe source clear",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_NONE});

        redirect_valid = 1'b1;
        redirect_pc = 32'h1c00_0100;
        redirect_epoch = 2'd2;
        redirect_from_wb = 1'b0;
        #1;
        `check("FE control direct redirect fast injects", redirect_fast_inject);
        `check("FE control direct redirect probes icache", ic_redirect_probe_valid);
        `check32("FE control direct redirect S1 skips injected IF1 PC",
                 s1_redirect_pc, 32'h1c00_0104);
        `check32("FE control redirect wins lookup", lookup_pc, 32'h1c00_0100);
        `check32("FE control redirect lookup source",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_REDIRECT});
        `check32("FE control direct redirect probe addr",
                 ic_redirect_probe_addr, 32'h1c00_0100);
        `check32("FE control direct redirect probe source",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_DIRECT});
        tick();
        `check("FE control redirect updates epoch", frontend_epoch == 2'd2);
        redirect_valid = 1'b0;

        s10_idle_flush = 1'b1;
        tick();
        s10_idle_flush = 1'b0;
        `check("FE control idle flush locks frontend", frontend_idle_lock);
        csr_has_int = 1'b1;
        tick();
        csr_has_int = 1'b0;
        `check("FE control interrupt unlocks frontend", !frontend_idle_lock);

        redirect_valid = 1'b1;
        redirect_pc = 32'h1c00_0200;
        redirect_epoch = 2'd3;
        redirect_from_wb = 1'b1;
        #1;
        `check("FE control WB redirect does not fast inject", !redirect_fast_inject);
        `check("FE control WB redirect does not probe icache", !ic_redirect_probe_valid);
        `check32("FE control WB redirect keeps redirect lookup source",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_REDIRECT});
        `check32("FE control WB redirect probe source clear",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_NONE});
        `check32("FE control WB redirect sends exact S1 PC",
                 s1_redirect_pc, 32'h1c00_0200);
        tick();
        redirect_valid = 1'b0;
        redirect_from_wb = 1'b0;
        `check("FE control WB redirect updates epoch", frontend_epoch == 2'd3);

        s2_bpu_redirect_valid = 1'b1;
        s2_bpu_redirect_target = 32'h1c00_3000;
        s1_pc = 32'h1c00_2000;
        #1;
        `check32("FE control BPU redirect wins over S1 lookup",
                 lookup_pc, 32'h1c00_3000);
        `check32("FE control BPU lookup source",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_BPU});
        `check32("FE control S1 BPU redirect skips injected IF1 PC",
                 s1_bpu_redirect_pc, 32'h1c00_3004);
        s2_bpu_redirect_valid = 1'b0;
        #1;
        `check32("FE control lookup falls back to S1",
                 lookup_pc, 32'h1c00_2000);
        `check32("FE control fallback lookup source is S1",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_S1});

        csr_crmd = 32'h0000_0010;
        csr_dmw0 = {3'b100, 1'b0, 3'b001, 19'd0, 2'b00, 1'b0, 2'b00, 1'b1};
        redirect_valid = 1'b1;
        redirect_pc = 32'h8000_0040;
        redirect_epoch = 2'd0;
        #1;
        `check("FE control DMW redirect is direct mapped", redirect_direct_map);
        `check("FE control DMW redirect probes icache", ic_redirect_probe_valid);
        `check32("FE control DMW redirect probe paddr",
                 ic_redirect_probe_addr, 32'h2000_0040);
        `check32("FE control DMW redirect probe source",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_DMW0});

        csr_dmw0 = 32'h0;
        #1;
        `check("FE control paged unmapped redirect is not direct", !redirect_direct_map);
        `check("FE control paged unmapped redirect suppresses probe",
               !ic_redirect_probe_valid);
        `check32("FE control paged unmapped probe source clear",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_NONE});

        finish_tb();
    end
endmodule

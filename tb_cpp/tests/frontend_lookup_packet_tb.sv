`timescale 1ns / 1ps

module frontend_lookup_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        redirect_valid;
    logic [31:0] redirect_pc;
    logic        redirect_from_wb;
    logic        s2_bpu_redirect_valid;
    logic [31:0] s2_bpu_redirect_target;
    logic [31:0] s1_pc;
    logic [31:0] csr_crmd;
    logic [31:0] csr_dmw0;
    logic [31:0] csr_dmw1;

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
    localparam [1:0] PROBE_SRC_DMW1      = 2'd3;

    frontend_lookup_packet #(
        .XLEN(32)
    ) u_dut (
        .redirect_valid_i(redirect_valid),
        .redirect_pc_i(redirect_pc),
        .redirect_from_wb_i(redirect_from_wb),
        .s2_bpu_redirect_valid_i(s2_bpu_redirect_valid),
        .s2_bpu_redirect_target_i(s2_bpu_redirect_target),
        .s1_pc_i(s1_pc),
        .csr_crmd_i(csr_crmd),
        .csr_dmw0_i(csr_dmw0),
        .csr_dmw1_i(csr_dmw1),
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

    task automatic clear_inputs;
        begin
            redirect_valid = 1'b0;
            redirect_pc = 32'd0;
            redirect_from_wb = 1'b0;
            s2_bpu_redirect_valid = 1'b0;
            s2_bpu_redirect_target = 32'd0;
            s1_pc = 32'h1c00_0000;
            csr_crmd = 32'h0000_0000;
            csr_dmw0 = 32'h0;
            csr_dmw1 = 32'h0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;
        clear_inputs();
        #1;
        `check32("FE lookup idle uses S1 PC", lookup_pc, 32'h1c00_0000);
        `check32("FE lookup idle source is S1",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_S1});
        `check("FE lookup idle direct mode is direct", redirect_direct_map);
        `check("FE lookup idle has no fast inject", !redirect_fast_inject);
        `check("FE lookup idle has no redirect probe", !ic_redirect_probe_valid);
        `check32("FE lookup idle probe source clear",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_NONE});

        clear_inputs();
        s1_pc = 32'h1c00_1000;
        s2_bpu_redirect_valid = 1'b1;
        s2_bpu_redirect_target = 32'h1c00_2000;
        #1;
        `check32("FE lookup BPU redirect beats S1 PC", lookup_pc, 32'h1c00_2000);
        `check32("FE lookup BPU source",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_BPU});
        `check32("FE lookup BPU redirect injects IF1 next PC",
                 s1_bpu_redirect_pc, 32'h1c00_2004);
        `check("FE lookup BPU redirect does not create icache probe",
               !ic_redirect_probe_valid);
        `check32("FE lookup BPU probe source clear",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_NONE});

        clear_inputs();
        redirect_valid = 1'b1;
        redirect_pc = 32'h1c00_3000;
        s2_bpu_redirect_valid = 1'b1;
        s2_bpu_redirect_target = 32'h1c00_2000;
        s1_pc = 32'h1c00_1000;
        #1;
        `check32("FE lookup architectural redirect beats BPU redirect",
                 lookup_pc, 32'h1c00_3000);
        `check32("FE lookup architectural redirect source",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_REDIRECT});
        `check("FE lookup direct redirect fast injects", redirect_fast_inject);
        `check("FE lookup direct redirect probes icache", ic_redirect_probe_valid);
        `check32("FE lookup redirect fast IF1 PC", s1_redirect_pc, 32'h1c00_3004);
        `check32("FE lookup direct probe addr", ic_redirect_probe_addr, 32'h1c00_3000);
        `check32("FE lookup direct probe source",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_DIRECT});

        clear_inputs();
        redirect_valid = 1'b1;
        redirect_pc = 32'h1c00_4000;
        redirect_from_wb = 1'b1;
        #1;
        `check("FE lookup WB redirect suppresses fast inject", !redirect_fast_inject);
        `check("FE lookup WB redirect suppresses probe", !ic_redirect_probe_valid);
        `check32("FE lookup WB redirect keeps redirect source",
                 {30'd0, lookup_source}, {30'd0, LOOKUP_SRC_REDIRECT});
        `check32("FE lookup WB redirect probe source clear",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_NONE});
        `check32("FE lookup WB redirect keeps exact S1 PC",
                 s1_redirect_pc, 32'h1c00_4000);

        clear_inputs();
        csr_crmd = 32'h0000_0010;
        csr_dmw0 = {3'b100, 1'b0, 3'b001, 19'd0, 2'b00, 1'b0, 2'b00, 1'b1};
        redirect_valid = 1'b1;
        redirect_pc = 32'h8000_0040;
        #1;
        `check("FE lookup DMW0 redirect is direct mapped", redirect_direct_map);
        `check("FE lookup DMW0 redirect probes icache", ic_redirect_probe_valid);
        `check32("FE lookup DMW0 probe paddr", ic_redirect_probe_addr, 32'h2000_0040);
        `check32("FE lookup DMW0 probe source",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_DMW0});
        `check32("FE lookup DMW0 still looks up virtual redirect PC",
                 lookup_pc, 32'h8000_0040);

        clear_inputs();
        csr_crmd = 32'h0000_0013;
        csr_dmw1 = {3'b101, 1'b0, 3'b010, 19'd0, 2'b00, 1'b1, 2'b00, 1'b0};
        redirect_valid = 1'b1;
        redirect_pc = 32'ha000_0080;
        #1;
        `check("FE lookup DMW1 PLV3 redirect is direct mapped", redirect_direct_map);
        `check32("FE lookup DMW1 probe paddr", ic_redirect_probe_addr, 32'h4000_0080);
        `check32("FE lookup DMW1 probe source",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_DMW1});

        clear_inputs();
        csr_crmd = 32'h0000_0010;
        redirect_valid = 1'b1;
        redirect_pc = 32'h8000_0100;
        #1;
        `check("FE lookup paged unmapped redirect is not direct", !redirect_direct_map);
        `check("FE lookup paged unmapped suppresses probe", !ic_redirect_probe_valid);
        `check("FE lookup paged unmapped suppresses fast inject", !redirect_fast_inject);
        `check32("FE lookup paged unmapped probe source clear",
                 {30'd0, ic_redirect_probe_source}, {30'd0, PROBE_SRC_NONE});
        `check32("FE lookup paged unmapped redirect sends exact S1 PC",
                 s1_redirect_pc, 32'h8000_0100);

        finish_tb();
    end
endmodule

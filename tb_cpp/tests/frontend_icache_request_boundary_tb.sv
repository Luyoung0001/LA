`timescale 1ns / 1ps

module frontend_icache_request_boundary_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic req_valid;
    logic req_ready;
    logic [31:0] req_addr;
    logic resource_req_valid;
    logic resource_req_ready;
    logic [31:0] resource_req_addr;

    frontend_icache_request_boundary #(
        .XLEN(32)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .req_valid_i(req_valid),
        .req_ready_o(req_ready),
        .req_addr_i(req_addr),
        .resource_req_valid_o(resource_req_valid),
        .resource_req_ready_i(resource_req_ready),
        .resource_req_addr_o(resource_req_addr)
    );

    initial begin
        tb_start();
        rst_n = 1'b0;
        flush = 1'b0;
        req_valid = 1'b0;
        req_addr = 32'h0;
        resource_req_ready = 1'b0;

        tick();
        `check("FE icache req boundary reset clears pending valid",
               !resource_req_valid);

        rst_n = 1'b1;
        req_valid = 1'b1;
        req_addr = 32'h1c00_0100;
        #1;
        `check("FE icache req boundary accepts first upstream request",
               req_ready);
        `check("FE icache req boundary does not bypass request combinationally",
               !resource_req_valid);
        tick();
        #1;
        `check("FE icache req boundary exposes registered request",
               resource_req_valid);
        `check32("FE icache req boundary keeps first request address",
                 resource_req_addr, 32'h1c00_0100);

        req_addr = 32'h1c00_0104;
        #1;
        `check("FE icache req boundary blocks second request while full and stalled",
               !req_ready);
        tick();

        resource_req_ready = 1'b1;
        req_addr = 32'h1c00_0108;
        #1;
        `check("FE icache req boundary accepts replacement request when resource fires",
               req_ready);
        `check32("FE icache req boundary presents old request during dequeue",
                 resource_req_addr, 32'h1c00_0100);
        tick();
        #1;
        `check("FE icache req boundary keeps queue full after dequeue+enqueue",
               resource_req_valid);
        `check32("FE icache req boundary captures replacement request address",
                 resource_req_addr, 32'h1c00_0108);

        req_valid = 1'b0;
        #1;
        `check("FE icache req boundary drains final request",
               resource_req_valid);
        tick();
        #1;
        `check("FE icache req boundary becomes empty after final dequeue",
               !resource_req_valid);

        req_valid = 1'b1;
        req_addr = 32'h1c00_0200;
        resource_req_ready = 1'b0;
        tick();
        #1;
        `check("FE icache req boundary re-fills after drain",
               resource_req_valid);
        flush = 1'b1;
        tick();
        #1;
        `check("FE icache req boundary flush clears pending request",
               !resource_req_valid);
        `check("FE icache req boundary flush blocks new accept",
               !req_ready);

        finish_tb();
    end
endmodule

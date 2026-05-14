`timescale 1ns / 1ps

module cpu_regfile_2w_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        we0, we1;
    logic [4:0]  waddr0, waddr1;
    logic [31:0] wdata0, wdata1;
    logic [4:0]  raddr1, raddr2;
    logic [31:0] rdata1, rdata2;

    cpu_regfile_2w u_dut (
        .clk(clk),
        .we0_i(we0), .waddr0_i(waddr0), .wdata0_i(wdata0),
        .we1_i(we1), .waddr1_i(waddr1), .wdata1_i(wdata1),
        .raddr1_i(raddr1), .raddr2_i(raddr2),
        .rdata1_o(rdata1), .rdata2_o(rdata2)
    );

    task automatic clear_inputs;
        begin
            we0 = 1'b0;
            we1 = 1'b0;
            waddr0 = 5'd0;
            waddr1 = 5'd0;
            wdata0 = 32'd0;
            wdata1 = 32'd0;
            raddr1 = 5'd0;
            raddr2 = 5'd0;
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        clear_inputs();

        we0 = 1'b1;
        waddr0 = 5'd3;
        wdata0 = 32'h1111_0003;
        raddr1 = 5'd3;
        raddr2 = 5'd0;
        tick();
        `check32("RF2W current port0 forward", rdata1, 32'h1111_0003);
        `check32("RF2W x0 reads zero", rdata2, 32'd0);

        clear_inputs();
        raddr1 = 5'd3;
        tick();
        `check32("RF2W stored port0 write", rdata1, 32'h1111_0003);

        clear_inputs();
        we0 = 1'b1;
        waddr0 = 5'd4;
        wdata0 = 32'h2222_0004;
        we1 = 1'b1;
        waddr1 = 5'd5;
        wdata1 = 32'h3333_0005;
        raddr1 = 5'd4;
        raddr2 = 5'd5;
        tick();
        `check32("RF2W current port0 dual forward", rdata1, 32'h2222_0004);
        `check32("RF2W current port1 dual forward", rdata2, 32'h3333_0005);

        clear_inputs();
        raddr1 = 5'd4;
        raddr2 = 5'd5;
        tick();
        `check32("RF2W stored port0 dual write", rdata1, 32'h2222_0004);
        `check32("RF2W stored port1 dual write", rdata2, 32'h3333_0005);

        clear_inputs();
        we0 = 1'b1;
        waddr0 = 5'd6;
        wdata0 = 32'h4444_0006;
        we1 = 1'b1;
        waddr1 = 5'd6;
        wdata1 = 32'h5555_0006;
        raddr1 = 5'd6;
        tick();
        `check32("RF2W same-address port1 current priority", rdata1, 32'h5555_0006);

        clear_inputs();
        raddr1 = 5'd6;
        tick();
        `check32("RF2W same-address port1 stored priority", rdata1, 32'h5555_0006);

        clear_inputs();
        we0 = 1'b1;
        waddr0 = 5'd0;
        wdata0 = 32'hffff_0000;
        we1 = 1'b1;
        waddr1 = 5'd0;
        wdata1 = 32'hffff_0001;
        raddr1 = 5'd0;
        tick();
        `check32("RF2W ignores writes to x0", rdata1, 32'd0);

        finish_tb();
    end
endmodule

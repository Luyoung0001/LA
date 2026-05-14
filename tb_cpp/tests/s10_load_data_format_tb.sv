`timescale 1ns / 1ps

module s10_load_data_format_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] addr;
    logic [31:0] data;
    logic [1:0]  size;
    logic        sign_ext;
    logic [31:0] load_data;

    s10_load_data_format u_dut (
        .addr_i(addr),
        .data_i(data),
        .size_i(size),
        .sign_ext_i(sign_ext),
        .data_o(load_data)
    );

    task automatic check_case(
        input string name,
        input [31:0] test_addr,
        input [31:0] test_data,
        input [1:0] test_size,
        input logic test_sign_ext,
        input [31:0] exp_data
    );
        begin
            addr = test_addr;
            data = test_data;
            size = test_size;
            sign_ext = test_sign_ext;
            #1;
            `check32(name, load_data, exp_data);
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        check_case("S10 load fmt signed byte lane0",
                   32'h1000_0000, 32'h807f_01ff, 2'b00, 1'b1, 32'hffff_ffff);
        check_case("S10 load fmt unsigned byte lane1",
                   32'h1000_0001, 32'h807f_abff, 2'b00, 1'b0, 32'h0000_00ab);
        check_case("S10 load fmt signed byte lane2",
                   32'h1000_0002, 32'h0080_01ff, 2'b00, 1'b1, 32'hffff_ff80);
        check_case("S10 load fmt unsigned byte lane3",
                   32'h1000_0003, 32'h7f00_01ff, 2'b00, 1'b0, 32'h0000_007f);

        check_case("S10 load fmt signed half low",
                   32'h1000_0000, 32'h1234_8001, 2'b01, 1'b1, 32'hffff_8001);
        check_case("S10 load fmt unsigned half low",
                   32'h1000_0000, 32'h1234_ffee, 2'b01, 1'b0, 32'h0000_ffee);
        check_case("S10 load fmt signed half high",
                   32'h1000_0002, 32'h8001_1234, 2'b01, 1'b1, 32'hffff_8001);
        check_case("S10 load fmt unsigned half high",
                   32'h1000_0002, 32'h8001_1234, 2'b01, 1'b0, 32'h0000_8001);

        check_case("S10 load fmt word ignores sign",
                   32'h1000_0003, 32'hfeed_c0de, 2'b10, 1'b1, 32'hfeed_c0de);
        check_case("S10 load fmt default word for size3",
                   32'h1000_0001, 32'h1357_2468, 2'b11, 1'b0, 32'h1357_2468);

        finish_tb();
    end
endmodule

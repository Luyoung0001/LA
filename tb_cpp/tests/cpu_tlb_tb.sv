`timescale 1ns / 1ps

module cpu_tlb_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic reset;
    logic [31:0] csr_crmd;
    logic [31:0] csr_asid;
    logic [31:0] csr_dmw0;
    logic [31:0] csr_dmw1;
    logic [31:0] csr_tlbidx;
    logic [31:0] csr_tlbehi;
    logic [31:0] csr_tlbelo0;
    logic [31:0] csr_tlbelo1;
    logic [31:0] csr_estat;
    logic commit_tlbsrch;
    logic commit_tlbrd;
    logic commit_tlbwr;
    logic commit_tlbfill;
    logic commit_invtlb;
    logic [4:0] commit_invtlb_op;
    logic [31:0] commit_invtlb_asid;
    logic [31:0] commit_invtlb_vaddr;
    logic tlbsrch_found;
    logic [4:0] tlbsrch_index;
    logic tlbrd_found;
    logic [31:0] tlbrd_tlbidx;
    logic [31:0] tlbrd_tlbehi;
    logic [31:0] tlbrd_tlbelo0;
    logic [31:0] tlbrd_tlbelo1;
    logic [31:0] tlbrd_asid;
    logic i_tlb_query_valid;
    logic i_tlb_query_write;
    logic [31:0] i_tlb_query_vaddr;
    logic i_tlb_resp_valid;
    logic [31:0] i_tlb_resp_vaddr;
    logic [31:0] i_tlb_query_paddr;
    logic i_tlb_exception_valid;
    logic [5:0] i_tlb_exception_ecode;
    logic d_tlb_query_valid;
    logic d_tlb_query_write;
    logic [31:0] d_tlb_query_vaddr;
    logic d_tlb_resp_valid;
    logic [31:0] d_tlb_resp_vaddr;
    logic [31:0] d_tlb_query_paddr;
    logic d_tlb_exception_valid;
    logic [5:0] d_tlb_exception_ecode;

    localparam [31:0] TEST_VADDR = 32'h0040_0004;
    localparam [31:0] MISS_VADDR = 32'h0080_0004;
    localparam [19:0] TEST_PPN0  = 20'h12345;
    localparam [19:0] TEST_PPN1  = 20'h23456;

    assign reset = !rst_n;

    cpu_tlb u_dut (
        .clk(clk),
        .reset(reset),
        .csr_crmd(csr_crmd),
        .csr_asid(csr_asid),
        .csr_dmw0(csr_dmw0),
        .csr_dmw1(csr_dmw1),
        .csr_tlbidx(csr_tlbidx),
        .csr_tlbehi(csr_tlbehi),
        .csr_tlbelo0(csr_tlbelo0),
        .csr_tlbelo1(csr_tlbelo1),
        .csr_estat(csr_estat),
        .commit_tlbsrch(commit_tlbsrch),
        .commit_tlbrd(commit_tlbrd),
        .commit_tlbwr(commit_tlbwr),
        .commit_tlbfill(commit_tlbfill),
        .commit_invtlb(commit_invtlb),
        .commit_invtlb_op(commit_invtlb_op),
        .commit_invtlb_asid(commit_invtlb_asid),
        .commit_invtlb_vaddr(commit_invtlb_vaddr),
        .tlbsrch_found(tlbsrch_found),
        .tlbsrch_index(tlbsrch_index),
        .tlbrd_found(tlbrd_found),
        .tlbrd_tlbidx(tlbrd_tlbidx),
        .tlbrd_tlbehi(tlbrd_tlbehi),
        .tlbrd_tlbelo0(tlbrd_tlbelo0),
        .tlbrd_tlbelo1(tlbrd_tlbelo1),
        .tlbrd_asid(tlbrd_asid),
        .i_tlb_query_valid(i_tlb_query_valid),
        .i_tlb_query_write(i_tlb_query_write),
        .i_tlb_query_vaddr(i_tlb_query_vaddr),
        .i_tlb_resp_valid(i_tlb_resp_valid),
        .i_tlb_resp_vaddr(i_tlb_resp_vaddr),
        .i_tlb_query_paddr(i_tlb_query_paddr),
        .i_tlb_exception_valid(i_tlb_exception_valid),
        .i_tlb_exception_ecode(i_tlb_exception_ecode),
        .d_tlb_query_valid(d_tlb_query_valid),
        .d_tlb_query_write(d_tlb_query_write),
        .d_tlb_query_vaddr(d_tlb_query_vaddr),
        .d_tlb_resp_valid(d_tlb_resp_valid),
        .d_tlb_resp_vaddr(d_tlb_resp_vaddr),
        .d_tlb_query_paddr(d_tlb_query_paddr),
        .d_tlb_exception_valid(d_tlb_exception_valid),
        .d_tlb_exception_ecode(d_tlb_exception_ecode)
    );

    task automatic clear_inputs;
        begin
            csr_crmd = 32'b0;
            csr_asid = 32'b0;
            csr_dmw0 = 32'b0;
            csr_dmw1 = 32'b0;
            csr_tlbidx = 32'b0;
            csr_tlbehi = 32'b0;
            csr_tlbelo0 = 32'b0;
            csr_tlbelo1 = 32'b0;
            csr_estat = 32'b0;
            commit_tlbsrch = 1'b0;
            commit_tlbrd = 1'b0;
            commit_tlbwr = 1'b0;
            commit_tlbfill = 1'b0;
            commit_invtlb = 1'b0;
            commit_invtlb_op = 5'b0;
            commit_invtlb_asid = 32'b0;
            commit_invtlb_vaddr = 32'b0;
            i_tlb_query_valid = 1'b0;
            i_tlb_query_write = 1'b0;
            i_tlb_query_vaddr = 32'b0;
            d_tlb_query_valid = 1'b0;
            d_tlb_query_write = 1'b0;
            d_tlb_query_vaddr = 32'b0;
        end
    endtask

    task automatic write_tlb_entry(
        input [4:0]  index,
        input [31:0] vaddr,
        input [19:0] ppn0,
        input [19:0] ppn1,
        input        d0,
        input        d1
    );
        begin
            csr_tlbidx = {2'b00, 6'd12, 19'b0, index};
            csr_tlbehi = {vaddr[31:13], 13'b0};
            csr_tlbelo0 = {4'b0, ppn0, 1'b0, 1'b1, 2'b01, 2'b00, d0, 1'b1};
            csr_tlbelo1 = {4'b0, ppn1, 1'b0, 1'b1, 2'b01, 2'b00, d1, 1'b1};
            commit_tlbwr = 1'b1;
            tick();
            commit_tlbwr = 1'b0;
            tick();
        end
    endtask

    task automatic expect_i_response_after_two_cycles(
        input string name,
        input [31:0] vaddr,
        input [31:0] exp_paddr,
        input        exp_exception,
        input [5:0]  exp_ecode
    );
        begin
            `check({name, " idle before query"}, !i_tlb_resp_valid);
            i_tlb_query_valid = 1'b1;
            i_tlb_query_vaddr = vaddr;
            tick();
            i_tlb_query_valid = 1'b0;
            i_tlb_query_vaddr = 32'b0;
            #1;
            `check({name, " no response at issue cycle"}, !i_tlb_resp_valid);
            tick();
            #1;
            `check({name, " no response at plus one"}, !i_tlb_resp_valid);
            tick();
            #1;
            `check({name, " response at plus two"}, i_tlb_resp_valid);
            `check32({name, " response vaddr"}, i_tlb_resp_vaddr, vaddr);
            `check32({name, " response paddr"}, i_tlb_query_paddr, exp_paddr);
            `check({name, " response exception"}, i_tlb_exception_valid == exp_exception);
            if (exp_exception) begin
                `check32({name, " response ecode"}, {26'b0, i_tlb_exception_ecode},
                         {26'b0, exp_ecode});
            end
            tick();
            #1;
            `check({name, " response pulse clears"}, !i_tlb_resp_valid);
        end
    endtask

    task automatic expect_i_response_after_three_cycles(
        input string name,
        input [31:0] vaddr,
        input [31:0] exp_paddr,
        input        exp_exception,
        input [5:0]  exp_ecode
    );
        begin
            `check({name, " idle before query"}, !i_tlb_resp_valid);
            i_tlb_query_valid = 1'b1;
            i_tlb_query_vaddr = vaddr;
            tick();
            i_tlb_query_valid = 1'b0;
            i_tlb_query_vaddr = 32'b0;
            #1;
            `check({name, " no response at issue cycle"}, !i_tlb_resp_valid);
            tick();
            #1;
            `check({name, " no response at plus one"}, !i_tlb_resp_valid);
            tick();
            #1;
            `check({name, " no response at plus two"}, !i_tlb_resp_valid);
            tick();
            #1;
            `check({name, " response at plus three"}, i_tlb_resp_valid);
            `check32({name, " response vaddr"}, i_tlb_resp_vaddr, vaddr);
            `check32({name, " response paddr"}, i_tlb_query_paddr, exp_paddr);
            `check({name, " response exception"}, i_tlb_exception_valid == exp_exception);
            if (exp_exception) begin
                `check32({name, " response ecode"}, {26'b0, i_tlb_exception_ecode},
                         {26'b0, exp_ecode});
            end
            tick();
            #1;
            `check({name, " response pulse clears"}, !i_tlb_resp_valid);
        end
    endtask

    task automatic expect_d_response_after_three_cycles(
        input string name,
        input [31:0] vaddr,
        input        write,
        input [31:0] exp_paddr,
        input        exp_exception,
        input [5:0]  exp_ecode
    );
        begin
            `check({name, " idle before query"}, !d_tlb_resp_valid);
            d_tlb_query_valid = 1'b1;
            d_tlb_query_write = write;
            d_tlb_query_vaddr = vaddr;
            tick();
            d_tlb_query_valid = 1'b0;
            d_tlb_query_write = 1'b0;
            d_tlb_query_vaddr = 32'b0;
            #1;
            `check({name, " no response at issue cycle"}, !d_tlb_resp_valid);
            tick();
            #1;
            `check({name, " no response at plus one"}, !d_tlb_resp_valid);
            tick();
            #1;
            `check({name, " no response at plus two"}, !d_tlb_resp_valid);
            tick();
            #1;
            `check({name, " response at plus three"}, d_tlb_resp_valid);
            `check32({name, " response vaddr"}, d_tlb_resp_vaddr, vaddr);
            `check32({name, " response paddr"}, d_tlb_query_paddr, exp_paddr);
            `check({name, " response exception"}, d_tlb_exception_valid == exp_exception);
            if (exp_exception) begin
                `check32({name, " response ecode"}, {26'b0, d_tlb_exception_ecode},
                         {26'b0, exp_ecode});
            end
            tick();
            #1;
            `check({name, " response pulse clears"}, !d_tlb_resp_valid);
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        expect_i_response_after_two_cycles("I-TLB direct map",
                                           32'h1c00_0004,
                                           32'h1c00_0004,
                                           1'b0,
                                           6'b0);

        csr_crmd = 32'h10;
        csr_asid = 32'h12;
        write_tlb_entry(5'd3, TEST_VADDR, TEST_PPN0, TEST_PPN1, 1'b0, 1'b1);

        expect_i_response_after_three_cycles("I-TLB translated hit",
                                             TEST_VADDR,
                                             {TEST_PPN0, TEST_VADDR[11:0]},
                                             1'b0,
                                             6'b0);

        expect_d_response_after_three_cycles("D-TLB dirty exception",
                                             TEST_VADDR,
                                             1'b1,
                                             {TEST_PPN0, TEST_VADDR[11:0]},
                                             1'b1,
                                             6'h04);

        expect_i_response_after_three_cycles("I-TLB refill exception",
                                             MISS_VADDR,
                                             32'h0000_0004,
                                             1'b1,
                                             6'h3f);

        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module s5_m1_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic reset;
    logic in_valid;
    logic in_is_load;
    logic in_is_store;
    logic in_is_csr;
    logic in_csr_we;
    logic in_exception_valid;
    logic in_exception_badv_valid;
    logic d_tlb_resp_valid;
    logic d_tlb_exception_valid;
    logic dcache_req_valid;
    logic dcache_req_write;
    logic dcache_resp_valid;
    logic m1_allowin;
    logic m1_load_valid;
    logic out_valid;
    logic out_wen;
    logic out_csr_we;
    logic out_exception_valid;
    logic out_exception_badv_valid;
    logic d_tlb_query_valid;
    logic d_tlb_query_write;

    logic [3:0] dcache_req_wstrb;
    logic [4:0] in_rd;
    logic [4:0] m1_load_rd;
    logic [4:0] out_rd;
    logic [5:0] in_exception_ecode;
    logic [5:0] d_tlb_exception_ecode;
    logic [5:0] out_exception_ecode;
    logic [8:0] in_exception_esubcode;
    logic [8:0] out_exception_esubcode;
    logic [13:0] in_csr_addr;
    logic [13:0] out_csr_addr;

    logic [31:0] in_pc;
    logic [31:0] in_inst;
    logic [31:0] in_result;
    logic [31:0] in_op1;
    logic [31:0] in_op2;
    logic [31:0] in_store_data;
    logic [31:0] in_csr_wdata;
    logic [31:0] in_exception_badv;
    logic [31:0] d_tlb_resp_vaddr;
    logic [31:0] d_tlb_query_paddr;
    logic [31:0] dcache_req_addr;
    logic [31:0] dcache_req_wdata;
    logic [31:0] dcache_resp_data;
    logic [31:0] out_pc;
    logic [31:0] out_inst;
    logic [31:0] out_wb_data;
    logic [31:0] out_op1;
    logic [31:0] out_op2;
    logic [31:0] out_csr_wdata;
    logic [31:0] out_exception_badv;
    logic [31:0] d_tlb_query_vaddr;

    assign reset = !rst_n;

    s5_m1 u_dut (
        .clk(clk),
        .reset(reset),
        .in_valid(in_valid),
        .in_pc(in_pc),
        .in_inst(in_inst),
        .in_rd(in_rd),
        .in_result(in_result),
        .in_op1(in_op1),
        .in_op2(in_op2),
        .in_is_load(in_is_load),
        .in_is_store(in_is_store),
        .in_store_data(in_store_data),
        .in_is_csr(in_is_csr),
        .in_csr_we(in_csr_we),
        .in_csr_addr(in_csr_addr),
        .in_csr_wdata(in_csr_wdata),
        .in_exception_valid(in_exception_valid),
        .in_exception_ecode(in_exception_ecode),
        .in_exception_esubcode(in_exception_esubcode),
        .in_exception_badv_valid(in_exception_badv_valid),
        .in_exception_badv(in_exception_badv),
        .d_tlb_query_valid(d_tlb_query_valid),
        .d_tlb_query_write(d_tlb_query_write),
        .d_tlb_query_vaddr(d_tlb_query_vaddr),
        .d_tlb_resp_valid(d_tlb_resp_valid),
        .d_tlb_resp_vaddr(d_tlb_resp_vaddr),
        .d_tlb_query_paddr(d_tlb_query_paddr),
        .d_tlb_exception_valid(d_tlb_exception_valid),
        .d_tlb_exception_ecode(d_tlb_exception_ecode),
        .dcache_req_valid(dcache_req_valid),
        .dcache_req_write(dcache_req_write),
        .dcache_req_addr(dcache_req_addr),
        .dcache_req_wdata(dcache_req_wdata),
        .dcache_req_wstrb(dcache_req_wstrb),
        .dcache_resp_valid(dcache_resp_valid),
        .dcache_resp_data(dcache_resp_data),
        .m1_allowin(m1_allowin),
        .m1_load_valid(m1_load_valid),
        .m1_load_rd(m1_load_rd),
        .out_valid(out_valid),
        .out_pc(out_pc),
        .out_inst(out_inst),
        .out_rd(out_rd),
        .out_wb_data(out_wb_data),
        .out_op1(out_op1),
        .out_op2(out_op2),
        .out_wen(out_wen),
        .out_csr_we(out_csr_we),
        .out_csr_addr(out_csr_addr),
        .out_csr_wdata(out_csr_wdata),
        .out_exception_valid(out_exception_valid),
        .out_exception_ecode(out_exception_ecode),
        .out_exception_esubcode(out_exception_esubcode),
        .out_exception_badv_valid(out_exception_badv_valid),
        .out_exception_badv(out_exception_badv)
    );

    function automatic [31:0] encode_add_w;
        input [4:0] rd_in;
        input [4:0] rj_in;
        input [4:0] rk_in;
        begin
            encode_add_w = {6'h00, 4'h0, 2'h1, 5'h00, rk_in, rj_in, rd_in};
        end
    endfunction

    function automatic [31:0] encode_beq;
        input [4:0] rj_in;
        input [4:0] rd_in;
        input [15:0] offs16;
        begin
            encode_beq = {6'h16, offs16, rj_in, rd_in};
        end
    endfunction

    function automatic [31:0] encode_ld_w;
        input [4:0] rd_in;
        input [4:0] rj_in;
        input [11:0] imm12;
        begin
            encode_ld_w = {6'h0a, 4'h2, imm12, rj_in, rd_in};
        end
    endfunction

    function automatic [31:0] encode_st_b;
        input [4:0] rd_in;
        input [4:0] rj_in;
        input [11:0] imm12;
        begin
            encode_st_b = {6'h0a, 4'h4, imm12, rj_in, rd_in};
        end
    endfunction

    function automatic [31:0] encode_ld_h;
        input [4:0] rd_in;
        input [4:0] rj_in;
        input [11:0] imm12;
        begin
            encode_ld_h = {6'h0a, 4'h1, imm12, rj_in, rd_in};
        end
    endfunction

    function automatic [31:0] encode_cacop;
        input [4:0] code;
        input [4:0] rj_in;
        input [11:0] imm12;
        begin
            encode_cacop = {6'h01, 4'h8, imm12, rj_in, code};
        end
    endfunction

    task automatic clear_inputs;
        begin
            in_valid = 1'b0;
            in_pc = 32'b0;
            in_inst = 32'b0;
            in_rd = 5'b0;
            in_result = 32'b0;
            in_op1 = 32'b0;
            in_op2 = 32'b0;
            in_is_load = 1'b0;
            in_is_store = 1'b0;
            in_store_data = 32'b0;
            in_is_csr = 1'b0;
            in_csr_we = 1'b0;
            in_csr_addr = 14'b0;
            in_csr_wdata = 32'b0;
            in_exception_valid = 1'b0;
            in_exception_ecode = 6'b0;
            in_exception_esubcode = 9'b0;
            in_exception_badv_valid = 1'b0;
            in_exception_badv = 32'b0;
            d_tlb_resp_valid = 1'b0;
            d_tlb_resp_vaddr = 32'b0;
            d_tlb_query_paddr = 32'b0;
            d_tlb_exception_valid = 1'b0;
            d_tlb_exception_ecode = 6'b0;
            dcache_resp_valid = 1'b0;
            dcache_resp_data = 32'b0;
        end
    endtask

    task automatic issue_nonmem;
        input [31:0] inst;
        input [4:0] rd;
        input [31:0] result;
        begin
            clear_inputs();
            in_valid = 1'b1;
            in_pc = 32'h1c00_1000;
            in_inst = inst;
            in_rd = rd;
            in_result = result;
            in_op1 = 32'h1111_2222;
            in_op2 = 32'h3333_4444;
            tick();
            clear_inputs();
        end
    endtask

    task automatic issue_mem;
        input [31:0] inst;
        input [4:0] rd;
        input [31:0] addr;
        input is_load;
        input is_store;
        begin
            clear_inputs();
            in_valid = 1'b1;
            in_pc = 32'h1c00_2000;
            in_inst = inst;
            in_rd = rd;
            in_result = addr;
            in_op1 = 32'h1000_0000;
            in_op2 = 32'h2222_3333;
            in_is_load = is_load;
            in_is_store = is_store;
            in_store_data = 32'ha1b2_c3d4;
            tick();
            clear_inputs();
        end
    endtask

    task automatic send_tlb_resp;
        input [31:0] vaddr;
        input [31:0] paddr;
        input exc_valid;
        input [5:0] exc_ecode;
        begin
            d_tlb_resp_valid = 1'b1;
            d_tlb_resp_vaddr = vaddr;
            d_tlb_query_paddr = paddr;
            d_tlb_exception_valid = exc_valid;
            d_tlb_exception_ecode = exc_ecode;
            tick();
            d_tlb_resp_valid = 1'b0;
            d_tlb_exception_valid = 1'b0;
        end
    endtask

    task automatic send_dcache_resp;
        input [31:0] data;
        begin
            dcache_resp_valid = 1'b1;
            dcache_resp_data = data;
            tick();
            dcache_resp_valid = 1'b0;
            dcache_resp_data = 32'b0;
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        issue_nonmem(encode_add_w(5'd3, 5'd4, 5'd5), 5'd3, 32'hdead_beef);
        `check("M1 nonmem emits", out_valid);
        `check32("M1 nonmem pc", out_pc, 32'h1c00_1000);
        `check32("M1 nonmem rd", {27'b0, out_rd}, 32'd3);
        `check32("M1 nonmem wb data", out_wb_data, 32'hdead_beef);
        `check("M1 nonmem writes GPR", out_wen);
        `check("M1 nonmem no exception", !out_exception_valid);
        tick();
        `check("M1 output clears by default", !out_valid);

        issue_nonmem(encode_beq(5'd1, 5'd2, 16'h0004), 5'd2, 32'h1111_1111);
        `check("M1 branch emits", out_valid);
        `check("M1 branch suppresses GPR write", !out_wen);
        tick();

        clear_inputs();
        in_valid = 1'b1;
        in_pc = 32'h1c00_1100;
        in_inst = encode_add_w(5'd6, 5'd7, 5'd8);
        in_rd = 5'd6;
        in_result = 32'h0123_4567;
        in_is_csr = 1'b1;
        in_csr_we = 1'b1;
        in_csr_addr = 14'h123;
        in_csr_wdata = 32'hc001_cafe;
        tick();
        clear_inputs();
        `check("M1 CSR emits", out_valid);
        `check("M1 CSR write passes", out_csr_we);
        `check32("M1 CSR addr", {18'b0, out_csr_addr}, {18'b0, 14'h123});
        `check32("M1 CSR wdata", out_csr_wdata, 32'hc001_cafe);
        tick();

        issue_mem(encode_ld_w(5'd9, 5'd10, 12'h020), 5'd9, 32'h8000_0004, 1'b1, 1'b0);
        `check("M1 load captured pending", !m1_allowin);
        `check("M1 load pending visible", m1_load_valid);
        `check32("M1 load pending rd", {27'b0, m1_load_rd}, 32'd9);
        send_tlb_resp(32'h8000_0004, 32'h0000_1004, 1'b0, 6'b0);
        `check("M1 load issues dcache request", dcache_req_valid);
        `check("M1 load request is read", !dcache_req_write);
        `check32("M1 load request aligned paddr", dcache_req_addr, 32'h0000_1004);
        `check32("M1 load request wstrb zero", {28'b0, dcache_req_wstrb}, 32'h0);
        send_dcache_resp(32'h5566_7788);
        `check("M1 load emits response", out_valid);
        `check("M1 load writes GPR", out_wen);
        `check32("M1 load wb data", out_wb_data, 32'h5566_7788);
        `check("M1 load pending cleared", m1_allowin);
        tick();

        issue_mem(encode_st_b(5'd11, 5'd12, 12'h030), 5'd0, 32'h8000_0003, 1'b0, 1'b1);
        send_tlb_resp(32'h8000_0003, 32'h0000_2003, 1'b0, 6'b0);
        `check("M1 store issues dcache request", dcache_req_valid);
        `check("M1 store request is write", dcache_req_write);
        `check32("M1 store request aligned paddr", dcache_req_addr, 32'h0000_2000);
        `check32("M1 store byte wstrb", {28'b0, dcache_req_wstrb}, 32'h8);
        `check32("M1 store byte wdata", dcache_req_wdata, 32'hd400_0000);
        send_dcache_resp(32'b0);
        `check("M1 store emits completion", out_valid);
        `check("M1 store suppresses GPR write", !out_wen);
        tick();

        issue_mem(encode_ld_h(5'd13, 5'd14, 12'h040), 5'd13, 32'h8000_0001, 1'b1, 1'b0);
        tick();
        `check("M1 ALE emits exception", out_valid);
        `check("M1 ALE exception valid", out_exception_valid);
        `check32("M1 ALE ecode", {26'b0, out_exception_ecode}, 32'h09);
        `check32("M1 ALE badv", out_exception_badv, 32'h8000_0001);
        `check("M1 ALE suppresses GPR write", !out_wen);
        tick();

        issue_mem(encode_ld_w(5'd14, 5'd15, 12'h050), 5'd14, 32'h9000_0000, 1'b1, 1'b0);
        send_tlb_resp(32'h9000_0000, 32'b0, 1'b1, 6'h3f);
        `check("M1 TLB exception emits", out_valid);
        `check("M1 TLB exception valid", out_exception_valid);
        `check32("M1 TLB exception ecode", {26'b0, out_exception_ecode}, {26'b0, 6'h3f});
        `check32("M1 TLB exception badv", out_exception_badv, 32'h9000_0000);
        `check("M1 TLB exception no dcache request", !dcache_req_valid);
        tick();

        issue_mem(encode_cacop(5'b10000, 5'd1, 12'h060), 5'd0, 32'ha000_0000, 1'b1, 1'b0);
        send_tlb_resp(32'ha000_0000, 32'h0000_3000, 1'b0, 6'b0);
        `check("M1 CACOP emits after translate", out_valid);
        `check("M1 CACOP suppresses GPR write", !out_wen);
        `check("M1 CACOP skips dcache request", !dcache_req_valid);

        finish_tb();
    end
endmodule

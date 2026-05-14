`timescale 1ns / 1ps

module cpu_tlb_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [18:0] s0_vppn, s1_vppn, invtlb_vpn, srch_vppn, w_vppn, r_vppn;
    logic s0_va12, s1_va12, s0_found, s1_found, invtlb_valid, we, w_e, w_g, w_d0, w_v0, w_d1, w_v1;
    logic srch_found, r_e, r_g, r_d0, r_v0, r_d1, r_v1;
    logic [9:0] s0_asid, s1_asid, invtlb_asid, srch_asid, w_asid, r_asid;
    logic [4:0] invtlb_op;
    logic [1:0] s0_index, s1_index, srch_index, w_index, r_index;
    logic [19:0] s0_ppn, s1_ppn, w_ppn0, w_ppn1, r_ppn0, r_ppn1;
    logic [5:0] s0_ps, s1_ps, w_ps, r_ps;
    logic [1:0] s0_plv, s0_mat, s1_plv, s1_mat, w_plv0, w_mat0, w_plv1, w_mat1, r_plv0, r_mat0, r_plv1, r_mat1;
    cpu_tlb #(.TLBNUM(4)) u_dut (
        .clk(clk), .rst_n(rst_n), .s0_vppn(s0_vppn), .s0_va_bit12(s0_va12), .s0_asid(s0_asid),
        .s0_found(s0_found), .s0_index(s0_index), .s0_ppn(s0_ppn), .s0_ps(s0_ps),
        .s0_plv(s0_plv), .s0_mat(s0_mat), .s0_d(), .s0_v(), .s1_vppn(s1_vppn),
        .s1_va_bit12(s1_va12), .s1_asid(s1_asid), .s1_found(s1_found), .s1_index(s1_index),
        .s1_ppn(s1_ppn), .s1_ps(s1_ps), .s1_plv(s1_plv), .s1_mat(s1_mat), .s1_d(), .s1_v(),
        .invtlb_valid(invtlb_valid), .invtlb_op(invtlb_op), .invtlb_asid(invtlb_asid),
        .invtlb_vpn(invtlb_vpn), .srch_vppn(srch_vppn), .srch_asid(srch_asid),
        .srch_found(srch_found), .srch_index(srch_index),
        .we(we), .w_index(w_index), .w_e(w_e), .w_vppn(w_vppn),
        .w_ps(w_ps), .w_asid(w_asid), .w_g(w_g), .w_ppn0(w_ppn0), .w_plv0(w_plv0),
        .w_mat0(w_mat0), .w_d0(w_d0), .w_v0(w_v0), .w_ppn1(w_ppn1), .w_plv1(w_plv1),
        .w_mat1(w_mat1), .w_d1(w_d1), .w_v1(w_v1), .r_index(r_index), .r_e(r_e),
        .r_vppn(r_vppn), .r_ps(r_ps), .r_asid(r_asid), .r_g(r_g), .r_ppn0(r_ppn0),
        .r_plv0(r_plv0), .r_mat0(r_mat0), .r_d0(r_d0), .r_v0(r_v0), .r_ppn1(r_ppn1),
        .r_plv1(r_plv1), .r_mat1(r_mat1), .r_d1(r_d1), .r_v1(r_v1)
    );

    initial begin
        tb_start();
        s0_vppn = 0; s0_va12 = 0; s0_asid = 0; s1_vppn = 0; s1_va12 = 0; s1_asid = 0; invtlb_valid = 0; invtlb_op = 0; invtlb_asid = 0; invtlb_vpn = 0; srch_vppn = 0; srch_asid = 0; we = 0;
        w_index = 0; w_e = 0; w_vppn = 0; w_ps = 6'd12; w_asid = 0; w_g = 0; w_ppn0 = 0; w_plv0 = 0; w_mat0 = 0; w_d0 = 0; w_v0 = 0; w_ppn1 = 0; w_plv1 = 0; w_mat1 = 0; w_d1 = 0; w_v1 = 0; r_index = 0;
        reset_dut();
        we = 1'b1; w_index = 2'd1; w_e = 1'b1; w_vppn = 19'h12345; w_ps = 6'd12; w_asid = 10'h12; w_g = 0;
        w_ppn0 = 20'habcde; w_plv0 = 0; w_mat0 = 1; w_d0 = 1; w_v0 = 1;
        w_ppn1 = 20'hfedcb; w_plv1 = 3; w_mat1 = 2; w_d1 = 0; w_v1 = 1; tick();
        we = 0; s0_vppn = 19'h12345; s0_asid = 10'h12; s0_va12 = 1; r_index = 2'd1;
        srch_vppn = 19'h12345; srch_asid = 10'h12; #1;
        `check("TLB CSR search finds entry", srch_found && srch_index == 2'd1);
        tick();
        `check("TLB find", s0_found);
        `check32("TLB odd ppn", {12'h0, s0_ppn}, 32'h000fedcb);
        `check("TLB read port", r_e && r_v1);

        we = 1'b1; w_index = 2'd2; w_e = 1'b1; w_vppn = 19'h22000; w_ps = 6'd12; w_asid = 10'h55; w_g = 1'b1;
        w_ppn0 = 20'h11111; w_ppn1 = 20'h22222; tick(); we = 1'b0;
        we = 1'b1; w_index = 2'd3; w_e = 1'b1; w_vppn = 19'h33000; w_ps = 6'd21; w_asid = 10'h77; w_g = 1'b0;
        w_ppn0 = 20'h33333; w_ppn1 = 20'h44444; tick(); we = 1'b0;

        invtlb_valid = 1'b1; invtlb_op = 5'd2; tick(); invtlb_valid = 1'b0; #1;
        r_index = 2'd2; #1;
        `check("TLB INVTLB op2 clears global entry", !r_e);
        r_index = 2'd3; #1;
        `check("TLB INVTLB op2 keeps non-global entry", r_e);

        invtlb_valid = 1'b1; invtlb_op = 5'd5; invtlb_asid = 10'h77; invtlb_vpn = 19'h33123; tick(); invtlb_valid = 1'b0; #1;
        r_index = 2'd3; #1;
        `check("TLB INVTLB op5 matches 4MB VPN high bits", !r_e);

        we = 1'b1; w_index = 2'd1; w_e = 1'b1; w_vppn = 19'h12345; w_ps = 6'd12; w_asid = 10'h12; w_g = 0; tick(); we = 1'b0;
        invtlb_valid = 1'b1; invtlb_op = 5'd0; tick(); invtlb_valid = 1'b0; tick();
        `check("TLB invalidate all", !s0_found);
        finish_tb();
    end
endmodule

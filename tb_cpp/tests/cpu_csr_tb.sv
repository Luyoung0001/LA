`timescale 1ns / 1ps
`include "cpu_defs.vh"

module cpu_csr_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [13:0] rd_addr;
    logic [31:0] rd_data;
    logic wr_valid;
    logic [13:0] wr_addr;
    logic [31:0] wr_data;
    logic timer_tick_i;
    logic excp_valid;
    logic [31:0] excp_pc;
    logic [5:0] excp_ecode;
    logic [8:0] excp_esubcode;
    logic excp_badv_valid;
    logic [31:0] excp_badv;
    logic llbit_set;
    logic llbit_in;
    logic lladdr_set;
    logic [27:0] lladdr_in;
    logic [7:0] interrupt_i;
    logic ertn_valid;
    logic tlbsrch_valid, tlbsrch_found, tlbrd_valid, tlbrd_e, tlbrd_g, tlbrd_d0, tlbrd_v0, tlbrd_d1, tlbrd_v1;
    logic [4:0] tlbsrch_index;
    logic [18:0] tlbrd_vppn;
    logic [5:0] tlbrd_ps;
    logic [9:0] tlbrd_asid;
    logic [19:0] tlbrd_ppn0, tlbrd_ppn1;
    logic [1:0] tlbrd_plv0, tlbrd_mat0, tlbrd_plv1, tlbrd_mat1;
    logic has_int;
    logic [31:0] eentry, era, crmd, prmd, ecfg, estat, badv, save0, save1, save2, save3;
    logic [31:0] tid, tcfg, tval, tlbidx, tlbehi, tlbelo0, tlbelo1, asid, tlbrentry, dmw0, dmw1;
    logic [63:0] timer64;

    cpu_csr u_dut (
        .clk(clk), .rst_n(rst_n),
        .rd_addr_i(rd_addr), .rd_data_o(rd_data),
        .wr_valid_i(wr_valid), .wr_addr_i(wr_addr), .wr_data_i(wr_data),
        .timer_tick_i(timer_tick_i),
        .interrupt_i(interrupt_i), .has_int_o(has_int),
        .excp_valid_i(excp_valid), .excp_pc_i(excp_pc),
        .excp_ecode_i(excp_ecode), .excp_esubcode_i(excp_esubcode),
        .excp_badv_valid_i(excp_badv_valid), .excp_badv_i(excp_badv),
        .ertn_valid_i(ertn_valid),
        .llbit_set_i(llbit_set), .llbit_i(llbit_in),
        .lladdr_set_i(lladdr_set), .lladdr_i(lladdr_in),
        .tlbsrch_valid_i(tlbsrch_valid), .tlbsrch_found_i(tlbsrch_found),
        .tlbsrch_index_i(tlbsrch_index), .tlbrd_valid_i(tlbrd_valid),
        .tlbrd_e_i(tlbrd_e), .tlbrd_vppn_i(tlbrd_vppn), .tlbrd_ps_i(tlbrd_ps),
        .tlbrd_asid_i(tlbrd_asid), .tlbrd_g_i(tlbrd_g), .tlbrd_ppn0_i(tlbrd_ppn0),
        .tlbrd_plv0_i(tlbrd_plv0), .tlbrd_mat0_i(tlbrd_mat0), .tlbrd_d0_i(tlbrd_d0),
        .tlbrd_v0_i(tlbrd_v0), .tlbrd_ppn1_i(tlbrd_ppn1), .tlbrd_plv1_i(tlbrd_plv1),
        .tlbrd_mat1_i(tlbrd_mat1), .tlbrd_d1_i(tlbrd_d1), .tlbrd_v1_i(tlbrd_v1),
        .eentry_o(eentry), .era_o(era), .crmd_o(crmd), .prmd_o(prmd), .estat_o(estat),
        .ecfg_o(ecfg), .badv_o(badv),
        .save0_o(save0), .save1_o(save1), .save2_o(save2), .save3_o(save3),
        .tid_o(tid), .tcfg_o(tcfg), .tval_o(tval),
        .tlbidx_o(tlbidx), .tlbehi_o(tlbehi), .tlbelo0_o(tlbelo0),
        .tlbelo1_o(tlbelo1), .asid_o(asid), .tlbrentry_o(tlbrentry),
        .dmw0_o(dmw0), .dmw1_o(dmw1),
        .timer64_o(timer64)
    );

    task automatic csr_write(input [13:0] addr, input [31:0] data);
        begin
            wr_addr = addr;
            wr_data = data;
            wr_valid = 1'b1;
            tick();
            wr_valid = 1'b0;
            #1;
        end
    endtask

    task automatic csr_read_check(input string name, input [13:0] addr, input [31:0] expected);
        begin
            rd_addr = addr;
            #1;
            `check32(name, rd_data, expected);
        end
    endtask

    initial begin
        tb_start();
        rd_addr = 0; wr_valid = 0; wr_addr = 0; wr_data = 0; timer_tick_i = 1'b1;
        excp_valid = 0; excp_pc = 0; excp_ecode = 0; excp_esubcode = 0;
        excp_badv_valid = 0; excp_badv = 0; llbit_set = 0; llbit_in = 0; lladdr_set = 0; lladdr_in = 0;
        interrupt_i = 0; ertn_valid = 0;
        tlbsrch_valid = 0; tlbsrch_found = 0; tlbsrch_index = 0;
        tlbrd_valid = 0; tlbrd_e = 0; tlbrd_vppn = 0; tlbrd_ps = 0; tlbrd_asid = 0; tlbrd_g = 0;
        tlbrd_ppn0 = 0; tlbrd_plv0 = 0; tlbrd_mat0 = 0; tlbrd_d0 = 0; tlbrd_v0 = 0;
        tlbrd_ppn1 = 0; tlbrd_plv1 = 0; tlbrd_mat1 = 0; tlbrd_d1 = 0; tlbrd_v1 = 0;
        reset_dut();

        csr_read_check("CSR reset CRMD direct mode", `CPU_CSR_CRMD, 32'h0000_0008);
        csr_read_check("CSR reset PRMD", `CPU_CSR_PRMD, 32'h0000_0000);
        csr_read_check("CSR reset ASID reports 10 ASID bits", `CPU_CSR_ASID, 32'h000a_0000);
        csr_read_check("CSR CPUCFG1 fixed value", `CPU_CSR_CPUCFG1, 32'h0001_f1f4);
        csr_read_check("CSR CPUCFG2 fixed value", `CPU_CSR_CPUCFG2, 32'h0000_0000);
        csr_read_check("CSR CPUCFG10 fixed value", `CPU_CSR_CPUCFG10, 32'h0000_0005);
        csr_read_check("CSR CPUCFG11 fixed value", `CPU_CSR_CPUCFG11, 32'h0408_0001);
        csr_read_check("CSR CPUCFG12 fixed value", `CPU_CSR_CPUCFG12, 32'h0408_0001);
        csr_read_check("CSR CPUCFG13 fixed value", `CPU_CSR_CPUCFG13, 32'h0000_0000);

        csr_write(`CPU_CSR_EENTRY, 32'h1c00_8000);
        csr_write(`CPU_CSR_TLBRENTRY, 32'h1c00_8043);
        csr_write(`CPU_CSR_TLBIDX, 32'h8c00_0003);
        csr_write(`CPU_CSR_TLBEHI, 32'h0001_2345);
        csr_write(`CPU_CSR_TLBELO0, 32'hf034_abcd);
        csr_write(`CPU_CSR_TLBELO1, 32'hf0ff_ab41);
        csr_write(`CPU_CSR_ASID, 32'hffff_02aa);
        csr_write(`CPU_CSR_ECFG, 32'h0000_1fff);
        csr_write(`CPU_CSR_TID, 32'h1234_abcd);
        csr_write(`CPU_CSR_SAVE0, 32'h1111_2222);
        csr_write(`CPU_CSR_SAVE1, 32'h3333_4444);
        csr_write(`CPU_CSR_SAVE2, 32'h5555_6666);
        csr_write(`CPU_CSR_SAVE3, 32'h7777_8888);
        csr_write(`CPU_CSR_DMW0, 32'h9fff_ffff);
        csr_write(`CPU_CSR_DMW1, 32'h7fff_fff9);
        csr_read_check("CSR EENTRY write/read", `CPU_CSR_EENTRY, 32'h1c00_8000);
        csr_read_check("CSR TLBRENTRY aligns low 6 bits", `CPU_CSR_TLBRENTRY, 32'h1c00_8040);
        csr_read_check("CSR TLBIDX keeps NE/PS/index", `CPU_CSR_TLBIDX, 32'h8c00_0003);
        csr_read_check("CSR TLBEHI keeps only VPPN", `CPU_CSR_TLBEHI, 32'h0001_2000);
        csr_read_check("CSR TLBELO0 masks reserved bits", `CPU_CSR_TLBELO0, 32'h0034_ab4d);
        csr_read_check("CSR TLBELO1 masks reserved bits", `CPU_CSR_TLBELO1, 32'h00ff_ab41);
        csr_read_check("CSR ASID writes low 10 bits", `CPU_CSR_ASID, 32'h000a_02aa);
        csr_read_check("CSR ECFG masks reserved LIE bit10", `CPU_CSR_ECFG, 32'h0000_1bff);
        csr_read_check("CSR TID write/read", `CPU_CSR_TID, 32'h1234_abcd);
        csr_read_check("CSR SAVE0 write/read", `CPU_CSR_SAVE0, 32'h1111_2222);
        csr_read_check("CSR SAVE1 write/read", `CPU_CSR_SAVE1, 32'h3333_4444);
        csr_read_check("CSR SAVE2 write/read", `CPU_CSR_SAVE2, 32'h5555_6666);
        csr_read_check("CSR SAVE3 write/read", `CPU_CSR_SAVE3, 32'h7777_8888);
        csr_read_check("CSR DMW0 masks reserved bits", `CPU_CSR_DMW0, 32'h8e00_0039);
        csr_read_check("CSR DMW1 masks reserved bits", `CPU_CSR_DMW1, 32'h6e00_0039);

        llbit_in = 1'b1;
        llbit_set = 1'b1;
        lladdr_in = 28'h1234_567;
        lladdr_set = 1'b1;
        tick();
        llbit_set = 1'b0;
        lladdr_set = 1'b0;
        #1;
        csr_read_check("CSR LLBCTL reflects llbit", `CPU_CSR_LLBCTL, 32'h0000_0001);
        `check32("CSR lladdr commit input", u_dut.lladdr_o, 28'h1234_567);

        csr_write(`CPU_CSR_LLBCTL, 32'h0000_0002);
        csr_read_check("CSR LLBCTL WCLLB clears llbit", `CPU_CSR_LLBCTL, 32'h0000_0000);

        llbit_in = 1'b1;
        llbit_set = 1'b1;
        tick();
        llbit_set = 1'b0;
        #1;
        csr_write(`CPU_CSR_LLBCTL, 32'h0000_0004);
        csr_read_check("CSR LLBCTL keeps KLO visible", `CPU_CSR_LLBCTL, 32'h0000_0005);
        ertn_valid = 1'b1;
        tick();
        ertn_valid = 1'b0;
        #1;
        csr_read_check("CSR ERTN with KLO keeps llbit but clears KLO", `CPU_CSR_LLBCTL, 32'h0000_0001);
        ertn_valid = 1'b1;
        tick();
        ertn_valid = 1'b0;
        #1;
        csr_read_check("CSR ERTN without KLO clears llbit", `CPU_CSR_LLBCTL, 32'h0000_0000);

        tlbsrch_found = 1'b1;
        tlbsrch_index = 5'd7;
        tlbsrch_valid = 1'b1;
        tick();
        tlbsrch_valid = 1'b0;
        #1;
        csr_read_check("CSR TLBSRCH hit writes index and clears NE", `CPU_CSR_TLBIDX, 32'h0c00_0007);
        tlbsrch_found = 1'b0;
        tlbsrch_valid = 1'b1;
        tick();
        tlbsrch_valid = 1'b0;
        #1;
        `check("CSR TLBSRCH miss sets NE", tlbidx[31]);

        tlbrd_e = 1'b1;
        tlbrd_vppn = 19'h12345;
        tlbrd_ps = 6'd21;
        tlbrd_asid = 10'h155;
        tlbrd_g = 1'b1;
        tlbrd_ppn0 = 20'h0abcd;
        tlbrd_plv0 = 2'd3;
        tlbrd_mat0 = 2'd1;
        tlbrd_d0 = 1'b1;
        tlbrd_v0 = 1'b1;
        tlbrd_ppn1 = 20'h0bcde;
        tlbrd_plv1 = 2'd0;
        tlbrd_mat1 = 2'd2;
        tlbrd_d1 = 1'b0;
        tlbrd_v1 = 1'b1;
        tlbrd_valid = 1'b1;
        tick();
        tlbrd_valid = 1'b0;
        #1;
        csr_read_check("CSR TLBRD valid writes TLBEHI", `CPU_CSR_TLBEHI, 32'h2468_a000);
        csr_read_check("CSR TLBRD valid writes TLBELO0", `CPU_CSR_TLBELO0, 32'h00ab_cd5f);
        csr_read_check("CSR TLBRD valid writes TLBELO1", `CPU_CSR_TLBELO1, 32'h00bc_de61);
        csr_read_check("CSR TLBRD valid writes ASID", `CPU_CSR_ASID, 32'h000a_0155);
        csr_read_check("CSR TLBRD valid writes PS and clears NE", `CPU_CSR_TLBIDX, 32'h1500_0007);

        tlbrd_e = 1'b0;
        tlbrd_valid = 1'b1;
        tick();
        tlbrd_valid = 1'b0;
        #1;
        csr_read_check("CSR TLBRD invalid clears TLBEHI", `CPU_CSR_TLBEHI, 32'h0000_0000);
        csr_read_check("CSR TLBRD invalid clears TLBELO0", `CPU_CSR_TLBELO0, 32'h0000_0000);
        csr_read_check("CSR TLBRD invalid sets NE", `CPU_CSR_TLBIDX, 32'h8000_0007);

        csr_write(`CPU_CSR_CRMD, 32'h0000_000b);
        excp_pc = 32'h1c01_0080;
        excp_ecode = `CPU_ECODE_SYS;
        excp_esubcode = 9'd0;
        excp_badv_valid = 1'b0;
        excp_valid = 1'b1;
        tick();
        excp_valid = 1'b0;
        #1;
        `check32("CSR exception saves ERA", era, 32'h1c01_0080);
        `check32("CSR exception clears CRMD PLV/IE only", crmd, 32'h0000_0008);
        `check32("CSR exception saves old PLV/IE to PRMD", prmd & 32'h7, 32'h0000_0003);
        `check32("CSR exception writes ESTAT.ECODE", (estat >> 16) & 32'h3f, `CPU_ECODE_SYS);

        excp_pc = 32'h1c01_0090;
        excp_ecode = `CPU_ECODE_ALE;
        excp_esubcode = 9'd0;
        excp_badv_valid = 1'b1;
        excp_badv = 32'h1d00_0001;
        excp_valid = 1'b1;
        tick();
        excp_valid = 1'b0;
        excp_badv_valid = 1'b0;
        #1;
        `check32("CSR ALE exception writes BADV", badv, 32'h1d00_0001);
        `check32("CSR ALE exception writes ECODE", (estat >> 16) & 32'h3f, `CPU_ECODE_ALE);

        csr_write(`CPU_CSR_ERA, 32'h1c01_0084);
        csr_write(`CPU_CSR_PRMD, 32'h0000_0003);
        ertn_valid = 1'b1;
        tick();
        ertn_valid = 1'b0;
        #1;
        `check32("CSR ERTN restores CRMD low bits", crmd & 32'h7, 32'h0000_0003);
        `check32("CSR ERTN keeps ERA value", era, 32'h1c01_0084);

        csr_write(`CPU_CSR_CRMD, 32'h0000_0010);
        csr_write(`CPU_CSR_PRMD, 32'h0000_0004);
        excp_pc = 32'h1c01_0100;
        excp_ecode = `CPU_ECODE_TLBR;
        excp_esubcode = 9'd0;
        excp_badv_valid = 1'b1;
        excp_badv = 32'h4000_1234;
        excp_valid = 1'b1;
        tick();
        excp_valid = 1'b0;
        excp_badv_valid = 1'b0;
        #1;
        `check32("CSR TLBR exception saves ERA", era, 32'h1c01_0100);
        `check32("CSR TLBR exception switches to DA=1 PG=0", crmd & 32'h18, 32'h0000_0008);
        `check32("CSR TLBR exception updates BADV", badv, 32'h4000_1234);
        `check32("CSR TLBR exception updates TLBEHI.VPPN", tlbehi, 32'h4000_0000);
        ertn_valid = 1'b1;
        tick();
        ertn_valid = 1'b0;
        #1;
        `check32("CSR ERTN from TLBR restores DA=0 PG=1", crmd & 32'h18, 32'h0000_0010);

        excp_pc = 32'h1c01_0104;
        excp_ecode = `CPU_ECODE_PIS;
        excp_badv_valid = 1'b1;
        excp_badv = 32'h5000_1abc;
        excp_valid = 1'b1;
        tick();
        excp_valid = 1'b0;
        excp_badv_valid = 1'b0;
        #1;
        `check32("CSR data TLB exception keeps normal exception mode", crmd & 32'h18, 32'h0000_0010);
        `check32("CSR data TLB exception updates TLBEHI.VPPN", tlbehi, 32'h5000_0000);
        `check32("CSR data TLB exception writes ESTAT.ECODE", (estat >> 16) & 32'h3f, `CPU_ECODE_PIS);

        csr_write(`CPU_CSR_CRMD, 32'h0000_000c);
        csr_write(`CPU_CSR_ECFG, 32'h0000_0003);
        csr_write(`CPU_CSR_ESTAT, 32'hffff_ffff);
        #1;
        `check("CSR software interrupt pending", has_int);
        `check32("CSR ESTAT write only affects software IS bits", estat & 32'h1fff, 32'h0000_0003);
        csr_write(`CPU_CSR_ESTAT, 32'h0000_0000);
        #1;
        `check("CSR software interrupt clears", !has_int);

        interrupt_i = 8'h04;
        tick();
        #1;
        csr_read_check("CSR hardware interrupt sampled into ESTAT[9:2]", `CPU_CSR_ESTAT, estat);
        `check32("CSR hardware interrupt bit position", estat & 32'h1fff, 32'h0000_0010);

        interrupt_i = 8'h00;
        csr_write(`CPU_CSR_ECFG, 32'h0000_0800);
        csr_write(`CPU_CSR_TCFG, 32'h0000_0001);
        repeat (3) tick();
        #1;
        `check("CSR timer interrupt pending", has_int && estat[11]);
        csr_read_check("CSR TVAL one-shot reaches terminal value", `CPU_CSR_TVAL, 32'hffff_ffff);
        csr_write(`CPU_CSR_TICLR, 32'h0000_0001);
        #1;
        `check("CSR TICLR clears timer interrupt", !estat[11]);
        csr_read_check("CSR TICLR reads zero", `CPU_CSR_TICLR, 32'h0000_0000);
        `check("CSR timer64 increments", timer64 != 64'd0);

        csr_write(`CPU_CSR_TCFG, 32'h0000_0005);
        timer_tick_i = 1'b0;
        repeat (3) tick();
        #1;
        `check32("CSR timer holds TVAL while tick disabled", tval, 32'h0000_0004);
        timer_tick_i = 1'b1;

        finish_tb();
    end
endmodule

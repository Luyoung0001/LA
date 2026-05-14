`timescale 1ns / 1ps

module s9_slot0_result_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] pc;
    logic [31:0] instr;
    logic [1:0]  epoch;
    logic [4:0]  rd;
    logic        wb_en;
    logic [31:0] wb_data_pre;
    logic        is_load;
    logic        is_store;
    logic        mem_uncached;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic        exception;
    logic [5:0]  excp_ecode;
    logic [8:0]  excp_esubcode;
    logic        excp_badv_valid;
    logic [31:0] excp_badv;
    logic        is_csr;
    logic        csr_we;
    logic        csr_xchg;
    logic [13:0] csr_addr;
    logic [31:0] csr_wdata;
    logic [31:0] csr_wmask;
    logic        is_syscall;
    logic        is_ertn;
    logic        is_ll;
    logic        is_sc;
    logic        sc_success;
    logic [31:0] mem_paddr;

    logic [31:0] pc_o;
    logic [31:0] instr_o;
    logic [1:0]  epoch_o;
    logic [4:0]  rd_o;
    logic        wb_en_o;
    logic [31:0] wb_data_pre_o;
    logic        is_load_o;
    logic        is_store_o;
    logic        mem_uncached_o;
    logic [1:0]  mem_size_o;
    logic        mem_sign_ext_o;
    logic        exception_o;
    logic [5:0]  excp_ecode_o;
    logic [8:0]  excp_esubcode_o;
    logic        excp_badv_valid_o;
    logic [31:0] excp_badv_o;
    logic        is_csr_o;
    logic        csr_we_o;
    logic        csr_xchg_o;
    logic [13:0] csr_addr_o;
    logic [31:0] csr_wdata_o;
    logic [31:0] csr_wmask_o;
    logic        is_syscall_o;
    logic        is_ertn_o;
    logic        is_ll_o;
    logic        is_sc_o;
    logic        sc_success_o;
    logic [31:0] mem_paddr_o;

    s9_slot0_result_packet #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .pc_i(pc),
        .instr_i(instr),
        .epoch_i(epoch),
        .rd_i(rd),
        .wb_en_i(wb_en),
        .wb_data_pre_i(wb_data_pre),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .mem_uncached_i(mem_uncached),
        .mem_size_i(mem_size),
        .mem_sign_ext_i(mem_sign_ext),
        .exception_i(exception),
        .excp_ecode_i(excp_ecode),
        .excp_esubcode_i(excp_esubcode),
        .excp_badv_valid_i(excp_badv_valid),
        .excp_badv_i(excp_badv),
        .is_csr_i(is_csr),
        .csr_we_i(csr_we),
        .csr_xchg_i(csr_xchg),
        .csr_addr_i(csr_addr),
        .csr_wdata_i(csr_wdata),
        .csr_wmask_i(csr_wmask),
        .is_syscall_i(is_syscall),
        .is_ertn_i(is_ertn),
        .is_ll_i(is_ll),
        .is_sc_i(is_sc),
        .sc_success_i(sc_success),
        .mem_paddr_i(mem_paddr),
        .pc_o(pc_o),
        .instr_o(instr_o),
        .epoch_o(epoch_o),
        .rd_o(rd_o),
        .wb_en_o(wb_en_o),
        .wb_data_pre_o(wb_data_pre_o),
        .is_load_o(is_load_o),
        .is_store_o(is_store_o),
        .mem_uncached_o(mem_uncached_o),
        .mem_size_o(mem_size_o),
        .mem_sign_ext_o(mem_sign_ext_o),
        .exception_o(exception_o),
        .excp_ecode_o(excp_ecode_o),
        .excp_esubcode_o(excp_esubcode_o),
        .excp_badv_valid_o(excp_badv_valid_o),
        .excp_badv_o(excp_badv_o),
        .is_csr_o(is_csr_o),
        .csr_we_o(csr_we_o),
        .csr_xchg_o(csr_xchg_o),
        .csr_addr_o(csr_addr_o),
        .csr_wdata_o(csr_wdata_o),
        .csr_wmask_o(csr_wmask_o),
        .is_syscall_o(is_syscall_o),
        .is_ertn_o(is_ertn_o),
        .is_ll_o(is_ll_o),
        .is_sc_o(is_sc_o),
        .sc_success_o(sc_success_o),
        .mem_paddr_o(mem_paddr_o)
    );

    task automatic drive_payload;
        begin
            pc = 32'h1c00_a000;
            instr = 32'h288c_0006;
            epoch = 2'd2;
            rd = 5'd6;
            wb_en = 1'b1;
            wb_data_pre = 32'h1234_5678;
            is_load = 1'b1;
            is_store = 1'b0;
            mem_uncached = 1'b1;
            mem_size = 2'd2;
            mem_sign_ext = 1'b1;
            exception = 1'b0;
            excp_ecode = 6'h09;
            excp_esubcode = 9'h012;
            excp_badv_valid = 1'b0;
            excp_badv = 32'h4000_0100;
            is_csr = 1'b0;
            csr_we = 1'b0;
            csr_xchg = 1'b0;
            csr_addr = 14'h018;
            csr_wdata = 32'h55aa_00ff;
            csr_wmask = 32'hffff_0000;
            is_syscall = 1'b0;
            is_ertn = 1'b0;
            is_ll = 1'b1;
            is_sc = 1'b0;
            sc_success = 1'b0;
            mem_paddr = 32'h0cafe000;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_payload();
        #1;
        `check32("PKT pc pass", pc_o, 32'h1c00_a000);
        `check32("PKT instr pass", instr_o, 32'h288c_0006);
        `check32("PKT epoch pass", {30'd0, epoch_o}, 32'd2);
        `check32("PKT rd pass", {27'd0, rd_o}, 32'd6);
        `check("PKT load sideband pass", wb_en_o && is_load_o && !is_store_o);
        `check("PKT mem attrs pass", mem_uncached_o && mem_sign_ext_o && mem_size_o == 2'd2);
        `check32("PKT wb data pass", wb_data_pre_o, 32'h1234_5678);
        `check32("PKT paddr pass", mem_paddr_o, 32'h0cafe000);
        `check("PKT ll/sc pass", is_ll_o && !is_sc_o && !sc_success_o);

        exception = 1'b1;
        excp_badv_valid = 1'b1;
        is_syscall = 1'b1;
        is_ertn = 1'b1;
        #1;
        `check("PKT exception pass",
               exception_o && excp_badv_valid_o && is_syscall_o && is_ertn_o);
        `check32("PKT exception bundle pass",
                 {17'd0, excp_esubcode_o, excp_ecode_o},
                 {17'd0, 9'h012, 6'h09});
        `check32("PKT exception badv pass", excp_badv_o, 32'h4000_0100);

        exception = 1'b0;
        excp_badv_valid = 1'b0;
        is_csr = 1'b1;
        csr_we = 1'b1;
        csr_xchg = 1'b1;
        is_ll = 1'b0;
        is_sc = 1'b1;
        sc_success = 1'b1;
        #1;
        `check("PKT csr controls pass", is_csr_o && csr_we_o && csr_xchg_o);
        `check32("PKT csr addr pass", {18'd0, csr_addr_o}, {18'd0, 14'h018});
        `check32("PKT csr data pass", csr_wdata_o, 32'h55aa_00ff);
        `check32("PKT csr mask pass", csr_wmask_o, 32'hffff_0000);
        `check("PKT sc success pass", !is_ll_o && is_sc_o && sc_success_o);

        pc = 32'hdead_beef;
        instr = 32'hffff_ffff;
        epoch = 2'd3;
        rd = 5'd31;
        wb_en = 1'b0;
        wb_data_pre = 32'hface_feed;
        is_load = 1'b0;
        is_store = 1'b1;
        mem_uncached = 1'b0;
        mem_size = 2'd1;
        mem_sign_ext = 1'b0;
        exception = 1'b0;
        excp_ecode = 6'h3f;
        excp_esubcode = 9'h1ff;
        excp_badv_valid = 1'b1;
        excp_badv = 32'h0bad_f00d;
        is_csr = 1'b0;
        csr_we = 1'b0;
        csr_xchg = 1'b0;
        is_syscall = 1'b0;
        is_ertn = 1'b0;
        mem_paddr = 32'h0123_4567;
        #1;
        `check32("PKT raw pc pass", pc_o, 32'hdead_beef);
        `check32("PKT raw instr pass", instr_o, 32'hffff_ffff);
        `check("PKT raw store controls pass",
               !wb_en_o && !is_load_o && is_store_o && mem_size_o == 2'd1);
        `check("PKT raw exception sideband preserved",
               !exception_o && excp_badv_valid_o &&
               excp_ecode_o == 6'h3f && excp_esubcode_o == 9'h1ff);
        `check32("PKT raw paddr pass", mem_paddr_o, 32'h0123_4567);

        finish_tb();
    end
endmodule

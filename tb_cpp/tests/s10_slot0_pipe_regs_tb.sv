`timescale 1ns / 1ps

module s10_slot0_pipe_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        capture;
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
`ifdef DIFFTEST_EN
    logic [31:0] diff_mem_vaddr;
    logic [31:0] diff_mem_paddr;
    logic [31:0] diff_store_data;
`endif

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
`ifdef DIFFTEST_EN
    logic [31:0] diff_mem_vaddr_o;
    logic [31:0] diff_mem_paddr_o;
    logic [31:0] diff_store_data_o;
`endif

    s10_slot0_pipe_regs #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .clk(clk),
        .capture_i(capture),
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
`ifdef DIFFTEST_EN
        .diff_mem_vaddr_i(diff_mem_vaddr),
        .diff_mem_paddr_i(diff_mem_paddr),
        .diff_store_data_i(diff_store_data),
`endif
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
`ifdef DIFFTEST_EN
        ,
        .diff_mem_vaddr_o(diff_mem_vaddr_o),
        .diff_mem_paddr_o(diff_mem_paddr_o),
        .diff_store_data_o(diff_store_data_o)
`endif
    );

    task automatic drive_payload;
        input [31:0] base;
        begin
            pc = base;
            instr = base ^ 32'h10a0_9000;
            epoch = base[1:0];
            rd = base[6:2];
            wb_en = base[7];
            wb_data_pre = base + 32'h1000_0100;
            is_load = base[8];
            is_store = base[9];
            mem_uncached = base[10];
            mem_size = base[12:11];
            mem_sign_ext = base[13];
            exception = base[14];
            excp_ecode = base[20:15];
            excp_esubcode = base[23:15];
            excp_badv_valid = base[24];
            excp_badv = base + 32'h2000_0200;
            is_csr = base[25];
            csr_we = base[26];
            csr_xchg = base[27];
            csr_addr = base[13:0];
            csr_wdata = base + 32'h3000_0300;
            csr_wmask = base ^ 32'h00ff_ff00;
            is_syscall = base[28];
            is_ertn = base[29];
            is_ll = base[30];
            is_sc = base[31];
            sc_success = base[0];
            mem_paddr = base + 32'h4000_0400;
`ifdef DIFFTEST_EN
            diff_mem_vaddr = base + 32'h5000_0500;
            diff_mem_paddr = base + 32'h6000_0600;
            diff_store_data = base + 32'h7000_0700;
`endif
        end
    endtask

    task automatic check_payload;
        input string prefix;
        input [31:0] base;
        begin
            `check32({prefix, " pc"}, pc_o, base);
            `check32({prefix, " instr"}, instr_o, base ^ 32'h10a0_9000);
            `check32({prefix, " epoch/rd/wb"},
                     {24'd0, epoch_o, rd_o, wb_en_o},
                     {24'd0, base[1:0], base[6:2], base[7]});
            `check32({prefix, " wb data pre"}, wb_data_pre_o, base + 32'h1000_0100);
            `check32({prefix, " memory controls"},
                     {26'd0, is_load_o, is_store_o, mem_uncached_o, mem_size_o, mem_sign_ext_o},
                     {26'd0, base[8], base[9], base[10], base[12:11], base[13]});
            `check32({prefix, " exception"},
                     {16'd0, exception_o, excp_ecode_o, excp_esubcode_o},
                     {16'd0, base[14], base[20:15], base[23:15]});
            `check32({prefix, " badv valid"}, {31'd0, excp_badv_valid_o},
                     {31'd0, base[24]});
            `check32({prefix, " badv"}, excp_badv_o, base + 32'h2000_0200);
            `check32({prefix, " csr controls"},
                     {15'd0, is_csr_o, csr_we_o, csr_xchg_o, csr_addr_o},
                     {15'd0, base[25], base[26], base[27], base[13:0]});
            `check32({prefix, " csr wdata"}, csr_wdata_o, base + 32'h3000_0300);
            `check32({prefix, " csr wmask"}, csr_wmask_o, base ^ 32'h00ff_ff00);
            `check32({prefix, " special controls"},
                     {27'd0, is_syscall_o, is_ertn_o, is_ll_o, is_sc_o, sc_success_o},
                     {27'd0, base[28], base[29], base[30], base[31], base[0]});
            `check32({prefix, " paddr"}, mem_paddr_o, base + 32'h4000_0400);
`ifdef DIFFTEST_EN
            `check32({prefix, " diff vaddr"}, diff_mem_vaddr_o, base + 32'h5000_0500);
            `check32({prefix, " diff paddr"}, diff_mem_paddr_o, base + 32'h6000_0600);
            `check32({prefix, " diff store data"}, diff_store_data_o, base + 32'h7000_0700);
`endif
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        capture = 1'b0;
        drive_payload(32'hdc00_a10c);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S10S0REG capture", 32'hdc00_a10c);

        capture = 1'b0;
        drive_payload(32'h9c00_b244);
        tick();
        #1;
        check_payload("S10S0REG hold", 32'hdc00_a10c);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S10S0REG recapture", 32'h9c00_b244);

        finish_tb();
    end
endmodule

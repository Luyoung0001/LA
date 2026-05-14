`timescale 1ns / 1ps

module s9_slot0_pipe_regs_tb;
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
    logic        is_load;
    logic        is_store;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic [31:0] addr;
    logic [31:0] store_data;
    logic [31:0] wb_data_pre;
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

    logic [31:0] pc_o;
    logic [31:0] instr_o;
    logic [1:0]  epoch_o;
    logic [4:0]  rd_o;
    logic        wb_en_o;
    logic        is_load_o;
    logic        is_store_o;
    logic [1:0]  mem_size_o;
    logic        mem_sign_ext_o;
    logic [31:0] addr_o;
    logic [31:0] store_data_o;
    logic [31:0] wb_data_pre_o;
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

    s9_slot0_pipe_regs #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .clk(clk),
        .capture_i(capture),
        .pc_i(pc),
        .instr_i(instr),
        .epoch_i(epoch),
        .rd_i(rd),
        .wb_en_i(wb_en),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .mem_size_i(mem_size),
        .mem_sign_ext_i(mem_sign_ext),
        .addr_i(addr),
        .store_data_i(store_data),
        .wb_data_pre_i(wb_data_pre),
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
        .pc_o(pc_o),
        .instr_o(instr_o),
        .epoch_o(epoch_o),
        .rd_o(rd_o),
        .wb_en_o(wb_en_o),
        .is_load_o(is_load_o),
        .is_store_o(is_store_o),
        .mem_size_o(mem_size_o),
        .mem_sign_ext_o(mem_sign_ext_o),
        .addr_o(addr_o),
        .store_data_o(store_data_o),
        .wb_data_pre_o(wb_data_pre_o),
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
        .is_ertn_o(is_ertn_o)
    );

    task automatic drive_payload;
        input [31:0] base;
        begin
            pc = base;
            instr = base ^ 32'h0a5a_9000;
            epoch = base[1:0];
            rd = base[6:2];
            wb_en = base[7];
            is_load = base[8];
            is_store = base[9];
            mem_size = base[11:10];
            mem_sign_ext = base[12];
            addr = base + 32'h1000_0100;
            store_data = base + 32'h2000_0200;
            wb_data_pre = base + 32'h3000_0300;
            exception = base[13];
            excp_ecode = base[19:14];
            excp_esubcode = base[22:14];
            excp_badv_valid = base[23];
            excp_badv = base + 32'h4000_0400;
            is_csr = base[24];
            csr_we = base[25];
            csr_xchg = base[26];
            csr_addr = base[13:0];
            csr_wdata = base + 32'h5000_0500;
            csr_wmask = base ^ 32'hffff_0000;
            is_syscall = base[27];
            is_ertn = base[28];
        end
    endtask

    task automatic check_payload;
        input string prefix;
        input [31:0] base;
        begin
            `check32({prefix, " pc"}, pc_o, base);
            `check32({prefix, " instr"}, instr_o, base ^ 32'h0a5a_9000);
            `check32({prefix, " epoch/rd/wb"},
                     {24'd0, epoch_o, rd_o, wb_en_o},
                     {24'd0, base[1:0], base[6:2], base[7]});
            `check32({prefix, " memory controls"},
                     {27'd0, is_load_o, is_store_o, mem_size_o, mem_sign_ext_o},
                     {27'd0, base[8], base[9], base[11:10], base[12]});
            `check32({prefix, " addr"}, addr_o, base + 32'h1000_0100);
            `check32({prefix, " store data"}, store_data_o, base + 32'h2000_0200);
            `check32({prefix, " wb data pre"}, wb_data_pre_o, base + 32'h3000_0300);
            `check32({prefix, " exception"},
                     {16'd0, exception_o, excp_ecode_o, excp_esubcode_o},
                     {16'd0, base[13], base[19:14], base[22:14]});
            `check32({prefix, " badv valid"}, {31'd0, excp_badv_valid_o},
                     {31'd0, base[23]});
            `check32({prefix, " badv"}, excp_badv_o, base + 32'h4000_0400);
            `check32({prefix, " csr controls"},
                     {15'd0, is_csr_o, csr_we_o, csr_xchg_o, csr_addr_o},
                     {15'd0, base[24], base[25], base[26], base[13:0]});
            `check32({prefix, " csr wdata"}, csr_wdata_o, base + 32'h5000_0500);
            `check32({prefix, " csr wmask"}, csr_wmask_o, base ^ 32'hffff_0000);
            `check32({prefix, " syscall/ertn"}, {30'd0, is_syscall_o, is_ertn_o},
                     {30'd0, base[27], base[28]});
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        capture = 1'b0;
        drive_payload(32'h1c00_9108);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S9S0REG capture", 32'h1c00_9108);

        capture = 1'b0;
        drive_payload(32'h1c00_b244);
        tick();
        #1;
        check_payload("S9S0REG hold", 32'h1c00_9108);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S9S0REG recapture", 32'h1c00_b244);

        finish_tb();
    end
endmodule

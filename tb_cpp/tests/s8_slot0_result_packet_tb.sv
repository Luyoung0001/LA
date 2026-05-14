`timescale 1ns / 1ps

module s8_slot0_result_packet_tb;
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
    logic        is_load;
    logic        is_store;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic [31:0] mem_addr;
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
    logic [31:0] mem_addr_o;
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

    s8_slot0_result_packet #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .pc_i(pc),
        .instr_i(instr),
        .epoch_i(epoch),
        .rd_i(rd),
        .wb_en_i(wb_en),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .mem_size_i(mem_size),
        .mem_sign_ext_i(mem_sign_ext),
        .mem_addr_i(mem_addr),
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
        .mem_addr_o(mem_addr_o),
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

    task automatic drive_payload(
        input logic load_flag,
        input logic store_flag,
        input logic exception_flag,
        input logic csr_flag
    );
        begin
            pc = 32'h1c00_7000;
            instr = 32'h0280_04c6;
            epoch = 2'd3;
            rd = 5'd6;
            wb_en = 1'b1;
            is_load = load_flag;
            is_store = store_flag;
            mem_size = 2'd2;
            mem_sign_ext = 1'b1;
            mem_addr = 32'h8000_0100;
            store_data = 32'hcafe_f00d;
            wb_data_pre = 32'h1234_5678;
            exception = exception_flag;
            excp_ecode = 6'h09;
            excp_esubcode = 9'h012;
            excp_badv_valid = exception_flag;
            excp_badv = 32'h8000_0102;
            is_csr = csr_flag;
            csr_we = csr_flag;
            csr_xchg = csr_flag;
            csr_addr = 14'h018;
            csr_wdata = 32'h55aa_00ff;
            csr_wmask = 32'hffff_0000;
            is_syscall = 1'b0;
            is_ertn = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_payload(1'b1, 1'b0, 1'b0, 1'b0);
        #1;
        `check32("PKT pc pass", pc_o, 32'h1c00_7000);
        `check32("PKT instr pass", instr_o, 32'h0280_04c6);
        `check32("PKT epoch pass", {30'd0, epoch_o}, 32'd3);
        `check32("PKT rd pass", {27'd0, rd_o}, 32'd6);
        `check("PKT load sideband pass", wb_en_o && is_load_o && !is_store_o);
        `check32("PKT mem control pass", {29'd0, mem_sign_ext_o, mem_size_o},
                 {29'd0, 1'b1, 2'd2});
        `check32("PKT mem addr pass", mem_addr_o, 32'h8000_0100);
        `check32("PKT store data raw pass", store_data_o, 32'hcafe_f00d);
        `check32("PKT wb data pass", wb_data_pre_o, 32'h1234_5678);
        `check("PKT no exception pass",
               !exception_o && !excp_badv_valid_o && excp_ecode_o == 6'h09);

        drive_payload(1'b0, 1'b1, 1'b1, 1'b1);
        is_syscall = 1'b1;
        is_ertn = 1'b1;
        #1;
        `check("PKT store exception csr controls pass",
               is_store_o && exception_o && is_csr_o && csr_we_o && csr_xchg_o);
        `check32("PKT exception bundle pass",
                 {17'd0, excp_esubcode_o, excp_ecode_o},
                 {17'd0, 9'h012, 6'h09});
        `check("PKT badv pass", excp_badv_valid_o && excp_badv_o == 32'h8000_0102);
        `check32("PKT csr addr pass", {18'd0, csr_addr_o}, {18'd0, 14'h018});
        `check32("PKT csr wdata pass", csr_wdata_o, 32'h55aa_00ff);
        `check32("PKT csr wmask pass", csr_wmask_o, 32'hffff_0000);
        `check("PKT syscall ertn pass", is_syscall_o && is_ertn_o);

        pc = 32'hdead_beef;
        instr = 32'hffff_ffff;
        epoch = 2'd1;
        rd = 5'd31;
        wb_en = 1'b0;
        is_load = 1'b0;
        is_store = 1'b0;
        mem_size = 2'd1;
        mem_sign_ext = 1'b0;
        mem_addr = 32'h0000_0001;
        store_data = 32'hbad0_cafe;
        wb_data_pre = 32'hface_feed;
        exception = 1'b0;
        excp_ecode = 6'h3f;
        excp_esubcode = 9'h1ff;
        excp_badv_valid = 1'b1;
        excp_badv = 32'h0bad_f00d;
        is_csr = 1'b0;
        csr_we = 1'b0;
        csr_xchg = 1'b0;
        csr_addr = 14'h3fff;
        csr_wdata = 32'haaaa_5555;
        csr_wmask = 32'h5555_aaaa;
        is_syscall = 1'b0;
        is_ertn = 1'b0;
        #1;
        `check32("PKT raw pc can pass invalid payload", pc_o, 32'hdead_beef);
        `check32("PKT raw instr can pass invalid payload", instr_o, 32'hffff_ffff);
        `check32("PKT raw control can pass invalid payload",
                 {25'd0, wb_en_o, is_load_o, is_store_o, mem_sign_ext_o, mem_size_o},
                 {25'd0, 1'b0, 1'b0, 1'b0, 1'b0, 2'd1});
        `check("PKT raw exception payload preserved",
               !exception_o && excp_badv_valid_o &&
               excp_ecode_o == 6'h3f && excp_esubcode_o == 9'h1ff);
        `check32("PKT raw CSR payload preserved", csr_wdata_o, 32'haaaa_5555);

        finish_tb();
    end
endmodule

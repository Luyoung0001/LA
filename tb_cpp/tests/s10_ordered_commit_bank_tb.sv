`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s10_ordered_commit_bank_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        slot0_commit_valid;
    logic [31:0] slot0_commit_pc;
    logic [31:0] slot0_commit_instr;
    logic        slot0_exception;
    logic        slot0_refetch;
    logic        slot1_refetch;
    logic        slot0_rf_we;
    logic [4:0]  slot0_rf_waddr;
    logic [31:0] slot0_rf_wdata;

    logic        slot0_valid;
    logic        slot0_wb_en;
    logic        slot0_load_wait;
    logic        slot0_load_uncached;
    logic [4:0]  slot0_rd;
    logic [31:0] slot0_result;

    logic        slot1_valid;
    logic        slot1_issue_valid;
    logic [3:0]  slot1_issue_class;
    logic [31:0] slot1_commit_pc;
    logic [31:0] slot1_commit_instr;
    logic        slot1_wb_en;
    logic        slot1_load_wait;
    logic [4:0]  slot1_rd;
    logic [31:0] slot1_alu_result;
    logic        slot1_rf_we_candidate;
    logic [4:0]  slot1_rf_waddr_candidate;
    logic [31:0] slot1_rf_wdata_candidate;
    logic        slot1_mem_lsu;
    logic        slot1_is_load;
    logic        slot1_is_store;

`ifdef DIFFTEST_EN
    logic [7:0]  raw_load_valid;
    logic [31:0] raw_load_paddr;
    logic [31:0] raw_load_vaddr;
    logic [7:0]  raw_store_valid;
    logic [31:0] raw_store_paddr;
    logic [31:0] raw_store_vaddr;
    logic [31:0] raw_store_data;
`endif

    logic        dual_commit_enable;
    logic        debug_unknown_inst;

    logic        commit_valid;
    logic [31:0] commit_pc;
    logic [31:0] commit_instr;
    logic        commit1_valid;
    logic [31:0] commit1_pc;
    logic [31:0] commit1_instr;

    logic        wb0_we;
    logic [4:0]  wb0_waddr;
    logic [31:0] wb0_wdata;
    logic        wb1_we;
    logic [4:0]  wb1_waddr;
    logic [31:0] wb1_wdata;

    logic        commit_event0_valid;
    logic        commit_event1_valid;
    logic        commit_event1_accept;
    logic        commit_event_dual_commit;
    logic [3:0]  commit_event_select_reason;
    logic        commit_event_wb0_we;
    logic        commit_event_wb1_we;
    logic        commit_event_dual_wb;
    logic [3:0]  commit_event_wb_reason;
    logic        commit_event_slot1_commit_held;
    logic        commit_event_slot1_wb_held;
    logic [7:0]  commit_event_reason;

    logic        fb_valid;
    logic        fb_wb_en;
    logic        fb_load_wait;
    logic        fb_load_uncached;
    logic [4:0]  fb_rd;
    logic [31:0] fb_result;
    logic        fb_slot1_issue_valid;
    logic        fb_slot1_wb_en;
    logic        fb_slot1_load_wait;
    logic [4:0]  fb_slot1_rd;
    logic [31:0] fb_slot1_result;

    logic        debug_wb_rf_wen;
    logic [4:0]  debug_wb_rf_wnum;
    logic [31:0] debug_wb_pc;
    logic [31:0] debug_wb_rf_wdata;
    logic        debug1_wb_rf_wen;
    logic [4:0]  debug1_wb_rf_wnum;
    logic [31:0] debug1_wb_pc;
    logic [31:0] debug1_wb_rf_wdata;
    logic        debug_unknown_inst_o;

`ifdef DIFFTEST_EN
    logic [7:0]  diff_commit_load_valid;
    logic [31:0] diff_commit_load_paddr;
    logic [31:0] diff_commit_load_vaddr;
    logic [7:0]  diff_commit_store_valid;
    logic [31:0] diff_commit_store_paddr;
    logic [31:0] diff_commit_store_vaddr;
    logic [31:0] diff_commit_store_data;
`endif

    s10_ordered_commit_bank u_dut (
        .slot0_commit_valid_i(slot0_commit_valid),
        .slot0_commit_pc_i(slot0_commit_pc),
        .slot0_commit_instr_i(slot0_commit_instr),
        .slot0_exception_i(slot0_exception),
        .slot0_refetch_i(slot0_refetch),
        .slot1_refetch_i(slot1_refetch),
        .slot0_rf_we_i(slot0_rf_we),
        .slot0_rf_waddr_i(slot0_rf_waddr),
        .slot0_rf_wdata_i(slot0_rf_wdata),
        .slot0_valid_i(slot0_valid),
        .slot0_wb_en_i(slot0_wb_en),
        .slot0_load_wait_i(slot0_load_wait),
        .slot0_load_uncached_i(slot0_load_uncached),
        .slot0_rd_i(slot0_rd),
        .slot0_result_i(slot0_result),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_commit_pc_i(slot1_commit_pc),
        .slot1_commit_instr_i(slot1_commit_instr),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_load_wait_i(slot1_load_wait),
        .slot1_rd_i(slot1_rd),
        .slot1_alu_result_i(slot1_alu_result),
        .slot1_rf_we_candidate_i(slot1_rf_we_candidate),
        .slot1_rf_waddr_candidate_i(slot1_rf_waddr_candidate),
        .slot1_rf_wdata_candidate_i(slot1_rf_wdata_candidate),
        .slot1_mem_lsu_i(slot1_mem_lsu),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
`ifdef DIFFTEST_EN
        .raw_load_valid_i(raw_load_valid),
        .raw_load_paddr_i(raw_load_paddr),
        .raw_load_vaddr_i(raw_load_vaddr),
        .raw_store_valid_i(raw_store_valid),
        .raw_store_paddr_i(raw_store_paddr),
        .raw_store_vaddr_i(raw_store_vaddr),
        .raw_store_data_i(raw_store_data),
`endif
        .dual_commit_enable_i(dual_commit_enable),
        .debug_unknown_inst_i(debug_unknown_inst),
        .commit_valid_o(commit_valid),
        .commit_pc_o(commit_pc),
        .commit_instr_o(commit_instr),
        .commit1_valid_o(commit1_valid),
        .commit1_pc_o(commit1_pc),
        .commit1_instr_o(commit1_instr),
        .wb0_we_o(wb0_we),
        .wb0_waddr_o(wb0_waddr),
        .wb0_wdata_o(wb0_wdata),
        .wb1_we_o(wb1_we),
        .wb1_waddr_o(wb1_waddr),
        .wb1_wdata_o(wb1_wdata),
        .commit_event0_valid_o(commit_event0_valid),
        .commit_event1_valid_o(commit_event1_valid),
        .commit_event1_accept_o(commit_event1_accept),
        .commit_event_dual_commit_o(commit_event_dual_commit),
        .commit_event_select_reason_o(commit_event_select_reason),
        .commit_event_wb0_we_o(commit_event_wb0_we),
        .commit_event_wb1_we_o(commit_event_wb1_we),
        .commit_event_dual_wb_o(commit_event_dual_wb),
        .commit_event_wb_reason_o(commit_event_wb_reason),
        .commit_event_slot1_commit_held_o(commit_event_slot1_commit_held),
        .commit_event_slot1_wb_held_o(commit_event_slot1_wb_held),
        .commit_event_reason_o(commit_event_reason),
        .fb_valid_o(fb_valid),
        .fb_wb_en_o(fb_wb_en),
        .fb_load_wait_o(fb_load_wait),
        .fb_load_uncached_o(fb_load_uncached),
        .fb_rd_o(fb_rd),
        .fb_result_o(fb_result),
        .fb_slot1_issue_valid_o(fb_slot1_issue_valid),
        .fb_slot1_wb_en_o(fb_slot1_wb_en),
        .fb_slot1_load_wait_o(fb_slot1_load_wait),
        .fb_slot1_rd_o(fb_slot1_rd),
        .fb_slot1_result_o(fb_slot1_result),
        .debug_wb_rf_wen_o(debug_wb_rf_wen),
        .debug_wb_rf_wnum_o(debug_wb_rf_wnum),
        .debug_wb_pc_o(debug_wb_pc),
        .debug_wb_rf_wdata_o(debug_wb_rf_wdata),
        .debug1_wb_rf_wen_o(debug1_wb_rf_wen),
        .debug1_wb_rf_wnum_o(debug1_wb_rf_wnum),
        .debug1_wb_pc_o(debug1_wb_pc),
        .debug1_wb_rf_wdata_o(debug1_wb_rf_wdata),
        .debug_unknown_inst_o(debug_unknown_inst_o)
`ifdef DIFFTEST_EN
        ,
        .diff_commit_load_valid_o(diff_commit_load_valid),
        .diff_commit_load_paddr_o(diff_commit_load_paddr),
        .diff_commit_load_vaddr_o(diff_commit_load_vaddr),
        .diff_commit_store_valid_o(diff_commit_store_valid),
        .diff_commit_store_paddr_o(diff_commit_store_paddr),
        .diff_commit_store_vaddr_o(diff_commit_store_vaddr),
        .diff_commit_store_data_o(diff_commit_store_data)
`endif
    );

    task automatic clear_inputs;
        begin
            slot0_commit_valid = 1'b0;
            slot0_commit_pc = 32'd0;
            slot0_commit_instr = 32'd0;
            slot0_exception = 1'b0;
            slot0_refetch = 1'b0;
            slot1_refetch = 1'b0;
            slot0_rf_we = 1'b0;
            slot0_rf_waddr = 5'd0;
            slot0_rf_wdata = 32'd0;
            slot0_valid = 1'b0;
            slot0_wb_en = 1'b0;
            slot0_load_wait = 1'b0;
            slot0_load_uncached = 1'b0;
            slot0_rd = 5'd0;
            slot0_result = 32'd0;
            slot1_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
            slot1_commit_pc = 32'd0;
            slot1_commit_instr = 32'd0;
            slot1_wb_en = 1'b0;
            slot1_load_wait = 1'b0;
            slot1_rd = 5'd0;
            slot1_alu_result = 32'd0;
            slot1_rf_we_candidate = 1'b0;
            slot1_rf_waddr_candidate = 5'd0;
            slot1_rf_wdata_candidate = 32'd0;
            slot1_mem_lsu = 1'b0;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b0;
`ifdef DIFFTEST_EN
            raw_load_valid = 8'h00;
            raw_load_paddr = 32'd0;
            raw_load_vaddr = 32'd0;
            raw_store_valid = 8'h00;
            raw_store_paddr = 32'd0;
            raw_store_vaddr = 32'd0;
            raw_store_data = 32'd0;
`endif
            dual_commit_enable = 1'b0;
            debug_unknown_inst = 1'b0;
        end
    endtask

    task automatic drive_slot0_commit(
        input [31:0] pc_i,
        input [31:0] instr_i,
        input [4:0]  rd_i,
        input [31:0] data_i
    );
        begin
            slot0_commit_valid = 1'b1;
            slot0_commit_pc = pc_i;
            slot0_commit_instr = instr_i;
            slot0_rf_we = 1'b1;
            slot0_rf_waddr = rd_i;
            slot0_rf_wdata = data_i;
            slot0_valid = 1'b1;
            slot0_wb_en = 1'b1;
            slot0_rd = rd_i;
            slot0_result = data_i;
        end
    endtask

    task automatic drive_slot1_alu_candidate(
        input [31:0] pc_i,
        input [31:0] instr_i,
        input [4:0]  rd_i,
        input [31:0] data_i
    );
        begin
            slot1_valid = 1'b1;
            slot1_issue_valid = 1'b1;
            slot1_issue_class = 4'b1000;
            slot1_commit_pc = pc_i;
            slot1_commit_instr = instr_i;
            slot1_wb_en = 1'b1;
            slot1_rd = rd_i;
            slot1_alu_result = data_i;
            slot1_rf_we_candidate = 1'b1;
            slot1_rf_waddr_candidate = rd_i;
            slot1_rf_wdata_candidate = data_i;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("OCB idle clears commit and wb",
               !commit_valid && !commit1_valid && !wb0_we && !wb1_we &&
               !commit_event0_valid && !commit_event1_valid &&
               !fb_valid && !fb_slot1_issue_valid &&
               !debug_wb_rf_wen && !debug1_wb_rf_wen);
        `check32("OCB idle clears pcs",
                 commit_pc | commit1_pc | debug_wb_pc | debug1_wb_pc, 32'd0);
`ifdef DIFFTEST_EN
        `check("OCB idle clears gated difftest memory",
               diff_commit_load_valid == 8'h00 &&
               diff_commit_store_valid == 8'h00 &&
               diff_commit_load_paddr == 32'd0 &&
               diff_commit_store_data == 32'd0);
`endif

        clear_inputs();
        drive_slot0_commit(32'h1c00_0000, 32'h0280_0001, 5'd3, 32'h0000_0033);
        #1;
        `check("OCB slot0-only commit stays single-lane",
               commit_valid && !commit1_valid && wb0_we && !wb1_we &&
               commit_event0_valid && !commit_event1_valid &&
               commit_event_wb0_we && !commit_event_wb1_we &&
               fb_valid && fb_wb_en && !fb_slot1_issue_valid &&
               debug_wb_rf_wen && !debug1_wb_rf_wen);
        `check32("OCB slot0 commit payload", commit_pc, 32'h1c00_0000);
        `check32("OCB slot0 wb payload", {27'd0, wb0_waddr}, 32'd3);
        `check32("OCB slot0 debug data", debug_wb_rf_wdata, 32'h0000_0033);

        clear_inputs();
        drive_slot0_commit(32'h1c00_0010, 32'h0280_0010, 5'd4, 32'h0000_0044);
        drive_slot1_alu_candidate(32'h1c00_0014, 32'h0280_0014, 5'd5, 32'h0000_0055);
        #1;
        `check("OCB holds slot1 candidate when dual commit is disabled",
               commit_valid && !commit1_valid && wb0_we && !wb1_we &&
               commit_event_slot1_commit_held && commit_event_slot1_wb_held &&
               !fb_slot1_issue_valid && !fb_slot1_wb_en &&
               !debug1_wb_rf_wen);
        `check32("OCB held slot1 clears visible commit1 pc", commit1_pc, 32'd0);
        `check32("OCB held slot1 clears wb1 data", wb1_wdata, 32'd0);

        clear_inputs();
        slot0_valid = 1'b1;
        slot0_commit_valid = 1'b0;
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd6;
        slot0_result = 32'h0000_0066;
        drive_slot1_alu_candidate(32'h1c00_0018, 32'h0280_0018, 5'd15, 32'h0000_1000);
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB exposes slot1 producer as pending while slot0 waits",
               !commit_valid && !commit1_valid && !wb0_we && !wb1_we &&
               fb_valid && fb_wb_en && fb_slot1_issue_valid &&
               fb_slot1_wb_en && fb_slot1_load_wait &&
               !debug_wb_rf_wen && !debug1_wb_rf_wen);
        `check32("OCB pending slot1 rd is visible for RAW hazard",
                 {27'd0, fb_slot1_rd}, 32'd15);
        `check32("OCB pending slot1 does not forward data before acceptance",
                 fb_slot1_result, 32'd0);

        clear_inputs();
        drive_slot0_commit(32'h1c00_0020, 32'h0280_0020, 5'd6, 32'h0000_0066);
        drive_slot1_alu_candidate(32'h1c00_0024, 32'h0280_0024, 5'd7, 32'h0000_0077);
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB dual-enable exposes ordered slot1 commit/wb/debug",
               commit_valid && commit1_valid &&
               wb0_we && wb1_we &&
               commit_event1_valid && commit_event1_accept &&
               commit_event_dual_commit && commit_event_dual_wb &&
               fb_slot1_issue_valid && fb_slot1_wb_en &&
               debug_wb_rf_wen && debug1_wb_rf_wen);
        `check32("OCB dual commit1 pc", commit1_pc, 32'h1c00_0024);
        `check32("OCB dual wb1 data", wb1_wdata, 32'h0000_0077);
        `check32("OCB dual feedback slot1 rd", {27'd0, fb_slot1_rd}, 32'd7);
        `check32("OCB dual debug1 data", debug1_wb_rf_wdata, 32'h0000_0077);

        clear_inputs();
        drive_slot0_commit(32'h1c00_0030, 32'h0280_0030, 5'd8, 32'h0000_0088);
        drive_slot1_alu_candidate(32'h1c00_0034, 32'h0280_0034, 5'd9, 32'h0000_0099);
        slot0_exception = 1'b1;
        slot0_rf_we = 1'b0;
        slot0_wb_en = 1'b0;
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB older slot0 exception blocks younger slot1 visibility",
               commit_valid && !commit1_valid &&
               !wb0_we && !wb1_we &&
               !commit_event1_valid && !commit_event1_accept &&
               !fb_slot1_issue_valid && !debug1_wb_rf_wen);
        `check32("OCB exception keeps slot0 commit pc", commit_pc, 32'h1c00_0030);
        `check32("OCB exception masks commit1 instr", commit1_instr, 32'd0);

`ifdef DIFFTEST_EN
        clear_inputs();
        drive_slot0_commit(32'h1c00_0040, 32'h0280_0040, 5'd10, 32'h0000_00aa);
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_commit_pc = 32'h1c00_0044;
        slot1_commit_instr = 32'h28c0_0000;
        slot1_mem_lsu = 1'b1;
        slot1_is_store = 1'b1;
        raw_store_valid = 8'h04;
        raw_store_paddr = 32'h0000_0200;
        raw_store_vaddr = 32'h4000_0200;
        raw_store_data  = 32'hdead_beef;
        #1;
        `check("OCB hides slot1 difftest store before commit1 acceptance",
               diff_commit_store_valid == 8'h00 &&
               diff_commit_store_paddr == 32'd0 &&
               diff_commit_store_data == 32'd0);

        slot1_issue_class = 4'b1000;
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB hides slot1 difftest store when class is inconsistent",
               commit1_valid && commit_event1_accept &&
               diff_commit_store_valid == 8'h00 &&
               diff_commit_store_paddr == 32'd0 &&
               diff_commit_store_data == 32'd0);

        slot1_issue_class = 4'b0010;
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB releases slot1 difftest store after ordered acceptance",
               commit1_valid && commit_event1_accept &&
               diff_commit_store_valid == 8'h04 &&
               diff_commit_store_paddr == 32'h0000_0200 &&
               diff_commit_store_vaddr == 32'h4000_0200 &&
               diff_commit_store_data == 32'hdead_beef);
        `check("OCB store commit still writes no debug lane1 RF",
               !wb1_we && !debug1_wb_rf_wen);

        clear_inputs();
        drive_slot0_commit(32'h1c00_0050, 32'h2880_0050, 5'd0, 32'h0000_0101);
        slot0_exception = 1'b1;
        slot0_rf_we = 1'b0;
        slot0_wb_en = 1'b0;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_commit_pc = 32'h1c00_0054;
        slot1_commit_instr = 32'h2980_0001;
        slot1_mem_lsu = 1'b1;
        slot1_is_store = 1'b1;
        raw_store_valid = 8'h04;
        raw_store_paddr = 32'h0000_0210;
        raw_store_vaddr = 32'h4000_0210;
        raw_store_data  = 32'hc001_d00d;
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB older slot0 exception blocks slot1 store commit event",
               commit_valid && !commit1_valid && !commit_event1_accept &&
               commit_event_select_reason == 4'h9 &&
               diff_commit_store_valid == 8'h00 &&
               diff_commit_store_paddr == 32'd0 &&
               diff_commit_store_data == 32'd0);

        clear_inputs();
        drive_slot0_commit(32'h1c00_0060, 32'h2880_0060, 5'd0, 32'h0000_0101);
        slot0_refetch = 1'b1;
        slot0_rf_we = 1'b0;
        slot0_wb_en = 1'b0;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_commit_pc = 32'h1c00_0064;
        slot1_commit_instr = 32'h2980_0002;
        slot1_mem_lsu = 1'b1;
        slot1_is_store = 1'b1;
        raw_store_valid = 8'h04;
        raw_store_paddr = 32'h0000_0214;
        raw_store_vaddr = 32'h4000_0214;
        raw_store_data  = 32'hf00d_cafe;
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB older slot0 refetch blocks slot1 store difftest visibility",
               commit_valid && !commit1_valid && !commit_event1_accept &&
               commit_event_select_reason == 4'h9 &&
               diff_commit_store_valid == 8'h00 &&
               diff_commit_store_vaddr == 32'd0 &&
               diff_commit_store_data == 32'd0);

        clear_inputs();
        drive_slot0_commit(32'h1c00_0070, 32'h2880_0070, 5'd4, 32'h0000_0104);
        slot1_refetch = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        slot1_commit_pc = 32'h1c00_0074;
        slot1_commit_instr = 32'h2980_0003;
        slot1_mem_lsu = 1'b1;
        slot1_is_store = 1'b1;
        raw_store_valid = 8'h04;
        raw_store_paddr = 32'h0000_0218;
        raw_store_vaddr = 32'h4000_0218;
        raw_store_data  = 32'h1234_abcd;
        dual_commit_enable = 1'b1;
        #1;
        `check("OCB slot1 refetch blocks slot1 store commit visibility",
               commit_valid && !commit1_valid && wb0_we && !wb1_we &&
               !commit_event1_accept && commit_event_select_reason == 4'h9 &&
               diff_commit_store_valid == 8'h00 &&
               diff_commit_store_paddr == 32'd0 &&
               diff_commit_store_data == 32'd0);
`endif

        finish_tb();
    end
endmodule

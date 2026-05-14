`timescale 1ns / 1ps
`include "cpu_defs.vh"

module fpga_pipeline_cpu_core_tb;
    localparam [31:0] RESET_PC = 32'h1c00_0000;
    localparam [31:0] SLOT1_LOAD_DATA_ADDR = 32'h0000_0100;
    localparam [31:0] SLOT1_LOAD_DATA_WORD = 32'h4bad_cafe;
    localparam [31:0] SLOT1_STORE_ADDR = 32'h0000_0200;
    localparam [31:0] SLOT1_STORE_WORD = 32'h0000_0666;
    localparam [31:0] SLOT0_LOAD_DATA_ADDR = 32'h0000_0300;
    localparam [31:0] SLOT0_LOAD_DATA_WORD = 32'h1357_9bdf;
    localparam [31:0] SLOT0_STORE_ADDR = 32'h0000_0208;
    localparam [31:0] SLOT0_STORE_WORD = 32'h0000_0099;
    localparam [31:0] SLOT1_RAW_STORE_ADDR = 32'h0000_0210;
    localparam [31:0] SLOT1_RAW_STORE_WORD = 32'h0000_0242;
    localparam [31:0] SLOT1_KILLED_STORE_ADDR = 32'h0000_0218;
    localparam [31:0] SLOT1_KILLED_STORE_WORD = 32'h0000_0001;
    localparam [31:0] SLOT1_ALE_LOAD_ADDR = 32'h0000_0101;

    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    function automatic [31:0] la_addi(input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_addi = {6'h00, 4'ha, imm, rj, rd};
    endfunction

    function automatic [31:0] la_ori(input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_ori = {6'h00, 4'he, imm, rj, rd};
    endfunction

    function automatic [31:0] la_branch(input [5:0] op31_26, input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_branch = {op31_26, imm, rj, rd};
    endfunction

    function automatic [31:0] la_bl(input [25:0] imm);
        la_bl = {6'h15, imm[15:0], imm[25:16]};
    endfunction

    function automatic [31:0] la_alu_3r(input [1:0] op21_20, input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] rk);
        la_alu_3r = {6'h00, 4'h0, op21_20, op19_15, rk, rj, rd};
    endfunction

    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_dbar();
        la_dbar = {6'h0e, 4'h1, 2'h3, 5'h04, 15'd0};
    endfunction

    function automatic [31:0] imem_word(input [31:0] addr);
        begin
            case (addr)
                RESET_PC + 32'h00: imem_word = la_addi(5'd4, 5'd0, 12'h011);
                RESET_PC + 32'h04: imem_word = la_addi(5'd5, 5'd0, 12'h022);
                RESET_PC + 32'h08: imem_word = la_addi(5'd6, 5'd0, 12'h033);
                RESET_PC + 32'h0c: imem_word = la_addi(5'd7, 5'd0, 12'h044);
                RESET_PC + 32'h10: imem_word = la_addi(5'd8, 5'd0, 12'h001);
                RESET_PC + 32'h14: imem_word = la_branch(6'h16, 5'd0, 5'd0, 16'h0004);
                RESET_PC + 32'h18: imem_word = la_addi(5'd10, 5'd0, 12'h0aa);
                RESET_PC + 32'h1c: imem_word = la_addi(5'd11, 5'd0, 12'h0bb);
                RESET_PC + 32'h20: imem_word = la_addi(5'd12, 5'd0, 12'h0cc);
                RESET_PC + 32'h24: imem_word = la_addi(5'd9, 5'd0, 12'h055);
                RESET_PC + 32'h28: imem_word = la_addi(5'd13, 5'd0, 12'h066);
                RESET_PC + 32'h2c: imem_word = la_addi(5'd13, 5'd0, 12'h007);
                RESET_PC + 32'h30: imem_word = la_addi(5'd12, 5'd0, 12'h007);
                RESET_PC + 32'h34: imem_word = la_dbar();
                RESET_PC + 32'h38: imem_word = la_ori(5'd12, 5'd0, 12'h004);
                RESET_PC + 32'h3c: imem_word = la_branch(6'h16, 5'd12, 5'd13, 16'h0004);
                RESET_PC + 32'h40: imem_word = la_addi(5'd14, 5'd0, 12'h123);
                RESET_PC + 32'h44: imem_word = la_addi(5'd15, 5'd0, 12'h456);
                RESET_PC + 32'h48: imem_word = la_addi(5'd16, 5'd0, 12'h777);
                RESET_PC + 32'h4c: imem_word = la_addi(5'd17, 5'd0, 12'h7aa);
                RESET_PC + 32'h50: imem_word = la_ori(5'd12, 5'd0, 12'h004);
                RESET_PC + 32'h54: imem_word = la_branch(6'h16, 5'd12, 5'd13, 16'h0007);
                RESET_PC + 32'h58: imem_word = la_ori(5'd12, 5'd0, 12'h005);
                RESET_PC + 32'h5c: imem_word = la_branch(6'h16, 5'd12, 5'd13, 16'h0009);
                RESET_PC + 32'h60: imem_word = la_addi(5'd18, 5'd0, 12'h222);
                RESET_PC + 32'h70: imem_word = la_addi(5'd19, 5'd0, 12'h333);
                RESET_PC + 32'h80: imem_word = la_addi(5'd20, 5'd0, 12'h444);
                RESET_PC + 32'h84: imem_word = la_addi(5'd21, 5'd0, 12'h001);
                RESET_PC + 32'h88: imem_word = la_branch(6'h16, 5'd21, 5'd21, 16'h0002);
                RESET_PC + 32'h8c: imem_word = la_mem(4'h6, 5'd21, 5'd0, SLOT1_KILLED_STORE_ADDR[11:0]);
                RESET_PC + 32'h90: imem_word = la_addi(5'd23, 5'd0, 12'h444);
                RESET_PC + 32'h94: imem_word = la_mem(4'h2, 5'd28, 5'd0, SLOT1_LOAD_DATA_ADDR[11:0]);
                RESET_PC + 32'h98: imem_word = la_addi(5'd24, 5'd0, 12'h666);
                RESET_PC + 32'h9c: imem_word = la_alu_3r(2'h1, 5'h18, 5'd26, 5'd4, 5'd5);
                RESET_PC + 32'ha0: imem_word = la_addi(5'd27, 5'd0, 12'h077);
                RESET_PC + 32'ha4: imem_word = la_bl(26'd3);
                RESET_PC + 32'ha8: imem_word = la_addi(5'd30, 5'd0, 12'h0a8);
                RESET_PC + 32'hac: imem_word = la_addi(5'd31, 5'd0, 12'h0ac);
                RESET_PC + 32'hb0: imem_word = la_addi(5'd29, 5'd0, 12'h0b0);
                RESET_PC + 32'hb4: imem_word = la_addi(5'd25, 5'd29, 12'hfe9);
                RESET_PC + 32'hb8: imem_word = la_addi(5'd30, 5'd0, 12'h0b8);
                RESET_PC + 32'hbc: imem_word = la_mem(4'h6, 5'd24, 5'd0, SLOT1_STORE_ADDR[11:0]);
                RESET_PC + 32'hc0: imem_word = la_mem(4'h2, 5'd6, 5'd0, SLOT0_LOAD_DATA_ADDR[11:0]);
                RESET_PC + 32'hc4: imem_word = la_addi(5'd7, 5'd0, 12'h778);
                RESET_PC + 32'hc8: imem_word = la_mem(4'h6, 5'd25, 5'd0, SLOT0_STORE_ADDR[11:0]);
                RESET_PC + 32'hcc: imem_word = la_addi(5'd5, 5'd0, 12'h0cc);
                RESET_PC + 32'hd0: imem_word = la_addi(5'd2, 5'd0, 12'h111);
                RESET_PC + 32'hd4: imem_word = la_addi(5'd2, 5'd0, 12'h222);
                RESET_PC + 32'hd8: imem_word = la_addi(5'd3, 5'd2, 12'h001);
                RESET_PC + 32'hdc: imem_word = la_addi(5'd31, 5'd0, 12'h0dc);
                RESET_PC + 32'he0: imem_word = la_addi(5'd10, 5'd0, 12'h123);
                RESET_PC + 32'he4: imem_word = la_addi(5'd11, 5'd10, 12'h004);
                RESET_PC + 32'he8: imem_word = la_addi(5'd31, 5'd0, 12'h0e8);
                RESET_PC + 32'hf0: imem_word = la_addi(5'd26, 5'd0, 12'h242);
                RESET_PC + 32'hf4: imem_word = la_mem(4'h6, 5'd26, 5'd0, SLOT1_RAW_STORE_ADDR[11:0]);
                RESET_PC + 32'hf8: imem_word = la_addi(5'd30, 5'd0, 12'h1a5);
                RESET_PC + 32'hfc: imem_word = la_mem(4'h2, 5'd27, 5'd0, SLOT1_ALE_LOAD_ADDR[11:0]);
                SLOT1_LOAD_DATA_ADDR: imem_word = SLOT1_LOAD_DATA_WORD;
                SLOT0_LOAD_DATA_ADDR: imem_word = SLOT0_LOAD_DATA_WORD;
                default:           imem_word = la_addi(5'd0, 5'd0, 12'h000);
            endcase
        end
    endfunction

    logic commit_valid, commit1_valid, debug_wen, debug1_wen, debug_unknown_inst;
`ifdef VERILATOR
    logic debug_excp_flush;
    logic [5:0] debug_excp_ecode;
    logic [31:0] debug_csr_estat, debug_csr_tval, debug_csr_tid;
    logic [63:0] debug_csr_timer64;
`endif
`ifdef PERF_MONI
    logic bpu_perf_valid, bpu_perf_is_branch, bpu_perf_is_jump;
    logic bpu_perf_is_ret_jirl, bpu_perf_is_indirect_jirl;
    logic [31:0] bpu_perf_pc;
    logic bpu_perf_pred_taken, bpu_perf_actual_taken;
    logic bpu_perf_correct, bpu_perf_direction_miss, bpu_perf_target_miss, bpu_perf_exu_flush;
`endif
`ifdef DIFFTEST_EN
    logic diff_commit_valid, diff_commit_wen, diff_commit1_valid, diff_commit1_wen;
    logic diff_excp_valid;
    logic [31:0] diff_commit_pc, diff_commit_instr, diff_commit_wdata;
    logic [31:0] diff_commit1_pc, diff_commit1_instr, diff_commit1_wdata;
    logic [4:0] diff_commit_wdest, diff_commit1_wdest;
    logic [7:0] diff_load_valid, diff_store_valid;
`endif
    logic [31:0] commit_pc, commit_instr, commit1_pc, commit1_instr;
    logic [31:0] debug_pc, debug_wdata, debug1_pc, debug1_wdata;
    logic [4:0] debug_wnum, debug1_wnum;
    logic [7:0] interrupt_i;
    logic arvalid, arready, rvalid, rready, rlast, awvalid, awready, wvalid, wready, wlast, bvalid, bready;
    logic [31:0] araddr, rdata, awaddr, wdata;
    logic [3:0] arid, rid, awid, wstrb, bid;
    logic [7:0] arlen, awlen;
    logic [2:0] arsize, awsize;
    logic [1:0] arburst, rresp, awburst, bresp;

    logic rd_busy_q;
    logic [31:0] rd_next_addr_q;
    logic [7:0] rd_beats_left_q;
    logic wr_aw_seen_q;
    logic wr_w_seen_q;
    logic bvalid_q;
    logic [3:0] wr_awid_q;
    logic [3:0] bid_q;
    logic slot1_store_aw_seen_q;
    logic slot1_store_w_seen_q;
    logic slot0_store_aw_seen_q;
    logic slot0_store_w_seen_q;
    logic slot1_raw_store_aw_seen_q;
    logic slot1_raw_store_w_seen_q;
    logic slot1_killed_store_aw_seen_q;
    logic slot1_killed_store_w_seen_q;

    assign arready = !rd_busy_q && !rvalid;
    assign awready = 1'b1;
    assign wready  = 1'b1;
    assign bvalid  = bvalid_q;
    assign bresp   = 2'b00;
    assign bid     = bid_q;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_busy_q       <= 1'b0;
            rd_next_addr_q  <= 32'd0;
            rd_beats_left_q <= 8'd0;
            rvalid          <= 1'b0;
            rdata           <= 32'd0;
            rresp           <= 2'b00;
            rid             <= 4'd0;
            rlast           <= 1'b0;
        end else begin
            if (rvalid && rready) begin
                if (rd_beats_left_q == 8'd0) begin
                    rd_busy_q <= 1'b0;
                    rvalid    <= 1'b0;
                    rlast     <= 1'b0;
                end else begin
                    rdata           <= imem_word(rd_next_addr_q);
                    rd_next_addr_q  <= rd_next_addr_q + 32'd4;
                    rd_beats_left_q <= rd_beats_left_q - 8'd1;
                    rlast           <= (rd_beats_left_q == 8'd1);
                end
            end

            if (!rd_busy_q && !rvalid && arvalid) begin
                rd_busy_q       <= 1'b1;
                rvalid          <= 1'b1;
                rdata           <= imem_word(araddr);
                rresp           <= 2'b00;
                rid             <= arid;
                rlast           <= (arlen == 8'd0);
                rd_next_addr_q  <= araddr + 32'd4;
                rd_beats_left_q <= arlen;
            end
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_aw_seen_q <= 1'b0;
            wr_w_seen_q  <= 1'b0;
            wr_awid_q    <= 4'd0;
            bvalid_q     <= 1'b0;
            bid_q        <= 4'd0;
            slot1_store_aw_seen_q <= 1'b0;
            slot1_store_w_seen_q  <= 1'b0;
            slot0_store_aw_seen_q <= 1'b0;
            slot0_store_w_seen_q  <= 1'b0;
            slot1_raw_store_aw_seen_q <= 1'b0;
            slot1_raw_store_w_seen_q  <= 1'b0;
            slot1_killed_store_aw_seen_q <= 1'b0;
            slot1_killed_store_w_seen_q  <= 1'b0;
        end else begin
            if (bvalid_q && bready) begin
                bvalid_q <= 1'b0;
            end

            if (awvalid && awready) begin
                wr_aw_seen_q <= 1'b1;
                wr_awid_q    <= awid;
                if (awaddr == SLOT1_STORE_ADDR) begin
                    slot1_store_aw_seen_q <= 1'b1;
                end
                if (awaddr == SLOT0_STORE_ADDR) begin
                    slot0_store_aw_seen_q <= 1'b1;
                end
                if (awaddr == SLOT1_RAW_STORE_ADDR) begin
                    slot1_raw_store_aw_seen_q <= 1'b1;
                end
                if (awaddr == SLOT1_KILLED_STORE_ADDR) begin
                    slot1_killed_store_aw_seen_q <= 1'b1;
                end
            end
            if (wvalid && wready) begin
                wr_w_seen_q <= 1'b1;
                if ((wdata == SLOT1_STORE_WORD) &&
                    (wstrb == 4'hf) && wlast) begin
                    slot1_store_w_seen_q <= 1'b1;
                end
                if ((wdata == SLOT0_STORE_WORD) &&
                    (wstrb == 4'hf) && wlast) begin
                    slot0_store_w_seen_q <= 1'b1;
                end
                if ((wdata == SLOT1_RAW_STORE_WORD) &&
                    (wstrb == 4'hf) && wlast) begin
                    slot1_raw_store_w_seen_q <= 1'b1;
                end
                if ((wdata == SLOT1_KILLED_STORE_WORD) &&
                    (wstrb == 4'hf) && wlast) begin
                    slot1_killed_store_w_seen_q <= 1'b1;
                end
            end

            if (!bvalid_q &&
                (wr_aw_seen_q || (awvalid && awready)) &&
                (wr_w_seen_q || (wvalid && wready))) begin
                wr_aw_seen_q <= 1'b0;
                wr_w_seen_q  <= 1'b0;
                bvalid_q     <= 1'b1;
                bid_q        <= (awvalid && awready) ? awid : wr_awid_q;
            end
        end
    end

    fpga_pipeline_cpu_core #(
        .CORE_DUAL_ISSUE_ENABLE(1),
        .CORE_SLOT1_CTRL_PREVIEW_ENABLE(1),
        .CORE_DUAL_COMMIT_ENABLE(1),
        .CORE_SLOT1_ALU_ENABLE(1),
        .CORE_SLOT1_BRANCH_ENABLE(1),
        .CORE_SLOT1_MUL_ENABLE(1),
        .CORE_SLOT1_LOAD_ENABLE(1),
        .CORE_SLOT1_STORE_ENABLE(1)
    ) u_dut (
        .clk(clk), .rst_n(rst_n), .interrupt_i(interrupt_i),
        .commit_valid_o(commit_valid), .commit_pc_o(commit_pc),
        .commit_instr_o(commit_instr),
        .commit1_valid_o(commit1_valid), .commit1_pc_o(commit1_pc),
        .commit1_instr_o(commit1_instr),
        .debug_wb_rf_wen(debug_wen), .debug_wb_rf_wnum(debug_wnum),
        .debug_wb_pc(debug_pc), .debug_wb_rf_wdata(debug_wdata),
        .debug1_wb_rf_wen(debug1_wen), .debug1_wb_rf_wnum(debug1_wnum),
        .debug1_wb_pc(debug1_pc), .debug1_wb_rf_wdata(debug1_wdata),
        .debug_unknown_inst(debug_unknown_inst),
`ifdef VERILATOR
        .debug_excp_flush(debug_excp_flush), .debug_excp_ecode(debug_excp_ecode),
        .debug_csr_estat(debug_csr_estat), .debug_csr_tval(debug_csr_tval),
        .debug_csr_tid(debug_csr_tid), .debug_csr_timer64(debug_csr_timer64),
`endif
`ifdef PERF_MONI
        .bpu_perf_valid_o(bpu_perf_valid), .bpu_perf_is_branch_o(bpu_perf_is_branch),
        .bpu_perf_is_jump_o(bpu_perf_is_jump), .bpu_perf_pred_taken_o(bpu_perf_pred_taken),
        .bpu_perf_is_ret_jirl_o(bpu_perf_is_ret_jirl),
        .bpu_perf_is_indirect_jirl_o(bpu_perf_is_indirect_jirl),
        .bpu_perf_pc_o(bpu_perf_pc),
        .bpu_perf_actual_taken_o(bpu_perf_actual_taken), .bpu_perf_correct_o(bpu_perf_correct),
        .bpu_perf_direction_miss_o(bpu_perf_direction_miss),
        .bpu_perf_target_miss_o(bpu_perf_target_miss),
        .bpu_perf_exu_flush_o(bpu_perf_exu_flush),
`endif
`ifdef DIFFTEST_EN
        .diff_commit_valid_o(diff_commit_valid),
        .diff_commit_pc_o(diff_commit_pc),
        .diff_commit_instr_o(diff_commit_instr),
        .diff_commit_wen_o(diff_commit_wen),
        .diff_commit_wdest_o(diff_commit_wdest),
        .diff_commit_wdata_o(diff_commit_wdata),
        .diff_commit1_valid_o(diff_commit1_valid),
        .diff_commit1_pc_o(diff_commit1_pc),
        .diff_commit1_instr_o(diff_commit1_instr),
        .diff_commit1_wen_o(diff_commit1_wen),
        .diff_commit1_wdest_o(diff_commit1_wdest),
        .diff_commit1_wdata_o(diff_commit1_wdata),
        .diff_excp_valid_o(diff_excp_valid),
        .diff_load_valid_o(diff_load_valid),
        .diff_store_valid_o(diff_store_valid),
`endif
        .axi_arvalid_o(arvalid), .axi_arready_i(arready), .axi_araddr_o(araddr), .axi_arid_o(arid),
        .axi_arlen_o(arlen), .axi_arsize_o(arsize), .axi_arburst_o(arburst),
        .axi_rvalid_i(rvalid), .axi_rready_o(rready),
        .axi_rdata_i(rdata), .axi_rresp_i(rresp), .axi_rid_i(rid), .axi_rlast_i(rlast),
        .axi_awvalid_o(awvalid), .axi_awready_i(awready), .axi_awaddr_o(awaddr), .axi_awid_o(awid),
        .axi_awlen_o(awlen), .axi_awsize_o(awsize), .axi_awburst_o(awburst),
        .axi_wvalid_o(wvalid), .axi_wready_i(wready),
        .axi_wdata_o(wdata), .axi_wstrb_o(wstrb), .axi_wlast_o(wlast), .axi_bvalid_i(bvalid),
        .axi_bready_o(bready), .axi_bresp_i(bresp), .axi_bid_i(bid)
    );

    initial begin
        integer i;
        bit saw_dual_commit;
        bit saw_slot1_branch_commit;
        bit saw_slot1_branch_target;
        bit saw_fallthrough_commit;
        bit saw_slot1_raw_branch_fallthrough;
        bit saw_slot1_raw_branch_target_early;
        bit saw_vector_chain_fallthrough;
        bit saw_vector_chain_wrong_target;
        bit saw_slot0_branch_target;
        bit saw_slot0_branch_slot1_wrong_commit;
        bit saw_slot1_mul_commit;
        bit saw_slot1_load_commit;
        bit saw_bl_commit;
        bit saw_slot1_bl_target;
        bit saw_slot1_bl_fallthrough;
        bit saw_slot1_store_commit;
        bit saw_slot1_store_early_diff_event;
        bit saw_slot0_load_slot1_alu_commit;
        bit saw_slot0_store_slot1_alu_commit;
        bit saw_waw_slot0_commit;
        bit saw_waw_promoted_commit;
        bit saw_waw_consumer_commit;
        bit saw_slot1_raw_store_slot0_commit;
        bit saw_slot1_raw_store_commit;
        bit saw_slot1_raw_store_dual_commit;
        bit saw_slot1_raw_store_early_diff_event;
        bit saw_slot1_ale_commit1;
        bit saw_slot1_ale_lane0_exception;
        bit saw_slot1_killed_store_diff_event;
        bit saw_raw_pair_dual_commit;
        bit saw_raw_slot0_commit;
        bit saw_raw_slot1_promote_commit;
        tb_start();
        interrupt_i = 8'b0;
        reset_dut();
        repeat (4) tick();
        `check("core enables conditional BPU prediction", u_dut.u_bpu.COND_PREDICT_ENABLE == 1);
        `check("core bumps BTB capacity for branch prediction", u_dut.u_bpu.BTB_INDEX_WIDTH == 10);
        `check("core uses gshare PHT indexing", u_dut.u_bpu.GSHARE_ENABLE == 1);
        `check("core can parameter-enable dual issue gate", u_dut.core_dual_issue_enable_w);
        `check("core can parameter-enable dual commit gate", u_dut.core_dual_commit_enable_w);
        `check("core routes dual issue to fetch-buffer slot consume",
               u_dut.u_fb.dual_slot_consume_i);
        `check("core dual commit elaborates two-write regfile",
               u_dut.gen_dual_write_regfiles.u_regfile.XLEN == 32);
`ifdef PERF_MONI
        `check("core BPU perf idle without memory", !bpu_perf_valid && !bpu_perf_exu_flush);
        `check("core BPU JIRL perf idle without memory", !bpu_perf_is_ret_jirl && !bpu_perf_is_indirect_jirl);
        `check32("core BPU perf PC idle reset value", bpu_perf_pc, 32'h00000000);
`endif
        saw_dual_commit = 1'b0;
        for (i = 0; i < 240 && !saw_dual_commit; i = i + 1) begin
            tick();
            saw_dual_commit = commit_valid && commit1_valid &&
                              (commit_pc == RESET_PC) &&
                              (commit1_pc == RESET_PC + 32'h4);
        end
        `check("core dual-issues independent ALU pair to ordered dual commit", saw_dual_commit);
        `check32("core slot0 dual commit PC", commit_pc, RESET_PC);
        `check32("core slot1 dual commit PC", commit1_pc, RESET_PC + 32'h4);
        `check32("core slot0 committed instr", commit_instr, la_addi(5'd4, 5'd0, 12'h011));
        `check32("core slot1 committed instr", commit1_instr, la_addi(5'd5, 5'd0, 12'h022));
        `check("core dual commit writes both debug lanes",
               debug_wen && debug1_wen && debug_wnum == 5'd4 && debug1_wnum == 5'd5);
        `check32("core slot0 debug write data", debug_wdata, 32'h0000_0011);
        `check32("core slot1 debug write data", debug1_wdata, 32'h0000_0022);
`ifdef DIFFTEST_EN
        `check("core difftest reports both dual commit lanes",
               diff_commit_valid && diff_commit1_valid);
        `check32("core difftest slot0 dual commit PC", diff_commit_pc, RESET_PC);
        `check32("core difftest slot1 dual commit PC", diff_commit1_pc, RESET_PC + 32'h4);
        `check32("core difftest slot0 dual commit instr",
                 diff_commit_instr, la_addi(5'd4, 5'd0, 12'h011));
        `check32("core difftest slot1 dual commit instr",
                 diff_commit1_instr, la_addi(5'd5, 5'd0, 12'h022));
        `check("core difftest dual commit writes both lanes",
               diff_commit_wen && diff_commit1_wen &&
               diff_commit_wdest == 5'd4 && diff_commit1_wdest == 5'd5 &&
               diff_commit_wdata == 32'h0000_0011 &&
               diff_commit1_wdata == 32'h0000_0022);
`endif

        saw_slot1_branch_commit = 1'b0;
        saw_slot1_branch_target = 1'b0;
        saw_fallthrough_commit = 1'b0;
        for (i = 0; i < 400 && !saw_slot1_branch_target; i = i + 1) begin
            tick();
            if (commit_valid &&
                ((commit_pc == RESET_PC + 32'h18) ||
                 (commit_pc == RESET_PC + 32'h1c) ||
                 (commit_pc == RESET_PC + 32'h20))) begin
                saw_fallthrough_commit = 1'b1;
            end
            if (commit1_valid &&
                ((commit1_pc == RESET_PC + 32'h18) ||
                 (commit1_pc == RESET_PC + 32'h1c) ||
                 (commit1_pc == RESET_PC + 32'h20))) begin
                saw_fallthrough_commit = 1'b1;
            end
            if (commit_valid && commit1_valid &&
                (commit_pc == RESET_PC + 32'h10) &&
                (commit1_pc == RESET_PC + 32'h14)) begin
                saw_slot1_branch_commit = 1'b1;
                `check32("core slot1 branch pair slot0 instr",
                         commit_instr, la_addi(5'd8, 5'd0, 12'h001));
                `check32("core slot1 branch pair branch instr",
                         commit1_instr, la_branch(6'h16, 5'd0, 5'd0, 16'h0004));
                `check("core slot1 branch pair writes only slot0",
                       debug_wen && !debug1_wen &&
                       debug_wnum == 5'd8 && debug_wdata == 32'h0000_0001);
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'h24)) begin
                saw_slot1_branch_target = 1'b1;
                `check32("core slot1 branch target instr",
                         commit_instr, la_addi(5'd9, 5'd0, 12'h055));
                `check("core slot1 branch target writes lane0",
                       debug_wen && debug_wnum == 5'd9 && debug_wdata == 32'h0000_0055);
            end
        end
        `check("core restricted pair allows slot1 taken branch dual commit",
               saw_slot1_branch_commit);
        `check("core slot1 taken branch redirects to target", saw_slot1_branch_target);
        `check("core slot1 taken branch flushes fall-through commits", !saw_fallthrough_commit);

        saw_slot1_raw_branch_fallthrough = 1'b0;
        saw_slot1_raw_branch_target_early = 1'b0;
        for (i = 0; i < 600 && !saw_slot1_raw_branch_fallthrough; i = i + 1) begin
            tick();
            if (!saw_slot1_raw_branch_fallthrough) begin
                if ((commit_valid && (commit_pc == RESET_PC + 32'h4c)) ||
                    (commit1_valid && (commit1_pc == RESET_PC + 32'h4c))) begin
                    saw_slot1_raw_branch_target_early = 1'b1;
                end
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'h40)) begin
                saw_slot1_raw_branch_fallthrough = 1'b1;
                `check32("core slot1 RAW branch fall-through instr",
                         commit_instr, la_addi(5'd14, 5'd0, 12'h123));
                `check("core slot1 RAW branch fall-through writes r14",
                       debug_wen && debug_wnum == 5'd14 &&
                       debug_wdata == 32'h0000_0123);
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'h40)) begin
                saw_slot1_raw_branch_fallthrough = 1'b1;
                `check32("core slot1 RAW branch fall-through instr lane1",
                         commit1_instr, la_addi(5'd14, 5'd0, 12'h123));
                `check("core slot1 RAW branch fall-through writes r14 lane1",
                       debug1_wen && debug1_wnum == 5'd14 &&
                       debug1_wdata == 32'h0000_0123);
            end
        end
        `check("core slot1 branch using slot0 result falls through",
               saw_slot1_raw_branch_fallthrough);
        `check("core slot1 branch using slot0 result does not jump early",
               !saw_slot1_raw_branch_target_early);

        saw_vector_chain_fallthrough = 1'b0;
        saw_vector_chain_wrong_target = 1'b0;
        for (i = 0; i < 800 && !saw_vector_chain_fallthrough; i = i + 1) begin
            tick();
            if ((commit_valid &&
                 ((commit_pc == RESET_PC + 32'h70) ||
                  (commit_pc == RESET_PC + 32'h80))) ||
                (commit1_valid &&
                 ((commit1_pc == RESET_PC + 32'h70) ||
                  (commit1_pc == RESET_PC + 32'h80)))) begin
                saw_vector_chain_wrong_target = 1'b1;
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'h60)) begin
                saw_vector_chain_fallthrough = 1'b1;
                `check32("core chained slot1 RAW branches fall-through instr",
                         commit_instr, la_addi(5'd18, 5'd0, 12'h222));
                `check("core chained slot1 RAW branches write marker",
                       debug_wen && debug_wnum == 5'd18 &&
                       debug_wdata == 32'h0000_0222);
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'h60)) begin
                saw_vector_chain_fallthrough = 1'b1;
                `check32("core chained slot1 RAW branches fall-through instr lane1",
                         commit1_instr, la_addi(5'd18, 5'd0, 12'h222));
                `check("core chained slot1 RAW branches write marker lane1",
                       debug1_wen && debug1_wnum == 5'd18 &&
                       debug1_wdata == 32'h0000_0222);
            end
        end
        `check("core chained slot1 RAW branches fall through",
               saw_vector_chain_fallthrough);
        `check("core chained slot1 RAW branches avoid stale target",
               !saw_vector_chain_wrong_target);

        saw_slot0_branch_target = 1'b0;
        saw_slot0_branch_slot1_wrong_commit = 1'b0;
        saw_slot1_killed_store_diff_event = 1'b0;
        saw_slot1_mul_commit = 1'b0;
        saw_slot1_load_commit = 1'b0;
        for (i = 0; i < 800 && !saw_slot0_branch_target; i = i + 1) begin
            tick();
`ifdef DIFFTEST_EN
            if (|diff_store_valid) begin
                saw_slot1_killed_store_diff_event = 1'b1;
            end
`endif
            if ((commit_valid && (commit_pc == RESET_PC + 32'h8c)) ||
                (commit1_valid && (commit1_pc == RESET_PC + 32'h8c))) begin
                saw_slot0_branch_slot1_wrong_commit = 1'b1;
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'h90)) begin
                saw_slot0_branch_target = 1'b1;
                `check32("core slot0 branch target instr lane0",
                         commit_instr, la_addi(5'd23, 5'd0, 12'h444));
                `check("core slot0 branch target writes lane0",
                       debug_wen && debug_wnum == 5'd23 &&
                       debug_wdata == 32'h0000_0444);
                if (commit1_valid && (commit1_pc == RESET_PC + 32'h94)) begin
                    saw_slot1_load_commit = 1'b1;
                    `check32("core slot1 load committed instr",
                             commit1_instr, la_mem(4'h2, 5'd28, 5'd0, SLOT1_LOAD_DATA_ADDR[11:0]));
                    `check("core slot1 load writes debug lane1",
                           debug1_wen && debug1_wnum == 5'd28 &&
                           debug1_wdata == SLOT1_LOAD_DATA_WORD);
                end
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'h90)) begin
                saw_slot0_branch_target = 1'b1;
                `check32("core slot0 branch target instr lane1",
                         commit1_instr, la_addi(5'd23, 5'd0, 12'h444));
                `check("core slot0 branch target writes lane1",
                       debug1_wen && debug1_wnum == 5'd23 &&
                       debug1_wdata == 32'h0000_0444);
            end
        end
        `check("core slot0 taken branch reaches target after pair attempt",
               saw_slot0_branch_target);
        `check("core slot0 taken branch squashes slot1 fall-through write",
               !saw_slot0_branch_slot1_wrong_commit);
        `check("core slot0 taken branch suppresses killed slot1 store AW",
               !slot1_killed_store_aw_seen_q);
        `check("core slot0 taken branch suppresses killed slot1 store W",
               !slot1_killed_store_w_seen_q);
`ifdef DIFFTEST_EN
        `check("core slot0 taken branch suppresses killed slot1 store difftest event",
               !saw_slot1_killed_store_diff_event);
`endif
        `check("core dual-issues slot1 load through shared LSU",
               saw_slot1_load_commit);

        saw_slot1_mul_commit = 1'b0;
        for (i = 0; i < 800 && !saw_slot1_mul_commit; i = i + 1) begin
            tick();
            if (commit_valid && commit1_valid &&
                (commit_pc == RESET_PC + 32'h98) &&
                (commit1_pc == RESET_PC + 32'h9c)) begin
                saw_slot1_mul_commit = 1'b1;
                `check32("core slot1 mul pair slot0 instr",
                         commit_instr, la_addi(5'd24, 5'd0, 12'h666));
                `check32("core slot1 mul committed instr",
                         commit1_instr, la_alu_3r(2'h1, 5'h18, 5'd26, 5'd4, 5'd5));
                `check("core slot1 mul writes debug lane1",
                       debug1_wen && debug1_wnum == 5'd26 &&
                       debug1_wdata == 32'h0000_0242);
            end
        end
        `check("core dual-issues slot1 mul through S10 debug lane",
               saw_slot1_mul_commit);

        saw_bl_commit = 1'b0;
        saw_slot1_bl_target = 1'b0;
        saw_slot1_bl_fallthrough = 1'b0;
        for (i = 0; i < 1000 && !saw_slot1_bl_target; i = i + 1) begin
            tick();
            if ((commit_valid &&
                 ((commit_pc == RESET_PC + 32'ha8) ||
                  (commit_pc == RESET_PC + 32'hac))) ||
                (commit1_valid &&
                 ((commit1_pc == RESET_PC + 32'ha8) ||
                  (commit1_pc == RESET_PC + 32'hac)))) begin
                saw_slot1_bl_fallthrough = 1'b1;
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'ha4)) begin
                saw_bl_commit = 1'b1;
                `check32("core BL committed instr lane0",
                         commit_instr, la_bl(26'd3));
                `check("core BL writes link in lane0",
                       debug_wen && debug_wnum == 5'd1 &&
                       debug_wdata == RESET_PC + 32'ha8);
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'ha4)) begin
                saw_bl_commit = 1'b1;
                `check32("core BL committed instr lane1",
                         commit1_instr, la_bl(26'd3));
                `check("core BL writes link in lane1",
                       debug1_wen && debug1_wnum == 5'd1 &&
                       debug1_wdata == RESET_PC + 32'ha8);
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'hb0)) begin
                saw_slot1_bl_target = 1'b1;
                `check32("core slot1 BL target instr lane0",
                         commit_instr, la_addi(5'd29, 5'd0, 12'h0b0));
                `check("core slot1 BL target writes lane0",
                       debug_wen && debug_wnum == 5'd29 &&
                       debug_wdata == 32'h0000_00b0);
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'hb0)) begin
                saw_slot1_bl_target = 1'b1;
                `check32("core slot1 BL target instr lane1",
                         commit1_instr, la_addi(5'd29, 5'd0, 12'h0b0));
                `check("core slot1 BL target writes lane1",
                       debug1_wen && debug1_wnum == 5'd29 &&
                       debug1_wdata == 32'h0000_00b0);
            end
        end
        `check("core BL commits and writes link",
               saw_bl_commit);
        `check("core BL redirects to target", saw_slot1_bl_target);
        `check("core BL flushes fall-through commits",
               !saw_slot1_bl_fallthrough);

        saw_slot1_store_commit = 1'b0;
        saw_slot1_store_early_diff_event = 1'b0;
        for (i = 0; i < 1000 &&
                    !(saw_slot1_store_commit &&
                      slot1_store_aw_seen_q &&
                      slot1_store_w_seen_q); i = i + 1) begin
            tick();
`ifdef DIFFTEST_EN
            if ((|diff_store_valid) &&
                !(commit_valid && commit1_valid &&
                  (commit_pc == RESET_PC + 32'hb8) &&
                  (commit1_pc == RESET_PC + 32'hbc))) begin
                saw_slot1_store_early_diff_event = 1'b1;
            end
`endif
            if (!saw_slot1_store_commit &&
                commit_valid && commit1_valid &&
                (commit_pc == RESET_PC + 32'hb8) &&
                (commit1_pc == RESET_PC + 32'hbc)) begin
                saw_slot1_store_commit = 1'b1;
                `check32("core slot1 store pair slot0 instr",
                         commit_instr, la_addi(5'd30, 5'd0, 12'h0b8));
                `check32("core slot1 store committed instr",
                         commit1_instr, la_mem(4'h6, 5'd24, 5'd0, SLOT1_STORE_ADDR[11:0]));
                `check("core slot1 store pair writes only slot0",
                       debug_wen && !debug1_wen &&
                       debug_wnum == 5'd30 &&
                       debug_wdata == 32'h0000_00b8);
`ifdef DIFFTEST_EN
                `check("core difftest exposes slot1 store only with commit1",
                       diff_commit_valid && diff_commit1_valid &&
                       diff_store_valid == 8'h04);
`endif
            end
        end
        `check("core dual-issues slot1 store through shared LSU",
               saw_slot1_store_commit);
`ifdef DIFFTEST_EN
        `check("core slot1 store has no early difftest store event",
               !saw_slot1_store_early_diff_event);
`endif
        `check("core slot1 store emits AXI AW for write-through",
               slot1_store_aw_seen_q);
        `check("core slot1 store emits AXI W data for write-through",
               slot1_store_w_seen_q);

        saw_slot0_load_slot1_alu_commit = 1'b0;
        for (i = 0; i < 1000 && !saw_slot0_load_slot1_alu_commit; i = i + 1) begin
            tick();
            if (commit_valid && commit1_valid &&
                (commit_pc == RESET_PC + 32'hc0) &&
                (commit1_pc == RESET_PC + 32'hc4)) begin
                saw_slot0_load_slot1_alu_commit = 1'b1;
                `check32("core slot0 load plus slot1 ALU slot0 instr",
                         commit_instr, la_mem(4'h2, 5'd6, 5'd0, SLOT0_LOAD_DATA_ADDR[11:0]));
                `check32("core slot0 load plus slot1 ALU slot1 instr",
                         commit1_instr, la_addi(5'd7, 5'd0, 12'h778));
                `check("core slot0 load plus slot1 ALU writes both lanes",
                       debug_wen && debug1_wen &&
                       debug_wnum == 5'd6 &&
                       debug1_wnum == 5'd7 &&
                       debug_wdata == SLOT0_LOAD_DATA_WORD &&
                       debug1_wdata == 32'h0000_0778);
            end
        end
        `check("core dual-issues slot0 load with independent slot1 ALU",
               saw_slot0_load_slot1_alu_commit);

        saw_slot0_store_slot1_alu_commit = 1'b0;
        for (i = 0; i < 1000 &&
                    !(saw_slot0_store_slot1_alu_commit &&
                      slot0_store_aw_seen_q &&
                      slot0_store_w_seen_q); i = i + 1) begin
            tick();
            if (!saw_slot0_store_slot1_alu_commit &&
                commit_valid && commit1_valid &&
                (commit_pc == RESET_PC + 32'hc8) &&
                (commit1_pc == RESET_PC + 32'hcc)) begin
                saw_slot0_store_slot1_alu_commit = 1'b1;
                `check32("core slot0 store plus slot1 ALU slot0 instr",
                         commit_instr, la_mem(4'h6, 5'd25, 5'd0, SLOT0_STORE_ADDR[11:0]));
                `check32("core slot0 store plus slot1 ALU slot1 instr",
                         commit1_instr, la_addi(5'd5, 5'd0, 12'h0cc));
                `check("core slot0 store plus slot1 ALU writes only slot1 RF",
                       !debug_wen && debug1_wen &&
                       debug1_wnum == 5'd5 &&
                       debug1_wdata == 32'h0000_00cc);
            end
        end
        `check("core dual-issues slot0 store with independent slot1 ALU",
               saw_slot0_store_slot1_alu_commit);
        `check("core slot0 store pair emits AXI AW for write-through",
               slot0_store_aw_seen_q);
        `check("core slot0 store pair emits AXI W data for write-through",
               slot0_store_w_seen_q);

        saw_waw_slot0_commit = 1'b0;
        saw_waw_promoted_commit = 1'b0;
        saw_waw_consumer_commit = 1'b0;
        // The registered IF2 output shifts observation timing by a cycle, so
        // keep watching until we have seen the old write, the promoted young
        // write, and the consumer commit instead of exiting on the first one.
        for (i = 0; i < 1000 &&
                    !(saw_waw_slot0_commit &&
                      saw_waw_promoted_commit &&
                      saw_waw_consumer_commit); i = i + 1) begin
            if (commit_valid && (commit_pc == RESET_PC + 32'hd0)) begin
                saw_waw_slot0_commit = 1'b1;
                `check32("core WAW pair slot0 instr",
                         commit_instr, la_addi(5'd2, 5'd0, 12'h111));
                `check("core WAW pair keeps slot1 out of same-cycle commit",
                       debug_wen && !commit1_valid && !debug1_wen &&
                       debug_wnum == 5'd2 &&
                       debug_wdata == 32'h0000_0111);
`ifdef DIFFTEST_EN
                `check("core difftest WAW pair reports only slot0 first",
                       diff_commit_valid && !diff_commit1_valid &&
                       diff_commit_wen &&
                       diff_commit_wdest == 5'd2 &&
                       diff_commit_wdata == 32'h0000_0111);
`endif
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'hd4)) begin
                saw_waw_promoted_commit = 1'b1;
                `check32("core WAW promoted slot1 instr",
                         commit_instr, la_addi(5'd2, 5'd0, 12'h222));
                `check("core WAW promoted slot1 writes younger value",
                       debug_wen && !commit1_valid && !debug1_wen &&
                       debug_wnum == 5'd2 &&
                       debug_wdata == 32'h0000_0222);
`ifdef DIFFTEST_EN
                `check("core difftest WAW promoted slot1 writes younger value",
                       diff_commit_valid && !diff_commit1_valid &&
                       diff_commit_wen &&
                       diff_commit_wdest == 5'd2 &&
                       diff_commit_wdata == 32'h0000_0222);
`endif
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'hd8)) begin
                saw_waw_consumer_commit = 1'b1;
                `check32("core WAW consumer committed instr",
                         commit_instr, la_addi(5'd3, 5'd2, 12'h001));
                `check("core WAW consumer sees younger slot1 result",
                       debug_wen && debug_wnum == 5'd3 &&
                       debug_wdata == 32'h0000_0223);
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'hd8)) begin
                saw_waw_consumer_commit = 1'b1;
                `check32("core WAW consumer committed instr lane1",
                         commit1_instr, la_addi(5'd3, 5'd2, 12'h001));
                `check("core WAW consumer sees younger slot1 result lane1",
                       debug1_wen && debug1_wnum == 5'd3 &&
                       debug1_wdata == 32'h0000_0223);
            end
            if (!(saw_waw_slot0_commit &&
                  saw_waw_promoted_commit &&
                  saw_waw_consumer_commit)) begin
                tick();
            end
        end
        `check("core WAW pair commits slot0 first",
               saw_waw_slot0_commit);
        `check("core WAW pair promotes slot1 instead of dual-committing",
               saw_waw_promoted_commit);
        `check("core regfile keeps younger slot1 result after WAW",
               saw_waw_consumer_commit);

        saw_raw_pair_dual_commit = 1'b0;
        saw_raw_slot0_commit = 1'b0;
        saw_raw_slot1_promote_commit = 1'b0;
        for (i = 0; i < 1000 && !saw_raw_slot1_promote_commit; i = i + 1) begin
            if (commit_valid && commit1_valid &&
                (commit_pc == RESET_PC + 32'he0) &&
                (commit1_pc == RESET_PC + 32'he4)) begin
                saw_raw_pair_dual_commit = 1'b1;
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'he0)) begin
                saw_raw_pair_dual_commit = 1'b1;
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'he0)) begin
                saw_raw_slot0_commit = 1'b1;
                `check32("core RAW split slot0 committed instr",
                         commit_instr, la_addi(5'd10, 5'd0, 12'h123));
                `check("core RAW split slot0 writes producer",
                       debug_wen && debug_wnum == 5'd10 &&
                       debug_wdata == 32'h0000_0123);
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'he4)) begin
                saw_raw_slot1_promote_commit = 1'b1;
                `check32("core RAW promoted slot1 committed instr",
                         commit_instr, la_addi(5'd11, 5'd10, 12'h004));
                `check("core RAW promoted slot1 sees slot0 result",
                       debug_wen && debug_wnum == 5'd11 &&
                       debug_wdata == 32'h0000_0127);
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'he4)) begin
                saw_raw_slot1_promote_commit = 1'b1;
                `check32("core RAW promoted slot1 committed instr lane1",
                         commit1_instr, la_addi(5'd11, 5'd10, 12'h004));
                `check("core RAW promoted slot1 sees slot0 result lane1",
                       debug1_wen && debug1_wnum == 5'd11 &&
                       debug1_wdata == 32'h0000_0127);
            end
            if (!saw_raw_slot1_promote_commit) begin
                tick();
            end
        end
        `check("core blocks same-packet slot0-to-slot1 RAW dual commit",
               !saw_raw_pair_dual_commit);
        `check("core commits RAW producer before promoted consumer",
               saw_raw_slot0_commit);
        `check("core promotes RAW slot1 with correct producer value",
               saw_raw_slot1_promote_commit);

        saw_slot1_raw_store_slot0_commit = 1'b0;
        saw_slot1_raw_store_commit = 1'b0;
        saw_slot1_raw_store_dual_commit = 1'b0;
        saw_slot1_raw_store_early_diff_event = 1'b0;
        for (i = 0; i < 1000 &&
                    !(saw_slot1_raw_store_slot0_commit &&
                      saw_slot1_raw_store_commit &&
                      slot1_raw_store_aw_seen_q &&
                      slot1_raw_store_w_seen_q); i = i + 1) begin
`ifdef DIFFTEST_EN
            if ((|diff_store_valid) &&
                !(commit_valid && (commit_pc == RESET_PC + 32'hf4))) begin
                saw_slot1_raw_store_early_diff_event = 1'b1;
            end
`endif
            if (commit_valid && commit1_valid &&
                (commit_pc == RESET_PC + 32'hf0) &&
                (commit1_pc == RESET_PC + 32'hf4)) begin
                saw_slot1_raw_store_dual_commit = 1'b1;
            end
            if (commit1_valid && (commit1_pc == RESET_PC + 32'hf4)) begin
                saw_slot1_raw_store_dual_commit = 1'b1;
            end
            if (commit_valid && (commit_pc == RESET_PC + 32'hf0)) begin
                saw_slot1_raw_store_slot0_commit = 1'b1;
                `check32("core slot1 RAW store split slot0 instr",
                         commit_instr, la_addi(5'd26, 5'd0, 12'h242));
                `check("core slot1 RAW store split slot0 writes producer",
                       debug_wen && debug_wnum == 5'd26 &&
                       debug_wdata == SLOT1_RAW_STORE_WORD);
            end
            if (!saw_slot1_raw_store_commit &&
                commit_valid &&
                (commit_pc == RESET_PC + 32'hf4)) begin
                saw_slot1_raw_store_commit = 1'b1;
                `check32("core slot1 RAW store promoted instr",
                         commit_instr, la_mem(4'h6, 5'd26, 5'd0, SLOT1_RAW_STORE_ADDR[11:0]));
                `check("core slot1 RAW store promoted commit writes no RF",
                       !debug_wen);
`ifdef DIFFTEST_EN
                `check("core difftest exposes promoted slot1 RAW store as lane0 store",
                       diff_commit_valid && !diff_commit1_valid &&
                       diff_store_valid == 8'h04);
`endif
            end
            if (!(saw_slot1_raw_store_slot0_commit &&
                  saw_slot1_raw_store_commit &&
                  slot1_raw_store_aw_seen_q &&
                  slot1_raw_store_w_seen_q)) begin
                tick();
            end
        end
        `check("core RAW store commits producer before promoted store",
               saw_slot1_raw_store_slot0_commit);
        `check("core blocks slot0->slot1 RAW store data dual commit",
               !saw_slot1_raw_store_dual_commit);
        `check("core promotes slot1 RAW store after producer",
               saw_slot1_raw_store_commit);
`ifdef DIFFTEST_EN
        `check("core RAW slot1 store has no early difftest store event",
               !saw_slot1_raw_store_early_diff_event);
`endif
        `check("core slot1 RAW store emits AXI AW for write-through",
               slot1_raw_store_aw_seen_q);
        `check("core slot1 RAW store emits AXI W data for write-through",
               slot1_raw_store_w_seen_q);

        saw_slot1_ale_commit1 = 1'b0;
        saw_slot1_ale_lane0_exception = 1'b0;
        for (i = 0; i < 1000 &&
                    !saw_slot1_ale_lane0_exception; i = i + 1) begin
            if (commit1_valid && (commit1_pc == RESET_PC + 32'hfc)) begin
                saw_slot1_ale_commit1 = 1'b1;
            end
            if (!saw_slot1_ale_lane0_exception &&
                commit_valid &&
                (commit_pc == RESET_PC + 32'hfc) &&
                u_dut.s10_excp_flush_w) begin
                saw_slot1_ale_lane0_exception = 1'b1;
                `check32("core refetched slot1 ALE becomes precise lane0 instr",
                         commit_instr, la_mem(4'h2, 5'd27, 5'd0, SLOT1_ALE_LOAD_ADDR[11:0]));
                `check("core refetched slot1 ALE raises lane0 ALE",
                       u_dut.s10_excp_ecode_w == `CPU_ECODE_ALE &&
                       !debug_wen && !debug1_wen && !commit1_valid);
`ifdef DIFFTEST_EN
                `check("core refetched slot1 ALE reports only difftest exception event",
                       !diff_commit_valid && !diff_commit1_valid && diff_excp_valid &&
                       diff_load_valid == 8'h00 && diff_store_valid == 8'h00);
`endif
            end
            if (!saw_slot1_ale_lane0_exception) begin
                tick();
            end
        end
        `check("core slot1 ALE never commits as lane1 before precise refetch",
               !saw_slot1_ale_commit1);
        `check("core slot1 ALE refetch reaches precise lane0 exception",
               saw_slot1_ale_lane0_exception);
        finish_tb();
    end
endmodule

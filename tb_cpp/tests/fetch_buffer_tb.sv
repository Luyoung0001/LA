`timescale 1ns / 1ps
`include "cpu_defs.vh"

module fetch_buffer_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, dual_slot_consume, wr_valid, wr_slot0_valid, wr_slot1_valid;
    logic wr_pred_taken, wr_ras_valid, wr_fault, not_full, rd_allowin;
    logic rd_valid, rd_slot0_valid, rd_slot1_valid;
    logic wr_fire, rd_fire, bypass, empty, nonempty, full;
    logic rd_pred_taken, rd_ras_valid, rd_fault;
    logic [1:0] current_epoch, wr_epoch, rd_epoch;
    logic [2:0] level;
    logic [5:0] wr_fault_ecode, rd_fault_ecode;
    logic [31:0] wr_pc, wr_pc1, wr_instr, wr_instr1, wr_pred_target, wr_ras_target, wr_fault_badv;
    logic [31:0] rd_pc, rd_pc1, rd_instr, rd_instr1, rd_pred_target, rd_ras_target, rd_fault_badv;
    fetch_buffer #(.DEPTH(4), .EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .current_epoch_i(current_epoch),
        .dual_slot_consume_i(dual_slot_consume),
        .wr_valid_i(wr_valid),
        .wr_pc_i(wr_pc), .wr_pc1_i(wr_pc1), .wr_instr_i(wr_instr), .wr_pred_taken_i(wr_pred_taken),
        .wr_slot0_valid_i(wr_slot0_valid), .wr_instr1_i(wr_instr1),
        .wr_slot1_valid_i(wr_slot1_valid), .wr_epoch_i(wr_epoch),
        .wr_pred_target_i(wr_pred_target), .wr_ras_valid_i(wr_ras_valid),
        .wr_ras_target_i(wr_ras_target), .wr_fault_i(wr_fault),
        .wr_fault_ecode_i(wr_fault_ecode), .wr_fault_badv_i(wr_fault_badv),
        .not_full_o(not_full), .wr_fire_o(wr_fire), .bypass_o(bypass),
        .rd_allowin_i(rd_allowin), .rd_valid_o(rd_valid), .rd_pc_o(rd_pc), .rd_pc1_o(rd_pc1),
        .rd_fire_o(rd_fire), .empty_o(empty), .nonempty_o(nonempty),
        .full_o(full), .level_o(level),
        .rd_instr_o(rd_instr), .rd_pred_taken_o(rd_pred_taken),
        .rd_slot0_valid_o(rd_slot0_valid), .rd_instr1_o(rd_instr1),
        .rd_slot1_valid_o(rd_slot1_valid), .rd_epoch_o(rd_epoch),
        .rd_pred_target_o(rd_pred_target), .rd_ras_valid_o(rd_ras_valid),
        .rd_ras_target_o(rd_ras_target), .rd_fault_o(rd_fault),
        .rd_fault_ecode_o(rd_fault_ecode), .rd_fault_badv_o(rd_fault_badv)
    );

    initial begin
        tb_start();
        flush = 0; dual_slot_consume = 0; wr_valid = 0; wr_pc = 0; wr_pc1 = 0; wr_instr = 0; wr_pred_taken = 0; wr_pred_target = 0; wr_ras_valid = 0; wr_ras_target = 0;
        current_epoch = 0; wr_slot0_valid = 0; wr_instr1 = 0; wr_slot1_valid = 0; wr_epoch = 0;
        wr_fault = 0; wr_fault_ecode = 0; wr_fault_badv = 0; rd_allowin = 0;
        reset_dut();
        wr_valid = 1'b1; wr_pc = 32'h0800; wr_pc1 = 32'h0804; wr_instr = 32'habcd; wr_ras_valid = 1'b1; wr_ras_target = 32'h0880;
        current_epoch = 2'd2;
        wr_slot0_valid = 1'b1; wr_instr1 = 32'h1234; wr_slot1_valid = 1'b1; wr_epoch = 2'd2;
        wr_fault = 1'b1; wr_fault_ecode = `CPU_ECODE_PIF; wr_fault_badv = 32'h4000_0800; rd_allowin = 1'b1; #1;
        `check("FetchBuffer empty fall-through valid", rd_valid);
        `check("FetchBuffer empty fall-through is bypass event",
               bypass && !wr_fire && !rd_fire && empty && !nonempty && level == 3'd0);
        `check32("FetchBuffer empty fall-through PC", rd_pc, 32'h0800);
        `check32("FetchBuffer empty fall-through slot1 PC", rd_pc1, 32'h0804);
        `check("FetchBuffer empty fall-through packet slots",
               rd_slot0_valid && rd_slot1_valid && rd_instr1 == 32'h1234 && rd_epoch == 2'd2);
        `check("FetchBuffer empty fall-through RAS", rd_ras_valid && rd_ras_target == 32'h0880);
        `check("FetchBuffer empty fall-through fault", rd_fault);
        `check32("FetchBuffer empty fall-through fault ecode", {26'd0, rd_fault_ecode}, {26'd0, `CPU_ECODE_PIF});
        `check32("FetchBuffer empty fall-through fault badv", rd_fault_badv, 32'h4000_0800);
        tick();
        wr_valid = 1'b0; rd_allowin = 1'b0; #1;
        `check("FetchBuffer fall-through does not enqueue", !rd_valid);
        `check("FetchBuffer remains empty after fall-through", empty && level == 3'd0);

        wr_fault = 1'b0; wr_fault_ecode = 0; wr_fault_badv = 0; current_epoch = 2'd1;
        wr_valid = 1'b1; wr_pc = 32'h1000; wr_pc1 = 32'h1004; wr_instr = 32'h1111;
        wr_slot0_valid = 1'b1; wr_instr1 = 32'h1112; wr_slot1_valid = 1'b0; wr_epoch = 2'd1; tick();
        wr_pc = 32'h1004; wr_pc1 = 32'h1008; wr_instr = 32'h2222;
        wr_slot0_valid = 1'b1; wr_instr1 = 32'h2223; wr_slot1_valid = 1'b1; wr_epoch = 2'd1;
        wr_fault = 1'b1; wr_fault_ecode = `CPU_ECODE_TLBR; wr_fault_badv = 32'h4000_1004; tick();
        wr_valid = 1'b0; #1;
        `check("FetchBuffer has data", rd_valid);
        `check("FetchBuffer reports queued level", nonempty && !empty && level == 3'd2);
        `check32("FetchBuffer first PC", rd_pc, 32'h1000);
        `check32("FetchBuffer first slot1 PC", rd_pc1, 32'h1004);
        `check("FetchBuffer first packet sideband", rd_slot0_valid && !rd_slot1_valid && rd_instr1 == 32'h1112 && rd_epoch == 2'd1);
        rd_allowin = 1'b1; #1;
        `check("FetchBuffer read event pops one queued packet", rd_fire && !bypass && level == 3'd2);
        tick(); rd_allowin = 1'b0; #1;
        `check("FetchBuffer level after one pop", level == 3'd1);
        `check32("FetchBuffer FIFO order", rd_instr, 32'h2222);
        `check32("FetchBuffer FIFO slot1 PC order", rd_pc1, 32'h1008);
        `check("FetchBuffer FIFO packet sideband order", rd_slot0_valid && rd_slot1_valid && rd_instr1 == 32'h2223 && rd_epoch == 2'd1);
        `check("FetchBuffer FIFO fault sideband order", rd_fault);
        `check32("FetchBuffer FIFO fault ecode", {26'd0, rd_fault_ecode}, {26'd0, `CPU_ECODE_TLBR});
        `check32("FetchBuffer FIFO fault badv", rd_fault_badv, 32'h4000_1004);

        current_epoch = 2'd3; #1;
        `check("FetchBuffer stale head auto-pops without downstream allowin",
               !rd_valid && rd_fire && level == 3'd1);
        tick(); #1;
        `check("FetchBuffer stale head removed", level == 3'd0 && !rd_valid);

        wr_valid = 1'b1; wr_pc = 32'h1800; wr_pc1 = 32'h1804; wr_instr = 32'h7777;
        wr_slot0_valid = 1'b1; wr_instr1 = 32'h0; wr_slot1_valid = 1'b0;
        wr_epoch = 2'd1; rd_allowin = 1'b1; #1;
        `check("FetchBuffer empty stale fall-through is suppressed",
               !rd_valid && !wr_fire && !rd_fire && !bypass && empty);
        tick();
        wr_epoch = 2'd3; wr_fault = 1'b0; wr_fault_ecode = 0; wr_fault_badv = 0; #1;
        `check("FetchBuffer empty matching epoch fall-through survives", rd_valid && bypass);
        tick();
        wr_valid = 1'b0; rd_allowin = 1'b0; #1;

        wr_fault = 1'b0; wr_fault_ecode = 0; wr_fault_badv = 0; current_epoch = 2'd3; wr_epoch = 2'd3;
        wr_valid = 1'b1; wr_pc = 32'h2000; wr_pc1 = 32'h2004; wr_instr = 32'h3333; tick();
        wr_pc = 32'h2004; wr_pc1 = 32'h2008; wr_instr = 32'h4444; tick();
        wr_pc = 32'h2008; wr_pc1 = 32'h200c; wr_instr = 32'h5555; tick();
        wr_pc = 32'h200c; wr_pc1 = 32'h2010; wr_instr = 32'h6666; tick();
        `check("FetchBuffer full applies backpressure", !not_full && full && level == 3'd4);
        rd_allowin = 1'b1; wr_pc = 32'h2010; wr_pc1 = 32'h2014; wr_instr = 32'h7777; #1;
        `check("FetchBuffer full accepts write while reading", not_full && wr_fire && rd_fire && full);
        tick();
        wr_valid = 1'b0;
        tick(); tick(); tick();
        rd_allowin = 1'b0; #1;
        `check32("FetchBuffer simultaneous full read/write keeps tail", rd_instr, 32'h7777);
        `check32("FetchBuffer simultaneous full read/write keeps tail slot1 PC", rd_pc1, 32'h2014);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        `check("FetchBuffer flush clears", !rd_valid);

        dual_slot_consume = 1'b1; current_epoch = 2'd1; wr_epoch = 2'd1; rd_allowin = 1'b1;
        wr_valid = 1'b1; wr_pc = 32'h3000; wr_pc1 = 32'h3004; wr_instr = 32'haaaa_0000;
        wr_slot0_valid = 1'b1; wr_instr1 = 32'haaaa_0001; wr_slot1_valid = 1'b1; #1;
        `check("FetchBuffer dual consume exposes first packet", rd_valid && bypass && rd_slot1_valid);
        tick();
        wr_pc = 32'h3004; wr_pc1 = 32'h3008; wr_instr = 32'hbbbb_0000;
        wr_instr1 = 32'hbbbb_0001; wr_slot1_valid = 1'b0; #1;
        `check("FetchBuffer dual consume drops duplicate slot1 PC",
               !rd_valid && !bypass && !wr_fire && empty && u_dut.skip_valid_q);
        tick(); wr_valid = 1'b0; #1;
        `check("FetchBuffer dual consume clears skip after duplicate",
               !rd_valid && empty && !u_dut.skip_valid_q);
        wr_valid = 1'b1; wr_pc = 32'h3008; wr_pc1 = 32'h300c; wr_instr = 32'hcccc_0000;
        wr_instr1 = 32'hcccc_0001; wr_slot1_valid = 1'b0; #1;
        `check("FetchBuffer dual consume lets later PC pass", rd_valid && bypass && rd_pc == 32'h3008);
        tick();

        flush = 1'b1; wr_valid = 1'b0; tick(); flush = 1'b0; #1;
        dual_slot_consume = 1'b1; current_epoch = 2'd2; wr_epoch = 2'd2; rd_allowin = 1'b1;
        wr_valid = 1'b1; wr_pc = 32'h4000; wr_pc1 = 32'h4004; wr_instr = 32'hdddd_0000;
        wr_instr1 = 32'hdddd_0001; wr_slot1_valid = 1'b1; #1;
        `check("FetchBuffer dual consume arms skip for missing duplicate",
               rd_valid && bypass && rd_slot1_valid);
        tick();
        wr_pc = 32'h4008; wr_pc1 = 32'h400c; wr_instr = 32'heeee_0000;
        wr_instr1 = 32'heeee_0001; wr_slot1_valid = 1'b0; #1;
        `check("FetchBuffer dual consume allows nonmatching later PC",
               rd_valid && bypass && rd_pc == 32'h4008 && u_dut.skip_valid_q);
        tick(); wr_valid = 1'b0; #1;
        `check("FetchBuffer dual consume clears stale skip on later PC",
               !rd_valid && empty && !u_dut.skip_valid_q);

        flush = 1'b1; wr_valid = 1'b0; tick(); flush = 1'b0; #1;
        dual_slot_consume = 1'b1; current_epoch = 2'd1; wr_epoch = 2'd1; rd_allowin = 1'b0;
        wr_valid = 1'b1; wr_pc = 32'h5000; wr_pc1 = 32'h5004; wr_instr = 32'hf000_0000;
        wr_instr1 = 32'hf000_0001; wr_slot1_valid = 1'b1; tick();
        wr_pc = 32'h5004; wr_pc1 = 32'h5008; wr_instr = 32'hf100_0000;
        wr_instr1 = 32'hf100_0001; wr_slot1_valid = 1'b0; tick();
        wr_valid = 1'b0; rd_allowin = 1'b1; #1;
        `check("FetchBuffer queued dual consume exposes first packet",
               rd_valid && !bypass && rd_pc == 32'h5000 && rd_slot1_valid && level == 3'd2);
        tick(); #1;
        `check("FetchBuffer queued dual consume auto-pops stored duplicate",
               !rd_valid && rd_fire && level == 3'd1 && u_dut.skip_valid_q);
        tick(); #1;
        `check("FetchBuffer queued duplicate skip drains FIFO",
               empty && !rd_valid && !u_dut.skip_valid_q);
        wr_valid = 1'b0; dual_slot_consume = 1'b0; rd_allowin = 1'b0; #1;
        finish_tb();
    end
endmodule

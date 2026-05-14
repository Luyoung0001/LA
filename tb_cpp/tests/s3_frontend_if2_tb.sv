`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s3_frontend_if2_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, in_valid, allowin, s4_allowin, out_valid, ic_req_valid, ic_req_ready;
    logic pred_taken_i, ras_valid_i, tlb_fault_i, ic_valid, ic_fault, ic_line_valid;
    logic redirect_fast_valid, redirect_fast_line_valid, redirect_fast_consume;
    logic [5:0] fault_ecode_i, fault_ecode_o;
    logic [31:0] pc_i, pred_target_i, ras_target_i, ic_instr, fault_badv_i, paddr_i, ic_req_addr;
    logic [31:0] ic_line_addr, ic_line_d0, ic_line_d1, ic_line_d2, ic_line_d3;
    logic [31:0] redirect_fast_addr, redirect_fast_instr;
    logic [31:0] redirect_fast_line_addr, redirect_fast_line_d0, redirect_fast_line_d1;
    logic [31:0] redirect_fast_line_d2, redirect_fast_line_d3;
    logic [31:0] pc_o, pc1_o, instr_o, instr1_o, pred_target_o, ras_target_o, fault_badv_o;
    logic pred_taken_o, ras_valid_o, fault_o, slot0_valid_o, slot1_valid_o;
    logic s2_dup_drop_o;
    logic dual_slot_consume;
    logic slot1_ctrl_preview_enable;
    logic [1:0] current_epoch, epoch_i, epoch_o;
    integer fill_i;
    s3_frontend_if2 #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .current_epoch_i(current_epoch),
        .dual_slot_consume_i(dual_slot_consume),
        .slot1_ctrl_preview_enable_i(slot1_ctrl_preview_enable),
        .s2_to_s3_valid(in_valid),
        .s3_allowin(allowin), .s4_allowin(s4_allowin), .s3_to_s4_valid(out_valid),
        .s2_pc_i(pc_i), .s2_epoch_i(epoch_i),
        .s2_pred_taken_i(pred_taken_i), .s2_pred_target_i(pred_target_i),
        .s2_ras_valid_i(ras_valid_i), .s2_ras_target_i(ras_target_i),
        .s2_tlb_fault_i(tlb_fault_i), .s2_fault_ecode_i(fault_ecode_i),
        .s2_fault_badv_i(fault_badv_i),
        .s2_icache_paddr_i(paddr_i), .ic_req_valid_o(ic_req_valid),
        .ic_req_ready_i(ic_req_ready), .ic_req_addr_o(ic_req_addr),
        .redirect_fast_valid_i(redirect_fast_valid),
        .redirect_fast_addr_i(redirect_fast_addr),
        .redirect_fast_instr_i(redirect_fast_instr),
        .redirect_fast_line_valid_i(redirect_fast_line_valid),
        .redirect_fast_line_addr_i(redirect_fast_line_addr),
        .redirect_fast_line_data_i_0(redirect_fast_line_d0),
        .redirect_fast_line_data_i_1(redirect_fast_line_d1),
        .redirect_fast_line_data_i_2(redirect_fast_line_d2),
        .redirect_fast_line_data_i_3(redirect_fast_line_d3),
        .redirect_fast_consume_o(redirect_fast_consume),
        .ic_resp_valid_i(ic_valid), .ic_resp_instr_i(ic_instr),
        .ic_resp_fault_i(ic_fault),
        .ic_resp_line_valid_i(ic_line_valid),
        .ic_resp_line_addr_i(ic_line_addr),
        .ic_resp_line_data_i_0(ic_line_d0),
        .ic_resp_line_data_i_1(ic_line_d1),
        .ic_resp_line_data_i_2(ic_line_d2),
        .ic_resp_line_data_i_3(ic_line_d3),
        .s3_pc_o(pc_o), .s3_pc1_o(pc1_o), .s3_instr_o(instr_o),
        .s3_slot0_valid_o(slot0_valid_o), .s3_instr1_o(instr1_o),
        .s3_slot1_valid_o(slot1_valid_o), .s3_epoch_o(epoch_o),
        .s3_pred_taken_o(pred_taken_o), .s3_pred_target_o(pred_target_o),
        .s3_ras_valid_o(ras_valid_o), .s3_ras_target_o(ras_target_o), .s3_fault_o(fault_o),
        .s3_fault_ecode_o(fault_ecode_o), .s3_fault_badv_o(fault_badv_o),
        .s2_dup_drop_o(s2_dup_drop_o)
    );

    initial begin
        tb_start();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        dual_slot_consume = 1;
        slot1_ctrl_preview_enable = 1;
        pc_i = 0; paddr_i = 0; current_epoch = 0; epoch_i = 0; pred_taken_i = 0; pred_target_i = 0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0; ic_valid = 0; ic_instr = 0; ic_fault = 0;
        ic_line_valid = 0; ic_line_addr = 0; ic_line_d0 = 0; ic_line_d1 = 0; ic_line_d2 = 0; ic_line_d3 = 0;
        redirect_fast_valid = 0; redirect_fast_addr = 0; redirect_fast_instr = 0;
        redirect_fast_line_valid = 0; redirect_fast_line_addr = 0;
        redirect_fast_line_d0 = 0; redirect_fast_line_d1 = 0;
        redirect_fast_line_d2 = 0; redirect_fast_line_d3 = 0;
        reset_dut();

        `check("S3 accepts first metadata", allowin);
        current_epoch = 2'd1; pc_i = 32'h1c001000; paddr_i = 32'h00001000; epoch_i = 2'd1;
        pred_taken_i = 1'b1; pred_target_i = 32'h1c002000; ras_valid_i = 1'b1; ras_target_i = 32'h1c003000; in_valid = 1'b1; #1;
        `check("S3 issues first ICache request", ic_req_valid && ic_req_addr == 32'h00001000);
        tick();
        in_valid = 1'b0; #1;
        `check("S3 queues metadata and waits for icache", !out_valid);

        ic_valid = 1'b1; ic_instr = 32'h02804884; ic_fault = 1'b1; #1;
        `check("S3 bypasses first response when downstream ready", out_valid);
        `check32("S3 bypass pc", pc_o, 32'h1c001000);
        `check32("S3 bypass slot1 pc preview", pc1_o, 32'h1c001004);
        `check32("S3 bypass instr", instr_o, 32'h02804884);
        `check("S3 bypass suppresses slot1 on fetch fault",
               slot0_valid_o && !slot1_valid_o && epoch_o == 2'd1);
        `check("S3 bypass prediction kept", pred_taken_o && pred_target_o == 32'h1c002000);
        `check("S3 bypass RAS kept", ras_valid_o && ras_target_o == 32'h1c003000);
        `check("S3 bypass fault OR", fault_o);
        `check32("S3 icache fault ecode is ADEF", {26'd0, fault_ecode_o}, {26'd0, `CPU_ECODE_ADEF});
        `check32("S3 icache fault badv is PC", fault_badv_o, 32'h1c001000);
        tick();
        ic_valid = 1'b0; ic_fault = 1'b0; #1;
        `check("S3 bypass does not enqueue", !out_valid);

        tick();

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; redirect_fast_valid = 0;
        current_epoch = 2'd2;
        pc_i = 32'h1c001000; paddr_i = 32'h00001000; epoch_i = 2'd2;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        in_valid = 1; #1;
        `check("S3 packet seed request issued", ic_req_valid && ic_req_addr == 32'h00001000);
        tick();
        in_valid = 0; #1;
        ic_valid = 1; ic_instr = 32'hf1000000;
        ic_line_valid = 1;
        ic_line_addr = 32'h00001000;
        ic_line_d0 = 32'hf1000000;
        ic_line_d1 = 32'hf1000001;
        ic_line_d2 = 32'hf1000002;
        ic_line_d3 = 32'hf1000003;
        #1;
        `check("S3 packet seed bypasses response", out_valid);
        `check32("S3 packet seed instr", instr_o, 32'hf1000000);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        current_epoch = 2'd3;
        pc_i = 32'h1c001004; paddr_i = 32'h00001004; epoch_i = 2'd3;
        pred_taken_i = 1; pred_target_i = 32'h1c001080;
        ras_valid_i = 1; ras_target_i = 32'h1c0010c0;
        in_valid = 1; #1;
        `check("S3 packet hit skips ICache request", !ic_req_valid);
        `check("S3 packet hit bypasses output", out_valid);
        `check32("S3 packet hit pc", pc_o, 32'h1c001004);
        `check32("S3 packet hit instr", instr_o, 32'hf1000001);
        `check("S3 packet hit suppresses slot1 for predicted-taken packet",
               slot0_valid_o && !slot1_valid_o && epoch_o == 2'd3);
        `check("S3 packet hit prediction kept", pred_taken_o && pred_target_o == 32'h1c001080);
        `check("S3 packet hit RAS kept", ras_valid_o && ras_target_o == 32'h1c0010c0);
        tick();
        in_valid = 0; #1;
        `check("S3 packet hit drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        current_epoch = 2'd1;
        pc_i = 32'h1c001200; paddr_i = 32'h00001200; epoch_i = 2'd1;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        in_valid = 1; #1;
        `check("S3 dual-slot seed request issued", ic_req_valid && ic_req_addr == 32'h00001200);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h12000000;
        ic_line_valid = 1;
        ic_line_addr = 32'h00001200;
        ic_line_d0 = 32'h12000000;
        ic_line_d1 = 32'h12000001;
        ic_line_d2 = 32'h12000002;
        ic_line_d3 = 32'h12000003;
        #1;
        `check("S3 dual-slot seed exposes slot1 preview",
               out_valid && slot0_valid_o && slot1_valid_o && epoch_o == 2'd1);
        `check32("S3 dual-slot seed instr0", instr_o, 32'h12000000);
        `check32("S3 dual-slot seed pc1", pc1_o, 32'h1c001204);
        `check32("S3 dual-slot seed instr1", instr1_o, 32'h12000001);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 dual-slot stream still emits next word singly", out_valid && slot0_valid_o);
        `check32("S3 dual-slot stream pc1", pc1_o, 32'h1c001208);
        `check32("S3 dual-slot stream instr0", instr_o, 32'h12000001);
        `check32("S3 dual-slot stream instr1", instr1_o, 32'h12000002);
        `check("S3 dual-slot stream carries slot1 preview", slot1_valid_o);
        tick(); #1;
        `check("S3 dual-slot final line word suppresses slot1 at boundary",
               out_valid && pc_o == 32'h1c001208 && slot1_valid_o);
        tick(); #1;
        `check("S3 dual-slot line tail has no slot1",
               out_valid && pc_o == 32'h1c00120c && !slot1_valid_o);
        tick(); #1;
        `check("S3 dual-slot preview drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        current_epoch = 2'd2;
        pc_i = 32'h1c001100; paddr_i = 32'h00001100; epoch_i = 2'd2;
        pred_taken_i = 1'b0; pred_target_i = 32'h0; ras_valid_i = 1'b0; ras_target_i = 32'h0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        ic_valid = 1'b1; ic_instr = 32'h11112222; ic_fault = 1'b0;
        in_valid = 1'b1; #1;
        `check("S3 same-cycle issue+resp still issues request", ic_req_valid && ic_req_addr == 32'h00001100);
        `check("S3 same-cycle issue+resp bypasses output", out_valid);
        `check32("S3 same-cycle issue+resp pc", pc_o, 32'h1c001100);
        `check32("S3 same-cycle issue+resp instr", instr_o, 32'h11112222);
        `check("S3 same-cycle issue+resp keeps epoch", epoch_o == 2'd2);
        `check("S3 same-cycle issue+resp leaves no queued output", u_dut.out_count_q == 0);
        `check("S3 same-cycle issue+resp leaves no issued count", u_dut.issued_count_q == 0);
        tick();
        in_valid = 1'b0; ic_valid = 1'b0; #1;
        `check("S3 same-cycle issue+resp drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 0;
        current_epoch = 2'd1;
        pc_i = 32'h1c002100; paddr_i = 32'h00002100; epoch_i = 2'd1;
        pred_taken_i = 1'b1; pred_target_i = 32'h1c002180; ras_valid_i = 1'b1; ras_target_i = 32'h1c0021c0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        in_valid = 1'b1; tick();
        in_valid = 1'b0;
        ic_valid = 1'b1; ic_instr = 32'h21212222; ic_fault = 1'b0;
        ic_req_ready = 1'b1; #1;
        `check("S3 pending issue same-cycle resp uses queued meta", ic_req_valid && ic_req_addr == 32'h00002100);
        `check("S3 pending issue same-cycle resp bypasses output", out_valid);
        `check32("S3 pending issue same-cycle resp pc", pc_o, 32'h1c002100);
        `check32("S3 pending issue same-cycle resp instr", instr_o, 32'h21212222);
        `check("S3 pending issue same-cycle resp keeps queued epoch", epoch_o == 2'd1);
        `check("S3 pending issue same-cycle resp keeps queued prediction", pred_taken_o && pred_target_o == 32'h1c002180);
        `check("S3 pending issue same-cycle resp keeps queued RAS", ras_valid_o && ras_target_o == 32'h1c0021c0);
        tick();
        ic_valid = 1'b0; #1;
        `check("S3 pending issue same-cycle resp drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 0;
        current_epoch = 2'd1;
        pc_i = 32'h1c002000; paddr_i = 32'h00002000; epoch_i = 2'd1; in_valid = 1; tick();
        pc_i = 32'h1c002004; paddr_i = 32'h00002004; epoch_i = 2'd1; tick();
        pc_i = 32'h1c002008; paddr_i = 32'h00002008; epoch_i = 2'd1; tick();
        in_valid = 0; #1;
        `check("S3 keeps accepting while ICache not ready", allowin);
        `check("S3 holds oldest pending ICache request", ic_req_valid && ic_req_addr == 32'h00002000);
        ic_req_ready = 1; #1;
        `check("S3 first queued request ready", ic_req_valid && ic_req_addr == 32'h00002000);
        tick(); #1;
        `check("S3 second queued request after first issue", ic_req_valid && ic_req_addr == 32'h00002004);
        tick(); #1;
        `check("S3 third queued request after second issue", ic_req_valid && ic_req_addr == 32'h00002008);
        tick(); #1;
        `check("S3 drains queued ICache requests", !ic_req_valid);

        s4_allowin = 0;
        ic_valid = 1; ic_instr = 32'hb0000000; tick();
        ic_instr = 32'hb0000001; tick();
        ic_instr = 32'hb0000002; tick();
        ic_valid = 0; #1;
        `check32("S3 queued issue pc 0", pc_o, 32'h1c002000);
        `check32("S3 queued issue instr 0", instr_o, 32'hb0000000);
        `check("S3 queued issue epoch 0", epoch_o == 2'd1);
        s4_allowin = 1;
        tick(); #1;
        `check32("S3 queued issue pc 1", pc_o, 32'h1c002004);
        `check32("S3 queued issue instr 1", instr_o, 32'hb0000001);
        `check("S3 queued issue epoch 1", epoch_o == 2'd1);
        tick(); #1;
        `check32("S3 queued issue pc 2", pc_o, 32'h1c002008);
        `check32("S3 queued issue instr 2", instr_o, 32'hb0000002);
        `check("S3 queued issue epoch 2", epoch_o == 2'd1);
        tick(); #1;
        `check("S3 queued issue output drains", !out_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd2; epoch_i = 2'd2;
        pc_i = 32'h1c002200; paddr_i = 32'h00002200; in_valid = 1; #1;
        `check("S3 stale packet first request issues", ic_req_valid && ic_req_addr == 32'h00002200);
        tick();
        pc_i = 32'h1c002204; paddr_i = 32'h00002204; #1;
        `check("S3 stale packet second request issues", ic_req_valid && ic_req_addr == 32'h00002204);
        tick();
        pc_i = 32'h1c002208; paddr_i = 32'h00002208; #1;
        `check("S3 stale packet third request issues", ic_req_valid && ic_req_addr == 32'h00002208);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'hd2000000;
        ic_line_valid = 1;
        ic_line_addr = 32'h00002200;
        ic_line_d0 = 32'hd2000000;
        ic_line_d1 = 32'hd2000001;
        ic_line_d2 = 32'hd2000002;
        ic_line_d3 = 32'h50000000;
        #1;
        `check("S3 stale packet first real response bypasses", out_valid);
        `check32("S3 stale packet first pc", pc_o, 32'h1c002200);
        `check32("S3 stale packet first instr", instr_o, 32'hd2000000);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stale packet serves issued second locally", out_valid && !ic_req_valid);
        `check32("S3 stale packet second pc", pc_o, 32'h1c002204);
        `check32("S3 stale packet second instr", instr_o, 32'hd2000001);
        tick(); #1;
        `check("S3 stale packet serves issued third locally", out_valid && !ic_req_valid);
        `check32("S3 stale packet third pc", pc_o, 32'h1c002208);
        `check32("S3 stale packet third instr", instr_o, 32'hd2000002);
        tick(); #1;
        `check("S3 stale packet records two stale responses", u_dut.stale_resp_count_q == 2);
        ic_valid = 1; ic_instr = 32'hbad0_0001;
        `check("S3 drops first stale ICache response", !out_valid);
        tick(); #1;
        ic_instr = 32'hbad0_0002;
        `check("S3 drops second stale ICache response", !out_valid);
        tick();
        ic_valid = 0; #1;
        `check("S3 stale packet drains cleanly",
               !out_valid && !ic_req_valid && u_dut.stale_resp_count_q == 0);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 0;
        ic_valid = 0; ic_fault = 0;
        redirect_fast_valid = 1; redirect_fast_addr = 32'h00003000; redirect_fast_instr = 32'hf0003000;
        current_epoch = 2'd2;
        pc_i = 32'h1c003000; paddr_i = 32'h00003000; epoch_i = 2'd2;
        pred_taken_i = 1; pred_target_i = 32'h1c003080;
        ras_valid_i = 1; ras_target_i = 32'h1c0030c0;
        tlb_fault_i = 0; in_valid = 1; #1;
        `check("S3 consumes redirect fast token", redirect_fast_consume);
        `check("S3 does not issue ICache request for fast token", !ic_req_valid);
        `check("S3 bypasses redirect fast token", out_valid);
        `check32("S3 redirect fast pc", pc_o, 32'h1c003000);
        `check32("S3 redirect fast instr", instr_o, 32'hf0003000);
        `check("S3 redirect fast keeps epoch", epoch_o == 2'd2);
        `check("S3 redirect fast prediction kept", pred_taken_o && pred_target_o == 32'h1c003080);
        `check("S3 redirect fast RAS kept", ras_valid_o && ras_target_o == 32'h1c0030c0);
        `check("S3 redirect fast has no fetch fault", !fault_o && fault_ecode_o == 6'd0);
        tick();
        in_valid = 0; redirect_fast_valid = 0; #1;
        `check("S3 redirect fast bypass does not leave queued output", !out_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 0; ic_req_ready = 0;
        redirect_fast_valid = 1; redirect_fast_addr = 32'h00004000; redirect_fast_instr = 32'hf0004000;
        current_epoch = 2'd3;
        pc_i = 32'h1c004000; paddr_i = 32'h00004000; epoch_i = 2'd3;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0; tlb_fault_i = 0;
        in_valid = 1; tick();
        in_valid = 0; redirect_fast_valid = 0; #1;
        `check("S3 queues redirect fast token while downstream stalls", out_valid);
        `check32("S3 queued redirect fast pc", pc_o, 32'h1c004000);
        `check32("S3 queued redirect fast instr", instr_o, 32'hf0004000);
        `check("S3 queued redirect fast keeps epoch", epoch_o == 2'd3);
        `check("S3 queued redirect fast skipped ICache request", !ic_req_valid);
        s4_allowin = 1; tick(); #1;
        `check("S3 queued redirect fast drains", !out_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 0;
        ic_valid = 0; ic_fault = 0; redirect_fast_valid = 0;
        current_epoch = 2'd1;
        pc_i = 32'h1c005000; paddr_i = 32'h00005000; epoch_i = 2'd1;
        pred_taken_i = 1; pred_target_i = 32'h1c005080;
        ras_valid_i = 1; ras_target_i = 32'h1c0050c0; tlb_fault_i = 0;
        in_valid = 1; tick();
        in_valid = 0; #1;
        `check("S3 holds delayed-fast target as pending request",
               ic_req_valid && ic_req_addr == 32'h00005000);
        redirect_fast_valid = 1;
        redirect_fast_addr = 32'h00005000;
        redirect_fast_instr = 32'hf0005000;
        #1;
        `check("S3 consumes delayed fast token for pending head", redirect_fast_consume);
        `check("S3 suppresses ICache request for delayed fast head", !ic_req_valid);
        `check("S3 bypasses delayed fast head", out_valid);
        `check32("S3 delayed fast head pc", pc_o, 32'h1c005000);
        `check32("S3 delayed fast head instr", instr_o, 32'hf0005000);
        `check("S3 delayed fast head keeps epoch", epoch_o == 2'd1);
        `check("S3 delayed fast head prediction kept", pred_taken_o && pred_target_o == 32'h1c005080);
        `check("S3 delayed fast head RAS kept", ras_valid_o && ras_target_o == 32'h1c0050c0);
        tick();
        redirect_fast_valid = 0; #1;
        `check("S3 delayed fast head drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 0;
        ic_valid = 0; ic_fault = 0; redirect_fast_valid = 0;
        current_epoch = 2'd2;
        pc_i = 32'h1c006004; paddr_i = 32'h00006004; epoch_i = 2'd2;
        pred_taken_i = 0; pred_target_i = 32'h0;
        ras_valid_i = 0; ras_target_i = 32'h0; tlb_fault_i = 0;
        in_valid = 1; tick();
        in_valid = 0; #1;
        redirect_fast_valid = 1;
        redirect_fast_addr = 32'h00006004;
        redirect_fast_instr = 32'hf0006001;
        redirect_fast_line_valid = 1;
        redirect_fast_line_addr = 32'h00006000;
        redirect_fast_line_d0 = 32'hf0006000;
        redirect_fast_line_d1 = 32'hf0006001;
        redirect_fast_line_d2 = 32'hf0006002;
        redirect_fast_line_d3 = 32'hf0006003;
        #1;
        `check("S3 consumes delayed fast packet", redirect_fast_consume);
        `check("S3 delayed fast packet bypasses head", out_valid);
        `check32("S3 delayed fast packet head instr", instr_o, 32'hf0006001);
        `check("S3 delayed fast packet head keeps epoch", epoch_o == 2'd2);
        tick();
        redirect_fast_valid = 0; redirect_fast_line_valid = 0; #1;
        current_epoch = 2'd3;
        pc_i = 32'h1c006008; paddr_i = 32'h00006008; epoch_i = 2'd3;
        pred_taken_i = 1; pred_target_i = 32'h1c006080;
        in_valid = 1; #1;
        `check("S3 delayed fast packet serves next word", out_valid && !ic_req_valid);
        `check32("S3 delayed fast packet next pc", pc_o, 32'h1c006008);
        `check32("S3 delayed fast packet next instr", instr_o, 32'hf0006002);
        `check("S3 delayed fast packet next keeps epoch", epoch_o == 2'd3);
        `check("S3 delayed fast packet keeps next prediction",
               pred_taken_o && pred_target_o == 32'h1c006080);
        tick();
        in_valid = 0; #1;
        `check("S3 delayed fast packet drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; redirect_fast_valid = 0;
        current_epoch = 2'd1;
        pc_i = 32'h1c007100; paddr_i = 32'h00007100; epoch_i = 2'd1;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        in_valid = 1; #1;
        `check("S3 packet append seed issues request", ic_req_valid && ic_req_addr == 32'h00007100);
        tick();
        in_valid = 0; s4_allowin = 0;
        ic_valid = 1; ic_instr = 32'h71000000;
        ic_line_valid = 1;
        ic_line_addr = 32'h00007100;
        ic_line_d0 = 32'h71000000;
        ic_line_d1 = 32'h71000001;
        ic_line_d2 = 32'h71000002;
        ic_line_d3 = 32'h71000003;
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 packet append keeps seed output queued", out_valid && u_dut.out_count_q == 1);
        pc_i = 32'h1c007104; paddr_i = 32'h00007104; epoch_i = 2'd1;
        pred_taken_i = 1; pred_target_i = 32'h1c007180;
        in_valid = 1; #1;
        `check("S3 packet append uses packet despite queued output", out_valid && !ic_req_valid);
        `check("S3 packet append does not bypass while downstream stalled", u_dut.out_count_q == 1);
        tick();
        in_valid = 0; #1;
        `check("S3 packet append queued second output", u_dut.out_count_q == 2);
        s4_allowin = 1; #1;
        `check32("S3 packet append first pc", pc_o, 32'h1c007100);
        `check32("S3 packet append first instr", instr_o, 32'h71000000);
        `check("S3 packet append first epoch", epoch_o == 2'd1);
        tick(); #1;
        `check32("S3 packet append second pc", pc_o, 32'h1c007104);
        `check32("S3 packet append second instr", instr_o, 32'h71000001);
        `check("S3 packet append second epoch", epoch_o == 2'd1);
        `check("S3 packet append keeps second prediction",
               pred_taken_o && pred_target_o == 32'h1c007180);
        tick(); #1;
        `check("S3 packet append drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd3;
        pc_i = 32'h1c008100; paddr_i = 32'h00008100; epoch_i = 2'd3;
        in_valid = 1; #1;
        `check("S3 stream seed issues request", ic_req_valid && ic_req_addr == 32'h00008100);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h81000000;
        ic_line_valid = 1; ic_line_addr = 32'h00008100;
        ic_line_d0 = 32'h81000000;
        ic_line_d1 = 32'h81000001;
        ic_line_d2 = 32'h81000002;
        ic_line_d3 = 32'h81000003;
        #1;
        `check("S3 stream seed bypasses response", out_valid);
        `check32("S3 stream seed instr", instr_o, 32'h81000000);
        `check("S3 stream seed epoch", epoch_o == 2'd3);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stream emits next word without S2 input", out_valid && !ic_req_valid);
        `check32("S3 stream next pc", pc_o, 32'h1c008104);
        `check32("S3 stream next instr", instr_o, 32'h81000001);
        `check("S3 stream next keeps epoch", epoch_o == 2'd3);
        tick(); #1;
        `check("S3 stream emits second next word without S2 input", out_valid && !ic_req_valid);
        `check32("S3 stream second next pc", pc_o, 32'h1c008108);
        `check32("S3 stream second next instr", instr_o, 32'h81000002);
        `check("S3 stream second keeps epoch", epoch_o == 2'd3);
        tick(); #1;
        `check("S3 stream emits third next word without S2 input", out_valid && !ic_req_valid);
        `check32("S3 stream third next pc", pc_o, 32'h1c00810c);
        `check32("S3 stream third next instr", instr_o, 32'h81000003);
        `check("S3 stream third keeps epoch", epoch_o == 2'd3);
        tick(); #1;
        `check("S3 stream stops at line boundary", !out_valid && !ic_req_valid);
        pc_i = 32'h1c008104; paddr_i = 32'h00008104;
        in_valid = 1; #1;
        `check("S3 stream drops first duplicate S2 metadata", allowin && !ic_req_valid && !out_valid);
        tick();
        pc_i = 32'h1c008108; paddr_i = 32'h00008108; #1;
        `check("S3 stream drops second duplicate S2 metadata", allowin && !ic_req_valid && !out_valid);
        tick();
        pc_i = 32'h1c00810c; paddr_i = 32'h0000810c; #1;
        `check("S3 stream drops third duplicate S2 metadata", allowin && !ic_req_valid && !out_valid);
        tick();
        in_valid = 0; #1;
        `check("S3 stream duplicate drop drains cleanly", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        pc_i = 32'h1c008200; paddr_i = 32'h00008200;
        in_valid = 1; #1;
        `check("S3 stream control seed issues request", ic_req_valid && ic_req_addr == 32'h00008200);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h82000000;
        ic_line_valid = 1; ic_line_addr = 32'h00008200;
        ic_line_d0 = 32'h82000000;
        ic_line_d1 = 32'h50000000; // b 0, stream must stop before control flow.
        ic_line_d2 = 32'h82000002;
        ic_line_d3 = 32'h82000003;
        #1;
        `check("S3 stream control seed bypasses response", out_valid);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stream does not pre-emit control instruction", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        pc_i = 32'h1c008300; paddr_i = 32'h00008300;
        in_valid = 1; #1;
        `check("S3 slot1 conditional branch seed issues request", ic_req_valid && ic_req_addr == 32'h00008300);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h83000000;
        ic_line_valid = 1; ic_line_addr = 32'h00008300;
        ic_line_d0 = 32'h83000000;
        ic_line_d1 = {6'h16, 16'h0004, 5'd2, 5'd1}; // beq r1,r2,+16 may issue as slot1.
        ic_line_d2 = 32'h83000002;
        ic_line_d3 = 32'h83000003;
        #1;
        `check("S3 allows conditional branch in slot1 preview",
               out_valid && slot0_valid_o && slot1_valid_o);
        `check32("S3 slot1 conditional branch instr1", instr1_o, {6'h16, 16'h0004, 5'd2, 5'd1});
        `check("S3 does not arm duplicate drop on seed slot0", !s2_dup_drop_o);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stream stops after slot1 conditional branch", !out_valid && !ic_req_valid);
        pc_i = 32'h1c008304; paddr_i = 32'h00008304; epoch_i = 2'd0;
        pred_taken_i = 1; pred_target_i = 32'h1c009000;
        in_valid = 1; #1;
        `check("S3 drops duplicated slot1 branch metadata with sideband",
               allowin && !out_valid && !ic_req_valid && s2_dup_drop_o);
        `check("S3 raises duplicate-drop sideband for slot1 branch duplicate", s2_dup_drop_o);
        tick();
        in_valid = 0; pred_taken_i = 0; pred_target_i = 32'h0; #1;
        `check("S3 clears duplicate-drop sideband after branch duplicate consumed", !s2_dup_drop_o);

        reset_dut();
        dual_slot_consume = 0;
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        pc_i = 32'h1c008500; paddr_i = 32'h00008500;
        in_valid = 1; #1;
        `check("S3 single-consume mode still seeds conditional slot1 packet",
               ic_req_valid && ic_req_addr == 32'h00008500);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h85000000;
        ic_line_valid = 1; ic_line_addr = 32'h00008500;
        ic_line_d0 = 32'h85000000;
        ic_line_d1 = {6'h16, 16'h0004, 5'd2, 5'd1};
        ic_line_d2 = 32'h85000002;
        ic_line_d3 = 32'h85000003;
        #1;
        `check("S3 single-consume mode disables slot1 branch preview",
               out_valid && slot0_valid_o && !slot1_valid_o);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        pc_i = 32'h1c008504; paddr_i = 32'h00008504; epoch_i = 2'd0;
        pred_taken_i = 1; pred_target_i = 32'h1c009400;
        in_valid = 1; #1;
        `check("S3 single-consume mode must not dup-drop slot1 branch metadata",
               allowin && !s2_dup_drop_o && (ic_req_valid || out_valid));
        tick();
        in_valid = 0; pred_taken_i = 0; pred_target_i = 32'h0;
        dual_slot_consume = 1;
        #1;

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        pc_i = 32'h1c008400; paddr_i = 32'h00008400;
        in_valid = 1; #1;
        `check("S3 slot1 B seed issues request", ic_req_valid && ic_req_addr == 32'h00008400);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h84000000;
        ic_line_valid = 1; ic_line_addr = 32'h00008400;
        ic_line_d0 = 32'h84000000;
        ic_line_d1 = 32'h50000000; // b 0 is not allowed in slot1 without BPU/RAS metadata.
        ic_line_d2 = 32'h84000002;
        ic_line_d3 = 32'h84000003;
        #1;
        `check("S3 still blocks unconditional branch in slot1 preview",
               out_valid && slot0_valid_o && !slot1_valid_o);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stream stops before slot1 unconditional branch", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        pc_i = 32'h1c008600; paddr_i = 32'h00008600;
        in_valid = 1; #1;
        `check("S3 slot1 BL seed issues request", ic_req_valid && ic_req_addr == 32'h00008600);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h86000000;
        ic_line_valid = 1; ic_line_addr = 32'h00008600;
        ic_line_d0 = 32'h86000000;
        ic_line_d1 = 32'h54000000; // bl 0 must stay slot0-predicted, not slot1-previewed.
        ic_line_d2 = 32'h86000002;
        ic_line_d3 = 32'h86000003;
        #1;
        `check("S3 still blocks BL in slot1 preview",
               out_valid && slot0_valid_o && !slot1_valid_o);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stream stops before slot1 BL", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        pc_i = 32'h1c008700; paddr_i = 32'h00008700;
        in_valid = 1; #1;
        `check("S3 slot1 JIRL seed issues request", ic_req_valid && ic_req_addr == 32'h00008700);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h87000000;
        ic_line_valid = 1; ic_line_addr = 32'h00008700;
        ic_line_d0 = 32'h87000000;
        ic_line_d1 = {6'h13, 16'h0000, 5'd1, 5'd0}; // ret-like jirl still needs slot0 BPU/RAS metadata.
        ic_line_d2 = 32'h87000002;
        ic_line_d3 = 32'h87000003;
        #1;
        `check("S3 still blocks JIRL in slot1 preview",
               out_valid && slot0_valid_o && !slot1_valid_o);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stream stops before slot1 JIRL", !out_valid && !ic_req_valid);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd2; epoch_i = 2'd1;
        pc_i = 32'h1c009000; paddr_i = 32'h00009000; in_valid = 1; #1;
        `check("S3 drops stale incoming epoch without ICache request",
               allowin && !ic_req_valid && !out_valid);
        tick();
        in_valid = 0; #1;
        `check("S3 stale incoming epoch does not allocate queues",
               u_dut.meta_count_q == 0 && u_dut.out_count_q == 0);

        reset_dut();
        flush = 0; in_valid = 1; s4_allowin = 0; ic_req_ready = 1;
        ic_valid = 1; ic_fault = 0; redirect_fast_valid = 0;
        current_epoch = 2'd1; epoch_i = 2'd1;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        pc_i = 32'h1c009100; paddr_i = 32'h00009100; ic_instr = 32'h91000000; tick();
        pc_i = 32'h1c009104; paddr_i = 32'h00009104; ic_instr = 32'h91000001; tick();
        in_valid = 0; ic_valid = 0; #1;
        `check("S3 queued current epoch outputs before epoch switch", out_valid && u_dut.out_count_q == 2);
        current_epoch = 2'd2; #1;
        `check("S3 hides stale out head and schedules pop", !out_valid && u_dut.out_count_q == 2);
        tick(); #1;
        `check("S3 auto-pops first stale out entry", !out_valid && u_dut.out_count_q == 1);
        tick(); #1;
        `check("S3 auto-pops second stale out entry", !out_valid && u_dut.out_count_q == 0);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 1; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0; ic_line_valid = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd3; epoch_i = 2'd3;
        pc_i = 32'h1c009200; paddr_i = 32'h00009200; in_valid = 1; #1;
        `check("S3 stale stream seed issues request", ic_req_valid && ic_req_addr == 32'h00009200);
        tick();
        in_valid = 0;
        ic_valid = 1; ic_instr = 32'h92000000;
        ic_line_valid = 1; ic_line_addr = 32'h00009200;
        ic_line_d0 = 32'h92000000;
        ic_line_d1 = 32'h92000001;
        ic_line_d2 = 32'h92000002;
        ic_line_d3 = 32'h92000003;
        #1;
        `check("S3 stale stream seed bypasses response", out_valid);
        tick();
        ic_valid = 0; ic_line_valid = 0; #1;
        `check("S3 stale stream can emit before epoch switch", out_valid && epoch_o == 2'd3);
        current_epoch = 2'd0; #1;
        `check("S3 suppresses stale stream after epoch switch", !out_valid && u_dut.stream_valid_q);
        tick(); #1;
        `check("S3 clears stale stream state", !out_valid && !u_dut.stream_valid_q);

        reset_dut();
        flush = 0; in_valid = 0; s4_allowin = 0; ic_req_ready = 1;
        ic_valid = 0; ic_fault = 0;
        s4_allowin = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        pc_i = 32'h1c001004; paddr_i = 32'h00001004; pred_taken_i = 0; pred_target_i = 32'h0; tlb_fault_i = 0; in_valid = 1; tick();
        pc_i = 32'h1c001008; paddr_i = 32'h00001008; pred_taken_i = 1; pred_target_i = 32'h1c001080; ras_valid_i = 1; ras_target_i = 32'h1c0010c0; tlb_fault_i = 0; tick();
        pc_i = 32'h1c00100c; paddr_i = 32'h0000100c; pred_taken_i = 0; pred_target_i = 32'h0; tlb_fault_i = 1;
        fault_ecode_i = `CPU_ECODE_TLBR; fault_badv_i = 32'h4000_1000; tick();
        in_valid = 0; #1;
        `check("S3 keeps accepting multiple outstanding requests", allowin);

        ic_valid = 1; ic_instr = 32'ha0000001; ic_fault = 0; tick();
        ic_instr = 32'ha0000002; tick();
        ic_instr = 32'ha0000003; ic_fault = 1; tick();
        ic_valid = 0; ic_fault = 0; #1;
        `check("S3 holds returned queue when fetch buffer stalls", out_valid);
        `check32("S3 ordered pc 0", pc_o, 32'h1c001004);
        `check32("S3 ordered instr 0", instr_o, 32'ha0000001);

        s4_allowin = 1; tick(); #1;
        `check32("S3 ordered pc 1", pc_o, 32'h1c001008);
        `check32("S3 ordered instr 1", instr_o, 32'ha0000002);
        `check("S3 ordered prediction 1", pred_taken_o && pred_target_o == 32'h1c001080);
        `check("S3 ordered RAS 1", ras_valid_o && ras_target_o == 32'h1c0010c0);

        tick(); #1;
        `check32("S3 ordered pc 2", pc_o, 32'h1c00100c);
        `check32("S3 ordered instr 2", instr_o, 32'ha0000003);
        `check("S3 ordered fault 2", fault_o);
        `check32("S3 ordered fault keeps TLB ecode priority", {26'd0, fault_ecode_o}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S3 ordered fault keeps TLB badv", fault_badv_o, 32'h4000_1000);

        reset_dut();
        flush = 0; in_valid = 1; s4_allowin = 0; ic_req_ready = 1;
        ic_valid = 1; ic_fault = 0; redirect_fast_valid = 0;
        pred_taken_i = 0; pred_target_i = 32'h0; ras_valid_i = 0; ras_target_i = 0;
        tlb_fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        current_epoch = 2'd0; epoch_i = 2'd0;
        for (fill_i = 0; fill_i < 8; fill_i = fill_i + 1) begin
            pc_i = 32'h1c007000 + (fill_i << 2);
            paddr_i = 32'h00007000 + (fill_i << 2);
            ic_instr = 32'hc0000000 + fill_i;
            tick();
        end
        in_valid = 0; ic_valid = 0; #1;
        `check("S3 output FIFO is full", u_dut.out_count_q == 8 && !allowin);
        s4_allowin = 1;
        in_valid = 1;
        pc_i = 32'h1c007020; paddr_i = 32'h00007020;
        #1;
        `check("S3 accepts new metadata while full output pops", allowin);
        `check("S3 issues accepted metadata during full pop", ic_req_valid && ic_req_addr == 32'h00007020);
        `check32("S3 full-pop keeps oldest output pc", pc_o, 32'h1c007000);
        `check32("S3 full-pop keeps oldest output instr", instr_o, 32'hc0000000);
        tick();
        in_valid = 0; #1;
        `check("S3 full-pop keeps total occupancy bounded",
               (u_dut.meta_count_q + u_dut.out_count_q) == 8);

        finish_tb();
    end
endmodule

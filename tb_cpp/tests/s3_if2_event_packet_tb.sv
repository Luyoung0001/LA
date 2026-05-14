`timescale 1ns / 1ps

module s3_if2_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        ic_req_valid;
    logic        ic_req_ready;
    logic [31:0] ic_req_addr;
    logic        redirect_fast_consume;
    logic        s3_to_s4_valid;
    logic [31:0] s3_pc;
    logic [31:0] s3_pc1;
    logic [31:0] s3_instr;
    logic        s3_slot0_valid;
    logic [31:0] s3_instr1;
    logic        s3_slot1_valid;
    logic [1:0]  s3_epoch;
    logic        s3_pred_taken;
    logic [31:0] s3_pred_target;
    logic        s3_ras_valid;
    logic [31:0] s3_ras_target;
    logic        s3_fault;
    logic [5:0]  s3_fault_ecode;
    logic [31:0] s3_fault_badv;
    logic        out_deliver;
    logic        resp_bypass;
    logic        fast_bypass;
    logic        packet_bypass;
    logic        stream_bypass;
    logic        meta_push;
    logic        meta_fifo_push;
    logic        meta_pop;
    logic        resp_push;
    logic        fast_push;
    logic        packet_push;
    logic        out_pop;
    logic        resp_drop;
    logic        stale_resp_drop;
    logic        stream_skip_drop;
    logic        preview_skip_drop;
    logic        duplicate_drop;
    logic        s2_dup_drop;

    logic        ic_req_valid_o;
    logic [31:0] ic_req_addr_o;
    logic        redirect_fast_consume_o;
    logic        s3_to_s4_valid_o;
    logic [31:0] s3_pc_o;
    logic [31:0] s3_pc1_o;
    logic [31:0] s3_instr_o;
    logic        s3_slot0_valid_o;
    logic [31:0] s3_instr1_o;
    logic        s3_slot1_valid_o;
    logic [1:0]  s3_epoch_o;
    logic        s3_pred_taken_o;
    logic [31:0] s3_pred_target_o;
    logic        s3_ras_valid_o;
    logic [31:0] s3_ras_target_o;
    logic        s3_fault_o;
    logic [5:0]  s3_fault_ecode_o;
    logic [31:0] s3_fault_badv_o;
    logic [3:0]  request_event_summary_o;
    logic [4:0]  source_event_summary_o;
    logic [7:0]  queue_event_summary_o;
    logic [7:0]  drop_event_summary_o;
    logic [15:0] if2_event_reason_o;

    s3_if2_event_packet #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .ic_req_valid_i(ic_req_valid),
        .ic_req_ready_i(ic_req_ready),
        .ic_req_addr_i(ic_req_addr),
        .redirect_fast_consume_i(redirect_fast_consume),
        .s3_to_s4_valid_i(s3_to_s4_valid),
        .s3_pc_i(s3_pc),
        .s3_pc1_i(s3_pc1),
        .s3_instr_i(s3_instr),
        .s3_slot0_valid_i(s3_slot0_valid),
        .s3_instr1_i(s3_instr1),
        .s3_slot1_valid_i(s3_slot1_valid),
        .s3_epoch_i(s3_epoch),
        .s3_pred_taken_i(s3_pred_taken),
        .s3_pred_target_i(s3_pred_target),
        .s3_ras_valid_i(s3_ras_valid),
        .s3_ras_target_i(s3_ras_target),
        .s3_fault_i(s3_fault),
        .s3_fault_ecode_i(s3_fault_ecode),
        .s3_fault_badv_i(s3_fault_badv),
        .out_deliver_i(out_deliver),
        .resp_bypass_i(resp_bypass),
        .fast_bypass_i(fast_bypass),
        .packet_bypass_i(packet_bypass),
        .stream_bypass_i(stream_bypass),
        .meta_push_i(meta_push),
        .meta_fifo_push_i(meta_fifo_push),
        .meta_pop_i(meta_pop),
        .resp_push_i(resp_push),
        .fast_push_i(fast_push),
        .packet_push_i(packet_push),
        .out_pop_i(out_pop),
        .resp_drop_i(resp_drop),
        .stale_resp_drop_i(stale_resp_drop),
        .stream_skip_drop_i(stream_skip_drop),
        .preview_skip_drop_i(preview_skip_drop),
        .duplicate_drop_i(duplicate_drop),
        .s2_dup_drop_i(s2_dup_drop),
        .ic_req_valid_o(ic_req_valid_o),
        .ic_req_addr_o(ic_req_addr_o),
        .redirect_fast_consume_o(redirect_fast_consume_o),
        .s3_to_s4_valid_o(s3_to_s4_valid_o),
        .s3_pc_o(s3_pc_o),
        .s3_pc1_o(s3_pc1_o),
        .s3_instr_o(s3_instr_o),
        .s3_slot0_valid_o(s3_slot0_valid_o),
        .s3_instr1_o(s3_instr1_o),
        .s3_slot1_valid_o(s3_slot1_valid_o),
        .s3_epoch_o(s3_epoch_o),
        .s3_pred_taken_o(s3_pred_taken_o),
        .s3_pred_target_o(s3_pred_target_o),
        .s3_ras_valid_o(s3_ras_valid_o),
        .s3_ras_target_o(s3_ras_target_o),
        .s3_fault_o(s3_fault_o),
        .s3_fault_ecode_o(s3_fault_ecode_o),
        .s3_fault_badv_o(s3_fault_badv_o),
        .request_event_summary_o(request_event_summary_o),
        .source_event_summary_o(source_event_summary_o),
        .queue_event_summary_o(queue_event_summary_o),
        .drop_event_summary_o(drop_event_summary_o),
        .if2_event_reason_o(if2_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            ic_req_valid = 1'b0;
            ic_req_ready = 1'b0;
            ic_req_addr = 32'd0;
            redirect_fast_consume = 1'b0;
            s3_to_s4_valid = 1'b0;
            s3_pc = 32'd0;
            s3_pc1 = 32'd0;
            s3_instr = 32'd0;
            s3_slot0_valid = 1'b0;
            s3_instr1 = 32'd0;
            s3_slot1_valid = 1'b0;
            s3_epoch = 2'd0;
            s3_pred_taken = 1'b0;
            s3_pred_target = 32'd0;
            s3_ras_valid = 1'b0;
            s3_ras_target = 32'd0;
            s3_fault = 1'b0;
            s3_fault_ecode = 6'd0;
            s3_fault_badv = 32'd0;
            out_deliver = 1'b0;
            resp_bypass = 1'b0;
            fast_bypass = 1'b0;
            packet_bypass = 1'b0;
            stream_bypass = 1'b0;
            meta_push = 1'b0;
            meta_fifo_push = 1'b0;
            meta_pop = 1'b0;
            resp_push = 1'b0;
            fast_push = 1'b0;
            packet_push = 1'b0;
            out_pop = 1'b0;
            resp_drop = 1'b0;
            stale_resp_drop = 1'b0;
            stream_skip_drop = 1'b0;
            preview_skip_drop = 1'b0;
            duplicate_drop = 1'b0;
            s2_dup_drop = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S3EVT idle clears visible events",
               !ic_req_valid_o && !redirect_fast_consume_o &&
               !s3_to_s4_valid_o && !s3_slot0_valid_o);
        `check32("S3EVT idle summaries clear",
                 {7'd0, request_event_summary_o, source_event_summary_o,
                  queue_event_summary_o, drop_event_summary_o}, 32'd0);

        clear_inputs();
        ic_req_valid = 1'b1;
        ic_req_ready = 1'b1;
        ic_req_addr = 32'h0000_1000;
        redirect_fast_consume = 1'b1;
        #1;
        `check("S3EVT forwards request and fast consume",
               ic_req_valid_o && redirect_fast_consume_o);
        `check32("S3EVT forwards request addr", ic_req_addr_o, 32'h0000_1000);
        `check32("S3EVT packs request summary",
                 {28'd0, request_event_summary_o}, {28'd0, 4'b1111});
        `check32("S3EVT packs request reason",
                 {16'd0, if2_event_reason_o}, 32'h0007);

        clear_inputs();
        s3_to_s4_valid = 1'b1;
        s3_pc = 32'h1c00_0100;
        s3_pc1 = 32'h1c00_0104;
        s3_instr = 32'h0280_0004;
        s3_slot0_valid = 1'b1;
        s3_instr1 = 32'h0280_0005;
        s3_slot1_valid = 1'b1;
        s3_epoch = 2'd2;
        s3_pred_taken = 1'b1;
        s3_pred_target = 32'h1c00_0200;
        s3_ras_valid = 1'b1;
        s3_ras_target = 32'h1c00_0300;
        s3_fault = 1'b1;
        s3_fault_ecode = 6'h03;
        s3_fault_badv = 32'h1c00_0100;
        resp_bypass = 1'b1;
        #1;
        `check("S3EVT forwards S4 packet payload",
               s3_to_s4_valid_o && s3_slot0_valid_o && s3_slot1_valid_o &&
               s3_pred_taken_o && s3_ras_valid_o && s3_fault_o);
        `check32("S3EVT forwards pc", s3_pc_o, 32'h1c00_0100);
        `check32("S3EVT forwards instr0", s3_instr_o, 32'h0280_0004);
        `check32("S3EVT forwards instr1", s3_instr1_o, 32'h0280_0005);
        `check32("S3EVT forwards pred target", s3_pred_target_o, 32'h1c00_0200);
        `check32("S3EVT forwards ras target", s3_ras_target_o, 32'h1c00_0300);
        `check32("S3EVT forwards fault ecode", {26'd0, s3_fault_ecode_o}, 32'h0000_0003);
        `check32("S3EVT packs resp source summary",
                 {27'd0, source_event_summary_o}, {27'd0, 5'b00010});
        `check32("S3EVT packs output reason",
                 {16'd0, if2_event_reason_o}, 32'h0110);

        clear_inputs();
        s3_to_s4_valid = 1'b1;
        out_deliver = 1'b1;
        stream_bypass = 1'b1;
        meta_push = 1'b1;
        meta_fifo_push = 1'b1;
        meta_pop = 1'b1;
        resp_push = 1'b1;
        fast_push = 1'b1;
        packet_push = 1'b1;
        out_pop = 1'b1;
        #1;
        `check32("S3EVT packs source mix",
                 {27'd0, source_event_summary_o}, {27'd0, 5'b10001});
        `check32("S3EVT packs queue summary",
                 {24'd0, queue_event_summary_o}, {24'd0, 8'b1111_1111});
        `check32("S3EVT packs queue reason",
                 {16'd0, if2_event_reason_o}, 32'h0388);

        clear_inputs();
        s3_slot1_valid = 1'b1;
        s3_fault = 1'b1;
        resp_drop = 1'b1;
        stale_resp_drop = 1'b1;
        stream_skip_drop = 1'b1;
        preview_skip_drop = 1'b1;
        duplicate_drop = 1'b1;
        s2_dup_drop = 1'b1;
        #1;
        `check32("S3EVT packs drop summary",
                 {24'd0, drop_event_summary_o}, {24'd0, 8'b1111_1111});
        `check32("S3EVT packs drop reason",
                 {16'd0, if2_event_reason_o}, 32'hfc00);

        finish_tb();
    end
endmodule

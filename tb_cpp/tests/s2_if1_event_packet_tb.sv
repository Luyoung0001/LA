`timescale 1ns / 1ps

module s2_if1_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s2_valid;
    logic        s2_ready_go;
    logic        s2_allowin;
    logic        s2_capture;
    logic        s2_fire;
    logic        s2_to_s3_valid;
    logic [31:0] s2_pc;
    logic [1:0]  s2_epoch;
    logic        s2_pred_valid;
    logic        s2_pred_taken;
    logic [31:0] s2_pred_target;
    logic        s2_ras_valid;
    logic [31:0] s2_ras_target;
    logic        s2_tlb_fault;
    logic [5:0]  s2_fault_ecode;
    logic [31:0] s2_fault_badv;
    logic [31:0] s2_icache_paddr;
    logic        shadow_fetch_valid;
    logic [31:0] shadow_fetch_paddr;
    logic        bpu_redirect_valid;
    logic [31:0] bpu_redirect_target;

    logic        s2_to_s3_valid_o;
    logic [31:0] s2_pc_o;
    logic [1:0]  s2_epoch_o;
    logic        s2_pred_taken_o;
    logic [31:0] s2_pred_target_o;
    logic        s2_ras_valid_o;
    logic [31:0] s2_ras_target_o;
    logic        s2_tlb_fault_o;
    logic [5:0]  s2_fault_ecode_o;
    logic [31:0] s2_fault_badv_o;
    logic [31:0] s2_icache_paddr_o;
    logic        shadow_fetch_valid_o;
    logic [31:0] shadow_fetch_paddr_o;
    logic        bpu_redirect_valid_o;
    logic [31:0] bpu_redirect_target_o;
    logic [3:0]  stage_event_summary_o;
    logic [3:0]  pred_event_summary_o;
    logic [3:0]  fault_event_summary_o;
    logic [15:0] if1_event_reason_o;

    s2_if1_event_packet #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .s2_valid_i(s2_valid),
        .s2_ready_go_i(s2_ready_go),
        .s2_allowin_i(s2_allowin),
        .s2_capture_i(s2_capture),
        .s2_fire_i(s2_fire),
        .s2_to_s3_valid_i(s2_to_s3_valid),
        .s2_pc_i(s2_pc),
        .s2_epoch_i(s2_epoch),
        .s2_pred_valid_i(s2_pred_valid),
        .s2_pred_taken_i(s2_pred_taken),
        .s2_pred_target_i(s2_pred_target),
        .s2_ras_valid_i(s2_ras_valid),
        .s2_ras_target_i(s2_ras_target),
        .s2_tlb_fault_i(s2_tlb_fault),
        .s2_fault_ecode_i(s2_fault_ecode),
        .s2_fault_badv_i(s2_fault_badv),
        .s2_icache_paddr_i(s2_icache_paddr),
        .shadow_fetch_valid_i(shadow_fetch_valid),
        .shadow_fetch_paddr_i(shadow_fetch_paddr),
        .bpu_redirect_valid_i(bpu_redirect_valid),
        .bpu_redirect_target_i(bpu_redirect_target),
        .s2_to_s3_valid_o(s2_to_s3_valid_o),
        .s2_pc_o(s2_pc_o),
        .s2_epoch_o(s2_epoch_o),
        .s2_pred_taken_o(s2_pred_taken_o),
        .s2_pred_target_o(s2_pred_target_o),
        .s2_ras_valid_o(s2_ras_valid_o),
        .s2_ras_target_o(s2_ras_target_o),
        .s2_tlb_fault_o(s2_tlb_fault_o),
        .s2_fault_ecode_o(s2_fault_ecode_o),
        .s2_fault_badv_o(s2_fault_badv_o),
        .s2_icache_paddr_o(s2_icache_paddr_o),
        .shadow_fetch_valid_o(shadow_fetch_valid_o),
        .shadow_fetch_paddr_o(shadow_fetch_paddr_o),
        .bpu_redirect_valid_o(bpu_redirect_valid_o),
        .bpu_redirect_target_o(bpu_redirect_target_o),
        .stage_event_summary_o(stage_event_summary_o),
        .pred_event_summary_o(pred_event_summary_o),
        .fault_event_summary_o(fault_event_summary_o),
        .if1_event_reason_o(if1_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            s2_valid = 1'b0;
            s2_ready_go = 1'b0;
            s2_allowin = 1'b0;
            s2_capture = 1'b0;
            s2_fire = 1'b0;
            s2_to_s3_valid = 1'b0;
            s2_pc = 32'd0;
            s2_epoch = 2'd0;
            s2_pred_valid = 1'b0;
            s2_pred_taken = 1'b0;
            s2_pred_target = 32'd0;
            s2_ras_valid = 1'b0;
            s2_ras_target = 32'd0;
            s2_tlb_fault = 1'b0;
            s2_fault_ecode = 6'd0;
            s2_fault_badv = 32'd0;
            s2_icache_paddr = 32'd0;
            shadow_fetch_valid = 1'b0;
            shadow_fetch_paddr = 32'd0;
            bpu_redirect_valid = 1'b0;
            bpu_redirect_target = 32'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S2EVT idle clears visible valid events",
               !s2_to_s3_valid_o && !s2_pred_taken_o && !s2_ras_valid_o &&
               !shadow_fetch_valid_o && !bpu_redirect_valid_o);
        `check32("S2EVT idle summaries clear",
                 {16'd0, stage_event_summary_o, pred_event_summary_o,
                  fault_event_summary_o, if1_event_reason_o[3:0]}, 32'd0);

        clear_inputs();
        s2_valid = 1'b1;
        s2_ready_go = 1'b1;
        s2_allowin = 1'b1;
        s2_capture = 1'b1;
        s2_fire = 1'b1;
        s2_to_s3_valid = 1'b1;
        s2_pc = 32'h1c00_1000;
        s2_epoch = 2'd2;
        s2_icache_paddr = 32'h000a_1000;
        #1;
        `check("S2EVT forwards stage payload",
               s2_to_s3_valid_o && !s2_tlb_fault_o);
        `check32("S2EVT forwards pc", s2_pc_o, 32'h1c00_1000);
        `check32("S2EVT forwards epoch", {30'd0, s2_epoch_o}, 32'd2);
        `check32("S2EVT forwards paddr", s2_icache_paddr_o, 32'h000a_1000);
        `check32("S2EVT packs stage summary",
                 {28'd0, stage_event_summary_o}, {28'd0, 4'b1111});
        `check32("S2EVT packs basic reason",
                 {16'd0, if1_event_reason_o}, 32'h03f0);

        clear_inputs();
        s2_pred_valid = 1'b1;
        s2_pred_taken = 1'b1;
        s2_pred_target = 32'h1c00_2000;
        s2_ras_valid = 1'b1;
        s2_ras_target = 32'h1c00_3000;
        shadow_fetch_valid = 1'b1;
        shadow_fetch_paddr = 32'h000a_1004;
        bpu_redirect_valid = 1'b1;
        bpu_redirect_target = 32'h1c00_2000;
        #1;
        `check("S2EVT forwards prediction sidebands",
               s2_pred_taken_o && s2_ras_valid_o &&
               shadow_fetch_valid_o && bpu_redirect_valid_o);
        `check32("S2EVT forwards prediction target", s2_pred_target_o, 32'h1c00_2000);
        `check32("S2EVT forwards RAS target", s2_ras_target_o, 32'h1c00_3000);
        `check32("S2EVT forwards shadow paddr", shadow_fetch_paddr_o, 32'h000a_1004);
        `check32("S2EVT forwards BPU redirect target", bpu_redirect_target_o, 32'h1c00_2000);
        `check32("S2EVT packs pred summary",
                 {28'd0, pred_event_summary_o}, {28'd0, 4'b1111});
        `check32("S2EVT packs pred reason",
                 {16'd0, if1_event_reason_o}, 32'hf800);

        clear_inputs();
        s2_valid = 1'b1;
        s2_tlb_fault = 1'b1;
        s2_fault_ecode = 6'h0f;
        s2_fault_badv = 32'h4000_1003;
        #1;
        `check("S2EVT forwards fault sideband", s2_tlb_fault_o);
        `check32("S2EVT forwards fault ecode",
                 {26'd0, s2_fault_ecode_o}, 32'h0000_000f);
        `check32("S2EVT forwards fault badv", s2_fault_badv_o, 32'h4000_1003);
        `check32("S2EVT packs fault summary",
                 {28'd0, fault_event_summary_o}, {28'd0, 4'b1111});
        `check32("S2EVT packs fault reason",
                 {16'd0, if1_event_reason_o}, 32'h041f);

        finish_tb();
    end
endmodule

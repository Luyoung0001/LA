`timescale 1ns / 1ps

module s3_frontend_if2_registered_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        flush;
    logic        in_valid;
    logic        allowin;
    logic        s4_allowin;
    logic        out_valid;
    logic        ic_req_valid;
    logic        ic_req_ready;
    logic        ic_valid;
    logic        ic_fault;
    logic        ic_line_valid;
    logic        redirect_fast_valid;
    logic        redirect_fast_line_valid;
    logic        redirect_fast_consume;
    logic        s2_dup_drop;
    logic [1:0]  current_epoch;
    logic [1:0]  epoch_i;
    logic [31:0] pc_i;
    logic [31:0] paddr_i;
    logic [31:0] pred_target_i;
    logic [31:0] ras_target_i;
    logic        pred_taken_i;
    logic        ras_valid_i;
    logic        tlb_fault_i;
    logic [5:0]  fault_ecode_i;
    logic [31:0] fault_badv_i;
    logic [31:0] ic_instr;
    logic [31:0] ic_req_addr;
    logic [31:0] ic_line_addr;
    logic [31:0] ic_line_d0;
    logic [31:0] ic_line_d1;
    logic [31:0] ic_line_d2;
    logic [31:0] ic_line_d3;
    logic [31:0] redirect_fast_addr;
    logic [31:0] redirect_fast_instr;
    logic [31:0] redirect_fast_line_addr;
    logic [31:0] redirect_fast_line_d0;
    logic [31:0] redirect_fast_line_d1;
    logic [31:0] redirect_fast_line_d2;
    logic [31:0] redirect_fast_line_d3;
    logic [31:0] pc_o;
    logic [31:0] pc1_o;
    logic [31:0] instr_o;
    logic [31:0] instr1_o;
    logic [1:0]  epoch_o;
    logic        slot0_valid_o;
    logic        slot1_valid_o;
    logic        pred_taken_o;
    logic [31:0] pred_target_o;
    logic        ras_valid_o;
    logic [31:0] ras_target_o;
    logic        fault_o;
    logic [5:0]  fault_ecode_o;
    logic [31:0] fault_badv_o;

    s3_frontend_if2 #(
        .EPOCH_WIDTH(2),
        .REGISTER_OUTPUT(1)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .current_epoch_i(current_epoch),
        .dual_slot_consume_i(1'b1),
        .slot1_ctrl_preview_enable_i(1'b0),
        .s2_to_s3_valid(in_valid),
        .s3_allowin(allowin),
        .s4_allowin(s4_allowin),
        .s3_to_s4_valid(out_valid),
        .s2_pc_i(pc_i),
        .s2_epoch_i(epoch_i),
        .s2_pred_taken_i(pred_taken_i),
        .s2_pred_target_i(pred_target_i),
        .s2_ras_valid_i(ras_valid_i),
        .s2_ras_target_i(ras_target_i),
        .s2_tlb_fault_i(tlb_fault_i),
        .s2_fault_ecode_i(fault_ecode_i),
        .s2_fault_badv_i(fault_badv_i),
        .s2_icache_paddr_i(paddr_i),
        .ic_req_valid_o(ic_req_valid),
        .ic_req_ready_i(ic_req_ready),
        .ic_req_addr_o(ic_req_addr),
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
        .ic_resp_valid_i(ic_valid),
        .ic_resp_instr_i(ic_instr),
        .ic_resp_fault_i(ic_fault),
        .ic_resp_line_valid_i(ic_line_valid),
        .ic_resp_line_addr_i(ic_line_addr),
        .ic_resp_line_data_i_0(ic_line_d0),
        .ic_resp_line_data_i_1(ic_line_d1),
        .ic_resp_line_data_i_2(ic_line_d2),
        .ic_resp_line_data_i_3(ic_line_d3),
        .s3_pc_o(pc_o),
        .s3_pc1_o(pc1_o),
        .s3_instr_o(instr_o),
        .s3_slot0_valid_o(slot0_valid_o),
        .s3_instr1_o(instr1_o),
        .s3_slot1_valid_o(slot1_valid_o),
        .s3_epoch_o(epoch_o),
        .s3_pred_taken_o(pred_taken_o),
        .s3_pred_target_o(pred_target_o),
        .s3_ras_valid_o(ras_valid_o),
        .s3_ras_target_o(ras_target_o),
        .s3_fault_o(fault_o),
        .s3_fault_ecode_o(fault_ecode_o),
        .s3_fault_badv_o(fault_badv_o),
        .s2_dup_drop_o(s2_dup_drop)
    );

    task automatic clear_inputs;
        begin
            flush = 1'b0;
            in_valid = 1'b0;
            s4_allowin = 1'b1;
            ic_req_ready = 1'b1;
            ic_valid = 1'b0;
            ic_fault = 1'b0;
            ic_line_valid = 1'b0;
            redirect_fast_valid = 1'b0;
            redirect_fast_line_valid = 1'b0;
            current_epoch = 2'd0;
            epoch_i = 2'd0;
            pc_i = 32'd0;
            paddr_i = 32'd0;
            pred_taken_i = 1'b0;
            pred_target_i = 32'd0;
            ras_valid_i = 1'b0;
            ras_target_i = 32'd0;
            tlb_fault_i = 1'b0;
            fault_ecode_i = 6'd0;
            fault_badv_i = 32'd0;
            ic_instr = 32'd0;
            ic_line_addr = 32'd0;
            ic_line_d0 = 32'd0;
            ic_line_d1 = 32'd0;
            ic_line_d2 = 32'd0;
            ic_line_d3 = 32'd0;
            redirect_fast_addr = 32'd0;
            redirect_fast_instr = 32'd0;
            redirect_fast_line_addr = 32'd0;
            redirect_fast_line_d0 = 32'd0;
            redirect_fast_line_d1 = 32'd0;
            redirect_fast_line_d2 = 32'd0;
            redirect_fast_line_d3 = 32'd0;
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        current_epoch = 2'd1;
        epoch_i = 2'd1;
        pc_i = 32'h1c00_1000;
        paddr_i = 32'h0000_1000;
        pred_taken_i = 1'b1;
        pred_target_i = 32'h1c00_2000;
        ras_valid_i = 1'b1;
        ras_target_i = 32'h1c00_3000;
        in_valid = 1'b1;
        #1;
        `check("S3 registered output issues request", ic_req_valid && ic_req_addr == 32'h0000_1000);
        tick();
        in_valid = 1'b0;
        ic_valid = 1'b1;
        ic_instr = 32'h0280_4884;
        #1;
        `check("S3 registered output does not expose same-cycle response", !out_valid);
        tick();
        ic_valid = 1'b0;
        #1;
        `check("S3 registered output exposes response next cycle", out_valid);
        `check32("S3 registered response pc", pc_o, 32'h1c00_1000);
        `check32("S3 registered response instr", instr_o, 32'h0280_4884);
        `check("S3 registered response keeps prediction",
               pred_taken_o && pred_target_o == 32'h1c00_2000);
        `check("S3 registered response keeps RAS",
               ras_valid_o && ras_target_o == 32'h1c00_3000);
        tick();
        #1;
        `check("S3 registered response drains after downstream accept", !out_valid);

        clear_inputs();
        reset_dut();
        current_epoch = 2'd2;
        epoch_i = 2'd2;
        pc_i = 32'h1c00_4000;
        paddr_i = 32'h0000_4000;
        in_valid = 1'b1;
        tick();
        in_valid = 1'b0;
        s4_allowin = 1'b0;
        ic_valid = 1'b1;
        ic_instr = 32'h0400_0001;
        tick();
        ic_valid = 1'b0;
        #1;
        `check("S3 registered output holds while downstream stalls", out_valid);
        `check32("S3 registered hold pc", pc_o, 32'h1c00_4000);
        `check32("S3 registered hold instr", instr_o, 32'h0400_0001);
        repeat (3) begin
            tick();
            #1;
            `check("S3 registered output remains valid during stall", out_valid);
            `check32("S3 registered held instr stable", instr_o, 32'h0400_0001);
        end
        s4_allowin = 1'b1;
        tick();
        #1;
        `check("S3 registered held output drains on accept", !out_valid);

        clear_inputs();
        reset_dut();
        current_epoch = 2'd3;
        epoch_i = 2'd3;
        pc_i = 32'h1c00_5000;
        paddr_i = 32'h0000_5000;
        in_valid = 1'b1;
        tick();
        in_valid = 1'b0;
        s4_allowin = 1'b0;
        ic_valid = 1'b1;
        ic_instr = 32'h0500_0001;
        tick();
        ic_valid = 1'b0;
        #1;
        `check("S3 registered stale setup captured output", out_valid && epoch_o == 2'd3);
        current_epoch = 2'd0;
        #1;
        `check("S3 registered output hides stale epoch", !out_valid);
        tick();
        #1;
        `check("S3 registered stale output clears without downstream accept", !out_valid);

        finish_tb();
    end
endmodule

`timescale 1ns / 1ps

module fetch_buffer_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic dual_slot_consume;
    logic wr_valid;
    logic wr_slot0_valid;
    logic wr_slot1_valid;
    logic wr_pred_taken;
    logic wr_ras_valid;
    logic wr_fault;
    logic rd_allowin;
    logic not_full;
    logic wr_fire;
    logic bypass;
    logic rd_valid;
    logic rd_fire;
    logic empty;
    logic nonempty;
    logic full;
    logic rd_slot0_valid;
    logic rd_slot1_valid;
    logic rd_pred_taken;
    logic rd_ras_valid;
    logic rd_fault;
    logic current_epoch;
    logic wr_epoch;
    logic rd_epoch;
    logic [1:0] level;
    logic [5:0] wr_fault_ecode;
    logic [5:0] rd_fault_ecode;
    logic [31:0] wr_pc;
    logic [31:0] wr_pc1;
    logic [31:0] wr_instr;
    logic [31:0] wr_instr1;
    logic [31:0] wr_pred_target;
    logic [31:0] wr_ras_target;
    logic [31:0] wr_fault_badv;
    logic [31:0] rd_pc;
    logic [31:0] rd_pc1;
    logic [31:0] rd_instr;
    logic [31:0] rd_instr1;
    logic [31:0] rd_pred_target;
    logic [31:0] rd_ras_target;
    logic [31:0] rd_fault_badv;

    fetch_buffer #(
        .DEPTH(2),
        .EPOCH_WIDTH(1)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .current_epoch_i(current_epoch),
        .dual_slot_consume_i(dual_slot_consume),
        .wr_valid_i(wr_valid),
        .wr_pc_i(wr_pc),
        .wr_pc1_i(wr_pc1),
        .wr_instr_i(wr_instr),
        .wr_slot0_valid_i(wr_slot0_valid),
        .wr_instr1_i(wr_instr1),
        .wr_slot1_valid_i(wr_slot1_valid),
        .wr_epoch_i(wr_epoch),
        .wr_pred_taken_i(wr_pred_taken),
        .wr_pred_target_i(wr_pred_target),
        .wr_ras_valid_i(wr_ras_valid),
        .wr_ras_target_i(wr_ras_target),
        .wr_fault_i(wr_fault),
        .wr_fault_ecode_i(wr_fault_ecode),
        .wr_fault_badv_i(wr_fault_badv),
        .not_full_o(not_full),
        .wr_fire_o(wr_fire),
        .bypass_o(bypass),
        .rd_allowin_i(rd_allowin),
        .rd_valid_o(rd_valid),
        .rd_fire_o(rd_fire),
        .empty_o(empty),
        .nonempty_o(nonempty),
        .full_o(full),
        .level_o(level),
        .rd_pc_o(rd_pc),
        .rd_pc1_o(rd_pc1),
        .rd_instr_o(rd_instr),
        .rd_slot0_valid_o(rd_slot0_valid),
        .rd_instr1_o(rd_instr1),
        .rd_slot1_valid_o(rd_slot1_valid),
        .rd_epoch_o(rd_epoch),
        .rd_pred_taken_o(rd_pred_taken),
        .rd_pred_target_o(rd_pred_target),
        .rd_ras_valid_o(rd_ras_valid),
        .rd_ras_target_o(rd_ras_target),
        .rd_fault_o(rd_fault),
        .rd_fault_ecode_o(rd_fault_ecode),
        .rd_fault_badv_o(rd_fault_badv)
    );

    task automatic clear_inputs;
        begin
            flush = 1'b0;
            dual_slot_consume = 1'b0;
            wr_valid = 1'b0;
            wr_slot0_valid = 1'b0;
            wr_slot1_valid = 1'b0;
            wr_pred_taken = 1'b0;
            wr_ras_valid = 1'b0;
            wr_fault = 1'b0;
            wr_fault_ecode = 6'd0;
            wr_fault_badv = 32'd0;
            rd_allowin = 1'b0;
            current_epoch = 1'b0;
            wr_epoch = 1'b0;
            wr_pc = 32'd0;
            wr_pc1 = 32'd0;
            wr_instr = 32'd0;
            wr_instr1 = 32'd0;
            wr_pred_target = 32'd0;
            wr_ras_target = 32'd0;
        end
    endtask

    task automatic drive_packet(
        input [31:0] pc,
        input [31:0] inst,
        input        epoch
    );
        begin
            wr_valid = 1'b1;
            wr_slot0_valid = 1'b1;
            wr_slot1_valid = 1'b0;
            wr_pc = pc;
            wr_pc1 = pc + 32'd4;
            wr_instr = inst;
            wr_instr1 = inst + 32'd1;
            wr_epoch = epoch;
            wr_pred_taken = pc[4];
            wr_pred_target = pc + 32'h40;
            wr_ras_valid = pc[5];
            wr_ras_target = pc + 32'h80;
            wr_fault = 1'b0;
            wr_fault_ecode = 6'd0;
            wr_fault_badv = 32'd0;
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        rd_allowin = 1'b1;
        current_epoch = 1'b0;
        drive_packet(32'h1000, 32'haaaa_0000, 1'b0);
        wr_fault = 1'b1;
        wr_fault_ecode = 6'h08;
        wr_fault_badv = 32'h4000_1000;
        #1;
        `check("FetchBuffer empty bypass is valid", rd_valid && bypass);
        `check("FetchBuffer empty bypass does not enqueue", !wr_fire && !rd_fire && empty && level == 2'd0);
        `check32("FetchBuffer bypass PC", rd_pc, 32'h1000);
        `check32("FetchBuffer bypass inst", rd_instr, 32'haaaa_0000);
        `check("FetchBuffer bypass fault sideband", rd_fault && rd_fault_ecode == 6'h08);
        `check32("FetchBuffer bypass badv", rd_fault_badv, 32'h4000_1000);
        tick();
        wr_valid = 1'b0;
        #1;
        `check("FetchBuffer bypass leaves FIFO empty", !rd_valid && empty && level == 2'd0);

        rd_allowin = 1'b0;
        current_epoch = 1'b0;
        drive_packet(32'h2000, 32'h1111_0000, 1'b0);
        tick();
        drive_packet(32'h2004, 32'h2222_0000, 1'b0);
        tick();
        #1;
        `check("FetchBuffer fills to full under downstream stall", full && !not_full && level == 2'd2);
        `check32("FetchBuffer holds oldest packet while stalled", rd_pc, 32'h2000);

        drive_packet(32'h2008, 32'h3333_0000, 1'b0);
        #1;
        `check("FetchBuffer full blocks write without read", !not_full && !wr_fire && !rd_fire);

        rd_allowin = 1'b1;
        #1;
        `check("FetchBuffer full accepts write when simultaneously reading",
               not_full && wr_fire && rd_fire && full);
        tick();
        wr_valid = 1'b0;
        #1;
        `check32("FetchBuffer simultaneous full read/write keeps FIFO order", rd_pc, 32'h2004);
        tick();
        #1;
        `check32("FetchBuffer simultaneous full read/write keeps new tail", rd_pc, 32'h2008);
        tick();
        #1;
        `check("FetchBuffer drains after queued packets", empty && !rd_valid);

        rd_allowin = 1'b0;
        current_epoch = 1'b0;
        drive_packet(32'h3000, 32'h4444_0000, 1'b0);
        tick();
        wr_valid = 1'b0;
        flush = 1'b1;
        #1;
        `check("FetchBuffer hides output during flush", !rd_valid && !wr_fire && !rd_fire);
        tick();
        flush = 1'b0;
        #1;
        `check("FetchBuffer flush clears queued packet", empty && !rd_valid && level == 2'd0);

        current_epoch = 1'b0;
        drive_packet(32'h4000, 32'h5555_0000, 1'b0);
        tick();
        current_epoch = 1'b1;
        wr_valid = 1'b0;
        #1;
        `check("FetchBuffer stale head auto-pops without downstream allowin",
               !rd_valid && rd_fire && level == 2'd1);
        tick();
        #1;
        `check("FetchBuffer stale head is removed", empty && !rd_valid);

        drive_packet(32'h5000, 32'h6666_0000, 1'b0);
        rd_allowin = 1'b1;
        #1;
        `check("FetchBuffer stale empty input is suppressed",
               !rd_valid && !wr_fire && !bypass && empty);
        tick();
        wr_epoch = 1'b1;
        #1;
        `check("FetchBuffer matching epoch input can bypass", rd_valid && bypass && rd_pc == 32'h5000);
        tick();

        flush = 1'b1;
        wr_valid = 1'b0;
        tick();
        flush = 1'b0;
        dual_slot_consume = 1'b1;
        rd_allowin = 1'b1;
        current_epoch = 1'b0;
        drive_packet(32'h6000, 32'h7777_0000, 1'b0);
        wr_slot1_valid = 1'b1;
        wr_instr1 = 32'h7777_0001;
        #1;
        `check("FetchBuffer dual-slot packet bypasses with slot1", rd_valid && rd_slot1_valid);
        tick();
        drive_packet(32'h6004, 32'h8888_0000, 1'b0);
        #1;
        `check("FetchBuffer dual-slot duplicate PC is dropped", !rd_valid && !wr_fire && empty);
        tick();
        drive_packet(32'h6008, 32'h9999_0000, 1'b0);
        #1;
        `check("FetchBuffer dual-slot later PC is accepted", rd_valid && rd_pc == 32'h6008);

        wr_valid = 1'b0;
        dual_slot_consume = 1'b0;
        rd_allowin = 1'b0;
        finish_tb();
    end
endmodule

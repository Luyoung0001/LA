`timescale 1ns / 1ps

module la_fetch_buffer_adapter_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic reset;
    logic flush;
    logic out_allowin;
    logic in_allowin;
    logic in_valid;
    logic in_pred_taken;
    logic in_exception_valid;
    logic out_valid;
    logic out_pred_taken;
    logic out_exception_valid;
    logic [5:0] in_exception_ecode;
    logic [5:0] out_exception_ecode;
    logic [31:0] in_pc;
    logic [31:0] in_inst;
    logic [31:0] in_pred_target;
    logic [31:0] in_exception_badv;
    logic [31:0] out_pc;
    logic [31:0] out_inst;
    logic [31:0] out_pred_target;
    logic [31:0] out_exception_badv;

    assign reset = !rst_n;

    la_fetch_buffer_adapter #(
        .DEPTH(2),
        .EPOCH_WIDTH(1)
    ) u_dut (
        .clk(clk),
        .reset(reset),
        .flush(flush),
        .out_allowin(out_allowin),
        .in_allowin(in_allowin),
        .in_valid(in_valid),
        .in_pc(in_pc),
        .in_inst(in_inst),
        .in_pred_taken(in_pred_taken),
        .in_pred_target(in_pred_target),
        .in_exception_valid(in_exception_valid),
        .in_exception_ecode(in_exception_ecode),
        .in_exception_badv(in_exception_badv),
        .out_valid(out_valid),
        .out_pc(out_pc),
        .out_inst(out_inst),
        .out_pred_taken(out_pred_taken),
        .out_pred_target(out_pred_target),
        .out_exception_valid(out_exception_valid),
        .out_exception_ecode(out_exception_ecode),
        .out_exception_badv(out_exception_badv)
    );

    task automatic clear_inputs;
        begin
            flush = 1'b0;
            out_allowin = 1'b0;
            in_valid = 1'b0;
            in_pc = 32'd0;
            in_inst = 32'd0;
            in_pred_taken = 1'b0;
            in_pred_target = 32'd0;
            in_exception_valid = 1'b0;
            in_exception_ecode = 6'd0;
            in_exception_badv = 32'd0;
        end
    endtask

    task automatic drive_packet(
        input [31:0] pc,
        input [31:0] inst
    );
        begin
            in_valid = 1'b1;
            in_pc = pc;
            in_inst = inst;
            in_pred_taken = pc[4];
            in_pred_target = pc + 32'h40;
            in_exception_valid = 1'b0;
            in_exception_ecode = 6'd0;
            in_exception_badv = 32'd0;
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        out_allowin = 1'b1;
        drive_packet(32'h1000, 32'haaaa_0000);
        in_pred_taken = 1'b1;
        in_pred_target = 32'h1800;
        in_exception_valid = 1'b1;
        in_exception_ecode = 6'h08;
        in_exception_badv = 32'h4000_1000;
        #1;
        `check("Adapter empty path presents valid packet", out_valid && in_allowin);
        `check32("Adapter empty path PC", out_pc, 32'h1000);
        `check32("Adapter empty path inst", out_inst, 32'haaaa_0000);
        `check("Adapter empty path prediction sideband",
               out_pred_taken && out_pred_target == 32'h1800);
        `check("Adapter empty path exception sideband",
               out_exception_valid && out_exception_ecode == 6'h08);
        `check32("Adapter empty path exception badv", out_exception_badv, 32'h4000_1000);
        tick();
        in_valid = 1'b0;
        #1;
        `check("Adapter bypass does not leave stale output", !out_valid);

        out_allowin = 1'b0;
        drive_packet(32'h2000, 32'h1111_0000);
        #1;
        `check("Adapter queues first packet when downstream stalls", out_valid && in_allowin);
        tick();
        drive_packet(32'h2004, 32'h2222_0000);
        #1;
        `check("Adapter exposes oldest packet while filling", out_valid && out_pc == 32'h2000 && in_allowin);
        tick();
        drive_packet(32'h2008, 32'h3333_0000);
        #1;
        `check("Adapter backpressures input when buffer is full", !in_allowin && out_valid && out_pc == 32'h2000);

        out_allowin = 1'b1;
        #1;
        `check("Adapter accepts input on full read/write cycle", in_allowin && out_valid && out_pc == 32'h2000);
        tick();
        in_valid = 1'b0;
        #1;
        `check32("Adapter drains second queued packet", out_pc, 32'h2004);
        tick();
        #1;
        `check32("Adapter drains simultaneous-write tail", out_pc, 32'h2008);
        tick();
        #1;
        `check("Adapter drains to empty", !out_valid);

        out_allowin = 1'b0;
        drive_packet(32'h3000, 32'h4444_0000);
        tick();
        in_valid = 1'b0;
        flush = 1'b1;
        #1;
        `check("Adapter hides output during flush", !out_valid);
        tick();
        flush = 1'b0;
        #1;
        `check("Adapter flush clears buffered packet", !out_valid && in_allowin);

        out_allowin = 1'b1;
        drive_packet(32'h4000, 32'h5555_0000);
        tick();
        in_valid = 1'b0;
        #1;
        `check("Adapter remains empty after accepted bypass", !out_valid);

        finish_tb();
    end
endmodule

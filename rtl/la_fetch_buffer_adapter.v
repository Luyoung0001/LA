`include "la_core_defs.vh"

module la_fetch_buffer_adapter #(
    parameter XLEN = `LA_XLEN,
    parameter ILEN = `LA_ILEN,
    parameter DEPTH = 8,
    parameter EPOCH_WIDTH = 1
) (
    input  wire            clk,
    input  wire            reset,
    input  wire            flush,
    input  wire            out_allowin,
    output wire            in_allowin,

    input  wire            in_valid,
    input  wire [XLEN-1:0] in_pc,
    input  wire [ILEN-1:0] in_inst,
    input  wire            in_pred_taken,
    input  wire [XLEN-1:0] in_pred_target,
    input  wire            in_exception_valid,
    input  wire [5:0]      in_exception_ecode,
    input  wire [XLEN-1:0] in_exception_badv,

    output wire            out_valid,
    output wire [XLEN-1:0] out_pc,
    output wire [ILEN-1:0] out_inst,
    output wire            out_pred_taken,
    output wire [XLEN-1:0] out_pred_target,
    output wire            out_exception_valid,
    output wire [5:0]      out_exception_ecode,
    output wire [XLEN-1:0] out_exception_badv
);

    wire unused_status;
    wire wr_fire_w;
    wire bypass_w;
    wire rd_fire_w;
    wire empty_w;
    wire nonempty_w;
    wire full_w;
    wire [$clog2(DEPTH):0] level_w;
    wire [XLEN-1:0] rd_pc1_w;
    wire rd_slot0_valid_w;
    wire [ILEN-1:0] rd_instr1_w;
    wire rd_slot1_valid_w;
    wire [EPOCH_WIDTH-1:0] rd_epoch_w;
    wire rd_pred_taken_w;
    wire [XLEN-1:0] rd_pred_target_w;
    wire rd_ras_valid_w;
    wire [XLEN-1:0] rd_ras_target_w;
    wire rd_fault_w;
    wire [5:0] rd_fault_ecode_w;
    wire [XLEN-1:0] rd_fault_badv_w;

    assign unused_status = &{1'b0, wr_fire_w, bypass_w, rd_fire_w, empty_w,
                             nonempty_w, full_w, level_w, rd_pc1_w,
                             rd_slot0_valid_w, rd_instr1_w, rd_slot1_valid_w,
                             rd_epoch_w,
                             rd_ras_valid_w, rd_ras_target_w, rd_fault_w,
                             rd_fault_ecode_w, rd_fault_badv_w};

    assign out_pred_taken = rd_pred_taken_w;
    assign out_pred_target = rd_pred_target_w;
    assign out_exception_valid = rd_fault_w;
    assign out_exception_ecode = rd_fault_ecode_w;
    assign out_exception_badv = rd_fault_badv_w;

    fetch_buffer #(
        .XLEN(XLEN),
        .ILEN(ILEN),
        .DEPTH(DEPTH),
        .EPOCH_WIDTH(EPOCH_WIDTH)
    ) u_fetch_buffer (
        .clk                (clk),
        .rst_n              (~reset),
        .flush              (flush),
        .current_epoch_i    ({EPOCH_WIDTH{1'b0}}),
        .dual_slot_consume_i(1'b0),

        .wr_valid_i         (in_valid),
        .wr_pc_i            (in_pc),
        .wr_pc1_i           (in_pc + {{(XLEN-3){1'b0}}, 3'd4}),
        .wr_instr_i         (in_inst),
        .wr_slot0_valid_i   (in_valid),
        .wr_instr1_i        ({ILEN{1'b0}}),
        .wr_slot1_valid_i   (1'b0),
        .wr_epoch_i         ({EPOCH_WIDTH{1'b0}}),
        .wr_pred_taken_i    (in_pred_taken),
        .wr_pred_target_i   (in_pred_target),
        .wr_ras_valid_i     (1'b0),
        .wr_ras_target_i    ({XLEN{1'b0}}),
        .wr_fault_i         (in_exception_valid),
        .wr_fault_ecode_i   (in_exception_ecode),
        .wr_fault_badv_i    (in_exception_badv),
        .not_full_o         (in_allowin),
        .wr_fire_o          (wr_fire_w),
        .bypass_o           (bypass_w),

        .rd_allowin_i       (out_allowin),
        .rd_valid_o         (out_valid),
        .rd_fire_o          (rd_fire_w),
        .empty_o            (empty_w),
        .nonempty_o         (nonempty_w),
        .full_o             (full_w),
        .level_o            (level_w),
        .rd_pc_o            (out_pc),
        .rd_pc1_o           (rd_pc1_w),
        .rd_instr_o         (out_inst),
        .rd_slot0_valid_o   (rd_slot0_valid_w),
        .rd_instr1_o        (rd_instr1_w),
        .rd_slot1_valid_o   (rd_slot1_valid_w),
        .rd_epoch_o         (rd_epoch_w),
        .rd_pred_taken_o    (rd_pred_taken_w),
        .rd_pred_target_o   (rd_pred_target_w),
        .rd_ras_valid_o     (rd_ras_valid_w),
        .rd_ras_target_o    (rd_ras_target_w),
        .rd_fault_o         (rd_fault_w),
        .rd_fault_ecode_o   (rd_fault_ecode_w),
        .rd_fault_badv_o    (rd_fault_badv_w)
    );

endmodule

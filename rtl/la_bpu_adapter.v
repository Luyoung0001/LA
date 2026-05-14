module la_bpu_adapter #(
    parameter XLEN = 32
) (
    input  wire            clk,
    input  wire            reset,

    input  wire            req_valid,
    input  wire [XLEN-1:0] req_pc,
    output wire            resp_valid,
    output wire            pred_taken,
    output wire [XLEN-1:0] pred_target,

    input  wire            update_valid,
    input  wire            update_taken,
    input  wire [XLEN-1:0] update_pc,
    input  wire [XLEN-1:0] update_target
);

    wire pred_valid_w;
    wire pred_taken_w;
    wire [XLEN-1:0] pred_target_w;
    reg req_valid_q;
    reg [XLEN-1:0] req_pc_q;

    wire unused_bpu_sideband;
    wire pred_is_call_w;
    wire pred_is_ret_w;
    wire pred_is_indirect_jmp_w;
    wire pred_ras_valid_w;
    wire [XLEN-1:0] pred_ras_target_w;

    assign unused_bpu_sideband = &{1'b0, pred_is_call_w, pred_is_ret_w,
                                   pred_is_indirect_jmp_w, pred_ras_valid_w,
                                   pred_ras_target_w};

    assign resp_valid  = req_valid_q;
    assign pred_taken  = pred_valid_w && pred_taken_w;
    assign pred_target = pred_taken ? pred_target_w : (req_pc_q + {{(XLEN-3){1'b0}}, 3'd4});

    always @(posedge clk) begin
        if (reset) begin
            req_valid_q <= 1'b0;
            req_pc_q    <= {XLEN{1'b0}};
        end else begin
            req_valid_q <= req_valid;
            req_pc_q    <= req_pc;
        end
    end

    cpu_bpu #(
        .XLEN(XLEN)
    ) u_cpu_bpu (
        .clk                       (clk),
        .rst_n                     (~reset),

        .lookup_pc_i               (req_pc),
        .pred_valid_o              (pred_valid_w),
        .pred_taken_o              (pred_taken_w),
        .pred_target_o             (pred_target_w),
        .pred_is_call_o            (pred_is_call_w),
        .pred_is_ret_o             (pred_is_ret_w),
        .pred_is_indirect_jmp_o    (pred_is_indirect_jmp_w),
        .pred_ras_valid_o          (pred_ras_valid_w),
        .pred_ras_target_o         (pred_ras_target_w),

        .update_valid_i            (update_valid),
        .update_pc_i               (update_pc),
        .update_taken_i            (update_taken),
        .update_target_i           (update_target),
        .update_is_call_i          (1'b0),
        .update_is_ret_i           (1'b0),
        .update_is_jmp_i           (update_taken),
        .update_is_indirect_jmp_i  (1'b0),

        .ras_update_valid_i        (1'b0),
        .ras_update_pc_i           ({XLEN{1'b0}}),
        .ras_update_is_call_i      (1'b0),
        .ras_update_is_ret_i       (1'b0)
    );

endmodule

module s1_f1 #(
    parameter RESET_PC = 32'h1c000000
) (
    input  wire        clk,
    input  wire        reset,
    input  wire        hold,
    input  wire        redirect_valid,
    input  wire [31:0] redirect_pc,
    input  wire        bp_resp_valid,
    input  wire [31:0] bp_resp_pc,
    input  wire        bp_pred_taken,
    input  wire [31:0] bp_pred_target,
    output wire        bp_req_valid,
    output wire [31:0] bp_req_pc,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output wire        out_pred_taken,
    output wire [31:0] out_pred_target
);

    reg [31:0] pc_r;
    // Redirect suppression filters registered BPU responses that were launched
    // before an exception/interrupt/refetch redirect.
    reg        pred_allowed_r;

    wire bp_use_valid = bp_resp_valid && bp_pred_taken &&
                        (bp_resp_pc == pc_r) && pred_allowed_r;
    wire [31:0] seq_next_pc_w = bp_use_valid ? bp_pred_target : (pc_r + 32'd4);
    wire [31:0] bp_lookup_pc_w = hold ? pc_r : seq_next_pc_w;

    assign out_pred_taken  = bp_use_valid;
    assign out_pred_target = seq_next_pc_w;
    assign bp_req_valid    = !reset;
    assign bp_req_pc       = redirect_valid ? redirect_pc : bp_lookup_pc_w;

    always @(posedge clk) begin
        if (reset) begin
            pc_r              <= RESET_PC;
            out_valid         <= 1'b0;
            out_pc            <= RESET_PC;
            pred_allowed_r    <= 1'b0;
        end else begin
            pred_allowed_r <= !redirect_valid;

            if (redirect_valid) begin
                out_valid    <= 1'b1;
                out_pc       <= redirect_pc;
                pc_r         <= redirect_pc;
            end else begin
                out_valid    <= 1'b1;

                if (hold) begin
                    out_pc <= pc_r;
                    pc_r <= pc_r;
                end else begin
                    out_pc <= seq_next_pc_w;
                    pc_r   <= seq_next_pc_w;
                end
            end
        end
    end

`ifdef VERILATOR
`ifdef PERF_MONI
    integer dbg_out_pred_taken_cnt = 0;
    integer dbg_bp_use_valid_cnt = 0;
    integer dbg_redirect_cnt = 0;
    final begin
        $display("[S1F1][DBG] out_pred_taken=%0d bp_use_valid=%0d redirect=%0d",
                 dbg_out_pred_taken_cnt, dbg_bp_use_valid_cnt, dbg_redirect_cnt);
    end
    always @(posedge clk) begin
        if (!reset) begin
            if (out_pred_taken) dbg_out_pred_taken_cnt <= dbg_out_pred_taken_cnt + 1;
            if (bp_use_valid) dbg_bp_use_valid_cnt <= dbg_bp_use_valid_cnt + 1;
            if (redirect_valid) dbg_redirect_cnt <= dbg_redirect_cnt + 1;
        end
    end
`endif
`endif

endmodule

module s2_f2 (
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,
    input  wire        next_allowin,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire        in_pred_taken,
    input  wire [31:0] in_pred_target,
    output wire        s2_allowin,
    output wire        tlb_query_valid,
    output wire        tlb_query_write,
    output wire [31:0] tlb_query_vaddr,
    input  wire [31:0] tlb_query_paddr,
    input  wire        tlb_exception_valid,
    input  wire [5:0]  tlb_exception_ecode,
    output reg         icache_req_valid,
    output reg  [31:0] icache_req_addr,
    input  wire        icache_req_ready,
    input  wire        icache_resp_valid,
    input  wire [31:0] icache_resp_data,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg         out_pred_taken,
    output reg  [31:0] out_pred_target,
    output reg         out_exception_valid,
    output reg  [5:0]  out_exception_ecode,
    output reg  [8:0]  out_exception_esubcode,
    output reg         out_exception_badv_valid,
    output reg  [31:0] out_exception_badv
);

    reg        pend_valid;
    reg        pend_req_sent;
    reg [31:0] pend_pc;
    reg        pend_pred_taken;
    reg [31:0] pend_pred_target;
    reg        pend_exception_valid;
    reg [5:0]  pend_exception_ecode;
    reg [8:0]  pend_exception_esubcode;
    reg        pend_exception_badv_valid;
    reg [31:0] pend_exception_badv;

    wire        pc_adef_w;
    wire        req_exception_valid_w;
    wire [5:0]  req_exception_ecode_w;
    wire [8:0]  req_exception_esubcode_w;
    wire [31:0] req_addr_w;
    wire        in_fire_w;
    wire        out_slot_ready_w;
    wire        pend_ready_w;
    wire        out_fire_w;

    assign pc_adef_w = |in_pc[1:0];
    assign req_exception_valid_w = pc_adef_w || tlb_exception_valid;
    assign req_exception_ecode_w = pc_adef_w ? 6'h08 : tlb_exception_ecode;
    assign req_exception_esubcode_w = 9'h0;
    assign req_addr_w = tlb_query_paddr;

    assign out_slot_ready_w = !out_valid || next_allowin;
    assign pend_ready_w = pend_valid &&
                          (pend_exception_valid ||
                           (pend_req_sent && icache_resp_valid));
    assign out_fire_w = out_slot_ready_w && pend_ready_w;
    assign s2_allowin = !flush && !pend_valid && out_slot_ready_w;
    assign in_fire_w = in_valid && s2_allowin;

    assign tlb_query_valid = in_fire_w && !pc_adef_w;
    assign tlb_query_write = 1'b0;
    assign tlb_query_vaddr = in_pc;

    always @(posedge clk) begin
        if (reset || flush) begin
            pend_valid                <= 1'b0;
            pend_req_sent             <= 1'b0;
            pend_pc                   <= 32'b0;
            pend_pred_taken           <= 1'b0;
            pend_pred_target          <= 32'b0;
            pend_exception_valid      <= 1'b0;
            pend_exception_ecode      <= 6'b0;
            pend_exception_esubcode   <= 9'b0;
            pend_exception_badv_valid <= 1'b0;
            pend_exception_badv       <= 32'b0;
            out_valid                 <= 1'b0;
            out_pc                    <= 32'b0;
            out_inst                  <= 32'h03400000;
            out_pred_taken            <= 1'b0;
            out_pred_target           <= 32'b0;
            out_exception_valid       <= 1'b0;
            out_exception_ecode       <= 6'b0;
            out_exception_esubcode    <= 9'b0;
            out_exception_badv_valid  <= 1'b0;
            out_exception_badv        <= 32'b0;
            icache_req_valid          <= 1'b0;
            icache_req_addr           <= 32'b0;
        end else begin
            if (out_slot_ready_w) begin
                if (pend_ready_w) begin
                    out_valid                <= 1'b1;
                    out_pc                   <= pend_pc;
                    out_inst                 <= pend_exception_valid ? 32'h03400000 : icache_resp_data;
                    out_pred_taken           <= pend_pred_taken;
                    out_pred_target          <= pend_pred_target;
                    out_exception_valid      <= pend_exception_valid;
                    out_exception_ecode      <= pend_exception_ecode;
                    out_exception_esubcode   <= pend_exception_esubcode;
                    out_exception_badv_valid <= pend_exception_badv_valid;
                    out_exception_badv       <= pend_exception_badv;
                    pend_valid               <= 1'b0;
                    pend_req_sent            <= 1'b0;
                end else begin
                    out_valid                <= 1'b0;
                    out_exception_valid      <= 1'b0;
                    out_exception_ecode      <= 6'b0;
                    out_exception_esubcode   <= 9'b0;
                    out_exception_badv_valid <= 1'b0;
                    out_exception_badv       <= 32'b0;
                end
            end

            if (icache_req_valid && icache_req_ready) begin
                icache_req_valid <= 1'b0;
                pend_req_sent    <= 1'b1;
            end

            if (in_fire_w) begin
                pend_valid                <= 1'b1;
                pend_req_sent             <= req_exception_valid_w;
                pend_pc                   <= in_pc;
                pend_pred_taken           <= in_pred_taken;
                pend_pred_target          <= in_pred_target;
                pend_exception_valid      <= req_exception_valid_w;
                pend_exception_ecode      <= req_exception_ecode_w;
                pend_exception_esubcode   <= req_exception_esubcode_w;
                pend_exception_badv_valid <= req_exception_valid_w;
                pend_exception_badv       <= in_pc;
                if (!req_exception_valid_w) begin
                    icache_req_valid <= 1'b1;
                    icache_req_addr  <= req_addr_w;
                end
            end
        end
    end

`ifdef VERILATOR
`ifdef PERF_MONI
    integer dbg_accept_cnt = 0;
    integer dbg_accept_pred_taken_cnt = 0;
    integer dbg_emit_cnt = 0;
    integer dbg_emit_pred_taken_cnt = 0;
    final begin
        $display("[S2F2][DBG] accept=%0d accept_pred_taken=%0d emit=%0d emit_pred_taken=%0d",
                 dbg_accept_cnt, dbg_accept_pred_taken_cnt,
                 dbg_emit_cnt, dbg_emit_pred_taken_cnt);
    end
    always @(posedge clk) begin
        if (!reset) begin
            if (in_fire_w) begin
                dbg_accept_cnt <= dbg_accept_cnt + 1;
                if (in_pred_taken)
                    dbg_accept_pred_taken_cnt <= dbg_accept_pred_taken_cnt + 1;
            end
            if (out_fire_w) begin
                dbg_emit_cnt <= dbg_emit_cnt + 1;
                if (pend_pred_taken)
                    dbg_emit_pred_taken_cnt <= dbg_emit_pred_taken_cnt + 1;
            end
        end
    end
`endif
`endif

endmodule

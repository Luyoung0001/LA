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
    input  wire        tlb_resp_valid,
    input  wire [31:0] tlb_query_paddr,
    input  wire        tlb_exception_valid,
    input  wire [5:0]  tlb_exception_ecode,
    output wire        icache_req_valid,
    output wire [31:0] icache_req_addr,
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

    localparam FIFO_DEPTH = 8;
    localparam PTR_W = 3;
    localparam COUNT_W = 4;
    localparam [COUNT_W-1:0] FIFO_DEPTH_COUNT = FIFO_DEPTH[COUNT_W-1:0];

    reg [PTR_W-1:0]   fifo_head_r;
    reg [PTR_W-1:0]   fifo_tail_r;
    reg [PTR_W-1:0]   issue_ptr_r;
    reg [PTR_W-1:0]   resp_ptr_r;
    reg [COUNT_W-1:0] fifo_count_r;
    reg [COUNT_W-1:0] req_pending_count_r;
    reg [COUNT_W-1:0] resp_pending_count_r;
    reg               exception_pending_r;
    reg               tlb_pending_r;
    reg        tlb_pending_pc_adef_r;
    reg [31:0] tlb_pending_pc_r;
    reg        tlb_pending_pred_taken_r;
    reg [31:0] tlb_pending_pred_target_r;

    reg        fifo_data_valid_r           [0:FIFO_DEPTH-1];
    reg [31:0] fifo_pc_r                   [0:FIFO_DEPTH-1];
    reg [31:0] fifo_req_addr_r             [0:FIFO_DEPTH-1];
    reg [31:0] fifo_inst_r                 [0:FIFO_DEPTH-1];
    reg        fifo_pred_taken_r           [0:FIFO_DEPTH-1];
    reg [31:0] fifo_pred_target_r          [0:FIFO_DEPTH-1];
    reg        fifo_exception_valid_r      [0:FIFO_DEPTH-1];
    reg [5:0]  fifo_exception_ecode_r      [0:FIFO_DEPTH-1];
    reg [8:0]  fifo_exception_esubcode_r   [0:FIFO_DEPTH-1];
    reg        fifo_exception_badv_valid_r [0:FIFO_DEPTH-1];
    reg [31:0] fifo_exception_badv_r       [0:FIFO_DEPTH-1];

    wire        pc_adef_w;
    wire        tlb_pending_ready_w;
    wire        tlb_pending_exception_valid_w;
    wire [5:0]  tlb_pending_exception_ecode_w;
    wire [8:0]  tlb_pending_exception_esubcode_w;
    wire        in_fire_w;
    wire        out_slot_ready_w;
    wire        out_fire_w;
    wire        fifo_full_w;
    wire        fifo_empty_w;
    wire [COUNT_W:0] fifo_count_after_w;
    wire        fifo_room_after_pending_w;
    wire        head_ready_w;
    wire        issue_fire_w;
    wire        fifo_enqueue_w;
    wire        req_enqueue_w;
    wire        resp_take_w;
    wire        pending_exception_ready_w;
    integer reset_i;

    assign pc_adef_w = |in_pc[1:0];
    assign tlb_pending_ready_w = tlb_pending_r &&
                                 (tlb_pending_pc_adef_r || tlb_resp_valid);
    assign tlb_pending_exception_valid_w = tlb_pending_pc_adef_r ||
                                           tlb_exception_valid;
    assign tlb_pending_exception_ecode_w = tlb_pending_pc_adef_r ?
                                           6'h08 : tlb_exception_ecode;
    assign tlb_pending_exception_esubcode_w = 9'h0;
    assign pending_exception_ready_w = tlb_pending_ready_w &&
                                       tlb_pending_exception_valid_w;

    assign fifo_full_w = (fifo_count_r == FIFO_DEPTH_COUNT);
    assign fifo_empty_w = (fifo_count_r == {COUNT_W{1'b0}});
    assign fifo_enqueue_w = tlb_pending_ready_w;
    assign fifo_count_after_w = {1'b0, fifo_count_r} +
                                {{COUNT_W{1'b0}}, fifo_enqueue_w} -
                                {{COUNT_W{1'b0}}, out_fire_w};
    assign fifo_room_after_pending_w =
        (fifo_count_after_w < {1'b0, FIFO_DEPTH_COUNT});
    assign out_slot_ready_w = !out_valid || next_allowin;
    assign head_ready_w = !fifo_empty_w &&
                          (fifo_exception_valid_r[fifo_head_r] ||
                           fifo_data_valid_r[fifo_head_r]);
    assign out_fire_w = out_slot_ready_w && head_ready_w;
    assign s2_allowin = !flush &&
                        (!tlb_pending_r || tlb_pending_ready_w) &&
                        !exception_pending_r &&
                        !pending_exception_ready_w &&
                        fifo_room_after_pending_w;
    assign in_fire_w = in_valid && s2_allowin;
    assign req_enqueue_w = fifo_enqueue_w && !tlb_pending_exception_valid_w;
    assign resp_take_w = icache_resp_valid &&
                         (resp_pending_count_r != {COUNT_W{1'b0}});
    assign icache_req_valid = (req_pending_count_r != {COUNT_W{1'b0}});
    assign icache_req_addr = fifo_req_addr_r[issue_ptr_r];
    assign issue_fire_w = icache_req_valid && icache_req_ready;

    assign tlb_query_valid = in_fire_w && !pc_adef_w;
    assign tlb_query_write = 1'b0;
    assign tlb_query_vaddr = in_pc;

    always @(posedge clk) begin
        if (reset || flush) begin
            fifo_head_r               <= {PTR_W{1'b0}};
            fifo_tail_r               <= {PTR_W{1'b0}};
            issue_ptr_r               <= {PTR_W{1'b0}};
            resp_ptr_r                <= {PTR_W{1'b0}};
            fifo_count_r              <= {COUNT_W{1'b0}};
            req_pending_count_r       <= {COUNT_W{1'b0}};
            resp_pending_count_r      <= {COUNT_W{1'b0}};
            exception_pending_r       <= 1'b0;
            tlb_pending_r             <= 1'b0;
            tlb_pending_pc_adef_r     <= 1'b0;
            tlb_pending_pc_r          <= 32'b0;
            tlb_pending_pred_taken_r  <= 1'b0;
            tlb_pending_pred_target_r <= 32'b0;
            for (reset_i = 0; reset_i < FIFO_DEPTH; reset_i = reset_i + 1) begin
                fifo_data_valid_r[reset_i]           <= 1'b0;
                fifo_pc_r[reset_i]                   <= 32'b0;
                fifo_req_addr_r[reset_i]             <= 32'b0;
                fifo_inst_r[reset_i]                 <= 32'h03400000;
                fifo_pred_taken_r[reset_i]           <= 1'b0;
                fifo_pred_target_r[reset_i]          <= 32'b0;
                fifo_exception_valid_r[reset_i]      <= 1'b0;
                fifo_exception_ecode_r[reset_i]      <= 6'b0;
                fifo_exception_esubcode_r[reset_i]   <= 9'b0;
                fifo_exception_badv_valid_r[reset_i] <= 1'b0;
                fifo_exception_badv_r[reset_i]       <= 32'b0;
            end
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
        end else begin
            if (out_slot_ready_w) begin
                if (head_ready_w) begin
                    out_valid                <= 1'b1;
                    out_pc                   <= fifo_pc_r[fifo_head_r];
                    out_inst                 <= fifo_exception_valid_r[fifo_head_r] ?
                                                32'h03400000 : fifo_inst_r[fifo_head_r];
                    out_pred_taken           <= fifo_pred_taken_r[fifo_head_r];
                    out_pred_target          <= fifo_pred_target_r[fifo_head_r];
                    out_exception_valid      <= fifo_exception_valid_r[fifo_head_r];
                    out_exception_ecode      <= fifo_exception_ecode_r[fifo_head_r];
                    out_exception_esubcode   <= fifo_exception_esubcode_r[fifo_head_r];
                    out_exception_badv_valid <= fifo_exception_badv_valid_r[fifo_head_r];
                    out_exception_badv       <= fifo_exception_badv_r[fifo_head_r];
                end else begin
                    out_valid                <= 1'b0;
                    out_exception_valid      <= 1'b0;
                    out_exception_ecode      <= 6'b0;
                    out_exception_esubcode   <= 9'b0;
                    out_exception_badv_valid <= 1'b0;
                    out_exception_badv       <= 32'b0;
                end
            end

            if (issue_fire_w) begin
                issue_ptr_r <= issue_ptr_r + {{(PTR_W-1){1'b0}}, 1'b1};
            end

            if (resp_take_w) begin
                fifo_data_valid_r[resp_ptr_r] <= 1'b1;
                fifo_inst_r[resp_ptr_r]       <= icache_resp_data;
                resp_ptr_r <= resp_ptr_r + {{(PTR_W-1){1'b0}}, 1'b1};
            end

            if (out_fire_w) begin
                fifo_data_valid_r[fifo_head_r]           <= 1'b0;
                fifo_exception_valid_r[fifo_head_r]      <= 1'b0;
                fifo_exception_badv_valid_r[fifo_head_r] <= 1'b0;
                fifo_head_r <= fifo_head_r + {{(PTR_W-1){1'b0}}, 1'b1};
                if (fifo_exception_valid_r[fifo_head_r]) begin
                    exception_pending_r <= 1'b0;
                    issue_ptr_r <= fifo_head_r + {{(PTR_W-1){1'b0}}, 1'b1};
                    resp_ptr_r  <= fifo_head_r + {{(PTR_W-1){1'b0}}, 1'b1};
                end
            end

            if (fifo_enqueue_w) begin
                fifo_data_valid_r[fifo_tail_r]           <= tlb_pending_exception_valid_w;
                fifo_pc_r[fifo_tail_r]                   <= tlb_pending_pc_r;
                fifo_req_addr_r[fifo_tail_r]             <= tlb_query_paddr;
                fifo_inst_r[fifo_tail_r]                 <= 32'h03400000;
                fifo_pred_taken_r[fifo_tail_r]           <= tlb_pending_pred_taken_r;
                fifo_pred_target_r[fifo_tail_r]          <= tlb_pending_pred_target_r;
                fifo_exception_valid_r[fifo_tail_r]      <= tlb_pending_exception_valid_w;
                fifo_exception_ecode_r[fifo_tail_r]      <= tlb_pending_exception_ecode_w;
                fifo_exception_esubcode_r[fifo_tail_r]   <= tlb_pending_exception_esubcode_w;
                fifo_exception_badv_valid_r[fifo_tail_r] <= tlb_pending_exception_valid_w;
                fifo_exception_badv_r[fifo_tail_r]       <= tlb_pending_pc_r;
                fifo_tail_r <= fifo_tail_r + {{(PTR_W-1){1'b0}}, 1'b1};
                if (tlb_pending_exception_valid_w)
                    exception_pending_r <= 1'b1;
            end

            if (in_fire_w) begin
                tlb_pending_r             <= 1'b1;
                tlb_pending_pc_adef_r     <= pc_adef_w;
                tlb_pending_pc_r          <= in_pc;
                tlb_pending_pred_taken_r  <= in_pred_taken;
                tlb_pending_pred_target_r <= in_pred_target;
            end else if (tlb_pending_ready_w) begin
                tlb_pending_r <= 1'b0;
            end

            case ({fifo_enqueue_w, out_fire_w})
                2'b10: fifo_count_r <= fifo_count_r + {{(COUNT_W-1){1'b0}}, 1'b1};
                2'b01: fifo_count_r <= fifo_count_r - {{(COUNT_W-1){1'b0}}, 1'b1};
                default: ;
            endcase

            case ({req_enqueue_w, issue_fire_w})
                2'b10: req_pending_count_r <= req_pending_count_r + {{(COUNT_W-1){1'b0}}, 1'b1};
                2'b01: req_pending_count_r <= req_pending_count_r - {{(COUNT_W-1){1'b0}}, 1'b1};
                default: ;
            endcase

            case ({issue_fire_w, resp_take_w})
                2'b10: resp_pending_count_r <= resp_pending_count_r + {{(COUNT_W-1){1'b0}}, 1'b1};
                2'b01: resp_pending_count_r <= resp_pending_count_r - {{(COUNT_W-1){1'b0}}, 1'b1};
                default: ;
            endcase
        end
    end

`ifdef VERILATOR
`ifdef PERF_MONI
    integer dbg_cycle_cnt = 0;
    integer dbg_accept_cnt = 0;
    integer dbg_accept_pred_taken_cnt = 0;
    integer dbg_emit_cnt = 0;
    integer dbg_emit_pred_taken_cnt = 0;
    integer dbg_req_start_cnt = 0;
    integer dbg_req_fire_cnt = 0;
    integer dbg_resp_cnt = 0;
    integer dbg_flush_cnt = 0;
    integer dbg_block_pend_cnt = 0;
    integer dbg_block_out_cnt = 0;
    integer dbg_wait_req_ready_cnt = 0;
    integer dbg_wait_resp_cnt = 0;
    integer dbg_no_input_cnt = 0;
    integer dbg_fifo_level_sum = 0;
    integer dbg_fifo_level_max = 0;
    integer dbg_req_pending_max = 0;
    integer dbg_resp_pending_max = 0;
    wire [31:0] dbg_fifo_count_w = {{(32-COUNT_W){1'b0}}, fifo_count_r};
    wire [31:0] dbg_req_pending_count_w = {{(32-COUNT_W){1'b0}}, req_pending_count_r};
    wire [31:0] dbg_resp_pending_count_w = {{(32-COUNT_W){1'b0}}, resp_pending_count_r};
    final begin
        $display("[PERF][S2F2] cycles=%0d accept=%0d emit=%0d req_start=%0d req_fire=%0d resp=%0d flush=%0d",
                 dbg_cycle_cnt, dbg_accept_cnt, dbg_emit_cnt,
                 dbg_req_start_cnt, dbg_req_fire_cnt, dbg_resp_cnt,
                 dbg_flush_cnt);
        $display("[PERF][S2F2] block_pend=%0d block_out=%0d wait_req_ready=%0d wait_resp=%0d no_input=%0d accept_pred_taken=%0d emit_pred_taken=%0d",
                 dbg_block_pend_cnt, dbg_block_out_cnt,
                 dbg_wait_req_ready_cnt, dbg_wait_resp_cnt,
                 dbg_no_input_cnt, dbg_accept_pred_taken_cnt,
                 dbg_emit_pred_taken_cnt);
        $display("[PERF][S2F2] fifo_level_sum=%0d fifo_level_max=%0d req_pending_max=%0d resp_pending_max=%0d",
                 dbg_fifo_level_sum, dbg_fifo_level_max,
                 dbg_req_pending_max, dbg_resp_pending_max);
    end
    always @(posedge clk) begin
        if (!reset) begin
            dbg_cycle_cnt <= dbg_cycle_cnt + 1;
            dbg_fifo_level_sum <= dbg_fifo_level_sum + dbg_fifo_count_w;
            if (dbg_fifo_count_w > dbg_fifo_level_max)
                dbg_fifo_level_max <= dbg_fifo_count_w;
            if (dbg_req_pending_count_w > dbg_req_pending_max)
                dbg_req_pending_max <= dbg_req_pending_count_w;
            if (dbg_resp_pending_count_w > dbg_resp_pending_max)
                dbg_resp_pending_max <= dbg_resp_pending_count_w;
            if (flush)
                dbg_flush_cnt <= dbg_flush_cnt + 1;
            if (in_fire_w) begin
                dbg_accept_cnt <= dbg_accept_cnt + 1;
                if (in_pred_taken)
                    dbg_accept_pred_taken_cnt <= dbg_accept_pred_taken_cnt + 1;
            end
            if (req_enqueue_w)
                dbg_req_start_cnt <= dbg_req_start_cnt + 1;
            if (issue_fire_w)
                dbg_req_fire_cnt <= dbg_req_fire_cnt + 1;
            if (icache_resp_valid)
                dbg_resp_cnt <= dbg_resp_cnt + 1;
            if (out_fire_w) begin
                dbg_emit_cnt <= dbg_emit_cnt + 1;
                if (fifo_pred_taken_r[fifo_head_r])
                    dbg_emit_pred_taken_cnt <= dbg_emit_pred_taken_cnt + 1;
            end
            if (in_valid && !s2_allowin &&
                (fifo_full_w || tlb_pending_r || !fifo_room_after_pending_w))
                dbg_block_pend_cnt <= dbg_block_pend_cnt + 1;
            if (head_ready_w && !out_slot_ready_w)
                dbg_block_out_cnt <= dbg_block_out_cnt + 1;
            if (icache_req_valid && !icache_req_ready)
                dbg_wait_req_ready_cnt <= dbg_wait_req_ready_cnt + 1;
            if (!fifo_empty_w && !head_ready_w && !icache_resp_valid)
                dbg_wait_resp_cnt <= dbg_wait_resp_cnt + 1;
            if (s2_allowin && !in_valid)
                dbg_no_input_cnt <= dbg_no_input_cnt + 1;
        end
    end
`endif
`endif

endmodule

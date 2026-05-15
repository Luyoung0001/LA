module la_l1i_adapter (
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,
    input  wire        cacop_valid,
    input  wire [1:0]  cacop_mode,
    input  wire [31:0] cacop_addr,

    input  wire        req_valid,
    input  wire [31:0] req_addr,
    output wire        req_ready,
    output wire        resp_valid,
    output wire [31:0] resp_data,

    output wire        axi_req_valid,
    output wire [31:0] axi_req_addr,
    input  wire        axi_req_ready,
    input  wire        axi_resp_valid,
    input  wire [31:0] axi_resp_data
);

    localparam [1:0] FILL_IDLE = 2'd0;
    localparam [1:0] FILL_REQ  = 2'd1;
    localparam [1:0] FILL_RESP = 2'd2;

    wire        l2_req_valid_w;
    wire [31:0] l2_req_addr_w;
    wire        l2_req_is_prefetch_w;
    wire        l2_req_ready_w;
    wire        icache_resp_valid_w;
    wire [31:0] icache_resp_data_w;
    reg         resp_valid_r;
    reg [31:0]  resp_data_r;
    reg         l2_resp_valid_r;
    reg [31:0]  l2_resp_data0_r, l2_resp_data1_r, l2_resp_data2_r, l2_resp_data3_r;

    reg [1:0]   fill_state_r;
    reg [1:0]   fill_word_r;
    reg [31:0]  fill_base_r;
    reg [31:0]  line_word0_r, line_word1_r, line_word2_r, line_word3_r;
    reg         axi_req_valid_r;
    // Tracks AXI burst transactions that were started but interrupted by
    // flush. Each remaining beat will arrive on axi_resp_valid; we silently
    // consume them and pulse l2_resp_valid on the final beat so cpu_l1_icache
    // clears stale_l2_resp_pending_q.
    reg [2:0]   axi_outstanding_r;
    // A flush can coincide with an L1I miss request that the cache considers
    // accepted but this adapter has not yet launched to AXI. No real AXI
    // response will arrive in that case, so pulse a dummy L2 response after
    // the flush to release cpu_l1_icache's stale-response wait state.
    reg         stale_clear_pulse_r;

    reg         cacop_pend_r;
    reg [1:0]   cacop_mode_r;
    reg [31:0]  cacop_addr_r;
    wire        cacop_ready_w;
    wire        cacop_done_w;
    wire        cacop_to_cache_valid = cacop_pend_r && cacop_ready_w;

    wire        resp_fault_w, resp_line_valid_w;
    wire [31:0] resp_line_addr_w, resp_line_data0_w, resp_line_data1_w, resp_line_data2_w, resp_line_data3_w;
    wire        redirect_probe_hit_w, redirect_fast_valid_w, redirect_fast_line_valid_w;
    wire [31:0] redirect_fast_addr_w, redirect_fast_instr_w, redirect_fast_line_addr_w;
    wire [31:0] redirect_fast_line_data0_w, redirect_fast_line_data1_w;
    wire [31:0] redirect_fast_line_data2_w, redirect_fast_line_data3_w;

    wire unused_sb = &{1'b0, l2_req_is_prefetch_w, redirect_probe_hit_w,
                       redirect_fast_valid_w, redirect_fast_addr_w,
                       redirect_fast_instr_w, redirect_fast_line_valid_w,
                       redirect_fast_line_addr_w, redirect_fast_line_data0_w,
                       redirect_fast_line_data1_w, redirect_fast_line_data2_w,
                       redirect_fast_line_data3_w, resp_fault_w, resp_line_valid_w,
                       resp_line_addr_w, resp_line_data0_w, resp_line_data1_w,
                       resp_line_data2_w, resp_line_data3_w, cacop_done_w};

    wire [31:0] aligned_l2_addr_w = {l2_req_addr_w[31:4], 4'b0};
    wire l2_req_accept_w  = l2_req_valid_w && l2_req_ready_w;
    wire axi_req_fire_w   = axi_req_valid_r && axi_req_ready;
    wire axi_resp_fire_w  = axi_resp_valid && (fill_state_r == FILL_RESP);
    wire flush_real_resp_pending_w =
        ((fill_state_r == FILL_RESP) && !axi_resp_valid) ||
        ((fill_state_r == FILL_REQ) && axi_req_fire_w);
    wire flush_synth_clear_w =
        (l2_req_accept_w || (fill_state_r != FILL_IDLE)) &&
        !flush_real_resp_pending_w;
    wire flush_drain_stale_resp_w = (axi_outstanding_r != 3'd0) && axi_resp_valid;
    wire [3:0] flush_outstanding_next_w =
        {1'b0, axi_outstanding_r} +
        {3'b0, flush_real_resp_pending_w} -
        {3'b0, flush_drain_stale_resp_w};
    wire flush_stale_done_w =
        (flush_outstanding_next_w == 4'd0) &&
        (flush_synth_clear_w || flush_drain_stale_resp_w);

    assign l2_req_ready_w = (fill_state_r == FILL_IDLE) && (axi_outstanding_r == 3'd0);
    assign axi_req_valid  = axi_req_valid_r;
    assign axi_req_addr   = fill_base_r + {28'b0, fill_word_r, 2'b00};
    assign resp_valid     = resp_valid_r;
    assign resp_data      = resp_data_r;

    // Buffer the upstream request so s2_f2 doesn't need to track icache
    // req_ready_o (which can drop momentarily on CACOP/stale conditions).
    // External req_ready is always 1; we replay buffered req to cpu_l1_icache
    // until it accepts.
    reg        pend_req_valid_r;
    reg [31:0] pend_req_addr_r;
    wire       icache_req_ready_w;

    assign req_ready = !pend_req_valid_r || icache_req_ready_w;
    wire       cache_req_valid_w = pend_req_valid_r;
    wire [31:0] cache_req_addr_w = pend_req_addr_r;

    cpu_l1_icache #(.XLEN(32), .ILEN(32), .NUM_WAYS(4), .NUM_LINES(128), .LINE_SIZE(16))
    u_cpu_l1_icache (
        .clk(clk), .rst_n(~reset), .flush(flush),
        .req_valid_i(cache_req_valid_w), .req_ready_o(icache_req_ready_w), .req_addr_i(cache_req_addr_w),
        .shadow_fetch_valid_i(1'b0), .shadow_fetch_addr_i(32'b0),
        .redirect_probe_valid_i(1'b0), .redirect_probe_addr_i(32'b0),
        .redirect_probe_hit_o(redirect_probe_hit_w),
        .redirect_fast_valid_o(redirect_fast_valid_w),
        .redirect_fast_addr_o(redirect_fast_addr_w),
        .redirect_fast_instr_o(redirect_fast_instr_w),
        .redirect_fast_line_valid_o(redirect_fast_line_valid_w),
        .redirect_fast_line_addr_o(redirect_fast_line_addr_w),
        .redirect_fast_line_data_o_0(redirect_fast_line_data0_w),
        .redirect_fast_line_data_o_1(redirect_fast_line_data1_w),
        .redirect_fast_line_data_o_2(redirect_fast_line_data2_w),
        .redirect_fast_line_data_o_3(redirect_fast_line_data3_w),
        .redirect_fast_consume_i(1'b0),
        .resp_valid_o(icache_resp_valid_w), .resp_instr_o(icache_resp_data_w),
        .resp_fault_o(resp_fault_w),
        .resp_line_valid_o(resp_line_valid_w), .resp_line_addr_o(resp_line_addr_w),
        .resp_line_data_o_0(resp_line_data0_w), .resp_line_data_o_1(resp_line_data1_w),
        .resp_line_data_o_2(resp_line_data2_w), .resp_line_data_o_3(resp_line_data3_w),
        .cacop_valid_i(cacop_to_cache_valid), .cacop_mode_i(cacop_mode_r),
        .cacop_addr_i(cacop_addr_r), .cacop_ready_o(cacop_ready_w),
        .cacop_done_o(cacop_done_w),
        .l2_req_valid_o(l2_req_valid_w), .l2_req_addr_o(l2_req_addr_w),
        .l2_req_is_prefetch_o(l2_req_is_prefetch_w), .l2_req_ready_i(l2_req_ready_w),
        .l2_resp_valid_i(l2_resp_valid_r),
        .l2_resp_data_i_0(l2_resp_data0_r), .l2_resp_data_i_1(l2_resp_data1_r),
        .l2_resp_data_i_2(l2_resp_data2_r), .l2_resp_data_i_3(l2_resp_data3_r),
        .l2_pf_resp_valid_i(1'b0),
        .l2_pf_resp_addr_i(32'b0),
        .l2_pf_resp_data_i_0(32'b0), .l2_pf_resp_data_i_1(32'b0),
        .l2_pf_resp_data_i_2(32'b0), .l2_pf_resp_data_i_3(32'b0)
    );

    always @(posedge clk) begin
        if (reset || flush) begin
            pend_req_valid_r <= 1'b0;
            pend_req_addr_r  <= 32'b0;
        end else begin
            if (req_valid && !pend_req_valid_r) begin
                pend_req_valid_r <= 1'b1;
                pend_req_addr_r  <= req_addr;
            end else if (pend_req_valid_r && icache_req_ready_w) begin
                if (req_valid) begin
                    pend_req_valid_r <= 1'b1;
                    pend_req_addr_r  <= req_addr;
                end else begin
                    pend_req_valid_r <= 1'b0;
                end
            end
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            cacop_pend_r <= 1'b0;
            cacop_mode_r <= 2'b0;
            cacop_addr_r <= 32'b0;
        end else begin
            if (cacop_valid && !cacop_pend_r) begin
                cacop_pend_r <= 1'b1;
                cacop_mode_r <= cacop_mode;
                cacop_addr_r <= cacop_addr;
            end else if (cacop_pend_r && cacop_ready_w) begin
                cacop_pend_r <= 1'b0;
            end
        end
    end

    always @(posedge clk) begin
        if (reset || flush) begin
            fill_state_r    <= FILL_IDLE;
            fill_word_r     <= 2'b0;
            fill_base_r     <= 32'b0;
            line_word0_r    <= 32'b0;
            line_word1_r    <= 32'b0;
            line_word2_r    <= 32'b0;
            line_word3_r    <= 32'b0;
            axi_req_valid_r <= 1'b0;
            l2_resp_valid_r <= 1'b0;
            l2_resp_data0_r <= 32'b0;
            l2_resp_data1_r <= 32'b0;
            l2_resp_data2_r <= 32'b0;
            l2_resp_data3_r <= 32'b0;
            resp_valid_r    <= 1'b0;
            resp_data_r     <= 32'b0;
            if (reset) begin
                axi_outstanding_r <= 3'd0;
                stale_clear_pulse_r <= 1'b0;
            end else if (flush) begin
                axi_outstanding_r <= flush_outstanding_next_w[2:0];
                stale_clear_pulse_r <= stale_clear_pulse_r || flush_stale_done_w;
            end
        end else begin
            l2_resp_valid_r <= 1'b0;
            resp_valid_r <= icache_resp_valid_w;
            if (icache_resp_valid_w) resp_data_r <= icache_resp_data_w;

            if (stale_clear_pulse_r) begin
                stale_clear_pulse_r <= 1'b0;
                l2_resp_valid_r <= 1'b1;
            end

            // Drain stale AXI responses left over from a flushed fill. Pulse
            // l2_resp_valid on the LAST drained beat so cpu_l1_icache clears
            // stale_l2_resp_pending_q.
            if (axi_outstanding_r != 3'd0 && axi_resp_valid) begin
                axi_outstanding_r <= axi_outstanding_r - 3'd1;
                if (axi_outstanding_r == 3'd1)
                    l2_resp_valid_r <= 1'b1;
            end

            case (fill_state_r)
                FILL_IDLE: begin
                    axi_req_valid_r <= 1'b0;
                    if (l2_req_accept_w) begin
                        fill_base_r     <= aligned_l2_addr_w;
                        fill_word_r     <= 2'b0;
                        axi_req_valid_r <= 1'b1;
                        fill_state_r    <= FILL_REQ;
                    end
                end
                FILL_REQ: if (axi_req_fire_w) begin
                    axi_req_valid_r <= 1'b0;
                    fill_state_r    <= FILL_RESP;
                end
                FILL_RESP: if (axi_resp_fire_w) begin
                    case (fill_word_r)
                        2'd0: line_word0_r <= axi_resp_data;
                        2'd1: line_word1_r <= axi_resp_data;
                        2'd2: line_word2_r <= axi_resp_data;
                        default: line_word3_r <= axi_resp_data;
                    endcase
                    if (fill_word_r == 2'd3) begin
                        l2_resp_valid_r <= 1'b1;
                        l2_resp_data0_r <= line_word0_r;
                        l2_resp_data1_r <= line_word1_r;
                        l2_resp_data2_r <= line_word2_r;
                        l2_resp_data3_r <= axi_resp_data;
                        fill_state_r    <= FILL_IDLE;
                    end else begin
                        fill_word_r     <= fill_word_r + 2'd1;
                        axi_req_valid_r <= 1'b1;
                        fill_state_r    <= FILL_REQ;
                    end
                end
                default: begin
                    fill_state_r    <= FILL_IDLE;
                    axi_req_valid_r <= 1'b0;
                end
            endcase
        end
    end

endmodule

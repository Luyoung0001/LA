module la_l1i_adapter (
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,

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
    reg [31:0] resp_data_r;
    reg         l2_resp_valid_r;
    reg [31:0] l2_resp_data0_r;
    reg [31:0] l2_resp_data1_r;
    reg [31:0] l2_resp_data2_r;
    reg [31:0] l2_resp_data3_r;

    reg [1:0]  fill_state_r;
    reg [1:0]  fill_word_r;
    reg [31:0] fill_base_r;
    reg [31:0] line_word0_r;
    reg [31:0] line_word1_r;
    reg [31:0] line_word2_r;
    reg [31:0] line_word3_r;
    reg        axi_req_valid_r;

    wire [31:0] aligned_l2_addr_w = {l2_req_addr_w[31:4], 4'b0};
    wire        l2_req_accept_w = l2_req_valid_w && l2_req_ready_w;
    wire        axi_req_fire_w = axi_req_valid_r && axi_req_ready;
    wire        axi_resp_fire_w = axi_resp_valid && (fill_state_r == FILL_RESP);

    wire unused_icache_sideband;
    wire redirect_probe_hit_w;
    wire redirect_fast_valid_w;
    wire [31:0] redirect_fast_addr_w;
    wire [31:0] redirect_fast_instr_w;
    wire redirect_fast_line_valid_w;
    wire [31:0] redirect_fast_line_addr_w;
    wire [31:0] redirect_fast_line_data0_w;
    wire [31:0] redirect_fast_line_data1_w;
    wire [31:0] redirect_fast_line_data2_w;
    wire [31:0] redirect_fast_line_data3_w;
    wire resp_fault_w;
    wire resp_line_valid_w;
    wire [31:0] resp_line_addr_w;
    wire [31:0] resp_line_data0_w;
    wire [31:0] resp_line_data1_w;
    wire [31:0] resp_line_data2_w;
    wire [31:0] resp_line_data3_w;
    wire cacop_ready_w;
    wire cacop_done_w;
    wire l2_pf_resp_valid_unused;

    assign unused_icache_sideband = &{1'b0, l2_req_is_prefetch_w,
                                      redirect_probe_hit_w,
                                      redirect_fast_valid_w,
                                      redirect_fast_addr_w,
                                      redirect_fast_instr_w,
                                      redirect_fast_line_valid_w,
                                      redirect_fast_line_addr_w,
                                      redirect_fast_line_data0_w,
                                      redirect_fast_line_data1_w,
                                      redirect_fast_line_data2_w,
                                      redirect_fast_line_data3_w,
                                      resp_fault_w, resp_line_valid_w,
                                      resp_line_addr_w, resp_line_data0_w,
                                      resp_line_data1_w, resp_line_data2_w,
                                      resp_line_data3_w, cacop_ready_w,
                                      cacop_done_w, l2_pf_resp_valid_unused};

    assign l2_req_ready_w = (fill_state_r == FILL_IDLE);
    assign axi_req_valid  = axi_req_valid_r;
    assign axi_req_addr   = fill_base_r + {28'b0, fill_word_r, 2'b00};
    assign resp_valid     = resp_valid_r;
    assign resp_data      = resp_data_r;

    cpu_l1_icache #(
        .XLEN(32),
        .ILEN(32),
        .NUM_WAYS(4),
        .NUM_LINES(128),
        .LINE_SIZE(16)
    ) u_cpu_l1_icache (
        .clk                       (clk),
        .rst_n                     (~reset),
        .flush                     (flush),

        .req_valid_i               (req_valid),
        .req_ready_o               (req_ready),
        .req_addr_i                (req_addr),
        .shadow_fetch_valid_i      (1'b0),
        .shadow_fetch_addr_i       (32'b0),
        .redirect_probe_valid_i    (1'b0),
        .redirect_probe_addr_i     (32'b0),
        .redirect_probe_hit_o      (redirect_probe_hit_w),
        .redirect_fast_valid_o     (redirect_fast_valid_w),
        .redirect_fast_addr_o      (redirect_fast_addr_w),
        .redirect_fast_instr_o     (redirect_fast_instr_w),
        .redirect_fast_line_valid_o(redirect_fast_line_valid_w),
        .redirect_fast_line_addr_o (redirect_fast_line_addr_w),
        .redirect_fast_line_data_o_0(redirect_fast_line_data0_w),
        .redirect_fast_line_data_o_1(redirect_fast_line_data1_w),
        .redirect_fast_line_data_o_2(redirect_fast_line_data2_w),
        .redirect_fast_line_data_o_3(redirect_fast_line_data3_w),
        .redirect_fast_consume_i   (1'b0),
        .resp_valid_o              (icache_resp_valid_w),
        .resp_instr_o              (icache_resp_data_w),
        .resp_fault_o              (resp_fault_w),
        .resp_line_valid_o         (resp_line_valid_w),
        .resp_line_addr_o          (resp_line_addr_w),
        .resp_line_data_o_0        (resp_line_data0_w),
        .resp_line_data_o_1        (resp_line_data1_w),
        .resp_line_data_o_2        (resp_line_data2_w),
        .resp_line_data_o_3        (resp_line_data3_w),

        .cacop_valid_i             (1'b0),
        .cacop_mode_i              (2'b0),
        .cacop_addr_i              (32'b0),
        .cacop_ready_o             (cacop_ready_w),
        .cacop_done_o              (cacop_done_w),

        .l2_req_valid_o            (l2_req_valid_w),
        .l2_req_addr_o             (l2_req_addr_w),
        .l2_req_is_prefetch_o      (l2_req_is_prefetch_w),
        .l2_req_ready_i            (l2_req_ready_w),

        .l2_resp_valid_i           (l2_resp_valid_r),
        .l2_resp_data_i_0          (l2_resp_data0_r),
        .l2_resp_data_i_1          (l2_resp_data1_r),
        .l2_resp_data_i_2          (l2_resp_data2_r),
        .l2_resp_data_i_3          (l2_resp_data3_r),

        .l2_pf_resp_valid_i        (l2_pf_resp_valid_unused),
        .l2_pf_resp_addr_i         (32'b0),
        .l2_pf_resp_data_i_0       (32'b0),
        .l2_pf_resp_data_i_1       (32'b0),
        .l2_pf_resp_data_i_2       (32'b0),
        .l2_pf_resp_data_i_3       (32'b0)
    );

    assign l2_pf_resp_valid_unused = 1'b0;

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
        end else begin
            l2_resp_valid_r <= 1'b0;
            resp_valid_r <= icache_resp_valid_w;
            if (icache_resp_valid_w) begin
                resp_data_r <= icache_resp_data_w;
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

                FILL_REQ: begin
                    if (axi_req_fire_w) begin
                        axi_req_valid_r <= 1'b0;
                        fill_state_r    <= FILL_RESP;
                    end
                end

                FILL_RESP: begin
                    if (axi_resp_fire_w) begin
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
                end

                default: begin
                    fill_state_r    <= FILL_IDLE;
                    axi_req_valid_r <= 1'b0;
                end
            endcase
        end
    end

`ifdef VERILATOR
    always @(posedge clk) begin
        if ($test$plusargs("LA_L1I_LOG")) begin
            if (reset || flush) begin
                $display("[LA][L1I_ADAPTER][CLEAR] reset=%0d flush=%0d state=%0d",
                         reset, flush, fill_state_r);
            end else if (l2_req_valid_w || l2_req_accept_w || axi_req_fire_w ||
                         axi_resp_fire_w || l2_resp_valid_r || req_valid ||
                         resp_valid) begin
                $display("[LA][L1I_ADAPTER] state=%0d cpu_req(valid=%0d ready=%0d addr=0x%08x) cpu_resp(valid=%0d data=0x%08x) l2_req(valid=%0d ready=%0d addr=0x%08x pf=%0d) axi(valid=%0d ready=%0d addr=0x%08x resp=%0d rdata=0x%08x word=%0d l2_resp=%0d line={%08x,%08x,%08x,%08x}",
                         fill_state_r, req_valid, req_ready, req_addr,
                         resp_valid, resp_data, l2_req_valid_w, l2_req_ready_w,
                         l2_req_addr_w, l2_req_is_prefetch_w, axi_req_valid_r,
                         axi_req_ready, axi_req_addr, axi_resp_valid,
                         axi_resp_data, fill_word_r, l2_resp_valid_r,
                         l2_resp_data0_r, l2_resp_data1_r, l2_resp_data2_r,
                         l2_resp_data3_r);
            end
        end
    end
`endif

endmodule

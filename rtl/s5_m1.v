module s5_m1 (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_result,
    input  wire [31:0] in_op1,
    input  wire [31:0] in_op2,
    input  wire        in_is_load,
    input  wire        in_is_store,
    input  wire [31:0] in_store_data,
    input  wire        in_is_csr,
    input  wire        in_csr_we,
    input  wire [13:0] in_csr_addr,
    input  wire [31:0] in_csr_wdata,
    input  wire        in_exception_valid,
    input  wire [5:0]  in_exception_ecode,
    input  wire [8:0]  in_exception_esubcode,
    input  wire        in_exception_badv_valid,
    input  wire [31:0] in_exception_badv,
    output wire        d_tlb_query_valid,
    output wire        d_tlb_query_write,
    output wire [31:0] d_tlb_query_vaddr,
    input  wire        d_tlb_resp_valid,
    input  wire [31:0] d_tlb_resp_vaddr,
    input  wire [31:0] d_tlb_query_paddr,
    input  wire        d_tlb_exception_valid,
    input  wire [5:0]  d_tlb_exception_ecode,
    output reg         dcache_req_valid,
    output reg         dcache_req_write,
    output reg  [31:0] dcache_req_addr,
    output reg  [31:0] dcache_req_wdata,
    output reg  [3:0]  dcache_req_wstrb,
    input  wire        dcache_resp_valid,
    input  wire [31:0] dcache_resp_data,
    output wire        m1_allowin,
    output wire        m1_load_valid,
    output wire [4:0]  m1_load_rd,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_wb_data,
    output reg  [31:0] out_op1,
    output reg  [31:0] out_op2,
    output reg         out_wen,
    output reg         out_csr_we,
    output reg  [13:0] out_csr_addr,
    output reg  [31:0] out_csr_wdata,
    output reg         out_exception_valid,
    output reg  [5:0]  out_exception_ecode,
    output reg  [8:0]  out_exception_esubcode,
    output reg         out_exception_badv_valid,
    output reg  [31:0] out_exception_badv
);

    wire [5:0] op_31_26;
    wire [3:0] op_25_22;
    wire in_inst_ld_h;
    wire in_inst_ld_w;
    wire in_inst_ld_hu;
    wire in_inst_st_h;
    wire in_inst_st_w;
    wire in_inst_cacop;
    wire in_cacop_needs_translate;
    wire in_data_ale_w;
    wire in_mem_accept_w;
    wire in_d_tlb_needs_query_w;
    wire inst_b;
    wire inst_beq;
    wire inst_bne;
    wire inst_blt;
    wire inst_bge;
    wire inst_bltu;
    wire inst_bgeu;
    wire wb_wen_no_mem;
    wire [3:0] pend_op_25_22;
    wire pend_inst_ld_b;
    wire pend_inst_ld_h;
    wire pend_inst_ld_bu;
    wire pend_inst_ld_hu;
    wire pend_inst_st_b;
    wire pend_inst_st_h;
    wire pend_inst_cacop;
    wire pend_cacop_needs_translate;
    wire [31:0] pend_aligned_addr;
    wire [31:0] pend_aligned_paddr;
    wire [3:0] store_wstrb_w;
    wire [31:0] store_wdata_w;
    wire [7:0] load_byte_w;
    wire [15:0] load_half_w;
    wire [31:0] load_result_w;
    wire        d_tlb_needs_query_w;
    wire        d_tlb_resp_match_w;

    reg        pend_valid;
    reg        pend_req_sent;
    reg        pend_tlb_wait;
    reg [31:0] pend_pc;
    reg [31:0] pend_inst;
    reg [4:0]  pend_rd;
    reg [31:0] pend_result;
    reg [31:0] pend_op1;
    reg [31:0] pend_op2;
    reg        pend_is_load;
    reg        pend_is_store;
    reg [31:0] pend_store_data;
    reg        pend_exception_valid;
    reg [5:0]  pend_exception_ecode;
    reg [8:0]  pend_exception_esubcode;
    reg        pend_exception_badv_valid;
    reg [31:0] pend_exception_badv;

    assign m1_allowin = !pend_valid;
    assign m1_load_valid = pend_valid && pend_is_load;
    assign m1_load_rd = pend_rd;

    assign op_31_26 = in_inst[31:26];
    assign op_25_22 = in_inst[25:22];
    assign in_inst_ld_h  = in_is_load && (op_25_22 == 4'h1);
    assign in_inst_ld_w  = in_is_load && (op_25_22 == 4'h2);
    assign in_inst_ld_hu = in_is_load && (op_25_22 == 4'h9);
    assign in_inst_st_h  = in_is_store && (op_25_22 == 4'h5);
    assign in_inst_st_w  = in_is_store && (op_25_22 == 4'h6);
    assign in_inst_cacop = (op_31_26 == 6'h01) && (op_25_22 == 4'h8);
    assign in_cacop_needs_translate = in_inst_cacop && (in_inst[4:3] == 2'b10);
    assign in_data_ale_w = ((in_inst_ld_h || in_inst_ld_hu || in_inst_st_h) && in_result[0]) ||
                           ((in_inst_ld_w || in_inst_st_w) && (in_result[1:0] != 2'b00));
    assign inst_b   = (op_31_26 == 6'h14);
    assign inst_beq = (op_31_26 == 6'h16);
    assign inst_bne = (op_31_26 == 6'h17);
    assign inst_blt = (op_31_26 == 6'h18);
    assign inst_bge = (op_31_26 == 6'h19);
    assign inst_bltu = (op_31_26 == 6'h1a);
    assign inst_bgeu = (op_31_26 == 6'h1b);
    // Branches without link do not write GPR; bl/jirl keep link writeback.
    assign wb_wen_no_mem = ~(inst_b | inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu);

    assign pend_op_25_22 = pend_inst[25:22];
    assign pend_inst_ld_b  = (pend_op_25_22 == 4'h0);
    assign pend_inst_ld_h  = (pend_op_25_22 == 4'h1);
    assign pend_inst_ld_bu = (pend_op_25_22 == 4'h8);
    assign pend_inst_ld_hu = (pend_op_25_22 == 4'h9);
    assign pend_inst_st_b  = (pend_op_25_22 == 4'h4);
    assign pend_inst_st_h  = (pend_op_25_22 == 4'h5);
    assign pend_inst_cacop = (pend_inst[31:26] == 6'h01) && (pend_inst[25:22] == 4'h8);
    assign pend_cacop_needs_translate = pend_inst_cacop && (pend_inst[4:3] == 2'b10);

    assign pend_aligned_addr = {pend_result[31:2], 2'b0};
    assign pend_aligned_paddr = {d_tlb_query_paddr[31:2], 2'b0};
    assign d_tlb_needs_query_w = pend_valid && !pend_req_sent && !pend_exception_valid &&
                                 ((pend_is_load && !pend_inst_cacop) || pend_is_store ||
                                  pend_cacop_needs_translate);
    assign in_mem_accept_w = !pend_valid && in_valid && (in_is_load || in_is_store);
    assign in_d_tlb_needs_query_w = in_mem_accept_w && !in_exception_valid && !in_data_ale_w &&
                                    ((in_is_load && !in_inst_cacop) || in_is_store ||
                                     in_cacop_needs_translate);
    assign d_tlb_query_valid = in_d_tlb_needs_query_w ||
                               (d_tlb_needs_query_w && !pend_tlb_wait);
    assign d_tlb_query_write = in_d_tlb_needs_query_w ?
                               (in_is_store && !in_inst_cacop) :
                               (pend_is_store && !pend_inst_cacop);
    assign d_tlb_query_vaddr = in_d_tlb_needs_query_w ? in_result : pend_result;
    assign d_tlb_resp_match_w = d_tlb_resp_valid &&
                                (d_tlb_resp_vaddr == pend_result);
    assign store_wstrb_w = pend_inst_st_b ? (4'b0001 << pend_result[1:0]) :
                           pend_inst_st_h ? (pend_result[1] ? 4'b1100 : 4'b0011) :
                                            4'b1111;
    assign store_wdata_w = pend_inst_st_b ? ({24'b0, pend_store_data[7:0]} << {pend_result[1:0], 3'b000}) :
                           pend_inst_st_h ? ({16'b0, pend_store_data[15:0]} << {pend_result[1], 4'b0000}) :
                                            pend_store_data;
    assign load_byte_w = (pend_result[1:0] == 2'b00) ? dcache_resp_data[7:0] :
                         (pend_result[1:0] == 2'b01) ? dcache_resp_data[15:8] :
                         (pend_result[1:0] == 2'b10) ? dcache_resp_data[23:16] :
                                                       dcache_resp_data[31:24];
    assign load_half_w = pend_result[1] ? dcache_resp_data[31:16] : dcache_resp_data[15:0];
    assign load_result_w = pend_inst_ld_b  ? {{24{load_byte_w[7]}}, load_byte_w} :
                           pend_inst_ld_bu ? {24'b0, load_byte_w} :
                           pend_inst_ld_h  ? {{16{load_half_w[15]}}, load_half_w} :
                           pend_inst_ld_hu ? {16'b0, load_half_w} :
                                             dcache_resp_data;

    always @(posedge clk) begin
        if (reset) begin
            pend_valid       <= 1'b0;
            pend_req_sent    <= 1'b0;
            pend_tlb_wait    <= 1'b0;
            pend_pc          <= 32'b0;
            pend_inst        <= 32'b0;
            pend_rd          <= 5'b0;
            pend_result      <= 32'b0;
            pend_op1         <= 32'b0;
            pend_op2         <= 32'b0;
            pend_is_load     <= 1'b0;
            pend_is_store    <= 1'b0;
            pend_store_data  <= 32'b0;
            pend_exception_valid      <= 1'b0;
            pend_exception_ecode      <= 6'b0;
            pend_exception_esubcode   <= 9'b0;
            pend_exception_badv_valid <= 1'b0;
            pend_exception_badv       <= 32'b0;

            dcache_req_valid <= 1'b0;
            dcache_req_write <= 1'b0;
            dcache_req_addr  <= 32'b0;
            dcache_req_wdata <= 32'b0;
            dcache_req_wstrb <= 4'b0;

            out_valid        <= 1'b0;
            out_pc           <= 32'b0;
            out_inst         <= 32'b0;
            out_rd           <= 5'b0;
            out_wb_data      <= 32'b0;
            out_op1          <= 32'b0;
            out_op2          <= 32'b0;
            out_wen          <= 1'b0;
            out_csr_we       <= 1'b0;
            out_csr_addr     <= 14'b0;
            out_csr_wdata    <= 32'b0;
            out_exception_valid      <= 1'b0;
            out_exception_ecode      <= 6'b0;
            out_exception_esubcode   <= 9'b0;
            out_exception_badv_valid <= 1'b0;
            out_exception_badv       <= 32'b0;
        end else begin
            dcache_req_valid <= 1'b0;
            dcache_req_write <= 1'b0;
            dcache_req_addr  <= 32'b0;
            dcache_req_wdata <= 32'b0;
            dcache_req_wstrb <= 4'b0;

            out_valid        <= 1'b0;
            out_wen          <= 1'b0;
            out_csr_we       <= 1'b0;
            out_csr_addr     <= 14'b0;
            out_csr_wdata    <= 32'b0;
            out_exception_valid      <= 1'b0;
            out_exception_ecode      <= 6'b0;
            out_exception_esubcode   <= 9'b0;
            out_exception_badv_valid <= 1'b0;
            out_exception_badv       <= 32'b0;

            if (!pend_valid && in_valid) begin
                if (in_is_load || in_is_store) begin
                    pend_valid      <= 1'b1;
                    pend_req_sent   <= 1'b0;
                    pend_tlb_wait   <= in_d_tlb_needs_query_w;
                    pend_pc         <= in_pc;
                    pend_inst       <= in_inst;
                    pend_rd         <= in_rd;
                    pend_result     <= in_result;
                    pend_op1        <= in_op1;
                    pend_op2        <= in_op2;
                    pend_is_load    <= in_is_load;
                    pend_is_store   <= in_is_store;
                    pend_store_data <= in_store_data;
                    pend_exception_valid      <= in_exception_valid || in_data_ale_w;
                    pend_exception_ecode      <= in_exception_valid ? in_exception_ecode : 6'h09;
                    pend_exception_esubcode   <= in_exception_valid ? in_exception_esubcode : 9'b0;
                    pend_exception_badv_valid <= in_exception_valid ? in_exception_badv_valid : in_data_ale_w;
                    pend_exception_badv       <= in_exception_valid ? in_exception_badv : in_result;
                end else begin
                    out_valid                <= 1'b1;
                    out_pc                   <= in_pc;
                    out_inst                 <= in_inst;
                    out_rd                   <= in_rd;
                    out_wb_data              <= in_result;
                    out_op1                  <= in_op1;
                    out_op2                  <= in_op2;
                    out_wen                  <= wb_wen_no_mem && !in_exception_valid;
                    out_csr_we               <= in_is_csr && in_csr_we && !in_exception_valid;
                    out_csr_addr             <= in_csr_addr;
                    out_csr_wdata            <= in_csr_wdata;
                    out_exception_valid      <= in_exception_valid;
                    out_exception_ecode      <= in_exception_ecode;
                    out_exception_esubcode   <= in_exception_esubcode;
                    out_exception_badv_valid <= in_exception_badv_valid;
                    out_exception_badv       <= in_exception_badv;
                end
            end

            if (pend_valid) begin
                if (pend_exception_valid) begin
                    out_valid                <= 1'b1;
                    out_pc                   <= pend_pc;
                    out_inst                 <= pend_inst;
                    out_rd                   <= pend_rd;
                    out_wb_data              <= pend_result;
                    out_op1                  <= pend_op1;
                    out_op2                  <= pend_op2;
                    out_wen                  <= 1'b0;
                    out_exception_valid      <= 1'b1;
                    out_exception_ecode      <= pend_exception_ecode;
                    out_exception_esubcode   <= pend_exception_esubcode;
                    out_exception_badv_valid <= pend_exception_badv_valid;
                    out_exception_badv       <= pend_exception_badv;

                    pend_valid    <= 1'b0;
                    pend_req_sent <= 1'b0;
                    pend_tlb_wait <= 1'b0;
                end else if (!pend_req_sent) begin
                    if (pend_tlb_wait) begin
                        if (d_tlb_resp_match_w) begin
                            pend_tlb_wait <= 1'b0;
                            if (d_tlb_exception_valid) begin
                                out_valid                <= 1'b1;
                                out_pc                   <= pend_pc;
                                out_inst                 <= pend_inst;
                                out_rd                   <= pend_rd;
                                out_wb_data              <= pend_result;
                                out_op1                  <= pend_op1;
                                out_op2                  <= pend_op2;
                                out_wen                  <= 1'b0;
                                out_exception_valid      <= 1'b1;
                                out_exception_ecode      <= d_tlb_exception_ecode;
                                out_exception_esubcode   <= 9'b0;
                                out_exception_badv_valid <= 1'b1;
                                out_exception_badv       <= pend_result;

                                pend_valid    <= 1'b0;
                                pend_req_sent <= 1'b0;
                            end else if (pend_inst_cacop) begin
                                out_valid                <= 1'b1;
                                out_pc                   <= pend_pc;
                                out_inst                 <= pend_inst;
                                out_rd                   <= pend_rd;
                                out_wb_data              <= pend_result;
                                out_op1                  <= pend_op1;
                                out_op2                  <= pend_op2;
                                out_wen                  <= 1'b0;
                                out_exception_valid      <= 1'b0;
                                out_exception_ecode      <= 6'b0;
                                out_exception_esubcode   <= 9'b0;
                                out_exception_badv_valid <= 1'b0;
                                out_exception_badv       <= 32'b0;

                                pend_valid    <= 1'b0;
                                pend_req_sent <= 1'b0;
                            end else begin
                                dcache_req_valid <= 1'b1;
                                dcache_req_write <= pend_is_store;
                                dcache_req_addr  <= pend_aligned_paddr;
                                dcache_req_wdata <= store_wdata_w;
                                dcache_req_wstrb <= pend_is_store ? store_wstrb_w : 4'h0;
                                pend_req_sent    <= 1'b1;
                            end
                        end
                    end else if (d_tlb_needs_query_w) begin
                        pend_tlb_wait <= 1'b1;
                    end else begin
                        if (pend_inst_cacop) begin
                            out_valid                <= 1'b1;
                            out_pc                   <= pend_pc;
                            out_inst                 <= pend_inst;
                            out_rd                   <= pend_rd;
                            out_wb_data              <= pend_result;
                            out_op1                  <= pend_op1;
                            out_op2                  <= pend_op2;
                            out_wen                  <= 1'b0;
                            out_exception_valid      <= 1'b0;
                            out_exception_ecode      <= 6'b0;
                            out_exception_esubcode   <= 9'b0;
                            out_exception_badv_valid <= 1'b0;
                            out_exception_badv       <= 32'b0;

                            pend_valid    <= 1'b0;
                            pend_req_sent <= 1'b0;
                            pend_tlb_wait <= 1'b0;
                        end else begin
                            dcache_req_valid <= 1'b1;
                            dcache_req_write <= pend_is_store;
                            dcache_req_addr  <= pend_aligned_paddr;
                            dcache_req_wdata <= store_wdata_w;
                            dcache_req_wstrb <= pend_is_store ? store_wstrb_w : 4'h0;
                            pend_req_sent    <= 1'b1;
                        end
                    end
                end

                if (pend_req_sent && dcache_resp_valid) begin
                    out_valid                <= 1'b1;
                    out_pc                   <= pend_pc;
                    out_inst                 <= pend_inst;
                    out_rd                   <= pend_rd;
                    out_wb_data              <= pend_is_load ? load_result_w : pend_result;
                    out_op1                  <= pend_op1;
                    out_op2                  <= pend_op2;
                    out_wen                  <= ~pend_is_store;
                    out_exception_valid      <= 1'b0;
                    out_exception_ecode      <= 6'b0;
                    out_exception_esubcode   <= 9'b0;
                    out_exception_badv_valid <= 1'b0;
                    out_exception_badv       <= 32'b0;

                    pend_valid    <= 1'b0;
                    pend_req_sent <= 1'b0;
                    pend_tlb_wait <= 1'b0;
                end
            end
        end
    end

`ifdef VERILATOR
`ifdef PERF_MONI
    integer dbg_cycle_cnt = 0;
    integer dbg_accept_cnt = 0;
    integer dbg_accept_mem_cnt = 0;
    integer dbg_accept_nonmem_cnt = 0;
    integer dbg_emit_cnt = 0;
    integer dbg_pend_busy_cnt = 0;
    integer dbg_req_issue_cnt = 0;
    integer dbg_resp_cnt = 0;
    integer dbg_wait_resp_cnt = 0;
    integer dbg_exception_emit_cnt = 0;
    final begin
        $display("[PERF][M1] cycles=%0d accept=%0d accept_mem=%0d accept_nonmem=%0d emit=%0d pend_busy=%0d",
                 dbg_cycle_cnt, dbg_accept_cnt, dbg_accept_mem_cnt,
                 dbg_accept_nonmem_cnt, dbg_emit_cnt, dbg_pend_busy_cnt);
        $display("[PERF][M1] req_issue=%0d resp=%0d wait_resp=%0d exception_emit=%0d",
                 dbg_req_issue_cnt, dbg_resp_cnt, dbg_wait_resp_cnt,
                 dbg_exception_emit_cnt);
    end
    always @(posedge clk) begin
        if (!reset) begin
            dbg_cycle_cnt <= dbg_cycle_cnt + 1;
            if (in_valid && m1_allowin) begin
                dbg_accept_cnt <= dbg_accept_cnt + 1;
                if (in_is_load || in_is_store)
                    dbg_accept_mem_cnt <= dbg_accept_mem_cnt + 1;
                else
                    dbg_accept_nonmem_cnt <= dbg_accept_nonmem_cnt + 1;
            end
            if (out_valid)
                dbg_emit_cnt <= dbg_emit_cnt + 1;
            if (pend_valid)
                dbg_pend_busy_cnt <= dbg_pend_busy_cnt + 1;
            if (dcache_req_valid)
                dbg_req_issue_cnt <= dbg_req_issue_cnt + 1;
            if (dcache_resp_valid)
                dbg_resp_cnt <= dbg_resp_cnt + 1;
            if (pend_valid && pend_req_sent && !dcache_resp_valid)
                dbg_wait_resp_cnt <= dbg_wait_resp_cnt + 1;
            if (pend_valid && pend_exception_valid)
                dbg_exception_emit_cnt <= dbg_exception_emit_cnt + 1;
        end
    end
`endif
`endif

endmodule

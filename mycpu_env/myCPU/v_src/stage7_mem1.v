module stage7_mem1 (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_result,
    input  wire        in_is_load,
    input  wire        in_is_store,
    input  wire [31:0] in_store_data,
    output reg         dcache_req_valid,
    output reg         dcache_req_write,
    output reg  [31:0] dcache_req_addr,
    output reg  [31:0] dcache_req_wdata,
    output reg  [3:0]  dcache_req_wstrb,
    input  wire        dcache_resp_valid,
    input  wire [31:0] dcache_resp_data,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_wb_data,
    output reg         out_wen
);

    wire [5:0] op_31_26;
    wire inst_b;
    wire inst_beq;
    wire inst_bne;
    wire wb_wen_no_mem;

    reg        pend_valid;
    reg        pend_req_sent;
    reg [31:0] pend_pc;
    reg [31:0] pend_inst;
    reg [4:0]  pend_rd;
    reg [31:0] pend_result;
    reg        pend_is_load;
    reg        pend_is_store;
    reg [31:0] pend_store_data;

    assign op_31_26 = in_inst[31:26];
    assign inst_b   = (op_31_26 == 6'h14);
    assign inst_beq = (op_31_26 == 6'h16);
    assign inst_bne = (op_31_26 == 6'h17);
    // b/beq/bne should not write GPR; bl/jirl keep link writeback.
    assign wb_wen_no_mem = ~(inst_b | inst_beq | inst_bne);

    always @(posedge clk) begin
        if (reset) begin
            pend_valid       <= 1'b0;
            pend_req_sent    <= 1'b0;
            pend_pc          <= 32'b0;
            pend_inst        <= 32'b0;
            pend_rd          <= 5'b0;
            pend_result      <= 32'b0;
            pend_is_load     <= 1'b0;
            pend_is_store    <= 1'b0;
            pend_store_data  <= 32'b0;

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
            out_wen          <= 1'b0;
        end else begin
            dcache_req_valid <= 1'b0;
            dcache_req_write <= 1'b0;
            dcache_req_addr  <= 32'b0;
            dcache_req_wdata <= 32'b0;
            dcache_req_wstrb <= 4'b0;

            out_valid        <= 1'b0;
            out_wen          <= 1'b0;

            if (!pend_valid && in_valid) begin
                if (in_is_load || in_is_store) begin
                    pend_valid      <= 1'b1;
                    pend_req_sent   <= 1'b0;
                    pend_pc         <= in_pc;
                    pend_inst       <= in_inst;
                    pend_rd         <= in_rd;
                    pend_result     <= in_result;
                    pend_is_load    <= in_is_load;
                    pend_is_store   <= in_is_store;
                    pend_store_data <= in_store_data;
                end else begin
                    out_valid       <= 1'b1;
                    out_pc          <= in_pc;
                    out_inst        <= in_inst;
                    out_rd          <= in_rd;
                    out_wb_data     <= in_result;
                    out_wen         <= wb_wen_no_mem;
                end
            end

            if (pend_valid) begin
                if (!pend_req_sent) begin
                    dcache_req_valid <= 1'b1;
                    dcache_req_write <= pend_is_store;
                    dcache_req_addr  <= pend_result;
                    dcache_req_wdata <= pend_store_data;
                    dcache_req_wstrb <= pend_is_store ? 4'hf : 4'h0;
                    pend_req_sent    <= 1'b1;
                end

                if (dcache_resp_valid) begin
                    out_valid    <= 1'b1;
                    out_pc       <= pend_pc;
                    out_inst     <= pend_inst;
                    out_rd       <= pend_rd;
                    out_wb_data  <= pend_is_load ? dcache_resp_data : pend_result;
                    out_wen      <= ~pend_is_store;

                    pend_valid    <= 1'b0;
                    pend_req_sent <= 1'b0;
                end
            end
        end
    end

endmodule

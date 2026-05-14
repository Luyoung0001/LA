module s2_f2 (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    output wire        tlb_query_valid,
    output wire        tlb_query_write,
    output wire [31:0] tlb_query_vaddr,
    input  wire [31:0] tlb_query_paddr,
    input  wire        tlb_exception_valid,
    input  wire [5:0]  tlb_exception_ecode,
    output reg         icache_req_valid,
    output reg  [31:0] icache_req_addr,
    input  wire        icache_resp_valid,
    input  wire [31:0] icache_resp_data,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg         out_exception_valid,
    output reg  [5:0]  out_exception_ecode,
    output reg  [8:0]  out_exception_esubcode,
    output reg         out_exception_badv_valid,
    output reg  [31:0] out_exception_badv
);

    reg        pend_valid;
    reg [31:0] pend_pc;
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

    assign pc_adef_w = |in_pc[1:0];
    assign tlb_query_valid = in_valid && !pc_adef_w;
    assign tlb_query_write = 1'b0;
    assign tlb_query_vaddr = in_pc;
    assign req_exception_valid_w = pc_adef_w || tlb_exception_valid;
    assign req_exception_ecode_w = pc_adef_w ? 6'h08 : tlb_exception_ecode;
    assign req_exception_esubcode_w = pc_adef_w ? 9'h0 : 9'h0;
    assign req_addr_w = tlb_query_paddr;

    always @(posedge clk) begin
        if (reset) begin
            pend_valid                <= 1'b0;
            pend_pc                   <= 32'b0;
            pend_exception_valid      <= 1'b0;
            pend_exception_ecode      <= 6'b0;
            pend_exception_esubcode   <= 9'b0;
            pend_exception_badv_valid <= 1'b0;
            pend_exception_badv       <= 32'b0;
            out_valid                 <= 1'b0;
            out_pc                    <= 32'b0;
            out_inst                  <= 32'h03400000;
            out_exception_valid       <= 1'b0;
            out_exception_ecode       <= 6'b0;
            out_exception_esubcode    <= 9'b0;
            out_exception_badv_valid  <= 1'b0;
            out_exception_badv        <= 32'b0;
            icache_req_valid          <= 1'b0;
            icache_req_addr           <= 32'b0;
        end else begin
            out_valid                <= 1'b0;
            out_exception_valid      <= 1'b0;
            out_exception_ecode      <= 6'b0;
            out_exception_esubcode   <= 9'b0;
            out_exception_badv_valid <= 1'b0;
            out_exception_badv       <= 32'b0;
            icache_req_valid         <= 1'b0;

            if (in_valid && !pend_valid) begin
                pend_valid                <= 1'b1;
                pend_pc                   <= in_pc;
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

            if (pend_valid && (pend_exception_valid || icache_resp_valid)) begin
                out_valid                <= 1'b1;
                out_pc                   <= pend_pc;
                out_inst                 <= pend_exception_valid ? 32'h03400000 : icache_resp_data;
                out_exception_valid      <= pend_exception_valid;
                out_exception_ecode      <= pend_exception_ecode;
                out_exception_esubcode   <= pend_exception_esubcode;
                out_exception_badv_valid <= pend_exception_badv_valid;
                out_exception_badv       <= pend_exception_badv;
                pend_valid               <= 1'b0;
            end
        end
    end

endmodule

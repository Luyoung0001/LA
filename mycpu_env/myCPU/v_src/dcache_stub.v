module dcache_stub (
    input  wire        clk,
    input  wire        reset,
    input  wire        req_valid,
    input  wire        req_write,
    input  wire [31:0] req_addr,
    input  wire [31:0] req_wdata,
    input  wire [3:0]  req_wstrb,
    output wire        req_ready,
    output reg         resp_valid,
    output reg  [31:0] resp_rdata
);

    reg [31:0] ram [0:255];
    reg        pend_valid;
    reg        pend_write;
    reg [31:0] pend_addr;
    reg [31:0] pend_wdata;
    reg [3:0]  pend_wstrb;

    integer i;

    assign req_ready = 1'b1;

    always @(posedge clk) begin
        if (reset) begin
            pend_valid <= 1'b0;
            pend_write <= 1'b0;
            pend_addr  <= 32'b0;
            pend_wdata <= 32'b0;
            pend_wstrb <= 4'b0;
            resp_valid <= 1'b0;
            resp_rdata <= 32'b0;
            for (i = 0; i < 256; i = i + 1) begin
                ram[i] = 32'b0;
            end
        end else begin
            pend_valid <= req_valid;
            pend_write <= req_write;
            pend_addr  <= req_addr;
            pend_wdata <= req_wdata;
            pend_wstrb <= req_wstrb;

            resp_valid <= pend_valid;
            if (pend_valid) begin
                if (pend_write && (|pend_wstrb)) begin
                    ram[pend_addr[9:2]] <= pend_wdata;
                end
                resp_rdata <= ram[pend_addr[9:2]];
            end
        end
    end

endmodule

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
    output reg  [31:0] resp_rdata,
    // AXI-side request/response channel (all-miss forwarding for now)
    output reg         axi_req_valid,
    output reg         axi_req_write,
    output reg  [31:0] axi_req_addr,
    output reg  [31:0] axi_req_wdata,
    output reg  [3:0]  axi_req_wstrb,
    input  wire        axi_req_ready,
    input  wire        axi_resp_valid,
    input  wire [31:0] axi_resp_rdata
);

    reg waiting_resp;

    assign req_ready = ~axi_req_valid & ~waiting_resp;

    always @(posedge clk) begin
        if (reset) begin
            waiting_resp  <= 1'b0;
            resp_valid    <= 1'b0;
            resp_rdata    <= 32'b0;
            axi_req_valid <= 1'b0;
            axi_req_write <= 1'b0;
            axi_req_addr  <= 32'b0;
            axi_req_wdata <= 32'b0;
            axi_req_wstrb <= 4'b0;
        end else begin
            resp_valid <= 1'b0;

            // Accept one outstanding data request and forward to AXI.
            if (req_valid && req_ready) begin
                axi_req_valid <= 1'b1;
                axi_req_write <= req_write;
                axi_req_addr  <= req_addr;
                axi_req_wdata <= req_wdata;
                axi_req_wstrb <= req_wstrb;
            end

            if (axi_req_valid && axi_req_ready) begin
                axi_req_valid <= 1'b0;
                waiting_resp  <= 1'b1;
            end

            if (waiting_resp && axi_resp_valid) begin
                waiting_resp <= 1'b0;
                resp_valid   <= 1'b1;
                resp_rdata   <= axi_resp_rdata;
            end
        end
    end

endmodule

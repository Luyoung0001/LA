module regfile_d1 (
    input  wire        clk,
    input  wire        reset,
    input  wire        rreq_valid,
    input  wire [4:0]  raddr1,
    input  wire [4:0]  raddr2,
    output reg         rvalid,
    output reg  [31:0] rdata1,
    output reg  [31:0] rdata2,
    input  wire        we,
    input  wire [4:0]  waddr,
    input  wire [31:0] wdata,
    input  wire [4:0]  dbg_raddr,
    output wire [31:0] dbg_rdata
);

    reg [31:0] regs [31:0];
    integer i;

    assign dbg_rdata = (dbg_raddr == 5'b0) ? 32'b0 : regs[dbg_raddr];

    always @(posedge clk) begin
        if (reset) begin
            rvalid <= 1'b0;
            rdata1 <= 32'b0;
            rdata2 <= 32'b0;
            for (i = 0; i < 32; i = i + 1) begin
                regs[i] = 32'b0;
            end
        end else begin
            if (we && (waddr != 5'b0)) begin
                regs[waddr] <= wdata;
            end

            rvalid <= rreq_valid;
            if (rreq_valid) begin
                rdata1 <= (raddr1 == 5'b0) ? 32'b0 : regs[raddr1];
                rdata2 <= (raddr2 == 5'b0) ? 32'b0 : regs[raddr2];
            end
        end
    end

endmodule

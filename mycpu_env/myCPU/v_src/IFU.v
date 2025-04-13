module IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号
        
        input wire br_taken,        // 分支跳转信号
        input [31:0] br_target,       // 分支跳转地址
        output reg [31:0] pc
    );

    wire [31:0] seq_pc;
    wire [31:0] nextpc;
    assign seq_pc       = pc + 32'h4;
    assign nextpc       = br_taken ? br_target : seq_pc;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h1bfffffc;
        end
        else begin
            pc <= nextpc;  // 跳转时，直接使用跳转地址
        end
    end

endmodule

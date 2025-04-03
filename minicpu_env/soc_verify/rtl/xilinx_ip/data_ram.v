module data_ram(
    input clk,
    input we,
    input  [15:0] a,
    input  [31:0] d,
    output reg [31:0] spo
);
    reg [31:0] memory [0:1023]; // 4KB 内存
// 初始化 memory

    initial begin
    memory[0] = 32'h10;
    end

    // 同步写操作（需时钟）
    always @(posedge clk) begin
        if (we) begin
            memory[a[9:0]]        <= d;
        end
    end
    always @(*) begin
        spo = memory[a[9:0]];
    end

endmodule

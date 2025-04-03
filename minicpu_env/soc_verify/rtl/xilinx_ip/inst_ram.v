module inst_ram(
    input clk,
    input we,
    input  [15:0] a,
    input  [31:0] d,
    output [31:0] spo
);
    reg [31:0] mem [0:1023]; // 4KB

    wire [31:0] temp;
    initial begin
        mem[0]  = 32'h0c008002;
        mem[1]  = 32'h0d048002;
        mem[2]  = 32'h17008002;
        mem[3]  = 32'h18048002;
        mem[4]  = 32'h04008028;
        mem[5]  = 32'h8e351000;
        mem[6]  = 32'hac018002;
        mem[7]  = 32'hcd018002;
        mem[8]  = 32'hf7621000;
        mem[9]  = 32'he4f2ff5f;
        mem[10]  = 32'h0e109029;
        mem[11]  = 32'h0003005c;
    end
    assign temp = mem[a[9:0]];
    assign spo = we ? {temp[7:0],temp[15:8],temp[23:16],temp[31:24]} : 32'b0;

endmodule

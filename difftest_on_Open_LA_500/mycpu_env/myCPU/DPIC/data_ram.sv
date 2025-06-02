// module data_ram(
//     input clk,
//     input [3:0] we,
//     input  en,
//     input  [31:0] a,
//     input  [31:0] d,
//     output [31:0] spo
// );
//     initial begin
//     end

//     // dpi-c
//     import "DPI-C" function int data_ram_read(input int addr);
//     import "DPI-C" function void data_ram_write(input int addr, input int wdata);

//     always @(clk) begin
//         if (we[3]) begin
//             data_ram_write(a, d);
//         end
//     end

//     assign spo = data_ram_read(a);


// endmodule

module data_ram(
    input clk,
    input [3:0] we,
    input  en,
    input  [31:0] a,
    input  [31:0] d,
    output reg [31:0] spo
);

    // dpi-c
    import "DPI-C" function int data_ram_read(input int addr);

    wire [7:0] we7;
    assign we7 = {4'b0,we};
    import "DPI-C" function void data_ram_write(input int addr, input int wdata, input byte we_7);

    // 同步写操作
    always_ff @(posedge clk) begin
        if ((we != 4'b0000) && en) begin
            data_ram_write(a, d, we7);
        end else if (we == 4'b0000 && en) begin
            // 如果没有写操作且使能，则可以选择是否输出默认值
            spo <= data_ram_read(a); // 在下一个周期输出上一个周期请求的地址的数据
        end else begin
            spo <= 32'h0; // 没有使能时输出默认值
        end
    end

endmodule
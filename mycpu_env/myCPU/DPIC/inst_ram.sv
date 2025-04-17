// module inst_ram(
//     input clk,
//     input [3:0] we,
//     input en,
//     input  [31:0] a,
//     input  [31:0] d,
//     output [31:0] spo
// );
//     // dpi-c
//     import "DPI-C" function int inst_ram_read(input int addr);

//         assign spo = inst_ram_read(a);

// endmodule


// 上面是异步 ram 的代码，下面是同步 ram 的代码
module inst_ram(
    input clk,
    input [3:0] we,
    input en,
    input  [31:0] a,
    input  [31:0] d,
    output reg [31:0] spo // 将 spo 声明为 reg 类型，因为其值在时钟边沿更新
);
    // dpi-c
    import "DPI-C" function int inst_ram_read(input int addr);

    // 在时钟上升沿更新读请求和地址
    always_ff @(posedge clk) begin
            // 在下一个时钟上升沿根据存储的地址读取数据
            if (en) begin
                spo <= inst_ram_read(a);
            end else begin
                spo <= 32'h0; // 如果当前周期没有使能，输出可以保持为 0 或其他默认值
            end
        end

endmodule
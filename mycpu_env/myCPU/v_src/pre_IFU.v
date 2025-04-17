module pre_IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号

        input wire [31:0] fs_pc,

        input wire [32:0] bus_br_data,

        output wire [31:0] next_pc,
        output wire [31:0]  inst_addr,       // 发射给inst_ram的地址

        // 保持 ram 的输出是一个关键，但是观察波形图，可以让inst_addr 遇到 load_use 的时候
        // 让 inst_addr 变成上一个周期的值
        input wire fs_allowin
    );

    wire [31:0] seq_pc;
    wire [31:0] nextpc;

    wire br_taken;
    wire [31:0] br_target;

    assign {br_taken, br_target } = bus_br_data;

    assign seq_pc       = fs_pc + 32'h4;
    assign nextpc       = br_taken ? br_target : seq_pc;

    assign inst_addr = fs_allowin ? nextpc : fs_pc;
    assign next_pc = nextpc;



endmodule

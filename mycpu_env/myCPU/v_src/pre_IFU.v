module pre_IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号

        input wire [31:0] fs_pc,

        input wire [32:0] bus_br_data,

        output wire [31:0] next_pc,
        output wire [31:0]  inst_addr,       // 发射给inst_ram的地址
        input wire excp_flush,
        input wire ertn_flush,
        input wire [31:0] csr_era,
        input wire [31:0] csr_eentry,

        output wire pfs_excp_adef,
        output wire pfs_excp,

        // 保持 ram 的输出是一个关键，但是观察波形图，可以让inst_addr 遇到 load_use 的时候
        // 让 inst_addr 变成上一个周期的值
        input wire fs_allowin
    );
    wire flush_sign;
    assign flush_sign = ertn_flush || excp_flush;

    wire [31:0] seq_pc;
    wire [31:0] nextpc;

    wire br_taken;
    wire [31:0] br_target;

    wire [31:0] inst_flush_pc;

    assign {br_taken, br_target } = bus_br_data;

    assign inst_flush_pc = {32{ertn_flush}} & csr_era;

    assign seq_pc       = fs_pc + 32'h4;
    assign nextpc       = excp_flush ? csr_eentry:
           ertn_flush ? inst_flush_pc:
           br_taken ? br_target :
           seq_pc;

    assign inst_addr = fs_allowin ? nextpc : fs_pc;
    assign next_pc = nextpc;

    // 取值地址错例外
    assign pfs_excp_adef = (nextpc[0] || nextpc[1]);

    assign pfs_excp = pfs_excp_adef;



endmodule

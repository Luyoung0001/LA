module IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号

        input wire [31:0] pc_i,
        output wire [31:0] pc_o,

        output wire fs_excp_out,
        output wire [15:0] fs_excp_num_out,

        input wire [1:0] flush,

        // 握手信号
        input up_valid,
        output state_valid,

        input waite_ready_i,
        output waite_ready_o,

        // like SRAM
        output wire req, // en
        output wr,   // |we
        output [1:0] size, // 新增
        output [3:0] wstrb, // we
        output wire [31:0] addr,
        output [31:0] wdata,
        input addr_ok, // 新增
        input data_ok,
        input [31:0] rdata,
        output [31:0] rdata_o // 发送到下游的指令
    );

    // IFU 阶段有效信号
    reg fs_valid;
    wire fs_ready_go;

    reg  [31:0] pc;
    wire excp_flush;
    wire ertn_flush;
    wire flush_sign;


    assign {excp_flush, ertn_flush} = flush;
    assign flush_sign = ertn_flush || excp_flush;

    // 异常
    wire pfs_excp_adef;
    wire pfs_excp;
    wire [15:0] fs_excp_num;
    assign fs_excp_out = pfs_excp;
    assign fs_excp_num_out = fs_excp_num;
    assign pfs_excp_adef = (pc[0] || pc[1]) ;
    assign pfs_excp = pfs_excp_adef;
    assign fs_excp_num = pfs_excp_adef ? 16'h0100 : 16'h0000;

    // 发送数据请求
    assign wr = 1'b0; // 读
    assign wstrb = 4'b1111;
    assign wdata = 32'b0;
    assign size = 2'b10;    // 4字节读取
    // assign req = 1'b0;      // 默认
    assign addr = pc;


    // 这里应该设置一个握手机制：参考的是 ysyx 中的 B1 总线，也是我之前实现过的一个模块
    // 具体的，分为两个状态：idle <---> waite_ready
    // 1、一开始处于空闲状态 idle，===> valid = 0；
    //  - 如果不需要发送消息, 则一直处于 idle 状态
    //  - 如果需要发送消息, 则将 valid = 1, 并进入 wait_ready 状态, 等待 slave 就绪
    // 2、在 wait_read 状态中, 同时检测 slave 的 ready 信号
    // - 如果ready信号有效, 则握手成功, 返回idle状态
    // - 如果ready信号无效, 则继续处于wait_ready状态等待
    // 0:   idle
    // 1:   process
    // 2:   waite_ready

    reg [1:0] ifu_state;
    always @(posedge clk) begin
        if(rst || flush_sign) begin
            ifu_state <= 2'b0;
        end
        // 空闲且上游数据有效则 取出上游数据
        else if(ifu_state == 2'b0 && up_valid) begin
            // 取出数据
            pc <= pc_i;
            ifu_state <= 2'b1;
        end
        // 处理
        else if(ifu_state == 2'b1) begin
            // 如果下游空闲，再发送请求，不然还得保持
            if(waite_ready_i && addr_ok) begin
                ifu_state <= 2'd2;
            end
        end
        // 给下游准备数据阶段
        else if(ifu_state == 2'd2) begin
            if(data_ok) begin
                ifu_state <= 2'd0;
            end
        end
    end
    assign req = flush_sign ? 1'b0: ifu_state == 2'b1 && waite_ready_i && !addr_ok;
    assign pc_o = flush_sign ? 32'd0 : pc;
    assign rdata_o = flush_sign ? 32'd0 : rdata;
    assign waite_ready_o = ifu_state == 2'b0 ? 1'b1:1'b0;
    assign state_valid = flush_sign ? 1'b0 : ifu_state == 2'd2 && data_ok;


endmodule

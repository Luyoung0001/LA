module IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号

        input wire pfs_excp_adef,
        input wire pfs_excp,

        output wire fs_excp_out,
        output wire [15:0] fs_excp_num_out,

        input wire [31:0] next_pc,
        output wire [31:0] fs_pc,

        // 握手信号
        input wire ds_allowin,
        output wire fs_allowin, // 发给上游的信号，表示当前阶段是否可以接收数据
        output wire fs_to_ds_valid       // ifu 阶段有效信号
    );

    // 异常
    reg fs_excp_r;
    reg [15:0] fs_excp_num_r;

    // 这里添加异常信号
    assign fs_excp_out = fs_excp_r;
    assign fs_excp_num_out = fs_excp_num_r;

    reg  [31:0] pc;
    reg  [31:0] inst_ram_data_reg; // 发射给下游的指令


    // IFU 阶段有效信号
    reg fs_valid;     // 表示当前流水级是否在处理指令
    wire fs_ready_go; // 表示流水级是否需要被阻塞
    wire to_fs_valid; // 上游指令是否处理完毕

    // pre-IF stage
    assign to_fs_valid  = ~rst; // 复位时，IFU 阶段无效 这里表示上游指令已经处理完毕

    // IF stage
    assign fs_ready_go    = 1'b1; // 不需要阻塞
    assign fs_allowin     = !fs_valid || (fs_ready_go && ds_allowin); // 表示当前阶段是否允许上游进入
    assign fs_to_ds_valid = fs_valid && fs_ready_go; // 如果不阻塞且当前处理指令（事实上，
    // 当fs_valid有效，数据已经处理完成，可以提前发射fs_to_ds_valid）完成


    always @(posedge clk) begin
        if(rst) begin
            fs_valid <= 1'b0; // 复位时，IFU 阶段无效
        end
        else if(fs_allowin) begin
            fs_valid <= to_fs_valid; // 上游指令处理完毕且当前阶段允许上游进入，那么当前阶段开始处理数据
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h1bfffffc;
            fs_excp_r      <= 1'b0;
            fs_excp_num_r  <= 16'b0;
        end
        // 上游指令处理完毕且当前阶段允许上游进入，那么当前阶段开始处理数据
        else if(to_fs_valid && fs_allowin) begin
            pc <= next_pc;
            fs_excp_r      <= pfs_excp ;
            fs_excp_num_r  <= pfs_excp_adef ? 16'h0100 : 16'h0000; // 如果有 adef 例外，传给 fs_excp_num
        end
    end

    assign fs_pc = pc; // 发送给下游的指令地址

    // 数据的处理和 fs_valid 均在下一个相同的周期完成

endmodule

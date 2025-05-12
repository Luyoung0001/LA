module IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号
        input wire [32:0] bus_br_data,
        output wire [31:0] fs_pc,

        output wire fs_excp_out,
        output wire [15:0] fs_excp_num_out,
        output wire [31:0] inst_addr,

        input wire [1:0] flush,
        input wire [31:0] csr_era,
        input wire [31:0] csr_eentry,
        input wire [31:0] inst_data,
        // 握手信号
        input wire ds_allowin,
        output wire fs_to_ds_valid
    );



    // 异常
    reg fs_excp_r;
    reg [15:0] fs_excp_num_r;
    wire pfs_excp_adef;
    wire pfs_excp;
    assign fs_excp_out = fs_excp_r;
    assign fs_excp_num_out = fs_excp_num_r;
    reg  [31:0] pc;

    wire excp_flush;
    wire ertn_flush;
    wire flush_sign;
    assign {excp_flush, ertn_flush} = flush;
    assign flush_sign = ertn_flush || excp_flush;

    // IFU 阶段有效信号
    reg fs_valid;     // 表示当前流水级是否在处理指令
    wire fs_ready_go; // 表示流水级是否需要被阻塞
    wire to_fs_valid; // 上游指令是否处理完毕
    wire fs_allowin;

    // pre-IF stage
    assign to_fs_valid  = ~rst; // 复位时，IFU 阶段无效 这里表示上游指令已经处理完毕

    wire [31:0] seq_pc;
    wire [31:0] nextpc;

    wire br_taken;
    wire [31:0] br_target;

    wire [31:0] inst_flush_pc;

    assign {br_taken, br_target } = bus_br_data;

    assign inst_flush_pc = {32{ertn_flush}} & csr_era;

    assign seq_pc       = pc + 32'h4;
    assign nextpc       = excp_flush ? csr_eentry:
           ertn_flush ? inst_flush_pc:
           br_taken ? br_target :
           seq_pc;

    wire [31:0] inst_mem_addr;
    assign inst_mem_addr = fs_allowin ? nextpc : pc; // 下游阻塞的话，保持 pc
    assign pfs_excp_adef = (nextpc[0] || nextpc[1]);
    assign pfs_excp = pfs_excp_adef;

    assign inst_addr = inst_mem_addr;

    
    //=================================================================================================================

    // IF stage
    assign fs_ready_go    = 1'b1;
    assign fs_allowin     = !fs_valid || (fs_ready_go && ds_allowin);
    assign fs_to_ds_valid = fs_valid && fs_ready_go;
    always @(posedge clk) begin
        if(rst) begin
            fs_valid <= 1'b0; // 复位时，IFU 阶段无效
        end
        else if(fs_allowin) begin
            fs_valid <= to_fs_valid;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h1bfffffc;
            fs_excp_r <= 1'b0;
            fs_excp_num_r <= 16'b0;
        end
        else if(to_fs_valid && fs_allowin) begin
            pc <= nextpc;
            fs_excp_r      <= pfs_excp ;
            fs_excp_num_r  <= pfs_excp_adef ? 16'h0100 : 16'h0000; // 如果有 adef 例外，传给 fs_excp_num
        end
    end

    assign fs_pc = pc;
endmodule

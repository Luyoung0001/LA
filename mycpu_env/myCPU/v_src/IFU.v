module IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号
        input wire [32:0] bus_br_data,
        output wire [31:0] fs_pc,

        output wire fs_excp_out,
        output wire [15:0] fs_excp_num_out,

        input wire [1:0] flush,
        input wire [31:0] csr_era,
        input wire [31:0] csr_eentry,
        // 握手信号
        input wire ds_allowin,
        output wire fs_to_ds_valid,

        output wire condition_4,

        // SRAM

        // output [31:0] inst_sram_addr,
        // output [31:0] inst_sram_wdata,
        // output [3:0] inst_sram_we,
        // output inst_sram_en

        // like SRAM
        output req, // en
        output wr,   // |we
        output [1:0] size, // 新增
        output [3:0] wstrb, // we
        output wire [31:0] addr,
        output [31:0] wdata,
        input addr_ok, // 新增
        input data_ok
    );
    // wire [31:0] addr;

    // assign inst_sram_addr = addr;
    // assign inst_sram_wdata = 32'd0;
    // assign inst_sram_we = 4'd0;
    // assign inst_sram_en = 1'b1;

    // IFU 阶段有效信号
    reg fs_valid;     // 表示当前流水级是否在处理指令
    wire fs_ready_go; // 表示流水级是否需要被阻塞
    wire pfs_to_fs_valid; // 上游指令是否处理完毕
    wire fs_allowin;
    wire pfs_ready_go;

    // like SRAM 的信号
    // 1 req
    // 1 wr
    // 2 size
    // 32 addr
    // 4 wstrb
    // 32 wdata
    // 1 addr_ok
    // 1 data_ok
    // 32 rdata

    assign wr = 1'b0; // 读
    assign wstrb = 4'b1111;
    assign wdata = 32'b0;
    assign size = 2'b10; // 4字节读取

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

    // pre-IF stage
    assign pfs_ready_go = req && addr_ok;
    // assign pfs_ready_go = 1'b1;
    assign pfs_to_fs_valid  = ~rst && pfs_ready_go;

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
           !fs_allowin ? pc:  // 下游阻塞的话，保持 pc
           seq_pc;

    assign req = fs_allowin; // 读请求
    assign addr = nextpc;

    assign pfs_excp_adef = (nextpc[0] || nextpc[1]) ;
    assign pfs_excp = pfs_excp_adef;

    //=================================================================================================================

    // IF stage
    assign fs_ready_go    =  data_ok || ds_allowin;
    // assign fs_ready_go = 1'b1;
    assign fs_allowin     = !fs_valid || (fs_ready_go && ds_allowin);
    assign fs_to_ds_valid = fs_valid && fs_ready_go;
    always @(posedge clk) begin
        if(rst) begin
            fs_valid <= 1'b0;
        end
        else if(fs_allowin) begin
            fs_valid <= pfs_to_fs_valid;
        end
    end

    reg [31:0] reg_rdata;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h1bfffffc;
            fs_excp_r <= 1'b0;
            fs_excp_num_r <= 16'b0;
        end
        else if(pfs_to_fs_valid && fs_allowin) begin
            pc <= nextpc;
            fs_excp_r      <= pfs_excp ;
            fs_excp_num_r  <= pfs_excp_adef ? 16'h0100 : 16'h0000;
        end
    end

    assign fs_pc = pc;

    assign condition_4 =  fs_ready_go && !ds_allowin;


endmodule

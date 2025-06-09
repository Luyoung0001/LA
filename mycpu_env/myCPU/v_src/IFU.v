`include "csr.h"
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

        // from csr
        input wire [1:0]  csr_plv,
        input wire [31:0] csr_dmw0,
        input wire [31:0] csr_dmw1,
        input wire        csr_da,
        input wire        csr_pg,
        input wire [31:0] csr_tlbidx,
        input wire [31:0] csr_tlbehi,
        input wire [31:0] csr_tlbelo0,
        input wire [31:0] csr_tlbelo1,
        input wire [9:0]  csr_asid,

        // addr_trans
        output        inst_addr_trans_en,
        output [9:0]  inst_asid,
        output [31:0] inst_vaddr,
        output        inst_dmw0_en,
        output        inst_dmw1_en,
        output [31:0] inst_dmw0,
        output [31:0] inst_dmw1,
        output        inst_da,
        output        inst_pg,


        input  [7:0]  inst_index,
        input  [19:0] inst_tag,
        input  [3:0]  inst_offset,
        input         inst_tlb_found,
        input         inst_tlb_v,
        input         inst_tlb_d,
        input [ 1:0]  inst_tlb_mat,
        input [ 1:0]  inst_tlb_plv,


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
        output [31:0] rdata_o, // 发送到下游的指令

        // from WBU
        input wire wbu_refetch_sign_i,
        output wire refetch_excp_o,

        input wire wbu_refetch_flush
    );

    // IFU 阶段有效信号
    reg fs_valid;
    wire fs_ready_go;

    reg  [31:0] pc;
    wire excp_flush;
    wire ertn_flush;
    wire flush_sign;

    assign {excp_flush, ertn_flush} = flush;
    assign flush_sign = ertn_flush || excp_flush || wbu_refetch_flush;

    // 异常
    // 取址地址错移异常
    wire pfs_excp_adef;
    wire [15:0] excp_adef_num;
    // 取址操作页无效异常
    wire fs_excp_pif;
    wire [15:0] excp_pif_num;
    // 页特权异常
    wire fs_excp_ppi;
    wire [15:0] excp_ppi_num;
    // TLB重填异常
    wire fs_excp_tlbr;
    wire [15:0] excp_tlbr_num;


    wire pfs_excp;
    wire [15:0] fs_excp_num;



    // 异常
    // 0x0
    assign pfs_excp_adef = (pc[0] || pc[1]) ;
    assign excp_adef_num = pfs_excp_adef ? 16'h0001 : 16'h0000;
    // 0x1
    assign fs_excp_tlbr = !inst_tlb_found && inst_addr_trans_en;
    assign excp_tlbr_num = fs_excp_tlbr ? 16'h0002 : 16'h0000;
    // 0x2
    assign fs_excp_pif  = !inst_tlb_v && inst_addr_trans_en;
    assign excp_pif_num = fs_excp_pif ? 16'h0004 : 16'h0000;
    // 0x3
    assign fs_excp_ppi  = (csr_plv > inst_tlb_plv) && inst_addr_trans_en;
    assign excp_ppi_num = fs_excp_ppi ? 16'h0008 : 16'h0000;

    assign pfs_excp = pfs_excp_adef |
           fs_excp_tlbr |
           fs_excp_pif  |
           fs_excp_ppi;
    assign fs_excp_num = excp_adef_num | excp_pif_num |
           excp_ppi_num | excp_tlbr_num;


    // 输出
    assign fs_excp_out = pfs_excp;
    assign fs_excp_num_out = fs_excp_num;

    // 发送数据请求
    assign wr = 1'b0; // 读
    assign wstrb = 4'b0; // 读不写
    assign wdata = 32'b0;
    assign size = 2'b10;    // 4字节读取
    // assign req = 1'b0;      // 默认
    // assign addr = pc;


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
    reg refetch_excp_i_r;

    always @(posedge clk) begin
        if(rst || flush_sign ) begin
            ifu_state <= 2'b0;
            refetch_excp_i_r <= 1'b0;
        end
        // 空闲且上游数据有效则 取出上游数据
        else if(ifu_state == 2'b0 && up_valid) begin
            // 取出数据
            pc <= pc_i;
            ifu_state <= 2'b1;
            refetch_excp_i_r <= wbu_refetch_sign_i; // 记录是否需要重取
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
    assign pc_o =  pc;
    assign rdata_o = rdata;
    assign waite_ready_o = ifu_state == 2'b0 ? 1'b1:1'b0;
    assign state_valid = ifu_state == 2'd2 && data_ok;

    // tlb
    wire pg_mode;
    assign inst_da = csr_da;
    assign inst_pg = csr_pg;
    assign pg_mode = csr_pg && !csr_da;
    assign inst_vaddr = pc;
    assign inst_dmw0 = csr_dmw0;
    assign inst_dmw1 = csr_dmw1;
    assign inst_dmw0_en = ((inst_dmw0[`PLV0] && csr_plv == 2'd0) || (inst_dmw0[`PLV3] && csr_plv == 2'd3)) && (pc[31:29] == inst_dmw0[`VSEG]) && pg_mode;
    assign inst_dmw1_en = ((inst_dmw1[`PLV0] && csr_plv == 2'd0) || (inst_dmw1[`PLV3] && csr_plv == 2'd3)) && (pc[31:29] == inst_dmw1[`VSEG]) && pg_mode;
    assign inst_addr_trans_en = pg_mode && !inst_dmw0_en && !inst_dmw1_en;
    assign inst_asid = csr_asid;

    assign addr = {inst_tag, inst_index, inst_offset}; // 物理地址

    assign refetch_excp_o = refetch_excp_i_r;

endmodule

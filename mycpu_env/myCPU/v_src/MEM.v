`include "csr.h"
module MEM
    #(
         parameter TLBNUM = 16
     )
     (
         // from exu
         input wire clk,
         input wire rst,

         input wire es_excp,
         input wire [15:0] es_excp_num,
         output wire ms_excp_out,
         output wire [15:0] ms_excp_num_out,

         input wire [9:0] in_mem_op,
         input wire [3:0] in_mem_mask,

         input wire [150:0] bus_exu_to_mem_data,
         input wire [31:0] inst_data_i,
         output wire [31:0] inst_data_o,
         output wire [149:0] bus_mem_to_wbu_data,

         // from mem_sram
         input wire [31:0] data_sram_rdata,
         output wire [85:0] bus_mem_bypass_data,

         // exception
         input wire [1:0] flush,

         input wire wbu_in_is_ertn, // from wbu
         output wire mem_excp, // 发射到 exu 以实现精确异常
         output wire is_ertn, // 这个信号的作用和异常一致，但是它归根结底不属于异常

         // 握手信号
         input up_valid,
         output state_valid,
         input waite_ready_i,
         output waite_ready_o,
         // tlb
         input wire [4:0] tlb_inst_bus,
         output wire [4:0] tlb_inst_bus_o,
         // tlbsrch
         input wire[$clog2(TLBNUM)-1:0] tlbsrch_index,
         input wire                     tlbsrch_found,
         output wire [$clog2(TLBNUM)-1:0] tlbsrch_index_o,
         output wire                     tlbsrch_found_o,
         // invtlb
         input wire [4:0]       invtlb_op_i,
         input wire [9:0]       invtlb_asid_i,
         input wire [18:0]      invtlb_vpn_i,
         output wire [4:0]      invtlb_op_o,
         output wire [9:0]      invtlb_asid_o,
         output wire [18:0]     invtlb_vpn_o,

         // debug
         input wire is_csr_wr_i,
         output wire is_csr_wr_o,

         // refetch sign
         input wire wbu_refetch_sign_i,
         input wire refetch_excp_i,
         output wire refetch_excp_o,

         input [31:0] pc_pro_i,
         output [31:0] pc_pro_o,

         input wbu_refetch_flush,

         // from csr
         output wire [13:0] rd_csr_addr,
         input  wire [31:0] rd_csr_data,
         // //timer 64
         input [63:0] timer_64,
         input [31:0] csr_tid,

         input [82:0] bus_csr_rd_wr_data_i,

         output wire [1:0] ll_sc,
         input wire [31:0] paddr_i,
         output wire [31:0] paddr_o

     );
    reg [31:0] paddr_i_r;
    assign paddr_o = paddr_i_r;
    
    reg [82:0] bus_csr_rd_wr_data_i_r;
    reg is_csr_wr_i_r;

    wire excp_flush;
    wire ertn_flush;
    assign {excp_flush, ertn_flush} = flush;

    // 异常信号
    reg [15:0] es_excp_num_r; // 从上一级接收
    reg es_excp_r;

    wire [15:0] wire_es_excp_num = es_excp_num_r;
    wire wire_es_excp = es_excp_r;

    wire [15:0] ms_excp_num = wire_es_excp_num; // 当前阶段的异常 += 上一阶段
    wire ms_excp = wire_es_excp; // 当前阶段的异常 += 上一阶段

    // 清空信号
    wire flush_sign = ertn_flush || excp_flush || wbu_refetch_flush;

    // 数据相关
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;
    wire mem_over;

    wire mem_csr_we;
    wire [13:0] mem_csr_idx;
    wire [31:0] mem_csr_wdata;


    reg [150:0] bus_exu_to_mem_data_r;
    reg [31:0] inst_data_i_r;
    reg [31:0] reg_rdata;

    wire [31:0] wire_exu_result;
    wire wire_res_from_mem;
    wire [4:0] wire_dest;
    wire wire_gr_we;
    wire [31:0] wire_pc;
    wire wire_csr_we;
    wire [13:0] wire_csr_idx;
    wire [31:0] wire_csr_wdata;
    wire wire_is_inst_ertn;
    wire [31:0] wire_error_va;

    wire gr_we;
    wire [4:0] dest;
    wire [31:0] pc;
    wire [31:0] final_result;

    reg [9:0] mem_op_reg;
    reg [3:0] mem_mask_reg;

    // tlb
    reg [4:0] tlb_inst_bus_r;
    wire wire_inst_tlbsrch;
    wire wire_inst_tlbrd;
    wire wire_inst_tlbwr;
    wire wire_inst_tlbfill;
    wire wire_inst_invtlb;




    assign {
            wire_inst_tlbsrch,
            wire_inst_tlbrd,
            wire_inst_tlbwr,
            wire_inst_tlbfill,
            wire_inst_invtlb
        } = tlb_inst_bus_r;


    assign {
            wire_res_from_mem,
            wire_exu_result,
            wire_gr_we,
            wire_dest,
            wire_pc,
            wire_csr_we,
            wire_csr_idx,
            wire_csr_wdata,
            wire_is_inst_ertn,
            wire_error_va
        } = bus_exu_to_mem_data_r;

    assign bus_mem_to_wbu_data = flush_sign ? 150'd0 : {
               gr_we,
               dest,
               final_result,
               pc,
               wire_csr_we,
               wire_csr_idx,
               csr_wdata,
               wire_is_inst_ertn,
               wire_error_va
           };

    //    res_from_csr,
    //    rd_csr_addr,
    //    csr_we,
    //    csr_mask,
    //    csr_rkd_value

    wire wire_res_from_csr;
    wire [13:0] wire_rd_csr_addr;
    wire wire_csr_we;
    wire [31:0] wire_csr_mask;
    wire [31:0] wire_csr_rkd_value;
    wire wire_inst_rdcntvl_w;
    wire wire_inst_rdcntvh_w;
    wire wire_inst_rdcntid_w;



    assign {
            wire_res_from_csr,
            wire_rd_csr_addr,
            wire_csr_we,
            wire_csr_mask,
            wire_csr_rkd_value,
            wire_inst_rdcntvl_w,
            wire_inst_rdcntvh_w,
            wire_inst_rdcntid_w
        } = bus_csr_rd_wr_data_i_r;

    wire rdcnt_en;
    wire [31:0] rdcnt_result;
    assign {rdcnt_en, rdcnt_result} = ({33{wire_inst_rdcntvl_w}} & {1'b1, timer_64[31: 0]}) |
           ({33{wire_inst_rdcntvh_w}} & {1'b1, timer_64[63:32]}) |
           ({33{wire_inst_rdcntid_w}} & {1'b1, csr_tid});

    // 从 csr 独读出的值有两种情况
    wire [31:0] csr_data = rdcnt_en ? rdcnt_result :
         wire_res_from_csr ? rd_csr_data : 32'd0;

    // 从 csr 中读取数据
    // 其中，如果是读计数器寄存器，则直接返回计数器的值
    assign rd_csr_addr = wire_rd_csr_addr;
    wire [31:0] csr_wdata = wire_csr_rkd_value & wire_csr_mask | (csr_data & ~wire_csr_mask);

    assign final_result = wire_res_from_mem ? mem_result :
           wire_res_from_csr ? csr_data :
           wire_exu_result;

    // 输出
    assign ms_excp_out = ms_excp;
    assign ms_excp_num_out = ms_excp_num;

    assign mem_excp = ms_excp;   // 发送给上一级，目的是为了取消上一级的一些执行效果，比如内存写、除法计算等等
    assign is_ertn = wire_is_inst_ertn; // 同样也是为了取消上一级的执行效果

    assign gr_we          = wire_gr_we;
    assign dest           = wire_dest;
    assign pc             = wire_pc;


    wire [9:0] mem_op = mem_op_reg;
    wire [3:0] mem_mask = mem_mask_reg;

    wire st_b = mem_op[0];
    wire st_h = mem_op[1];
    wire st_w = mem_op[2];
    wire ld_b = mem_op[3];
    wire ld_bu = mem_op[4];
    wire ld_h = mem_op[5];
    wire ld_hu = mem_op[6];
    wire ld_w = mem_op[7];
    wire ll_w = mem_op[8];
    wire sc_w = mem_op[9];

    // 这里读出来的数据也很讲究
    wire [31:0] mem_result =
         reg_rdata;

    // 解决数据相关
    assign mem_regWr = gr_we;
    assign mem_data = final_result;
    assign mem_regAddr = wire_dest;

    assign mem_csr_we = wire_csr_we;
    assign mem_csr_idx = wire_csr_idx;
    assign mem_csr_wdata = csr_wdata;

    assign bus_mem_bypass_data = {
               mem_regWr,
               mem_data,
               mem_regAddr,
               mem_csr_we,
               mem_csr_idx,
               mem_csr_wdata,
               mem_over
           };

    reg [1:0] mem_state;
    reg [$clog2(TLBNUM)-1:0] tlbsrch_index_r;
    reg tlbsrch_found_r;

    reg [4:0] invtlb_op_i_r;
    reg [9:0] invtlb_asid_i_r;
    reg [18:0] invtlb_vpn_i_r;


    reg refetch_excp_i_r;
    reg [31:0] pc_pro_i_r;

    always @(posedge clk) begin
        if (rst || flush_sign) begin
            mem_state <= 2'd0;
            reg_rdata <= 32'd0;
            bus_exu_to_mem_data_r <= 151'd0;
            inst_data_i_r <= 32'd0;
            mem_op_reg <=10'd0;
            mem_mask_reg <= 4'd0;
            es_excp_num_r <= 16'd0;
            es_excp_r <= 1'b0;
            // tlb
            tlb_inst_bus_r <= 5'd0;
            // tlbsrch
            tlbsrch_index_r <= 4'd0;
            tlbsrch_found_r <= 1'b0;
            // invtlb
            invtlb_op_i_r <= 5'd0;
            invtlb_asid_i_r <= 10'd0;
            invtlb_vpn_i_r <= 19'd0;

            is_csr_wr_i_r <= 1'b0;

            refetch_excp_i_r <= 1'b0;

            bus_csr_rd_wr_data_i_r <= 83'd0;

            paddr_i_r <= 32'd0;


        end
        else if (mem_state == 2'd0 && up_valid) begin
            reg_rdata <= data_sram_rdata;
            bus_exu_to_mem_data_r <= bus_exu_to_mem_data;
            inst_data_i_r <= inst_data_i;
            mem_op_reg <= in_mem_op;
            mem_mask_reg <= in_mem_mask;
            es_excp_num_r <= es_excp_num;
            es_excp_r <= es_excp;
            mem_state <= 2'd1;
            // tlb
            tlb_inst_bus_r <= tlb_inst_bus;
            // tlbsrch
            tlbsrch_index_r <= tlbsrch_index;
            tlbsrch_found_r <= tlbsrch_found;
            // invtlb
            invtlb_op_i_r <= invtlb_op_i;
            invtlb_asid_i_r <= invtlb_asid_i;
            invtlb_vpn_i_r <= invtlb_vpn_i;

            is_csr_wr_i_r <= is_csr_wr_i;

            refetch_excp_i_r <= wbu_refetch_sign_i | refetch_excp_i;

            pc_pro_i_r <= pc_pro_i;

            bus_csr_rd_wr_data_i_r <= bus_csr_rd_wr_data_i;

            paddr_i_r <= paddr_i;
        end

        else if(mem_state == 2'd1) begin
            if(waite_ready_i) begin
                mem_state <= 2'd0;
            end
        end

    end

    assign state_valid = (mem_state == 2'd1) ? 1'b1 : 1'b0;
    assign waite_ready_o = (mem_state == 2'd0) ? 1'b1 : 1'b0;
    assign mem_over = mem_state == 2'd0;

    // tlb
    assign tlb_inst_bus_o = tlb_inst_bus_r;
    // tlbsrch
    assign tlbsrch_index_o = tlbsrch_index_r;
    assign tlbsrch_found_o = tlbsrch_found_r;
    // for invtlb
    assign invtlb_op_o = invtlb_op_i_r;
    assign invtlb_asid_o = invtlb_asid_i_r;
    assign invtlb_vpn_o = invtlb_vpn_i_r;

    assign inst_data_o = inst_data_i_r;

    assign is_csr_wr_o = is_csr_wr_i_r;

    assign refetch_excp_o = refetch_excp_i_r;

    assign pc_pro_o = pc_pro_i_r;

    assign ll_sc = mem_op[9:8];


endmodule

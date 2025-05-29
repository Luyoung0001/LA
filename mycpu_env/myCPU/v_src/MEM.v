`include "csr.h"
module MEM    #(
        parameter TLBNUM = 64
    )
    (
        // from exu
        input wire clk,
        input wire rst,

        input wire es_excp,
        input wire [15:0] es_excp_num,
        output wire ms_excp_out,
        output wire [15:0] ms_excp_num_out,

        input wire [7:0] in_mem_op,
        input wire [3:0] in_mem_mask,

        input wire [150:0] bus_exu_to_mem_data,
        output wire [149:0] bus_mem_to_wbu_data,

        // from mem_sram
        input wire [31:0] data_sram_rdata,
        output wire [85:0] bus_mem_bypass_data,

        // exception
        input wire [1:0] flush,

        input wire wbu_in_is_ertn,
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
        // tlbrd
        input wire [31:0]       tlbehi_in,
        input wire [31:0]       tlbelo0_in,
        input wire [31:0]       tlbelo1_in,
        input wire [31:0]       tlbidx_in,
        output wire [31:0]      tlbehi_o,
        output wire [31:0]      tlbelo0_o,
        output wire [31:0]      tlbelo1_o,
        output wire [31:0]      tlbidx_o1
    );

    wire excp_flush;
    wire ertn_flush;
    assign {excp_flush, ertn_flush} = flush;

    // 异常信号
    reg [15:0] es_excp_num_r; // 从上一级接收
    reg es_excp_r;

    wire [15:0] wire_es_excp_num;
    wire wire_es_excp;

    assign wire_es_excp_num = es_excp_num_r;
    assign wire_es_excp = es_excp_r;

    wire [15:0] ms_excp_num; // 当前阶段的异常 += 上一阶段
    wire ms_excp;            // 当前阶段的异常 += 上一阶段

    assign ms_excp_num = wire_es_excp_num;
    assign ms_excp = wire_es_excp;

    // 清空信号
    wire flush_sign;
    assign flush_sign = ertn_flush | excp_flush;

    // 数据相关
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;
    wire mem_over;

    wire mem_csr_we;
    wire [13:0] mem_csr_idx;
    wire [31:0] mem_csr_wdata;


    reg [150:0] bus_exu_to_mem_data_r;
    reg [31:0] reg_rdata;

    wire    [31:0] wire_exu_result;
    wire    wire_res_from_mem;
    wire    [4:0] wire_dest;
    wire    wire_gr_we;
    wire   [31:0] wire_pc;
    wire wire_csr_we;
    wire [13:0] wire_csr_idx;
    wire [31:0] wire_csr_wdata;
    wire wire_is_inst_ertn;
    wire [31:0] wire_error_va;

    wire gr_we;
    wire [4:0] dest;
    wire [31:0] pc;
    wire [31:0] final_result;

    reg [7:0] mem_op_reg;
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
               wire_csr_wdata,
               wire_is_inst_ertn,
               wire_error_va
           };

    // 输出
    assign ms_excp_out = ms_excp;
    assign ms_excp_num_out = ms_excp_num;
    assign mem_excp = ms_excp;   // 发送给上一级，目的是为了取消上一级的一些执行效果，比如内存写、除法计算等等
    assign is_ertn = wire_is_inst_ertn | wbu_in_is_ertn; // 同样也是为了取消上一级的执行效果

    assign gr_we          = wire_gr_we;
    assign dest           = wire_dest;
    assign pc             = wire_pc;


    wire [31:0] mem_result;

    wire [7:0] mem_op;
    wire [3:0] mem_mask;
    assign mem_op = mem_op_reg;
    assign mem_mask = mem_mask_reg;

    wire st_b;
    wire st_h;
    wire st_w;
    wire ld_b;
    wire ld_bu;
    wire ld_h;
    wire ld_hu;
    wire ld_w;

    assign st_b = mem_op[0];
    assign st_h = mem_op[1];
    assign st_w = mem_op[2];

    assign ld_b = mem_op[3];
    assign ld_bu = mem_op[4];
    assign ld_h = mem_op[5];
    assign ld_hu = mem_op[6];
    assign ld_w = mem_op[7];

    // 这里读出来的数据也很讲究
    assign mem_result = ld_b && mem_mask[0] ? {{24{reg_rdata[7]}}, reg_rdata[7:0]}:
           ld_b && mem_mask[1] ? {{24{reg_rdata[15]}}, reg_rdata[15:8]}:
           ld_b && mem_mask[2] ? {{24{reg_rdata[23]}}, reg_rdata[23:16]}:
           ld_b && mem_mask[3] ? {{24{reg_rdata[31]}}, reg_rdata[31:24]}:
           ld_bu && mem_mask[0] ? {24'b0, reg_rdata[7:0]}:
           ld_bu && mem_mask[1] ? {24'b0, reg_rdata[15:8]}:
           ld_bu && mem_mask[2] ? {24'b0, reg_rdata[23:16]}:
           ld_bu && mem_mask[3] ? {24'b0, reg_rdata[31:24]}:
           ld_h && mem_mask == 4'b0011 ? {{16{reg_rdata[15]}}, reg_rdata[15:0]}:
           ld_h && mem_mask == 4'b0110 ? {{16{reg_rdata[23]}}, reg_rdata[23:8]}:
           ld_h && mem_mask == 4'b1100 ? {{16{reg_rdata[31]}}, reg_rdata[31:16]}:
           ld_hu && mem_mask == 4'b0011 ? {16'b0, reg_rdata[15:0]}:
           ld_hu && mem_mask == 4'b0110 ? {16'b0, reg_rdata[23:8]}:
           ld_hu && mem_mask == 4'b1100 ? {16'b0, reg_rdata[31:16]}:
           reg_rdata;

    assign final_result = wire_res_from_mem ? mem_result : wire_exu_result;


    // 解决数据相关
    assign mem_regWr = gr_we;
    assign mem_data = final_result;
    assign mem_regAddr = wire_dest;

    assign mem_csr_we = wire_csr_we;
    assign mem_csr_idx = wire_csr_idx;
    assign mem_csr_wdata = wire_csr_wdata;

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
    reg [31:0] tlbehi_in_r;
    reg [31:0] tlbelo0_in_r;
    reg [31:0] tlbelo1_in_r;
    reg [31:0] tlbidx_in_r;

    always @(posedge clk) begin
        if (rst || flush_sign) begin
            mem_state <= 2'd0;
            reg_rdata <= 32'd0;
            bus_exu_to_mem_data_r <= 151'd0;
            mem_op_reg <= 8'd0;
            mem_mask_reg <= 4'd0;
            es_excp_num_r <= 16'd0;
            es_excp_r <= 1'b0;
            // tlb
            tlb_inst_bus_r <= 5'd0;
            // tlbsrch
            tlbsrch_index_r <= 6'd0;
            tlbsrch_found_r <= 1'b0;
            // tlbrd
            tlbehi_in_r <= 32'd0;
            tlbelo0_in_r <= 32'd0;
            tlbelo1_in_r <= 32'd0;
            tlbidx_in_r <= 32'd0;

        end
        else if (mem_state == 2'd0 && up_valid) begin
            reg_rdata <= data_sram_rdata;
            bus_exu_to_mem_data_r <= bus_exu_to_mem_data;
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
            // tlbrd
            tlbehi_in_r <= tlbehi_in;
            tlbelo0_in_r <= tlbelo0_in;
            tlbelo1_in_r <= tlbelo1_in;
            tlbidx_in_r <= tlbidx_in;
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
    // tlbrd
    assign tlbehi_o = tlbehi_in_r;
    assign tlbelo0_o = tlbelo0_in_r;
    assign tlbelo1_o = tlbelo1_in_r;
    assign tlbidx_o1 = tlbidx_in_r;

endmodule

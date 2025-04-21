module MEM(
        // from exu
        input wire clk,
        input wire rst,

        input wire es_excp,
        input wire [15:0] es_excp_num,
        output wire ms_excp_out,
        output wire [15:0] ms_excp_num_out,

        input wire [7:0] in_mem_op,
        input wire [3:0] in_mem_mask,

        input wire [118:0] bus_exu_to_mem_data,
        output wire [117:0] bus_mem_to_wbu_data,

        // from mem_sram
        input wire [31:0] data_sram_rdata,
        output wire [84:0] bus_mem_bypass_data,

        // exception
        input wire ertn_flush,
        input wire excp_flush,

        output wire mem_excp, // 发射到 exu 以实现精确异常

        // 握手信号
        //allowin
        input    ws_allowin, // 来自下游的 allowin 信号
        output   ms_allowin, // 发给上游的 allowin 信号

        input    es_to_ms_valid, // 来自上游的 valid 信号
        output   ms_to_ws_valid  // 发给下游的 valid 信号
    );

    // 异常信号
    reg [15:0] es_excp_num_r; // 从上一级接收
    reg es_excp_r;

    wire [15:0] wire_es_excp_num;
    wire wire_es_excp;

    assign wire_es_excp_num = es_excp_num_r;
    assign wire_es_excp = es_excp_r;



    wire [15:0] ms_excp_num;
    wire ms_excp;

    assign ms_excp_num = wire_es_excp_num;
    assign ms_excp = wire_es_excp;

    // 输出
    assign ms_excp_out = ms_excp;
    assign ms_excp_num_out = ms_excp_num;



    wire flush_sign;
    assign flush_sign = ertn_flush | excp_flush;

    assign mem_excp = ms_excp;

    // 数据相关
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    wire mem_csr_we;
    wire [13:0] mem_csr_idx;
    wire [31:0] mem_csr_wdata;



    reg [118:0] bus_exu_to_mem_data_r;

    reg     ms_valid;
    wire    ms_ready_go;

    wire    [31:0] wire_exu_result;
    wire    wire_res_from_mem;
    wire    [4:0] wire_dest;
    wire    wire_gr_we;
    wire   [31:0] wire_pc;
    wire wire_csr_we;
    wire [13:0] wire_csr_idx;
    wire [31:0] wire_csr_wdata;
    wire wire_is_inst_ertn;

    wire gr_we;
    wire [4:0] dest;
    wire [31:0] pc;
    wire [31:0] final_result;

    reg [7:0] mem_op_reg;
    reg [3:0] mem_mask_reg;

    assign {
            wire_res_from_mem,
            wire_exu_result,
            wire_gr_we,
            wire_dest,
            wire_pc,
            wire_csr_we,
            wire_csr_idx,
            wire_csr_wdata,
            wire_is_inst_ertn
        } = bus_exu_to_mem_data_r;

    assign bus_mem_to_wbu_data = {
               gr_we,
               dest,
               final_result,
               pc,
               wire_csr_we,
               wire_csr_idx,
               wire_csr_wdata,
               wire_is_inst_ertn
           };

    assign gr_we          = wire_gr_we & ms_valid;
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
    // assign mem_result   = data_sram_rdata;
    assign mem_result = ld_b && mem_mask[0] ? {{24{data_sram_rdata[7]}}, data_sram_rdata[7:0]}:
           ld_b && mem_mask[1] ? {{24{data_sram_rdata[15]}}, data_sram_rdata[15:8]}:
           ld_b && mem_mask[2] ? {{24{data_sram_rdata[23]}}, data_sram_rdata[23:16]}:
           ld_b && mem_mask[3] ? {{24{data_sram_rdata[31]}}, data_sram_rdata[31:24]}:
           ld_bu && mem_mask[0] ? {24'b0, data_sram_rdata[7:0]}:
           ld_bu && mem_mask[1] ? {24'b0, data_sram_rdata[15:8]}:
           ld_bu && mem_mask[2] ? {24'b0, data_sram_rdata[23:16]}:
           ld_bu && mem_mask[3] ? {24'b0, data_sram_rdata[31:24]}:
           ld_h && mem_mask == 4'b0011 ? {{16{data_sram_rdata[15]}}, data_sram_rdata[15:0]}:
           ld_h && mem_mask == 4'b0110 ? {{16{data_sram_rdata[23]}}, data_sram_rdata[23:8]}:
           ld_h && mem_mask == 4'b1100 ? {{16{data_sram_rdata[31]}}, data_sram_rdata[31:16]}:
           ld_hu && mem_mask == 4'b0011 ? {16'b0, data_sram_rdata[15:0]}:
           ld_hu && mem_mask == 4'b0110 ? {16'b0, data_sram_rdata[23:8]}:
           ld_hu && mem_mask == 4'b1100 ? {16'b0, data_sram_rdata[31:16]}:
           data_sram_rdata;

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
               mem_csr_wdata
           };

    assign ms_ready_go    = 1'b1;
    assign ms_allowin     = !ms_valid || ms_ready_go && ws_allowin;
    assign ms_to_ws_valid =  ms_valid && ms_ready_go;

    always @(posedge clk) begin
        if (rst || flush_sign) begin
            ms_valid <= 1'b0;
        end
        else if (ms_allowin) begin
            ms_valid <= es_to_ms_valid;
        end

        if (es_to_ms_valid && ms_allowin) begin
            bus_exu_to_mem_data_r <= bus_exu_to_mem_data;
            mem_op_reg <= in_mem_op;
            mem_mask_reg <= in_mem_mask;

            es_excp_num_r <= es_excp_num;
            es_excp_r <= es_excp;

        end
    end



endmodule

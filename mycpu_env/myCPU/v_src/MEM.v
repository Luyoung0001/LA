module MEM(
        // from exu
        input wire clk,
        input wire rst,


        input wire [70:0] bus_exu_to_mem_data,
        output wire [69:0] bus_mem_to_wbu_data,

        // from mem_sram
        input wire [31:0] data_sram_rdata,
        output wire [37:0] bus_mem_bypass_data,

        // 握手信号
        //allowin
        input    ws_allowin, // 来自下游的 allowin 信号
        output   ms_allowin, // 发给上游的 allowin 信号

        input    es_to_ms_valid, // 来自上游的 valid 信号
        output   ms_to_ws_valid  // 发给下游的 valid 信号
    );

    // 数据相关
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    reg [70:0] bus_exu_to_mem_data_r;

    reg     ms_valid;
    wire    ms_ready_go;

    wire    [31:0] wire_exu_result;
    wire    wire_res_from_mem;
    wire    [4:0] wire_dest;
    wire    wire_gr_we;
    wire   [31:0] wire_pc;

    wire gr_we;
    wire [4:0] dest;
    wire [31:0] pc;
    wire [31:0] final_result;

    assign {
            wire_res_from_mem,
            wire_exu_result,
            wire_gr_we,
            wire_dest,
            wire_pc
        } = bus_exu_to_mem_data_r;

    assign bus_mem_to_wbu_data = {
               gr_we,
               dest,
               final_result,
               pc
           };

    assign gr_we          = wire_gr_we & ms_valid;
    assign dest           = wire_dest;
    assign pc             = wire_pc;


    wire [31:0] mem_result;
    assign mem_result   = data_sram_rdata;
    assign final_result = wire_res_from_mem ? mem_result : wire_exu_result;


    // 解决数据相关
    assign mem_regWr = gr_we;
    assign mem_data = final_result;
    assign mem_regAddr = wire_dest;

    assign bus_mem_bypass_data = {
               mem_regWr,
               mem_data,
               mem_regAddr};

    assign ms_ready_go    = 1'b1;
    assign ms_allowin     = !ms_valid || ms_ready_go && ws_allowin;
    assign ms_to_ws_valid =  ms_valid && ms_ready_go;

    always @(posedge clk) begin
        if (rst) begin
            ms_valid <= 1'b0;
        end
        else if (ms_allowin) begin
            ms_valid <= es_to_ms_valid;
        end

        if (es_to_ms_valid && ms_allowin) begin
            bus_exu_to_mem_data_r <= bus_exu_to_mem_data;

        end
    end



endmodule

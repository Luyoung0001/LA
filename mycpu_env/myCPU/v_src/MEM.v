module MEM(
        // from exu
        input wire clk,
        input wire rst,
        input wire mem_we,
        input wire valid,
        input wire [31:0] alu_result,
        input wire [31:0] rkd_value,
        input wire res_from_mem,

        // to mem_sram
        output wire [31:0] data_sram_addr,
        output wire [31:0] data_sram_wdata,
        output wire [3:0] data_sram_we,
        // from mem_sram
        input wire [31:0] data_sram_rdata,

        //  for wb
        input wire in_gr_we,
        input wire [4:0] in_dest,
        input wire [31:0] in_pc,

        output wire gr_we,
        output wire [4:0] dest,

        // to wb
        output wire [31:0] final_result,
        output wire [31:0] pc,


        // 数据相关
        output wire mem_regWr,
        output wire [31:0] mem_data,
        output wire [4:0] mem_regAddr
    );

    reg mem_we_reg;
    reg [31:0] alu_result_reg;
    reg [31:0] rkd_value_reg;
    reg res_from_mem_reg;

    reg [4:0] dest_reg;
    reg gr_we_reg;
    reg [31:0] pc_reg;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            mem_we_reg <= 1'b0;
            alu_result_reg <= 32'd0;
            rkd_value_reg <= 32'd0;
            res_from_mem_reg <= 1'b0;
            dest_reg <= 5'd0;
            gr_we_reg <= 1'b0;
            pc_reg <= 32'd0;
        end
        else begin
            mem_we_reg <= mem_we;
            alu_result_reg <= alu_result;
            rkd_value_reg <= rkd_value;
            res_from_mem_reg <= res_from_mem;
            dest_reg <= in_dest;
            gr_we_reg <= in_gr_we;
            pc_reg <= in_pc;
        end
    end

    wire wire_mem_we;
    wire [31:0] wire_alu_result;
    wire [31:0] wire_rkd_value;
    wire wire_res_from_mem;
    wire [4:0] wire_dest;
    wire wire_gr_we;


    assign wire_mem_we = mem_we_reg;
    assign wire_alu_result = alu_result_reg;
    assign wire_rkd_value = rkd_value_reg;
    assign wire_res_from_mem = res_from_mem_reg;

    assign wire_dest = dest_reg;
    assign wire_gr_we = gr_we_reg;

    assign data_sram_we    = {wire_mem_we && valid,
                              wire_mem_we && valid,
                              wire_mem_we && valid,
                              wire_mem_we && valid};
    assign data_sram_addr  = wire_alu_result;
    assign data_sram_wdata = wire_rkd_value;

    assign gr_we          = wire_gr_we;
    assign dest           = wire_dest;
    assign pc             = pc_reg;


    wire [31:0] mem_result;
    assign mem_result   = data_sram_rdata;
    assign final_result = wire_res_from_mem ? mem_result : wire_alu_result;


        // 解决数据相关
    assign mem_regWr = wire_gr_we;
    assign mem_data = final_result;
    assign mem_regAddr = wire_dest;



endmodule

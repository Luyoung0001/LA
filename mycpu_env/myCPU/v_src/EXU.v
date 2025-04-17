module EXU (
        input wire clk,
        input wire rst,

        // bus
        input wire [177:0] bus_ds_to_es_data,
        output wire [70:0] bus_exu_to_mem_data,

        // to mem_sram
        output wire [31:0] data_sram_addr,
        output wire [31:0] data_sram_wdata,
        output wire [3:0] data_sram_we,

        output wire [37:0] bus_exu_bypass_data,

        // 握手信号
        // allowin
        input     ms_allowin, // 来自的下游的 allowin 信号
        output    es_allowin, // 发给上游的 allowin 信号

        input     ds_to_es_valid, // 来自的上游的 valid 信号
        output    es_to_ms_valid  // 发给下游的 valid 信号
    );

    // 数据相关
    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;

    reg [177:0] ds_to_es_bus_data_r;


    reg         es_valid      ;
    wire        es_ready_go   ;

    wire [9:0] mul_div_op;
    wire [31:0] wire_alu_op;
    wire [31:0] wire_alu_src1;
    wire [31:0] wire_alu_src2;

    wire wire_in_mem_we;
    wire [31:0] wire_in_rkd_value;
    wire wire_in_res_from_mem;

    wire wire_in_gr_we;
    wire [4:0] wire_in_dest;
    wire [31:0] wire_in_pc;

    wire res_from_mem;
    wire [31:0] exu_result;
    wire gr_we;
    wire [4:0] dest;
    wire [31:0] pc;

    assign {
            mul_div_op,
            wire_alu_op,
            wire_alu_src1,
            wire_alu_src2,

            wire_in_mem_we,
            wire_in_rkd_value,
            wire_in_res_from_mem,

            wire_in_gr_we,
            wire_in_dest,
            wire_in_pc
        } = ds_to_es_bus_data_r;

    assign bus_exu_to_mem_data = {
               res_from_mem,
               exu_result,
               gr_we,
               dest,
               pc
           };


    assign res_from_mem = wire_in_res_from_mem;
    assign gr_we = wire_in_gr_we & es_valid;
    assign dest = wire_in_dest;
    assign pc = wire_in_pc;


    wire [31:0] alu_result;
    alu u_alu(
            .alu_op     (wire_alu_op    ),
            .alu_src1   (wire_alu_src1  ),
            .alu_src2   (wire_alu_src2  ),
            .alu_result (alu_result)
        );

    // 解决数据相关
    assign exu_regWr = gr_we;
    assign exu_data = exu_result;
    assign exu_regAddr = wire_in_dest;

    assign bus_exu_bypass_data = {
               exu_regWr,
               exu_data,
               exu_regAddr};



    // 提前发射访存信号，必须在 es 阶段有效
    assign data_sram_we = {wire_in_mem_we && es_valid,
                           wire_in_mem_we && es_valid,
                           wire_in_mem_we && es_valid,
                           wire_in_mem_we && es_valid};
    assign data_sram_addr  = alu_result; // 访存地址
    assign data_sram_wdata = wire_in_rkd_value;

    // 乘除法
    wire op_div;   //signed divide operation low
    wire op_divu;  //unsigned divide operation low
    wire op_mod;   //signed mod operation low
    wire op_modu;  //unsigned mod operation low


    assign op_div  = mul_div_op[3];
    assign op_divu = mul_div_op[4];
    assign op_mod  = mul_div_op[5];
    assign op_modu = mul_div_op[6];

    wire div;
    wire div_signed;
    assign div = op_div || op_divu || op_mod || op_modu;
    assign div_signed = op_div || op_mod;


    // 乘法器
    wire [31:0] mul_result;
    mul mul(
            .mul_div_op(mul_div_op),
            .alu_src1(wire_alu_src1),
            .alu_src2(wire_alu_src2),
            .mul_result(mul_result)
        );

    // 除法器，调用 ip 实现，这里是 axi 总线
    wire [31:0] div_result;
    wire [31:0] mod_result;
    reg complete;
    wire wire_complete;
    always @(posedge clk) begin
        if (rst) begin
            complete <= 1'b0;
        end
        else begin
            complete <= wire_complete;
        end
    end

    divider divider(
                .div_clk(clk),
                .reset(rst),
                .div(div),
                .div_signed (div_signed),
                .x(wire_alu_src1),
                .y(wire_alu_src2),
                .s(div_result),
                .r(mod_result),
                .complete(wire_complete)
            );

    // 对结果进行汇总

    assign exu_result = ({32{op_div}} & div_result)
           | ({32{op_divu}} & div_result)
           | ({32{op_mod}} & mod_result)
           | ({32{op_modu}} & mod_result)
           | ({32{mul_div_op[0]}} & mul_result)
           | ({32{mul_div_op[1]}} & mul_result)
           | ({32{mul_div_op[2]}} & mul_result)
           | ({32{wire_alu_op[0]}} & alu_result)
           | ({32{wire_alu_op[1]}} & alu_result)
           | ({32{wire_alu_op[2]}} & alu_result)
           | ({32{wire_alu_op[3]}} & alu_result)
           | ({32{wire_alu_op[4]}} & alu_result)
           | ({32{wire_alu_op[5]}} & alu_result)
           | ({32{wire_alu_op[6]}} & alu_result)
           | ({32{wire_alu_op[7]}} & alu_result)
           | ({32{wire_alu_op[8]}} & alu_result)
           | ({32{wire_alu_op[9]}} & alu_result)
           | ({32{wire_alu_op[10]}} & alu_result)
           | ({32{wire_alu_op[11]}} & alu_result);


    // 握手信号
    assign es_ready_go    = complete & div ? 1'b1 : (div ? 1'b0 : 1'b1);
    assign es_allowin     = !es_valid || es_ready_go && ms_allowin;
    assign es_to_ms_valid =  es_valid && es_ready_go;

    always @(posedge clk) begin
        if (rst) begin
            es_valid <= 1'b0;
        end
        else if (es_allowin) begin
            es_valid <= ds_to_es_valid;
        end
        if (ds_to_es_valid && es_allowin) begin
            ds_to_es_bus_data_r <= bus_ds_to_es_data;

        end
    end
endmodule

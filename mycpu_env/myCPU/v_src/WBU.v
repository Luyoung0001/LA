module WBU(
        // from mem
        input wire clk,
        input wire rst,
        input wire valid,
        input wire gr_we,
        input wire [4:0] dest,
        input wire [31:0] final_result,
        input wire [31:0] in_pc,

        // to rf
        output wire rf_we,
        output wire [4:0] rf_waddr,
        output wire [31:0] rf_wdata,
        output wire [31:0] pc,

        // 数据相关
        output wire wbu_regWr,
        output wire [31:0] wbu_data,
        output wire [4:0] wbu_regAddr,

        // 握手信号
        //allowin
        output   ws_allowin,    // 发给上游的 allowin 信号
        input    ms_to_ws_valid // 来自的上游的 valid 信号

    );

    reg gr_we_reg;
    reg [4:0] dest_reg;
    reg [31:0] final_result_reg;
    reg [31:0] pc_reg;

    reg         ws_valid;
    wire        ws_ready_go;

    // always @(posedge clk or posedge rst) begin
    //     if (rst) begin
    //         gr_we_reg <= 1'b0;
    //         dest_reg <= 5'd0;
    //         final_result_reg <= 32'd0;
    //         pc_reg <= 32'd0;
    //     end
    //     else begin
    //         gr_we_reg <= gr_we;
    //         dest_reg <= dest;
    //         final_result_reg <= final_result;
    //         pc_reg <= in_pc;
    //     end
    // end

    wire wire_gr_we;
    wire [4:0] wire_dest;
    wire [31:0] wire_final_result;
    assign wire_gr_we = gr_we_reg;
    assign wire_dest = dest_reg;
    assign wire_final_result = final_result_reg;

    assign rf_we    = wire_gr_we && ws_valid;
    assign rf_waddr = wire_dest;
    assign rf_wdata = wire_final_result;
    assign pc       = pc_reg;

    // 解决数据相关
    assign wbu_regWr = rf_we;
    assign wbu_data = wire_final_result;
    assign wbu_regAddr = wire_dest;



    assign ws_ready_go = 1'b1;
    assign ws_allowin  = !ws_valid || ws_ready_go;
    always @(posedge clk) begin
        if (rst) begin
            ws_valid <= 1'b0;
        end
        else if (ws_allowin) begin
            ws_valid <= ms_to_ws_valid;
        end

        if (ms_to_ws_valid && ws_allowin) begin
            // ms_to_ws_bus_r <= ms_to_ws_bus;
            // 卸货
            // gr_we_reg <= gr_we;
            gr_we_reg <= gr_we;
            dest_reg <= dest;
            final_result_reg <= final_result;
            pc_reg <= in_pc;
        end
    end


endmodule

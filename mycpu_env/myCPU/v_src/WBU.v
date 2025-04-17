module WBU(
        // from mem
        input wire clk,
        input wire rst,

        input wire [69:0] bus_mem_to_wbu_data,

        // to rf
        output wire rf_we,
        output wire [4:0] rf_waddr,
        output wire [31:0] rf_wdata,
        output wire [31:0] pc,

        // bus
        output wire [37:0] bus_wbu_bypass_data,

        // 握手信号
        //allowin
        output   ws_allowin,    // 发给上游的 allowin 信号
        input    ms_to_ws_valid // 来自的上游的 valid 信号

    );
    // 数据相关
    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;

    wire wire_gr_we;
    wire [4:0] wire_dest;
    wire [31:0] wire_final_result;
    wire [31:0] wire_pc;

    reg [69:0] bus_mem_to_wbu_data_r;

    assign {
            wire_gr_we,
            wire_dest,
            wire_final_result,
            wire_pc
        } = bus_mem_to_wbu_data_r;

    reg         ws_valid;
    wire        ws_ready_go;

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
            bus_mem_to_wbu_data_r <= bus_mem_to_wbu_data;
        end
    end
    assign rf_we    = wire_gr_we & ws_valid;
    assign rf_waddr = wire_dest;
    assign rf_wdata = wire_final_result;
    assign pc       = wire_pc;

    // 解决数据相关
    assign wbu_regWr = rf_we;
    assign wbu_data = wire_final_result;
    assign wbu_regAddr = wire_dest;

    assign bus_wbu_bypass_data = {
               wbu_regWr,
               wbu_data,
               wbu_regAddr};
endmodule

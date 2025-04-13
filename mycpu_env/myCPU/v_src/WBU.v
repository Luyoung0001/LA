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
        output wire [31:0] pc

    );

    reg gr_we_reg;
    reg [4:0] dest_reg;
    reg [31:0] final_result_reg;
    reg [31:0] pc_reg;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            gr_we_reg <= 1'b0;
            dest_reg <= 5'd0;
            final_result_reg <= 32'd0;
            pc_reg <= 32'd0;
        end
        else begin
            gr_we_reg <= gr_we;
            dest_reg <= dest;
            final_result_reg <= final_result;
            pc_reg <= in_pc;
        end
    end

    wire wire_gr_we;
    wire [4:0] wire_dest;
    wire [31:0] wire_final_result;
    assign wire_gr_we = gr_we_reg;
    assign wire_dest = dest_reg;
    assign wire_final_result = final_result_reg;

    assign rf_we    = wire_gr_we && valid;
    assign rf_waddr = wire_dest;
    assign rf_wdata = wire_final_result;
    assign pc       = pc_reg;


endmodule

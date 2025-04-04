module data_ram(
    input clk,
    input we,
    input  [31:0] a,
    input  [31:0] d,
    output reg [31:0] spo
);
    initial begin
    end

    // dpi-c
    import "DPI-C" function int data_ram_read(input int addr);
    import "DPI-C" function void data_ram_write(input int addr, input int wdata);

    always @(posedge clk) begin
        if (we) begin
            data_ram_write(a,d);
        end
    end
    always @(*) begin
        spo = data_ram_read(a);
    end

endmodule

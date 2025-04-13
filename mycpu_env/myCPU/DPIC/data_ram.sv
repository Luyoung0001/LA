module data_ram(
    input clk,
    input [3:0] we,
    input  en,
    input  [31:0] a,
    input  [31:0] d,
    output [31:0] spo
);
    initial begin
    end

    // dpi-c
    import "DPI-C" function int data_ram_read(input int addr);
    import "DPI-C" function void data_ram_write(input int addr, input int wdata);

    always @(clk) begin
        if (we[3]) begin
            data_ram_write(a, d);
        end
    end

    assign spo = data_ram_read(a);


endmodule

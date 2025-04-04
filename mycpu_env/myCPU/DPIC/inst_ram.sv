module inst_ram(
    input clk,
    input we,
    input  [31:0] a,
    input  [31:0] d,
    output [31:0] spo
);
    // dpi-c
    import "DPI-C" function int inst_ram_read(input int addr);
    
assign spo = inst_ram_read(a);

endmodule

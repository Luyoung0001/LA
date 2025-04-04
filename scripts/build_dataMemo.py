import argparse

def hex_to_data_mem_verilog(hex_filepath, verilog_filepath):
    """
    Converts a hex file (.hex) to a Verilog data memory module initialization file (.v).
    Removes spaces from hex literals to ensure correct Verilog syntax.

    Args:
        hex_filepath (str): Path to the input hex file.
        verilog_filepath (str): Path to the output Verilog file.
    """

    mem_init_lines = []
    address = 0

    try:
        with open(hex_filepath, 'r') as hex_file:
            for line in hex_file:
                line = line.strip()
                if line and not line.startswith('//'):  # Ignore empty lines and comments
                    # Remove spaces from the hex line before creating Verilog literal
                    hex_value_no_spaces = line.replace(" ", "")
                    verilog_hex_literal = f"        memory[{address}]  = 32'h{hex_value_no_spaces};" # Modified for DataMem memory name
                    mem_init_lines.append(verilog_hex_literal)
                    address += 1

    except FileNotFoundError:
        print(f"Error: Input hex file '{hex_filepath}' not found.")
        return

    with open(verilog_filepath, 'w') as verilog_file:
        verilog_file.write("module data_ram(\n")
        verilog_file.write("    input clk,\n")
        verilog_file.write("    input we,\n")
        verilog_file.write("    input  [15:0] a,\n")
        verilog_file.write("    input  [31:0] d,\n")
        verilog_file.write("    output reg [31:0] spo\n")
        verilog_file.write(");\n")
        verilog_file.write("    reg [31:0] memory [0:1023]; // 4KB 内存\n")
        verilog_file.write("// 初始化 memory\n\n")
        verilog_file.write("    initial begin\n")
        for init_line in mem_init_lines:
            verilog_file.write(f"{init_line}\n")
        verilog_file.write("    end\n\n")
        verilog_file.write("    // 同步写操作（需时钟）\n")
        verilog_file.write("    always @(posedge clk) begin\n")
        verilog_file.write("        if (we) begin\n")
        verilog_file.write("            memory[a[9:0]]        <= d;\n")
        verilog_file.write("        end\n")
        verilog_file.write("    end\n")
        verilog_file.write("    always @(*) begin\n")
        verilog_file.write("        if(a[9:0] == 10'd256) begin\n")
        verilog_file.write("            spo = 32'ha;\n")
        verilog_file.write("        end\n")
        verilog_file.write("        else\n")
        verilog_file.write("            spo = memory[a[9:0]];\n")
        verilog_file.write("    end\n\n")
        verilog_file.write("endmodule\n")

    print(f"Successfully converted '{hex_filepath}' to '{verilog_filepath}'")

def main():
    # 使用 argparse 来解析命令行参数
    parser = argparse.ArgumentParser(description="Convert HEX file to Verilog data memory module")
    parser.add_argument("input_hex_file", help="Path to the input HEX file")
    parser.add_argument("output_verilog_file", help="Path to the output Verilog file")

    # 解析命令行参数
    args = parser.parse_args()

    # 调用函数
    hex_to_data_mem_verilog(args.input_hex_file, args.output_verilog_file)

if __name__ == "__main__":
    main()
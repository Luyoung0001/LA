module verilator_top(
        input  wire        rst,
        input  wire        clk
    );

    wire cpu_resetn;
    assign cpu_resetn = ~rst;
    // always @(posedge clk)begin
    //     cpu_resetn <= ~rst;
    // end

    //cpu inst sram
    wire        cpu_inst_en;
    wire [3:0]       cpu_inst_we;
    wire [31:0] cpu_inst_addr;
    wire [31:0] cpu_inst_wdata;
    wire [31:0] cpu_inst_rdata;
    //cpu data sram
    wire        cpu_data_en;
    wire  [3:0]      cpu_data_we;
    wire [31:0] cpu_data_addr;
    wire [31:0] cpu_data_wdata;
    wire [31:0] cpu_data_rdata;

    //debug
    wire [31:0] debug_wb_pc/* verilator public */;
    wire [ 3:0] debug_wb_rf_we/* verilator public */;
    wire [ 4:0] debug_wb_rf_wnum/* verilator public */;
    wire [31:0] debug_wb_rf_wdata/* verilator public */;

    //data sram
    wire        data_sram_en;
    wire        data_sram_we;
    wire [31:0] data_sram_addr;
    wire [31:0] data_sram_wdata;
    wire [31:0] data_sram_rdata;

    // //conf
    // wire        conf_en;
    // wire        conf_we;
    // wire [31:0] conf_addr;
    // wire [31:0] conf_wdata;
    // wire [31:0] conf_rdata;
    // wire [15:0] conf_led;



    //cpu
    mycpu_top cpu(
                  .clk              (clk       ),
                  .resetn           (cpu_resetn    ),  //low active

                  .inst_sram_en     (cpu_inst_en   ),
                  .inst_sram_we     (cpu_inst_we   ),
                  .inst_sram_addr   (cpu_inst_addr ),
                  .inst_sram_wdata  (cpu_inst_wdata),
                  .inst_sram_rdata  (cpu_inst_rdata),

                  .data_sram_en     (cpu_data_en   ),
                  .data_sram_we     (cpu_data_we   ),
                  .data_sram_addr   (cpu_data_addr ),
                  .data_sram_wdata  (cpu_data_wdata),
                  .data_sram_rdata  (cpu_data_rdata),

                  .debug_wb_pc      (debug_wb_pc),
                  .debug_wb_rf_we   (debug_wb_rf_we),
                  .debug_wb_rf_wnum (debug_wb_rf_wnum),
                  .debug_wb_rf_wdata(debug_wb_rf_wdata)
              );

    // assign cpu_data_rdata = (cpu_data_addr == 12'd1024)? {24'b0, ~switch[7:0]} :
    //        32'b0;

    //inst ram
    inst_ram inst_ram
                (
                 .clk   (clk            ),
                 .we    (cpu_inst_we        ),
                 .en    (cpu_inst_en),
                 .a     (cpu_inst_addr),
                 .d     (cpu_inst_wdata     ),
                 .spo   (cpu_inst_rdata     )
             );
    data_ram data_ram
             (
                 .clk   (clk            ),
                 .we    (cpu_data_we        ),
                 .en    (cpu_data_en        ),
                 .a     (cpu_data_addr),
                 .d     (cpu_data_wdata     ),
                 .spo   (cpu_data_rdata     )
             );
    debug debug
          (   .debug_wb_pc(debug_wb_pc),
              .debug_wb_rf_we(debug_wb_rf_we),
              .debug_wb_rf_wnum(debug_wb_rf_wnum),
              .debug_wb_rf_wdata(debug_wb_rf_wdata)
          );




endmodule


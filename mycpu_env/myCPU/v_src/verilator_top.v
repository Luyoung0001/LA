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


    // wire_AXI

    wire [3:0] wire_arid;
    wire [31:0] wire_araddr;
    wire [7:0] wire_arlen;
    wire [2:0] wire_arsize;
    wire [1:0] wire_arburst;
    wire [1:0] wire_arlock;
    wire [3:0] wire_arcache;
    wire [2:0] wire_arprot;
    wire        wire_arvalid;
    wire        wire_arready;

    wire [3:0] wire_rid;
    wire [31:0] wire_rdata;
    wire [1:0] wire_rresp;
    wire        wire_rlast;
    wire        wire_rvalid;
    wire        wire_rready;

    wire [3:0] wire_awid;
    wire [31:0] wire_awaddr;
    wire [7:0] wire_awlen;
    wire [2:0] wire_awsize;
    wire [1:0] wire_awburst;
    wire [1:0] wire_awlock;
    wire [3:0] wire_awcache;
    wire [2:0] wire_awprot;
    wire        wire_awvalid;
    wire        wire_awready;


    wire [3:0] wire_wid;
    wire [31:0] wire_wdata;
    wire [3:0] wire_wstrb;
    wire wire_wlast;
    wire        wire_wvalid;
    wire        wire_wready;

    wire [1:0] wire_bresp;
    wire        wire_bvalid;
    wire        wire_bready;
    wire [3:0] wire_bid;


    //cpu
    cpu_top cpu(
                .clk              (clk       ),
                .resetn           (cpu_resetn    ),  //low active

                .inst_sram_en     (cpu_inst_en   ),
                .inst_sram_we     (cpu_inst_we   ),
                .inst_sram_addr   (cpu_inst_addr ),
                .inst_sram_wdata  (cpu_inst_wdata),
                .inst_sram_rdata  (cpu_inst_rdata),

                // .arid           (wire_arid),
                // .araddr         (wire_araddr),
                // .arlen          (wire_arlen),
                // .arsize         (wire_arsize),
                // .arburst        (wire_arburst),
                // .arlock         (wire_arlock),
                // .arcache        (wire_arcache),
                // .arprot         (wire_arprot),
                // .arvalid        (wire_arvalid),
                // .arready        (wire_arready),
                // .rid            (wire_rid),
                // .rdata          (wire_rdata),
                // .rresp          (wire_rresp),
                // .rlast          (wire_rlast),
                // .rvalid         (wire_rvalid),
                // .rready         (wire_rready),
                // .awid           (wire_awid),
                // .awaddr         (wire_awaddr),
                // .awlen          (wire_awlen),
                // .awsize         (wire_awsize),
                // .awburst        (wire_awburst),
                // .awlock         (wire_awlock),
                // .awcache        (wire_awcache),
                // .awprot         (wire_awprot),
                // .awvalid        (wire_awvalid),
                // .awready        (wire_awready),

                // .wid            (wire_wid),
                // .wdata          (wire_wdata),
                // .wstrb          (wire_wstrb),
                // .wlast          (wire_wlast),
                // .wvalid         (wire_wvalid),
                // .wready         (wire_wready),

                // .bresp          (wire_bresp),
                // .bvalid         (wire_bvalid),
                // .bready         (wire_bready),
                // .bid            (wire_bid),

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

    // axi_ram axi_ram (
    //             .clock (clk),
    //             .reset (rst),
    //             // AR
    //             .arid           (wire_arid),
    //             .araddr         (wire_araddr),
    //             .arlen          (wire_arlen),
    //             .arsize         (wire_arsize),
    //             .arburst        (wire_arburst),
    //             .arlock         (wire_arlock),
    //             .arcache        (wire_arcache),
    //             .arprot         (wire_arprot),
    //             .arvalid        (wire_arvalid),
    //             .arready        (wire_arready),
    //             .rid            (wire_rid),
    //             .rdata          (wire_rdata),
    //             .rresp          (wire_rresp),
    //             .rlast          (wire_rlast),
    //             .rvalid         (wire_rvalid),
    //             .rready         (wire_rready),
    //             .awid           (wire_awid),
    //             .awaddr         (wire_awaddr),
    //             .awlen          (wire_awlen),
    //             .awsize         (wire_awsize),
    //             .awburst        (wire_awburst),
    //             .awlock         (wire_awlock),
    //             .awcache        (wire_awcache),
    //             .awprot         (wire_awprot),
    //             .awvalid        (wire_awvalid),
    //             .awready        (wire_awready),

    //             .wid            (wire_wid),
    //             .wdata          (wire_wdata),
    //             .wstrb          (wire_wstrb),
    //             .wlast          (wire_wlast),
    //             .wvalid         (wire_wvalid),
    //             .wready         (wire_wready),

    //             .bresp          (wire_bresp),
    //             .bvalid         (wire_bvalid),
    //             .bready         (wire_bready),
    //             .bid            (wire_bid)

    //         );
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


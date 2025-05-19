module verilator_top(
        input  wire        rst,
        input  wire        clk

    );

    wire cpu_resetn;
    assign cpu_resetn = ~rst;

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

    //cpu inst sram
    wire        cpu_inst_req;
    wire        cpu_inst_wr;
    wire [1 :0] cpu_inst_size;
    wire [3 :0] cpu_inst_wstrb;
    wire [31:0] cpu_inst_addr;
    wire [31:0] cpu_inst_wdata;
    wire        cpu_inst_addr_ok;
    wire        cpu_inst_data_ok;
    wire [31:0] cpu_inst_rdata;

    //cpu data sram
    wire        cpu_data_req;
    wire        cpu_data_wr;
    wire [1 :0] cpu_data_size;
    wire [3 :0] cpu_data_wstrb;
    wire [31:0] cpu_data_addr;
    wire [31:0] cpu_data_wdata;
    wire        cpu_data_addr_ok;
    wire        cpu_data_data_ok;
    wire [31:0] cpu_data_rdata;


    //cpu
    mycpu_top cpu(
                .aclk              (clk       ),
                .aresetn           (cpu_resetn    ),  //low active


                // .inst_sram_req    (cpu_inst_req    ),
                // .inst_sram_wr     (cpu_inst_wr     ),
                // .inst_sram_size   (cpu_inst_size   ),
                // .inst_sram_wstrb  (cpu_inst_wstrb  ),
                // .inst_sram_addr   (cpu_inst_addr   ),
                // .inst_sram_wdata  (cpu_inst_wdata  ),
                // .inst_sram_addr_ok(cpu_inst_addr_ok),
                // .inst_sram_data_ok(cpu_inst_data_ok),
                // .inst_sram_rdata  (cpu_inst_rdata  ),

                .arid           (wire_arid),
                .araddr         (wire_araddr),
                .arlen          (wire_arlen),
                .arsize         (wire_arsize),
                .arburst        (wire_arburst),
                .arlock         (wire_arlock),
                .arcache        (wire_arcache),
                .arprot         (wire_arprot),
                .arvalid        (wire_arvalid),
                .arready        (wire_arready),
                .rid            (wire_rid),
                .rdata          (wire_rdata),
                .rresp          (wire_rresp),
                .rlast          (wire_rlast),
                .rvalid         (wire_rvalid),
                .rready         (wire_rready),
                .awid           (wire_awid),
                .awaddr         (wire_awaddr),
                .awlen          (wire_awlen),
                .awsize         (wire_awsize),
                .awburst        (wire_awburst),
                .awlock         (wire_awlock),
                .awcache        (wire_awcache),
                .awprot         (wire_awprot),
                .awvalid        (wire_awvalid),
                .awready        (wire_awready),

                .wid            (wire_wid),
                .wdata          (wire_wdata),
                .wstrb          (wire_wstrb),
                .wlast          (wire_wlast),
                .wvalid         (wire_wvalid),
                .wready         (wire_wready),

                .bresp          (wire_bresp),
                .bvalid         (wire_bvalid),
                .bready         (wire_bready),
                .bid            (wire_bid),


                // .data_sram_req    (cpu_data_req    ),
                // .data_sram_wr     (cpu_data_wr     ),
                // .data_sram_size   (cpu_data_size   ),
                // .data_sram_wstrb  (cpu_data_wstrb  ),
                // .data_sram_addr   (cpu_data_addr   ),
                // .data_sram_wdata  (cpu_data_wdata  ),
                // .data_sram_addr_ok(cpu_data_addr_ok),
                // .data_sram_data_ok(cpu_data_data_ok),
                // .data_sram_rdata  (cpu_data_rdata  ),


                .debug_wb_pc      (debug_wb_pc),
                .debug_wb_rf_we   (debug_wb_rf_we),
                .debug_wb_rf_wnum (debug_wb_rf_wnum),
                .debug_wb_rf_wdata(debug_wb_rf_wdata)
            );


    // 包装器

    // wire        inst_ram_en   ;
    // wire [3 :0] inst_ram_we   ;
    // wire [31:0] inst_ram_addr ;
    // wire [31:0] inst_ram_wdata;
    // wire [31:0] inst_ram_rdata;

    // sram_wrap u_inst_sram_wrap(
    //               .clk              (clk   ),
    //               .resetn           (cpu_resetn),  //low active

    //               .req             (cpu_inst_req    ),
    //               .wr              (cpu_inst_wr     ),
    //               .size            (cpu_inst_size   ),
    //               .wstrb           (cpu_inst_wstrb  ),
    //               .addr            (cpu_inst_addr   ),
    //               .wdata           (cpu_inst_wdata  ),
    //               .addr_ok         (cpu_inst_addr_ok),
    //               .data_ok         (cpu_inst_data_ok),
    //               .rdata           (cpu_inst_rdata  ),

    //               //slave
    //               .ram_en          (inst_ram_en     ),
    //               .ram_we          (inst_ram_we     ),
    //               .ram_addr        (inst_ram_addr   ),
    //               .ram_wdata       (inst_ram_wdata  ),
    //               .ram_rdata       (inst_ram_rdata  )
    //           );

    // //inst ram
    // inst_ram inst_ram
    //          (
    //              .clk   (clk            ),
    //              .we    (inst_ram_we        ),
    //              .en    (inst_ram_en),
    //              .a     (inst_ram_addr),
    //              .d     (inst_ram_wdata     ),
    //              .spo   (inst_ram_rdata     )
    //          );


    // // data ram
    // wire        data_ram_en   ;
    // wire [3 :0] data_ram_we   ;
    // wire [31:0] data_ram_addr ;
    // wire [31:0] data_ram_wdata;
    // wire [31:0] data_ram_rdata;

    // sram_wrap u_data_sram_wrap(
    //               .clk             (clk          ),
    //               .resetn          (cpu_resetn       ),  //low active

    //               .req             (cpu_data_req    ),
    //               .wr              (cpu_data_wr     ),
    //               .size            (cpu_data_size   ),
    //               .wstrb           (cpu_data_wstrb  ),
    //               .addr            (cpu_data_addr   ),
    //               .wdata           (cpu_data_wdata  ),
    //               .addr_ok         (cpu_data_addr_ok),
    //               .data_ok         (cpu_data_data_ok),
    //               .rdata           (cpu_data_rdata  ),

    //               //slave
    //               .ram_en          (data_ram_en     ),
    //               .ram_we          (data_ram_we     ),
    //               .ram_addr        (data_ram_addr   ),
    //               .ram_wdata       (data_ram_wdata  ),
    //               .ram_rdata       (data_ram_rdata  )
    //           );


    // data_ram data_ram
    //          (
    //              .clk   (clk            ),
    //              .we    (data_ram_we        ),
    //              .en    (data_ram_en        ),
    //              .a     (data_ram_addr),
    //              .d     (data_ram_wdata     ),
    //              .spo   (data_ram_rdata     )
    //          );

    debug debug
          (   .debug_wb_pc(debug_wb_pc),
              .debug_wb_rf_we(debug_wb_rf_we),
              .debug_wb_rf_wnum(debug_wb_rf_wnum),
              .debug_wb_rf_wdata(debug_wb_rf_wdata)
          );

    axi_ram axi_ram (
                .clock (clk),
                .reset (rst),
                // AR
                .arid           (wire_arid),
                .araddr         (wire_araddr),
                .arlen          (wire_arlen),
                .arsize         (wire_arsize),
                .arburst        (wire_arburst),
                .arlock         (wire_arlock),
                .arcache        (wire_arcache),
                .arprot         (wire_arprot),
                .arvalid        (wire_arvalid),
                .arready        (wire_arready),
                .rid            (wire_rid),
                .rdata          (wire_rdata),
                .rresp          (wire_rresp),
                .rlast          (wire_rlast),
                .rvalid         (wire_rvalid),
                .rready         (wire_rready),
                .awid           (wire_awid),
                .awaddr         (wire_awaddr),
                .awlen          (wire_awlen),
                .awsize         (wire_awsize),
                .awburst        (wire_awburst),
                .awlock         (wire_awlock),
                .awcache        (wire_awcache),
                .awprot         (wire_awprot),
                .awvalid        (wire_awvalid),
                .awready        (wire_awready),

                .wid            (wire_wid),
                .wdata          (wire_wdata),
                .wstrb          (wire_wstrb),
                .wlast          (wire_wlast),
                .wvalid         (wire_wvalid),
                .wready         (wire_wready),

                .bresp          (wire_bresp),
                .bvalid         (wire_bvalid),
                .bready         (wire_bready),
                .bid            (wire_bid)

            );




endmodule


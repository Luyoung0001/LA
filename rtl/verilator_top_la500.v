`timescale 1ns / 1ps

// Simulation shell for the vendored openLA500 reference CPU.
// It presents the same public commit debug wires as the default verilator_top,
// so Verilator/main.cpp can run dynamic difftest and IPC accounting unchanged.
module verilator_top (
    input wire rst,
    input wire clk
);

    wire cpu_resetn = ~rst;

    wire [31:0] debug_wb_pc       /* verilator public */;
    wire        debug_wb_valid    /* verilator public */;
    wire [3:0]  debug_wb_rf_wen   /* verilator public */;
    wire [4:0]  debug_wb_rf_wnum  /* verilator public */;
    wire [31:0] debug_wb_rf_wdata /* verilator public */;
    wire [31:0] debug_wb_inst     /* verilator public */;
    wire        debug_excp_valid  /* verilator public */;
    wire [5:0]  debug_excp_ecode  /* verilator public */;
    wire [10:0] debug_intr_no     /* verilator public */;
    wire        debug_ertn_valid  /* verilator public */;

    wire        ws_valid;
    wire [31:0] rf_rdata;

    wire [3:0]  axi_arid;
    wire [31:0] axi_araddr;
    wire [7:0]  axi_arlen;
    wire [2:0]  axi_arsize;
    wire [1:0]  axi_arburst;
    wire [1:0]  axi_arlock;
    wire [3:0]  axi_arcache;
    wire [2:0]  axi_arprot;
    wire        axi_arvalid;
    wire        axi_arready;

    wire [3:0]  axi_rid;
    wire [31:0] axi_rdata;
    wire [1:0]  axi_rresp;
    wire        axi_rlast;
    wire        axi_rvalid;
    wire        axi_rready;

    wire [3:0]  axi_awid;
    wire [31:0] axi_awaddr;
    wire [7:0]  axi_awlen;
    wire [2:0]  axi_awsize;
    wire [1:0]  axi_awburst;
    wire [1:0]  axi_awlock;
    wire [3:0]  axi_awcache;
    wire [2:0]  axi_awprot;
    wire        axi_awvalid;
    wire        axi_awready;

    wire [3:0]  axi_wid;
    wire [31:0] axi_wdata;
    wire [3:0]  axi_wstrb;
    wire        axi_wlast;
    wire        axi_wvalid;
    wire        axi_wready;

    wire [3:0]  axi_bid;
    wire [1:0]  axi_bresp;
    wire        axi_bvalid;
    wire        axi_bready;

    wire la500_axi_arvalid       /* verilator public */;
    wire la500_axi_arready       /* verilator public */;
    wire la500_axi_arid0         /* verilator public */;
    wire la500_axi_rvalid        /* verilator public */;
    wire la500_axi_rready        /* verilator public */;
    wire la500_axi_rid0          /* verilator public */;
    wire la500_axi_rlast         /* verilator public */;
    wire la500_axi_awvalid       /* verilator public */;
    wire la500_axi_awready       /* verilator public */;
    wire la500_axi_wvalid        /* verilator public */;
    wire la500_axi_wready        /* verilator public */;
    wire la500_axi_bvalid        /* verilator public */;
    wire la500_axi_bready        /* verilator public */;

    wire la500_inst_valid        /* verilator public */;
    wire la500_inst_addr_ok      /* verilator public */;
    wire la500_inst_data_ok      /* verilator public */;
    wire la500_inst_rd_req       /* verilator public */;
    wire la500_inst_rd_rdy       /* verilator public */;
    wire la500_inst_ret_valid    /* verilator public */;
    wire la500_inst_ret_last     /* verilator public */;
    wire la500_inst_uncache_en    /* verilator public */;
    wire la500_inst_rd_line       /* verilator public */;

    wire la500_data_valid        /* verilator public */;
    wire la500_data_addr_ok      /* verilator public */;
    wire la500_data_data_ok      /* verilator public */;
    wire la500_data_rd_req       /* verilator public */;
    wire la500_data_rd_rdy       /* verilator public */;
    wire la500_data_ret_valid    /* verilator public */;
    wire la500_data_ret_last     /* verilator public */;
    wire la500_data_wr_req       /* verilator public */;
    wire la500_data_wr_rdy       /* verilator public */;
    wire la500_write_buffer_empty /* verilator public */;
    wire la500_data_uncache_en    /* verilator public */;
    wire la500_data_rd_line       /* verilator public */;
    wire la500_data_wr_line       /* verilator public */;

    wire la500_fs_to_ds_valid    /* verilator public */;
    wire la500_ds_to_es_valid    /* verilator public */;
    wire la500_es_to_ms_valid    /* verilator public */;
    wire la500_ms_to_ws_valid    /* verilator public */;
    wire la500_commit_inst       /* verilator public */;
    wire la500_icache_miss       /* verilator public */;
    wire la500_dcache_miss       /* verilator public */;
    wire la500_fs_icache_miss    /* verilator public */;
    wire la500_ms_dcache_miss    /* verilator public */;
    wire la500_br_inst           /* verilator public */;
    wire la500_br_pre_error      /* verilator public */;
    wire la500_excp_flush        /* verilator public */;
    wire la500_ertn_flush        /* verilator public */;
    wire la500_refetch_flush     /* verilator public */;
    wire la500_icacop_flush      /* verilator public */;
    wire la500_idle_flush        /* verilator public */;

    assign debug_wb_valid = ws_valid;
    assign debug_excp_valid = u_cpu.excp_flush;
    assign debug_excp_ecode = u_cpu.ws_csr_ecode;
    assign debug_intr_no = u_cpu.csr_estat_diff_0[12:2];
    assign debug_ertn_valid = u_cpu.ertn_flush;
    assign la500_axi_arvalid = axi_arvalid;
    assign la500_axi_arready = axi_arready;
    assign la500_axi_arid0 = axi_arid[0];
    assign la500_axi_rvalid = axi_rvalid;
    assign la500_axi_rready = axi_rready;
    assign la500_axi_rid0 = axi_rid[0];
    assign la500_axi_rlast = axi_rlast;
    assign la500_axi_awvalid = axi_awvalid;
    assign la500_axi_awready = axi_awready;
    assign la500_axi_wvalid = axi_wvalid;
    assign la500_axi_wready = axi_wready;
    assign la500_axi_bvalid = axi_bvalid;
    assign la500_axi_bready = axi_bready;

    assign la500_inst_valid = u_cpu.inst_valid;
    assign la500_inst_addr_ok = u_cpu.inst_addr_ok;
    assign la500_inst_data_ok = u_cpu.inst_data_ok;
    assign la500_inst_rd_req = u_cpu.inst_rd_req;
    assign la500_inst_rd_rdy = u_cpu.inst_rd_rdy;
    assign la500_inst_ret_valid = u_cpu.inst_ret_valid;
    assign la500_inst_ret_last = u_cpu.inst_ret_last;
    assign la500_inst_uncache_en = u_cpu.inst_uncache_en;
    assign la500_inst_rd_line = (u_cpu.inst_rd_type == 3'b100);

    assign la500_data_valid = u_cpu.data_valid;
    assign la500_data_addr_ok = u_cpu.data_addr_ok;
    assign la500_data_data_ok = u_cpu.data_data_ok;
    assign la500_data_rd_req = u_cpu.data_rd_req;
    assign la500_data_rd_rdy = u_cpu.data_rd_rdy;
    assign la500_data_ret_valid = u_cpu.data_ret_valid;
    assign la500_data_ret_last = u_cpu.data_ret_last;
    assign la500_data_wr_req = u_cpu.data_wr_req;
    assign la500_data_wr_rdy = u_cpu.data_wr_rdy;
    assign la500_write_buffer_empty = u_cpu.write_buffer_empty;
    assign la500_data_uncache_en = u_cpu.data_uncache_en;
    assign la500_data_rd_line = (u_cpu.data_rd_type == 3'b100);
    assign la500_data_wr_line = (u_cpu.data_wr_type == 3'b100);

    assign la500_fs_to_ds_valid = u_cpu.fs_to_ds_valid;
    assign la500_ds_to_es_valid = u_cpu.ds_to_es_valid;
    assign la500_es_to_ms_valid = u_cpu.es_to_ms_valid;
    assign la500_ms_to_ws_valid = u_cpu.ms_to_ws_valid;
    assign la500_commit_inst = u_cpu.commit_inst;
    assign la500_icache_miss = u_cpu.icache_miss;
    assign la500_dcache_miss = u_cpu.dcache_miss;
    assign la500_fs_icache_miss = u_cpu.fs_icache_miss;
    assign la500_ms_dcache_miss = u_cpu.ms_dcache_miss;
    assign la500_br_inst = u_cpu.br_inst;
    assign la500_br_pre_error = u_cpu.br_pre_error;
    assign la500_excp_flush = u_cpu.excp_flush;
    assign la500_ertn_flush = u_cpu.ertn_flush;
    assign la500_refetch_flush = u_cpu.refetch_flush;
    assign la500_icacop_flush = u_cpu.icacop_flush;
    assign la500_idle_flush = u_cpu.idle_flush;

    core_top u_cpu (
        .aclk(clk),
        .aresetn(cpu_resetn),
        .intrpt(8'b0),

        .arid(axi_arid),
        .araddr(axi_araddr),
        .arlen(axi_arlen),
        .arsize(axi_arsize),
        .arburst(axi_arburst),
        .arlock(axi_arlock),
        .arcache(axi_arcache),
        .arprot(axi_arprot),
        .arvalid(axi_arvalid),
        .arready(axi_arready),

        .rid(axi_rid),
        .rdata(axi_rdata),
        .rresp(axi_rresp),
        .rlast(axi_rlast),
        .rvalid(axi_rvalid),
        .rready(axi_rready),

        .awid(axi_awid),
        .awaddr(axi_awaddr),
        .awlen(axi_awlen),
        .awsize(axi_awsize),
        .awburst(axi_awburst),
        .awlock(axi_awlock),
        .awcache(axi_awcache),
        .awprot(axi_awprot),
        .awvalid(axi_awvalid),
        .awready(axi_awready),

        .wid(axi_wid),
        .wdata(axi_wdata),
        .wstrb(axi_wstrb),
        .wlast(axi_wlast),
        .wvalid(axi_wvalid),
        .wready(axi_wready),

        .bid(axi_bid),
        .bresp(axi_bresp),
        .bvalid(axi_bvalid),
        .bready(axi_bready),

        .break_point(1'b0),
        .infor_flag(1'b0),
        .reg_num(5'b0),
        .ws_valid(ws_valid),
        .rf_rdata(rf_rdata),

        .debug0_wb_pc(debug_wb_pc),
        .debug0_wb_rf_wen(debug_wb_rf_wen),
        .debug0_wb_rf_wnum(debug_wb_rf_wnum),
        .debug0_wb_rf_wdata(debug_wb_rf_wdata),
        .debug0_wb_inst(debug_wb_inst)
    );

    axi_ram u_mem (
        .clock(clk),
        .reset(rst),

        .arid(axi_arid),
        .araddr(axi_araddr),
        .arlen(axi_arlen),
        .arsize(axi_arsize),
        .arburst(axi_arburst),
        .arlock(axi_arlock),
        .arcache(axi_arcache),
        .arprot(axi_arprot),
        .arvalid(axi_arvalid),
        .arready(axi_arready),

        .rid(axi_rid),
        .rdata(axi_rdata),
        .rresp(axi_rresp),
        .rlast(axi_rlast),
        .rvalid(axi_rvalid),
        .rready(axi_rready),

        .awid(axi_awid),
        .awaddr(axi_awaddr),
        .awlen(axi_awlen),
        .awsize(axi_awsize),
        .awburst(axi_awburst),
        .awlock(axi_awlock),
        .awcache(axi_awcache),
        .awprot(axi_awprot),
        .awvalid(axi_awvalid),
        .awready(axi_awready),

        .wid(axi_wid),
        .wdata(axi_wdata),
        .wstrb(axi_wstrb),
        .wlast(axi_wlast),
        .wvalid(axi_wvalid),
        .wready(axi_wready),

        .bid(axi_bid),
        .bresp(axi_bresp),
        .bvalid(axi_bvalid),
        .bready(axi_bready)
    );

    wire unused_debug = |rf_rdata;

endmodule

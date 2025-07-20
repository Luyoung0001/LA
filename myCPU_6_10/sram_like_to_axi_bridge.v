module sram_like_to_axi_bridge(

        input wire clk,
        input wire rst,

        // SRAM like
        // input wire         inst_sram_req,
        // input wire         inst_sram_wr,
        // input wire [1:0]   inst_sram_size,
        // input wire [3:0]   inst_sram_wstrb,
        // input wire [31:0]  inst_sram_addr,
        // input wire [31:0]  inst_sram_wdata,
        // output  wire         inst_sram_addr_ok,
        // output  wire         inst_sram_data_ok,
        // output  wire [31:0]  inst_sram_rdata,

        input wire          data_sram_req,
        input wire          data_sram_wr,
        input wire [1:0]    data_sram_size,
        input wire [3:0]    data_sram_wstrb,
        input wire [31:0]   data_sram_addr,
        input wire [31:0]   data_sram_wdata,
        output  wire        data_sram_addr_ok,
        output  wire        data_sram_data_ok,
        output  wire [31:0] data_sram_rdata,

        // icache
        input   wire        icache_rd_req,
        input   wire [2:0]  icache_rd_type,
        input   wire [31:0] icache_rd_addr,
        output  wire        icache_rd_rdy,
        output  wire        icache_ret_valid,
        output  wire        icache_ret_last,
        output  wire [31:0] icache_ret_data,

        // icache 鐢ㄤ笉鍒?
        input   wire         icache_wr_req,
        input   wire [2:0]   icache_wr_type,
        input   wire [31:0]  icache_wr_addr,
        input   wire [3:0]   icache_wr_wstrb,
        input   wire [127:0] icache_wr_data,
        output  wire         icache_wr_rdy,

        // AXI
        output   wire  [3:0]  arid,
        output   wire  [31:0] araddr,
        output   wire  [7:0]  arlen,
        output   wire  [2:0]  arsize,
        output   wire  [1:0]  arburst,
        output   wire  [1:0]  arlock,
        output   wire  [3:0]  arcache,
        output   wire  [2:0]  arprot,
        output   wire         arvalid,
        input    wire         arready,

        input   wire  [3:0]  rid,
        input   wire  [31:0] rdata,
        input   wire  [1:0]  rresp,
        input   wire         rlast,
        input   wire         rvalid,
        output  wire         rready,

        output   wire  [3:0]  awid,
        output   reg   [31:0] awaddr,
        output   reg   [7:0]  awlen,
        output   reg   [2:0]  awsize,
        output   wire  [1:0]  awburst,
        output   wire  [1:0]  awlock,
        output   wire  [3:0]  awcache,
        output   wire  [2:0]  awprot,
        output   reg          awvalid,
        input    wire         awready,

        output   wire  [3:0]  wid,
        output   reg   [31:0] wdata,
        output   reg   [3:0]  wstrb,
        output   reg          wlast,
        output   reg          wvalid,
        input    wire         wready,

        input   wire  [3:0]   bid,
        input   wire  [1:0]   bresp,
        input   wire          bvalid,
        output  reg           bready
    );

    // Fixed AXI signals
    assign arburst = 2'b01;    // INCR burst type
    assign arlock  = 2'b00;    // Normal access
    assign arcache = 4'b0000;  // Non-cacheable
    assign arprot  = 3'b000;   // Unprivileged, secure, data access

    assign awburst = 2'b01;    // INCR burst type
    assign awlock  = 2'b00;    // Normal access
    assign awcache = 4'b0000;  // Non-cacheable
    assign awprot  = 3'b000;   // Unprivileged, secure, data access

    assign awid    = 4'b0001;  // ID for write transactions
    assign wid     = 4'b0001;  // Write ID (same as awid)

    // FSM states
    localparam IDLE            = 3'b000;
    localparam READ_ADDR       = 3'b001;
    localparam READ_DATA       = 3'b010;
    localparam WRITE_ADDR      = 3'b011;
    localparam WRITE_DATA      = 3'b100;
    localparam WRITE_RESP      = 3'b101;

    // FSM state registers
    reg [2:0] inst_state;
    reg [2:0] data_state;

    // SRAM to AXI size conversion
    function [2:0] convert_size;
        input [1:0] sram_size;
        begin
            case(sram_size)
                2'b00:
                    convert_size = 3'b000; // 1 byte
                2'b01:
                    convert_size = 3'b001; // 2 bytes
                2'b10:
                    convert_size = 3'b010; // 4 bytes
                2'b11:
                    convert_size = 3'b010; // 4 bytes (max for 32-bit bus)
            endcase
        end
    endfunction

    // 绐佸彂闀垮害鍜屾鏁?
    wire inst_rd_cache_line = icache_rd_type == 3'b100;
    wire [2:0] inst_real_rd_size  = inst_rd_cache_line ? 3'b10 : icache_rd_type;
    wire [7:0] inst_real_rd_len   = inst_rd_cache_line ? 8'b11 : 8'b0; // 3 +1娆★紝姣忔 4 涓瓧鑺傦紝鍏? 16 涓瓧鑺?

    // Read/write arbitration logic
    wire inst_read_request;
    wire data_read_request;
    wire data_write_request;

    assign inst_read_request = icache_rd_req;
    assign data_read_request = data_sram_req && !data_sram_wr && !inst_read_request; // 鎸囦护浼樺厛
    assign data_write_request = data_sram_req && data_sram_wr;

    // Handshake signals
    reg inst_addr_accepted;
    reg data_addr_accepted;
    reg inst_data_received;
    reg data_data_received;
    reg data_write_done;

    // Read data buffers
    reg [31:0] inst_read_data;
    reg [31:0] data_read_data;

    // Signal for tracking which request is being processed
    reg handling_inst_request;
    reg handling_data_request;

    // SRAM interface status signals
    // assign inst_sram_addr_ok = inst_addr_accepted;
    assign data_sram_addr_ok = data_addr_accepted;
    // assign inst_sram_data_ok = inst_data_received;
    assign data_sram_data_ok = data_data_received || data_write_done;
    // assign inst_sram_rdata = inst_read_data;
    assign data_sram_rdata = data_read_data;


    // icache
    assign icache_rd_rdy = inst_state == IDLE;
    assign icache_ret_valid = rvalid && rid[0] == 1'b0;
    assign icache_ret_last = rlast;
    assign icache_ret_data = rdata;

    reg inst_arvalid;
    reg [3:0] inst_arid;
    reg [31:0] inst_araddr;
    reg [2:0] inst_arsize;
    reg [7:0] inst_arlen;
    reg inst_rready;

    reg data_arvalid;
    reg [3:0] data_arid;
    reg [31:0] data_araddr;
    reg [2:0] data_arsize;
    reg [7:0] data_arlen;
    reg data_rready;


    // Main FSM for instruction requests

    reg [7:0] inst_beat_count;
    reg [7:0] inst_total_beats;
    reg    inst_burst_complete;
    always @(posedge clk) begin
        if (rst) begin
            inst_state <= IDLE;
            inst_addr_accepted <= 1'b0;
            inst_data_received <= 1'b0;
            inst_read_data <= 32'b0;
            handling_inst_request <= 1'b0;

            inst_arvalid <= 1'b0;
            inst_arid <= 4'd0;
            inst_araddr <= 32'd0;
            inst_arsize <= 3'd0;
            inst_arlen <= 8'd0;
            inst_rready <= 1'b0;

            // 娣诲姞绐佸彂浼犺緭鏀寔淇″彿
            inst_beat_count <= 8'd0;
            inst_total_beats <= 8'd0;
            inst_burst_complete <= 1'b0;
        end

        else begin
            // Reset per-cycle signals
            inst_addr_accepted <= 1'b0;
            inst_data_received <= 1'b0;
            inst_burst_complete <= 1'b0;

            case (inst_state)
                IDLE: begin
                    if (inst_read_request && !handling_data_request) begin
                        inst_state <= READ_ADDR;
                        handling_inst_request <= 1'b1;
                        inst_arvalid <= 1'b1;
                        inst_arid <= 4'b0000; // ID for instruction reads
                        inst_araddr <= icache_rd_addr;
                        inst_arsize <= inst_real_rd_size;
                        inst_arlen <= inst_real_rd_len;

                        // 鍒濆鍖栫獊鍙戜紶杈撹鏁板櫒
                        inst_total_beats <= inst_real_rd_len + 1; // arlen=0琛ㄧず1涓妭鎷?
                        inst_beat_count <= 8'd0;
                    end
                end

                READ_ADDR: begin
                    inst_arvalid <= 1'b1;
                    inst_arid <= 4'b0000; // ID for instruction reads
                    inst_araddr <= icache_rd_addr;
                    inst_arsize <= inst_real_rd_size;
                    inst_arlen <= inst_real_rd_len;

                    if (arready) begin
                        inst_arvalid <= 1'b0;
                        inst_state <= READ_DATA;
                        inst_addr_accepted <= 1'b1;
                        inst_rready <= 1'b1;
                    end
                end

                READ_DATA: begin
                    inst_rready <= 1'b1; // 淇濇寔ready淇″彿
                    if (rvalid && rid[0] == 1'b0) begin  // Check if it's instruction data (rid[0] = 0)
                        // 澶勭悊褰撳墠鑺傛媿鐨勬暟鎹?
                        // inst_read_data <= rdata;
                        inst_data_received <= 1'b1;
                        // 鏇存柊鑺傛媿璁℃暟鍣?
                        inst_beat_count <= inst_beat_count + 1;
                        // 妫?鏌ユ槸鍚︿负鏈?鍚庝竴涓妭鎷?
                        if (rlast || (inst_beat_count == (inst_total_beats - 1))) begin
                            // 绐佸彂浼犺緭瀹屾垚
                            inst_rready <= 1'b0;
                            inst_state <= IDLE;
                            handling_inst_request <= 1'b0;
                            inst_burst_complete <= 1'b1;
                            inst_beat_count <= 8'd0;
                        end
                        // 濡傛灉涓嶆槸鏈?鍚庝竴涓妭鎷嶏紝缁х画鍦≧EAD_DATA鐘舵?佺瓑寰呬笅涓?涓暟鎹?
                    end
                end

                default:
                    inst_state <= IDLE;
            endcase
        end
    end

    // Main FSM for data requests
    always @(posedge clk) begin
        if (rst) begin
            data_state <= IDLE;
            data_addr_accepted <= 1'b0;
            data_data_received <= 1'b0;
            data_write_done <= 1'b0;
            data_read_data <= 32'b0;
            handling_data_request <= 1'b0;

            data_arvalid <= 1'b0;
            data_arid <= 4'd0;
            data_araddr <= 32'd0;
            data_arsize <= 3'd0;
            data_arlen <= 8'd0;
            data_rready <= 1'b0;

            // Reset AXI signals
            // arvalid <= 1'b0;
            // rready <= 1'b0;
            awvalid <= 1'b0;
            wvalid <= 1'b0;
            wlast <= 1'b0;
            bready <= 1'b0;
        end
        else begin
            // Reset per-cycle signals
            data_addr_accepted <= 1'b0;
            data_data_received <= 1'b0;
            data_write_done <= 1'b0;

            case (data_state)
                IDLE: begin
                    if (!handling_inst_request) begin
                        if (data_read_request) begin
                            data_state <= READ_ADDR;
                            handling_data_request <= 1'b1;

                            data_arvalid <= 1'b1;
                            data_arid <= 4'b0001; // ID for data reads
                            data_araddr <= data_sram_addr;
                            data_arsize <= convert_size(data_sram_size);
                            data_arlen <= 8'b00000000; // Single transfer
                        end
                        else if (data_write_request) begin
                            data_state <= WRITE_ADDR;
                            handling_data_request <= 1'b1;

                            awvalid <= 1'b1;
                            awaddr <= data_sram_addr;
                            awsize <= convert_size(data_sram_size);
                            awlen <= 8'b00000000; // Single transfer
                        end
                    end
                end

                READ_ADDR: begin

                    data_arvalid <= 1'b1;
                    data_arid <= 4'b0001; // ID for data reads
                    data_araddr <= data_sram_addr;
                    data_arsize <= convert_size(data_sram_size);
                    data_arlen <= 8'b00000000; // Single transfer

                    if (arready) begin
                        // arvalid <= 1'b0;
                        data_arvalid <= 1'b0;
                        data_state <= READ_DATA;
                        data_addr_accepted <= 1'b1;
                        // rready <= 1'b1;
                        data_rready <= 1'b1;
                    end
                end

                READ_DATA: begin
                    if (rvalid && rid[0] == 1'b1) begin  // Check if it's data read (rid[0] = 1)
                        data_read_data <= rdata;
                        data_data_received <= 1'b1;
                        // rready <= 1'b0;
                        data_rready <= 1'b0;
                        data_state <= IDLE;
                        handling_data_request <= 1'b0;
                    end
                end

                WRITE_ADDR: begin
                    awvalid <= 1'b1;
                    awaddr <= data_sram_addr;
                    awsize <= convert_size(data_sram_size);
                    awlen <= 8'b00000000; // Single transfer

                    if (awready) begin
                        awvalid <= 1'b0;
                        data_state <= WRITE_DATA;
                        data_addr_accepted <= 1'b1;
                        wvalid <= 1'b1;
                        wdata <= data_sram_wdata;
                        wstrb <= data_sram_wstrb;
                        wlast <= 1'b1; // Single transfer
                    end
                end

                WRITE_DATA: begin
                    if (wready) begin
                        wvalid <= 1'b0;
                        wlast <= 1'b0;
                        data_state <= WRITE_RESP;
                        bready <= 1'b1;
                    end
                end

                WRITE_RESP: begin
                    if (bvalid) begin
                        bready <= 1'b0;
                        data_write_done <= 1'b1;
                        data_state <= IDLE;
                        handling_data_request <= 1'b0;
                    end
                end

                default:
                    data_state <= IDLE;
            endcase
        end
    end

    assign  arvalid = inst_arvalid | data_arvalid;
    assign  araddr = handling_inst_request ? inst_araddr : data_araddr;
    assign arid = handling_inst_request ? inst_arid : data_arid;
    assign arsize = handling_inst_request ? inst_arsize : data_arsize;
    assign arlen = handling_inst_request ? inst_arlen : data_arlen;
    assign rready = inst_rready | data_rready;

endmodule



// module sram_like_to_axi_bridge(
//         input wire clk,
//         input wire rst,
//         // SRAM like
//         input wire         inst_req_cancel,
//         input wire         inst_sram_req,
//         input wire         inst_sram_wr,
//         input wire [1:0]   inst_sram_size,
//         input wire [3:0]   inst_sram_wstrb,
//         input wire [31:0]  inst_sram_addr,
//         input wire [31:0]  inst_sram_wdata,
//         output  wire         inst_sram_addr_ok,
//         output  wire         inst_sram_data_ok,
//         output  wire [31:0]  inst_sram_rdata,

//         input wire        data_req_cancel,
//         input wire        data_sram_req,
//         input wire        data_sram_wr,
//         input wire [1:0]  data_sram_size,
//         input wire [3:0]  data_sram_wstrb,
//         input wire [31:0] data_sram_addr,
//         input wire [31:0] data_sram_wdata,
//         output  wire        data_sram_addr_ok,
//         output  wire        data_sram_data_ok,
//         output  wire [31:0] data_sram_rdata,

//         // AXI
//         output   wire  [3:0]  arid,
//         output   wire  [31:0] araddr,
//         output   wire  [7:0]  arlen,
//         output   wire  [2:0]  arsize,
//         output   wire  [1:0]  arburst,
//         output   wire  [1:0]  arlock,
//         output   wire  [3:0]  arcache,
//         output   wire  [2:0]  arprot,
//         output   wire         arvalid,
//         input    wire         arready,

//         input   wire  [3:0]  rid,
//         input   wire  [31:0] rdata,
//         input   wire  [1:0]  rresp,
//         input   wire         rlast,
//         input   wire         rvalid,
//         output  wire         rready,

//         output   wire  [3:0]  awid,
//         output   reg   [31:0] awaddr,
//         output   reg   [7:0]  awlen,
//         output   reg   [2:0]  awsize,
//         output   wire  [1:0]  awburst,
//         output   wire  [1:0]  awlock,
//         output   wire  [3:0]  awcache,
//         output   wire  [2:0]  awprot,
//         output   reg          awvalid,
//         input    wire         awready,

//         output   wire  [3:0]  wid,
//         output   reg   [31:0] wdata,
//         output   reg   [3:0]  wstrb,
//         output   reg          wlast,
//         output   reg          wvalid,
//         input    wire         wready,

//         input   wire  [3:0]   bid,
//         input   wire  [1:0]   bresp,
//         input   wire          bvalid,
//         output  reg           bready
//     );

//     // Fixed AXI signals
//     assign arburst = 2'b01;    // INCR burst type
//     assign arlock  = 2'b00;    // Normal access
//     assign arcache = 4'b0000;  // Non-cacheable
//     assign arprot  = 3'b000;   // Unprivileged, secure, data access

//     assign awburst = 2'b01;    // INCR burst type
//     assign awlock  = 2'b00;    // Normal access
//     assign awcache = 4'b0000;  // Non-cacheable
//     assign awprot  = 3'b000;   // Unprivileged, secure, data access

//     assign awid    = 4'b0001;  // ID for write transactions
//     assign wid     = 4'b0001;  // Write ID (same as awid)

//     // FSM states
//     localparam IDLE            = 3'b000;
//     localparam READ_ADDR       = 3'b001;
//     localparam READ_DATA       = 3'b010;
//     localparam WRITE_ADDR      = 3'b011;
//     localparam WRITE_DATA      = 3'b100;
//     localparam WRITE_RESP      = 3'b101;

//     // FSM state registers
//     reg [2:0] inst_state;
//     reg [2:0] data_state;

//     // SRAM to AXI size conversion
//     function [2:0] convert_size;
//         input [1:0] sram_size;
//         begin
//             case(sram_size)
//                 2'b00:
//                     convert_size = 3'b000; // 1 byte
//                 2'b01:
//                     convert_size = 3'b001; // 2 bytes
//                 2'b10:
//                     convert_size = 3'b010; // 4 bytes
//                 2'b11:
//                     convert_size = 3'b010; // 4 bytes (max for 32-bit bus)
//             endcase
//         end
//     endfunction

//     // Read/write arbitration logic
//     wire inst_read_request;
//     wire data_read_request;
//     wire data_write_request;

//     assign inst_read_request = inst_sram_req && !inst_sram_wr;
//     assign data_read_request = data_sram_req && !data_sram_wr && !inst_read_request; // 指令优先
//     assign data_write_request = data_sram_req && data_sram_wr;

//     // Handshake signals
//     reg inst_addr_accepted;
//     reg data_addr_accepted;
//     reg inst_data_received;
//     reg data_data_received;
//     reg data_write_done;

//     // Read data buffers
//     reg [31:0] inst_read_data;
//     reg [31:0] data_read_data;

//     // Signal for tracking which request is being processed
//     reg handling_inst_request;
//     reg handling_data_request;

//     // SRAM interface status signals
//     assign inst_sram_addr_ok = inst_addr_accepted;
//     assign data_sram_addr_ok = data_addr_accepted;
//     assign inst_sram_data_ok = inst_data_received;
//     assign data_sram_data_ok = data_data_received || data_write_done;
//     assign inst_sram_rdata = inst_read_data;
//     assign data_sram_rdata = data_read_data;

//     reg inst_arvalid;
//     reg [3:0] inst_arid;
//     reg [31:0] inst_araddr;
//     reg [2:0] inst_arsize;
//     reg [7:0] inst_arlen;
//     reg inst_rready;

//     reg data_arvalid;
//     reg [3:0] data_arid;
//     reg [31:0] data_araddr;
//     reg [2:0] data_arsize;
//     reg [7:0] data_arlen;
//     reg data_rready;

//     // Main FSM for instruction requests
//     always @(posedge clk) begin
//         if (rst) begin
//             inst_state <= IDLE;
//             inst_addr_accepted <= 1'b0;
//             inst_data_received <= 1'b0;
//             inst_read_data <= 32'b0;
//             handling_inst_request <= 1'b0;

//             inst_arvalid <= 1'b0;
//             inst_arid <= 4'd0;
//             inst_araddr <= 32'd0;
//             inst_arsize <= 3'd0;
//             inst_arlen <= 8'd0;
//             inst_rready <= 1'b0;
//         end

//         else begin
//             // Reset per-cycle signals
//             inst_addr_accepted <= 1'b0;
//             inst_data_received <= 1'b0;
//             case (inst_state)
//                 IDLE: begin
//                     if (inst_read_request && !handling_data_request) begin
//                         inst_state <= READ_ADDR;
//                         handling_inst_request <= 1'b1;
//                         inst_arvalid <= 1'b1;
//                         inst_arid <= 4'b0000; // ID for instruction reads
//                         inst_araddr <= inst_sram_addr;
//                         inst_arsize <= convert_size(inst_sram_size);
//                         inst_arlen <= 8'b00000000; // Single transfer
//                     end
//                 end

//                 READ_ADDR: begin
//                     inst_arvalid <= 1'b1;
//                     inst_arid <= 4'b0000; // ID for instruction reads
//                     inst_araddr <= inst_sram_addr;
//                     inst_arsize <= convert_size(inst_sram_size);
//                     inst_arlen <= 8'b00000000; // Single transfer

//                     if (arready) begin
//                         inst_arvalid <= 1'b0;
//                         inst_state <= READ_DATA;
//                         inst_addr_accepted <= 1'b1;
//                         inst_rready <= 1'b1;
//                     end
//                 end

//                 READ_DATA: begin
//                     if (rvalid && rid[0] == 1'b0) begin  // Check if it's instruction data (rid[0] = 0)
//                         inst_read_data <= rdata;
//                         inst_data_received <= 1'b1;
//                         inst_rready <= 1'b0;
//                         inst_state <= IDLE;
//                         handling_inst_request <= 1'b0;
//                     end
//                 end

//                 default:
//                     inst_state <= IDLE;
//             endcase
//         end
//     end



//     // Main FSM for data requests
//     always @(posedge clk) begin
//         if (rst) begin
//             data_state <= IDLE;
//             data_addr_accepted <= 1'b0;
//             data_data_received <= 1'b0;
//             data_write_done <= 1'b0;
//             data_read_data <= 32'b0;
//             handling_data_request <= 1'b0;

//             data_arvalid <= 1'b0;
//             data_arid <= 4'd0;
//             data_araddr <= 32'd0;
//             data_arsize <= 3'd0;
//             data_arlen <= 8'd0;
//             data_rready <= 1'b0;

//             // Reset AXI signals
//             // arvalid <= 1'b0;
//             // rready <= 1'b0;
//             awvalid <= 1'b0;
//             wvalid <= 1'b0;
//             wlast <= 1'b0;
//             bready <= 1'b0;
//         end
//         else begin
//             // Reset per-cycle signals
//             data_addr_accepted <= 1'b0;
//             data_data_received <= 1'b0;
//             data_write_done <= 1'b0;

//             case (data_state)
//                 IDLE: begin
//                     if (!handling_inst_request) begin
//                         if (data_read_request) begin
//                             data_state <= READ_ADDR;
//                             handling_data_request <= 1'b1;

//                             data_arvalid <= 1'b1;
//                             data_arid <= 4'b0001; // ID for data reads
//                             data_araddr <= data_sram_addr;
//                             data_arsize <= convert_size(data_sram_size);
//                             data_arlen <= 8'b00000000; // Single transfer
//                         end
//                         else if (data_write_request) begin
//                             data_state <= WRITE_ADDR;
//                             handling_data_request <= 1'b1;

//                             awvalid <= 1'b1;
//                             awaddr <= data_sram_addr;
//                             awsize <= convert_size(data_sram_size);
//                             awlen <= 8'b00000000; // Single transfer
//                         end
//                     end
//                 end

//                 READ_ADDR: begin
//                     // arvalid <= 1'b1;
//                     // arid <= 4'b0001; // ID for data reads
//                     // araddr <= data_sram_addr;
//                     // arsize <= convert_size(data_sram_size);
//                     // arlen <= 8'b00000000; // Single transfer


//                     data_arvalid <= 1'b1;
//                     data_arid <= 4'b0001; // ID for data reads
//                     data_araddr <= data_sram_addr;
//                     data_arsize <= convert_size(data_sram_size);
//                     data_arlen <= 8'b00000000; // Single transfer

//                     if (arready) begin
//                         // arvalid <= 1'b0;
//                         data_arvalid <= 1'b0;
//                         data_state <= READ_DATA;
//                         data_addr_accepted <= 1'b1;
//                         // rready <= 1'b1;
//                         data_rready <= 1'b1;
//                     end
//                 end

//                 READ_DATA: begin
//                     if (rvalid && rid[0] == 1'b1) begin  // Check if it's data read (rid[0] = 1)
//                         data_read_data <= rdata;
//                         data_data_received <= 1'b1;
//                         // rready <= 1'b0;
//                         data_rready <= 1'b0;
//                         data_state <= IDLE;
//                         handling_data_request <= 1'b0;
//                     end
//                 end

//                 WRITE_ADDR: begin
//                     awvalid <= 1'b1;
//                     awaddr <= data_sram_addr;
//                     awsize <= convert_size(data_sram_size);
//                     awlen <= 8'b00000000; // Single transfer

//                     if (awready) begin
//                         awvalid <= 1'b0;
//                         data_state <= WRITE_DATA;
//                         data_addr_accepted <= 1'b1;
//                         wvalid <= 1'b1;
//                         wdata <= data_sram_wdata;
//                         wstrb <= data_sram_wstrb;
//                         wlast <= 1'b1; // Single transfer
//                     end
//                 end

//                 WRITE_DATA: begin
//                     if (wready) begin
//                         wvalid <= 1'b0;
//                         wlast <= 1'b0;
//                         data_state <= WRITE_RESP;
//                         bready <= 1'b1;
//                     end
//                 end

//                 WRITE_RESP: begin
//                     if (bvalid) begin
//                         bready <= 1'b0;
//                         data_write_done <= 1'b1;
//                         data_state <= IDLE;
//                         handling_data_request <= 1'b0;
//                     end
//                 end

//                 default:
//                     data_state <= IDLE;
//             endcase
//         end
//     end

//     assign arvalid = inst_arvalid | data_arvalid;
//     assign araddr = handling_inst_request ? inst_araddr : data_araddr;
//     assign arid = handling_inst_request ? inst_arid : data_arid;
//     assign arsize = handling_inst_request ? inst_arsize : data_arsize;
//     assign arlen = handling_inst_request ? inst_arlen : data_arlen;
//     assign rready = inst_rready | data_rready;

// endmodule







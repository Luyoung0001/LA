module axi_ram (
        input          clock,
        input          reset,

        input   reg[ 3:0] arid,
        input   reg[31:0] araddr,
        input   reg[ 7:0] arlen,
        input   reg[ 2:0] arsize,
        input      [ 1:0] arburst,
        input      [ 1:0] arlock,
        input      [ 3:0] arcache,
        input      [ 2:0] arprot,
        input   reg       arvalid,
        output  reg       arready,

        output  reg  [ 3:0] rid,
        output  reg  [31:0] rdata,
        output  reg  [ 1:0] rresp,
        output  reg         rlast,
        output  reg         rvalid,
        input   reg         rready,

        input      [ 3:0] awid,
        input   reg[31:0] awaddr,
        input   reg[ 7:0] awlen,
        input   reg[ 2:0] awsize,
        input      [ 1:0] awburst,
        input      [ 1:0] awlock,
        input      [ 3:0] awcache,
        input      [ 2:0] awprot,
        input   reg       awvalid,
        output  reg       awready,

        input      [ 3:0] wid,
        input   reg[31:0] wdata,
        input   reg[ 3:0] wstrb,
        input   reg       wlast,
        input   reg       wvalid,
        output  reg       wready,

        output  reg [ 3:0] bid,
        output  reg [ 1:0] bresp,
        output  reg        bvalid,
        input   reg        bready
    );

    import "DPI-C" function int data_ram_read(input int addr);
    import "DPI-C" function void data_ram_write(input int addr, input int wdata, input byte we_7);

    // 寄存器信号
    logic [3:0] state;
    logic [3:0] state1;

    // 读通道状态机
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            // 初始化状态和信号
            arready <= 1'b0;
            rvalid  <= 1'b0;
            rdata   <= 32'b0;
            rresp   <= 2'b00;
            rlast   <= 1'b1;
            rid     <= 4'b0;
            state   <= 4'd0;
        end
        else begin
            case (state)
                4'd0: begin // 等待 arvalid
                    arready <= 1'b0;
                    rvalid  <= 1'b0;
                    if (arvalid) begin
                        arready <= 1'b1;  // 地址已接受
                        rid     <= arid;   // 修复：在接受地址时设置 rid
                        state   <= 4'd1;  // 转换到处理数据状态
                    end
                end

                4'd1: begin
                    arready <= 1'b0;
                    rdata   <= data_ram_read(araddr);
                    rvalid  <= 1'b1;
                    rresp   <= 2'b00;
                    rlast   <= 1'b1;

                    if (rready) begin
                        state <= 4'd0;
                    end
                end
                default:begin end

            endcase
        end
    end

    // 写通道状态机
    wire [7:0] wstrb_1;  // 目标是扩展为 8 位
    assign wstrb_1 = {4'b0, wstrb};  // 高 4 位填充 0，低 4 位为 wstrb

    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            // 初始化状态和信号
            awready <= 1'b0;
            wready  <= 1'b0;
            bvalid  <= 1'b0;
            bresp   <= 2'b00;
            bid     <= 4'b0;    // 修复：初始化 bid
            state1  <= 4'd0;
        end
        else begin
            case (state1)
                4'd0: begin // 等待 awvalid
                    awready <= 1'b0;
                    wready  <= 1'b0;
                    bvalid  <= 1'b0;

                    if (awvalid) begin
                        awready <= 1'b1;
                        bid     <= awid;
                        state1  <= 4'd1;
                    end
                end

                4'd1: begin // 等待 wvalid
                    awready <= 1'b0;

                    if (wvalid) begin
                        data_ram_write(awaddr, wdata, wstrb_1);
                        wready <= 1'b1;
                        state1 <= 4'd2;
                    end
                end

                4'd2: begin // 写响应，发射信号并保持直到 bready
                    wready <= 1'b0;
                    bresp  <= 2'b00;      // 响应状态（OKAY）
                    bvalid <= 1'b1;       // 准备写响应

                    if (bready) begin
                        bvalid <= 1'b0;
                        state1 <= 4'd0;
                    end
                end
                default: begin
                end
            endcase
        end
    end

endmodule
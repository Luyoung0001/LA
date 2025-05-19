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
        output              arready,

        output    [ 3:0] rid,
        output    [31:0] rdata,
        output    [ 1:0] rresp,
        output           rlast,
        output           rvalid,
        input   reg    rready,

        input      [ 3:0] awid,
        input   reg[31:0] awaddr,
        input   reg[ 7:0] awlen,
        input   reg[ 2:0] awsize,
        input      [ 1:0] awburst,
        input      [ 1:0] awlock,
        input      [ 3:0] awcache,
        input      [ 2:0] awprot,
        input   reg       awvalid,
        output              awready,

        input      [ 3:0] wid,
        input   reg[31:0] wdata,
        input   reg[ 3:0] wstrb,
        input   reg       wlast,
        input   reg       wvalid,
        output              wready,

        output    [ 3:0] bid,
        output    [ 1:0] bresp,
        output           bvalid,
        input   reg    bready
    );

    import "DPI-C" function int data_ram_read(input int addr);
               import "DPI-C" function void data_ram_write(input int addr, input int wdata, input byte we_7);


                          // 寄存器信号
                          logic [3:0] state;
                          logic [3:0] state1;

                          always_ff @(posedge clock or posedge reset) begin
                                        if (reset) begin
                                            // 初始化状态和信号
                                            rvalid <= 1'b0;
                                            state <= 4'd0;
                                        end
                                        else begin
                                            // 设置默认值
                                            arready <= 1'b0;
                                            rvalid  <= 1'b0;
                                            rdata   <= 32'b0;
                                            rresp   <= 2'b11; // 默认状态：DECERR (解码错误)

                                            // 状态 0：等待 arvalid
                                            if (state == 4'd0 && arvalid) begin
                                                arready <= 1'b1;  // 地址已接受
                                                state <= 4'd1;    // 转换到处理数据状态
                                            end
                                            // 状态 1：访问内存并发射信号并保持，一直到等到 rready
                                            if (state == 4'd1) begin
                                                rdata <= data_ram_read(araddr);  // 读取数据，每次读取都设为 4 个字节
                                                rvalid <= 1'b1;   // 数据有效，rvalid 发射
                                                rresp <= 2'b1;    // 正常响应

                                            end

                                            if (rvalid && rready) begin
                                                state <= 4'd0;    // 结束当前事务，准备下一个事务
                                            end

                                            // $display("arready:= 0x%h", arready);
                                        end
                                    end
                                    wire [7:0] wstrb_1;  // 目标是扩展为 8 位
                          assign wstrb_1 = {4'b0, wstrb};  // 高 4 位填充 0，低 4 位为 wstrb

                          always_ff @(posedge clock or posedge reset) begin
                                        if (reset) begin
                                            // 初始化状态和信号
                                            bvalid <= 1'b0;
                                            state1 <= 4'd0;
                                        end
                                        else begin
                                            // 设置默认值
                                            awready <= 1'b0;
                                            wready  <= 1'b0;
                                            bresp   <= 2'b11; // 默认状态：DECERR (解码错误)
                                            bvalid  <= 1'b0;

                                            // 状态 0：等待 awvalid
                                            if (awvalid && state1 == 4'd0) begin
                                                awready <= 1'b1;  // 地址已接受
                                                state1 <= 4'd1;   // 转换到等待写数据状态
                                            end
                                            // 状态 1：等待 wvalid
                                            if (state1 == 4'd1 && wvalid) begin
                                                data_ram_write(awaddr, wdata, wstrb_1);
                                                wready <= 1'b1;  // 写数据有效
                                                state1 <= 4'd2;  // 转换到写响应状态
                                            end

                                            // 状态 2：写响应，发射信号并保持直到 bready
                                            if (state1 == 4'd2) begin
                                                bresp <= 2'b0;   // 响应状态（OKAY）
                                                bvalid <= 1'b1;  // 准备写响应
                                            end
                                            // 完成写响应
                                            if (bready && bvalid) begin
                                                bvalid <= 1'b0;  // 写响应完成
                                                state1 <= 4'd0;  // 回到等待写地址状态
                                            end
                                        end
                                        // $display("wstrb:= 0x%h", wstrb);
                                    end

                                    assign rlast = 1'b0;
                          assign rid = arid;
                          assign bid = 4'b0;


                      endmodule

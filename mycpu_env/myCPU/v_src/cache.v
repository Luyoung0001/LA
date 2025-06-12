module cache(
        input wire  clk,
        input wire  resetn,
        // 可以考虑将所有非 AXI 接口换成 SRAM_Like 接口
        // to from IFU
        input wire  valid,  // 报表明请求有效
        input wire  op,     // 0: read, 1: write
        input wire  [7:0]  index,
        input wire  [19:0] tag,
        input wire  [3:0]  offset,
        input wire  [3:0]  wstrb,
        input wire  [31:0] wdata,

        output wire addr_ok,
        output wire data_ok,
        output wire [31:0] rdata,

        //to from axi_bridge
        output wire rd_req,
        output wire [2:0]  rd_type,
        output wire [31:0] rd_addr,
        input  wire rd_rdy,

        input  wire ret_valid,
        input  wire ret_last,
        input  wire [31:0] ret_data,

        output wire wr_req,
        output wire [2:0]  wr_type,
        output wire [31:0] wr_addr,
        output wire [3:0] wr_wstrb,
        output wire [31:0] wr_data,
        input  wire wr_rdy
    );
    // IFU 发送请求，这里返回数据或者通过 AXI 和 SRAM 交互完后返回数据
    // 一共设计四种操作：
    // Look Up 如果命中，选取 Data
    // Hit Write 写操作进入 Write Buffer，随后将数据写入命中 Cache 行的对应位置
    // Repalce 未命中读写需要进行 Repalce，为 Refill 提供基础，也就是选一个 Cache Line
    // Refill 将内存返回的数据填入 Replace 空出的位置上


    genvar i,j;
    // 这里的 cache 直接使用 2_way
    // 每一个 way 有 4 个 bank
    wire [ 7:0] way_bank_addra [1:0][3:0];
    wire [31:0] way_bank_dina  [1:0][3:0];
    wire [31:0] way_bank_douta [1:0][3:0];
    wire        way_bank_ena   [1:0][3:0];
    wire [ 3:0] way_bank_wea   [1:0][3:0];

    wire [ 7:0] way_tagv_addra [1:0];
    wire [20:0] way_tagv_dina  [1:0];
    wire [20:0] way_tagv_douta [1:0];
    wire        way_tagv_ena   [1:0];
    wire        way_tagv_wea   [1:0];

    wire [127:0] way_data[1:0]; // 2 路 cache 块，4 个 字
    wire [31:0]  way_load_word [1:0]; // 2 路 load word
    wire [31:0]  load_res;  // load 结果


    wire [1:0] way_d;
    wire [1:0] way_hit;
    wire        cache_hit;

    // Data bank
    generate
        for(i=0;i<2;i=i+1) begin:data_ram_way
            for(j=0;j<4;j=j+1) begin:data_ram_bank
                data_bank_sram u(
                                   .addra      (way_bank_addra[i][j]),
                                   .clka       (clk                 ),
                                   .dina       (way_bank_dina[i][j] ),
                                   .douta      (way_bank_douta[i][j]),
                                   .ena        (way_bank_ena[i][j]  ),
                                   .wea        (way_bank_wea[i][j]  )
                               );
            end
        end
    endgenerate
    // TagV
    generate
        for(i=0;i<2;i=i+1) begin:tagv_ram_way
            //[20:1] tag     [0:0] v
            tagv_sram u(
                          .addra      (way_tagv_addra[i]),
                          .clka       (clk              ),
                          .dina       (way_tagv_dina[i] ),
                          .douta      (way_tagv_douta[i]),
                          .ena        (way_tagv_ena[i]  ),
                          .wea        (way_tagv_wea[i]  )
                      );
        end
    endgenerate

    // D，脏位，直接使用 reg
    reg [1:0] way_d_reg [255:0];


    // 阻塞 cache
    // 核心部分分别是：Request Buffer, Tag Compare, Data Select, Miss Buffer 以及 Write Buffer

    // Request Buffer
    reg         request_buffer_op;
    reg [ 7:0]  request_buffer_index;
    reg [19:0]  request_buffer_tag;
    reg [ 3:0]  request_buffer_offset;
    reg [ 3:0]  request_buffer_wstrb;
    reg [31:0]  request_buffer_wdata;

    // Miss Buffer
    reg  [1:0]  miss_buffer_replace_way;  // 准备替换的 way 信息
    reg  [1:0]  miss_buffer_ret_num;      // 已经从 AXI 返回了几个字

    // Write Buffer
    reg [ 7:0]  write_buffer_index;
    reg [ 3:0]  write_buffer_wstrb;
    reg [31:0]  write_buffer_wdata;
    reg [ 1:0]  write_buffer_way;
    reg [ 3:0]  write_buffer_offset;

    always @(posedge clk or negedge resetn) begin
        if (!resetn) begin
            request_buffer_op      <= 1'b0;
            request_buffer_index   <= 8'h00;
            request_buffer_tag     <= 20'h00000;
            request_buffer_offset  <= 4'h0;
            request_buffer_wstrb   <= 4'h0;
            request_buffer_wdata   <= 32'h00000000;
        end
        else if (valid) begin
            request_buffer_op      <= op;
            request_buffer_index   <= index;
            request_buffer_tag     <= tag;
            request_buffer_offset  <= offset;
            request_buffer_wstrb   <= wstrb;
            request_buffer_wdata   <= wdata;
        end
    end

    // Tag Compare
    generate
        for(i=0;i<2;i=i+1) begin:gen_way_hit
            assign way_hit[i] = way_tagv_douta[i][0] && (tag == way_tagv_douta[i][20:1]);
        end
    endgenerate

    assign cache_hit = |way_hit;

    // Data Select
    generate
        for(i=0;i<2;i=i+1) begin:gen_way_data
            assign way_data[i] = {way_bank_douta[i][3],way_bank_douta[i][2],way_bank_douta[i][1],way_bank_douta[i][0]};

            assign way_load_word[i] = way_data[i][request_buffer_offset[3:2]*32 +: 32];
        end
    endgenerate
    assign load_res = {32{way_hit[0]}} & way_load_word[0] |
           {32{way_hit[1]}} & way_load_word[1] ;


    // Miss Buffer
    // 在 cache 未命中后，需要从 AXI 返回信息且替换到某 cache line

    // Write Buffer
    // 在 Hit Write（Store 操作在 Look Up 时发现命中 Cache）时启动的，它会寄存 Store 要写入的 way、bank 等等






    




















endmodule



// =====================================================tools========================================================
// =====================================================tools========================================================
module data_bank_sram
    #(
         parameter WIDTH = 32    ,
         parameter DEPTH = 256
     )
     (
         input  [ 7:0]          addra   ,
         input                  clka    ,
         input  [31:0]          dina    ,
         output [31:0]          douta   ,
         input                  ena     ,
         input  [ 3:0]          wea
     );

    reg [31:0] mem_reg [255:0];
    reg [31:0] output_buffer;

    always @(posedge clka) begin
        if (ena) begin
            if (wea != 4'd0) begin
                if (wea[0]) begin
                    mem_reg[addra][ 7: 0] <= dina[ 7: 0];
                end

                if (wea[1]) begin
                    mem_reg[addra][15: 8] <= dina[15: 8];
                end

                if (wea[2]) begin
                    mem_reg[addra][23:16] <= dina[23:16];
                end

                if (wea[3]) begin
                    mem_reg[addra][31:24] <= dina[31:24];
                end
            end
            else begin
                output_buffer <= mem_reg[addra];
            end
        end
    end

    assign douta = output_buffer;

endmodule

module tagv_sram
    #(
         parameter WIDTH = 21    ,
         parameter DEPTH = 256
     )
     (
         input  [ 7:0]          addra   ,
         input                  clka    ,
         input  [20:0]          dina    ,
         output [20:0]          douta   ,
         input                  ena     ,
         input                  wea
     );

    reg [20:0] mem_reg [255:0];
    reg [20:0] output_buffer;

    always @(posedge clka) begin
        if (ena) begin
            if (wea) begin
                mem_reg[addra] <= dina;
            end
            else begin
                output_buffer <= mem_reg[addra];
            end
        end
    end

    assign douta = output_buffer;

endmodule

// 随机数
module lfsr (
        input           clk         ,
        input           reset       ,
        output [1:0]    random_val
    );

    reg [7:0] r_lfsr;
    always @(posedge clk) begin
        if (reset) begin
            r_lfsr <= 8'b1;
        end
        else begin
            r_lfsr[0] <= r_lfsr[7];
            r_lfsr[1] <= r_lfsr[0];
            r_lfsr[2] <= r_lfsr[1];
            r_lfsr[3] <= r_lfsr[2];
            r_lfsr[4] <= r_lfsr[3] ^ r_lfsr[7];
            r_lfsr[5] <= r_lfsr[4] ^ r_lfsr[7];
            r_lfsr[6] <= r_lfsr[5] ^ r_lfsr[7];
            r_lfsr[7] <= r_lfsr[6];
        end
    end

    assign random_val = r_lfsr[7:6];

endmodule


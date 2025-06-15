module cache(
        input wire  clk,
        input wire  resetn,
        // to from CPU
        input wire  valid,  // 报表明请求有效
        input wire  op,     // 0: read, 1: write
        input wire  [7:0]  index,
        input wire  [19:0] tag,
        input wire  [3:0]  offset,
        input wire  [3:0]  wstrb,
        input wire  [31:0] wdata,

        // 所有的 cacop 暂不考虑

        output wire addr_ok,
        output wire data_ok,
        output wire [31:0] rdata,

        //to from axi_bridge
        output wire rd_req,
        output wire [2:0]  rd_type, // 为了支持 uncache 访问
        output wire [31:0] rd_addr,
        input  wire rd_rdy,

        input  wire ret_valid,
        input  wire ret_last,
        input  wire [31:0] ret_data, // axi 返回的数据，这个数据 refill 到 2 路 4 组 表中

        output reg          wr_req,
        output wire [2:0]   wr_type,
        output wire [31:0]  wr_addr,
        output wire [3:0]   wr_wstrb,
        output wire [127:0] wr_data, // 可以直接发射一个 cache line 到 axi 的 buffer
        input  wire         wr_rdy
    );
    // IFU 发送请求，这里返回数据或者通过 AXI 和 SRAM 交互完后返回数据
    // 一共设计四种操作：
    // Look Up 如果命中，选取 Data
    // Hit Write 写操作进入 Write Buffer，随后将数据写入命中 Cache 行的对应位置
    // Repalce 未命中读写需要进行 Repalce，为 Refill 提供基础，也就是选一个 Cache Line
    // Refill 将内存返回的数据填入 Replace 空出的位置上


    // 状态机
    localparam main_idle    = 5'b00001;
    localparam main_lookup  = 5'b00010;
    localparam main_miss    = 5'b00100;
    localparam main_replace = 5'b01000;
    localparam main_refill  = 5'b10000;

    localparam write_buffer_idle  = 1'b0;
    localparam write_buffer_write = 1'b1;

    wire main_state_is_idle    = main_state == main_idle   ;
    wire main_state_is_lookup  = main_state == main_lookup ;
    wire main_state_is_miss    = main_state == main_miss   ;
    wire main_state_is_replace = main_state == main_replace;
    wire main_state_is_refill  = main_state == main_refill ;

    wire write_state_is_full   = write_buffer_state == write_buffer_write;
    wire write_state_is_idle  = write_buffer_state == write_buffer_idle;

    reg [4:0] main_state;
    reg write_buffer_state;

    genvar i,j;

    // 这里的 cache 为 2_way
    // 每一个 way 有 4 个 bank
    //   线宽                   way  back
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

    wire        wr_match_way_bank[1:0][3:0];

    wire [127:0] way_data[1:0]; // 2 路 cache 块，4 个 字
    wire [31:0]  way_load_word [1:0]; // 2 路 load word
    wire [31:0]  load_res;  // load 结果


    wire [1:0] way_d;
    wire [1:0] way_hit;
    wire       cache_hit;

    wire [19:0]  replace_tag;
    wire [127:0] replace_data;
    wire [1:0]   replace_way;
    wire         replace_d;
    wire         replace_v;
    wire [1:0]   way_wr_en;
    wire [31:0]  write_in;
    wire [31:0]  refill_data;
    // Data bank
    // 实例化 2 路 8 个 data_back
    generate
        for(i=0;i<2;i=i+1) begin:data_ram_way
            for(j=0;j<4;j=j+1) begin:data_ram_bank
                data_bank_sram u(
                                   .addra      (way_bank_addra[i][j]),
                                   .clka       (clk                 ),
                                   .reset      (!resetn),
                                   .dina       (way_bank_dina[i][j] ),
                                   .douta      (way_bank_douta[i][j]),
                                   .ena        (way_bank_ena[i][j]  ),
                                   .wea        (way_bank_wea[i][j]  )
                               );
            end
        end
    endgenerate
    // TagV
    // 实例化 2 路 tagv
    generate
        for(i=0;i<2;i=i+1) begin:tagv_ram_way
            tagv_sram u(
                          .addra      (way_tagv_addra[i]),
                          .clka       (clk              ),
                          .reset      (!resetn),
                          .dina       (way_tagv_dina[i] ),
                          .douta      (way_tagv_douta[i]),
                          .ena        (way_tagv_ena[i]  ),
                          .wea        (way_tagv_wea[i]  )
                      );
        end
    endgenerate

    reg rd_req_buffer;

    always @(posedge clk) begin
        if (!resetn) begin
            rd_req_buffer <= 1'b0;
        end
        else if (rd_req) begin
            rd_req_buffer <= 1'b1;
        end
        else if (main_state_is_refill && (ret_valid && ret_last)) begin
            rd_req_buffer <= 1'b0;
        end
    end

    // D，脏位，直接使用 reg
    //  way             index
    reg [1:0] way_d_reg [255:0];

    always @(posedge clk) begin
        // 更新脏位
        // 如果 现在是 refill 状态 且
        // 读完所有数据

        // 更新脏位有两种情况
        // 1. 被替换
        // 2. Write hit 了
        if (main_state_is_refill &&
                ((ret_valid && ret_last) || !rd_req_buffer) ) begin
            way_d_reg[request_buffer_index][0] <= miss_buffer_replace_way[0] ? request_buffer_op : way_d_reg[request_buffer_index][0];
            way_d_reg[request_buffer_index][1] <= miss_buffer_replace_way[1] ? request_buffer_op : way_d_reg[request_buffer_index][1];
        end
        else if (write_state_is_full) begin
            way_d_reg[write_buffer_index] <= way_d_reg[write_buffer_index] | write_buffer_way;
        end
    end

    // 伪随机数发生器
    wire [1:0] random_val;
    lfsr lfsr(
             .clk        (clk),
             .reset      (!resetn),
             .random_val (random_val)
         );


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

    // Tag Compare
    generate
        for(i=0;i<2;i=i+1) begin:gen_way_hit
            assign way_hit[i]
                   = way_tagv_douta[i][0] && (tag == way_tagv_douta[i][20:1]);
        end
    endgenerate

    assign cache_hit = |way_hit;

    // Data Select
    generate
        for(i=0;i<2;i=i+1) begin:gen_way_data
            assign way_data[i] = {way_bank_douta[i][3],
                                  way_bank_douta[i][2],
                                  way_bank_douta[i][1],
                                  way_bank_douta[i][0]};
            assign way_load_word[i] = way_data[i][request_buffer_offset[3:2]*32 +: 32];
        end
    endgenerate

    assign load_res = {32{way_hit[0]}} & way_load_word[0] |
           {32{way_hit[1]}} & way_load_word[1];

    // 根据随机数替换被替换的 way 的信息
    assign replace_data = {128{miss_buffer_replace_way[0]}} & way_data[0] |
           {128{miss_buffer_replace_way[1]}} & way_data[1];

    assign replace_d    = |(replace_way & way_d);
    assign replace_v    = |(replace_way & {way_tagv_douta[1][0],way_tagv_douta[0][0]});


    generate
        for(i=0;i<2;i=i+1) begin: gen_data_way
            for(j=0;j<4;j=j+1) begin: gen_data_bank

                assign wr_match_way_bank[i][j] = write_state_is_full &&
                       (write_buffer_way[i] && (write_buffer_offset[3:2] == j[1:0]));

                assign way_bank_addra[i][j] = wr_match_way_bank[i][j] ? write_buffer_index : ({8{addr_ok}}  & index |
                        {8{!addr_ok}} & request_buffer_index);
                assign way_bank_wea[i][j] = {4{wr_match_way_bank[i][j]}} & write_buffer_wstrb |
                       {4{main_state_is_refill && (way_wr_en[i] && (miss_buffer_ret_num == j[1:0]))}} & 4'hf;
                assign way_bank_dina[i][j] = {32{write_state_is_full}}  & write_buffer_wdata |
                       {32{main_state_is_refill}} & refill_data;
                assign way_bank_ena[i][j] =  main_state_is_idle || main_state_is_lookup;
            end
        end
    endgenerate


    generate
        for(i=0;i<2;i=i+1) begin: gen_tagv_way
            assign way_tagv_addra[i] = {8{addr_ok }} & index   |
                   {8{!addr_ok}} & request_buffer_index ;
            assign way_tagv_ena[i] = main_state_is_idle || main_state_is_lookup;
            assign way_tagv_wea[i] = miss_buffer_replace_way[i] && main_state_is_refill &&
                   ((ret_valid && ret_last)); //write at least 4B
            assign way_tagv_dina[i] =  {request_buffer_tag, 1'b1};
        end
    endgenerate


    // Miss Buffer
    // 在 cache 未命中后，需要从 AXI 返回信息且替换到某 cache line
    // 利用随机数发生器产生 way 选择器
    assign replace_tag  = {20{miss_buffer_replace_way[0]}} & way_tagv_douta[0][20:1] |
           {20{miss_buffer_replace_way[1]}} & way_tagv_douta[1][20:1];

    wire [3:0] chosen_way;
    decoder_2_4 dec_rand_way (.in({1'b0,random_val[0]}),.out(chosen_way));

    wire [1:0] invalid_way;

    wire has_invalid_way;

    one_valid_n #(2) sel_one_invalid (.in(~{way_tagv_douta[1][0],way_tagv_douta[0][0]}),.out(invalid_way),.nozero(has_invalid_way));

    wire[1:0] rand_repl_way = has_invalid_way ? invalid_way : chosen_way[1:0]; //chose invalid way first.

    assign replace_way = rand_repl_way;

    assign way_d = way_d_reg[request_buffer_index] |
           {2{(write_buffer_index == request_buffer_index) && write_state_is_full}} & write_buffer_way;

    assign way_wr_en = miss_buffer_replace_way & {2{ret_valid}};

    assign write_in = {(request_buffer_wstrb[3] ? request_buffer_wdata[31:24] : ret_data[31:24]),
                       (request_buffer_wstrb[2] ? request_buffer_wdata[23:16] : ret_data[23:16]),
                       (request_buffer_wstrb[1] ? request_buffer_wdata[15: 8] : ret_data[15: 8]),
                       (request_buffer_wstrb[0] ? request_buffer_wdata[ 7: 0] : ret_data[ 7: 0])};

    assign refill_data = (request_buffer_op && (request_buffer_offset[3:2] == miss_buffer_ret_num)) ? write_in : ret_data;


    // 输出
    assign addr_ok = (main_state_is_idle && main_idle2lookup) || (main_state_is_lookup && main_lookup2lookup);
    assign data_ok = (main_state_is_lookup && (cache_hit || request_buffer_op)) || // 直接命中
           (main_state_is_refill && (!request_buffer_op && (ret_valid && (miss_buffer_ret_num == request_buffer_offset[3:2])))); // 或者没有命中但是已经返回，这里可以提前返回

    assign rdata = {32{main_state_is_lookup}} & load_res |
           {32{main_state_is_refill}} & ret_data ;

    assign rd_req = main_state_is_replace;
    assign rd_type = 3'b100; // 16B
    assign rd_addr = {request_buffer_tag, request_buffer_index, 4'b0}; // 16B 对齐


    assign wr_type  = 3'b100;     //replace cache line
    assign wr_addr  = {replace_tag, request_buffer_index, 4'b0};
    assign wr_wstrb = 4'hf;
    assign wr_data  = replace_data;



    wire req_or_inst_valid;
    wire req_after_wr_conflict; // 写后请求 冲突
    wire rd_after_reqing_conflict; // 正在处理请求时读 冲突
    wire main_idle2lookup;
    wire main_lookup2lookup;

    assign req_after_wr_conflict    = write_state_is_full && (write_buffer_offset[3:2] == offset[3:2]);
    assign rd_after_reqing_conflict = request_buffer_op && !op && ((request_buffer_offset[3:2] == offset[3:2]));

    assign req_or_inst_valid = valid;
    assign main_idle2lookup = !req_after_wr_conflict;
    assign main_lookup2lookup = (!req_after_wr_conflict) && (!rd_after_reqing_conflict) && cache_hit;

    wire [1:0] ret_num_add_one;

    always @(posedge clk) begin
        if(!resetn) begin
            main_state <= main_idle;
            request_buffer_op <= 1'b0;
            request_buffer_index      <=  8'b0;
            request_buffer_tag        <= 20'b0;
            request_buffer_offset     <=  4'b0;
            request_buffer_wstrb      <=  4'b0;
            request_buffer_wdata      <= 32'b0;

            miss_buffer_replace_way <= 2'b0;
        end
        else
        case (main_state)
            main_idle: begin
                if (req_or_inst_valid && main_idle2lookup) begin
                    // 请求有效 且 无写后请求 冲突，就进入查询
                    main_state <= main_lookup;

                    request_buffer_op         <= op   ;

                    request_buffer_index      <= index ;
                    request_buffer_offset     <= offset;
                    request_buffer_wstrb      <= wstrb;
                    request_buffer_wdata      <= wdata;
                end
            end
            main_lookup: begin
                if(req_or_inst_valid && main_lookup2lookup) begin
                    // 如果请求有效 && 无 写后请求 冲突 && 无 正在处理请求时读 冲突 && 命中，就继续处理请求
                    main_state <= main_lookup;

                    request_buffer_op         <= op   ;
                    request_buffer_index      <= index ;
                    request_buffer_offset     <= offset;
                    request_buffer_wstrb      <= wstrb;
                    request_buffer_wdata      <= wdata;
                end
                else if(!cache_hit) begin
                    // 如果没有命中，应该进行替换，但是替换前要判断 replace_d、replace_v 的状态
                    if (replace_d && replace_v) begin
                        // 如果被替换的 way 脏位有效且有效位有效，就进入 main_miss 状态
                        main_state <= main_miss;
                    end
                    else begin
                        // 否则 直接替换就行
                        main_state <= main_replace;
                    end

                    request_buffer_tag        <= tag;
                    miss_buffer_replace_way   <= replace_way;
                end
                else begin
                    main_state <= main_idle;
                end
            end
            main_miss: begin
                if (wr_rdy) begin
                    // 如果写准备好
                    main_state <= main_replace;
                    // 发起写请求，此时
                    wr_req <= 1'b1;
                end
            end

            main_replace: begin
                // 回填 cache line 之前需要从 axi 获取 4 个字
                if(rd_rdy) begin
                    // 如果 axi 缓存准备好了数据，就可以进入 main_refill
                    main_state <= main_refill;
                    miss_buffer_ret_num <= 2'b0; // 开始计数
                end
                // 取消 写请求，wr_data 为 128 位一次就可以写完带 axi 的 buffer
                wr_req <= 1'b0;
            end

            main_refill: begin
                if ((ret_valid && ret_last) || !rd_req_buffer) begin
                    // 如果传送完成，直接 idle
                    main_state <= main_idle;
                end
                else begin
                    if (ret_valid)begin
                        miss_buffer_ret_num <= miss_buffer_ret_num + 2'b1;
                    end
                end
            end
            default: begin
                main_state <= main_idle;
            end
        endcase

    end

    // assign ret_num_add_one[0] = miss_buffer_ret_num[0] ^ 1'b1;
    // assign ret_num_add_one[1] = miss_buffer_ret_num[1] ^ miss_buffer_ret_num[0];

    // Write Buffer
    // 在 Hit Write（Store 操作在 Look Up 时发现命中 Cache）时启动的，它会寄存 Store 要写入的 way、bank 等等
    // 这是写命中，只需要就写请求放到缓存中就可以了
    always @(posedge clk) begin
        if (!resetn) begin
            write_buffer_state  <= write_buffer_idle;

            write_buffer_index  <= 8'b0;
            write_buffer_wstrb  <= 4'b0;
            write_buffer_wdata  <= 32'b0;
            write_buffer_offset <= 4'b0;
            write_buffer_way    <= 2'b0;
        end
        else
        case (write_buffer_state)
            write_buffer_idle: begin
                if (main_state_is_lookup && cache_hit && request_buffer_op) begin
                    write_buffer_state  <= write_buffer_write;

                    write_buffer_index  <= request_buffer_index;
                    write_buffer_wstrb  <= request_buffer_wstrb;
                    write_buffer_wdata  <= request_buffer_wdata;
                    write_buffer_offset <= request_buffer_offset;
                    write_buffer_way    <= way_hit;
                end
            end
            write_buffer_write: begin
                if (main_state_is_lookup && cache_hit && request_buffer_op) begin
                    write_buffer_state  <= write_buffer_write;

                    write_buffer_index  <= request_buffer_index;
                    write_buffer_wstrb  <= request_buffer_wstrb;
                    write_buffer_wdata  <= request_buffer_wdata;
                    write_buffer_offset <= request_buffer_offset;
                    write_buffer_way    <= way_hit;
                end
                else begin
                    write_buffer_state <= write_buffer_idle;
                end
            end
        endcase
    end

endmodule

// =====================================================tools========================================================
// =====================================================tools========================================================

module decoder_2_4(
        input  [ 1:0] in,
        output [ 3:0] out
    );

    genvar i;
generate for (i=0; i<4; i=i+1) begin : gen_for_dec_2_4
            assign out[i] = (in == i);
        end
    endgenerate

endmodule


module one_valid_n #(
        parameter n = 16
    )(
        input  [n-1:0] in,
        output [n-1:0] out,
        output         nozero
    );

    wire [n-1:0] one_in;

    assign one_in[0] = in[0];

    genvar i;
    generate
        for (i=1; i<n; i=i+1) begin: sel_one
            assign one_in[i] = in[i] && ~|in[i-1:0];
        end
    endgenerate

    assign out = one_in;
    assign nozero = |out;

endmodule

module data_bank_sram
    #(
         parameter WIDTH = 32    ,
         parameter DEPTH = 256
     )
     (
         input  [ 7:0]          addra   ,
         input                  clka    ,
         input                  reset       ,
         input  [31:0]          dina    ,
         output [31:0]          douta   ,
         input                  ena     ,
         input  [ 3:0]          wea
     );
    reg [31:0] mem_reg [255:0];
    reg [31:0] output_buffer;
    integer k;

    always @(posedge clka)begin
        if (reset) begin
            // 使用for循环复位所有元素
            for (k = 0; k < 256; k = k + 1) begin
                mem_reg[k] = 32'd0;  // 每个32位寄存器清零
            end
        end
        if (ena)begin
            if (wea != 4'd0)begin
                if (wea[0])begin
                    mem_reg[addra][ 7: 0] <= dina[ 7: 0];
                end

                if (wea[1])begin
                    mem_reg[addra][15: 8] <= dina[15: 8];
                end

                if (wea[2])begin
                    mem_reg[addra][23:16] <= dina[23:16];
                end

                if (wea[3])begin
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
         input           reset       ,
         input  [20:0]          dina    ,
         output [20:0]          douta   ,
         input                  ena     ,
         input                  wea
     );

    reg [20:0] mem_reg [255:0];
    reg [20:0] output_buffer;

    integer k;
    always @(posedge clka)begin
        if (reset) begin
            // 使用for循环复位所有元素
            for (k = 0; k < 256; k = k + 1) begin
                mem_reg[k] = 21'd0;  // 每个32位寄存器清零
            end
        end
        if (ena) begin
            if (wea)begin
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
    always @(posedge clk)begin
        if (reset)begin
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

    assign random_val = r_lfsr[7:
                               6];

endmodule


`include "csr.h"
module csr(
        input                           clk          ,
        input                           reset        ,
        //from ds for read
        input  [13:0]                   rd_addr      ,
        output [31:0]                   rd_data      ,
        //timer 64
        // output [63:0]                   timer_64_out ,
        // output [31:0]                   tid_out      ,
        // write signal
        input                           csr_wr_en    ,
        input  [13:0]                   wr_addr      ,
        input  [31:0]                   wr_data,
        input  [31:0]                   era_in       ,
        input                           ertn_flush   ,
        input                           excp_flush   ,

        input  [ 5:0]                   ecode_in     ,
        input                           va_error_in  ,
        input  [31:0]                   bad_va_in    ,
        input  [ 8:0]                   esubcode_in  ,
        input                           excp_tlbrefill,
        input                           excp_tlb     ,
        input  [18:0]                   excp_tlb_vppn,


        // to ifu
        output wire [31:0] era_out,
        output wire [31:0] eentry_out



    );

    localparam CRMD  = 14'h0;
    localparam PRMD  = 14'h1;
    localparam ESTAT = 14'h5;
    localparam ERA   = 14'h6;
    localparam EENTRY = 14'hc;
    localparam SAVE0 = 14'h30;
    localparam SAVE1 = 14'h31;
    localparam SAVE2 = 14'h32;
    localparam SAVE3 = 14'h33;

    wire crmd_wen   = csr_wr_en & (wr_addr == CRMD);
    wire prmd_wen   = csr_wr_en & (wr_addr == PRMD);
    wire estat_wen  = csr_wr_en & (wr_addr == ESTAT);
    wire era_wen    = csr_wr_en & (wr_addr == ERA);
    wire eentry_wen = csr_wr_en & (wr_addr == EENTRY);

    wire save0_wen  = csr_wr_en & (wr_addr == SAVE0);
    wire save1_wen  = csr_wr_en & (wr_addr == SAVE1);
    wire save2_wen  = csr_wr_en & (wr_addr == SAVE2);
    wire save3_wen  = csr_wr_en & (wr_addr == SAVE3);

    reg [31:0] csr_crmd;
    reg [31:0] csr_prmd;
    reg [31:0] csr_estat;
    reg [31:0] csr_era;
    reg [31:0] csr_eentry;

    reg [31:0] csr_save0;
    reg [31:0] csr_save1;
    reg [31:0] csr_save2;
    reg [31:0] csr_save3;

    // csr 读取发生在 idu 中
    assign rd_data = {32{rd_addr == CRMD  }}  & csr_crmd    |
           {32{rd_addr == PRMD  }}  & csr_prmd    |
           {32{rd_addr == ESTAT }}  & csr_estat   |
           {32{rd_addr == ERA   }}  & csr_era	    |
           {32{rd_addr == EENTRY}}  & csr_eentry  |
           {32{rd_addr == SAVE0 }}  & csr_save0   |
           {32{rd_addr == SAVE1 }}  & csr_save1   |
           {32{rd_addr == SAVE2 }}  & csr_save2   |
           {32{rd_addr == SAVE3 }}  & csr_save3;

    assign era_out = csr_era;
    assign eentry_out   = csr_eentry;



    // csr 的修改和 wbu 一样，发生在 wbu 中
    // reg        timer_en;
    // reg [63:0] timer_64;


    //crmd
    always @(posedge clk) begin
        if (reset) begin
            // 《龙芯架构 32 位精简版参考手册》page 55
            csr_crmd[ `PLV] <=  2'b0;
            csr_crmd[  `IE] <=  1'b0; // 复位后需要屏蔽中断
            csr_crmd[  `DA] <=  1'b1; // 复位后开启地址直接翻译
            csr_crmd[  `PG] <=  1'b0; // 复位后关闭映射地址翻译
            csr_crmd[`DATF] <=  2'b0;
            csr_crmd[`DATM] <=  2'b0;
            csr_crmd[31: 9] <= 23'b0;
        end
        else if (excp_flush) begin
            csr_crmd[ `PLV] <=  2'b0; // 例外发生时，将权限打到最高，关闭中断
            csr_crmd[  `IE] <=  1'b0;
        end
        else if (ertn_flush) begin
            csr_crmd[ `PLV] <= csr_prmd[`PPLV]; // 恢复特权等级
            csr_crmd[  `IE] <= csr_prmd[`PIE ]; // 恢复中断
        end
        else if (crmd_wen) begin
            csr_crmd[ `PLV] <= wr_data[ `PLV];
            csr_crmd[  `IE] <= wr_data[	 `IE];
            csr_crmd[  `DA] <= wr_data[	 `DA];
            csr_crmd[  `PG] <= wr_data[  `PG];
            csr_crmd[`DATF] <= wr_data[`DATF];
            csr_crmd[`DATM] <= wr_data[`DATM];
        end
    end


    //prmd
    always @(posedge clk) begin
        if (reset) begin
            csr_prmd[31:3] <= 29'b0;
        end
        else if (excp_flush) begin
            csr_prmd[`PPLV] <= csr_crmd[`PLV];
            csr_prmd[ `PIE] <= csr_crmd[`IE ];
        end
        else if (prmd_wen) begin
            csr_prmd[`PPLV] <= wr_data[`PPLV];
            csr_prmd[ `PIE] <= wr_data[ `PIE];
        end
    end

    //estat
    always @(posedge clk) begin
        if (reset) begin
            csr_estat[1:0] <= 2'b0;     // 软中断状态位
            csr_estat[10]    <= 1'b0;   // 保留域
            csr_estat[12]    <= 1'b0;   // 核间中断，暂不考虑
            csr_estat[15:13] <= 3'b0;   // 保留域
            csr_estat[31]    <= 1'b0;   // 保留域
        end
        else begin
            if (excp_flush) begin
                csr_estat[   `ECODE] <= ecode_in;
                csr_estat[`ESUBCODE] <= esubcode_in;
            end
            else if (estat_wen) begin
                csr_estat[1:0] <= wr_data[1:0]; // 仅仅被 csr 更新
            end
        end
    end

    //era
    always @(posedge clk) begin
        if (excp_flush) begin
            csr_era <= era_in; // 发生例外时写
        end
        else if (era_wen) begin
            csr_era <= wr_data;  // 也可以直接操作
        end
    end

    //eentry
    always @(posedge clk) begin
        if (reset) begin
            csr_eentry[5:0] <= 6'b0;
        end
        else if (eentry_wen) begin
            csr_eentry[31:6] <= wr_data[31:6];
        end
    end

    //save0
    always @(posedge clk) begin
        if (save0_wen) begin
            csr_save0 <= wr_data;
        end
    end

    //save1
    always @(posedge clk) begin
        if (save1_wen) begin
            csr_save1 <= wr_data;
        end
    end

    //save2
    always @(posedge clk) begin
        if (save2_wen) begin
            csr_save2 <= wr_data;
        end
    end

    //save3
    always @(posedge clk) begin
        if (save3_wen) begin
            csr_save3 <= wr_data;
        end
    end


    // 一些硬件

    // timer_64
    // always @(posedge clk) begin
    //     if (reset) begin
    //         timer_64 <= 64'b0;
    //     end
    //     else begin
    //         timer_64 <= timer_64 + 1'b1;
    //     end
    // end

endmodule

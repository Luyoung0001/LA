module sram_wrap(
        input  wire        clk,
        input  wire        resetn,

        input  wire        req    ,
        input  wire        wr     ,
        input  wire [1 :0] size   ,
        input  wire [3 :0] wstrb  ,
        input  wire [31:0] addr   ,
        input  wire [31:0] wdata  ,
        output wire        addr_ok,
        output wire        data_ok,
        output wire [31:0] rdata  ,

        //slave
        output wire        ram_en   ,
        output wire [3 :0] ram_we   ,
        output wire [31:0] ram_addr ,
        output wire [31:0] ram_wdata,
        input  wire [31:0] ram_rdata
    );
    wire addr_and;
    wire data_and;

    assign addr_and = 1'b1;
    assign data_and = 1'b1;


    //to ram
    wire [3:0] size_decode = size==2'd0 ? {addr[1:0]==2'd3,addr[1:0]==2'd2,addr[1:0]==2'd1,addr[1:0]==2'd0} :
         size==2'd1 ? {addr[1],addr[1],~addr[1],~addr[1]} :
         4'hf;
    assign ram_en    = req && addr_ok;
    assign ram_we    = {4{wr}} & wstrb & size_decode;
    assign ram_addr  = addr;
    assign ram_wdata = wdata;

    reg ram_en_r;
    always @(posedge clk)begin
        ram_en_r <= ram_en;
    end

    //buf of rdata from ram
    reg [2 :0] buf_wptr;
    reg [2 :0] buf_rptr;
    reg [31:0] buf_rdata [3:0];

    wire  buf_empty   = buf_wptr==buf_rptr;
    wire  buf_full    = buf_wptr=={~buf_rptr[2],buf_rptr[1:0]};
    //return data_ok in next clock.
    wire  fast_return = ram_en_r && data_ok && buf_empty;

    always @(posedge clk)begin
        if(!resetn)begin
            buf_wptr <= 3'd0;
        end
        else if(ram_en_r && !fast_return)begin
            buf_wptr <= buf_wptr + 1'b1;
        end

        if(ram_en_r && !fast_return)begin
            buf_rdata[buf_wptr[1:0]] <= ram_rdata;
        end

        if(!resetn)begin
            buf_rptr <= 3'd0;
        end
        else if(!buf_empty && data_ok)begin
            buf_rptr <= buf_rptr + 1'b1;
        end
    end
    //addr_ok
    assign addr_ok = 1'b1 && addr_and && !buf_full;
    //data_ok
    assign data_ok = 1'b1 && data_and &&(!buf_empty||ram_en_r);
    //rdata
    assign rdata   = buf_empty ? ram_rdata : buf_rdata[buf_rptr[1:0]];
endmodule

module tlb
    #(
         parameter TLBNUM = 64
     )
     (
         input        clk,
         // search port 0
         input   [18:0]               s0_vppn     ,
         input                        s0_va_bit12 , // for odd page
         input   [ 9:0]               s0_asid     ,
         output                       s0_found    ,
         output  [ 5:0]               s0_index    ,
         output  [19:0]               s0_ppn      ,
         output  [ 5:0]               s0_ps       ,
         output  [ 1:0]               s0_plv      ,
         output  [ 1:0]               s0_mat      ,
         output                       s0_d        ,
         output                       s0_v        ,

         //search port 1
         input   [18:0]               s1_vppn     ,
         input                        s1_va_bit12 , // for odd page
         input   [ 9:0]               s1_asid     ,
         output                       s1_found    ,
         output  [ 5:0]               s1_index    ,
         output  [19:0]               s1_ppn      ,
         output  [ 5:0]               s1_ps       ,
         output  [ 1:0]               s1_plv      ,
         output  [ 1:0]               s1_mat      ,
         output                       s1_d        ,
         output                       s1_v        ,

         // invalid port
         input                        invtlb_valid,
         input   [4:0]                invtlb_op,
         input   [9:0]                invtlb_asid,
         input   [18:0]               invtlb_vpn,
         // write port
         input                       we          ,
         input  [$clog2(TLBNUM)-1:0] w_index     ,
         input                       w_e         ,
         input  [18:0]               w_vppn      ,
         input  [ 5:0]               w_ps        ,
         input  [ 9:0]               w_asid      ,
         input                       w_g         ,
         input  [19:0]               w_ppn0      ,
         input  [ 1:0]               w_plv0      ,
         input  [ 1:0]               w_mat0      ,
         input                       w_d0        ,
         input                       w_v0        ,
         input  [19:0]               w_ppn1      ,
         input  [ 1:0]               w_plv1      ,
         input  [ 1:0]               w_mat1      ,
         input                       w_d1        ,
         input                       w_v1        ,

         // read port
         input  [$clog2(TLBNUM)-1:0] r_index     ,
         output                      r_e         ,
         output [18:0]               r_vppn      ,
         output [ 5:0]               r_ps        ,
         output [ 9:0]               r_asid      ,
         output                      r_g         ,
         output [19:0]               r_ppn0      ,
         output [ 1:0]               r_plv0      ,
         output [ 1:0]               r_mat0      ,
         output                      r_d0        ,
         output                      r_v0        ,
         output [19:0]               r_ppn1      ,
         output [ 1:0]               r_plv1      ,
         output [ 1:0]               r_mat1      ,
         output                      r_d1        ,
         output                      r_v1
     );

    reg [18:0] tlb_vppn     [TLBNUM-1:0];
    reg        tlb_e        [TLBNUM-1:0];
    reg [ 9:0] tlb_asid     [TLBNUM-1:0];
    reg        tlb_g        [TLBNUM-1:0];
    reg [ 5:0] tlb_ps       [TLBNUM-1:0];
    reg [19:0] tlb_ppn0     [TLBNUM-1:0];
    reg [ 1:0] tlb_plv0     [TLBNUM-1:0];
    reg [ 1:0] tlb_mat0     [TLBNUM-1:0];
    reg        tlb_d0       [TLBNUM-1:0];
    reg        tlb_v0       [TLBNUM-1:0];
    reg [19:0] tlb_ppn1     [TLBNUM-1:0];
    reg [ 1:0] tlb_plv1     [TLBNUM-1:0];
    reg [ 1:0] tlb_mat1     [TLBNUM-1:0];
    reg        tlb_d1       [TLBNUM-1:0];
    reg        tlb_v1       [TLBNUM-1:0];


    wire [TLBNUM-1:0] match0;
    wire [TLBNUM-1:0] match1;

    wire [$clog2(TLBNUM)-1:0] match0_en;
    wire [$clog2(TLBNUM)-1:0] match1_en;

    wire [TLBNUM-1:0] s0_odd_page_buffer;
    wire [TLBNUM-1:0] s1_odd_page_buffer;

    genvar i;
    generate
        for (i = 0; i < TLBNUM; i = i + 1) begin: match
            assign match0[i] = tlb_e[i] && ((tlb_ps[i] == 6'd12) ? s0_vppn == tlb_vppn[i] : s0_vppn[18: 9] == tlb_vppn[i][18: 9]) && ((s0_asid == tlb_asid[i]) || tlb_g[i]);
            assign match1[i] = tlb_e[i] && ((tlb_ps[i] == 6'd12) ? s1_vppn == tlb_vppn[i] : s1_vppn[18: 9] == tlb_vppn[i][18: 9]) && ((s1_asid == tlb_asid[i]) || tlb_g[i]);

            // 如果是小页 4KB，就看 va_bit12，如果是1，那就是奇数页
            // 如果是大页 2MB，就看 va_bit21，如果是1，那就是奇数页
            // 而 vppn 是 vaddr[31:13]，那么 va_bit21 其实就是 vppn[8]
            // 但是，Linux 内核中 4MB 页大小对应的是透明大页的页表项，
            // 其在填入 TLB 过程中等分为 2 个 2MB 大小相同页表属性的表项，因此 TLB 的大页其实对应的是 2MB
            assign s0_odd_page_buffer[i] = (tlb_ps[i] == 6'd12) ? s0_va_bit12 : s0_vppn[8];
            assign s1_odd_page_buffer[i] = (tlb_ps[i] == 6'd12) ? s1_va_bit12 : s1_vppn[8];
        end
    endgenerate

    encoder_64_6 en_match0 (.in({{(64-TLBNUM){1'b0}},match0}), .out(match0_en));
    encoder_64_6 en_match1 (.in({{(64-TLBNUM){1'b0}},match1}), .out(match1_en));


    assign s0_found = |match0;
    assign s0_index = {{(6-$clog2(TLBNUM)){1'b0}},match0_en};
    assign s0_ps    = tlb_ps[match0_en];
    assign s0_ppn   = s0_odd_page_buffer[match0_en] ? tlb_ppn1[match0_en] : tlb_ppn0[match0_en];
    assign s0_v     = s0_odd_page_buffer[match0_en] ? tlb_v1[match0_en]   : tlb_v0[match0_en]  ;
    assign s0_d     = s0_odd_page_buffer[match0_en] ? tlb_d1[match0_en]   : tlb_d0[match0_en]  ;
    assign s0_mat   = s0_odd_page_buffer[match0_en] ? tlb_mat1[match0_en] : tlb_mat0[match0_en];
    assign s0_plv   = s0_odd_page_buffer[match0_en] ? tlb_plv1[match0_en] : tlb_plv0[match0_en];

    assign s1_found = |match1;
    assign s1_index = {{(6-$clog2(TLBNUM)){1'b0}},match1_en};
    assign s1_ps    = tlb_ps[match1_en];
    assign s1_ppn   = s1_odd_page_buffer[match1_en] ? tlb_ppn1[match1_en] : tlb_ppn0[match1_en];
    assign s1_v     = s1_odd_page_buffer[match1_en] ? tlb_v1[match1_en]   : tlb_v0[match1_en]  ;
    assign s1_d     = s1_odd_page_buffer[match1_en] ? tlb_d1[match1_en]   : tlb_d0[match1_en]  ;
    assign s1_mat   = s1_odd_page_buffer[match1_en] ? tlb_mat1[match1_en] : tlb_mat0[match1_en];
    assign s1_plv   = s1_odd_page_buffer[match1_en] ? tlb_plv1[match1_en] : tlb_plv0[match1_en];

    always @(posedge clk) begin
        if (we) begin
            tlb_vppn [w_index] <= w_vppn;
            tlb_asid [w_index] <= w_asid;
            tlb_g    [w_index] <= w_g;
            tlb_ps   [w_index] <= w_ps;
            tlb_ppn0 [w_index] <= w_ppn0;
            tlb_plv0 [w_index] <= w_plv0;
            tlb_mat0 [w_index] <= w_mat0;
            tlb_d0   [w_index] <= w_d0;
            tlb_v0   [w_index] <= w_v0;
            tlb_ppn1 [w_index] <= w_ppn1;
            tlb_plv1 [w_index] <= w_plv1;
            tlb_mat1 [w_index] <= w_mat1;
            tlb_d1   [w_index] <= w_d1;
            tlb_v1   [w_index] <= w_v1;
        end
    end

    assign r_vppn  =  tlb_vppn [r_index];
    assign r_asid  =  tlb_asid [r_index];
    assign r_g     =  tlb_g    [r_index];
    assign r_ps    =  tlb_ps   [r_index];
    assign r_e     =  tlb_e    [r_index];
    assign r_v0    =  tlb_v0   [r_index];
    assign r_d0    =  tlb_d0   [r_index];
    assign r_mat0  =  tlb_mat0 [r_index];
    assign r_plv0  =  tlb_plv0 [r_index];
    assign r_ppn0  =  tlb_ppn0 [r_index];
    assign r_v1    =  tlb_v1   [r_index];
    assign r_d1    =  tlb_d1   [r_index];
    assign r_mat1  =  tlb_mat1 [r_index];
    assign r_plv1  =  tlb_plv1 [r_index];
    assign r_ppn1  =  tlb_ppn1 [r_index];

    //tlb entry invalid
    generate
        for (i = 0; i < TLBNUM; i = i + 1) begin: invalid_tlb_entry
            always @(posedge clk) begin
                if (we && (w_index == i)) begin
                    tlb_e[i] <= w_e;
                end
                else if (invtlb_valid) begin
                    if (invtlb_op == 5'd0 || invtlb_op == 5'd1) begin
                        tlb_e[i] <= 1'b0;
                    end
                    else if (invtlb_op == 5'd2) begin
                        if (tlb_g[i]) begin
                            tlb_e[i] <= 1'b0;
                        end
                    end
                    else if (invtlb_op == 5'd3) begin
                        if (!tlb_g[i]) begin
                            tlb_e[i] <= 1'b0;
                        end
                    end
                    else if (invtlb_op == 5'd4) begin
                        if (!tlb_g[i] && (tlb_asid[i] == invtlb_asid)) begin
                            tlb_e[i] <= 1'b0;
                        end
                    end
                    else if (invtlb_op == 5'd5) begin
                        if (!tlb_g[i] && (tlb_asid[i] == invtlb_asid) &&
                                ((tlb_ps[i] == 6'd12) ? (tlb_vppn[i] == invtlb_vpn) : (tlb_vppn[i][18:9] == invtlb_vpn[18:9]))) begin
                            tlb_e[i] <= 1'b0;
                        end
                    end
                    else if (invtlb_op == 5'd6) begin
                        if ((tlb_g[i] || (tlb_asid[i] == invtlb_asid)) &&
                                ((tlb_ps[i] == 6'd12) ? (tlb_vppn[i] == invtlb_vpn) : (tlb_vppn[i][18:9] == invtlb_vpn[18:9]))) begin
                            tlb_e[i] <= 1'b0;
                        end
                    end
                end
            end
        end
    endgenerate

endmodule

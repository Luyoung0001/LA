`include "csr.h"

module addr_trans
    #(
         parameter TLBNUM = 16
     )
     (
         input                  clk                  ,
         //inst addr trans
         input                  inst_addr_trans_en   ,
         input  [ 9:0]          inst_asid            ,
         input  [31:0]          inst_vaddr           ,
         input                  inst_dmw0_en         ,
         input                  inst_dmw1_en         ,

         input  [31:0]          inst_dmw0             ,
         input  [31:0]          inst_dmw1             ,
         input                  inst_da               ,
         input                  inst_pg,

         output [ 7:0]          inst_index           ,
         output [19:0]          inst_tag             ,
         output [ 3:0]          inst_offset          ,
         output                 inst_tlb_found       ,
         output                 inst_tlb_v           ,
         output                 inst_tlb_d           ,
         output [ 1:0]          inst_tlb_mat         ,
         output [ 1:0]          inst_tlb_plv         ,
         //data addr trans
         input                  data_addr_trans_en   ,
         input  [ 9:0]          data_asid            ,
         input  [31:0]          data_vaddr           ,
         input                  data_dmw0_en         ,
         input                  data_dmw1_en         ,

         input  [31:0]          data_dmw0             ,
         input  [31:0]          data_dmw1             ,
         input                  data_da               ,
         input                  data_pg,

         output [ 7:0]          data_index           ,
         output [19:0]          data_tag             ,
         output [ 3:0]          data_offset          ,
         output                 data_tlb_found       ,
         output [ $clog2(TLBNUM)-1:0]          data_tlb_index       , // for tlbsrch
         output                 data_tlb_v           ,
         output                 data_tlb_d           ,
         output [ 1:0]          data_tlb_mat         ,
         output [ 1:0]          data_tlb_plv         ,
         // tlbwr tlbfill
         input                  tlbfill_en           ,
         input                  tlbwr_en             ,
         input [9:0]            w_asid               ,
         input  [ $clog2(TLBNUM)-1:0]          rand_index           , // tlbfill
         input  [31:0]          tlbehi_in            ,
         input  [31:0]          tlbelo0_in           ,
         input  [31:0]          tlbelo1_in           ,
         input  [31:0]          tlbidx_in            , // tlbrd tlbwr
         input  [ 5:0]          ecode_in             ,
         // for tlbrd
         output [31:0]          tlbehi_out           ,
         output [31:0]          tlbelo0_out          ,
         output [31:0]          tlbelo1_out          ,
         output [31:0]          tlbidx_out           ,
         output [ 9:0]          asid_out             ,
         //invtlb
         input                  invtlb_valid         ,
         input  [ 4:0]          invtlb_op            ,
         input  [ 9:0]          invtlb_asid          ,
         input  [18:0]          invtlb_vpn

     );

    wire [18:0] s0_vppn     ;
    wire        s0_odd_page ;
    wire [ 5:0] s0_ps       ;
    wire [19:0] s0_ppn      ;
    wire s0_va_bit12        ;

    wire [18:0] s1_vppn     ;
    wire        s1_odd_page ;
    wire [ 5:0] s1_ps       ;
    wire [19:0] s1_ppn      ;
    wire s1_va_bit12        ;

    wire        we          ;
    wire [ $clog2(TLBNUM)-1 :0] w_index     ;
    wire [18:0] w_vppn      ;
    wire        w_g         ;
    wire [ 5:0] w_ps        ;
    wire        w_e         ;
    wire        w_v0        ;
    wire        w_d0        ;
    wire [ 1:0] w_mat0      ;
    wire [ 1:0] w_plv0      ;
    wire [19:0] w_ppn0      ;
    wire        w_v1        ;
    wire        w_d1        ;
    wire [ 1:0] w_mat1      ;
    wire [ 1:0] w_plv1      ;
    wire [19:0] w_ppn1      ;

    wire [ $clog2(TLBNUM)-1:0] r_index     ;
    wire [18:0] r_vppn      ;
    wire [ 9:0] r_asid      ;
    wire        r_g         ;
    wire [ 5:0] r_ps        ;
    wire        r_e         ;
    wire        r_v0        ;
    wire        r_d0        ;
    wire [ 1:0] r_mat0      ;
    wire [ 1:0] r_plv0      ;
    wire [19:0] r_ppn0      ;
    wire        r_v1        ;
    wire        r_d1        ;
    wire [ 1:0] r_mat1      ;
    wire [ 1:0] r_plv1      ;
    wire [19:0] r_ppn1      ;

    wire [31:0] inst_paddr;
    wire [31:0] data_paddr;

    wire        inst_pg_mode;
    wire        inst_da_mode;
    wire        data_pg_mode;
    wire        data_da_mode;

    // 搜索
    assign s0_vppn     = inst_vaddr[31:13];
    assign s0_va_bit12 = inst_vaddr[12];
    assign s1_vppn     = data_vaddr[31:13];
    assign s1_va_bit12 = data_vaddr[12];

    // 写
    assign we      = tlbfill_en || tlbwr_en;
    assign w_index = ({$clog2(TLBNUM){tlbfill_en}} & rand_index) | ({$clog2(TLBNUM){tlbwr_en}} & tlbidx_in[`INDEX]);
    assign w_vppn  = tlbehi_in[`VPPN];
    assign w_g     = tlbelo0_in[`TLB_G] && tlbelo1_in[`TLB_G];
    assign w_ps    = tlbidx_in[`PS];
    assign w_e     = (ecode_in == 6'h3f) ? 1'b1 : !tlbidx_in[`NE];

    assign w_v0    = tlbelo0_in[`TLB_V];
    assign w_d0    = tlbelo0_in[`TLB_D];
    assign w_plv0  = tlbelo0_in[`TLB_PLV];
    assign w_mat0  = tlbelo0_in[`TLB_MAT];
    assign w_ppn0  = tlbelo0_in[`TLB_PPN_EN];

    assign w_v1    = tlbelo1_in[`TLB_V];
    assign w_d1    = tlbelo1_in[`TLB_D];
    assign w_plv1  = tlbelo1_in[`TLB_PLV];
    assign w_mat1  = tlbelo1_in[`TLB_MAT];
    assign w_ppn1  = tlbelo1_in[`TLB_PPN_EN];

    // 读
    assign r_index      = tlbidx_in[`INDEX];
    assign tlbehi_out   = {r_vppn, 13'b0};
    assign tlbelo0_out  = {4'b0, r_ppn0, 1'b0, r_g, r_mat0, r_plv0, r_d0, r_v0};
    assign tlbelo1_out  = {4'b0, r_ppn1, 1'b0, r_g, r_mat1, r_plv1, r_d1, r_v1};
    assign tlbidx_out   = {!r_e, 1'b0, r_ps, 24'b0}; //note do not write index
    assign asid_out     = r_asid;

    tlb  blt_o(
             .clk            (clk            ),
             // search port 0
             .s0_vppn        (s0_vppn        ),
             .s0_va_bit12    (s0_va_bit12    ),
             .s0_asid        (inst_asid      ),
             .s0_found       (inst_tlb_found ),
             .s0_index       (),
             .s0_ppn         (s0_ppn         ),
             .s0_ps          (s0_ps          ),
             .s0_plv         (inst_tlb_plv   ),
             .s0_mat         (inst_tlb_mat   ),
             .s0_d           (inst_tlb_d     ),
             .s0_v           (inst_tlb_v     ),

             // search port 1
             .s1_vppn        (s1_vppn        ),
             .s1_va_bit12    (s1_va_bit12    ),
             .s1_asid        (data_asid      ),
             .s1_found       (data_tlb_found ),
             .s1_index       (data_tlb_index ),
             .s1_ppn         (s1_ppn         ),
             .s1_ps          (s1_ps          ),
             .s1_plv         (data_tlb_plv   ),
             .s1_mat         (data_tlb_mat   ),
             .s1_d           (data_tlb_d     ),
             .s1_v           (data_tlb_v     ),

             //invalid port
             .invtlb_valid    (invtlb_valid   ),
             .invtlb_op       (invtlb_op      ),
             .invtlb_asid     (invtlb_asid    ),
             .invtlb_vpn      (invtlb_vpn     ),

             // write port
             .we             (we             ),
             .w_index        (w_index        ),
             .w_vppn         (w_vppn         ),
             .w_asid         (w_asid         ),
             .w_g            (w_g            ),
             .w_ps           (w_ps           ),
             .w_e            (w_e            ),
             .w_v0           (w_v0           ),
             .w_d0           (w_d0           ),
             .w_plv0         (w_plv0         ),
             .w_mat0         (w_mat0         ),
             .w_ppn0         (w_ppn0         ),
             .w_v1           (w_v1           ),
             .w_d1           (w_d1           ),
             .w_plv1         (w_plv1         ),
             .w_mat1         (w_mat1         ),
             .w_ppn1         (w_ppn1         ),

             //read port
             .r_index        (r_index        ),
             .r_vppn         (r_vppn         ),
             .r_asid         (r_asid         ),
             .r_g            (r_g            ),
             .r_ps           (r_ps           ),
             .r_e            (r_e            ),
             .r_v0           (r_v0           ),
             .r_d0           (r_d0           ),
             .r_mat0         (r_mat0         ),
             .r_plv0         (r_plv0         ),
             .r_ppn0         (r_ppn0         ),
             .r_v1           (r_v1           ),
             .r_d1           (r_d1           ),
             .r_mat1         (r_mat1         ),
             .r_plv1         (r_plv1         ),
             .r_ppn1         (r_ppn1         )

         );

    assign inst_pg_mode = !inst_da && inst_pg; // 映射地址翻译模式
    assign inst_da_mode = inst_da && !inst_pg; // 直接地址翻译模式

    assign data_pg_mode = !data_da && data_pg;
    assign data_da_mode = data_da && !data_pg;
    // 在映射地址翻译模式下, 地址翻译时将优先看其能否按照直接映射
    // 模式进行地址翻译, 无法进行后再通过页表映射模式进行翻译。
    assign inst_paddr = (inst_pg_mode && inst_dmw0_en) ? {inst_dmw0[`PSEG], inst_vaddr[28:0]} :
           (inst_pg_mode && inst_dmw1_en) ? {inst_dmw1[`PSEG], inst_vaddr[28:0]} : inst_vaddr;

    assign inst_offset = inst_vaddr[3:0];
    assign inst_index  = inst_vaddr[11:4];
    assign inst_tag    = inst_addr_trans_en ? ((s0_ps == 6'd12) ? s0_ppn : {s0_ppn[19:10], inst_paddr[21:12]}) : inst_paddr[31:12];

    assign data_paddr = (data_pg_mode && data_dmw0_en ) ? {data_dmw0[`PSEG], data_vaddr[28:0]} :
           (data_pg_mode && data_dmw1_en ) ? {data_dmw1[`PSEG], data_vaddr[28:0]} : data_vaddr;

    assign data_offset = data_vaddr[3:0];
    assign data_index  = data_vaddr[11:4];
    assign data_tag    = data_addr_trans_en ? ((s1_ps == 6'd12) ? s1_ppn : {s1_ppn[19:10], data_paddr[21:12]}) : data_paddr[31:12];

endmodule

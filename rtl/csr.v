module csr_stub (
    input  wire        clk,
    input  wire        reset,

    input  wire [13:0] read_addr,
    output reg  [31:0] read_data,

    input  wire        write_valid,
    input  wire [13:0] write_addr,
    input  wire [31:0] write_data,
    input  wire        timer_tick,
    input  wire        tlb_commit_valid,
    input  wire [31:0] tlb_commit_inst,
    input  wire [31:0] tlb_commit_op1,
    input  wire [31:0] tlb_commit_op2,
    input  wire        i_tlb_query_valid,
    input  wire        i_tlb_query_write,
    input  wire [31:0] i_tlb_query_vaddr,
    output wire [31:0] i_tlb_query_paddr,
    output wire        i_tlb_exception_valid,
    output wire [5:0]  i_tlb_exception_ecode,
    input  wire        d_tlb_query_valid,
    input  wire        d_tlb_query_write,
    input  wire [31:0] d_tlb_query_vaddr,
    output wire [31:0] d_tlb_query_paddr,
    output wire        d_tlb_exception_valid,
    output wire [5:0]  d_tlb_exception_ecode,

    input  wire        exception_valid,
    input  wire [31:0] exception_pc,
    input  wire [5:0]  exception_ecode,
    input  wire [8:0]  exception_esubcode,
    input  wire        exception_badv_valid,
    input  wire [31:0] exception_badv,
    input  wire        ertn_valid,
    input  wire [7:0]  interrupt,

    output wire [31:0] exception_entry,
    output wire [31:0] ertn_pc,
    output wire [10:0] interrupt_pending,
    output wire        has_int,
    output wire [63:0] timer_64_out
);

    localparam CSR_CRMD       = 14'h000;
    localparam CSR_PRMD       = 14'h001;
    localparam CSR_ECFG       = 14'h004;
    localparam CSR_ESTAT      = 14'h005;
    localparam CSR_ERA        = 14'h006;
    localparam CSR_BADV       = 14'h007;
    localparam CSR_EENTRY     = 14'h00c;
    localparam CSR_TLBIDX     = 14'h010;
    localparam CSR_TLBEHI     = 14'h011;
    localparam CSR_TLBELO0    = 14'h012;
    localparam CSR_TLBELO1    = 14'h013;
    localparam CSR_ASID       = 14'h018;
    localparam CSR_PGDL       = 14'h019;
    localparam CSR_PGDH       = 14'h01a;
    localparam CSR_PGD        = 14'h01b;
    localparam CSR_CPUID      = 14'h020;
    localparam CSR_SAVE0      = 14'h030;
    localparam CSR_SAVE1      = 14'h031;
    localparam CSR_SAVE2      = 14'h032;
    localparam CSR_SAVE3      = 14'h033;
    localparam CSR_TID        = 14'h040;
    localparam CSR_TCFG       = 14'h041;
    localparam CSR_TVAL       = 14'h042;
    localparam CSR_CNTC       = 14'h043;
    localparam CSR_TICLR      = 14'h044;
    localparam CSR_LLBCTL     = 14'h060;
    localparam CSR_TLBRENTRY  = 14'h088;
    localparam CSR_DISABLE_CACHE = 14'h101;
    localparam CSR_DMW0       = 14'h180;
    localparam CSR_DMW1       = 14'h181;

    localparam CPUCFG_1       = 14'h0b1;
    localparam CPUCFG_2       = 14'h0b2;
    localparam CPUCFG_10      = 14'h0c0;
    localparam CPUCFG_11      = 14'h0c1;
    localparam CPUCFG_12      = 14'h0c2;
    localparam CPUCFG_13      = 14'h0c3;

    reg [31:0] csr_crmd;
    reg [31:0] csr_prmd;
    reg [31:0] csr_ecfg;
    reg [31:0] csr_estat;
    reg [31:0] csr_era;
    reg [31:0] csr_badv;
    reg [31:0] csr_eentry;
    reg [31:0] csr_tlbidx;
    reg [31:0] csr_tlbehi;
    reg [31:0] csr_tlbelo0;
    reg [31:0] csr_tlbelo1;
    reg [31:0] csr_asid;
    reg [31:0] csr_pgdl;
    reg [31:0] csr_pgdh;
    reg [31:0] csr_cpuid;
    reg [31:0] csr_save0;
    reg [31:0] csr_save1;
    reg [31:0] csr_save2;
    reg [31:0] csr_save3;
    reg [31:0] csr_tid;
    reg [31:0] csr_tcfg;
    reg [31:0] csr_tval;
    reg [31:0] csr_cntc;
    reg [31:0] csr_ticlr;
    reg [31:0] csr_llbctl;
    reg [31:0] csr_tlbrentry;
    reg [31:0] csr_disable_cache;
    reg [31:0] csr_dmw0;
    reg [31:0] csr_dmw1;

    reg        timer_en;
    reg [63:0] timer_64;

    reg [18:0] tlb_vppn [0:31];
    reg [9:0]  tlb_asid [0:31];
    reg        tlb_g    [0:31];
    reg [5:0]  tlb_ps   [0:31];
    reg        tlb_e    [0:31];
    reg [19:0] tlb_ppn0 [0:31];
    reg [1:0]  tlb_plv0 [0:31];
    reg [1:0]  tlb_mat0 [0:31];
    reg        tlb_d0   [0:31];
    reg        tlb_v0   [0:31];
    reg [19:0] tlb_ppn1 [0:31];
    reg [1:0]  tlb_plv1 [0:31];
    reg [1:0]  tlb_mat1 [0:31];
    reg        tlb_d1   [0:31];
    reg        tlb_v1   [0:31];

    integer reset_i;
    integer search_i;
    integer inv_i;
    integer d_search_i;
    reg        tlbsrch_found_r;
    reg [4:0]  tlbsrch_index_r;
    reg        d_tlb_found_r;
    reg [4:0]  d_tlb_index_r;

    wire [31:0] csr_pgd;
    wire [5:0]  commit_op_31_26;
    wire [3:0]  commit_op_25_22;
    wire [1:0]  commit_op_21_20;
    wire [4:0]  commit_op_19_15;
    wire [4:0]  commit_rj;
    wire [4:0]  commit_rk;
    wire [4:0]  commit_rd;
    wire        commit_tlbsrch;
    wire        commit_tlbrd;
    wire        commit_tlbwr;
    wire        commit_tlbfill;
    wire        commit_invtlb;
    wire [4:0]  tlb_write_index;
    wire        tlb_write_enable_value;
    wire [31:0] tlbelo0_packed;
    wire [31:0] tlbelo1_packed;
    wire        d_pg_mode;
    wire        d_dmw0_hit;
    wire        d_dmw1_hit;
    wire        d_tlb_translate;
    wire        d_tlb_odd_page;
    wire [19:0] d_tlb_ppn;
    wire        d_tlb_v;
    wire        d_tlb_d;
    wire [1:0]  d_tlb_plv;
    wire [5:0]  d_tlb_ps;
    wire [31:0] d_tlb_trans_paddr;
    wire [31:0] d_dmw_paddr;
    wire        i_pg_mode;
    wire        i_dmw0_hit;
    wire        i_dmw1_hit;
    wire        i_tlb_translate;
    integer     i_search_i;
    reg         i_tlb_found_r;
    reg [4:0]   i_tlb_index_r;
    wire        i_tlb_odd_page;
    wire [19:0] i_tlb_ppn;
    wire        i_tlb_v;
    wire        i_tlb_d;
    wire [1:0]  i_tlb_plv;
    wire [5:0]  i_tlb_ps;
    wire [31:0]  i_tlb_trans_paddr;
    wire [31:0]  i_dmw_paddr;

    assign csr_pgd = csr_badv[31] ? csr_pgdh : csr_pgdl;
    assign exception_entry = (exception_valid && (exception_ecode == 6'h3f)) ? csr_tlbrentry : csr_eentry;
    assign ertn_pc = csr_era;
    assign interrupt_pending = csr_estat[12:2];
    assign has_int = (|(csr_ecfg[12:0] & csr_estat[12:0])) && csr_crmd[2];
    assign timer_64_out = timer_64 + {{32{csr_cntc[31]}}, csr_cntc};

    assign commit_op_31_26 = tlb_commit_inst[31:26];
    assign commit_op_25_22 = tlb_commit_inst[25:22];
    assign commit_op_21_20 = tlb_commit_inst[21:20];
    assign commit_op_19_15 = tlb_commit_inst[19:15];
    assign commit_rj       = tlb_commit_inst[9:5];
    assign commit_rk       = tlb_commit_inst[14:10];
    assign commit_rd       = tlb_commit_inst[4:0];
    assign commit_tlbsrch  = tlb_commit_valid && (commit_op_31_26 == 6'h01) &&
                             (commit_op_25_22 == 4'h9) && (commit_op_21_20 == 2'h0) &&
                             (commit_op_19_15 == 5'h10) && (commit_rk == 5'h0a) &&
                             (commit_rj == 5'h00) && (commit_rd == 5'h00);
    assign commit_tlbrd    = tlb_commit_valid && (commit_op_31_26 == 6'h01) &&
                             (commit_op_25_22 == 4'h9) && (commit_op_21_20 == 2'h0) &&
                             (commit_op_19_15 == 5'h10) && (commit_rk == 5'h0b) &&
                             (commit_rj == 5'h00) && (commit_rd == 5'h00);
    assign commit_tlbwr    = tlb_commit_valid && (commit_op_31_26 == 6'h01) &&
                             (commit_op_25_22 == 4'h9) && (commit_op_21_20 == 2'h0) &&
                             (commit_op_19_15 == 5'h10) && (commit_rk == 5'h0c) &&
                             (commit_rj == 5'h00) && (commit_rd == 5'h00);
    assign commit_tlbfill  = tlb_commit_valid && (commit_op_31_26 == 6'h01) &&
                             (commit_op_25_22 == 4'h9) && (commit_op_21_20 == 2'h0) &&
                             (commit_op_19_15 == 5'h10) && (commit_rk == 5'h0d) &&
                             (commit_rj == 5'h00) && (commit_rd == 5'h00);
    assign commit_invtlb   = tlb_commit_valid && (commit_op_31_26 == 6'h01) &&
                             (commit_op_25_22 == 4'h9) && (commit_op_21_20 == 2'h0) &&
                             (commit_op_19_15 == 5'h13) && (commit_rd <= 5'd6);
    assign tlb_write_index = commit_tlbfill ? 5'b0 : csr_tlbidx[4:0];
    assign tlb_write_enable_value = (csr_estat[21:16] == 6'h3f) ? 1'b1 : ~csr_tlbidx[31];
    assign tlbelo0_packed = {4'b0, tlb_ppn0[csr_tlbidx[4:0]], 1'b0, tlb_g[csr_tlbidx[4:0]],
                             tlb_mat0[csr_tlbidx[4:0]], tlb_plv0[csr_tlbidx[4:0]],
                             tlb_d0[csr_tlbidx[4:0]], tlb_v0[csr_tlbidx[4:0]]};
    assign tlbelo1_packed = {4'b0, tlb_ppn1[csr_tlbidx[4:0]], 1'b0, tlb_g[csr_tlbidx[4:0]],
                             tlb_mat1[csr_tlbidx[4:0]], tlb_plv1[csr_tlbidx[4:0]],
                             tlb_d1[csr_tlbidx[4:0]], tlb_v1[csr_tlbidx[4:0]]};
    assign d_pg_mode = !csr_crmd[3] && csr_crmd[4];
    assign d_dmw0_hit = d_pg_mode &&
                        (((csr_dmw0[0] && (csr_crmd[1:0] == 2'd0)) ||
                          (csr_dmw0[3] && (csr_crmd[1:0] == 2'd3))) &&
                         (d_tlb_query_vaddr[31:29] == csr_dmw0[31:29]));
    assign d_dmw1_hit = d_pg_mode &&
                        (((csr_dmw1[0] && (csr_crmd[1:0] == 2'd0)) ||
                          (csr_dmw1[3] && (csr_crmd[1:0] == 2'd3))) &&
                         (d_tlb_query_vaddr[31:29] == csr_dmw1[31:29]));
    assign d_tlb_translate = d_tlb_query_valid && d_pg_mode && !d_dmw0_hit && !d_dmw1_hit;
    assign d_tlb_ps = tlb_ps[d_tlb_index_r];
    assign d_tlb_odd_page = (d_tlb_ps == 6'd12) ? d_tlb_query_vaddr[12] : d_tlb_query_vaddr[21];
    assign d_tlb_ppn = d_tlb_odd_page ? tlb_ppn1[d_tlb_index_r] : tlb_ppn0[d_tlb_index_r];
    assign d_tlb_v   = d_tlb_odd_page ? tlb_v1[d_tlb_index_r]   : tlb_v0[d_tlb_index_r];
    assign d_tlb_d   = d_tlb_odd_page ? tlb_d1[d_tlb_index_r]   : tlb_d0[d_tlb_index_r];
    assign d_tlb_plv = d_tlb_odd_page ? tlb_plv1[d_tlb_index_r] : tlb_plv0[d_tlb_index_r];
    assign d_tlb_trans_paddr = (d_tlb_ps == 6'd12) ?
                               {d_tlb_ppn, d_tlb_query_vaddr[11:0]} :
                               {d_tlb_ppn[19:10], d_tlb_query_vaddr[21:0]};
    assign d_dmw_paddr = d_dmw0_hit ? {csr_dmw0[27:25], d_tlb_query_vaddr[28:0]} :
                         d_dmw1_hit ? {csr_dmw1[27:25], d_tlb_query_vaddr[28:0]} :
                                      d_tlb_query_vaddr;
    assign d_tlb_query_paddr = d_tlb_translate ? d_tlb_trans_paddr : d_dmw_paddr;
    assign d_tlb_exception_valid = d_tlb_translate &&
                                   (!d_tlb_found_r ||
                                    !d_tlb_v ||
                                    (csr_crmd[1:0] > d_tlb_plv) ||
                                    (d_tlb_query_write && !d_tlb_d));
    assign d_tlb_exception_ecode = !d_tlb_found_r ? 6'h3f :
                                   !d_tlb_v ? (d_tlb_query_write ? 6'h02 : 6'h01) :
                                   (csr_crmd[1:0] > d_tlb_plv) ? 6'h07 :
                                   6'h04;

    assign i_pg_mode = d_pg_mode;
    assign i_dmw0_hit = i_pg_mode &&
                        (((csr_dmw0[0] && (csr_crmd[1:0] == 2'd0)) ||
                          (csr_dmw0[3] && (csr_crmd[1:0] == 2'd3))) &&
                         (i_tlb_query_vaddr[31:29] == csr_dmw0[31:29]));
    assign i_dmw1_hit = i_pg_mode &&
                        (((csr_dmw1[0] && (csr_crmd[1:0] == 2'd0)) ||
                          (csr_dmw1[3] && (csr_crmd[1:0] == 2'd3))) &&
                         (i_tlb_query_vaddr[31:29] == csr_dmw1[31:29]));
    assign i_tlb_translate = i_tlb_query_valid && i_pg_mode && !i_dmw0_hit && !i_dmw1_hit;
    assign i_tlb_ps = tlb_ps[i_tlb_index_r];
    assign i_tlb_odd_page = (i_tlb_ps == 6'd12) ? i_tlb_query_vaddr[12] : i_tlb_query_vaddr[21];
    assign i_tlb_ppn = i_tlb_odd_page ? tlb_ppn1[i_tlb_index_r] : tlb_ppn0[i_tlb_index_r];
    assign i_tlb_v   = i_tlb_odd_page ? tlb_v1[i_tlb_index_r]   : tlb_v0[i_tlb_index_r];
    assign i_tlb_d   = i_tlb_odd_page ? tlb_d1[i_tlb_index_r]   : tlb_d0[i_tlb_index_r];
    assign i_tlb_plv = i_tlb_odd_page ? tlb_plv1[i_tlb_index_r] : tlb_plv0[i_tlb_index_r];
    assign i_tlb_trans_paddr = (i_tlb_ps == 6'd12) ?
                               {i_tlb_ppn, i_tlb_query_vaddr[11:0]} :
                               {i_tlb_ppn[19:10], i_tlb_query_vaddr[21:0]};
    assign i_dmw_paddr = i_dmw0_hit ? {csr_dmw0[27:25], i_tlb_query_vaddr[28:0]} :
                         i_dmw1_hit ? {csr_dmw1[27:25], i_tlb_query_vaddr[28:0]} :
                                      i_tlb_query_vaddr;
    assign i_tlb_query_paddr = i_tlb_translate ? i_tlb_trans_paddr : i_dmw_paddr;
    assign i_tlb_exception_valid = i_tlb_translate &&
                                   (!i_tlb_found_r ||
                                    !i_tlb_v ||
                                    (csr_crmd[1:0] > i_tlb_plv));
    assign i_tlb_exception_ecode = !i_tlb_found_r ? 6'h3f :
                                   !i_tlb_v ? 6'h03 :
                                   6'h07;

    always @(*) begin
        d_tlb_found_r = 1'b0;
        d_tlb_index_r = 5'b0;
        for (d_search_i = 0; d_search_i < 32; d_search_i = d_search_i + 1) begin
            if (!d_tlb_found_r && tlb_e[d_search_i] &&
                ((tlb_ps[d_search_i] == 6'd12) ?
                 (tlb_vppn[d_search_i] == d_tlb_query_vaddr[31:13]) :
                 (tlb_vppn[d_search_i][18:9] == d_tlb_query_vaddr[31:22])) &&
                ((tlb_asid[d_search_i] == csr_asid[9:0]) || tlb_g[d_search_i])) begin
                d_tlb_found_r = 1'b1;
                d_tlb_index_r = d_search_i[4:0];
            end
        end
    end

    always @(*) begin
        i_tlb_found_r = 1'b0;
        i_tlb_index_r = 5'b0;
        for (i_search_i = 0; i_search_i < 32; i_search_i = i_search_i + 1) begin
            if (!i_tlb_found_r && tlb_e[i_search_i] &&
                ((tlb_ps[i_search_i] == 6'd12) ?
                 (tlb_vppn[i_search_i] == i_tlb_query_vaddr[31:13]) :
                 (tlb_vppn[i_search_i][18:9] == i_tlb_query_vaddr[31:22])) &&
                ((tlb_asid[i_search_i] == csr_asid[9:0]) || tlb_g[i_search_i])) begin
                i_tlb_found_r = 1'b1;
                i_tlb_index_r = i_search_i[4:0];
            end
        end
    end

    always @(*) begin
        case (read_addr)
            CSR_CRMD:          read_data = csr_crmd;
            CSR_PRMD:          read_data = csr_prmd;
            CSR_ECFG:          read_data = csr_ecfg;
            CSR_ESTAT:         read_data = csr_estat;
            CSR_ERA:           read_data = csr_era;
            CSR_BADV:          read_data = csr_badv;
            CSR_EENTRY:        read_data = csr_eentry;
            CSR_TLBIDX:        read_data = csr_tlbidx;
            CSR_TLBEHI:        read_data = csr_tlbehi;
            CSR_TLBELO0:       read_data = csr_tlbelo0;
            CSR_TLBELO1:       read_data = csr_tlbelo1;
            CSR_ASID:          read_data = csr_asid;
            CSR_PGDL:          read_data = csr_pgdl;
            CSR_PGDH:          read_data = csr_pgdh;
            CSR_PGD:           read_data = csr_pgd;
            CSR_CPUID:         read_data = csr_cpuid;
            CSR_SAVE0:         read_data = csr_save0;
            CSR_SAVE1:         read_data = csr_save1;
            CSR_SAVE2:         read_data = csr_save2;
            CSR_SAVE3:         read_data = csr_save3;
            CSR_TID:           read_data = csr_tid;
            CSR_TCFG:          read_data = csr_tcfg;
            CSR_TVAL:          read_data = csr_tval;
            CSR_CNTC:          read_data = csr_cntc;
            CSR_TICLR:         read_data = csr_ticlr;
            CSR_LLBCTL:        read_data = csr_llbctl;
            CSR_TLBRENTRY:     read_data = csr_tlbrentry;
            CSR_DISABLE_CACHE: read_data = csr_disable_cache;
            CSR_DMW0:          read_data = csr_dmw0;
            CSR_DMW1:          read_data = csr_dmw1;
            CPUCFG_1:          read_data = 32'h00000000;
            CPUCFG_2:          read_data = 32'h00000000;
            CPUCFG_10:         read_data = 32'h00000000;
            CPUCFG_11:         read_data = 32'h00000000;
            CPUCFG_12:         read_data = 32'h00000000;
            CPUCFG_13:         read_data = 32'h00000000;
            default:           read_data = 32'b0;
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin
            csr_crmd          <= 32'h00000008;
            csr_prmd          <= 32'b0;
            csr_ecfg          <= 32'b0;
            csr_estat         <= 32'b0;
            csr_era           <= 32'b0;
            csr_badv          <= 32'b0;
            csr_eentry        <= 32'b0;
            csr_tlbidx        <= 32'b0;
            csr_tlbehi        <= 32'b0;
            csr_tlbelo0       <= 32'b0;
            csr_tlbelo1       <= 32'b0;
            csr_asid          <= {22'h280, 10'b0};
            csr_pgdl          <= 32'b0;
            csr_pgdh          <= 32'b0;
            csr_cpuid         <= 32'b0;
            csr_save0         <= 32'b0;
            csr_save1         <= 32'b0;
            csr_save2         <= 32'b0;
            csr_save3         <= 32'b0;
            csr_tid           <= 32'b0;
            csr_tcfg          <= 32'b0;
            csr_tval          <= 32'b0;
            csr_cntc          <= 32'b0;
            csr_ticlr         <= 32'b0;
            csr_llbctl        <= 32'b0;
            csr_tlbrentry     <= 32'b0;
            csr_disable_cache <= 32'b0;
            csr_dmw0          <= 32'b0;
            csr_dmw1          <= 32'b0;
            timer_en          <= 1'b0;
            timer_64          <= 64'b0;
            for (reset_i = 0; reset_i < 32; reset_i = reset_i + 1) begin
                tlb_vppn[reset_i] <= 19'b0;
                tlb_asid[reset_i] <= 10'b0;
                tlb_g[reset_i]    <= 1'b0;
                tlb_ps[reset_i]   <= 6'b0;
                tlb_e[reset_i]    <= 1'b0;
                tlb_ppn0[reset_i] <= 20'b0;
                tlb_plv0[reset_i] <= 2'b0;
                tlb_mat0[reset_i] <= 2'b0;
                tlb_d0[reset_i]   <= 1'b0;
                tlb_v0[reset_i]   <= 1'b0;
                tlb_ppn1[reset_i] <= 20'b0;
                tlb_plv1[reset_i] <= 2'b0;
                tlb_mat1[reset_i] <= 2'b0;
                tlb_d1[reset_i]   <= 1'b0;
                tlb_v1[reset_i]   <= 1'b0;
            end
        end else begin
            if (timer_tick) begin
                timer_64 <= timer_64 + 64'd1;
            end
            csr_estat[9:2] <= interrupt;

            if (timer_tick && timer_en) begin
                if (csr_tval != 32'b0) begin
                    csr_tval <= csr_tval - 32'd1;
                end else begin
                    csr_estat[11] <= 1'b1;
                    timer_en <= csr_tcfg[1];
                    csr_tval <= csr_tcfg[1] ? {csr_tcfg[31:2], 2'b0} : 32'hffffffff;
                end
            end

            if (exception_valid) begin
                csr_prmd[1:0]   <= csr_crmd[1:0];
                csr_prmd[2]     <= csr_crmd[2];
                csr_crmd[1:0]   <= 2'b0;
                csr_crmd[2]     <= 1'b0;
                if (exception_ecode == 6'h3f) begin
                    csr_crmd[3] <= 1'b1;
                    csr_crmd[4] <= 1'b0;
                end
                csr_era         <= exception_pc;
                csr_estat[21:16] <= exception_ecode;
                csr_estat[30:22] <= exception_esubcode;
                if (exception_badv_valid) begin
                    csr_badv <= exception_badv;
                    if ((exception_ecode == 6'h3f) ||
                        (exception_ecode == 6'h01) ||
                        (exception_ecode == 6'h02) ||
                        (exception_ecode == 6'h03) ||
                        (exception_ecode == 6'h04) ||
                        (exception_ecode == 6'h07)) begin
                        csr_tlbehi <= {exception_badv[31:13], 13'b0};
                    end
                end
            end else if (ertn_valid) begin
                csr_crmd[1:0] <= csr_prmd[1:0];
                csr_crmd[2]   <= csr_prmd[2];
                if (csr_estat[21:16] == 6'h3f) begin
                    csr_crmd[3] <= 1'b0;
                    csr_crmd[4] <= 1'b1;
                end
            end else if (write_valid) begin
                case (write_addr)
                    CSR_CRMD: begin
                        csr_crmd[1:0] <= write_data[1:0];
                        csr_crmd[2]   <= write_data[2];
                        csr_crmd[3]   <= write_data[3];
                        csr_crmd[4]   <= write_data[4];
                        csr_crmd[6:5] <= write_data[6:5];
                        csr_crmd[8:7] <= write_data[8:7];
                    end
                    CSR_PRMD: begin
                        csr_prmd[1:0] <= write_data[1:0];
                        csr_prmd[2]   <= write_data[2];
                    end
                    CSR_ECFG:          csr_ecfg          <= {19'b0, write_data[12:11], 1'b0, write_data[9:0]};
                    CSR_ESTAT:         csr_estat[1:0]    <= write_data[1:0];
                    CSR_ERA:           csr_era           <= write_data;
                    CSR_BADV:          csr_badv          <= write_data;
                    CSR_EENTRY:        csr_eentry        <= {write_data[31:6], 6'b0};
                    CSR_TLBIDX:        csr_tlbidx        <= {write_data[31], 1'b0, write_data[29:24], 19'b0, write_data[4:0]};
                    CSR_TLBEHI:        csr_tlbehi        <= {write_data[31:13], 13'b0};
                    CSR_TLBELO0:       csr_tlbelo0       <= {4'b0, write_data[27:8], 1'b0, write_data[6:0]};
                    CSR_TLBELO1:       csr_tlbelo1       <= {4'b0, write_data[27:8], 1'b0, write_data[6:0]};
                    CSR_ASID:          csr_asid          <= {22'h280, write_data[9:0]};
                    CSR_PGDL:          csr_pgdl          <= {write_data[31:12], 12'b0};
                    CSR_PGDH:          csr_pgdh          <= {write_data[31:12], 12'b0};
                    CSR_CPUID:         csr_cpuid         <= write_data;
                    CSR_SAVE0:         csr_save0         <= write_data;
                    CSR_SAVE1:         csr_save1         <= write_data;
                    CSR_SAVE2:         csr_save2         <= write_data;
                    CSR_SAVE3:         csr_save3         <= write_data;
                    CSR_TID:           csr_tid           <= write_data;
                    CSR_TCFG: begin
                        csr_tcfg <= write_data;
                        csr_tval <= {write_data[31:2], 2'b0} + 32'd1;
                        timer_en <= write_data[0];
                    end
                    CSR_TVAL:          csr_tval          <= write_data;
                    CSR_CNTC:          csr_cntc          <= write_data;
                    CSR_TICLR: begin
                        csr_ticlr <= 32'b0;
                        if (write_data[0]) begin
                            csr_estat[11] <= 1'b0;
                        end
                    end
                    CSR_LLBCTL:        csr_llbctl        <= write_data;
                    CSR_TLBRENTRY:     csr_tlbrentry     <= {write_data[31:6], 6'b0};
                    CSR_DISABLE_CACHE: csr_disable_cache <= write_data;
                    CSR_DMW0:          csr_dmw0          <= write_data;
                    CSR_DMW1:          csr_dmw1          <= write_data;
                    default: begin
                    end
                endcase
            end else if (commit_tlbwr || commit_tlbfill) begin
                tlb_vppn[tlb_write_index] <= csr_tlbehi[31:13];
                tlb_asid[tlb_write_index] <= csr_asid[9:0];
                tlb_g[tlb_write_index]    <= csr_tlbelo0[6] & csr_tlbelo1[6];
                tlb_ps[tlb_write_index]   <= csr_tlbidx[29:24];
                tlb_e[tlb_write_index]    <= tlb_write_enable_value;
                tlb_ppn0[tlb_write_index] <= csr_tlbelo0[27:8];
                tlb_plv0[tlb_write_index] <= csr_tlbelo0[3:2];
                tlb_mat0[tlb_write_index] <= csr_tlbelo0[5:4];
                tlb_d0[tlb_write_index]   <= csr_tlbelo0[1];
                tlb_v0[tlb_write_index]   <= csr_tlbelo0[0];
                tlb_ppn1[tlb_write_index] <= csr_tlbelo1[27:8];
                tlb_plv1[tlb_write_index] <= csr_tlbelo1[3:2];
                tlb_mat1[tlb_write_index] <= csr_tlbelo1[5:4];
                tlb_d1[tlb_write_index]   <= csr_tlbelo1[1];
                tlb_v1[tlb_write_index]   <= csr_tlbelo1[0];
            end else if (commit_tlbrd) begin
                if (tlb_e[csr_tlbidx[4:0]]) begin
                    csr_tlbidx  <= {1'b0, 1'b0, tlb_ps[csr_tlbidx[4:0]], 19'b0, csr_tlbidx[4:0]};
                    csr_tlbehi  <= {tlb_vppn[csr_tlbidx[4:0]], 13'b0};
                    csr_tlbelo0 <= tlbelo0_packed;
                    csr_tlbelo1 <= tlbelo1_packed;
                    csr_asid    <= {22'h280, tlb_asid[csr_tlbidx[4:0]]};
                end else begin
                    csr_tlbidx  <= {1'b1, 1'b0, 6'b0, 19'b0, csr_tlbidx[4:0]};
                    csr_tlbehi  <= 32'b0;
                    csr_tlbelo0 <= 32'b0;
                    csr_tlbelo1 <= 32'b0;
                    csr_asid    <= {22'h280, 10'b0};
                end
            end else if (commit_tlbsrch) begin
                tlbsrch_found_r = 1'b0;
                tlbsrch_index_r = 5'b0;
                for (search_i = 0; search_i < 32; search_i = search_i + 1) begin
                    if (!tlbsrch_found_r && tlb_e[search_i] &&
                        ((tlb_ps[search_i] == 6'd12) ?
                         (tlb_vppn[search_i] == csr_tlbehi[31:13]) :
                         (tlb_vppn[search_i][18:9] == csr_tlbehi[31:22])) &&
                        ((tlb_asid[search_i] == csr_asid[9:0]) || tlb_g[search_i])) begin
                        tlbsrch_found_r = 1'b1;
                        tlbsrch_index_r = search_i[4:0];
                    end
                end
                if (tlbsrch_found_r) begin
                    csr_tlbidx <= {1'b0, csr_tlbidx[30:5], tlbsrch_index_r};
                end else begin
                    csr_tlbidx <= {1'b1, csr_tlbidx[30:0]};
                end
            end else if (commit_invtlb) begin
                for (inv_i = 0; inv_i < 32; inv_i = inv_i + 1) begin
                    if ((commit_rd == 5'd0) || (commit_rd == 5'd1)) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_rd == 5'd2) && tlb_g[inv_i]) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_rd == 5'd3) && !tlb_g[inv_i]) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_rd == 5'd4) && !tlb_g[inv_i] &&
                                 (tlb_asid[inv_i] == tlb_commit_op1[9:0])) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_rd == 5'd5) && !tlb_g[inv_i] &&
                                 (tlb_asid[inv_i] == tlb_commit_op1[9:0]) &&
                                 ((tlb_ps[inv_i] == 6'd12) ?
                                  (tlb_vppn[inv_i] == tlb_commit_op2[31:13]) :
                                  (tlb_vppn[inv_i][18:9] == tlb_commit_op2[31:22]))) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_rd == 5'd6) &&
                                 (tlb_g[inv_i] || (tlb_asid[inv_i] == tlb_commit_op1[9:0])) &&
                                 ((tlb_ps[inv_i] == 6'd12) ?
                                  (tlb_vppn[inv_i] == tlb_commit_op2[31:13]) :
                                  (tlb_vppn[inv_i][18:9] == tlb_commit_op2[31:22]))) begin
                        tlb_e[inv_i] <= 1'b0;
                    end
                end
            end
        end
    end

endmodule

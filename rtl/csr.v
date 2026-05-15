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
    output wire        i_tlb_resp_valid,
    output wire [31:0] i_tlb_resp_vaddr,
    output wire [31:0] i_tlb_query_paddr,
    output wire        i_tlb_exception_valid,
    output wire [5:0]  i_tlb_exception_ecode,
    input  wire        d_tlb_query_valid,
    input  wire        d_tlb_query_write,
    input  wire [31:0] d_tlb_query_vaddr,
    output wire        d_tlb_resp_valid,
    output wire [31:0] d_tlb_resp_vaddr,
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
    wire        tlbsrch_found_w;
    wire [4:0]  tlbsrch_index_w;
    wire        tlbrd_found_w;
    wire [31:0] tlbrd_tlbidx_w;
    wire [31:0] tlbrd_tlbehi_w;
    wire [31:0] tlbrd_tlbelo0_w;
    wire [31:0] tlbrd_tlbelo1_w;
    wire [31:0] tlbrd_asid_w;

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
    cpu_tlb u_cpu_tlb (
        .clk                  (clk),
        .reset                (reset),
        .csr_crmd             (csr_crmd),
        .csr_asid             (csr_asid),
        .csr_dmw0             (csr_dmw0),
        .csr_dmw1             (csr_dmw1),
        .csr_tlbidx           (csr_tlbidx),
        .csr_tlbehi           (csr_tlbehi),
        .csr_tlbelo0          (csr_tlbelo0),
        .csr_tlbelo1          (csr_tlbelo1),
        .csr_estat            (csr_estat),
        .commit_tlbsrch       (commit_tlbsrch),
        .commit_tlbrd         (commit_tlbrd),
        .commit_tlbwr         (commit_tlbwr),
        .commit_tlbfill       (commit_tlbfill),
        .commit_invtlb        (commit_invtlb),
        .commit_invtlb_op     (commit_rd),
        .commit_invtlb_asid   (tlb_commit_op1),
        .commit_invtlb_vaddr  (tlb_commit_op2),
        .tlbsrch_found        (tlbsrch_found_w),
        .tlbsrch_index        (tlbsrch_index_w),
        .tlbrd_found          (tlbrd_found_w),
        .tlbrd_tlbidx         (tlbrd_tlbidx_w),
        .tlbrd_tlbehi         (tlbrd_tlbehi_w),
        .tlbrd_tlbelo0        (tlbrd_tlbelo0_w),
        .tlbrd_tlbelo1        (tlbrd_tlbelo1_w),
        .tlbrd_asid           (tlbrd_asid_w),
        .i_tlb_query_valid    (i_tlb_query_valid),
        .i_tlb_query_write    (i_tlb_query_write),
        .i_tlb_query_vaddr    (i_tlb_query_vaddr),
        .i_tlb_resp_valid     (i_tlb_resp_valid),
        .i_tlb_resp_vaddr     (i_tlb_resp_vaddr),
        .i_tlb_query_paddr    (i_tlb_query_paddr),
        .i_tlb_exception_valid(i_tlb_exception_valid),
        .i_tlb_exception_ecode(i_tlb_exception_ecode),
        .d_tlb_query_valid    (d_tlb_query_valid),
        .d_tlb_query_write    (d_tlb_query_write),
        .d_tlb_query_vaddr    (d_tlb_query_vaddr),
        .d_tlb_resp_valid     (d_tlb_resp_valid),
        .d_tlb_resp_vaddr     (d_tlb_resp_vaddr),
        .d_tlb_query_paddr    (d_tlb_query_paddr),
        .d_tlb_exception_valid(d_tlb_exception_valid),
        .d_tlb_exception_ecode(d_tlb_exception_ecode)
    );

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
            end else if (commit_tlbrd) begin
                if (tlbrd_found_w) begin
                    csr_tlbidx  <= tlbrd_tlbidx_w;
                    csr_tlbehi  <= tlbrd_tlbehi_w;
                    csr_tlbelo0 <= tlbrd_tlbelo0_w;
                    csr_tlbelo1 <= tlbrd_tlbelo1_w;
                    csr_asid    <= tlbrd_asid_w;
                end else begin
                    csr_tlbidx  <= {1'b1, 1'b0, 6'b0, 19'b0, csr_tlbidx[4:0]};
                    csr_tlbehi  <= 32'b0;
                    csr_tlbelo0 <= 32'b0;
                    csr_tlbelo1 <= 32'b0;
                    csr_asid    <= {22'h280, 10'b0};
                end
            end else if (commit_tlbsrch) begin
                if (tlbsrch_found_w) begin
                    csr_tlbidx <= {1'b0, csr_tlbidx[30:5], tlbsrch_index_w};
                end else begin
                    csr_tlbidx <= {1'b1, csr_tlbidx[30:0]};
                end
            end
        end
    end

endmodule

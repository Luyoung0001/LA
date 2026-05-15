module cpu_tlb (
    input  wire        clk,
    input  wire        reset,

    input  wire [31:0] csr_crmd,
    input  wire [31:0] csr_asid,
    input  wire [31:0] csr_dmw0,
    input  wire [31:0] csr_dmw1,
    input  wire [31:0] csr_tlbidx,
    input  wire [31:0] csr_tlbehi,
    input  wire [31:0] csr_tlbelo0,
    input  wire [31:0] csr_tlbelo1,
    input  wire [31:0] csr_estat,

    input  wire        commit_tlbsrch,
    input  wire        commit_tlbrd,
    input  wire        commit_tlbwr,
    input  wire        commit_tlbfill,
    input  wire        commit_invtlb,
    input  wire [4:0]  commit_invtlb_op,
    input  wire [31:0] commit_invtlb_asid,
    input  wire [31:0] commit_invtlb_vaddr,

    output wire        tlbsrch_found,
    output wire [4:0]  tlbsrch_index,
    output wire        tlbrd_found,
    output wire [31:0] tlbrd_tlbidx,
    output wire [31:0] tlbrd_tlbehi,
    output wire [31:0] tlbrd_tlbelo0,
    output wire [31:0] tlbrd_tlbelo1,
    output wire [31:0] tlbrd_asid,

    input  wire        i_tlb_query_valid,
    input  wire        i_tlb_query_write,
    input  wire [31:0] i_tlb_query_vaddr,
    output reg         i_tlb_resp_valid,
    output reg  [31:0] i_tlb_query_paddr,
    output reg         i_tlb_exception_valid,
    output reg  [5:0]  i_tlb_exception_ecode,

    input  wire        d_tlb_query_valid,
    input  wire        d_tlb_query_write,
    input  wire [31:0] d_tlb_query_vaddr,
    output reg         d_tlb_resp_valid,
    output reg  [31:0] d_tlb_query_paddr,
    output reg         d_tlb_exception_valid,
    output reg  [5:0]  d_tlb_exception_ecode
);

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
    integer i_search_i;
    integer d_search_i;

    reg        tlbsrch_found_r;
    reg [4:0]  tlbsrch_index_r;
    reg        i_tlb_found_r;
    reg [4:0]  i_tlb_index_r;
    reg        i_tlb_req_valid_r;
    reg [31:0] i_tlb_req_vaddr_r;
    reg [9:0]  i_tlb_req_asid_r;
    reg [1:0]  i_tlb_req_plv_r;
    reg        i_tlb_req_pg_mode_r;
    reg [31:0] i_tlb_req_dmw0_r;
    reg [31:0] i_tlb_req_dmw1_r;
    reg        d_tlb_found_r;
    reg [4:0]  d_tlb_index_r;
    reg        d_tlb_req_valid_r;
    reg        d_tlb_req_write_r;
    reg [31:0] d_tlb_req_vaddr_r;
    reg [9:0]  d_tlb_req_asid_r;
    reg [1:0]  d_tlb_req_plv_r;
    reg        d_tlb_req_pg_mode_r;
    reg [31:0] d_tlb_req_dmw0_r;
    reg [31:0] d_tlb_req_dmw1_r;

    wire [4:0]  tlb_write_index;
    wire        tlb_write_enable_value;
    wire [31:0] tlbelo0_packed;
    wire [31:0] tlbelo1_packed;

    wire        pg_mode;

    wire        i_dmw0_hit;
    wire        i_dmw1_hit;
    wire        i_tlb_translate;
    wire        i_tlb_odd_page;
    wire [5:0]  i_tlb_ps;
    wire [19:0] i_tlb_ppn;
    wire        i_tlb_v;
    wire [1:0]  i_tlb_plv;
    wire [31:0] i_tlb_trans_paddr;
    wire [31:0] i_dmw_paddr;
    wire [31:0] i_tlb_query_paddr_w;
    wire        i_tlb_exception_valid_w;
    wire [5:0]  i_tlb_exception_ecode_w;

    wire        d_dmw0_hit;
    wire        d_dmw1_hit;
    wire        d_tlb_translate;
    wire        d_tlb_odd_page;
    wire [5:0]  d_tlb_ps;
    wire [19:0] d_tlb_ppn;
    wire        d_tlb_v;
    wire        d_tlb_d;
    wire [1:0]  d_tlb_plv;
    wire [31:0] d_tlb_trans_paddr;
    wire [31:0] d_dmw_paddr;
    wire [31:0] d_tlb_query_paddr_w;
    wire        d_tlb_exception_valid_w;
    wire [5:0]  d_tlb_exception_ecode_w;

    assign pg_mode = !csr_crmd[3] && csr_crmd[4];
    assign tlb_write_index = commit_tlbfill ? 5'b0 : csr_tlbidx[4:0];
    assign tlb_write_enable_value = (csr_estat[21:16] == 6'h3f) ? 1'b1 : ~csr_tlbidx[31];

    assign tlbelo0_packed = {4'b0, tlb_ppn0[csr_tlbidx[4:0]], 1'b0, tlb_g[csr_tlbidx[4:0]],
                             tlb_mat0[csr_tlbidx[4:0]], tlb_plv0[csr_tlbidx[4:0]],
                             tlb_d0[csr_tlbidx[4:0]], tlb_v0[csr_tlbidx[4:0]]};
    assign tlbelo1_packed = {4'b0, tlb_ppn1[csr_tlbidx[4:0]], 1'b0, tlb_g[csr_tlbidx[4:0]],
                             tlb_mat1[csr_tlbidx[4:0]], tlb_plv1[csr_tlbidx[4:0]],
                             tlb_d1[csr_tlbidx[4:0]], tlb_v1[csr_tlbidx[4:0]]};

    assign tlbsrch_found = tlbsrch_found_r;
    assign tlbsrch_index = tlbsrch_index_r;
    assign tlbrd_found   = tlb_e[csr_tlbidx[4:0]];
    assign tlbrd_tlbidx  = {1'b0, 1'b0, tlb_ps[csr_tlbidx[4:0]], 19'b0, csr_tlbidx[4:0]};
    assign tlbrd_tlbehi  = {tlb_vppn[csr_tlbidx[4:0]], 13'b0};
    assign tlbrd_tlbelo0 = tlbelo0_packed;
    assign tlbrd_tlbelo1 = tlbelo1_packed;
    assign tlbrd_asid    = {22'h280, tlb_asid[csr_tlbidx[4:0]]};

    always @(*) begin
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
    end

    assign i_dmw0_hit = i_tlb_req_pg_mode_r &&
                        (((i_tlb_req_dmw0_r[0] && (i_tlb_req_plv_r == 2'd0)) ||
                          (i_tlb_req_dmw0_r[3] && (i_tlb_req_plv_r == 2'd3))) &&
                         (i_tlb_req_vaddr_r[31:29] == i_tlb_req_dmw0_r[31:29]));
    assign i_dmw1_hit = i_tlb_req_pg_mode_r &&
                        (((i_tlb_req_dmw1_r[0] && (i_tlb_req_plv_r == 2'd0)) ||
                          (i_tlb_req_dmw1_r[3] && (i_tlb_req_plv_r == 2'd3))) &&
                         (i_tlb_req_vaddr_r[31:29] == i_tlb_req_dmw1_r[31:29]));
    assign i_tlb_translate = i_tlb_req_valid_r && i_tlb_req_pg_mode_r && !i_dmw0_hit && !i_dmw1_hit;
    assign i_tlb_ps = tlb_ps[i_tlb_index_r];
    assign i_tlb_odd_page = (i_tlb_ps == 6'd12) ? i_tlb_req_vaddr_r[12] : i_tlb_req_vaddr_r[21];
    assign i_tlb_ppn = i_tlb_odd_page ? tlb_ppn1[i_tlb_index_r] : tlb_ppn0[i_tlb_index_r];
    assign i_tlb_v   = i_tlb_odd_page ? tlb_v1[i_tlb_index_r]   : tlb_v0[i_tlb_index_r];
    assign i_tlb_plv = i_tlb_odd_page ? tlb_plv1[i_tlb_index_r] : tlb_plv0[i_tlb_index_r];
    assign i_tlb_trans_paddr = (i_tlb_ps == 6'd12) ?
                               {i_tlb_ppn, i_tlb_req_vaddr_r[11:0]} :
                               {i_tlb_ppn[19:10], i_tlb_req_vaddr_r[21:0]};
    assign i_dmw_paddr = i_dmw0_hit ? {i_tlb_req_dmw0_r[27:25], i_tlb_req_vaddr_r[28:0]} :
                         i_dmw1_hit ? {i_tlb_req_dmw1_r[27:25], i_tlb_req_vaddr_r[28:0]} :
                                      i_tlb_req_vaddr_r;
    assign i_tlb_query_paddr_w = i_tlb_translate ? i_tlb_trans_paddr : i_dmw_paddr;
    assign i_tlb_exception_valid_w = i_tlb_translate &&
                                     (!i_tlb_found_r ||
                                      !i_tlb_v ||
                                      (i_tlb_req_plv_r > i_tlb_plv));
    assign i_tlb_exception_ecode_w = !i_tlb_found_r ? 6'h3f :
                                     !i_tlb_v ? 6'h03 :
                                     6'h07;

    always @(*) begin
        i_tlb_found_r = 1'b0;
        i_tlb_index_r = 5'b0;
        for (i_search_i = 0; i_search_i < 32; i_search_i = i_search_i + 1) begin
            if (!i_tlb_found_r && tlb_e[i_search_i] &&
                ((tlb_ps[i_search_i] == 6'd12) ?
                 (tlb_vppn[i_search_i] == i_tlb_req_vaddr_r[31:13]) :
                 (tlb_vppn[i_search_i][18:9] == i_tlb_req_vaddr_r[31:22])) &&
                ((tlb_asid[i_search_i] == i_tlb_req_asid_r) || tlb_g[i_search_i])) begin
                i_tlb_found_r = 1'b1;
                i_tlb_index_r = i_search_i[4:0];
            end
        end
    end

    assign d_dmw0_hit = d_tlb_req_pg_mode_r &&
                        (((d_tlb_req_dmw0_r[0] && (d_tlb_req_plv_r == 2'd0)) ||
                          (d_tlb_req_dmw0_r[3] && (d_tlb_req_plv_r == 2'd3))) &&
                         (d_tlb_req_vaddr_r[31:29] == d_tlb_req_dmw0_r[31:29]));
    assign d_dmw1_hit = d_tlb_req_pg_mode_r &&
                        (((d_tlb_req_dmw1_r[0] && (d_tlb_req_plv_r == 2'd0)) ||
                          (d_tlb_req_dmw1_r[3] && (d_tlb_req_plv_r == 2'd3))) &&
                         (d_tlb_req_vaddr_r[31:29] == d_tlb_req_dmw1_r[31:29]));
    assign d_tlb_translate = d_tlb_req_valid_r && d_tlb_req_pg_mode_r && !d_dmw0_hit && !d_dmw1_hit;
    assign d_tlb_ps = tlb_ps[d_tlb_index_r];
    assign d_tlb_odd_page = (d_tlb_ps == 6'd12) ? d_tlb_req_vaddr_r[12] : d_tlb_req_vaddr_r[21];
    assign d_tlb_ppn = d_tlb_odd_page ? tlb_ppn1[d_tlb_index_r] : tlb_ppn0[d_tlb_index_r];
    assign d_tlb_v   = d_tlb_odd_page ? tlb_v1[d_tlb_index_r]   : tlb_v0[d_tlb_index_r];
    assign d_tlb_d   = d_tlb_odd_page ? tlb_d1[d_tlb_index_r]   : tlb_d0[d_tlb_index_r];
    assign d_tlb_plv = d_tlb_odd_page ? tlb_plv1[d_tlb_index_r] : tlb_plv0[d_tlb_index_r];
    assign d_tlb_trans_paddr = (d_tlb_ps == 6'd12) ?
                               {d_tlb_ppn, d_tlb_req_vaddr_r[11:0]} :
                               {d_tlb_ppn[19:10], d_tlb_req_vaddr_r[21:0]};
    assign d_dmw_paddr = d_dmw0_hit ? {d_tlb_req_dmw0_r[27:25], d_tlb_req_vaddr_r[28:0]} :
                         d_dmw1_hit ? {d_tlb_req_dmw1_r[27:25], d_tlb_req_vaddr_r[28:0]} :
                                      d_tlb_req_vaddr_r;
    assign d_tlb_query_paddr_w = d_tlb_translate ? d_tlb_trans_paddr : d_dmw_paddr;
    assign d_tlb_exception_valid_w = d_tlb_translate &&
                                     (!d_tlb_found_r ||
                                      !d_tlb_v ||
                                      (d_tlb_req_plv_r > d_tlb_plv) ||
                                      (d_tlb_req_write_r && !d_tlb_d));
    assign d_tlb_exception_ecode_w = !d_tlb_found_r ? 6'h3f :
                                     !d_tlb_v ? (d_tlb_req_write_r ? 6'h02 : 6'h01) :
                                     (d_tlb_req_plv_r > d_tlb_plv) ? 6'h07 :
                                     6'h04;

    always @(*) begin
        d_tlb_found_r = 1'b0;
        d_tlb_index_r = 5'b0;
        for (d_search_i = 0; d_search_i < 32; d_search_i = d_search_i + 1) begin
            if (!d_tlb_found_r && tlb_e[d_search_i] &&
                ((tlb_ps[d_search_i] == 6'd12) ?
                 (tlb_vppn[d_search_i] == d_tlb_req_vaddr_r[31:13]) :
                 (tlb_vppn[d_search_i][18:9] == d_tlb_req_vaddr_r[31:22])) &&
                ((tlb_asid[d_search_i] == d_tlb_req_asid_r) || tlb_g[d_search_i])) begin
                d_tlb_found_r = 1'b1;
                d_tlb_index_r = d_search_i[4:0];
            end
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            i_tlb_resp_valid      <= 1'b0;
            i_tlb_query_paddr     <= 32'b0;
            i_tlb_exception_valid <= 1'b0;
            i_tlb_exception_ecode <= 6'b0;
            i_tlb_req_valid_r     <= 1'b0;
            i_tlb_req_vaddr_r     <= 32'b0;
            i_tlb_req_asid_r      <= 10'b0;
            i_tlb_req_plv_r       <= 2'b0;
            i_tlb_req_pg_mode_r   <= 1'b0;
            i_tlb_req_dmw0_r      <= 32'b0;
            i_tlb_req_dmw1_r      <= 32'b0;
            d_tlb_req_valid_r     <= 1'b0;
            d_tlb_req_write_r     <= 1'b0;
            d_tlb_req_vaddr_r     <= 32'b0;
            d_tlb_req_asid_r      <= 10'b0;
            d_tlb_req_plv_r       <= 2'b0;
            d_tlb_req_pg_mode_r   <= 1'b0;
            d_tlb_req_dmw0_r      <= 32'b0;
            d_tlb_req_dmw1_r      <= 32'b0;
            d_tlb_resp_valid      <= 1'b0;
            d_tlb_query_paddr     <= 32'b0;
            d_tlb_exception_valid <= 1'b0;
            d_tlb_exception_ecode <= 6'b0;
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
            i_tlb_req_valid_r     <= i_tlb_query_valid;
            i_tlb_req_vaddr_r     <= i_tlb_query_vaddr;
            i_tlb_req_asid_r      <= csr_asid[9:0];
            i_tlb_req_plv_r       <= csr_crmd[1:0];
            i_tlb_req_pg_mode_r   <= pg_mode;
            i_tlb_req_dmw0_r      <= csr_dmw0;
            i_tlb_req_dmw1_r      <= csr_dmw1;

            i_tlb_resp_valid      <= i_tlb_req_valid_r;
            i_tlb_query_paddr     <= i_tlb_query_paddr_w;
            i_tlb_exception_valid <= i_tlb_exception_valid_w;
            i_tlb_exception_ecode <= i_tlb_exception_ecode_w;

            d_tlb_req_valid_r     <= d_tlb_query_valid;
            d_tlb_req_write_r     <= d_tlb_query_write;
            d_tlb_req_vaddr_r     <= d_tlb_query_vaddr;
            d_tlb_req_asid_r      <= csr_asid[9:0];
            d_tlb_req_plv_r       <= csr_crmd[1:0];
            d_tlb_req_pg_mode_r   <= pg_mode;
            d_tlb_req_dmw0_r      <= csr_dmw0;
            d_tlb_req_dmw1_r      <= csr_dmw1;
            d_tlb_resp_valid      <= d_tlb_req_valid_r;
            d_tlb_query_paddr     <= d_tlb_query_paddr_w;
            d_tlb_exception_valid <= d_tlb_exception_valid_w;
            d_tlb_exception_ecode <= d_tlb_exception_ecode_w;

            if (commit_tlbwr || commit_tlbfill) begin
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
            end else if (commit_invtlb) begin
                for (inv_i = 0; inv_i < 32; inv_i = inv_i + 1) begin
                    if ((commit_invtlb_op == 5'd0) || (commit_invtlb_op == 5'd1)) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_invtlb_op == 5'd2) && tlb_g[inv_i]) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_invtlb_op == 5'd3) && !tlb_g[inv_i]) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_invtlb_op == 5'd4) && !tlb_g[inv_i] &&
                                 (tlb_asid[inv_i] == commit_invtlb_asid[9:0])) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_invtlb_op == 5'd5) && !tlb_g[inv_i] &&
                                 (tlb_asid[inv_i] == commit_invtlb_asid[9:0]) &&
                                 ((tlb_ps[inv_i] == 6'd12) ?
                                  (tlb_vppn[inv_i] == commit_invtlb_vaddr[31:13]) :
                                  (tlb_vppn[inv_i][18:9] == commit_invtlb_vaddr[31:22]))) begin
                        tlb_e[inv_i] <= 1'b0;
                    end else if ((commit_invtlb_op == 5'd6) &&
                                 (tlb_g[inv_i] || (tlb_asid[inv_i] == commit_invtlb_asid[9:0])) &&
                                 ((tlb_ps[inv_i] == 6'd12) ?
                                  (tlb_vppn[inv_i] == commit_invtlb_vaddr[31:13]) :
                                  (tlb_vppn[inv_i][18:9] == commit_invtlb_vaddr[31:22]))) begin
                        tlb_e[inv_i] <= 1'b0;
                    end
                end
            end
        end
    end

    wire unused_commit_tlbsrch = commit_tlbsrch;
    wire unused_commit_tlbrd   = commit_tlbrd;
    wire unused_i_write        = i_tlb_query_write;

endmodule

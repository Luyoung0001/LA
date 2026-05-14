`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s2_frontend_if1_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, redirect_inject_valid, s1_valid, s2_allowin, s3_allowin, s2_valid;
    logic bpu_valid, bpu_taken, bpu_ras_valid, tlb_found, tlb_v;
    logic [31:0] redirect_inject_pc, s1_pc, bpu_pc, bpu_target, bpu_ras_target, s2_pc, pred_target, ras_target, paddr, bpu_redirect_target;
    logic [31:0] csr_crmd, csr_dmw0, csr_dmw1, fault_badv;
    logic [1:0] s1_epoch, redirect_inject_epoch, s2_epoch;
    logic [19:0] tlb_ppn;
    logic [5:0] tlb_ps;
    logic [5:0] fault_ecode;
    logic [1:0] tlb_plv;
    logic pred_taken, ras_valid, tlb_fault, bpu_redirect_valid;
    logic s3_dup_drop;
    logic shadow_fetch_valid;
    logic [31:0] shadow_fetch_paddr;
    s2_frontend_if1 #(.EPOCH_WIDTH(2), .BPU_ENABLE(1)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush),
        .redirect_inject_valid_i(redirect_inject_valid),
        .redirect_inject_pc_i(redirect_inject_pc),
        .redirect_inject_epoch_i(redirect_inject_epoch),
        .s1_to_s2_valid(s1_valid),
        .s2_allowin(s2_allowin), .s3_allowin(s3_allowin), .s3_dup_drop_i(s3_dup_drop),
        .s2_to_s3_valid(s2_valid),
        .s1_pc_i(s1_pc), .s1_epoch_i(s1_epoch),
        .bpu_pred_pc_i(bpu_pc), .bpu_pred_valid_i(bpu_valid), .bpu_pred_taken_i(bpu_taken),
        .bpu_pred_target_i(bpu_target), .bpu_ras_valid_i(bpu_ras_valid), .bpu_ras_target_i(bpu_ras_target),
        .tlb_found_i(tlb_found), .tlb_ppn_i(tlb_ppn),
        .tlb_ps_i(tlb_ps), .tlb_plv_i(tlb_plv), .tlb_v_i(tlb_v),
        .csr_crmd_i(csr_crmd), .csr_dmw0_i(csr_dmw0), .csr_dmw1_i(csr_dmw1), .s2_pc_o(s2_pc),
        .s2_epoch_o(s2_epoch),
        .s2_pred_taken_o(pred_taken), .s2_pred_target_o(pred_target),
        .s2_ras_valid_o(ras_valid), .s2_ras_target_o(ras_target), .s2_tlb_fault_o(tlb_fault),
        .s2_fault_ecode_o(fault_ecode), .s2_fault_badv_o(fault_badv),
        .s2_icache_paddr_o(paddr),
        .shadow_fetch_valid_o(shadow_fetch_valid),
        .shadow_fetch_paddr_o(shadow_fetch_paddr),
        .bpu_redirect_valid_o(bpu_redirect_valid),
        .bpu_redirect_target_o(bpu_redirect_target)
    );

    initial begin
        tb_start();
        flush = 0; redirect_inject_valid = 0; redirect_inject_pc = 0; redirect_inject_epoch = 0;
        s1_valid = 0; s3_allowin = 1; s1_pc = 0; s1_epoch = 0; bpu_pc = 0; bpu_valid = 0; bpu_taken = 0; bpu_target = 0; bpu_ras_valid = 0; bpu_ras_target = 0;
        s3_dup_drop = 0;
        csr_crmd = 32'h0000_0010; csr_dmw0 = 0; csr_dmw1 = 0;
        tlb_found = 0; tlb_v = 1; tlb_ppn = 0; tlb_ps = 6'd12; tlb_plv = 0;
        reset_dut();
        s1_pc = 32'h1c001234; s1_epoch = 2'd1; tlb_found = 1'b1; tlb_ppn = 20'h000ab; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 accepts and emits", s2_valid);
        `check32("S2 PC pass-through", s2_pc, 32'h1c001234);
        `check("S2 epoch pass-through", s2_epoch == 2'd1);
        `check32("S2 TLB paddr", paddr, 32'h000ab234);
        `check("S2 aligned PC has no ADEF fault", !tlb_fault);
        `check32("S2 no-fault ecode", {26'd0, fault_ecode}, 32'h0);
        `check("S2 no BPU redirect without prediction", !bpu_redirect_valid);
        tick();

        s1_pc = 32'h1c002000; s1_epoch = 2'd2; bpu_pc = 32'h1c002000; bpu_valid = 1'b1; bpu_taken = 1'b1;
        bpu_target = 32'h1c003000; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 BPU prediction propagates", pred_taken);
        `check("S2 BPU prediction keeps source epoch", s2_epoch == 2'd2);
        `check32("S2 BPU target propagates", pred_target, 32'h1c003000);
        `check("S2 BPU redirect fires on emit", bpu_redirect_valid);
        `check32("S2 BPU redirect target", bpu_redirect_target, 32'h1c003000);
        `check("S2 shadows fall-through when predicting taken", shadow_fetch_valid);
        `check32("S2 taken shadow fall-through paddr", shadow_fetch_paddr, 32'h000ab004);
        s1_pc = 32'h1c003004; s1_epoch = 2'd0;
        s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 injects redirected target without fall-through bubble", s2_valid);
        `check32("S2 redirected target PC", s2_pc, 32'h1c003000);
        `check("S2 BPU injected target keeps epoch", s2_epoch == 2'd2);
        `check("S2 redirected target waits for its own BPU metadata", !pred_taken);
        bpu_pc = 32'h1c003000; bpu_valid = 1'b0; bpu_taken = 1'b0;
        s1_pc = 32'h1c003004; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 accepts sequential PC after injected target", s2_valid);
        `check32("S2 post-target PC", s2_pc, 32'h1c003004);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        s1_pc = 32'h1c002400; s1_epoch = 2'd1; bpu_pc = 32'h1c002400;
        bpu_valid = 1'b1; bpu_taken = 1'b1; bpu_target = 32'h1c002800;
        s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 chained first prediction redirects", bpu_redirect_valid);
        `check32("S2 chained first redirect target", bpu_redirect_target, 32'h1c002800);
        s1_pc = 32'h1c002804; s1_epoch = 2'd0; bpu_pc = 32'h1c002800;
        bpu_valid = 1'b1; bpu_taken = 1'b1; bpu_target = 32'h1c002c00;
        s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 chained injected target consumes its own prediction", pred_taken);
        `check32("S2 chained injected target PC", s2_pc, 32'h1c002800);
        `check("S2 chained second prediction redirects", bpu_redirect_valid);
        `check32("S2 chained second redirect target", bpu_redirect_target, 32'h1c002c00);
        bpu_valid = 1'b0; bpu_taken = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        s3_allowin = 1'b0;
        s1_pc = 32'h1c002500; s1_epoch = 2'd2; bpu_pc = 32'h1c002500;
        bpu_valid = 1'b1; bpu_taken = 1'b1; bpu_target = 32'h1c002900;
        s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 backpressure holds predicted instruction", s2_valid && pred_taken);
        `check("S2 backpressure suppresses BPU redirect until emit", !bpu_redirect_valid);
        tick();
        bpu_valid = 1'b0; bpu_taken = 1'b0; bpu_pc = 32'h1c00ffff; #1;
        `check("S2 backpressure caches matched prediction metadata", pred_taken);
        `check32("S2 backpressure cached target", pred_target, 32'h1c002900);
        s3_allowin = 1'b1; #1;
        `check("S2 cached prediction redirects once downstream reopens", bpu_redirect_valid);
        `check32("S2 cached prediction redirect target", bpu_redirect_target, 32'h1c002900);
        tick();
        #1;
        `check32("S2 cached prediction injects held target", s2_pc, 32'h1c002900);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        s1_pc = 32'h1c002100; bpu_pc = 32'h1c002100; bpu_valid = 1'b1; bpu_taken = 1'b1;
        bpu_target = 32'h1c002104; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 sequential BPU target keeps prediction metadata", pred_taken);
        `check32("S2 sequential BPU target propagates", pred_target, 32'h1c002104);
        `check("S2 sequential BPU target does not redirect", !bpu_redirect_valid);
        `check("S2 suppresses shadow for sequential taken target", !shadow_fetch_valid);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        s3_dup_drop = 1'b1;
        s1_pc = 32'h1c002280; bpu_pc = 32'h1c002280; bpu_valid = 1'b1; bpu_taken = 1'b1;
        bpu_target = 32'h1c003280; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 duplicate-drop sideband keeps prediction metadata", pred_taken);
        `check32("S2 duplicate-drop sideband keeps prediction target", pred_target, 32'h1c003280);
        `check("S2 duplicate-drop sideband suppresses redirect", !bpu_redirect_valid);
        `check("S2 duplicate-drop sideband suppresses shadow fetch", !shadow_fetch_valid);
        s3_dup_drop = 1'b0;

        flush = 1'b1; tick(); flush = 1'b0; #1;
        s1_pc = 32'h1c002200; bpu_pc = 32'h1c002200; bpu_valid = 1'b1; bpu_taken = 1'b0;
        bpu_target = 32'h1c002240; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 shadows branch target when predicting not-taken", shadow_fetch_valid);
        `check32("S2 not-taken shadow target paddr", shadow_fetch_paddr, 32'h000ab240);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        s1_pc = 32'h1c004000; bpu_pc = 32'h1c004000; bpu_valid = 1'b0; bpu_taken = 1'b0;
        bpu_ras_valid = 1'b1; bpu_ras_target = 32'h1c004080; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 RAS valid propagates without BTB taken", ras_valid && !pred_taken);
        `check32("S2 RAS target propagates", ras_target, 32'h1c004080);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        s1_pc = 32'h227f9789; bpu_pc = 32'h227f9789; bpu_valid = 1'b0; bpu_ras_valid = 1'b0;
        tlb_found = 1'b0; s1_valid = 1'b1; tick();
        s1_valid = 1'b0; #1;
        `check("S2 misaligned PC raises ADEF fault sideband", s2_valid && tlb_fault);
        `check32("S2 ADEF ecode", {26'd0, fault_ecode}, {26'd0, `CPU_ECODE_ADEF});
        `check32("S2 ADEF badv is PC", fault_badv, 32'h227f9789);
        `check32("S2 ADEF paddr keeps bad PC", paddr, 32'h227f9789);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        csr_crmd = 32'h0000_0010; csr_dmw0 = 32'h0000_0000; csr_dmw1 = 32'h0000_0000;
        s1_pc = 32'h4000_1000; tlb_found = 1'b0; tlb_v = 1'b1; tlb_plv = 2'd0; tlb_ps = 6'd12;
        s1_valid = 1'b1; tick(); s1_valid = 1'b0; #1;
        `check("S2 missing TLB raises TLBR", s2_valid && tlb_fault);
        `check32("S2 TLBR ecode", {26'd0, fault_ecode}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S2 TLBR badv", fault_badv, 32'h4000_1000);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        tlb_found = 1'b1; tlb_v = 1'b0; tlb_ppn = 20'h12345; s1_pc = 32'h4000_2000;
        s1_valid = 1'b1; tick(); s1_valid = 1'b0; #1;
        `check("S2 invalid instruction page raises PIF", s2_valid && tlb_fault);
        `check32("S2 PIF ecode", {26'd0, fault_ecode}, {26'd0, `CPU_ECODE_PIF});

        flush = 1'b1; tick(); flush = 1'b0; #1;
        csr_crmd = 32'h0000_0013; tlb_found = 1'b1; tlb_v = 1'b1; tlb_plv = 2'd0; s1_pc = 32'h4000_3000;
        s1_valid = 1'b1; tick(); s1_valid = 1'b0; #1;
        `check("S2 PLV violation raises PPI", s2_valid && tlb_fault);
        `check32("S2 PPI ecode", {26'd0, fault_ecode}, {26'd0, `CPU_ECODE_PPI});

        flush = 1'b1; tick(); flush = 1'b0; #1;
        csr_crmd = 32'h0000_0010;
        csr_dmw0 = {3'b100, 1'b0, 3'b001, 19'd0, 2'b00, 1'b0, 2'b00, 1'b1};
        tlb_found = 1'b0; tlb_v = 1'b0; s1_pc = 32'h8000_4568;
        s1_valid = 1'b1; tick(); s1_valid = 1'b0; #1;
        `check("S2 DMW0 suppresses TLB lookup fault", s2_valid && !tlb_fault);
        `check32("S2 DMW0 maps VSEG to PSEG", paddr, 32'h2000_4568);

        flush = 1'b1; redirect_inject_valid = 1'b1;
        redirect_inject_pc = 32'h1c006000;
        redirect_inject_epoch = 2'd3;
        bpu_pc = 32'h1c006000; bpu_valid = 1'b0; bpu_taken = 1'b0;
        tick();
        flush = 1'b0; redirect_inject_valid = 1'b0; #1;
        `check("S2 redirect inject creates valid target", s2_valid);
        `check32("S2 redirect inject target PC", s2_pc, 32'h1c006000);
        `check("S2 redirect inject carries next epoch", s2_epoch == 2'd3);
        `check("S2 redirect inject clears old prediction", !pred_taken && !ras_valid);

        flush = 1'b1; tick(); flush = 1'b0; #1;
        `check("S2 flush clears valid", !s2_valid);
        finish_tb();
    end
endmodule

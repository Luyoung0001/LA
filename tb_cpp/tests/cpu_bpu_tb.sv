`timescale 1ns / 1ps

module cpu_bpu_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    localparam [31:0] PC_INIT      = 32'h8000_0000;
    localparam [31:0] PC_GSHARE    = 32'h8000_0040;
    localparam [31:0] PC_DIRECT    = 32'h8000_0104;
    localparam [31:0] PC_CALL      = 32'h8000_0208;
    localparam [31:0] PC_RET       = 32'h8000_030c;
    localparam [31:0] PC_INDIRECT  = 32'h8000_0410;
    localparam [31:0] PC_COND      = 32'h8000_0520;
    localparam [31:0] PC_ALIAS_A   = 32'h8000_0600;
    localparam [31:0] PC_ALIAS_B   = 32'h8000_0640; // same BTB index as A when BTB_INDEX_WIDTH=4
    localparam [31:0] PC_MIX0      = 32'h8000_0714;
    localparam [31:0] PC_MIX1      = 32'h8000_0818;
    localparam [31:0] PC_MIX2      = 32'h8000_091c;
    localparam [31:0] PC_MIX_RET   = 32'h8000_0a20;
    localparam [31:0] PC_LAT_A     = 32'h8000_0b24;
    localparam [31:0] PC_LAT_B     = 32'h8000_0b28;
    localparam [31:0] PC_LAT_C     = 32'h8000_0b2c;

    logic [31:0] lookup_pc;
    logic [31:0] update_pc;
    logic [31:0] update_target;
    logic        update_valid;
    logic        update_taken;
    logic        update_call;
    logic        update_ret;
    logic        update_jmp;
    logic        update_indirect;
    logic        ras_update_valid;
    logic [31:0] ras_update_pc;
    logic        ras_update_call;
    logic        ras_update_ret;

    logic [31:0] main_target;
    logic [31:0] main_ras_target;
    logic        main_valid;
    logic        main_taken;
    logic        main_call;
    logic        main_ret;
    logic        main_indirect;
    logic        main_ras_valid;

    logic [31:0] cond_off_target;
    logic [31:0] cond_off_ras_target;
    logic        cond_off_valid;
    logic        cond_off_taken;
    logic        cond_off_call;
    logic        cond_off_ret;
    logic        cond_off_indirect;
    logic        cond_off_ras_valid;

    logic [31:0] indirect_off_target;
    logic [31:0] indirect_off_ras_target;
    logic        indirect_off_valid;
    logic        indirect_off_taken;
    logic        indirect_off_call;
    logic        indirect_off_ret;
    logic        indirect_off_indirect;
    logic        indirect_off_ras_valid;

    logic [31:0] local_target;
    logic [31:0] local_ras_target;
    logic        local_valid;
    logic        local_taken;
    logic        local_call;
    logic        local_ret;
    logic        local_indirect;
    logic        local_ras_valid;

    integer cov_initial;
    integer cov_direct;
    integer cov_call;
    integer cov_ret;
    integer cov_indirect;
    integer cov_indirect_gate;
    integer cov_cond_gate;
    integer cov_cond_taken;
    integer cov_cond_hysteresis;
    integer cov_gshare_history;
    integer cov_ras_push_pop;
    integer cov_ras_empty;
    integer cov_ras_wrap;
    integer cov_ras_priority;
    integer cov_alias;
    integer cov_type_overwrite;
    integer cov_mixed;
    integer cov_lookup_latency;
    integer cov_registered_update;

    cpu_bpu #(
        .BTB_INDEX_WIDTH(4), .PHT_INDEX_WIDTH(4), .RAS_INDEX_WIDTH(2)
    ) u_main (
        .clk(clk), .rst_n(rst_n),
        .lookup_pc_i(lookup_pc),
        .pred_valid_o(main_valid),
        .pred_taken_o(main_taken),
        .pred_target_o(main_target),
        .pred_is_call_o(main_call),
        .pred_is_ret_o(main_ret),
        .pred_is_indirect_jmp_o(main_indirect),
        .pred_ras_valid_o(main_ras_valid),
        .pred_ras_target_o(main_ras_target),
        .update_valid_i(update_valid),
        .update_pc_i(update_pc),
        .update_taken_i(update_taken),
        .update_target_i(update_target),
        .update_is_call_i(update_call),
        .update_is_ret_i(update_ret),
        .update_is_jmp_i(update_jmp),
        .update_is_indirect_jmp_i(update_indirect),
        .ras_update_valid_i(ras_update_valid),
        .ras_update_pc_i(ras_update_pc),
        .ras_update_is_call_i(ras_update_call),
        .ras_update_is_ret_i(ras_update_ret)
    );

    cpu_bpu #(
        .BTB_INDEX_WIDTH(4), .PHT_INDEX_WIDTH(4), .RAS_INDEX_WIDTH(2),
        .COND_PREDICT_ENABLE(0)
    ) u_cond_off (
        .clk(clk), .rst_n(rst_n),
        .lookup_pc_i(lookup_pc),
        .pred_valid_o(cond_off_valid),
        .pred_taken_o(cond_off_taken),
        .pred_target_o(cond_off_target),
        .pred_is_call_o(cond_off_call),
        .pred_is_ret_o(cond_off_ret),
        .pred_is_indirect_jmp_o(cond_off_indirect),
        .pred_ras_valid_o(cond_off_ras_valid),
        .pred_ras_target_o(cond_off_ras_target),
        .update_valid_i(update_valid),
        .update_pc_i(update_pc),
        .update_taken_i(update_taken),
        .update_target_i(update_target),
        .update_is_call_i(update_call),
        .update_is_ret_i(update_ret),
        .update_is_jmp_i(update_jmp),
        .update_is_indirect_jmp_i(update_indirect),
        .ras_update_valid_i(ras_update_valid),
        .ras_update_pc_i(ras_update_pc),
        .ras_update_is_call_i(ras_update_call),
        .ras_update_is_ret_i(ras_update_ret)
    );

    cpu_bpu #(
        .BTB_INDEX_WIDTH(4), .PHT_INDEX_WIDTH(4), .RAS_INDEX_WIDTH(2),
        .INDIRECT_PREDICT_ENABLE(0)
    ) u_indirect_off (
        .clk(clk), .rst_n(rst_n),
        .lookup_pc_i(lookup_pc),
        .pred_valid_o(indirect_off_valid),
        .pred_taken_o(indirect_off_taken),
        .pred_target_o(indirect_off_target),
        .pred_is_call_o(indirect_off_call),
        .pred_is_ret_o(indirect_off_ret),
        .pred_is_indirect_jmp_o(indirect_off_indirect),
        .pred_ras_valid_o(indirect_off_ras_valid),
        .pred_ras_target_o(indirect_off_ras_target),
        .update_valid_i(update_valid),
        .update_pc_i(update_pc),
        .update_taken_i(update_taken),
        .update_target_i(update_target),
        .update_is_call_i(update_call),
        .update_is_ret_i(update_ret),
        .update_is_jmp_i(update_jmp),
        .update_is_indirect_jmp_i(update_indirect),
        .ras_update_valid_i(ras_update_valid),
        .ras_update_pc_i(ras_update_pc),
        .ras_update_is_call_i(ras_update_call),
        .ras_update_is_ret_i(ras_update_ret)
    );

    cpu_bpu #(
        .BTB_INDEX_WIDTH(4), .PHT_INDEX_WIDTH(4), .RAS_INDEX_WIDTH(2),
        .GSHARE_ENABLE(0), .COND_PREDICT_ENABLE(1)
    ) u_local (
        .clk(clk), .rst_n(rst_n),
        .lookup_pc_i(lookup_pc),
        .pred_valid_o(local_valid),
        .pred_taken_o(local_taken),
        .pred_target_o(local_target),
        .pred_is_call_o(local_call),
        .pred_is_ret_o(local_ret),
        .pred_is_indirect_jmp_o(local_indirect),
        .pred_ras_valid_o(local_ras_valid),
        .pred_ras_target_o(local_ras_target),
        .update_valid_i(update_valid),
        .update_pc_i(update_pc),
        .update_taken_i(update_taken),
        .update_target_i(update_target),
        .update_is_call_i(update_call),
        .update_is_ret_i(update_ret),
        .update_is_jmp_i(update_jmp),
        .update_is_indirect_jmp_i(update_indirect),
        .ras_update_valid_i(ras_update_valid),
        .ras_update_pc_i(ras_update_pc),
        .ras_update_is_call_i(ras_update_call),
        .ras_update_is_ret_i(ras_update_ret)
    );

    task automatic init_inputs;
        begin
            lookup_pc = 32'h0;
            update_valid = 1'b0;
            update_pc = 32'h0;
            update_taken = 1'b0;
            update_target = 32'h0;
            update_call = 1'b0;
            update_ret = 1'b0;
            update_jmp = 1'b0;
            update_indirect = 1'b0;
            ras_update_valid = 1'b0;
            ras_update_pc = 32'h0;
            ras_update_call = 1'b0;
            ras_update_ret = 1'b0;
        end
    endtask

    task automatic init_coverage;
        begin
            cov_initial = 0;
            cov_direct = 0;
            cov_call = 0;
            cov_ret = 0;
            cov_indirect = 0;
            cov_indirect_gate = 0;
            cov_cond_gate = 0;
            cov_cond_taken = 0;
            cov_cond_hysteresis = 0;
            cov_gshare_history = 0;
            cov_ras_push_pop = 0;
            cov_ras_empty = 0;
            cov_ras_wrap = 0;
            cov_ras_priority = 0;
            cov_alias = 0;
            cov_type_overwrite = 0;
            cov_mixed = 0;
            cov_lookup_latency = 0;
            cov_registered_update = 0;
        end
    endtask

    task automatic banner(input string name);
        begin
            $display("");
            $display("[SCENARIO] %s", name);
            `tb_event($sformatf("SCENARIO %s", name));
        end
    endtask

    task automatic do_update(
        input [31:0] pc,
        input [31:0] target,
        input bit taken,
        input bit call_type,
        input bit ret_type,
        input bit direct_type,
        input bit indirect_type
    );
        begin
            $display("[BPU-TB][UPDATE] pc=0x%08x target=0x%08x taken=%0d call=%0d ret=%0d direct=%0d indirect=%0d",
                     pc, target, taken, call_type, ret_type, direct_type, indirect_type);
            `tb_event($sformatf("UPDATE pc=0x%08x target=0x%08x taken=%0d call=%0d ret=%0d direct=%0d indirect=%0d",
                                pc, target, taken, call_type, ret_type, direct_type, indirect_type));
            update_valid = 1'b1;
            update_pc = pc;
            update_taken = taken;
            update_target = target;
            update_call = call_type;
            update_ret = ret_type;
            update_jmp = direct_type;
            update_indirect = indirect_type;
            tick();
            update_valid = 1'b0;
            update_pc = 32'h0;
            update_taken = 1'b0;
            update_target = 32'h0;
            update_call = 1'b0;
            update_ret = 1'b0;
            update_jmp = 1'b0;
            update_indirect = 1'b0;
            tick();
        end
    endtask

    task automatic do_lookup(input [31:0] pc);
        begin
            $display("[BPU-TB][LOOKUP] pc=0x%08x", pc);
            `tb_event($sformatf("LOOKUP pc=0x%08x", pc));
            lookup_pc = pc;
            repeat (3) tick();
        end
    endtask

    task automatic do_ras_update(input [31:0] pc, input bit call_type, input bit ret_type);
        begin
            $display("[BPU-TB][RAS] pc=0x%08x call=%0d ret=%0d", pc, call_type, ret_type);
            `tb_event($sformatf("RAS pc=0x%08x call=%0d ret=%0d", pc, call_type, ret_type));
            ras_update_valid = 1'b1;
            ras_update_pc = pc;
            ras_update_call = call_type;
            ras_update_ret = ret_type;
            tick();
            ras_update_valid = 1'b0;
            ras_update_pc = 32'h0;
            ras_update_call = 1'b0;
            ras_update_ret = 1'b0;
            tick();
        end
    endtask

    task automatic expect_main(
        input string name,
        input bit exp_valid,
        input bit exp_taken,
        input [31:0] exp_target,
        input bit exp_call,
        input bit exp_ret,
        input bit exp_indirect
    );
        begin
            `check($sformatf("%s main valid", name), main_valid === exp_valid);
            `check($sformatf("%s main taken", name), main_taken === exp_taken);
            `check($sformatf("%s main call", name), main_call === exp_call);
            `check($sformatf("%s main ret", name), main_ret === exp_ret);
            `check($sformatf("%s main indirect", name), main_indirect === exp_indirect);
            if (exp_valid)
                `check32($sformatf("%s main target", name), main_target, exp_target);
        end
    endtask

    task automatic expect_local_cond(
        input string name,
        input bit exp_taken,
        input [31:0] exp_target
    );
        begin
            `check($sformatf("%s local valid", name), local_valid);
            `check($sformatf("%s local taken", name), local_taken === exp_taken);
            `check($sformatf("%s local conditional type", name),
                   !local_call && !local_ret && !local_indirect);
            `check32($sformatf("%s local target", name), local_target, exp_target);
        end
    endtask

    task automatic check_coverage;
        begin
            banner("functional coverage summary");
            `check("coverage initial miss", cov_initial);
            `check("coverage direct jump", cov_direct);
            `check("coverage call type", cov_call);
            `check("coverage ret type", cov_ret);
            `check("coverage indirect JIRL", cov_indirect);
            `check("coverage indirect gate", cov_indirect_gate);
            `check("coverage conditional gate", cov_cond_gate);
            `check("coverage conditional taken", cov_cond_taken);
            `check("coverage conditional hysteresis", cov_cond_hysteresis);
            `check("coverage gshare history", cov_gshare_history);
            `check("coverage RAS push/pop", cov_ras_push_pop);
            `check("coverage RAS empty pop", cov_ras_empty);
            `check("coverage RAS wrap", cov_ras_wrap);
            `check("coverage RAS priority over BTB", cov_ras_priority);
            `check("coverage BTB alias/tag", cov_alias);
            `check("coverage type overwrite", cov_type_overwrite);
            `check("coverage mixed stream", cov_mixed);
            `check("coverage registered lookup latency", cov_lookup_latency);
            `check("coverage registered update latency", cov_registered_update);
        end
    endtask

    initial begin
        tb_start();
        init_inputs();
        init_coverage();
        reset_dut();

        banner("initial lookup and gshare/local contrast");
        do_lookup(PC_INIT);
        expect_main("cold miss", 1'b0, 1'b0, 32'h0, 1'b0, 1'b0, 1'b0);
        `check("cold miss cond_off invalid", !cond_off_valid);
        `check("cold miss indirect_off invalid", !indirect_off_valid);
        `check("cold miss local invalid", !local_valid);
        cov_initial = 1;

        banner("registered lookup and update timing contract");
        do_update(PC_LAT_A, 32'h9000_0b24, 1'b1, 1'b0, 1'b0, 1'b1, 1'b0);
        lookup_pc = PC_LAT_A;
        #1;
        `check("lookup has no current-cycle combinational result", !main_valid);
        tick();
        expect_main("lookup result appears after one clock", 1'b1, 1'b1, 32'h9000_0b24,
                    1'b0, 1'b0, 1'b0);
        lookup_pc = PC_LAT_B;
        #1;
        expect_main("lookup output is held until next clock", 1'b1, 1'b1, 32'h9000_0b24,
                    1'b0, 1'b0, 1'b0);
        tick();
        expect_main("lookup switched PC miss appears after one clock", 1'b0, 1'b0, 32'h0,
                    1'b0, 1'b0, 1'b0);
        cov_lookup_latency = 1;

        init_inputs();
        reset_dut();
        lookup_pc = PC_LAT_C;
        update_valid = 1'b1;
        update_pc = PC_LAT_C;
        update_target = 32'h9000_0b2c;
        update_taken = 1'b1;
        update_call = 1'b0;
        update_ret = 1'b0;
        update_jmp = 1'b1;
        update_indirect = 1'b0;
        #1;
        `check("same-cycle update has no combinational prediction", !main_valid);
        tick();
        `check("same-cycle update is not visible on write edge", !main_valid);
        update_valid = 1'b0;
        update_pc = 32'h0;
        update_target = 32'h0;
        update_taken = 1'b0;
        update_jmp = 1'b0;
        tick();
        expect_main("registered update visible on following lookup cycle", 1'b1, 1'b1,
                    32'h9000_0b2c, 1'b0, 1'b0, 1'b0);
        cov_registered_update = 1;

        init_inputs();
        reset_dut();
        do_update(PC_GSHARE, 32'h9000_0040, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_GSHARE);
        `check("gshare trained branch BTB hit", main_valid);
        `check("gshare history changes selected PHT entry", !main_taken);
        expect_local_cond("local PHT after one taken", 1'b1, 32'h9000_0040);
        cov_gshare_history = 1;

        banner("BTB type encoding and parameter gates");
        do_update(PC_DIRECT, 32'h9000_0104, 1'b1, 1'b0, 1'b0, 1'b1, 1'b0);
        do_lookup(PC_DIRECT);
        expect_main("direct jump", 1'b1, 1'b1, 32'h9000_0104, 1'b0, 1'b0, 1'b0);
        `check("direct jump cond_off still taken", cond_off_valid && cond_off_taken);
        `check("direct jump indirect_off still taken", indirect_off_valid && indirect_off_taken);
        cov_direct = 1;

        do_update(PC_CALL, 32'h9000_0208, 1'b1, 1'b1, 1'b0, 1'b1, 1'b0);
        do_lookup(PC_CALL);
        expect_main("call jump", 1'b1, 1'b1, 32'h9000_0208, 1'b1, 1'b0, 1'b0);
        cov_call = 1;

        do_update(PC_RET, 32'hdead_030c, 1'b1, 1'b0, 1'b1, 1'b0, 1'b0);
        do_lookup(PC_RET);
        expect_main("ret with empty RAS uses BTB target", 1'b1, 1'b1, 32'hdead_030c, 1'b0, 1'b1, 1'b0);
        cov_ret = 1;

        do_ras_update(32'h8123_0000, 1'b1, 1'b0);
        do_lookup(PC_RET);
        expect_main("ret with RAS overrides BTB target", 1'b1, 1'b1, 32'h8123_0004, 1'b0, 1'b1, 1'b0);
        `check("ret lookup exposes RAS valid", main_ras_valid);
        `check32("ret lookup RAS target", main_ras_target, 32'h8123_0004);
        cov_ras_priority = 1;

        do_update(PC_INDIRECT, 32'h9000_0410, 1'b1, 1'b0, 1'b0, 1'b0, 1'b1);
        do_lookup(PC_INDIRECT);
        expect_main("indirect JIRL", 1'b1, 1'b1, 32'h9000_0410, 1'b0, 1'b0, 1'b1);
        `check("indirect JIRL cond_off still taken",
               cond_off_valid && cond_off_taken && cond_off_indirect);
        `check("indirect JIRL indirect_off records type but does not take",
               indirect_off_valid && !indirect_off_taken && indirect_off_indirect);
        `check32("indirect_off records target", indirect_off_target, 32'h9000_0410);
        cov_indirect = 1;
        cov_indirect_gate = 1;

        banner("conditional PHT gate and 2-bit hysteresis");
        do_update(PC_COND, 32'h9000_0520, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_COND);
        expect_local_cond("local conditional after not-taken", 1'b0, 32'h9000_0520);
        `check("COND_PREDICT_ENABLE=0 blocks conditional taken", cond_off_valid && !cond_off_taken);
        cov_cond_gate = 1;

        do_update(PC_COND, 32'h9000_0520, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_COND);
        expect_local_cond("local conditional first taken below threshold", 1'b0, 32'h9000_0520);

        do_update(PC_COND, 32'h9000_0520, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_COND);
        expect_local_cond("local conditional second taken reaches threshold", 1'b1, 32'h9000_0520);
        `check("COND_PREDICT_ENABLE=0 still blocks trained conditional",
               cond_off_valid && !cond_off_taken);
        cov_cond_taken = 1;

        do_update(PC_COND, 32'h9000_0520, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_COND);
        expect_local_cond("local conditional saturated taken", 1'b1, 32'h9000_0520);

        do_update(PC_COND, 32'h9000_0520, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_COND);
        expect_local_cond("local conditional one miss keeps weak taken", 1'b1, 32'h9000_0520);

        do_update(PC_COND, 32'h9000_0520, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_COND);
        expect_local_cond("local conditional second miss drops not-taken", 1'b0, 32'h9000_0520);
        cov_cond_hysteresis = 1;

        banner("RAS empty pop, push/pop stack, and wrap");
        init_inputs();
        reset_dut();
        do_ras_update(32'h8100_0000, 1'b0, 1'b1);
        `check("empty RAS pop keeps invalid", !main_ras_valid);
        cov_ras_empty = 1;

        do_ras_update(32'h8100_1000, 1'b1, 1'b0);
        `check("RAS first push valid", main_ras_valid);
        `check32("RAS first push target", main_ras_target, 32'h8100_1004);
        do_ras_update(32'h8100_2000, 1'b1, 1'b0);
        `check32("RAS second push target", main_ras_target, 32'h8100_2004);
        do_ras_update(32'h0, 1'b0, 1'b1);
        `check32("RAS pop returns to first target", main_ras_target, 32'h8100_1004);
        do_ras_update(32'h0, 1'b0, 1'b1);
        `check("RAS second pop clears top", !main_ras_valid);
        cov_ras_push_pop = 1;

        init_inputs();
        reset_dut();
        do_ras_update(32'h8100_3000, 1'b1, 1'b0);
        do_ras_update(32'h8100_4000, 1'b1, 1'b0);
        do_ras_update(32'h8100_5000, 1'b1, 1'b0);
        do_ras_update(32'h8100_6000, 1'b1, 1'b0);
        do_ras_update(32'h8100_7000, 1'b1, 1'b0);
        `check32("RAS wraps and keeps newest target", main_ras_target, 32'h8100_7004);
        do_ras_update(32'h0, 1'b0, 1'b1);
        `check32("RAS wrap pop exposes previous wrapped target", main_ras_target, 32'h8100_6004);
        cov_ras_wrap = 1;

        banner("BTB alias, tag check, and type overwrite");
        do_update(PC_ALIAS_A, 32'h9000_0600, 1'b1, 1'b0, 1'b0, 1'b1, 1'b0);
        do_lookup(PC_ALIAS_A);
        expect_main("alias A before conflict", 1'b1, 1'b1, 32'h9000_0600, 1'b0, 1'b0, 1'b0);
        do_update(PC_ALIAS_B, 32'h9000_0640, 1'b1, 1'b0, 1'b0, 1'b0, 1'b1);
        do_lookup(PC_ALIAS_B);
        expect_main("alias B overwrites same index", 1'b1, 1'b1, 32'h9000_0640, 1'b0, 1'b0, 1'b1);
        do_lookup(PC_ALIAS_A);
        expect_main("alias A tag mismatch after overwrite", 1'b0, 1'b0, 32'h0, 1'b0, 1'b0, 1'b0);
        cov_alias = 1;

        do_update(PC_ALIAS_B, 32'h9000_0660, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        do_lookup(PC_ALIAS_B);
        `check("type overwrite clears indirect bit", cond_off_valid && !cond_off_indirect);
        `check("type overwrite makes conditional not taken when gated", cond_off_valid && !cond_off_taken);
        `check32("type overwrite target", cond_off_target, 32'h9000_0660);
        cov_type_overwrite = 1;

        banner("mixed control-flow stream");
        do_update(PC_MIX0, 32'h9000_0714, 1'b1, 1'b0, 1'b0, 1'b1, 1'b0);
        do_lookup(PC_MIX0);
        expect_main("mixed direct", 1'b1, 1'b1, 32'h9000_0714, 1'b0, 1'b0, 1'b0);
        do_update(PC_MIX1, 32'h9000_0818, 1'b1, 1'b1, 1'b0, 1'b1, 1'b0);
        do_lookup(PC_MIX1);
        expect_main("mixed call", 1'b1, 1'b1, 32'h9000_0818, 1'b1, 1'b0, 1'b0);
        do_update(PC_MIX2, 32'h9000_091c, 1'b1, 1'b0, 1'b0, 1'b0, 1'b1);
        do_lookup(PC_MIX2);
        expect_main("mixed indirect", 1'b1, 1'b1, 32'h9000_091c, 1'b0, 1'b0, 1'b1);
        init_inputs();
        reset_dut();
        do_ras_update(32'h8100_8000, 1'b1, 1'b0);
        do_update(PC_MIX_RET, 32'h9000_0a20, 1'b1, 1'b0, 1'b1, 1'b0, 1'b0);
        do_lookup(PC_MIX_RET);
        expect_main("mixed ret RAS", 1'b1, 1'b1, 32'h8100_8004, 1'b0, 1'b1, 1'b0);
        cov_mixed = 1;

        check_coverage();
        finish_tb();
    end
endmodule

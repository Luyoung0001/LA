`ifndef TB_COMMON_SVH
`define TB_COMMON_SVH

localparam integer TB_TRACE_DEPTH = 512;
integer tb_cycle;
integer tb_trace_head;
integer tb_trace_count;
integer tb_debug_window;
string tb_trace_ring [0:TB_TRACE_DEPTH-1];

task automatic tb_record;
    input string msg;
    begin
        tb_trace_ring[tb_trace_head] = $sformatf("cycle=%0d time=%0t %s", tb_cycle, $time, msg);
        tb_trace_head = (tb_trace_head + 1) % TB_TRACE_DEPTH;
        if (tb_trace_count < TB_TRACE_DEPTH)
            tb_trace_count = tb_trace_count + 1;
    end
endtask

task automatic tb_dump_trace_window;
    integer i;
    integer n;
    integer idx;
    begin
        n = tb_debug_window;
        if (n <= 0 || n > TB_TRACE_DEPTH)
            n = TB_TRACE_DEPTH;
        if (n > tb_trace_count)
            n = tb_trace_count;

        $display("[TRACE-DUMP] last %0d/%0d testbench events", n, tb_trace_count);
        for (i = n; i > 0; i = i - 1) begin
            idx = tb_trace_head - i;
            if (idx < 0)
                idx = idx + TB_TRACE_DEPTH;
            $display("       %s", tb_trace_ring[idx]);
        end
    end
endtask

task automatic tb_start;
    string wave_path;
    begin
        clk = 1'b0;
        checks = 0;
        failures = 0;
        tb_cycle = 0;
        tb_trace_head = 0;
        tb_trace_count = 0;
        tb_debug_window = 256;
        if (!$value$plusargs("DEBUG_WINDOW=%d", tb_debug_window))
            tb_debug_window = 256;
        if ($value$plusargs("WAVE=%s", wave_path)) begin
            $dumpfile(wave_path);
            $dumpvars(0);
            $display("[WAVE] %s", wave_path);
        end
        $display("[TB] start case=%m cycle=%0d time=%0t debug_window=%0d", tb_cycle, $time, tb_debug_window);
        tb_record($sformatf("TB_START case=%m debug_window=%0d", tb_debug_window));
    end
endtask

task automatic tick;
    begin
        #1 clk = 1'b0;
        #1 clk = 1'b1;
        tb_cycle = tb_cycle + 1;
        #1 clk = 1'b0;
        #1;
    end
endtask

task automatic reset_dut;
    begin
        tb_record("RESET assert rst_n=0");
        rst_n = 1'b0;
        repeat (3) tick();
        rst_n = 1'b1;
        tb_record("RESET deassert rst_n=1");
        repeat (2) tick();
    end
endtask

task automatic check_impl(
    input string name,
    input bit cond,
    input string cond_expr,
    input string file_name,
    input integer line_no
);
    begin
        checks = checks + 1;
        if (!cond) begin
            failures = failures + 1;
            tb_record($sformatf("CHECK_FAIL name=\"%s\" expr=\"%s\" actual=%0d", name, cond_expr, cond));
            $display("[FAIL] %s", name);
        end else begin
            tb_record($sformatf("CHECK_PASS name=\"%s\" expr=\"%s\" actual=%0d", name, cond_expr, cond));
            $display("[PASS] %s", name);
        end
        $display("       source=%s:%0d", file_name, line_no);
        $display("       cycle=%0d time=%0t", tb_cycle, $time);
        $display("       expect: condition is true");
        $display("       actual: condition \"%s\" -> %0d", cond_expr, cond);
        $display("       result: %s", cond ? "MATCH" : "MISMATCH");
        if (!cond)
            tb_dump_trace_window();
    end
endtask

task automatic check32_impl(
    input string name,
    input [31:0] got,
    input [31:0] exp,
    input string got_expr,
    input string exp_expr,
    input string file_name,
    input integer line_no
);
    bit pass;
    begin
        pass = got === exp;
        checks = checks + 1;
        if (!pass) begin
            failures = failures + 1;
            tb_record($sformatf("CHECK32_FAIL name=\"%s\" got_expr=\"%s\" got=0x%08x exp_expr=\"%s\" exp=0x%08x",
                                name, got_expr, got, exp_expr, exp));
            $display("[FAIL] %s", name);
        end else begin
            tb_record($sformatf("CHECK32_PASS name=\"%s\" got_expr=\"%s\" got=0x%08x exp_expr=\"%s\" exp=0x%08x",
                                name, got_expr, got, exp_expr, exp));
            $display("[PASS] %s", name);
        end
        $display("       source=%s:%0d", file_name, line_no);
        $display("       cycle=%0d time=%0t", tb_cycle, $time);
        $display("       expect: %s = 0x%08x", exp_expr, exp);
        $display("       actual: %s = 0x%08x", got_expr, got);
        $display("       result: %s", pass ? "MATCH" : "MISMATCH");
        if (!pass)
            tb_dump_trace_window();
    end
endtask

task automatic wait_signal_impl(
    input string name,
    input integer max_cycles,
    ref logic sig,
    input string sig_expr,
    input string file_name,
    input integer line_no
);
    integer i;
    bit seen;
    begin
        tb_record($sformatf("WAIT_START name=\"%s\" signal=\"%s\" max_cycles=%0d initial=%0d",
                            name, sig_expr, max_cycles, sig));
        seen = sig;
        for (i = 0; i < max_cycles && !seen; i = i + 1) begin
            tick();
            seen = sig;
        end
        checks = checks + 1;
        if (!seen) begin
            failures = failures + 1;
            tb_record($sformatf("WAIT_FAIL name=\"%s\" signal=\"%s\" waited=%0d final=%0d",
                                name, sig_expr, i, seen));
            $display("[FAIL] %s", name);
        end else begin
            tb_record($sformatf("WAIT_PASS name=\"%s\" signal=\"%s\" waited=%0d final=%0d",
                                name, sig_expr, i, seen));
            $display("[PASS] %s", name);
        end
        $display("       source=%s:%0d", file_name, line_no);
        $display("       cycle=%0d time=%0t", tb_cycle, $time);
        $display("       expect: %s becomes true within %0d cycles", sig_expr, max_cycles);
        $display("       actual: %s=%0d after %0d cycles", sig_expr, seen, i);
        $display("       result: %s", seen ? "MATCH" : "MISMATCH");
        if (!seen)
            tb_dump_trace_window();
    end
endtask

task automatic finish_tb;
    begin
        tb_record($sformatf("TB_FINISH checks=%0d failures=%0d", checks, failures));
        $display("[SUMMARY] checks=%0d failures=%0d cycle=%0d time=%0t", checks, failures, tb_cycle, $time);
        $dumpflush;
        if (failures != 0) begin
            tb_dump_trace_window();
            $fatal(1, "test failed");
        end
        $finish;
    end
endtask

`define check(NAME, COND) \
    check_impl(NAME, COND, `"COND`", `__FILE__, `__LINE__)

`define check32(NAME, GOT, EXP) \
    check32_impl(NAME, GOT, EXP, `"GOT`", `"EXP`", `__FILE__, `__LINE__)

`define wait_signal(NAME, MAX_CYCLES, SIG) \
    wait_signal_impl(NAME, MAX_CYCLES, SIG, `"SIG`", `__FILE__, `__LINE__)

`define tb_event(MSG) \
    tb_record(MSG)

`endif

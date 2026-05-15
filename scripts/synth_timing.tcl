################################################################################
# LA CPU timing analysis script
#
# Target: xc7a200tfbg676-1 (default, configurable)
# Mode:   Out-of-Context synthesis + implementation
#
# Usage:
#   vivado -mode batch -source scripts/synth_timing.tcl
#   vivado -mode batch -source scripts/synth_timing.tcl -tclargs -freq 150
#
# Outputs (in ./vivado_timing/):
#   timing_summary.rpt   post-route timing summary
#   utilization.rpt      resource utilization
#   critical_path.rpt    worst setup paths
#   timing_summary.txt   human-readable frequency estimate
################################################################################

#==============================================================================
# Configuration
#==============================================================================

set script_dir  [file dirname [info script]]
set repo_root   [file normalize "$script_dir/.."]
set rtl_dir     [file normalize "$repo_root/rtl"]
set project_dir [file normalize "$repo_root/vivado_timing"]
set output_dir  $project_dir

set fpga_part    "xc7a200tfbg676-1"
set project_name "la_cpu_timing"
set top_module   "core_top"
set synth_top    "timing_wrapper"
set num_jobs     8
set cfg_tlb_enable 0
set cfg_l1i_enable 0
set cfg_l1d_enable 0
set cfg_l2_enable 0
set cfg_bpu_enable 0
set cfg_fetch_buffer_enable 0
set cfg_itcm_enable 0
set cfg_cache_op_strict_enable 0
set cfg_l2_prefetch_enable 1
set cfg_perf_moni_enable 0

# Target clock frequency in MHz (used for constraint, not hard limit)
set target_freq_mhz 100.0
set target_period_ns [expr {1000.0 / $target_freq_mhz}]

proc normalize_bool_arg {name value} {
    set lower_value [string tolower $value]
    switch -exact -- $lower_value {
        "1" - "true" - "yes" - "on" {
            return 1
        }
        "0" - "false" - "no" - "off" {
            return 0
        }
        default {
            puts "ERROR: $name expects 0/1, true/false, yes/no, or on/off; got '$value'"
            exit 1
        }
    }
}

# Parse command line args
if {[info exists argc]} {
    for {set i 0} {$i < $argc} {incr i} {
        set arg [lindex $argv $i]
        switch -exact -- $arg {
            "-freq" {
                incr i
                set target_freq_mhz [lindex $argv $i]
                set target_period_ns [expr {1000.0 / double($target_freq_mhz)}]
            }
            "-jobs" {
                incr i
                set num_jobs [lindex $argv $i]
            }
            "-part" {
                incr i
                set fpga_part [lindex $argv $i]
            }
            "-top" {
                incr i
                set top_module [lindex $argv $i]
            }
            "-tlb" {
                incr i
                set cfg_tlb_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-l1i" {
                incr i
                set cfg_l1i_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-l1d" {
                incr i
                set cfg_l1d_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-l2" {
                incr i
                set cfg_l2_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-bpu" {
                incr i
                set cfg_bpu_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-fetch-buffer" {
                incr i
                set cfg_fetch_buffer_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-itcm" {
                incr i
                set cfg_itcm_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-cache-op-strict" {
                incr i
                set cfg_cache_op_strict_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-l2-prefetch" {
                incr i
                set cfg_l2_prefetch_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            "-perf-moni" {
                incr i
                set cfg_perf_moni_enable [normalize_bool_arg $arg [lindex $argv $i]]
            }
            default {
                # Ignore unknown args for forward compatibility
            }
        }
    }
}

set verilog_defines [list \
    "LA_TLB_ENABLE=$cfg_tlb_enable" \
    "LA_L1I_ENABLE=$cfg_l1i_enable" \
    "LA_L1D_ENABLE=$cfg_l1d_enable" \
    "LA_L2_ENABLE=$cfg_l2_enable" \
    "LA_BPU_ENABLE=$cfg_bpu_enable" \
    "LA_FETCH_BUFFER_ENABLE=$cfg_fetch_buffer_enable" \
    "LA_ITCM_ENABLE=$cfg_itcm_enable" \
    "LA_CACHE_OP_STRICT_ENABLE=$cfg_cache_op_strict_enable" \
]

if {!$cfg_l2_prefetch_enable} {
    lappend verilog_defines "CPU_DISABLE_L2_PREFETCH"
}

if {$cfg_perf_moni_enable} {
    lappend verilog_defines "PERF_MONI"
}

puts "=============================================="
puts " LA CPU Timing Analysis"
puts "=============================================="
puts " FPGA Part   : $fpga_part"
puts " DUT Top     : $top_module"
puts " Synth Top   : $synth_top"
puts " Target Freq : ${target_freq_mhz} MHz (period = [format %.3f $target_period_ns] ns)"
puts " RTL Dir     : $rtl_dir"
puts " Output Dir  : $output_dir"
puts " Config      : TLB=$cfg_tlb_enable L1I=$cfg_l1i_enable L1D=$cfg_l1d_enable L2=$cfg_l2_enable BPU=$cfg_bpu_enable FBUF=$cfg_fetch_buffer_enable ITCM=$cfg_itcm_enable STRICT_CACOP=$cfg_cache_op_strict_enable L2_PREFETCH=$cfg_l2_prefetch_enable PERF_MONI=$cfg_perf_moni_enable"
puts "=============================================="

#==============================================================================
# Discover source files
#==============================================================================

set all_rtl_sources [lsort [glob -nocomplain "$rtl_dir/*.v"]]
set rtl_sources [list]

foreach src $all_rtl_sources {
    set name [file tail $src]
    # Simulation-only wrappers; exclude from synthesis flow.
    if {($name eq "verilator_top.v") || ($name eq "verilator_top_la500.v")} {
        continue
    }
    lappend rtl_sources $src
}

if {[llength $rtl_sources] == 0} {
    puts "ERROR: no RTL source files found under $rtl_dir"
    exit 1
}

#==============================================================================
# Create project
#==============================================================================

file mkdir $output_dir
create_project $project_name $project_dir -part $fpga_part -force
set_property target_language Verilog [current_project]

#==============================================================================
# Add source files
#==============================================================================

puts "Adding RTL sources..."
foreach src $rtl_sources {
    add_files -norecurse $src
    puts "  + [file tail $src]"
}

set wrapper_file "$project_dir/${synth_top}.v"
set fh [open $wrapper_file w]
puts $fh "// Auto-generated by scripts/synth_timing.tcl"
puts $fh "// Wraps the CPU DUT so Vivado Fmax runs do not map every DUT port to package IO."
puts $fh "module ${synth_top} ("
puts $fh "    input  wire        aclk,"
puts $fh "    input  wire        aresetn,"
puts $fh "    output wire \[31:0\] sink"
puts $fh ");"
puts $fh ""
puts $fh "    (* keep = \"true\" *) reg \[31:0\] stim_q;"
puts $fh "    always @(posedge aclk) begin"
puts $fh "        if (!aresetn)"
puts $fh "            stim_q <= 32'h1;"
puts $fh "        else"
puts $fh "            stim_q <= {stim_q\[30:0\], stim_q\[31\] ^ stim_q\[21\] ^ stim_q\[1\] ^ stim_q\[0\]};"
puts $fh "    end"
puts $fh ""
puts $fh "    wire \[3:0\]  arid;"
puts $fh "    wire \[31:0\] araddr;"
puts $fh "    wire \[7:0\]  arlen;"
puts $fh "    wire \[2:0\]  arsize;"
puts $fh "    wire \[1:0\]  arburst;"
puts $fh "    wire \[1:0\]  arlock;"
puts $fh "    wire \[3:0\]  arcache;"
puts $fh "    wire \[2:0\]  arprot;"
puts $fh "    wire        arvalid;"
puts $fh "    wire        rready;"
puts $fh "    wire \[3:0\]  awid;"
puts $fh "    wire \[31:0\] awaddr;"
puts $fh "    wire \[7:0\]  awlen;"
puts $fh "    wire \[2:0\]  awsize;"
puts $fh "    wire \[1:0\]  awburst;"
puts $fh "    wire \[1:0\]  awlock;"
puts $fh "    wire \[3:0\]  awcache;"
puts $fh "    wire \[2:0\]  awprot;"
puts $fh "    wire        awvalid;"
puts $fh "    wire \[3:0\]  wid;"
puts $fh "    wire \[31:0\] wdata;"
puts $fh "    wire \[3:0\]  wstrb;"
puts $fh "    wire        wlast;"
puts $fh "    wire        wvalid;"
puts $fh "    wire        bready;"
puts $fh "    wire        ws_valid;"
puts $fh "    wire \[31:0\] rf_rdata;"
puts $fh "    wire \[31:0\] debug0_wb_pc;"
puts $fh "    wire \[3:0\]  debug0_wb_rf_wen;"
puts $fh "    wire \[4:0\]  debug0_wb_rf_wnum;"
puts $fh "    wire \[31:0\] debug0_wb_rf_wdata;"
puts $fh "    wire \[31:0\] debug0_wb_inst;"
puts $fh "    wire        debug0_excp_valid;"
puts $fh "    wire \[5:0\]  debug0_excp_ecode;"
puts $fh "    wire \[10:0\] debug0_intr_no;"
puts $fh "    wire        debug0_ertn_valid;"
puts $fh "`ifdef PERF_MONI"
puts $fh "    wire        bpu_perf_valid;"
puts $fh "    wire        bpu_perf_is_branch;"
puts $fh "    wire        bpu_perf_is_jump;"
puts $fh "    wire \[31:0\] bpu_perf_pc;"
puts $fh "    wire        bpu_perf_pred_taken;"
puts $fh "    wire        bpu_perf_actual_taken;"
puts $fh "    wire        bpu_perf_correct;"
puts $fh "    wire        bpu_perf_direction_miss;"
puts $fh "    wire        bpu_perf_target_miss;"
puts $fh "    wire        bpu_perf_exu_flush;"
puts $fh "    wire        bpu_perf_is_direct_jump;"
puts $fh "    wire        bpu_perf_is_jirl;"
puts $fh "    wire        bpu_perf_is_ret_jirl;"
puts $fh "    wire        bpu_perf_is_indirect_jirl;"
puts $fh "`endif"
puts $fh "    wire \[31:0\] debug1_wb_pc;"
puts $fh "    wire \[3:0\]  debug1_wb_rf_wen;"
puts $fh "    wire \[4:0\]  debug1_wb_rf_wnum;"
puts $fh "    wire \[31:0\] debug1_wb_rf_wdata;"
puts $fh ""
puts $fh "    ${top_module} u_dut ("
puts $fh "        .aclk(aclk),"
puts $fh "        .aresetn(aresetn),"
puts $fh "        .intrpt(stim_q\[7:0\]),"
puts $fh "        .arid(arid),"
puts $fh "        .araddr(araddr),"
puts $fh "        .arlen(arlen),"
puts $fh "        .arsize(arsize),"
puts $fh "        .arburst(arburst),"
puts $fh "        .arlock(arlock),"
puts $fh "        .arcache(arcache),"
puts $fh "        .arprot(arprot),"
puts $fh "        .arvalid(arvalid),"
puts $fh "        .arready(stim_q\[8\]),"
puts $fh "        .rid(stim_q\[3:0\]),"
puts $fh "        .rdata(stim_q ^ 32'h5a5a_a5a5),"
puts $fh "        .rresp(stim_q\[10:9\]),"
puts $fh "        .rlast(stim_q\[11\]),"
puts $fh "        .rvalid(stim_q\[12\]),"
puts $fh "        .rready(rready),"
puts $fh "        .awid(awid),"
puts $fh "        .awaddr(awaddr),"
puts $fh "        .awlen(awlen),"
puts $fh "        .awsize(awsize),"
puts $fh "        .awburst(awburst),"
puts $fh "        .awlock(awlock),"
puts $fh "        .awcache(awcache),"
puts $fh "        .awprot(awprot),"
puts $fh "        .awvalid(awvalid),"
puts $fh "        .awready(stim_q\[13\]),"
puts $fh "        .wid(wid),"
puts $fh "        .wdata(wdata),"
puts $fh "        .wstrb(wstrb),"
puts $fh "        .wlast(wlast),"
puts $fh "        .wvalid(wvalid),"
puts $fh "        .wready(stim_q\[14\]),"
puts $fh "        .bid(stim_q\[18:15\]),"
puts $fh "        .bresp(stim_q\[20:19\]),"
puts $fh "        .bvalid(stim_q\[21\]),"
puts $fh "        .bready(bready),"
puts $fh "        .break_point(stim_q\[22\]),"
puts $fh "        .infor_flag(stim_q\[23\]),"
puts $fh "        .reg_num(stim_q\[28:24\]),"
puts $fh "        .ws_valid(ws_valid),"
puts $fh "        .rf_rdata(rf_rdata),"
puts $fh "        .debug0_wb_pc(debug0_wb_pc),"
puts $fh "        .debug0_wb_rf_wen(debug0_wb_rf_wen),"
puts $fh "        .debug0_wb_rf_wnum(debug0_wb_rf_wnum),"
puts $fh "        .debug0_wb_rf_wdata(debug0_wb_rf_wdata),"
puts $fh "        .debug0_wb_inst(debug0_wb_inst),"
puts $fh "        .debug0_excp_valid(debug0_excp_valid),"
puts $fh "        .debug0_excp_ecode(debug0_excp_ecode),"
puts $fh "        .debug0_intr_no(debug0_intr_no),"
puts $fh "        .debug0_ertn_valid(debug0_ertn_valid),"
puts $fh "`ifdef PERF_MONI"
puts $fh "        .bpu_perf_valid(bpu_perf_valid),"
puts $fh "        .bpu_perf_is_branch(bpu_perf_is_branch),"
puts $fh "        .bpu_perf_is_jump(bpu_perf_is_jump),"
puts $fh "        .bpu_perf_pc(bpu_perf_pc),"
puts $fh "        .bpu_perf_pred_taken(bpu_perf_pred_taken),"
puts $fh "        .bpu_perf_actual_taken(bpu_perf_actual_taken),"
puts $fh "        .bpu_perf_correct(bpu_perf_correct),"
puts $fh "        .bpu_perf_direction_miss(bpu_perf_direction_miss),"
puts $fh "        .bpu_perf_target_miss(bpu_perf_target_miss),"
puts $fh "        .bpu_perf_exu_flush(bpu_perf_exu_flush),"
puts $fh "        .bpu_perf_is_direct_jump(bpu_perf_is_direct_jump),"
puts $fh "        .bpu_perf_is_jirl(bpu_perf_is_jirl),"
puts $fh "        .bpu_perf_is_ret_jirl(bpu_perf_is_ret_jirl),"
puts $fh "        .bpu_perf_is_indirect_jirl(bpu_perf_is_indirect_jirl),"
puts $fh "`endif"
puts $fh "        .debug1_wb_pc(debug1_wb_pc),"
puts $fh "        .debug1_wb_rf_wen(debug1_wb_rf_wen),"
puts $fh "        .debug1_wb_rf_wnum(debug1_wb_rf_wnum),"
puts $fh "        .debug1_wb_rf_wdata(debug1_wb_rf_wdata)"
puts $fh "    );"
puts $fh ""
puts $fh "    (* keep = \"true\" *) wire \[31:0\] dut_sink ="
puts $fh "        araddr ^ awaddr ^ wdata ^ rf_rdata ^ debug0_wb_pc ^"
puts $fh "        debug0_wb_rf_wdata ^ debug0_wb_inst ^ debug1_wb_pc ^"
puts $fh "        debug1_wb_rf_wdata ^ {24'b0, arlen} ^ {24'b0, awlen} ^"
puts $fh "        {28'b0, arid} ^ {28'b0, awid} ^ {28'b0, wid} ^"
puts $fh "        {28'b0, wstrb} ^ {28'b0, debug0_wb_rf_wen} ^ {28'b0, debug1_wb_rf_wen} ^"
puts $fh "        {27'b0, debug0_wb_rf_wnum} ^ {27'b0, debug1_wb_rf_wnum} ^"
puts $fh "        {29'b0, arsize} ^ {29'b0, awsize} ^ {30'b0, arburst} ^ {30'b0, awburst} ^"
puts $fh "        {30'b0, arlock} ^ {30'b0, awlock} ^ {28'b0, arcache} ^ {28'b0, awcache} ^"
puts $fh "        {29'b0, arprot} ^ {29'b0, awprot} ^ {26'b0, debug0_excp_ecode} ^"
puts $fh "        {21'b0, debug0_intr_no} ^"
puts $fh "        {24'b0, arvalid, rready, awvalid, wlast, wvalid, bready, ws_valid, debug0_excp_valid} ^"
puts $fh "        {31'b0, debug0_ertn_valid}"
puts $fh "`ifdef PERF_MONI"
puts $fh "        ^ bpu_perf_pc ^ {19'b0, bpu_perf_valid, bpu_perf_is_branch, bpu_perf_is_jump,"
puts $fh "        bpu_perf_pred_taken, bpu_perf_actual_taken, bpu_perf_correct,"
puts $fh "        bpu_perf_direction_miss, bpu_perf_target_miss, bpu_perf_exu_flush,"
puts $fh "        bpu_perf_is_direct_jump, bpu_perf_is_jirl, bpu_perf_is_ret_jirl,"
puts $fh "        bpu_perf_is_indirect_jirl}"
puts $fh "`endif"
puts $fh "        ;"
puts $fh ""
puts $fh "    assign sink = dut_sink ^ stim_q;"
puts $fh ""
puts $fh "endmodule"
close $fh
add_files -norecurse $wrapper_file
puts "  + Generated wrapper: [file tail $wrapper_file] (instantiates $top_module)"

set_property include_dirs [list $rtl_dir] [current_fileset]
set_property verilog_define $verilog_defines [current_fileset]
set_property top $synth_top [current_fileset]
puts "  + Verilog defines: $verilog_defines"

#==============================================================================
# Constraints
#==============================================================================

set base_xdc [file normalize "$script_dir/cpu_timing.xdc"]
if {![file exists $base_xdc]} {
    puts "ERROR: baseline XDC not found: $base_xdc"
    exit 1
}
add_files -fileset constrs_1 -norecurse $base_xdc
puts "  + Constraints: [file tail $base_xdc]"

# Override XDC with target frequency and I/O false-path for OOC Fmax evaluation.
set override_xdc "$project_dir/override_clk.xdc"
set fh [open $override_xdc w]
puts $fh "# Auto-generated by scripts/synth_timing.tcl"
puts $fh [format {create_clock -period %.3f -name cpu_clk [get_ports aclk]} $target_period_ns]
puts $fh {set_false_path -from [get_ports aresetn]}
close $fh
add_files -fileset constrs_1 -norecurse $override_xdc
set_property IS_ENABLED false [get_files $base_xdc]
puts "  + Override clock: ${target_freq_mhz} MHz ([format %.3f $target_period_ns] ns)"

#==============================================================================
# Synthesis / implementation strategies
#==============================================================================

set_property strategy "Vivado Synthesis Defaults" [get_runs synth_1]
set_property STEPS.SYNTH_DESIGN.ARGS.FLATTEN_HIERARCHY rebuilt [get_runs synth_1]
catch {set_property STEPS.SYNTH_DESIGN.ARGS.GLOBAL_RETIMING true [get_runs synth_1]}
set_property STEPS.SYNTH_DESIGN.ARGS.DIRECTIVE PerformanceOptimized [get_runs synth_1]

set_property strategy "Performance_ExplorePostRoutePhysOpt" [get_runs impl_1]
set_property STEPS.PHYS_OPT_DESIGN.IS_ENABLED true [get_runs impl_1]
set_property STEPS.POST_ROUTE_PHYS_OPT_DESIGN.IS_ENABLED true [get_runs impl_1]

#==============================================================================
# Run synthesis
#==============================================================================

puts ""
puts "=============================================="
puts " Step 1/3: Synthesis"
puts "=============================================="

reset_run synth_1
reset_run impl_1
launch_runs synth_1 -jobs $num_jobs
wait_on_run synth_1

set synth_status [get_property STATUS [get_runs synth_1]]
puts "Synthesis status: $synth_status"
if {[get_property PROGRESS [get_runs synth_1]] != "100%"} {
    puts "ERROR: synthesis failed"
    exit 1
}

#==============================================================================
# Run implementation
#==============================================================================

puts ""
puts "=============================================="
puts " Step 2/3: Implementation"
puts "=============================================="

launch_runs impl_1 -jobs $num_jobs
wait_on_run impl_1

set impl_status [get_property STATUS [get_runs impl_1]]
puts "Implementation status: $impl_status"
if {[get_property PROGRESS [get_runs impl_1]] != "100%"} {
    puts "WARNING: implementation may not be fully routed"
}

#==============================================================================
# Reports and Fmax estimation
#==============================================================================

puts ""
puts "=============================================="
puts " Step 3/3: Timing Reports"
puts "=============================================="

open_run impl_1

set timing_rpt "$output_dir/timing_summary.rpt"
report_timing_summary \
    -delay_type min_max \
    -max_paths 20 \
    -input_pins \
    -routable_nets \
    -file $timing_rpt

set util_rpt "$output_dir/utilization.rpt"
report_utilization -hierarchical -hierarchical_depth 3 -file $util_rpt

set crit_rpt "$output_dir/critical_path.rpt"
report_timing \
    -max_paths 10 \
    -nworst 1 \
    -delay_type max \
    -sort_by slack \
    -input_pins \
    -file $crit_rpt

set clk_rpt "$output_dir/clock_interaction.rpt"
report_clock_interaction -file $clk_rpt

# Query WNS directly from timing DB.
set wns 0.0
set timing_path [get_timing_paths -max_paths 1 -delay_type max -sort_by slack]
if {[llength $timing_path] > 0} {
    set wns [get_property SLACK [lindex $timing_path 0]]
}

set achievable_period_ns [expr {$target_period_ns - $wns}]
if {$achievable_period_ns <= 0.0} {
    set achievable_period_ns 0.001
}
set achievable_freq_mhz [expr {1000.0 / $achievable_period_ns}]

set summary_file "$output_dir/timing_summary.txt"
set sf [open $summary_file w]
puts $sf "========================================================"
puts $sf "  LA CPU Timing Analysis Result"
puts $sf "========================================================"
puts $sf ""
puts $sf "  Device               : $fpga_part"
puts $sf "  DUT top              : $top_module"
puts $sf "  Synthesis top        : $synth_top"
puts $sf "  Config               : TLB=$cfg_tlb_enable L1I=$cfg_l1i_enable L1D=$cfg_l1d_enable L2=$cfg_l2_enable BPU=$cfg_bpu_enable FBUF=$cfg_fetch_buffer_enable ITCM=$cfg_itcm_enable STRICT_CACOP=$cfg_cache_op_strict_enable L2_PREFETCH=$cfg_l2_prefetch_enable PERF_MONI=$cfg_perf_moni_enable"
puts $sf "  Target frequency     : [format %.1f $target_freq_mhz] MHz"
puts $sf "  Target period        : [format %.3f $target_period_ns] ns"
puts $sf "  WNS                  : [format %.3f $wns] ns"
puts $sf "  Estimated period     : [format %.3f $achievable_period_ns] ns"
puts $sf "  Estimated frequency  : [format %.1f $achievable_freq_mhz] MHz"
puts $sf "  FMAX_MHZ=[format %.1f $achievable_freq_mhz]"
puts $sf ""
if {$wns >= 0} {
    puts $sf "  STATUS: TIMING MET at target frequency"
} else {
    puts $sf "  STATUS: TIMING VIOLATED at target frequency"
}
puts $sf "========================================================"
close $sf

puts ""
puts "=============================================="
puts " TIMING RESULT"
puts "=============================================="
puts "  Target      : [format %.1f $target_freq_mhz] MHz ([format %.3f $target_period_ns] ns)"
puts "  WNS         : [format %.3f $wns] ns"
puts "  Est. Fmax   : [format %.1f $achievable_freq_mhz] MHz"
if {$wns >= 0} {
    puts "  Status      : TIMING MET"
} else {
    puts "  Status      : TIMING VIOLATED"
}
puts "  Summary     : $summary_file"
puts "=============================================="
puts ""
puts "Reports generated in: $output_dir"

exit 0

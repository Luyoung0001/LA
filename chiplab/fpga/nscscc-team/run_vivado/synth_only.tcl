# Synthesis-only script for SoC timing exploration (stub CPU)
# Run: vivado -mode batch -source synth_only.tcl

set  project_name loongson_synth
set  project_path ./project_synth
set project_part xc7a200tfbg676-2

# CLEAR old project
file delete -force $project_path
file delete -force ../../../chip/soc_demo/nscscc-team/xilinx_ip/clk_pll/gen
file delete -force ../../../chip/soc_demo/nscscc-team/xilinx_ip/clk_pll_ddr/gen
file delete -force ../../../chip/soc_demo/nscscc-team/xilinx_ip/vio/gen
file delete -force ../../../chip/soc_demo/nscscc-team/xilinx_ip/axi_crossbar_2x3/gen
file delete -force ../../../chip/soc_demo/nscscc-team/xilinx_ip/jtag_axi/gen
file delete -force ../../../chip/soc_demo/nscscc-team/xilinx_ip/mig_axi_32/gen

create_project -force $project_name $project_path -part $project_part

# Add sources
add_files -scan_for_includes ../../../chip/soc_demo/nscscc-team
add_files -scan_for_includes ../../../IP/AXI_SRAM_BRIDGE
add_files -scan_for_includes ../../../IP/APB_DEV/URT
add_files -norecurse "../../../IP/APB_DEV/apb_dev_top_no_nand.v"
add_files -norecurse "../../../IP/APB_DEV/apb_mux2.v"
add_files -norecurse "../../../IP/AMBA/axi2apb.v"

# Add IPs
add_files -quiet [glob -nocomplain ../../../chip/soc_demo/nscscc-team/xilinx_ip/*/*.xci]

# Add myCPU
add_files -scan_for_includes ../../../myCPU

# Add xilinx_ip in myCPU (if any)
add_files -quiet [glob -nocomplain ../../../myCPU/xilinx_ip/*/*.xci]
add_files -quiet [glob -nocomplain ../../../myCPU/xilinx_ip/*/*.xcix]

# Upgrade IPs
upgrade_ip -quiet [get_ips]

# Add constraints
add_files -fileset constrs_1 -quiet ../constraints

set_property top soc_top [current_fileset]

# Use high-performance synthesis strategy
set_property strategy Flow_PerfOptimized_high [get_runs synth_1]

# Run synthesis
launch_runs synth_1 -jobs 8
wait_on_run synth_1

# Report timing summary after synthesis
open_run synth_1
report_timing_summary -delay_type max -report_unconstrained \
    -check_timing_verbose -max_paths 10 -input_pins \
    -file ./project_synth/synth_timing_summary.rpt
report_clock_interaction -file ./project_synth/synth_clock_interaction.rpt

puts "=== Synthesis done. Reports saved to ./project_synth/ ==="

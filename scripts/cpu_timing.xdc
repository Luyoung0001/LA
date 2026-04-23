################################################################################
# LA CPU timing constraints (baseline)
# - Clock period will be overridden by scripts/synth_timing.tcl via -freq
################################################################################

create_clock -period 10.000 -name cpu_clk -waveform {0.000 5.000} [get_ports aclk]
set_false_path -from [get_ports aresetn]

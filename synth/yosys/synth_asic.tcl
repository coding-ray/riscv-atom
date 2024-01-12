###############################################################################
# Synthesis script for yosys synthesis (FPGA)
###############################################################################
set time_start [clock seconds]; puts "Start time: [clock format ${time_start} -gmt false]"

if {[llength $argv] != 2} {
    puts "Usage: script.tcl <asic_lib_file> <build_dir>"
    exit 1
}

###############################################################################
# Settings
set liberty [lindex $argv 0]
set flatten 0
set default_synth 1
set clk_period 10

# Output directories
set build_dir [lindex $argv 1]
set output_dir "$build_dir/output"
set report_dir "$build_dir/report"

set vsource $build_dir/HydrogenSoC.v
set topmodule HydrogenSoC
###############################################################################
file mkdir $output_dir
file mkdir $report_dir

yosys "echo on"

# -- Read Liberty ----------------------
yosys "read_liberty -lib $liberty"

# -- Read Verilog ----------------------
set rd_vrlg_flags "-DSYNTHESIS_YOSYS -DSOC_BOOTROM_INIT_FILE=\"$build_dir/bootloader.hex\""
yosys "read_verilog $rd_vrlg_flags $vsource"

# Check hierarchy
yosys "hierarchy -check -top $topmodule"

# Flatten
if {$flatten} {
    yosys "flatten"
}

# check for problems
yosys "check -assert"

# -- Synth -----------------------------
if {$default_synth} {
    # Use default synth command
    yosys "synth -top $topmodule"
} else {
    # the high-level stuff
    yosys "proc; opt; fsm; opt; memory; opt;"

    # mapping to internal cell library
    yosys "techmap; opt;"
}

# map DFF to library
yosys "dfflibmap -liberty $liberty"

# mapping logic to Library
yosys "abc -liberty $liberty -D $clk_period"

# check for problems
yosys "check -mapped"

# -- Write reports ---------------------
yosys "tee -a $report_dir/utilization.rpt stat -liberty $liberty"
yosys "tee -a $report_dir/ltp.rpt ltp"
yosys "tee -a $report_dir/timing.rpt sta"

yosys "clean"

# -- Write output ----------------------
yosys "write_verilog -v -attr2comment $output_dir/${topmodule}.v"
yosys "write_blif $output_dir/${topmodule}.blif"
yosys "write_rtlil $output_dir/${topmodule}.rtlil"

###############################################################################
set time_end [clock seconds]; puts "End time: [clock format ${time_start} -gmt false]"
source ../utils.tcl
print_elapsed_time $time_start $time_end
puts "----- We're done here -----"
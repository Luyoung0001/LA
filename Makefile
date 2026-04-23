CPU_HOME = $(shell pwd)

EXP ?= 6
FREQ ?= 200
JOBS ?= 8
FPGA_PART ?= xc7a200tfbg676-1
SYNTH_TOP ?= core_top

# mycpu
VSRC_mycpu_env_vsrc = $(CPU_HOME)/mycpu_env/myCPU/v_src/*.v
VSRC_dpic = $(CPU_HOME)/mycpu_env/myCPU/DPIC
SV_FLAGS = -I$(VSRC_dpic)

DPIC_C_SRC = $(CPU_HOME)/mycpu_env/myCPU/DPIC_C/src/*.cpp
DPIC_C_INC = $(CPU_HOME)/mycpu_env/myCPU/DPIC_C/include

MEM_SRC = $(CPU_HOME)/mycpu_env/myCPU/memory/src/*.c
MEM_INC = $(CPU_HOME)/mycpu_env/myCPU/memory/include

MAIN_INC = $(CPU_HOME)/Verilator/include

INC_PATH = $(MAIN_INC) $(DPIC_C_INC) $(MEM_INC)

INCFLAGS = $(addprefix -I, $(INC_PATH))

VERILATOR = verilator
TOP = verilator_top
VIVADO = vivado
VIVADO_FLAGS = -mode batch -nojournal -nolog

CPPSRC = $(CPU_HOME)/Verilator/*.cpp
SRC = $(CPPSRC) $(DPIC_C_SRC) $(MEM_SRC)

VSRC = $(VSRC_mycpu_env_vsrc) $(VSRC_dpic)/*.sv $(VSRC_dpic)/*.v

V_FLAGS = --cc $(VSRC) --Wno-UNOPTFLAT -Wno-fatal --exe $(SRC) $(SV_FLAGS) --top $(TOP)  --trace-fst --CFLAGS "$(INCFLAGS)" --LDFLAGS "-ldl"

OBJ_DIR = obj_dir

EXE = $(CPU_HOME)/$(OBJ_DIR)/V$(TOP)

SCRIPTS_DIR = $(CPU_HOME)/scripts
TIMING_SCRIPT = $(SCRIPTS_DIR)/synth_timing.tcl
TIMING_DIR = $(CPU_HOME)/vivado_timing
LOG_DIR = $(CPU_HOME)/logs
SYNTH_LOG = $(LOG_DIR)/synth_timing.log

test:
	@rm -rf $(CPU_HOME)/mycpu_env/func/obj
	$(MAKE) -C mycpu_env/func EXP=$(EXP)

simu: clean
	$(VERILATOR) $(V_FLAGS)

build: simu
	bear -- $(MAKE) -C $(OBJ_DIR) -f V$(TOP).mk -j10

run: build
	$(EXE)

all: test run

fmax: synth_timing

synth_timing: $(TIMING_SCRIPT)
	@mkdir -p $(LOG_DIR)
	bash -c '$(VIVADO) $(VIVADO_FLAGS) \
		-source $(TIMING_SCRIPT) \
		-tclargs -freq $(FREQ) -jobs $(JOBS) -part $(FPGA_PART) -top $(SYNTH_TOP) \
		2>&1 | tee $(SYNTH_LOG); exit $${PIPESTATUS[0]}'
	@echo ""
	@echo "=== Timing Result ==="
	@cat $(TIMING_DIR)/timing_summary.txt
	@echo "(Full log: $(SYNTH_LOG))"

synth_timing_clean:
	@rm -rf $(TIMING_DIR) $(LOG_DIR) $(CPU_HOME)/.Xil

docs:
	@echo "Docs index: $(CPU_HOME)/docs/README.md"

help:
	@echo "Usage:"
	@echo "  make all EXP=6      # run test + dynamic difftest simulation"
	@echo "  make test EXP=6     # build func test program"
	@echo "  make build          # build verilator executable"
	@echo "  make run            # run simulation"
	@echo "  make fmax           # Vivado synth+P&R and print estimated Fmax"
	@echo "  make synth_timing FREQ=150 JOBS=8 SYNTH_TOP=core_top"
	@echo "                      # run timing flow with custom options"
	@echo "  make synth_timing_clean # clean Vivado timing artifacts"
	@echo "  make docs           # print docs index path"
	@echo "  make clean          # clean build artifacts"

clean:
	@rm -rf $(OBJ_DIR) wave.vcd wave.fst

runall:
	@bash run_all_tests.sh

.PHONY: test simu build run all fmax synth_timing synth_timing_clean clean runall docs help

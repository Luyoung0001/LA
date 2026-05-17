CPU_HOME = $(shell pwd)

CPU ?= PIPELINE
CPU_SELECT = $(shell printf '%s' '$(CPU)' | tr '[:lower:]' '[:upper:]')
EXP ?= 6
FREQ ?= 200
JOBS ?= 8
FPGA_PART ?= xc7a200tfbg676-1
SYNTH_TOP ?= core_top
RTL_LOG ?= 0
PERF_MONI ?= 0
PERF_IC ?= 0
PERF_DC ?= 0
PERF_BPU ?= 0
L2_PREFETCH ?= 1
MDU ?= 0
TRACE ?= 0
SIM_JOBS ?= 4
CHIPLAB_BUILD_JOBS ?= 4
# Default to the full performance CPU configuration. Override these on the
# command line for ablation runs, e.g. `make fmax BPU_ENABLE=0`.
TLB_ENABLE ?= 1
L1I_ENABLE ?= 1
L1D_ENABLE ?= 1
L2_ENABLE ?= 1
BPU_ENABLE ?= 1
FETCH_BUFFER_ENABLE ?= 1
ITCM_ENABLE ?= 0
CACHE_OP_STRICT_ENABLE ?= 1
IPC_CASE ?= set1a_alu
BENCH_REPEAT ?= 512
BENCH_UNROLL ?= 16
PERF_MONI_FLAGS = $(if $(filter 1 yes true on,$(PERF_MONI)),-DPERF_MONI,)
PERF_IC_FLAGS = $(if $(filter 1 yes true on,$(PERF_IC)),-DPERF_IC,)
PERF_DC_FLAGS = $(if $(filter 1 yes true on,$(PERF_DC)),-DPERF_DC,)
PERF_BPU_FLAGS = $(if $(filter 1 yes true on,$(PERF_BPU)),-DPERF_BPU -DPERF_MONI,)
L2_PREFETCH_FLAGS = $(if $(filter 0 no false off,$(L2_PREFETCH)),-DCPU_DISABLE_L2_PREFETCH,)
MDU_FLAGS = $(if $(filter 1 yes true on,$(MDU)),-DMDU=1,)
TRACE_BUILD_FLAGS = $(if $(filter 1 yes true on,$(TRACE) $(PERF_MONI)),--trace-fst,)
TRACE_CPP_FLAGS = $(if $(filter 1 yes true on,$(TRACE)),-DCPU_SIM_TRACE,)
CONFIG_FLAGS = \
	-DLA_TLB_ENABLE=$(TLB_ENABLE) \
	-DLA_L1I_ENABLE=$(L1I_ENABLE) \
	-DLA_L1D_ENABLE=$(L1D_ENABLE) \
	-DLA_L2_ENABLE=$(L2_ENABLE) \
	-DLA_BPU_ENABLE=$(BPU_ENABLE) \
	-DLA_FETCH_BUFFER_ENABLE=$(FETCH_BUFFER_ENABLE) \
	-DLA_ITCM_ENABLE=$(ITCM_ENABLE) \
	-DLA_CACHE_OP_STRICT_ENABLE=$(CACHE_OP_STRICT_ENABLE)

TIMING_CONFIG_ARGS = \
	-tlb $(TLB_ENABLE) \
	-l1i $(L1I_ENABLE) \
	-l1d $(L1D_ENABLE) \
	-l2 $(L2_ENABLE) \
	-bpu $(BPU_ENABLE) \
	-fetch-buffer $(FETCH_BUFFER_ENABLE) \
	-itcm $(ITCM_ENABLE) \
	-cache-op-strict $(CACHE_OP_STRICT_ENABLE) \
	-l2-prefetch $(L2_PREFETCH) \
	-perf-moni $(PERF_MONI)

# mycpu
RTL_DIR = $(CPU_HOME)/rtl
VSRC_project_la_rtl_all = $(wildcard $(RTL_DIR)/*.v)
VSRC_project_la_rtl = $(filter-out $(RTL_DIR)/verilator_top.v $(RTL_DIR)/verilator_top_la500.v,$(VSRC_project_la_rtl_all))
VSRC_mycpu_env_sim = $(wildcard $(CPU_HOME)/mycpu_env/myCPU/sim/*.v)
VSRC_dpic = $(CPU_HOME)/mycpu_env/myCPU/DPIC
LA500_DIR = $(CPU_HOME)/reference_cpu/open-la500

ifeq ($(CPU_SELECT),LA500)
VSRC_project_rtl = $(wildcard $(LA500_DIR)/*.v)
VSRC_sim_top = $(RTL_DIR)/verilator_top_la500.v
SIM_MODELS =
SV_FLAGS = -I$(VSRC_dpic) -I$(RTL_DIR) -I$(LA500_DIR) -DCPU_LA500 -DSIMU
CPP_DEFINES = -DCPU_LA500 $(TRACE_CPP_FLAGS)
else
VSRC_project_rtl = $(VSRC_project_la_rtl)
VSRC_sim_top = $(RTL_DIR)/verilator_top.v
SIM_MODELS = $(VSRC_mycpu_env_sim)
SV_FLAGS = -I$(VSRC_dpic) -I$(RTL_DIR) $(PERF_MONI_FLAGS) $(PERF_IC_FLAGS) $(PERF_DC_FLAGS) $(PERF_BPU_FLAGS) $(L2_PREFETCH_FLAGS) $(MDU_FLAGS) $(CONFIG_FLAGS)
CPP_DEFINES = $(PERF_MONI_FLAGS) $(PERF_IC_FLAGS) $(PERF_DC_FLAGS) $(PERF_BPU_FLAGS) $(TRACE_CPP_FLAGS)
endif

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

VSRC = $(VSRC_sim_top) $(VSRC_project_rtl) $(SIM_MODELS) $(VSRC_dpic)/*.sv $(VSRC_dpic)/*.v

V_FLAGS = --cc $(VSRC) --Wno-UNOPTFLAT --Wno-TIMESCALEMOD --Wno-PINMISSING -Wno-fatal --exe $(SRC) $(SV_FLAGS) --top $(TOP) $(TRACE_BUILD_FLAGS) --CFLAGS "$(INCFLAGS) $(CPP_DEFINES)" --LDFLAGS "-ldl"

OBJ_DIR = obj_dir

EXE = $(CPU_HOME)/$(OBJ_DIR)/V$(TOP)
IPC_BENCH_DIR = $(CPU_HOME)/mycpu_env/ipc_microbench
IPC_BENCH_OBJ = $(IPC_BENCH_DIR)/obj/repeat_$(BENCH_REPEAT)_unroll_$(BENCH_UNROLL)/$(IPC_CASE)

SCRIPTS_DIR = $(CPU_HOME)/scripts
TIMING_SCRIPT = $(SCRIPTS_DIR)/synth_timing.tcl
TIMING_DIR = $(CPU_HOME)/vivado_timing
LOG_DIR = $(CPU_HOME)/logs
SYNTH_LOG = $(LOG_DIR)/synth_timing_log.txt

CHIPLAB_HOME = $(CPU_HOME)/chiplab
CHIPLAB_RUN_DIR = $(CHIPLAB_HOME)/sims/verilator/run_prog
CHIPLAB_SOFTWARE_TARGETS = func/% fireye/% c_prg/% nscscc_perf/% my_program memset dhrystone coremark hello_world linux rtthread lacc
CHIPLAB_AVAILABLE_SOFTWARE = func/func_lab3 func/func_lab4 func/func_lab6 func/func_lab7 \
	func/func_lab8 func/func_lab9 func/func_lab14 func/func_lab15 func/func_lab19 \
	func/func_advance fireye/A0 fireye/B2 fireye/C0 fireye/D1 fireye/I2 \
	c_prg/memcmp c_prg/inner_product c_prg/lookup_table c_prg/loop_induction \
	c_prg/minmax_sequence c_prg/product_sequence my_program memset dhrystone \
	coremark hello_world linux rtthread lacc \
	nscscc_perf/bitcount nscscc_perf/bubble_sort nscscc_perf/coremark \
	nscscc_perf/crc32 nscscc_perf/dhrystone nscscc_perf/quick_sort \
	nscscc_perf/select_sort nscscc_perf/sha nscscc_perf/stream_copy \
	nscscc_perf/stringsearch nscscc_perf/fireye_A0 nscscc_perf/fireye_B2 \
	nscscc_perf/fireye_C0 nscscc_perf/fireye_D1 nscscc_perf/fireye_I2 \
	nscscc_perf/inner_product nscscc_perf/lookup_table \
	nscscc_perf/loop_induction nscscc_perf/my_memcmp \
	nscscc_perf/minmax_sequence nscscc_perf/allbench
CHIPLAB_FUNC_TESTS ?= func/func_lab3,func/func_lab4,func/func_lab6,func/func_lab7,func/func_lab8,func/func_lab9,func/func_lab14,func/func_lab15,func/func_lab19,func/func_advance
CHIPLAB_FUNC_SMOKE ?= func/func_lab3
CHIPLAB_PERF_TESTS ?= nscscc_perf/bitcount,nscscc_perf/bubble_sort,nscscc_perf/coremark,nscscc_perf/crc32,nscscc_perf/dhrystone,nscscc_perf/quick_sort,nscscc_perf/select_sort,nscscc_perf/sha,nscscc_perf/stream_copy,nscscc_perf/stringsearch,nscscc_perf/fireye_A0,nscscc_perf/fireye_B2,nscscc_perf/fireye_C0,nscscc_perf/fireye_D1,nscscc_perf/fireye_I2,nscscc_perf/inner_product,nscscc_perf/lookup_table,nscscc_perf/loop_induction,nscscc_perf/my_memcmp,nscscc_perf/minmax_sequence
CHIPLAB_PERF_SMOKE ?= nscscc_perf/dhrystone
CHIPLAB_LIGHTSSS ?= 1
CHIPLAB_LIGHTSSS_OPTS ?= --dump-fst --fork-interval 1000 --slot-size 2 --wait-interval 5
CHIPLAB_LIGHTSSS_MAKE_ARGS = $(if $(filter 1 yes true on,$(CHIPLAB_LIGHTSSS)),FORK_CHILD=1,)
CHIPLAB_SMOKE_OPTS ?= --disable-trace-comp --disable-simu-trace
CHIPLAB_SOFTWARE_GOALS = $(filter $(CHIPLAB_SOFTWARE_TARGETS),$(MAKECMDGOALS))
CHIPLAB_OPTION_GOALS = $(filter --%,$(MAKECMDGOALS))
CHIPLAB_FORWARD_OPTS = $(filter-out --run,$(CHIPLAB_OPTION_GOALS))
CHIPLAB_RUN ?= $(if $(RUN),$(RUN),$(if $(RUN_SOFTWARE),$(RUN_SOFTWARE),$(firstword $(CHIPLAB_SOFTWARE_GOALS))))
CHIPLAB_OPTS ?= --disable-trace-comp --disable-simu-trace
CHIPLAB_EFFECTIVE_OPTS = $(CHIPLAB_OPTS) $(if $(filter 1 yes true on,$(CHIPLAB_LIGHTSSS)),$(CHIPLAB_LIGHTSSS_OPTS),)
CHIPLAB_CONFIG_ARGS ?= $(if $(CHIPLAB_RUN),--run $(CHIPLAB_RUN),) $(CHIPLAB_FORWARD_OPTS) $(CHIPLAB_EFFECTIVE_OPTS)
CHIPLAB_VFLAGS = $(strip $(PERF_MONI_FLAGS) $(PERF_IC_FLAGS) $(PERF_DC_FLAGS) $(PERF_BPU_FLAGS) $(L2_PREFETCH_FLAGS) $(MDU_FLAGS) $(CONFIG_FLAGS))
CHIPLAB_VFLAGS_ENV = $(if $(CHIPLAB_VFLAGS),VFLAGS="$(CHIPLAB_VFLAGS)",)
CHIPLAB_MAKE_ARGS ?=
CHIPLAB_MDU_COLLECT_ARG = MDU_COLLECT=$(MDU_COLLECT)
CHIPLAB_PERF_ARGS = PERF_IC=$(PERF_IC) PERF_DC=$(PERF_DC) PERF_BPU=$(PERF_BPU)
CHIPLAB_CPU ?= $(CPU_SELECT)
CHIPLAB_SIM_DIR = $(CPU_HOME)/mycpu_env/myCPU/sim
CHIPLAB_RTL_SRCS = $(filter-out $(RTL_DIR)/mycpu_top.v $(RTL_DIR)/verilator_top.v $(RTL_DIR)/verilator_top_la500.v,$(wildcard $(RTL_DIR)/*.v $(RTL_DIR)/*.vh))

test:
	@rm -rf $(CPU_HOME)/mycpu_env/func/obj
	$(MAKE) -C mycpu_env/func EXP=$(EXP)

simu: clean
	$(VERILATOR) $(V_FLAGS)

build: simu
	bear -- $(MAKE) -C $(OBJ_DIR) -f V$(TOP).mk -j$(SIM_JOBS)

run: build
	$(EXE)

all: test run

ipcbench:
	$(MAKE) -C $(IPC_BENCH_DIR) CASE=$(IPC_CASE) BENCH_REPEAT=$(BENCH_REPEAT) BENCH_UNROLL=$(BENCH_UNROLL) case

ipcbench-run: ipcbench build
	LA_MAIN_BIN=$(IPC_BENCH_OBJ)/main.bin \
	LA_STOP_PC=$$(cat $(IPC_BENCH_OBJ)/stop_pc.txt) \
	$(EXE)

ipcbench-list:
	$(MAKE) -C $(IPC_BENCH_DIR) list

fmax: synth_timing

synth_timing: $(TIMING_SCRIPT)
	@mkdir -p $(LOG_DIR)
	bash -c '$(VIVADO) $(VIVADO_FLAGS) \
		-source $(TIMING_SCRIPT) \
		-tclargs -freq $(FREQ) -jobs $(JOBS) -part $(FPGA_PART) -top $(SYNTH_TOP) $(TIMING_CONFIG_ARGS) \
		2>&1 | tee $(SYNTH_LOG); exit $${PIPESTATUS[0]}'
	@echo ""
	@echo "=== Timing Result ==="
	@cat $(TIMING_DIR)/timing_summary.txt
	@echo "(Full log: $(SYNTH_LOG))"

synth_timing_clean:
	@rm -rf $(TIMING_DIR) $(LOG_DIR) $(CPU_HOME)/.Xil

docs:
	@echo "Docs index: $(CPU_HOME)/docs/README.md"

mycpu-sync-rtl:
	@rm -rf $(CPU_HOME)/mycpu_env/myCPU/v_src
	@echo "RTL is sourced directly from $(RTL_DIR); removed obsolete mycpu_env/myCPU/v_src."

chiplab-list:
	@printf '%s\n' $(CHIPLAB_AVAILABLE_SOFTWARE)

chiplab-sync-rtl:
	@mkdir -p $(CHIPLAB_HOME)/myCPU
	@find $(CHIPLAB_HOME)/myCPU -maxdepth 1 -type l -delete
	@ln -sf ../../rtl/mycpu_top.v $(CHIPLAB_HOME)/myCPU/core_top.v
	@for src in $(CHIPLAB_RTL_SRCS); do \
		ln -sf ../../rtl/$$(basename "$$src") $(CHIPLAB_HOME)/myCPU/$$(basename "$$src"); \
	done
	@if [ -d "$(CHIPLAB_SIM_DIR)" ]; then \
		for src in $(wildcard $(CHIPLAB_SIM_DIR)/*.v); do \
			ln -sf ../../mycpu_env/myCPU/sim/$$(basename "$$src") $(CHIPLAB_HOME)/myCPU/$$(basename "$$src"); \
		done; \
	fi

configure: chiplab-run

chiplab-configure:
	@if [ -z "$(strip $(CHIPLAB_CONFIG_ARGS))" ]; then \
		echo "Usage:"; \
		echo "  make configure RUN=func/func_lab14"; \
		echo "  make configure RUN=hello_world"; \
		echo "  make configure RUN=coremark CPU=LA500"; \
		echo "  make chiplab-list"; \
		exit 2; \
	fi
	@if [ -n "$(strip $(CHIPLAB_RUN))" ]; then \
		for soft in $$(printf '%s\n' "$(CHIPLAB_RUN)" | tr ',' ' '); do \
			case " $(CHIPLAB_AVAILABLE_SOFTWARE) " in \
				*" $$soft "*) ;; \
				*) \
					echo "Chiplab software '$$soft' unavailable in this tree."; \
					echo "Run 'make chiplab-list' to list available software."; \
					exit 2; \
					;; \
			esac; \
		done; \
	fi
	cd $(CHIPLAB_RUN_DIR) && CHIPLAB_HOME=$(CHIPLAB_HOME) ./configure.sh $(CHIPLAB_CONFIG_ARGS)

chiplab-run: chiplab-configure
	@$(MAKE) chiplab-sync-rtl
	$(CHIPLAB_VFLAGS_ENV) $(MAKE) -C $(CHIPLAB_RUN_DIR) CHIPLAB_HOME=$(CHIPLAB_HOME) CHIPLAB_CPU=$(CHIPLAB_CPU) CHIPLAB_BUILD_JOBS=$(CHIPLAB_BUILD_JOBS) $(CHIPLAB_MDU_COLLECT_ARG) $(CHIPLAB_PERF_ARGS) $(CHIPLAB_LIGHTSSS_MAKE_ARGS) $(CHIPLAB_MAKE_ARGS)

chiplab-smoke: chiplab-configure
	@$(MAKE) chiplab-sync-rtl
	$(CHIPLAB_VFLAGS_ENV) $(MAKE) -C $(CHIPLAB_RUN_DIR) CHIPLAB_HOME=$(CHIPLAB_HOME) CHIPLAB_CPU=$(CHIPLAB_CPU) CHIPLAB_BUILD_JOBS=$(CHIPLAB_BUILD_JOBS) $(CHIPLAB_MDU_COLLECT_ARG) $(CHIPLAB_PERF_ARGS) $(CHIPLAB_LIGHTSSS_MAKE_ARGS) compile soft $(CHIPLAB_MAKE_ARGS)

chiplab-func-smoke:
	$(MAKE) chiplab-run RUN="$(CHIPLAB_FUNC_SMOKE)" CHIPLAB_OPTS="$(CHIPLAB_SMOKE_OPTS) $(CHIPLAB_OPTS)" CHIPLAB_MAKE_ARGS="$(CHIPLAB_MAKE_ARGS)"

chiplab-perf-smoke:
	$(MAKE) chiplab-run RUN="$(CHIPLAB_PERF_SMOKE)" CHIPLAB_OPTS="$(CHIPLAB_SMOKE_OPTS) $(CHIPLAB_OPTS)" CHIPLAB_MAKE_ARGS="$(CHIPLAB_MAKE_ARGS)"

chiplab-func:
	$(MAKE) chiplab-run RUN="$(CHIPLAB_FUNC_TESTS)" CHIPLAB_OPTS="$(CHIPLAB_OPTS)" CHIPLAB_MAKE_ARGS="$(CHIPLAB_MAKE_ARGS)"

chiplab-perf:
	$(MAKE) chiplab-run RUN="$(CHIPLAB_PERF_TESTS)" CHIPLAB_OPTS="$(CHIPLAB_OPTS)" CHIPLAB_MAKE_ARGS="$(CHIPLAB_MAKE_ARGS)"

chiplab-test-smoke: chiplab-func-smoke chiplab-perf-smoke

help:
	@echo "Usage:"
	@echo "  make all EXP=6      # run test + dynamic difftest simulation"
	@echo "  make all EXP=6 CPU=LA500 # run dynamic difftest with reference openLA500"
	@echo "  make all EXP=23 PERF_MONI=1 # print IPC and BPU accuracy/miss statistics"
	@echo "  make all EXP=6 BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1"
	@echo "                      # enable copied BPU/fetch-buffer adapters"
	@echo "  make ipcbench-run IPC_CASE=set1a_alu BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1"
	@echo "                      # run standalone IPC microbenchmark"
	@echo "  make ipcbench-list  # list standalone IPC microbenchmarks"
	@echo "  make test EXP=6     # build func test program"
	@echo "  make build SIM_JOBS=4 TRACE=0 # build verilator executable"
	@echo "  make run            # run simulation"
	@echo "  make fmax           # Vivado synth+P&R and print estimated Fmax"
	@echo "  make synth_timing FREQ=150 JOBS=8 SYNTH_TOP=core_top"
	@echo "                      # run timing flow with custom options"
	@echo "  make configure RUN=hello_world"
	@echo "                      # configure and run Chiplab Verilator simulation"
	@echo "  make configure RUN=coremark PERF_IC=1 PERF_DC=1 PERF_BPU=1"
	@echo "                      # print Chiplab ICache/DCache/BPU performance counters"
	@echo "  make configure RUN=linux CHIPLAB_LIGHTSSS=0"
	@echo "                      # disable default Chiplab lightSSS fork waveform mode"
	@echo "  make chiplab-smoke RUN=hello_world"
	@echo "                      # compile Chiplab Verilator + software without running simulation"
	@echo "  make chiplab-func-smoke"
	@echo "                      # run one short Chiplab function test without trace files"
	@echo "  make chiplab-perf-smoke"
	@echo "                      # run one short Chiplab performance/application test without trace files"
	@echo "  make chiplab-func   # run grouped Chiplab function tests"
	@echo "  make chiplab-perf   # run grouped Chiplab performance/application tests"
	@echo "  make chiplab-perf MDU_COLLECT=1"
	@echo "                      # collect retired mul/div/mod operands to mdu_collect.txt"
	@echo "  make configure RUN=coremark CPU=LA500"
	@echo "                      # run Chiplab with reference openLA500 core"
	@echo "  make chiplab-list   # list software names accepted by the wrapper"
	@echo "  make synth_timing_clean # clean Vivado timing artifacts"
	@echo "  make docs           # print docs index path"
	@echo "  make clean          # clean build artifacts"

clean:
	@rm -rf $(OBJ_DIR) wave.vcd wave.fst

runall:
	@bash run_all_tests.sh

func/% fireye/% c_prg/%:
	@:

my_program memset dhrystone coremark hello_world linux rtthread lacc:
	@:

--%:
	@:

.PHONY: test simu build run all fmax synth_timing synth_timing_clean clean runall docs help mycpu-sync-rtl configure chiplab-list chiplab-sync-rtl chiplab-configure chiplab-run chiplab-smoke chiplab-func-smoke chiplab-perf-smoke chiplab-func chiplab-perf chiplab-test-smoke

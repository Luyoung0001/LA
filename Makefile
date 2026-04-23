CPU_HOME = $(shell pwd)

EXP ?= 6

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

CPPSRC = $(CPU_HOME)/Verilator/*.cpp
SRC = $(CPPSRC) $(DPIC_C_SRC) $(MEM_SRC)

VSRC = $(VSRC_mycpu_env_vsrc) $(VSRC_dpic)/*.sv $(VSRC_dpic)/*.v

V_FLAGS = --cc $(VSRC) --Wno-UNOPTFLAT -Wno-fatal --exe $(SRC) $(SV_FLAGS) --top $(TOP)  --trace-fst --CFLAGS "$(INCFLAGS)" --LDFLAGS "-ldl"

OBJ_DIR = obj_dir

EXE = $(CPU_HOME)/$(OBJ_DIR)/V$(TOP)

test:
	$(MAKE) -C mycpu_env/func EXP=$(EXP)

trace:
	$(MAKE) -C mycpu_env/gettrace iverilog

simu: clean
	$(VERILATOR) $(V_FLAGS)

build: simu
	bear -- $(MAKE) -C $(OBJ_DIR) -f V$(TOP).mk -j10

run: build
	$(EXE)

all: test run

docs:
	@echo "Docs index: $(CPU_HOME)/docs/README.md"

help:
	@echo "Usage:"
	@echo "  make all EXP=6      # run test + dynamic difftest simulation"
	@echo "  make test EXP=6     # build func test program"
	@echo "  make trace          # generate golden trace"
	@echo "  make build          # build verilator executable"
	@echo "  make run            # run simulation"
	@echo "  make docs           # print docs index path"
	@echo "  make clean          # clean build artifacts"

clean:
	@rm -rf $(OBJ_DIR) wave.vcd wave.fst

runall:
	@bash run_all_tests.sh

.PHONY: test trace simu build run all clean runall docs help

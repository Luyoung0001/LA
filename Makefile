CPU_HOME = $(shell pwd)

## minicpu
VSRC_minicpu_env_miniCPU = $(CPU_HOME)/minicpu_env/miniCPU/*.v

VSRC_minicpu_env_soc_verify_rtl = $(CPU_HOME)/minicpu_env/soc_verify/rtl/*.v
VSRC_minicpu_env_soc_verify_rtl_xilinx_ip = $(CPU_HOME)/minicpu_env/soc_verify/rtl/xilinx_ip/*.v

VSRC_minicpu = $(VSRC_minicpu_env_miniCPU) $(VSRC_minicpu_env_soc_verify_rtl) $(VSRC_minicpu_env_soc_verify_rtl_xilinx_ip)

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

VSRC = $(VSRC_mycpu_env_vsrc) $(VSRC_dpic)/*.sv

V_FLAGS = --cc $(VSRC) --Wno-UNOPTFLAT --exe $(SRC) $(SV_FLAGS) --top $(TOP)  --trace-fst --CFLAGS "$(INCFLAGS)"

OBJ_DIR = obj_dir

EXE = $(CPU_HOME)/$(OBJ_DIR)/V$(TOP)

simu: clean
	$(VERILATOR) $(V_FLAGS)

build: simu
	bear -- make -C $(OBJ_DIR) -f V$(TOP).mk -j10

run: build
	$(EXE)

clean:
	@rm -rf $(OBJ_DIR)

runall:
	@bash run_all_tests.sh

.PHONY: simu build run




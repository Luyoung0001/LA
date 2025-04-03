CPU_HOME = $(shell pwd)
VSRC_minicpu_env_miniCPU = $(CPU_HOME)/minicpu_env/miniCPU/*.v

VSRC_minicpu_env_soc_verify_rtl = $(CPU_HOME)/minicpu_env/soc_verify/rtl/*.v
VSRC_minicpu_env_soc_verify_rtl_xilinx_ip = $(CPU_HOME)/minicpu_env/soc_verify/rtl/xilinx_ip/*.v

VSRC_minicpu = $(VSRC_minicpu_env_miniCPU) $(VSRC_minicpu_env_soc_verify_rtl) $(VSRC_minicpu_env_soc_verify_rtl_xilinx_ip)


VERILATOR = verilator
TOP = soc_mini_top

CPPSRC = $(CPU_HOME)/Verilator/*.cpp
SRC = $(CPPSRC)

V_FLAGS = --cc $(VSRC_minicpu) --top $(TOP) --exe $(SRC) --trace-fst

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




SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

REPO_ROOT := ..
RTL_DIR   := $(REPO_ROOT)/rtl
SIM_DIR   := $(REPO_ROOT)/sim
LA_DIR    := $(REPO_ROOT)/mycpu_env/myCPU
TEST_DIR  := tests

OBJ_DIR    = obj_dir_sv/$(if $(filter 1 yes true on,$(PERF_MONI)),perf,default)
OUTPUT_DIR := output
VERILATOR ?= verilator
EXTRA_PLUSARGS ?=
DEBUG_LEVEL ?= 1
DEBUG_WINDOW ?= 256
DEBUG_FATAL ?= 0
PERF_MONI ?= 0
DIFFTEST_EN ?= 0
DEBUG_FATAL_PLUSARG := $(if $(filter 1 yes true on,$(DEBUG_FATAL)),+DEBUG_FATAL,)
PERF_MONI_FLAG := $(if $(filter 1 yes true on,$(PERF_MONI)),-DPERF_MONI,)
DIFFTEST_EN_FLAG := $(if $(filter 1 yes true on,$(DIFFTEST_EN)),-DDIFFTEST_EN,)

TESTS := \
	cpu_tlb_tb \
	fetch_buffer_tb \
	la_bpu_adapter_tb \
	la_fetch_buffer_adapter_tb \
	s3_d1_fast_redirect_tb \
	s4_ex_forwarding_tb \
	s5_m1_tb

CASES := $(patsubst %_tb,%,$(TESTS))
CASE ?=
CASE_TB := $(if $(CASE),$(if $(filter %_tb,$(CASE)),$(CASE),$(CASE)_tb))
CASE_NAME := $(patsubst %_tb,%,$(CASE_TB))

ifneq ($(CASE),)
ifeq ($(filter $(CASE_TB),$(TESTS)),)
$(error Unknown CASE '$(CASE)'. Use 'make list' to show supported CASE values)
endif
endif

VFLAGS := \
	--binary \
	--sv \
	--timing \
	--trace \
	-DTB_DEBUG \
	-DCPU_DEBUG_CYCLE_DIV=4 \
	$(PERF_MONI_FLAG) \
	$(DIFFTEST_EN_FLAG) \
	-I$(RTL_DIR) \
	-I$(TEST_DIR) \
	--x-initial 0 \
	--x-assign 0 \
	-Wno-fatal \
	-Wno-DECLFILENAME \
	-Wno-UNUSED \
	-Wno-WIDTH \
	-Wno-PINCONNECTEMPTY \
	-Wno-PINMISSING \
	-Wno-BLKSEQ \
	-Wno-SYNCASYNCNET \
	-Wno-CASEINCOMPLETE

SRC_la_bpu_adapter_tb         := $(RTL_DIR)/cpu_bpu.v $(RTL_DIR)/la_bpu_adapter.v
SRC_cpu_tlb_tb                := $(RTL_DIR)/cpu_tlb.v
SRC_fetch_buffer_tb           := $(RTL_DIR)/fetch_buffer.v
SRC_la_fetch_buffer_adapter_tb := $(RTL_DIR)/fetch_buffer.v $(RTL_DIR)/la_fetch_buffer_adapter.v
SRC_s3_d1_fast_redirect_tb    := $(RTL_DIR)/s3_d1.v
SRC_s4_ex_forwarding_tb       := $(RTL_DIR)/s4_ex.v
SRC_s5_m1_tb                  := $(RTL_DIR)/s5_m1.v

BUILD_TARGETS := $(foreach test,$(TESTS),$(OBJ_DIR)/$(test)/V$(test))
RUN_TARGETS   := $(addprefix run-,$(CASES))

.PHONY: all build run clean list $(RUN_TARGETS) $(addprefix run-,$(TESTS))

all: run

build: $(BUILD_TARGETS)

ifneq ($(CASE),)
run: run-$(CASE_NAME)
else
run: $(RUN_TARGETS)
endif

list:
	@printf '%s\n' $(CASES)

define TEST_RULE
$(OBJ_DIR)/$(1)/V$(1): $(TEST_DIR)/$(1).sv $$(SRC_$(1)) $(TEST_DIR)/tb_common.svh $(RTL_DIR)/rtl_debug.vh Makefile
	@mkdir -p $(OBJ_DIR)/$(1)
	$(VERILATOR) $(VFLAGS) --top-module $(1) --Mdir $(OBJ_DIR)/$(1) $(TEST_DIR)/$(1).sv $$(SRC_$(1))

run-$(patsubst %_tb,%,$(1)): $(OBJ_DIR)/$(1)/V$(1)
	@mkdir -p $(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))
	@./$(OBJ_DIR)/$(1)/V$(1) +WAVE=$(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))/wave.vcd +TB_DEBUG +DEBUG_LEVEL=$(DEBUG_LEVEL) +DEBUG_WINDOW=$(DEBUG_WINDOW) $(DEBUG_FATAL_PLUSARG) $(EXTRA_PLUSARGS) 2>&1 \
		| tee >(awk '/^\[RTL-/{print}' > $(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))/debug.txt) \
		| awk '!/^\[RTL-/{print}' \
		| tee $(OUTPUT_DIR)/cases/$(patsubst %_tb,%,$(1))/log.txt

run-$(1): run-$(patsubst %_tb,%,$(1))
endef

$(foreach test,$(TESTS),$(eval $(call TEST_RULE,$(test))))

clean:
	rm -rf $(OBJ_DIR) obj_dir $(OUTPUT_DIR) logs wave.vcd wave.fst

CASE ?= set1a_alu
BENCH_REPEAT ?= 512
BENCH_UNROLL ?= 16
obj_root := ./obj
obj_path := $(obj_root)/repeat_$(BENCH_REPEAT)_unroll_$(BENCH_UNROLL)

LA_CC      ?= loongarch32r-linux-gnusf-gcc
LA_AS      ?= loongarch32r-linux-gnusf-as
LA_LD      ?= loongarch32r-linux-gnusf-ld
LA_OBJCOPY ?= loongarch32r-linux-gnusf-objcopy
LA_OBJDUMP ?= loongarch32r-linux-gnusf-objdump
LA_NM      ?= loongarch32r-linux-gnusf-nm

CASES := $(sort $(patsubst cases/%.S,%,$(wildcard cases/*.S)))
case_obj := $(obj_path)/$(CASE)
case_src := cases/$(CASE).S
all_bins := $(addprefix $(obj_path)/,$(addsuffix /main.bin,$(CASES)))

.PHONY: case all list clean help

case: $(case_obj)/main.bin $(case_obj)/test.s $(case_obj)/stop_pc.txt
	@echo "IPC microbench case: $(CASE)"
	@echo "  bin     : $(case_obj)/main.bin"
	@echo "  stop_pc : $$(cat $(case_obj)/stop_pc.txt)"

all: $(all_bins)
	@for case in $(CASES); do \
		$(MAKE) --no-print-directory CASE=$$case $(obj_path)/$$case/test.s $(obj_path)/$$case/stop_pc.txt >/dev/null; \
	done

list:
	@printf '%s\n' $(CASES)

$(obj_path)/%/main.s: cases/%.S include/bench_common.inc
	@mkdir -p $(dir $@)
	$(LA_CC) -Iinclude -I../func/include -nostdinc -nostdlib -D_KERNEL -fno-builtin -D__loongarch32 -DBENCH_REPEAT=$(BENCH_REPEAT) -DBENCH_UNROLL=$(BENCH_UNROLL) -S $< > $@

$(obj_path)/%/main.o: $(obj_path)/%/main.s
	$(LA_AS) -mabi=ilp32 -o $@ $<

$(obj_path)/%/main.elf: bin.lds $(obj_path)/%/main.o
	$(LA_LD) $(obj_path)/$*/main.o -T bin.lds -o $@

$(obj_path)/%/main.bin: $(obj_path)/%/main.elf
	$(LA_OBJCOPY) -O binary -j .text $< $@

$(obj_path)/%/test.s: $(obj_path)/%/main.elf
	$(LA_OBJDUMP) -alD $< > $@

$(obj_path)/%/stop_pc.txt: $(obj_path)/%/main.elf
	@$(LA_NM) $< | awk '$$3 == "__bench_stop" { print "0x" $$1 }' > $@
	@test -s $@ || { echo "missing __bench_stop in $<" >&2; exit 1; }

clean:
	rm -rf $(obj_path)

help:
	@echo "Usage:"
	@echo "  make -C mycpu_env/ipc_microbench list"
	@echo "  make -C mycpu_env/ipc_microbench CASE=set1a_alu case"
	@echo "  make -C mycpu_env/ipc_microbench CASE=set1a_alu BENCH_REPEAT=1024 BENCH_UNROLL=16 case"
	@echo "  make -C mycpu_env/ipc_microbench all"

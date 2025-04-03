obj_path = ./obj
LA_HOME = $(shell pwd)/../../..

xilinx_ip = $(LA_HOME)/minicpu_env/soc_verify/rtl/xilinx_ip

OBJDUMP = mips-linux-gnu-objdump

default:
	make all
	# make tidy

all:
	mkdir -p ${obj_path}
	make ${obj_path}/inst_ram.coe ${obj_path}/test.s sub

FLAGS_HDUMP = -v -e '4/1 "%02x " "\n"'
sub: $(obj_path)/main.bin $(obj_path)/main.data
	hexdump $(FLAGS_HDUMP) $(obj_path)/main.bin > $(obj_path)/main_inst.hex
	hexdump $(FLAGS_HDUMP) $(obj_path)/main.data > $(obj_path)/main_data.hex

	@echo "\nConverts a hex file (.hex) to a Verilog memory initialization file (.v)."
# 这里调用 python 脚本将 .hex 文件转换为 .v 文件
	@python3 $(LA_HOME)/scripts/build_instMemo.py $(obj_path)/main_inst.hex $(xilinx_ip)/inst_ram.v
	@python3 $(LA_HOME)/scripts/build_dataMemo.py $(obj_path)/main_data.hex $(xilinx_ip)/data_ram.v
	@echo "\nBuild done."

tidy:
	rm -f ${obj_path}/convert ${obj_path}/main.bin ${obj_path}/main.data ${obj_path}/main.elf
	rm -f ${obj_path}/start.s ${obj_path}/start.o

${obj_path}/test.s: ${obj_path}/main.elf
	loongarch32r-linux-gnusf-objdump -alD ${obj_path}/main.elf > ${obj_path}/test.s

${obj_path}/start.o: ${obj_path}/start.s
	loongarch32r-linux-gnusf-as -mabi=ilp32 ${obj_path}/start.s -o ${obj_path}/start.o

${obj_path}/inst_ram.coe ${obj_path}/inst_ram.mif: ${obj_path}/main.bin ${obj_path}/main.data ${obj_path}/convert
	cd ${obj_path} && ./convert

${obj_path}/convert: convert.c
	gcc ./convert.c -o ${obj_path}/convert

${obj_path}/main.bin: ${obj_path}/main.elf
	loongarch32r-linux-gnusf-objcopy -O binary -j .text ${obj_path}/main.elf ${obj_path}/main.bin

${obj_path}/main.data: ${obj_path}/main.elf
	loongarch32r-linux-gnusf-objcopy -O binary -j .data ${obj_path}/main.elf ${obj_path}/main.data

${obj_path}/main.elf: ${obj_path}/start.o
	loongarch32r-linux-gnusf-ld ${obj_path}/start.o -T bin.lds -o ${obj_path}/main.elf

${obj_path}/start.s: start.S
	@mkdir -p ${obj_path}
	loongarch32r-linux-gnusf-gcc \
		-S start.S > ${obj_path}/start.s

# ${obj_path}/init.s: init.S
# 	@mkdir -p ${obj_path}
# 	loongarch32r-linux-gnusf-gcc \
# 		-Iinclude -nostdinc -nostdlib -D_KERNEL -fno-builtin -D__loongarch32\
# 		-DMEMSTART=0x10000000 -DMEMSIZE=0x04000 -DCPU_COUNT_PER_US=1000 -DEXP=$(EXP)    \
# 		-S init.S > ${obj_path}/init.s

clean:
	rm -rf obj

help:
	@echo "################################################################"
	@echo "### help for compiling func"
	@echo "################################################################"
	@echo "### options:"
	@echo "###     make      : get compiled result, which is saved in ./obj"
	@echo "###     make clean: remove *.o, *.a, and ./obj"
	@echo "###     make help : show help information"
	@echo "###############################################################"


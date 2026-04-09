# myCPU 文档索引

## 总览
- [系统总拓扑与模块连接图](./00_system_topology.md)

## 硬件模块（mycpu_env/myCPU/v_src + DPIC）
- [core_top](./hardware/core_top.md)
- [mycpu_top](./hardware/mycpu_top.md)
- [verilator_top](./hardware/verilator_top.md)
- [stage0_ifu](./hardware/stage0_ifu.md)
- [stage1_if1](./hardware/stage1_if1.md)
- [stage2_if2](./hardware/stage2_if2.md)
- [stage3_idu](./hardware/stage3_idu.md)
- [stage4_rrd](./hardware/stage4_rrd.md)
- [stage5_ex1](./hardware/stage5_ex1.md)
- [stage6_ex2](./hardware/stage6_ex2.md)
- [stage7_mem1](./hardware/stage7_mem1.md)
- [stage8_wbu](./hardware/stage8_wbu.md)
- [branch_predictor_d1](./hardware/branch_predictor_d1.md)
- [regfile_d1](./hardware/regfile_d1.md)
- [muldiv_stub](./hardware/muldiv_stub.md)
- [csr_stub](./hardware/csr_stub.md)
- [icache_stub](./hardware/icache_stub.md)
- [dcache_stub](./hardware/dcache_stub.md)
- [axi_ram](./hardware/axi_ram.md)
- [inst_ram](./hardware/inst_ram.md)
- [data_ram](./hardware/data_ram.md)
- [sram_wrap](./hardware/sram_wrap.md)

## 软件 SoC / 仿真侧模块（DPIC_C + memory + Verilator）
- [dpi_c.cpp](./software/dpi_c.md)
- [paddr.c](./software/paddr.md)
- [Verilator 主程序 main.cpp](./software/verilator_main.md)
- [软件 SoC 如何连接 mycpu](./software/soc_integration.md)

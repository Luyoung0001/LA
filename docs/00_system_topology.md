# 系统总拓扑与模块连接图

## 1. 总体说明
- 当前 `core_top` 已改为真实串接 `stage0~stage8`。
- CPU 对外只暴露 AXI 主接口，仿真中由 `verilator_top -> axi_ram -> DPI-C -> paddr` 完成“软件 SoC”。
- 分支预测器为 1 拍返回（`branch_predictor_d1`），寄存器堆读为 1 拍返回（`regfile_d1`）。

## 2. 全链路 Mermaid 图
```mermaid
flowchart LR
    subgraph HW_CPU[myCPU 硬件核心]
        S0["stage0_ifu<br/>PC 产生"]
        BP["branch_predictor_d1<br/>1-cycle resp"]
        S1["stage1_if1<br/>发起取指"]
        S2["stage2_if2<br/>等待取指返回"]
        S3["stage3_idu<br/>译码"]
        RF["regfile_d1<br/>1-cycle 读/写回"]
        S4["stage4_rrd<br/>读数对齐"]
        S5["stage5_ex1<br/>ALU/地址计算"]
        MD["muldiv_stub<br/>1-cycle 空壳"]
        S6["stage6_ex2<br/>分支决策/EX2"]
        S7["stage7_mem1<br/>访存发射与等待"]
        S8["stage8_wbu<br/>写回/调试"]
        CT["core_top<br/>流水整合+AXI主控"]

        S0 -- bp_req --> BP
        BP -- pred --> S0
        S0 --> S1 --> S2 --> S3 --> S4 --> S5 --> S6 --> S7 --> S8
        S3 -- 读请求 --> RF
        RF -- 读数据 --> S4
        S8 -- 写回 --> RF
        S5 -- mul/div req --> MD
        MD -- resp --> S6
        S6 -- branch_update --> BP
        CT -.例化/连接.- S0
        CT -.例化/连接.- S8
    end

    subgraph TB_TOP[仿真硬件顶层]
        VT[verilator_top]
        AXI["axi_ram.sv<br/>AXI从设备模型"]
    end

    subgraph SW_SOC[软件 SoC (C/C++)]
        DPI["dpi_c.cpp<br/>DPI 读写桥"]
        MEM["paddr.c<br/>pmem + 装载镜像"]
        BIN[func/obj/main.bin]
        DIF[golden_trace.txt]
        MAIN["Verilator/main.cpp<br/>时钟驱动+diff"]
    end

    CT -- AXI总线 --> VT
    VT -- AXI信号 --> AXI
    AXI -- DPI-C 调用 --> DPI
    DPI -- 读写 --> MEM
    MEM -- load_inst --> BIN
    MAIN -- 读取 debug_wb_* --> VT
    MAIN -- 对比 --> DIF
```

## 3. 时序主线（按指令）
- 取指：`stage1_if1` 发请求；`core_top` AXI 控制器完成 `AR->R`；`stage2_if2` 在收到 `icache_resp_valid` 当拍输出 `out_valid`。
- 译码+读寄存器：`stage3_idu` 发读地址；`regfile_d1` 下一拍给 `rvalid/rdata`；`stage4_rrd` 对齐后送执行。
- 执行：`stage5_ex1` 组合计算，拍末寄存；`stage6_ex2` 做分支决策并回写 BP 表项。
- 访存：`stage7_mem1` 对 load/store 先发请求，再等待 `dcache_resp_valid` 后提交。
- 写回：`stage8_wbu` 产生 `rf_we/rf_waddr/rf_wdata` 与 `debug_wb_*`。
- 当前实现为“单在途指令”控制：`issue_busy_r` 在发射后置位，直到 `wbu_ws_valid_w` 清零，确保时序正确性优先。

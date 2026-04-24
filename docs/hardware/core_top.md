# core_top 模块文档

- 源文件：`mycpu_env/myCPU/v_src/mycpu_top.v`（`module core_top`）
- 功能定位：CPU 主体（9 级流水 + AXI 仲裁 + 调试接口）

## 架构总览
流水级连接：
`stage0_ifu -> stage1_if1 -> stage2_if2 -> stage3_idu -> stage4_rrd -> stage5_ex1 -> stage6_ex2 -> stage7_mem1 -> stage8_wbu`

关键子模块：
- 预测器：`branch_predictor_d1`
- 寄存器堆：`regfile_d1`
- 乘除占位：`muldiv_stub`
- 访存桥：`icache_stub/dcache_stub`（all-miss forwarding 到 AXI）

## 发射与在途控制（重要）
- `issue_fire_w = ifu_out_valid_w && !issue_busy_r`
- `issue_busy_r` 在发射后置 1，在 `wbu_ws_valid_w` 置 0。

含义：
- 当前是“单在途指令”控制模型，避免多条指令并发穿越流水。
- 该策略降低控制复杂度，也降低了前端/访存时序压力。

## 分支重定向路径
- EX2 输出：`ex2_branch_update_valid_w/ex2_branch_taken_w/ex2_branch_target_w`
- IFU 输入：`redirect_valid/redirect_pc`
- 重定向 PC：`taken ? target : (ex2_out_pc_w + 4)`

时序特性：
- 分支结果在 EX2 拍寄存，下一拍生效到 IFU 的 PC 更新。

## AXI 状态机
状态定义：
- `AXI_IDLE`
- 取指读：`AXI_I_AR -> AXI_I_R`
- 数据读：`AXI_D_AR -> AXI_D_R`
- 数据写：`AXI_D_AW -> AXI_D_W -> AXI_D_B`

仲裁策略：
- 在 `AXI_IDLE` 下，先看 ICache 请求，再看 DCache 请求（I 优先）。

关键握手：
- AR/AW/W 成功握手后，向对应 cache stub 回送 `*_axi_req_ready_r` 脉冲。
- R/B 成功握手后，向 stub 回送 `*_axi_resp_valid_r` 脉冲并携带数据。

## 时序实测（2026-04-24，Vivado 实现后）
来源：`vivado_timing/timing_summary.rpt`、`vivado_timing/critical_path.rpt`、`vivado_timing/high_fanout.rpt`

全局指标（200MHz 目标）：
- `WNS = -0.098ns`
- `TNS = -0.282ns`
- `Setup Failing Endpoints = 5`
- Hold 全满足（`WHS = 0.043ns`）

最差路径：
- `u_stage4_rrd/out_op1_reg[1] -> u_stage5_ex1/out_alu_result_reg[30]`
- `Data Path Delay = 4.809ns`（logic 2.479ns + route 2.330ns）
- `Logic Levels = 11`（`CARRY4=8`）

路由主导路径示例：
- `u_stage4_rrd/out_inst_reg[27] -> u_stage5_ex1/out_alu_result_reg[6]`
- `Data Path Delay = 4.999ns`，其中 `route = 4.047ns (80.955%)`

高扇出热点：
- `u_stage4_rrd/out_inst_reg[31]_0[14]` fanout 112
- `u_stage4_rrd/out_inst_reg[31]_0[13]` fanout 112
- `u_stage4_rrd/out_inst_reg[31]_0[12]` fanout 104
- `u_stage4_rrd/out_op1_reg[31]_0[31]` fanout 55

## 收敛建议（按优先级）
1. 结构优先：把 EX1 的重复指令译码前移到 IDU，跨级传 `alu_op` 控制。
2. 缩短组合链：合并 EX1 加减/比较通路，降低 carry+mux 串接。
3. 缓解布线：对 `out_inst` 热点控制网进行寄存复制或扇出约束。
4. 物理试探：在 RTL 不变前提下增加 impl seed 扫描，争取吃掉 <0.1ns 余量。

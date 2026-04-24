# stage5_ex1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage5_ex1.v`
- 功能定位：执行一级（ALU/地址生成/link 值计算）

## 功能行为
- 以 `in_inst` 再次译码（`inst_add_w/.../inst_lu12i_w`）。
- 组合计算 `ex_result`：
  - `add/sub/addi/ld/st`
  - `slt/sltu`
  - `and/or/xor/nor`
  - `slli/srli/srai`
  - `lu12i` 直接取 `in_imm`
  - `bl/jirl` 写回 `in_pc + 4`
- 时钟上升沿寄存到 `out_alu_result`，并透传其余流水信息。

## 时序语义
- 关键计算在 `always @(*)` 完成，属于本核最重的组合级之一。
- `in_use_imm` 当前未参与运算分支选择（属于可优化冗余输入）。

## 当前关键路径（重点）
基于 `vivado_timing/critical_path.rpt`（2026-04-24）：
- 最差路径：
  - `Source: u_stage4_rrd/out_op1_reg[1]/C`
  - `Dest  : u_stage5_ex1/out_alu_result_reg[30]/D`
  - `Slack : -0.098ns`
  - `Data Path Delay: 4.809ns (logic 2.479ns, route 2.330ns)`
  - `Logic Levels: 11 (CARRY4=8, LUT2=1, LUT4=1, LUT6=1)`
- 另有明显路由主导路径：
  - `out_inst_reg[27] -> out_alu_result_reg[6]`
  - `Data Path Delay: 4.999ns`，其中 `route=4.047ns (80.955%)`

## 优化建议
1. 结构优化：在 IDU 生成 `alu_op`，EX1 改为 `case(alu_op)`，删除重复译码。
2. 算术通路优化：合并 `add/sub/addr` 通路，降低 carry+mux 串接层级。
3. 物理优化：对来自 stage4 的热点控制信号做扇出控制或寄存复制。

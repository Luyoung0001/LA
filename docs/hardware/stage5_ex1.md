# stage5_ex1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage5_ex1.v`
- 角色：执行一级（ALU/地址/链接值）

## 功能
- 基于 `in_inst` 再次判型，计算 `ex_result`：
  - ALU 运算（add/sub/slt/sltu/and/or/xor/nor/shift）
  - 地址类（`addi/ld/st`）用 `op1 + imm`
  - `lu12i` 直接用 `imm`
  - `bl/jirl` 写回值为 `pc+4`
- 输出 `out_alu_result` 给 EX2。

## 时序
- `ex_result` 组合计算。
- 时钟上升沿寄存到 `out_*`。

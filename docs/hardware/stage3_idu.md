# stage3_idu 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage3_idu.v`
- 角色：译码级（EXP=6 指令集）

## 功能
- 对 `n1~n20` 指令精确译码：
  - 算术逻辑：`lu12i/add/addi/sub/slt/sltu/and/or/xor/nor/slli/srli/srai`
  - 访存：`ld.w/st.w`
  - 分支跳转：`beq/bne/bl/jirl/b`
- 生成：
  - 读寄存器地址 `rf_raddr1/rf_raddr2`
  - 目的寄存器 `out_rd`（`bl` 强制 `r1`）
  - 立即数 `out_imm`（含分支偏移、imm20<<12、移位立即数）
  - 控制位 `out_use_imm/out_is_branch/out_is_load/out_is_store`

## 时序
- 时钟上升沿输出译码结果。
- 与 `regfile_d1` 配合：本拍发读地址，下一拍拿读数据。

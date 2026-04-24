# stage3_idu 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage3_idu.v`
- 功能定位：译码级（IDU），生成寄存器读地址与执行控制元信息

## 指令覆盖
- 算术/逻辑：`lu12i/add/addi/sub/slt/sltu/and/or/xor/nor/slli/srli/srai`
- 访存：`ld.w/st.w`
- 分支：`jirl/b/bl/beq/bne`

## 主要输出
- 寄存器读地址：`rf_raddr1/rf_raddr2`
- 写回目的寄存器：`out_rd`（`bl` 强制 `r1`）
- 立即数：`out_imm`（含符号扩展、分支偏移、`imm20<<12`、移位立即数）
- 控制位：`out_use_imm/out_is_branch/out_is_load/out_is_store/out_is_muldiv`

## 时序语义
- 译码是组合逻辑，结果在拍末寄存输出。
- 与 `regfile_d1` 构成固定 1 拍握手：
  - 第 N 拍发 `rf_req_valid/raddr*`
  - 第 N+1 拍在 `stage4_rrd` 看到 `rf_rvalid/rdata*`

## 时序风险与观察
- 本级译码较宽（大量 opcode 比较），但当前不是最差路径。
- `out_use_imm` 目前在 EX1 中未参与运算选择，保留该信号主要用于接口兼容与后续优化。

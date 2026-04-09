# stage4_rrd 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage4_rrd.v`
- 角色：寄存器读结果对齐级

## 功能
- 将 IDU 元信息打一拍进入 `meta_*_d1`。
- 在 `meta_valid_d1 && rf_rvalid` 时输出：
  - `out_op1 = rf_rdata1`
  - `out_op2 = rf_rdata2`
  - 透传 PC/inst/rd/imm/control。

## 时序
- 固定一拍元信息缓存。
- 只在 regfile 返回有效时提交，有效避免读数未就绪。

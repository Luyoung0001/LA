# IPC Microbenchmarks

This directory contains standalone LA32 microbenchmarks for theoretical IPC
debugging. They are intentionally separate from `mycpu_env/func` so EXP6/EXP23
remain functional correctness regressions.

Build one case:

```sh
make -C mycpu_env/ipc_microbench CASE=set1a_alu case
```

Default length is `BENCH_REPEAT=512` and `BENCH_UNROLL=16`. The code body stays
small enough for the current 8KB L1I while dynamic instruction count is large
enough to dilute startup/fill/stop overhead. Use smaller values for smoke tests
and larger values when fixed overhead is still visible:

```sh
make -C mycpu_env/ipc_microbench CASE=set1a_alu BENCH_REPEAT=64 BENCH_UNROLL=8 case
make ipcbench-run IPC_CASE=set1a_alu BENCH_REPEAT=1024 BENCH_UNROLL=16
```

Run one case through the existing Verilator/difftest executable:

```sh
make ipcbench-run IPC_CASE=set1a_alu BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1
```

List cases:

```sh
make -C mycpu_env/ipc_microbench list
```

Each build emits:

- `obj/repeat_<N>_unroll_<M>/<case>/main.bin`: image loaded through `LA_MAIN_BIN`
- `obj/repeat_<N>_unroll_<M>/<case>/stop_pc.txt`: `LA_STOP_PC` for pass detection
- `obj/repeat_<N>_unroll_<M>/<case>/test.s`: disassembly for instruction inspection

Instruction spellings and operand forms were cross-checked against EXP23
sources/disassembly in `mycpu_env/func/inst/*.S` and
`mycpu_env/func/obj/test.s`.

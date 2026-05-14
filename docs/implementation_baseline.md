# LA Implementation Baseline

Date: 2026-05-13 22:50:59 CST

This file records the A0 baseline before the architecture-skeleton work starts.

## Build And Test

Command:

```sh
make all EXP=6
```

Result:

- Passed.
- Stop PC: `0x1c000100`.
- Committed instructions: `11990`.
- Difftest reference: `toolchains/nemu/la32r-nemu-interpreter-so`.

## Current RTL Boundary

Primary RTL directory after A0.0/A0 shell migration:

```text
rtl/
```

`mycpu_env/myCPU/v_src/` and `chiplab/myCPU/` are symlink mirrors for
Verilator/Chiplab entry compatibility.

Current project RTL modules:

```text
backend_top.v
branch_predictor_d1.v
commit_unit.v
csr.v
dcache_stub.v
frontend_top.v
icache_stub.v
la_core_defs.vh
memsys_top.v
muldiv_stub.v
mycpu_top.v
redirect_ctrl.v
regfile_d1.v
stage0_ifu.v
stage1_if1.v
stage2_if2.v
stage3_idu.v
stage4_rrd.v
stage5_ex1.v
stage6_ex2.v
stage7_mem1.v
stage8_wbu.v
```

## Current Core Shape

- `core_top` is the actual CPU top used by Verilator and timing synthesis.
- `mycpu_top` is a board-facing wrapper around `core_top`.
- The pipeline is currently:

```text
stage0_ifu
  -> stage1_if1
  -> stage2_if2
  -> stage3_idu
  -> stage4_rrd
  -> stage5_ex1
  -> stage6_ex2
  -> stage7_mem1
  -> stage8_wbu
```

- `issue_busy_r` keeps the core in a single-in-flight mode: a new instruction is issued only after WBU commits the previous instruction.
- `stage8_wbu` is the current architectural writeback/debug point.
- `icache_stub` and `dcache_stub` are all-miss pass-through units to the AXI state machine in `core_top`.
- `csr_stub` exists but is not yet integrated into the main pipeline.

## A0 Progress Snapshot

Date: 2026-05-14 14:29:20 CST

Goal:

- Start executing the new blueprint without breaking the current EXP baseline.
- Turn the planned top-level boundaries into real wrappers on the existing runnable path.

Changed modules:

- `frontend_top.v`: now wraps `branch_predictor_d1`, `stage0_ifu`, `stage1_if1`, and `stage2_if2`.
- `backend_top.v`: now wraps `stage3_idu`, `regfile_d1`, `stage4_rrd`, `stage5_ex1`, `muldiv_stub`, `stage6_ex2`, `stage7_mem1`, and `commit_unit`.
- `memsys_top.v`: now wraps `icache_stub`, `dcache_stub`, and the all-miss AXI state machine that used to live in `core_top`.
- `mycpu_top.v`: `core_top` now connects `redirect_ctrl`, `frontend_top`, `backend_top`, and `memsys_top` instead of directly hosting frontend/backend/memsys internals.

Current runnable status:

- `make build CPU=PIPELINE SIM_JOBS=4`: passed.
- `make all EXP=6 CPU=PIPELINE`: passed.
- `make build CPU=LA500 SIM_JOBS=4`: passed; reference width warnings remain unchanged.
- `make mycpu-sync-rtl && make chiplab-sync-rtl`: passed.

Latest EXP=6 result after the wrapper split:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

Notes:

- This is still the old conservative single-in-flight behavior.
- Performance is not meaningful yet; A0 is preserving correctness while moving logic under the final boundaries.
- The old all-miss AXI path is now in `memsys_top`, which is the replacement point for copied L1/L2/AXI modules in A2.

## Interfaces To Preserve

Do not break these external contracts during A1-A8:

- `core_top` AXI master interface.
- `core_top` debug/difftest outputs:
  - `ws_valid`
  - `debug0_wb_pc`
  - `debug0_wb_rf_wen`
  - `debug0_wb_rf_wnum`
  - `debug0_wb_rf_wdata`
  - `debug0_wb_inst`
- `mycpu_top` board-facing AXI and debug outputs.
- Verilator public debug wires in `verilator_top`.

## Known Worktree State

Before A1 edits, the worktree already contained local/untracked planning and reference files:

```text
M Makefile
?? LA.txt
?? blueprint.md
?? plan.md
?? planx.md
?? reference_cpu/
```

Those files are treated as user/project context and must not be reverted as part of the skeleton work.

## A1 Progress Snapshot

Date: 2026-05-14 14:38:36 CST

Goal:

- Add the feature-switch contract required by the new blueprint.
- Keep the current conservative implementation runnable while giving TLB,
  L1I, L1D, L2, BPU, ITCM, and cache-op behavior stable configuration entry
  points.

Changed modules:

- `Makefile`: adds `TLB_ENABLE`, `L1I_ENABLE`, `L1D_ENABLE`, `L2_ENABLE`,
  `BPU_ENABLE`, `ITCM_ENABLE`, and `CACHE_OP_STRICT_ENABLE`, passed as
  `-DLA_*` defines to Verilator and Chiplab `VFLAGS`.
- `la_core_defs.vh`: defines default feature macros and shared architectural
  constants for future packet/module contracts.
- `mycpu_top.v`: exposes the feature parameters on `core_top` and passes them
  to frontend/backend/memsys wrappers.
- `frontend_top.v`: gates BPU behavior; when `BPU_ENABLE=0`, the frontend uses
  a fixed not-taken path.
- `backend_top.v`: anchors `TLB_ENABLE` and strict cache-op configuration.
- `memsys_top.v`: anchors ITCM/L1I/L1D/L2/cache-op configuration while still
  using the current all-miss stubs.

Configuration status:

```text
BASE_SAFE   : TLB=0 L1I=0 L1D=0 L2=0 BPU=0 ITCM=0 CACHE_OP_STRICT=0
ALL_STUB_ON : TLB=1 L1I=1 L1D=1 L2=1 BPU=1 ITCM=1 CACHE_OP_STRICT=1
```

Current runnable status:

- `make build CPU=PIPELINE SIM_JOBS=4`: passed.
- `make build CPU=PIPELINE SIM_JOBS=4 TLB_ENABLE=1 L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1 BPU_ENABLE=1 ITCM_ENABLE=1 CACHE_OP_STRICT_ENABLE=1`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 TLB_ENABLE=1 L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1 BPU_ENABLE=1 ITCM_ENABLE=1 CACHE_OP_STRICT_ENABLE=1`: passed.
- `make mycpu-sync-rtl && make chiplab-sync-rtl`: passed.

Latest EXP=6 result for both `BASE_SAFE` and `ALL_STUB_ON`:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

Notes:

- `ALL_STUB_ON` is intentionally not a real cache/TLB/L2-on configuration yet.
  It proves that the switch plumbing compiles and preserves the current safe
  behavior.
- At the end of A1, `BPU_ENABLE=1` still selected the existing
  `branch_predictor_d1`; copied reference `cpu_bpu` integration is an A2 task.
- L1I/L1D/L2/ITCM/TLB switches are replacement points only; the path remains
  the current all-miss/direct behavior until copied modules and LA wrappers are
  connected.

## A2a Progress Snapshot

Date: 2026-05-14 14:47:12 CST

Goal:

- Start importing the reusable reference RTL from
  `/home/luyoung/demos/fpga-pipeline-cpu` in a traceable way.
- Prove at least one copied module can be adapted into the current LA/Chiplab
  flow without breaking the `BASE_SAFE` path.

Reference source:

```text
repo: /home/luyoung/demos/fpga-pipeline-cpu
head: 2f4b0c5c86c3f5ee59518b3fb7597546249ea0f7
```

Copied original reference files:

```text
rtl/copied_from_ref/axi_arbiter.v
rtl/copied_from_ref/cpu_bpu.v
rtl/copied_from_ref/cpu_defs.vh
rtl/copied_from_ref/cpu_l1_dcache.v
rtl/copied_from_ref/cpu_l1_icache.v
rtl/copied_from_ref/cpu_l2_cache.v
rtl/copied_from_ref/cpu_primitives.v
rtl/copied_from_ref/fetch_buffer.v
rtl/copied_from_ref/rtl_debug.vh
```

Changed modules:

- `cpu_bpu.v`: copied into the active RTL root as the first enabled reference
  module.
- `rtl_debug.vh`: copied into the active RTL root for reference-module debug
  macros.
- `la_bpu_adapter.v`: new LA wrapper that maps the current frontend's simple
  BPU lookup/update contract onto reference `cpu_bpu`.
- `frontend_top.v`: `BPU_ENABLE=1` now instantiates `la_bpu_adapter` and the
  copied `cpu_bpu`; `BPU_ENABLE=0` remains fixed not-taken.
- `Verilator/main.cpp`: now calls `Verilated::commandArgs(argc, argv)` so
  reference RTL debug macros using `$test$plusargs` work under Verilator.
- `Makefile`: suppresses `TIMESCALEMOD` warnings introduced by copied
  reference files with explicit `timescale`.

Current runnable status:

- `make build CPU=PIPELINE SIM_JOBS=4`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 BPU_ENABLE=1`: passed.

Latest copied-BPU EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

Notes:

- This does not yet improve IPC because the core is still globally
  single-in-flight and every branch resolves by redirect.
- The first copied module is now genuinely in the active LA flow, not only
  archived.
- L1I/L1D/L2/AXI copied files remain original reference copies only; they are
  not active until wrapper interfaces are added.

## A2a/A2b Reference-Module Parse And Fetch-Buffer Snapshot

Date: 2026-05-14 15:05:00 CST

Goal:

- Move the major copied reference modules into the active `rtl/` source root so
  Verilator and Chiplab parse them through the normal LA build.
- Add a guarded adapter for the copied `fetch_buffer.v`.
- Preserve the current conservative execution behavior unless the new switch is
  explicitly enabled.

Active copied modules in `rtl/`:

```text
axi_arbiter.v
cpu_bpu.v
cpu_defs.vh
cpu_l1_dcache.v
cpu_l1_icache.v
cpu_l2_cache.v
cpu_primitives.v
fetch_buffer.v
rtl_debug.vh
```

Changed modules:

- `Makefile`: adds `FETCH_BUFFER_ENABLE`, passed as
  `-DLA_FETCH_BUFFER_ENABLE`.
- `la_core_defs.vh`: defines the default `LA_FETCH_BUFFER_ENABLE` switch.
- `frontend_top.v`: can now select either direct IF2-to-decode delivery or the
  copied fetch buffer through an LA adapter.
- `la_fetch_buffer_adapter.v`: new wrapper around copied `fetch_buffer.v`,
  using single-slot entries and always-ready readout for the current
  single-in-flight frontend/backend contract.
- `mycpu_top.v`: passes `FETCH_BUFFER_ENABLE` to `frontend_top`.

Current runnable status:

- `make build CPU=PIPELINE SIM_JOBS=4`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 FETCH_BUFFER_ENABLE=1`: passed.

Latest copied-fetch-buffer EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

Notes:

- `FETCH_BUFFER_ENABLE=1` currently proves integration, not performance. The
  adapter consumes one slot at a time and keeps `rd_allowin_i=1` because the LA
  backend still lacks a real decode/issue `allowin` contract.
- The next useful frontend step is to make D1 expose a consume/allowin signal;
  after that, the copied fetch buffer can absorb I-cache response bursts instead
  of behaving as an equivalent pass-through.
- Copied L1I/L1D/L2/AXI modules are now active parse-time sources, but remain
  uninstantiated until LA wrappers map the current all-miss request/response
  path onto their line/refill interfaces.

## A2b Copied L1I Smoke Snapshot

Date: 2026-05-14 15:28:00 CST

Goal:

- Instantiate the copied `cpu_l1_icache.v` behind the existing `L1I_ENABLE`
  switch.
- Keep `L1I_ENABLE=0` on the old `icache_stub` all-miss path.
- Use a small LA adapter instead of modifying the copied ICache internals.

Changed modules:

- `memsys_top.v`: selects `la_l1i_adapter` when `L1I_ENABLE=1`; otherwise
  keeps `icache_stub`.
- `la_l1i_adapter.v`: new wrapper around copied `cpu_l1_icache.v`. It maps the
  copied ICache 16B line-miss interface onto the current LA single-word AXI
  FSM by issuing four word reads per line fill.

Important adapter note:

- Copied `cpu_l1_icache` can return same-cycle fastbuf/linebuf hits under its
  native ready/valid contract.
- The current LA `stage2_if2` is still the old all-miss style and expects a
  response after a pending request has already been registered.
- Therefore `la_l1i_adapter` registers the ICache CPU-side response by one
  cycle. This is an intentional compatibility shim for the current frontend,
  not a permanent target interface.

Current runnable status:

- `make build CPU=PIPELINE SIM_JOBS=4 L1I_ENABLE=1`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 L1I_ENABLE=1`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4`: passed after the L1I adapter change.

Latest `L1I_ENABLE=1` EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 223666
Total cycles: 223667
IPC: 0.053607
CPI: 18.654379
```

Latest default `L1I_ENABLE=0` EXP=6 result remains:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

Notes:

- `L1I_ENABLE=1` is functionally correct for EXP=6, but it is not a performance
  win yet. The current bridge performs four single-word AXI reads per cold line
  and the core remains globally single-in-flight.
- The next cache step should either connect copied L2/burst paths or first
  introduce a real frontend consume/allowin contract so the copied ICache and
  fetch buffer can use their native response behavior.

## Chiplab Migration Smoke Snapshot

Date: 2026-05-14 15:40:36 CST

Goal:

- Make the relocated `rtl/` tree usable from Chiplab through the
  `chiplab/myCPU` symlink mirror.
- Preserve single-commit LA behavior while satisfying Chiplab's optional
  two-commit debug harness.
- Keep Verilator's Chiplab top selection stable when copied reference modules
  add many unrelated module definitions to the source set.

Changed modules:

- `mycpu_top.v`: `core_top` now exposes inactive `debug1_*` outputs for the
  Chiplab `CPU_2CMT` harness. Slot 1 is tied off:
  `pc=0`, `rf_wen=0`, `rf_wnum=0`, `rf_wdata=0`.
- `mycpu_top.v`: board-facing `mycpu_top` wrapper forwards those inactive
  `debug1_*` outputs without changing the existing `debug_wb_*` interface.
- `chiplab/sims/verilator/run_prog/Makefile`: Verilator now uses
  `--top-module ${SIMU_TOP_NAME}` so `simu_top` remains the C++ model top even
  when copied RTL and primitive/helper modules are present.

Chiplab status:

- `make mycpu-sync-rtl && make chiplab-sync-rtl`: passed.
- `make configure RUN=hello_world CHIPLAB_OPTS='--output-nothing'`:
  Verilog compile passed, C++ testbench compile passed, hello_world software
  compile passed, and simulation started.
- The hello_world run was manually terminated after startup because the current
  CPU baseline is still the conservative EXP=6-era path and the Chiplab
  generated `Makefile_run` sets `TIME_LIMIT=0` for this program.

Local regression after Chiplab compatibility changes:

```text
make all EXP=6 CPU=PIPELINE SIM_JOBS=4

Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

Notes:

- Chiplab compile/startup integration is now unblocked.
- Chiplab full software completion is not expected yet; it belongs to the A3/A4
  instruction/CSR/TLB/system-software work, not this A2 integration smoke.
- Next Chiplab environment task: add a bounded smoke target or wrapper option so
  startup checks cannot leave an unlimited simulation running.

## A2b Copied L1D Smoke Snapshot

Date: 2026-05-14 16:05:30 CST

Goal:

- Instantiate the copied `cpu_l1_dcache.v` behind the existing `L1D_ENABLE`
  switch.
- Keep `L1D_ENABLE=0` on the old `dcache_stub` all-miss path.
- Reuse the copied DCache internals through an LA adapter rather than editing
  the reference module.

Changed modules:

- `memsys_top.v`: selects `la_l1d_adapter` when `L1D_ENABLE=1`; otherwise
  keeps `dcache_stub`.
- `la_l1d_adapter.v`: new wrapper around copied `cpu_l1_dcache.v`. It maps the
  copied DCache line-miss read interface onto four single-word AXI reads and
  maps the copied write-through channel onto the current single-word AXI write
  path.

Current runnable status:

- `make build CPU=PIPELINE SIM_JOBS=4 L1D_ENABLE=1`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 L1D_ENABLE=1`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4`: passed after the L1D adapter
  change.

Latest `L1D_ENABLE=1` EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209318
Total cycles: 209319
IPC: 0.057281
CPI: 17.457715
```

Latest default `L1D_ENABLE=0` EXP=6 result remains:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

Notes:

- `L1D_ENABLE=1` is functionally correct for EXP=6 with the current
  single-in-flight backend.
- This is still a compatibility bridge: line fills are four single-word reads,
  stores use the existing single-word AXI write path, and copied L2/burst
  behavior is not active yet.
- The current `stage7_mem1` still does not consume `dmem_req_ready`; the L1D
  adapter therefore preserves an always-ready CPU-side request contract for now.
- `make chiplab-smoke RUN=hello_world CHIPLAB_OPTS='--output-nothing'
  L1D_ENABLE=1`: passed. This compiles Chiplab Verilator and software without
  starting the long hello_world simulation.

## A2b Copied L2/AXI Arbiter Smoke Snapshot

Date: 2026-05-14 16:22:57 CST

Goal:

- Instantiate the copied `cpu_l2_cache.v` and `axi_arbiter.v` behind the
  existing `L2_ENABLE` switch.
- Preserve the current I/D simplified word request contract, so L2 can be
  enabled before the L1I/L1D adapters are converted to their native L2 line
  ports.

Changed modules:

- `la_l2_adapter.v`: new wrapper that maps current I-side and D-side word
  requests onto copied L2's L1I/L1D half-line response interfaces, selects the
  requested word, and uses copied `axi_arbiter` for the external AXI bus.
- `memsys_top.v`: when `L2_ENABLE=1`, I/D cache-stub or L1 adapter miss
  requests go through `la_l2_adapter`; when `L2_ENABLE=0`, the old all-miss AXI
  FSM remains active.

Current runnable status:

- `make build CPU=PIPELINE SIM_JOBS=4 L2_ENABLE=1 L2_PREFETCH=0`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 L2_ENABLE=1 L2_PREFETCH=0`: passed.

Latest `L2_ENABLE=1 L2_PREFETCH=0` EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 192873
Total cycles: 192874
IPC: 0.062165
CPI: 16.086155
```

Notes:

- This is the first copied cache layer that shows a measurable EXP=6 speedup in
  the current conservative pipeline.
- L2 prefetch is disabled for this smoke (`L2_PREFETCH=0`) to keep the first
  integration deterministic.
- The current wrapper is deliberately conservative: it only allows one
  outstanding I-side request and one outstanding D-side request, and it chooses
  one word from copied L2's four-word response.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4`: passed after the L2 adapter change.
  Latest default result remains:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 209086
Total cycles: 209087
IPC: 0.057345
CPI: 17.438365
```

- `make chiplab-smoke RUN=hello_world CHIPLAB_OPTS='--output-nothing'
  L2_ENABLE=1 L2_PREFETCH=0`: passed. This compiles Chiplab Verilator and
  software without starting the long hello_world simulation.
- The next step is to test combined L1I/L1D/L2 configurations, then decide
  whether to convert L1I/L1D adapters to the copied L2 native line interfaces.

## A2b Combined Copied Cache Smoke Snapshot

Date: 2026-05-14 16:29:51 CST

Goal:

- Verify that the copied L1I and L1D adapters can run on top of the copied L2
  compatibility bridge.
- Keep `L2_PREFETCH=0` so the first combined checks stay deterministic.

Current runnable status:

- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 L1I_ENABLE=1 L2_ENABLE=1
  L2_PREFETCH=0`: passed.
- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 L1D_ENABLE=1 L2_ENABLE=1
  L2_PREFETCH=0`: passed.

Latest `L1I_ENABLE=1 L2_ENABLE=1 L2_PREFETCH=0` EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 211208
Total cycles: 211209
IPC: 0.056769
CPI: 17.615346
```

Latest `L1D_ENABLE=1 L2_ENABLE=1 L2_PREFETCH=0` EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 192859
Total cycles: 192860
IPC: 0.062170
CPI: 16.084987
```

Notes:

- The earlier parallel launch of two `make all` commands corrupted the shared
  `mycpu_env/func/obj` intermediate output. Local `make all` tests should be run
  serially unless the build directories are separated.
- `L1I+L2` is functionally correct, but currently slower than L2-only because
  the L1I adapter still decomposes copied ICache miss fills through the
  simplified word bridge instead of using native copied L2 line ports.
- `L1D+L2` keeps the copied L2 speedup for EXP=6 and proves the current
  DCache write-through completion path is compatible with the L2 adapter.

Latest `L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1 L2_PREFETCH=0` EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 211174
Total cycles: 211175
IPC: 0.056778
CPI: 17.612510
```

Notes:

- `L1I+L1D+L2` proves that both copied L1 adapters can share the copied L2 and
  copied AXI arbiter without breaking EXP=6.
- The full-cache combination is still dominated by the current I-side
  compatibility bridge; improving this means wiring copied L1I misses to copied
  L2's native line response path instead of decomposing through single-word
  requests.

## A2b Copied Frontend + Cache Stack Smoke Snapshot

Date: 2026-05-14 16:32:35 CST

Goal:

- Verify the copied BPU, copied Fetch Buffer, copied L1I/L1D, copied L2, and
  copied AXI arbiter can all be enabled together through LA wrappers.
- Keep TLB off and L2 prefetch off for this A2 integration smoke.

Current runnable status:

- `make all EXP=6 CPU=PIPELINE SIM_JOBS=4 BPU_ENABLE=1
  FETCH_BUFFER_ENABLE=1 L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1
  L2_PREFETCH=0`: passed.
- `make chiplab-smoke RUN=hello_world CHIPLAB_OPTS='--output-nothing'
  BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1 L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1
  L2_PREFETCH=0`: passed. This compiles the Chiplab Verilator model and
  software for the copied-stack configuration without starting the long
  hello_world simulation.

Latest copied frontend + cache stack EXP=6 result:

```text
Passed all the tests at stop pc 0x1c000100
Committed instructions: 11990
Execution cycles: 211174
Total cycles: 211175
IPC: 0.056778
CPI: 17.612510
```

Notes:

- This is the strongest A2 smoke so far: all copied non-TLB performance blocks
  are present in one local Verilator configuration and in the Chiplab compile
  path.
- The result matches the `L1I+L1D+L2` run, so current BPU/Fetch Buffer adapters
  do not add an observable EXP=6 regression in this single-in-flight baseline.
- Next checks: run an A3 `EXP=23` baseline to identify the first missing
  instruction/CSR/TLB/system behavior, then decide whether to start native
  L1-to-L2 line-interface cleanup or move straight into functional completion.

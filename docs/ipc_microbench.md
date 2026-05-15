# IPC Microbench Evaluation

The suite is usable as a first theoretical IPC harness under ideal memory
settings, with two limits to keep explicit:

1. Set1, Set2, Set5, and Set6 are directly useful on the current in-order
   single-issue pipeline.
2. Set3 and Set4 become fully diagnostic only after store-buffer occupancy,
   full backpressure, and store-load forwarding signals exist. Before that,
   they still measure LSU/store pipe ordering and throughput.

Recommended run mode:

```sh
make ipcbench-run IPC_CASE=set1a_alu L1I_ENABLE=0 L1D_ENABLE=0 L2_ENABLE=0
make ipcbench-run IPC_CASE=set1a_alu BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1 L1I_ENABLE=0 L1D_ENABLE=0 L2_ENABLE=0
```

For batch runs:

```sh
scripts/run_ipc_microbench.sh set1a_alu set2a_raw_alu set5c_branch_alternating
```

The generated CSV is `logs/ipc_microbench/summary.csv`.

Default case length is `BENCH_REPEAT=512` and `BENCH_UNROLL=16`. This gives a
large dynamic instruction count without statically expanding the hot code beyond
the current 8KB L1I. Static expansion alone is a bad IPC benchmark knob: if the
text body exceeds L1I capacity, the benchmark starts measuring fetch/cache
capacity behavior instead of the intended pipeline bottleneck.

## Coverage Verdict

| Set | Current value | Gap |
| --- | --- | --- |
| Set1 no-dependency throughput | Good. Measures frontend/backend steady-state IPC. | Needs commit stall reason to distinguish frontend bubbles from backend bubbles. |
| Set2 RAW/load-use/MDU | Good. Shows bypass and load-use penalties. | MDU case depends on whether mul/div are actually multi-cycle. |
| Set3 load-store interaction | Partial. Checks ordering and LSU pipe cost. | Store buffer forwarding/merge cannot be proven until SB exists. |
| Set4 store buffer pressure | Future-facing. Useful once SB is added. | Needs `sb_occupancy`, `stall_sb_full`, and uncached policy visibility. |
| Set5 branch prediction | Good. Covers taken, not-taken, alternating, and mispredict recovery patterns. | Needs per-redirect recovery-cycle counter for exact penalty. |
| Set6 fusion | Baseline/future guard. | Actual fusion benefit needs fusion implementation and `fusion_commit_cnt`. |

## Minimum Signals Still Needed

The proposed signal list is correct. For this CPU, the highest-priority subset
is:

- `commit_valid`
- `commit_stall_reason`
- `stall_dependency`
- `stall_lsu_busy`
- `bpu_mispredict`

Add these when interpreting Set1/Set2/Set5. Add `stall_sb_full`,
`sb_occupancy`, and forwarding counters when implementing the store buffer.

## Source Notes

Instruction forms were taken from the existing EXP23 path:

- ALU: `mycpu_env/func/inst/n2_add_w.S`, `n3_addi_w.S`
- Load/store: `n14_ld_w.S`, `n15_st_w.S`
- Branch: `n16_beq.S`, `n17_bne.S`, `n20_b.S`
- MDU: `n32_mul_w.S`
- `lu12i/addi`: `n1_lu12i_w.S`, `n3_addi_w.S`

One correction from the draft: fixed not-taken should use a condition that is
actually false, such as `bne zero, zero, target`; `beq zero, zero, target` is
always taken.

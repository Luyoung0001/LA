#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BENCH_DIR="$ROOT_DIR/mycpu_env/ipc_microbench"
LOG_DIR="$ROOT_DIR/logs/ipc_microbench"
EXE="$ROOT_DIR/obj_dir/Vverilator_top"
BENCH_REPEAT="${BENCH_REPEAT:-512}"
BENCH_UNROLL="${BENCH_UNROLL:-16}"

mkdir -p "$LOG_DIR"

if (($# > 0)); then
  mapfile -t cases < <(printf '%s\n' "$@")
else
  mapfile -t cases < <(make --no-print-directory -C "$BENCH_DIR" list)
fi

make --no-print-directory -C "$ROOT_DIR" build

printf 'case,ipc,cpi,committed,cycles,log\n' | tee "$LOG_DIR/summary.csv"
for case in "${cases[@]}"; do
  make -C "$BENCH_DIR" CASE="$case" BENCH_REPEAT="$BENCH_REPEAT" BENCH_UNROLL="$BENCH_UNROLL" case >/dev/null
  case_obj="$BENCH_DIR/obj/repeat_${BENCH_REPEAT}_unroll_${BENCH_UNROLL}/$case"
  stop_pc="$(cat "$case_obj/stop_pc.txt")"
  log="$LOG_DIR/$case.log"
  LA_MAIN_BIN="$case_obj/main.bin" LA_STOP_PC="$stop_pc" "$EXE" >"$log" 2>&1
  ipc="$(awk '/^IPC:/ {print $2}' "$log" | tail -n1)"
  cpi="$(awk '/^CPI:/ {print $2}' "$log" | tail -n1)"
  committed="$(awk '/^Committed instructions:/ {print $3}' "$log" | tail -n1)"
  cycles="$(awk '/^Execution cycles:/ {print $3}' "$log" | tail -n1)"
  printf '%s,%s,%s,%s,%s,%s\n' "$case" "$ipc" "$cpi" "$committed" "$cycles" "$log" | tee -a "$LOG_DIR/summary.csv"
done

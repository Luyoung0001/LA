#!/usr/bin/env bash
# sweep.sh — Run the EXP × {feature} regression matrix serially.
#
# Why: mycpu_env/func/obj is shared across runs (see memory: exp-regression-serial),
# so combos must be serialized; this script keeps each invocation short.
# Single Bash command should stay under ~60s budgeted to harness (see memory:
# bash-60s-cap), so callers can kill -9 and resume cleanly.
#
# Usage:
#   ./sweep.sh                       # default: EXP=6,23 × 9 combos, PERF_MONI=1
#   EXP_LIST="6 23" OPTS_LIST=...    # override
#   ./sweep.sh --quick               # only baseline + full-on, EXP=6
#   ./sweep.sh --combo "L1I_ENABLE=1 L1D_ENABLE=1"
#
# Output: one PASS/FAIL line per (EXP,combo). Exit non-zero on any failure.
set -u
cd "$(dirname "$0")"

EXP_LIST="${EXP_LIST:-6 23}"
PERF_MONI="${PERF_MONI:-1}"
SIM_JOBS="${SIM_JOBS:-4}"
TIMEOUT_SEC="${TIMEOUT_SEC:-1500}"

DEFAULT_COMBOS=(
  ""
  "BPU_ENABLE=1"
  "FETCH_BUFFER_ENABLE=1"
  "BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1"
  "L1I_ENABLE=1"
  "L1D_ENABLE=1"
  "L1I_ENABLE=1 L1D_ENABLE=1"
  "L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1"
  "BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1 L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1"
)

if [[ "${1:-}" == "--quick" ]]; then
  combos=("" "BPU_ENABLE=1 FETCH_BUFFER_ENABLE=1 L1I_ENABLE=1 L1D_ENABLE=1 L2_ENABLE=1")
  EXP_LIST="6"
elif [[ "${1:-}" == "--combo" ]]; then
  combos=("$2")
else
  combos=("${DEFAULT_COMBOS[@]}")
fi

fail=0
pass=0
for EXP in $EXP_LIST; do
  for opts in "${combos[@]}"; do
    label="EXP=$EXP [${opts:-baseline}]"
    cmd="make all EXP=$EXP CPU=PIPELINE PERF_MONI=$PERF_MONI $opts SIM_JOBS=$SIM_JOBS"
    out=$(eval "timeout $TIMEOUT_SEC $cmd" 2>&1)
    if echo "$out" | grep -q "Passed all the tests"; then
      printf "PASS  %s\n" "$label"
      pass=$((pass+1))
    else
      printf "FAIL  %s\n" "$label"
      echo "$out" | grep -E "Difftest failed|^%Error|Killed|Error 1$|Error 127$" | head -3 | sed 's/^/      /'
      fail=$((fail+1))
    fi
  done
done

echo "---"
echo "Summary: $pass passed, $fail failed"
exit $((fail > 0 ? 1 : 0))

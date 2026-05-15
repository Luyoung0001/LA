#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    lu12i.w t0, 0x12345
    addi.w  t0, t0, 0x678
    .endr
BENCH_LOOP_END

BENCH_STOP

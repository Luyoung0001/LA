#include "bench_common.inc"

BENCH_START
BENCH_INIT_DATA

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    ld.w    t0, s0, 0
    add.w   t1, t0, s1
    ld.w    t2, s0, 4
    add.w   t3, t2, s2
    .endr
BENCH_LOOP_END

BENCH_STOP

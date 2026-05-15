#include "bench_common.inc"

BENCH_START
BENCH_INIT_DATA

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    ld.w    t0, s0, 0
    add.w   t1, s1, s2
    ld.w    t2, s0, 4
    add.w   t3, s3, s4
    .endr
BENCH_LOOP_END

BENCH_STOP

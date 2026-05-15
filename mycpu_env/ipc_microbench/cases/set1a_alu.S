#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    add.w   t0, s1, s2
    add.w   t1, s3, s4
    add.w   t2, s5, s6
    add.w   t3, s7, s8
    .endr
BENCH_LOOP_END

BENCH_STOP

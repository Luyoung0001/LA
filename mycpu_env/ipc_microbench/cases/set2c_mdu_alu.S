#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    mul.w   t0, s1, s2
    add.w   t1, t0, s3
    mul.w   t2, s4, s5
    add.w   t3, t2, s6
    .endr
BENCH_LOOP_END

BENCH_STOP

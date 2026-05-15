#include "bench_common.inc"

BENCH_START

    add.w   t0, s1, s2
BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    add.w   t0, t0, s3
    .endr
BENCH_LOOP_END

BENCH_STOP

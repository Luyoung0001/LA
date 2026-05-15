#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    b       1f
    add.w   t0, t0, s1
1:
    add.w   t1, s2, s3
    .endr
BENCH_LOOP_END

BENCH_STOP

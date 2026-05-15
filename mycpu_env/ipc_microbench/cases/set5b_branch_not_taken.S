#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    bne     zero, zero, 1f
    add.w   t0, s1, s2
1:
    add.w   t1, s3, s4
    .endr
BENCH_LOOP_END

BENCH_STOP

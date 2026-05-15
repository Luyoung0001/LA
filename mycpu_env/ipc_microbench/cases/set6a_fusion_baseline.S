#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    lu12i.w t0, 0x12345
    addi.w  t0, t0, 0x678
    lu12i.w t1, 0x23456
    addi.w  t1, t1, 0x789
    .endr
BENCH_LOOP_END

BENCH_STOP

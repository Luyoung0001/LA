#include "bench_common.inc"

BENCH_START

    lu12i.w t0, 0x12345
    addi.w  t0, t0, 0x678

    lu12i.w t1, 0x12345
    addi.w  t2, t1, 0x678

    lu12i.w t3, 0x12345
    addi.w  zero, zero, 0
    addi.w  t3, t3, 0x678

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    lu12i.w t4, 0x23456
    addi.w  t4, t4, 0x789
    lu12i.w t5, 0x34567
    addi.w  t6, t5, 0x12
    .endr
BENCH_LOOP_END

BENCH_STOP

#include "bench_common.inc"

BENCH_START

    lu12i.w t0, 0x12345
    addi.w  t1, t0, 0x678

    lu12i.w t2, 0x12345
    BENCH_NOP
    addi.w  t2, t2, 0x678

    .align 6
    .rept 15
    BENCH_NOP
    .endr
    lu12i.w t3, 0x23456
    addi.w  t3, t3, 0x789

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    lu12i.w t4, 0x34567
    addi.w  t4, t4, 0x111
    .endr
BENCH_LOOP_END

BENCH_STOP

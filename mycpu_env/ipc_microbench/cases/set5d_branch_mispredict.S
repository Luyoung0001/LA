#include "bench_common.inc"

BENCH_START

    li.w    t0, BENCH_REPEAT
    add.w   t1, zero, zero
1:
    xori    t1, t1, 1
    bne     t1, zero, 2f
    add.w   t2, s1, s2
    add.w   t3, s3, s4
    add.w   t4, s5, s6
2:
    addi.w  t0, t0, -1
    bne     t0, zero, 1b

BENCH_STOP

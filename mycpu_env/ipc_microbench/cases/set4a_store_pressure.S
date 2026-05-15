#include "bench_common.inc"

BENCH_START

    li.w    t0, BENCH_REPEAT
    add.w   t1, s0, zero
1:
    .rept BENCH_UNROLL
    st.w    s1, t1, 0
    st.w    s2, t1, 4
    st.w    s3, t1, 8
    st.w    s4, t1, 12
    addi.w  t1, t1, 16
    .endr
    addi.w  t0, t0, -1
    bne     t0, zero, 1b

BENCH_STOP

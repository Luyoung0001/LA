#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    st.w    s1, s0, 0
    ld.w    t0, s0, 0
    st.w    s2, s0, 4
    ld.w    t1, s0, 4
    st.w    s3, s0, 8
    ld.w    t2, s0, 8
    st.w    s4, s0, 12
    ld.w    t3, s0, 12
    .endr
BENCH_LOOP_END

BENCH_STOP

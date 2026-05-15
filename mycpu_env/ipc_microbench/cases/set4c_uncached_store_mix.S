#include "bench_common.inc"

BENCH_START

    li.w    t0, UNCACHED_PROBE
BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    st.w    s1, s0, 0
    st.w    s2, t0, 0
    st.w    s3, s0, 4
    st.w    s4, t0, 0
    .endr
BENCH_LOOP_END

BENCH_STOP

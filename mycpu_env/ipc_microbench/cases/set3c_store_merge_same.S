#include "bench_common.inc"

BENCH_START

BENCH_LOOP_BEGIN
    .rept BENCH_UNROLL
    st.w    s1, s0, 0
    st.w    s2, s0, 0
    st.w    s3, s0, 0
    st.w    s4, s0, 0
    .endr
BENCH_LOOP_END

BENCH_STOP

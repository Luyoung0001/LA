#include "regdef.h"

#define BENCH_DATA_BASE  0x001d0000
#define BENCH_STACK_TOP  0x001f0000
#define UNCACHED_PROBE   0xbfaff050

#ifndef BENCH_REPEAT
#define BENCH_REPEAT 512
#endif

#ifndef BENCH_UNROLL
#define BENCH_UNROLL 16
#endif

    .macro BENCH_START
    .text
    .globl _start
    .globl __bench_stop
    .align 3
_start:
    li.w    sp, BENCH_STACK_TOP
    li.w    s0, BENCH_DATA_BASE
    li.w    s1, 0x11111111
    li.w    s2, 0x22222222
    li.w    s3, 0x33333333
    li.w    s4, 0x44444444
    li.w    s5, 0x55555555
    li.w    s6, 0x66666666
    li.w    s7, 0x77777777
    li.w    s8, 0x7fffffff
    .endm

    .macro BENCH_INIT_DATA
    st.w    s1, s0, 0
    st.w    s2, s0, 4
    st.w    s3, s0, 8
    st.w    s4, s0, 12
    st.w    s5, s0, 16
    st.w    s6, s0, 20
    st.w    s7, s0, 24
    st.w    s8, s0, 28
    .endm

    .macro BENCH_STOP
__bench_stop:
    add.w   zero, zero, zero
1:
    b       1b
    .endm

    .macro BENCH_NOP
    addi.w  zero, zero, 0
    .endm

    .macro BENCH_LOOP_BEGIN
    li.w    a0, BENCH_REPEAT
bench_loop:
    .endm

    .macro BENCH_LOOP_END
    addi.w  a0, a0, -1
    bne     a0, zero, bench_loop
    .endm

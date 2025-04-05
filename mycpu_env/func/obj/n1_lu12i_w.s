# 1 "n1_lu12i_w.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n1_lu12i_w.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n1_lu12i_w.S" 2
# 1 "../include/regdef.h" 1
# 3 "n1_lu12i_w.S" 2
# 1 "../include/inst_test.h" 1
# 1 "../include/cpu_cde.h" 1
# 1 "../include/test_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 2 "../include/inst_test.h" 2
# 1 "../include/test_define.h" 1
# 3 "../include/inst_test.h" 2
# 4 "n1_lu12i_w.S" 2

.text; .globl n1_lu12i_w_test; .align 3; .cfi_startproc ; .type n1_lu12i_w_test, @function; n1_lu12i_w_test:

    addi.w $r23, $r23 ,1
    addi.w $r25, $r0, 0x0
    lu12i.w $r14, 0x1
###test inst
    addi.w $r13, $r0, 0x0
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00000&0x80000?0x00000 -0x100000:0x00000; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00001&0x80000?0x00001 -0x100000:0x00001; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00002&0x80000?0x00002 -0x100000:0x00002; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00003&0x80000?0x00003 -0x100000:0x00003; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00004&0x80000?0x00004 -0x100000:0x00004; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00005&0x80000?0x00005 -0x100000:0x00005; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00006&0x80000?0x00006 -0x100000:0x00006; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00007&0x80000?0x00007 -0x100000:0x00007; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00008&0x80000?0x00008 -0x100000:0x00008; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x00009&0x80000?0x00009 -0x100000:0x00009; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x0000a&0x80000?0x0000a -0x100000:0x0000a; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x0000b&0x80000?0x0000b -0x100000:0x0000b; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x0000c&0x80000?0x0000c -0x100000:0x0000c; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x0000d&0x80000?0x0000d -0x100000:0x0000d; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x0000e&0x80000?0x0000e -0x100000:0x0000e; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x00000&0x80000?0x00000 -0x100000:0x00000; lu12i.w $r12, 0x0000f&0x80000?0x0000f -0x100000:0x0000f; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    addi.w $r13, $r0, 0x0
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11010&0x80000?0x11010 -0x100000:0x11010; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11011&0x80000?0x11011 -0x100000:0x11011; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11012&0x80000?0x11012 -0x100000:0x11012; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11013&0x80000?0x11013 -0x100000:0x11013; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11014&0x80000?0x11014 -0x100000:0x11014; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11015&0x80000?0x11015 -0x100000:0x11015; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11016&0x80000?0x11016 -0x100000:0x11016; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11017&0x80000?0x11017 -0x100000:0x11017; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11018&0x80000?0x11018 -0x100000:0x11018; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x11019&0x80000?0x11019 -0x100000:0x11019; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x1101a&0x80000?0x1101a -0x100000:0x1101a; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x1101b&0x80000?0x1101b -0x100000:0x1101b; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x1101c&0x80000?0x1101c -0x100000:0x1101c; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x1101d&0x80000?0x1101d -0x100000:0x1101d; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x1101e&0x80000?0x1101e -0x100000:0x1101e; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x11010&0x80000?0x11010 -0x100000:0x11010; lu12i.w $r12, 0x1101f&0x80000?0x1101f -0x100000:0x1101f; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    addi.w $r13, $r0, 0x0
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22020&0x80000?0x22020 -0x100000:0x22020; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22021&0x80000?0x22021 -0x100000:0x22021; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22022&0x80000?0x22022 -0x100000:0x22022; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22023&0x80000?0x22023 -0x100000:0x22023; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22024&0x80000?0x22024 -0x100000:0x22024; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22025&0x80000?0x22025 -0x100000:0x22025; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22026&0x80000?0x22026 -0x100000:0x22026; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22027&0x80000?0x22027 -0x100000:0x22027; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22028&0x80000?0x22028 -0x100000:0x22028; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x22029&0x80000?0x22029 -0x100000:0x22029; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x2202a&0x80000?0x2202a -0x100000:0x2202a; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x2202b&0x80000?0x2202b -0x100000:0x2202b; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x2202c&0x80000?0x2202c -0x100000:0x2202c; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x2202d&0x80000?0x2202d -0x100000:0x2202d; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x2202e&0x80000?0x2202e -0x100000:0x2202e; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
    lu12i.w $r4, 0x22020&0x80000?0x22020 -0x100000:0x22020; lu12i.w $r12, 0x2202f&0x80000?0x2202f -0x100000:0x2202f; ;;;; add.w $r4, $r4, $r13; add.w $r13, $r13, $r14; ;;;; bne $r12, $r4, inst_error; ;;;
# 217 "n1_lu12i_w.S"
###detect exception
    bne $r25, $r0, inst_error
    ;;;
###score ++
    addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
    slli.w $r13, $r23, 24
    ;;;
    or $r12, $r13, $r26
    ;;;
    st.w $r12, $r24, 0
    jirl $r0, $r1, 0
    ;;;
.cfi_endproc ; .size n1_lu12i_w_test,.-n1_lu12i_w_test;

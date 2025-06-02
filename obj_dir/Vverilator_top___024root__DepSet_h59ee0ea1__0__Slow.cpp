// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top___024root.h"

VL_ATTR_COLD void Vverilator_top___024root___eval_static(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vverilator_top___024root___eval_final(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vverilator_top___024root___eval_triggers__stl(Vverilator_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__stl(Vverilator_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___eval_stl(Vverilator_top___024root* vlSelf);

VL_ATTR_COLD void Vverilator_top___024root___eval_settle(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vverilator_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vverilator_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/luyoung/LA/mycpu_env/myCPU/v_src/verilator_top.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vverilator_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__stl(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if (vlSelf->__VstlTriggered.at(1U)) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(2U)) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(3U)) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(4U)) {
        VL_DBG_MSGF("         'stl' region trigger index 4 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(5U)) {
        VL_DBG_MSGF("         'stl' region trigger index 5 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(6U)) {
        VL_DBG_MSGF("         'stl' region trigger index 6 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(7U)) {
        VL_DBG_MSGF("         'stl' region trigger index 7 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(8U)) {
        VL_DBG_MSGF("         'stl' region trigger index 8 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(9U)) {
        VL_DBG_MSGF("         'stl' region trigger index 9 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0xaU)) {
        VL_DBG_MSGF("         'stl' region trigger index 10 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0xbU)) {
        VL_DBG_MSGF("         'stl' region trigger index 11 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0xcU)) {
        VL_DBG_MSGF("         'stl' region trigger index 12 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0xdU)) {
        VL_DBG_MSGF("         'stl' region trigger index 13 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0xeU)) {
        VL_DBG_MSGF("         'stl' region trigger index 14 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0xfU)) {
        VL_DBG_MSGF("         'stl' region trigger index 15 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x10U)) {
        VL_DBG_MSGF("         'stl' region trigger index 16 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x11U)) {
        VL_DBG_MSGF("         'stl' region trigger index 17 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x12U)) {
        VL_DBG_MSGF("         'stl' region trigger index 18 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x13U)) {
        VL_DBG_MSGF("         'stl' region trigger index 19 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x14U)) {
        VL_DBG_MSGF("         'stl' region trigger index 20 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x15U)) {
        VL_DBG_MSGF("         'stl' region trigger index 21 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x16U)) {
        VL_DBG_MSGF("         'stl' region trigger index 22 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x17U)) {
        VL_DBG_MSGF("         'stl' region trigger index 23 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x18U)) {
        VL_DBG_MSGF("         'stl' region trigger index 24 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x19U)) {
        VL_DBG_MSGF("         'stl' region trigger index 25 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x1aU)) {
        VL_DBG_MSGF("         'stl' region trigger index 26 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x1bU)) {
        VL_DBG_MSGF("         'stl' region trigger index 27 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x1cU)) {
        VL_DBG_MSGF("         'stl' region trigger index 28 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x1dU)) {
        VL_DBG_MSGF("         'stl' region trigger index 29 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x1eU)) {
        VL_DBG_MSGF("         'stl' region trigger index 30 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x1fU)) {
        VL_DBG_MSGF("         'stl' region trigger index 31 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x20U)) {
        VL_DBG_MSGF("         'stl' region trigger index 32 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x21U)) {
        VL_DBG_MSGF("         'stl' region trigger index 33 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x22U)) {
        VL_DBG_MSGF("         'stl' region trigger index 34 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x23U)) {
        VL_DBG_MSGF("         'stl' region trigger index 35 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x24U)) {
        VL_DBG_MSGF("         'stl' region trigger index 36 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x25U)) {
        VL_DBG_MSGF("         'stl' region trigger index 37 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x26U)) {
        VL_DBG_MSGF("         'stl' region trigger index 38 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s1 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x27U)) {
        VL_DBG_MSGF("         'stl' region trigger index 39 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x28U)) {
        VL_DBG_MSGF("         'stl' region trigger index 40 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x29U)) {
        VL_DBG_MSGF("         'stl' region trigger index 41 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x2aU)) {
        VL_DBG_MSGF("         'stl' region trigger index 42 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x2bU)) {
        VL_DBG_MSGF("         'stl' region trigger index 43 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x2cU)) {
        VL_DBG_MSGF("         'stl' region trigger index 44 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x2dU)) {
        VL_DBG_MSGF("         'stl' region trigger index 45 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x2eU)) {
        VL_DBG_MSGF("         'stl' region trigger index 46 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x2fU)) {
        VL_DBG_MSGF("         'stl' region trigger index 47 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x30U)) {
        VL_DBG_MSGF("         'stl' region trigger index 48 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x31U)) {
        VL_DBG_MSGF("         'stl' region trigger index 49 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x32U)) {
        VL_DBG_MSGF("         'stl' region trigger index 50 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x33U)) {
        VL_DBG_MSGF("         'stl' region trigger index 51 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x34U)) {
        VL_DBG_MSGF("         'stl' region trigger index 52 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x35U)) {
        VL_DBG_MSGF("         'stl' region trigger index 53 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x36U)) {
        VL_DBG_MSGF("         'stl' region trigger index 54 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x37U)) {
        VL_DBG_MSGF("         'stl' region trigger index 55 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s1 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x38U)) {
        VL_DBG_MSGF("         'stl' region trigger index 56 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x39U)) {
        VL_DBG_MSGF("         'stl' region trigger index 57 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x3aU)) {
        VL_DBG_MSGF("         'stl' region trigger index 58 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x3bU)) {
        VL_DBG_MSGF("         'stl' region trigger index 59 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x3cU)) {
        VL_DBG_MSGF("         'stl' region trigger index 60 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x3dU)) {
        VL_DBG_MSGF("         'stl' region trigger index 61 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x3eU)) {
        VL_DBG_MSGF("         'stl' region trigger index 62 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x3fU)) {
        VL_DBG_MSGF("         'stl' region trigger index 63 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x40U)) {
        VL_DBG_MSGF("         'stl' region trigger index 64 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x41U)) {
        VL_DBG_MSGF("         'stl' region trigger index 65 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x42U)) {
        VL_DBG_MSGF("         'stl' region trigger index 66 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x43U)) {
        VL_DBG_MSGF("         'stl' region trigger index 67 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x44U)) {
        VL_DBG_MSGF("         'stl' region trigger index 68 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x45U)) {
        VL_DBG_MSGF("         'stl' region trigger index 69 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x46U)) {
        VL_DBG_MSGF("         'stl' region trigger index 70 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x47U)) {
        VL_DBG_MSGF("         'stl' region trigger index 71 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x48U)) {
        VL_DBG_MSGF("         'stl' region trigger index 72 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x49U)) {
        VL_DBG_MSGF("         'stl' region trigger index 73 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x4aU)) {
        VL_DBG_MSGF("         'stl' region trigger index 74 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x4bU)) {
        VL_DBG_MSGF("         'stl' region trigger index 75 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x4cU)) {
        VL_DBG_MSGF("         'stl' region trigger index 76 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x4dU)) {
        VL_DBG_MSGF("         'stl' region trigger index 77 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x4eU)) {
        VL_DBG_MSGF("         'stl' region trigger index 78 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x4fU)) {
        VL_DBG_MSGF("         'stl' region trigger index 79 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x50U)) {
        VL_DBG_MSGF("         'stl' region trigger index 80 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x51U)) {
        VL_DBG_MSGF("         'stl' region trigger index 81 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x52U)) {
        VL_DBG_MSGF("         'stl' region trigger index 82 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x53U)) {
        VL_DBG_MSGF("         'stl' region trigger index 83 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x54U)) {
        VL_DBG_MSGF("         'stl' region trigger index 84 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x55U)) {
        VL_DBG_MSGF("         'stl' region trigger index 85 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x56U)) {
        VL_DBG_MSGF("         'stl' region trigger index 86 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x57U)) {
        VL_DBG_MSGF("         'stl' region trigger index 87 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x58U)) {
        VL_DBG_MSGF("         'stl' region trigger index 88 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x59U)) {
        VL_DBG_MSGF("         'stl' region trigger index 89 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x5aU)) {
        VL_DBG_MSGF("         'stl' region trigger index 90 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x5bU)) {
        VL_DBG_MSGF("         'stl' region trigger index 91 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x5cU)) {
        VL_DBG_MSGF("         'stl' region trigger index 92 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x5dU)) {
        VL_DBG_MSGF("         'stl' region trigger index 93 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x5eU)) {
        VL_DBG_MSGF("         'stl' region trigger index 94 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x5fU)) {
        VL_DBG_MSGF("         'stl' region trigger index 95 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x60U)) {
        VL_DBG_MSGF("         'stl' region trigger index 96 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x61U)) {
        VL_DBG_MSGF("         'stl' region trigger index 97 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x62U)) {
        VL_DBG_MSGF("         'stl' region trigger index 98 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x63U)) {
        VL_DBG_MSGF("         'stl' region trigger index 99 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VstlTriggered.at(0x64U)) {
        VL_DBG_MSGF("         'stl' region trigger index 100 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c1_s1)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__act(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(4U)) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(5U)) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(6U)) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(7U)) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(8U)) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(9U)) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0xaU)) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0xbU)) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0xcU)) {
        VL_DBG_MSGF("         'act' region trigger index 12 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0xdU)) {
        VL_DBG_MSGF("         'act' region trigger index 13 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0xeU)) {
        VL_DBG_MSGF("         'act' region trigger index 14 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0xfU)) {
        VL_DBG_MSGF("         'act' region trigger index 15 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x10U)) {
        VL_DBG_MSGF("         'act' region trigger index 16 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x11U)) {
        VL_DBG_MSGF("         'act' region trigger index 17 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x12U)) {
        VL_DBG_MSGF("         'act' region trigger index 18 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x13U)) {
        VL_DBG_MSGF("         'act' region trigger index 19 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x14U)) {
        VL_DBG_MSGF("         'act' region trigger index 20 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x15U)) {
        VL_DBG_MSGF("         'act' region trigger index 21 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x16U)) {
        VL_DBG_MSGF("         'act' region trigger index 22 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x17U)) {
        VL_DBG_MSGF("         'act' region trigger index 23 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x18U)) {
        VL_DBG_MSGF("         'act' region trigger index 24 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x19U)) {
        VL_DBG_MSGF("         'act' region trigger index 25 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x1aU)) {
        VL_DBG_MSGF("         'act' region trigger index 26 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x1bU)) {
        VL_DBG_MSGF("         'act' region trigger index 27 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x1cU)) {
        VL_DBG_MSGF("         'act' region trigger index 28 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x1dU)) {
        VL_DBG_MSGF("         'act' region trigger index 29 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x1eU)) {
        VL_DBG_MSGF("         'act' region trigger index 30 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x1fU)) {
        VL_DBG_MSGF("         'act' region trigger index 31 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x20U)) {
        VL_DBG_MSGF("         'act' region trigger index 32 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x21U)) {
        VL_DBG_MSGF("         'act' region trigger index 33 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x22U)) {
        VL_DBG_MSGF("         'act' region trigger index 34 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x23U)) {
        VL_DBG_MSGF("         'act' region trigger index 35 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x24U)) {
        VL_DBG_MSGF("         'act' region trigger index 36 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x25U)) {
        VL_DBG_MSGF("         'act' region trigger index 37 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s1 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x26U)) {
        VL_DBG_MSGF("         'act' region trigger index 38 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x27U)) {
        VL_DBG_MSGF("         'act' region trigger index 39 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x28U)) {
        VL_DBG_MSGF("         'act' region trigger index 40 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x29U)) {
        VL_DBG_MSGF("         'act' region trigger index 41 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x2aU)) {
        VL_DBG_MSGF("         'act' region trigger index 42 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x2bU)) {
        VL_DBG_MSGF("         'act' region trigger index 43 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x2cU)) {
        VL_DBG_MSGF("         'act' region trigger index 44 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x2dU)) {
        VL_DBG_MSGF("         'act' region trigger index 45 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x2eU)) {
        VL_DBG_MSGF("         'act' region trigger index 46 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x2fU)) {
        VL_DBG_MSGF("         'act' region trigger index 47 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x30U)) {
        VL_DBG_MSGF("         'act' region trigger index 48 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x31U)) {
        VL_DBG_MSGF("         'act' region trigger index 49 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x32U)) {
        VL_DBG_MSGF("         'act' region trigger index 50 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x33U)) {
        VL_DBG_MSGF("         'act' region trigger index 51 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x34U)) {
        VL_DBG_MSGF("         'act' region trigger index 52 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x35U)) {
        VL_DBG_MSGF("         'act' region trigger index 53 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x36U)) {
        VL_DBG_MSGF("         'act' region trigger index 54 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s1 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x37U)) {
        VL_DBG_MSGF("         'act' region trigger index 55 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x38U)) {
        VL_DBG_MSGF("         'act' region trigger index 56 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x39U)) {
        VL_DBG_MSGF("         'act' region trigger index 57 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x3aU)) {
        VL_DBG_MSGF("         'act' region trigger index 58 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x3bU)) {
        VL_DBG_MSGF("         'act' region trigger index 59 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x3cU)) {
        VL_DBG_MSGF("         'act' region trigger index 60 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x3dU)) {
        VL_DBG_MSGF("         'act' region trigger index 61 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x3eU)) {
        VL_DBG_MSGF("         'act' region trigger index 62 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x3fU)) {
        VL_DBG_MSGF("         'act' region trigger index 63 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x40U)) {
        VL_DBG_MSGF("         'act' region trigger index 64 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x41U)) {
        VL_DBG_MSGF("         'act' region trigger index 65 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x42U)) {
        VL_DBG_MSGF("         'act' region trigger index 66 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x43U)) {
        VL_DBG_MSGF("         'act' region trigger index 67 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x44U)) {
        VL_DBG_MSGF("         'act' region trigger index 68 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x45U)) {
        VL_DBG_MSGF("         'act' region trigger index 69 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x46U)) {
        VL_DBG_MSGF("         'act' region trigger index 70 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x47U)) {
        VL_DBG_MSGF("         'act' region trigger index 71 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x48U)) {
        VL_DBG_MSGF("         'act' region trigger index 72 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x49U)) {
        VL_DBG_MSGF("         'act' region trigger index 73 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x4aU)) {
        VL_DBG_MSGF("         'act' region trigger index 74 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x4bU)) {
        VL_DBG_MSGF("         'act' region trigger index 75 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x4cU)) {
        VL_DBG_MSGF("         'act' region trigger index 76 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x4dU)) {
        VL_DBG_MSGF("         'act' region trigger index 77 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x4eU)) {
        VL_DBG_MSGF("         'act' region trigger index 78 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x4fU)) {
        VL_DBG_MSGF("         'act' region trigger index 79 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x50U)) {
        VL_DBG_MSGF("         'act' region trigger index 80 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x51U)) {
        VL_DBG_MSGF("         'act' region trigger index 81 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x52U)) {
        VL_DBG_MSGF("         'act' region trigger index 82 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x53U)) {
        VL_DBG_MSGF("         'act' region trigger index 83 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x54U)) {
        VL_DBG_MSGF("         'act' region trigger index 84 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x55U)) {
        VL_DBG_MSGF("         'act' region trigger index 85 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x56U)) {
        VL_DBG_MSGF("         'act' region trigger index 86 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x57U)) {
        VL_DBG_MSGF("         'act' region trigger index 87 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x58U)) {
        VL_DBG_MSGF("         'act' region trigger index 88 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x59U)) {
        VL_DBG_MSGF("         'act' region trigger index 89 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x5aU)) {
        VL_DBG_MSGF("         'act' region trigger index 90 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x5bU)) {
        VL_DBG_MSGF("         'act' region trigger index 91 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x5cU)) {
        VL_DBG_MSGF("         'act' region trigger index 92 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x5dU)) {
        VL_DBG_MSGF("         'act' region trigger index 93 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x5eU)) {
        VL_DBG_MSGF("         'act' region trigger index 94 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x5fU)) {
        VL_DBG_MSGF("         'act' region trigger index 95 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x60U)) {
        VL_DBG_MSGF("         'act' region trigger index 96 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x61U)) {
        VL_DBG_MSGF("         'act' region trigger index 97 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x62U)) {
        VL_DBG_MSGF("         'act' region trigger index 98 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VactTriggered.at(0x63U)) {
        VL_DBG_MSGF("         'act' region trigger index 99 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VactTriggered.at(0x64U)) {
        VL_DBG_MSGF("         'act' region trigger index 100 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(0x65U)) {
        VL_DBG_MSGF("         'act' region trigger index 101 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__nba(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(4U)) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(7U)) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(8U)) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(9U)) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xaU)) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xbU)) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xcU)) {
        VL_DBG_MSGF("         'nba' region trigger index 12 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xdU)) {
        VL_DBG_MSGF("         'nba' region trigger index 13 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xeU)) {
        VL_DBG_MSGF("         'nba' region trigger index 14 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xfU)) {
        VL_DBG_MSGF("         'nba' region trigger index 15 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x10U)) {
        VL_DBG_MSGF("         'nba' region trigger index 16 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x11U)) {
        VL_DBG_MSGF("         'nba' region trigger index 17 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x12U)) {
        VL_DBG_MSGF("         'nba' region trigger index 18 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x13U)) {
        VL_DBG_MSGF("         'nba' region trigger index 19 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x14U)) {
        VL_DBG_MSGF("         'nba' region trigger index 20 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x15U)) {
        VL_DBG_MSGF("         'nba' region trigger index 21 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x16U)) {
        VL_DBG_MSGF("         'nba' region trigger index 22 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x17U)) {
        VL_DBG_MSGF("         'nba' region trigger index 23 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.result.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x18U)) {
        VL_DBG_MSGF("         'nba' region trigger index 24 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x19U)) {
        VL_DBG_MSGF("         'nba' region trigger index 25 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x1aU)) {
        VL_DBG_MSGF("         'nba' region trigger index 26 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x1bU)) {
        VL_DBG_MSGF("         'nba' region trigger index 27 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x1cU)) {
        VL_DBG_MSGF("         'nba' region trigger index 28 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x1dU)) {
        VL_DBG_MSGF("         'nba' region trigger index 29 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x1eU)) {
        VL_DBG_MSGF("         'nba' region trigger index 30 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x1fU)) {
        VL_DBG_MSGF("         'nba' region trigger index 31 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x20U)) {
        VL_DBG_MSGF("         'nba' region trigger index 32 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x21U)) {
        VL_DBG_MSGF("         'nba' region trigger index 33 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x22U)) {
        VL_DBG_MSGF("         'nba' region trigger index 34 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x23U)) {
        VL_DBG_MSGF("         'nba' region trigger index 35 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x24U)) {
        VL_DBG_MSGF("         'nba' region trigger index 36 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x25U)) {
        VL_DBG_MSGF("         'nba' region trigger index 37 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s1 or [hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x26U)) {
        VL_DBG_MSGF("         'nba' region trigger index 38 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x27U)) {
        VL_DBG_MSGF("         'nba' region trigger index 39 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x28U)) {
        VL_DBG_MSGF("         'nba' region trigger index 40 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.signcomp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x29U)) {
        VL_DBG_MSGF("         'nba' region trigger index 41 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x2aU)) {
        VL_DBG_MSGF("         'nba' region trigger index 42 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x2bU)) {
        VL_DBG_MSGF("         'nba' region trigger index 43 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x2cU)) {
        VL_DBG_MSGF("         'nba' region trigger index 44 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x2dU)) {
        VL_DBG_MSGF("         'nba' region trigger index 45 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x2eU)) {
        VL_DBG_MSGF("         'nba' region trigger index 46 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x2fU)) {
        VL_DBG_MSGF("         'nba' region trigger index 47 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x30U)) {
        VL_DBG_MSGF("         'nba' region trigger index 48 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x31U)) {
        VL_DBG_MSGF("         'nba' region trigger index 49 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x32U)) {
        VL_DBG_MSGF("         'nba' region trigger index 50 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x33U)) {
        VL_DBG_MSGF("         'nba' region trigger index 51 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x34U)) {
        VL_DBG_MSGF("         'nba' region trigger index 52 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x35U)) {
        VL_DBG_MSGF("         'nba' region trigger index 53 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x36U)) {
        VL_DBG_MSGF("         'nba' region trigger index 54 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s1 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x37U)) {
        VL_DBG_MSGF("         'nba' region trigger index 55 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x38U)) {
        VL_DBG_MSGF("         'nba' region trigger index 56 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x39U)) {
        VL_DBG_MSGF("         'nba' region trigger index 57 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x3aU)) {
        VL_DBG_MSGF("         'nba' region trigger index 58 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x3bU)) {
        VL_DBG_MSGF("         'nba' region trigger index 59 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x3cU)) {
        VL_DBG_MSGF("         'nba' region trigger index 60 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x3dU)) {
        VL_DBG_MSGF("         'nba' region trigger index 61 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x3eU)) {
        VL_DBG_MSGF("         'nba' region trigger index 62 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x3fU)) {
        VL_DBG_MSGF("         'nba' region trigger index 63 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x40U)) {
        VL_DBG_MSGF("         'nba' region trigger index 64 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x41U)) {
        VL_DBG_MSGF("         'nba' region trigger index 65 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x42U)) {
        VL_DBG_MSGF("         'nba' region trigger index 66 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x43U)) {
        VL_DBG_MSGF("         'nba' region trigger index 67 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x44U)) {
        VL_DBG_MSGF("         'nba' region trigger index 68 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x45U)) {
        VL_DBG_MSGF("         'nba' region trigger index 69 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x46U)) {
        VL_DBG_MSGF("         'nba' region trigger index 70 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x47U)) {
        VL_DBG_MSGF("         'nba' region trigger index 71 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x48U)) {
        VL_DBG_MSGF("         'nba' region trigger index 72 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x49U)) {
        VL_DBG_MSGF("         'nba' region trigger index 73 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x4aU)) {
        VL_DBG_MSGF("         'nba' region trigger index 74 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s0 or [hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x4bU)) {
        VL_DBG_MSGF("         'nba' region trigger index 75 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x4cU)) {
        VL_DBG_MSGF("         'nba' region trigger index 76 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c6_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x4dU)) {
        VL_DBG_MSGF("         'nba' region trigger index 77 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x4eU)) {
        VL_DBG_MSGF("         'nba' region trigger index 78 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c5_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x4fU)) {
        VL_DBG_MSGF("         'nba' region trigger index 79 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x50U)) {
        VL_DBG_MSGF("         'nba' region trigger index 80 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c4_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x51U)) {
        VL_DBG_MSGF("         'nba' region trigger index 81 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x52U)) {
        VL_DBG_MSGF("         'nba' region trigger index 82 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c3_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x53U)) {
        VL_DBG_MSGF("         'nba' region trigger index 83 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x54U)) {
        VL_DBG_MSGF("         'nba' region trigger index 84 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c2_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x55U)) {
        VL_DBG_MSGF("         'nba' region trigger index 85 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x56U)) {
        VL_DBG_MSGF("         'nba' region trigger index 86 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x57U)) {
        VL_DBG_MSGF("         'nba' region trigger index 87 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_low.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x58U)) {
        VL_DBG_MSGF("         'nba' region trigger index 88 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c6_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x59U)) {
        VL_DBG_MSGF("         'nba' region trigger index 89 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c6_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x5aU)) {
        VL_DBG_MSGF("         'nba' region trigger index 90 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c5_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x5bU)) {
        VL_DBG_MSGF("         'nba' region trigger index 91 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c5_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x5cU)) {
        VL_DBG_MSGF("         'nba' region trigger index 92 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c4_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x5dU)) {
        VL_DBG_MSGF("         'nba' region trigger index 93 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c4_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x5eU)) {
        VL_DBG_MSGF("         'nba' region trigger index 94 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c3_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x5fU)) {
        VL_DBG_MSGF("         'nba' region trigger index 95 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c3_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x60U)) {
        VL_DBG_MSGF("         'nba' region trigger index 96 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c2_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x61U)) {
        VL_DBG_MSGF("         'nba' region trigger index 97 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c2_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x62U)) {
        VL_DBG_MSGF("         'nba' region trigger index 98 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c1_s0)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x63U)) {
        VL_DBG_MSGF("         'nba' region trigger index 99 is active: @([hybrid] verilator_top.cpu.exu.mul.o.o1.resulttemp.adder_high.c1_s1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x64U)) {
        VL_DBG_MSGF("         'nba' region trigger index 100 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0x65U)) {
        VL_DBG_MSGF("         'nba' region trigger index 101 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vverilator_top___024root___ctor_var_reset(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigrprev__TOP__verilator_top____PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

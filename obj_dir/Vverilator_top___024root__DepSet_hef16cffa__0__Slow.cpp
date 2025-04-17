// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top__Syms.h"
#include "Vverilator_top___024root.h"

VL_ATTR_COLD void Vverilator_top_verilator_top___eval_initial__TOP__verilator_top(Vverilator_top_verilator_top* vlSelf);

VL_ATTR_COLD void Vverilator_top___024root___eval_initial(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_initial\n"); );
    // Body
    Vverilator_top_verilator_top___eval_initial__TOP__verilator_top((&vlSymsp->TOP__verilator_top));
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__stl(Vverilator_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vverilator_top___024root___eval_triggers__stl(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vverilator_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vverilator_top_verilator_top___stl_sequent__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf);

VL_ATTR_COLD void Vverilator_top___024root___eval_stl(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vverilator_top_verilator_top___stl_sequent__TOP__verilator_top__0((&vlSymsp->TOP__verilator_top));
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

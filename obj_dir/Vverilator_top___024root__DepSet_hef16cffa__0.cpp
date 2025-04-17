// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top__Syms.h"
#include "Vverilator_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__act(Vverilator_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vverilator_top___024root___eval_triggers__act(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(1U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->rst) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__rst))));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vverilator_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf);
void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__1(Vverilator_top_verilator_top* vlSelf);
void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__2(Vverilator_top_verilator_top* vlSelf);
void Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf);

void Vverilator_top___024root___eval_nba(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__0((&vlSymsp->TOP__verilator_top));
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__1((&vlSymsp->TOP__verilator_top));
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__2((&vlSymsp->TOP__verilator_top));
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__0((&vlSymsp->TOP__verilator_top));
    }
}

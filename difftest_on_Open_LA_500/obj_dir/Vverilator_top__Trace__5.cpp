// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vverilator_top__Syms.h"


void Vverilator_top___024root__trace_chg_sub_5(Vverilator_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_chg_sub_5\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 10799);
    VlWide<4>/*127:0*/ __Vtemp_h8178c22d__0;
    VlWide<4>/*127:0*/ __Vtemp_h8178c37b__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgBit(oldp+0,((((~ (IData)((0x3ffULL 
                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1cU)))) 
                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                              | (((IData)((0x3ffULL 
                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1cU))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                 | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                      [0x36U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                    | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x36U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1,((1U & (IData)((0x1ffULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1dU))))));
        bufp->chgBit(oldp+2,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                              [0x37U])));
        bufp->chgBit(oldp+3,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                    [0x37U] >> 1U))));
        bufp->chgBit(oldp+4,((1U & (~ (IData)((0x1ffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU)))))));
        bufp->chgBit(oldp+5,((((~ (IData)((0x1ffULL 
                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1dU)))) 
                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                              | (((IData)((0x1ffULL 
                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1dU))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                 | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                      [0x37U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                    | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x37U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+6,((1U & (IData)((0xffULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1eU))))));
        bufp->chgBit(oldp+7,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                              [0x38U])));
        bufp->chgBit(oldp+8,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                    [0x38U] >> 1U))));
        bufp->chgBit(oldp+9,((1U & (~ (IData)((0xffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU)))))));
        bufp->chgBit(oldp+10,((((~ (IData)((0xffULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1eU)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0xffULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1eU))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x38U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x38U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+11,((1U & (IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1fU))))));
        bufp->chgBit(oldp+12,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [0x39U])));
        bufp->chgBit(oldp+13,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [0x39U] >> 1U))));
        bufp->chgBit(oldp+14,((1U & (~ (IData)((0x7fULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   >> 0x1fU)))))));
        bufp->chgBit(oldp+15,((((~ (IData)((0x7fULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1fU)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x7fULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1fU))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x39U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x39U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+16,((1U & (IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x20U))))));
        bufp->chgBit(oldp+17,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [0x3aU])));
        bufp->chgBit(oldp+18,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [0x3aU] >> 1U))));
        bufp->chgBit(oldp+19,((1U & (~ (IData)((0x3fULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   >> 0x20U)))))));
        bufp->chgBit(oldp+20,((((~ (IData)((0x3fULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x20U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x3fULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x20U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x3aU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x3aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+21,((1U & (IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x21U))))));
        bufp->chgBit(oldp+22,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [0x3bU])));
        bufp->chgBit(oldp+23,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [0x3bU] >> 1U))));
        bufp->chgBit(oldp+24,((1U & (~ (IData)((0x1fULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   >> 0x21U)))))));
        bufp->chgBit(oldp+25,((((~ (IData)((0x1fULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x21U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x1fULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x21U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x3bU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x3bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+26,((1U & (IData)((0x7ffffffffe00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x15U))))));
        bufp->chgBit(oldp+27,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [5U])));
        bufp->chgBit(oldp+28,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [5U] >> 1U))));
        bufp->chgBit(oldp+29,((1U & (~ (IData)((0x7ffffffffe00000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x15U)))))));
        bufp->chgBit(oldp+30,((((~ (IData)((0x7ffffffffe00000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x15U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x7ffffffffe00000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x15U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [5U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [5U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+31,((1U & (IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x22U))))));
        bufp->chgBit(oldp+32,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [0x3cU])));
        bufp->chgBit(oldp+33,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [0x3cU] >> 1U))));
        bufp->chgBit(oldp+34,((1U & (~ (IData)((0xfULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   >> 0x22U)))))));
        bufp->chgBit(oldp+35,((((~ (IData)((0xfULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x22U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0xfULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x22U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x3cU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x3cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+36,((1U & (IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x23U))))));
        bufp->chgBit(oldp+37,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [0x3dU])));
        bufp->chgBit(oldp+38,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [0x3dU] >> 1U))));
        bufp->chgBit(oldp+39,((1U & (~ (IData)((7ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   >> 0x23U)))))));
        bufp->chgBit(oldp+40,((((~ (IData)((7ULL & 
                                            (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x23U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((7ULL & 
                                            (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x23U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x3dU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x3dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+41,((1U & (IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x24U))))));
        bufp->chgBit(oldp+42,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [0x3eU])));
        bufp->chgBit(oldp+43,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [0x3eU] >> 1U))));
        bufp->chgBit(oldp+44,((1U & (~ (IData)((3ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   >> 0x24U)))))));
        bufp->chgBit(oldp+45,((((~ (IData)((3ULL & 
                                            (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x24U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((3ULL & 
                                            (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x24U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x3eU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x3eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+46,((1U & (IData)((1ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x25U))))));
        bufp->chgBit(oldp+47,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [0x3fU])));
        bufp->chgBit(oldp+48,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [0x3fU] >> 1U))));
        bufp->chgBit(oldp+49,((1U & (~ (IData)((1ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   >> 0x25U)))))));
        bufp->chgBit(oldp+50,((((~ (IData)((1ULL & 
                                            (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x25U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | ((IData)(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x25U) 
                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x))) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [0x3fU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [0x3fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+51,((1U & (IData)((0x3fffffffff00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x14U))))));
        bufp->chgBit(oldp+52,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [6U])));
        bufp->chgBit(oldp+53,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [6U] >> 1U))));
        bufp->chgBit(oldp+54,((1U & (~ (IData)((0x3fffffffff00000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x14U)))))));
        bufp->chgBit(oldp+55,((((~ (IData)((0x3fffffffff00000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x14U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x3fffffffff00000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x14U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [6U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [6U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+56,((1U & (IData)((0x1fffffffff80000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x13U))))));
        bufp->chgBit(oldp+57,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [7U])));
        bufp->chgBit(oldp+58,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [7U] >> 1U))));
        bufp->chgBit(oldp+59,((1U & (~ (IData)((0x1fffffffff80000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x13U)))))));
        bufp->chgBit(oldp+60,((((~ (IData)((0x1fffffffff80000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x13U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x1fffffffff80000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x13U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [7U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [7U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+61,((1U & (IData)((0xfffffffffc0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x12U))))));
        bufp->chgBit(oldp+62,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [8U])));
        bufp->chgBit(oldp+63,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [8U] >> 1U))));
        bufp->chgBit(oldp+64,((1U & (~ (IData)((0xfffffffffc0000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x12U)))))));
        bufp->chgBit(oldp+65,((((~ (IData)((0xfffffffffc0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0xfffffffffc0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [8U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [8U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+66,((1U & (IData)((0x7ffffffffe0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x11U))))));
        bufp->chgBit(oldp+67,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                               [9U])));
        bufp->chgBit(oldp+68,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                     [9U] >> 1U))));
        bufp->chgBit(oldp+69,((1U & (~ (IData)((0x7ffffffffe0000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x11U)))))));
        bufp->chgBit(oldp+70,((((~ (IData)((0x7ffffffffe0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x7ffffffffe0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                       [9U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT__CarrySig
                                        [9U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+71,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                             >> 0x1bU)))));
        bufp->chgBit(oldp+72,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                             >> 0x1aU)))));
        bufp->chgCData(oldp+73,((7U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 0x1bU)))),3);
        bufp->chgQData(oldp+74,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                 << 0x1cU)),64);
        bufp->chgQData(oldp+76,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__OutX),64);
        bufp->chgBit(oldp+78,(((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x) 
                               | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx))));
        bufp->chgBit(oldp+79,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx));
        bufp->chgBit(oldp+80,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x));
        bufp->chgBit(oldp+81,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x));
        bufp->chgBit(oldp+82,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x1cU)))));
        bufp->chgBit(oldp+83,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1cU))))));
        bufp->chgBit(oldp+84,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            << 0x1cU))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            << 0x1cU)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                  | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)))));
        bufp->chgBit(oldp+85,((1U & (IData)((0x3ffffffffc0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x12U))))));
        bufp->chgBit(oldp+86,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                               [0xaU])));
        bufp->chgBit(oldp+87,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                     [0xaU] >> 1U))));
        bufp->chgBit(oldp+88,((1U & (~ (IData)((0x3ffffffffc0000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x12U)))))));
        bufp->chgBit(oldp+89,((((~ (IData)((0x3ffffffffc0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x3ffffffffc0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                       [0xaU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0xaU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+90,((1U & (IData)((0x1ffffffffe0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x11U))))));
        bufp->chgBit(oldp+91,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                               [0xbU])));
        bufp->chgBit(oldp+92,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                     [0xbU] >> 1U))));
        bufp->chgBit(oldp+93,((1U & (~ (IData)((0x1ffffffffe0000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x11U)))))));
        bufp->chgBit(oldp+94,((((~ (IData)((0x1ffffffffe0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0x1ffffffffe0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                       [0xbU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0xbU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+95,((1U & (IData)((0xfffffffff0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x10U))))));
        bufp->chgBit(oldp+96,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                               [0xcU])));
        bufp->chgBit(oldp+97,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                     [0xcU] >> 1U))));
        bufp->chgBit(oldp+98,((1U & (~ (IData)((0xfffffffff0000ULL 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                   << 0x10U)))))));
        bufp->chgBit(oldp+99,((((~ (IData)((0xfffffffff0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x10U)))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                               | (((IData)((0xfffffffff0000ULL 
                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x10U))) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                  | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                       [0xcU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                     | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0xcU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+100,((1U & (IData)((0x7ffffffff8000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xfU))))));
        bufp->chgBit(oldp+101,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0xdU])));
        bufp->chgBit(oldp+102,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0xdU] >> 1U))));
        bufp->chgBit(oldp+103,((1U & (~ (IData)((0x7ffffffff8000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xfU)))))));
        bufp->chgBit(oldp+104,((((~ (IData)((0x7ffffffff8000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffff8000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0xdU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0xdU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+105,((1U & (IData)((0x3ffffffffc000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xeU))))));
        bufp->chgBit(oldp+106,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0xeU])));
        bufp->chgBit(oldp+107,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0xeU] >> 1U))));
        bufp->chgBit(oldp+108,((1U & (~ (IData)((0x3ffffffffc000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xeU)))))));
        bufp->chgBit(oldp+109,((((~ (IData)((0x3ffffffffc000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffc000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0xeU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0xeU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+110,((1U & (IData)((0x1ffffffffe000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))));
        bufp->chgBit(oldp+111,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0xfU])));
        bufp->chgBit(oldp+112,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0xfU] >> 1U))));
        bufp->chgBit(oldp+113,((1U & (~ (IData)((0x1ffffffffe000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xdU)))))));
        bufp->chgBit(oldp+114,((((~ (IData)((0x1ffffffffe000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffe000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0xfU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0xfU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+115,((1U & (IData)((0xfffffffff000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xcU))))));
        bufp->chgBit(oldp+116,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x10U])));
        bufp->chgBit(oldp+117,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x10U] >> 1U))));
        bufp->chgBit(oldp+118,((1U & (~ (IData)((0xfffffffff000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xcU)))))));
        bufp->chgBit(oldp+119,((((~ (IData)((0xfffffffff000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffff000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x10U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x10U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+120,((1U & (IData)((0x7ffffffff800ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xbU))))));
        bufp->chgBit(oldp+121,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x11U])));
        bufp->chgBit(oldp+122,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x11U] >> 1U))));
        bufp->chgBit(oldp+123,((1U & (~ (IData)((0x7ffffffff800ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xbU)))))));
        bufp->chgBit(oldp+124,((((~ (IData)((0x7ffffffff800ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffff800ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x11U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x11U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+125,((1U & (IData)((0x3ffffffffc00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xaU))))));
        bufp->chgBit(oldp+126,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x12U])));
        bufp->chgBit(oldp+127,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x12U] >> 1U))));
        bufp->chgBit(oldp+128,((1U & (~ (IData)((0x3ffffffffc00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xaU)))))));
        bufp->chgBit(oldp+129,((((~ (IData)((0x3ffffffffc00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffc00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x12U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x12U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+130,((1U & (IData)((0x1ffffffffe00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 9U))))));
        bufp->chgBit(oldp+131,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x13U])));
        bufp->chgBit(oldp+132,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x13U] >> 1U))));
        bufp->chgBit(oldp+133,((1U & (~ (IData)((0x1ffffffffe00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 9U)))))));
        bufp->chgBit(oldp+134,((((~ (IData)((0x1ffffffffe00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffe00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x13U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x13U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+135,((1U & (IData)((0x7ffffffff8000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1bU))))));
        bufp->chgBit(oldp+136,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [1U])));
        bufp->chgBit(oldp+137,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [1U] >> 1U))));
        bufp->chgBit(oldp+138,((1U & (~ (IData)((0x7ffffffff8000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1bU)))))));
        bufp->chgBit(oldp+139,((((~ (IData)((0x7ffffffff8000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffff8000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [1U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [1U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+140,((1U & (IData)((0xfffffffff00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 8U))))));
        bufp->chgBit(oldp+141,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x14U])));
        bufp->chgBit(oldp+142,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x14U] >> 1U))));
        bufp->chgBit(oldp+143,((1U & (~ (IData)((0xfffffffff00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 8U)))))));
        bufp->chgBit(oldp+144,((((~ (IData)((0xfffffffff00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffff00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x14U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x14U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+145,((1U & (IData)((0x7ffffffff80ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))))));
        bufp->chgBit(oldp+146,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x15U])));
        bufp->chgBit(oldp+147,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x15U] >> 1U))));
        bufp->chgBit(oldp+148,((1U & (~ (IData)((0x7ffffffff80ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 7U)))))));
        bufp->chgBit(oldp+149,((((~ (IData)((0x7ffffffff80ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffff80ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x15U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x15U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+150,((1U & (IData)((0x3ffffffffc0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 6U))))));
        bufp->chgBit(oldp+151,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x16U])));
        bufp->chgBit(oldp+152,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x16U] >> 1U))));
        bufp->chgBit(oldp+153,((1U & (~ (IData)((0x3ffffffffc0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 6U)))))));
        bufp->chgBit(oldp+154,((((~ (IData)((0x3ffffffffc0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffc0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x16U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x16U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+155,((1U & (IData)((0x1ffffffffe0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))))));
        bufp->chgBit(oldp+156,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x17U])));
        bufp->chgBit(oldp+157,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x17U] >> 1U))));
        bufp->chgBit(oldp+158,((1U & (~ (IData)((0x1ffffffffe0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 5U)))))));
        bufp->chgBit(oldp+159,((((~ (IData)((0x1ffffffffe0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 5U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffe0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 5U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x17U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x17U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+160,((1U & (IData)((0xfffffffff0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))));
        bufp->chgBit(oldp+161,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x18U])));
        bufp->chgBit(oldp+162,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x18U] >> 1U))));
        bufp->chgBit(oldp+163,((1U & (~ (IData)((0xfffffffff0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 4U)))))));
        bufp->chgBit(oldp+164,((((~ (IData)((0xfffffffff0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 4U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffff0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 4U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x18U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x18U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+165,((1U & (IData)((0x7ffffffff8ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))));
        bufp->chgBit(oldp+166,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x19U])));
        bufp->chgBit(oldp+167,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x19U] >> 1U))));
        bufp->chgBit(oldp+168,((1U & (~ (IData)((0x7ffffffff8ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 3U)))))));
        bufp->chgBit(oldp+169,((((~ (IData)((0x7ffffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x19U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x19U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+170,((1U & (IData)((0x3ffffffffcULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))));
        bufp->chgBit(oldp+171,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x1aU])));
        bufp->chgBit(oldp+172,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x1aU] >> 1U))));
        bufp->chgBit(oldp+173,((1U & (~ (IData)((0x3ffffffffcULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 2U)))))));
        bufp->chgBit(oldp+174,((((~ (IData)((0x3ffffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x1aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x1aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+175,((1U & (IData)((0x1ffffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))));
        bufp->chgBit(oldp+176,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x1bU])));
        bufp->chgBit(oldp+177,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x1bU] >> 1U))));
        bufp->chgBit(oldp+178,((1U & (~ (IData)((0x1ffffffffeULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 1U)))))));
        bufp->chgBit(oldp+179,((((~ (IData)((0x1ffffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x1bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x1bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+180,((1U & (IData)((0xfffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)))));
        bufp->chgBit(oldp+181,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x1cU])));
        bufp->chgBit(oldp+182,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x1cU] >> 1U))));
        bufp->chgBit(oldp+183,((1U & (~ (IData)((0xfffffffffULL 
                                                 & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))))));
        bufp->chgBit(oldp+184,((((~ (IData)((0xfffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x1cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x1cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+185,((1U & (IData)((0x7ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))));
        bufp->chgBit(oldp+186,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x1dU])));
        bufp->chgBit(oldp+187,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x1dU] >> 1U))));
        bufp->chgBit(oldp+188,((1U & (~ (IData)((0x7ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 1U)))))));
        bufp->chgBit(oldp+189,((((~ (IData)((0x7ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x1dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x1dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+190,((1U & (IData)((0x3ffffffffc000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1aU))))));
        bufp->chgBit(oldp+191,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [2U])));
        bufp->chgBit(oldp+192,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [2U] >> 1U))));
        bufp->chgBit(oldp+193,((1U & (~ (IData)((0x3ffffffffc000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1aU)))))));
        bufp->chgBit(oldp+194,((((~ (IData)((0x3ffffffffc000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffc000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [2U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [2U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+195,((1U & (IData)((0x3ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))));
        bufp->chgBit(oldp+196,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x1eU])));
        bufp->chgBit(oldp+197,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x1eU] >> 1U))));
        bufp->chgBit(oldp+198,((1U & (~ (IData)((0x3ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 2U)))))));
        bufp->chgBit(oldp+199,((((~ (IData)((0x3ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x1eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x1eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+200,((1U & (IData)((0x1ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))));
        bufp->chgBit(oldp+201,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x1fU])));
        bufp->chgBit(oldp+202,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x1fU] >> 1U))));
        bufp->chgBit(oldp+203,((1U & (~ (IData)((0x1ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 3U)))))));
        bufp->chgBit(oldp+204,((((~ (IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x1fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x1fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+205,((1U & (IData)((0xffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))));
        bufp->chgBit(oldp+206,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x20U])));
        bufp->chgBit(oldp+207,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x20U] >> 1U))));
        bufp->chgBit(oldp+208,((1U & (~ (IData)((0xffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 4U)))))));
        bufp->chgBit(oldp+209,((((~ (IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x20U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x20U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+210,((1U & (IData)((0x7fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))));
        bufp->chgBit(oldp+211,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x21U])));
        bufp->chgBit(oldp+212,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x21U] >> 1U))));
        bufp->chgBit(oldp+213,((1U & (~ (IData)((0x7fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 5U)))))));
        bufp->chgBit(oldp+214,((((~ (IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x21U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x21U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+215,((1U & (IData)((0x3fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))));
        bufp->chgBit(oldp+216,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x22U])));
        bufp->chgBit(oldp+217,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x22U] >> 1U))));
        bufp->chgBit(oldp+218,((1U & (~ (IData)((0x3fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 6U)))))));
        bufp->chgBit(oldp+219,((((~ (IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x22U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x22U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+220,((1U & (IData)((0x1fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))));
        bufp->chgBit(oldp+221,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x23U])));
        bufp->chgBit(oldp+222,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x23U] >> 1U))));
        bufp->chgBit(oldp+223,((1U & (~ (IData)((0x1fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 7U)))))));
        bufp->chgBit(oldp+224,((((~ (IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x23U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x23U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+225,((1U & (IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))));
        bufp->chgBit(oldp+226,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x24U])));
        bufp->chgBit(oldp+227,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x24U] >> 1U))));
        bufp->chgBit(oldp+228,((1U & (~ (IData)((0xfffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 8U)))))));
        bufp->chgBit(oldp+229,((((~ (IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x24U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x24U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+230,((1U & (IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))));
        bufp->chgBit(oldp+231,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x25U])));
        bufp->chgBit(oldp+232,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x25U] >> 1U))));
        bufp->chgBit(oldp+233,((1U & (~ (IData)((0x7ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 9U)))))));
        bufp->chgBit(oldp+234,((((~ (IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x25U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x25U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+235,((1U & (IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))));
        bufp->chgBit(oldp+236,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x26U])));
        bufp->chgBit(oldp+237,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x26U] >> 1U))));
        bufp->chgBit(oldp+238,((1U & (~ (IData)((0x3ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xaU)))))));
        bufp->chgBit(oldp+239,((((~ (IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x26U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x26U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+240,((1U & (IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))));
        bufp->chgBit(oldp+241,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x27U])));
        bufp->chgBit(oldp+242,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x27U] >> 1U))));
        bufp->chgBit(oldp+243,((1U & (~ (IData)((0x1ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xbU)))))));
        bufp->chgBit(oldp+244,((((~ (IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x27U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x27U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+245,((1U & (IData)((0x1ffffffffe000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x19U))))));
        bufp->chgBit(oldp+246,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [3U])));
        bufp->chgBit(oldp+247,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [3U] >> 1U))));
        bufp->chgBit(oldp+248,((1U & (~ (IData)((0x1ffffffffe000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x19U)))))));
        bufp->chgBit(oldp+249,((((~ (IData)((0x1ffffffffe000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffe000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [3U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [3U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+250,((1U & (IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))));
        bufp->chgBit(oldp+251,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x28U])));
        bufp->chgBit(oldp+252,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x28U] >> 1U))));
        bufp->chgBit(oldp+253,((1U & (~ (IData)((0xffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xcU)))))));
        bufp->chgBit(oldp+254,((((~ (IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x28U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x28U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+255,((1U & (IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))));
        bufp->chgBit(oldp+256,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x29U])));
        bufp->chgBit(oldp+257,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x29U] >> 1U))));
        bufp->chgBit(oldp+258,((1U & (~ (IData)((0x7fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xdU)))))));
        bufp->chgBit(oldp+259,((((~ (IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x29U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x29U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+260,((1U & (IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))));
        bufp->chgBit(oldp+261,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x2aU])));
        bufp->chgBit(oldp+262,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x2aU] >> 1U))));
        bufp->chgBit(oldp+263,((1U & (~ (IData)((0x3fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xeU)))))));
        bufp->chgBit(oldp+264,((((~ (IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x2aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x2aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+265,((1U & (IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))));
        bufp->chgBit(oldp+266,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x2bU])));
        bufp->chgBit(oldp+267,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x2bU] >> 1U))));
        bufp->chgBit(oldp+268,((1U & (~ (IData)((0x1fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xfU)))))));
        bufp->chgBit(oldp+269,((((~ (IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x2bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x2bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+270,((1U & (IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))));
        bufp->chgBit(oldp+271,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x2cU])));
        bufp->chgBit(oldp+272,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x2cU] >> 1U))));
        bufp->chgBit(oldp+273,((1U & (~ (IData)((0xfffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x10U)))))));
        bufp->chgBit(oldp+274,((((~ (IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x2cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x2cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+275,((1U & (IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))));
        bufp->chgBit(oldp+276,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x2dU])));
        bufp->chgBit(oldp+277,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x2dU] >> 1U))));
        bufp->chgBit(oldp+278,((1U & (~ (IData)((0x7ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x11U)))))));
        bufp->chgBit(oldp+279,((((~ (IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x2dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x2dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+280,((1U & (IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))));
        bufp->chgBit(oldp+281,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x2eU])));
        bufp->chgBit(oldp+282,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x2eU] >> 1U))));
        bufp->chgBit(oldp+283,((1U & (~ (IData)((0x3ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x12U)))))));
        bufp->chgBit(oldp+284,((((~ (IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x2eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x2eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+285,((1U & (IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))));
        bufp->chgBit(oldp+286,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x2fU])));
        bufp->chgBit(oldp+287,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x2fU] >> 1U))));
        bufp->chgBit(oldp+288,((1U & (~ (IData)((0x1ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x13U)))))));
        bufp->chgBit(oldp+289,((((~ (IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x2fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x2fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+290,((1U & (IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))));
        bufp->chgBit(oldp+291,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x30U])));
        bufp->chgBit(oldp+292,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x30U] >> 1U))));
        bufp->chgBit(oldp+293,((1U & (~ (IData)((0xffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x14U)))))));
        bufp->chgBit(oldp+294,((((~ (IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x30U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x30U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+295,((1U & (IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))));
        bufp->chgBit(oldp+296,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x31U])));
        bufp->chgBit(oldp+297,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x31U] >> 1U))));
        bufp->chgBit(oldp+298,((1U & (~ (IData)((0x7fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x15U)))))));
        bufp->chgBit(oldp+299,((((~ (IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x31U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x31U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+300,((1U & (IData)((0xfffffffff000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x18U))))));
        bufp->chgBit(oldp+301,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [4U])));
        bufp->chgBit(oldp+302,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [4U] >> 1U))));
        bufp->chgBit(oldp+303,((1U & (~ (IData)((0xfffffffff000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x18U)))))));
        bufp->chgBit(oldp+304,((((~ (IData)((0xfffffffff000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffff000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [4U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [4U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+305,((1U & (IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))));
        bufp->chgBit(oldp+306,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x32U])));
        bufp->chgBit(oldp+307,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x32U] >> 1U))));
        bufp->chgBit(oldp+308,((1U & (~ (IData)((0x3fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x16U)))))));
        bufp->chgBit(oldp+309,((((~ (IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x32U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x32U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+310,((1U & (IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))));
        bufp->chgBit(oldp+311,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x33U])));
        bufp->chgBit(oldp+312,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x33U] >> 1U))));
        bufp->chgBit(oldp+313,((1U & (~ (IData)((0x1fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x17U)))))));
        bufp->chgBit(oldp+314,((((~ (IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x33U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x33U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+315,((1U & (IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))));
        bufp->chgBit(oldp+316,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x34U])));
        bufp->chgBit(oldp+317,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x34U] >> 1U))));
        bufp->chgBit(oldp+318,((1U & (~ (IData)((0xfffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x18U)))))));
        bufp->chgBit(oldp+319,((((~ (IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x34U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x34U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+320,((1U & (IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))));
        bufp->chgBit(oldp+321,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x35U])));
        bufp->chgBit(oldp+322,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x35U] >> 1U))));
        bufp->chgBit(oldp+323,((1U & (~ (IData)((0x7ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x19U)))))));
        bufp->chgBit(oldp+324,((((~ (IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x35U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x35U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+325,((1U & (IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))));
        bufp->chgBit(oldp+326,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x36U])));
        bufp->chgBit(oldp+327,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x36U] >> 1U))));
        bufp->chgBit(oldp+328,((1U & (~ (IData)((0x3ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1aU)))))));
        bufp->chgBit(oldp+329,((((~ (IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x36U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x36U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+330,((1U & (IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))));
        bufp->chgBit(oldp+331,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x37U])));
        bufp->chgBit(oldp+332,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x37U] >> 1U))));
        bufp->chgBit(oldp+333,((1U & (~ (IData)((0x1ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1bU)))))));
        bufp->chgBit(oldp+334,((((~ (IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x37U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x37U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+335,((1U & (IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))));
        bufp->chgBit(oldp+336,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x38U])));
        bufp->chgBit(oldp+337,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x38U] >> 1U))));
        bufp->chgBit(oldp+338,((1U & (~ (IData)((0xffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1cU)))))));
        bufp->chgBit(oldp+339,((((~ (IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x38U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x38U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+340,((1U & (IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))));
        bufp->chgBit(oldp+341,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x39U])));
        bufp->chgBit(oldp+342,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x39U] >> 1U))));
        bufp->chgBit(oldp+343,((1U & (~ (IData)((0x7fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1dU)))))));
        bufp->chgBit(oldp+344,((((~ (IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x39U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x39U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+345,((1U & (IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))));
        bufp->chgBit(oldp+346,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x3aU])));
        bufp->chgBit(oldp+347,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x3aU] >> 1U))));
        bufp->chgBit(oldp+348,((1U & (~ (IData)((0x3fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1eU)))))));
        bufp->chgBit(oldp+349,((((~ (IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x3aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x3aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+350,((1U & (IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))));
        bufp->chgBit(oldp+351,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x3bU])));
        bufp->chgBit(oldp+352,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x3bU] >> 1U))));
        bufp->chgBit(oldp+353,((1U & (~ (IData)((0x1fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1fU)))))));
        bufp->chgBit(oldp+354,((((~ (IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1fU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1fU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x3bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x3bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+355,((1U & (IData)((0x7ffffffff800000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x17U))))));
        bufp->chgBit(oldp+356,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [5U])));
        bufp->chgBit(oldp+357,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [5U] >> 1U))));
        bufp->chgBit(oldp+358,((1U & (~ (IData)((0x7ffffffff800000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x17U)))))));
        bufp->chgBit(oldp+359,((((~ (IData)((0x7ffffffff800000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffff800000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [5U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [5U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+360,((1U & (IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))));
        bufp->chgBit(oldp+361,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x3cU])));
        bufp->chgBit(oldp+362,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x3cU] >> 1U))));
        bufp->chgBit(oldp+363,((1U & (~ (IData)((0xfULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x20U)))))));
        bufp->chgBit(oldp+364,((((~ (IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x20U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x20U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x3cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x3cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+365,((1U & (IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))))));
        bufp->chgBit(oldp+366,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x3dU])));
        bufp->chgBit(oldp+367,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x3dU] >> 1U))));
        bufp->chgBit(oldp+368,((1U & (~ (IData)((7ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x21U)))))));
        bufp->chgBit(oldp+369,((((~ (IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x21U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x21U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x3dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x3dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+370,((1U & (IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))))));
        bufp->chgBit(oldp+371,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x3eU])));
        bufp->chgBit(oldp+372,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x3eU] >> 1U))));
        bufp->chgBit(oldp+373,((1U & (~ (IData)((3ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x22U)))))));
        bufp->chgBit(oldp+374,((((~ (IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x22U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x22U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x3eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x3eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+375,((1U & (IData)((1ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U))))));
        bufp->chgBit(oldp+376,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [0x3fU])));
        bufp->chgBit(oldp+377,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [0x3fU] >> 1U))));
        bufp->chgBit(oldp+378,((1U & (~ (IData)((1ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x23U)))))));
        bufp->chgBit(oldp+379,((((~ (IData)((1ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x23U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | ((IData)(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x23U) 
                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x))) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [0x3fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [0x3fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+380,((1U & (IData)((0x3ffffffffc00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x16U))))));
        bufp->chgBit(oldp+381,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [6U])));
        bufp->chgBit(oldp+382,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [6U] >> 1U))));
        bufp->chgBit(oldp+383,((1U & (~ (IData)((0x3ffffffffc00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x16U)))))));
        bufp->chgBit(oldp+384,((((~ (IData)((0x3ffffffffc00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffc00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [6U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [6U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+385,((1U & (IData)((0x1ffffffffe00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x15U))))));
        bufp->chgBit(oldp+386,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [7U])));
        bufp->chgBit(oldp+387,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [7U] >> 1U))));
        bufp->chgBit(oldp+388,((1U & (~ (IData)((0x1ffffffffe00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x15U)))))));
        bufp->chgBit(oldp+389,((((~ (IData)((0x1ffffffffe00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffe00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [7U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [7U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+390,((1U & (IData)((0xfffffffff00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x14U))))));
        bufp->chgBit(oldp+391,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [8U])));
        bufp->chgBit(oldp+392,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [8U] >> 1U))));
        bufp->chgBit(oldp+393,((1U & (~ (IData)((0xfffffffff00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x14U)))))));
        bufp->chgBit(oldp+394,((((~ (IData)((0xfffffffff00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffff00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [8U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [8U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+395,((1U & (IData)((0x7ffffffff80000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x13U))))));
        bufp->chgBit(oldp+396,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                [9U])));
        bufp->chgBit(oldp+397,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                      [9U] >> 1U))));
        bufp->chgBit(oldp+398,((1U & (~ (IData)((0x7ffffffff80000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x13U)))))));
        bufp->chgBit(oldp+399,((((~ (IData)((0x7ffffffff80000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffff80000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                        [9U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT__CarrySig
                                         [9U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+400,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x1dU)))));
        bufp->chgBit(oldp+401,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x1cU)))));
        bufp->chgCData(oldp+402,((7U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                                >> 0x1dU)))),3);
        bufp->chgQData(oldp+403,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                  << 0x1eU)),64);
        bufp->chgQData(oldp+405,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__OutX),64);
        bufp->chgBit(oldp+407,(((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x) 
                                | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx))));
        bufp->chgBit(oldp+408,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx));
        bufp->chgBit(oldp+409,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x));
        bufp->chgBit(oldp+410,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x));
        bufp->chgBit(oldp+411,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 0x1eU)))));
        bufp->chgBit(oldp+412,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1eU))))));
        bufp->chgBit(oldp+413,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x1eU))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x1eU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)))));
        bufp->chgBit(oldp+414,((1U & (IData)((0x3ffffffff00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x14U))))));
        bufp->chgBit(oldp+415,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0xaU])));
        bufp->chgBit(oldp+416,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0xaU] >> 1U))));
        bufp->chgBit(oldp+417,((1U & (~ (IData)((0x3ffffffff00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x14U)))))));
        bufp->chgBit(oldp+418,((((~ (IData)((0x3ffffffff00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffff00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0xaU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0xaU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+419,((1U & (IData)((0x1ffffffff80000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x13U))))));
        bufp->chgBit(oldp+420,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0xbU])));
        bufp->chgBit(oldp+421,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0xbU] >> 1U))));
        bufp->chgBit(oldp+422,((1U & (~ (IData)((0x1ffffffff80000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x13U)))))));
        bufp->chgBit(oldp+423,((((~ (IData)((0x1ffffffff80000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffff80000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0xbU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0xbU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+424,((1U & (IData)((0xffffffffc0000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x12U))))));
        bufp->chgBit(oldp+425,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0xcU])));
        bufp->chgBit(oldp+426,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0xcU] >> 1U))));
        bufp->chgBit(oldp+427,((1U & (~ (IData)((0xffffffffc0000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x12U)))))));
        bufp->chgBit(oldp+428,((((~ (IData)((0xffffffffc0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x12U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffc0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x12U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0xcU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0xcU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+429,((1U & (IData)((0x7fffffffe0000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x11U))))));
        bufp->chgBit(oldp+430,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0xdU])));
        bufp->chgBit(oldp+431,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0xdU] >> 1U))));
        bufp->chgBit(oldp+432,((1U & (~ (IData)((0x7fffffffe0000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x11U)))))));
        bufp->chgBit(oldp+433,((((~ (IData)((0x7fffffffe0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x11U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffe0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x11U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0xdU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0xdU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+434,((1U & (IData)((0x3ffffffff0000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x10U))))));
        bufp->chgBit(oldp+435,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0xeU])));
        bufp->chgBit(oldp+436,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0xeU] >> 1U))));
        bufp->chgBit(oldp+437,((1U & (~ (IData)((0x3ffffffff0000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x10U)))))));
        bufp->chgBit(oldp+438,((((~ (IData)((0x3ffffffff0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x10U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffff0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x10U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0xeU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0xeU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+439,((1U & (IData)((0x1ffffffff8000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xfU))))));
        bufp->chgBit(oldp+440,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0xfU])));
        bufp->chgBit(oldp+441,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0xfU] >> 1U))));
        bufp->chgBit(oldp+442,((1U & (~ (IData)((0x1ffffffff8000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xfU)))))));
        bufp->chgBit(oldp+443,((((~ (IData)((0x1ffffffff8000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffff8000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0xfU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0xfU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+444,((1U & (IData)((0xffffffffc000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xeU))))));
        bufp->chgBit(oldp+445,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x10U])));
        bufp->chgBit(oldp+446,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x10U] >> 1U))));
        bufp->chgBit(oldp+447,((1U & (~ (IData)((0xffffffffc000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xeU)))))));
        bufp->chgBit(oldp+448,((((~ (IData)((0xffffffffc000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffc000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x10U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x10U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+449,((1U & (IData)((0x7fffffffe000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))));
        bufp->chgBit(oldp+450,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x11U])));
        bufp->chgBit(oldp+451,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x11U] >> 1U))));
        bufp->chgBit(oldp+452,((1U & (~ (IData)((0x7fffffffe000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xdU)))))));
        bufp->chgBit(oldp+453,((((~ (IData)((0x7fffffffe000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffe000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x11U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x11U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+454,((1U & (IData)((0x3ffffffff000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xcU))))));
        bufp->chgBit(oldp+455,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x12U])));
        bufp->chgBit(oldp+456,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x12U] >> 1U))));
        bufp->chgBit(oldp+457,((1U & (~ (IData)((0x3ffffffff000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xcU)))))));
        bufp->chgBit(oldp+458,((((~ (IData)((0x3ffffffff000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffff000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x12U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x12U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+459,((1U & (IData)((0x1ffffffff800ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xbU))))));
        bufp->chgBit(oldp+460,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x13U])));
        bufp->chgBit(oldp+461,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x13U] >> 1U))));
        bufp->chgBit(oldp+462,((1U & (~ (IData)((0x1ffffffff800ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xbU)))))));
        bufp->chgBit(oldp+463,((((~ (IData)((0x1ffffffff800ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffff800ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x13U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x13U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+464,((1U & (IData)((0x7fffffffe0000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1dU))))));
        bufp->chgBit(oldp+465,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [1U])));
        bufp->chgBit(oldp+466,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [1U] >> 1U))));
        bufp->chgBit(oldp+467,((1U & (~ (IData)((0x7fffffffe0000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1dU)))))));
        bufp->chgBit(oldp+468,((((~ (IData)((0x7fffffffe0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffe0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [1U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [1U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+469,((1U & (IData)((0xffffffffc00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xaU))))));
        bufp->chgBit(oldp+470,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x14U])));
        bufp->chgBit(oldp+471,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x14U] >> 1U))));
        bufp->chgBit(oldp+472,((1U & (~ (IData)((0xffffffffc00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xaU)))))));
        bufp->chgBit(oldp+473,((((~ (IData)((0xffffffffc00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffc00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x14U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x14U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+474,((1U & (IData)((0x7fffffffe00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 9U))))));
        bufp->chgBit(oldp+475,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x15U])));
        bufp->chgBit(oldp+476,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x15U] >> 1U))));
        bufp->chgBit(oldp+477,((1U & (~ (IData)((0x7fffffffe00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 9U)))))));
        bufp->chgBit(oldp+478,((((~ (IData)((0x7fffffffe00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffe00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x15U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x15U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+479,((1U & (IData)((0x3ffffffff00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 8U))))));
        bufp->chgBit(oldp+480,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x16U])));
        bufp->chgBit(oldp+481,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x16U] >> 1U))));
        bufp->chgBit(oldp+482,((1U & (~ (IData)((0x3ffffffff00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 8U)))))));
        bufp->chgBit(oldp+483,((((~ (IData)((0x3ffffffff00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffff00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x16U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x16U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+484,((1U & (IData)((0x1ffffffff80ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))))));
        bufp->chgBit(oldp+485,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x17U])));
        bufp->chgBit(oldp+486,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x17U] >> 1U))));
        bufp->chgBit(oldp+487,((1U & (~ (IData)((0x1ffffffff80ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 7U)))))));
        bufp->chgBit(oldp+488,((((~ (IData)((0x1ffffffff80ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffff80ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x17U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x17U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+489,((1U & (IData)((0xffffffffc0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 6U))))));
        bufp->chgBit(oldp+490,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x18U])));
        bufp->chgBit(oldp+491,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x18U] >> 1U))));
        bufp->chgBit(oldp+492,((1U & (~ (IData)((0xffffffffc0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 6U)))))));
        bufp->chgBit(oldp+493,((((~ (IData)((0xffffffffc0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffc0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x18U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x18U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+494,((1U & (IData)((0x7fffffffe0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))))));
        bufp->chgBit(oldp+495,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x19U])));
        bufp->chgBit(oldp+496,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x19U] >> 1U))));
        bufp->chgBit(oldp+497,((1U & (~ (IData)((0x7fffffffe0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 5U)))))));
        bufp->chgBit(oldp+498,((((~ (IData)((0x7fffffffe0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 5U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffe0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 5U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x19U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x19U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+499,((1U & (IData)((0x3ffffffff0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))));
        bufp->chgBit(oldp+500,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x1aU])));
        bufp->chgBit(oldp+501,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x1aU] >> 1U))));
        bufp->chgBit(oldp+502,((1U & (~ (IData)((0x3ffffffff0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 4U)))))));
        bufp->chgBit(oldp+503,((((~ (IData)((0x3ffffffff0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 4U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffff0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 4U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x1aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x1aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+504,((1U & (IData)((0x1ffffffff8ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))));
        bufp->chgBit(oldp+505,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x1bU])));
        bufp->chgBit(oldp+506,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x1bU] >> 1U))));
        bufp->chgBit(oldp+507,((1U & (~ (IData)((0x1ffffffff8ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 3U)))))));
        bufp->chgBit(oldp+508,((((~ (IData)((0x1ffffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x1bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x1bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+509,((1U & (IData)((0xffffffffcULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))));
        bufp->chgBit(oldp+510,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x1cU])));
        bufp->chgBit(oldp+511,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x1cU] >> 1U))));
        bufp->chgBit(oldp+512,((1U & (~ (IData)((0xffffffffcULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 2U)))))));
        bufp->chgBit(oldp+513,((((~ (IData)((0xffffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x1cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x1cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+514,((1U & (IData)((0x7fffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))));
        bufp->chgBit(oldp+515,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x1dU])));
        bufp->chgBit(oldp+516,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x1dU] >> 1U))));
        bufp->chgBit(oldp+517,((1U & (~ (IData)((0x7fffffffeULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 1U)))))));
        bufp->chgBit(oldp+518,((((~ (IData)((0x7fffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x1dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x1dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+519,((1U & (IData)((0x3ffffffff0000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1cU))))));
        bufp->chgBit(oldp+520,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [2U])));
        bufp->chgBit(oldp+521,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [2U] >> 1U))));
        bufp->chgBit(oldp+522,((1U & (~ (IData)((0x3ffffffff0000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1cU)))))));
        bufp->chgBit(oldp+523,((((~ (IData)((0x3ffffffff0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffff0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [2U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [2U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+524,((1U & (IData)((0x3ffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)))));
        bufp->chgBit(oldp+525,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x1eU])));
        bufp->chgBit(oldp+526,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x1eU] >> 1U))));
        bufp->chgBit(oldp+527,((1U & (~ (IData)((0x3ffffffffULL 
                                                 & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))))));
        bufp->chgBit(oldp+528,((((~ (IData)((0x3ffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x1eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x1eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+529,((1U & (IData)((0x1ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))));
        bufp->chgBit(oldp+530,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x1fU])));
        bufp->chgBit(oldp+531,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x1fU] >> 1U))));
        bufp->chgBit(oldp+532,((1U & (~ (IData)((0x1ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 1U)))))));
        bufp->chgBit(oldp+533,((((~ (IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x1fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x1fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+534,((1U & (IData)((0xffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))));
        bufp->chgBit(oldp+535,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x20U])));
        bufp->chgBit(oldp+536,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x20U] >> 1U))));
        bufp->chgBit(oldp+537,((1U & (~ (IData)((0xffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 2U)))))));
        bufp->chgBit(oldp+538,((((~ (IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x20U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x20U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+539,((1U & (IData)((0x7fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))));
        bufp->chgBit(oldp+540,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x21U])));
        bufp->chgBit(oldp+541,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x21U] >> 1U))));
        bufp->chgBit(oldp+542,((1U & (~ (IData)((0x7fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 3U)))))));
        bufp->chgBit(oldp+543,((((~ (IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x21U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x21U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+544,((1U & (IData)((0x3fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))));
        bufp->chgBit(oldp+545,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x22U])));
        bufp->chgBit(oldp+546,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x22U] >> 1U))));
        bufp->chgBit(oldp+547,((1U & (~ (IData)((0x3fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 4U)))))));
        bufp->chgBit(oldp+548,((((~ (IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x22U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x22U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+549,((1U & (IData)((0x1fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))));
        bufp->chgBit(oldp+550,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x23U])));
        bufp->chgBit(oldp+551,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x23U] >> 1U))));
        bufp->chgBit(oldp+552,((1U & (~ (IData)((0x1fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 5U)))))));
        bufp->chgBit(oldp+553,((((~ (IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x23U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x23U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+554,((1U & (IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))));
        bufp->chgBit(oldp+555,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x24U])));
        bufp->chgBit(oldp+556,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x24U] >> 1U))));
        bufp->chgBit(oldp+557,((1U & (~ (IData)((0xfffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 6U)))))));
        bufp->chgBit(oldp+558,((((~ (IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x24U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x24U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+559,((1U & (IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))));
        bufp->chgBit(oldp+560,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x25U])));
        bufp->chgBit(oldp+561,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x25U] >> 1U))));
        bufp->chgBit(oldp+562,((1U & (~ (IData)((0x7ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 7U)))))));
        bufp->chgBit(oldp+563,((((~ (IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x25U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x25U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+564,((1U & (IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))));
        bufp->chgBit(oldp+565,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x26U])));
        bufp->chgBit(oldp+566,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x26U] >> 1U))));
        bufp->chgBit(oldp+567,((1U & (~ (IData)((0x3ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 8U)))))));
        bufp->chgBit(oldp+568,((((~ (IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x26U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x26U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+569,((1U & (IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))));
        bufp->chgBit(oldp+570,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x27U])));
        bufp->chgBit(oldp+571,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x27U] >> 1U))));
        bufp->chgBit(oldp+572,((1U & (~ (IData)((0x1ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 9U)))))));
        bufp->chgBit(oldp+573,((((~ (IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x27U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x27U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+574,((1U & (IData)((0x1ffffffff8000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1bU))))));
        bufp->chgBit(oldp+575,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [3U])));
        bufp->chgBit(oldp+576,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [3U] >> 1U))));
        bufp->chgBit(oldp+577,((1U & (~ (IData)((0x1ffffffff8000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1bU)))))));
        bufp->chgBit(oldp+578,((((~ (IData)((0x1ffffffff8000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffff8000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [3U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [3U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+579,((1U & (IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))));
        bufp->chgBit(oldp+580,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x28U])));
        bufp->chgBit(oldp+581,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x28U] >> 1U))));
        bufp->chgBit(oldp+582,((1U & (~ (IData)((0xffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xaU)))))));
        bufp->chgBit(oldp+583,((((~ (IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x28U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x28U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+584,((1U & (IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))));
        bufp->chgBit(oldp+585,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x29U])));
        bufp->chgBit(oldp+586,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x29U] >> 1U))));
        bufp->chgBit(oldp+587,((1U & (~ (IData)((0x7fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xbU)))))));
        bufp->chgBit(oldp+588,((((~ (IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x29U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x29U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+589,((1U & (IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))));
        bufp->chgBit(oldp+590,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x2aU])));
        bufp->chgBit(oldp+591,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x2aU] >> 1U))));
        bufp->chgBit(oldp+592,((1U & (~ (IData)((0x3fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xcU)))))));
        bufp->chgBit(oldp+593,((((~ (IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x2aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x2aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+594,((1U & (IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))));
        bufp->chgBit(oldp+595,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x2bU])));
        bufp->chgBit(oldp+596,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x2bU] >> 1U))));
        bufp->chgBit(oldp+597,((1U & (~ (IData)((0x1fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xdU)))))));
        bufp->chgBit(oldp+598,((((~ (IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x2bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x2bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+599,((1U & (IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))));
        bufp->chgBit(oldp+600,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x2cU])));
        bufp->chgBit(oldp+601,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x2cU] >> 1U))));
        bufp->chgBit(oldp+602,((1U & (~ (IData)((0xfffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xeU)))))));
        bufp->chgBit(oldp+603,((((~ (IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x2cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x2cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+604,((1U & (IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))));
        bufp->chgBit(oldp+605,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x2dU])));
        bufp->chgBit(oldp+606,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x2dU] >> 1U))));
        bufp->chgBit(oldp+607,((1U & (~ (IData)((0x7ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xfU)))))));
        bufp->chgBit(oldp+608,((((~ (IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x2dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x2dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+609,((1U & (IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))));
        bufp->chgBit(oldp+610,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x2eU])));
        bufp->chgBit(oldp+611,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x2eU] >> 1U))));
        bufp->chgBit(oldp+612,((1U & (~ (IData)((0x3ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x10U)))))));
        bufp->chgBit(oldp+613,((((~ (IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x2eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x2eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+614,((1U & (IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))));
        bufp->chgBit(oldp+615,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x2fU])));
        bufp->chgBit(oldp+616,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x2fU] >> 1U))));
        bufp->chgBit(oldp+617,((1U & (~ (IData)((0x1ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x11U)))))));
        bufp->chgBit(oldp+618,((((~ (IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x2fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x2fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+619,((1U & (IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))));
        bufp->chgBit(oldp+620,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x30U])));
        bufp->chgBit(oldp+621,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x30U] >> 1U))));
        bufp->chgBit(oldp+622,((1U & (~ (IData)((0xffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x12U)))))));
        bufp->chgBit(oldp+623,((((~ (IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x30U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x30U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+624,((1U & (IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))));
        bufp->chgBit(oldp+625,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x31U])));
        bufp->chgBit(oldp+626,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x31U] >> 1U))));
        bufp->chgBit(oldp+627,((1U & (~ (IData)((0x7fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x13U)))))));
        bufp->chgBit(oldp+628,((((~ (IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x31U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x31U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+629,((1U & (IData)((0xffffffffc000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1aU))))));
        bufp->chgBit(oldp+630,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [4U])));
        bufp->chgBit(oldp+631,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [4U] >> 1U))));
        bufp->chgBit(oldp+632,((1U & (~ (IData)((0xffffffffc000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1aU)))))));
        bufp->chgBit(oldp+633,((((~ (IData)((0xffffffffc000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffc000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [4U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [4U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+634,((1U & (IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))));
        bufp->chgBit(oldp+635,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x32U])));
        bufp->chgBit(oldp+636,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x32U] >> 1U))));
        bufp->chgBit(oldp+637,((1U & (~ (IData)((0x3fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x14U)))))));
        bufp->chgBit(oldp+638,((((~ (IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x32U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x32U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+639,((1U & (IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))));
        bufp->chgBit(oldp+640,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x33U])));
        bufp->chgBit(oldp+641,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x33U] >> 1U))));
        bufp->chgBit(oldp+642,((1U & (~ (IData)((0x1fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x15U)))))));
        bufp->chgBit(oldp+643,((((~ (IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x33U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x33U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+644,((1U & (IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))));
        bufp->chgBit(oldp+645,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x34U])));
        bufp->chgBit(oldp+646,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x34U] >> 1U))));
        bufp->chgBit(oldp+647,((1U & (~ (IData)((0xfffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x16U)))))));
        bufp->chgBit(oldp+648,((((~ (IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x34U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x34U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+649,((1U & (IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))));
        bufp->chgBit(oldp+650,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x35U])));
        bufp->chgBit(oldp+651,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x35U] >> 1U))));
        bufp->chgBit(oldp+652,((1U & (~ (IData)((0x7ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x17U)))))));
        bufp->chgBit(oldp+653,((((~ (IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x35U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x35U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+654,((1U & (IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))));
        bufp->chgBit(oldp+655,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x36U])));
        bufp->chgBit(oldp+656,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x36U] >> 1U))));
        bufp->chgBit(oldp+657,((1U & (~ (IData)((0x3ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x18U)))))));
        bufp->chgBit(oldp+658,((((~ (IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x36U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x36U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+659,((1U & (IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))));
        bufp->chgBit(oldp+660,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x37U])));
        bufp->chgBit(oldp+661,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x37U] >> 1U))));
        bufp->chgBit(oldp+662,((1U & (~ (IData)((0x1ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x19U)))))));
        bufp->chgBit(oldp+663,((((~ (IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x37U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x37U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+664,((1U & (IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))));
        bufp->chgBit(oldp+665,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x38U])));
        bufp->chgBit(oldp+666,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x38U] >> 1U))));
        bufp->chgBit(oldp+667,((1U & (~ (IData)((0xffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1aU)))))));
        bufp->chgBit(oldp+668,((((~ (IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x38U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x38U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+669,((1U & (IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))));
        bufp->chgBit(oldp+670,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x39U])));
        bufp->chgBit(oldp+671,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x39U] >> 1U))));
        bufp->chgBit(oldp+672,((1U & (~ (IData)((0x7fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1bU)))))));
        bufp->chgBit(oldp+673,((((~ (IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x39U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x39U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+674,((1U & (IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))));
        bufp->chgBit(oldp+675,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x3aU])));
        bufp->chgBit(oldp+676,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x3aU] >> 1U))));
        bufp->chgBit(oldp+677,((1U & (~ (IData)((0x3fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1cU)))))));
        bufp->chgBit(oldp+678,((((~ (IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x3aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x3aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+679,((1U & (IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))));
        bufp->chgBit(oldp+680,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x3bU])));
        bufp->chgBit(oldp+681,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x3bU] >> 1U))));
        bufp->chgBit(oldp+682,((1U & (~ (IData)((0x1fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1dU)))))));
        bufp->chgBit(oldp+683,((((~ (IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x3bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x3bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+684,((1U & (IData)((0x7fffffffe000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x19U))))));
        bufp->chgBit(oldp+685,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [5U])));
        bufp->chgBit(oldp+686,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [5U] >> 1U))));
        bufp->chgBit(oldp+687,((1U & (~ (IData)((0x7fffffffe000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x19U)))))));
        bufp->chgBit(oldp+688,((((~ (IData)((0x7fffffffe000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffe000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [5U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [5U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+689,((1U & (IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))));
        bufp->chgBit(oldp+690,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x3cU])));
        bufp->chgBit(oldp+691,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x3cU] >> 1U))));
        bufp->chgBit(oldp+692,((1U & (~ (IData)((0xfULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1eU)))))));
        bufp->chgBit(oldp+693,((((~ (IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x3cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x3cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+694,((1U & (IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))));
        bufp->chgBit(oldp+695,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x3dU])));
        bufp->chgBit(oldp+696,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x3dU] >> 1U))));
        bufp->chgBit(oldp+697,((1U & (~ (IData)((7ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1fU)))))));
        bufp->chgBit(oldp+698,((((~ (IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1fU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1fU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x3dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x3dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+699,((1U & (IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))));
        bufp->chgBit(oldp+700,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x3eU])));
        bufp->chgBit(oldp+701,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x3eU] >> 1U))));
        bufp->chgBit(oldp+702,((1U & (~ (IData)((3ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x20U)))))));
        bufp->chgBit(oldp+703,((((~ (IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x20U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x20U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x3eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x3eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+704,((1U & (IData)((1ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))))));
        bufp->chgBit(oldp+705,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [0x3fU])));
        bufp->chgBit(oldp+706,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [0x3fU] >> 1U))));
        bufp->chgBit(oldp+707,((1U & (~ (IData)((1ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x21U)))))));
        bufp->chgBit(oldp+708,((((~ (IData)((1ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x21U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | ((IData)(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x21U) 
                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x))) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [0x3fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [0x3fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+709,((1U & (IData)((0x3ffffffff000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x18U))))));
        bufp->chgBit(oldp+710,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [6U])));
        bufp->chgBit(oldp+711,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [6U] >> 1U))));
        bufp->chgBit(oldp+712,((1U & (~ (IData)((0x3ffffffff000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x18U)))))));
        bufp->chgBit(oldp+713,((((~ (IData)((0x3ffffffff000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffff000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [6U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [6U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+714,((1U & (IData)((0x1ffffffff800000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x17U))))));
        bufp->chgBit(oldp+715,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [7U])));
        bufp->chgBit(oldp+716,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [7U] >> 1U))));
        bufp->chgBit(oldp+717,((1U & (~ (IData)((0x1ffffffff800000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x17U)))))));
        bufp->chgBit(oldp+718,((((~ (IData)((0x1ffffffff800000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffff800000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [7U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [7U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+719,((1U & (IData)((0xffffffffc00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x16U))))));
        bufp->chgBit(oldp+720,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [8U])));
        bufp->chgBit(oldp+721,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [8U] >> 1U))));
        bufp->chgBit(oldp+722,((1U & (~ (IData)((0xffffffffc00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x16U)))))));
        bufp->chgBit(oldp+723,((((~ (IData)((0xffffffffc00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffc00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [8U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [8U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+724,((1U & (IData)((0x7fffffffe00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x15U))))));
        bufp->chgBit(oldp+725,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                [9U])));
        bufp->chgBit(oldp+726,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                      [9U] >> 1U))));
        bufp->chgBit(oldp+727,((1U & (~ (IData)((0x7fffffffe00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x15U)))))));
        bufp->chgBit(oldp+728,((((~ (IData)((0x7fffffffe00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffe00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                        [9U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT__CarrySig
                                         [9U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+729,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x1fU)))));
        bufp->chgBit(oldp+730,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x1eU)))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+731,(vlSymsp->TOP__verilator_top.__PVT__wire_arready));
        bufp->chgBit(oldp+732,(vlSymsp->TOP__verilator_top.__PVT__wire_awready));
        bufp->chgBit(oldp+733,(vlSymsp->TOP__verilator_top.__PVT__wire_wready));
        bufp->chgBit(oldp+734,(vlSymsp->TOP__verilator_top.__PVT__wire_bvalid));
        bufp->chgBit(oldp+735,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_ret_valid));
        bufp->chgBit(oldp+736,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_ret_last));
        bufp->chgBit(oldp+737,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_ret_valid));
        bufp->chgBit(oldp+738,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_ret_last));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        bufp->chgBit(oldp+739,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ds_allowin));
        bufp->chgBit(oldp+740,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__es_allowin));
        bufp->chgBit(oldp+741,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ms_allowin));
        bufp->chgBit(oldp+742,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__fs_to_ds_valid));
        bufp->chgBit(oldp+743,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ds_to_es_valid));
        bufp->chgBit(oldp+744,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__es_to_ms_valid));
        bufp->chgBit(oldp+745,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ms_to_ws_valid));
        bufp->chgBit(oldp+746,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icacop_op_en));
        bufp->chgBit(oldp+747,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcacop_op_en));
        bufp->chgIData(oldp+748,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__fetch_pc),32);
        bufp->chgBit(oldp+749,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__fetch_en));
        bufp->chgBit(oldp+750,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__btb_add_entry));
        bufp->chgBit(oldp+751,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__btb_operate_en));
        bufp->chgBit(oldp+752,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__btb_pre_error));
        bufp->chgBit(oldp+753,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__btb_target_error));
        bufp->chgBit(oldp+754,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__btb_right_orien));
        bufp->chgIData(oldp+755,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__btb_right_target),32);
        bufp->chgBit(oldp+756,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_fetch));
        bufp->chgWData(oldp+757,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__es_to_ms_bus),425);
        bufp->chgQData(oldp+771,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush)) 
                                   << 0x20U) | (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush_target)))),33);
        bufp->chgBit(oldp+773,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_valid));
        bufp->chgCData(oldp+774,((0xffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__fetch_pc 
                                           >> 4U))),8);
        bufp->chgCData(oldp+775,((0xfU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__fetch_pc)),4);
        bufp->chgBit(oldp+776,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addr_ok));
        bufp->chgBit(oldp+777,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_data_ok));
        bufp->chgIData(oldp+778,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_rdata),32);
        bufp->chgBit(oldp+779,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_valid));
        bufp->chgBit(oldp+780,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_addr_ok));
        bufp->chgBit(oldp+781,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__axi_bridge__DOT__rd_requst_can_receive));
        bufp->chgBit(oldp+782,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__preld_en));
        bufp->chgIData(oldp+783,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__fetch_pc 
                                  >> 0xdU)),19);
        bufp->chgBit(oldp+784,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__fetch_pc 
                                      >> 0xcU))));
        bufp->chgCData(oldp+785,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][0U]),8);
        bufp->chgCData(oldp+786,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][1U]),8);
        bufp->chgCData(oldp+787,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][2U]),8);
        bufp->chgCData(oldp+788,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][3U]),8);
        bufp->chgCData(oldp+789,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][0U]),8);
        bufp->chgCData(oldp+790,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][1U]),8);
        bufp->chgCData(oldp+791,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][2U]),8);
        bufp->chgCData(oldp+792,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][3U]),8);
        bufp->chgIData(oldp+793,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][0U]),32);
        bufp->chgIData(oldp+794,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][1U]),32);
        bufp->chgIData(oldp+795,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][2U]),32);
        bufp->chgIData(oldp+796,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][3U]),32);
        bufp->chgIData(oldp+797,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][0U]),32);
        bufp->chgIData(oldp+798,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][1U]),32);
        bufp->chgIData(oldp+799,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][2U]),32);
        bufp->chgIData(oldp+800,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][3U]),32);
        bufp->chgCData(oldp+801,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][0U]),4);
        bufp->chgCData(oldp+802,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][1U]),4);
        bufp->chgCData(oldp+803,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][2U]),4);
        bufp->chgCData(oldp+804,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][3U]),4);
        bufp->chgCData(oldp+805,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][0U]),4);
        bufp->chgCData(oldp+806,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][1U]),4);
        bufp->chgCData(oldp+807,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][2U]),4);
        bufp->chgCData(oldp+808,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][3U]),4);
        bufp->chgCData(oldp+809,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_tagv_addra[0]),8);
        bufp->chgCData(oldp+810,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_tagv_addra[1]),8);
        bufp->chgBit(oldp+811,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_tagv_wea[0]));
        bufp->chgBit(oldp+812,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_tagv_wea[1]));
        bufp->chgBit(oldp+813,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__main_idle2lookup));
        bufp->chgBit(oldp+814,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__main_lookup2lookup));
        bufp->chgCData(oldp+815,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_wr_en),2);
        bufp->chgIData(oldp+816,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__refill_data),32);
        bufp->chgBit(oldp+817,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__req_or_inst_valid));
        bufp->chgCData(oldp+818,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][0U]),8);
        bufp->chgIData(oldp+819,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][0U]),32);
        bufp->chgCData(oldp+820,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][0U]),4);
        bufp->chgCData(oldp+821,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][1U]),8);
        bufp->chgIData(oldp+822,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][1U]),32);
        bufp->chgCData(oldp+823,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][1U]),4);
        bufp->chgCData(oldp+824,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][2U]),8);
        bufp->chgIData(oldp+825,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][2U]),32);
        bufp->chgCData(oldp+826,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][2U]),4);
        bufp->chgCData(oldp+827,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [0U][3U]),8);
        bufp->chgIData(oldp+828,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [0U][3U]),32);
        bufp->chgCData(oldp+829,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [0U][3U]),4);
        bufp->chgCData(oldp+830,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][0U]),8);
        bufp->chgIData(oldp+831,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][0U]),32);
        bufp->chgCData(oldp+832,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][0U]),4);
        bufp->chgCData(oldp+833,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][1U]),8);
        bufp->chgIData(oldp+834,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][1U]),32);
        bufp->chgCData(oldp+835,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][1U]),4);
        bufp->chgCData(oldp+836,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][2U]),8);
        bufp->chgIData(oldp+837,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][2U]),32);
        bufp->chgCData(oldp+838,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][2U]),4);
        bufp->chgCData(oldp+839,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_addra
                                 [1U][3U]),8);
        bufp->chgIData(oldp+840,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_dina
                                 [1U][3U]),32);
        bufp->chgCData(oldp+841,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_bank_wea
                                 [1U][3U]),4);
        bufp->chgCData(oldp+842,(vlSymsp->TOP__verilator_top.cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__addra),8);
        bufp->chgBit(oldp+843,(vlSymsp->TOP__verilator_top.cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__wea));
        bufp->chgBit(oldp+844,(vlSymsp->TOP__verilator_top.cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__1__KET____DOT__u__wea));
        bufp->chgBit(oldp+845,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exe_stage__DOT__es_ready_go));
        bufp->chgBit(oldp+846,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en));
        bufp->chgCData(oldp+847,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][0U]),8);
        bufp->chgCData(oldp+848,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][1U]),8);
        bufp->chgCData(oldp+849,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][2U]),8);
        bufp->chgCData(oldp+850,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][3U]),8);
        bufp->chgCData(oldp+851,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][0U]),8);
        bufp->chgCData(oldp+852,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][1U]),8);
        bufp->chgCData(oldp+853,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][2U]),8);
        bufp->chgCData(oldp+854,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][3U]),8);
        bufp->chgIData(oldp+855,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][0U]),32);
        bufp->chgIData(oldp+856,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][1U]),32);
        bufp->chgIData(oldp+857,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][2U]),32);
        bufp->chgIData(oldp+858,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][3U]),32);
        bufp->chgIData(oldp+859,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][0U]),32);
        bufp->chgIData(oldp+860,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][1U]),32);
        bufp->chgIData(oldp+861,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][2U]),32);
        bufp->chgIData(oldp+862,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][3U]),32);
        bufp->chgCData(oldp+863,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][0U]),4);
        bufp->chgCData(oldp+864,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][1U]),4);
        bufp->chgCData(oldp+865,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][2U]),4);
        bufp->chgCData(oldp+866,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][3U]),4);
        bufp->chgCData(oldp+867,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][0U]),4);
        bufp->chgCData(oldp+868,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][1U]),4);
        bufp->chgCData(oldp+869,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][2U]),4);
        bufp->chgCData(oldp+870,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][3U]),4);
        bufp->chgCData(oldp+871,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_tagv_addra[0]),8);
        bufp->chgCData(oldp+872,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_tagv_addra[1]),8);
        bufp->chgBit(oldp+873,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_tagv_wea[0]));
        bufp->chgBit(oldp+874,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_tagv_wea[1]));
        bufp->chgCData(oldp+875,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_wr_en),2);
        bufp->chgCData(oldp+876,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__real_offset),4);
        bufp->chgCData(oldp+877,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__real_index),8);
        bufp->chgBit(oldp+878,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__req_or_inst_valid));
        bufp->chgCData(oldp+879,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][0U]),8);
        bufp->chgIData(oldp+880,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][0U]),32);
        bufp->chgCData(oldp+881,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][0U]),4);
        bufp->chgCData(oldp+882,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][1U]),8);
        bufp->chgIData(oldp+883,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][1U]),32);
        bufp->chgCData(oldp+884,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][1U]),4);
        bufp->chgCData(oldp+885,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][2U]),8);
        bufp->chgIData(oldp+886,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][2U]),32);
        bufp->chgCData(oldp+887,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][2U]),4);
        bufp->chgCData(oldp+888,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [0U][3U]),8);
        bufp->chgIData(oldp+889,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [0U][3U]),32);
        bufp->chgCData(oldp+890,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [0U][3U]),4);
        bufp->chgCData(oldp+891,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][0U]),8);
        bufp->chgIData(oldp+892,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][0U]),32);
        bufp->chgCData(oldp+893,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][0U]),4);
        bufp->chgCData(oldp+894,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][1U]),8);
        bufp->chgIData(oldp+895,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][1U]),32);
        bufp->chgCData(oldp+896,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][1U]),4);
        bufp->chgCData(oldp+897,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][2U]),8);
        bufp->chgIData(oldp+898,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][2U]),32);
        bufp->chgCData(oldp+899,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][2U]),4);
        bufp->chgCData(oldp+900,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_addra
                                 [1U][3U]),8);
        bufp->chgIData(oldp+901,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_dina
                                 [1U][3U]),32);
        bufp->chgCData(oldp+902,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__way_bank_wea
                                 [1U][3U]),4);
        bufp->chgCData(oldp+903,(vlSymsp->TOP__verilator_top.cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__addra),8);
        bufp->chgBit(oldp+904,(vlSymsp->TOP__verilator_top.cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__wea));
        bufp->chgBit(oldp+905,(vlSymsp->TOP__verilator_top.cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__1__KET____DOT__u__wea));
        bufp->chgBit(oldp+906,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__ds_ready_go));
        bufp->chgBit(oldp+907,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush));
        bufp->chgIData(oldp+908,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush_target),32);
        bufp->chgIData(oldp+909,(vlSymsp->TOP__verilator_top.cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U]),32);
        bufp->chgIData(oldp+910,(vlSymsp->TOP__verilator_top.cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[1U]),32);
        bufp->chgBit(oldp+911,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__rj_eq_rd));
        bufp->chgBit(oldp+912,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_sign));
        bufp->chgBit(oldp+913,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign));
        bufp->chgIData(oldp+914,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__ms_forward_data),32);
        bufp->chgBit(oldp+915,((1U & vlSymsp->TOP__verilator_top.cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[2U])));
        bufp->chgBit(oldp+916,((1U & vlSymsp->TOP__verilator_top.cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[2U])));
        bufp->chgIData(oldp+917,(vlSymsp->TOP__verilator_top.cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U]),32);
        bufp->chgIData(oldp+918,(vlSymsp->TOP__verilator_top.cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U]),32);
        bufp->chgBit(oldp+919,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__if_stage__DOT__fs_ready_go));
        bufp->chgBit(oldp+920,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__if_stage__DOT__fs_allowin));
        bufp->chgBit(oldp+921,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__if_stage__DOT__to_fs_valid));
        bufp->chgBit(oldp+922,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__if_stage__DOT__pfs_ready_go));
        bufp->chgBit(oldp+923,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__if_stage__DOT__pfs_excp_adef));
        bufp->chgBit(oldp+924,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__if_stage__DOT__flush_inst_delay));
        bufp->chgBit(oldp+925,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__if_stage__DOT__flush_inst_go_dirt));
        bufp->chgBit(oldp+926,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_stage__DOT__ms_ready_go));
        bufp->chgIData(oldp+927,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_stage__DOT__ms_rdata),32);
        bufp->chgCData(oldp+928,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_stage__DOT__mem_byteLoaded),8);
        bufp->chgSData(oldp+929,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_stage__DOT__mem_halfLoaded),16);
    }
    bufp->chgBit(oldp+930,(vlSelf->rst));
    bufp->chgBit(oldp+931,(vlSelf->clk));
    bufp->chgBit(oldp+932,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->chgIData(oldp+933,(vlSymsp->TOP__verilator_top.debug_wb_pc),32);
    bufp->chgCData(oldp+934,(vlSymsp->TOP__verilator_top.debug_wb_rf_we),4);
    bufp->chgCData(oldp+935,(vlSymsp->TOP__verilator_top.debug_wb_rf_wnum),5);
    bufp->chgIData(oldp+936,(vlSymsp->TOP__verilator_top.debug_wb_rf_wdata),32);
    bufp->chgIData(oldp+937,(vlSymsp->TOP__verilator_top.debug_wb_inst),32);
    bufp->chgBit(oldp+938,(vlSymsp->TOP__verilator_top.debug_wb_is_csr_wr_o));
    bufp->chgIData(oldp+939,(vlSymsp->TOP__verilator_top.csr_crmd_diff),32);
    bufp->chgIData(oldp+940,(vlSymsp->TOP__verilator_top.csr_prmd_diff),32);
    bufp->chgIData(oldp+941,(vlSymsp->TOP__verilator_top.csr_ectl_diff),32);
    bufp->chgIData(oldp+942,(vlSymsp->TOP__verilator_top.csr_estat_diff),32);
    bufp->chgIData(oldp+943,(vlSymsp->TOP__verilator_top.csr_era_diff),32);
    bufp->chgIData(oldp+944,(vlSymsp->TOP__verilator_top.csr_badv_diff),32);
    bufp->chgIData(oldp+945,(vlSymsp->TOP__verilator_top.csr_eentry_diff),32);
    bufp->chgIData(oldp+946,(vlSymsp->TOP__verilator_top.csr_tlbidx_diff),32);
    bufp->chgIData(oldp+947,(vlSymsp->TOP__verilator_top.csr_tlbehi_diff),32);
    bufp->chgIData(oldp+948,(vlSymsp->TOP__verilator_top.csr_tlbelo0_diff),32);
    bufp->chgIData(oldp+949,(vlSymsp->TOP__verilator_top.csr_tlbelo1_diff),32);
    bufp->chgIData(oldp+950,(vlSymsp->TOP__verilator_top.csr_asid_diff),32);
    bufp->chgIData(oldp+951,(vlSymsp->TOP__verilator_top.csr_save0_diff),32);
    bufp->chgIData(oldp+952,(vlSymsp->TOP__verilator_top.csr_save1_diff),32);
    bufp->chgIData(oldp+953,(vlSymsp->TOP__verilator_top.csr_save2_diff),32);
    bufp->chgIData(oldp+954,(vlSymsp->TOP__verilator_top.csr_save3_diff),32);
    bufp->chgIData(oldp+955,(vlSymsp->TOP__verilator_top.csr_tid_diff),32);
    bufp->chgIData(oldp+956,(vlSymsp->TOP__verilator_top.csr_tcfg_diff),32);
    bufp->chgIData(oldp+957,(vlSymsp->TOP__verilator_top.csr_tval_diff),32);
    bufp->chgIData(oldp+958,(vlSymsp->TOP__verilator_top.csr_ticlr_diff),32);
    bufp->chgIData(oldp+959,(vlSymsp->TOP__verilator_top.csr_llbctl_diff),32);
    bufp->chgIData(oldp+960,(vlSymsp->TOP__verilator_top.csr_tlbrentry_diff),32);
    bufp->chgIData(oldp+961,(vlSymsp->TOP__verilator_top.csr_dmw0_diff),32);
    bufp->chgIData(oldp+962,(vlSymsp->TOP__verilator_top.csr_dmw1_diff),32);
    bufp->chgIData(oldp+963,(vlSymsp->TOP__verilator_top.csr_pgdl_diff),32);
    bufp->chgIData(oldp+964,(vlSymsp->TOP__verilator_top.csr_pgdh_diff),32);
    bufp->chgIData(oldp+965,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rd_csr_data),32);
    bufp->chgBit(oldp+966,(((~ (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_rd_req)) 
                            & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__axi_bridge__DOT__rd_requst_can_receive))));
    bufp->chgBit(oldp+967,(((~ (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__dcache__DOT____VdfgTmp_h63343402__0)) 
                            & (((2U == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                & ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__cache_hit) 
                                   | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_op) 
                                      | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__cancel_req)))) 
                               | ((0x10U == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                  & ((~ (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_op)) 
                                     & ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_ret_valid) 
                                        & (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num) 
                                            == (3U 
                                                & ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                                                   >> 2U))) 
                                           | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_uncache_en)))))))));
    __Vtemp_h8178c22d__0[0U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][0U];
    __Vtemp_h8178c22d__0[1U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][1U];
    __Vtemp_h8178c22d__0[2U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][2U];
    __Vtemp_h8178c22d__0[3U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][3U];
    __Vtemp_h8178c37b__0[0U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][0U];
    __Vtemp_h8178c37b__0[1U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][1U];
    __Vtemp_h8178c37b__0[2U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][2U];
    __Vtemp_h8178c37b__0[3U] = vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][3U];
    bufp->chgIData(oldp+968,((((- (IData)((2U == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__main_state)))) 
                               & (((- (IData)((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__dcache__DOT____VdfgTmp_h064d00c1__0))) 
                                   & __Vtemp_h8178c22d__0[
                                   (3U & ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                                          >> 2U))]) 
                                  | ((- (IData)((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__dcache__DOT____VdfgTmp_hb6042862__0))) 
                                     & __Vtemp_h8178c37b__0[
                                     (3U & ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                                            >> 2U))]))) 
                              | ((- (IData)((0x10U 
                                             == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__main_state)))) 
                                 & vlSymsp->TOP__verilator_top.__PVT__wire_rdata))),32);
    bufp->chgBit(oldp+969,(((0x10U == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__main_state)) 
                            & ((~ ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__request_buffer_icacop) 
                                   | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__request_buffer_uncache_en))) 
                               & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_ret_last)))));
    bufp->chgBit(oldp+970,(((0x10U == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__main_state)) 
                            & ((~ ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_uncache_en) 
                                   | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__dcache__DOT____VdfgTmp_h63343402__0))) 
                               & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__data_ret_last)))));
    bufp->chgIData(oldp+971,(((((8U & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                                 ? (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata 
                                    >> 0x18U) : (vlSymsp->TOP__verilator_top.__PVT__wire_rdata 
                                                 >> 0x18U)) 
                               << 0x18U) | ((0xff0000U 
                                             & (((4U 
                                                  & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                                                  ? 
                                                 (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata 
                                                  >> 0x10U)
                                                  : 
                                                 (vlSymsp->TOP__verilator_top.__PVT__wire_rdata 
                                                  >> 0x10U)) 
                                                << 0x10U)) 
                                            | ((0xff00U 
                                                & (((2U 
                                                     & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                                                     ? 
                                                    (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata 
                                                     >> 8U)
                                                     : 
                                                    (vlSymsp->TOP__verilator_top.__PVT__wire_rdata 
                                                     >> 8U)) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & ((1U 
                                                      & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                                                      ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata
                                                      : vlSymsp->TOP__verilator_top.__PVT__wire_rdata)))))),32);
    bufp->chgBit(oldp+972,(((1U != (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icache__DOT__main_state)) 
                            & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__icacop_op_en))));
    bufp->chgIData(oldp+973,(((1U & (IData)(((((- (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))) 
                                               >> 0x20U) 
                                              & (1ULL 
                                                 | ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ds_timer_64)) 
                                                    >> 0x20U))) 
                                             | ((((- (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))) 
                                                  >> 0x20U) 
                                                 & (1ULL 
                                                    | ((QData)((IData)(
                                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ds_timer_64 
                                                                        >> 0x20U))) 
                                                       >> 0x20U))) 
                                                | (((- (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))) 
                                                    >> 0x20U) 
                                                   & (1ULL 
                                                      | ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_csr__DOT__csr_tid)) 
                                                         >> 0x20U)))))))
                               ? (((IData)((0x1ffffffffULL 
                                            & (- (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))))) 
                                   & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ds_timer_64)) 
                                  | (((IData)((0x1ffffffffULL 
                                               & (- (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))))) 
                                      & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ds_timer_64 
                                                 >> 0x20U))) 
                                     | ((IData)((0x1ffffffffULL 
                                                 & (- (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))))) 
                                        & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_csr__DOT__csr_tid)))
                               : ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)
                                   ? (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_csr__DOT__llbit)
                                   : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rd_csr_data))),32);
}

void Vverilator_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_cleanup\n"); );
    // Init
    Vverilator_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_top___024root*>(voidSelf);
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}

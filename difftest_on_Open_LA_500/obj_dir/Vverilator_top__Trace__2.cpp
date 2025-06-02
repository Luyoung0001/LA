// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vverilator_top__Syms.h"


void Vverilator_top___024root__trace_chg_sub_2(Vverilator_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_chg_sub_2\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 6074);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgBit(oldp+0,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x22U)))));
        bufp->chgBit(oldp+1,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                              [0x22U])));
        bufp->chgBit(oldp+2,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                    [0x22U] >> 1U))));
        bufp->chgBit(oldp+3,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x22U))))));
        bufp->chgBit(oldp+4,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                           >> 0x22U))) 
                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                              | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                           >> 0x22U)) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                 | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x22U] >> 1U) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+5,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x23U)))));
        bufp->chgBit(oldp+6,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                              [0x23U])));
        bufp->chgBit(oldp+7,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                    [0x23U] >> 1U))));
        bufp->chgBit(oldp+8,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x23U))))));
        bufp->chgBit(oldp+9,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                           >> 0x23U))) 
                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                              | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                           >> 0x23U)) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                 | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x23U] >> 1U) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+10,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x24U)))));
        bufp->chgBit(oldp+11,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x24U])));
        bufp->chgBit(oldp+12,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x24U] >> 1U))));
        bufp->chgBit(oldp+13,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x24U))))));
        bufp->chgBit(oldp+14,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x24U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x24U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x24U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+15,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x25U)))));
        bufp->chgBit(oldp+16,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x25U])));
        bufp->chgBit(oldp+17,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x25U] >> 1U))));
        bufp->chgBit(oldp+18,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x25U))))));
        bufp->chgBit(oldp+19,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x25U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x25U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x25U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+20,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x26U)))));
        bufp->chgBit(oldp+21,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x26U])));
        bufp->chgBit(oldp+22,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x26U] >> 1U))));
        bufp->chgBit(oldp+23,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x26U))))));
        bufp->chgBit(oldp+24,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x26U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x26U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x26U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+25,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x27U)))));
        bufp->chgBit(oldp+26,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x27U])));
        bufp->chgBit(oldp+27,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x27U] >> 1U))));
        bufp->chgBit(oldp+28,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x27U))))));
        bufp->chgBit(oldp+29,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x27U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x27U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x27U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+30,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 3U)))));
        bufp->chgBit(oldp+31,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [3U])));
        bufp->chgBit(oldp+32,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [3U] >> 1U))));
        bufp->chgBit(oldp+33,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U))))));
        bufp->chgBit(oldp+34,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 3U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 3U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [3U] >> 1U) & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+35,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x28U)))));
        bufp->chgBit(oldp+36,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x28U])));
        bufp->chgBit(oldp+37,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x28U] >> 1U))));
        bufp->chgBit(oldp+38,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x28U))))));
        bufp->chgBit(oldp+39,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x28U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x28U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x28U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+40,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x29U)))));
        bufp->chgBit(oldp+41,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x29U])));
        bufp->chgBit(oldp+42,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x29U] >> 1U))));
        bufp->chgBit(oldp+43,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x29U))))));
        bufp->chgBit(oldp+44,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x29U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x29U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x29U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+45,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x2aU)))));
        bufp->chgBit(oldp+46,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x2aU])));
        bufp->chgBit(oldp+47,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x2aU] >> 1U))));
        bufp->chgBit(oldp+48,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2aU))))));
        bufp->chgBit(oldp+49,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2aU))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2aU)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x2aU] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+50,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x2bU)))));
        bufp->chgBit(oldp+51,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x2bU])));
        bufp->chgBit(oldp+52,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x2bU] >> 1U))));
        bufp->chgBit(oldp+53,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2bU))))));
        bufp->chgBit(oldp+54,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2bU))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2bU)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x2bU] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+55,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x2cU)))));
        bufp->chgBit(oldp+56,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x2cU])));
        bufp->chgBit(oldp+57,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x2cU] >> 1U))));
        bufp->chgBit(oldp+58,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2cU))))));
        bufp->chgBit(oldp+59,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2cU))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2cU)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x2cU] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+60,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x2dU)))));
        bufp->chgBit(oldp+61,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x2dU])));
        bufp->chgBit(oldp+62,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x2dU] >> 1U))));
        bufp->chgBit(oldp+63,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2dU))))));
        bufp->chgBit(oldp+64,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2dU))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2dU)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x2dU] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+65,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x2eU)))));
        bufp->chgBit(oldp+66,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x2eU])));
        bufp->chgBit(oldp+67,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x2eU] >> 1U))));
        bufp->chgBit(oldp+68,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2eU))))));
        bufp->chgBit(oldp+69,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2eU))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2eU)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x2eU] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+70,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x2fU)))));
        bufp->chgBit(oldp+71,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x2fU])));
        bufp->chgBit(oldp+72,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x2fU] >> 1U))));
        bufp->chgBit(oldp+73,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2fU))))));
        bufp->chgBit(oldp+74,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2fU))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x2fU)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x2fU] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+75,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x30U)))));
        bufp->chgBit(oldp+76,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x30U])));
        bufp->chgBit(oldp+77,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x30U] >> 1U))));
        bufp->chgBit(oldp+78,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x30U))))));
        bufp->chgBit(oldp+79,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x30U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x30U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x30U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+80,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x31U)))));
        bufp->chgBit(oldp+81,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x31U])));
        bufp->chgBit(oldp+82,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x31U] >> 1U))));
        bufp->chgBit(oldp+83,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x31U))))));
        bufp->chgBit(oldp+84,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x31U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x31U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x31U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+85,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 4U)))));
        bufp->chgBit(oldp+86,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [4U])));
        bufp->chgBit(oldp+87,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [4U] >> 1U))));
        bufp->chgBit(oldp+88,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U))))));
        bufp->chgBit(oldp+89,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 4U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 4U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [4U] >> 1U) & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+90,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x32U)))));
        bufp->chgBit(oldp+91,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x32U])));
        bufp->chgBit(oldp+92,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x32U] >> 1U))));
        bufp->chgBit(oldp+93,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x32U))))));
        bufp->chgBit(oldp+94,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x32U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x32U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x32U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+95,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x33U)))));
        bufp->chgBit(oldp+96,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                               [0x33U])));
        bufp->chgBit(oldp+97,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                     [0x33U] >> 1U))));
        bufp->chgBit(oldp+98,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x33U))))));
        bufp->chgBit(oldp+99,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x33U))) 
                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                               | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                            >> 0x33U)) 
                                   & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                  | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x33U] >> 1U) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+100,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x34U)))));
        bufp->chgBit(oldp+101,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x34U])));
        bufp->chgBit(oldp+102,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x34U] >> 1U))));
        bufp->chgBit(oldp+103,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x34U))))));
        bufp->chgBit(oldp+104,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x34U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x34U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x34U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+105,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x35U)))));
        bufp->chgBit(oldp+106,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x35U])));
        bufp->chgBit(oldp+107,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x35U] >> 1U))));
        bufp->chgBit(oldp+108,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x35U))))));
        bufp->chgBit(oldp+109,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x35U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x35U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x35U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+110,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x36U)))));
        bufp->chgBit(oldp+111,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x36U])));
        bufp->chgBit(oldp+112,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x36U] >> 1U))));
        bufp->chgBit(oldp+113,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x36U))))));
        bufp->chgBit(oldp+114,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x36U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x36U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x36U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+115,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x37U)))));
        bufp->chgBit(oldp+116,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x37U])));
        bufp->chgBit(oldp+117,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x37U] >> 1U))));
        bufp->chgBit(oldp+118,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x37U))))));
        bufp->chgBit(oldp+119,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x37U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x37U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x37U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+120,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x38U)))));
        bufp->chgBit(oldp+121,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x38U])));
        bufp->chgBit(oldp+122,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x38U] >> 1U))));
        bufp->chgBit(oldp+123,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x38U))))));
        bufp->chgBit(oldp+124,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x38U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x38U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x38U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+125,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x39U)))));
        bufp->chgBit(oldp+126,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x39U])));
        bufp->chgBit(oldp+127,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x39U] >> 1U))));
        bufp->chgBit(oldp+128,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x39U))))));
        bufp->chgBit(oldp+129,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x39U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x39U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x39U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+130,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3aU)))));
        bufp->chgBit(oldp+131,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x3aU])));
        bufp->chgBit(oldp+132,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x3aU] >> 1U))));
        bufp->chgBit(oldp+133,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3aU))))));
        bufp->chgBit(oldp+134,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3aU))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3aU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x3aU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+135,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3bU)))));
        bufp->chgBit(oldp+136,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x3bU])));
        bufp->chgBit(oldp+137,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x3bU] >> 1U))));
        bufp->chgBit(oldp+138,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3bU))))));
        bufp->chgBit(oldp+139,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3bU))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3bU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x3bU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+140,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 5U)))));
        bufp->chgBit(oldp+141,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [5U])));
        bufp->chgBit(oldp+142,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [5U] >> 1U))));
        bufp->chgBit(oldp+143,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))));
        bufp->chgBit(oldp+144,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 5U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 5U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [5U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+145,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3cU)))));
        bufp->chgBit(oldp+146,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x3cU])));
        bufp->chgBit(oldp+147,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x3cU] >> 1U))));
        bufp->chgBit(oldp+148,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3cU))))));
        bufp->chgBit(oldp+149,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3cU))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3cU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x3cU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+150,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3dU)))));
        bufp->chgBit(oldp+151,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x3dU])));
        bufp->chgBit(oldp+152,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x3dU] >> 1U))));
        bufp->chgBit(oldp+153,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3dU))))));
        bufp->chgBit(oldp+154,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3dU))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3dU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x3dU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+155,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3eU)))));
        bufp->chgBit(oldp+156,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x3eU])));
        bufp->chgBit(oldp+157,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x3eU] >> 1U))));
        bufp->chgBit(oldp+158,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3eU))))));
        bufp->chgBit(oldp+159,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3eU))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3eU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x3eU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+160,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3fU)))));
        bufp->chgBit(oldp+161,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [0x3fU])));
        bufp->chgBit(oldp+162,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [0x3fU] >> 1U))));
        bufp->chgBit(oldp+163,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3fU))))));
        bufp->chgBit(oldp+164,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3fU))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3fU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [0x3fU] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+165,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 6U)))));
        bufp->chgBit(oldp+166,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [6U])));
        bufp->chgBit(oldp+167,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [6U] >> 1U))));
        bufp->chgBit(oldp+168,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))));
        bufp->chgBit(oldp+169,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 6U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 6U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [6U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+170,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 7U)))));
        bufp->chgBit(oldp+171,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [7U])));
        bufp->chgBit(oldp+172,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [7U] >> 1U))));
        bufp->chgBit(oldp+173,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))));
        bufp->chgBit(oldp+174,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 7U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 7U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [7U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+175,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 8U)))));
        bufp->chgBit(oldp+176,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [8U])));
        bufp->chgBit(oldp+177,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [8U] >> 1U))));
        bufp->chgBit(oldp+178,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))));
        bufp->chgBit(oldp+179,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 8U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 8U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [8U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+180,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 9U)))));
        bufp->chgBit(oldp+181,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                [9U])));
        bufp->chgBit(oldp+182,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                      [9U] >> 1U))));
        bufp->chgBit(oldp+183,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))));
        bufp->chgBit(oldp+184,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 9U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 9U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_he6224cd4__0)) 
                                   | ((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.__PVT__CarrySig
                                       [9U] >> 1U) 
                                      & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__fir.uu__DOT____VdfgTmp_hf6cd5b06__0))))));
        bufp->chgBit(oldp+185,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 1U)))));
        bufp->chgBit(oldp+186,((1U & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))));
        bufp->chgCData(oldp+187,(vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__las__y),3);
        bufp->chgQData(oldp+188,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                  << 0x20U)),64);
        bufp->chgQData(oldp+190,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__OutX),64);
        bufp->chgBit(oldp+192,(((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x) 
                                | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx))));
        bufp->chgBit(oldp+193,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx));
        bufp->chgBit(oldp+194,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x));
        bufp->chgBit(oldp+195,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x));
        bufp->chgBit(oldp+196,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 0x20U)))));
        bufp->chgBit(oldp+197,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x20U))))));
        bufp->chgBit(oldp+198,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x20U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x20U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)))));
        bufp->chgBit(oldp+199,((1U & (IData)((0x3fffffffc00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x16U))))));
        bufp->chgBit(oldp+200,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0xaU])));
        bufp->chgBit(oldp+201,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0xaU] >> 1U))));
        bufp->chgBit(oldp+202,((1U & (~ (IData)((0x3fffffffc00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x16U)))))));
        bufp->chgBit(oldp+203,((((~ (IData)((0x3fffffffc00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffc00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0xaU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0xaU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+204,((1U & (IData)((0x1fffffffe00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x15U))))));
        bufp->chgBit(oldp+205,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0xbU])));
        bufp->chgBit(oldp+206,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0xbU] >> 1U))));
        bufp->chgBit(oldp+207,((1U & (~ (IData)((0x1fffffffe00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x15U)))))));
        bufp->chgBit(oldp+208,((((~ (IData)((0x1fffffffe00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffe00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0xbU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0xbU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+209,((1U & (IData)((0xffffffff00000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x14U))))));
        bufp->chgBit(oldp+210,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0xcU])));
        bufp->chgBit(oldp+211,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0xcU] >> 1U))));
        bufp->chgBit(oldp+212,((1U & (~ (IData)((0xffffffff00000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x14U)))))));
        bufp->chgBit(oldp+213,((((~ (IData)((0xffffffff00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffff00000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0xcU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0xcU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+214,((1U & (IData)((0x7fffffff80000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x13U))))));
        bufp->chgBit(oldp+215,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0xdU])));
        bufp->chgBit(oldp+216,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0xdU] >> 1U))));
        bufp->chgBit(oldp+217,((1U & (~ (IData)((0x7fffffff80000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x13U)))))));
        bufp->chgBit(oldp+218,((((~ (IData)((0x7fffffff80000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff80000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0xdU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0xdU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+219,((1U & (IData)((0x3fffffffc0000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x12U))))));
        bufp->chgBit(oldp+220,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0xeU])));
        bufp->chgBit(oldp+221,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0xeU] >> 1U))));
        bufp->chgBit(oldp+222,((1U & (~ (IData)((0x3fffffffc0000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x12U)))))));
        bufp->chgBit(oldp+223,((((~ (IData)((0x3fffffffc0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x12U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffc0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x12U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0xeU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0xeU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+224,((1U & (IData)((0x1fffffffe0000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x11U))))));
        bufp->chgBit(oldp+225,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0xfU])));
        bufp->chgBit(oldp+226,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0xfU] >> 1U))));
        bufp->chgBit(oldp+227,((1U & (~ (IData)((0x1fffffffe0000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x11U)))))));
        bufp->chgBit(oldp+228,((((~ (IData)((0x1fffffffe0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x11U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffe0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x11U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0xfU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0xfU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+229,((1U & (IData)((0xffffffff0000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x10U))))));
        bufp->chgBit(oldp+230,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x10U])));
        bufp->chgBit(oldp+231,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x10U] >> 1U))));
        bufp->chgBit(oldp+232,((1U & (~ (IData)((0xffffffff0000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x10U)))))));
        bufp->chgBit(oldp+233,((((~ (IData)((0xffffffff0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x10U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffff0000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x10U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x10U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x10U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+234,((1U & (IData)((0x7fffffff8000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xfU))))));
        bufp->chgBit(oldp+235,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x11U])));
        bufp->chgBit(oldp+236,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x11U] >> 1U))));
        bufp->chgBit(oldp+237,((1U & (~ (IData)((0x7fffffff8000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xfU)))))));
        bufp->chgBit(oldp+238,((((~ (IData)((0x7fffffff8000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff8000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x11U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x11U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+239,((1U & (IData)((0x3fffffffc000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xeU))))));
        bufp->chgBit(oldp+240,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x12U])));
        bufp->chgBit(oldp+241,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x12U] >> 1U))));
        bufp->chgBit(oldp+242,((1U & (~ (IData)((0x3fffffffc000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xeU)))))));
        bufp->chgBit(oldp+243,((((~ (IData)((0x3fffffffc000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffc000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x12U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x12U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+244,((1U & (IData)((0x1fffffffe000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))));
        bufp->chgBit(oldp+245,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x13U])));
        bufp->chgBit(oldp+246,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x13U] >> 1U))));
        bufp->chgBit(oldp+247,((1U & (~ (IData)((0x1fffffffe000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xdU)))))));
        bufp->chgBit(oldp+248,((((~ (IData)((0x1fffffffe000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffe000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x13U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x13U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+249,((1U & (IData)((0x7fffffff80000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1fU))))));
        bufp->chgBit(oldp+250,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [1U])));
        bufp->chgBit(oldp+251,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [1U] >> 1U))));
        bufp->chgBit(oldp+252,((1U & (~ (IData)((0x7fffffff80000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1fU)))))));
        bufp->chgBit(oldp+253,((((~ (IData)((0x7fffffff80000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1fU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff80000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1fU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [1U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [1U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+254,((1U & (IData)((0xffffffff000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xcU))))));
        bufp->chgBit(oldp+255,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x14U])));
        bufp->chgBit(oldp+256,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x14U] >> 1U))));
        bufp->chgBit(oldp+257,((1U & (~ (IData)((0xffffffff000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xcU)))))));
        bufp->chgBit(oldp+258,((((~ (IData)((0xffffffff000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffff000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x14U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x14U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+259,((1U & (IData)((0x7fffffff800ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xbU))))));
        bufp->chgBit(oldp+260,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x15U])));
        bufp->chgBit(oldp+261,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x15U] >> 1U))));
        bufp->chgBit(oldp+262,((1U & (~ (IData)((0x7fffffff800ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xbU)))))));
        bufp->chgBit(oldp+263,((((~ (IData)((0x7fffffff800ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff800ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x15U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x15U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+264,((1U & (IData)((0x3fffffffc00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xaU))))));
        bufp->chgBit(oldp+265,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x16U])));
        bufp->chgBit(oldp+266,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x16U] >> 1U))));
        bufp->chgBit(oldp+267,((1U & (~ (IData)((0x3fffffffc00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0xaU)))))));
        bufp->chgBit(oldp+268,((((~ (IData)((0x3fffffffc00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffc00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x16U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x16U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+269,((1U & (IData)((0x1fffffffe00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 9U))))));
        bufp->chgBit(oldp+270,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x17U])));
        bufp->chgBit(oldp+271,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x17U] >> 1U))));
        bufp->chgBit(oldp+272,((1U & (~ (IData)((0x1fffffffe00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 9U)))))));
        bufp->chgBit(oldp+273,((((~ (IData)((0x1fffffffe00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffe00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x17U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x17U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+274,((1U & (IData)((0xffffffff00ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 8U))))));
        bufp->chgBit(oldp+275,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x18U])));
        bufp->chgBit(oldp+276,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x18U] >> 1U))));
        bufp->chgBit(oldp+277,((1U & (~ (IData)((0xffffffff00ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 8U)))))));
        bufp->chgBit(oldp+278,((((~ (IData)((0xffffffff00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffff00ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x18U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x18U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+279,((1U & (IData)((0x7fffffff80ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))))));
        bufp->chgBit(oldp+280,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x19U])));
        bufp->chgBit(oldp+281,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x19U] >> 1U))));
        bufp->chgBit(oldp+282,((1U & (~ (IData)((0x7fffffff80ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 7U)))))));
        bufp->chgBit(oldp+283,((((~ (IData)((0x7fffffff80ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff80ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x19U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x19U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+284,((1U & (IData)((0x3fffffffc0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 6U))))));
        bufp->chgBit(oldp+285,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x1aU])));
        bufp->chgBit(oldp+286,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x1aU] >> 1U))));
        bufp->chgBit(oldp+287,((1U & (~ (IData)((0x3fffffffc0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 6U)))))));
        bufp->chgBit(oldp+288,((((~ (IData)((0x3fffffffc0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffc0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x1aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x1aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+289,((1U & (IData)((0x1fffffffe0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))))));
        bufp->chgBit(oldp+290,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x1bU])));
        bufp->chgBit(oldp+291,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x1bU] >> 1U))));
        bufp->chgBit(oldp+292,((1U & (~ (IData)((0x1fffffffe0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 5U)))))));
        bufp->chgBit(oldp+293,((((~ (IData)((0x1fffffffe0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 5U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffe0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 5U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x1bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x1bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+294,((1U & (IData)((0xffffffff0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))));
        bufp->chgBit(oldp+295,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x1cU])));
        bufp->chgBit(oldp+296,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x1cU] >> 1U))));
        bufp->chgBit(oldp+297,((1U & (~ (IData)((0xffffffff0ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 4U)))))));
        bufp->chgBit(oldp+298,((((~ (IData)((0xffffffff0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 4U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffff0ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 4U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x1cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x1cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+299,((1U & (IData)((0x7fffffff8ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))));
        bufp->chgBit(oldp+300,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x1dU])));
        bufp->chgBit(oldp+301,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x1dU] >> 1U))));
        bufp->chgBit(oldp+302,((1U & (~ (IData)((0x7fffffff8ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 3U)))))));
        bufp->chgBit(oldp+303,((((~ (IData)((0x7fffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x1dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x1dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+304,((1U & (IData)((0x3fffffffc0000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1eU))))));
        bufp->chgBit(oldp+305,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [2U])));
        bufp->chgBit(oldp+306,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [2U] >> 1U))));
        bufp->chgBit(oldp+307,((1U & (~ (IData)((0x3fffffffc0000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1eU)))))));
        bufp->chgBit(oldp+308,((((~ (IData)((0x3fffffffc0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1eU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffc0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1eU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [2U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [2U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+309,((1U & (IData)((0x3fffffffcULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))));
        bufp->chgBit(oldp+310,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x1eU])));
        bufp->chgBit(oldp+311,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x1eU] >> 1U))));
        bufp->chgBit(oldp+312,((1U & (~ (IData)((0x3fffffffcULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 2U)))))));
        bufp->chgBit(oldp+313,((((~ (IData)((0x3fffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x1eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x1eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+314,((1U & (IData)((0x1fffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))));
        bufp->chgBit(oldp+315,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x1fU])));
        bufp->chgBit(oldp+316,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x1fU] >> 1U))));
        bufp->chgBit(oldp+317,((1U & (~ (IData)((0x1fffffffeULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 1U)))))));
        bufp->chgBit(oldp+318,((((~ (IData)((0x1fffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x1fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x1fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+319,((1U & (IData)((0xffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)))));
        bufp->chgBit(oldp+320,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x20U])));
        bufp->chgBit(oldp+321,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x20U] >> 1U))));
        bufp->chgBit(oldp+322,((1U & (~ (IData)((0xffffffffULL 
                                                 & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))))));
        bufp->chgBit(oldp+323,((((~ (IData)((0xffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x20U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x20U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+324,((1U & (IData)((0x7fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))));
        bufp->chgBit(oldp+325,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x21U])));
        bufp->chgBit(oldp+326,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x21U] >> 1U))));
        bufp->chgBit(oldp+327,((1U & (~ (IData)((0x7fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 1U)))))));
        bufp->chgBit(oldp+328,((((~ (IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x21U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x21U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+329,((1U & (IData)((0x3fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))));
        bufp->chgBit(oldp+330,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x22U])));
        bufp->chgBit(oldp+331,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x22U] >> 1U))));
        bufp->chgBit(oldp+332,((1U & (~ (IData)((0x3fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 2U)))))));
        bufp->chgBit(oldp+333,((((~ (IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x22U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x22U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+334,((1U & (IData)((0x1fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))));
        bufp->chgBit(oldp+335,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x23U])));
        bufp->chgBit(oldp+336,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x23U] >> 1U))));
        bufp->chgBit(oldp+337,((1U & (~ (IData)((0x1fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 3U)))))));
        bufp->chgBit(oldp+338,((((~ (IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x23U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x23U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+339,((1U & (IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))));
        bufp->chgBit(oldp+340,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x24U])));
        bufp->chgBit(oldp+341,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x24U] >> 1U))));
        bufp->chgBit(oldp+342,((1U & (~ (IData)((0xfffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 4U)))))));
        bufp->chgBit(oldp+343,((((~ (IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x24U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x24U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+344,((1U & (IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))));
        bufp->chgBit(oldp+345,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x25U])));
        bufp->chgBit(oldp+346,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x25U] >> 1U))));
        bufp->chgBit(oldp+347,((1U & (~ (IData)((0x7ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 5U)))))));
        bufp->chgBit(oldp+348,((((~ (IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x25U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x25U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+349,((1U & (IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))));
        bufp->chgBit(oldp+350,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x26U])));
        bufp->chgBit(oldp+351,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x26U] >> 1U))));
        bufp->chgBit(oldp+352,((1U & (~ (IData)((0x3ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 6U)))))));
        bufp->chgBit(oldp+353,((((~ (IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x26U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x26U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+354,((1U & (IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))));
        bufp->chgBit(oldp+355,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x27U])));
        bufp->chgBit(oldp+356,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x27U] >> 1U))));
        bufp->chgBit(oldp+357,((1U & (~ (IData)((0x1ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 7U)))))));
        bufp->chgBit(oldp+358,((((~ (IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x27U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x27U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+359,((1U & (IData)((0x1fffffffe0000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1dU))))));
        bufp->chgBit(oldp+360,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [3U])));
        bufp->chgBit(oldp+361,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [3U] >> 1U))));
        bufp->chgBit(oldp+362,((1U & (~ (IData)((0x1fffffffe0000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1dU)))))));
        bufp->chgBit(oldp+363,((((~ (IData)((0x1fffffffe0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffe0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [3U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [3U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+364,((1U & (IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))));
        bufp->chgBit(oldp+365,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x28U])));
        bufp->chgBit(oldp+366,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x28U] >> 1U))));
        bufp->chgBit(oldp+367,((1U & (~ (IData)((0xffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 8U)))))));
        bufp->chgBit(oldp+368,((((~ (IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x28U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x28U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+369,((1U & (IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))));
        bufp->chgBit(oldp+370,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x29U])));
        bufp->chgBit(oldp+371,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x29U] >> 1U))));
        bufp->chgBit(oldp+372,((1U & (~ (IData)((0x7fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 9U)))))));
        bufp->chgBit(oldp+373,((((~ (IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x29U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x29U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+374,((1U & (IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))));
        bufp->chgBit(oldp+375,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x2aU])));
        bufp->chgBit(oldp+376,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x2aU] >> 1U))));
        bufp->chgBit(oldp+377,((1U & (~ (IData)((0x3fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xaU)))))));
        bufp->chgBit(oldp+378,((((~ (IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x2aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x2aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+379,((1U & (IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))));
        bufp->chgBit(oldp+380,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x2bU])));
        bufp->chgBit(oldp+381,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x2bU] >> 1U))));
        bufp->chgBit(oldp+382,((1U & (~ (IData)((0x1fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xbU)))))));
        bufp->chgBit(oldp+383,((((~ (IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x2bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x2bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+384,((1U & (IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))));
        bufp->chgBit(oldp+385,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x2cU])));
        bufp->chgBit(oldp+386,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x2cU] >> 1U))));
        bufp->chgBit(oldp+387,((1U & (~ (IData)((0xfffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xcU)))))));
        bufp->chgBit(oldp+388,((((~ (IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x2cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x2cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+389,((1U & (IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))));
        bufp->chgBit(oldp+390,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x2dU])));
        bufp->chgBit(oldp+391,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x2dU] >> 1U))));
        bufp->chgBit(oldp+392,((1U & (~ (IData)((0x7ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xdU)))))));
        bufp->chgBit(oldp+393,((((~ (IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x2dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x2dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+394,((1U & (IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))));
        bufp->chgBit(oldp+395,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x2eU])));
        bufp->chgBit(oldp+396,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x2eU] >> 1U))));
        bufp->chgBit(oldp+397,((1U & (~ (IData)((0x3ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xeU)))))));
        bufp->chgBit(oldp+398,((((~ (IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x2eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x2eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+399,((1U & (IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))));
        bufp->chgBit(oldp+400,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x2fU])));
        bufp->chgBit(oldp+401,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x2fU] >> 1U))));
        bufp->chgBit(oldp+402,((1U & (~ (IData)((0x1ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xfU)))))));
        bufp->chgBit(oldp+403,((((~ (IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x2fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x2fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+404,((1U & (IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))));
        bufp->chgBit(oldp+405,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x30U])));
        bufp->chgBit(oldp+406,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x30U] >> 1U))));
        bufp->chgBit(oldp+407,((1U & (~ (IData)((0xffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x10U)))))));
        bufp->chgBit(oldp+408,((((~ (IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x30U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x30U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+409,((1U & (IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))));
        bufp->chgBit(oldp+410,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x31U])));
        bufp->chgBit(oldp+411,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x31U] >> 1U))));
        bufp->chgBit(oldp+412,((1U & (~ (IData)((0x7fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x11U)))))));
        bufp->chgBit(oldp+413,((((~ (IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x31U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x31U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+414,((1U & (IData)((0xffffffff0000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1cU))))));
        bufp->chgBit(oldp+415,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [4U])));
        bufp->chgBit(oldp+416,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [4U] >> 1U))));
        bufp->chgBit(oldp+417,((1U & (~ (IData)((0xffffffff0000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1cU)))))));
        bufp->chgBit(oldp+418,((((~ (IData)((0xffffffff0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffff0000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [4U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [4U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+419,((1U & (IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))));
        bufp->chgBit(oldp+420,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x32U])));
        bufp->chgBit(oldp+421,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x32U] >> 1U))));
        bufp->chgBit(oldp+422,((1U & (~ (IData)((0x3fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x12U)))))));
        bufp->chgBit(oldp+423,((((~ (IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x32U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x32U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+424,((1U & (IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))));
        bufp->chgBit(oldp+425,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x33U])));
        bufp->chgBit(oldp+426,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x33U] >> 1U))));
        bufp->chgBit(oldp+427,((1U & (~ (IData)((0x1fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x13U)))))));
        bufp->chgBit(oldp+428,((((~ (IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x33U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x33U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+429,((1U & (IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))));
        bufp->chgBit(oldp+430,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x34U])));
        bufp->chgBit(oldp+431,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x34U] >> 1U))));
        bufp->chgBit(oldp+432,((1U & (~ (IData)((0xfffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x14U)))))));
        bufp->chgBit(oldp+433,((((~ (IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x34U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x34U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+434,((1U & (IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))));
        bufp->chgBit(oldp+435,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x35U])));
        bufp->chgBit(oldp+436,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x35U] >> 1U))));
        bufp->chgBit(oldp+437,((1U & (~ (IData)((0x7ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x15U)))))));
        bufp->chgBit(oldp+438,((((~ (IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x35U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x35U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+439,((1U & (IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))));
        bufp->chgBit(oldp+440,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x36U])));
        bufp->chgBit(oldp+441,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x36U] >> 1U))));
        bufp->chgBit(oldp+442,((1U & (~ (IData)((0x3ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x16U)))))));
        bufp->chgBit(oldp+443,((((~ (IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x36U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x36U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+444,((1U & (IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))));
        bufp->chgBit(oldp+445,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x37U])));
        bufp->chgBit(oldp+446,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x37U] >> 1U))));
        bufp->chgBit(oldp+447,((1U & (~ (IData)((0x1ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x17U)))))));
        bufp->chgBit(oldp+448,((((~ (IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x37U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x37U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+449,((1U & (IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))));
        bufp->chgBit(oldp+450,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x38U])));
        bufp->chgBit(oldp+451,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x38U] >> 1U))));
        bufp->chgBit(oldp+452,((1U & (~ (IData)((0xffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x18U)))))));
        bufp->chgBit(oldp+453,((((~ (IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x38U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x38U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+454,((1U & (IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))));
        bufp->chgBit(oldp+455,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x39U])));
        bufp->chgBit(oldp+456,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x39U] >> 1U))));
        bufp->chgBit(oldp+457,((1U & (~ (IData)((0x7fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x19U)))))));
        bufp->chgBit(oldp+458,((((~ (IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x39U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x39U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+459,((1U & (IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))));
        bufp->chgBit(oldp+460,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x3aU])));
        bufp->chgBit(oldp+461,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x3aU] >> 1U))));
        bufp->chgBit(oldp+462,((1U & (~ (IData)((0x3fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1aU)))))));
        bufp->chgBit(oldp+463,((((~ (IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x3aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x3aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+464,((1U & (IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))));
        bufp->chgBit(oldp+465,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x3bU])));
        bufp->chgBit(oldp+466,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x3bU] >> 1U))));
        bufp->chgBit(oldp+467,((1U & (~ (IData)((0x1fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1bU)))))));
        bufp->chgBit(oldp+468,((((~ (IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x3bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x3bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+469,((1U & (IData)((0x7fffffff8000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1bU))))));
        bufp->chgBit(oldp+470,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [5U])));
        bufp->chgBit(oldp+471,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [5U] >> 1U))));
        bufp->chgBit(oldp+472,((1U & (~ (IData)((0x7fffffff8000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1bU)))))));
        bufp->chgBit(oldp+473,((((~ (IData)((0x7fffffff8000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff8000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [5U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [5U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+474,((1U & (IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))));
        bufp->chgBit(oldp+475,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x3cU])));
        bufp->chgBit(oldp+476,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x3cU] >> 1U))));
        bufp->chgBit(oldp+477,((1U & (~ (IData)((0xfULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1cU)))))));
        bufp->chgBit(oldp+478,((((~ (IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x3cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x3cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+479,((1U & (IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))));
        bufp->chgBit(oldp+480,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x3dU])));
        bufp->chgBit(oldp+481,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x3dU] >> 1U))));
        bufp->chgBit(oldp+482,((1U & (~ (IData)((7ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1dU)))))));
        bufp->chgBit(oldp+483,((((~ (IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x3dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x3dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+484,((1U & (IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))));
        bufp->chgBit(oldp+485,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x3eU])));
        bufp->chgBit(oldp+486,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x3eU] >> 1U))));
        bufp->chgBit(oldp+487,((1U & (~ (IData)((3ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1eU)))))));
        bufp->chgBit(oldp+488,((((~ (IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1eU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1eU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x3eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x3eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+489,((1U & (IData)((1ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))));
        bufp->chgBit(oldp+490,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [0x3fU])));
        bufp->chgBit(oldp+491,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [0x3fU] >> 1U))));
        bufp->chgBit(oldp+492,((1U & (~ (IData)((1ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1fU)))))));
        bufp->chgBit(oldp+493,((((~ (IData)((1ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x1fU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | ((IData)(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x1fU) 
                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x))) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [0x3fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [0x3fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+494,((1U & (IData)((0x3fffffffc000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1aU))))));
        bufp->chgBit(oldp+495,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [6U])));
        bufp->chgBit(oldp+496,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [6U] >> 1U))));
        bufp->chgBit(oldp+497,((1U & (~ (IData)((0x3fffffffc000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x1aU)))))));
        bufp->chgBit(oldp+498,((((~ (IData)((0x3fffffffc000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x3fffffffc000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [6U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [6U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+499,((1U & (IData)((0x1fffffffe000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x19U))))));
        bufp->chgBit(oldp+500,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [7U])));
        bufp->chgBit(oldp+501,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [7U] >> 1U))));
        bufp->chgBit(oldp+502,((1U & (~ (IData)((0x1fffffffe000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x19U)))))));
        bufp->chgBit(oldp+503,((((~ (IData)((0x1fffffffe000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x1fffffffe000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [7U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [7U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+504,((1U & (IData)((0xffffffff000000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x18U))))));
        bufp->chgBit(oldp+505,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [8U])));
        bufp->chgBit(oldp+506,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [8U] >> 1U))));
        bufp->chgBit(oldp+507,((1U & (~ (IData)((0xffffffff000000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x18U)))))));
        bufp->chgBit(oldp+508,((((~ (IData)((0xffffffff000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0xffffffff000000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [8U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [8U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+509,((1U & (IData)((0x7fffffff800000ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x17U))))));
        bufp->chgBit(oldp+510,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                [9U])));
        bufp->chgBit(oldp+511,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                      [9U] >> 1U))));
        bufp->chgBit(oldp+512,((1U & (~ (IData)((0x7fffffff800000ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 0x17U)))))));
        bufp->chgBit(oldp+513,((((~ (IData)((0x7fffffff800000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__negx)) 
                                | (((IData)((0x7fffffff800000ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                        [9U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT__CarrySig
                                         [9U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__las.__PVT___2x)))))));
        bufp->chgBit(oldp+514,((1U & ((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__las__y) 
                                      >> 2U))));
        bufp->chgBit(oldp+515,((1U & ((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__las__y) 
                                      >> 1U))));
        bufp->chgBit(oldp+516,((1U & (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__las__y))));
        bufp->chgCData(oldp+517,((7U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                                >> 1U)))),3);
        bufp->chgQData(oldp+518,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                  << 2U)),64);
        bufp->chgQData(oldp+520,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__OutX),64);
        bufp->chgBit(oldp+522,(((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x) 
                                | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx))));
        bufp->chgBit(oldp+523,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx));
        bufp->chgBit(oldp+524,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x));
        bufp->chgBit(oldp+525,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x));
        bufp->chgBit(oldp+526,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 2U)))));
        bufp->chgBit(oldp+527,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))));
        bufp->chgBit(oldp+528,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 2U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 2U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)))));
        bufp->chgBit(oldp+529,((1U & (IData)((0x3fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))));
        bufp->chgBit(oldp+530,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0xaU])));
        bufp->chgBit(oldp+531,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0xaU] >> 1U))));
        bufp->chgBit(oldp+532,((1U & (~ (IData)((0x3fffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 8U)))))));
        bufp->chgBit(oldp+533,((((~ (IData)((0x3fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0xaU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0xaU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+534,((1U & (IData)((0x1fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))));
        bufp->chgBit(oldp+535,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0xbU])));
        bufp->chgBit(oldp+536,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0xbU] >> 1U))));
        bufp->chgBit(oldp+537,((1U & (~ (IData)((0x1fffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 9U)))))));
        bufp->chgBit(oldp+538,((((~ (IData)((0x1fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0xbU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0xbU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+539,((1U & (IData)((0xfffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))));
        bufp->chgBit(oldp+540,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0xcU])));
        bufp->chgBit(oldp+541,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0xcU] >> 1U))));
        bufp->chgBit(oldp+542,((1U & (~ (IData)((0xfffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xaU)))))));
        bufp->chgBit(oldp+543,((((~ (IData)((0xfffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0xcU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0xcU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+544,((1U & (IData)((0x7ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))));
        bufp->chgBit(oldp+545,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0xdU])));
        bufp->chgBit(oldp+546,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0xdU] >> 1U))));
        bufp->chgBit(oldp+547,((1U & (~ (IData)((0x7ffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xbU)))))));
        bufp->chgBit(oldp+548,((((~ (IData)((0x7ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0xdU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0xdU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+549,((1U & (IData)((0x3ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))));
        bufp->chgBit(oldp+550,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0xeU])));
        bufp->chgBit(oldp+551,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0xeU] >> 1U))));
        bufp->chgBit(oldp+552,((1U & (~ (IData)((0x3ffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xcU)))))));
        bufp->chgBit(oldp+553,((((~ (IData)((0x3ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0xeU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0xeU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+554,((1U & (IData)((0x1ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))));
        bufp->chgBit(oldp+555,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0xfU])));
        bufp->chgBit(oldp+556,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0xfU] >> 1U))));
        bufp->chgBit(oldp+557,((1U & (~ (IData)((0x1ffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xdU)))))));
        bufp->chgBit(oldp+558,((((~ (IData)((0x1ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0xfU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0xfU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+559,((1U & (IData)((0xffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))));
        bufp->chgBit(oldp+560,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x10U])));
        bufp->chgBit(oldp+561,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x10U] >> 1U))));
        bufp->chgBit(oldp+562,((1U & (~ (IData)((0xffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xeU)))))));
        bufp->chgBit(oldp+563,((((~ (IData)((0xffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x10U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x10U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+564,((1U & (IData)((0x7fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))));
        bufp->chgBit(oldp+565,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x11U])));
        bufp->chgBit(oldp+566,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x11U] >> 1U))));
        bufp->chgBit(oldp+567,((1U & (~ (IData)((0x7fffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xfU)))))));
        bufp->chgBit(oldp+568,((((~ (IData)((0x7fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x11U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x11U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+569,((1U & (IData)((0x3fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))));
        bufp->chgBit(oldp+570,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x12U])));
        bufp->chgBit(oldp+571,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x12U] >> 1U))));
        bufp->chgBit(oldp+572,((1U & (~ (IData)((0x3fffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x10U)))))));
        bufp->chgBit(oldp+573,((((~ (IData)((0x3fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x12U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x12U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+574,((1U & (IData)((0x1fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))));
        bufp->chgBit(oldp+575,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x13U])));
        bufp->chgBit(oldp+576,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x13U] >> 1U))));
        bufp->chgBit(oldp+577,((1U & (~ (IData)((0x1fffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x11U)))))));
        bufp->chgBit(oldp+578,((((~ (IData)((0x1fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x13U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x13U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+579,((1U & (IData)((0x7ffffffffffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))));
        bufp->chgBit(oldp+580,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [1U])));
        bufp->chgBit(oldp+581,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [1U] >> 1U))));
        bufp->chgBit(oldp+582,((1U & (~ (IData)((0x7ffffffffffffffeULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 1U)))))));
        bufp->chgBit(oldp+583,((((~ (IData)((0x7ffffffffffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffffffffeULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [1U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [1U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+584,((1U & (IData)((0xfffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))));
        bufp->chgBit(oldp+585,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x14U])));
        bufp->chgBit(oldp+586,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x14U] >> 1U))));
        bufp->chgBit(oldp+587,((1U & (~ (IData)((0xfffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x12U)))))));
        bufp->chgBit(oldp+588,((((~ (IData)((0xfffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x14U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x14U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+589,((1U & (IData)((0x7ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))));
        bufp->chgBit(oldp+590,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x15U])));
        bufp->chgBit(oldp+591,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x15U] >> 1U))));
        bufp->chgBit(oldp+592,((1U & (~ (IData)((0x7ffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x13U)))))));
        bufp->chgBit(oldp+593,((((~ (IData)((0x7ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x15U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x15U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+594,((1U & (IData)((0x3ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))));
        bufp->chgBit(oldp+595,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x16U])));
        bufp->chgBit(oldp+596,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x16U] >> 1U))));
        bufp->chgBit(oldp+597,((1U & (~ (IData)((0x3ffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x14U)))))));
        bufp->chgBit(oldp+598,((((~ (IData)((0x3ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x16U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x16U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+599,((1U & (IData)((0x1ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))));
        bufp->chgBit(oldp+600,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x17U])));
        bufp->chgBit(oldp+601,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x17U] >> 1U))));
        bufp->chgBit(oldp+602,((1U & (~ (IData)((0x1ffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x15U)))))));
        bufp->chgBit(oldp+603,((((~ (IData)((0x1ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x17U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x17U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+604,((1U & (IData)((0xffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))));
        bufp->chgBit(oldp+605,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x18U])));
        bufp->chgBit(oldp+606,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x18U] >> 1U))));
        bufp->chgBit(oldp+607,((1U & (~ (IData)((0xffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x16U)))))));
        bufp->chgBit(oldp+608,((((~ (IData)((0xffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x18U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x18U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+609,((1U & (IData)((0x7fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))));
        bufp->chgBit(oldp+610,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x19U])));
        bufp->chgBit(oldp+611,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x19U] >> 1U))));
        bufp->chgBit(oldp+612,((1U & (~ (IData)((0x7fffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x17U)))))));
        bufp->chgBit(oldp+613,((((~ (IData)((0x7fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x19U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x19U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+614,((1U & (IData)((0x3fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))));
        bufp->chgBit(oldp+615,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x1aU])));
        bufp->chgBit(oldp+616,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x1aU] >> 1U))));
        bufp->chgBit(oldp+617,((1U & (~ (IData)((0x3fffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x18U)))))));
        bufp->chgBit(oldp+618,((((~ (IData)((0x3fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x1aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x1aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+619,((1U & (IData)((0x1fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))));
        bufp->chgBit(oldp+620,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x1bU])));
        bufp->chgBit(oldp+621,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x1bU] >> 1U))));
        bufp->chgBit(oldp+622,((1U & (~ (IData)((0x1fffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x19U)))))));
        bufp->chgBit(oldp+623,((((~ (IData)((0x1fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x1bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x1bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+624,((1U & (IData)((0xfffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))));
        bufp->chgBit(oldp+625,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x1cU])));
        bufp->chgBit(oldp+626,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x1cU] >> 1U))));
        bufp->chgBit(oldp+627,((1U & (~ (IData)((0xfffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1aU)))))));
        bufp->chgBit(oldp+628,((((~ (IData)((0xfffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x1cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x1cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+629,((1U & (IData)((0x7ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))));
        bufp->chgBit(oldp+630,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x1dU])));
        bufp->chgBit(oldp+631,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x1dU] >> 1U))));
        bufp->chgBit(oldp+632,((1U & (~ (IData)((0x7ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1bU)))))));
        bufp->chgBit(oldp+633,((((~ (IData)((0x7ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x1dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x1dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+634,((1U & (IData)((0x3fffffffffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)))));
        bufp->chgBit(oldp+635,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [2U])));
        bufp->chgBit(oldp+636,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [2U] >> 1U))));
        bufp->chgBit(oldp+637,((1U & (~ (IData)((0x3fffffffffffffffULL 
                                                 & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))))));
        bufp->chgBit(oldp+638,((((~ (IData)((0x3fffffffffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffffffffffULL 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [2U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [2U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+639,((1U & (IData)((0x3ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))));
        bufp->chgBit(oldp+640,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x1eU])));
        bufp->chgBit(oldp+641,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x1eU] >> 1U))));
        bufp->chgBit(oldp+642,((1U & (~ (IData)((0x3ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1cU)))))));
        bufp->chgBit(oldp+643,((((~ (IData)((0x3ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x1eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x1eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+644,((1U & (IData)((0x1ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))));
        bufp->chgBit(oldp+645,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x1fU])));
        bufp->chgBit(oldp+646,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x1fU] >> 1U))));
        bufp->chgBit(oldp+647,((1U & (~ (IData)((0x1ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1dU)))))));
        bufp->chgBit(oldp+648,((((~ (IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x1fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x1fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+649,((1U & (IData)((0xffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))));
        bufp->chgBit(oldp+650,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x20U])));
        bufp->chgBit(oldp+651,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x20U] >> 1U))));
        bufp->chgBit(oldp+652,((1U & (~ (IData)((0xffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1eU)))))));
        bufp->chgBit(oldp+653,((((~ (IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x20U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x20U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+654,((1U & (IData)((0x7fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))));
        bufp->chgBit(oldp+655,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x21U])));
        bufp->chgBit(oldp+656,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x21U] >> 1U))));
        bufp->chgBit(oldp+657,((1U & (~ (IData)((0x7fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1fU)))))));
        bufp->chgBit(oldp+658,((((~ (IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1fU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1fU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x21U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x21U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+659,((1U & (IData)((0x3fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))));
        bufp->chgBit(oldp+660,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x22U])));
        bufp->chgBit(oldp+661,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x22U] >> 1U))));
        bufp->chgBit(oldp+662,((1U & (~ (IData)((0x3fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x20U)))))));
        bufp->chgBit(oldp+663,((((~ (IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x20U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x20U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x22U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x22U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+664,((1U & (IData)((0x1fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))))));
        bufp->chgBit(oldp+665,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x23U])));
        bufp->chgBit(oldp+666,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x23U] >> 1U))));
        bufp->chgBit(oldp+667,((1U & (~ (IData)((0x1fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x21U)))))));
        bufp->chgBit(oldp+668,((((~ (IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x21U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x21U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x23U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x23U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+669,((1U & (IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))))));
        bufp->chgBit(oldp+670,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x24U])));
        bufp->chgBit(oldp+671,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x24U] >> 1U))));
        bufp->chgBit(oldp+672,((1U & (~ (IData)((0xfffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x22U)))))));
        bufp->chgBit(oldp+673,((((~ (IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x22U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x22U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x24U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x24U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+674,((1U & (IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U))))));
        bufp->chgBit(oldp+675,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x25U])));
        bufp->chgBit(oldp+676,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x25U] >> 1U))));
        bufp->chgBit(oldp+677,((1U & (~ (IData)((0x7ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x23U)))))));
        bufp->chgBit(oldp+678,((((~ (IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x23U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x23U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x25U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x25U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+679,((1U & (IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U))))));
        bufp->chgBit(oldp+680,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x26U])));
        bufp->chgBit(oldp+681,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x26U] >> 1U))));
        bufp->chgBit(oldp+682,((1U & (~ (IData)((0x3ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x24U)))))));
        bufp->chgBit(oldp+683,((((~ (IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x24U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x24U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x26U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x26U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+684,((1U & (IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x25U))))));
        bufp->chgBit(oldp+685,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x27U])));
        bufp->chgBit(oldp+686,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x27U] >> 1U))));
        bufp->chgBit(oldp+687,((1U & (~ (IData)((0x1ffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x25U)))))));
        bufp->chgBit(oldp+688,((((~ (IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x25U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x25U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x27U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x27U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+689,((1U & (IData)((0x1fffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))));
        bufp->chgBit(oldp+690,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [3U])));
        bufp->chgBit(oldp+691,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [3U] >> 1U))));
        bufp->chgBit(oldp+692,((1U & (~ (IData)((0x1fffffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 1U)))))));
        bufp->chgBit(oldp+693,((((~ (IData)((0x1fffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 1U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [3U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [3U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+694,((1U & (IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x26U))))));
        bufp->chgBit(oldp+695,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x28U])));
        bufp->chgBit(oldp+696,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x28U] >> 1U))));
        bufp->chgBit(oldp+697,((1U & (~ (IData)((0xffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x26U)))))));
        bufp->chgBit(oldp+698,((((~ (IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x26U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x26U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x28U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x28U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+699,((1U & (IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x27U))))));
        bufp->chgBit(oldp+700,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x29U])));
        bufp->chgBit(oldp+701,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x29U] >> 1U))));
        bufp->chgBit(oldp+702,((1U & (~ (IData)((0x7fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x27U)))))));
        bufp->chgBit(oldp+703,((((~ (IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x27U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x27U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x29U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x29U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+704,((1U & (IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x28U))))));
        bufp->chgBit(oldp+705,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x2aU])));
        bufp->chgBit(oldp+706,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x2aU] >> 1U))));
        bufp->chgBit(oldp+707,((1U & (~ (IData)((0x3fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x28U)))))));
        bufp->chgBit(oldp+708,((((~ (IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x28U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x28U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x2aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x2aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+709,((1U & (IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x29U))))));
        bufp->chgBit(oldp+710,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x2bU])));
        bufp->chgBit(oldp+711,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x2bU] >> 1U))));
        bufp->chgBit(oldp+712,((1U & (~ (IData)((0x1fffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x29U)))))));
        bufp->chgBit(oldp+713,((((~ (IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x29U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x29U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x2bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x2bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+714,((1U & (IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2aU))))));
        bufp->chgBit(oldp+715,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x2cU])));
        bufp->chgBit(oldp+716,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x2cU] >> 1U))));
        bufp->chgBit(oldp+717,((1U & (~ (IData)((0xfffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x2aU)))))));
        bufp->chgBit(oldp+718,((((~ (IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x2cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x2cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+719,((1U & (IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2bU))))));
        bufp->chgBit(oldp+720,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x2dU])));
        bufp->chgBit(oldp+721,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x2dU] >> 1U))));
        bufp->chgBit(oldp+722,((1U & (~ (IData)((0x7ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x2bU)))))));
        bufp->chgBit(oldp+723,((((~ (IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x2dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x2dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+724,((1U & (IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2cU))))));
        bufp->chgBit(oldp+725,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x2eU])));
        bufp->chgBit(oldp+726,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x2eU] >> 1U))));
        bufp->chgBit(oldp+727,((1U & (~ (IData)((0x3ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x2cU)))))));
        bufp->chgBit(oldp+728,((((~ (IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x2eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x2eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+729,((1U & (IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2dU))))));
        bufp->chgBit(oldp+730,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x2fU])));
        bufp->chgBit(oldp+731,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x2fU] >> 1U))));
        bufp->chgBit(oldp+732,((1U & (~ (IData)((0x1ffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x2dU)))))));
        bufp->chgBit(oldp+733,((((~ (IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x2fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x2fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+734,((1U & (IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2eU))))));
        bufp->chgBit(oldp+735,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x30U])));
        bufp->chgBit(oldp+736,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x30U] >> 1U))));
        bufp->chgBit(oldp+737,((1U & (~ (IData)((0xffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x2eU)))))));
        bufp->chgBit(oldp+738,((((~ (IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2eU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2eU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x30U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x30U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+739,((1U & (IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2fU))))));
        bufp->chgBit(oldp+740,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x31U])));
        bufp->chgBit(oldp+741,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x31U] >> 1U))));
        bufp->chgBit(oldp+742,((1U & (~ (IData)((0x7fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x2fU)))))));
        bufp->chgBit(oldp+743,((((~ (IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2fU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x2fU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x31U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x31U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+744,((1U & (IData)((0xfffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))));
        bufp->chgBit(oldp+745,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [4U])));
        bufp->chgBit(oldp+746,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [4U] >> 1U))));
        bufp->chgBit(oldp+747,((1U & (~ (IData)((0xfffffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 2U)))))));
        bufp->chgBit(oldp+748,((((~ (IData)((0xfffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [4U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [4U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+749,((1U & (IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x30U))))));
        bufp->chgBit(oldp+750,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x32U])));
        bufp->chgBit(oldp+751,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x32U] >> 1U))));
        bufp->chgBit(oldp+752,((1U & (~ (IData)((0x3fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x30U)))))));
        bufp->chgBit(oldp+753,((((~ (IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x30U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x30U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x32U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x32U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+754,((1U & (IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x31U))))));
        bufp->chgBit(oldp+755,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x33U])));
        bufp->chgBit(oldp+756,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x33U] >> 1U))));
        bufp->chgBit(oldp+757,((1U & (~ (IData)((0x1fffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x31U)))))));
        bufp->chgBit(oldp+758,((((~ (IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x31U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x31U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x33U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x33U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+759,((1U & (IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x32U))))));
        bufp->chgBit(oldp+760,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x34U])));
        bufp->chgBit(oldp+761,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x34U] >> 1U))));
        bufp->chgBit(oldp+762,((1U & (~ (IData)((0xfffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x32U)))))));
        bufp->chgBit(oldp+763,((((~ (IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x32U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x32U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x34U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x34U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+764,((1U & (IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x33U))))));
        bufp->chgBit(oldp+765,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x35U])));
        bufp->chgBit(oldp+766,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x35U] >> 1U))));
        bufp->chgBit(oldp+767,((1U & (~ (IData)((0x7ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x33U)))))));
        bufp->chgBit(oldp+768,((((~ (IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x33U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x33U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x35U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x35U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+769,((1U & (IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x34U))))));
        bufp->chgBit(oldp+770,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x36U])));
        bufp->chgBit(oldp+771,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x36U] >> 1U))));
        bufp->chgBit(oldp+772,((1U & (~ (IData)((0x3ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x34U)))))));
        bufp->chgBit(oldp+773,((((~ (IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x34U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x34U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x36U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x36U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+774,((1U & (IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x35U))))));
        bufp->chgBit(oldp+775,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x37U])));
        bufp->chgBit(oldp+776,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x37U] >> 1U))));
        bufp->chgBit(oldp+777,((1U & (~ (IData)((0x1ffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x35U)))))));
        bufp->chgBit(oldp+778,((((~ (IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x35U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x35U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x37U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x37U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+779,((1U & (IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x36U))))));
        bufp->chgBit(oldp+780,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x38U])));
        bufp->chgBit(oldp+781,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x38U] >> 1U))));
        bufp->chgBit(oldp+782,((1U & (~ (IData)((0xffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x36U)))))));
        bufp->chgBit(oldp+783,((((~ (IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x36U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x36U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x38U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x38U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+784,((1U & (IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x37U))))));
        bufp->chgBit(oldp+785,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x39U])));
        bufp->chgBit(oldp+786,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x39U] >> 1U))));
        bufp->chgBit(oldp+787,((1U & (~ (IData)((0x7fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x37U)))))));
        bufp->chgBit(oldp+788,((((~ (IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x37U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x37U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x39U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x39U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+789,((1U & (IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x38U))))));
        bufp->chgBit(oldp+790,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x3aU])));
        bufp->chgBit(oldp+791,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x3aU] >> 1U))));
        bufp->chgBit(oldp+792,((1U & (~ (IData)((0x3fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x38U)))))));
        bufp->chgBit(oldp+793,((((~ (IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x38U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x38U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x3aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x3aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+794,((1U & (IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x39U))))));
        bufp->chgBit(oldp+795,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x3bU])));
        bufp->chgBit(oldp+796,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x3bU] >> 1U))));
        bufp->chgBit(oldp+797,((1U & (~ (IData)((0x1fULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x39U)))))));
        bufp->chgBit(oldp+798,((((~ (IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x39U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x39U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x3bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x3bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+799,((1U & (IData)((0x7ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))));
        bufp->chgBit(oldp+800,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [5U])));
        bufp->chgBit(oldp+801,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [5U] >> 1U))));
        bufp->chgBit(oldp+802,((1U & (~ (IData)((0x7ffffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 3U)))))));
        bufp->chgBit(oldp+803,((((~ (IData)((0x7ffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [5U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [5U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+804,((1U & (IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3aU))))));
        bufp->chgBit(oldp+805,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x3cU])));
        bufp->chgBit(oldp+806,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x3cU] >> 1U))));
        bufp->chgBit(oldp+807,((1U & (~ (IData)((0xfULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x3aU)))))));
        bufp->chgBit(oldp+808,((((~ (IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x3aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x3aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x3cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x3cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+809,((1U & (IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3bU))))));
        bufp->chgBit(oldp+810,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x3dU])));
        bufp->chgBit(oldp+811,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x3dU] >> 1U))));
        bufp->chgBit(oldp+812,((1U & (~ (IData)((7ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x3bU)))))));
        bufp->chgBit(oldp+813,((((~ (IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((7ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x3dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x3dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+814,((1U & (IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3cU))))));
        bufp->chgBit(oldp+815,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x3eU])));
        bufp->chgBit(oldp+816,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x3eU] >> 1U))));
        bufp->chgBit(oldp+817,((1U & (~ (IData)((3ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x3cU)))))));
        bufp->chgBit(oldp+818,((((~ (IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((3ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x3eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x3eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+819,((1U & (IData)((1ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3dU))))));
        bufp->chgBit(oldp+820,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [0x3fU])));
        bufp->chgBit(oldp+821,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [0x3fU] >> 1U))));
        bufp->chgBit(oldp+822,((1U & (~ (IData)((1ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x3dU)))))));
        bufp->chgBit(oldp+823,((((~ (IData)((1ULL & 
                                             (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | ((IData)(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3dU) 
                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x))) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [0x3fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [0x3fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+824,((1U & (IData)((0x3ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))));
        bufp->chgBit(oldp+825,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [6U])));
        bufp->chgBit(oldp+826,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [6U] >> 1U))));
        bufp->chgBit(oldp+827,((1U & (~ (IData)((0x3ffffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 4U)))))));
        bufp->chgBit(oldp+828,((((~ (IData)((0x3ffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 4U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [6U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [6U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+829,((1U & (IData)((0x1ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))));
        bufp->chgBit(oldp+830,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [7U])));
        bufp->chgBit(oldp+831,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [7U] >> 1U))));
        bufp->chgBit(oldp+832,((1U & (~ (IData)((0x1ffffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 5U)))))));
        bufp->chgBit(oldp+833,((((~ (IData)((0x1ffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 5U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [7U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [7U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+834,((1U & (IData)((0xffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))));
        bufp->chgBit(oldp+835,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [8U])));
        bufp->chgBit(oldp+836,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [8U] >> 1U))));
        bufp->chgBit(oldp+837,((1U & (~ (IData)((0xffffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 6U)))))));
        bufp->chgBit(oldp+838,((((~ (IData)((0xffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [8U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [8U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+839,((1U & (IData)((0x7fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))));
        bufp->chgBit(oldp+840,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                [9U])));
        bufp->chgBit(oldp+841,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                      [9U] >> 1U))));
        bufp->chgBit(oldp+842,((1U & (~ (IData)((0x7fffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 7U)))))));
        bufp->chgBit(oldp+843,((((~ (IData)((0x7fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                        [9U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT__CarrySig
                                         [9U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+844,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 3U)))));
        bufp->chgBit(oldp+845,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 2U)))));
        bufp->chgCData(oldp+846,((7U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                                >> 3U)))),3);
        bufp->chgQData(oldp+847,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                  << 4U)),64);
        bufp->chgQData(oldp+849,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__OutX),64);
        bufp->chgBit(oldp+851,(((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x) 
                                | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx))));
        bufp->chgBit(oldp+852,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx));
        bufp->chgBit(oldp+853,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x));
        bufp->chgBit(oldp+854,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x));
        bufp->chgBit(oldp+855,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 4U)))));
        bufp->chgBit(oldp+856,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))));
        bufp->chgBit(oldp+857,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 4U))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                             << 4U)) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)))));
        bufp->chgBit(oldp+858,((1U & (IData)((0x3fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))));
        bufp->chgBit(oldp+859,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0xaU])));
        bufp->chgBit(oldp+860,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0xaU] >> 1U))));
        bufp->chgBit(oldp+861,((1U & (~ (IData)((0x3fffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 6U)))))));
        bufp->chgBit(oldp+862,((((~ (IData)((0x3fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 6U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0xaU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0xaU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+863,((1U & (IData)((0x1fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))));
        bufp->chgBit(oldp+864,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0xbU])));
        bufp->chgBit(oldp+865,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0xbU] >> 1U))));
        bufp->chgBit(oldp+866,((1U & (~ (IData)((0x1fffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 7U)))))));
        bufp->chgBit(oldp+867,((((~ (IData)((0x1fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 7U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0xbU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0xbU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+868,((1U & (IData)((0xfffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))));
        bufp->chgBit(oldp+869,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0xcU])));
        bufp->chgBit(oldp+870,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0xcU] >> 1U))));
        bufp->chgBit(oldp+871,((1U & (~ (IData)((0xfffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 8U)))))));
        bufp->chgBit(oldp+872,((((~ (IData)((0xfffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 8U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0xcU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0xcU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+873,((1U & (IData)((0x7ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))));
        bufp->chgBit(oldp+874,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0xdU])));
        bufp->chgBit(oldp+875,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0xdU] >> 1U))));
        bufp->chgBit(oldp+876,((1U & (~ (IData)((0x7ffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 9U)))))));
        bufp->chgBit(oldp+877,((((~ (IData)((0x7ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 9U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0xdU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0xdU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+878,((1U & (IData)((0x3ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))));
        bufp->chgBit(oldp+879,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0xeU])));
        bufp->chgBit(oldp+880,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0xeU] >> 1U))));
        bufp->chgBit(oldp+881,((1U & (~ (IData)((0x3ffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xaU)))))));
        bufp->chgBit(oldp+882,((((~ (IData)((0x3ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xaU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0xeU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0xeU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+883,((1U & (IData)((0x1ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))));
        bufp->chgBit(oldp+884,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0xfU])));
        bufp->chgBit(oldp+885,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0xfU] >> 1U))));
        bufp->chgBit(oldp+886,((1U & (~ (IData)((0x1ffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xbU)))))));
        bufp->chgBit(oldp+887,((((~ (IData)((0x1ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xbU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0xfU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0xfU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+888,((1U & (IData)((0xffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))));
        bufp->chgBit(oldp+889,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x10U])));
        bufp->chgBit(oldp+890,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x10U] >> 1U))));
        bufp->chgBit(oldp+891,((1U & (~ (IData)((0xffffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xcU)))))));
        bufp->chgBit(oldp+892,((((~ (IData)((0xffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xcU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x10U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x10U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+893,((1U & (IData)((0x7fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))));
        bufp->chgBit(oldp+894,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x11U])));
        bufp->chgBit(oldp+895,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x11U] >> 1U))));
        bufp->chgBit(oldp+896,((1U & (~ (IData)((0x7fffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xdU)))))));
        bufp->chgBit(oldp+897,((((~ (IData)((0x7fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xdU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x11U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x11U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+898,((1U & (IData)((0x3fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))));
        bufp->chgBit(oldp+899,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x12U])));
        bufp->chgBit(oldp+900,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x12U] >> 1U))));
        bufp->chgBit(oldp+901,((1U & (~ (IData)((0x3fffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xeU)))))));
        bufp->chgBit(oldp+902,((((~ (IData)((0x3fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xeU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x12U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x12U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+903,((1U & (IData)((0x1fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))));
        bufp->chgBit(oldp+904,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x13U])));
        bufp->chgBit(oldp+905,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x13U] >> 1U))));
        bufp->chgBit(oldp+906,((1U & (~ (IData)((0x1fffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0xfU)))))));
        bufp->chgBit(oldp+907,((((~ (IData)((0x1fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0xfU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x13U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x13U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+908,((1U & (IData)((0x7ffffffffffffff8ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))));
        bufp->chgBit(oldp+909,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [1U])));
        bufp->chgBit(oldp+910,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [1U] >> 1U))));
        bufp->chgBit(oldp+911,((1U & (~ (IData)((0x7ffffffffffffff8ULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 3U)))))));
        bufp->chgBit(oldp+912,((((~ (IData)((0x7ffffffffffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffffffff8ULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 3U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [1U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [1U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+913,((1U & (IData)((0xfffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))));
        bufp->chgBit(oldp+914,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x14U])));
        bufp->chgBit(oldp+915,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x14U] >> 1U))));
        bufp->chgBit(oldp+916,((1U & (~ (IData)((0xfffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x10U)))))));
        bufp->chgBit(oldp+917,((((~ (IData)((0xfffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x10U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x14U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x14U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+918,((1U & (IData)((0x7ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))));
        bufp->chgBit(oldp+919,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x15U])));
        bufp->chgBit(oldp+920,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x15U] >> 1U))));
        bufp->chgBit(oldp+921,((1U & (~ (IData)((0x7ffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x11U)))))));
        bufp->chgBit(oldp+922,((((~ (IData)((0x7ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x11U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x15U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x15U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+923,((1U & (IData)((0x3ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))));
        bufp->chgBit(oldp+924,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x16U])));
        bufp->chgBit(oldp+925,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x16U] >> 1U))));
        bufp->chgBit(oldp+926,((1U & (~ (IData)((0x3ffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x12U)))))));
        bufp->chgBit(oldp+927,((((~ (IData)((0x3ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x12U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x16U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x16U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+928,((1U & (IData)((0x1ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))));
        bufp->chgBit(oldp+929,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x17U])));
        bufp->chgBit(oldp+930,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x17U] >> 1U))));
        bufp->chgBit(oldp+931,((1U & (~ (IData)((0x1ffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x13U)))))));
        bufp->chgBit(oldp+932,((((~ (IData)((0x1ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x13U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x17U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x17U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+933,((1U & (IData)((0xffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))));
        bufp->chgBit(oldp+934,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x18U])));
        bufp->chgBit(oldp+935,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x18U] >> 1U))));
        bufp->chgBit(oldp+936,((1U & (~ (IData)((0xffffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x14U)))))));
        bufp->chgBit(oldp+937,((((~ (IData)((0xffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x14U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x18U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x18U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+938,((1U & (IData)((0x7fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))));
        bufp->chgBit(oldp+939,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x19U])));
        bufp->chgBit(oldp+940,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x19U] >> 1U))));
        bufp->chgBit(oldp+941,((1U & (~ (IData)((0x7fffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x15U)))))));
        bufp->chgBit(oldp+942,((((~ (IData)((0x7fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x15U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x19U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x19U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+943,((1U & (IData)((0x3fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))));
        bufp->chgBit(oldp+944,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x1aU])));
        bufp->chgBit(oldp+945,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x1aU] >> 1U))));
        bufp->chgBit(oldp+946,((1U & (~ (IData)((0x3fffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x16U)))))));
        bufp->chgBit(oldp+947,((((~ (IData)((0x3fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x16U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x1aU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x1aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+948,((1U & (IData)((0x1fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))));
        bufp->chgBit(oldp+949,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x1bU])));
        bufp->chgBit(oldp+950,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x1bU] >> 1U))));
        bufp->chgBit(oldp+951,((1U & (~ (IData)((0x1fffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x17U)))))));
        bufp->chgBit(oldp+952,((((~ (IData)((0x1fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x17U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x1bU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x1bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+953,((1U & (IData)((0xfffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))));
        bufp->chgBit(oldp+954,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x1cU])));
        bufp->chgBit(oldp+955,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x1cU] >> 1U))));
        bufp->chgBit(oldp+956,((1U & (~ (IData)((0xfffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x18U)))))));
        bufp->chgBit(oldp+957,((((~ (IData)((0xfffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xfffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x18U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x1cU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x1cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+958,((1U & (IData)((0x7ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))));
        bufp->chgBit(oldp+959,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x1dU])));
        bufp->chgBit(oldp+960,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x1dU] >> 1U))));
        bufp->chgBit(oldp+961,((1U & (~ (IData)((0x7ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x19U)))))));
        bufp->chgBit(oldp+962,((((~ (IData)((0x7ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x19U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x1dU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x1dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+963,((1U & (IData)((0x3ffffffffffffffcULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))));
        bufp->chgBit(oldp+964,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [2U])));
        bufp->chgBit(oldp+965,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [2U] >> 1U))));
        bufp->chgBit(oldp+966,((1U & (~ (IData)((0x3ffffffffffffffcULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    << 2U)))))));
        bufp->chgBit(oldp+967,((((~ (IData)((0x3ffffffffffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffffffffcULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                << 2U))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [2U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [2U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+968,((1U & (IData)((0x3ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))));
        bufp->chgBit(oldp+969,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x1eU])));
        bufp->chgBit(oldp+970,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x1eU] >> 1U))));
        bufp->chgBit(oldp+971,((1U & (~ (IData)((0x3ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1aU)))))));
        bufp->chgBit(oldp+972,((((~ (IData)((0x3ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1aU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x1eU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x1eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+973,((1U & (IData)((0x1ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))));
        bufp->chgBit(oldp+974,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x1fU])));
        bufp->chgBit(oldp+975,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x1fU] >> 1U))));
        bufp->chgBit(oldp+976,((1U & (~ (IData)((0x1ffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1bU)))))));
        bufp->chgBit(oldp+977,((((~ (IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1ffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1bU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x1fU] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x1fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+978,((1U & (IData)((0xffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))));
        bufp->chgBit(oldp+979,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x20U])));
        bufp->chgBit(oldp+980,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x20U] >> 1U))));
        bufp->chgBit(oldp+981,((1U & (~ (IData)((0xffffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1cU)))))));
        bufp->chgBit(oldp+982,((((~ (IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0xffffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1cU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x20U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x20U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+983,((1U & (IData)((0x7fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))));
        bufp->chgBit(oldp+984,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x21U])));
        bufp->chgBit(oldp+985,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x21U] >> 1U))));
        bufp->chgBit(oldp+986,((1U & (~ (IData)((0x7fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1dU)))))));
        bufp->chgBit(oldp+987,((((~ (IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x7fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1dU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x21U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x21U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+988,((1U & (IData)((0x3fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))));
        bufp->chgBit(oldp+989,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x22U])));
        bufp->chgBit(oldp+990,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x22U] >> 1U))));
        bufp->chgBit(oldp+991,((1U & (~ (IData)((0x3fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1eU)))))));
        bufp->chgBit(oldp+992,((((~ (IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x3fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1eU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x22U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x22U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+993,((1U & (IData)((0x1fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))));
        bufp->chgBit(oldp+994,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x23U])));
        bufp->chgBit(oldp+995,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                      [0x23U] >> 1U))));
        bufp->chgBit(oldp+996,((1U & (~ (IData)((0x1fffffffULL 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                    >> 0x1fU)))))));
        bufp->chgBit(oldp+997,((((~ (IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1fU)))) 
                                 & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                | (((IData)((0x1fffffffULL 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                >> 0x1fU))) 
                                    & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                   | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                        [0x23U] >> 1U) 
                                       & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                      | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x23U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+998,((1U & (IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))));
        bufp->chgBit(oldp+999,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                [0x24U])));
        bufp->chgBit(oldp+1000,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x24U] >> 1U))));
        bufp->chgBit(oldp+1001,((1U & (~ (IData)((0xfffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x20U)))))));
        bufp->chgBit(oldp+1002,((((~ (IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x24U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x24U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1003,((1U & (IData)((0x7ffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U))))));
        bufp->chgBit(oldp+1004,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x25U])));
        bufp->chgBit(oldp+1005,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x25U] >> 1U))));
        bufp->chgBit(oldp+1006,((1U & (~ (IData)((0x7ffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x21U)))))));
        bufp->chgBit(oldp+1007,((((~ (IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x25U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x25U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1008,((1U & (IData)((0x3ffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U))))));
        bufp->chgBit(oldp+1009,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x26U])));
        bufp->chgBit(oldp+1010,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x26U] >> 1U))));
        bufp->chgBit(oldp+1011,((1U & (~ (IData)((0x3ffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x22U)))))));
        bufp->chgBit(oldp+1012,((((~ (IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x26U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x26U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1013,((1U & (IData)((0x1ffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U))))));
        bufp->chgBit(oldp+1014,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x27U])));
        bufp->chgBit(oldp+1015,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x27U] >> 1U))));
        bufp->chgBit(oldp+1016,((1U & (~ (IData)((0x1ffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x23U)))))));
        bufp->chgBit(oldp+1017,((((~ (IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x27U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x27U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1018,((1U & (IData)((0x1ffffffffffffffeULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U))))));
        bufp->chgBit(oldp+1019,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [3U])));
        bufp->chgBit(oldp+1020,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [3U] >> 1U))));
        bufp->chgBit(oldp+1021,((1U & (~ (IData)((0x1ffffffffffffffeULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     << 1U)))))));
        bufp->chgBit(oldp+1022,((((~ (IData)((0x1ffffffffffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [3U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [3U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1023,((1U & (IData)((0xffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U))))));
        bufp->chgBit(oldp+1024,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x28U])));
        bufp->chgBit(oldp+1025,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x28U] >> 1U))));
        bufp->chgBit(oldp+1026,((1U & (~ (IData)((0xffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x24U)))))));
        bufp->chgBit(oldp+1027,((((~ (IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x28U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x28U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1028,((1U & (IData)((0x7fffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U))))));
        bufp->chgBit(oldp+1029,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x29U])));
        bufp->chgBit(oldp+1030,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x29U] >> 1U))));
        bufp->chgBit(oldp+1031,((1U & (~ (IData)((0x7fffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x25U)))))));
        bufp->chgBit(oldp+1032,((((~ (IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x25U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x25U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x29U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x29U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1033,((1U & (IData)((0x3fffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x26U))))));
        bufp->chgBit(oldp+1034,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x2aU])));
        bufp->chgBit(oldp+1035,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x2aU] >> 1U))));
        bufp->chgBit(oldp+1036,((1U & (~ (IData)((0x3fffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x26U)))))));
        bufp->chgBit(oldp+1037,((((~ (IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x26U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x26U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x2aU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x2aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1038,((1U & (IData)((0x1fffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x27U))))));
        bufp->chgBit(oldp+1039,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x2bU])));
        bufp->chgBit(oldp+1040,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x2bU] >> 1U))));
        bufp->chgBit(oldp+1041,((1U & (~ (IData)((0x1fffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x27U)))))));
        bufp->chgBit(oldp+1042,((((~ (IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x27U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x27U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x2bU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x2bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1043,((1U & (IData)((0xfffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x28U))))));
        bufp->chgBit(oldp+1044,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x2cU])));
        bufp->chgBit(oldp+1045,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x2cU] >> 1U))));
        bufp->chgBit(oldp+1046,((1U & (~ (IData)((0xfffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x28U)))))));
        bufp->chgBit(oldp+1047,((((~ (IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x28U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x28U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x2cU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x2cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1048,((1U & (IData)((0x7ffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x29U))))));
        bufp->chgBit(oldp+1049,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x2dU])));
        bufp->chgBit(oldp+1050,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x2dU] >> 1U))));
        bufp->chgBit(oldp+1051,((1U & (~ (IData)((0x7ffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x29U)))))));
        bufp->chgBit(oldp+1052,((((~ (IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x29U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x29U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x2dU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x2dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1053,((1U & (IData)((0x3ffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2aU))))));
        bufp->chgBit(oldp+1054,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x2eU])));
        bufp->chgBit(oldp+1055,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x2eU] >> 1U))));
        bufp->chgBit(oldp+1056,((1U & (~ (IData)((0x3ffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2aU)))))));
        bufp->chgBit(oldp+1057,((((~ (IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2aU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2aU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x2eU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x2eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1058,((1U & (IData)((0x1ffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2bU))))));
        bufp->chgBit(oldp+1059,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x2fU])));
        bufp->chgBit(oldp+1060,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x2fU] >> 1U))));
        bufp->chgBit(oldp+1061,((1U & (~ (IData)((0x1ffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2bU)))))));
        bufp->chgBit(oldp+1062,((((~ (IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2bU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2bU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x2fU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x2fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1063,((1U & (IData)((0xffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2cU))))));
        bufp->chgBit(oldp+1064,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x30U])));
        bufp->chgBit(oldp+1065,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x30U] >> 1U))));
        bufp->chgBit(oldp+1066,((1U & (~ (IData)((0xffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2cU)))))));
        bufp->chgBit(oldp+1067,((((~ (IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2cU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2cU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x30U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x30U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1068,((1U & (IData)((0x7fffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2dU))))));
        bufp->chgBit(oldp+1069,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x31U])));
        bufp->chgBit(oldp+1070,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x31U] >> 1U))));
        bufp->chgBit(oldp+1071,((1U & (~ (IData)((0x7fffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2dU)))))));
        bufp->chgBit(oldp+1072,((((~ (IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2dU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2dU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x31U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x31U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1073,((1U & (IData)((0xfffffffffffffffULL 
                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)))));
        bufp->chgBit(oldp+1074,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [4U])));
        bufp->chgBit(oldp+1075,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [4U] >> 1U))));
        bufp->chgBit(oldp+1076,((1U & (~ (IData)((0xfffffffffffffffULL 
                                                  & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))))));
        bufp->chgBit(oldp+1077,((((~ (IData)((0xfffffffffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [4U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [4U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1078,((1U & (IData)((0x3fffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2eU))))));
        bufp->chgBit(oldp+1079,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x32U])));
        bufp->chgBit(oldp+1080,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x32U] >> 1U))));
        bufp->chgBit(oldp+1081,((1U & (~ (IData)((0x3fffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2eU)))))));
        bufp->chgBit(oldp+1082,((((~ (IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2eU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2eU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x32U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x32U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1083,((1U & (IData)((0x1fffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2fU))))));
        bufp->chgBit(oldp+1084,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x33U])));
        bufp->chgBit(oldp+1085,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x33U] >> 1U))));
        bufp->chgBit(oldp+1086,((1U & (~ (IData)((0x1fffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2fU)))))));
        bufp->chgBit(oldp+1087,((((~ (IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2fU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2fU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x33U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x33U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1088,((1U & (IData)((0xfffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x30U))))));
        bufp->chgBit(oldp+1089,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x34U])));
        bufp->chgBit(oldp+1090,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x34U] >> 1U))));
        bufp->chgBit(oldp+1091,((1U & (~ (IData)((0xfffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x30U)))))));
        bufp->chgBit(oldp+1092,((((~ (IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x30U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x30U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x34U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x34U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1093,((1U & (IData)((0x7ffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x31U))))));
        bufp->chgBit(oldp+1094,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x35U])));
        bufp->chgBit(oldp+1095,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x35U] >> 1U))));
        bufp->chgBit(oldp+1096,((1U & (~ (IData)((0x7ffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x31U)))))));
        bufp->chgBit(oldp+1097,((((~ (IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x31U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x31U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x35U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x35U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1098,((1U & (IData)((0x3ffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x32U))))));
        bufp->chgBit(oldp+1099,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x36U])));
        bufp->chgBit(oldp+1100,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x36U] >> 1U))));
        bufp->chgBit(oldp+1101,((1U & (~ (IData)((0x3ffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x32U)))))));
        bufp->chgBit(oldp+1102,((((~ (IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x32U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x32U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x36U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x36U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1103,((1U & (IData)((0x1ffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x33U))))));
        bufp->chgBit(oldp+1104,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x37U])));
        bufp->chgBit(oldp+1105,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x37U] >> 1U))));
        bufp->chgBit(oldp+1106,((1U & (~ (IData)((0x1ffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x33U)))))));
        bufp->chgBit(oldp+1107,((((~ (IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x33U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x33U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x37U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x37U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1108,((1U & (IData)((0xffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x34U))))));
        bufp->chgBit(oldp+1109,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x38U])));
        bufp->chgBit(oldp+1110,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x38U] >> 1U))));
        bufp->chgBit(oldp+1111,((1U & (~ (IData)((0xffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x34U)))))));
        bufp->chgBit(oldp+1112,((((~ (IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x34U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x34U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x38U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x38U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1113,((1U & (IData)((0x7fULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x35U))))));
        bufp->chgBit(oldp+1114,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x39U])));
        bufp->chgBit(oldp+1115,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x39U] >> 1U))));
        bufp->chgBit(oldp+1116,((1U & (~ (IData)((0x7fULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x35U)))))));
        bufp->chgBit(oldp+1117,((((~ (IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x35U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x35U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x39U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x39U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1118,((1U & (IData)((0x3fULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x36U))))));
        bufp->chgBit(oldp+1119,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x3aU])));
        bufp->chgBit(oldp+1120,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x3aU] >> 1U))));
        bufp->chgBit(oldp+1121,((1U & (~ (IData)((0x3fULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x36U)))))));
        bufp->chgBit(oldp+1122,((((~ (IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x36U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x36U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x3aU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x3aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1123,((1U & (IData)((0x1fULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x37U))))));
        bufp->chgBit(oldp+1124,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x3bU])));
        bufp->chgBit(oldp+1125,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x3bU] >> 1U))));
        bufp->chgBit(oldp+1126,((1U & (~ (IData)((0x1fULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x37U)))))));
        bufp->chgBit(oldp+1127,((((~ (IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x37U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x37U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x3bU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x3bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1128,((1U & (IData)((0x7ffffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U))))));
        bufp->chgBit(oldp+1129,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [5U])));
        bufp->chgBit(oldp+1130,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [5U] >> 1U))));
        bufp->chgBit(oldp+1131,((1U & (~ (IData)((0x7ffffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 1U)))))));
        bufp->chgBit(oldp+1132,((((~ (IData)((0x7ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [5U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [5U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1133,((1U & (IData)((0xfULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x38U))))));
        bufp->chgBit(oldp+1134,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x3cU])));
        bufp->chgBit(oldp+1135,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x3cU] >> 1U))));
        bufp->chgBit(oldp+1136,((1U & (~ (IData)((0xfULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x38U)))))));
        bufp->chgBit(oldp+1137,((((~ (IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x38U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x38U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x3cU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x3cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1138,((1U & (IData)((7ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x39U))))));
        bufp->chgBit(oldp+1139,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x3dU])));
        bufp->chgBit(oldp+1140,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x3dU] >> 1U))));
        bufp->chgBit(oldp+1141,((1U & (~ (IData)((7ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x39U)))))));
        bufp->chgBit(oldp+1142,((((~ (IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x39U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x39U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x3dU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x3dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1143,((1U & (IData)((3ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3aU))))));
        bufp->chgBit(oldp+1144,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x3eU])));
        bufp->chgBit(oldp+1145,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x3eU] >> 1U))));
        bufp->chgBit(oldp+1146,((1U & (~ (IData)((3ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x3aU)))))));
        bufp->chgBit(oldp+1147,((((~ (IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3aU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3aU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x3eU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x3eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1148,((1U & (IData)((1ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3bU))))));
        bufp->chgBit(oldp+1149,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [0x3fU])));
        bufp->chgBit(oldp+1150,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [0x3fU] >> 1U))));
        bufp->chgBit(oldp+1151,((1U & (~ (IData)((1ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x3bU)))))));
        bufp->chgBit(oldp+1152,((((~ (IData)((1ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3bU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | ((IData)(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x3bU) 
                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x))) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [0x3fU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [0x3fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1153,((1U & (IData)((0x3ffffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))));
        bufp->chgBit(oldp+1154,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [6U])));
        bufp->chgBit(oldp+1155,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [6U] >> 1U))));
        bufp->chgBit(oldp+1156,((1U & (~ (IData)((0x3ffffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 2U)))))));
        bufp->chgBit(oldp+1157,((((~ (IData)((0x3ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [6U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [6U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1158,((1U & (IData)((0x1ffffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))));
        bufp->chgBit(oldp+1159,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [7U])));
        bufp->chgBit(oldp+1160,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [7U] >> 1U))));
        bufp->chgBit(oldp+1161,((1U & (~ (IData)((0x1ffffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 3U)))))));
        bufp->chgBit(oldp+1162,((((~ (IData)((0x1ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [7U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [7U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1163,((1U & (IData)((0xffffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))));
        bufp->chgBit(oldp+1164,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [8U])));
        bufp->chgBit(oldp+1165,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [8U] >> 1U))));
        bufp->chgBit(oldp+1166,((1U & (~ (IData)((0xffffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 4U)))))));
        bufp->chgBit(oldp+1167,((((~ (IData)((0xffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [8U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [8U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1168,((1U & (IData)((0x7fffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))));
        bufp->chgBit(oldp+1169,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                 [9U])));
        bufp->chgBit(oldp+1170,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                       [9U] >> 1U))));
        bufp->chgBit(oldp+1171,((1U & (~ (IData)((0x7fffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 5U)))))));
        bufp->chgBit(oldp+1172,((((~ (IData)((0x7fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                         [9U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT__CarrySig
                                          [9U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__4__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1173,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 5U)))));
        bufp->chgBit(oldp+1174,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 4U)))));
        bufp->chgCData(oldp+1175,((7U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                                 >> 5U)))),3);
        bufp->chgQData(oldp+1176,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                   << 6U)),64);
        bufp->chgQData(oldp+1178,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__OutX),64);
        bufp->chgBit(oldp+1180,(((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x) 
                                 | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx))));
        bufp->chgBit(oldp+1181,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx));
        bufp->chgBit(oldp+1182,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x));
        bufp->chgBit(oldp+1183,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x));
        bufp->chgBit(oldp+1184,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 6U)))));
        bufp->chgBit(oldp+1185,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U))))));
        bufp->chgBit(oldp+1186,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 6U))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 6U)) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)))));
        bufp->chgBit(oldp+1187,((1U & (IData)((0x3fffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))));
        bufp->chgBit(oldp+1188,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0xaU])));
        bufp->chgBit(oldp+1189,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0xaU] >> 1U))));
        bufp->chgBit(oldp+1190,((1U & (~ (IData)((0x3fffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 4U)))))));
        bufp->chgBit(oldp+1191,((((~ (IData)((0x3fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0xaU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0xaU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1192,((1U & (IData)((0x1fffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))));
        bufp->chgBit(oldp+1193,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0xbU])));
        bufp->chgBit(oldp+1194,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0xbU] >> 1U))));
        bufp->chgBit(oldp+1195,((1U & (~ (IData)((0x1fffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 5U)))))));
        bufp->chgBit(oldp+1196,((((~ (IData)((0x1fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0xbU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0xbU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1197,((1U & (IData)((0xfffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U))))));
        bufp->chgBit(oldp+1198,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0xcU])));
        bufp->chgBit(oldp+1199,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0xcU] >> 1U))));
        bufp->chgBit(oldp+1200,((1U & (~ (IData)((0xfffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 6U)))))));
        bufp->chgBit(oldp+1201,((((~ (IData)((0xfffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0xcU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0xcU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1202,((1U & (IData)((0x7ffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U))))));
        bufp->chgBit(oldp+1203,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0xdU])));
        bufp->chgBit(oldp+1204,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0xdU] >> 1U))));
        bufp->chgBit(oldp+1205,((1U & (~ (IData)((0x7ffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 7U)))))));
        bufp->chgBit(oldp+1206,((((~ (IData)((0x7ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0xdU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0xdU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1207,((1U & (IData)((0x3ffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U))))));
        bufp->chgBit(oldp+1208,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0xeU])));
        bufp->chgBit(oldp+1209,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0xeU] >> 1U))));
        bufp->chgBit(oldp+1210,((1U & (~ (IData)((0x3ffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 8U)))))));
        bufp->chgBit(oldp+1211,((((~ (IData)((0x3ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0xeU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0xeU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1212,((1U & (IData)((0x1ffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U))))));
        bufp->chgBit(oldp+1213,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0xfU])));
        bufp->chgBit(oldp+1214,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0xfU] >> 1U))));
        bufp->chgBit(oldp+1215,((1U & (~ (IData)((0x1ffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 9U)))))));
        bufp->chgBit(oldp+1216,((((~ (IData)((0x1ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0xfU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0xfU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1217,((1U & (IData)((0xffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU))))));
        bufp->chgBit(oldp+1218,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x10U])));
        bufp->chgBit(oldp+1219,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x10U] >> 1U))));
        bufp->chgBit(oldp+1220,((1U & (~ (IData)((0xffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xaU)))))));
        bufp->chgBit(oldp+1221,((((~ (IData)((0xffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x10U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x10U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1222,((1U & (IData)((0x7fffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU))))));
        bufp->chgBit(oldp+1223,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x11U])));
        bufp->chgBit(oldp+1224,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x11U] >> 1U))));
        bufp->chgBit(oldp+1225,((1U & (~ (IData)((0x7fffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xbU)))))));
        bufp->chgBit(oldp+1226,((((~ (IData)((0x7fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x11U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x11U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1227,((1U & (IData)((0x3fffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU))))));
        bufp->chgBit(oldp+1228,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x12U])));
        bufp->chgBit(oldp+1229,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x12U] >> 1U))));
        bufp->chgBit(oldp+1230,((1U & (~ (IData)((0x3fffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xcU)))))));
        bufp->chgBit(oldp+1231,((((~ (IData)((0x3fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x12U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x12U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1232,((1U & (IData)((0x1fffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU))))));
        bufp->chgBit(oldp+1233,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x13U])));
        bufp->chgBit(oldp+1234,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x13U] >> 1U))));
        bufp->chgBit(oldp+1235,((1U & (~ (IData)((0x1fffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xdU)))))));
        bufp->chgBit(oldp+1236,((((~ (IData)((0x1fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x13U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x13U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1237,((1U & (IData)((0x7fffffffffffffe0ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U))))));
        bufp->chgBit(oldp+1238,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [1U])));
        bufp->chgBit(oldp+1239,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [1U] >> 1U))));
        bufp->chgBit(oldp+1240,((1U & (~ (IData)((0x7fffffffffffffe0ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     << 5U)))))));
        bufp->chgBit(oldp+1241,((((~ (IData)((0x7fffffffffffffe0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffffffe0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [1U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [1U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1242,((1U & (IData)((0xfffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU))))));
        bufp->chgBit(oldp+1243,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x14U])));
        bufp->chgBit(oldp+1244,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x14U] >> 1U))));
        bufp->chgBit(oldp+1245,((1U & (~ (IData)((0xfffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xeU)))))));
        bufp->chgBit(oldp+1246,((((~ (IData)((0xfffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x14U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x14U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1247,((1U & (IData)((0x7ffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU))))));
        bufp->chgBit(oldp+1248,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x15U])));
        bufp->chgBit(oldp+1249,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x15U] >> 1U))));
        bufp->chgBit(oldp+1250,((1U & (~ (IData)((0x7ffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xfU)))))));
        bufp->chgBit(oldp+1251,((((~ (IData)((0x7ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x15U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x15U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1252,((1U & (IData)((0x3ffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U))))));
        bufp->chgBit(oldp+1253,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x16U])));
        bufp->chgBit(oldp+1254,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x16U] >> 1U))));
        bufp->chgBit(oldp+1255,((1U & (~ (IData)((0x3ffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x10U)))))));
        bufp->chgBit(oldp+1256,((((~ (IData)((0x3ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x16U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x16U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1257,((1U & (IData)((0x1ffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U))))));
        bufp->chgBit(oldp+1258,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x17U])));
        bufp->chgBit(oldp+1259,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x17U] >> 1U))));
        bufp->chgBit(oldp+1260,((1U & (~ (IData)((0x1ffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x11U)))))));
        bufp->chgBit(oldp+1261,((((~ (IData)((0x1ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x17U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x17U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1262,((1U & (IData)((0xffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U))))));
        bufp->chgBit(oldp+1263,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x18U])));
        bufp->chgBit(oldp+1264,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x18U] >> 1U))));
        bufp->chgBit(oldp+1265,((1U & (~ (IData)((0xffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x12U)))))));
        bufp->chgBit(oldp+1266,((((~ (IData)((0xffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x18U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x18U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1267,((1U & (IData)((0x7fffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U))))));
        bufp->chgBit(oldp+1268,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x19U])));
        bufp->chgBit(oldp+1269,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x19U] >> 1U))));
        bufp->chgBit(oldp+1270,((1U & (~ (IData)((0x7fffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x13U)))))));
        bufp->chgBit(oldp+1271,((((~ (IData)((0x7fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x19U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x19U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1272,((1U & (IData)((0x3fffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U))))));
        bufp->chgBit(oldp+1273,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x1aU])));
        bufp->chgBit(oldp+1274,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x1aU] >> 1U))));
        bufp->chgBit(oldp+1275,((1U & (~ (IData)((0x3fffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x14U)))))));
        bufp->chgBit(oldp+1276,((((~ (IData)((0x3fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x1aU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x1aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1277,((1U & (IData)((0x1fffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U))))));
        bufp->chgBit(oldp+1278,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x1bU])));
        bufp->chgBit(oldp+1279,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x1bU] >> 1U))));
        bufp->chgBit(oldp+1280,((1U & (~ (IData)((0x1fffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x15U)))))));
        bufp->chgBit(oldp+1281,((((~ (IData)((0x1fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x1bU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x1bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1282,((1U & (IData)((0xfffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U))))));
        bufp->chgBit(oldp+1283,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x1cU])));
        bufp->chgBit(oldp+1284,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x1cU] >> 1U))));
        bufp->chgBit(oldp+1285,((1U & (~ (IData)((0xfffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x16U)))))));
        bufp->chgBit(oldp+1286,((((~ (IData)((0xfffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x1cU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x1cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1287,((1U & (IData)((0x7ffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U))))));
        bufp->chgBit(oldp+1288,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x1dU])));
        bufp->chgBit(oldp+1289,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x1dU] >> 1U))));
        bufp->chgBit(oldp+1290,((1U & (~ (IData)((0x7ffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x17U)))))));
        bufp->chgBit(oldp+1291,((((~ (IData)((0x7ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x1dU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x1dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1292,((1U & (IData)((0x3ffffffffffffff0ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U))))));
        bufp->chgBit(oldp+1293,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [2U])));
        bufp->chgBit(oldp+1294,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [2U] >> 1U))));
        bufp->chgBit(oldp+1295,((1U & (~ (IData)((0x3ffffffffffffff0ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     << 4U)))))));
        bufp->chgBit(oldp+1296,((((~ (IData)((0x3ffffffffffffff0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffffffff0ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [2U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [2U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1297,((1U & (IData)((0x3ffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U))))));
        bufp->chgBit(oldp+1298,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x1eU])));
        bufp->chgBit(oldp+1299,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x1eU] >> 1U))));
        bufp->chgBit(oldp+1300,((1U & (~ (IData)((0x3ffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x18U)))))));
        bufp->chgBit(oldp+1301,((((~ (IData)((0x3ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x1eU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x1eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1302,((1U & (IData)((0x1ffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U))))));
        bufp->chgBit(oldp+1303,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x1fU])));
        bufp->chgBit(oldp+1304,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x1fU] >> 1U))));
        bufp->chgBit(oldp+1305,((1U & (~ (IData)((0x1ffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x19U)))))));
        bufp->chgBit(oldp+1306,((((~ (IData)((0x1ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x1fU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x1fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1307,((1U & (IData)((0xffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU))))));
        bufp->chgBit(oldp+1308,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x20U])));
        bufp->chgBit(oldp+1309,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x20U] >> 1U))));
        bufp->chgBit(oldp+1310,((1U & (~ (IData)((0xffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x1aU)))))));
        bufp->chgBit(oldp+1311,((((~ (IData)((0xffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x20U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x20U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1312,((1U & (IData)((0x7fffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU))))));
        bufp->chgBit(oldp+1313,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x21U])));
        bufp->chgBit(oldp+1314,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x21U] >> 1U))));
        bufp->chgBit(oldp+1315,((1U & (~ (IData)((0x7fffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x1bU)))))));
        bufp->chgBit(oldp+1316,((((~ (IData)((0x7fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x21U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x21U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1317,((1U & (IData)((0x3fffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU))))));
        bufp->chgBit(oldp+1318,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x22U])));
        bufp->chgBit(oldp+1319,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x22U] >> 1U))));
        bufp->chgBit(oldp+1320,((1U & (~ (IData)((0x3fffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x1cU)))))));
        bufp->chgBit(oldp+1321,((((~ (IData)((0x3fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x22U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x22U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1322,((1U & (IData)((0x1fffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU))))));
        bufp->chgBit(oldp+1323,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x23U])));
        bufp->chgBit(oldp+1324,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x23U] >> 1U))));
        bufp->chgBit(oldp+1325,((1U & (~ (IData)((0x1fffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x1dU)))))));
        bufp->chgBit(oldp+1326,((((~ (IData)((0x1fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x23U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x23U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1327,((1U & (IData)((0xfffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU))))));
        bufp->chgBit(oldp+1328,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x24U])));
        bufp->chgBit(oldp+1329,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x24U] >> 1U))));
        bufp->chgBit(oldp+1330,((1U & (~ (IData)((0xfffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x1eU)))))));
        bufp->chgBit(oldp+1331,((((~ (IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x24U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x24U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1332,((1U & (IData)((0x7ffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU))))));
        bufp->chgBit(oldp+1333,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x25U])));
        bufp->chgBit(oldp+1334,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x25U] >> 1U))));
        bufp->chgBit(oldp+1335,((1U & (~ (IData)((0x7ffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x1fU)))))));
        bufp->chgBit(oldp+1336,((((~ (IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x25U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x25U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1337,((1U & (IData)((0x3ffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U))))));
        bufp->chgBit(oldp+1338,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x26U])));
        bufp->chgBit(oldp+1339,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x26U] >> 1U))));
        bufp->chgBit(oldp+1340,((1U & (~ (IData)((0x3ffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x20U)))))));
        bufp->chgBit(oldp+1341,((((~ (IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x26U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x26U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1342,((1U & (IData)((0x1ffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U))))));
        bufp->chgBit(oldp+1343,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x27U])));
        bufp->chgBit(oldp+1344,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x27U] >> 1U))));
        bufp->chgBit(oldp+1345,((1U & (~ (IData)((0x1ffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x21U)))))));
        bufp->chgBit(oldp+1346,((((~ (IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x27U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x27U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1347,((1U & (IData)((0x1ffffffffffffff8ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U))))));
        bufp->chgBit(oldp+1348,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [3U])));
        bufp->chgBit(oldp+1349,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [3U] >> 1U))));
        bufp->chgBit(oldp+1350,((1U & (~ (IData)((0x1ffffffffffffff8ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     << 3U)))))));
        bufp->chgBit(oldp+1351,((((~ (IData)((0x1ffffffffffffff8ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffffff8ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [3U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [3U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1352,((1U & (IData)((0xffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U))))));
        bufp->chgBit(oldp+1353,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x28U])));
        bufp->chgBit(oldp+1354,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x28U] >> 1U))));
        bufp->chgBit(oldp+1355,((1U & (~ (IData)((0xffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x22U)))))));
        bufp->chgBit(oldp+1356,((((~ (IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x28U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x28U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1357,((1U & (IData)((0x7fffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U))))));
        bufp->chgBit(oldp+1358,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x29U])));
        bufp->chgBit(oldp+1359,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x29U] >> 1U))));
        bufp->chgBit(oldp+1360,((1U & (~ (IData)((0x7fffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x23U)))))));
        bufp->chgBit(oldp+1361,((((~ (IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x29U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x29U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1362,((1U & (IData)((0x3fffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U))))));
        bufp->chgBit(oldp+1363,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x2aU])));
        bufp->chgBit(oldp+1364,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x2aU] >> 1U))));
        bufp->chgBit(oldp+1365,((1U & (~ (IData)((0x3fffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x24U)))))));
        bufp->chgBit(oldp+1366,((((~ (IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x2aU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x2aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1367,((1U & (IData)((0x1fffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U))))));
        bufp->chgBit(oldp+1368,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x2bU])));
        bufp->chgBit(oldp+1369,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x2bU] >> 1U))));
        bufp->chgBit(oldp+1370,((1U & (~ (IData)((0x1fffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x25U)))))));
        bufp->chgBit(oldp+1371,((((~ (IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x25U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x25U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x2bU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x2bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1372,((1U & (IData)((0xfffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x26U))))));
        bufp->chgBit(oldp+1373,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x2cU])));
        bufp->chgBit(oldp+1374,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x2cU] >> 1U))));
        bufp->chgBit(oldp+1375,((1U & (~ (IData)((0xfffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x26U)))))));
        bufp->chgBit(oldp+1376,((((~ (IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x26U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x26U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x2cU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x2cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1377,((1U & (IData)((0x7ffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x27U))))));
        bufp->chgBit(oldp+1378,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x2dU])));
        bufp->chgBit(oldp+1379,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x2dU] >> 1U))));
        bufp->chgBit(oldp+1380,((1U & (~ (IData)((0x7ffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x27U)))))));
        bufp->chgBit(oldp+1381,((((~ (IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x27U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x27U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x2dU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x2dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1382,((1U & (IData)((0x3ffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x28U))))));
        bufp->chgBit(oldp+1383,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x2eU])));
        bufp->chgBit(oldp+1384,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x2eU] >> 1U))));
        bufp->chgBit(oldp+1385,((1U & (~ (IData)((0x3ffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x28U)))))));
        bufp->chgBit(oldp+1386,((((~ (IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x28U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x28U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x2eU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x2eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1387,((1U & (IData)((0x1ffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x29U))))));
        bufp->chgBit(oldp+1388,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x2fU])));
        bufp->chgBit(oldp+1389,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x2fU] >> 1U))));
        bufp->chgBit(oldp+1390,((1U & (~ (IData)((0x1ffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x29U)))))));
        bufp->chgBit(oldp+1391,((((~ (IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x29U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x29U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x2fU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x2fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1392,((1U & (IData)((0xffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2aU))))));
        bufp->chgBit(oldp+1393,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x30U])));
        bufp->chgBit(oldp+1394,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x30U] >> 1U))));
        bufp->chgBit(oldp+1395,((1U & (~ (IData)((0xffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2aU)))))));
        bufp->chgBit(oldp+1396,((((~ (IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2aU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2aU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x30U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x30U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1397,((1U & (IData)((0x7fffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2bU))))));
        bufp->chgBit(oldp+1398,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x31U])));
        bufp->chgBit(oldp+1399,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x31U] >> 1U))));
        bufp->chgBit(oldp+1400,((1U & (~ (IData)((0x7fffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2bU)))))));
        bufp->chgBit(oldp+1401,((((~ (IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2bU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2bU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x31U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x31U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1402,((1U & (IData)((0xffffffffffffffcULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U))))));
        bufp->chgBit(oldp+1403,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [4U])));
        bufp->chgBit(oldp+1404,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [4U] >> 1U))));
        bufp->chgBit(oldp+1405,((1U & (~ (IData)((0xffffffffffffffcULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     << 2U)))))));
        bufp->chgBit(oldp+1406,((((~ (IData)((0xffffffffffffffcULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffffffffcULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [4U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [4U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1407,((1U & (IData)((0x3fffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2cU))))));
        bufp->chgBit(oldp+1408,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x32U])));
        bufp->chgBit(oldp+1409,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x32U] >> 1U))));
        bufp->chgBit(oldp+1410,((1U & (~ (IData)((0x3fffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2cU)))))));
        bufp->chgBit(oldp+1411,((((~ (IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2cU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2cU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x32U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x32U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1412,((1U & (IData)((0x1fffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2dU))))));
        bufp->chgBit(oldp+1413,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x33U])));
        bufp->chgBit(oldp+1414,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x33U] >> 1U))));
        bufp->chgBit(oldp+1415,((1U & (~ (IData)((0x1fffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2dU)))))));
        bufp->chgBit(oldp+1416,((((~ (IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2dU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2dU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x33U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x33U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1417,((1U & (IData)((0xfffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2eU))))));
        bufp->chgBit(oldp+1418,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x34U])));
        bufp->chgBit(oldp+1419,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x34U] >> 1U))));
        bufp->chgBit(oldp+1420,((1U & (~ (IData)((0xfffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2eU)))))));
        bufp->chgBit(oldp+1421,((((~ (IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2eU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2eU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x34U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x34U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1422,((1U & (IData)((0x7ffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2fU))))));
        bufp->chgBit(oldp+1423,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x35U])));
        bufp->chgBit(oldp+1424,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x35U] >> 1U))));
        bufp->chgBit(oldp+1425,((1U & (~ (IData)((0x7ffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x2fU)))))));
        bufp->chgBit(oldp+1426,((((~ (IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2fU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2fU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x35U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x35U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1427,((1U & (IData)((0x3ffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x30U))))));
        bufp->chgBit(oldp+1428,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x36U])));
        bufp->chgBit(oldp+1429,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x36U] >> 1U))));
        bufp->chgBit(oldp+1430,((1U & (~ (IData)((0x3ffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x30U)))))));
        bufp->chgBit(oldp+1431,((((~ (IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x30U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x30U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x36U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x36U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1432,((1U & (IData)((0x1ffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x31U))))));
        bufp->chgBit(oldp+1433,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x37U])));
        bufp->chgBit(oldp+1434,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x37U] >> 1U))));
        bufp->chgBit(oldp+1435,((1U & (~ (IData)((0x1ffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x31U)))))));
        bufp->chgBit(oldp+1436,((((~ (IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x31U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x31U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x37U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x37U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1437,((1U & (IData)((0xffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x32U))))));
        bufp->chgBit(oldp+1438,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x38U])));
        bufp->chgBit(oldp+1439,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x38U] >> 1U))));
        bufp->chgBit(oldp+1440,((1U & (~ (IData)((0xffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x32U)))))));
        bufp->chgBit(oldp+1441,((((~ (IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x32U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x32U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x38U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x38U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1442,((1U & (IData)((0x7fULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x33U))))));
        bufp->chgBit(oldp+1443,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x39U])));
        bufp->chgBit(oldp+1444,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x39U] >> 1U))));
        bufp->chgBit(oldp+1445,((1U & (~ (IData)((0x7fULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x33U)))))));
        bufp->chgBit(oldp+1446,((((~ (IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x33U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x33U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x39U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x39U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1447,((1U & (IData)((0x3fULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x34U))))));
        bufp->chgBit(oldp+1448,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x3aU])));
        bufp->chgBit(oldp+1449,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x3aU] >> 1U))));
        bufp->chgBit(oldp+1450,((1U & (~ (IData)((0x3fULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x34U)))))));
        bufp->chgBit(oldp+1451,((((~ (IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x34U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x34U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x3aU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x3aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1452,((1U & (IData)((0x1fULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x35U))))));
        bufp->chgBit(oldp+1453,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x3bU])));
        bufp->chgBit(oldp+1454,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x3bU] >> 1U))));
        bufp->chgBit(oldp+1455,((1U & (~ (IData)((0x1fULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x35U)))))));
        bufp->chgBit(oldp+1456,((((~ (IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x35U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x35U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x3bU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x3bU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1457,((1U & (IData)((0x7fffffffffffffeULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U))))));
        bufp->chgBit(oldp+1458,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [5U])));
        bufp->chgBit(oldp+1459,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [5U] >> 1U))));
        bufp->chgBit(oldp+1460,((1U & (~ (IData)((0x7fffffffffffffeULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     << 1U)))))));
        bufp->chgBit(oldp+1461,((((~ (IData)((0x7fffffffffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffffffeULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [5U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [5U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1462,((1U & (IData)((0xfULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x36U))))));
        bufp->chgBit(oldp+1463,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x3cU])));
        bufp->chgBit(oldp+1464,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x3cU] >> 1U))));
        bufp->chgBit(oldp+1465,((1U & (~ (IData)((0xfULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x36U)))))));
        bufp->chgBit(oldp+1466,((((~ (IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x36U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x36U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x3cU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x3cU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1467,((1U & (IData)((7ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x37U))))));
        bufp->chgBit(oldp+1468,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x3dU])));
        bufp->chgBit(oldp+1469,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x3dU] >> 1U))));
        bufp->chgBit(oldp+1470,((1U & (~ (IData)((7ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x37U)))))));
        bufp->chgBit(oldp+1471,((((~ (IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x37U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((7ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x37U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x3dU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x3dU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1472,((1U & (IData)((3ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x38U))))));
        bufp->chgBit(oldp+1473,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x3eU])));
        bufp->chgBit(oldp+1474,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x3eU] >> 1U))));
        bufp->chgBit(oldp+1475,((1U & (~ (IData)((3ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x38U)))))));
        bufp->chgBit(oldp+1476,((((~ (IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x38U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((3ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x38U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x3eU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x3eU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1477,((1U & (IData)((1ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x39U))))));
        bufp->chgBit(oldp+1478,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [0x3fU])));
        bufp->chgBit(oldp+1479,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [0x3fU] >> 1U))));
        bufp->chgBit(oldp+1480,((1U & (~ (IData)((1ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x39U)))))));
        bufp->chgBit(oldp+1481,((((~ (IData)((1ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x39U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | ((IData)(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              >> 0x39U) 
                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x))) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [0x3fU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [0x3fU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1482,((1U & (IData)((0x3ffffffffffffffULL 
                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)))));
        bufp->chgBit(oldp+1483,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [6U])));
        bufp->chgBit(oldp+1484,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [6U] >> 1U))));
        bufp->chgBit(oldp+1485,((1U & (~ (IData)((0x3ffffffffffffffULL 
                                                  & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))))));
        bufp->chgBit(oldp+1486,((((~ (IData)((0x3ffffffffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffffffffULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [6U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [6U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1487,((1U & (IData)((0x1ffffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U))))));
        bufp->chgBit(oldp+1488,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [7U])));
        bufp->chgBit(oldp+1489,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [7U] >> 1U))));
        bufp->chgBit(oldp+1490,((1U & (~ (IData)((0x1ffffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 1U)))))));
        bufp->chgBit(oldp+1491,((((~ (IData)((0x1ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [7U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [7U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1492,((1U & (IData)((0xffffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))));
        bufp->chgBit(oldp+1493,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [8U])));
        bufp->chgBit(oldp+1494,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [8U] >> 1U))));
        bufp->chgBit(oldp+1495,((1U & (~ (IData)((0xffffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 2U)))))));
        bufp->chgBit(oldp+1496,((((~ (IData)((0xffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [8U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [8U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1497,((1U & (IData)((0x7fffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))));
        bufp->chgBit(oldp+1498,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                 [9U])));
        bufp->chgBit(oldp+1499,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                       [9U] >> 1U))));
        bufp->chgBit(oldp+1500,((1U & (~ (IData)((0x7fffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 3U)))))));
        bufp->chgBit(oldp+1501,((((~ (IData)((0x7fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                         [9U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT__CarrySig
                                          [9U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1502,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 7U)))));
        bufp->chgBit(oldp+1503,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 6U)))));
        bufp->chgCData(oldp+1504,((7U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                                 >> 7U)))),3);
        bufp->chgQData(oldp+1505,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                   << 8U)),64);
        bufp->chgQData(oldp+1507,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__OutX),64);
        bufp->chgBit(oldp+1509,(((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x) 
                                 | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx))));
        bufp->chgBit(oldp+1510,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx));
        bufp->chgBit(oldp+1511,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x));
        bufp->chgBit(oldp+1512,(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x));
        bufp->chgBit(oldp+1513,((1U & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                               << 8U)))));
        bufp->chgBit(oldp+1514,((1U & (~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U))))));
        bufp->chgBit(oldp+1515,((((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 8U))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                              << 8U)) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)))));
        bufp->chgBit(oldp+1516,((1U & (IData)((0x3fffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))));
        bufp->chgBit(oldp+1517,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0xaU])));
        bufp->chgBit(oldp+1518,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0xaU] >> 1U))));
        bufp->chgBit(oldp+1519,((1U & (~ (IData)((0x3fffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 2U)))))));
        bufp->chgBit(oldp+1520,((((~ (IData)((0x3fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0xaU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0xaU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1521,((1U & (IData)((0x1fffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))));
        bufp->chgBit(oldp+1522,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0xbU])));
        bufp->chgBit(oldp+1523,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0xbU] >> 1U))));
        bufp->chgBit(oldp+1524,((1U & (~ (IData)((0x1fffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 3U)))))));
        bufp->chgBit(oldp+1525,((((~ (IData)((0x1fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0xbU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0xbU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1526,((1U & (IData)((0xfffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))));
        bufp->chgBit(oldp+1527,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0xcU])));
        bufp->chgBit(oldp+1528,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0xcU] >> 1U))));
        bufp->chgBit(oldp+1529,((1U & (~ (IData)((0xfffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 4U)))))));
        bufp->chgBit(oldp+1530,((((~ (IData)((0xfffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0xcU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0xcU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1531,((1U & (IData)((0x7ffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))));
        bufp->chgBit(oldp+1532,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0xdU])));
        bufp->chgBit(oldp+1533,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0xdU] >> 1U))));
        bufp->chgBit(oldp+1534,((1U & (~ (IData)((0x7ffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 5U)))))));
        bufp->chgBit(oldp+1535,((((~ (IData)((0x7ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0xdU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0xdU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1536,((1U & (IData)((0x3ffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U))))));
        bufp->chgBit(oldp+1537,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0xeU])));
        bufp->chgBit(oldp+1538,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0xeU] >> 1U))));
        bufp->chgBit(oldp+1539,((1U & (~ (IData)((0x3ffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 6U)))))));
        bufp->chgBit(oldp+1540,((((~ (IData)((0x3ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0xeU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0xeU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1541,((1U & (IData)((0x1ffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U))))));
        bufp->chgBit(oldp+1542,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0xfU])));
        bufp->chgBit(oldp+1543,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0xfU] >> 1U))));
        bufp->chgBit(oldp+1544,((1U & (~ (IData)((0x1ffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 7U)))))));
        bufp->chgBit(oldp+1545,((((~ (IData)((0x1ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0xfU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0xfU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1546,((1U & (IData)((0xffffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U))))));
        bufp->chgBit(oldp+1547,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x10U])));
        bufp->chgBit(oldp+1548,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x10U] >> 1U))));
        bufp->chgBit(oldp+1549,((1U & (~ (IData)((0xffffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 8U)))))));
        bufp->chgBit(oldp+1550,((((~ (IData)((0xffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x10U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x10U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1551,((1U & (IData)((0x7fffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U))))));
        bufp->chgBit(oldp+1552,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x11U])));
        bufp->chgBit(oldp+1553,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x11U] >> 1U))));
        bufp->chgBit(oldp+1554,((1U & (~ (IData)((0x7fffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 9U)))))));
        bufp->chgBit(oldp+1555,((((~ (IData)((0x7fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x11U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x11U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1556,((1U & (IData)((0x3fffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU))))));
        bufp->chgBit(oldp+1557,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x12U])));
        bufp->chgBit(oldp+1558,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x12U] >> 1U))));
        bufp->chgBit(oldp+1559,((1U & (~ (IData)((0x3fffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xaU)))))));
        bufp->chgBit(oldp+1560,((((~ (IData)((0x3fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x12U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x12U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1561,((1U & (IData)((0x1fffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU))))));
        bufp->chgBit(oldp+1562,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x13U])));
        bufp->chgBit(oldp+1563,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x13U] >> 1U))));
        bufp->chgBit(oldp+1564,((1U & (~ (IData)((0x1fffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xbU)))))));
        bufp->chgBit(oldp+1565,((((~ (IData)((0x1fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1fffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x13U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x13U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1566,((1U & (IData)((0x7fffffffffffff80ULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U))))));
        bufp->chgBit(oldp+1567,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [1U])));
        bufp->chgBit(oldp+1568,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [1U] >> 1U))));
        bufp->chgBit(oldp+1569,((1U & (~ (IData)((0x7fffffffffffff80ULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     << 7U)))))));
        bufp->chgBit(oldp+1570,((((~ (IData)((0x7fffffffffffff80ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffffff80ULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [1U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [1U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1571,((1U & (IData)((0xfffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU))))));
        bufp->chgBit(oldp+1572,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x14U])));
        bufp->chgBit(oldp+1573,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x14U] >> 1U))));
        bufp->chgBit(oldp+1574,((1U & (~ (IData)((0xfffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xcU)))))));
        bufp->chgBit(oldp+1575,((((~ (IData)((0xfffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xfffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x14U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x14U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1576,((1U & (IData)((0x7ffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU))))));
        bufp->chgBit(oldp+1577,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x15U])));
        bufp->chgBit(oldp+1578,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x15U] >> 1U))));
        bufp->chgBit(oldp+1579,((1U & (~ (IData)((0x7ffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xdU)))))));
        bufp->chgBit(oldp+1580,((((~ (IData)((0x7ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x15U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x15U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1581,((1U & (IData)((0x3ffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU))))));
        bufp->chgBit(oldp+1582,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x16U])));
        bufp->chgBit(oldp+1583,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x16U] >> 1U))));
        bufp->chgBit(oldp+1584,((1U & (~ (IData)((0x3ffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xeU)))))));
        bufp->chgBit(oldp+1585,((((~ (IData)((0x3ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x16U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x16U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1586,((1U & (IData)((0x1ffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU))))));
        bufp->chgBit(oldp+1587,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x17U])));
        bufp->chgBit(oldp+1588,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x17U] >> 1U))));
        bufp->chgBit(oldp+1589,((1U & (~ (IData)((0x1ffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0xfU)))))));
        bufp->chgBit(oldp+1590,((((~ (IData)((0x1ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x1ffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x17U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x17U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1591,((1U & (IData)((0xffffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U))))));
        bufp->chgBit(oldp+1592,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x18U])));
        bufp->chgBit(oldp+1593,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x18U] >> 1U))));
        bufp->chgBit(oldp+1594,((1U & (~ (IData)((0xffffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x10U)))))));
        bufp->chgBit(oldp+1595,((((~ (IData)((0xffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0xffffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x18U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x18U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1596,((1U & (IData)((0x7fffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U))))));
        bufp->chgBit(oldp+1597,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x19U])));
        bufp->chgBit(oldp+1598,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x19U] >> 1U))));
        bufp->chgBit(oldp+1599,((1U & (~ (IData)((0x7fffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x11U)))))));
        bufp->chgBit(oldp+1600,((((~ (IData)((0x7fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x7fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x19U] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x19U] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1601,((1U & (IData)((0x3fffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U))))));
        bufp->chgBit(oldp+1602,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x1aU])));
        bufp->chgBit(oldp+1603,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x1aU] >> 1U))));
        bufp->chgBit(oldp+1604,((1U & (~ (IData)((0x3fffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x12U)))))));
        bufp->chgBit(oldp+1605,((((~ (IData)((0x3fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__negx)) 
                                 | (((IData)((0x3fffffffffULL 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))) 
                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__x)) 
                                    | (((vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                         [0x1aU] >> 1U) 
                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__neg2x)) 
                                       | (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                          [0x1aU] & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT___2x)))))));
        bufp->chgBit(oldp+1606,((1U & (IData)((0x1fffffffffULL 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U))))));
        bufp->chgBit(oldp+1607,((1U & vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                 [0x1bU])));
        bufp->chgBit(oldp+1608,((1U & (vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai.__PVT__CarrySig
                                       [0x1bU] >> 1U))));
        bufp->chgBit(oldp+1609,((1U & (~ (IData)((0x1fffffffffULL 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                     >> 0x13U)))))));
    }
}

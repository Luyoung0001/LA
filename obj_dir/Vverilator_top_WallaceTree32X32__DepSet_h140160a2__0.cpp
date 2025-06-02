// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_WallaceTree32X32.h"
#include "Vverilator_top__Syms.h"

VL_INLINE_OPT void Vverilator_top_WallaceTree32X32___nba_sequent__TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace__0(Vverilator_top_WallaceTree32X32* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vverilator_top_WallaceTree32X32___nba_sequent__TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace__0\n"); );
    // Body
    vlSelf->__Vcellinp__sec1ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1));
    vlSelf->__Vcellout__fir1fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2)));
    vlSelf->__Vcellout__fir1fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir1fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2)));
    vlSelf->__Vcellout__fir1fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir1fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir1fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir1fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir1fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir1fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir1fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir1fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 4U))));
    vlSelf->__Vcellout__fir1fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir1fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir1fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir1fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir1fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir1fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir1fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir1fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir1fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir1fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir1fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir1fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir1fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir1fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir1fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir1fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0xcU))));
    vlSelf->__Vcellinp__sec1ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                     >> 0x1eU));
    vlSelf->__Vcellout__fir1fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir1fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0xdU))));
    vlSelf->__Vcellinp__sec1ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir1fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir1fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir1fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir1fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir1fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir1fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir1fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir1fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir1fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir1fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir1fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir1fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir1fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir1fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir1fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir1fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x1dU))));
    vlSelf->__Vcellout__fir1fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir1fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir1fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir1fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir1fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir1fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir1fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir1fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir1fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir1fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir1fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir1fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir1fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0x10U))));
    vlSelf->__Vcellout__fir1fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir1fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                           >> 0xeU))));
    vlSelf->__Vcellinp__sec11ha30____pinNumber2 = (
                                                   (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                    >> 0x1fU) 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 0x1eU));
    vlSelf->__Vcellinp__sec11ha29____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1fU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x1eU)));
    vlSelf->__Vcellinp__sec11ha29____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1eU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x1dU)));
    vlSelf->__Vcellinp__sec11ha28____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x1dU)));
    vlSelf->__Vcellinp__sec11ha28____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1dU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x1cU)));
    vlSelf->__Vcellinp__sec11ha27____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x1cU)));
    vlSelf->__Vcellinp__sec11ha27____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1cU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x1bU)));
    vlSelf->__Vcellinp__sec11ha26____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x1bU)));
    vlSelf->__Vcellinp__sec11ha26____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1bU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x1aU)));
    vlSelf->__Vcellinp__sec11ha25____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x1aU)));
    vlSelf->__Vcellinp__sec11ha25____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1aU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x19U)));
    vlSelf->__Vcellinp__sec11ha21____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x16U)));
    vlSelf->__Vcellinp__sec11ha22____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x17U)));
    vlSelf->__Vcellinp__sec11ha23____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x18U)));
    vlSelf->__Vcellinp__sec11ha24____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x19U)));
    vlSelf->__Vcellinp__sec11ha21____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x16U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x15U)));
    vlSelf->__Vcellinp__sec11ha22____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x17U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x16U)));
    vlSelf->__Vcellinp__sec11ha23____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x18U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x17U)));
    vlSelf->__Vcellinp__sec11ha24____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x19U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x18U)));
    vlSelf->__Vcellinp__sec11ha20____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x15U)));
    vlSelf->__Vcellinp__sec11ha20____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x15U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x14U)));
    vlSelf->__Vcellinp__sec11ha19____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x14U)));
    vlSelf->__Vcellinp__sec11ha19____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x14U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x13U)));
    vlSelf->__Vcellinp__sec11ha18____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x13U)));
    vlSelf->__Vcellinp__sec11ha18____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x13U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x12U)));
    vlSelf->__Vcellinp__sec11ha17____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x12U)));
    vlSelf->__Vcellinp__sec11ha17____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x12U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x11U)));
    vlSelf->__Vcellinp__sec11ha16____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x11U)));
    vlSelf->__Vcellinp__sec11ha16____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x11U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0x10U)));
    vlSelf->__Vcellinp__sec11ha15____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0x10U)));
    vlSelf->__Vcellinp__sec11ha15____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x10U) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0xfU)));
    vlSelf->__Vcellinp__sec11ha8____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 0xaU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 9U)));
    vlSelf->__Vcellinp__sec11ha9____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 0xbU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 0xaU)));
    vlSelf->__Vcellinp__sec11ha10____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0xbU)));
    vlSelf->__Vcellinp__sec11ha11____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0xcU)));
    vlSelf->__Vcellinp__sec11ha12____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0xdU)));
    vlSelf->__Vcellinp__sec11ha13____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0xeU)));
    vlSelf->__Vcellinp__sec11ha14____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                       >> 0xfU)));
    vlSelf->__Vcellinp__sec11ha8____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 9U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 8U)));
    vlSelf->__Vcellinp__sec11ha9____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 0xaU) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 9U)));
    vlSelf->__Vcellinp__sec11ha10____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xbU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0xaU)));
    vlSelf->__Vcellinp__sec11ha11____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xcU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0xbU)));
    vlSelf->__Vcellinp__sec11ha12____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xdU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0xcU)));
    vlSelf->__Vcellinp__sec11ha13____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xeU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0xdU)));
    vlSelf->__Vcellinp__sec11ha14____pinNumber2 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                       >> 0xfU) 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                         >> 0xeU)));
    vlSelf->__Vcellinp__sec11ha7____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 8U)));
    vlSelf->__Vcellinp__sec11ha7____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 8U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 7U)));
    vlSelf->__Vcellinp__sec11ha6____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 7U)));
    vlSelf->__Vcellinp__sec11ha6____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 7U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 6U)));
    vlSelf->__Vcellinp__thi7fa2____pinNumber3 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31));
    vlSelf->__Vcellinp__sec11ha5____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 6U)));
    vlSelf->__Vcellinp__sec11ha5____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 6U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 5U)));
    vlSelf->__Vcellinp__sec11ha4____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 5U)));
    vlSelf->__Vcellinp__sec11ha4____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 5U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 4U)));
    vlSelf->__Vcellinp__sec11ha3____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 4U)));
    vlSelf->__Vcellinp__sec11ha3____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 4U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 3U)));
    vlSelf->__Vcellinp__sec11ha0____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 1U)));
    vlSelf->__Vcellinp__sec11ha0____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 1U) 
                                                     & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31));
    vlSelf->__Vcellinp__sec11ha1____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 2U)));
    vlSelf->__Vcellinp__sec11ha2____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                      >> 3U)));
    vlSelf->__Vcellinp__sec11ha1____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 2U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 1U)));
    vlSelf->__Vcellinp__sec11ha2____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                                                      >> 3U) 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                        >> 2U)));
    vlSelf->__Vcellinp__thi1fa2____pinNumber3 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4));
    vlSelf->__Vcellinp__sec2ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4));
    vlSelf->__Vcellout__fir2fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5)));
    vlSelf->__Vcellout__fir2fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir2fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5)));
    vlSelf->__Vcellout__fir2fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir2fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 1U))));
    vlSelf->__Vcellinp__sec2ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                     >> 0x1eU));
    vlSelf->__Vcellout__fir2fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir2fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir2fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir2fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir2fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir2fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 4U))));
    vlSelf->__Vcellinp__sec2ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir2fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x1dU))));
    vlSelf->__Vcellout__fir2fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir2fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir2fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir2fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir2fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir2fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir2fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir2fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir2fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir2fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir2fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir2fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir2fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir2fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir2fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir2fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir2fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir2fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir2fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir2fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir2fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir2fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir2fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir2fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir2fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir2fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0xeU))));
    vlSelf->__Vcellout__fir2fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir2fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir2fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir2fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x10U))));
    vlSelf->__Vcellout__fir2fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir2fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir2fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir2fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir2fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir2fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir2fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir2fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir2fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir2fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir2fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir2fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir2fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir2fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir2fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir2fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir2fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir2fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                           >> 0x12U))));
    vlSelf->__Vcellinp__sev3fa3____pinNumber3 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28));
    vlSelf->__Vcellinp__sec10ha31____pinNumber2 = (
                                                   (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                    >> 0x1fU) 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                      >> 0x1eU));
    vlSelf->__Vcellinp__sec10ha30____pinNumber1 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 0x1fU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 0x1eU)));
    vlSelf->__Vcellout__fir10fa30____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x1fU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x1eU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x1dU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x1eU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x1dU))));
    vlSelf->__Vcellinp__sec10ha0____pinNumber2 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 1U) 
                                                     & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28));
    vlSelf->__Vcellout__fir10fa1____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 2U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 1U) 
                                                      ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29)));
    vlSelf->__Vcellout__fir10fa30____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x1fU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x1eU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x1dU))));
    vlSelf->__Vcellout__fir10fa29____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x1eU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x1dU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x1cU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x1dU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x1cU))));
    vlSelf->__Vcellout__fir10fa29____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x1dU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x1cU))));
    vlSelf->__Vcellout__fir10fa28____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x1dU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x1cU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x1bU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x1cU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x1bU))));
    vlSelf->__Vcellout__fir10fa28____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x1cU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x1bU))));
    vlSelf->__Vcellout__fir10fa27____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x1cU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x1bU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x1aU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x1bU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x1aU))));
    vlSelf->__Vcellout__fir10fa27____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x1bU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x1aU))));
    vlSelf->__Vcellout__fir10fa26____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x1aU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x19U))));
    vlSelf->__Vcellout__fir10fa25____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x19U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x18U))));
    vlSelf->__Vcellout__fir10fa26____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x1bU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x1aU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x19U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x1aU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x19U))));
    vlSelf->__Vcellout__fir10fa25____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x1aU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x19U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x18U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x19U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x18U))));
    vlSelf->__Vcellout__fir10fa24____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x19U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x18U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x17U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x18U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x17U))));
    vlSelf->__Vcellout__fir10fa24____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x19U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x18U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x17U))));
    vlSelf->__Vcellout__fir10fa23____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x18U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x17U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x16U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x17U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x16U))));
    vlSelf->__Vcellout__fir10fa23____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x18U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x17U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x16U))));
    vlSelf->__Vcellout__fir10fa22____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x17U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x16U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x15U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x16U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x15U))));
    vlSelf->__Vcellout__fir10fa22____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x17U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x16U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x15U))));
    vlSelf->__Vcellout__fir10fa21____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x16U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x15U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x14U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x15U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x14U))));
    vlSelf->__Vcellout__fir10fa21____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x16U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x15U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x14U))));
    vlSelf->__Vcellout__fir10fa20____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x15U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x14U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x13U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x14U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x13U))));
    vlSelf->__Vcellout__fir10fa20____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x15U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x14U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x13U))));
    vlSelf->__Vcellout__fir10fa19____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x14U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x13U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x12U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x13U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x12U))));
    vlSelf->__Vcellout__fir10fa19____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x14U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x13U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x12U))));
    vlSelf->__Vcellout__fir10fa18____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x13U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x12U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x11U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x12U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x11U))));
    vlSelf->__Vcellout__fir10fa18____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x13U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x12U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x11U))));
    vlSelf->__Vcellout__fir10fa17____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x12U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x11U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0x10U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x11U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0x10U))));
    vlSelf->__Vcellout__fir10fa17____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x12U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x11U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0x10U))));
    vlSelf->__Vcellout__fir10fa16____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x11U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0x10U) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0xfU))));
    vlSelf->__Vcellout__fir10fa15____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0x10U) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0xfU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0xeU))));
    vlSelf->__Vcellout__fir10fa14____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0xfU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0xeU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0xdU))));
    vlSelf->__Vcellout__fir10fa13____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0xeU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0xdU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0xcU))));
    vlSelf->__Vcellout__fir10fa12____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0xdU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0xcU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0xbU))));
    vlSelf->__Vcellout__fir10fa16____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x11U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0x10U) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0xfU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0x10U) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0xfU))));
    vlSelf->__Vcellout__fir10fa15____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0x10U) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0xfU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0xeU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0xfU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0xeU))));
    vlSelf->__Vcellout__fir10fa14____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0xfU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0xeU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0xdU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0xeU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0xdU))));
    vlSelf->__Vcellout__fir10fa13____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0xeU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0xdU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0xcU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0xdU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0xcU))));
    vlSelf->__Vcellout__fir10fa12____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0xdU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0xcU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0xbU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0xcU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0xbU))));
    vlSelf->__Vcellout__fir10fa11____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0xcU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0xbU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 0xaU))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0xbU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 0xaU))));
    vlSelf->__Vcellout__fir10fa11____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0xcU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0xbU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 0xaU))));
    vlSelf->__Vcellout__fir10fa10____pinNumber5 = (1U 
                                                   & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                        >> 0xbU) 
                                                       & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                           >> 0xaU) 
                                                          | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                             >> 9U))) 
                                                      | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 0xaU) 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 9U))));
    vlSelf->__Vcellout__fir10fa10____pinNumber4 = (1U 
                                                   & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0xbU) 
                                                      ^ 
                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                        >> 0xaU) 
                                                       ^ 
                                                       (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                        >> 9U))));
    vlSelf->__Vcellout__fir10fa9____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 0xaU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 9U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 8U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 9U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 8U))));
    vlSelf->__Vcellout__fir10fa2____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 3U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 2U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 1U))));
    vlSelf->__Vcellout__fir10fa1____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 2U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 1U) 
                                                         | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29)) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 1U) 
                                                        & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29)));
    vlSelf->__Vcellout__fir10fa9____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 0xaU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 9U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 8U))));
    vlSelf->__Vcellout__fir10fa8____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 9U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 8U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 7U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 8U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 7U))));
    vlSelf->__Vcellout__fir10fa8____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 9U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 8U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 7U))));
    vlSelf->__Vcellout__fir10fa7____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 8U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 7U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 6U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 7U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 6U))));
    vlSelf->__Vcellout__fir10fa7____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 8U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 7U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 6U))));
    vlSelf->__Vcellout__fir10fa6____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 7U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 6U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 5U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 6U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 5U))));
    vlSelf->__Vcellout__fir10fa3____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 4U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 3U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 2U))));
    vlSelf->__Vcellout__fir10fa2____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 3U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 2U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 1U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 2U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 1U))));
    vlSelf->__Vcellout__fir10fa6____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 7U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 6U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 5U))));
    vlSelf->__Vcellout__fir10fa5____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 6U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 5U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 4U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 5U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 4U))));
    vlSelf->__Vcellout__fir10fa4____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 5U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 4U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 3U))));
    vlSelf->__Vcellout__fir10fa3____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 4U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 3U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 2U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 3U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 2U))));
    vlSelf->__Vcellout__fir10fa5____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                      >> 6U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                       >> 5U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                       >> 4U))));
    vlSelf->__Vcellout__fir10fa4____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                       >> 5U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                          >> 4U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                            >> 3U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                         >> 4U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                           >> 3U))));
    vlSelf->__Vcellinp__thi2fa2____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7));
    vlSelf->__Vcellinp__sec3ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7));
    vlSelf->__Vcellout__fir3fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8)));
    vlSelf->__Vcellout__fir3fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir3fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8)));
    vlSelf->__Vcellinp__sec3ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                     >> 0x1eU));
    vlSelf->__Vcellout__fir3fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir3fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir3fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir3fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir3fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir3fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir3fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir3fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 4U))));
    vlSelf->__Vcellinp__sec3ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir3fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x1dU))));
    vlSelf->__Vcellout__fir3fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir3fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir3fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir3fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir3fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir3fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir3fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir3fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir3fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir3fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir3fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir3fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir3fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir3fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir3fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir3fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir3fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir3fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir3fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir3fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir3fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir3fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir3fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir3fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir3fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir3fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir3fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir3fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir3fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir3fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir3fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir3fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0xeU))));
    vlSelf->__Vcellout__fir3fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir3fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir3fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir3fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir3fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir3fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir3fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir3fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir3fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir3fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir3fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir3fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir3fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir3fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir3fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir3fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                           >> 0x10U))));
    vlSelf->__Vcellinp__thi4fa2____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16));
    vlSelf->__Vcellinp__sec6ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                     >> 0x1eU));
    vlSelf->__Vcellinp__sec6ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir6fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x1dU))));
    vlSelf->__Vcellout__fir6fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir6fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir6fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir6fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir6fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir6fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir6fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir6fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir6fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir6fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir6fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir6fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir6fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir6fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir6fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir6fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x15U))));
    vlSelf->__Vcellinp__sec6ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16));
    vlSelf->__Vcellout__fir6fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17)));
    vlSelf->__Vcellout__fir6fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir6fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir6fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir6fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17)));
    vlSelf->__Vcellout__fir6fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir6fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir6fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir6fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir6fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir6fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir6fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir6fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir6fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir6fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir6fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir6fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir6fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir6fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0x10U))));
    vlSelf->__Vcellout__fir6fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir6fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 4U))));
    vlSelf->__Vcellout__fir6fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir6fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir6fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir6fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir6fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir6fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir6fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir6fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir6fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir6fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir6fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir6fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir6fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir6fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir6fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir6fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir6fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0xeU))));
    vlSelf->__Vcellout__fir6fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir6fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir6fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir6fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir6fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                           >> 9U))));
    vlSelf->__Vcellinp__sec5ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                     >> 0x1eU));
    vlSelf->__Vcellinp__thi3fa2____pinNumber3 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13));
    vlSelf->__Vcellinp__sec5ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir5fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x1dU))));
    vlSelf->__Vcellinp__sec5ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13));
    vlSelf->__Vcellout__fir5fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14)));
    vlSelf->__Vcellout__fir5fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir5fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir5fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir5fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir5fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir5fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir5fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir5fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir5fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir5fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir5fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir5fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14)));
    vlSelf->__Vcellout__fir5fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir5fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir5fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir5fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir5fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir5fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir5fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir5fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir5fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir5fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir5fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir5fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir5fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir5fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 4U))));
    vlSelf->__Vcellout__fir5fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir5fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir5fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir5fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir5fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir5fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir5fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir5fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir5fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir5fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir5fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir5fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir5fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir5fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir5fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir5fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir5fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir5fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir5fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir5fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir5fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir5fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir5fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir5fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir5fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir5fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir5fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0x10U))));
    vlSelf->__Vcellout__fir5fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir5fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0xeU))));
    vlSelf->__Vcellout__fir5fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir5fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir5fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                           >> 0xbU))));
    vlSelf->__Vcellinp__fif2fa2____pinNumber1 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10));
    vlSelf->__Vcellinp__sec4ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10));
    vlSelf->__Vcellout__fir4fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11)));
    vlSelf->__Vcellout__fir4fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir4fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11)));
    vlSelf->__Vcellinp__sec4ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                     >> 0x1eU));
    vlSelf->__Vcellinp__sec4ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir4fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x1dU))));
    vlSelf->__Vcellout__fir4fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir4fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir4fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir4fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir4fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir4fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir4fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir4fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir4fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir4fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir4fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir4fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir4fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir4fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir4fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir4fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 4U))));
    vlSelf->__Vcellout__fir4fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir4fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir4fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir4fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir4fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir4fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir4fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir4fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir4fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir4fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir4fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir4fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir4fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir4fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir4fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir4fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir4fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir4fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir4fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir4fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir4fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir4fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir4fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir4fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir4fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir4fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir4fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir4fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir4fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir4fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir4fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir4fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir4fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir4fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir4fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir4fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir4fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir4fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0x10U))));
    vlSelf->__Vcellout__fir4fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir4fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                           >> 0xeU))));
    vlSelf->__Vcellinp__fif3fa3____pinNumber3 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19));
    vlSelf->__Vcellinp__sec7ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19));
    vlSelf->__Vcellout__fir7fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20)));
    vlSelf->__Vcellout__fir7fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir7fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20)));
    vlSelf->__Vcellout__fir7fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir7fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir7fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir7fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir7fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir7fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir7fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir7fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir7fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir7fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir7fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir7fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir7fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir7fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir7fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir7fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir7fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir7fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir7fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir7fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir7fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir7fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir7fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir7fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir7fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir7fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x11U))));
    vlSelf->__Vcellinp__sec7ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir7fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x1dU))));
    vlSelf->__Vcellout__fir7fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir7fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0x10U))));
    vlSelf->__Vcellinp__sec7ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                     >> 0x1eU));
    vlSelf->__Vcellout__fir7fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir7fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir7fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir7fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir7fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir7fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0xeU))));
    vlSelf->__Vcellout__fir7fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir7fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir7fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir7fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir7fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir7fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir7fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir7fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 4U))));
    vlSelf->__Vcellout__fir7fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir7fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir7fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir7fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir7fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir7fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir7fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir7fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir7fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir7fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir7fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir7fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir7fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir7fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                           >> 0xaU))));
    vlSelf->__Vcellinp__thi5fa2____pinNumber3 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22));
    vlSelf->__Vcellinp__sec8ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                     >> 0x1eU));
    vlSelf->__Vcellinp__sec8ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir8fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x1dU))));
    vlSelf->__Vcellinp__sec8ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22));
    vlSelf->__Vcellout__fir8fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23)));
    vlSelf->__Vcellout__fir8fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir8fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir8fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir8fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir8fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir8fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir8fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir8fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir8fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir8fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir8fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir8fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir8fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir8fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir8fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir8fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir8fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir8fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir8fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir8fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x10U))));
    vlSelf->__Vcellout__fir8fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir8fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir8fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir8fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir8fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir8fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0xeU))));
    vlSelf->__Vcellout__fir8fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir8fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir8fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir8fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir8fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir8fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir8fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir8fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir8fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir8fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir8fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir8fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23)));
    vlSelf->__Vcellout__fir8fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir8fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir8fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir8fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir8fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir8fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir8fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir8fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir8fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir8fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir8fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir8fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir8fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir8fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 4U))));
    vlSelf->__Vcellout__fir8fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir8fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir8fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir8fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 6U))));
    vlSelf->__Vcellout__fir8fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir8fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                          >> 7U))));
    vlSelf->__Vcellinp__sec9ha31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                   >> 0x1fU) 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                     >> 0x1eU));
    vlSelf->__Vcellinp__thi6fa2____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 1U) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25));
    vlSelf->__Vcellinp__sec9ha30____pinNumber1 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 0x1eU)));
    vlSelf->__Vcellout__fir9fa30____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x1fU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x1eU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x1dU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x1eU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x1dU))));
    vlSelf->__Vcellout__fir9fa30____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x1fU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x1eU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x1dU))));
    vlSelf->__Vcellout__fir9fa29____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x1eU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x1dU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x1cU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x1dU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x1cU))));
    vlSelf->__Vcellout__fir9fa29____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x1eU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x1dU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x1cU))));
    vlSelf->__Vcellout__fir9fa28____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x1dU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x1cU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x1bU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x1cU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x1bU))));
    vlSelf->__Vcellout__fir9fa28____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x1dU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x1cU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x1bU))));
    vlSelf->__Vcellout__fir9fa27____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x1cU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x1bU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x1aU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x1bU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x1aU))));
    vlSelf->__Vcellout__fir9fa27____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x1cU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x1bU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x1aU))));
    vlSelf->__Vcellout__fir9fa26____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x1bU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x1aU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x19U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x1aU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x19U))));
    vlSelf->__Vcellout__fir9fa26____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x1bU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x1aU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x19U))));
    vlSelf->__Vcellout__fir9fa25____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x1aU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x19U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x18U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x19U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x18U))));
    vlSelf->__Vcellout__fir9fa25____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x1aU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x19U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x18U))));
    vlSelf->__Vcellout__fir9fa24____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x19U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x18U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x17U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x18U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x17U))));
    vlSelf->__Vcellout__fir9fa24____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x19U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x18U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x17U))));
    vlSelf->__Vcellout__fir9fa23____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x18U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x17U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x16U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x17U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x16U))));
    vlSelf->__Vcellout__fir9fa23____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x18U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x17U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x16U))));
    vlSelf->__Vcellout__fir9fa22____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x17U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x16U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x15U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x16U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x15U))));
    vlSelf->__Vcellout__fir9fa22____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x17U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x16U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x15U))));
    vlSelf->__Vcellout__fir9fa21____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x16U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x15U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x14U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x15U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x14U))));
    vlSelf->__Vcellout__fir9fa21____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x16U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x15U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x14U))));
    vlSelf->__Vcellout__fir9fa20____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x15U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x14U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x13U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x14U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x13U))));
    vlSelf->__Vcellout__fir9fa20____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x15U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x14U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x13U))));
    vlSelf->__Vcellout__fir9fa19____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x14U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x13U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x12U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x13U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x12U))));
    vlSelf->__Vcellout__fir9fa19____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x14U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x13U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x12U))));
    vlSelf->__Vcellout__fir9fa18____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x13U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x12U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x11U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x12U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x11U))));
    vlSelf->__Vcellout__fir9fa18____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x13U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x12U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x11U))));
    vlSelf->__Vcellout__fir9fa17____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x12U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x11U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0x10U))));
    vlSelf->__Vcellout__fir9fa16____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x11U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0x10U) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0xfU))));
    vlSelf->__Vcellout__fir9fa15____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0x10U) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0xfU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0xeU))));
    vlSelf->__Vcellout__fir9fa17____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x12U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x11U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0x10U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x11U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0x10U))));
    vlSelf->__Vcellout__fir9fa16____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x11U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0x10U) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0xfU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0x10U) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0xfU))));
    vlSelf->__Vcellout__fir9fa15____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0x10U) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0xfU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0xeU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0xfU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0xeU))));
    vlSelf->__Vcellout__fir9fa14____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0xfU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0xeU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0xdU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0xeU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0xdU))));
    vlSelf->__Vcellout__fir9fa14____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0xfU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0xeU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0xdU))));
    vlSelf->__Vcellout__fir9fa13____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0xeU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0xdU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0xcU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0xdU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0xcU))));
    vlSelf->__Vcellout__fir9fa13____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0xeU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0xdU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0xcU))));
    vlSelf->__Vcellout__fir9fa12____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0xdU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0xcU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0xbU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0xcU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0xbU))));
    vlSelf->__Vcellout__fir9fa12____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0xdU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0xcU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0xbU))));
    vlSelf->__Vcellout__fir9fa11____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0xcU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0xbU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 0xaU))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0xbU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 0xaU))));
    vlSelf->__Vcellout__fir9fa11____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0xcU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0xbU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 0xaU))));
    vlSelf->__Vcellout__fir9fa10____pinNumber5 = (1U 
                                                  & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                       >> 0xbU) 
                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                          >> 0xaU) 
                                                         | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                            >> 9U))) 
                                                     | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 0xaU) 
                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 9U))));
    vlSelf->__Vcellout__fir9fa10____pinNumber4 = (1U 
                                                  & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0xbU) 
                                                     ^ 
                                                     ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                       >> 0xaU) 
                                                      ^ 
                                                      (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                       >> 9U))));
    vlSelf->__Vcellout__fir9fa9____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 0xaU) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 9U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 8U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 9U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 8U))));
    vlSelf->__Vcellout__fir9fa9____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 0xaU) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 9U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 8U))));
    vlSelf->__Vcellout__fir9fa8____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 9U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 8U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 7U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 8U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 7U))));
    vlSelf->__Vcellout__fir9fa8____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 9U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 8U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 7U))));
    vlSelf->__Vcellout__fir9fa7____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 8U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 7U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 6U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 7U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 6U))));
    vlSelf->__Vcellinp__sec9ha0____pinNumber2 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 1U) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25));
    vlSelf->__Vcellout__fir9fa1____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 2U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 1U) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26)));
    vlSelf->__Vcellout__fir9fa7____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 8U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 7U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 6U))));
    vlSelf->__Vcellout__fir9fa6____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 7U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 6U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 5U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 6U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 5U))));
    vlSelf->__Vcellout__fir9fa2____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 3U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 2U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 1U))));
    vlSelf->__Vcellout__fir9fa1____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 2U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 1U) 
                                                        | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26)) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 1U) 
                                                       & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26)));
    vlSelf->__Vcellout__fir9fa3____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 4U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 3U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 2U))));
    vlSelf->__Vcellout__fir9fa2____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 3U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 2U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 1U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 2U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 1U))));
    vlSelf->__Vcellout__fir9fa4____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 5U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 4U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 3U))));
    vlSelf->__Vcellout__fir9fa3____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 4U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 3U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 2U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 3U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 2U))));
    vlSelf->__Vcellout__fir9fa5____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 6U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 5U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 4U))));
    vlSelf->__Vcellout__fir9fa4____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 5U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 4U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 3U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 4U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 3U))));
    vlSelf->__Vcellout__fir9fa6____pinNumber4 = (1U 
                                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                     >> 7U) 
                                                    ^ 
                                                    ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                      >> 6U) 
                                                     ^ 
                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 5U))));
    vlSelf->__Vcellout__fir9fa5____pinNumber5 = (1U 
                                                 & (((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                      >> 6U) 
                                                     & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 5U) 
                                                        | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                           >> 4U))) 
                                                    | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                        >> 5U) 
                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                          >> 4U))));
    vlSelf->__Vcellinp__thi1fa1____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec1ha0____pinNumber2));
    vlSelf->__Vcellinp__thi1fa1____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa1____pinNumber5));
    vlSelf->__Vcellinp__thi1fa2____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa1____pinNumber5));
    vlSelf->__Vcellinp__thi1fa2____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa2____pinNumber5));
    vlSelf->__Vcellinp__thi1fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa2____pinNumber5));
    vlSelf->__Vcellinp__thi1fa3____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa3____pinNumber5));
    vlSelf->__Vcellinp__thi1fa4____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa3____pinNumber5));
    vlSelf->__Vcellinp__thi1fa4____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa4____pinNumber5));
    vlSelf->__Vcellinp__thi1fa5____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa4____pinNumber5));
    vlSelf->__Vcellinp__thi1fa5____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa5____pinNumber5));
    vlSelf->__Vcellinp__thi1fa6____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa5____pinNumber5));
    vlSelf->__Vcellinp__thi1fa6____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa6____pinNumber5));
    vlSelf->__Vcellinp__thi1fa7____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa7____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa6____pinNumber5));
    vlSelf->__Vcellinp__thi1fa7____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa8____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa7____pinNumber5));
    vlSelf->__Vcellinp__thi1fa8____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa8____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa7____pinNumber5));
    vlSelf->__Vcellinp__thi1fa8____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa9____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa8____pinNumber5));
    vlSelf->__Vcellinp__thi1fa9____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa9____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir1fa8____pinNumber5));
    vlSelf->__Vcellinp__thi1fa9____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa10____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir1fa9____pinNumber5));
    vlSelf->__Vcellinp__thi1fa10____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa9____pinNumber5));
    vlSelf->__Vcellinp__thi1fa10____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa10____pinNumber5));
    vlSelf->__Vcellinp__thi1fa11____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa10____pinNumber5));
    vlSelf->__Vcellinp__thi1fa11____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa11____pinNumber5));
    vlSelf->__Vcellinp__thi1fa12____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa11____pinNumber5));
    vlSelf->__Vcellinp__thi1fa12____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa12____pinNumber5));
    vlSelf->__Vcellinp__thi1fa13____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa12____pinNumber5));
    vlSelf->__Vcellinp__thi1fa13____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa13____pinNumber5));
    vlSelf->__Vcellinp__thi1fa14____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa13____pinNumber5));
    vlSelf->__Vcellinp__thi1fa32____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec1ha31____pinNumber2));
    vlSelf->__Vcellinp__thi1fa31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec1ha31____pinNumber2));
    vlSelf->__Vcellinp__thi1fa14____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa14____pinNumber5));
    vlSelf->__Vcellinp__thi1fa15____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa14____pinNumber5));
    vlSelf->__Vcellinp__thi1fa30____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec1ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa30____pinNumber5));
    vlSelf->__Vcellinp__thi1fa31____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec1ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa30____pinNumber5));
    vlSelf->__Vcellinp__thi1fa29____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa29____pinNumber5));
    vlSelf->__Vcellinp__thi1fa30____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa29____pinNumber5));
    vlSelf->__Vcellinp__thi1fa28____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa28____pinNumber5));
    vlSelf->__Vcellinp__thi1fa29____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa28____pinNumber5));
    vlSelf->__Vcellinp__thi1fa27____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa27____pinNumber5));
    vlSelf->__Vcellinp__thi1fa28____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa27____pinNumber5));
    vlSelf->__Vcellinp__thi1fa26____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa26____pinNumber5));
    vlSelf->__Vcellinp__thi1fa27____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa26____pinNumber5));
    vlSelf->__Vcellinp__thi1fa25____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa25____pinNumber5));
    vlSelf->__Vcellinp__thi1fa26____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa25____pinNumber5));
    vlSelf->__Vcellinp__thi1fa24____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa24____pinNumber5));
    vlSelf->__Vcellinp__thi1fa25____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa24____pinNumber5));
    vlSelf->__Vcellinp__thi1fa23____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa23____pinNumber5));
    vlSelf->__Vcellinp__thi1fa24____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa23____pinNumber5));
    vlSelf->__Vcellinp__thi1fa22____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa22____pinNumber5));
    vlSelf->__Vcellinp__thi1fa23____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa22____pinNumber5));
    vlSelf->__Vcellinp__thi1fa21____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa21____pinNumber5));
    vlSelf->__Vcellinp__thi1fa22____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa21____pinNumber5));
    vlSelf->__Vcellinp__thi1fa20____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa20____pinNumber5));
    vlSelf->__Vcellinp__thi1fa21____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa20____pinNumber5));
    vlSelf->__Vcellinp__thi1fa19____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa19____pinNumber5));
    vlSelf->__Vcellinp__thi1fa20____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa19____pinNumber5));
    vlSelf->__Vcellinp__thi1fa18____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa18____pinNumber5));
    vlSelf->__Vcellinp__thi1fa19____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa18____pinNumber5));
    vlSelf->__Vcellinp__thi1fa17____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa17____pinNumber5));
    vlSelf->__Vcellinp__thi1fa18____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa17____pinNumber5));
    vlSelf->__Vcellinp__thi1fa16____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa16____pinNumber5));
    vlSelf->__Vcellinp__thi1fa17____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa16____pinNumber5));
    vlSelf->__Vcellinp__thi1fa15____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir1fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir1fa15____pinNumber5));
    vlSelf->__Vcellinp__thi1fa16____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir1fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir1fa15____pinNumber5));
    vlSelf->__Vcellinp__fif5fa32____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha30____pinNumber2));
    vlSelf->__Vcellinp__fou7fa32____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha30____pinNumber2));
    vlSelf->__Vcellinp__fif5fa31____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha29____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha29____pinNumber2));
    vlSelf->__Vcellinp__thi7fa32____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec11ha29____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha29____pinNumber2));
    vlSelf->__Vcellinp__fif5fa30____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha28____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha28____pinNumber2));
    vlSelf->__Vcellinp__thi7fa31____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha28____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha28____pinNumber2));
    vlSelf->__Vcellinp__fif5fa29____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha27____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha27____pinNumber2));
    vlSelf->__Vcellinp__thi7fa30____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha27____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha27____pinNumber2));
    vlSelf->__Vcellinp__fif5fa28____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha26____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha26____pinNumber2));
    vlSelf->__Vcellinp__thi7fa29____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha26____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha26____pinNumber2));
    vlSelf->__Vcellinp__fif5fa27____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha25____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha25____pinNumber2));
    vlSelf->__Vcellinp__thi7fa28____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha25____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha25____pinNumber2));
    vlSelf->__Vcellinp__fif5fa23____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha21____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha21____pinNumber2));
    vlSelf->__Vcellinp__thi7fa24____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha21____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha21____pinNumber2));
    vlSelf->__Vcellinp__fif5fa24____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha22____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha22____pinNumber2));
    vlSelf->__Vcellinp__thi7fa25____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha22____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha22____pinNumber2));
    vlSelf->__Vcellinp__fif5fa25____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha23____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha23____pinNumber2));
    vlSelf->__Vcellinp__thi7fa26____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha23____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha23____pinNumber2));
    vlSelf->__Vcellinp__fif5fa26____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha24____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha24____pinNumber2));
    vlSelf->__Vcellinp__thi7fa27____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha24____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha24____pinNumber2));
    vlSelf->__Vcellinp__fif5fa22____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha20____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha20____pinNumber2));
    vlSelf->__Vcellinp__thi7fa23____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha20____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha20____pinNumber2));
    vlSelf->__Vcellinp__fif5fa21____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha19____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha19____pinNumber2));
    vlSelf->__Vcellinp__thi7fa22____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha19____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha19____pinNumber2));
    vlSelf->__Vcellinp__fif5fa20____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha18____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha18____pinNumber2));
    vlSelf->__Vcellinp__thi7fa21____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha18____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha18____pinNumber2));
    vlSelf->__Vcellinp__fif5fa19____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha17____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha17____pinNumber2));
    vlSelf->__Vcellinp__thi7fa20____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha17____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha17____pinNumber2));
    vlSelf->__Vcellinp__fif5fa18____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha16____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha16____pinNumber2));
    vlSelf->__Vcellinp__thi7fa19____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha16____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha16____pinNumber2));
    vlSelf->__Vcellinp__fif5fa17____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha15____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha15____pinNumber2));
    vlSelf->__Vcellinp__thi7fa18____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha15____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha15____pinNumber2));
    vlSelf->__Vcellinp__fif5fa10____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha8____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha8____pinNumber2));
    vlSelf->__Vcellinp__thi7fa11____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha8____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha8____pinNumber2));
    vlSelf->__Vcellinp__fif5fa11____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha9____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha9____pinNumber2));
    vlSelf->__Vcellinp__thi7fa12____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha9____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha9____pinNumber2));
    vlSelf->__Vcellinp__fif5fa12____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha10____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha10____pinNumber2));
    vlSelf->__Vcellinp__thi7fa13____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha10____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha10____pinNumber2));
    vlSelf->__Vcellinp__fif5fa13____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha11____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha11____pinNumber2));
    vlSelf->__Vcellinp__thi7fa14____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha11____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha11____pinNumber2));
    vlSelf->__Vcellinp__fif5fa14____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha12____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha12____pinNumber2));
    vlSelf->__Vcellinp__thi7fa15____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha12____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha12____pinNumber2));
    vlSelf->__Vcellinp__fif5fa15____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha13____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha13____pinNumber2));
    vlSelf->__Vcellinp__thi7fa16____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha13____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha13____pinNumber2));
    vlSelf->__Vcellinp__fif5fa16____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha14____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__sec11ha14____pinNumber2));
    vlSelf->__Vcellinp__thi7fa17____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha14____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha14____pinNumber2));
    vlSelf->__Vcellinp__fif5fa9____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha7____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha7____pinNumber2));
    vlSelf->__Vcellinp__thi7fa10____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha7____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec11ha7____pinNumber2));
    vlSelf->__Vcellinp__fif5fa8____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha6____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha6____pinNumber2));
    vlSelf->__Vcellinp__thi7fa9____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha6____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec11ha6____pinNumber2));
    vlSelf->__Vcellinp__fif5fa7____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha5____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha5____pinNumber2));
    vlSelf->__Vcellinp__thi7fa8____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha5____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec11ha5____pinNumber2));
    vlSelf->__Vcellinp__fif5fa6____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha4____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha4____pinNumber2));
    vlSelf->__Vcellinp__thi7fa7____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha4____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec11ha4____pinNumber2));
    vlSelf->__Vcellinp__fif5fa5____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha3____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha3____pinNumber2));
    vlSelf->__Vcellinp__thi7fa6____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha3____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec11ha3____pinNumber2));
    vlSelf->__Vcellinp__fif5fa2____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha0____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha0____pinNumber2));
    vlSelf->__Vcellinp__thi7fa3____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha0____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec11ha0____pinNumber2));
    vlSelf->__Vcellinp__fif5fa3____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha1____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha1____pinNumber2));
    vlSelf->__Vcellinp__thi7fa4____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha1____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec11ha1____pinNumber2));
    vlSelf->__Vcellinp__fif5fa4____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha2____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__sec11ha2____pinNumber2));
    vlSelf->__Vcellinp__thi7fa5____pinNumber3 = ((IData)(vlSelf->__Vcellinp__sec11ha2____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec11ha2____pinNumber2));
    vlSelf->__Vcellinp__thi2fa1____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec2ha0____pinNumber2));
    vlSelf->__Vcellinp__thi1fa3____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec2ha0____pinNumber2));
    vlSelf->__Vcellinp__thi1fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir2fa1____pinNumber5));
    vlSelf->__Vcellinp__thi2fa2____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa1____pinNumber5));
    vlSelf->__Vcellinp__thi1fa5____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir2fa2____pinNumber5));
    vlSelf->__Vcellinp__thi2fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa2____pinNumber5));
    vlSelf->__Vcellinp__fif1fa32____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec2ha31____pinNumber2));
    vlSelf->__Vcellinp__thi2fa32____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec2ha31____pinNumber2));
    vlSelf->__Vcellinp__thi1fa6____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir2fa3____pinNumber5));
    vlSelf->__Vcellinp__thi2fa4____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa3____pinNumber5));
    vlSelf->__Vcellinp__thi1fa7____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir2fa4____pinNumber5));
    vlSelf->__Vcellinp__thi2fa5____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa4____pinNumber5));
    vlSelf->__Vcellinp__thi1fa8____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir2fa5____pinNumber5));
    vlSelf->__Vcellinp__thi2fa6____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa5____pinNumber5));
    vlSelf->__Vcellinp__fou1fa32____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec2ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa30____pinNumber5));
    vlSelf->__Vcellinp__thi2fa31____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec2ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa30____pinNumber5));
    vlSelf->__Vcellinp__thi1fa9____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir2fa6____pinNumber5));
    vlSelf->__Vcellinp__thi2fa7____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa7____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa6____pinNumber5));
    vlSelf->__Vcellinp__thi1fa10____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa8____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa7____pinNumber5));
    vlSelf->__Vcellinp__thi2fa8____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa8____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa7____pinNumber5));
    vlSelf->__Vcellinp__thi1fa11____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa9____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa8____pinNumber5));
    vlSelf->__Vcellinp__thi2fa9____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa9____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir2fa8____pinNumber5));
    vlSelf->__Vcellinp__thi1fa12____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa10____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa9____pinNumber5));
    vlSelf->__Vcellinp__thi2fa10____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa9____pinNumber5));
    vlSelf->__Vcellinp__thi1fa13____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa10____pinNumber5));
    vlSelf->__Vcellinp__thi2fa11____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa10____pinNumber5));
    vlSelf->__Vcellinp__thi1fa14____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa11____pinNumber5));
    vlSelf->__Vcellinp__thi2fa12____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa11____pinNumber5));
    vlSelf->__Vcellinp__thi1fa15____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa12____pinNumber5));
    vlSelf->__Vcellinp__thi2fa13____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa12____pinNumber5));
    vlSelf->__Vcellinp__thi1fa32____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir2fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa29____pinNumber5));
    vlSelf->__Vcellinp__thi2fa30____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa29____pinNumber5));
    vlSelf->__Vcellinp__thi1fa16____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa13____pinNumber5));
    vlSelf->__Vcellinp__thi2fa14____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa13____pinNumber5));
    vlSelf->__Vcellinp__thi1fa31____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa28____pinNumber5));
    vlSelf->__Vcellinp__thi2fa29____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa28____pinNumber5));
    vlSelf->__Vcellinp__thi1fa17____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa14____pinNumber5));
    vlSelf->__Vcellinp__thi2fa15____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa14____pinNumber5));
    vlSelf->__Vcellinp__thi1fa30____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa27____pinNumber5));
    vlSelf->__Vcellinp__thi2fa28____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa27____pinNumber5));
    vlSelf->__Vcellinp__thi1fa18____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa15____pinNumber5));
    vlSelf->__Vcellinp__thi2fa16____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa15____pinNumber5));
    vlSelf->__Vcellinp__thi1fa19____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa16____pinNumber5));
    vlSelf->__Vcellinp__thi2fa17____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa16____pinNumber5));
    vlSelf->__Vcellinp__thi1fa20____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa17____pinNumber5));
    vlSelf->__Vcellinp__thi2fa18____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa17____pinNumber5));
    vlSelf->__Vcellinp__thi1fa21____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa18____pinNumber5));
    vlSelf->__Vcellinp__thi2fa19____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa18____pinNumber5));
    vlSelf->__Vcellinp__thi1fa29____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa26____pinNumber5));
    vlSelf->__Vcellinp__thi2fa27____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa26____pinNumber5));
    vlSelf->__Vcellinp__thi1fa28____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa25____pinNumber5));
    vlSelf->__Vcellinp__thi2fa26____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa25____pinNumber5));
    vlSelf->__Vcellinp__thi1fa27____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa24____pinNumber5));
    vlSelf->__Vcellinp__thi2fa25____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa24____pinNumber5));
    vlSelf->__Vcellinp__thi1fa26____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa23____pinNumber5));
    vlSelf->__Vcellinp__thi2fa24____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa23____pinNumber5));
    vlSelf->__Vcellinp__thi1fa25____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa22____pinNumber5));
    vlSelf->__Vcellinp__thi2fa23____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa22____pinNumber5));
    vlSelf->__Vcellinp__thi1fa24____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa21____pinNumber5));
    vlSelf->__Vcellinp__thi2fa22____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa21____pinNumber5));
    vlSelf->__Vcellinp__thi1fa23____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa20____pinNumber5));
    vlSelf->__Vcellinp__thi2fa21____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa20____pinNumber5));
    vlSelf->__Vcellinp__thi1fa22____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir2fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir2fa19____pinNumber5));
    vlSelf->__Vcellinp__thi2fa20____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir2fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir2fa19____pinNumber5));
    vlSelf->__Vcellinp__thi7fa32____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec10ha31____pinNumber2));
    vlSelf->__Vcellinp__thi7fa31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec10ha31____pinNumber2));
    vlSelf->__Vcellinp__thi7fa31____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec10ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa30____pinNumber5));
    vlSelf->__Vcellinp__thi7fa30____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec10ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa30____pinNumber5));
    vlSelf->__Vcellinp__sev3fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir10fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec10ha0____pinNumber2));
    vlSelf->__Vcellinp__thi7fa1____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec10ha0____pinNumber2));
    vlSelf->__Vcellinp__thi7fa30____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa29____pinNumber5));
    vlSelf->__Vcellinp__thi7fa29____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa29____pinNumber5));
    vlSelf->__Vcellinp__thi7fa29____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa28____pinNumber5));
    vlSelf->__Vcellinp__thi7fa28____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa28____pinNumber5));
    vlSelf->__Vcellinp__thi7fa28____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa27____pinNumber5));
    vlSelf->__Vcellinp__thi7fa27____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa27____pinNumber5));
    vlSelf->__Vcellinp__thi7fa26____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa26____pinNumber5));
    vlSelf->__Vcellinp__thi7fa27____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa26____pinNumber5));
    vlSelf->__Vcellinp__thi7fa25____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa25____pinNumber5));
    vlSelf->__Vcellinp__thi7fa26____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa25____pinNumber5));
    vlSelf->__Vcellinp__thi7fa24____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa24____pinNumber5));
    vlSelf->__Vcellinp__thi7fa25____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa24____pinNumber5));
    vlSelf->__Vcellinp__thi7fa24____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa23____pinNumber5));
    vlSelf->__Vcellinp__thi7fa23____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa23____pinNumber5));
    vlSelf->__Vcellinp__thi7fa23____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa22____pinNumber5));
    vlSelf->__Vcellinp__thi7fa22____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa22____pinNumber5));
    vlSelf->__Vcellinp__thi7fa22____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa21____pinNumber5));
    vlSelf->__Vcellinp__thi7fa21____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa21____pinNumber5));
    vlSelf->__Vcellinp__thi7fa21____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa20____pinNumber5));
    vlSelf->__Vcellinp__thi7fa20____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa20____pinNumber5));
    vlSelf->__Vcellinp__thi7fa20____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa19____pinNumber5));
    vlSelf->__Vcellinp__thi7fa19____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa19____pinNumber5));
    vlSelf->__Vcellinp__thi7fa19____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa18____pinNumber5));
    vlSelf->__Vcellinp__thi7fa18____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa18____pinNumber5));
    vlSelf->__Vcellinp__thi7fa18____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa17____pinNumber5));
    vlSelf->__Vcellinp__thi7fa17____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa17____pinNumber5));
    vlSelf->__Vcellinp__thi7fa16____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa16____pinNumber5));
    vlSelf->__Vcellinp__thi7fa17____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa16____pinNumber5));
    vlSelf->__Vcellinp__thi7fa15____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa15____pinNumber5));
    vlSelf->__Vcellinp__thi7fa16____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa15____pinNumber5));
    vlSelf->__Vcellinp__thi7fa14____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa14____pinNumber5));
    vlSelf->__Vcellinp__thi7fa15____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa14____pinNumber5));
    vlSelf->__Vcellinp__thi7fa13____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa13____pinNumber5));
    vlSelf->__Vcellinp__thi7fa14____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa13____pinNumber5));
    vlSelf->__Vcellinp__thi7fa12____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa12____pinNumber5));
    vlSelf->__Vcellinp__thi7fa13____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa12____pinNumber5));
    vlSelf->__Vcellinp__thi7fa11____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa11____pinNumber5));
    vlSelf->__Vcellinp__thi7fa12____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa11____pinNumber5));
    vlSelf->__Vcellinp__thi7fa11____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa10____pinNumber5));
    vlSelf->__Vcellinp__thi7fa10____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir10fa10____pinNumber5));
    vlSelf->__Vcellinp__thi7fa10____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir10fa9____pinNumber5));
    vlSelf->__Vcellinp__thi7fa9____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa10____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa9____pinNumber5));
    vlSelf->__Vcellinp__thi7fa1____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa1____pinNumber5));
    vlSelf->__Vcellinp__thi7fa2____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa1____pinNumber5));
    vlSelf->__Vcellinp__thi7fa9____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa9____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa8____pinNumber5));
    vlSelf->__Vcellinp__thi7fa8____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa9____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa8____pinNumber5));
    vlSelf->__Vcellinp__thi7fa8____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa8____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa7____pinNumber5));
    vlSelf->__Vcellinp__thi7fa7____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa8____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa7____pinNumber5));
    vlSelf->__Vcellinp__thi7fa7____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa7____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa6____pinNumber5));
    vlSelf->__Vcellinp__thi7fa6____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa6____pinNumber5));
    vlSelf->__Vcellinp__thi7fa2____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa2____pinNumber5));
    vlSelf->__Vcellinp__thi7fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa2____pinNumber5));
    vlSelf->__Vcellinp__thi7fa6____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa5____pinNumber5));
    vlSelf->__Vcellinp__thi7fa5____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa5____pinNumber5));
    vlSelf->__Vcellinp__thi7fa3____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa3____pinNumber5));
    vlSelf->__Vcellinp__thi7fa4____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa3____pinNumber5));
    vlSelf->__Vcellinp__thi7fa4____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir10fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir10fa4____pinNumber5));
    vlSelf->__Vcellinp__thi7fa5____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir10fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir10fa4____pinNumber5));
    vlSelf->__Vcellinp__thi2fa3____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec3ha0____pinNumber2));
    vlSelf->__Vcellinp__thi2fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec3ha0____pinNumber2));
    vlSelf->__Vcellinp__thi2fa4____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir3fa1____pinNumber5));
    vlSelf->__Vcellinp__thi2fa5____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir3fa1____pinNumber5));
    vlSelf->__Vcellinp__fou2fa34____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec3ha31____pinNumber2));
    vlSelf->__Vcellinp__thi2fa34____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec3ha31____pinNumber2));
    vlSelf->__Vcellinp__thi2fa5____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir3fa2____pinNumber5));
    vlSelf->__Vcellinp__thi2fa6____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir3fa2____pinNumber5));
    vlSelf->__Vcellinp__thi2fa6____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir3fa3____pinNumber5));
    vlSelf->__Vcellinp__thi2fa7____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir3fa3____pinNumber5));
    vlSelf->__Vcellinp__thi2fa7____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir3fa4____pinNumber5));
    vlSelf->__Vcellinp__thi2fa8____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir3fa4____pinNumber5));
    vlSelf->__Vcellinp__thi2fa8____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir3fa5____pinNumber5));
    vlSelf->__Vcellinp__thi2fa9____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir3fa5____pinNumber5));
    vlSelf->__Vcellinp__thi2fa34____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec3ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa30____pinNumber5));
    vlSelf->__Vcellinp__thi2fa33____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec3ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa30____pinNumber5));
    vlSelf->__Vcellinp__thi2fa9____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir3fa6____pinNumber5));
    vlSelf->__Vcellinp__thi2fa10____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa7____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa6____pinNumber5));
    vlSelf->__Vcellinp__thi2fa10____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa8____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa7____pinNumber5));
    vlSelf->__Vcellinp__thi2fa11____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa8____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa7____pinNumber5));
    vlSelf->__Vcellinp__thi2fa11____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa9____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa8____pinNumber5));
    vlSelf->__Vcellinp__thi2fa12____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa9____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa8____pinNumber5));
    vlSelf->__Vcellinp__thi2fa33____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa29____pinNumber5));
    vlSelf->__Vcellinp__thi2fa32____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa29____pinNumber5));
    vlSelf->__Vcellinp__thi2fa12____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa10____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa9____pinNumber5));
    vlSelf->__Vcellinp__thi2fa13____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa9____pinNumber5));
    vlSelf->__Vcellinp__thi2fa32____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa28____pinNumber5));
    vlSelf->__Vcellinp__thi2fa31____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa28____pinNumber5));
    vlSelf->__Vcellinp__thi2fa31____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa27____pinNumber5));
    vlSelf->__Vcellinp__thi2fa30____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa27____pinNumber5));
    vlSelf->__Vcellinp__thi2fa13____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa10____pinNumber5));
    vlSelf->__Vcellinp__thi2fa14____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa10____pinNumber5));
    vlSelf->__Vcellinp__thi2fa30____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa26____pinNumber5));
    vlSelf->__Vcellinp__thi2fa29____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa26____pinNumber5));
    vlSelf->__Vcellinp__thi2fa14____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa11____pinNumber5));
    vlSelf->__Vcellinp__thi2fa15____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa11____pinNumber5));
    vlSelf->__Vcellinp__thi2fa29____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa25____pinNumber5));
    vlSelf->__Vcellinp__thi2fa28____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa25____pinNumber5));
    vlSelf->__Vcellinp__thi2fa15____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa12____pinNumber5));
    vlSelf->__Vcellinp__thi2fa16____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa12____pinNumber5));
    vlSelf->__Vcellinp__thi2fa28____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa24____pinNumber5));
    vlSelf->__Vcellinp__thi2fa27____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa24____pinNumber5));
    vlSelf->__Vcellinp__thi2fa16____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa13____pinNumber5));
    vlSelf->__Vcellinp__thi2fa17____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa13____pinNumber5));
    vlSelf->__Vcellinp__thi2fa17____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa14____pinNumber5));
    vlSelf->__Vcellinp__thi2fa18____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa14____pinNumber5));
    vlSelf->__Vcellinp__thi2fa18____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa15____pinNumber5));
    vlSelf->__Vcellinp__thi2fa19____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa15____pinNumber5));
    vlSelf->__Vcellinp__thi2fa19____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa16____pinNumber5));
    vlSelf->__Vcellinp__thi2fa20____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa16____pinNumber5));
    vlSelf->__Vcellinp__thi2fa26____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa23____pinNumber5));
    vlSelf->__Vcellinp__thi2fa27____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa23____pinNumber5));
    vlSelf->__Vcellinp__thi2fa25____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa22____pinNumber5));
    vlSelf->__Vcellinp__thi2fa26____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa22____pinNumber5));
    vlSelf->__Vcellinp__thi2fa24____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa21____pinNumber5));
    vlSelf->__Vcellinp__thi2fa25____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa21____pinNumber5));
    vlSelf->__Vcellinp__thi2fa23____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa20____pinNumber5));
    vlSelf->__Vcellinp__thi2fa24____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa20____pinNumber5));
    vlSelf->__Vcellinp__thi2fa22____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa19____pinNumber5));
    vlSelf->__Vcellinp__thi2fa23____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa19____pinNumber5));
    vlSelf->__Vcellinp__thi2fa21____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa18____pinNumber5));
    vlSelf->__Vcellinp__thi2fa22____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa18____pinNumber5));
    vlSelf->__Vcellinp__thi2fa20____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir3fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir3fa17____pinNumber5));
    vlSelf->__Vcellinp__thi2fa21____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir3fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir3fa17____pinNumber5));
    vlSelf->__Vcellinp__fou4fa34____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec6ha31____pinNumber2));
    vlSelf->__Vcellinp__thi4fa34____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec6ha31____pinNumber2));
    vlSelf->__Vcellinp__thi4fa34____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec6ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa30____pinNumber5));
    vlSelf->__Vcellinp__thi4fa33____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec6ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa30____pinNumber5));
    vlSelf->__Vcellinp__thi4fa33____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa29____pinNumber5));
    vlSelf->__Vcellinp__thi4fa32____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa29____pinNumber5));
    vlSelf->__Vcellinp__thi4fa32____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa28____pinNumber5));
    vlSelf->__Vcellinp__thi4fa31____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa28____pinNumber5));
    vlSelf->__Vcellinp__thi4fa31____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa27____pinNumber5));
    vlSelf->__Vcellinp__thi4fa30____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa27____pinNumber5));
    vlSelf->__Vcellinp__thi4fa30____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa26____pinNumber5));
    vlSelf->__Vcellinp__thi4fa29____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa26____pinNumber5));
    vlSelf->__Vcellinp__thi4fa29____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa25____pinNumber5));
    vlSelf->__Vcellinp__thi4fa28____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa25____pinNumber5));
    vlSelf->__Vcellinp__thi4fa27____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa24____pinNumber5));
    vlSelf->__Vcellinp__thi4fa28____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa24____pinNumber5));
    vlSelf->__Vcellinp__thi4fa26____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa23____pinNumber5));
    vlSelf->__Vcellinp__thi4fa27____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa23____pinNumber5));
    vlSelf->__Vcellinp__thi4fa26____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa22____pinNumber5));
    vlSelf->__Vcellinp__thi4fa25____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa22____pinNumber5));
    vlSelf->__Vcellinp__thi4fa3____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec6ha0____pinNumber2));
    vlSelf->__Vcellinp__thi4fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec6ha0____pinNumber2));
    vlSelf->__Vcellinp__thi4fa25____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa21____pinNumber5));
    vlSelf->__Vcellinp__thi4fa24____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa21____pinNumber5));
    vlSelf->__Vcellinp__thi4fa4____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir6fa1____pinNumber5));
    vlSelf->__Vcellinp__thi4fa5____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir6fa1____pinNumber5));
    vlSelf->__Vcellinp__thi4fa24____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa20____pinNumber5));
    vlSelf->__Vcellinp__thi4fa23____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa20____pinNumber5));
    vlSelf->__Vcellinp__thi4fa5____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir6fa2____pinNumber5));
    vlSelf->__Vcellinp__thi4fa6____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir6fa2____pinNumber5));
    vlSelf->__Vcellinp__thi4fa23____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa19____pinNumber5));
    vlSelf->__Vcellinp__thi4fa22____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa19____pinNumber5));
    vlSelf->__Vcellinp__thi4fa6____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir6fa3____pinNumber5));
    vlSelf->__Vcellinp__thi4fa7____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir6fa3____pinNumber5));
    vlSelf->__Vcellinp__thi4fa22____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa18____pinNumber5));
    vlSelf->__Vcellinp__thi4fa21____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa18____pinNumber5));
    vlSelf->__Vcellinp__thi4fa7____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir6fa4____pinNumber5));
    vlSelf->__Vcellinp__thi4fa8____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir6fa4____pinNumber5));
    vlSelf->__Vcellinp__thi4fa21____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa17____pinNumber5));
    vlSelf->__Vcellinp__thi4fa20____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa17____pinNumber5));
    vlSelf->__Vcellinp__thi4fa8____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir6fa5____pinNumber5));
    vlSelf->__Vcellinp__thi4fa9____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir6fa5____pinNumber5));
    vlSelf->__Vcellinp__thi4fa20____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa16____pinNumber5));
    vlSelf->__Vcellinp__thi4fa19____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa16____pinNumber5));
    vlSelf->__Vcellinp__thi4fa9____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir6fa6____pinNumber5));
    vlSelf->__Vcellinp__thi4fa10____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa7____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa6____pinNumber5));
    vlSelf->__Vcellinp__thi4fa10____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa8____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa7____pinNumber5));
    vlSelf->__Vcellinp__thi4fa11____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa8____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa7____pinNumber5));
    vlSelf->__Vcellinp__thi4fa11____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa9____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa8____pinNumber5));
    vlSelf->__Vcellinp__thi4fa12____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa9____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa8____pinNumber5));
    vlSelf->__Vcellinp__thi4fa12____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa10____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa9____pinNumber5));
    vlSelf->__Vcellinp__thi4fa13____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa9____pinNumber5));
    vlSelf->__Vcellinp__thi4fa18____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa15____pinNumber5));
    vlSelf->__Vcellinp__thi4fa19____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa15____pinNumber5));
    vlSelf->__Vcellinp__thi4fa17____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa14____pinNumber5));
    vlSelf->__Vcellinp__thi4fa18____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa14____pinNumber5));
    vlSelf->__Vcellinp__thi4fa16____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa13____pinNumber5));
    vlSelf->__Vcellinp__thi4fa17____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa13____pinNumber5));
    vlSelf->__Vcellinp__thi4fa15____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa12____pinNumber5));
    vlSelf->__Vcellinp__thi4fa16____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa12____pinNumber5));
    vlSelf->__Vcellinp__thi4fa14____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa11____pinNumber5));
    vlSelf->__Vcellinp__thi4fa15____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa11____pinNumber5));
    vlSelf->__Vcellinp__thi4fa13____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir6fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir6fa10____pinNumber5));
    vlSelf->__Vcellinp__thi4fa14____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir6fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir6fa10____pinNumber5));
    vlSelf->__Vcellinp__fif2fa37____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec5ha31____pinNumber2));
    vlSelf->__Vcellinp__thi4fa32____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec5ha31____pinNumber2));
    vlSelf->__Vcellinp__fou3fa32____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec5ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa30____pinNumber5));
    vlSelf->__Vcellinp__thi4fa31____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec5ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa30____pinNumber5));
    vlSelf->__Vcellinp__thi4fa1____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec5ha0____pinNumber2));
    vlSelf->__Vcellinp__thi3fa3____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec5ha0____pinNumber2));
    vlSelf->__Vcellinp__thi4fa30____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa29____pinNumber5));
    vlSelf->__Vcellinp__thi3fa32____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir5fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa29____pinNumber5));
    vlSelf->__Vcellinp__thi4fa29____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa28____pinNumber5));
    vlSelf->__Vcellinp__thi3fa31____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa28____pinNumber5));
    vlSelf->__Vcellinp__thi4fa28____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa27____pinNumber5));
    vlSelf->__Vcellinp__thi3fa30____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa27____pinNumber5));
    vlSelf->__Vcellinp__thi4fa27____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa26____pinNumber5));
    vlSelf->__Vcellinp__thi3fa29____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa26____pinNumber5));
    vlSelf->__Vcellinp__thi4fa26____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa25____pinNumber5));
    vlSelf->__Vcellinp__thi3fa28____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa25____pinNumber5));
    vlSelf->__Vcellinp__thi4fa2____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa1____pinNumber5));
    vlSelf->__Vcellinp__thi3fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir5fa1____pinNumber5));
    vlSelf->__Vcellinp__thi4fa25____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa24____pinNumber5));
    vlSelf->__Vcellinp__thi3fa27____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa24____pinNumber5));
    vlSelf->__Vcellinp__thi4fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa2____pinNumber5));
    vlSelf->__Vcellinp__thi3fa5____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir5fa2____pinNumber5));
    vlSelf->__Vcellinp__thi4fa4____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa3____pinNumber5));
    vlSelf->__Vcellinp__thi3fa6____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir5fa3____pinNumber5));
    vlSelf->__Vcellinp__thi4fa24____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa23____pinNumber5));
    vlSelf->__Vcellinp__thi3fa26____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa23____pinNumber5));
    vlSelf->__Vcellinp__thi4fa5____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa4____pinNumber5));
    vlSelf->__Vcellinp__thi3fa7____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir5fa4____pinNumber5));
    vlSelf->__Vcellinp__thi4fa23____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa22____pinNumber5));
    vlSelf->__Vcellinp__thi3fa25____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa22____pinNumber5));
    vlSelf->__Vcellinp__thi4fa6____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa5____pinNumber5));
    vlSelf->__Vcellinp__thi3fa8____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir5fa5____pinNumber5));
    vlSelf->__Vcellinp__thi4fa22____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa21____pinNumber5));
    vlSelf->__Vcellinp__thi3fa24____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa21____pinNumber5));
    vlSelf->__Vcellinp__thi4fa7____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa7____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa6____pinNumber5));
    vlSelf->__Vcellinp__thi3fa9____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir5fa6____pinNumber5));
    vlSelf->__Vcellinp__thi4fa21____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa20____pinNumber5));
    vlSelf->__Vcellinp__thi3fa23____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa20____pinNumber5));
    vlSelf->__Vcellinp__thi4fa8____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa8____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa7____pinNumber5));
    vlSelf->__Vcellinp__thi3fa10____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa8____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa7____pinNumber5));
    vlSelf->__Vcellinp__thi4fa20____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa19____pinNumber5));
    vlSelf->__Vcellinp__thi3fa22____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa19____pinNumber5));
    vlSelf->__Vcellinp__thi4fa9____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa9____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir5fa8____pinNumber5));
    vlSelf->__Vcellinp__thi3fa11____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa9____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa8____pinNumber5));
    vlSelf->__Vcellinp__thi4fa10____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa9____pinNumber5));
    vlSelf->__Vcellinp__thi3fa12____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa10____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa9____pinNumber5));
    vlSelf->__Vcellinp__thi4fa11____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa10____pinNumber5));
    vlSelf->__Vcellinp__thi3fa13____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa10____pinNumber5));
    vlSelf->__Vcellinp__thi4fa12____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa11____pinNumber5));
    vlSelf->__Vcellinp__thi3fa14____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa11____pinNumber5));
    vlSelf->__Vcellinp__thi4fa19____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa18____pinNumber5));
    vlSelf->__Vcellinp__thi3fa21____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa18____pinNumber5));
    vlSelf->__Vcellinp__thi4fa18____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa17____pinNumber5));
    vlSelf->__Vcellinp__thi3fa20____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa17____pinNumber5));
    vlSelf->__Vcellinp__thi4fa17____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa16____pinNumber5));
    vlSelf->__Vcellinp__thi3fa19____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa16____pinNumber5));
    vlSelf->__Vcellinp__thi4fa16____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa15____pinNumber5));
    vlSelf->__Vcellinp__thi3fa18____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa15____pinNumber5));
    vlSelf->__Vcellinp__thi4fa15____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa14____pinNumber5));
    vlSelf->__Vcellinp__thi3fa17____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa14____pinNumber5));
    vlSelf->__Vcellinp__thi4fa14____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa13____pinNumber5));
    vlSelf->__Vcellinp__thi3fa16____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa13____pinNumber5));
    vlSelf->__Vcellinp__thi4fa13____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir5fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir5fa12____pinNumber5));
    vlSelf->__Vcellinp__thi3fa15____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir5fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir5fa12____pinNumber5));
    vlSelf->__Vcellinp__fif2fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec4ha0____pinNumber2));
    vlSelf->__Vcellinp__thi3fa1____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec4ha0____pinNumber2));
    vlSelf->__Vcellinp__thi3fa1____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa1____pinNumber5));
    vlSelf->__Vcellinp__thi3fa2____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa1____pinNumber5));
    vlSelf->__Vcellinp__thi3fa32____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec4ha31____pinNumber2));
    vlSelf->__Vcellinp__thi3fa31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec4ha31____pinNumber2));
    vlSelf->__Vcellinp__thi3fa31____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec4ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa30____pinNumber5));
    vlSelf->__Vcellinp__thi3fa30____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec4ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa30____pinNumber5));
    vlSelf->__Vcellinp__thi3fa30____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa29____pinNumber5));
    vlSelf->__Vcellinp__thi3fa29____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa29____pinNumber5));
    vlSelf->__Vcellinp__thi3fa29____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa28____pinNumber5));
    vlSelf->__Vcellinp__thi3fa28____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa28____pinNumber5));
    vlSelf->__Vcellinp__thi3fa28____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa27____pinNumber5));
    vlSelf->__Vcellinp__thi3fa27____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa27____pinNumber5));
    vlSelf->__Vcellinp__thi3fa2____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa2____pinNumber5));
    vlSelf->__Vcellinp__thi3fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa2____pinNumber5));
    vlSelf->__Vcellinp__thi3fa27____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa26____pinNumber5));
    vlSelf->__Vcellinp__thi3fa26____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa26____pinNumber5));
    vlSelf->__Vcellinp__thi3fa3____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa3____pinNumber5));
    vlSelf->__Vcellinp__thi3fa4____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa3____pinNumber5));
    vlSelf->__Vcellinp__thi3fa4____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa4____pinNumber5));
    vlSelf->__Vcellinp__thi3fa5____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa4____pinNumber5));
    vlSelf->__Vcellinp__thi3fa5____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa5____pinNumber5));
    vlSelf->__Vcellinp__thi3fa6____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa5____pinNumber5));
    vlSelf->__Vcellinp__thi3fa6____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa6____pinNumber5));
    vlSelf->__Vcellinp__thi3fa7____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa7____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa6____pinNumber5));
    vlSelf->__Vcellinp__thi3fa26____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa25____pinNumber5));
    vlSelf->__Vcellinp__thi3fa25____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa25____pinNumber5));
    vlSelf->__Vcellinp__thi3fa7____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa8____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa7____pinNumber5));
    vlSelf->__Vcellinp__thi3fa8____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa8____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa7____pinNumber5));
    vlSelf->__Vcellinp__thi3fa25____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa24____pinNumber5));
    vlSelf->__Vcellinp__thi3fa24____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa24____pinNumber5));
    vlSelf->__Vcellinp__thi3fa8____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa9____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa8____pinNumber5));
    vlSelf->__Vcellinp__thi3fa9____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa9____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir4fa8____pinNumber5));
    vlSelf->__Vcellinp__thi3fa24____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa23____pinNumber5));
    vlSelf->__Vcellinp__thi3fa23____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa23____pinNumber5));
    vlSelf->__Vcellinp__thi3fa9____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa10____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir4fa9____pinNumber5));
    vlSelf->__Vcellinp__thi3fa10____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa9____pinNumber5));
    vlSelf->__Vcellinp__thi3fa23____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa22____pinNumber5));
    vlSelf->__Vcellinp__thi3fa22____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa22____pinNumber5));
    vlSelf->__Vcellinp__thi3fa10____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa10____pinNumber5));
    vlSelf->__Vcellinp__thi3fa11____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa10____pinNumber5));
    vlSelf->__Vcellinp__thi3fa22____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa21____pinNumber5));
    vlSelf->__Vcellinp__thi3fa21____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa21____pinNumber5));
    vlSelf->__Vcellinp__thi3fa11____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa11____pinNumber5));
    vlSelf->__Vcellinp__thi3fa12____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa11____pinNumber5));
    vlSelf->__Vcellinp__thi3fa12____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa12____pinNumber5));
    vlSelf->__Vcellinp__thi3fa13____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa12____pinNumber5));
    vlSelf->__Vcellinp__thi3fa13____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa13____pinNumber5));
    vlSelf->__Vcellinp__thi3fa14____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa13____pinNumber5));
    vlSelf->__Vcellinp__thi3fa14____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa14____pinNumber5));
    vlSelf->__Vcellinp__thi3fa15____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa14____pinNumber5));
    vlSelf->__Vcellinp__thi3fa20____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa20____pinNumber5));
    vlSelf->__Vcellinp__thi3fa21____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa20____pinNumber5));
    vlSelf->__Vcellinp__thi3fa19____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa19____pinNumber5));
    vlSelf->__Vcellinp__thi3fa20____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa19____pinNumber5));
    vlSelf->__Vcellinp__thi3fa18____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa18____pinNumber5));
    vlSelf->__Vcellinp__thi3fa19____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa18____pinNumber5));
    vlSelf->__Vcellinp__thi3fa17____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa17____pinNumber5));
    vlSelf->__Vcellinp__thi3fa18____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa17____pinNumber5));
    vlSelf->__Vcellinp__thi3fa16____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa16____pinNumber5));
    vlSelf->__Vcellinp__thi3fa17____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa16____pinNumber5));
    vlSelf->__Vcellinp__thi3fa15____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir4fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir4fa15____pinNumber5));
    vlSelf->__Vcellinp__thi3fa16____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir4fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir4fa15____pinNumber5));
    vlSelf->__Vcellinp__fif3fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir7fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec7ha0____pinNumber2));
    vlSelf->__Vcellinp__thi5fa1____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec7ha0____pinNumber2));
    vlSelf->__Vcellinp__thi5fa1____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa1____pinNumber5));
    vlSelf->__Vcellinp__thi5fa2____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa1____pinNumber5));
    vlSelf->__Vcellinp__thi5fa2____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa2____pinNumber5));
    vlSelf->__Vcellinp__thi5fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa2____pinNumber5));
    vlSelf->__Vcellinp__thi5fa29____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa28____pinNumber5));
    vlSelf->__Vcellinp__thi5fa28____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa28____pinNumber5));
    vlSelf->__Vcellinp__thi5fa29____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa29____pinNumber5));
    vlSelf->__Vcellinp__thi5fa30____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa29____pinNumber5));
    vlSelf->__Vcellinp__thi5fa28____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa27____pinNumber5));
    vlSelf->__Vcellinp__thi5fa27____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa27____pinNumber5));
    vlSelf->__Vcellinp__thi5fa27____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa26____pinNumber5));
    vlSelf->__Vcellinp__thi5fa26____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa26____pinNumber5));
    vlSelf->__Vcellinp__thi5fa26____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa25____pinNumber5));
    vlSelf->__Vcellinp__thi5fa25____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa25____pinNumber5));
    vlSelf->__Vcellinp__thi5fa25____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa24____pinNumber5));
    vlSelf->__Vcellinp__thi5fa24____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa24____pinNumber5));
    vlSelf->__Vcellinp__thi5fa24____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa23____pinNumber5));
    vlSelf->__Vcellinp__thi5fa23____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa23____pinNumber5));
    vlSelf->__Vcellinp__thi5fa22____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa22____pinNumber5));
    vlSelf->__Vcellinp__thi5fa23____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa22____pinNumber5));
    vlSelf->__Vcellinp__thi5fa21____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa21____pinNumber5));
    vlSelf->__Vcellinp__thi5fa22____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa21____pinNumber5));
    vlSelf->__Vcellinp__thi5fa20____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa20____pinNumber5));
    vlSelf->__Vcellinp__thi5fa21____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa20____pinNumber5));
    vlSelf->__Vcellinp__thi5fa20____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa19____pinNumber5));
    vlSelf->__Vcellinp__thi5fa19____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa19____pinNumber5));
    vlSelf->__Vcellinp__thi5fa19____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa18____pinNumber5));
    vlSelf->__Vcellinp__thi5fa18____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa18____pinNumber5));
    vlSelf->__Vcellinp__thi5fa30____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec7ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa30____pinNumber5));
    vlSelf->__Vcellinp__thi5fa31____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec7ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa30____pinNumber5));
    vlSelf->__Vcellinp__thi5fa18____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa17____pinNumber5));
    vlSelf->__Vcellinp__thi5fa17____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa17____pinNumber5));
    vlSelf->__Vcellinp__thi5fa32____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec7ha31____pinNumber2));
    vlSelf->__Vcellinp__thi5fa31____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec7ha31____pinNumber2));
    vlSelf->__Vcellinp__thi5fa3____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa3____pinNumber5));
    vlSelf->__Vcellinp__thi5fa4____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa3____pinNumber5));
    vlSelf->__Vcellinp__thi5fa17____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa16____pinNumber5));
    vlSelf->__Vcellinp__thi5fa16____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa16____pinNumber5));
    vlSelf->__Vcellinp__thi5fa16____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa15____pinNumber5));
    vlSelf->__Vcellinp__thi5fa15____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa15____pinNumber5));
    vlSelf->__Vcellinp__thi5fa4____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa4____pinNumber5));
    vlSelf->__Vcellinp__thi5fa5____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa4____pinNumber5));
    vlSelf->__Vcellinp__thi5fa15____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa14____pinNumber5));
    vlSelf->__Vcellinp__thi5fa14____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa14____pinNumber5));
    vlSelf->__Vcellinp__thi5fa14____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa13____pinNumber5));
    vlSelf->__Vcellinp__thi5fa13____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa13____pinNumber5));
    vlSelf->__Vcellinp__thi5fa5____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa5____pinNumber5));
    vlSelf->__Vcellinp__thi5fa6____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa5____pinNumber5));
    vlSelf->__Vcellinp__thi5fa13____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa12____pinNumber5));
    vlSelf->__Vcellinp__thi5fa12____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa12____pinNumber5));
    vlSelf->__Vcellinp__thi5fa6____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa6____pinNumber5));
    vlSelf->__Vcellinp__thi5fa7____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa7____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa6____pinNumber5));
    vlSelf->__Vcellinp__thi5fa7____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa8____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa7____pinNumber5));
    vlSelf->__Vcellinp__thi5fa8____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa8____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa7____pinNumber5));
    vlSelf->__Vcellinp__thi5fa8____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa9____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa8____pinNumber5));
    vlSelf->__Vcellinp__thi5fa9____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa9____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir7fa8____pinNumber5));
    vlSelf->__Vcellinp__thi5fa9____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa10____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir7fa9____pinNumber5));
    vlSelf->__Vcellinp__thi5fa10____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa9____pinNumber5));
    vlSelf->__Vcellinp__thi5fa10____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa10____pinNumber5));
    vlSelf->__Vcellinp__thi5fa11____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa10____pinNumber5));
    vlSelf->__Vcellinp__thi5fa11____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir7fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir7fa11____pinNumber5));
    vlSelf->__Vcellinp__thi5fa12____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir7fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir7fa11____pinNumber5));
    vlSelf->__Vcellinp__six4fa30____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec8ha31____pinNumber2));
    vlSelf->__Vcellinp__thi6fa32____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec8ha31____pinNumber2));
    vlSelf->__Vcellinp__fou5fa32____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec8ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa30____pinNumber5));
    vlSelf->__Vcellinp__thi6fa31____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec8ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa30____pinNumber5));
    vlSelf->__Vcellinp__thi5fa3____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec8ha0____pinNumber2));
    vlSelf->__Vcellinp__thi6fa1____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec8ha0____pinNumber2));
    vlSelf->__Vcellinp__thi5fa29____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa26____pinNumber5));
    vlSelf->__Vcellinp__thi6fa27____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa26____pinNumber5));
    vlSelf->__Vcellinp__thi5fa28____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa25____pinNumber5));
    vlSelf->__Vcellinp__thi6fa26____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa25____pinNumber5));
    vlSelf->__Vcellinp__thi5fa27____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa24____pinNumber5));
    vlSelf->__Vcellinp__thi6fa25____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa24____pinNumber5));
    vlSelf->__Vcellinp__thi5fa26____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa23____pinNumber5));
    vlSelf->__Vcellinp__thi6fa24____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa23____pinNumber5));
    vlSelf->__Vcellinp__thi5fa25____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa22____pinNumber5));
    vlSelf->__Vcellinp__thi6fa23____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa22____pinNumber5));
    vlSelf->__Vcellinp__thi5fa24____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa21____pinNumber5));
    vlSelf->__Vcellinp__thi6fa22____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa21____pinNumber5));
    vlSelf->__Vcellinp__thi5fa23____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa20____pinNumber5));
    vlSelf->__Vcellinp__thi6fa21____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa20____pinNumber5));
    vlSelf->__Vcellinp__thi5fa22____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa19____pinNumber5));
    vlSelf->__Vcellinp__thi6fa20____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa19____pinNumber5));
    vlSelf->__Vcellinp__thi5fa21____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa18____pinNumber5));
    vlSelf->__Vcellinp__thi6fa19____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa18____pinNumber5));
    vlSelf->__Vcellinp__thi5fa20____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa17____pinNumber5));
    vlSelf->__Vcellinp__thi6fa18____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa17____pinNumber5));
    vlSelf->__Vcellinp__thi5fa19____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa16____pinNumber5));
    vlSelf->__Vcellinp__thi6fa17____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa16____pinNumber5));
    vlSelf->__Vcellinp__thi5fa30____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa27____pinNumber5));
    vlSelf->__Vcellinp__thi6fa28____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa27____pinNumber5));
    vlSelf->__Vcellinp__thi5fa18____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa15____pinNumber5));
    vlSelf->__Vcellinp__thi6fa16____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa15____pinNumber5));
    vlSelf->__Vcellinp__thi5fa32____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir8fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa29____pinNumber5));
    vlSelf->__Vcellinp__thi6fa30____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa29____pinNumber5));
    vlSelf->__Vcellinp__thi5fa31____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa28____pinNumber5));
    vlSelf->__Vcellinp__thi6fa29____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa28____pinNumber5));
    vlSelf->__Vcellinp__thi5fa17____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa14____pinNumber5));
    vlSelf->__Vcellinp__thi6fa15____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa14____pinNumber5));
    vlSelf->__Vcellinp__thi5fa16____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa13____pinNumber5));
    vlSelf->__Vcellinp__thi6fa14____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa13____pinNumber5));
    vlSelf->__Vcellinp__thi5fa15____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa12____pinNumber5));
    vlSelf->__Vcellinp__thi6fa13____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa12____pinNumber5));
    vlSelf->__Vcellinp__thi5fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir8fa1____pinNumber5));
    vlSelf->__Vcellinp__thi6fa2____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa1____pinNumber5));
    vlSelf->__Vcellinp__thi5fa14____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa11____pinNumber5));
    vlSelf->__Vcellinp__thi6fa12____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa11____pinNumber5));
    vlSelf->__Vcellinp__thi5fa5____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir8fa2____pinNumber5));
    vlSelf->__Vcellinp__thi6fa3____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa2____pinNumber5));
    vlSelf->__Vcellinp__thi5fa13____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa10____pinNumber5));
    vlSelf->__Vcellinp__thi6fa11____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa10____pinNumber5));
    vlSelf->__Vcellinp__thi5fa12____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa10____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa9____pinNumber5));
    vlSelf->__Vcellinp__thi6fa10____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir8fa9____pinNumber5));
    vlSelf->__Vcellinp__thi5fa6____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir8fa3____pinNumber5));
    vlSelf->__Vcellinp__thi6fa4____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa3____pinNumber5));
    vlSelf->__Vcellinp__thi5fa7____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir8fa4____pinNumber5));
    vlSelf->__Vcellinp__thi6fa5____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa4____pinNumber5));
    vlSelf->__Vcellinp__thi5fa8____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir8fa5____pinNumber5));
    vlSelf->__Vcellinp__thi6fa6____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa5____pinNumber5));
    vlSelf->__Vcellinp__thi5fa9____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir8fa6____pinNumber5));
    vlSelf->__Vcellinp__thi6fa7____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa7____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa6____pinNumber5));
    vlSelf->__Vcellinp__thi5fa10____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa8____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa7____pinNumber5));
    vlSelf->__Vcellinp__thi6fa8____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa8____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa7____pinNumber5));
    vlSelf->__Vcellinp__thi5fa11____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir8fa9____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir8fa8____pinNumber5));
    vlSelf->__Vcellinp__thi6fa9____pinNumber1 = ((IData)(vlSelf->__Vcellout__fir8fa9____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir8fa8____pinNumber5));
    vlSelf->__Vcellinp__fou6fa34____pinNumber2 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                   >> 0x1fU) 
                                                  & (IData)(vlSelf->__Vcellinp__sec9ha31____pinNumber2));
    vlSelf->__Vcellinp__thi6fa34____pinNumber1 = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                   >> 0x1fU) 
                                                  ^ (IData)(vlSelf->__Vcellinp__sec9ha31____pinNumber2));
    vlSelf->__Vcellinp__thi6fa34____pinNumber2 = ((IData)(vlSelf->__Vcellinp__sec9ha30____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa30____pinNumber5));
    vlSelf->__Vcellinp__thi6fa33____pinNumber1 = ((IData)(vlSelf->__Vcellinp__sec9ha30____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa30____pinNumber5));
    vlSelf->__Vcellinp__thi6fa33____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa30____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa29____pinNumber5));
    vlSelf->__Vcellinp__thi6fa32____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa30____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa29____pinNumber5));
    vlSelf->__Vcellinp__thi6fa32____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa29____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa28____pinNumber5));
    vlSelf->__Vcellinp__thi6fa31____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa29____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa28____pinNumber5));
    vlSelf->__Vcellinp__thi6fa31____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa28____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa27____pinNumber5));
    vlSelf->__Vcellinp__thi6fa30____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa28____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa27____pinNumber5));
    vlSelf->__Vcellinp__thi6fa30____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa27____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa26____pinNumber5));
    vlSelf->__Vcellinp__thi6fa29____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa27____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa26____pinNumber5));
    vlSelf->__Vcellinp__thi6fa29____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa26____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa25____pinNumber5));
    vlSelf->__Vcellinp__thi6fa28____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa26____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa25____pinNumber5));
    vlSelf->__Vcellinp__thi6fa28____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa25____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa24____pinNumber5));
    vlSelf->__Vcellinp__thi6fa27____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa25____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa24____pinNumber5));
    vlSelf->__Vcellinp__thi6fa27____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa24____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa23____pinNumber5));
    vlSelf->__Vcellinp__thi6fa26____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa24____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa23____pinNumber5));
    vlSelf->__Vcellinp__thi6fa26____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa23____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa22____pinNumber5));
    vlSelf->__Vcellinp__thi6fa25____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa23____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa22____pinNumber5));
    vlSelf->__Vcellinp__thi6fa25____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa22____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa21____pinNumber5));
    vlSelf->__Vcellinp__thi6fa24____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa22____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa21____pinNumber5));
    vlSelf->__Vcellinp__thi6fa24____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa21____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa20____pinNumber5));
    vlSelf->__Vcellinp__thi6fa23____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa21____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa20____pinNumber5));
    vlSelf->__Vcellinp__thi6fa23____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa20____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa19____pinNumber5));
    vlSelf->__Vcellinp__thi6fa22____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa20____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa19____pinNumber5));
    vlSelf->__Vcellinp__thi6fa22____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa19____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa18____pinNumber5));
    vlSelf->__Vcellinp__thi6fa21____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa19____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa18____pinNumber5));
    vlSelf->__Vcellinp__thi6fa20____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa18____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa17____pinNumber5));
    vlSelf->__Vcellinp__thi6fa21____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa18____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa17____pinNumber5));
    vlSelf->__Vcellinp__thi6fa19____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa17____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa16____pinNumber5));
    vlSelf->__Vcellinp__thi6fa20____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa17____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa16____pinNumber5));
    vlSelf->__Vcellinp__thi6fa18____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa16____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa15____pinNumber5));
    vlSelf->__Vcellinp__thi6fa19____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa16____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa15____pinNumber5));
    vlSelf->__Vcellinp__thi6fa17____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa15____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa14____pinNumber5));
    vlSelf->__Vcellinp__thi6fa18____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa15____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa14____pinNumber5));
    vlSelf->__Vcellinp__thi6fa17____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa14____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa13____pinNumber5));
    vlSelf->__Vcellinp__thi6fa16____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa14____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa13____pinNumber5));
    vlSelf->__Vcellinp__thi6fa16____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa13____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa12____pinNumber5));
    vlSelf->__Vcellinp__thi6fa15____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa13____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa12____pinNumber5));
    vlSelf->__Vcellinp__thi6fa15____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa12____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa11____pinNumber5));
    vlSelf->__Vcellinp__thi6fa14____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa12____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa11____pinNumber5));
    vlSelf->__Vcellinp__thi6fa14____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa11____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa10____pinNumber5));
    vlSelf->__Vcellinp__thi6fa13____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa11____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa10____pinNumber5));
    vlSelf->__Vcellinp__thi6fa13____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa10____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa9____pinNumber5));
    vlSelf->__Vcellinp__thi6fa12____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa10____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa9____pinNumber5));
    vlSelf->__Vcellinp__thi6fa12____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa9____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa8____pinNumber5));
    vlSelf->__Vcellinp__thi6fa11____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa9____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa8____pinNumber5));
    vlSelf->__Vcellinp__thi6fa11____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa8____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa7____pinNumber5));
    vlSelf->__Vcellinp__thi6fa10____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa8____pinNumber4) 
                                                  ^ (IData)(vlSelf->__Vcellout__fir9fa7____pinNumber5));
    vlSelf->__Vcellinp__thi6fa3____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa1____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellinp__sec9ha0____pinNumber2));
    vlSelf->__Vcellinp__thi6fa4____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa1____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellinp__sec9ha0____pinNumber2));
    vlSelf->__Vcellinp__thi6fa10____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa7____pinNumber4) 
                                                  & (IData)(vlSelf->__Vcellout__fir9fa6____pinNumber5));
    vlSelf->__Vcellinp__thi6fa9____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa7____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir9fa6____pinNumber5));
    vlSelf->__Vcellinp__thi6fa4____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa2____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir9fa1____pinNumber5));
    vlSelf->__Vcellinp__thi6fa5____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa2____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir9fa1____pinNumber5));
    vlSelf->__Vcellinp__thi6fa5____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa3____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir9fa2____pinNumber5));
    vlSelf->__Vcellinp__thi6fa6____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa3____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir9fa2____pinNumber5));
    vlSelf->__Vcellinp__thi6fa6____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa4____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir9fa3____pinNumber5));
    vlSelf->__Vcellinp__thi6fa7____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa4____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir9fa3____pinNumber5));
    vlSelf->__Vcellinp__thi6fa7____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa5____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir9fa4____pinNumber5));
    vlSelf->__Vcellinp__thi6fa8____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa5____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir9fa4____pinNumber5));
    vlSelf->__Vcellinp__thi6fa8____pinNumber2 = ((IData)(vlSelf->__Vcellout__fir9fa6____pinNumber4) 
                                                 ^ (IData)(vlSelf->__Vcellout__fir9fa5____pinNumber5));
    vlSelf->__Vcellinp__thi6fa9____pinNumber3 = ((IData)(vlSelf->__Vcellout__fir9fa6____pinNumber4) 
                                                 & (IData)(vlSelf->__Vcellout__fir9fa5____pinNumber5));
    vlSelf->__Vcellout__thi1fa1____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa1____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa1____pinNumber2) 
                                                     | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3)) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa1____pinNumber2) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3));
    vlSelf->__Vcellout__thi1fa2____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber3)));
    vlSelf->__Vcellout__thi1fa2____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa2____pinNumber3)));
    vlSelf->__Vcellinp__fif1fa2____pinNumber3 = (1U 
                                                 & ((IData)(vlSelf->__Vcellinp__thi2fa1____pinNumber1) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6));
    vlSelf->__Vcellinp__fou2fa1____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi2fa1____pinNumber1) 
                                                 & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6);
    vlSelf->__Vcellout__thi1fa3____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber3)));
    vlSelf->__Vcellout__thi1fa3____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa3____pinNumber3)));
    vlSelf->__Vcellout__thi1fa4____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber3)));
    vlSelf->__Vcellout__thi1fa4____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa4____pinNumber3)));
    vlSelf->__Vcellinp__fou2fa1____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi2fa2____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__thi2fa2____pinNumber2));
    vlSelf->__Vcellinp__fou2fa2____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi2fa2____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__thi2fa2____pinNumber2));
    vlSelf->__Vcellout__thi1fa5____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber3)));
    vlSelf->__Vcellout__thi1fa5____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa5____pinNumber3)));
    vlSelf->__Vcellout__thi1fa6____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber3)));
    vlSelf->__Vcellout__thi1fa6____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa6____pinNumber3)));
    vlSelf->__Vcellout__thi1fa7____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber3)));
    vlSelf->__Vcellout__thi1fa7____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa7____pinNumber3)));
    vlSelf->__Vcellout__thi1fa8____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber3)));
    vlSelf->__Vcellout__thi1fa8____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa8____pinNumber3)));
    vlSelf->__Vcellout__thi1fa9____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber3)));
    vlSelf->__Vcellout__thi1fa9____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi1fa9____pinNumber3)));
    vlSelf->__Vcellout__thi1fa10____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber3)));
    vlSelf->__Vcellout__thi1fa10____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa10____pinNumber3)));
    vlSelf->__Vcellout__thi1fa11____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber3)));
    vlSelf->__Vcellout__thi1fa11____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa11____pinNumber3)));
    vlSelf->__Vcellout__thi1fa12____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber3)));
    vlSelf->__Vcellout__thi1fa12____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa12____pinNumber3)));
    vlSelf->__Vcellout__thi1fa13____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber3)));
    vlSelf->__Vcellout__thi1fa13____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa13____pinNumber3)));
    vlSelf->__Vcellout__thi1fa14____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber3)));
    vlSelf->__Vcellout__thi1fa14____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa14____pinNumber3)));
    vlSelf->__Vcellout__thi1fa15____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber3)));
    vlSelf->__Vcellout__thi1fa15____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa15____pinNumber3)));
    vlSelf->__Vcellinp__fou1fa32____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi1fa32____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__thi1fa32____pinNumber2));
    vlSelf->__Vcellinp__fou1fa31____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi1fa32____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi1fa32____pinNumber2));
    vlSelf->__Vcellout__thi1fa16____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber3)));
    vlSelf->__Vcellout__thi1fa16____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa16____pinNumber3)));
    vlSelf->__Vcellout__thi1fa31____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber3)));
    vlSelf->__Vcellout__thi1fa31____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa31____pinNumber3)));
    vlSelf->__Vcellout__thi1fa17____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber3)));
    vlSelf->__Vcellout__thi1fa17____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa17____pinNumber3)));
    vlSelf->__Vcellout__thi1fa30____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber3)));
    vlSelf->__Vcellout__thi1fa30____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa30____pinNumber3)));
    vlSelf->__Vcellout__thi1fa18____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber3)));
    vlSelf->__Vcellout__thi1fa18____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa18____pinNumber3)));
    vlSelf->__Vcellout__thi1fa19____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber3)));
    vlSelf->__Vcellout__thi1fa19____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa19____pinNumber3)));
    vlSelf->__Vcellout__thi1fa20____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber3)));
    vlSelf->__Vcellout__thi1fa20____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa20____pinNumber3)));
    vlSelf->__Vcellout__thi1fa21____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber3)));
    vlSelf->__Vcellout__thi1fa21____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa21____pinNumber3)));
    vlSelf->__Vcellout__thi1fa29____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber3)));
    vlSelf->__Vcellout__thi1fa29____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa29____pinNumber3)));
    vlSelf->__Vcellout__thi1fa28____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber3)));
    vlSelf->__Vcellout__thi1fa28____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa28____pinNumber3)));
    vlSelf->__Vcellout__thi1fa27____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber3)));
    vlSelf->__Vcellout__thi1fa27____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa27____pinNumber3)));
    vlSelf->__Vcellout__thi1fa26____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber3)));
    vlSelf->__Vcellout__thi1fa26____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa26____pinNumber3)));
    vlSelf->__Vcellout__thi1fa25____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber3)));
    vlSelf->__Vcellout__thi1fa25____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa25____pinNumber3)));
    vlSelf->__Vcellout__thi1fa24____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber3)));
    vlSelf->__Vcellout__thi1fa24____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa24____pinNumber3)));
    vlSelf->__Vcellout__thi1fa23____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber3)));
    vlSelf->__Vcellout__thi1fa23____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa23____pinNumber3)));
    vlSelf->__Vcellout__thi1fa22____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber3)));
    vlSelf->__Vcellout__thi1fa22____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi1fa22____pinNumber3)));
    vlSelf->__Vcellinp__fou7fa32____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi7fa32____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__thi7fa32____pinNumber2));
    vlSelf->__Vcellinp__fou7fa31____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi7fa32____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa32____pinNumber2));
    vlSelf->__Vcellout__thi7fa31____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber3)));
    vlSelf->__Vcellout__thi7fa31____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa31____pinNumber3)));
    vlSelf->__Vcellout__thi7fa30____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber3)));
    vlSelf->__Vcellout__thi7fa30____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa30____pinNumber3)));
    vlSelf->__Vcellout__thi7fa29____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber3)));
    vlSelf->__Vcellout__thi7fa29____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa29____pinNumber3)));
    vlSelf->__Vcellout__thi7fa28____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber3)));
    vlSelf->__Vcellout__thi7fa28____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa28____pinNumber3)));
    vlSelf->__Vcellout__thi7fa27____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber3)));
    vlSelf->__Vcellout__thi7fa27____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa27____pinNumber3)));
    vlSelf->__Vcellout__thi7fa26____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber3)));
    vlSelf->__Vcellout__thi7fa26____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa26____pinNumber3)));
    vlSelf->__Vcellout__thi7fa25____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber3)));
    vlSelf->__Vcellout__thi7fa25____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa25____pinNumber3)));
    vlSelf->__Vcellout__thi7fa24____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber3)));
    vlSelf->__Vcellout__thi7fa24____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa24____pinNumber3)));
    vlSelf->__Vcellout__thi7fa23____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber3)));
    vlSelf->__Vcellout__thi7fa23____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa23____pinNumber3)));
    vlSelf->__Vcellout__thi7fa22____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber3)));
    vlSelf->__Vcellout__thi7fa22____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa22____pinNumber3)));
    vlSelf->__Vcellout__thi7fa21____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber3)));
    vlSelf->__Vcellout__thi7fa21____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa21____pinNumber3)));
    vlSelf->__Vcellout__thi7fa20____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber3)));
    vlSelf->__Vcellout__thi7fa20____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa20____pinNumber3)));
    vlSelf->__Vcellout__thi7fa19____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber3)));
    vlSelf->__Vcellout__thi7fa19____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa19____pinNumber3)));
    vlSelf->__Vcellout__thi7fa18____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber3)));
    vlSelf->__Vcellout__thi7fa18____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa18____pinNumber3)));
    vlSelf->__Vcellout__thi7fa17____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber3)));
    vlSelf->__Vcellout__thi7fa17____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa17____pinNumber3)));
    vlSelf->__Vcellout__thi7fa16____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber3)));
    vlSelf->__Vcellout__thi7fa16____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa16____pinNumber3)));
    vlSelf->__Vcellout__thi7fa15____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber3)));
    vlSelf->__Vcellout__thi7fa15____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa15____pinNumber3)));
    vlSelf->__Vcellout__thi7fa14____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber3)));
    vlSelf->__Vcellout__thi7fa14____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa14____pinNumber3)));
    vlSelf->__Vcellout__thi7fa13____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber3)));
    vlSelf->__Vcellout__thi7fa13____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa13____pinNumber3)));
    vlSelf->__Vcellout__thi7fa12____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber3)));
    vlSelf->__Vcellout__thi7fa12____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa12____pinNumber3)));
    vlSelf->__Vcellout__thi7fa11____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber3)));
    vlSelf->__Vcellout__thi7fa11____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa11____pinNumber3)));
    vlSelf->__Vcellout__thi7fa10____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber3)));
    vlSelf->__Vcellout__thi7fa10____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi7fa10____pinNumber3)));
    vlSelf->__Vcellinp__sev3fa5____pinNumber3 = (1U 
                                                 & ((IData)(vlSelf->__Vcellinp__thi7fa1____pinNumber1) 
                                                    ^ 
                                                    ((IData)(vlSelf->__Vcellinp__thi7fa1____pinNumber2) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30)));
    vlSelf->__Vcellout__thi7fa1____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa1____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa1____pinNumber2) 
                                                     | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30)) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa1____pinNumber2) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30));
    vlSelf->__Vcellout__thi7fa9____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber3)));
    vlSelf->__Vcellout__thi7fa9____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa9____pinNumber3)));
    vlSelf->__Vcellout__thi7fa8____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber3)));
    vlSelf->__Vcellout__thi7fa8____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa8____pinNumber3)));
    vlSelf->__Vcellout__thi7fa7____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber3)));
    vlSelf->__Vcellout__thi7fa7____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa7____pinNumber3)));
    vlSelf->__Vcellout__thi7fa2____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber3)));
    vlSelf->__Vcellout__thi7fa2____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa2____pinNumber3)));
    vlSelf->__Vcellout__thi7fa6____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber3)));
    vlSelf->__Vcellout__thi7fa6____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa6____pinNumber3)));
    vlSelf->__Vcellout__thi7fa3____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber3)));
    vlSelf->__Vcellout__thi7fa3____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa3____pinNumber3)));
    vlSelf->__Vcellout__thi7fa4____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber3)));
    vlSelf->__Vcellout__thi7fa4____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa4____pinNumber3)));
    vlSelf->__Vcellout__thi7fa5____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber3)));
    vlSelf->__Vcellout__thi7fa5____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi7fa5____pinNumber3)));
    vlSelf->__Vcellinp__fou2fa2____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi2fa3____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__thi2fa3____pinNumber2));
    vlSelf->__Vcellinp__fou2fa3____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi2fa3____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__thi2fa3____pinNumber2));
    vlSelf->__Vcellout__thi2fa4____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber3)));
    vlSelf->__Vcellout__thi2fa4____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi2fa4____pinNumber3)));
    vlSelf->__Vcellout__thi2fa5____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber3)));
    vlSelf->__Vcellout__thi2fa5____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi2fa5____pinNumber3)));
    vlSelf->__Vcellout__thi2fa6____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber3)));
    vlSelf->__Vcellout__thi2fa6____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi2fa6____pinNumber3)));
    vlSelf->__Vcellout__thi2fa7____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber3)));
    vlSelf->__Vcellout__thi2fa7____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi2fa7____pinNumber3)));
    vlSelf->__Vcellout__thi2fa8____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber3)));
    vlSelf->__Vcellout__thi2fa8____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi2fa8____pinNumber3)));
    vlSelf->__Vcellinp__fou2fa34____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi2fa34____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__thi2fa34____pinNumber2));
    vlSelf->__Vcellinp__fou2fa33____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi2fa34____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa34____pinNumber2));
    vlSelf->__Vcellout__thi2fa9____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber3)));
    vlSelf->__Vcellout__thi2fa9____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi2fa9____pinNumber3)));
    vlSelf->__Vcellout__thi2fa10____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber3)));
    vlSelf->__Vcellout__thi2fa10____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa10____pinNumber3)));
    vlSelf->__Vcellout__thi2fa11____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber3)));
    vlSelf->__Vcellout__thi2fa11____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa11____pinNumber3)));
    vlSelf->__Vcellinp__fou2fa33____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi2fa33____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__thi2fa33____pinNumber2));
    vlSelf->__Vcellinp__fou2fa32____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi2fa33____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi2fa33____pinNumber2));
    vlSelf->__Vcellout__thi2fa12____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber3)));
    vlSelf->__Vcellout__thi2fa12____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa12____pinNumber3)));
    vlSelf->__Vcellout__thi2fa32____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber3)));
    vlSelf->__Vcellout__thi2fa32____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa32____pinNumber3)));
    vlSelf->__Vcellout__thi2fa31____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber3)));
    vlSelf->__Vcellout__thi2fa31____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa31____pinNumber3)));
    vlSelf->__Vcellout__thi2fa13____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber3)));
    vlSelf->__Vcellout__thi2fa13____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa13____pinNumber3)));
    vlSelf->__Vcellout__thi2fa30____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber3)));
    vlSelf->__Vcellout__thi2fa30____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa30____pinNumber3)));
    vlSelf->__Vcellout__thi2fa14____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber3)));
    vlSelf->__Vcellout__thi2fa14____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa14____pinNumber3)));
    vlSelf->__Vcellout__thi2fa29____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber3)));
    vlSelf->__Vcellout__thi2fa29____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa29____pinNumber3)));
    vlSelf->__Vcellout__thi2fa15____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber3)));
    vlSelf->__Vcellout__thi2fa15____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa15____pinNumber3)));
    vlSelf->__Vcellout__thi2fa28____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber3)));
    vlSelf->__Vcellout__thi2fa28____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa28____pinNumber3)));
    vlSelf->__Vcellout__thi2fa16____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber3)));
    vlSelf->__Vcellout__thi2fa16____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa16____pinNumber3)));
    vlSelf->__Vcellout__thi2fa17____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber3)));
    vlSelf->__Vcellout__thi2fa17____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa17____pinNumber3)));
    vlSelf->__Vcellout__thi2fa18____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber3)));
    vlSelf->__Vcellout__thi2fa18____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa18____pinNumber3)));
    vlSelf->__Vcellout__thi2fa19____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber3)));
    vlSelf->__Vcellout__thi2fa19____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa19____pinNumber3)));
    vlSelf->__Vcellout__thi2fa27____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber3)));
    vlSelf->__Vcellout__thi2fa27____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa27____pinNumber3)));
    vlSelf->__Vcellout__thi2fa26____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber3)));
    vlSelf->__Vcellout__thi2fa26____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa26____pinNumber3)));
    vlSelf->__Vcellout__thi2fa25____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber3)));
    vlSelf->__Vcellout__thi2fa25____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa25____pinNumber3)));
    vlSelf->__Vcellout__thi2fa24____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber3)));
    vlSelf->__Vcellout__thi2fa24____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa24____pinNumber3)));
    vlSelf->__Vcellout__thi2fa23____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber3)));
    vlSelf->__Vcellout__thi2fa23____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa23____pinNumber3)));
    vlSelf->__Vcellout__thi2fa22____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber3)));
    vlSelf->__Vcellout__thi2fa22____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa22____pinNumber3)));
    vlSelf->__Vcellout__thi2fa20____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber3)));
    vlSelf->__Vcellout__thi2fa20____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa20____pinNumber3)));
    vlSelf->__Vcellout__thi2fa21____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber3)));
    vlSelf->__Vcellout__thi2fa21____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi2fa21____pinNumber3)));
    vlSelf->__Vcellinp__fou4fa34____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi4fa34____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__thi4fa34____pinNumber2));
    vlSelf->__Vcellinp__fou4fa33____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi4fa34____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa34____pinNumber2));
    vlSelf->__Vcellinp__fou4fa33____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi4fa33____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__thi4fa33____pinNumber2));
    vlSelf->__Vcellinp__fou4fa32____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi4fa33____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa33____pinNumber2));
    vlSelf->__Vcellout__thi4fa32____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber3)));
    vlSelf->__Vcellout__thi4fa32____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa32____pinNumber3)));
    vlSelf->__Vcellout__thi4fa31____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber3)));
    vlSelf->__Vcellout__thi4fa31____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa31____pinNumber3)));
    vlSelf->__Vcellinp__sev2fa1____pinNumber1 = (1U 
                                                 & ((IData)(vlSelf->__Vcellinp__thi4fa1____pinNumber1) 
                                                    ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15));
    vlSelf->__Vcellinp__fou4fa1____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi4fa1____pinNumber1) 
                                                 & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15);
    vlSelf->__Vcellout__thi4fa30____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber3)));
    vlSelf->__Vcellout__thi4fa30____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa30____pinNumber3)));
    vlSelf->__Vcellout__thi4fa29____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber3)));
    vlSelf->__Vcellout__thi4fa29____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa29____pinNumber3)));
    vlSelf->__Vcellout__thi4fa28____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber3)));
    vlSelf->__Vcellout__thi4fa28____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa28____pinNumber3)));
    vlSelf->__Vcellout__thi4fa27____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber3)));
    vlSelf->__Vcellout__thi4fa27____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa27____pinNumber3)));
    vlSelf->__Vcellout__thi4fa26____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber3)));
    vlSelf->__Vcellout__thi4fa26____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa26____pinNumber3)));
    vlSelf->__Vcellinp__fou4fa1____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi4fa2____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__thi4fa2____pinNumber2));
    vlSelf->__Vcellinp__fou4fa2____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi4fa2____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__thi4fa2____pinNumber2));
    vlSelf->__Vcellout__thi4fa25____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber3)));
    vlSelf->__Vcellout__thi4fa25____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa25____pinNumber3)));
    vlSelf->__Vcellinp__fou4fa2____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi4fa3____pinNumber1) 
                                                 ^ (IData)(vlSelf->__Vcellinp__thi4fa3____pinNumber2));
    vlSelf->__Vcellinp__fou4fa3____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi4fa3____pinNumber1) 
                                                 & (IData)(vlSelf->__Vcellinp__thi4fa3____pinNumber2));
    vlSelf->__Vcellout__thi4fa4____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber3)));
    vlSelf->__Vcellout__thi4fa4____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi4fa4____pinNumber3)));
    vlSelf->__Vcellout__thi4fa24____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber3)));
    vlSelf->__Vcellout__thi4fa24____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa24____pinNumber3)));
    vlSelf->__Vcellout__thi4fa5____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber3)));
    vlSelf->__Vcellout__thi4fa5____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi4fa5____pinNumber3)));
    vlSelf->__Vcellout__thi4fa23____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber3)));
    vlSelf->__Vcellout__thi4fa23____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa23____pinNumber3)));
    vlSelf->__Vcellout__thi4fa6____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber3)));
    vlSelf->__Vcellout__thi4fa6____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi4fa6____pinNumber3)));
    vlSelf->__Vcellout__thi4fa22____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber3)));
    vlSelf->__Vcellout__thi4fa22____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa22____pinNumber3)));
    vlSelf->__Vcellout__thi4fa7____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber3)));
    vlSelf->__Vcellout__thi4fa7____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi4fa7____pinNumber3)));
    vlSelf->__Vcellout__thi4fa21____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber3)));
    vlSelf->__Vcellout__thi4fa21____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa21____pinNumber3)));
    vlSelf->__Vcellout__thi4fa8____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber3)));
    vlSelf->__Vcellout__thi4fa8____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi4fa8____pinNumber3)));
    vlSelf->__Vcellout__thi4fa20____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber3)));
    vlSelf->__Vcellout__thi4fa20____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa20____pinNumber3)));
    vlSelf->__Vcellout__thi4fa9____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber3)));
    vlSelf->__Vcellout__thi4fa9____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi4fa9____pinNumber3)));
    vlSelf->__Vcellout__thi4fa10____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber3)));
    vlSelf->__Vcellout__thi4fa10____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa10____pinNumber3)));
    vlSelf->__Vcellout__thi4fa11____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber3)));
    vlSelf->__Vcellout__thi4fa11____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa11____pinNumber3)));
    vlSelf->__Vcellout__thi4fa12____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber3)));
    vlSelf->__Vcellout__thi4fa12____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa12____pinNumber3)));
    vlSelf->__Vcellout__thi4fa19____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber3)));
    vlSelf->__Vcellout__thi4fa19____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa19____pinNumber3)));
    vlSelf->__Vcellout__thi4fa18____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber3)));
    vlSelf->__Vcellout__thi4fa18____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa18____pinNumber3)));
    vlSelf->__Vcellout__thi4fa17____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber3)));
    vlSelf->__Vcellout__thi4fa17____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa17____pinNumber3)));
    vlSelf->__Vcellout__thi4fa16____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber3)));
    vlSelf->__Vcellout__thi4fa16____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa16____pinNumber3)));
    vlSelf->__Vcellout__thi4fa15____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber3)));
    vlSelf->__Vcellout__thi4fa15____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa15____pinNumber3)));
    vlSelf->__Vcellout__thi4fa14____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber3)));
    vlSelf->__Vcellout__thi4fa14____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa14____pinNumber3)));
    vlSelf->__Vcellout__thi4fa13____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber3)));
    vlSelf->__Vcellout__thi4fa13____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi4fa13____pinNumber3)));
    vlSelf->__Vcellout__thi3fa1____pinNumber4 = (1U 
                                                 & ((IData)(vlSelf->__Vcellinp__thi3fa1____pinNumber1) 
                                                    ^ 
                                                    ((IData)(vlSelf->__Vcellinp__thi3fa1____pinNumber2) 
                                                     ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12)));
    vlSelf->__Vcellout__thi3fa1____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa1____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa1____pinNumber2) 
                                                     | vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12)) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa1____pinNumber2) 
                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12));
    vlSelf->__Vcellinp__fou3fa32____pinNumber1 = ((IData)(vlSelf->__Vcellinp__thi3fa32____pinNumber1) 
                                                  & (IData)(vlSelf->__Vcellinp__thi3fa32____pinNumber2));
    vlSelf->__Vcellinp__fou3fa31____pinNumber2 = ((IData)(vlSelf->__Vcellinp__thi3fa32____pinNumber1) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa32____pinNumber2));
    vlSelf->__Vcellout__thi3fa31____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber3)));
    vlSelf->__Vcellout__thi3fa31____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa31____pinNumber3)));
    vlSelf->__Vcellout__thi3fa30____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber3)));
    vlSelf->__Vcellout__thi3fa30____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa30____pinNumber3)));
    vlSelf->__Vcellout__thi3fa29____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber3)));
    vlSelf->__Vcellout__thi3fa29____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa29____pinNumber3)));
    vlSelf->__Vcellout__thi3fa28____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber3)));
    vlSelf->__Vcellout__thi3fa28____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa28____pinNumber3)));
    vlSelf->__Vcellout__thi3fa2____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber3)));
    vlSelf->__Vcellout__thi3fa2____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa2____pinNumber3)));
    vlSelf->__Vcellout__thi3fa27____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber3)));
    vlSelf->__Vcellout__thi3fa27____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa27____pinNumber3)));
    vlSelf->__Vcellout__thi3fa3____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber3)));
    vlSelf->__Vcellout__thi3fa3____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa3____pinNumber3)));
    vlSelf->__Vcellout__thi3fa4____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber3)));
    vlSelf->__Vcellout__thi3fa4____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa4____pinNumber3)));
    vlSelf->__Vcellout__thi3fa5____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber3)));
    vlSelf->__Vcellout__thi3fa5____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa5____pinNumber3)));
    vlSelf->__Vcellout__thi3fa6____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber3)));
    vlSelf->__Vcellout__thi3fa6____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa6____pinNumber3)));
    vlSelf->__Vcellout__thi3fa26____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber3)));
    vlSelf->__Vcellout__thi3fa26____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa26____pinNumber3)));
    vlSelf->__Vcellout__thi3fa7____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber3)));
    vlSelf->__Vcellout__thi3fa7____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa7____pinNumber3)));
    vlSelf->__Vcellout__thi3fa25____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber3)));
    vlSelf->__Vcellout__thi3fa25____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa25____pinNumber3)));
    vlSelf->__Vcellout__thi3fa8____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber3)));
    vlSelf->__Vcellout__thi3fa8____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa8____pinNumber3)));
    vlSelf->__Vcellout__thi3fa24____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber3)));
    vlSelf->__Vcellout__thi3fa24____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa24____pinNumber3)));
    vlSelf->__Vcellout__thi3fa9____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber1) 
                                                 ^ 
                                                 ((IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber2) 
                                                  ^ (IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber3)));
    vlSelf->__Vcellout__thi3fa9____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber1) 
                                                  & ((IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber2) 
                                                     | (IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber3))) 
                                                 | ((IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber2) 
                                                    & (IData)(vlSelf->__Vcellinp__thi3fa9____pinNumber3)));
    vlSelf->__Vcellout__thi3fa23____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber3)));
    vlSelf->__Vcellout__thi3fa23____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa23____pinNumber3)));
    vlSelf->__Vcellout__thi3fa10____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber3)));
    vlSelf->__Vcellout__thi3fa10____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa10____pinNumber3)));
    vlSelf->__Vcellout__thi3fa22____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber3)));
    vlSelf->__Vcellout__thi3fa22____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa22____pinNumber3)));
    vlSelf->__Vcellout__thi3fa11____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber3)));
    vlSelf->__Vcellout__thi3fa11____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa11____pinNumber3)));
    vlSelf->__Vcellout__thi3fa12____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber3)));
    vlSelf->__Vcellout__thi3fa12____pinNumber5 = (((IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber1) 
                                                   & ((IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber2) 
                                                      | (IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber3))) 
                                                  | ((IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber2) 
                                                     & (IData)(vlSelf->__Vcellinp__thi3fa12____pinNumber3)));
    vlSelf->__Vcellout__thi3fa13____pinNumber4 = ((IData)(vlSelf->__Vcellinp__thi3fa13____pinNumber1) 
                                                  ^ 
                                                  ((IData)(vlSelf->__Vcellinp__thi3fa13____pinNumber2) 
                                                   ^ (IData)(vlSelf->__Vcellinp__thi3fa13____pinNumber3)));
}

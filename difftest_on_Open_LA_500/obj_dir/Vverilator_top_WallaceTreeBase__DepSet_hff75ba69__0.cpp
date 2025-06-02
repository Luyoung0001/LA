// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_WallaceTreeBase.h"
#include "Vverilator_top__Syms.h"

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__firs__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__firs__0\n"); );
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)));
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData)));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                              | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                              | ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
          >> 1U));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
          >> 0xaU));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__COut = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                              << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                           << 0xdU) 
                                          | (0xffffe000U 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                << 2U)))) 
                            | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                               << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                               << 0xcU) 
                                              & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                  << 0xcU) 
                                                 | (0xfffff000U 
                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                       << 2U)))) 
                                             | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                << 0xcU)) 
                                            | ((0x800U 
                                                & ((0xfffff800U 
                                                    & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                        << 2U) 
                                                       & ((IData)(
                                                                  (0U 
                                                                   != 
                                                                   (0x180U 
                                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry))) 
                                                          << 0xbU))) 
                                                   | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                      << 0xbU))) 
                                               | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                     & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                        | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                    | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                   << 0xaU) 
                                                  | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                        & (IData)(
                                                                  (0U 
                                                                   != 
                                                                   (0x60U 
                                                                    & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)))) 
                                                       | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                      << 9U) 
                                                     | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                           & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                              | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                          | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                         << 8U) 
                                                        | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                              << 7U) 
                                                             & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                 << 7U) 
                                                                | (0xffffff80U 
                                                                   & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                                      << 6U)))) 
                                                            | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                               << 7U)) 
                                                           | ((0x40U 
                                                               & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                                    & (IData)(
                                                                              (0U 
                                                                               != 
                                                                               (0x18U 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry)))) 
                                                                   | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                  << 6U)) 
                                                              | ((0x20U 
                                                                  & ((0xffffffe0U 
                                                                      & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                                          << 3U) 
                                                                         & ((0xffffffe0U 
                                                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                                                << 4U)) 
                                                                            | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__SecStageCarry 
                                                                               << 5U)))) 
                                                                     | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                        << 5U))) 
                                                                 | ((0x10U 
                                                                     & ((0xffff0U 
                                                                         & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                                             >> 0xcU) 
                                                                            & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                                               << 4U))) 
                                                                        | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                           << 4U))) 
                                                                    | ((8U 
                                                                        & ((0x3ffff8U 
                                                                            & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                                                >> 0xaU) 
                                                                               & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                                                << 3U))) 
                                                                           | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                              << 3U))) 
                                                                       | ((4U 
                                                                           & ((0xfffffcU 
                                                                               & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                                                << 2U))) 
                                                                              | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                          | ((2U 
                                                                              & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                             | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__firs__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__0\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h2a00c6da__0;
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData)));
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
          >> 0xaU));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h2a00c6da__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__firs.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h2a00c6da__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h68277bfa__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h68277bfa__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h68277bfa__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h61c4b8d5__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h61c4b8d5__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h61c4b8d5__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h39af221c__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h39af221c__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h39af221c__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hbaf6377c__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_hbaf6377c__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_hbaf6377c__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hfc9bd0be__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_hfc9bd0be__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_hfc9bd0be__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h85893d1f__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h85893d1f__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h85893d1f__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h0499ea3e__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h0499ea3e__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h0499ea3e__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h4977fb96__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h4977fb96__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h4977fb96__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h18d6ae04__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h18d6ae04__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h18d6ae04__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h6be9e197__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h6be9e197__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h6be9e197__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h3adb6491__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h3adb6491__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h3adb6491__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hdc935b6c__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_hdc935b6c__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_hdc935b6c__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h0fecf76b__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h0fecf76b__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h0fecf76b__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h640e73c9__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h640e73c9__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h640e73c9__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hf50d4034__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_hf50d4034__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_hf50d4034__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h6b375eb4__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h6b375eb4__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h6b375eb4__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hd45f29d9__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_hd45f29d9__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_hd45f29d9__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h11e5c48d__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h11e5c48d__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h11e5c48d__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_hd2a2f812__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_hd2a2f812__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_hd2a2f812__0;
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__0(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__0\n"); );
    // Body
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xc000U 
                                                           == 
                                                           (0xc000U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData)));
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData)));
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x300U 
                                                           == 
                                                           (0x300U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData)));
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x1800U 
                                                           == 
                                                           (0x1800U 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData)));
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0xcU 
                                                           == 
                                                           (0xcU 
                                                            & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData)));
    vlSelf->__Vcellinp__second4__A = (1U & ((IData)(
                                                    (0x4000U 
                                                     == 
                                                     (0x1c000U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x8000U 
                                                        == 
                                                        (0x1c000U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                   >> 0x10U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xc000U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__A = (1U & ((IData)(
                                                    (0x20U 
                                                     == 
                                                     (0xe0U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x40U 
                                                        == 
                                                        (0xe0U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                   >> 7U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__C = (1U & ((IData)(
                                                    (0x100U 
                                                     == 
                                                     (0x700U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x200U 
                                                        == 
                                                        (0x700U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                   >> 0xaU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x300U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second4__B = (1U & ((IData)(
                                                    (0x800U 
                                                     == 
                                                     (0x3800U 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (0x1000U 
                                                        == 
                                                        (0x3800U 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                   >> 0xdU) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x1800U 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__second3__B = (1U & ((IData)(
                                                    (4U 
                                                     == 
                                                     (0x1cU 
                                                      & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                            | ((IData)(
                                                       (8U 
                                                        == 
                                                        (0x1cU 
                                                         & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                               | ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                   >> 4U) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0xcU 
                                                               & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                     | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second4__B) & (IData)(vlSelf->__Vcellinp__second4__C));
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__second3__B) & 
         (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
          >> 1U));
    vlSelf->__Vcellinp__third2__A = (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                      & ((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                         & (IData)(vlSelf->__Vcellinp__second4__C))) 
                                     | (((~ (IData)(vlSelf->__Vcellinp__second4__A)) 
                                         & ((~ (IData)(vlSelf->__Vcellinp__second4__C)) 
                                            & (IData)(vlSelf->__Vcellinp__second4__B))) 
                                        | ((IData)(vlSelf->__Vcellinp__second4__A) 
                                           & (((~ (IData)(vlSelf->__Vcellinp__second4__B)) 
                                               & (~ (IData)(vlSelf->__Vcellinp__second4__C))) 
                                              | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__third2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                               & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                  >> 1U))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__second3__A)) 
                                               & ((~ 
                                                   (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                    >> 1U)) 
                                                  & (IData)(vlSelf->__Vcellinp__second3__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__second3__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__second3__B)) 
                                                     & (~ 
                                                        (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                         >> 1U))) 
                                                    | (IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0))))));
}

VL_INLINE_OPT void Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__1(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__1\n"); );
    // Init
    SData/*31:0*/ __Vtemp_h33a2371b__0;
    // Body
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x3000U 
                                                           == 
                                                           (0x3000U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))));
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x180U 
                                                            == 
                                                            (0x180U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))));
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                          (0x60U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))));
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))));
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = (IData)(
                                                           (0x18U 
                                                            == 
                                                            (0x18U 
                                                             & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))));
    vlSelf->__Vcellinp__fifth1__B = (1U & ((IData)(
                                                   (0x80U 
                                                    == 
                                                    (0x380U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (0x100U 
                                                       == 
                                                       (0x380U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                  >> 9U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x180U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third1__A = (1U & ((IData)(
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                           | ((IData)(
                                                      (2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                              | (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                  >> 2U) 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__Vcellinp__third2__C = (1U & (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData) 
                                            & (IData)(
                                                      (8U 
                                                       == 
                                                       (0x18U 
                                                        & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))))) 
                                           | (((~ vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData) 
                                               & (IData)(
                                                         (0x10U 
                                                          == 
                                                          (0x18U 
                                                           & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))))) 
                                              | (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                 & ((IData)(
                                                            (0U 
                                                             == 
                                                             (0x18U 
                                                              & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                                   & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                      >> 0xbU));
    vlSelf->__Vcellinp__fourth2__B = (1U & (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                             & (IData)(
                                                       (0x20U 
                                                        == 
                                                        (0x60U 
                                                         & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))))) 
                                            | (((~ (IData)(vlSelf->__Vcellinp__third1__A)) 
                                                & (IData)(
                                                          (0x40U 
                                                           == 
                                                           (0x60U 
                                                            & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))))) 
                                               | ((IData)(vlSelf->__Vcellinp__third1__A) 
                                                  & ((IData)(
                                                             (0U 
                                                              == 
                                                              (0x60U 
                                                               & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                                     | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                   & (IData)(vlSelf->__Vcellinp__third2__C));
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 
        ((IData)(vlSelf->__Vcellinp__fourth2__B) & 
         ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
          >> 0xaU));
    vlSelf->__Vcellinp__fourth2__A = (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                       & ((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                          & (IData)(vlSelf->__Vcellinp__third2__C))) 
                                      | (((~ (IData)(vlSelf->__Vcellinp__third2__A)) 
                                          & ((~ (IData)(vlSelf->__Vcellinp__third2__C)) 
                                             & (IData)(vlSelf->__Vcellinp__third2__B))) 
                                         | ((IData)(vlSelf->__Vcellinp__third2__A) 
                                            & (((~ (IData)(vlSelf->__Vcellinp__third2__B)) 
                                                & (~ (IData)(vlSelf->__Vcellinp__third2__C))) 
                                               | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)))));
    vlSelf->__Vcellinp__fifth1__A = (1U & (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                            & ((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                               & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                  >> 0xaU))) 
                                           | (((~ (IData)(vlSelf->__Vcellinp__fourth2__A)) 
                                               & ((~ 
                                                   ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                    >> 0xaU)) 
                                                  & (IData)(vlSelf->__Vcellinp__fourth2__B))) 
                                              | ((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                 & (((~ (IData)(vlSelf->__Vcellinp__fourth2__B)) 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                         >> 0xaU))) 
                                                    | (IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0))))));
    vlSelf->__PVT__FifSig = (1U & (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                    & ((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                       & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                          >> 0xbU))) 
                                   | (((~ (IData)(vlSelf->__Vcellinp__fifth1__A)) 
                                       & ((~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                              >> 0xbU)) 
                                          & (IData)(vlSelf->__Vcellinp__fifth1__B))) 
                                      | ((IData)(vlSelf->__Vcellinp__fifth1__A) 
                                         & (((~ (IData)(vlSelf->__Vcellinp__fifth1__B)) 
                                             & (~ ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                   >> 0xbU))) 
                                            | (IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0))))));
    __Vtemp_h33a2371b__0 = (((((IData)(vlSelf->__Vcellinp__fifth1__A) 
                               << 0xdU) & (((IData)(vlSelf->__Vcellinp__fifth1__B) 
                                            << 0xdU) 
                                           | (0xffffe000U 
                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                 << 2U)))) 
                             | ((IData)(vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0) 
                                << 0xdU)) | (((((IData)(vlSelf->__Vcellinp__fourth2__A) 
                                                << 0xcU) 
                                               & (((IData)(vlSelf->__Vcellinp__fourth2__B) 
                                                   << 0xcU) 
                                                  | (0xfffff000U 
                                                     & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                        << 2U)))) 
                                              | ((IData)(vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0) 
                                                 << 0xcU)) 
                                             | ((0x800U 
                                                 & ((0xfffff800U 
                                                     & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                         << 2U) 
                                                        & ((IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x180U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut)))) 
                                                           << 0xbU))) 
                                                    | ((IData)(vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0) 
                                                       << 0xbU))) 
                                                | (((((IData)(vlSelf->__Vcellinp__third2__A) 
                                                      & ((IData)(vlSelf->__Vcellinp__third2__B) 
                                                         | (IData)(vlSelf->__Vcellinp__third2__C))) 
                                                     | (IData)(vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                    << 0xaU) 
                                                   | (((((IData)(vlSelf->__Vcellinp__third1__A) 
                                                         & (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (0x60U 
                                                                     & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))))) 
                                                        | (IData)(vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0)) 
                                                       << 9U) 
                                                      | (((((IData)(vlSelf->__Vcellinp__second4__A) 
                                                            & ((IData)(vlSelf->__Vcellinp__second4__B) 
                                                               | (IData)(vlSelf->__Vcellinp__second4__C))) 
                                                           | (IData)(vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0)) 
                                                          << 8U) 
                                                         | (((((IData)(vlSelf->__Vcellinp__second3__A) 
                                                               << 7U) 
                                                              & (((IData)(vlSelf->__Vcellinp__second3__B) 
                                                                  << 7U) 
                                                                 | (0xffffff80U 
                                                                    & (vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                                       << 6U)))) 
                                                             | ((IData)(vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                << 7U)) 
                                                            | ((0x40U 
                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                                     & (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (0x18U 
                                                                                & (IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut))))) 
                                                                    | (IData)(vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0)) 
                                                                   << 6U)) 
                                                               | ((0x20U 
                                                                   & ((0xffffffe0U 
                                                                       & (((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                                           << 3U) 
                                                                          & ((0xffffffe0U 
                                                                              & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                                                << 4U)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi.__PVT__COut) 
                                                                                << 5U)))) 
                                                                      | ((IData)(vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0) 
                                                                         << 5U))) 
                                                                  | ((0x10U 
                                                                      & ((0xffff0U 
                                                                          & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                                              >> 0xcU) 
                                                                             & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xc000U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                                                << 4U))) 
                                                                         | ((IData)(vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0) 
                                                                            << 4U))) 
                                                                     | ((8U 
                                                                         & ((0x3ffff8U 
                                                                             & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                                                >> 0xaU) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1800U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                                                << 3U))) 
                                                                            | ((IData)(vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0) 
                                                                               << 3U))) 
                                                                        | ((4U 
                                                                            & ((0xfffffcU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                                                >> 8U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x300U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                                                << 2U))) 
                                                                               | ((IData)(vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 2U))) 
                                                                           | ((2U 
                                                                               & ((0x3fffffeU 
                                                                                & ((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                                                >> 6U) 
                                                                                & ((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60U 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData))) 
                                                                                << 1U))) 
                                                                                | ((IData)(vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0) 
                                                                                << 1U))) 
                                                                              | (1U 
                                                                                & (((vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData 
                                                                                >> 4U) 
                                                                                & (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSymsp->TOP__verilator_top.cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData)))) 
                                                                                | (IData)(vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0))))))))))))))));
    vlSelf->__PVT__COut = __Vtemp_h33a2371b__0;
}

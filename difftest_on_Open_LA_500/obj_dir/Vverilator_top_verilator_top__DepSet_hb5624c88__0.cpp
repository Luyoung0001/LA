// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_verilator_top.h"

VL_INLINE_OPT void Vverilator_top_verilator_top___ico_sequent__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___ico_sequent__TOP__verilator_top__0\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_hbddc6129__0;
    VlWide<5>/*159:0*/ __Vtemp_h8c7c8e28__0;
    VlWide<5>/*159:0*/ __Vtemp_h10f5efe2__0;
    VlWide<7>/*223:0*/ __Vtemp_h0d17e4e4__0;
    VlWide<7>/*223:0*/ __Vtemp_h953c8cfc__0;
    VlWide<11>/*351:0*/ __Vtemp_hd0ee12c5__0;
    VlWide<11>/*351:0*/ __Vtemp_h73b336c9__0;
    // Body
    vlSelf->__PVT__cpu__DOT__rd_csr_data = (((- (IData)(
                                                        (0U 
                                                         == 
                                                         (0x3fffU 
                                                          & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                             >> 0xaU))))) 
                                             & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd) 
                                            | (((- (IData)(
                                                           (1U 
                                                            == 
                                                            (0x3fffU 
                                                             & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                >> 0xaU))))) 
                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_prmd) 
                                               | (((- (IData)(
                                                              (4U 
                                                               == 
                                                               (0x3fffU 
                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                   >> 0xaU))))) 
                                                   & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ectl) 
                                                  | (((- (IData)(
                                                                 (5U 
                                                                  == 
                                                                  (0x3fffU 
                                                                   & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                      >> 0xaU))))) 
                                                      & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_estat) 
                                                     | (((- (IData)(
                                                                    (6U 
                                                                     == 
                                                                     (0x3fffU 
                                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                         >> 0xaU))))) 
                                                         & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_era) 
                                                        | (((- (IData)(
                                                                       (7U 
                                                                        == 
                                                                        (0x3fffU 
                                                                         & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                            >> 0xaU))))) 
                                                            & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_badv) 
                                                           | (((- (IData)(
                                                                          (0xcU 
                                                                           == 
                                                                           (0x3fffU 
                                                                            & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                               >> 0xaU))))) 
                                                               & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_eentry) 
                                                              | (((- (IData)(
                                                                             (0x10U 
                                                                              == 
                                                                              (0x3fffU 
                                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                  & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                                                                 | (((- (IData)(
                                                                                (0x11U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                     & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbehi) 
                                                                    | (((- (IData)(
                                                                                (0x12U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                        & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo0) 
                                                                       | (((- (IData)(
                                                                                (0x13U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                           & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo1) 
                                                                          | (((- (IData)(
                                                                                (0x18U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                              & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid) 
                                                                             | (((- (IData)(
                                                                                (0x19U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdl) 
                                                                                | (((- (IData)(
                                                                                (0x1aU 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdh) 
                                                                                | (((- (IData)(
                                                                                (0x1bU 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & ((vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_badv 
                                                                                >> 0x1fU)
                                                                                 ? vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdh
                                                                                 : vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdl)) 
                                                                                | (((- (IData)(
                                                                                (0x20U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cpuid) 
                                                                                | (((- (IData)(
                                                                                (0x30U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save0) 
                                                                                | (((- (IData)(
                                                                                (0x31U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save1) 
                                                                                | (((- (IData)(
                                                                                (0x32U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save2) 
                                                                                | (((- (IData)(
                                                                                (0x33U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save3) 
                                                                                | (((- (IData)(
                                                                                (0x40U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid) 
                                                                                | (((- (IData)(
                                                                                (0x41U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tcfg) 
                                                                                | (((- (IData)(
                                                                                (0x43U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cntc) 
                                                                                | (((- (IData)(
                                                                                (0x44U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ticlr) 
                                                                                | (((- (IData)(
                                                                                (0x60U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->csr_llbctl_diff) 
                                                                                | (((- (IData)(
                                                                                (0x42U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tval) 
                                                                                | (((- (IData)(
                                                                                (0x88U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbrentry) 
                                                                                | (((- (IData)(
                                                                                (0x180U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw0) 
                                                                                | ((- (IData)(
                                                                                (0x181U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw1)))))))))))))))))))))))))))));
    __Vtemp_hbddc6129__0[4U] = ((0x40U & (((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b)) 
                                           & (~ ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                    | ((0x16U 
                                                        == 
                                                        (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                         >> 0x1aU)) 
                                                       | ((0x17U 
                                                           == 
                                                           (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                            >> 0x1aU)) 
                                                          | ((0x18U 
                                                              == 
                                                              (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                               >> 0x1aU)) 
                                                             | ((0x19U 
                                                                 == 
                                                                 (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                  >> 0x1aU)) 
                                                                | ((0x1aU 
                                                                    == 
                                                                    (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                     >> 0x1aU)) 
                                                                   | ((0x1bU 
                                                                       == 
                                                                       (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                        >> 0x1aU)) 
                                                                      | ((0x14U 
                                                                          == 
                                                                          (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                           >> 0x1aU)) 
                                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall) 
                                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch) 
                                                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_dbar) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nop)))))))))))))))))))))) 
                                          << 6U)) | 
                                ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                            & (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit))))) 
                                  << 5U) | ((0x15U 
                                             == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                 >> 0x1aU))
                                             ? 1U : (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h416d0694__0))));
    __Vtemp_h8c7c8e28__0[4U] = ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__mem_sign_exted) 
                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                     | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w))))) 
                                 << 0xaU) | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__src2_is_4) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi) 
                                                  | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i))) 
                                              << 9U) 
                                             | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__need_ui5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui) 
                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori) 
                                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori) 
                                                                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi) 
                                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i) 
                                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w) 
                                                                                | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1d0e0636__0))))))))))))))))))))) 
                                                 << 8U) 
                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__src2_is_4) 
                                                    << 7U) 
                                                   | __Vtemp_hbddc6129__0[4U]))));
    __Vtemp_h10f5efe2__0[4U] = ((0xfffff800U & ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
                                                  & (0x60000U 
                                                     == 
                                                     (0xf8000U 
                                                      & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))) 
                                                 << 0x18U) 
                                                | ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
                                                     & (0x68000U 
                                                        == 
                                                        (0xf8000U 
                                                         & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))) 
                                                    << 0x17U) 
                                                   | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w) 
                                                       << 0x16U) 
                                                      | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sra_w) 
                                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srai_w)) 
                                                          << 0x15U) 
                                                         | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srl_w) 
                                                              | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srli_w)) 
                                                             << 0x14U) 
                                                            | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sll_w) 
                                                                 | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slli_w)) 
                                                                << 0x13U) 
                                                               | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xor) 
                                                                    | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori)) 
                                                                   << 0x12U) 
                                                                  | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_or) 
                                                                       | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori)) 
                                                                      << 0x11U) 
                                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nor) 
                                                                         << 0x10U) 
                                                                        | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_and) 
                                                                             | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi)) 
                                                                            << 0xfU) 
                                                                           | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltu) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui)) 
                                                                               << 0xeU) 
                                                                              | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slt) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti)) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sub_w) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_add_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i) 
                                                                                | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1d0e0636__0))))))))))))))))) 
                                                                                << 0xbU))))))))))))))) 
                                | __Vtemp_h8c7c8e28__0[4U]);
    __Vtemp_h0d17e4e4__0[5U] = ((((1U & (IData)((((
                                                   (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))) 
                                                   >> 0x20U) 
                                                  & (1ULL 
                                                     | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                                        >> 0x20U))) 
                                                 | ((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))) 
                                                      >> 0x20U) 
                                                     & (1ULL 
                                                        | ((QData)((IData)(
                                                                           (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                                            >> 0x20U))) 
                                                           >> 0x20U))) 
                                                    | (((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))) 
                                                        >> 0x20U) 
                                                       & (1ULL 
                                                          | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)) 
                                                             >> 0x20U)))))))
                                   ? (((IData)((0x1ffffffffULL 
                                                & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                      | (((IData)((0x1ffffffffULL 
                                                   & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))))) 
                                          & (IData)(
                                                    (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                     >> 0x20U))) 
                                         | ((IData)(
                                                    (0x1ffffffffULL 
                                                     & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))))) 
                                            & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)))
                                   : ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)
                                       ? (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit)
                                       : vlSelf->__PVT__cpu__DOT__rd_csr_data)) 
                                 << 2U) | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ertn) 
                                            << 1U) 
                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp)));
    __Vtemp_h0d17e4e4__0[6U] = (((1U & (IData)(((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))) 
                                                  >> 0x20U) 
                                                 & (1ULL 
                                                    | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                                       >> 0x20U))) 
                                                | ((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))) 
                                                     >> 0x20U) 
                                                    & (1ULL 
                                                       | ((QData)((IData)(
                                                                          (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                                           >> 0x20U))) 
                                                          >> 0x20U))) 
                                                   | (((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))) 
                                                       >> 0x20U) 
                                                      & (1ULL 
                                                         | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)) 
                                                            >> 0x20U)))))))
                                  ? (((IData)((0x1ffffffffULL 
                                               & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))))) 
                                      & (IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                     | (((IData)((0x1ffffffffULL 
                                                  & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))))) 
                                         & (IData)(
                                                   (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                    >> 0x20U))) 
                                        | ((IData)(
                                                   (0x1ffffffffULL 
                                                    & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))))) 
                                           & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)))
                                  : ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)
                                      ? (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit)
                                      : vlSelf->__PVT__cpu__DOT__rd_csr_data)) 
                                >> 0x1eU);
    __Vtemp_h953c8cfc__0[6U] = (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                 << 0x1cU) | ((0xfff80000U 
                                               & (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp_ipe) 
                                                   << 0x1bU) 
                                                  | ((0x4000000U 
                                                      & ((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid)) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_break) 
                                                         << 0x19U) 
                                                        | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall) 
                                                            << 0x18U) 
                                                           | ((0xf00000U 
                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                                  << 0x14U)) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__has_int) 
                                                                 << 0x13U))))))) 
                                              | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask) 
                                                  << 0x12U) 
                                                 | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_we) 
                                                     << 0x11U) 
                                                    | ((0x1fff8U 
                                                        & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                           >> 7U)) 
                                                       | ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h6983a416__0) 
                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj) 
                                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w) 
                                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w) 
                                                                     | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w))))) 
                                                           << 2U) 
                                                          | __Vtemp_h0d17e4e4__0[6U]))))));
    __Vtemp_hd0ee12c5__0[7U] = ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                 << 0xcU) | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_idle) 
                                              << 0xbU) 
                                             | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush) 
                                                 << 0xaU) 
                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_to_btb) 
                                                    << 9U) 
                                                   | ((0x100U 
                                                       & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                          << 3U)) 
                                                      | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_need_reg_data) 
                                                           | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1c4a3e54__0)) 
                                                          << 7U) 
                                                         | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
                                                                << 5U) 
                                                               | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__mem_sign_exted) 
                                                                   << 4U) 
                                                                  | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                                      << 3U) 
                                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                                         << 2U) 
                                                                        | (((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar))))) 
                                                                             & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_valid)) 
                                                                            << 1U) 
                                                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill)))))))))))));
    __Vtemp_h73b336c9__0[0xaU] = ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h6983a416__0) 
                                    & (0x1400U == (0xfffc00U 
                                                   & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))) 
                                   << 0x1dU) | ((0xffe00000U 
                                                 & ((((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit) 
                                                      & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)) 
                                                     << 0x18U) 
                                                    | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                        << 0x17U) 
                                                       | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                           << 0x16U) 
                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                             << 0x15U))))) 
                                                | ((0xffffe000U 
                                                    & (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                        << 0x12U) 
                                                       | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                           << 0x11U) 
                                                          | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                              << 0x10U) 
                                                             | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                 << 0xfU) 
                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                    << 0xeU) 
                                                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                      << 0xdU))))))) 
                                                   | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w) 
                                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))) 
                                                       << 0xcU) 
                                                      | ((IData)(
                                                                 (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                                  >> 0x20U)) 
                                                         >> 0x14U)))));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[0U] = vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[0U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[1U] = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[1U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[2U] = (IData)(
                                                        (((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm)) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U]))));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[3U] = (IData)(
                                                        ((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm)) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U]))) 
                                                         >> 0x20U));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[4U] = ((0xc0000000U 
                                                  & ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                          | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h))) 
                                                      << 0x1fU) 
                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                            | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b))) 
                                                        << 0x1eU))) 
                                                 | ((0xfc000000U 
                                                     & ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w) 
                                                          | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_wu)) 
                                                         << 0x1dU) 
                                                        | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w) 
                                                             | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_wu)) 
                                                            << 0x1cU) 
                                                           | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w) 
                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_wu)) 
                                                               << 0x1bU) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w) 
                                                                 << 0x1aU))))) 
                                                    | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w) 
                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w) 
                                                               | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w)))) 
                                                        << 0x19U) 
                                                       | __Vtemp_h10f5efe2__0[4U])));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[5U] = __Vtemp_h0d17e4e4__0[5U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[6U] = (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                  << 0x1fU) 
                                                 | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch) 
                                                     << 0x1eU) 
                                                    | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                        << 0x1dU) 
                                                       | __Vtemp_h953c8cfc__0[6U])));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[7U] = __Vtemp_hd0ee12c5__0[7U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[8U] = ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                  >> 0x14U) 
                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64) 
                                                    << 0xcU));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[9U] = (((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64) 
                                                  >> 0x14U) 
                                                 | ((IData)(
                                                            (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                             >> 0x20U)) 
                                                    << 0xcU));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[0xaU] = __Vtemp_h73b336c9__0[0xaU];
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__1(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__1\n"); );
    // Init
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_ha7c13be7__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_ha7c13be7__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h95da6b40__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h95da6b40__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h64c8ed36__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h64c8ed36__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_hda09fe26__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_hda09fe26__0 = 0;
    CData/*2:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0 = 0;
    CData/*1:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_hc70d6735__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_hc70d6735__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h8157b4ad__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h8157b4ad__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h7517b185__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h7517b185__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_ha340f1e6__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_ha340f1e6__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_ha4228d15__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_ha4228d15__0 = 0;
    CData/*0:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h811e5890__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h811e5890__0 = 0;
    CData/*0:0*/ cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0;
    cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0 = 0;
    CData/*2:0*/ cpu__DOT__wb_stage__DOT____VdfgTmp_hb64b5cce__0;
    cpu__DOT__wb_stage__DOT____VdfgTmp_hb64b5cce__0 = 0;
    CData/*1:0*/ cpu__DOT__wb_stage__DOT____VdfgTmp_h05fe9576__0;
    cpu__DOT__wb_stage__DOT____VdfgTmp_h05fe9576__0 = 0;
    IData/*19:0*/ cpu__DOT__wb_stage__DOT____VdfgTmp_he899fe78__0;
    cpu__DOT__wb_stage__DOT____VdfgTmp_he899fe78__0 = 0;
    QData/*62:0*/ cpu__DOT__wb_stage__DOT____VdfgTmp_he2911870__0;
    cpu__DOT__wb_stage__DOT____VdfgTmp_he2911870__0 = 0;
    IData/*19:0*/ cpu__DOT__wb_stage__DOT____VdfgTmp_hea49ee00__0;
    cpu__DOT__wb_stage__DOT____VdfgTmp_hea49ee00__0 = 0;
    QData/*62:0*/ cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0;
    cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0 = 0;
    CData/*0:0*/ __VdfgTmp_h26881c5e__0;
    __VdfgTmp_h26881c5e__0 = 0;
    VlWide<4>/*127:0*/ __Vtemp_h38de2501__0;
    VlWide<5>/*159:0*/ __Vtemp_h21808a7a__0;
    VlWide<7>/*223:0*/ __Vtemp_h27197a69__0;
    VlWide<3>/*95:0*/ __Vtemp_h9cf7bc36__0;
    VlWide<3>/*95:0*/ __Vtemp_h498d23a3__0;
    VlWide<3>/*95:0*/ __Vtemp_hcfd7f9d2__0;
    VlWide<3>/*95:0*/ __Vtemp_hb400cdeb__0;
    // Body
    vlSelf->__VdfgTmp_hd72442ad__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7ffU 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 0xbU))));
    vlSelf->__VdfgTmp_hd71b4a8a__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3ffU 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 0xaU))));
    vlSelf->__VdfgTmp_hd65c44e5__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1ffU 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 9U))));
    vlSelf->__VdfgTmp_hd67691e4__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fU 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 7U))));
    vlSelf->__VdfgTmp_hd66a0d7d__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fU 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 6U))));
    vlSelf->__VdfgTmp_hd66f5582__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fU 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 5U))));
    vlSelf->__VdfgTmp_hd666047e__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (7U 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 3U))));
    vlSelf->__VdfgTmp_hd638d239__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (3U 
                                                         & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                            & (~ ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                  >> 2U))));
    vlSelf->__VdfgTmp_ha60326f2__0 = (IData)((1U == 
                                              (3U & (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid))));
    vlSelf->__VdfgTmp_hef3bf6e7__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [0xfU]) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                          >> 0xfU)));
    vlSelf->__VdfgTmp_hef3821b5__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [0xeU]) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                          >> 0xeU)));
    vlSelf->__VdfgTmp_hef7d2fec__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [0xdU]) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                          >> 0xdU)));
    vlSelf->__VdfgTmp_hd0f0d5da__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [0xcU]) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                          >> 0xcU)));
    vlSelf->__VdfgTmp_hd0f3f017__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [0xbU]) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                          >> 0xbU)));
    vlSelf->__VdfgTmp_hea1021fd__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [0xaU]) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                          >> 0xaU)));
    vlSelf->__VdfgTmp_hea79f5b1__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [9U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 9U)));
    vlSelf->__VdfgTmp_hef7d1ebb__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [8U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 8U)));
    vlSelf->__VdfgTmp_hef734879__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [7U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 7U)));
    vlSelf->__VdfgTmp_hec9625f7__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [6U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 6U)));
    vlSelf->__VdfgTmp_hef1da2f3__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [5U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 5U)));
    vlSelf->__VdfgTmp_h86498323__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [4U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 4U)));
    vlSelf->__VdfgTmp_h8651482e__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [3U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 3U)));
    vlSelf->__VdfgTmp_h86e948c6__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [2U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 2U)));
    vlSelf->__VdfgTmp_hd0d3d28e__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                          [1U]) & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                   >> 1U)));
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry 
        = ((0x80000000U & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                           & ((~ (IData)((0U != vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                          [0x1fU]))) 
                              << 0x1fU))) | ((0x40000000U 
                                              & (((~ (IData)(
                                                             (0U 
                                                              != 
                                                              vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                              [0x1eU]))) 
                                                  << 0x1eU) 
                                                 & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                             | ((0x20000000U 
                                                 & (((~ (IData)(
                                                                (0U 
                                                                 != 
                                                                 vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                 [0x1dU]))) 
                                                     << 0x1dU) 
                                                    & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                | ((0x10000000U 
                                                    & (((~ (IData)(
                                                                   (0U 
                                                                    != 
                                                                    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                    [0x1cU]))) 
                                                        << 0x1cU) 
                                                       & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                   | ((0x8000000U 
                                                       & (((~ (IData)(
                                                                      (0U 
                                                                       != 
                                                                       vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                       [0x1bU]))) 
                                                           << 0x1bU) 
                                                          & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                      | ((0x4000000U 
                                                          & (((~ (IData)(
                                                                         (0U 
                                                                          != 
                                                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                          [0x1aU]))) 
                                                              << 0x1aU) 
                                                             & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                         | ((0x2000000U 
                                                             & (((~ (IData)(
                                                                            (0U 
                                                                             != 
                                                                             vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                             [0x19U]))) 
                                                                 << 0x19U) 
                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                            | ((0x1000000U 
                                                                & (((~ (IData)(
                                                                               (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x18U]))) 
                                                                    << 0x18U) 
                                                                   & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                               | ((0x800000U 
                                                                   & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x17U]))) 
                                                                       << 0x17U) 
                                                                      & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                  | ((0x400000U 
                                                                      & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x16U]))) 
                                                                          << 0x16U) 
                                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                     | ((0x200000U 
                                                                         & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x15U]))) 
                                                                             << 0x15U) 
                                                                            & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                        | ((0x100000U 
                                                                            & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x14U]))) 
                                                                                << 0x14U) 
                                                                               & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                           | ((0x80000U 
                                                                               & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x13U]))) 
                                                                                << 0x13U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                              | ((0x40000U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x12U]))) 
                                                                                << 0x12U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x20000U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x11U]))) 
                                                                                << 0x11U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x10000U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0x10U]))) 
                                                                                << 0x10U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x8000U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0xfU]))) 
                                                                                << 0xfU) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x4000U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0xeU]))) 
                                                                                << 0xeU) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x2000U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0xdU]))) 
                                                                                << 0xdU) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x1000U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0xcU]))) 
                                                                                << 0xcU) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x800U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0xbU]))) 
                                                                                << 0xbU) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x400U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0xaU]))) 
                                                                                << 0xaU) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x200U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [9U]))) 
                                                                                << 9U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x100U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [8U]))) 
                                                                                << 8U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x80U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [7U]))) 
                                                                                << 7U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x40U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [6U]))) 
                                                                                << 6U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x20U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [5U]))) 
                                                                                << 5U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((0x10U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [4U]))) 
                                                                                << 4U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((8U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [3U]))) 
                                                                                << 3U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((4U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [2U]))) 
                                                                                << 2U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | ((2U 
                                                                                & (((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [1U]))) 
                                                                                << 1U) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)) 
                                                                                | (1U 
                                                                                & ((~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                                                                [0U]))) 
                                                                                & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)))))))))))))))))))))))))))))))));
    vlSelf->__VdfgTmp_h287669a1__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x1fU))));
    vlSelf->__VdfgTmp_h284b4e24__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x1eU))));
    vlSelf->__VdfgTmp_h2b2d3ac1__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x1dU))));
    vlSelf->__VdfgTmp_h2b22ba23__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x1cU))));
    vlSelf->__VdfgTmp_h2b26b937__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7ffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x1bU))));
    vlSelf->__VdfgTmp_h2b39d584__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3ffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x1aU))));
    vlSelf->__VdfgTmp_h2b9f81d9__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1ffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x19U))));
    vlSelf->__VdfgTmp_h2b92025f__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xffffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x18U))));
    vlSelf->__VdfgTmp_h2b9503ed__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x17U))));
    vlSelf->__VdfgTmp_h2b227c39__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x16U))));
    vlSelf->__VdfgTmp_h2b2ff7d2__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x15U))));
    vlSelf->__VdfgTmp_h284bb0ae__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x14U))));
    vlSelf->__VdfgTmp_h2b8ddfe0__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0xfU))));
    vlSelf->__VdfgTmp_h286f7fb9__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0xeU))));
    vlSelf->__VdfgTmp_h2bd4a660__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0xdU))));
    vlSelf->__VdfgTmp_h2bd0af7c__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0xcU))));
    vlSelf->__VdfgTmp_h2bd66e9a__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7ffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0xbU))));
    vlSelf->__VdfgTmp_h2bd25251__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3ffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0xaU))));
    vlSelf->__VdfgTmp_h2b9f70b0__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1ffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 9U))));
    vlSelf->__VdfgTmp_h28475190__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 8U))));
    vlSelf->__VdfgTmp_h28431d65__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 7U))));
    vlSelf->__VdfgTmp_h28610961__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 6U))));
    vlSelf->__VdfgTmp_h286d4908__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 5U))));
    vlSelf->__VdfgTmp_h2b8acf86__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 4U))));
    vlSelf->__VdfgTmp_h2870c5f6__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7ffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x13U))));
    vlSelf->__VdfgTmp_h2872c95d__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3ffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x12U))));
    vlSelf->__VdfgTmp_h2bbd3cde__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1ffffU 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 0x11U))));
    vlSelf->__VdfgTmp_h2b9506da__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (7U 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 3U))));
    vlSelf->__VdfgTmp_h2b9112e1__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (3U 
                                                         & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                            & (~ (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                  >> 2U))));
    vlSelf->__VdfgTmp_h21b09c90__0 = (IData)((1U == 
                                              (3U & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)));
    vlSelf->__VdfgTmp_h28de6bba__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x1fU]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x1fU)));
    vlSelf->__VdfgTmp_h281e3aa3__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x1eU]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x1eU)));
    vlSelf->__VdfgTmp_h287d9e6a__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x1dU]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x1dU)));
    vlSelf->__VdfgTmp_h29902bb6__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x1cU]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x1cU)));
    vlSelf->__VdfgTmp_h282df2b4__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x1bU]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x1bU)));
    vlSelf->__VdfgTmp_h28447f91__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x1aU]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x1aU)));
    vlSelf->__VdfgTmp_h2f17bd15__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x19U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x19U)));
    vlSelf->__VdfgTmp_h2b34b778__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x18U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x18U)));
    vlSelf->__VdfgTmp_h2846d38b__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x17U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x17U)));
    vlSelf->__VdfgTmp_h283518d9__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x16U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x16U)));
    vlSelf->__VdfgTmp_h28d0af6a__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x15U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x15U)));
    vlSelf->__VdfgTmp_h28d16f34__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x14U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x14U)));
    __VdfgTmp_h26881c5e__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                              & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                   >> 2U) == vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                  [0x10U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                              >> 0x10U)));
    vlSelf->__VdfgTmp_h28b5f3c3__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x13U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x13U)));
    vlSelf->__VdfgTmp_h28b1ebfc__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x12U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x12U)));
    vlSelf->__VdfgTmp_h2961036f__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0x11U]) 
                                         & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                            >> 0x11U)));
    vlSelf->__VdfgTmp_h2991042b__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0xfU]) & 
                                         (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                          >> 0xfU)));
    vlSelf->__VdfgTmp_h28667139__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0xeU]) & 
                                         (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                          >> 0xeU)));
    vlSelf->__VdfgTmp_h29e8ee51__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0xdU]) & 
                                         (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                          >> 0xdU)));
    vlSelf->__VdfgTmp_h29c04841__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0xcU]) & 
                                         (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                          >> 0xcU)));
    vlSelf->__VdfgTmp_h29f565de__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0xbU]) & 
                                         (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                          >> 0xbU)));
    vlSelf->__VdfgTmp_h29ed2521__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [0xaU]) & 
                                         (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                          >> 0xaU)));
    vlSelf->__VdfgTmp_h284c4815__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [9U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 9U)));
    vlSelf->__VdfgTmp_h2b42431a__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [8U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 8U)));
    vlSelf->__VdfgTmp_h28a85f11__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [7U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 7U)));
    vlSelf->__VdfgTmp_h28689c53__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [6U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 6U)));
    vlSelf->__VdfgTmp_h2678667e__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [5U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 5U)));
    vlSelf->__VdfgTmp_h263ed55f__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [4U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 4U)));
    vlSelf->__VdfgTmp_h2865ac30__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [3U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 3U)));
    vlSelf->__VdfgTmp_h29829d30__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [2U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 2U)));
    vlSelf->__VdfgTmp_h2916341e__0 = ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                      & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                           >> 2U) == 
                                          vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                          [1U]) & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                   >> 1U)));
    if (((IData)(vlSelf->__PVT__cpu__DOT__fs_to_ds_valid) 
         & (IData)(vlSelf->__PVT__cpu__DOT__ds_allowin))) {
        __Vtemp_h38de2501__0[2U] = ((vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_ret_pc_t 
                                     << 0xdU) | ((0x1f00U 
                                                  & ((((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_en))) 
                                                       & (IData)(
                                                                 (vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_buffer 
                                                                  >> 0x20U))) 
                                                      | (IData)(vlSelf->__PVT__cpu__DOT__btb_index)) 
                                                     << 8U)) 
                                                 | ((((IData)(vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_ha3d303c7__0) 
                                                      | (IData)(vlSelf->__PVT__cpu__DOT__btb_taken)) 
                                                     << 7U) 
                                                    | ((((IData)(vlSelf->__PVT__cpu__DOT__btb_en) 
                                                         | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_en)) 
                                                        << 6U) 
                                                       | ((((0x10U 
                                                             == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                                                            & ((~ 
                                                                ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_icacop) 
                                                                 | (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_uncache_en))) 
                                                               & (IData)(vlSelf->__PVT__cpu__DOT__inst_ret_last))) 
                                                           << 5U) 
                                                          | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_excp) 
                                                              << 4U) 
                                                             | (((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_ppi) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_pif) 
                                                                    << 2U) 
                                                                   | (((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_tlbr) 
                                                                       << 1U) 
                                                                      | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_num))))))))));
        vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[0U] 
            = (IData)((((QData)((IData)(((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_buff_enable)
                                          ? vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_rd_buff
                                          : vlSelf->__PVT__cpu__DOT__inst_rdata))) 
                        << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc))));
        vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
            = (IData)(((((QData)((IData)(((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_buff_enable)
                                           ? vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_rd_buff
                                           : vlSelf->__PVT__cpu__DOT__inst_rdata))) 
                         << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc))) 
                       >> 0x20U));
        vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
            = __Vtemp_h38de2501__0[2U];
        vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[3U] 
            = (vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_ret_pc_t 
               >> 0x13U);
    }
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_buffer 
        = ((0x8000U & (((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                         [0xfU]) ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                         : (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                            >> 8U)) << 0xfU)) | ((0x4000U 
                                                  & (((0xcU 
                                                       == 
                                                       vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                       [0xeU])
                                                       ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                       : 
                                                      (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 8U)) 
                                                     << 0xeU)) 
                                                 | ((0x2000U 
                                                     & (((0xcU 
                                                          == 
                                                          vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                          [0xdU])
                                                          ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                          : 
                                                         (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                          >> 8U)) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & (((0xcU 
                                                             == 
                                                             vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                             [0xcU])
                                                             ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                             : 
                                                            (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                             >> 8U)) 
                                                           << 0xcU)) 
                                                       | ((0x800U 
                                                           & (((0xcU 
                                                                == 
                                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                [0xbU])
                                                                ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                : 
                                                               (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                >> 8U)) 
                                                              << 0xbU)) 
                                                          | ((0x400U 
                                                              & (((0xcU 
                                                                   == 
                                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                   [0xaU])
                                                                   ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                   : 
                                                                  (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                   >> 8U)) 
                                                                 << 0xaU)) 
                                                             | ((0x200U 
                                                                 & (((0xcU 
                                                                      == 
                                                                      vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                      [9U])
                                                                      ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                      : 
                                                                     (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                      >> 8U)) 
                                                                    << 9U)) 
                                                                | ((0x100U 
                                                                    & (((0xcU 
                                                                         == 
                                                                         vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                         [8U])
                                                                         ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                         : 
                                                                        (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                         >> 8U)) 
                                                                       << 8U)) 
                                                                   | ((0x80U 
                                                                       & (((0xcU 
                                                                            == 
                                                                            vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                            [7U])
                                                                            ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                            : 
                                                                           (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                            >> 8U)) 
                                                                          << 7U)) 
                                                                      | ((0x40U 
                                                                          & (((0xcU 
                                                                               == 
                                                                               vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                               [6U])
                                                                               ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                               : 
                                                                              (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                               >> 8U)) 
                                                                             << 6U)) 
                                                                         | ((0x20U 
                                                                             & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                                [5U])
                                                                                 ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                                >> 8U)) 
                                                                                << 5U)) 
                                                                            | ((0x10U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                                [4U])
                                                                                 ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                                >> 8U)) 
                                                                                << 4U)) 
                                                                               | ((8U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                                [3U])
                                                                                 ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                                >> 8U)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                                [2U])
                                                                                 ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                                >> 8U)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                                [1U])
                                                                                 ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                                >> 8U)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & ((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                                                [0U])
                                                                                 ? (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                                                >> 8U))))))))))))))))));
    vlSelf->csr_dmw1_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw1;
    vlSelf->csr_dmw0_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw0;
    vlSelf->csr_pgdh_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdh;
    vlSelf->csr_pgdl_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdl;
    vlSelf->csr_save3_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save3;
    vlSelf->csr_save2_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save2;
    vlSelf->csr_save1_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save1;
    vlSelf->csr_save0_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save0;
    vlSelf->csr_tid_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid;
    vlSelf->csr_tlbrentry_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbrentry;
    vlSelf->csr_eentry_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_eentry;
    vlSelf->csr_ectl_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ectl;
    vlSelf->csr_era_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_era;
    vlSelf->csr_badv_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_badv;
    vlSelf->__PVT__cpu__DOT__ds_timer_64 = (vlSelf->__PVT__cpu__DOT__u_csr__DOT__timer_64 
                                            + (((QData)((IData)(
                                                                (- (IData)(
                                                                           (vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cntc 
                                                                            >> 0x1fU))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cntc))));
    vlSelf->csr_llbctl_diff = ((0xfffffffeU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_llbctl) 
                               | (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit));
    if (vlSelf->__PVT__cpu__DOT__reset) {
        vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid 
            = (0xa0000U | (0x3ffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid));
        vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tcfg 
            = (0xfffffffeU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tcfg);
        vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_num = 0U;
        vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc = 0x1bfffffcU;
        vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
            = (0xff00001fU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx);
        vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
            = (0xbfffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx);
        vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
            = (0xffffffe0U & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx);
    } else {
        if (((IData)(vlSelf->__PVT__cpu__DOT__csr_wr_en) 
             & (0x1800U == (0x3fff00U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])))) {
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid 
                = ((0xfffffc00U & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid) 
                   | (0x3ffU & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                >> 8U)));
        } else if (vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_valid_wr_en) {
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid 
                = ((0xfffffc00U & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid) 
                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                   [(0xfU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)]);
        } else if (vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_invalid_wr_en) {
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid 
                = (0xfffffc00U & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid);
        }
        if (vlSelf->__PVT__cpu__DOT__u_csr__DOT__tcfg_wen) {
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tcfg 
                = ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                    << 0x18U) | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                 >> 8U));
        }
        if (((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__to_fs_valid) 
             & ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_allowin) 
                | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_go_dirt)))) {
            vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_num 
                = vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_excp_adef;
            vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc 
                = vlSelf->__PVT__cpu__DOT__fetch_pc;
        }
        if (((IData)(vlSelf->__PVT__cpu__DOT__csr_wr_en) 
             & (0x1000U == (0x3fff00U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])))) {
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                = ((0xfffffff0U & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                   | (0xfU & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                              >> 8U)));
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                = ((0xc0ffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                   | (0x3f000000U & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                     << 0x18U)));
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                = ((0x7fffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                   | (0x80000000U & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                     << 0x18U)));
        } else if ((1U & (((1U & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                  >> 9U)) | ((IData)(vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_h292b3a37__0) 
                                             >> 4U)) 
                          & ((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__commit_inst))) 
                             >> 4U)))) {
            if ((0x400U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U])) {
                vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                    = ((0xffffffe0U & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                       | (0x1fU & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                   >> 0xbU)));
                vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                    = (0x7fffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx);
            } else {
                vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                    = (0x80000000U | vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx);
            }
        } else if (vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_valid_wr_en) {
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                = ((0xc0ffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                   | (0x3f000000U & vlSelf->__PVT__cpu__DOT__tlbr_tlbidx));
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                = ((0x7fffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                   | (0x80000000U & vlSelf->__PVT__cpu__DOT__tlbr_tlbidx));
        } else if (vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_invalid_wr_en) {
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                = (0xc0ffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx);
            vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                = ((0x7fffffffU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                   | (0x80000000U & vlSelf->__PVT__cpu__DOT__tlbr_tlbidx));
        }
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state 
        = vlSelf->__Vdly__cpu__DOT__dcache__DOT__write_buffer_state;
    if (vlSelf->__Vdlyvset__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn__v0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn[vlSelf->__Vdlyvdim0__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn__v0] 
            = vlSelf->__Vdlyvval__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn__v0;
    }
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd = vlSelf->__Vdly__cpu__DOT__u_csr__DOT__csr_crmd;
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__timer_en = vlSelf->__Vdly__cpu__DOT__u_csr__DOT__timer_en;
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tval = vlSelf->__Vdly__cpu__DOT__u_csr__DOT__csr_tval;
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[0U][0U] 
        = vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
        [0U][0U];
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[0U][1U] 
        = vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
        [0U][1U];
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[0U][2U] 
        = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                    [0U][3U])) << 0x20U) 
                   | (QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                     [0U][2U]))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[0U][3U] 
        = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                     [0U][3U])) << 0x20U) 
                    | (QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                      [0U][2U]))) >> 0x20U));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[1U][0U] 
        = vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
        [1U][0U];
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[1U][1U] 
        = vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
        [1U][1U];
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[1U][2U] 
        = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                    [1U][3U])) << 0x20U) 
                   | (QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                     [1U][2U]))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[1U][3U] 
        = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                     [1U][3U])) << 0x20U) 
                    | (QData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta
                                      [1U][2U]))) >> 0x20U));
    vlSelf->__PVT__cpu__DOT__icache__DOT__invalid_way 
        = (((IData)((2U == (IData)(vlSelf->cpu__DOT__icache__DOT____Vcellinp__sel_one_invalid__in))) 
            << 1U) | (1U & (IData)(vlSelf->cpu__DOT__icache__DOT____Vcellinp__sel_one_invalid__in)));
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
        = (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_r 
           & ((~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_add_entry_dec) 
              | (- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__btb_add_entry_r)))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[0U][0U] 
        = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
        [0U][0U];
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[0U][1U] 
        = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
        [0U][1U];
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[0U][2U] 
        = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                    [0U][3U])) << 0x20U) 
                   | (QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                     [0U][2U]))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[0U][3U] 
        = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                     [0U][3U])) << 0x20U) 
                    | (QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                      [0U][2U]))) >> 0x20U));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[1U][0U] 
        = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
        [1U][0U];
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[1U][1U] 
        = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
        [1U][1U];
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[1U][2U] 
        = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                    [1U][3U])) << 0x20U) 
                   | (QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                     [1U][2U]))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[1U][3U] 
        = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                     [1U][3U])) << 0x20U) 
                    | (QData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta
                                      [1U][2U]))) >> 0x20U));
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_add_entry_index 
        = (0xfU & ((0xffffU == (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid))
                    ? (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fcsr)
                    : ((3U & ((- (IData)((1U & ((IData)(vlSelf->__VdfgTmp_hd666047e__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_hd638d239__0) 
                                                   | ((IData)(vlSelf->__VdfgTmp_ha60326f2__0) 
                                                      | (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))))) 
                              & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_ha60326f2__0)))) 
                                 | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_hd638d239__0)))) 
                                    | (- (IData)((IData)(vlSelf->__VdfgTmp_hd666047e__0))))))) 
                       | (((- (IData)((1U & ((IData)(vlSelf->__VdfgTmp_hd67691e4__0) 
                                             | ((IData)(vlSelf->__VdfgTmp_hd66a0d7d__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_hd66f5582__0) 
                                                   | ((~ (IData)(
                                                                 (0U 
                                                                  != 
                                                                  (0xfU 
                                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                                      & (~ 
                                                         ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                          >> 4U))))))))) 
                           & (4U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_hd66f5582__0)))) 
                                          | ((2U & 
                                              (- (IData)((IData)(vlSelf->__VdfgTmp_hd66a0d7d__0)))) 
                                             | (- (IData)((IData)(vlSelf->__VdfgTmp_hd67691e4__0)))))))) 
                          | (((- (IData)((1U & ((IData)(vlSelf->__VdfgTmp_hd72442ad__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_hd71b4a8a__0) 
                                                   | ((IData)(vlSelf->__VdfgTmp_hd65c44e5__0) 
                                                      | ((~ (IData)(
                                                                    (0U 
                                                                     != 
                                                                     (0xffU 
                                                                      & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                                         & (~ 
                                                            ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                             >> 8U))))))))) 
                              & (8U | (3U & ((1U & 
                                              (- (IData)((IData)(vlSelf->__VdfgTmp_hd65c44e5__0)))) 
                                             | ((2U 
                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_hd71b4a8a__0)))) 
                                                | (- (IData)((IData)(vlSelf->__VdfgTmp_hd72442ad__0)))))))) 
                             | ((- (IData)((1U & ((IData)(vlSelf->__VdfgTmp_hd654fdc0__0) 
                                                  | ((IData)(vlSelf->__VdfgTmp_hd64bffee__0) 
                                                     | ((IData)(vlSelf->__VdfgTmp_hd64efe69__0) 
                                                        | ((~ (IData)(
                                                                      (0U 
                                                                       != 
                                                                       (0xfffU 
                                                                        & (~ (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid)))))) 
                                                           & (~ 
                                                              ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid) 
                                                               >> 0xcU))))))))) 
                                & (0xcU | (3U & ((1U 
                                                  & (- (IData)((IData)(vlSelf->__VdfgTmp_hd64efe69__0)))) 
                                                 | ((2U 
                                                     & (- (IData)((IData)(vlSelf->__VdfgTmp_hd64bffee__0)))) 
                                                    | (- (IData)((IData)(vlSelf->__VdfgTmp_hd654fdc0__0)))))))))))));
    vlSelf->cpu__DOT__btb__DOT__encode_ras_match__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h8651482e__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h86e948c6__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_hd0d3d28e__0) 
                                  << 1U) | ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                            & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                                 >> 2U) 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc
                                                [0U]) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid))))));
    vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h2870c5f6__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h2872c95d__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h2bbd3cde__0) 
                                  << 1U) | (1U & ((~ (IData)(
                                                             (0U 
                                                              != 
                                                              (0xffffU 
                                                               & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid))))) 
                                                  & (~ 
                                                     (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid 
                                                      >> 0x10U)))))));
    vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h2b9506da__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h2b9112e1__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h21b09c90__0) 
                                  << 1U) | (1U & (~ vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)))));
    vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__two__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h28b5f3c3__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h28b1ebfc__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h2961036f__0) 
                                  << 1U) | (IData)(__VdfgTmp_h26881c5e__0))));
    vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__one__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h2865ac30__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h29829d30__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h2916341e__0) 
                                  << 1U) | ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r) 
                                            & (((vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r 
                                                 >> 2U) 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc
                                                [0U]) 
                                               & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)))));
    if (vlSelf->__Vdlyvset__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid__v0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid[vlSelf->__Vdlyvdim0__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid__v0] 
            = vlSelf->__Vdlyvval__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid__v0;
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[0U][0U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
              & (0U == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[0U][1U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
              & (4U == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[0U][2U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
              & (8U == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[0U][3U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
              & (0xcU == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[1U][0U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & (IData)((((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
                       >> 1U) & (0U == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[1U][1U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & (IData)((((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
                       >> 1U) & (4U == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[1U][2U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & (IData)((((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
                       >> 1U) & (8U == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[1U][3U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
           & (IData)((((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way) 
                       >> 1U) & (0xcU == (0xcU & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset))))));
    vlSelf->csr_tlbelo0_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo0;
    vlSelf->csr_tlbelo1_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo1;
    vlSelf->csr_tlbehi_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbehi;
    vlSelf->csr_prmd_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_prmd;
    vlSelf->csr_crmd_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd;
    vlSelf->csr_tval_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tval;
    vlSelf->csr_estat_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_estat;
    vlSelf->__PVT__cpu__DOT__has_int = ((0U != (0x1fffU 
                                                & (vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ectl 
                                                   & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_estat))) 
                                        & (vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd 
                                           >> 2U));
    vlSelf->__VdfgTmp_h144a4430__0 = ((vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                       >> 0x1fU) & 
                                      (~ (IData)((0U 
                                                  != 
                                                  (0x7fffffffU 
                                                   & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))));
    vlSelf->__VdfgTmp_h1470b1c1__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fffffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x1eU)));
    vlSelf->__VdfgTmp_h14758488__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fffffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x1dU)));
    vlSelf->__VdfgTmp_h1449ec64__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfffffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x1cU)));
    vlSelf->__VdfgTmp_h147b4aa2__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7ffffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x1bU)));
    vlSelf->__VdfgTmp_h295efed9__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3ffffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x1aU)));
    vlSelf->__VdfgTmp_h1492eda8__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1ffffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x19U)));
    vlSelf->__VdfgTmp_h1478ca08__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xffffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x18U)));
    vlSelf->__VdfgTmp_h147c90ec__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x17U)));
    vlSelf->__VdfgTmp_h14673d06__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x16U)));
    vlSelf->__VdfgTmp_h1462d6b9__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x15U)));
    vlSelf->__VdfgTmp_h146f23bf__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x14U)));
    vlSelf->__VdfgTmp_h14afccdb__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0xfU)));
    vlSelf->__VdfgTmp_h1468056a__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0xeU)));
    vlSelf->__VdfgTmp_h14940457__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0xdU)));
    vlSelf->__VdfgTmp_h1490813d__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0xcU)));
    vlSelf->__VdfgTmp_h147e8bf1__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7ffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0xbU)));
    vlSelf->__VdfgTmp_h147a4322__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3ffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0xaU)));
    vlSelf->__VdfgTmp_h1427ccc7__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1ffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 9U)));
    vlSelf->__VdfgTmp_h14219459__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 8U)));
    vlSelf->__VdfgTmp_h144d61b4__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7fU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 7U)));
    vlSelf->__VdfgTmp_h14924f66__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3fU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 6U)));
    vlSelf->__VdfgTmp_h149ff3f7__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1fU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 5U)));
    vlSelf->__VdfgTmp_h149b35b7__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 4U)));
    vlSelf->__VdfgTmp_h145a0ce5__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x7ffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x13U)));
    vlSelf->__VdfgTmp_h14462e1a__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x3ffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x12U)));
    vlSelf->__VdfgTmp_h1485ccbd__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0x1ffffU 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 0x11U)));
    vlSelf->__VdfgTmp_h145f01b1__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (7U 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 3U)));
    vlSelf->__VdfgTmp_h145b0fca__0 = (1U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (3U 
                                                         & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                               >> 2U)));
    vlSelf->__VdfgTmp_h88130675__0 = (IData)((2U == 
                                              (3U & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)));
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_match = 
        ((0U != (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_ptr)) 
         & ((IData)(vlSelf->__VdfgTmp_hef3bf6e7__0) 
            | ((IData)(vlSelf->__VdfgTmp_hef3821b5__0) 
               | ((IData)(vlSelf->__VdfgTmp_hef7d2fec__0) 
                  | ((IData)(vlSelf->__VdfgTmp_hd0f0d5da__0) 
                     | ((IData)(vlSelf->__VdfgTmp_hd0f3f017__0) 
                        | ((IData)(vlSelf->__VdfgTmp_hea1021fd__0) 
                           | ((IData)(vlSelf->__VdfgTmp_hea79f5b1__0) 
                              | ((IData)(vlSelf->__VdfgTmp_hef7d1ebb__0) 
                                 | ((IData)(vlSelf->__VdfgTmp_hef734879__0) 
                                    | ((IData)(vlSelf->__VdfgTmp_hec9625f7__0) 
                                       | ((IData)(vlSelf->__VdfgTmp_hef1da2f3__0) 
                                          | ((IData)(vlSelf->__VdfgTmp_h86498323__0) 
                                             | (0U 
                                                != (IData)(vlSelf->cpu__DOT__btb__DOT__encode_ras_match__DOT____Vcellinp__one__in)))))))))))))));
    vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h2991042b__0) 
            << 0xfU) | (((IData)(vlSelf->__VdfgTmp_h28667139__0) 
                         << 0xeU) | (((IData)(vlSelf->__VdfgTmp_h29e8ee51__0) 
                                      << 0xdU) | (((IData)(vlSelf->__VdfgTmp_h29c04841__0) 
                                                   << 0xcU) 
                                                  | (((IData)(vlSelf->__VdfgTmp_h29f565de__0) 
                                                      << 0xbU) 
                                                     | (((IData)(vlSelf->__VdfgTmp_h29ed2521__0) 
                                                         << 0xaU) 
                                                        | (((IData)(vlSelf->__VdfgTmp_h284c4815__0) 
                                                            << 9U) 
                                                           | (((IData)(vlSelf->__VdfgTmp_h2b42431a__0) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->__VdfgTmp_h28a85f11__0) 
                                                                  << 7U) 
                                                                 | (((IData)(vlSelf->__VdfgTmp_h28689c53__0) 
                                                                     << 6U) 
                                                                    | (((IData)(vlSelf->__VdfgTmp_h2678667e__0) 
                                                                        << 5U) 
                                                                       | (((IData)(vlSelf->__VdfgTmp_h263ed55f__0) 
                                                                           << 4U) 
                                                                          | (IData)(vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__one__DOT____Vcellinp__one__in)))))))))))));
    if ((1U & (~ (((IData)(vlSelf->__PVT__cpu__DOT__reset) 
                   | ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_ready_go) 
                      & (IData)(vlSelf->__PVT__cpu__DOT__ds_allowin))) 
                  | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign))))) {
        if (((IData)(vlSelf->__PVT__cpu__DOT__inst_data_ok) 
             & (~ (IData)(vlSelf->__PVT__cpu__DOT__ds_allowin)))) {
            vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_rd_buff 
                = vlSelf->__PVT__cpu__DOT__inst_rdata;
        }
    }
    if ((((IData)(vlSelf->__PVT__cpu__DOT__reset) | 
          ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_ready_go) 
           & (IData)(vlSelf->__PVT__cpu__DOT__ds_allowin))) 
         | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign))) {
        vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_buff_enable = 0U;
    } else if (((IData)(vlSelf->__PVT__cpu__DOT__inst_data_ok) 
                & (~ (IData)(vlSelf->__PVT__cpu__DOT__ds_allowin)))) {
        vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_buff_enable = 1U;
    }
    if ((((IData)(vlSelf->__PVT__cpu__DOT__reset) | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign)) 
         | (IData)(vlSelf->__PVT__cpu__DOT__fetch_en))) {
        vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_en = 0U;
    } else if (((IData)(vlSelf->__PVT__cpu__DOT__btb_en) 
                & (~ (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_ready_go)))) {
        vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_en = 1U;
    }
    if ((1U & (~ (((IData)(vlSelf->__PVT__cpu__DOT__reset) 
                   | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign)) 
                  | (IData)(vlSelf->__PVT__cpu__DOT__fetch_en))))) {
        if (((IData)(vlSelf->__PVT__cpu__DOT__btb_en) 
             & (~ (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_ready_go)))) {
            vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_buffer 
                = (((QData)((IData)(vlSelf->__PVT__cpu__DOT__btb_taken)) 
                    << 0x25U) | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__btb_index)) 
                                  << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__btb_ret_pc))));
        }
    }
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__op_31_26_d 
        = (((QData)((IData)((0x3fU == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                       >> 0x1aU)))) 
            << 0x3fU) | (((QData)((IData)((0x3eU == 
                                           (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                            >> 0x1aU)))) 
                          << 0x3eU) | (((QData)((IData)(
                                                        (0x3dU 
                                                         == 
                                                         (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                          >> 0x1aU)))) 
                                        << 0x3dU) | 
                                       (((QData)((IData)(
                                                         (0x3cU 
                                                          == 
                                                          (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                           >> 0x1aU)))) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(
                                                            (0x3bU 
                                                             == 
                                                             (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                              >> 0x1aU)))) 
                                            << 0x3bU) 
                                           | (((QData)((IData)(
                                                               (0x3aU 
                                                                == 
                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                 >> 0x1aU)))) 
                                               << 0x3aU) 
                                              | (((QData)((IData)(
                                                                  (0x39U 
                                                                   == 
                                                                   (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                    >> 0x1aU)))) 
                                                  << 0x39U) 
                                                 | (((QData)((IData)(
                                                                     (0x38U 
                                                                      == 
                                                                      (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                       >> 0x1aU)))) 
                                                     << 0x38U) 
                                                    | (((QData)((IData)(
                                                                        (0x37U 
                                                                         == 
                                                                         (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                          >> 0x1aU)))) 
                                                        << 0x37U) 
                                                       | (((QData)((IData)(
                                                                           (0x36U 
                                                                            == 
                                                                            (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                             >> 0x1aU)))) 
                                                           << 0x36U) 
                                                          | (((QData)((IData)(
                                                                              (0x35U 
                                                                               == 
                                                                               (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                              << 0x35U) 
                                                             | (((QData)((IData)(
                                                                                (0x34U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                 << 0x34U) 
                                                                | (((QData)((IData)(
                                                                                (0x33U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                    << 0x33U) 
                                                                   | (((QData)((IData)(
                                                                                (0x32U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                       << 0x32U) 
                                                                      | (((QData)((IData)(
                                                                                (0x31U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                          << 0x31U) 
                                                                         | (((QData)((IData)(
                                                                                (0x30U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                             << 0x30U) 
                                                                            | (((QData)((IData)(
                                                                                (0x2fU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2fU) 
                                                                               | (((QData)((IData)(
                                                                                (0x2eU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2dU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2cU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2bU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2aU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (0x29U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (0x28U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (0x27U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (0x26U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (0x25U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (0x24U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (0x23U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (0x22U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (0x21U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (0x20U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((0x1fU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x1fU) 
                                                                                | (((0x1eU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x1eU) 
                                                                                | (((0x1dU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x1dU) 
                                                                                | (((0x1cU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x1cU) 
                                                                                | (((0x1bU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x1bU) 
                                                                                | (((0x1aU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x1aU) 
                                                                                | (((0x19U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x19U) 
                                                                                | (((0x18U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x18U) 
                                                                                | (((0x17U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x17U) 
                                                                                | (((0x16U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x16U) 
                                                                                | (((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x15U) 
                                                                                | (((0x14U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x14U) 
                                                                                | (((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x13U) 
                                                                                | (((0x12U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x12U) 
                                                                                | (((0x11U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x11U) 
                                                                                | (((0x10U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0x10U) 
                                                                                | (((0xfU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0xfU) 
                                                                                | (((0xeU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rk_d = 
        (((0x1fU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                              >> 0xaU))) << 0x1fU) 
         | (((0x1eU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                 >> 0xaU))) << 0x1eU) 
            | (((0x1dU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                    >> 0xaU))) << 0x1dU) 
               | (((0x1cU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                       >> 0xaU))) << 0x1cU) 
                  | (((0x1bU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                          >> 0xaU))) 
                      << 0x1bU) | (((0x1aU == (0x1fU 
                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                  >> 0xaU))) 
                                    << 0x1aU) | (((0x19U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                       >> 0xaU))) 
                                                  << 0x19U) 
                                                 | (((0x18U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                          >> 0xaU))) 
                                                     << 0x18U) 
                                                    | (((0x17U 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                             >> 0xaU))) 
                                                        << 0x17U) 
                                                       | (((0x16U 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                >> 0xaU))) 
                                                           << 0x16U) 
                                                          | (((0x15U 
                                                               == 
                                                               (0x1fU 
                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                   >> 0xaU))) 
                                                              << 0x15U) 
                                                             | (((0x14U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                      >> 0xaU))) 
                                                                 << 0x14U) 
                                                                | (((0x13U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                         >> 0xaU))) 
                                                                    << 0x13U) 
                                                                   | (((0x12U 
                                                                        == 
                                                                        (0x1fU 
                                                                         & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                            >> 0xaU))) 
                                                                       << 0x12U) 
                                                                      | (((0x11U 
                                                                           == 
                                                                           (0x1fU 
                                                                            & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                               >> 0xaU))) 
                                                                          << 0x11U) 
                                                                         | (((0x10U 
                                                                              == 
                                                                              (0x1fU 
                                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                             << 0x10U) 
                                                                            | (((0xfU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 0xfU) 
                                                                               | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__op_25_22_d 
        = (((0xfU == (0xfU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                              >> 0x16U))) << 0xfU) 
           | (((0xeU == (0xfU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                 >> 0x16U))) << 0xeU) 
              | (((0xdU == (0xfU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                    >> 0x16U))) << 0xdU) 
                 | (((0xcU == (0xfU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                       >> 0x16U))) 
                     << 0xcU) | (((0xbU == (0xfU & 
                                            (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                             >> 0x16U))) 
                                  << 0xbU) | (((0xaU 
                                                == 
                                                (0xfU 
                                                 & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                    >> 0x16U))) 
                                               << 0xaU) 
                                              | (((9U 
                                                   == 
                                                   (0xfU 
                                                    & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                       >> 0x16U))) 
                                                  << 9U) 
                                                 | (((8U 
                                                      == 
                                                      (0xfU 
                                                       & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                          >> 0x16U))) 
                                                     << 8U) 
                                                    | (((7U 
                                                         == 
                                                         (0xfU 
                                                          & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                             >> 0x16U))) 
                                                        << 7U) 
                                                       | (((6U 
                                                            == 
                                                            (0xfU 
                                                             & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                >> 0x16U))) 
                                                           << 6U) 
                                                          | (((5U 
                                                               == 
                                                               (0xfU 
                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                   >> 0x16U))) 
                                                              << 5U) 
                                                             | (((4U 
                                                                  == 
                                                                  (0xfU 
                                                                   & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                      >> 0x16U))) 
                                                                 << 4U) 
                                                                | (((3U 
                                                                     == 
                                                                     (0xfU 
                                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                         >> 0x16U))) 
                                                                    << 3U) 
                                                                   | (((2U 
                                                                        == 
                                                                        (0xfU 
                                                                         & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                            >> 0x16U))) 
                                                                       << 2U) 
                                                                      | (((1U 
                                                                           == 
                                                                           (0xfU 
                                                                            & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                               >> 0x16U))) 
                                                                          << 1U) 
                                                                         | (0U 
                                                                            == 
                                                                            (0xfU 
                                                                             & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x16U))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__op_19_15_d 
        = (((0x1fU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                >> 0xfU))) << 0x1fU) 
           | (((0x1eU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                   >> 0xfU))) << 0x1eU) 
              | (((0x1dU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                      >> 0xfU))) << 0x1dU) 
                 | (((0x1cU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                         >> 0xfU))) 
                     << 0x1cU) | (((0x1bU == (0x1fU 
                                              & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                 >> 0xfU))) 
                                   << 0x1bU) | (((0x1aU 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                      >> 0xfU))) 
                                                 << 0x1aU) 
                                                | (((0x19U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                         >> 0xfU))) 
                                                    << 0x19U) 
                                                   | (((0x18U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                            >> 0xfU))) 
                                                       << 0x18U) 
                                                      | (((0x17U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                               >> 0xfU))) 
                                                          << 0x17U) 
                                                         | (((0x16U 
                                                              == 
                                                              (0x1fU 
                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                  >> 0xfU))) 
                                                             << 0x16U) 
                                                            | (((0x15U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                     >> 0xfU))) 
                                                                << 0x15U) 
                                                               | (((0x14U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                        >> 0xfU))) 
                                                                   << 0x14U) 
                                                                  | (((0x13U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                           >> 0xfU))) 
                                                                      << 0x13U) 
                                                                     | (((0x12U 
                                                                          == 
                                                                          (0x1fU 
                                                                           & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                              >> 0xfU))) 
                                                                         << 0x12U) 
                                                                        | (((0x11U 
                                                                             == 
                                                                             (0x1fU 
                                                                              & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                            << 0x11U) 
                                                                           | (((0x10U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                               << 0x10U) 
                                                                              | (((0xfU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 0xfU) 
                                                                                | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xfU))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_d = 
        (((0x1fU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                              >> 5U))) << 0x1fU) | 
         (((0x1eU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                               >> 5U))) << 0x1eU) | 
          (((0x1dU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                >> 5U))) << 0x1dU) 
           | (((0x1cU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                   >> 5U))) << 0x1cU) 
              | (((0x1bU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                      >> 5U))) << 0x1bU) 
                 | (((0x1aU == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                         >> 5U))) << 0x1aU) 
                    | (((0x19U == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                            >> 5U))) 
                        << 0x19U) | (((0x18U == (0x1fU 
                                                 & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                    >> 5U))) 
                                      << 0x18U) | (
                                                   ((0x17U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                         >> 5U))) 
                                                    << 0x17U) 
                                                   | (((0x16U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                            >> 5U))) 
                                                       << 0x16U) 
                                                      | (((0x15U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                               >> 5U))) 
                                                          << 0x15U) 
                                                         | (((0x14U 
                                                              == 
                                                              (0x1fU 
                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                  >> 5U))) 
                                                             << 0x14U) 
                                                            | (((0x13U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                     >> 5U))) 
                                                                << 0x13U) 
                                                               | (((0x12U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                        >> 5U))) 
                                                                   << 0x12U) 
                                                                  | (((0x11U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                           >> 5U))) 
                                                                      << 0x11U) 
                                                                     | (((0x10U 
                                                                          == 
                                                                          (0x1fU 
                                                                           & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                              >> 5U))) 
                                                                         << 0x10U) 
                                                                        | (((0xfU 
                                                                             == 
                                                                             (0x1fU 
                                                                              & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                            << 0xfU) 
                                                                           | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                               << 0xeU) 
                                                                              | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 5U))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rd_d = 
        (((0x1fU == (0x1fU & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
          << 0x1fU) | (((0x1eU == (0x1fU & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                        << 0x1eU) | (((0x1dU == (0x1fU 
                                                 & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                      << 0x1dU) | (
                                                   ((0x1cU 
                                                     == 
                                                     (0x1fU 
                                                      & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                    << 0x1cU) 
                                                   | (((0x1bU 
                                                        == 
                                                        (0x1fU 
                                                         & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                       << 0x1bU) 
                                                      | (((0x1aU 
                                                           == 
                                                           (0x1fU 
                                                            & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                          << 0x1aU) 
                                                         | (((0x19U 
                                                              == 
                                                              (0x1fU 
                                                               & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                             << 0x19U) 
                                                            | (((0x18U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                << 0x18U) 
                                                               | (((0x17U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                   << 0x17U) 
                                                                  | (((0x16U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                      << 0x16U) 
                                                                     | (((0x15U 
                                                                          == 
                                                                          (0x1fU 
                                                                           & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                         << 0x15U) 
                                                                        | (((0x14U 
                                                                             == 
                                                                             (0x1fU 
                                                                              & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                            << 0x14U) 
                                                                           | (((0x13U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                               << 0x13U) 
                                                                              | (((0x12U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0x12U) 
                                                                                | (((0x11U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0x11U) 
                                                                                | (((0x10U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0x10U) 
                                                                                | (((0xfU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0xfU) 
                                                                                | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__src2_is_4 
        = ((0x13U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                      >> 0x1aU)) | (0x15U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                              >> 0x1aU)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi 
        = (IData)((0x18000000U == (0xfe000000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1c4a3e54__0 
        = ((0x15U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                      >> 0x1aU)) | (0x14U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                              >> 0x1aU)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w 
        = (IData)((0x14000000U == (0xfe000000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i 
        = (IData)((0x1c000000U == (0xfe000000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    cpu__DOT__id_stage__DOT____VdfgTmp_ha340f1e6__0 
        = (IData)((0x38700000U == (0xfff00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0 
        = (IData)((0U == (0x3ffU & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w 
        = (IData)((0x28800000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu 
        = (IData)((0x2a400000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu 
        = (IData)((0x2a000000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori 
        = (IData)((0x3c00000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori 
        = (IData)((0x3800000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi 
        = (IData)((0x3400000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui 
        = (IData)((0x2400000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti 
        = (IData)((0x2000000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w 
        = (IData)((0x2800000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld 
        = (IData)((0x2ac00000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h 
        = (IData)((0x28400000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b 
        = (IData)((0x28000000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_cacop 
        = (IData)((0x6000000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    cpu__DOT__id_stage__DOT____VdfgTmp_h811e5890__0 
        = ((0x19U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                      >> 0x1aU)) | ((0x1aU == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                               >> 0x1aU)) 
                                    | (0x1bU == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                 >> 0x1aU))));
    cpu__DOT__id_stage__DOT____VdfgTmp_h64c8ed36__0 
        = (IData)((0x6400000U == (0xfff00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    cpu__DOT__id_stage__DOT____VdfgTmp_h7517b185__0 
        = (IData)((0x400000U == (0xfff00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w 
        = (IData)((0x29800000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h 
        = (IData)((0x29400000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b 
        = (IData)((0x29000000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h19962199__0 
        = ((0x16U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                      >> 0x1aU)) | (0x17U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                              >> 0x1aU)));
    cpu__DOT__id_stage__DOT____VdfgTmp_hc70d6735__0 
        = (IData)((0x20000000U == (0xfe000000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    cpu__DOT__id_stage__DOT____VdfgTmp_h8157b4ad__0 
        = (IData)((0x4000000U == (0xff000000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    cpu__DOT__id_stage__DOT____VdfgTmp_ha4228d15__0 
        = (IData)((0U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->csr_asid_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid;
    vlSelf->__VdfgTmp_ha0f10682__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xfU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xfU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xfU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xfU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xfU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xfU])));
    vlSelf->__VdfgTmp_h3a96ee69__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xeU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xeU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xeU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xeU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xeU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xeU])));
    vlSelf->__VdfgTmp_h4dc072c1__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xdU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xdU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xdU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xdU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xdU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xdU])));
    vlSelf->__VdfgTmp_h2824a371__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xcU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xcU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xcU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xcU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xcU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xcU])));
    vlSelf->__VdfgTmp_h386fae7d__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xbU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xbU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xbU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xbU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xbU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xbU])));
    vlSelf->__VdfgTmp_hce0c4684__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xaU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xaU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xaU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xaU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xaU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xaU])));
    vlSelf->__VdfgTmp_ha7233986__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [9U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [9U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [9U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [9U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [9U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [9U])));
    vlSelf->__VdfgTmp_h2b5e8621__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [8U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [8U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [8U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [8U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [8U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [8U])));
    vlSelf->__VdfgTmp_h81e7e4c9__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [7U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [7U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [7U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [7U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [7U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [7U])));
    vlSelf->__VdfgTmp_hb231f61d__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [6U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [6U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [6U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [6U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [6U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [6U])));
    vlSelf->__VdfgTmp_hf2d875ee__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [5U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [5U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [5U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [5U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [5U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [5U])));
    vlSelf->__VdfgTmp_hf2232012__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [4U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [4U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [4U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [4U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [4U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [4U])));
    vlSelf->__VdfgTmp_h65b1658b__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [3U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [3U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [3U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [3U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [3U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [3U])));
    vlSelf->__VdfgTmp_hbbbab294__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [2U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [2U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [2U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [2U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [2U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [2U])));
    vlSelf->__VdfgTmp_hc8484373__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [1U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [1U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [1U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [1U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [1U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [1U])));
    vlSelf->__VdfgTmp_he2772e6a__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xfU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xfU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xfU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xfU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xfU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xfU])));
    vlSelf->__VdfgTmp_h88048788__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xeU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xeU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xeU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xeU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xeU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xeU])));
    vlSelf->__VdfgTmp_h3f7dfeb7__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xdU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xdU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xdU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xdU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xdU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xdU])));
    vlSelf->__VdfgTmp_ha011a01e__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xcU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xcU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xcU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xcU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xcU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xcU])));
    vlSelf->__VdfgTmp_h6525c922__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xbU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xbU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xbU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xbU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xbU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xbU])));
    vlSelf->__VdfgTmp_h75708bee__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [0xaU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                  [0xaU])
                                                  ? 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0xaU])
                                                  : 
                                                 ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0xaU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                    [0xaU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                   [0xaU])));
    vlSelf->__VdfgTmp_he92a5bc9__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [9U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [9U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [9U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [9U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [9U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [9U])));
    vlSelf->__VdfgTmp_h1e27bdaa__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [8U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [8U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [8U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [8U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [8U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [8U])));
    vlSelf->__VdfgTmp_hd67f03ee__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [7U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [7U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [7U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [7U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [7U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [7U])));
    vlSelf->__VdfgTmp_ha83e7e37__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [6U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [6U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [6U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [6U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [6U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [6U])));
    vlSelf->__VdfgTmp_h4b4d1d0f__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [5U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [5U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [5U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [5U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [5U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [5U])));
    vlSelf->__VdfgTmp_h08d4b213__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [4U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [4U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [4U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [4U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [4U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [4U])));
    vlSelf->__VdfgTmp_h9f9dcade__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [3U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [3U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [3U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [3U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [3U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [3U])));
    vlSelf->__VdfgTmp_hac1c8e5b__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [2U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [2U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [2U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [2U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [2U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [2U])));
    vlSelf->__VdfgTmp_hb3c45e3f__0 = (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                      [1U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                [1U])
                                                ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                   [1U])
                                                : (
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                       >> 9U)) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                       [1U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                  [1U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                 [1U])));
    vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h145a0ce5__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h14462e1a__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h1485ccbd__0) 
                                  << 1U) | (1U & ((~ (IData)(
                                                             (0U 
                                                              != 
                                                              (0xffffU 
                                                               & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)))) 
                                                  & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t 
                                                     >> 0x10U))))));
    vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h145f01b1__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h145b0fca__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h88130675__0) 
                                  << 1U) | (1U & vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t))));
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_index 
        = (((- (IData)((0U != (IData)(vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT____Vcellinp__one__in)))) 
            & ((3U & ((- (IData)((0U != (IData)(vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__one__DOT____Vcellinp__one__in)))) 
                      & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h2916341e__0)))) 
                         | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h29829d30__0)))) 
                            | (- (IData)((IData)(vlSelf->__VdfgTmp_h2865ac30__0))))))) 
               | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h28a85f11__0) 
                               | ((IData)(vlSelf->__VdfgTmp_h28689c53__0) 
                                  | ((IData)(vlSelf->__VdfgTmp_h2678667e__0) 
                                     | (IData)(vlSelf->__VdfgTmp_h263ed55f__0)))))) 
                   & (4U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h2678667e__0)))) 
                                  | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h28689c53__0)))) 
                                     | (- (IData)((IData)(vlSelf->__VdfgTmp_h28a85f11__0)))))))) 
                  | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h29f565de__0) 
                                  | ((IData)(vlSelf->__VdfgTmp_h29ed2521__0) 
                                     | ((IData)(vlSelf->__VdfgTmp_h284c4815__0) 
                                        | (IData)(vlSelf->__VdfgTmp_h2b42431a__0)))))) 
                      & (8U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h284c4815__0)))) 
                                     | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h29ed2521__0)))) 
                                        | (- (IData)((IData)(vlSelf->__VdfgTmp_h29f565de__0)))))))) 
                     | ((- (IData)(((IData)(vlSelf->__VdfgTmp_h2991042b__0) 
                                    | ((IData)(vlSelf->__VdfgTmp_h28667139__0) 
                                       | ((IData)(vlSelf->__VdfgTmp_h29e8ee51__0) 
                                          | (IData)(vlSelf->__VdfgTmp_h29c04841__0)))))) 
                        & (0xcU | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h29e8ee51__0)))) 
                                         | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h28667139__0)))) 
                                            | (- (IData)((IData)(vlSelf->__VdfgTmp_h2991042b__0)))))))))))) 
           | ((- (IData)(((IData)(vlSelf->__VdfgTmp_h28de6bba__0) 
                          | ((IData)(vlSelf->__VdfgTmp_h281e3aa3__0) 
                             | ((IData)(vlSelf->__VdfgTmp_h287d9e6a__0) 
                                | ((IData)(vlSelf->__VdfgTmp_h29902bb6__0) 
                                   | ((IData)(vlSelf->__VdfgTmp_h282df2b4__0) 
                                      | ((IData)(vlSelf->__VdfgTmp_h28447f91__0) 
                                         | ((IData)(vlSelf->__VdfgTmp_h2f17bd15__0) 
                                            | ((IData)(vlSelf->__VdfgTmp_h2b34b778__0) 
                                               | ((IData)(vlSelf->__VdfgTmp_h2846d38b__0) 
                                                  | ((IData)(vlSelf->__VdfgTmp_h283518d9__0) 
                                                     | ((IData)(vlSelf->__VdfgTmp_h28d0af6a__0) 
                                                        | ((IData)(vlSelf->__VdfgTmp_h28d16f34__0) 
                                                           | (0U 
                                                              != (IData)(vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__two__DOT____Vcellinp__one__in)))))))))))))))) 
              & (0x10U | ((3U & ((- (IData)((0U != (IData)(vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__two__DOT____Vcellinp__one__in)))) 
                                 & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h2961036f__0)))) 
                                    | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h28b1ebfc__0)))) 
                                       | (- (IData)((IData)(vlSelf->__VdfgTmp_h28b5f3c3__0))))))) 
                          | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h2846d38b__0) 
                                          | ((IData)(vlSelf->__VdfgTmp_h283518d9__0) 
                                             | ((IData)(vlSelf->__VdfgTmp_h28d0af6a__0) 
                                                | (IData)(vlSelf->__VdfgTmp_h28d16f34__0)))))) 
                              & (4U | (3U & ((1U & 
                                              (- (IData)((IData)(vlSelf->__VdfgTmp_h28d0af6a__0)))) 
                                             | ((2U 
                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_h283518d9__0)))) 
                                                | (- (IData)((IData)(vlSelf->__VdfgTmp_h2846d38b__0)))))))) 
                             | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h282df2b4__0) 
                                             | ((IData)(vlSelf->__VdfgTmp_h28447f91__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_h2f17bd15__0) 
                                                   | (IData)(vlSelf->__VdfgTmp_h2b34b778__0)))))) 
                                 & (8U | (3U & ((1U 
                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_h2f17bd15__0)))) 
                                                | ((2U 
                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_h28447f91__0)))) 
                                                   | (- (IData)((IData)(vlSelf->__VdfgTmp_h282df2b4__0)))))))) 
                                | ((- (IData)(((IData)(vlSelf->__VdfgTmp_h28de6bba__0) 
                                               | ((IData)(vlSelf->__VdfgTmp_h281e3aa3__0) 
                                                  | ((IData)(vlSelf->__VdfgTmp_h287d9e6a__0) 
                                                     | (IData)(vlSelf->__VdfgTmp_h29902bb6__0)))))) 
                                   & (0xcU | (3U & 
                                              ((1U 
                                                & (- (IData)((IData)(vlSelf->__VdfgTmp_h287d9e6a__0)))) 
                                               | ((2U 
                                                   & (- (IData)((IData)(vlSelf->__VdfgTmp_h281e3aa3__0)))) 
                                                  | (- (IData)((IData)(vlSelf->__VdfgTmp_h28de6bba__0))))))))))))));
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_rd 
        = (((IData)(vlSelf->__VdfgTmp_h28de6bba__0) 
            << 0x1fU) | (((IData)(vlSelf->__VdfgTmp_h281e3aa3__0) 
                          << 0x1eU) | (((IData)(vlSelf->__VdfgTmp_h287d9e6a__0) 
                                        << 0x1dU) | 
                                       (((IData)(vlSelf->__VdfgTmp_h29902bb6__0) 
                                         << 0x1cU) 
                                        | (((IData)(vlSelf->__VdfgTmp_h282df2b4__0) 
                                            << 0x1bU) 
                                           | (((IData)(vlSelf->__VdfgTmp_h28447f91__0) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->__VdfgTmp_h2f17bd15__0) 
                                                  << 0x19U) 
                                                 | (((IData)(vlSelf->__VdfgTmp_h2b34b778__0) 
                                                     << 0x18U) 
                                                    | (((IData)(vlSelf->__VdfgTmp_h2846d38b__0) 
                                                        << 0x17U) 
                                                       | (((IData)(vlSelf->__VdfgTmp_h283518d9__0) 
                                                           << 0x16U) 
                                                          | (((IData)(vlSelf->__VdfgTmp_h28d0af6a__0) 
                                                              << 0x15U) 
                                                             | (((IData)(vlSelf->__VdfgTmp_h28d16f34__0) 
                                                                 << 0x14U) 
                                                                | (((IData)(vlSelf->__VdfgTmp_h28b5f3c3__0) 
                                                                    << 0x13U) 
                                                                   | (((IData)(vlSelf->__VdfgTmp_h28b1ebfc__0) 
                                                                       << 0x12U) 
                                                                      | (((IData)(vlSelf->__VdfgTmp_h2961036f__0) 
                                                                          << 0x11U) 
                                                                         | (((IData)(__VdfgTmp_h26881c5e__0) 
                                                                             << 0x10U) 
                                                                            | (IData)(vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT____Vcellinp__one__in)))))))))))))))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_ha340f1e6__0) 
           & (0x28000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_dbar 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_ha340f1e6__0) 
           & (0x20000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__mem_sign_exted 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h38353e9a__0 
        = ((0x18U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                      >> 0x1aU)) | (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h811e5890__0));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_idle 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h64c8ed36__0) 
           & (0x88000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h64c8ed36__0) 
           & (0x80000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h64c8ed36__0) 
           & (0x98000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srai_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h7517b185__0) 
           & (0x88000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srli_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h7517b185__0) 
           & (0x48000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slli_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h7517b185__0) 
           & (0x8000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hbc7c3b7a__0 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h19962199__0) 
           | (0x18U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                        >> 0x1aU)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w 
        = ((~ (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
               >> 0x18U)) & (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hc70d6735__0));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hc70d6735__0) 
           & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
              >> 0x18U));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrrd 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h8157b4ad__0) 
           & (0U == (0x3e0U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrwr 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h8157b4ad__0) 
           & (0x20U == (0x3e0U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask 
        = ((~ ((0U == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                >> 5U))) | (1U == (0x1fU 
                                                   & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                      >> 5U))))) 
           & (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h8157b4ad__0));
    cpu__DOT__id_stage__DOT____VdfgTmp_h95da6b40__0 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_ha4228d15__0) 
           & (IData)((0U == (0x3f8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))));
    cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_ha4228d15__0) 
           & (0x200000U == (0x300000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_ha4228d15__0) 
           & (0x100000U == (0x300000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h65b1658b__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_hbbbab294__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_hc8484373__0) 
                                  << 1U) | (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                            [0U] & 
                                            (((0xcU 
                                               == vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                               [0U])
                                               ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0U])
                                               : ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0U] 
                                                      >> 9U)))) 
                                             & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r) 
                                                 == 
                                                 vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                 [0U]) 
                                                | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                [0U]))))));
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h9f9dcade__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_hac1c8e5b__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_hb3c45e3f__0) 
                                  << 1U) | (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
                                            [0U] & 
                                            (((0xcU 
                                               == vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                               [0U])
                                               ? (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                  [0U])
                                               : ((0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r 
                                                      >> 9U)) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn
                                                      [0U] 
                                                      >> 9U)))) 
                                             & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r) 
                                                 == 
                                                 vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid
                                                 [0U]) 
                                                | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
                                                [0U]))))));
    vlSelf->csr_tcfg_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tcfg;
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_add_entry_index 
        = (0x1fU & ((0xffffffffU == vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid)
                     ? ((0U != vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t)
                         ? (((- (IData)(((IData)(vlSelf->__VdfgTmp_h14afccdb__0) 
                                         | ((IData)(vlSelf->__VdfgTmp_h1468056a__0) 
                                            | ((IData)(vlSelf->__VdfgTmp_h14940457__0) 
                                               | ((IData)(vlSelf->__VdfgTmp_h1490813d__0) 
                                                  | ((IData)(vlSelf->__VdfgTmp_h147e8bf1__0) 
                                                     | ((IData)(vlSelf->__VdfgTmp_h147a4322__0) 
                                                        | ((IData)(vlSelf->__VdfgTmp_h1427ccc7__0) 
                                                           | ((IData)(vlSelf->__VdfgTmp_h14219459__0) 
                                                              | ((IData)(vlSelf->__VdfgTmp_h144d61b4__0) 
                                                                 | ((IData)(vlSelf->__VdfgTmp_h14924f66__0) 
                                                                    | ((IData)(vlSelf->__VdfgTmp_h149ff3f7__0) 
                                                                       | ((IData)(vlSelf->__VdfgTmp_h149b35b7__0) 
                                                                          | (0U 
                                                                             != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in)))))))))))))))) 
                             & ((3U & ((- (IData)((0U 
                                                   != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in)))) 
                                       & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h88130675__0)))) 
                                          | ((2U & 
                                              (- (IData)((IData)(vlSelf->__VdfgTmp_h145b0fca__0)))) 
                                             | (- (IData)((IData)(vlSelf->__VdfgTmp_h145f01b1__0))))))) 
                                | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h144d61b4__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_h14924f66__0) 
                                                   | ((IData)(vlSelf->__VdfgTmp_h149ff3f7__0) 
                                                      | (IData)(vlSelf->__VdfgTmp_h149b35b7__0)))))) 
                                    & (4U | (3U & (
                                                   (1U 
                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_h149ff3f7__0)))) 
                                                   | ((2U 
                                                       & (- (IData)((IData)(vlSelf->__VdfgTmp_h14924f66__0)))) 
                                                      | (- (IData)((IData)(vlSelf->__VdfgTmp_h144d61b4__0)))))))) 
                                   | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h147e8bf1__0) 
                                                   | ((IData)(vlSelf->__VdfgTmp_h147a4322__0) 
                                                      | ((IData)(vlSelf->__VdfgTmp_h1427ccc7__0) 
                                                         | (IData)(vlSelf->__VdfgTmp_h14219459__0)))))) 
                                       & (8U | (3U 
                                                & ((1U 
                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_h1427ccc7__0)))) 
                                                   | ((2U 
                                                       & (- (IData)((IData)(vlSelf->__VdfgTmp_h147a4322__0)))) 
                                                      | (- (IData)((IData)(vlSelf->__VdfgTmp_h147e8bf1__0)))))))) 
                                      | ((- (IData)(
                                                    ((IData)(vlSelf->__VdfgTmp_h14afccdb__0) 
                                                     | ((IData)(vlSelf->__VdfgTmp_h1468056a__0) 
                                                        | ((IData)(vlSelf->__VdfgTmp_h14940457__0) 
                                                           | (IData)(vlSelf->__VdfgTmp_h1490813d__0)))))) 
                                         & (0xcU | 
                                            (3U & (
                                                   (1U 
                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_h14940457__0)))) 
                                                   | ((2U 
                                                       & (- (IData)((IData)(vlSelf->__VdfgTmp_h1468056a__0)))) 
                                                      | (- (IData)((IData)(vlSelf->__VdfgTmp_h14afccdb__0)))))))))))) 
                            | ((- (IData)(((IData)(vlSelf->__VdfgTmp_h144a4430__0) 
                                           | ((IData)(vlSelf->__VdfgTmp_h1470b1c1__0) 
                                              | ((IData)(vlSelf->__VdfgTmp_h14758488__0) 
                                                 | ((IData)(vlSelf->__VdfgTmp_h1449ec64__0) 
                                                    | ((IData)(vlSelf->__VdfgTmp_h147b4aa2__0) 
                                                       | ((IData)(vlSelf->__VdfgTmp_h295efed9__0) 
                                                          | ((IData)(vlSelf->__VdfgTmp_h1492eda8__0) 
                                                             | ((IData)(vlSelf->__VdfgTmp_h1478ca08__0) 
                                                                | ((IData)(vlSelf->__VdfgTmp_h147c90ec__0) 
                                                                   | ((IData)(vlSelf->__VdfgTmp_h14673d06__0) 
                                                                      | ((IData)(vlSelf->__VdfgTmp_h1462d6b9__0) 
                                                                         | ((IData)(vlSelf->__VdfgTmp_h146f23bf__0) 
                                                                            | (0U 
                                                                               != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in)))))))))))))))) 
                               & (0x10U | ((3U & ((- (IData)(
                                                             (0U 
                                                              != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in)))) 
                                                  & ((1U 
                                                      & (- (IData)((IData)(vlSelf->__VdfgTmp_h1485ccbd__0)))) 
                                                     | ((2U 
                                                         & (- (IData)((IData)(vlSelf->__VdfgTmp_h14462e1a__0)))) 
                                                        | (- (IData)((IData)(vlSelf->__VdfgTmp_h145a0ce5__0))))))) 
                                           | (((- (IData)(
                                                          ((IData)(vlSelf->__VdfgTmp_h147c90ec__0) 
                                                           | ((IData)(vlSelf->__VdfgTmp_h14673d06__0) 
                                                              | ((IData)(vlSelf->__VdfgTmp_h1462d6b9__0) 
                                                                 | (IData)(vlSelf->__VdfgTmp_h146f23bf__0)))))) 
                                               & (4U 
                                                  | (3U 
                                                     & ((1U 
                                                         & (- (IData)((IData)(vlSelf->__VdfgTmp_h1462d6b9__0)))) 
                                                        | ((2U 
                                                            & (- (IData)((IData)(vlSelf->__VdfgTmp_h14673d06__0)))) 
                                                           | (- (IData)((IData)(vlSelf->__VdfgTmp_h147c90ec__0)))))))) 
                                              | (((- (IData)(
                                                             ((IData)(vlSelf->__VdfgTmp_h147b4aa2__0) 
                                                              | ((IData)(vlSelf->__VdfgTmp_h295efed9__0) 
                                                                 | ((IData)(vlSelf->__VdfgTmp_h1492eda8__0) 
                                                                    | (IData)(vlSelf->__VdfgTmp_h1478ca08__0)))))) 
                                                  & (8U 
                                                     | (3U 
                                                        & ((1U 
                                                            & (- (IData)((IData)(vlSelf->__VdfgTmp_h1492eda8__0)))) 
                                                           | ((2U 
                                                               & (- (IData)((IData)(vlSelf->__VdfgTmp_h295efed9__0)))) 
                                                              | (- (IData)((IData)(vlSelf->__VdfgTmp_h147b4aa2__0)))))))) 
                                                 | ((- (IData)(
                                                               ((IData)(vlSelf->__VdfgTmp_h144a4430__0) 
                                                                | ((IData)(vlSelf->__VdfgTmp_h1470b1c1__0) 
                                                                   | ((IData)(vlSelf->__VdfgTmp_h14758488__0) 
                                                                      | (IData)(vlSelf->__VdfgTmp_h1449ec64__0)))))) 
                                                    & (0xcU 
                                                       | (3U 
                                                          & ((1U 
                                                              & (- (IData)((IData)(vlSelf->__VdfgTmp_h14758488__0)))) 
                                                             | ((2U 
                                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_h1470b1c1__0)))) 
                                                                | (- (IData)((IData)(vlSelf->__VdfgTmp_h144a4430__0))))))))))))))
                         : (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__fcsr))
                     : (((- (IData)(((IData)(vlSelf->__VdfgTmp_h2b8ddfe0__0) 
                                     | ((IData)(vlSelf->__VdfgTmp_h286f7fb9__0) 
                                        | ((IData)(vlSelf->__VdfgTmp_h2bd4a660__0) 
                                           | ((IData)(vlSelf->__VdfgTmp_h2bd0af7c__0) 
                                              | ((IData)(vlSelf->__VdfgTmp_h2bd66e9a__0) 
                                                 | ((IData)(vlSelf->__VdfgTmp_h2bd25251__0) 
                                                    | ((IData)(vlSelf->__VdfgTmp_h2b9f70b0__0) 
                                                       | ((IData)(vlSelf->__VdfgTmp_h28475190__0) 
                                                          | ((IData)(vlSelf->__VdfgTmp_h28431d65__0) 
                                                             | ((IData)(vlSelf->__VdfgTmp_h28610961__0) 
                                                                | ((IData)(vlSelf->__VdfgTmp_h286d4908__0) 
                                                                   | ((IData)(vlSelf->__VdfgTmp_h2b8acf86__0) 
                                                                      | (0U 
                                                                         != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in)))))))))))))))) 
                         & ((3U & ((- (IData)((0U != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in)))) 
                                   & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h21b09c90__0)))) 
                                      | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h2b9112e1__0)))) 
                                         | (- (IData)((IData)(vlSelf->__VdfgTmp_h2b9506da__0))))))) 
                            | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h28431d65__0) 
                                            | ((IData)(vlSelf->__VdfgTmp_h28610961__0) 
                                               | ((IData)(vlSelf->__VdfgTmp_h286d4908__0) 
                                                  | (IData)(vlSelf->__VdfgTmp_h2b8acf86__0)))))) 
                                & (4U | (3U & ((1U 
                                                & (- (IData)((IData)(vlSelf->__VdfgTmp_h286d4908__0)))) 
                                               | ((2U 
                                                   & (- (IData)((IData)(vlSelf->__VdfgTmp_h28610961__0)))) 
                                                  | (- (IData)((IData)(vlSelf->__VdfgTmp_h28431d65__0)))))))) 
                               | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h2bd66e9a__0) 
                                               | ((IData)(vlSelf->__VdfgTmp_h2bd25251__0) 
                                                  | ((IData)(vlSelf->__VdfgTmp_h2b9f70b0__0) 
                                                     | (IData)(vlSelf->__VdfgTmp_h28475190__0)))))) 
                                   & (8U | (3U & ((1U 
                                                   & (- (IData)((IData)(vlSelf->__VdfgTmp_h2b9f70b0__0)))) 
                                                  | ((2U 
                                                      & (- (IData)((IData)(vlSelf->__VdfgTmp_h2bd25251__0)))) 
                                                     | (- (IData)((IData)(vlSelf->__VdfgTmp_h2bd66e9a__0)))))))) 
                                  | ((- (IData)(((IData)(vlSelf->__VdfgTmp_h2b8ddfe0__0) 
                                                 | ((IData)(vlSelf->__VdfgTmp_h286f7fb9__0) 
                                                    | ((IData)(vlSelf->__VdfgTmp_h2bd4a660__0) 
                                                       | (IData)(vlSelf->__VdfgTmp_h2bd0af7c__0)))))) 
                                     & (0xcU | (3U 
                                                & ((1U 
                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_h2bd4a660__0)))) 
                                                   | ((2U 
                                                       & (- (IData)((IData)(vlSelf->__VdfgTmp_h286f7fb9__0)))) 
                                                      | (- (IData)((IData)(vlSelf->__VdfgTmp_h2b8ddfe0__0)))))))))))) 
                        | ((- (IData)(((IData)(vlSelf->__VdfgTmp_h287669a1__0) 
                                       | ((IData)(vlSelf->__VdfgTmp_h284b4e24__0) 
                                          | ((IData)(vlSelf->__VdfgTmp_h2b2d3ac1__0) 
                                             | ((IData)(vlSelf->__VdfgTmp_h2b22ba23__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_h2b26b937__0) 
                                                   | ((IData)(vlSelf->__VdfgTmp_h2b39d584__0) 
                                                      | ((IData)(vlSelf->__VdfgTmp_h2b9f81d9__0) 
                                                         | ((IData)(vlSelf->__VdfgTmp_h2b92025f__0) 
                                                            | ((IData)(vlSelf->__VdfgTmp_h2b9503ed__0) 
                                                               | ((IData)(vlSelf->__VdfgTmp_h2b227c39__0) 
                                                                  | ((IData)(vlSelf->__VdfgTmp_h2b2ff7d2__0) 
                                                                     | ((IData)(vlSelf->__VdfgTmp_h284bb0ae__0) 
                                                                        | (0U 
                                                                           != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in)))))))))))))))) 
                           & (0x10U | ((3U & ((- (IData)(
                                                         (0U 
                                                          != (IData)(vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in)))) 
                                              & ((1U 
                                                  & (- (IData)((IData)(vlSelf->__VdfgTmp_h2bbd3cde__0)))) 
                                                 | ((2U 
                                                     & (- (IData)((IData)(vlSelf->__VdfgTmp_h2872c95d__0)))) 
                                                    | (- (IData)((IData)(vlSelf->__VdfgTmp_h2870c5f6__0))))))) 
                                       | (((- (IData)(
                                                      ((IData)(vlSelf->__VdfgTmp_h2b9503ed__0) 
                                                       | ((IData)(vlSelf->__VdfgTmp_h2b227c39__0) 
                                                          | ((IData)(vlSelf->__VdfgTmp_h2b2ff7d2__0) 
                                                             | (IData)(vlSelf->__VdfgTmp_h284bb0ae__0)))))) 
                                           & (4U | 
                                              (3U & 
                                               ((1U 
                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_h2b2ff7d2__0)))) 
                                                | ((2U 
                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_h2b227c39__0)))) 
                                                   | (- (IData)((IData)(vlSelf->__VdfgTmp_h2b9503ed__0)))))))) 
                                          | (((- (IData)(
                                                         ((IData)(vlSelf->__VdfgTmp_h2b26b937__0) 
                                                          | ((IData)(vlSelf->__VdfgTmp_h2b39d584__0) 
                                                             | ((IData)(vlSelf->__VdfgTmp_h2b9f81d9__0) 
                                                                | (IData)(vlSelf->__VdfgTmp_h2b92025f__0)))))) 
                                              & (8U 
                                                 | (3U 
                                                    & ((1U 
                                                        & (- (IData)((IData)(vlSelf->__VdfgTmp_h2b9f81d9__0)))) 
                                                       | ((2U 
                                                           & (- (IData)((IData)(vlSelf->__VdfgTmp_h2b39d584__0)))) 
                                                          | (- (IData)((IData)(vlSelf->__VdfgTmp_h2b26b937__0)))))))) 
                                             | ((- (IData)(
                                                           ((IData)(vlSelf->__VdfgTmp_h287669a1__0) 
                                                            | ((IData)(vlSelf->__VdfgTmp_h284b4e24__0) 
                                                               | ((IData)(vlSelf->__VdfgTmp_h2b2d3ac1__0) 
                                                                  | (IData)(vlSelf->__VdfgTmp_h2b22ba23__0)))))) 
                                                & (0xcU 
                                                   | (3U 
                                                      & ((1U 
                                                          & (- (IData)((IData)(vlSelf->__VdfgTmp_h2b2d3ac1__0)))) 
                                                         | ((2U 
                                                             & (- (IData)((IData)(vlSelf->__VdfgTmp_h284b4e24__0)))) 
                                                            | (- (IData)((IData)(vlSelf->__VdfgTmp_h287669a1__0))))))))))))))));
    vlSelf->__PVT__cpu__DOT__btb_index = (((- (IData)(
                                                      (0U 
                                                       != vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_rd))) 
                                           & (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_index)) 
                                          | ((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_match))) 
                                             & ((3U 
                                                 & ((- (IData)(
                                                               (0U 
                                                                != (IData)(vlSelf->cpu__DOT__btb__DOT__encode_ras_match__DOT____Vcellinp__one__in)))) 
                                                    & ((1U 
                                                        & (- (IData)((IData)(vlSelf->__VdfgTmp_hd0d3d28e__0)))) 
                                                       | ((2U 
                                                           & (- (IData)((IData)(vlSelf->__VdfgTmp_h86e948c6__0)))) 
                                                          | (- (IData)((IData)(vlSelf->__VdfgTmp_h8651482e__0))))))) 
                                                | (((- (IData)(
                                                               ((IData)(vlSelf->__VdfgTmp_hef734879__0) 
                                                                | ((IData)(vlSelf->__VdfgTmp_hec9625f7__0) 
                                                                   | ((IData)(vlSelf->__VdfgTmp_hef1da2f3__0) 
                                                                      | (IData)(vlSelf->__VdfgTmp_h86498323__0)))))) 
                                                    & (4U 
                                                       | (3U 
                                                          & ((1U 
                                                              & (- (IData)((IData)(vlSelf->__VdfgTmp_hef1da2f3__0)))) 
                                                             | ((2U 
                                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_hec9625f7__0)))) 
                                                                | (- (IData)((IData)(vlSelf->__VdfgTmp_hef734879__0)))))))) 
                                                   | (((- (IData)(
                                                                  ((IData)(vlSelf->__VdfgTmp_hd0f3f017__0) 
                                                                   | ((IData)(vlSelf->__VdfgTmp_hea1021fd__0) 
                                                                      | ((IData)(vlSelf->__VdfgTmp_hea79f5b1__0) 
                                                                         | (IData)(vlSelf->__VdfgTmp_hef7d1ebb__0)))))) 
                                                       & (8U 
                                                          | (3U 
                                                             & ((1U 
                                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_hea79f5b1__0)))) 
                                                                | ((2U 
                                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_hea1021fd__0)))) 
                                                                   | (- (IData)((IData)(vlSelf->__VdfgTmp_hd0f3f017__0)))))))) 
                                                      | ((- (IData)(
                                                                    ((IData)(vlSelf->__VdfgTmp_hef3bf6e7__0) 
                                                                     | ((IData)(vlSelf->__VdfgTmp_hef3821b5__0) 
                                                                        | ((IData)(vlSelf->__VdfgTmp_hef7d2fec__0) 
                                                                           | (IData)(vlSelf->__VdfgTmp_hd0f0d5da__0)))))) 
                                                         & (0xcU 
                                                            | (3U 
                                                               & ((1U 
                                                                   & (- (IData)((IData)(vlSelf->__VdfgTmp_hef7d2fec__0)))) 
                                                                  | ((2U 
                                                                      & (- (IData)((IData)(vlSelf->__VdfgTmp_hef3821b5__0)))) 
                                                                     | (- (IData)((IData)(vlSelf->__VdfgTmp_hef3bf6e7__0)))))))))))));
    vlSelf->__PVT__cpu__DOT__btb_en = ((0U != vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_rd) 
                                       | (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_match));
    vlSelf->__PVT__cpu__DOT__btb_taken = (((0U != vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_rd) 
                                           & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter
                                              [vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_index] 
                                              >> 1U)) 
                                          | (IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_match));
    vlSelf->__PVT__cpu__DOT__btb_ret_pc = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_match))) 
                                            & (vlSelf->__PVT__cpu__DOT__btb__DOT__ras
                                               [(7U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__btb__DOT__ras_ptr) 
                                                    - (IData)(1U)))] 
                                               << 2U)) 
                                           | ((- (IData)(
                                                         (0U 
                                                          != vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_rd))) 
                                              & (vlSelf->__PVT__cpu__DOT__btb__DOT__btb_target
                                                 [vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_index] 
                                                 << 2U)));
    vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_ha3d303c7__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_en) 
           & (IData)((vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_buffer 
                      >> 0x25U)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x2c00U == (0x7c00U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                      & (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x3400U == (0x7c00U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                      & (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x3000U == (0x7c00U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                      & (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x2800U == (0x7c00U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                      & (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ertn 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x3800U == (0x7c00U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                      & (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__need_ui5 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slli_w) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srli_w) 
              | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srai_w)));
    cpu__DOT__id_stage__DOT____VdfgTmp_hda09fe26__0 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hbc7c3b7a__0) 
           | (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h811e5890__0));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_we 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrwr) 
           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h95da6b40__0) 
           & (IData)((0x6400U == (0x7fe0U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))));
    cpu__DOT__id_stage__DOT____VdfgTmp_ha7c13be7__0 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h95da6b40__0) 
           & (0x6000U == (0x7c00U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_break 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0) 
           & (0xa0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0) 
           & (0xb0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0) 
           & (0x8000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_wu 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0) 
           & (0x18000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0) 
           & (0U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_wu 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hb594121e__0) 
           & (0x10000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0xc8000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_wu 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0xd0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0xc0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sra_w 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x80000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srl_w 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x78000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sll_w 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x70000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xor 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x58000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_or 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x50000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nor 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x40000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_and 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x48000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltu 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x28000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slt 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x20000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sub_w 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0x10000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_add_w 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
           & (0U == (0xf8000U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match0 
        = (((IData)(vlSelf->__VdfgTmp_ha0f10682__0) 
            << 0xfU) | (((IData)(vlSelf->__VdfgTmp_h3a96ee69__0) 
                         << 0xeU) | (((IData)(vlSelf->__VdfgTmp_h4dc072c1__0) 
                                      << 0xdU) | (((IData)(vlSelf->__VdfgTmp_h2824a371__0) 
                                                   << 0xcU) 
                                                  | (((IData)(vlSelf->__VdfgTmp_h386fae7d__0) 
                                                      << 0xbU) 
                                                     | (((IData)(vlSelf->__VdfgTmp_hce0c4684__0) 
                                                         << 0xaU) 
                                                        | (((IData)(vlSelf->__VdfgTmp_ha7233986__0) 
                                                            << 9U) 
                                                           | (((IData)(vlSelf->__VdfgTmp_h2b5e8621__0) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->__VdfgTmp_h81e7e4c9__0) 
                                                                  << 7U) 
                                                                 | (((IData)(vlSelf->__VdfgTmp_hb231f61d__0) 
                                                                     << 6U) 
                                                                    | (((IData)(vlSelf->__VdfgTmp_hf2d875ee__0) 
                                                                        << 5U) 
                                                                       | (((IData)(vlSelf->__VdfgTmp_hf2232012__0) 
                                                                           << 4U) 
                                                                          | (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in)))))))))))));
    vlSelf->csr_tlbidx_diff = vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx;
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__w_e = 
        (1U & ((~ (vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx 
                   >> 0x1fU)) | (0x3fU == (0x3fU & 
                                           (vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_estat 
                                            >> 0x10U)))));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_e = 
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e
        [(0xfU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)];
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_g = 
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g
        [(0xfU & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)];
    vlSelf->__PVT__cpu__DOT__rd_csr_data = (((- (IData)(
                                                        (0U 
                                                         == 
                                                         (0x3fffU 
                                                          & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                             >> 0xaU))))) 
                                             & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd) 
                                            | (((- (IData)(
                                                           (1U 
                                                            == 
                                                            (0x3fffU 
                                                             & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                >> 0xaU))))) 
                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_prmd) 
                                               | (((- (IData)(
                                                              (4U 
                                                               == 
                                                               (0x3fffU 
                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                   >> 0xaU))))) 
                                                   & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ectl) 
                                                  | (((- (IData)(
                                                                 (5U 
                                                                  == 
                                                                  (0x3fffU 
                                                                   & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                      >> 0xaU))))) 
                                                      & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_estat) 
                                                     | (((- (IData)(
                                                                    (6U 
                                                                     == 
                                                                     (0x3fffU 
                                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                         >> 0xaU))))) 
                                                         & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_era) 
                                                        | (((- (IData)(
                                                                       (7U 
                                                                        == 
                                                                        (0x3fffU 
                                                                         & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                            >> 0xaU))))) 
                                                            & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_badv) 
                                                           | (((- (IData)(
                                                                          (0xcU 
                                                                           == 
                                                                           (0x3fffU 
                                                                            & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                               >> 0xaU))))) 
                                                               & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_eentry) 
                                                              | (((- (IData)(
                                                                             (0x10U 
                                                                              == 
                                                                              (0x3fffU 
                                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                  & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx) 
                                                                 | (((- (IData)(
                                                                                (0x11U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                     & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbehi) 
                                                                    | (((- (IData)(
                                                                                (0x12U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                        & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo0) 
                                                                       | (((- (IData)(
                                                                                (0x13U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                           & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo1) 
                                                                          | (((- (IData)(
                                                                                (0x18U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                              & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid) 
                                                                             | (((- (IData)(
                                                                                (0x19U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdl) 
                                                                                | (((- (IData)(
                                                                                (0x1aU 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdh) 
                                                                                | (((- (IData)(
                                                                                (0x1bU 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & ((vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_badv 
                                                                                >> 0x1fU)
                                                                                 ? vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdh
                                                                                 : vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdl)) 
                                                                                | (((- (IData)(
                                                                                (0x20U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cpuid) 
                                                                                | (((- (IData)(
                                                                                (0x30U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save0) 
                                                                                | (((- (IData)(
                                                                                (0x31U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save1) 
                                                                                | (((- (IData)(
                                                                                (0x32U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save2) 
                                                                                | (((- (IData)(
                                                                                (0x33U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save3) 
                                                                                | (((- (IData)(
                                                                                (0x40U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid) 
                                                                                | (((- (IData)(
                                                                                (0x41U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tcfg) 
                                                                                | (((- (IData)(
                                                                                (0x43U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cntc) 
                                                                                | (((- (IData)(
                                                                                (0x44U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ticlr) 
                                                                                | (((- (IData)(
                                                                                (0x60U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->csr_llbctl_diff) 
                                                                                | (((- (IData)(
                                                                                (0x42U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tval) 
                                                                                | (((- (IData)(
                                                                                (0x88U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbrentry) 
                                                                                | (((- (IData)(
                                                                                (0x180U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw0) 
                                                                                | ((- (IData)(
                                                                                (0x181U 
                                                                                == 
                                                                                (0x3fffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0xaU))))) 
                                                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw1)))))))))))))))))))))))))))));
    if (vlSelf->__PVT__cpu__DOT__ms_to_ws_valid) {
        __Vtemp_h21808a7a__0[2U] = (((IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil)) 
                                               << 0x3fU) 
                                              | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis)) 
                                                  << 0x3eU) 
                                                 | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi)) 
                                                     << 0x3dU) 
                                                    | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr)) 
                                                           << 0x3bU) 
                                                          | (((QData)((IData)(
                                                                              (0x3ffU 
                                                                               & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                                                                                << 2U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U] 
                                                                                >> 0x1eU))))) 
                                                              << 0x30U) 
                                                             | (0xffffffffffffULL 
                                                                & (((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U])) 
                                                                    << 0x12U) 
                                                                   | ((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])) 
                                                                      >> 0xeU)))))))))) 
                                     << 7U) | (((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp) 
                                                << 6U) 
                                               | (0x3fU 
                                                  & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])));
        __Vtemp_h21808a7a__0[3U] = (((IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil)) 
                                               << 0x3fU) 
                                              | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis)) 
                                                  << 0x3eU) 
                                                 | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi)) 
                                                     << 0x3dU) 
                                                    | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr)) 
                                                           << 0x3bU) 
                                                          | (((QData)((IData)(
                                                                              (0x3ffU 
                                                                               & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                                                                                << 2U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U] 
                                                                                >> 0x1eU))))) 
                                                              << 0x30U) 
                                                             | (0xffffffffffffULL 
                                                                & (((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U])) 
                                                                    << 0x12U) 
                                                                   | ((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])) 
                                                                      >> 0xeU)))))))))) 
                                     >> 0x19U) | ((IData)(
                                                          ((((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil)) 
                                                             << 0x3fU) 
                                                            | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis)) 
                                                                << 0x3eU) 
                                                               | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi)) 
                                                                   << 0x3dU) 
                                                                  | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme)) 
                                                                      << 0x3cU) 
                                                                     | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr)) 
                                                                         << 0x3bU) 
                                                                        | (((QData)((IData)(
                                                                                (0x3ffU 
                                                                                & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                                                                                << 2U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U] 
                                                                                >> 0x1eU))))) 
                                                                            << 0x30U) 
                                                                           | (0xffffffffffffULL 
                                                                              & (((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U])) 
                                                                                << 0x12U) 
                                                                                | ((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])) 
                                                                                >> 0xeU))))))))) 
                                                           >> 0x20U)) 
                                                  << 7U));
        __Vtemp_h21808a7a__0[4U] = ((IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil)) 
                                               << 0x3fU) 
                                              | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis)) 
                                                  << 0x3eU) 
                                                 | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi)) 
                                                     << 0x3dU) 
                                                    | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr)) 
                                                           << 0x3bU) 
                                                          | (((QData)((IData)(
                                                                              (0x3ffU 
                                                                               & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                                                                                << 2U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U] 
                                                                                >> 0x1eU))))) 
                                                              << 0x30U) 
                                                             | (0xffffffffffffULL 
                                                                & (((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U])) 
                                                                    << 0x12U) 
                                                                   | ((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])) 
                                                                      >> 0xeU))))))))) 
                                             >> 0x20U)) 
                                    >> 0x19U);
        __Vtemp_h27197a69__0[6U] = ((0x1800000U & (
                                                   vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                   << 5U)) 
                                    | ((((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                         & ((~ ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_uncache_en) 
                                                | (IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h63343402__0))) 
                                            & (IData)(vlSelf->__PVT__cpu__DOT__data_ret_last))) 
                                        << 0x16U) | 
                                       (((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__access_mem) 
                                         << 0x15U) 
                                        | ((0x1c0000U 
                                            & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                               << 3U)) 
                                           | (((IData)(
                                                       (0x3ffffffffULL 
                                                        & (((QData)((IData)(
                                                                            vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U])) 
                                                            << 0x14U) 
                                                           | ((QData)((IData)(
                                                                              vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U])) 
                                                              >> 0xcU)))) 
                                               >> 0x10U) 
                                              | ((IData)(
                                                         ((0x3ffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U])) 
                                                               << 0x14U) 
                                                              | ((QData)((IData)(
                                                                                vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U])) 
                                                                 >> 0xcU))) 
                                                          >> 0x20U)) 
                                                 << 0x10U))))));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data)) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0U]))));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[1U] 
            = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data)) 
                         << 0x20U) | (QData)((IData)(
                                                     vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0U]))) 
                       >> 0x20U));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
            = __Vtemp_h21808a7a__0[2U];
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
            = __Vtemp_h21808a7a__0[3U];
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
            = ((0xfffffe00U & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                                << 0x12U) | (0x3fe00U 
                                             & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                >> 0xeU)))) 
               | ((0x180U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                             >> 1U)) | __Vtemp_h21808a7a__0[4U]));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
            = (((IData)((0x3ffffffffULL & (((QData)((IData)(
                                                            vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U])) 
                                            << 0x14U) 
                                           | ((QData)((IData)(
                                                              vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U])) 
                                              >> 0xcU)))) 
                << 0x10U) | ((0x7800U & ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out) 
                                         << 0xbU)) 
                             | (((IData)((0U != (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match1))) 
                                 << 0xaU) | ((0x200U 
                                              & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                                                 >> 2U)) 
                                             | (0x1ffU 
                                                & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                                                   >> 0xeU))))));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[6U] 
            = ((0xfc000000U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                               << 3U)) | ((0x2000000U 
                                           & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                              << 3U)) 
                                          | __Vtemp_h27197a69__0[6U]));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[7U] 
            = ((0xf8000000U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                               << 4U)) | (((IData)(vlSelf->__PVT__cpu__DOT__data_uncache_en) 
                                           << 0x1aU) 
                                          | (0x3ffffffU 
                                             & ((0x3ffffc0U 
                                                 & (vlSelf->__PVT__cpu__DOT__data_tag 
                                                    << 6U)) 
                                                | (0x3fU 
                                                   & ((0x3fffff8U 
                                                       & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                                                          << 3U)) 
                                                      | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                         >> 0x1dU)))))));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[8U] 
            = (((0x7fffff0U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[7U] 
                               << 4U)) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                                          >> 0x1cU)) 
               | (0xf8000000U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[7U] 
                                 << 4U)));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[9U] 
            = (((0x7fffff0U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[8U] 
                               << 4U)) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[7U] 
                                          >> 0x1cU)) 
               | (0xf8000000U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[8U] 
                                 << 4U)));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0xaU] 
            = (((0x7fffff0U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[9U] 
                               << 4U)) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[8U] 
                                          >> 0x1cU)) 
               | (0xf8000000U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[9U] 
                                 << 4U)));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0xbU] 
            = ((0xfffffff0U & ((vlSelf->__PVT__cpu__DOT__data_tag 
                                << 0x10U) | (((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_index) 
                                              << 8U) 
                                             | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_offset) 
                                                << 4U)))) 
               | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[9U] 
                  >> 0x1cU));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0xcU] 
            = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xaU] 
                << 4U) | (0xfU & ((0xfU & (vlSelf->__PVT__cpu__DOT__data_tag 
                                           >> 0x10U)) 
                                  | ((0xfU & ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_index) 
                                              >> 0x18U)) 
                                     | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_offset) 
                                        >> 0x1cU)))));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0xdU] 
            = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xaU] 
                >> 0x1cU) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xbU] 
                             << 4U));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0xeU] 
            = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xbU] 
                >> 0x1cU) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xcU] 
                             << 4U));
        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0xfU] 
            = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xcU] 
                >> 0x1cU) | (0x1ff0U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xdU] 
                                        << 4U)));
    }
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_ret_pc_t 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_en))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_buffer)) 
           | vlSelf->__PVT__cpu__DOT__btb_ret_pc);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_to_btb 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hda09fe26__0) 
           | ((0x15U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                         >> 0x1aU)) | ((0x14U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                  >> 0x1aU)) 
                                       | (0x13U == 
                                          (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                           >> 0x1aU)))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_need_reg_data 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_hda09fe26__0) 
           | (0x13U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                        >> 0x1aU)));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h6983a416__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrrd) 
           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_we));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_raddr2 
        = (0x1fU & (((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hbc7c3b7a__0) 
                     | ((0x1aU == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                   >> 0x1aU)) | ((0x19U 
                                                  == 
                                                  (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                   >> 0x1aU)) 
                                                 | ((0x1bU 
                                                     == 
                                                     (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                      >> 0x1aU)) 
                                                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_we)))))))))
                     ? vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]
                     : ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                         << 0x16U) | (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                      >> 0xaU))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_ha7c13be7__0) 
           & (IData)(((0U == (0x3e0U & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                      & (0U != (0x1fU & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj 
        = ((IData)(cpu__DOT__id_stage__DOT____VdfgTmp_ha7c13be7__0) 
           & (0U == (0x1fU & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_haf287d09__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_add_w) 
           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sub_w));
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out 
        = ((- (IData)((0U != (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match0)))) 
           & ((3U & ((- (IData)((0U != (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in)))) 
                     & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_hc8484373__0)))) 
                        | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_hbbbab294__0)))) 
                           | (- (IData)((IData)(vlSelf->__VdfgTmp_h65b1658b__0))))))) 
              | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h81e7e4c9__0) 
                              | ((IData)(vlSelf->__VdfgTmp_hb231f61d__0) 
                                 | ((IData)(vlSelf->__VdfgTmp_hf2d875ee__0) 
                                    | (IData)(vlSelf->__VdfgTmp_hf2232012__0)))))) 
                  & (4U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_hf2d875ee__0)))) 
                                 | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_hb231f61d__0)))) 
                                    | (- (IData)((IData)(vlSelf->__VdfgTmp_h81e7e4c9__0)))))))) 
                 | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h386fae7d__0) 
                                 | ((IData)(vlSelf->__VdfgTmp_hce0c4684__0) 
                                    | ((IData)(vlSelf->__VdfgTmp_ha7233986__0) 
                                       | (IData)(vlSelf->__VdfgTmp_h2b5e8621__0)))))) 
                     & (8U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_ha7233986__0)))) 
                                    | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_hce0c4684__0)))) 
                                       | (- (IData)((IData)(vlSelf->__VdfgTmp_h386fae7d__0)))))))) 
                    | ((- (IData)(((IData)(vlSelf->__VdfgTmp_ha0f10682__0) 
                                   | ((IData)(vlSelf->__VdfgTmp_h3a96ee69__0) 
                                      | ((IData)(vlSelf->__VdfgTmp_h4dc072c1__0) 
                                         | (IData)(vlSelf->__VdfgTmp_h2824a371__0)))))) 
                       & (0xcU | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h4dc072c1__0)))) 
                                        | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h3a96ee69__0)))) 
                                           | (- (IData)((IData)(vlSelf->__VdfgTmp_ha0f10682__0))))))))))));
    vlSelf->__PVT__cpu__DOT__tlbr_tlbidx = (((~ (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_e)) 
                                             << 0x1fU) 
                                            | (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                               [(0xfU 
                                                 & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                               << 0x18U));
    vlSelf->__PVT__cpu__DOT__tlbr_tlbelo0 = ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn0
                                              [(0xfU 
                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                              << 8U) 
                                             | (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_g) 
                                                 << 6U) 
                                                | ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat0
                                                    [
                                                    (0xfU 
                                                     & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                                    << 4U) 
                                                   | ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv0
                                                       [
                                                       (0xfU 
                                                        & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                                       << 2U) 
                                                      | ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_d0
                                                          [
                                                          (0xfU 
                                                           & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                                          << 1U) 
                                                         | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v0
                                                         [
                                                         (0xfU 
                                                          & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)])))));
    vlSelf->__PVT__cpu__DOT__tlbr_tlbelo1 = ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn1
                                              [(0xfU 
                                                & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                              << 8U) 
                                             | (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_g) 
                                                 << 6U) 
                                                | ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat1
                                                    [
                                                    (0xfU 
                                                     & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                                    << 4U) 
                                                   | ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv1
                                                       [
                                                       (0xfU 
                                                        & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                                       << 2U) 
                                                      | ((vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_d1
                                                          [
                                                          (0xfU 
                                                           & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)] 
                                                          << 1U) 
                                                         | vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v1
                                                         [
                                                         (0xfU 
                                                          & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)])))));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match1 
        = (((IData)(vlSelf->__VdfgTmp_he2772e6a__0) 
            << 0xfU) | (((IData)(vlSelf->__VdfgTmp_h88048788__0) 
                         << 0xeU) | (((IData)(vlSelf->__VdfgTmp_h3f7dfeb7__0) 
                                      << 0xdU) | (((IData)(vlSelf->__VdfgTmp_ha011a01e__0) 
                                                   << 0xcU) 
                                                  | (((IData)(vlSelf->__VdfgTmp_h6525c922__0) 
                                                      << 0xbU) 
                                                     | (((IData)(vlSelf->__VdfgTmp_h75708bee__0) 
                                                         << 0xaU) 
                                                        | (((IData)(vlSelf->__VdfgTmp_he92a5bc9__0) 
                                                            << 9U) 
                                                           | (((IData)(vlSelf->__VdfgTmp_h1e27bdaa__0) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->__VdfgTmp_hd67f03ee__0) 
                                                                  << 7U) 
                                                                 | (((IData)(vlSelf->__VdfgTmp_ha83e7e37__0) 
                                                                     << 6U) 
                                                                    | (((IData)(vlSelf->__VdfgTmp_h4b4d1d0f__0) 
                                                                        << 5U) 
                                                                       | (((IData)(vlSelf->__VdfgTmp_h08d4b213__0) 
                                                                           << 4U) 
                                                                          | (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in)))))))))))));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hfea85cf8__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_to_btb) 
           & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
              >> 6U));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h416d0694__0 
        = (0x1fU & ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj)
                     ? ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                         << 0x1bU) | (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                      >> 5U)) : vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hac115781__0 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_haf287d09__0) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slt) 
              | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltu)));
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h5fe09d4e__0 
        = (1U & ((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_odd_page_buffer) 
                 >> (0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_index 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                    >> 4U));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_offset 
        = (0xfU & vlSelf->__PVT__cpu__DOT__data_vaddr);
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out 
        = ((- (IData)((0U != (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match1)))) 
           & ((3U & ((- (IData)((0U != (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in)))) 
                     & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_hb3c45e3f__0)))) 
                        | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_hac1c8e5b__0)))) 
                           | (- (IData)((IData)(vlSelf->__VdfgTmp_h9f9dcade__0))))))) 
              | (((- (IData)(((IData)(vlSelf->__VdfgTmp_hd67f03ee__0) 
                              | ((IData)(vlSelf->__VdfgTmp_ha83e7e37__0) 
                                 | ((IData)(vlSelf->__VdfgTmp_h4b4d1d0f__0) 
                                    | (IData)(vlSelf->__VdfgTmp_h08d4b213__0)))))) 
                  & (4U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h4b4d1d0f__0)))) 
                                 | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_ha83e7e37__0)))) 
                                    | (- (IData)((IData)(vlSelf->__VdfgTmp_hd67f03ee__0)))))))) 
                 | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h6525c922__0) 
                                 | ((IData)(vlSelf->__VdfgTmp_h75708bee__0) 
                                    | ((IData)(vlSelf->__VdfgTmp_he92a5bc9__0) 
                                       | (IData)(vlSelf->__VdfgTmp_h1e27bdaa__0)))))) 
                     & (8U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_he92a5bc9__0)))) 
                                    | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h75708bee__0)))) 
                                       | (- (IData)((IData)(vlSelf->__VdfgTmp_h6525c922__0)))))))) 
                    | ((- (IData)(((IData)(vlSelf->__VdfgTmp_he2772e6a__0) 
                                   | ((IData)(vlSelf->__VdfgTmp_h88048788__0) 
                                      | ((IData)(vlSelf->__VdfgTmp_h3f7dfeb7__0) 
                                         | (IData)(vlSelf->__VdfgTmp_ha011a01e__0)))))) 
                       & (0xcU | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h3f7dfeb7__0)))) 
                                        | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h88048788__0)))) 
                                           | (- (IData)((IData)(vlSelf->__VdfgTmp_he2772e6a__0))))))))))));
    if (((IData)(vlSelf->__PVT__cpu__DOT__es_to_ms_valid) 
         & (IData)(vlSelf->__PVT__cpu__DOT__ms_allowin))) {
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[1U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[2U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[3U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[4U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[5U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[6U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[7U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[7U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[8U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[8U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[9U] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[9U];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xaU] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xaU];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xbU] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xbU];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xcU] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xcU];
        vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[0xdU] 
            = vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xdU];
    }
    vlSelf->debug_wb_pc = vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U];
    vlSelf->debug_wb_rf_wnum = (0x1fU & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U]);
    vlSelf->debug_wb_rf_wdata = vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[1U];
    vlSelf->debug_wb_inst = ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[8U] 
                              << 5U) | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[7U] 
                                        >> 0x1bU));
    vlSelf->__PVT__cpu__DOT__ws_llbit = (1U & ((~ (
                                                   vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[7U] 
                                                   >> 0x1aU)) 
                                               & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
                                                  >> 7U)));
    cpu__DOT__wb_stage__DOT____VdfgTmp_h05fe9576__0 
        = ((2U & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                  >> 0x12U)) | (1U & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                      >> 0x14U)));
    vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_h71ee0a69__0 
        = (IData)((0U != (0x180U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])));
    vlSelf->__PVT__cpu__DOT__excp_flush = ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                            >> 6U) 
                                           & (IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid));
    cpu__DOT__wb_stage__DOT____VdfgTmp_he899fe78__0 
        = (((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid) 
            << 0x13U) | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U] 
                         >> 0xdU));
    cpu__DOT__wb_stage__DOT____VdfgTmp_hea49ee00__0 
        = (((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid) 
            << 0x13U) | (0x7ffffU & ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                      << 0xaU) | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
                                                  >> 0x16U))));
    vlSelf->__PVT__cpu__DOT__commit_inst = ((~ (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                                >> 6U)) 
                                            & (IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid));
    if ((0x15U == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                   >> 0x1aU))) {
        cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0 = 1U;
        cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0 = 0U;
    } else {
        cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0 
            = (7U & (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h416d0694__0));
        cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0 
            = (3U & ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h416d0694__0) 
                     >> 3U));
    }
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rkd 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hac115781__0) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_and) 
              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_or) 
                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nor) 
                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xor) 
                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w) 
                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w) 
                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_wu) 
                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w) 
                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_wu) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_wu) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sll_w) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srl_w) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sra_w) 
                                                     | ((0x16U 
                                                         == 
                                                         (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                          >> 0x1aU)) 
                                                        | ((0x17U 
                                                            == 
                                                            (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                             >> 0x1aU)) 
                                                           | ((0x18U 
                                                               == 
                                                               (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                >> 0x1aU)) 
                                                              | ((0x1aU 
                                                                  == 
                                                                  (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                   >> 0x1aU)) 
                                                                 | ((0x19U 
                                                                     == 
                                                                     (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                      >> 0x1aU)) 
                                                                    | ((0x1bU 
                                                                        == 
                                                                        (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                         >> 0x1aU)) 
                                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrwr) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s0_ppn 
        = ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h5fe09d4e__0)
            ? vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn1
           [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]
            : vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn0
           [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]);
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h9c4ee013__0 
        = (1U & ((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_buffer) 
                 >> (0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))));
    cpu__DOT__wb_stage__DOT____VdfgTmp_hb64b5cce__0 
        = ((4U & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                  >> 0xfU)) | (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_h05fe9576__0));
    cpu__DOT__wb_stage__DOT____VdfgTmp_he2911870__0 
        = (((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
            << 0x3eU) | (((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U])) 
                          << 0x1eU) | (QData)((IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_he899fe78__0))));
    cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0 
        = (((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
            << 0x3eU) | (((QData)((IData)(((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                            << 0x17U) 
                                           | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
                                              >> 9U)))) 
                          << 0x1eU) | (QData)((IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_hea49ee00__0))));
    vlSelf->__PVT__cpu__DOT__invtlb_en = ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                           >> 0x14U) 
                                          & (IData)(vlSelf->__PVT__cpu__DOT__commit_inst));
    vlSelf->__PVT__cpu__DOT__tlbrd_en = (1U & (((IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_h05fe9576__0) 
                                                & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__commit_inst)))) 
                                               >> 1U));
    vlSelf->__PVT__cpu__DOT__idle_flush = ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[6U] 
                                            >> 0x19U) 
                                           & (IData)(vlSelf->__PVT__cpu__DOT__commit_inst));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_we = 
        ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
          >> 5U) & (IData)(vlSelf->__PVT__cpu__DOT__commit_inst));
    vlSelf->__PVT__cpu__DOT__ertn_flush = ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                            >> 7U) 
                                           & (IData)(vlSelf->__PVT__cpu__DOT__commit_inst));
    vlSelf->__PVT__cpu__DOT__csr_wr_en = ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                           >> 0x16U) 
                                          & (IData)(vlSelf->__PVT__cpu__DOT__commit_inst));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nop 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_cacop) 
           & (((0U != (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0)) 
               & (1U != (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0))) 
              | (3U == (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_cacop) 
           & (((0U == (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0)) 
               | (1U == (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0))) 
              & ((0U == (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0)) 
                 | ((1U == (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0)) 
                    | (2U == (IData)(cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0))))));
    if (vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h9c4ee013__0) {
        vlSelf->__PVT__cpu__DOT__data_tlb_plv = vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv1
            [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))];
        vlSelf->__PVT__cpu__DOT__data_tlb_v = vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v1
            [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))];
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s1_ppn 
            = vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn1
            [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))];
    } else {
        vlSelf->__PVT__cpu__DOT__data_tlb_plv = vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv0
            [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))];
        vlSelf->__PVT__cpu__DOT__data_tlb_v = vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v0
            [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))];
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s1_ppn 
            = vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn0
            [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))];
    }
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_enable 
        = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
            >> 5U) & ((0U != (0x1fU & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])) 
                      & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid)));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__access_mem 
        = (1U & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                  >> 0xaU) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                              >> 6U)));
    vlSelf->__PVT__cpu__DOT__cacop_op_mode_di = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                  >> 0x15U) 
                                                 & ((0U 
                                                     == 
                                                     (3U 
                                                      & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                                         >> 3U))) 
                                                    | (1U 
                                                       == 
                                                       (3U 
                                                        & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                                           >> 3U)))));
    vlSelf->__PVT__cpu__DOT__tlbfill_en = (1U & (((IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_hb64b5cce__0) 
                                                  & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__commit_inst)))) 
                                                 >> 2U));
    vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_h292b3a37__0 
        = ((8U & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                  >> 0xdU)) | (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_hb64b5cce__0));
    if ((4U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])) {
        __Vtemp_h9cf7bc36__0[0U] = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                                             << 0x3eU) 
                                            | (((QData)((IData)(
                                                                ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                                                  << 0x17U) 
                                                                 | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
                                                                    >> 9U)))) 
                                                << 0x1eU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid) 
                                                                   << 0x14U) 
                                                                  | cpu__DOT__wb_stage__DOT____VdfgTmp_hea49ee00__0))))));
        __Vtemp_h9cf7bc36__0[1U] = (0x80000000U | (IData)(
                                                          ((((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                                                             << 0x3eU) 
                                                            | (((QData)((IData)(
                                                                                ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                                                                << 0x17U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
                                                                                >> 9U)))) 
                                                                << 0x1eU) 
                                                               | (QData)((IData)(
                                                                                (((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid) 
                                                                                << 0x14U) 
                                                                                | cpu__DOT__wb_stage__DOT____VdfgTmp_hea49ee00__0))))) 
                                                           >> 0x20U)));
    } else if ((8U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])) {
        __Vtemp_h9cf7bc36__0[0U] = (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0);
        __Vtemp_h9cf7bc36__0[1U] = (IData)((cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0 
                                            >> 0x20U));
    } else if ((0x10U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])) {
        __Vtemp_h9cf7bc36__0[0U] = (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0);
        __Vtemp_h9cf7bc36__0[1U] = (0x80000000U | (IData)(
                                                          (cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0 
                                                           >> 0x20U)));
    } else if ((0x20U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])) {
        __Vtemp_h9cf7bc36__0[0U] = (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0);
        __Vtemp_h9cf7bc36__0[1U] = (IData)((cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0 
                                            >> 0x20U));
    } else if ((0x40U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])) {
        __Vtemp_h9cf7bc36__0[0U] = (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0);
        __Vtemp_h9cf7bc36__0[1U] = (0x80000000U | (IData)(
                                                          (cpu__DOT__wb_stage__DOT____VdfgTmp_h3c9f3d8b__0 
                                                           >> 0x20U)));
    } else {
        __Vtemp_h9cf7bc36__0[0U] = 0U;
        __Vtemp_h9cf7bc36__0[1U] = 0U;
    }
    __Vtemp_h498d23a3__0[2U] = ((0x8000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                 ? 3U : ((0x10000000U 
                                          & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                          ? 5U : ((0x20000000U 
                                                   & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                                   ? 6U
                                                   : 
                                                  ((0x40000000U 
                                                    & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                                    ? 6U
                                                    : 
                                                   ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                                     >> 0x1fU)
                                                     ? 7U
                                                     : 
                                                    ((1U 
                                                      & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])
                                                      ? 4U
                                                      : 
                                                     ((4U 
                                                       & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])
                                                       ? 0x1fU
                                                       : 
                                                      ((8U 
                                                        & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])
                                                        ? 2U
                                                        : 
                                                       ((0x10U 
                                                         & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])
                                                         ? 3U
                                                         : 
                                                        ((0x20U 
                                                          & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])
                                                          ? 1U
                                                          : 0U))))))))));
    __Vtemp_hcfd7f9d2__0[1U] = ((0x4000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                 ? (0x80000000U | (IData)(
                                                          (cpu__DOT__wb_stage__DOT____VdfgTmp_he2911870__0 
                                                           >> 0x20U)))
                                 : ((0x8000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                     ? (0x80000000U 
                                        | (IData)((cpu__DOT__wb_stage__DOT____VdfgTmp_he2911870__0 
                                                   >> 0x20U)))
                                     : ((0x10000000U 
                                         & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                         ? 0x80000000U
                                         : ((0x20000000U 
                                             & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                             ? 0U : 
                                            ((0x40000000U 
                                              & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                              ? 0x80000000U
                                              : ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                                  >> 0x1fU)
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])
                                                   ? 
                                                  (0x80000000U 
                                                   | (IData)(
                                                             ((((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                                                                << 0x3eU) 
                                                               | ((QData)((IData)(
                                                                                ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                                                                << 0x17U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
                                                                                >> 9U)))) 
                                                                  << 0x1eU)) 
                                                              >> 0x20U)))
                                                   : 
                                                  __Vtemp_h9cf7bc36__0[1U])))))));
    __Vtemp_hb400cdeb__0[0U] = ((0x2000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                 ? (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                                             << 0x3eU) 
                                            | (((QData)((IData)(
                                                                vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U])) 
                                                << 0x1eU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid) 
                                                                   << 0x14U) 
                                                                  | cpu__DOT__wb_stage__DOT____VdfgTmp_he899fe78__0))))))
                                 : ((0x4000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                     ? (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_he2911870__0)
                                     : ((0x8000000U 
                                         & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                         ? (IData)(cpu__DOT__wb_stage__DOT____VdfgTmp_he2911870__0)
                                         : ((0x10000000U 
                                             & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                             ? 0U : 
                                            ((0x20000000U 
                                              & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                              ? 0U : 
                                             ((0x40000000U 
                                               & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                               ? 0U
                                               : ((
                                                   vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                                   >> 0x1fU)
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U])
                                                    ? (IData)(
                                                              (((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                                                                << 0x3eU) 
                                                               | ((QData)((IData)(
                                                                                ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                                                                                << 0x17U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[4U] 
                                                                                >> 9U)))) 
                                                                  << 0x1eU)))
                                                    : 
                                                   __Vtemp_h9cf7bc36__0[0U]))))))));
    if ((0x1000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])) {
        vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                        << 0x3eU) | ((QData)((IData)(
                                                     vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U])) 
                                     << 0x1eU)));
        vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[1U] 
            = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                         << 0x3eU) | ((QData)((IData)(
                                                      vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U])) 
                                      << 0x1eU)) >> 0x20U));
        vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[2U] = 4U;
    } else {
        vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[0U] 
            = __Vtemp_hb400cdeb__0[0U];
        if ((0x2000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])) {
            vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[1U] 
                = (0x80000000U | (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
                                            << 0x3eU) 
                                           | (((QData)((IData)(
                                                               vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U])) 
                                               << 0x1eU) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid) 
                                                                  << 0x14U) 
                                                                 | cpu__DOT__wb_stage__DOT____VdfgTmp_he899fe78__0))))) 
                                          >> 0x20U)));
            vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[2U] = 0x1fU;
        } else {
            vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[1U] 
                = __Vtemp_hcfd7f9d2__0[1U];
            vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[2U] 
                = ((0x4000000U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                    ? 1U : __Vtemp_h498d23a3__0[2U]);
        }
    }
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_valid_wr_en 
        = ((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_e) 
           & (IData)(vlSelf->__PVT__cpu__DOT__tlbrd_en));
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_invalid_wr_en 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_e)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__tlbrd_en));
    vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_h52ebff71__0 
        = ((((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
              >> 0x16U) | (((~ (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                >> 6U)) & (IData)(vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_h71ee0a69__0)) 
                           | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U] 
                              >> 0x12U))) & (IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
           | (((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[6U] 
                >> 0x12U) & (IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)) 
              | (IData)(vlSelf->__PVT__cpu__DOT__idle_flush)));
    vlSelf->debug_wb_rf_we = (0xfU & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_we))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2 
        = ((0U == (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_raddr2))
            ? 0U : ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_raddr2) 
                      == (0x1fU & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U])) 
                     & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_we))
                     ? vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[1U]
                     : vlSelf->__PVT__cpu__DOT__id_stage__DOT__u_regfile__DOT__rf
                    [vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_raddr2]));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1 
        = ((0U == (0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                            >> 5U))) ? 0U : ((((0x1fU 
                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                   >> 5U)) 
                                               == (0x1fU 
                                                   & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U])) 
                                              & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_we))
                                              ? vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[1U]
                                              : vlSelf->__PVT__cpu__DOT__id_stage__DOT__u_regfile__DOT__rf
                                             [(0x1fU 
                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                  >> 5U))]));
    vlSelf->cpu__DOT__u_csr__DOT____VdfgTmp_hce7fc8e0__0 
        = (IData)(((0x3f0000U == (0x3f0000U & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_estat)) 
                   & (IData)(vlSelf->__PVT__cpu__DOT__ertn_flush)));
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tcfg_wen = 
        ((IData)(vlSelf->__PVT__cpu__DOT__csr_wr_en) 
         & (0x4100U == (0x3fff00U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])));
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbehi_wen 
        = ((IData)(vlSelf->__PVT__cpu__DOT__csr_wr_en) 
           & (0x1100U == (0x3fff00U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])));
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__DMW0_wen = 
        ((IData)(vlSelf->__PVT__cpu__DOT__csr_wr_en) 
         & (0x18000U == (0x3fff00U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])));
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__DMW1_wen = 
        ((IData)(vlSelf->__PVT__cpu__DOT__csr_wr_en) 
         & (0x18100U == (0x3fff00U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])));
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__crmd_wen = 
        ((IData)(vlSelf->__PVT__cpu__DOT__csr_wr_en) 
         & (0U == (0x3fff00U & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hac115781__0) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nor) 
              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_and) 
                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_or) 
                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xor) 
                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sll_w) 
                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srl_w) 
                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sra_w) 
                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w) 
                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_wu) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_wu) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_wu) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_break) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall) 
                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slli_w) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srli_w) 
                                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srai_w) 
                                                                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_idle) 
                                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti) 
                                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui) 
                                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x14U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x16U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x17U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x18U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x19U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x1aU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x1bU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrwr) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ertn) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_dbar) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nop) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                                                & ((0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                | ((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                | ((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                | ((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                | ((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                | ((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])) 
                                                                                | (6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U])))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1d0e0636__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rj 
        = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_haf287d09__0) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w) 
              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slt) 
                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltu) 
                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti) 
                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui) 
                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_and) 
                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_or) 
                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nor) 
                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xor) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_wu) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w) 
                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_wu) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w) 
                                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_wu) 
                                                                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sll_w) 
                                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srl_w) 
                                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sra_w) 
                                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slli_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srli_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srai_w) 
                                                                                | ((0x16U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x17U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x18U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x1aU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x19U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x1bU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb)))))))))))))))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__tlbwr_en = (1U & (((IData)(vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_h292b3a37__0) 
                                                & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__commit_inst)))) 
                                               >> 3U));
    vlSelf->__PVT__cpu__DOT__ws_csr_ecode = ((0x800000U 
                                              & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U])
                                              ? 0U : 
                                             (0x3fU 
                                              & ((vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[2U] 
                                                  << 1U) 
                                                 | (vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[1U] 
                                                    >> 0x1fU))));
    vlSelf->__PVT__cpu__DOT__excp_tlbrefill = (1U & 
                                               ((~ 
                                                 (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                                  >> 0x17U)) 
                                                & (vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0[0U] 
                                                   >> 0x14U)));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign 
        = ((IData)(vlSelf->__PVT__cpu__DOT__ertn_flush) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__excp_flush) 
              | (IData)(vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_h52ebff71__0)));
    vlSelf->__VdfgTmp_hb44e37ca__0 = ((IData)(vlSelf->__PVT__cpu__DOT__ertn_flush) 
                                      | (IData)(vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_h52ebff71__0));
    vlSelf->__PVT__cpu__DOT__csr_dmw0 = ((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__DMW0_wen)
                                          ? ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                              << 0x18U) 
                                             | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                                >> 8U))
                                          : vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw0);
    vlSelf->__PVT__cpu__DOT__csr_dmw1 = ((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__DMW1_wen)
                                          ? ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[3U] 
                                              << 0x18U) 
                                             | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                                >> 8U))
                                          : vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw1);
    vlSelf->__PVT__cpu__DOT__csr_plv = (3U & (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__ertn_flush))) 
                                               & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_prmd) 
                                              | (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__crmd_wen))) 
                                                  & ((vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                                      << 0x18U) 
                                                     | (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                                        >> 8U))) 
                                                 | ((- (IData)(
                                                               (1U 
                                                                & ((~ (IData)(vlSelf->__PVT__cpu__DOT__excp_flush)) 
                                                                   & ((~ (IData)(vlSelf->__PVT__cpu__DOT__ertn_flush)) 
                                                                      & (~ (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__crmd_wen))))))) 
                                                    & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm 
        = ((0x1fU & ((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__need_ui5))) 
                     & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                        >> 0xaU))) | (((- (IData)(((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w) 
                                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                      | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti) 
                                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui) 
                                                                                | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1d0e0636__0)))))))))))))) 
                                       & (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                          >> 0x15U)))) 
                                           << 0xcU) 
                                          | (0xfffU 
                                             & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                >> 0xaU)))) 
                                      | ((0xfffU & 
                                          ((- (IData)(
                                                      ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi) 
                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori) 
                                                          | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori))))) 
                                           & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                              >> 0xaU))) 
                                         | (((- (IData)(
                                                        ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                         | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)))) 
                                             & (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                >> 0x17U)))) 
                                                 << 0x10U) 
                                                | (0xfffcU 
                                                   & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                      >> 8U)))) 
                                            | (((- (IData)(
                                                           ((0x13U 
                                                             == 
                                                             (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                              >> 0x1aU)) 
                                                            | ((0x16U 
                                                                == 
                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                 >> 0x1aU)) 
                                                               | ((0x17U 
                                                                   == 
                                                                   (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                    >> 0x1aU)) 
                                                                  | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h38353e9a__0)))))) 
                                                & (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                   >> 0x19U)))) 
                                                    << 0x12U) 
                                                   | (0x3fffcU 
                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                         >> 8U)))) 
                                               | ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w) 
                                                                  | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i)))) 
                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                         << 7U))) 
                                                  | (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi))) 
                                                      & (((- (IData)(
                                                                     (1U 
                                                                      & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                         >> 0x18U)))) 
                                                          << 0x16U) 
                                                         | (0x3ffffcU 
                                                            & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                               >> 3U)))) 
                                                     | ((- (IData)(
                                                                   ((0x14U 
                                                                     == 
                                                                     (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                      >> 0x1aU)) 
                                                                    | (0x15U 
                                                                       == 
                                                                       (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                        >> 0x1aU))))) 
                                                        & (((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                           >> 9U)))) 
                                                            << 0x1cU) 
                                                           | ((0xffc0000U 
                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                  << 0x12U)) 
                                                              | (0x3fffcU 
                                                                 & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                    >> 8U))))))))))));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__we = 
        ((IData)(vlSelf->__PVT__cpu__DOT__tlbfill_en) 
         | (IData)(vlSelf->__PVT__cpu__DOT__tlbwr_en));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__w_index 
        = (0x1fU & (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__tlbfill_en))) 
                     & (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__timer_64)) 
                    | ((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__tlbwr_en))) 
                       & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx)));
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__no_forward 
        = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__excp_tlbrefill)) 
                 & ((~ (IData)(vlSelf->cpu__DOT__u_csr__DOT____VdfgTmp_hce7fc8e0__0)) 
                    & (~ (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__crmd_wen)))));
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_flush_sign 
        = ((IData)(vlSelf->__PVT__cpu__DOT__excp_flush) 
           | (IData)(vlSelf->__VdfgTmp_hb44e37ca__0));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp_ipe 
        = (((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h6983a416__0) 
            | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
                & (2U != (3U & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                >> 3U)))) | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch) 
                                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill) 
                                                      | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ertn) 
                                                            | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_idle))))))))) 
           & (3U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv)));
    vlSelf->__VdfgTmp_h3a64b587__0 = ((vlSelf->__PVT__cpu__DOT__csr_dmw0 
                                       & (0U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv))) 
                                      | ((vlSelf->__PVT__cpu__DOT__csr_dmw0 
                                          >> 3U) & 
                                         (3U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv))));
    vlSelf->__VdfgTmp_h6802c383__0 = ((vlSelf->__PVT__cpu__DOT__csr_dmw1 
                                       & (0U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv))) 
                                      | ((vlSelf->__PVT__cpu__DOT__csr_dmw1 
                                          >> 3U) & 
                                         (3U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv))));
    vlSelf->__PVT__cpu__DOT__csr_pg = ((IData)(vlSelf->cpu__DOT__u_csr__DOT____VdfgTmp_hce7fc8e0__0) 
                                       | (((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__crmd_wen) 
                                           & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                              >> 0xcU)) 
                                          | ((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__no_forward) 
                                             & (vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd 
                                                >> 4U))));
    vlSelf->__PVT__cpu__DOT__csr_da = ((IData)(vlSelf->__PVT__cpu__DOT__excp_tlbrefill) 
                                       | (((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__crmd_wen) 
                                           & (vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[2U] 
                                              >> 0xbU)) 
                                          | ((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__no_forward) 
                                             & (vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd 
                                                >> 3U))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp = 
        (1U & ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp_ipe) 
               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_break) 
                     | ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                         >> 4U) | ((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid)) 
                                   | (IData)(vlSelf->__PVT__cpu__DOT__has_int)))))));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__da_mode 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__csr_pg)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__csr_da));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__csr_da)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__csr_pg));
    vlSelf->__PVT__cpu__DOT__inst_dmw0_en = ((IData)(vlSelf->__VdfgTmp_h3a64b587__0) 
                                             & (((vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc 
                                                  >> 0x1dU) 
                                                 == 
                                                 (vlSelf->__PVT__cpu__DOT__csr_dmw0 
                                                  >> 0x1dU)) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__inst_dmw1_en = ((IData)(vlSelf->__VdfgTmp_h6802c383__0) 
                                             & (((vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc 
                                                  >> 0x1dU) 
                                                 == 
                                                 (vlSelf->__PVT__cpu__DOT__csr_dmw1 
                                                  >> 0x1dU)) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__data_dmw0_en = ((IData)(vlSelf->__VdfgTmp_h3a64b587__0) 
                                             & (((7U 
                                                  & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                                                     >> 0x14U)) 
                                                 == 
                                                 (vlSelf->__PVT__cpu__DOT__csr_dmw0 
                                                  >> 0x1dU)) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__data_dmw1_en = ((IData)(vlSelf->__VdfgTmp_h6802c383__0) 
                                             & (((7U 
                                                  & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                                                     >> 0x14U)) 
                                                 == 
                                                 (vlSelf->__PVT__cpu__DOT__csr_dmw1 
                                                  >> 0x1dU)) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_paddr 
        = (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode) 
            & (IData)(vlSelf->__PVT__cpu__DOT__inst_dmw0_en))
            ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__csr_dmw0 
                               << 4U)) | (0x1fffffffU 
                                          & vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_vaddr_buffer))
            : (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode) 
                & (IData)(vlSelf->__PVT__cpu__DOT__inst_dmw1_en))
                ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__csr_dmw1 
                                   << 4U)) | (0x1fffffffU 
                                              & vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_vaddr_buffer))
                : vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_vaddr_buffer));
    vlSelf->__PVT__cpu__DOT__inst_addr_trans_en = (
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__cpu__DOT__inst_dmw0_en) 
                                                     | (IData)(vlSelf->__PVT__cpu__DOT__inst_dmw1_en))) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_paddr 
        = (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode) 
            & ((~ (IData)(vlSelf->__PVT__cpu__DOT__cacop_op_mode_di)) 
               & (IData)(vlSelf->__PVT__cpu__DOT__data_dmw0_en)))
            ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__csr_dmw0 
                               << 4U)) | (0x1fffffffU 
                                          & vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_vaddr_buffer))
            : (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode) 
                & ((~ (IData)(vlSelf->__PVT__cpu__DOT__cacop_op_mode_di)) 
                   & (IData)(vlSelf->__PVT__cpu__DOT__data_dmw1_en)))
                ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__csr_dmw1 
                                   << 4U)) | (0x1fffffffU 
                                              & vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_vaddr_buffer))
                : vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_vaddr_buffer));
    vlSelf->__PVT__cpu__DOT__data_addr_trans_en = (
                                                   (~ 
                                                    ((IData)(vlSelf->__PVT__cpu__DOT__data_dmw0_en) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__data_dmw1_en) 
                                                        | (IData)(vlSelf->__PVT__cpu__DOT__cacop_op_mode_di)))) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_tlbr 
        = ((~ (IData)((0U != (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match0)))) 
           & (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_trans_en));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_pif 
        = ((~ ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h5fe09d4e__0)
                ? vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v1
               [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]
                : vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v0
               [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))])) 
           & (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_trans_en));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_ppi 
        = (((IData)(vlSelf->__PVT__cpu__DOT__csr_plv) 
            > ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h5fe09d4e__0)
                ? vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv1
               [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]
                : vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv0
               [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))])) 
           & (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_trans_en));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr 
        = (((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__access_mem) 
            | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
               >> 0x15U)) & ((~ (IData)((0U != (IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match1)))) 
                             & (IData)(vlSelf->__PVT__cpu__DOT__data_addr_trans_en)));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi 
        = ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__access_mem) 
           & ((IData)(vlSelf->__PVT__cpu__DOT__data_tlb_v) 
              & (((IData)(vlSelf->__PVT__cpu__DOT__csr_plv) 
                  > (IData)(vlSelf->__PVT__cpu__DOT__data_tlb_plv)) 
                 & (IData)(vlSelf->__PVT__cpu__DOT__data_addr_trans_en))));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme 
        = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
            >> 0xaU) & ((IData)(vlSelf->__PVT__cpu__DOT__data_tlb_v) 
                        & (((IData)(vlSelf->__PVT__cpu__DOT__csr_plv) 
                            <= (IData)(vlSelf->__PVT__cpu__DOT__data_tlb_plv)) 
                           & ((~ ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h9c4ee013__0)
                                   ? vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_d1
                                  [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))]
                                   : vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_d0
                                  [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))])) 
                              & (IData)(vlSelf->__PVT__cpu__DOT__data_addr_trans_en)))));
    vlSelf->__PVT__cpu__DOT__data_uncache_en = (1U 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__da_mode) 
                                                    & (0U 
                                                       == 
                                                       (0x180U 
                                                        & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd))) 
                                                   | (((IData)(vlSelf->__PVT__cpu__DOT__data_dmw0_en) 
                                                       & (0U 
                                                          == 
                                                          (0x30U 
                                                           & vlSelf->__PVT__cpu__DOT__csr_dmw0))) 
                                                      | (((IData)(vlSelf->__PVT__cpu__DOT__data_dmw1_en) 
                                                          & (0U 
                                                             == 
                                                             (0x30U 
                                                              & vlSelf->__PVT__cpu__DOT__csr_dmw1))) 
                                                         | (((IData)(vlSelf->__PVT__cpu__DOT__data_addr_trans_en) 
                                                             & (0U 
                                                                == 
                                                                ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h9c4ee013__0)
                                                                  ? 
                                                                 vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat1
                                                                 [
                                                                 (0xfU 
                                                                  & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))]
                                                                  : 
                                                                 vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat0
                                                                 [
                                                                 (0xfU 
                                                                  & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))]))) 
                                                            | vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_disable_cache)))));
    cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__data_tlb_v)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__data_addr_trans_en));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil 
        = (((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
             >> 6U) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                       >> 0x15U)) & (IData)(cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis 
        = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
            >> 0xaU) & (IData)(cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0));
    vlSelf->__PVT__cpu__DOT__data_tlb_excp_cancel_req 
        = ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil) 
              | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis) 
                 | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi) 
                    | (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme)))));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp = 
        (1U & ((IData)(vlSelf->__PVT__cpu__DOT__data_tlb_excp_cancel_req) 
               | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                  >> 0xdU)));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__7(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__7\n"); );
    // Body
    vlSelf->__PVT__wire_awready = vlSelf->__Vdly__wire_awready;
    vlSelf->__PVT__wire_wready = vlSelf->__Vdly__wire_wready;
    vlSelf->__PVT__wire_arready = vlSelf->__Vdly__wire_arready;
    vlSelf->__PVT__wire_bvalid = vlSelf->__Vdly__wire_bvalid;
    vlSelf->__PVT__cpu__DOT__data_ret_last = ((IData)(vlSelf->__PVT__wire_rid) 
                                              & (IData)(vlSelf->__PVT__wire_rlast));
    vlSelf->__PVT__cpu__DOT__data_ret_valid = ((IData)(vlSelf->__PVT__wire_rid) 
                                               & (IData)(vlSelf->__PVT__wire_rvalid));
    vlSelf->__PVT__cpu__DOT__inst_ret_last = ((~ (IData)(vlSelf->__PVT__wire_rid)) 
                                              & (IData)(vlSelf->__PVT__wire_rlast));
    vlSelf->__PVT__cpu__DOT__inst_ret_valid = ((~ (IData)(vlSelf->__PVT__wire_rid)) 
                                               & (IData)(vlSelf->__PVT__wire_rvalid));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__0\n"); );
    // Init
    CData/*0:0*/ cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0;
    cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0 = 0;
    CData/*0:0*/ cpu__DOT__icache__DOT____VdfgTmp_h817477d8__0;
    cpu__DOT__icache__DOT____VdfgTmp_h817477d8__0 = 0;
    CData/*0:0*/ cpu__DOT__dcache__DOT____VdfgTmp_hb9bff828__0;
    cpu__DOT__dcache__DOT____VdfgTmp_hb9bff828__0 = 0;
    VlWide<4>/*127:0*/ __Vtemp_ha6ad9ad8__0;
    VlWide<4>/*127:0*/ __Vtemp_ha6ad9b0e__0;
    VlWide<4>/*127:0*/ __Vtemp_hc9dcc500__0;
    VlWide<4>/*127:0*/ __Vtemp_hc9dcc4c6__0;
    VlWide<5>/*159:0*/ __Vtemp_hbddc6129__0;
    VlWide<5>/*159:0*/ __Vtemp_h8c7c8e28__0;
    VlWide<5>/*159:0*/ __Vtemp_h10f5efe2__0;
    VlWide<7>/*223:0*/ __Vtemp_h0d17e4e4__0;
    VlWide<7>/*223:0*/ __Vtemp_h953c8cfc__0;
    VlWide<11>/*351:0*/ __Vtemp_hd0ee12c5__0;
    VlWide<11>/*351:0*/ __Vtemp_h73b336c9__0;
    // Body
    vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data 
        = (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_op) 
            & ((3U & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                      >> 2U)) == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num)))
            ? ((((8U & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                  ? (vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata 
                     >> 0x18U) : (vlSelf->__PVT__wire_rdata 
                                  >> 0x18U)) << 0x18U) 
               | ((0xff0000U & (((4U & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                                  ? (vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata 
                                     >> 0x10U) : (vlSelf->__PVT__wire_rdata 
                                                  >> 0x10U)) 
                                << 0x10U)) | ((0xff00U 
                                               & (((2U 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                                                    ? 
                                                   (vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata 
                                                    >> 8U)
                                                    : 
                                                   (vlSelf->__PVT__wire_rdata 
                                                    >> 8U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & ((1U 
                                                     & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb))
                                                     ? vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata
                                                     : vlSelf->__PVT__wire_rdata)))))
            : vlSelf->__PVT__wire_rdata);
    __Vtemp_ha6ad9ad8__0[0U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][0U];
    __Vtemp_ha6ad9ad8__0[1U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][1U];
    __Vtemp_ha6ad9ad8__0[2U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][2U];
    __Vtemp_ha6ad9ad8__0[3U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [0U][3U];
    __Vtemp_ha6ad9b0e__0[0U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][0U];
    __Vtemp_ha6ad9b0e__0[1U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][1U];
    __Vtemp_ha6ad9b0e__0[2U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][2U];
    __Vtemp_ha6ad9b0e__0[3U] = vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data
        [1U][3U];
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata 
        = ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__data_buff_enable)
            ? vlSelf->__PVT__cpu__DOT__mem_stage__DOT__data_rd_buff
            : (((- (IData)((2U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
                & (((- (IData)((IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h064d00c1__0))) 
                    & __Vtemp_ha6ad9ad8__0[(3U & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                                                  >> 2U))]) 
                   | ((- (IData)((IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_hb6042862__0))) 
                      & __Vtemp_ha6ad9b0e__0[(3U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                                               >> 2U))]))) 
               | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
                  & vlSelf->__PVT__wire_rdata)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[0U][0U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[0U][1U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[0U][2U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[0U][3U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[1U][0U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[1U][1U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[1U][2U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[1U][3U] 
        = ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
           & vlSelf->__PVT__wire_rdata);
    __Vtemp_hc9dcc500__0[0U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [0U][0U];
    __Vtemp_hc9dcc500__0[1U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [0U][1U];
    __Vtemp_hc9dcc500__0[2U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [0U][2U];
    __Vtemp_hc9dcc500__0[3U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [0U][3U];
    __Vtemp_hc9dcc4c6__0[0U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [1U][0U];
    __Vtemp_hc9dcc4c6__0[1U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [1U][1U];
    __Vtemp_hc9dcc4c6__0[2U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [1U][2U];
    __Vtemp_hc9dcc4c6__0[3U] = vlSelf->__PVT__cpu__DOT__icache__DOT__way_data
        [1U][3U];
    vlSelf->__PVT__cpu__DOT__inst_rdata = (((- (IData)(
                                                       (2U 
                                                        == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
                                            & (((- (IData)((IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h5d80e202__0))) 
                                                & __Vtemp_hc9dcc500__0[
                                                (3U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_offset) 
                                                    >> 2U))]) 
                                               | ((- (IData)((IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_he890b2ef__0))) 
                                                  & __Vtemp_hc9dcc4c6__0[
                                                  (3U 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_offset) 
                                                      >> 2U))]))) 
                                           | ((- (IData)(
                                                         (0x10U 
                                                          == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)))) 
                                              & vlSelf->__PVT__wire_rdata));
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__rd_requst_can_receive 
        = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__read_requst_state)) 
                 & (~ ((~ ((IData)(vlSelf->__PVT__wire_bready) 
                           & (IData)(vlSelf->__PVT__wire_bvalid))) 
                       & (0U != (IData)(vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__write_requst_state))))));
    cpu__DOT__dcache__DOT____VdfgTmp_hb9bff828__0 = 
        ((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
         & (((IData)(vlSelf->__PVT__cpu__DOT__data_ret_last) 
             & (IData)(vlSelf->__PVT__cpu__DOT__data_ret_valid)) 
            | ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode0) 
               | ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode1) 
                  | (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2_hit_wr_buffer)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_replace_way) 
           & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_ret_valid))));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_ready_go 
        = (1U & (((~ (IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h63343402__0)) 
                  & (((2U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                      & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cache_hit) 
                         | ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_op) 
                            | (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cancel_req)))) 
                     | ((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                        & ((~ (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_op)) 
                           & ((IData)(vlSelf->__PVT__cpu__DOT__data_ret_valid) 
                              & (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num) 
                                  == (3U & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                                            >> 2U))) 
                                 | (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_uncache_en))))))) 
                 | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__data_buff_enable) 
                    | ((~ (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__access_mem)) 
                       | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp) 
                          | (IData)(vlSelf->__PVT__cpu__DOT__sc_cancel_req))))));
    cpu__DOT__icache__DOT____VdfgTmp_h817477d8__0 = 
        ((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
         & (((IData)(vlSelf->__PVT__cpu__DOT__inst_ret_last) 
             & (IData)(vlSelf->__PVT__cpu__DOT__inst_ret_valid)) 
            | ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode0) 
               | ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode1) 
                  | (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode2_hit_wr)))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en 
        = ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_replace_way) 
           & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_ret_valid))));
    vlSelf->__PVT__cpu__DOT__inst_data_ok = (((2U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                                              & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cache_hit) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__inst_tlb_excp_cancel_req))) 
                                             | ((0x10U 
                                                 == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                                                & ((IData)(vlSelf->__PVT__cpu__DOT__inst_ret_valid) 
                                                   & ((~ (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_icacop)) 
                                                      & (((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num) 
                                                          == 
                                                          (3U 
                                                           & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_offset) 
                                                              >> 2U))) 
                                                         | (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_uncache_en))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[0U][0U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[0U][1U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[0U][2U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[0U][3U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[1U][0U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[1U][1U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[1U][2U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[1U][3U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state))) 
            & vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata) 
           | ((- (IData)((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)))) 
              & vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_byteLoaded 
        = (0xffU & (((- (IData)((0U == (3U & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U])))) 
                     & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata) 
                    | (((- (IData)((1U == (3U & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U])))) 
                        & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata 
                           >> 8U)) | (((- (IData)((2U 
                                                   == 
                                                   (3U 
                                                    & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U])))) 
                                       & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata 
                                          >> 0x10U)) 
                                      | ((- (IData)(
                                                    (3U 
                                                     == 
                                                     (3U 
                                                      & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U])))) 
                                         & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata 
                                            >> 0x18U))))));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_halfLoaded 
        = (0xffffU & (((- (IData)((0U == (3U & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U])))) 
                       & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata) 
                      | ((- (IData)((2U == (3U & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U])))) 
                         & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata 
                            >> 0x10U))));
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__wea 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_replace_way) 
           & (IData)(cpu__DOT__dcache__DOT____VdfgTmp_hb9bff828__0));
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__1__KET____DOT__u__wea 
        = (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_replace_way) 
            >> 1U) & (IData)(cpu__DOT__dcache__DOT____VdfgTmp_hb9bff828__0));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_wea[0U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_replace_way) 
           & (IData)(cpu__DOT__dcache__DOT____VdfgTmp_hb9bff828__0));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_wea[1U] 
        = (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_replace_way) 
            >> 1U) & (IData)(cpu__DOT__dcache__DOT____VdfgTmp_hb9bff828__0));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[0U][0U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [0U][0U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                    & (0U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[0U][1U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [0U][1U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                    & (1U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[0U][2U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [0U][2U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                    & (2U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[0U][3U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [0U][3U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                    & (3U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[1U][0U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [1U][0U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                     >> 1U) & (0U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[1U][1U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [1U][1U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                     >> 1U) & (1U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[1U][2U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [1U][2U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                     >> 1U) & (2U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[1U][3U] 
        = (0xfU & (((- (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                               [1U][3U])) & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb)) 
                   | (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                 & (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en) 
                                     >> 1U) & (3U == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num))))))));
    vlSelf->__PVT__cpu__DOT__ms_allowin = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid)) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_ready_go)));
    vlSelf->__PVT__cpu__DOT__ms_to_ws_valid = ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_ready_go));
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__wea 
        = ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_replace_way) 
           & (IData)(cpu__DOT__icache__DOT____VdfgTmp_h817477d8__0));
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__1__KET____DOT__u__wea 
        = (((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_replace_way) 
            >> 1U) & (IData)(cpu__DOT__icache__DOT____VdfgTmp_h817477d8__0));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_wea[0U] 
        = ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_replace_way) 
           & (IData)(cpu__DOT__icache__DOT____VdfgTmp_h817477d8__0));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_wea[1U] 
        = (((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_replace_way) 
            >> 1U) & (IData)(cpu__DOT__icache__DOT____VdfgTmp_h817477d8__0));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[0U][0U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                 & (0U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[0U][1U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                 & (1U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[0U][2U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                 & (2U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[0U][3U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                 & (3U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[1U][0U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & (((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                  >> 1U) & (0U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[1U][1U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & (((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                  >> 1U) & (1U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[1U][2U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & (((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                  >> 1U) & (2U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[1U][3U] 
        = (0xfU & (- (IData)(((0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                              & (((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en) 
                                  >> 1U) & (3U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num)))))));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_ready_go 
        = ((IData)(vlSelf->__PVT__cpu__DOT__inst_data_ok) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_buff_enable) 
              | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_excp)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data 
        = (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                              >> 6U)))) & (((- (IData)(
                                                       (1U 
                                                        & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                                            >> 0xbU) 
                                                           & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                              >> 0xeU))))) 
                                            & (((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_byteLoaded) 
                                                               >> 7U)))) 
                                                << 8U) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_byteLoaded))) 
                                           | (((- (IData)(
                                                          (1U 
                                                           & ((~ 
                                                               (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                                >> 0xeU)) 
                                                              & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                                                 >> 0xbU))))) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_byteLoaded)) 
                                              | (((- (IData)(
                                                             (1U 
                                                              & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                                                  >> 0xcU) 
                                                                 & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                                    >> 0xeU))))) 
                                                  & (((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_halfLoaded) 
                                                                     >> 0xfU)))) 
                                                      << 0x10U) 
                                                     | (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_halfLoaded))) 
                                                 | (((- (IData)(
                                                                (1U 
                                                                 & ((~ 
                                                                     (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                                      >> 0xeU)) 
                                                                    & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                                                       >> 0xcU))))) 
                                                     & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_halfLoaded)) 
                                                    | ((- (IData)(
                                                                  (1U 
                                                                   & (~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (3U 
                                                                                & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                                                                >> 0xbU)))))))) 
                                                       & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata)))))) 
           | (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                 >> 7U)))) & (IData)(vlSelf->__PVT__cpu__DOT__mul_result)) 
              | (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                    >> 8U)))) & (IData)(
                                                        (vlSelf->__PVT__cpu__DOT__mul_result 
                                                         >> 0x20U))) 
                 | (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                       >> 9U)))) & (IData)(
                                                           (0x1ffffffffULL 
                                                            & ((IData)(vlSelf->__PVT__cpu__DOT__u_div__DOT__real_div_signed)
                                                                ? 
                                                               (((IData)(vlSelf->__PVT__cpu__DOT__u_div__DOT__real_x_31) 
                                                                 == 
                                                                 (1U 
                                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__u_div__DOT__real_complete)
                                                                      ? (IData)(vlSelf->__PVT__cpu__DOT__u_div__DOT__y_31_buffer)
                                                                      : 
                                                                     (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[1U] 
                                                                      >> 0x1fU))))
                                                                 ? vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignS
                                                                 : 
                                                                (~ 
                                                                 (vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignS 
                                                                  - 1ULL)))
                                                                : vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignS)))) 
                    | (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                                          >> 0xaU)))) 
                        & (IData)((0x1ffffffffULL & 
                                   ((IData)(vlSelf->__PVT__cpu__DOT__u_div__DOT__real_div_signed)
                                     ? ((IData)(vlSelf->__PVT__cpu__DOT__u_div__DOT__real_x_31)
                                         ? (~ (vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignR 
                                               - 1ULL))
                                         : vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignR)
                                     : vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignR)))) 
                       | ((- (IData)((1U & (~ (IData)(
                                                      (0U 
                                                       != 
                                                       (0x7c0U 
                                                        & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U]))))))) 
                          & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[1U] 
                             & (- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__sc_cancel_req))))))))))));
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en 
        = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_valid) 
           & ((~ (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp)) 
              & ((~ ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_flush_sign) 
                     | (((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp) 
                         | ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                             >> 0xeU) | ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U] 
                                          >> 0x1dU) 
                                         | (((~ (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp)) 
                                             & (IData)(
                                                       (0U 
                                                        != 
                                                        (0x300U 
                                                         & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U])))) 
                                            | ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                                                >> 0xeU) 
                                               | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                  >> 0x16U)))))) 
                        & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid)))) 
                 & (IData)(vlSelf->__PVT__cpu__DOT__ms_allowin))));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h0663ec88__0 
        = (1U & (((~ (IData)(vlSelf->__PVT__cpu__DOT__ms_to_ws_valid)) 
                  & (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                     >> 6U)) | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_need_reg_data)));
    vlSelf->__PVT__cpu__DOT__fs_to_ds_valid = ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_valid) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_ready_go));
    vlSelf->__PVT__cpu__DOT__preld_en = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__preld_inst) 
                                         & (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en));
    vlSelf->__PVT__cpu__DOT__data_valid = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__access_mem) 
                                           & (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en));
    vlSelf->__PVT__cpu__DOT__icacop_op_en = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__icacop_inst) 
                                             & (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en));
    vlSelf->__PVT__cpu__DOT__dcacop_op_en = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcacop_inst) 
                                             & (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en));
    if ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_raddr2) 
          == (0x1fU & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U])) 
         & ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__forward_enable) 
            & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rkd)))) {
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[0U];
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[1U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[1U];
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[2U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[2U];
    } else if ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_raddr2) 
                 == (0x1fU & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])) 
                & ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_enable) 
                   & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rkd)))) {
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data)) 
                        << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2))));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[1U] 
            = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data)) 
                         << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2))) 
                       >> 0x20U));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[2U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h0663ec88__0;
    } else {
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2)) 
                        << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2))));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[1U] 
            = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2)) 
                         << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2))) 
                       >> 0x20U));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[2U] = 0U;
    }
    if ((((0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                    >> 5U)) == (0x1fU & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U])) 
         & ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__forward_enable) 
            & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rj)))) {
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[0U];
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[1U];
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[2U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[2U];
    } else if ((((0x1fU & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                           >> 5U)) == (0x1fU & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U])) 
                & ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_enable) 
                   & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rj)))) {
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data)) 
                        << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1))));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U] 
            = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data)) 
                         << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1))) 
                       >> 0x20U));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[2U] 
            = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h0663ec88__0;
    } else {
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1)) 
                        << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1))));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U] 
            = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1)) 
                         << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1))) 
                       >> 0x20U));
        vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[2U] = 0U;
    }
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0U] = (IData)(
                                                        (((QData)((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__exe_result)) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[0U]))));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[1U] = (IData)(
                                                        ((((QData)((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__exe_result)) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[0U]))) 
                                                         >> 0x20U));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[2U] = (((
                                                   (0x40000U 
                                                    & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U])
                                                    ? 
                                                   ((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[2U] 
                                                     & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[1U]) 
                                                    | ((~ 
                                                        vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[2U]) 
                                                       & ((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                           << 0x1eU) 
                                                          | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[5U] 
                                                             >> 2U))))
                                                    : 
                                                   vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[1U]) 
                                                  << 0xfU) 
                                                 | ((0x4000U 
                                                     & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[5U] 
                                                        << 0xdU)) 
                                                    | (((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp) 
                                                        << 0xdU) 
                                                       | ((0x1f80U 
                                                           & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U] 
                                                              >> 0x13U)) 
                                                          | ((0x40U 
                                                              & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U] 
                                                                 >> 4U)) 
                                                             | ((0x20U 
                                                                 & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U] 
                                                                    >> 1U)) 
                                                                | (0x1fU 
                                                                   & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U])))))));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[3U] = ((0xc0000000U 
                                                  & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                     << 0xbU)) 
                                                 | ((0x3fff8000U 
                                                     & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                        << 0xcU)) 
                                                    | (((0x40000U 
                                                         & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U])
                                                         ? 
                                                        ((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[2U] 
                                                          & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[1U]) 
                                                         | ((~ 
                                                             vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[2U]) 
                                                            & ((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                                << 0x1eU) 
                                                               | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[5U] 
                                                                  >> 2U))))
                                                         : 
                                                        vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[1U]) 
                                                       >> 0x11U)));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[4U] = ((0xf8000000U 
                                                  & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[1U] 
                                                     << 0xeU)) 
                                                 | ((0x7fe0000U 
                                                     & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[2U] 
                                                        << 0x11U)) 
                                                    | ((0x1f800U 
                                                        & ((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                                            << 0xdU) 
                                                           | (0x1800U 
                                                              & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                                 >> 0x13U)))) 
                                                       | ((0x400U 
                                                           & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U] 
                                                              << 5U)) 
                                                          | ((0x300U 
                                                              & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                                 >> 0x14U)) 
                                                             | (0x3fffffffU 
                                                                & ((0x3fffff80U 
                                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp_ale) 
                                                                       << 7U)) 
                                                                   | (0x7fU 
                                                                      & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                                         >> 0x15U)))))))));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[5U] = ((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__error_va 
                                                  << 0x17U) 
                                                 | ((0x400000U 
                                                     & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                                        << 0xbU)) 
                                                    | ((0x200000U 
                                                        & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                                           << 0x10U)) 
                                                       | (((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__preld_inst) 
                                                           << 0x14U) 
                                                          | ((0xf0000U 
                                                              & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                                                 << 9U)) 
                                                             | (((IData)(vlSelf->__PVT__cpu__DOT__icacop_op_en) 
                                                                 << 0xfU) 
                                                                | ((0x4000U 
                                                                    & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                                                       << 0xaU)) 
                                                                   | (0x7ffffffU 
                                                                      & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[1U] 
                                                                         >> 0x12U)))))))));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[6U] = ((0xff800000U 
                                                  & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                                     << 0xbU)) 
                                                 | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__error_va 
                                                    >> 9U));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[7U] = (((0x7ff800U 
                                                   & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[8U] 
                                                      << 0xbU)) 
                                                  | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                                     >> 0x15U)) 
                                                 | (0xff800000U 
                                                    & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[8U] 
                                                       << 0xbU)));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[8U] = (((0x7ff800U 
                                                   & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[9U] 
                                                      << 0xbU)) 
                                                  | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[8U] 
                                                     >> 0x15U)) 
                                                 | (0xff800000U 
                                                    & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[9U] 
                                                       << 0xbU)));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[9U] = (((0x7ff800U 
                                                   & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[0xaU] 
                                                      << 0xbU)) 
                                                  | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[9U] 
                                                     >> 0x15U)) 
                                                 | (0xff800000U 
                                                    & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[0xaU] 
                                                       << 0xbU)));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xaU] = vlSelf->__PVT__cpu__DOT__data_vaddr;
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xbU] = (
                                                   (vlSelf->__PVT__cpu__DOT__data_wdata 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[0xaU] 
                                                         >> 0x15U)));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xcU] = (
                                                   (0xfffffe00U 
                                                    & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[5U] 
                                                       << 7U)) 
                                                   | ((0x100U 
                                                       & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[0xaU] 
                                                          >> 0x15U)) 
                                                      | (vlSelf->__PVT__cpu__DOT__data_wdata 
                                                         >> 0x18U)));
    vlSelf->__PVT__cpu__DOT__es_to_ms_bus[0xdU] = (0x1ffU 
                                                   & ((0x180U 
                                                       & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                          << 7U)) 
                                                      | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[5U] 
                                                         >> 0x19U)));
    vlSelf->__PVT__cpu__DOT__inst_addr_ok = ((~ (IData)(vlSelf->__PVT__cpu__DOT__icacop_op_en)) 
                                             & ((1U 
                                                 == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                                                | ((2U 
                                                    == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cache_hit))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__req_or_inst_valid 
        = ((IData)(vlSelf->__PVT__cpu__DOT__data_valid) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__dcacop_op_en) 
              | (IData)(vlSelf->__PVT__cpu__DOT__preld_en)));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__main_idle2lookup 
        = (1U & (~ ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state) 
                    & (((3U & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset) 
                               >> 2U)) == (3U & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                                                 >> 2U))) 
                       | (IData)(vlSelf->__PVT__cpu__DOT__dcacop_op_en)))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_ready_go 
        = (1U & ((~ (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[2U] 
                     | (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[2U] 
                        | (((((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                               >> 0x1eU) | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[7U] 
                                            >> 2U)) 
                             & (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_valid)) 
                            | (((IData)((0U != (0x8800U 
                                                & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U]))) 
                                & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid)) 
                               | ((IData)((0U != (0x80200U 
                                                  & vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[5U]))) 
                                  & (IData)(vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid)))) 
                           | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar) 
                               | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_dbar)) 
                              & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__pipeline_no_empty)))))) 
                 | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp)));
    vlSelf->__PVT__cpu__DOT__btb_right_target = (((- (IData)(
                                                             ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h19962199__0) 
                                                              | ((0x15U 
                                                                  == 
                                                                  (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                   >> 0x1aU)) 
                                                                 | ((0x14U 
                                                                     == 
                                                                     (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                      >> 0x1aU)) 
                                                                    | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h38353e9a__0)))))) 
                                                  & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[0U] 
                                                     + vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm)) 
                                                 | ((- (IData)(
                                                               (0x13U 
                                                                == 
                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                 >> 0x1aU)))) 
                                                    & (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
                                                       + vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_eq_rd 
        = (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
           == vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U]);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign 
        = (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
           < vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U]);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_delay 
        = (((~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok)) 
            & (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign)) 
           | (IData)(vlSelf->__PVT__cpu__DOT__idle_flush));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_go_dirt 
        = ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign) 
           & ((~ (IData)(vlSelf->__PVT__cpu__DOT__idle_flush)) 
              & (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok)));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__main_lookup2lookup 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_idle2lookup) 
           & ((~ ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_op) 
                  & ((~ (IData)(vlSelf->__PVT__cpu__DOT__data_op)) 
                     & (((3U & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                                >> 2U)) == (3U & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                                                  >> 2U))) 
                        | (IData)(vlSelf->__PVT__cpu__DOT__dcacop_op_en))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cache_hit)));
    vlSelf->__PVT__cpu__DOT__ds_to_es_valid = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_valid) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_ready_go));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_sign 
        = (1U & (((~ (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U] 
                      >> 0x1fU)) & (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
                                    >> 0x1fU)) | ((~ 
                                                   ((~ 
                                                     (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[0U] 
                                                      >> 0x1fU)) 
                                                    & (vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[0U] 
                                                       >> 0x1fU))) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign))));
    vlSelf->__PVT__cpu__DOT__data_addr_ok = (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_idle2lookup) 
                                              & (1U 
                                                 == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state))) 
                                             | ((2U 
                                                 == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_lookup2lookup)));
    vlSelf->__PVT__cpu__DOT__btb_right_orien = ((((0x16U 
                                                   == 
                                                   (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                    >> 0x1aU)) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_eq_rd)) 
                                                 | (((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_eq_rd)) 
                                                     & (0x17U 
                                                        == 
                                                        (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                         >> 0x1aU))) 
                                                    | (((0x18U 
                                                         == 
                                                         (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                          >> 0x1aU)) 
                                                        & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_sign)) 
                                                       | (((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_sign)) 
                                                           & (0x19U 
                                                              == 
                                                              (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                               >> 0x1aU))) 
                                                          | (((0x1aU 
                                                               == 
                                                               (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                >> 0x1aU)) 
                                                              & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign)) 
                                                             | (((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign)) 
                                                                 & (0x1bU 
                                                                    == 
                                                                    (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                     >> 0x1aU))) 
                                                                | ((0x13U 
                                                                    == 
                                                                    (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                     >> 0x1aU)) 
                                                                   | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1c4a3e54__0)))))))) 
                                                & ((~ 
                                                    (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                     >> 4U)) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_valid)));
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__addra 
        = (0xffU & (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                     & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                        >> 4U)) | ((- (IData)((1U & 
                                               (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                   & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_addra[0U] 
        = (0xffU & (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                     & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                        >> 4U)) | ((- (IData)((1U & 
                                               (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                   & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_addra[1U] 
        = (0xffU & (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                     & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                        >> 4U)) | ((- (IData)((1U & 
                                               (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                   & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[0U][0U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [0U][0U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[0U][1U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [0U][1U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[0U][2U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [0U][2U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[0U][3U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [0U][3U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[1U][0U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [1U][0U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[1U][1U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [1U][1U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[1U][2U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [1U][2U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[1U][3U] 
        = (0xffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank
                    [1U][3U] ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)
                     : (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))) 
                         & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                            >> 4U)) | ((- (IData)((1U 
                                                   & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index)))));
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_ready_go 
        = (1U & (((~ ((0xffU != (IData)(vlSelf->__PVT__cpu__DOT__u_div__DOT__count)) 
                      & (IData)(vlSelf->__PVT__cpu__DOT__es_div_enable))) 
                  & ((~ (((vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                           >> 0x1eU) & (IData)(((0x20088000U 
                                                 == 
                                                 (0x3fff8000U 
                                                  & vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[3U])) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid)))) 
                         | ((1U != (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                            & (IData)(vlSelf->__PVT__cpu__DOT__icacop_op_en)))) 
                     & ((~ ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__access_mem) 
                            | ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcacop_inst) 
                               | (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__preld_inst)))) 
                        | ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en) 
                           & (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok))))) 
                 | (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush_target 
        = ((IData)(vlSelf->__PVT__cpu__DOT__btb_right_orien)
            ? vlSelf->__PVT__cpu__DOT__btb_right_target
            : ((IData)(4U) + vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[0U]));
    vlSelf->__PVT__cpu__DOT__btb_add_entry = ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_to_btb) 
                                              & ((~ 
                                                  (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                   >> 6U)) 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__btb_right_orien)));
    vlSelf->__PVT__cpu__DOT__btb_target_error = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hfea85cf8__0) 
                                                 & ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                     >> 7U) 
                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__btb_right_orien) 
                                                       & (((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[3U] 
                                                            << 0x13U) 
                                                           | (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                              >> 0xdU)) 
                                                          != vlSelf->__PVT__cpu__DOT__btb_right_target))));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hbba4846b__0 
        = (1U & ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                  >> 7U) ^ (IData)(vlSelf->__PVT__cpu__DOT__btb_right_orien)));
    vlSelf->__PVT__cpu__DOT__es_to_ms_valid = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_valid) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_ready_go));
    cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_ready_go) 
           & (IData)(vlSelf->__PVT__cpu__DOT__ms_allowin));
    vlSelf->__PVT__cpu__DOT__btb_pre_error = ((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hfea85cf8__0) 
                                              & (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hbba4846b__0));
    vlSelf->__PVT__cpu__DOT__data_fetch = ((((IData)(vlSelf->__PVT__cpu__DOT__data_valid) 
                                             | ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcacop_inst) 
                                                | (IData)(vlSelf->__PVT__cpu__DOT__preld_en))) 
                                            & (IData)(vlSelf->__PVT__cpu__DOT__data_addr_ok)) 
                                           | (((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__icacop_inst) 
                                               | (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[6U] 
                                                  >> 0x1eU)) 
                                              & (IData)(cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0)));
    vlSelf->__PVT__cpu__DOT__es_allowin = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_valid)) 
                                                 | (IData)(cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0)));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush 
        = (((IData)(vlSelf->__PVT__cpu__DOT__btb_add_entry) 
            | (((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_to_btb)) 
                & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                   >> 6U)) | ((IData)(vlSelf->__PVT__cpu__DOT__btb_pre_error) 
                              | (IData)(vlSelf->__PVT__cpu__DOT__btb_target_error)))) 
           & ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_valid) 
              & ((~ (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                     >> 4U)) & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_ready_go))));
    vlSelf->__PVT__cpu__DOT__ds_allowin = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_valid)) 
                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_ready_go) 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__es_allowin))));
    vlSelf->__PVT__cpu__DOT__btb_operate_en = ((IData)(vlSelf->__PVT__cpu__DOT__ds_to_es_valid) 
                                               & ((~ 
                                                   (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                    >> 4U)) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__es_allowin)));
    __Vtemp_hbddc6129__0[4U] = ((0x40U & (((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b)) 
                                           & (~ ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                    | ((0x16U 
                                                        == 
                                                        (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                         >> 0x1aU)) 
                                                       | ((0x17U 
                                                           == 
                                                           (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                            >> 0x1aU)) 
                                                          | ((0x18U 
                                                              == 
                                                              (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                               >> 0x1aU)) 
                                                             | ((0x19U 
                                                                 == 
                                                                 (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                  >> 0x1aU)) 
                                                                | ((0x1aU 
                                                                    == 
                                                                    (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                     >> 0x1aU)) 
                                                                   | ((0x1bU 
                                                                       == 
                                                                       (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                        >> 0x1aU)) 
                                                                      | ((0x14U 
                                                                          == 
                                                                          (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                           >> 0x1aU)) 
                                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall) 
                                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch) 
                                                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_dbar) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nop)))))))))))))))))))))) 
                                          << 6U)) | 
                                ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                            & (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit))))) 
                                  << 5U) | ((0x15U 
                                             == (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                 >> 0x1aU))
                                             ? 1U : (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h416d0694__0))));
    __Vtemp_h8c7c8e28__0[4U] = ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__mem_sign_exted) 
                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                     | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w))))) 
                                 << 0xaU) | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__src2_is_4) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi) 
                                                  | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i))) 
                                              << 9U) 
                                             | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__need_ui5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui) 
                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori) 
                                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori) 
                                                                    | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi) 
                                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i) 
                                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w) 
                                                                                | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1d0e0636__0))))))))))))))))))))) 
                                                 << 8U) 
                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__src2_is_4) 
                                                    << 7U) 
                                                   | __Vtemp_hbddc6129__0[4U]))));
    __Vtemp_h10f5efe2__0[4U] = ((0xfffff800U & ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
                                                  & (0x60000U 
                                                     == 
                                                     (0xf8000U 
                                                      & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))) 
                                                 << 0x18U) 
                                                | ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0) 
                                                     & (0x68000U 
                                                        == 
                                                        (0xf8000U 
                                                         & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))) 
                                                    << 0x17U) 
                                                   | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w) 
                                                       << 0x16U) 
                                                      | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sra_w) 
                                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srai_w)) 
                                                          << 0x15U) 
                                                         | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srl_w) 
                                                              | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srli_w)) 
                                                             << 0x14U) 
                                                            | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sll_w) 
                                                                 | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slli_w)) 
                                                                << 0x13U) 
                                                               | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xor) 
                                                                    | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori)) 
                                                                   << 0x12U) 
                                                                  | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_or) 
                                                                       | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori)) 
                                                                      << 0x11U) 
                                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nor) 
                                                                         << 0x10U) 
                                                                        | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_and) 
                                                                             | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi)) 
                                                                            << 0xfU) 
                                                                           | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltu) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui)) 
                                                                               << 0xeU) 
                                                                              | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slt) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti)) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sub_w) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_add_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                                                >> 0x1aU)) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i) 
                                                                                | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1d0e0636__0))))))))))))))))) 
                                                                                << 0xbU))))))))))))))) 
                                | __Vtemp_h8c7c8e28__0[4U]);
    __Vtemp_h0d17e4e4__0[5U] = ((((1U & (IData)((((
                                                   (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))) 
                                                   >> 0x20U) 
                                                  & (1ULL 
                                                     | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                                        >> 0x20U))) 
                                                 | ((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))) 
                                                      >> 0x20U) 
                                                     & (1ULL 
                                                        | ((QData)((IData)(
                                                                           (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                                            >> 0x20U))) 
                                                           >> 0x20U))) 
                                                    | (((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))) 
                                                        >> 0x20U) 
                                                       & (1ULL 
                                                          | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)) 
                                                             >> 0x20U)))))))
                                   ? (((IData)((0x1ffffffffULL 
                                                & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))))) 
                                       & (IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                      | (((IData)((0x1ffffffffULL 
                                                   & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))))) 
                                          & (IData)(
                                                    (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                     >> 0x20U))) 
                                         | ((IData)(
                                                    (0x1ffffffffULL 
                                                     & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))))) 
                                            & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)))
                                   : ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)
                                       ? (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit)
                                       : vlSelf->__PVT__cpu__DOT__rd_csr_data)) 
                                 << 2U) | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ertn) 
                                            << 1U) 
                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp)));
    __Vtemp_h0d17e4e4__0[6U] = (((1U & (IData)(((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))) 
                                                  >> 0x20U) 
                                                 & (1ULL 
                                                    | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                                       >> 0x20U))) 
                                                | ((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))) 
                                                     >> 0x20U) 
                                                    & (1ULL 
                                                       | ((QData)((IData)(
                                                                          (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                                           >> 0x20U))) 
                                                          >> 0x20U))) 
                                                   | (((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))) 
                                                       >> 0x20U) 
                                                      & (1ULL 
                                                         | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)) 
                                                            >> 0x20U)))))))
                                  ? (((IData)((0x1ffffffffULL 
                                               & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w))))) 
                                      & (IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64)) 
                                     | (((IData)((0x1ffffffffULL 
                                                  & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w))))) 
                                         & (IData)(
                                                   (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                    >> 0x20U))) 
                                        | ((IData)(
                                                   (0x1ffffffffULL 
                                                    & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))))) 
                                           & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid)))
                                  : ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)
                                      ? (IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit)
                                      : vlSelf->__PVT__cpu__DOT__rd_csr_data)) 
                                >> 0x1eU);
    __Vtemp_h953c8cfc__0[6U] = (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                 << 0x1cU) | ((0xfff80000U 
                                               & (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp_ipe) 
                                                   << 0x1bU) 
                                                  | ((0x4000000U 
                                                      & ((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid)) 
                                                         << 0x1aU)) 
                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_break) 
                                                         << 0x19U) 
                                                        | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall) 
                                                            << 0x18U) 
                                                           | ((0xf00000U 
                                                               & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                                  << 0x14U)) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__has_int) 
                                                                 << 0x13U))))))) 
                                              | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask) 
                                                  << 0x12U) 
                                                 | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_we) 
                                                     << 0x11U) 
                                                    | ((0x1fff8U 
                                                        & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                           >> 7U)) 
                                                       | ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h6983a416__0) 
                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj) 
                                                               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w) 
                                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w) 
                                                                     | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w))))) 
                                                           << 2U) 
                                                          | __Vtemp_h0d17e4e4__0[6U]))))));
    __Vtemp_hd0ee12c5__0[7U] = ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                 << 0xcU) | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_idle) 
                                              << 0xbU) 
                                             | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush) 
                                                 << 0xaU) 
                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_to_btb) 
                                                    << 9U) 
                                                   | ((0x100U 
                                                       & (vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                                                          << 3U)) 
                                                      | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_need_reg_data) 
                                                           | (IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1c4a3e54__0)) 
                                                          << 7U) 
                                                         | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop) 
                                                                << 5U) 
                                                               | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__mem_sign_exted) 
                                                                   << 4U) 
                                                                  | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                                      << 3U) 
                                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                                         << 2U) 
                                                                        | (((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar))))) 
                                                                             & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_valid)) 
                                                                            << 1U) 
                                                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill)))))))))))));
    __Vtemp_h73b336c9__0[0xaU] = ((((IData)(vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h6983a416__0) 
                                    & (0x1400U == (0xfffc00U 
                                                   & vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U]))) 
                                   << 0x1dU) | ((0xffe00000U 
                                                 & ((((IData)(vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit) 
                                                      & (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w)) 
                                                     << 0x18U) 
                                                    | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w) 
                                                        << 0x17U) 
                                                       | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h) 
                                                           << 0x16U) 
                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b) 
                                                             << 0x15U))))) 
                                                | ((0xffffe000U 
                                                    & (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w) 
                                                        << 0x12U) 
                                                       | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w) 
                                                           << 0x11U) 
                                                          | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                              << 0x10U) 
                                                             | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                                 << 0xfU) 
                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                                    << 0xeU) 
                                                                   | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                                      << 0xdU))))))) 
                                                   | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w) 
                                                           | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj))) 
                                                       << 0xcU) 
                                                      | ((IData)(
                                                                 (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                                  >> 0x20U)) 
                                                         >> 0x14U)))));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[0U] = vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[0U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[1U] = vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0[1U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[2U] = (IData)(
                                                        (((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm)) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U]))));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[3U] = (IData)(
                                                        ((((QData)((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm)) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0[1U]))) 
                                                         >> 0x20U));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[4U] = ((0xc0000000U 
                                                  & ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h) 
                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu) 
                                                          | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h))) 
                                                      << 0x1fU) 
                                                     | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu) 
                                                            | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b))) 
                                                        << 0x1eU))) 
                                                 | ((0xfc000000U 
                                                     & ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w) 
                                                          | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_wu)) 
                                                         << 0x1dU) 
                                                        | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w) 
                                                             | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_wu)) 
                                                            << 0x1cU) 
                                                           | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w) 
                                                                | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_wu)) 
                                                               << 0x1bU) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w) 
                                                                 << 0x1aU))))) 
                                                    | ((((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w) 
                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w) 
                                                               | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w)))) 
                                                        << 0x19U) 
                                                       | __Vtemp_h10f5efe2__0[4U])));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[5U] = __Vtemp_h0d17e4e4__0[5U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[6U] = (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr) 
                                                  << 0x1fU) 
                                                 | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch) 
                                                     << 0x1eU) 
                                                    | (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w) 
                                                        << 0x1dU) 
                                                       | __Vtemp_h953c8cfc__0[6U])));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[7U] = __Vtemp_hd0ee12c5__0[7U];
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[8U] = ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[1U] 
                                                  >> 0x14U) 
                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64) 
                                                    << 0xcU));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[9U] = (((IData)(vlSelf->__PVT__cpu__DOT__ds_timer_64) 
                                                  >> 0x14U) 
                                                 | ((IData)(
                                                            (vlSelf->__PVT__cpu__DOT__ds_timer_64 
                                                             >> 0x20U)) 
                                                    << 0xcU));
    vlSelf->__PVT__cpu__DOT__ds_to_es_bus[0xaU] = __Vtemp_h73b336c9__0[0xaU];
    vlSelf->__PVT__cpu__DOT__fetch_pc = ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_req_state)
                                          ? vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_req_buffer
                                          : ((IData)(vlSelf->__PVT__cpu__DOT__excp_flush)
                                              ? (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__excp_tlbrefill))) 
                                                  & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbrentry) 
                                                 | ((- (IData)(
                                                               (1U 
                                                                & (~ (IData)(vlSelf->__PVT__cpu__DOT__excp_tlbrefill))))) 
                                                    & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_eentry))
                                              : ((IData)(vlSelf->__VdfgTmp_hb44e37ca__0)
                                                  ? 
                                                 (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__ertn_flush))) 
                                                   & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_era) 
                                                  | ((- (IData)((IData)(vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_h52ebff71__0))) 
                                                     & ((IData)(4U) 
                                                        + 
                                                        vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r[0U])))
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__br_target_inst_req_state))
                                                   ? vlSelf->__PVT__cpu__DOT__if_stage__DOT__br_target_inst_req_buffer
                                                   : 
                                                  (((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush) 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_valid))
                                                    ? vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush_target
                                                    : 
                                                   ((((IData)(vlSelf->__PVT__cpu__DOT__btb_en) 
                                                      & (IData)(vlSelf->__PVT__cpu__DOT__btb_taken)) 
                                                     | (IData)(vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_ha3d303c7__0))
                                                     ? vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_ret_pc_t
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc)))))));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_allowin 
        = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_valid)) 
                 | ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_ready_go) 
                    & (IData)(vlSelf->__PVT__cpu__DOT__ds_allowin))));
    if (vlSelf->__PVT__cpu__DOT__icacop_op_en) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__real_offset 
            = (0xfU & vlSelf->__PVT__cpu__DOT__data_vaddr);
        vlSelf->__PVT__cpu__DOT__icache__DOT__real_index 
            = (0xffU & (vlSelf->__PVT__cpu__DOT__data_vaddr 
                        >> 4U));
    } else {
        vlSelf->__PVT__cpu__DOT__icache__DOT__real_offset 
            = (0xfU & vlSelf->__PVT__cpu__DOT__fetch_pc);
        vlSelf->__PVT__cpu__DOT__icache__DOT__real_index 
            = (0xffU & (vlSelf->__PVT__cpu__DOT__fetch_pc 
                        >> 4U));
    }
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_excp_adef 
        = (IData)((0U != (3U & vlSelf->__PVT__cpu__DOT__fetch_pc)));
    vlSelf->__PVT__cpu__DOT__inst_valid = ((~ ((IData)(vlSelf->__PVT__cpu__DOT__idle_flush) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__idle_lock))) 
                                           & (((~ ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_excp_adef) 
                                                   | ((~ 
                                                       ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_req_state) 
                                                        | (4U 
                                                           == (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__br_target_inst_req_state)))) 
                                                      & (IData)(vlSelf->__PVT__cpu__DOT__inst_tlb_excp_cancel_req)))) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_allowin)) 
                                              | ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush))));
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__addra 
        = (((- (IData)(((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok) 
                        | ((IData)(vlSelf->__PVT__cpu__DOT__icacop_op_en) 
                           & (IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h00af7739__0))))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)(((8U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                          | (0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_addra[0U] 
        = (((- (IData)(((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok) 
                        | ((IData)(vlSelf->__PVT__cpu__DOT__icacop_op_en) 
                           & (IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h00af7739__0))))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)(((8U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                          | (0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_addra[1U] 
        = (((- (IData)(((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok) 
                        | ((IData)(vlSelf->__PVT__cpu__DOT__icacop_op_en) 
                           & (IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h00af7739__0))))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)(((8U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state)) 
                          | (0x10U == (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__main_state))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[0U][0U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[0U][1U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[0U][2U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[0U][3U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[1U][0U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[1U][1U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[1U][2U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[1U][3U] 
        = (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))) 
            & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__real_index)) 
           | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok))))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index)));
    vlSelf->__PVT__cpu__DOT__fetch_en = ((IData)(vlSelf->__PVT__cpu__DOT__inst_valid) 
                                         & (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok));
    vlSelf->__PVT__cpu__DOT__icache__DOT__req_or_inst_valid 
        = ((IData)(vlSelf->__PVT__cpu__DOT__icacop_op_en) 
           | (IData)(vlSelf->__PVT__cpu__DOT__inst_valid));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_ready_go 
        = (((IData)(vlSelf->__PVT__cpu__DOT__inst_valid) 
            | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_excp_adef)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__inst_addr_ok));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__to_fs_valid 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__reset)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_ready_go));
}

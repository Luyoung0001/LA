// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_verilator_top.h"

VL_ATTR_COLD void Vverilator_top_verilator_top___stl_sequent__TOP__verilator_top__1(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___stl_sequent__TOP__verilator_top__1\n"); );
    // Init
    CData/*2:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h95ddbc08__0 = 0;
    CData/*1:0*/ cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0;
    cpu__DOT__id_stage__DOT____VdfgTmp_h9d620467__0 = 0;
    CData/*0:0*/ cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0;
    cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0 = 0;
    CData/*0:0*/ cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0;
    cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0 = 0;
    VlWide<4>/*127:0*/ __Vtemp_ha6ad9ad8__0;
    VlWide<4>/*127:0*/ __Vtemp_ha6ad9b0e__0;
    VlWide<4>/*127:0*/ __Vtemp_hc9dcc500__0;
    VlWide<4>/*127:0*/ __Vtemp_hc9dcc4c6__0;
    // Body
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s0_ppn 
        = ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h5fe09d4e__0)
            ? vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn1
           [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]
            : vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn0
           [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp = 
        (1U & (vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[5U] 
               | (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp_ale)));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[0U] 
        = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__exe_result)) 
                    << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__exe_result))));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[1U] 
        = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__exe_result)) 
                     << 0x20U) | (QData)((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__exe_result))) 
                   >> 0x20U));
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0[2U] 
        = (1U & (IData)(((0U != (0xc000400U & vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r[4U])) 
                         | (IData)(vlSelf->__PVT__cpu__DOT__es_div_enable))));
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
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__da_mode 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__csr_pg)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__csr_da));
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__csr_da)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__csr_pg));
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
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp = 
        (1U & ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp_ipe) 
               | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_break) 
                     | ((vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r[2U] 
                         >> 4U) | ((~ (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid)) 
                                   | (IData)(vlSelf->__PVT__cpu__DOT__has_int)))))));
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
    vlSelf->__PVT__cpu__DOT__inst_uncache_en = (1U 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans__DOT__da_mode) 
                                                    & (0U 
                                                       == 
                                                       (0x60U 
                                                        & vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd))) 
                                                   | (((IData)(vlSelf->__PVT__cpu__DOT__inst_dmw0_en) 
                                                       & (0U 
                                                          == 
                                                          (0x30U 
                                                           & vlSelf->__PVT__cpu__DOT__csr_dmw0))) 
                                                      | (((IData)(vlSelf->__PVT__cpu__DOT__inst_dmw1_en) 
                                                          & (0U 
                                                             == 
                                                             (0x30U 
                                                              & vlSelf->__PVT__cpu__DOT__csr_dmw1))) 
                                                         | (((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_trans_en) 
                                                             & (0U 
                                                                == 
                                                                ((IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h5fe09d4e__0)
                                                                  ? 
                                                                 vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat1
                                                                 [
                                                                 (0xfU 
                                                                  & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]
                                                                  : 
                                                                 vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat0
                                                                 [
                                                                 (0xfU 
                                                                  & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))]))) 
                                                            | vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_disable_cache)))));
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
    if (vlSelf->__PVT__cpu__DOT__data_addr_trans_en) {
        cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0 
            = (1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__data_tlb_v)));
        vlSelf->__PVT__cpu__DOT__data_tag = (0xfffffU 
                                             & ((0xcU 
                                                 == 
                                                 vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                                 [(0xfU 
                                                   & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out))])
                                                 ? vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s1_ppn
                                                 : 
                                                ((0xffc00U 
                                                  & vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s1_ppn) 
                                                 | (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_paddr 
                                                       >> 0xcU)))));
    } else {
        cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0 = 0U;
        vlSelf->__PVT__cpu__DOT__data_tag = (0xfffffU 
                                             & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_paddr 
                                                >> 0xcU));
    }
    vlSelf->__PVT__cpu__DOT__inst_tlb_excp_cancel_req 
        = ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_tlbr) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_pif) 
              | (IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_ppi)));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_uncache_en 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_dcacop)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__data_uncache_en));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil 
        = (((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
             >> 6U) | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                       >> 0x15U)) & (IData)(cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis 
        = ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
            >> 0xaU) & (IData)(cpu__DOT__mem_stage__DOT____VdfgTmp_h4e628a03__0));
    vlSelf->__PVT__cpu__DOT__icache__DOT__real_tag 
        = (0xfffffU & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_icacop)
                        ? vlSelf->__PVT__cpu__DOT__data_tag
                        : ((IData)(vlSelf->__PVT__cpu__DOT__inst_addr_trans_en)
                            ? ((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps
                                [(0xfU & (IData)(vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out))])
                                ? vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s0_ppn
                                : ((0xffc00U & vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s0_ppn) 
                                   | (0x3ffU & (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_paddr 
                                                >> 0xcU))))
                            : (vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_paddr 
                               >> 0xcU))));
    vlSelf->__PVT__cpu__DOT__sc_cancel_req = (((vlSelf->__PVT__cpu__DOT__u_csr__DOT__lladdr 
                                                != 
                                                ((vlSelf->__PVT__cpu__DOT__data_tag 
                                                  << 8U) 
                                                 | (0xffU 
                                                    & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[6U] 
                                                        << 5U) 
                                                       | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[5U] 
                                                          >> 0x1bU))))) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__data_uncache_en)) 
                                              & ((vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[4U] 
                                                  >> 9U) 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__access_mem)));
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_hb6042862__0 
        = (vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__output_buffer 
           & (vlSelf->__PVT__cpu__DOT__data_tag == 
              (0xfffffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__output_buffer 
                           >> 1U))));
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h064d00c1__0 
        = (vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__output_buffer 
           & (vlSelf->__PVT__cpu__DOT__data_tag == 
              (0xfffffU & (vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__output_buffer 
                           >> 1U))));
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_excp 
        = ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp) 
           | (IData)(vlSelf->__PVT__cpu__DOT__inst_tlb_excp_cancel_req));
    vlSelf->__PVT__cpu__DOT__data_tlb_excp_cancel_req 
        = ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil) 
              | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis) 
                 | ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi) 
                    | (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme)))));
    vlSelf->cpu__DOT__icache__DOT____VdfgTmp_he890b2ef__0 
        = (vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__output_buffer 
           & (vlSelf->__PVT__cpu__DOT__icache__DOT__real_tag 
              == (0xfffffU & (vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__output_buffer 
                              >> 1U))));
    vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h5d80e202__0 
        = (vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__output_buffer 
           & (vlSelf->__PVT__cpu__DOT__icache__DOT__real_tag 
              == (0xfffffU & (vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__output_buffer 
                              >> 1U))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_hit = 
        (((IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_hb6042862__0) 
          << 1U) | (IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h064d00c1__0));
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
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cancel_req 
        = ((IData)(vlSelf->__PVT__cpu__DOT__sc_cancel_req) 
           | (IData)(vlSelf->__PVT__cpu__DOT__data_tlb_excp_cancel_req));
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp = 
        (1U & ((IData)(vlSelf->__PVT__cpu__DOT__data_tlb_excp_cancel_req) 
               | (vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r[2U] 
                  >> 0xdU)));
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
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_hit = 
        (((IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_he890b2ef__0) 
          << 1U) | (IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h5d80e202__0));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2_hit_wr 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2) 
           & (0U != (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_hit)));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__replace_way 
        = (((- (IData)((IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_hdb34a219__0))) 
            & ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset) 
                      << 1U)) | (1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset))))) 
           | (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2))) 
               & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_hit)) 
              | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_dcacop))))) 
                 & ((0U != (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__invalid_way))
                     ? (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__invalid_way)
                     : ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__lfsr__DOT__r_lfsr) 
                               >> 5U)) | (1U & (~ ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__lfsr__DOT__r_lfsr) 
                                                   >> 6U))))))));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cache_hit 
        = ((~ ((IData)(vlSelf->__PVT__cpu__DOT__data_uncache_en) 
               | (IData)(vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h9ac96f4b__0))) 
           & (0U != (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__way_hit)));
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
    vlSelf->__PVT__cpu__DOT__icache__DOT__replace_way 
        = (((- (IData)((IData)(vlSelf->cpu__DOT__icache__DOT____VdfgTmp_hf6d3044e__0))) 
            & ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_offset) 
                      << 1U)) | (1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_offset))))) 
           | (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode2))) 
               & (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_hit)) 
              | ((- (IData)((1U & (~ (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_icacop))))) 
                 & ((0U != (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__invalid_way))
                     ? (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__invalid_way)
                     : ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__lfsr__DOT__r_lfsr) 
                               >> 5U)) | (1U & (~ ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__lfsr__DOT__r_lfsr) 
                                                   >> 6U))))))));
    vlSelf->__PVT__cpu__DOT__icache__DOT__cache_hit 
        = ((~ ((IData)(vlSelf->__PVT__cpu__DOT__inst_uncache_en) 
               | ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode0) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode1) 
                     | (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode2))))) 
           & (0U != (IData)(vlSelf->__PVT__cpu__DOT__icache__DOT__way_hit)));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__uncache_wr 
        = ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_uncache_en) 
           & ((~ ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode1) 
                  | (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2_hit_wr))) 
              & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_op)));
    vlSelf->__PVT__cpu__DOT__dcache__DOT__replace_d 
        = (0U != ((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__replace_way) 
                  & (vlSelf->__PVT__cpu__DOT__dcache__DOT__way_d_reg
                     [vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index] 
                     | ((- (IData)((((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index) 
                                     == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index)) 
                                    & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state)))) 
                        & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way)))));
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
    vlSelf->__PVT__cpu__DOT__ms_allowin = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid)) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_ready_go)));
    vlSelf->__PVT__cpu__DOT__ms_to_ws_valid = ((IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_ready_go));
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_ready_go 
        = ((IData)(vlSelf->__PVT__cpu__DOT__inst_data_ok) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_buff_enable) 
              | (IData)(vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_excp)));
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
    vlSelf->__PVT__cpu__DOT__data_addr_ok = (((IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_idle2lookup) 
                                              & (1U 
                                                 == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state))) 
                                             | ((2U 
                                                 == (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state)) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__dcache__DOT__main_lookup2lookup)));
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
    vlSelf->__PVT__cpu__DOT__es_to_ms_valid = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_valid) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_ready_go));
    cpu__DOT__exe_stage__DOT____VdfgTmp_he0d16426__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_ready_go) 
           & (IData)(vlSelf->__PVT__cpu__DOT__ms_allowin));
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
}

VL_ATTR_COLD void Vverilator_top_verilator_top___ctor_var_reset(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_inst_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_inst_we = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu_inst_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu_inst_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu_inst_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu_data_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_data_we = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu_data_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu_data_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu_data_rdata = VL_RAND_RESET_I(32);
    vlSelf->debug_wb_pc = VL_RAND_RESET_I(32);
    vlSelf->debug_wb_rf_we = VL_RAND_RESET_I(4);
    vlSelf->debug_wb_rf_wnum = VL_RAND_RESET_I(5);
    vlSelf->debug_wb_rf_wdata = VL_RAND_RESET_I(32);
    vlSelf->debug_wb_inst = VL_RAND_RESET_I(32);
    vlSelf->csr_crmd_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_prmd_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_ectl_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_estat_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_era_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_badv_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_eentry_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tlbidx_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tlbehi_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tlbelo0_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tlbelo1_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_asid_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_save0_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_save1_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_save2_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_save3_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tid_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tcfg_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tval_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_ticlr_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_llbctl_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_tlbrentry_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_dmw0_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_dmw1_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_pgdl_diff = VL_RAND_RESET_I(32);
    vlSelf->csr_pgdh_diff = VL_RAND_RESET_I(32);
    vlSelf->__PVT__data_sram_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__data_sram_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__data_sram_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__data_sram_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__data_sram_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__wire_arid = VL_RAND_RESET_I(4);
    vlSelf->__PVT__wire_araddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__wire_arlen = VL_RAND_RESET_I(8);
    vlSelf->__PVT__wire_arsize = VL_RAND_RESET_I(3);
    vlSelf->__PVT__wire_arvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_arready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_rid = VL_RAND_RESET_I(4);
    vlSelf->__PVT__wire_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__wire_rresp = VL_RAND_RESET_I(2);
    vlSelf->__PVT__wire_rlast = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_rvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_rready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_awaddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__wire_awlen = VL_RAND_RESET_I(8);
    vlSelf->__PVT__wire_awsize = VL_RAND_RESET_I(3);
    vlSelf->__PVT__wire_awvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_awready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__wire_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__wire_wlast = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_wvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_wready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_bresp = VL_RAND_RESET_I(2);
    vlSelf->__PVT__wire_bvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_bready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_bid = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu_inst_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_inst_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_inst_size = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu_inst_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu_inst_addr_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_inst_data_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_data_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_data_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_data_size = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu_data_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu_data_addr_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_data_data_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ds_allowin = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__es_allowin = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ms_allowin = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__fs_to_ds_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ds_to_es_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__es_to_ms_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ms_to_ws_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ws_csr_ecode = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__ds_timer_64 = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__rd_csr_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__ws_llbit = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__has_int = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_wr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__excp_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ertn_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idle_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__es_div_enable = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mul_result = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__tlbrd_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlbr_tlbelo0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__tlbr_tlbelo1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__tlbr_tlbidx = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__invtlb_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_tlb_v = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_tlb_plv = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlbfill_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlbwr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__excp_tlbrefill = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_pg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_da = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_dmw0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_dmw1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_plv = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__inst_addr_trans_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_addr_trans_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cacop_op_mode_di = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icacop_op_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcacop_op_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache_unbusy = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__fetch_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__fetch_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_ret_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__btb_taken = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__btb_add_entry = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_operate_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_pre_error = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_target_error = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_right_orien = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb_right_target = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__data_fetch = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(350, vlSelf->__PVT__cpu__DOT__ds_to_es_bus);
    VL_RAND_RESET_W(425, vlSelf->__PVT__cpu__DOT__es_to_ms_bus);
    vlSelf->__PVT__cpu__DOT__inst_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_addr_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_data_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__inst_rd_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_rd_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__inst_ret_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_ret_last = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_wr_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_wr_type = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__inst_wr_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__inst_wr_wstrb = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(128, vlSelf->__PVT__cpu__DOT__inst_wr_data);
    vlSelf->__PVT__cpu__DOT__inst_uncache_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_tlb_excp_cancel_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_dmw0_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_dmw1_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_vaddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__data_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_op = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_size = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__data_tag = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__data_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__data_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__data_addr_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_rd_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_rd_type = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__data_rd_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__data_ret_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_ret_last = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_wr_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_wr_type = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(128, vlSelf->__PVT__cpu__DOT__data_wr_data);
    vlSelf->__PVT__cpu__DOT__data_uncache_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_dmw0_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_dmw1_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_tlb_excp_cancel_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__sc_cancel_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__preld_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__commit_inst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_cnt_inst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_timer_64 = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__cmt_inst_ld_en = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__cmt_ld_paddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_ld_vaddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_inst_st_en = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__cmt_st_paddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_st_vaddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_st_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_csr_rstat_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_csr_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_wdest = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__cmt_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_inst = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__cmt_excp_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_ertn = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_csr_ecode = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__cmt_tlbfill_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__cmt_rand_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__trap = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__trap_code = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__cycleCnt = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__instrCnt = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_ready_go = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_allowin = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__to_fs_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_ready_go = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__pfs_excp_adef = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_tlbr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_pif = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_ppi = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_excp_num = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_rd_buff = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__inst_buff_enable = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_delay = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_go_dirt = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__idle_lock = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_ret_pc_t = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__fs_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_req_buffer = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__flush_inst_req_state = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__br_target_inst_req_buffer = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__br_target_inst_req_state = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_buffer = VL_RAND_RESET_Q(38);
    vlSelf->__PVT__cpu__DOT__if_stage__DOT__btb_lock_en = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_h52ebff71__0 = 0;
    vlSelf->cpu__DOT__if_stage__DOT____VdfgTmp_ha3d303c7__0 = 0;
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_ready_go = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_to_ds_bus_r);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__btb_pre_error_flush_target = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__src2_is_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_mask = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__mem_sign_exted = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__dst_is_rj = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__csr_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ds_imm = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__op_31_26_d = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__op_25_22_d = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__op_19_15_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rd_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rk_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_add_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sub_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slt = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nor = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_and = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_or = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xor = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_lu12i_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_addi_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slti = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sltui = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddi = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_pcaddu12i = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_andi = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ori = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_xori = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mul_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mulh_wu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_div_wu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_mod_wu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_slli_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srli_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srai_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sll_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_srl_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sra_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ll_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_sc_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_b = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_bu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_h = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_hu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ld_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_b = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_h = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_st_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_syscall = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_break = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrrd = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_csrwr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ertn = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvl_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_rdcntvh_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_idle = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbsrch = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbrd = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbwr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_tlbfill = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_invtlb = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_cacop = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid_cacop = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_preld = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_dbar = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_ibar = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_nop = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__need_ui5 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_raddr2 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rf_rdata2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__pipeline_no_empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_eq_rd = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_enable = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__ms_forward_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__excp_ipe = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__fs_excp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__branch_slot_cancel = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_jirl = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_need_reg_data = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__br_to_btb = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rj = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__id_stage__DOT__inst_need_rkd = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hfea85cf8__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hbba4846b__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1c4a3e54__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h19962199__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h38353e9a__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h6983a416__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h1d0e0636__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h416d0694__0 = 0;
    VL_ZERO_RESET_W(65, vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h51300fe8__0);
    VL_ZERO_RESET_W(65, vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hef9191ce__0);
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hb469ad25__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hbc7c3b7a__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_haf287d09__0 = 0;
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_hac115781__0 = 0;
    VL_ZERO_RESET_W(65, vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_ha01d14c2__0);
    vlSelf->cpu__DOT__id_stage__DOT____VdfgTmp_h0663ec88__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__id_stage__DOT__u_regfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_ready_go = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__error_va = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(350, vlSelf->__PVT__cpu__DOT__exe_stage__DOT__ds_to_es_bus_r);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__forward_enable = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__excp_ale = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__es_flush_sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__access_mem = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__icacop_inst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__dcacop_inst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__preld_inst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__exe_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__u_alu__DOT__add_sub_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__u_alu__DOT__or_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__u_alu__DOT__lui_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__u_alu__DOT__adder_a = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__u_alu__DOT__adder_b = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exe_stage__DOT__u_alu__DOT__adder_cin = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignS = VL_RAND_RESET_Q(33);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__UnsignR = VL_RAND_RESET_Q(33);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__tmp_r = VL_RAND_RESET_Q(33);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__count = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__tmp_d = VL_RAND_RESET_Q(33);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__result_r = VL_RAND_RESET_Q(33);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__div_signed_buffer = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__x_31_buffer = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__y_31_buffer = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__real_div_signed = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__real_x_31 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__complete_delay = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_div__DOT__real_complete = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_mul__DOT__CalX = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__u_mul__DOT__CalY = VL_RAND_RESET_Q(33);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__u_mul__DOT__BoothRes[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__las__y = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__u_mul__DOT__SecStageCarry = VL_RAND_RESET_I(17);
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__u_mul__DOT__SecStageBoothRes[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->__PVT__cpu__DOT__u_mul__DOT__p = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_mul__DOT__SOut = VL_RAND_RESET_Q(64);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__firs__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__1__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__2__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__10__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__11__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__12__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__13__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__14__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__15__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__16__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__17__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__18__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__19__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__20__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__21__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__22__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__23__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__24__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__25__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__26__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__27__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__28__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__29__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__30__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__31__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__32__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__33__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__34__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__35__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__36__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__37__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__38__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData = VL_RAND_RESET_I(17);
    vlSelf->cpu__DOT__u_mul__DOT____Vlvbound_hff1e071f__0 = VL_RAND_RESET_Q(64);
    vlSelf->cpu__DOT__u_mul__DOT____VdfgTmp_hb9b19849__0 = 0;
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_ready_go = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(425, vlSelf->__PVT__cpu__DOT__mem_stage__DOT__es_to_ms_bus_r);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__ms_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__data_rd_buff = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__data_buff_enable = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__access_mem = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_tlbr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pil = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pis = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_pme = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__excp_ppi = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_byteLoaded = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__mem_halfLoaded = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_index = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__mem_stage__DOT__tmp_data_offset = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ws_valid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(493, vlSelf->__PVT__cpu__DOT__wb_stage__DOT__ms_to_ws_bus_r);
    VL_ZERO_RESET_W(69, vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_hdefe0a78__0);
    vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_h71ee0a69__0 = 0;
    vlSelf->cpu__DOT__wb_stage__DOT____VdfgTmp_h292b3a37__0 = 0;
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__crmd_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbehi_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tcfg_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__DMW0_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__DMW1_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_crmd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_prmd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ectl = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_estat = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_era = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_badv = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_eentry = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbidx = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbehi = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbelo1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_asid = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cpuid = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_save3 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tid = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tcfg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tval = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_cntc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_ticlr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_llbctl = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_tlbrentry = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_dmw1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdl = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_pgdh = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_brk = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__csr_disable_cache = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__timer_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__timer_64 = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__llbit = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__lladdr = VL_RAND_RESET_I(28);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_valid_wr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__tlbrd_invalid_wr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__u_csr__DOT__no_forward = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__u_csr__DOT____VdfgTmp_hce7fc8e0__0 = 0;
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__read_requst_state = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__read_respond_state = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__write_requst_state = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__rd_requst_can_receive = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__data_real_rd_size = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__inst_real_rd_size = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(128, vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__write_buffer_data);
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__write_buffer_num = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__axi_bridge__DOT__write_buffer_last = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s0_ppn = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__s1_ppn = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__w_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__w_e = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_g = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__r_e = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_vaddr_buffer = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_vaddr_buffer = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__inst_paddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__data_paddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__pg_mode = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__da_mode = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn[__Vi0] = VL_RAND_RESET_I(19);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_e[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid[__Vi0] = VL_RAND_RESET_I(10);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_g[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ps[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn0[__Vi0] = VL_RAND_RESET_I(20);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv0[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat0[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_d0[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v0[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_ppn1[__Vi0] = VL_RAND_RESET_I(20);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_plv1[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_mat1[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_d1[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_v1[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_fetch_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_vppn_r = VL_RAND_RESET_I(19);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_odd_page_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_asid_r = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_fetch_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_vppn_r = VL_RAND_RESET_I(19);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_asid_r = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match0 = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__match1 = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s0_odd_page_buffer = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__s1_odd_page_buffer = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match0__out = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____Vcellout__en_match1__out = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h5fe09d4e__0 = 0;
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT____VdfgTmp_h9c4ee013__0 = 0;
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__addr_trans__DOT__tlb_entry__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_op = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_index = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_tag = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_offset = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_uncache_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_icacop = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__request_buffer_cacop_op_mode = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_replace_way = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__miss_buffer_ret_num = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__ret_num_add_one = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_addra[__Vi0][__Vi1] = VL_RAND_RESET_I(8);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_dina[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_douta[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_ena[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__icache__DOT__way_bank_wea[__Vi0][__Vi1] = VL_RAND_RESET_I(4);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_addra[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_dina[__Vi0] = VL_RAND_RESET_I(21);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_douta[__Vi0] = VL_RAND_RESET_I(21);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_ena[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__way_tagv_wea[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_hit = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__cache_hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__way_load_word[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->__PVT__cpu__DOT__icache__DOT__way_data[__Vi0]);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__way_wr_en = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__replace_way = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__invalid_way = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__cacop_op_mode2_hit_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__lookup_way_hit_buffer = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__icache__DOT__real_offset = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__icache__DOT__real_tag = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__icache__DOT__real_index = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__icache__DOT__req_or_inst_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__icache__DOT__main_state = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__icache__DOT__rd_req_buffer = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__sel_one_invalid__in = VL_RAND_RESET_I(2);
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__wea = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__ena = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__dina = VL_RAND_RESET_I(21);
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__addra = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__icache__DOT____Vcellinp__tagv_ram_way__BRA__1__KET____DOT__u__wea = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__icache__DOT____VdfgTmp_hf6d3044e__0 = 0;
    vlSelf->cpu__DOT__icache__DOT____VdfgTmp_he890b2ef__0 = 0;
    vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h5d80e202__0 = 0;
    vlSelf->cpu__DOT__icache__DOT____VdfgTmp_h00af7739__0 = 0;
    vlSelf->__PVT__cpu__DOT__icache__DOT__lfsr__DOT__r_lfsr = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(21);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(21);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(21);
    }
    vlSelf->__PVT__cpu__DOT__icache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(21);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__way_d_reg[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_uncache_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_op = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_preld = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_size = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_index = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_tag = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_offset = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_uncache_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_dcacop = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__request_buffer_cacop_op_mode = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_replace_way = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__miss_buffer_ret_num = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__ret_num_add_one = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_index = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_way = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_offset = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_addra[__Vi0][__Vi1] = VL_RAND_RESET_I(8);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_dina[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_douta[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_ena[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__dcache__DOT__way_bank_wea[__Vi0][__Vi1] = VL_RAND_RESET_I(4);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_addra[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_dina[__Vi0] = VL_RAND_RESET_I(21);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_douta[__Vi0] = VL_RAND_RESET_I(21);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_ena[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__way_tagv_wea[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->__PVT__cpu__DOT__dcache__DOT__wr_match_way_bank[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_hit = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cache_hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__way_load_word[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->__PVT__cpu__DOT__dcache__DOT__way_data[__Vi0]);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__replace_d = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__replace_way = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__invalid_way = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__main_idle2lookup = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__main_lookup2lookup = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__uncache_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__uncache_wr_buffer = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__way_wr_en = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__refill_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2_hit_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cacop_op_mode2_hit_wr_buffer = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__preld_st_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__preld_ld_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__preld_ld_st_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__req_or_inst_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__lookup_way_hit_buffer = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__main_state = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__write_buffer_state = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__rd_req_buffer = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__dcache__DOT__cancel_req = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__wea = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__ena = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__dina = VL_RAND_RESET_I(21);
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__0__KET____DOT__u__addra = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__dcache__DOT____Vcellinp__tagv_ram_way__BRA__1__KET____DOT__u__wea = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h63343402__0 = 0;
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h9ac96f4b__0 = 0;
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h3175ceaa__0 = 0;
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h13703b6f__0 = 0;
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_hdb34a219__0 = 0;
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_hb6042862__0 = 0;
    vlSelf->cpu__DOT__dcache__DOT____VdfgTmp_h064d00c1__0 = 0;
    vlSelf->__PVT__cpu__DOT__dcache__DOT__lfsr__DOT__r_lfsr = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__0__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__0__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__1__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__2__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__data_ram_way__BRA__1__KET____DOT__data_ram_bank__BRA__3__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(21);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(21);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__mem_reg[__Vi0] = VL_RAND_RESET_I(21);
    }
    vlSelf->__PVT__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__output_buffer = VL_RAND_RESET_I(21);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__btb__DOT__btb_pc[__Vi0] = VL_RAND_RESET_I(30);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__btb__DOT__btb_target[__Vi0] = VL_RAND_RESET_I(30);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__btb__DOT__btb_counter[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_valid = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__btb__DOT__ras_pc[__Vi0] = VL_RAND_RESET_I(30);
    }
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_valid = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_pc_r = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__btb__DOT__fetch_en_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__btb__DOT__ras[__Vi0] = VL_RAND_RESET_I(30);
    }
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_ptr = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_rd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_match = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_match_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_random_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_random_index = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_add_entry_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_add_entry_index_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_add_entry_dec = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__btb__DOT__ras_add_entry_index = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_r = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_untaken_entry_t = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__btb__DOT__btb_add_entry_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__btb__DOT__fcsr = VL_RAND_RESET_I(6);
    vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__btb__DOT__sel_one_untaken_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__one__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__btb__DOT__sel_one_btb_entry__DOT__coder__DOT__two__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT____Vcellinp__one__in = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__one__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__btb__DOT__encode_btb_match__DOT__two__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__btb__DOT__encode_ras_match__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->__PVT__axi_ram__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__PVT__axi_ram__DOT__state1 = VL_RAND_RESET_I(4);
    vlSelf->__VdfgTmp_hb44e37ca__0 = 0;
    vlSelf->__VdfgTmp_h3a64b587__0 = 0;
    vlSelf->__VdfgTmp_h6802c383__0 = 0;
    vlSelf->__VdfgTmp_ha0f10682__0 = 0;
    vlSelf->__VdfgTmp_h3a96ee69__0 = 0;
    vlSelf->__VdfgTmp_h4dc072c1__0 = 0;
    vlSelf->__VdfgTmp_h2824a371__0 = 0;
    vlSelf->__VdfgTmp_h386fae7d__0 = 0;
    vlSelf->__VdfgTmp_hce0c4684__0 = 0;
    vlSelf->__VdfgTmp_ha7233986__0 = 0;
    vlSelf->__VdfgTmp_h2b5e8621__0 = 0;
    vlSelf->__VdfgTmp_h81e7e4c9__0 = 0;
    vlSelf->__VdfgTmp_hb231f61d__0 = 0;
    vlSelf->__VdfgTmp_hf2d875ee__0 = 0;
    vlSelf->__VdfgTmp_hf2232012__0 = 0;
    vlSelf->__VdfgTmp_he2772e6a__0 = 0;
    vlSelf->__VdfgTmp_h88048788__0 = 0;
    vlSelf->__VdfgTmp_h3f7dfeb7__0 = 0;
    vlSelf->__VdfgTmp_ha011a01e__0 = 0;
    vlSelf->__VdfgTmp_h6525c922__0 = 0;
    vlSelf->__VdfgTmp_h75708bee__0 = 0;
    vlSelf->__VdfgTmp_he92a5bc9__0 = 0;
    vlSelf->__VdfgTmp_h1e27bdaa__0 = 0;
    vlSelf->__VdfgTmp_hd67f03ee__0 = 0;
    vlSelf->__VdfgTmp_ha83e7e37__0 = 0;
    vlSelf->__VdfgTmp_h4b4d1d0f__0 = 0;
    vlSelf->__VdfgTmp_h08d4b213__0 = 0;
    vlSelf->__VdfgTmp_h65b1658b__0 = 0;
    vlSelf->__VdfgTmp_hbbbab294__0 = 0;
    vlSelf->__VdfgTmp_hc8484373__0 = 0;
    vlSelf->__VdfgTmp_h9f9dcade__0 = 0;
    vlSelf->__VdfgTmp_hac1c8e5b__0 = 0;
    vlSelf->__VdfgTmp_hb3c45e3f__0 = 0;
    vlSelf->__VdfgTmp_h28de6bba__0 = 0;
    vlSelf->__VdfgTmp_h281e3aa3__0 = 0;
    vlSelf->__VdfgTmp_h287d9e6a__0 = 0;
    vlSelf->__VdfgTmp_h29902bb6__0 = 0;
    vlSelf->__VdfgTmp_h282df2b4__0 = 0;
    vlSelf->__VdfgTmp_h28447f91__0 = 0;
    vlSelf->__VdfgTmp_h2f17bd15__0 = 0;
    vlSelf->__VdfgTmp_h2b34b778__0 = 0;
    vlSelf->__VdfgTmp_h2846d38b__0 = 0;
    vlSelf->__VdfgTmp_h283518d9__0 = 0;
    vlSelf->__VdfgTmp_h28d0af6a__0 = 0;
    vlSelf->__VdfgTmp_h28d16f34__0 = 0;
    vlSelf->__VdfgTmp_h28b5f3c3__0 = 0;
    vlSelf->__VdfgTmp_h28b1ebfc__0 = 0;
    vlSelf->__VdfgTmp_h2961036f__0 = 0;
    vlSelf->__VdfgTmp_hef3bf6e7__0 = 0;
    vlSelf->__VdfgTmp_hef3821b5__0 = 0;
    vlSelf->__VdfgTmp_hef7d2fec__0 = 0;
    vlSelf->__VdfgTmp_hd0f0d5da__0 = 0;
    vlSelf->__VdfgTmp_hd0f3f017__0 = 0;
    vlSelf->__VdfgTmp_hea1021fd__0 = 0;
    vlSelf->__VdfgTmp_hea79f5b1__0 = 0;
    vlSelf->__VdfgTmp_hef7d1ebb__0 = 0;
    vlSelf->__VdfgTmp_hef734879__0 = 0;
    vlSelf->__VdfgTmp_hec9625f7__0 = 0;
    vlSelf->__VdfgTmp_hef1da2f3__0 = 0;
    vlSelf->__VdfgTmp_h86498323__0 = 0;
    vlSelf->__VdfgTmp_h144a4430__0 = 0;
    vlSelf->__VdfgTmp_h1470b1c1__0 = 0;
    vlSelf->__VdfgTmp_h14758488__0 = 0;
    vlSelf->__VdfgTmp_h1449ec64__0 = 0;
    vlSelf->__VdfgTmp_h147b4aa2__0 = 0;
    vlSelf->__VdfgTmp_h295efed9__0 = 0;
    vlSelf->__VdfgTmp_h1492eda8__0 = 0;
    vlSelf->__VdfgTmp_h1478ca08__0 = 0;
    vlSelf->__VdfgTmp_h147c90ec__0 = 0;
    vlSelf->__VdfgTmp_h14673d06__0 = 0;
    vlSelf->__VdfgTmp_h1462d6b9__0 = 0;
    vlSelf->__VdfgTmp_h146f23bf__0 = 0;
    vlSelf->__VdfgTmp_h145a0ce5__0 = 0;
    vlSelf->__VdfgTmp_h14462e1a__0 = 0;
    vlSelf->__VdfgTmp_h1485ccbd__0 = 0;
    vlSelf->__VdfgTmp_h14afccdb__0 = 0;
    vlSelf->__VdfgTmp_h1468056a__0 = 0;
    vlSelf->__VdfgTmp_h14940457__0 = 0;
    vlSelf->__VdfgTmp_h1490813d__0 = 0;
    vlSelf->__VdfgTmp_h147e8bf1__0 = 0;
    vlSelf->__VdfgTmp_h147a4322__0 = 0;
    vlSelf->__VdfgTmp_h1427ccc7__0 = 0;
    vlSelf->__VdfgTmp_h14219459__0 = 0;
    vlSelf->__VdfgTmp_h144d61b4__0 = 0;
    vlSelf->__VdfgTmp_h14924f66__0 = 0;
    vlSelf->__VdfgTmp_h149ff3f7__0 = 0;
    vlSelf->__VdfgTmp_h149b35b7__0 = 0;
    vlSelf->__VdfgTmp_h145f01b1__0 = 0;
    vlSelf->__VdfgTmp_h145b0fca__0 = 0;
    vlSelf->__VdfgTmp_h88130675__0 = 0;
    vlSelf->__VdfgTmp_h287669a1__0 = 0;
    vlSelf->__VdfgTmp_h284b4e24__0 = 0;
    vlSelf->__VdfgTmp_h2b2d3ac1__0 = 0;
    vlSelf->__VdfgTmp_h2b22ba23__0 = 0;
    vlSelf->__VdfgTmp_h2b26b937__0 = 0;
    vlSelf->__VdfgTmp_h2b39d584__0 = 0;
    vlSelf->__VdfgTmp_h2b9f81d9__0 = 0;
    vlSelf->__VdfgTmp_h2b92025f__0 = 0;
    vlSelf->__VdfgTmp_h2b9503ed__0 = 0;
    vlSelf->__VdfgTmp_h2b227c39__0 = 0;
    vlSelf->__VdfgTmp_h2b2ff7d2__0 = 0;
    vlSelf->__VdfgTmp_h284bb0ae__0 = 0;
    vlSelf->__VdfgTmp_h2870c5f6__0 = 0;
    vlSelf->__VdfgTmp_h2872c95d__0 = 0;
    vlSelf->__VdfgTmp_h2bbd3cde__0 = 0;
    vlSelf->__VdfgTmp_h2b8ddfe0__0 = 0;
    vlSelf->__VdfgTmp_h286f7fb9__0 = 0;
    vlSelf->__VdfgTmp_h2bd4a660__0 = 0;
    vlSelf->__VdfgTmp_h2bd0af7c__0 = 0;
    vlSelf->__VdfgTmp_h2bd66e9a__0 = 0;
    vlSelf->__VdfgTmp_h2bd25251__0 = 0;
    vlSelf->__VdfgTmp_h2b9f70b0__0 = 0;
    vlSelf->__VdfgTmp_h28475190__0 = 0;
    vlSelf->__VdfgTmp_h28431d65__0 = 0;
    vlSelf->__VdfgTmp_h28610961__0 = 0;
    vlSelf->__VdfgTmp_h286d4908__0 = 0;
    vlSelf->__VdfgTmp_h2b8acf86__0 = 0;
    vlSelf->__VdfgTmp_h2b9506da__0 = 0;
    vlSelf->__VdfgTmp_h2b9112e1__0 = 0;
    vlSelf->__VdfgTmp_h21b09c90__0 = 0;
    vlSelf->__VdfgTmp_hd654fdc0__0 = 0;
    vlSelf->__VdfgTmp_hd64bffee__0 = 0;
    vlSelf->__VdfgTmp_hd64efe69__0 = 0;
    vlSelf->__VdfgTmp_hd72442ad__0 = 0;
    vlSelf->__VdfgTmp_hd71b4a8a__0 = 0;
    vlSelf->__VdfgTmp_hd65c44e5__0 = 0;
    vlSelf->__VdfgTmp_hd67691e4__0 = 0;
    vlSelf->__VdfgTmp_hd66a0d7d__0 = 0;
    vlSelf->__VdfgTmp_hd66f5582__0 = 0;
    vlSelf->__VdfgTmp_hd666047e__0 = 0;
    vlSelf->__VdfgTmp_hd638d239__0 = 0;
    vlSelf->__VdfgTmp_ha60326f2__0 = 0;
    vlSelf->__VdfgTmp_h2991042b__0 = 0;
    vlSelf->__VdfgTmp_h28667139__0 = 0;
    vlSelf->__VdfgTmp_h29e8ee51__0 = 0;
    vlSelf->__VdfgTmp_h29c04841__0 = 0;
    vlSelf->__VdfgTmp_h29f565de__0 = 0;
    vlSelf->__VdfgTmp_h29ed2521__0 = 0;
    vlSelf->__VdfgTmp_h284c4815__0 = 0;
    vlSelf->__VdfgTmp_h2b42431a__0 = 0;
    vlSelf->__VdfgTmp_h28a85f11__0 = 0;
    vlSelf->__VdfgTmp_h28689c53__0 = 0;
    vlSelf->__VdfgTmp_h2678667e__0 = 0;
    vlSelf->__VdfgTmp_h263ed55f__0 = 0;
    vlSelf->__VdfgTmp_h2865ac30__0 = 0;
    vlSelf->__VdfgTmp_h29829d30__0 = 0;
    vlSelf->__VdfgTmp_h2916341e__0 = 0;
    vlSelf->__VdfgTmp_h8651482e__0 = 0;
    vlSelf->__VdfgTmp_h86e948c6__0 = 0;
    vlSelf->__VdfgTmp_hd0d3d28e__0 = 0;
    vlSelf->__Vdly__cpu__DOT__u_csr__DOT__csr_crmd = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__cpu__DOT__u_csr__DOT__timer_en = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__u_csr__DOT__csr_tval = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__cpu__DOT__axi_bridge__DOT__read_requst_state = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__axi_bridge__DOT__write_requst_state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__wire_wlast = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_bready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__axi_bridge__DOT__write_buffer_num = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(128, vlSelf->__Vdly__cpu__DOT__axi_bridge__DOT__write_buffer_data);
    vlSelf->__Vdlyvdim0__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn__v0 = 0;
    vlSelf->__Vdlyvval__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn__v0 = VL_RAND_RESET_I(19);
    vlSelf->__Vdlyvset__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_vppn__v0 = 0;
    vlSelf->__Vdlyvdim0__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid__v0 = 0;
    vlSelf->__Vdlyvval__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid__v0 = VL_RAND_RESET_I(10);
    vlSelf->__Vdlyvset__cpu__DOT__addr_trans__DOT__tlb_entry__DOT__tlb_asid__v0 = 0;
    vlSelf->__Vdly__cpu__DOT__icache__DOT__main_state = VL_RAND_RESET_I(5);
    vlSelf->__Vdly__cpu__DOT__icache__DOT__request_buffer_icacop = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__dcache__DOT__main_state = VL_RAND_RESET_I(5);
    vlSelf->__Vdly__cpu__DOT__dcache__DOT__write_buffer_state = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvdim0__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__mem_reg__v0 = 0;
    vlSelf->__Vdlyvval__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__mem_reg__v0 = VL_RAND_RESET_I(21);
    vlSelf->__Vdlyvset__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__0__KET____DOT__u__DOT__mem_reg__v0 = 0;
    vlSelf->__Vdlyvdim0__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__mem_reg__v0 = 0;
    vlSelf->__Vdlyvval__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__mem_reg__v0 = VL_RAND_RESET_I(21);
    vlSelf->__Vdlyvset__cpu__DOT__dcache__DOT__tagv_ram_way__BRA__1__KET____DOT__u__DOT__mem_reg__v0 = 0;
    vlSelf->__Vdly__wire_arready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_awready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_wready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_bvalid = VL_RAND_RESET_I(1);
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_verilator_top.h"

VL_ATTR_COLD void Vverilator_top_verilator_top___stl_sequent__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___stl_sequent__TOP__verilator_top__0\n"); );
    // Init
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0;
    cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0 = 0;
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0;
    cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0 = 0;
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0;
    cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0 = 0;
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0;
    cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0 = 0;
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_hb75ab56b__0;
    cpu__DOT__idu__DOT____VdfgTmp_hb75ab56b__0 = 0;
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_ha7c13be7__0;
    cpu__DOT__idu__DOT____VdfgTmp_ha7c13be7__0 = 0;
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h64c8ed36__0;
    cpu__DOT__idu__DOT____VdfgTmp_h64c8ed36__0 = 0;
    CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_ha4228d15__0;
    cpu__DOT__idu__DOT____VdfgTmp_ha4228d15__0 = 0;
    CData/*0:0*/ cpu__DOT__exu__DOT____VdfgTmp_hf84f9b29__0;
    cpu__DOT__exu__DOT____VdfgTmp_hf84f9b29__0 = 0;
    CData/*0:0*/ cpu__DOT__csr_o__DOT____VdfgTmp_hfdd17fff__0;
    cpu__DOT__csr_o__DOT____VdfgTmp_hfdd17fff__0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_hf6b25177__0;
    // Body
    vlSelf->debug_wb_pc = ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[3U] 
                            << 0x10U) | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                         >> 0x10U));
    vlSelf->debug_wb_rf_wnum = (0x1fU & (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
                                         >> 0x10U));
    vlSelf->debug_wb_rf_wdata = ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
                                  << 0x10U) | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[3U] 
                                               >> 0x10U));
    vlSelf->csr_crmd_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_crmd;
    vlSelf->csr_prmd_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_prmd;
    vlSelf->csr_ecfg_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_ecfg;
    vlSelf->csr_estat_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_estat;
    vlSelf->csr_era_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_era;
    vlSelf->csr_badv_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_badv;
    vlSelf->csr_eentry_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_eentry;
    vlSelf->csr_tlbidx_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx;
    vlSelf->csr_tlbehi_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbehi;
    vlSelf->csr_tlbelo0_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbelo0;
    vlSelf->csr_tlbelo1_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbelo1;
    vlSelf->csr_asid_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid;
    vlSelf->csr_save0_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save0;
    vlSelf->csr_save1_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save1;
    vlSelf->csr_save2_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save2;
    vlSelf->csr_save3_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save3;
    vlSelf->csr_tid_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tid;
    vlSelf->csr_tcfg_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tcfg;
    vlSelf->csr_tval_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tval;
    vlSelf->csr_ticlr_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_ticlr;
    vlSelf->csr_tlbrentry_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbrentry;
    vlSelf->csr_dmw0_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_dmw0;
    vlSelf->csr_dmw1_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_dmw1;
    vlSelf->csr_pgdl_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdl;
    vlSelf->csr_pgdh_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdh;
    vlSelf->__PVT__cpu__DOT__ifu__DOT__pfs_excp_adef 
        = (IData)((0U != (3U & vlSelf->__PVT__cpu__DOT__ifu__DOT__pc)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__src2_is_4 = 
        ((0x13U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                    >> 0x1aU)) | (0x15U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                            >> 0x1aU)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__rk_d = (((0x1fU 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                     >> 0xaU))) 
                                                << 0x1fU) 
                                               | (((0x1eU 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                        >> 0xaU))) 
                                                   << 0x1eU) 
                                                  | (((0x1dU 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                           >> 0xaU))) 
                                                      << 0x1dU) 
                                                     | (((0x1cU 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                              >> 0xaU))) 
                                                         << 0x1cU) 
                                                        | (((0x1bU 
                                                             == 
                                                             (0x1fU 
                                                              & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                 >> 0xaU))) 
                                                            << 0x1bU) 
                                                           | (((0x1aU 
                                                                == 
                                                                (0x1fU 
                                                                 & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                    >> 0xaU))) 
                                                               << 0x1aU) 
                                                              | (((0x19U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                       >> 0xaU))) 
                                                                  << 0x19U) 
                                                                 | (((0x18U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          >> 0xaU))) 
                                                                     << 0x18U) 
                                                                    | (((0x17U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                             >> 0xaU))) 
                                                                        << 0x17U) 
                                                                       | (((0x16U 
                                                                            == 
                                                                            (0x1fU 
                                                                             & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                           << 0x16U) 
                                                                          | (((0x15U 
                                                                               == 
                                                                               (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                              << 0x15U) 
                                                                             | (((0x14U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0x14U) 
                                                                                | (((0x13U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0x13U) 
                                                                                | (((0x12U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0x12U) 
                                                                                | (((0x11U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0x11U) 
                                                                                | (((0x10U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0x10U) 
                                                                                | (((0xfU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0xfU) 
                                                                                | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__op_19_15_d = 
        (((0x1fU == (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                              >> 0xfU))) << 0x1fU) 
         | (((0x1eU == (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                 >> 0xfU))) << 0x1eU) 
            | (((0x1dU == (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                    >> 0xfU))) << 0x1dU) 
               | (((0x1cU == (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0xfU))) << 0x1cU) 
                  | (((0x1bU == (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0xfU))) 
                      << 0x1bU) | (((0x1aU == (0x1fU 
                                               & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                  >> 0xfU))) 
                                    << 0x1aU) | (((0x19U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                       >> 0xfU))) 
                                                  << 0x19U) 
                                                 | (((0x18U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                          >> 0xfU))) 
                                                     << 0x18U) 
                                                    | (((0x17U 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                             >> 0xfU))) 
                                                        << 0x17U) 
                                                       | (((0x16U 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                >> 0xfU))) 
                                                           << 0x16U) 
                                                          | (((0x15U 
                                                               == 
                                                               (0x1fU 
                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                   >> 0xfU))) 
                                                              << 0x15U) 
                                                             | (((0x14U 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                      >> 0xfU))) 
                                                                 << 0x14U) 
                                                                | (((0x13U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                         >> 0xfU))) 
                                                                    << 0x13U) 
                                                                   | (((0x12U 
                                                                        == 
                                                                        (0x1fU 
                                                                         & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                            >> 0xfU))) 
                                                                       << 0x12U) 
                                                                      | (((0x11U 
                                                                           == 
                                                                           (0x1fU 
                                                                            & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                               >> 0xfU))) 
                                                                          << 0x11U) 
                                                                         | (((0x10U 
                                                                              == 
                                                                              (0x1fU 
                                                                               & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                             << 0x10U) 
                                                                            | (((0xfU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 0xfU) 
                                                                               | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xfU))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__op_25_22_d = 
        (((0xfU == (0xfU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                            >> 0x16U))) << 0xfU) | 
         (((0xeU == (0xfU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                             >> 0x16U))) << 0xeU) | 
          (((0xdU == (0xfU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                              >> 0x16U))) << 0xdU) 
           | (((0xcU == (0xfU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                 >> 0x16U))) << 0xcU) 
              | (((0xbU == (0xfU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                    >> 0x16U))) << 0xbU) 
                 | (((0xaU == (0xfU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0x16U))) 
                     << 0xaU) | (((9U == (0xfU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                  >> 0x16U))) 
                                  << 9U) | (((8U == 
                                              (0xfU 
                                               & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                  >> 0x16U))) 
                                             << 8U) 
                                            | (((7U 
                                                 == 
                                                 (0xfU 
                                                  & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                     >> 0x16U))) 
                                                << 7U) 
                                               | (((6U 
                                                    == 
                                                    (0xfU 
                                                     & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                        >> 0x16U))) 
                                                   << 6U) 
                                                  | (((5U 
                                                       == 
                                                       (0xfU 
                                                        & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                           >> 0x16U))) 
                                                      << 5U) 
                                                     | (((4U 
                                                          == 
                                                          (0xfU 
                                                           & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                              >> 0x16U))) 
                                                         << 4U) 
                                                        | (((3U 
                                                             == 
                                                             (0xfU 
                                                              & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                 >> 0x16U))) 
                                                            << 3U) 
                                                           | (((2U 
                                                                == 
                                                                (0xfU 
                                                                 & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                    >> 0x16U))) 
                                                               << 2U) 
                                                              | (((1U 
                                                                   == 
                                                                   (0xfU 
                                                                    & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                       >> 0x16U))) 
                                                                  << 1U) 
                                                                 | (0U 
                                                                    == 
                                                                    (0xfU 
                                                                     & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                        >> 0x16U))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__op_31_26_d = 
        (((QData)((IData)((0x3fU == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                     >> 0x1aU)))) << 0x3fU) 
         | (((QData)((IData)((0x3eU == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 0x1aU)))) 
             << 0x3eU) | (((QData)((IData)((0x3dU == 
                                            (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                             >> 0x1aU)))) 
                           << 0x3dU) | (((QData)((IData)(
                                                         (0x3cU 
                                                          == 
                                                          (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                           >> 0x1aU)))) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(
                                                            (0x3bU 
                                                             == 
                                                             (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                              >> 0x1aU)))) 
                                            << 0x3bU) 
                                           | (((QData)((IData)(
                                                               (0x3aU 
                                                                == 
                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                 >> 0x1aU)))) 
                                               << 0x3aU) 
                                              | (((QData)((IData)(
                                                                  (0x39U 
                                                                   == 
                                                                   (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                    >> 0x1aU)))) 
                                                  << 0x39U) 
                                                 | (((QData)((IData)(
                                                                     (0x38U 
                                                                      == 
                                                                      (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                       >> 0x1aU)))) 
                                                     << 0x38U) 
                                                    | (((QData)((IData)(
                                                                        (0x37U 
                                                                         == 
                                                                         (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          >> 0x1aU)))) 
                                                        << 0x37U) 
                                                       | (((QData)((IData)(
                                                                           (0x36U 
                                                                            == 
                                                                            (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                             >> 0x1aU)))) 
                                                           << 0x36U) 
                                                          | (((QData)((IData)(
                                                                              (0x35U 
                                                                               == 
                                                                               (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                              << 0x35U) 
                                                             | (((QData)((IData)(
                                                                                (0x34U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                 << 0x34U) 
                                                                | (((QData)((IData)(
                                                                                (0x33U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                    << 0x33U) 
                                                                   | (((QData)((IData)(
                                                                                (0x32U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                       << 0x32U) 
                                                                      | (((QData)((IData)(
                                                                                (0x31U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                          << 0x31U) 
                                                                         | (((QData)((IData)(
                                                                                (0x30U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                             << 0x30U) 
                                                                            | (((QData)((IData)(
                                                                                (0x2fU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2fU) 
                                                                               | (((QData)((IData)(
                                                                                (0x2eU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2dU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2cU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2bU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (0x2aU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (0x29U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (0x28U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (0x27U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (0x26U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (0x25U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (0x24U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (0x23U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (0x22U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (0x21U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (0x20U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((0x1fU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x1fU) 
                                                                                | (((0x1eU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x1eU) 
                                                                                | (((0x1dU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x1dU) 
                                                                                | (((0x1cU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x1cU) 
                                                                                | (((0x1bU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x1bU) 
                                                                                | (((0x1aU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x1aU) 
                                                                                | (((0x19U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x19U) 
                                                                                | (((0x18U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x18U) 
                                                                                | (((0x17U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x17U) 
                                                                                | (((0x16U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x16U) 
                                                                                | (((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x15U) 
                                                                                | (((0x14U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x14U) 
                                                                                | (((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x13U) 
                                                                                | (((0x12U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x12U) 
                                                                                | (((0x11U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x11U) 
                                                                                | (((0x10U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0x10U) 
                                                                                | (((0xfU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0xfU) 
                                                                                | (((0xeU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__rj_d = (((0x1fU 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                     >> 5U))) 
                                                << 0x1fU) 
                                               | (((0x1eU 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                        >> 5U))) 
                                                   << 0x1eU) 
                                                  | (((0x1dU 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                           >> 5U))) 
                                                      << 0x1dU) 
                                                     | (((0x1cU 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                              >> 5U))) 
                                                         << 0x1cU) 
                                                        | (((0x1bU 
                                                             == 
                                                             (0x1fU 
                                                              & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                 >> 5U))) 
                                                            << 0x1bU) 
                                                           | (((0x1aU 
                                                                == 
                                                                (0x1fU 
                                                                 & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                    >> 5U))) 
                                                               << 0x1aU) 
                                                              | (((0x19U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                       >> 5U))) 
                                                                  << 0x19U) 
                                                                 | (((0x18U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          >> 5U))) 
                                                                     << 0x18U) 
                                                                    | (((0x17U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                             >> 5U))) 
                                                                        << 0x17U) 
                                                                       | (((0x16U 
                                                                            == 
                                                                            (0x1fU 
                                                                             & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                           << 0x16U) 
                                                                          | (((0x15U 
                                                                               == 
                                                                               (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                              << 0x15U) 
                                                                             | (((0x14U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0x14U) 
                                                                                | (((0x13U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0x13U) 
                                                                                | (((0x12U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0x12U) 
                                                                                | (((0x11U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0x11U) 
                                                                                | (((0x10U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0x10U) 
                                                                                | (((0xfU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0xfU) 
                                                                                | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 5U))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__rd_d = (((0x1fU 
                                                 == 
                                                 (0x1fU 
                                                  & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                << 0x1fU) 
                                               | (((0x1eU 
                                                    == 
                                                    (0x1fU 
                                                     & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                   << 0x1eU) 
                                                  | (((0x1dU 
                                                       == 
                                                       (0x1fU 
                                                        & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                      << 0x1dU) 
                                                     | (((0x1cU 
                                                          == 
                                                          (0x1fU 
                                                           & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                         << 0x1cU) 
                                                        | (((0x1bU 
                                                             == 
                                                             (0x1fU 
                                                              & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                            << 0x1bU) 
                                                           | (((0x1aU 
                                                                == 
                                                                (0x1fU 
                                                                 & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                               << 0x1aU) 
                                                              | (((0x19U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                  << 0x19U) 
                                                                 | (((0x18U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                     << 0x18U) 
                                                                    | (((0x17U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                        << 0x17U) 
                                                                       | (((0x16U 
                                                                            == 
                                                                            (0x1fU 
                                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                           << 0x16U) 
                                                                          | (((0x15U 
                                                                               == 
                                                                               (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                              << 0x15U) 
                                                                             | (((0x14U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0x14U) 
                                                                                | (((0x13U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0x13U) 
                                                                                | (((0x12U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0x12U) 
                                                                                | (((0x11U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0x11U) 
                                                                                | (((0x10U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0x10U) 
                                                                                | (((0xfU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0xfU) 
                                                                                | (((0xeU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0xeU) 
                                                                                | (((0xdU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0xdU) 
                                                                                | (((0xcU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0xcU) 
                                                                                | (((0xbU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0xbU) 
                                                                                | (((0xaU 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 0xaU) 
                                                                                | (((9U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 9U) 
                                                                                | (((8U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 8U) 
                                                                                | (((7U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 7U) 
                                                                                | (((6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 6U) 
                                                                                | (((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 5U) 
                                                                                | (((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 4U) 
                                                                                | (((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__div_signed = (IData)(
                                                            (0U 
                                                             != 
                                                             (0x50000000U 
                                                              & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U])));
    vlSelf->csr_llbctl_diff = vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_llbctl;
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next 
        = (vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__dividend_reg 
           << 1U);
    if (((IData)((vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next 
                  >> 0x20U)) >= vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__divisor_reg)) {
        vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next 
            = ((0xffffffffULL & vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next) 
               | ((QData)((IData)(((IData)((vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next 
                                            >> 0x20U)) 
                                   - vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__divisor_reg))) 
                  << 0x20U));
        vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next 
            = (1ULL | vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next);
    } else {
        vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next 
            = (0xfffffffffffffffeULL & vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next);
    }
    vlSelf->__PVT__cpu__DOT__data_sram_data_ok = ((IData)(vlSelf->__PVT__cpu__DOT__o__DOT__data_data_received) 
                                                  | (IData)(vlSelf->__PVT__cpu__DOT__o__DOT__data_write_done));
    vlSelf->__PVT__cpu__DOT__csr_has_int = ((0U != 
                                             (0x1fffU 
                                              & (vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_ecfg 
                                                 & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_estat))) 
                                            & (vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_crmd 
                                               >> 2U));
    vlSelf->__PVT__cpu__DOT__data_sram_wr = (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__jirl_offs = 
        (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                            >> 0x19U)))) << 0x12U) 
         | (0x3fffcU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                        >> 8U)));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_e 
        = vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
        [(0x1fU & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)];
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h9c77f720__0 
        = (IData)((0U != (0x18U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg))));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_odd_page_buffer 
        = ((((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
              [0x1fU]) ? (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                          >> 0xcU) : (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                      >> 0x15U)) << 0x1fU) 
           | ((0x40000000U & (((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                [0x1eU]) ? (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                            >> 0xcU)
                                : (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                   >> 0x15U)) << 0x1eU)) 
              | ((0x20000000U & (((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                   [0x1dU]) ? (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                               >> 0xcU)
                                   : (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                      >> 0x15U)) << 0x1dU)) 
                 | ((0x10000000U & (((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                      [0x1cU]) ? (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                  >> 0xcU)
                                      : (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                         >> 0x15U)) 
                                    << 0x1cU)) | ((0x8000000U 
                                                   & (((0xcU 
                                                        == 
                                                        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                        [0x1bU])
                                                        ? 
                                                       (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                        >> 0xcU)
                                                        : 
                                                       (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                        >> 0x15U)) 
                                                      << 0x1bU)) 
                                                  | ((0x4000000U 
                                                      & (((0xcU 
                                                           == 
                                                           vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                           [0x1aU])
                                                           ? 
                                                          (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                           >> 0xcU)
                                                           : 
                                                          (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                           >> 0x15U)) 
                                                         << 0x1aU)) 
                                                     | ((0x2000000U 
                                                         & (((0xcU 
                                                              == 
                                                              vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                              [0x19U])
                                                              ? 
                                                             (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                              >> 0xcU)
                                                              : 
                                                             (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                              >> 0x15U)) 
                                                            << 0x19U)) 
                                                        | ((0x1000000U 
                                                            & (((0xcU 
                                                                 == 
                                                                 vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                 [0x18U])
                                                                 ? 
                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                 >> 0xcU)
                                                                 : 
                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                 >> 0x15U)) 
                                                               << 0x18U)) 
                                                           | ((0x800000U 
                                                               & (((0xcU 
                                                                    == 
                                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                    [0x17U])
                                                                    ? 
                                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                    >> 0xcU)
                                                                    : 
                                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                    >> 0x15U)) 
                                                                  << 0x17U)) 
                                                              | ((0x400000U 
                                                                  & (((0xcU 
                                                                       == 
                                                                       vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                       [0x16U])
                                                                       ? 
                                                                      (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                       >> 0xcU)
                                                                       : 
                                                                      (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                       >> 0x15U)) 
                                                                     << 0x16U)) 
                                                                 | ((0x200000U 
                                                                     & (((0xcU 
                                                                          == 
                                                                          vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                          [0x15U])
                                                                          ? 
                                                                         (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                          >> 0xcU)
                                                                          : 
                                                                         (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                          >> 0x15U)) 
                                                                        << 0x15U)) 
                                                                    | ((0x100000U 
                                                                        & (((0xcU 
                                                                             == 
                                                                             vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                             [0x14U])
                                                                             ? 
                                                                            (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                             >> 0xcU)
                                                                             : 
                                                                            (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                             >> 0x15U)) 
                                                                           << 0x14U)) 
                                                                       | ((0x80000U 
                                                                           & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x13U])
                                                                                ? 
                                                                               (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                : 
                                                                               (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                              << 0x13U)) 
                                                                          | ((0x40000U 
                                                                              & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x12U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0x12U)) 
                                                                             | ((0x20000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x11U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x10U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xfU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xeU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xdU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xcU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xbU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xaU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [9U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [8U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [7U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [6U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [5U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [4U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [3U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [2U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [1U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & ((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                                                >> 0x15U))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__mem_is_ertn = (1U & (vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
                                                  | vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U]));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_g 
        = vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
        [(0x1fU & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)];
    vlSelf->__VdfgTmp_hf491859d__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1fU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1fU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1fU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1fU] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1fU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1fU])));
    vlSelf->__VdfgTmp_h8db76367__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1eU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1eU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1eU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1eU] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1eU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1eU])));
    vlSelf->__VdfgTmp_h47e789ee__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1dU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1dU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1dU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1dU] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1dU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1dU])));
    vlSelf->__VdfgTmp_he9aee5e6__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1cU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1cU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1cU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1cU] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1cU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1cU])));
    vlSelf->__VdfgTmp_h22c40758__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1bU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1bU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1bU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1bU] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1bU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1bU])));
    vlSelf->__VdfgTmp_he2db1349__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1aU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1aU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1aU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1aU] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1aU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1aU])));
    vlSelf->__VdfgTmp_h009e5764__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x19U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x19U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x19U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x19U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x19U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x19U])));
    vlSelf->__VdfgTmp_hc2a96525__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x18U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x18U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x18U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x18U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x18U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x18U])));
    vlSelf->__VdfgTmp_h0bb51f1b__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x17U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x17U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x17U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x17U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x17U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x17U])));
    vlSelf->__VdfgTmp_hc7568c01__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x16U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x16U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x16U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x16U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x16U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x16U])));
    vlSelf->__VdfgTmp_h2279297c__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x15U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x15U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x15U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x15U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x15U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x15U])));
    vlSelf->__VdfgTmp_h55854117__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x14U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x14U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x14U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x14U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x14U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x14U])));
    vlSelf->__VdfgTmp_ha76d27d4__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xfU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xfU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xfU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xfU] 
                                                      >> 9U)))) 
                                                & (((0x3ffU 
                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xfU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xfU])));
    vlSelf->__VdfgTmp_h713b061a__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xeU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xeU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xeU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xeU] 
                                                      >> 9U)))) 
                                                & (((0x3ffU 
                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xeU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xeU])));
    vlSelf->__VdfgTmp_h059f3a5a__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xdU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xdU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xdU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xdU] 
                                                      >> 9U)))) 
                                                & (((0x3ffU 
                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xdU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xdU])));
    vlSelf->__VdfgTmp_h4bb6f19b__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xcU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xcU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xcU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xcU] 
                                                      >> 9U)))) 
                                                & (((0x3ffU 
                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xcU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xcU])));
    vlSelf->__VdfgTmp_h328b4211__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xbU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xbU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xbU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xbU] 
                                                      >> 9U)))) 
                                                & (((0x3ffU 
                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xbU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xbU])));
    vlSelf->__VdfgTmp_hded3e9aa__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xaU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xaU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xaU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xaU] 
                                                      >> 9U)))) 
                                                & (((0x3ffU 
                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xaU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xaU])));
    vlSelf->__VdfgTmp_h7ab2dec7__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [9U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [9U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [9U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [9U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [9U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [9U])));
    vlSelf->__VdfgTmp_h7fe385ba__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [8U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [8U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [8U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [8U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [8U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [8U])));
    vlSelf->__VdfgTmp_h0a6131bd__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [7U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [7U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [7U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [7U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [7U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [7U])));
    vlSelf->__VdfgTmp_h1ff363f5__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [6U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [6U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [6U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [6U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [6U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [6U])));
    vlSelf->__VdfgTmp_h44a86401__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [5U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [5U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [5U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [5U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [5U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [5U])));
    vlSelf->__VdfgTmp_hf99c2a8e__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [4U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [4U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [4U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [4U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [4U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [4U])));
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h29275379__0 
        = ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
            >> 0x16U) & (((0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                    >> 5U)) == (0x1fU 
                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                   >> 0x11U))) 
                         & (0U != (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                            >> 5U)))));
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h504567f6__0 
        = ((vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[3U] 
            >> 0x15U) & (((0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                    >> 5U)) == (0x1fU 
                                                & (vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[3U] 
                                                   >> 0x10U))) 
                         & (0U != (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                            >> 5U)))));
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h9616191f__0 
        = (IData)((0U != (0x60U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_w = (IData)(
                                                           (0x28800000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_hu = (IData)(
                                                            (0x2a400000U 
                                                             == 
                                                             (0xffc00000U 
                                                              & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_h = (IData)(
                                                           (0x28400000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_bu = (IData)(
                                                            (0x2a000000U 
                                                             == 
                                                             (0xffc00000U 
                                                              & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_b = (IData)(
                                                           (0x28000000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w 
        = (IData)((0x14000000U == (0xfe000000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xori = (IData)(
                                                           (0x3c00000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ori = (IData)(
                                                          (0x3800000U 
                                                           == 
                                                           (0xffc00000U 
                                                            & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_andi = (IData)(
                                                           (0x3400000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltui = (IData)(
                                                            (0x2400000U 
                                                             == 
                                                             (0xffc00000U 
                                                              & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slti = (IData)(
                                                           (0x2000000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w 
        = (IData)((0x2800000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_pcaddu12i 
        = (IData)((0x1c000000U == (0xfe000000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__mem__DOT__mem_result = 
        ((1U & (((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                 >> 3U) & (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
          ? (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                >> 7U)))) << 8U) | 
             (0xffU & vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata))
          : ((1U & (((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                     >> 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg) 
                               >> 1U))) ? (((- (IData)(
                                                       (1U 
                                                        & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                           >> 0xfU)))) 
                                            << 8U) 
                                           | (0xffU 
                                              & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                 >> 8U)))
              : ((1U & (((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                         >> 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg) 
                                   >> 2U))) ? (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                               >> 0x17U)))) 
                                                << 8U) 
                                               | (0xffU 
                                                  & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                     >> 0x10U)))
                  : ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                            & (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                      ? (((- (IData)((vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                      >> 0x1fU))) << 8U) 
                         | (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                            >> 0x18U)) : ((1U & (((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                  >> 4U) 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                                           ? (0xffU 
                                              & vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata)
                                           : ((1U & 
                                               (((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                 >> 4U) 
                                                & ((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg) 
                                                   >> 1U)))
                                               ? (0xffU 
                                                  & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                     >> 8U))
                                               : ((1U 
                                                   & (((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                       >> 4U) 
                                                      & ((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg) 
                                                         >> 2U)))
                                                   ? 
                                                  (0xffU 
                                                   & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                      >> 0x10U))
                                                   : 
                                                  ((IData)(
                                                           (((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                             >> 4U) 
                                                            & ((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg) 
                                                               >> 3U)))
                                                    ? 
                                                   (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                    >> 0x18U)
                                                    : 
                                                   ((((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                      >> 5U) 
                                                     & (3U 
                                                        == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                                                     ? 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                                     >> 0xfU)))) 
                                                      << 0x10U) 
                                                     | (0xffffU 
                                                        & vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata))
                                                     : 
                                                    ((((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                       >> 5U) 
                                                      & (6U 
                                                         == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                                                      ? 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                                      >> 0x17U)))) 
                                                       << 0x10U) 
                                                      | (0xffffU 
                                                         & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                            >> 8U)))
                                                      : 
                                                     ((((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                        >> 5U) 
                                                       & (0xcU 
                                                          == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                                    >> 0x1fU))) 
                                                        << 0x10U) 
                                                       | (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                          >> 0x10U))
                                                       : 
                                                      ((((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                         >> 6U) 
                                                        & (3U 
                                                           == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                                                        ? 
                                                       (0xffffU 
                                                        & vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata)
                                                        : 
                                                       ((((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                          >> 6U) 
                                                         & (6U 
                                                            == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                                                         ? 
                                                        (0xffffU 
                                                         & (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                            >> 8U))
                                                         : 
                                                        ((((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg) 
                                                           >> 6U) 
                                                          & (0xcU 
                                                             == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg)))
                                                          ? 
                                                         (vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata 
                                                          >> 0x10U)
                                                          : vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata))))))))))))));
    vlSelf->__VdfgTmp_h2b38d13c__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x13U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x13U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x13U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x13U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x13U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x13U])));
    vlSelf->__VdfgTmp_h0c09fcc4__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x12U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x12U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x12U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x12U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x12U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x12U])));
    vlSelf->__VdfgTmp_h0c8f67c9__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x11U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x11U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x11U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x11U] 
                                                       >> 9U)))) 
                                                 & (((0x3ffU 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x11U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x11U])));
    vlSelf->__VdfgTmp_h7b3f9024__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [3U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [3U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [3U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [3U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [3U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [3U])));
    vlSelf->__VdfgTmp_h52b193dd__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [2U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [2U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [2U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [2U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [2U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [2U])));
    vlSelf->__VdfgTmp_h0fd238d5__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [1U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [1U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [1U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [1U] 
                                                       >> 9U)))) 
                                              & (((0x3ffU 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [1U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [1U])));
    vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr = 
        ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
          >> 0x15U) & ((1U == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)) 
                       & ((~ (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_r)) 
                          & (~ ((vlSelf->__PVT__cpu__DOT__wbu__DOT__last_pc 
                                 == ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[3U] 
                                      << 0x10U) | (
                                                   vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                   >> 0x10U))) 
                                & ((IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__last_waddr) 
                                   == (0x1fU & (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
                                                >> 0x10U))))))));
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h817cd92b__0 
        = (IData)((0U != (0x30000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U])));
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_hd54a942d__0 
        = (IData)((0U != (0xc0000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U])));
    vlSelf->__PVT__cpu__DOT__exu__DOT__excp_flush = 
        ((IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_r) 
         & (1U == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h19962199__0 
        = ((0x16U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                      >> 0x1aU)) | (0x17U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                              >> 0x1aU)));
    cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0 = (IData)(
                                                         (0x400000U 
                                                          == 
                                                          (0xfff00000U 
                                                           & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h2d68c437__0 
        = (IData)((0U == (0x3ffU & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_w = (IData)(
                                                           (0x29800000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_h = (IData)(
                                                           (0x29400000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_b = (IData)(
                                                           (0x29000000U 
                                                            == 
                                                            (0xffc00000U 
                                                             & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    cpu__DOT__idu__DOT____VdfgTmp_h64c8ed36__0 = (IData)(
                                                         (0x6400000U 
                                                          == 
                                                          (0xfff00000U 
                                                           & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    if ((0x100U & (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r))) {
        __Vtemp_hf6b25177__0[0U] = (IData)((((QData)((IData)(
                                                             (1U 
                                                              == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)))) 
                                             << 0x3eU) 
                                            | ((QData)((IData)(
                                                               ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[3U] 
                                                                 << 0x10U) 
                                                                | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                                   >> 0x10U)))) 
                                               << 0x1eU)));
        __Vtemp_hf6b25177__0[1U] = (IData)(((((QData)((IData)(
                                                              (1U 
                                                               == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)))) 
                                              << 0x3eU) 
                                             | ((QData)((IData)(
                                                                ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[3U] 
                                                                  << 0x10U) 
                                                                 | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                                    >> 0x10U)))) 
                                                << 0x1eU)) 
                                            >> 0x20U));
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[0U] 
            = __Vtemp_hf6b25177__0[0U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[1U] 
            = __Vtemp_hf6b25177__0[1U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[2U] = 4U;
    } else if ((0x200U & (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r))) {
        __Vtemp_hf6b25177__0[0U] = (IData)((((QData)((IData)(
                                                             (1U 
                                                              == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)))) 
                                             << 0x3eU) 
                                            | ((QData)((IData)(
                                                               vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[0U])) 
                                               << 0x1eU)));
        __Vtemp_hf6b25177__0[1U] = (0x80000000U | (IData)(
                                                          ((((QData)((IData)(
                                                                             (1U 
                                                                              == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)))) 
                                                             << 0x3eU) 
                                                            | ((QData)((IData)(
                                                                               vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[0U])) 
                                                               << 0x1eU)) 
                                                           >> 0x20U)));
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[0U] 
            = __Vtemp_hf6b25177__0[0U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[1U] 
            = __Vtemp_hf6b25177__0[1U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[2U] = 4U;
    } else if ((0x800U & (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r))) {
        __Vtemp_hf6b25177__0[0U] = 0U;
        __Vtemp_hf6b25177__0[1U] = 0x80000000U;
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[0U] 
            = __Vtemp_hf6b25177__0[0U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[1U] 
            = __Vtemp_hf6b25177__0[1U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[2U] = 5U;
    } else if ((0x1000U & (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r))) {
        __Vtemp_hf6b25177__0[0U] = 0U;
        __Vtemp_hf6b25177__0[1U] = 0U;
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[0U] 
            = __Vtemp_hf6b25177__0[0U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[1U] 
            = __Vtemp_hf6b25177__0[1U];
        vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[2U] = 6U;
    } else {
        __Vtemp_hf6b25177__0[0U] = 0U;
        if ((0x2000U & (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r))) {
            __Vtemp_hf6b25177__0[1U] = 0x80000000U;
            vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[0U] 
                = __Vtemp_hf6b25177__0[0U];
            vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[1U] 
                = __Vtemp_hf6b25177__0[1U];
            vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[2U] = 6U;
        } else {
            __Vtemp_hf6b25177__0[1U] = 0U;
            vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[0U] 
                = __Vtemp_hf6b25177__0[0U];
            vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[1U] 
                = __Vtemp_hf6b25177__0[1U];
            vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[2U] = 0U;
        }
    }
    cpu__DOT__idu__DOT____VdfgTmp_hb75ab56b__0 = (IData)(
                                                         (0x4000000U 
                                                          == 
                                                          (0xff000000U 
                                                           & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    cpu__DOT__idu__DOT____VdfgTmp_ha4228d15__0 = (IData)(
                                                         (0U 
                                                          == 
                                                          (0xffc00000U 
                                                           & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result 
        = (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
             << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                       >> 0x19U)) | ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                >> 0x19U)));
    vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_r)) 
           & (1U == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin 
        = (IData)((0U != (0x1c000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U])));
    if ((0x2000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U])) {
        vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 
            = ((IData)(1U) + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                  << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                            >> 0x19U))));
        vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp0 
            = ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U));
    } else {
        vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 = 0U;
        vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp0 = 0U;
    }
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                         >> 0x19U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                             >> 0x19U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                         >> 0x1aU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                             >> 0x1aU))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x17U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x17U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x16U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x16U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp1 
        = ((0x4000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp2 
        = ((0x8000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp31 
        = ((0x1000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp30 
        = ((0x800000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                         >> 0x1bU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                             >> 0x1bU))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                         >> 0x1cU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                             >> 0x1cU))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                         >> 0x1dU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                             >> 0x1dU))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x13U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x13U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x15U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x15U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x14U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x14U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp3 
        = ((0x10000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp4 
        = ((0x20000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp5 
        = ((0x40000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp27 
        = ((0x100000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp29 
        = ((0x400000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
        = ((1U == (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                   >> 0x1eU)) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                  << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                            >> 0x19U))
            : ((2U == (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                       >> 0x1eU)) ? ((IData)(1U) + 
                                     (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                          << 7U) | 
                                         (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                          >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp28 
        = ((0x200000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
        = ((1U == (3U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U]))
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : ((2U == (3U 
                                                & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U]))
                                         ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                                         : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
        = ((1U == (3U & ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          << 1U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                    >> 0x1fU)))) ? 
           ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
             << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                       >> 0x19U)) : ((2U == (3U & (
                                                   (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                    << 1U) 
                                                   | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                      >> 0x1fU))))
                                      ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                                      : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 7U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 7U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 9U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 9U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 8U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 8U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp6 
        = ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
            >> 0x1fU) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                          << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                    >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp8 
        = ((2U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp7 
        = ((1U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 6U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 6U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 4U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 4U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp15 
        = ((0x100U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp17 
        = ((0x400U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 5U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 5U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp16 
        = ((0x200U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 1U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 1U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 2U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 2U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 3U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                      << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 3U))) ? ((IData)(1U) 
                                         + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                << 7U) 
                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp14 
        = ((0x80U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp12 
        = ((0x20U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp13 
        = ((0x40U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0xaU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                        << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0xaU))) ? ((IData)(1U) 
                                           + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                  << 7U) 
                                                 | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                    >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0xbU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                        << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0xbU))) ? ((IData)(1U) 
                                           + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                  << 7U) 
                                                 | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                    >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0xcU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                        << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0xcU))) ? ((IData)(1U) 
                                           + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                  << 7U) 
                                                 | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                    >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp9 
        = ((4U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp10 
        = ((8U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp11 
        = ((0x10U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp18 
        = ((0x800U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0xdU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                        << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0xdU))) ? ((IData)(1U) 
                                           + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                  << 7U) 
                                                 | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                    >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp19 
        = ((0x1000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0xfU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                        << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0xfU))) ? ((IData)(1U) 
                                           + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                  << 7U) 
                                                 | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                    >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp20 
        = ((0x2000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0xeU))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                        << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                  >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0xeU))) ? ((IData)(1U) 
                                           + (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                  << 7U) 
                                                 | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                    >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x12U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x12U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x10U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x10U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
        = ((1U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                         >> 0x11U))) ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                         << 7U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                   >> 0x19U))
            : ((2U == (3U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                             >> 0x11U))) ? ((IData)(1U) 
                                            + (~ ((
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                   << 7U) 
                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                     >> 0x19U))))
                : 0U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp21 
        = ((0x4000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp23 
        = ((0x10000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp22 
        = ((0x8000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp26 
        = ((0x80000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp24 
        = ((0x20000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp25 
        = ((0x40000U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U])
            ? ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                          >> 0x19U)) : 0U);
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbidx_o = (((~ (IData)(vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_e)) 
                                                  << 0x1fU) 
                                                 | (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                    [
                                                    (0x1fU 
                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                    << 0x18U));
    vlSelf->__PVT__cpu__DOT__exu__DOT__access_memo 
        = (((IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h9c77f720__0) 
            | (0U != (0xe0U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg)))) 
           | (IData)(vlSelf->__PVT__cpu__DOT__data_sram_wr));
    vlSelf->__PVT__cpu__DOT__exu_exu_is_etrn = (1U 
                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U] 
                                                   | (IData)(vlSelf->__PVT__cpu__DOT__mem_is_ertn)));
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbelo0_o = ((
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn0
                                                   [
                                                   (0x1fU 
                                                    & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_g) 
                                                      << 6U) 
                                                     | ((vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_mat0
                                                         [
                                                         (0x1fU 
                                                          & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                         << 4U) 
                                                        | ((vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_plv0
                                                            [
                                                            (0x1fU 
                                                             & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                            << 2U) 
                                                           | ((vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_d0
                                                               [
                                                               (0x1fU 
                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                               << 1U) 
                                                              | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_v0
                                                              [
                                                              (0x1fU 
                                                               & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)])))));
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbelo1_o = ((
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn1
                                                   [
                                                   (0x1fU 
                                                    & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_g) 
                                                      << 6U) 
                                                     | ((vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_mat1
                                                         [
                                                         (0x1fU 
                                                          & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                         << 4U) 
                                                        | ((vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_plv1
                                                            [
                                                            (0x1fU 
                                                             & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                            << 2U) 
                                                           | ((vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_d1
                                                               [
                                                               (0x1fU 
                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)] 
                                                               << 1U) 
                                                              | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_v1
                                                              [
                                                              (0x1fU 
                                                               & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)])))));
    cpu__DOT__exu__DOT____VdfgTmp_hf84f9b29__0 = (1U 
                                                  & ((IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h9616191f__0) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg) 
                                                        >> 1U)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data = (
                                                   (0x400000U 
                                                    & vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[4U])
                                                    ? vlSelf->__PVT__cpu__DOT__mem__DOT__mem_result
                                                    : 
                                                   ((vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[4U] 
                                                     << 0xaU) 
                                                    | (vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[3U] 
                                                       >> 0x16U)));
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__two__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h2b38d13c__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h0c09fcc4__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h0c8f67c9__0) 
                                  << 1U) | (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                            [0x10U] 
                                            & (((0xcU 
                                                 == 
                                                 vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                 [0x10U])
                                                 ? 
                                                ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                  >> 0xdU) 
                                                 == 
                                                 vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                 [0x10U])
                                                 : 
                                                ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                  >> 0x16U) 
                                                 == 
                                                 (0x3ffU 
                                                  & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                     [0x10U] 
                                                     >> 9U)))) 
                                               & (((0x3ffU 
                                                    & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                   [0x10U]) 
                                                  | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                  [0x10U]))))));
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h7b3f9024__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h52b193dd__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h0fd238d5__0) 
                                  << 1U) | (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                            [0U] & 
                                            (((0xcU 
                                               == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                               [0U])
                                               ? ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0U])
                                               : ((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0U] 
                                                      >> 9U)))) 
                                             & (((0x3ffU 
                                                  & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                 == 
                                                 vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                 [0U]) 
                                                | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                [0U]))))));
    vlSelf->debug_wb_rf_we = (0xfU & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr))));
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_hb28e2988__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr) 
           & (((0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                         >> 5U)) == (0x1fU & (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
                                              >> 0x10U))) 
              & (0U != (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                 >> 5U)))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__div = ((IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h817cd92b__0) 
                                              | (IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_hd54a942d__0));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0) 
           & (0x88000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0) 
           & (0x48000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0) 
           & (0x8000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_hc7a77381__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_b) 
           | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_h));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_invtlb 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h64c8ed36__0) 
           & (0x98000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0 = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h64c8ed36__0) 
                                                  & (0x80000U 
                                                     == 
                                                     (0xf8000U 
                                                      & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__wbu__DOT__csr_ecode = 
        ((1U & (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r))
          ? 0U : (0x3fU & ((vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[2U] 
                            << 1U) | (vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[1U] 
                                      >> 0x1fU))));
    vlSelf->__PVT__cpu__DOT__wbu__DOT__excp_tlbrefill 
        = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r)) 
                 & (vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0[0U] 
                    >> 0x14U)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrrd = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb75ab56b__0) 
         & (0U == (0x3e0U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrxchg 
        = ((~ ((0U == (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                >> 5U))) | (1U == (0x1fU 
                                                   & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                      >> 5U))))) 
           & (IData)(cpu__DOT__idu__DOT____VdfgTmp_hb75ab56b__0));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrwr = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb75ab56b__0) 
         & (0x20U == (0x3e0U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h95da6b40__0 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_ha4228d15__0) 
           & (IData)((0U == (0x3f8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg))));
    cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0 = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_ha4228d15__0) 
                                                  & (0x200000U 
                                                     == 
                                                     (0x300000U 
                                                      & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0 = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_ha4228d15__0) 
                                                  & (0x100000U 
                                                     == 
                                                     (0x300000U 
                                                      & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__wbu_invtlb_en_o = ((IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__tlb_inst_bus_r) 
                                                & (IData)(vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0));
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbrd_en_o = (
                                                   ((IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__tlb_inst_bus_r) 
                                                    >> 3U) 
                                                   & (IData)(vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0));
    vlSelf->__PVT__cpu__DOT__wbu_tlbwr_en_o = (((IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__tlb_inst_bus_r) 
                                                >> 2U) 
                                               & (IData)(vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0));
    vlSelf->__PVT__cpu__DOT__wbu_tlbfill_en_o = (((IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__tlb_inst_bus_r) 
                                                  >> 1U) 
                                                 & (IData)(vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush = 
        (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
         & (IData)(vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0));
    vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we = 
        ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
          >> 0xfU) & (IData)(vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b 
        = ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)
            ? (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                   << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                             >> 0x19U))) : ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                             << 7U) 
                                            | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                               >> 0x19U)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
        = ((0x80000000U & vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31) 
           | ((0x40000000U & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 
                              >> 1U)) | ((0x20000000U 
                                          & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 
                                             >> 2U)) 
                                         | ((0x10000000U 
                                             & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 
                                                >> 3U)) 
                                            | ((0x8000000U 
                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 
                                                   >> 4U)) 
                                               | ((0x4000000U 
                                                   & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 
                                                      >> 5U)) 
                                                  | ((0x2000000U 
                                                      & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 
                                                         >> 6U)) 
                                                     | ((0x1000000U 
                                                         & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 
                                                            >> 7U)) 
                                                        | ((0x800000U 
                                                            & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 
                                                               >> 8U)) 
                                                           | ((0x400000U 
                                                               & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 
                                                                  >> 9U)) 
                                                              | ((0x200000U 
                                                                  & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 
                                                                     >> 0xaU)) 
                                                                 | ((0x100000U 
                                                                     & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 
                                                                        >> 0xbU)) 
                                                                    | ((0x80000U 
                                                                        & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 
                                                                           >> 0xcU)) 
                                                                       | ((0x40000U 
                                                                           & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 
                                                                              >> 0xdU)) 
                                                                          | ((0x20000U 
                                                                              & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 
                                                                                >> 0xeU)) 
                                                                             | ((0x10000U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 
                                                                                >> 0xfU)) 
                                                                                | ((0x8000U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 
                                                                                >> 0x10U)) 
                                                                                | ((0x4000U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 
                                                                                >> 0x11U)) 
                                                                                | ((0x2000U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 
                                                                                >> 0x12U)) 
                                                                                | ((0x1000U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 
                                                                                >> 0x13U)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 
                                                                                >> 0x14U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 
                                                                                >> 0x15U)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 
                                                                                >> 0x16U)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 
                                                                                >> 0x17U)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 
                                                                                >> 0x18U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 
                                                                                >> 0x19U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 
                                                                                >> 0x1aU)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 
                                                                                >> 0x1bU)) 
                                                                                | ((8U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 
                                                                                >> 0x1cU)) 
                                                                                | ((4U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 
                                                                                >> 0x1dU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 
                                                                                >> 0x1eU)) 
                                                                                | (1U 
                                                                                & ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0x19U) 
                                                                                & (((IData)(1U) 
                                                                                + 
                                                                                (~ 
                                                                                ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                                << 7U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                                >> 0x19U)))) 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__data_sram_size = ((1U 
                                                & ((IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h9c77f720__0) 
                                                   | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg)))
                                                ? 0U
                                                : ((IData)(cpu__DOT__exu__DOT____VdfgTmp_hf84f9b29__0)
                                                    ? 1U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg))
                                                     ? 2U
                                                     : 0U)));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_index 
        = (((- (IData)(((IData)(vlSelf->__VdfgTmp_ha76d27d4__0) 
                        | ((IData)(vlSelf->__VdfgTmp_h713b061a__0) 
                           | ((IData)(vlSelf->__VdfgTmp_h059f3a5a__0) 
                              | ((IData)(vlSelf->__VdfgTmp_h4bb6f19b__0) 
                                 | ((IData)(vlSelf->__VdfgTmp_h328b4211__0) 
                                    | ((IData)(vlSelf->__VdfgTmp_hded3e9aa__0) 
                                       | ((IData)(vlSelf->__VdfgTmp_h7ab2dec7__0) 
                                          | ((IData)(vlSelf->__VdfgTmp_h7fe385ba__0) 
                                             | ((IData)(vlSelf->__VdfgTmp_h0a6131bd__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_h1ff363f5__0) 
                                                   | ((IData)(vlSelf->__VdfgTmp_h44a86401__0) 
                                                      | ((IData)(vlSelf->__VdfgTmp_hf99c2a8e__0) 
                                                         | (0U 
                                                            != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in)))))))))))))))) 
            & ((3U & ((- (IData)((0U != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in)))) 
                      & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h0fd238d5__0)))) 
                         | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h52b193dd__0)))) 
                            | (- (IData)((IData)(vlSelf->__VdfgTmp_h7b3f9024__0))))))) 
               | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h0a6131bd__0) 
                               | ((IData)(vlSelf->__VdfgTmp_h1ff363f5__0) 
                                  | ((IData)(vlSelf->__VdfgTmp_h44a86401__0) 
                                     | (IData)(vlSelf->__VdfgTmp_hf99c2a8e__0)))))) 
                   & (4U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h44a86401__0)))) 
                                  | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h1ff363f5__0)))) 
                                     | (- (IData)((IData)(vlSelf->__VdfgTmp_h0a6131bd__0)))))))) 
                  | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h328b4211__0) 
                                  | ((IData)(vlSelf->__VdfgTmp_hded3e9aa__0) 
                                     | ((IData)(vlSelf->__VdfgTmp_h7ab2dec7__0) 
                                        | (IData)(vlSelf->__VdfgTmp_h7fe385ba__0)))))) 
                      & (8U | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h7ab2dec7__0)))) 
                                     | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_hded3e9aa__0)))) 
                                        | (- (IData)((IData)(vlSelf->__VdfgTmp_h328b4211__0)))))))) 
                     | ((- (IData)(((IData)(vlSelf->__VdfgTmp_ha76d27d4__0) 
                                    | ((IData)(vlSelf->__VdfgTmp_h713b061a__0) 
                                       | ((IData)(vlSelf->__VdfgTmp_h059f3a5a__0) 
                                          | (IData)(vlSelf->__VdfgTmp_h4bb6f19b__0)))))) 
                        & (0xcU | (3U & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h059f3a5a__0)))) 
                                         | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h713b061a__0)))) 
                                            | (- (IData)((IData)(vlSelf->__VdfgTmp_ha76d27d4__0)))))))))))) 
           | ((- (IData)(((IData)(vlSelf->__VdfgTmp_hf491859d__0) 
                          | ((IData)(vlSelf->__VdfgTmp_h8db76367__0) 
                             | ((IData)(vlSelf->__VdfgTmp_h47e789ee__0) 
                                | ((IData)(vlSelf->__VdfgTmp_he9aee5e6__0) 
                                   | ((IData)(vlSelf->__VdfgTmp_h22c40758__0) 
                                      | ((IData)(vlSelf->__VdfgTmp_he2db1349__0) 
                                         | ((IData)(vlSelf->__VdfgTmp_h009e5764__0) 
                                            | ((IData)(vlSelf->__VdfgTmp_hc2a96525__0) 
                                               | ((IData)(vlSelf->__VdfgTmp_h0bb51f1b__0) 
                                                  | ((IData)(vlSelf->__VdfgTmp_hc7568c01__0) 
                                                     | ((IData)(vlSelf->__VdfgTmp_h2279297c__0) 
                                                        | ((IData)(vlSelf->__VdfgTmp_h55854117__0) 
                                                           | (0U 
                                                              != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__two__DOT____Vcellinp__one__in)))))))))))))))) 
              & (0x10U | ((3U & ((- (IData)((0U != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__two__DOT____Vcellinp__one__in)))) 
                                 & ((1U & (- (IData)((IData)(vlSelf->__VdfgTmp_h0c8f67c9__0)))) 
                                    | ((2U & (- (IData)((IData)(vlSelf->__VdfgTmp_h0c09fcc4__0)))) 
                                       | (- (IData)((IData)(vlSelf->__VdfgTmp_h2b38d13c__0))))))) 
                          | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h0bb51f1b__0) 
                                          | ((IData)(vlSelf->__VdfgTmp_hc7568c01__0) 
                                             | ((IData)(vlSelf->__VdfgTmp_h2279297c__0) 
                                                | (IData)(vlSelf->__VdfgTmp_h55854117__0)))))) 
                              & (4U | (3U & ((1U & 
                                              (- (IData)((IData)(vlSelf->__VdfgTmp_h2279297c__0)))) 
                                             | ((2U 
                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_hc7568c01__0)))) 
                                                | (- (IData)((IData)(vlSelf->__VdfgTmp_h0bb51f1b__0)))))))) 
                             | (((- (IData)(((IData)(vlSelf->__VdfgTmp_h22c40758__0) 
                                             | ((IData)(vlSelf->__VdfgTmp_he2db1349__0) 
                                                | ((IData)(vlSelf->__VdfgTmp_h009e5764__0) 
                                                   | (IData)(vlSelf->__VdfgTmp_hc2a96525__0)))))) 
                                 & (8U | (3U & ((1U 
                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_h009e5764__0)))) 
                                                | ((2U 
                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_he2db1349__0)))) 
                                                   | (- (IData)((IData)(vlSelf->__VdfgTmp_h22c40758__0)))))))) 
                                | ((- (IData)(((IData)(vlSelf->__VdfgTmp_hf491859d__0) 
                                               | ((IData)(vlSelf->__VdfgTmp_h8db76367__0) 
                                                  | ((IData)(vlSelf->__VdfgTmp_h47e789ee__0) 
                                                     | (IData)(vlSelf->__VdfgTmp_he9aee5e6__0)))))) 
                                   & (0xcU | (3U & 
                                              ((1U 
                                                & (- (IData)((IData)(vlSelf->__VdfgTmp_h47e789ee__0)))) 
                                               | ((2U 
                                                   & (- (IData)((IData)(vlSelf->__VdfgTmp_h8db76367__0)))) 
                                                  | (- (IData)((IData)(vlSelf->__VdfgTmp_hf491859d__0))))))))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__do_div = ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__div) 
                                                 & ((~ (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__wire_complete)) 
                                                    & (1U 
                                                       == (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_state))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__is_inst_ertn 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x3800U == (0x7c00U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                      & (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbsrch 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x2800U == (0x7c00U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                      & (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbrd = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0) 
         & (IData)(((0x2c00U == (0x7c00U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                    & (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbwr = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0) 
         & (IData)(((0x3000U == (0x7c00U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                    & (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbfill 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_h702eaf52__0) 
           & (IData)(((0x3400U == (0x7c00U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                      & (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h2d68c437__0))));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__w_e 
        = (1U & ((~ (vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx 
                     >> 0x1fU)) | (0x3fU == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__csr_ecode))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__csr_we = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrwr) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrxchg));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvh_w 
        = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h95da6b40__0) 
           & (IData)((0x6400U == (0x7fe0U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg))));
    cpu__DOT__idu__DOT____VdfgTmp_ha7c13be7__0 = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h95da6b40__0) 
                                                  & (0x6000U 
                                                     == 
                                                     (0x7c00U 
                                                      & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_syscall 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0) 
           & (0xb0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_break = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0) 
         & (0xa0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_wu 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0) 
           & (0x18000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_w = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0) 
         & (0x8000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_wu 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0) 
           & (0x10000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_w = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb594121e__0) 
         & (0U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_wu 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
           & (0xd0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_w 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
           & (0xc8000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mul_w = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
         & (0xc0000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sra = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                   & (0x80000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srl = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                   & (0x78000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sll = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                   & (0x70000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                   & (0x58000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                  & (0x50000U 
                                                     == 
                                                     (0xf8000U 
                                                      & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                   & (0x40000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                   & (0x48000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
         & (0x28000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
                                                   & (0x20000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
         & (0x10000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_hb469ad25__0) 
         & (0U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tlbrd_valid_wr_en 
        = ((IData)(vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_e) 
           & (IData)(vlSelf->__PVT__cpu__DOT__wbu_csr_tlbrd_en_o));
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tlbrd_invalid_wr_en 
        = ((~ (IData)(vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_e)) 
           & (IData)(vlSelf->__PVT__cpu__DOT__wbu_csr_tlbrd_en_o));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__we 
        = ((IData)(vlSelf->__PVT__cpu__DOT__wbu_tlbfill_en_o) 
           | (IData)(vlSelf->__PVT__cpu__DOT__wbu_tlbwr_en_o));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__w_index 
        = (0x1fU & (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__wbu_tlbfill_en_o))) 
                     & (IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__timer_64)) 
                    | ((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__wbu_tlbwr_en_o))) 
                       & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__flush_sign = 
        ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush) 
         | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__excp_flush));
    cpu__DOT__csr_o__DOT____VdfgTmp_hfdd17fff__0 = (IData)(
                                                           ((0x3f0000U 
                                                             == 
                                                             (0x3f0000U 
                                                              & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_estat)) 
                                                            & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush)));
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tcfg_wen = 
        ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we) 
         & (0x82U == (0x7ffeU & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])));
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 = (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we) 
                                               & (0x300U 
                                                  == 
                                                  (0x7ffeU 
                                                   & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])))
                                               ? ((
                                                   vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                   << 0x1fU) 
                                                  | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                     >> 1U))
                                               : vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_dmw0);
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 = (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we) 
                                               & (0x302U 
                                                  == 
                                                  (0x7ffeU 
                                                   & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])))
                                               ? ((
                                                   vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                   << 0x1fU) 
                                                  | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                     >> 1U))
                                               : vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_dmw1);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__crmd_wen = 
        ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we) 
         & (0U == (0x7ffeU & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])));
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tlbehi_wen 
        = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we) 
           & (0x22U == (0x7ffeU & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])));
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result 
        = (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
             << 7U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                       >> 0x19U)) + (vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b 
                                     + (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s0_ppn 
        = ((1U & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_odd_page_buffer 
                  >> (IData)(vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_index)))
            ? vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn1
           [vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_index]
            : vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn0
           [vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_index]);
    vlSelf->__PVT__cpu__DOT__idu_rf_raddr2 = (0x1fU 
                                              & (((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_w) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_h) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_b) 
                                                           | ((0x18U 
                                                               == 
                                                               (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                >> 0x1aU)) 
                                                              | ((0x1aU 
                                                                  == 
                                                                  (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                   >> 0x1aU)) 
                                                                 | ((0x19U 
                                                                     == 
                                                                     (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                      >> 0x1aU)) 
                                                                    | ((0x1bU 
                                                                        == 
                                                                        (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                         >> 0x1aU)) 
                                                                       | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_we)))))))))
                                                  ? vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg
                                                  : 
                                                 (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                  >> 0xaU)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvl_w 
        = ((IData)(cpu__DOT__idu__DOT____VdfgTmp_ha7c13be7__0) 
           & (IData)(((0U == (0x3e0U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                      & (0U != (0x1fU & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__dst_is_rj = 
        ((IData)(cpu__DOT__idu__DOT____VdfgTmp_ha7c13be7__0) 
         & (0U == (0x1fU & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__mul_div_op = 
        ((0x380U & (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mul_div_op)) 
         | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_wu) 
             << 6U) | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_w) 
                        << 5U) | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_wu) 
                                   << 4U) | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_w) 
                                              << 3U) 
                                             | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_wu) 
                                                 << 2U) 
                                                | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_w) 
                                                    << 1U) 
                                                   | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mul_w))))))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__alu_op = ((0xfffff000U 
                                                  & vlSelf->__PVT__cpu__DOT__idu__DOT__alu_op) 
                                                 | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                     << 0xbU) 
                                                    | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                         | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sra)) 
                                                        << 0xaU) 
                                                       | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                            | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srl)) 
                                                           << 9U) 
                                                          | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                               | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sll)) 
                                                              << 8U) 
                                                             | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                                                  | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xori)) 
                                                                 << 7U) 
                                                                | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                                     | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ori)) 
                                                                    << 6U) 
                                                                   | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                                       << 5U) 
                                                                      | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                                           | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_andi)) 
                                                                          << 4U) 
                                                                         | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                                              | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltui)) 
                                                                             << 3U) 
                                                                            | ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slti)) 
                                                                                << 2U) 
                                                                               | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                                << 1U) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_w) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_pcaddu12i) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_bu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_hu) 
                                                                                | (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_hc7a77381__0))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__inst_sram_req = ((~ (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__flush_sign)) 
                                              & ((1U 
                                                  == (IData)(vlSelf->__PVT__cpu__DOT__ifu__DOT__ifu_state)) 
                                                 & ((~ (IData)(vlSelf->__PVT__cpu__DOT__o__DOT__inst_addr_accepted)) 
                                                    & (0U 
                                                       == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__idu_state)))));
    vlSelf->__PVT__cpu__DOT__csr_plv_out = (3U & ((
                                                   (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush))) 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_prmd) 
                                                  | (((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__crmd_wen))) 
                                                      & ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                          << 0x1fU) 
                                                         | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                            >> 1U))) 
                                                     | ((- (IData)(
                                                                   (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__excp_flush) 
                                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush) 
                                                                           | (IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__crmd_wen))))))) 
                                                        & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_crmd))));
    vlSelf->__PVT__cpu__DOT__ifu_inst_da = (1U & ((IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__excp_tlbrefill) 
                                                  | ((~ (IData)(cpu__DOT__csr_o__DOT____VdfgTmp_hfdd17fff__0)) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__crmd_wen)
                                                         ? 
                                                        (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                         >> 4U)
                                                         : 
                                                        (vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_crmd 
                                                         >> 3U)))));
    vlSelf->__PVT__cpu__DOT__ifu_inst_pg = (1U & ((~ (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__excp_tlbrefill)) 
                                                  & ((IData)(cpu__DOT__csr_o__DOT____VdfgTmp_hfdd17fff__0) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__crmd_wen)
                                                         ? 
                                                        (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                         >> 5U)
                                                         : 
                                                        (vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_crmd 
                                                         >> 4U)))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr = ((
                                                   (- (IData)((IData)(
                                                                      (0U 
                                                                       != 
                                                                       (0x6000000U 
                                                                        & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U]))))) 
                                                   & vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result) 
                                                  | ((1U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                        >> 0x1bU)))) 
                                                         & (((~ 
                                                              (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                               >> 0x18U)) 
                                                             & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                >> 0x18U)) 
                                                            | ((~ 
                                                                ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                  ^ 
                                                                  vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U]) 
                                                                 >> 0x18U)) 
                                                               & (vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result 
                                                                  >> 0x1fU))))) 
                                                     | ((1U 
                                                         & ((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                           >> 0x1cU)))) 
                                                            & (~ (IData)(
                                                                         (1ULL 
                                                                          & (((QData)((IData)(
                                                                                ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                                << 7U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                                >> 0x19U)))) 
                                                                              + 
                                                                              ((QData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b)) 
                                                                               + (QData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)))) 
                                                                             >> 0x20U)))))) 
                                                        | (((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                           >> 0x1dU)))) 
                                                            & (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                 << 7U) 
                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                   >> 0x19U)) 
                                                               & ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                   << 7U) 
                                                                  | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                     >> 0x19U)))) 
                                                           | (((~ vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result) 
                                                               & (- (IData)(
                                                                            (1U 
                                                                             & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                                >> 0x1eU))))) 
                                                              | (((- (IData)(
                                                                             (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                              >> 0x1fU))) 
                                                                  & vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result) 
                                                                 | (((- (IData)(
                                                                                (1U 
                                                                                & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U]))) 
                                                                     & (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                          << 7U) 
                                                                         | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                            >> 0x19U)) 
                                                                        ^ 
                                                                        ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                          << 7U) 
                                                                         | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                            >> 0x19U)))) 
                                                                    | (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U] 
                                                                                >> 4U)))) 
                                                                        & ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                            << 7U) 
                                                                           | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                              >> 0x19U))) 
                                                                       | (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U] 
                                                                                >> 1U)))) 
                                                                           & (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                                << 7U) 
                                                                               | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                                >> 0x19U)) 
                                                                              << 
                                                                              (0x1fU 
                                                                               & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0x19U)))) 
                                                                          | ((- (IData)((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0xcU 
                                                                                & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U]))))) 
                                                                             & (IData)(
                                                                                ((((QData)((IData)(
                                                                                (- (IData)(
                                                                                (1U 
                                                                                & ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U] 
                                                                                >> 3U) 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                                >> 0x18U))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[6U] 
                                                                                << 7U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[5U] 
                                                                                >> 0x19U))))) 
                                                                                >> 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0x19U))))))))))))));
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h1fbcf766__0 
        = ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
            >> 0x16U) & (((IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2) 
                          == (0x1fU & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                       >> 0x11U))) 
                         & (0U != (IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2))));
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h8b961b55__0 
        = ((vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[3U] 
            >> 0x15U) & (((IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2) 
                          == (0x1fU & (vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[3U] 
                                       >> 0x10U))) 
                         & (0U != (IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2))));
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h52bf9dc3__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr) 
           & (((IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2) 
               == (0x1fU & (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
                            >> 0x10U))) & (0U != (IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2))));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h709b1d5a__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__dst_is_rj) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvl_w) 
              | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvh_w)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__dst_is_rj)
                                                   ? 0x40U
                                                   : 
                                                  (0x3fffU 
                                                   & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                      >> 0xaU)));
    vlSelf->__VdfgTmp_h152a734c__0 = ((vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 
                                       & (0U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv_out))) 
                                      | ((vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 
                                          >> 3U) & 
                                         (3U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv_out))));
    vlSelf->__VdfgTmp_h92ff612a__0 = ((vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 
                                       & (0U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv_out))) 
                                      | ((vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 
                                          >> 3U) & 
                                         (3U == (IData)(vlSelf->__PVT__cpu__DOT__csr_plv_out))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode = ((~ (IData)(vlSelf->__PVT__cpu__DOT__ifu_inst_da)) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__ifu_inst_pg));
    vlSelf->__PVT__cpu__DOT__exu__DOT__excp_ale = (
                                                   ((IData)(cpu__DOT__exu__DOT____VdfgTmp_hf84f9b29__0) 
                                                    & vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr) 
                                                   | ((IData)(
                                                              (0U 
                                                               != 
                                                               (0x84U 
                                                                & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg)))) 
                                                      & (0U 
                                                         != 
                                                         (3U 
                                                          & vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr))));
    vlSelf->__PVT__cpu__DOT__exu_data_vaddr = ((0x10U 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__tlb_inst_bus_r))
                                                ? (
                                                   ((IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__tlbehi_wen)
                                                     ? 
                                                    ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                      << 0x12U) 
                                                     | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                        >> 0xeU))
                                                     : 
                                                    (vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbehi 
                                                     >> 0xdU)) 
                                                   << 0xdU)
                                                : vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr);
    vlSelf->__PVT__cpu__DOT__idu__DOT__caculate_done 
        = (1U & (((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h29275379__0)
                   ? (0U == (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_state))
                   : ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h504567f6__0)
                       ? (0U == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_state))
                       : ((~ (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_hb28e2988__0)) 
                          | (0U == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state))))) 
                 & ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h1fbcf766__0)
                     ? (0U == (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_state))
                     : ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h8b961b55__0)
                         ? (0U == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_state))
                         : ((~ (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h52bf9dc3__0)) 
                            | (0U == (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state)))))));
    vlSelf->__PVT__cpu__DOT__csr_rd_data = (((- (IData)(
                                                        (0U 
                                                         == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                             & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_crmd) 
                                            | (((- (IData)(
                                                           (1U 
                                                            == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_prmd) 
                                               | (((- (IData)(
                                                              (4U 
                                                               == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                   & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_ecfg) 
                                                  | (((- (IData)(
                                                                 (5U 
                                                                  == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                      & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_estat) 
                                                     | (((- (IData)(
                                                                    (6U 
                                                                     == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                         & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_era) 
                                                        | (((- (IData)(
                                                                       (7U 
                                                                        == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                            & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_badv) 
                                                           | (((- (IData)(
                                                                          (0xcU 
                                                                           == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                               & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_eentry) 
                                                              | (((- (IData)(
                                                                             (0x10U 
                                                                              == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                  & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx) 
                                                                 | (((- (IData)(
                                                                                (0x11U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                     & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbehi) 
                                                                    | (((- (IData)(
                                                                                (0x12U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                        & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbelo0) 
                                                                       | (((- (IData)(
                                                                                (0x13U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                           & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbelo1) 
                                                                          | (((- (IData)(
                                                                                (0x18U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                              & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid) 
                                                                             | (((- (IData)(
                                                                                (0x19U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdl) 
                                                                                | (((- (IData)(
                                                                                (0x1aU 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdh) 
                                                                                | (((- (IData)(
                                                                                (0x1bU 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & ((vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_badv 
                                                                                >> 0x1fU)
                                                                                 ? vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdh
                                                                                 : vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdl)) 
                                                                                | (((- (IData)(
                                                                                (0x88U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbrentry) 
                                                                                | (((- (IData)(
                                                                                (0x30U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save0) 
                                                                                | (((- (IData)(
                                                                                (0x31U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save1) 
                                                                                | (((- (IData)(
                                                                                (0x32U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save2) 
                                                                                | (((- (IData)(
                                                                                (0x33U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save3) 
                                                                                | (((- (IData)(
                                                                                (0x40U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tid) 
                                                                                | (((- (IData)(
                                                                                (0x41U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tcfg) 
                                                                                | (((- (IData)(
                                                                                (0x44U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_ticlr) 
                                                                                | ((- (IData)(
                                                                                (0x42U 
                                                                                == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))) 
                                                                                & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tval))))))))))))))))))))))));
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0_en = ((IData)(vlSelf->__VdfgTmp_h152a734c__0) 
                                                 & (((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                      >> 0x1dU) 
                                                     == 
                                                     (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 
                                                      >> 0x1dU)) 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1_en = ((IData)(vlSelf->__VdfgTmp_h92ff612a__0) 
                                                 & (((vlSelf->__PVT__cpu__DOT__ifu__DOT__pc 
                                                      >> 0x1dU) 
                                                     == 
                                                     (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 
                                                      >> 0x1dU)) 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__exu_data_dmw0_en = ((IData)(vlSelf->__VdfgTmp_h152a734c__0) 
                                                 & (((vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr 
                                                      >> 0x1dU) 
                                                     == 
                                                     (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 
                                                      >> 0x1dU)) 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__exu_data_dmw1_en = ((IData)(vlSelf->__VdfgTmp_h92ff612a__0) 
                                                 & (((vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr 
                                                      >> 0x1dU) 
                                                     == 
                                                     (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 
                                                      >> 0x1dU)) 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__es_excp = ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__ds_excp_r) 
                                                  | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__excp_ale));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s1_odd_page_buffer 
        = ((((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
              [0x1fU]) ? (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                          >> 0xcU) : (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                      >> 0x15U)) << 0x1fU) 
           | ((0x40000000U & (((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                [0x1eU]) ? (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                            >> 0xcU)
                                : (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                   >> 0x15U)) << 0x1eU)) 
              | ((0x20000000U & (((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                   [0x1dU]) ? (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                               >> 0xcU)
                                   : (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                      >> 0x15U)) << 0x1dU)) 
                 | ((0x10000000U & (((0xcU == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                      [0x1cU]) ? (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                  >> 0xcU)
                                      : (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                         >> 0x15U)) 
                                    << 0x1cU)) | ((0x8000000U 
                                                   & (((0xcU 
                                                        == 
                                                        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                        [0x1bU])
                                                        ? 
                                                       (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                        >> 0xcU)
                                                        : 
                                                       (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                        >> 0x15U)) 
                                                      << 0x1bU)) 
                                                  | ((0x4000000U 
                                                      & (((0xcU 
                                                           == 
                                                           vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                           [0x1aU])
                                                           ? 
                                                          (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                           >> 0xcU)
                                                           : 
                                                          (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                           >> 0x15U)) 
                                                         << 0x1aU)) 
                                                     | ((0x2000000U 
                                                         & (((0xcU 
                                                              == 
                                                              vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                              [0x19U])
                                                              ? 
                                                             (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                              >> 0xcU)
                                                              : 
                                                             (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                              >> 0x15U)) 
                                                            << 0x19U)) 
                                                        | ((0x1000000U 
                                                            & (((0xcU 
                                                                 == 
                                                                 vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                 [0x18U])
                                                                 ? 
                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                 >> 0xcU)
                                                                 : 
                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                 >> 0x15U)) 
                                                               << 0x18U)) 
                                                           | ((0x800000U 
                                                               & (((0xcU 
                                                                    == 
                                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                    [0x17U])
                                                                    ? 
                                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                    >> 0xcU)
                                                                    : 
                                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                    >> 0x15U)) 
                                                                  << 0x17U)) 
                                                              | ((0x400000U 
                                                                  & (((0xcU 
                                                                       == 
                                                                       vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                       [0x16U])
                                                                       ? 
                                                                      (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                       >> 0xcU)
                                                                       : 
                                                                      (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                       >> 0x15U)) 
                                                                     << 0x16U)) 
                                                                 | ((0x200000U 
                                                                     & (((0xcU 
                                                                          == 
                                                                          vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                          [0x15U])
                                                                          ? 
                                                                         (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                          >> 0xcU)
                                                                          : 
                                                                         (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                          >> 0x15U)) 
                                                                        << 0x15U)) 
                                                                    | ((0x100000U 
                                                                        & (((0xcU 
                                                                             == 
                                                                             vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                             [0x14U])
                                                                             ? 
                                                                            (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                             >> 0xcU)
                                                                             : 
                                                                            (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                             >> 0x15U)) 
                                                                           << 0x14U)) 
                                                                       | ((0x80000U 
                                                                           & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x13U])
                                                                                ? 
                                                                               (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                : 
                                                                               (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                              << 0x13U)) 
                                                                          | ((0x40000U 
                                                                              & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x12U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0x12U)) 
                                                                             | ((0x20000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x11U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0x10U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xfU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xeU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xdU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xcU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xbU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0xaU])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [9U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [8U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [7U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [6U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [5U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [4U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [3U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [2U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [1U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & ((0xcU 
                                                                                == 
                                                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                                                [0U])
                                                                                 ? 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0xcU)
                                                                                 : 
                                                                                (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                                                >> 0x15U))))))))))))))))))))))))))))))))));
    vlSelf->__VdfgTmp_h6f00e02f__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1fU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1fU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1fU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1fU] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1fU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1fU])));
    vlSelf->__VdfgTmp_hf0004255__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1eU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1eU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1eU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1eU] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1eU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1eU])));
    vlSelf->__VdfgTmp_h9e962040__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1dU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1dU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1dU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1dU] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1dU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1dU])));
    vlSelf->__VdfgTmp_h8ed8f5cf__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1cU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1cU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1cU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1cU] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1cU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1cU])));
    vlSelf->__VdfgTmp_h12ddb05b__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1bU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1bU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1bU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1bU] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1bU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1bU])));
    vlSelf->__VdfgTmp_he53650ff__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x1aU] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x1aU])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x1aU])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x1aU] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x1aU]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x1aU])));
    vlSelf->__VdfgTmp_h7103b3dc__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x19U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x19U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x19U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x19U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x19U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x19U])));
    vlSelf->__VdfgTmp_h83a26ffc__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x18U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x18U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x18U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x18U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x18U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x18U])));
    vlSelf->__VdfgTmp_hb229ee02__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x17U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x17U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x17U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x17U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x17U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x17U])));
    vlSelf->__VdfgTmp_h19e72309__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x16U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x16U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x16U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x16U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x16U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x16U])));
    vlSelf->__VdfgTmp_h5ea32404__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x15U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x15U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x15U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x15U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x15U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x15U])));
    vlSelf->__VdfgTmp_h4a1f33f6__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x14U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x14U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x14U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x14U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x14U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x14U])));
    vlSelf->__VdfgTmp_h93bf0917__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x10U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x10U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x10U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x10U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x10U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x10U])));
    vlSelf->__VdfgTmp_h9d2405b8__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x13U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x13U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x13U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x13U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x13U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x13U])));
    vlSelf->__VdfgTmp_ha0f52a79__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x12U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x12U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x12U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x12U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x12U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x12U])));
    vlSelf->__VdfgTmp_hfe3e0abc__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0x11U] & (((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [0x11U])
                                                   ? 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [0x11U])
                                                   : 
                                                  ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [0x11U] 
                                                       >> 9U)))) 
                                                 & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                     == 
                                                     vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                     [0x11U]) 
                                                    | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                    [0x11U])));
    vlSelf->__VdfgTmp_h25039133__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xfU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xfU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xfU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xfU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xfU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xfU])));
    vlSelf->__VdfgTmp_heb094a5a__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xeU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xeU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xeU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xeU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xeU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xeU])));
    vlSelf->__VdfgTmp_hdc5aeeef__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xdU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xdU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xdU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xdU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xdU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xdU])));
    vlSelf->__VdfgTmp_hea9119cd__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xcU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xcU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xcU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xcU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xcU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xcU])));
    vlSelf->__VdfgTmp_he07c7f3b__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xbU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xbU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xbU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xbU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xbU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xbU])));
    vlSelf->__VdfgTmp_h045fbfd5__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [0xaU] & (((0xcU 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                  [0xaU])
                                                  ? 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0xaU])
                                                  : 
                                                 ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0xaU] 
                                                      >> 9U)))) 
                                                & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                    == 
                                                    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                    [0xaU]) 
                                                   | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                   [0xaU])));
    vlSelf->__VdfgTmp_hea5234c1__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [9U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [9U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [9U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [9U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [9U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [9U])));
    vlSelf->__VdfgTmp_h3d65e3d6__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [8U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [8U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [8U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [8U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [8U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [8U])));
    vlSelf->__VdfgTmp_h24244f83__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [7U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [7U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [7U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [7U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [7U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [7U])));
    vlSelf->__VdfgTmp_h84c4f938__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [6U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [6U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [6U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [6U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [6U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [6U])));
    vlSelf->__VdfgTmp_h379335bd__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [5U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [5U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [5U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [5U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [5U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [5U])));
    vlSelf->__VdfgTmp_h29af06bc__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [4U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [4U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [4U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [4U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [4U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [4U])));
    vlSelf->__VdfgTmp_hdea1d3a0__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [3U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [3U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [3U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [3U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [3U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [3U])));
    vlSelf->__VdfgTmp_h25a631c0__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [2U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [2U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [2U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [2U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [2U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [2U])));
    vlSelf->__VdfgTmp_h9b2c6fa7__0 = (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                      [1U] & (((0xcU 
                                                == 
                                                vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                [1U])
                                                ? (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0xdU) 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                   [1U])
                                                : (
                                                   (vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                    >> 0x16U) 
                                                   == 
                                                   (0x3ffU 
                                                    & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                       [1U] 
                                                       >> 9U)))) 
                                              & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                  [1U]) 
                                                 | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                 [1U])));
    vlSelf->__PVT__cpu__DOT__idu__DOT__csr_data = (
                                                   ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                                     >> 0xfU) 
                                                    & ((0x3fffU 
                                                        & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                                           >> 1U)) 
                                                       == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))
                                                    ? 
                                                   ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                                     << 0x1fU) 
                                                    | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U] 
                                                       >> 1U))
                                                    : 
                                                   (((vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                                      >> 0xfU) 
                                                     & ((0x3fffU 
                                                         & (vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                                            >> 1U)) 
                                                        == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))
                                                     ? 
                                                    ((vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                                      << 0x1fU) 
                                                     | (vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
                                                        >> 1U))
                                                     : 
                                                    (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we) 
                                                      & ((0x3fffU 
                                                          & (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                             >> 1U)) 
                                                         == (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx)))
                                                      ? 
                                                     ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                                       << 0x1fU) 
                                                      | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
                                                         >> 1U))
                                                      : 
                                                     ((1U 
                                                       & (IData)(
                                                                 ((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvl_w))) 
                                                                    >> 0x20U) 
                                                                   & (1ULL 
                                                                      | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__timer_64)) 
                                                                         >> 0x20U))) 
                                                                  | ((((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvh_w))) 
                                                                       >> 0x20U) 
                                                                      & (1ULL 
                                                                         | ((QData)((IData)(
                                                                                (vlSelf->__PVT__cpu__DOT__csr_o__DOT__timer_64 
                                                                                >> 0x20U))) 
                                                                            >> 0x20U))) 
                                                                     | (((- (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__dst_is_rj))) 
                                                                         >> 0x20U) 
                                                                        & (1ULL 
                                                                           | ((QData)((IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tid)) 
                                                                              >> 0x20U)))))))
                                                       ? 
                                                      (((IData)(
                                                                (0x1ffffffffULL 
                                                                 & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvl_w))))) 
                                                        & (IData)(vlSelf->__PVT__cpu__DOT__csr_o__DOT__timer_64)) 
                                                       | (((IData)(
                                                                   (0x1ffffffffULL 
                                                                    & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvh_w))))) 
                                                           & (IData)(
                                                                     (vlSelf->__PVT__cpu__DOT__csr_o__DOT__timer_64 
                                                                      >> 0x20U))) 
                                                          | ((IData)(
                                                                     (0x1ffffffffULL 
                                                                      & (- (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__dst_is_rj))))) 
                                                             & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tid)))
                                                       : vlSelf->__PVT__cpu__DOT__csr_rd_data))));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__inst_paddr 
        = (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode) 
            & (IData)(vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0_en))
            ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 
                               << 4U)) | (0x1fffffffU 
                                          & vlSelf->__PVT__cpu__DOT__ifu__DOT__pc))
            : (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode) 
                & (IData)(vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1_en))
                ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 
                                   << 4U)) | (0x1fffffffU 
                                              & vlSelf->__PVT__cpu__DOT__ifu__DOT__pc))
                : vlSelf->__PVT__cpu__DOT__ifu__DOT__pc));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__data_paddr 
        = (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode) 
            & (IData)(vlSelf->__PVT__cpu__DOT__exu_data_dmw0_en))
            ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 
                               << 4U)) | (0x1fffffffU 
                                          & vlSelf->__PVT__cpu__DOT__exu_data_vaddr))
            : (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode) 
                & (IData)(vlSelf->__PVT__cpu__DOT__exu_data_dmw1_en))
                ? ((0xe0000000U & (vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 
                                   << 4U)) | (0x1fffffffU 
                                              & vlSelf->__PVT__cpu__DOT__exu_data_vaddr))
                : vlSelf->__PVT__cpu__DOT__exu_data_vaddr));
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h1cf29c6f__0 
        = ((IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__es_excp_r) 
           | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__es_excp) 
              | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__flush_sign) 
                 | (IData)(vlSelf->__PVT__cpu__DOT__mem_is_ertn))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_valid = 
        (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__es_excp) 
          | (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__es_excp_r)) 
         | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w) 
            | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
               | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slti) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                        | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltui) 
                           | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor) 
                              | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and) 
                                 | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_andi) 
                                    | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or) 
                                       | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ori) 
                                          | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                             | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xori) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sll) 
                                                   | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                      | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srl) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                            | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sra) 
                                                               | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_w) 
                                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_b) 
                                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_bu) 
                                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_h) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_hu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_b) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_h) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x14U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x18U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x1aU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x16U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x17U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x19U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((0x1bU 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_pcaddu12i) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mul_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_wu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_wu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_wu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrwr) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrxchg) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__is_inst_ertn) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_syscall) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_break) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__dst_is_rj) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvl_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvh_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbsrch) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbrd) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbwr) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbfill) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_invtlb) 
                                                                                & ((0U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                | ((1U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                | ((2U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                | ((3U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                | ((4U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                | ((5U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)) 
                                                                                | (6U 
                                                                                == 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__two__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h9d2405b8__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_ha0f52a79__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_hfe3e0abc__0) 
                                  << 1U) | (IData)(vlSelf->__VdfgTmp_h93bf0917__0))));
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_hdea1d3a0__0) 
            << 3U) | (((IData)(vlSelf->__VdfgTmp_h25a631c0__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h9b2c6fa7__0) 
                                  << 1U) | (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e
                                            [0U] & 
                                            (((0xcU 
                                               == vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                               [0U])
                                               ? ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0xdU) 
                                                  == 
                                                  vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                  [0U])
                                               : ((vlSelf->__PVT__cpu__DOT__exu_data_vaddr 
                                                   >> 0x16U) 
                                                  == 
                                                  (0x3ffU 
                                                   & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn
                                                      [0U] 
                                                      >> 9U)))) 
                                             & (((IData)(vlSelf->__PVT__cpu__DOT__exu_data_asid) 
                                                 == 
                                                 vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid
                                                 [0U]) 
                                                | vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g
                                                [0U]))))));
    vlSelf->__PVT__cpu__DOT__inst_sram_addr = (((((~ 
                                                   ((IData)(vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0_en) 
                                                    | (IData)(vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1_en))) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode))
                                                  ? 
                                                 ((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_index])
                                                   ? vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s0_ppn
                                                   : 
                                                  ((0xffc00U 
                                                    & vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s0_ppn) 
                                                   | (0x3ffU 
                                                      & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__inst_paddr 
                                                         >> 0xcU))))
                                                  : 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__inst_paddr 
                                                  >> 0xcU)) 
                                                << 0xcU) 
                                               | (0xfffU 
                                                  & vlSelf->__PVT__cpu__DOT__ifu__DOT__pc));
    vlSelf->__PVT__cpu__DOT__data_sram_req = ((~ (IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h1cf29c6f__0)) 
                                              & ((1U 
                                                  == (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_state)) 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__access_memo) 
                                                    & ((~ (IData)(vlSelf->__PVT__cpu__DOT__o__DOT__data_addr_accepted)) 
                                                       & (0U 
                                                          == (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__mem_state))))));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_hd5810965__0 
        = (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_syscall)
             ? 0x800U : 0U) | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__fs_excp_num_r) 
                               | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_valid)
                                    ? 0U : 0x2000U) 
                                  | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_break)
                                      ? 0x1000U : 0U))));
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT____Vcellinp__one__in 
        = (((IData)(vlSelf->__VdfgTmp_h25039133__0) 
            << 0xfU) | (((IData)(vlSelf->__VdfgTmp_heb094a5a__0) 
                         << 0xeU) | (((IData)(vlSelf->__VdfgTmp_hdc5aeeef__0) 
                                      << 0xdU) | (((IData)(vlSelf->__VdfgTmp_hea9119cd__0) 
                                                   << 0xcU) 
                                                  | (((IData)(vlSelf->__VdfgTmp_he07c7f3b__0) 
                                                      << 0xbU) 
                                                     | (((IData)(vlSelf->__VdfgTmp_h045fbfd5__0) 
                                                         << 0xaU) 
                                                        | (((IData)(vlSelf->__VdfgTmp_hea5234c1__0) 
                                                            << 9U) 
                                                           | (((IData)(vlSelf->__VdfgTmp_h3d65e3d6__0) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->__VdfgTmp_h24244f83__0) 
                                                                  << 7U) 
                                                                 | (((IData)(vlSelf->__VdfgTmp_h84c4f938__0) 
                                                                     << 6U) 
                                                                    | (((IData)(vlSelf->__VdfgTmp_h379335bd__0) 
                                                                        << 5U) 
                                                                       | (((IData)(vlSelf->__VdfgTmp_h29af06bc__0) 
                                                                           << 4U) 
                                                                          | (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in)))))))))))));
    vlSelf->__PVT__cpu__DOT__exu_tlbsrch_index = ((
                                                   (- (IData)(
                                                              (0U 
                                                               != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT____Vcellinp__one__in)))) 
                                                   & ((3U 
                                                       & ((- (IData)(
                                                                     (0U 
                                                                      != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in)))) 
                                                          & ((1U 
                                                              & (- (IData)((IData)(vlSelf->__VdfgTmp_h9b2c6fa7__0)))) 
                                                             | ((2U 
                                                                 & (- (IData)((IData)(vlSelf->__VdfgTmp_h25a631c0__0)))) 
                                                                | (- (IData)((IData)(vlSelf->__VdfgTmp_hdea1d3a0__0))))))) 
                                                      | (((- (IData)(
                                                                     ((IData)(vlSelf->__VdfgTmp_h24244f83__0) 
                                                                      | ((IData)(vlSelf->__VdfgTmp_h84c4f938__0) 
                                                                         | ((IData)(vlSelf->__VdfgTmp_h379335bd__0) 
                                                                            | (IData)(vlSelf->__VdfgTmp_h29af06bc__0)))))) 
                                                          & (4U 
                                                             | (3U 
                                                                & ((1U 
                                                                    & (- (IData)((IData)(vlSelf->__VdfgTmp_h379335bd__0)))) 
                                                                   | ((2U 
                                                                       & (- (IData)((IData)(vlSelf->__VdfgTmp_h84c4f938__0)))) 
                                                                      | (- (IData)((IData)(vlSelf->__VdfgTmp_h24244f83__0)))))))) 
                                                         | (((- (IData)(
                                                                        ((IData)(vlSelf->__VdfgTmp_he07c7f3b__0) 
                                                                         | ((IData)(vlSelf->__VdfgTmp_h045fbfd5__0) 
                                                                            | ((IData)(vlSelf->__VdfgTmp_hea5234c1__0) 
                                                                               | (IData)(vlSelf->__VdfgTmp_h3d65e3d6__0)))))) 
                                                             & (8U 
                                                                | (3U 
                                                                   & ((1U 
                                                                       & (- (IData)((IData)(vlSelf->__VdfgTmp_hea5234c1__0)))) 
                                                                      | ((2U 
                                                                          & (- (IData)((IData)(vlSelf->__VdfgTmp_h045fbfd5__0)))) 
                                                                         | (- (IData)((IData)(vlSelf->__VdfgTmp_he07c7f3b__0)))))))) 
                                                            | ((- (IData)(
                                                                          ((IData)(vlSelf->__VdfgTmp_h25039133__0) 
                                                                           | ((IData)(vlSelf->__VdfgTmp_heb094a5a__0) 
                                                                              | ((IData)(vlSelf->__VdfgTmp_hdc5aeeef__0) 
                                                                                | (IData)(vlSelf->__VdfgTmp_hea9119cd__0)))))) 
                                                               & (0xcU 
                                                                  | (3U 
                                                                     & ((1U 
                                                                         & (- (IData)((IData)(vlSelf->__VdfgTmp_hdc5aeeef__0)))) 
                                                                        | ((2U 
                                                                            & (- (IData)((IData)(vlSelf->__VdfgTmp_heb094a5a__0)))) 
                                                                           | (- (IData)((IData)(vlSelf->__VdfgTmp_h25039133__0)))))))))))) 
                                                  | ((- (IData)(
                                                                ((IData)(vlSelf->__VdfgTmp_h6f00e02f__0) 
                                                                 | ((IData)(vlSelf->__VdfgTmp_hf0004255__0) 
                                                                    | ((IData)(vlSelf->__VdfgTmp_h9e962040__0) 
                                                                       | ((IData)(vlSelf->__VdfgTmp_h8ed8f5cf__0) 
                                                                          | ((IData)(vlSelf->__VdfgTmp_h12ddb05b__0) 
                                                                             | ((IData)(vlSelf->__VdfgTmp_he53650ff__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_h7103b3dc__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_h83a26ffc__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_hb229ee02__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_h19e72309__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_h5ea32404__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_h4a1f33f6__0) 
                                                                                | (0U 
                                                                                != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__two__DOT____Vcellinp__one__in)))))))))))))))) 
                                                     & (0x10U 
                                                        | ((3U 
                                                            & ((- (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__two__DOT____Vcellinp__one__in)))) 
                                                               & ((1U 
                                                                   & (- (IData)((IData)(vlSelf->__VdfgTmp_hfe3e0abc__0)))) 
                                                                  | ((2U 
                                                                      & (- (IData)((IData)(vlSelf->__VdfgTmp_ha0f52a79__0)))) 
                                                                     | (- (IData)((IData)(vlSelf->__VdfgTmp_h9d2405b8__0))))))) 
                                                           | (((- (IData)(
                                                                          ((IData)(vlSelf->__VdfgTmp_hb229ee02__0) 
                                                                           | ((IData)(vlSelf->__VdfgTmp_h19e72309__0) 
                                                                              | ((IData)(vlSelf->__VdfgTmp_h5ea32404__0) 
                                                                                | (IData)(vlSelf->__VdfgTmp_h4a1f33f6__0)))))) 
                                                               & (4U 
                                                                  | (3U 
                                                                     & ((1U 
                                                                         & (- (IData)((IData)(vlSelf->__VdfgTmp_h5ea32404__0)))) 
                                                                        | ((2U 
                                                                            & (- (IData)((IData)(vlSelf->__VdfgTmp_h19e72309__0)))) 
                                                                           | (- (IData)((IData)(vlSelf->__VdfgTmp_hb229ee02__0)))))))) 
                                                              | (((- (IData)(
                                                                             ((IData)(vlSelf->__VdfgTmp_h12ddb05b__0) 
                                                                              | ((IData)(vlSelf->__VdfgTmp_he53650ff__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_h7103b3dc__0) 
                                                                                | (IData)(vlSelf->__VdfgTmp_h83a26ffc__0)))))) 
                                                                  & (8U 
                                                                     | (3U 
                                                                        & ((1U 
                                                                            & (- (IData)((IData)(vlSelf->__VdfgTmp_h7103b3dc__0)))) 
                                                                           | ((2U 
                                                                               & (- (IData)((IData)(vlSelf->__VdfgTmp_he53650ff__0)))) 
                                                                              | (- (IData)((IData)(vlSelf->__VdfgTmp_h12ddb05b__0)))))))) 
                                                                 | ((- (IData)(
                                                                               ((IData)(vlSelf->__VdfgTmp_h6f00e02f__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_hf0004255__0) 
                                                                                | ((IData)(vlSelf->__VdfgTmp_h9e962040__0) 
                                                                                | (IData)(vlSelf->__VdfgTmp_h8ed8f5cf__0)))))) 
                                                                    & (0xcU 
                                                                       | (3U 
                                                                          & ((1U 
                                                                              & (- (IData)((IData)(vlSelf->__VdfgTmp_h9e962040__0)))) 
                                                                             | ((2U 
                                                                                & (- (IData)((IData)(vlSelf->__VdfgTmp_hf0004255__0)))) 
                                                                                | (- (IData)((IData)(vlSelf->__VdfgTmp_h6f00e02f__0))))))))))))));
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s1_ppn 
        = ((1U & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s1_odd_page_buffer 
                  >> (IData)(vlSelf->__PVT__cpu__DOT__exu_tlbsrch_index)))
            ? vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn1
           [vlSelf->__PVT__cpu__DOT__exu_tlbsrch_index]
            : vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn0
           [vlSelf->__PVT__cpu__DOT__exu_tlbsrch_index]);
    vlSelf->__PVT__cpu__DOT__data_sram_addr = (((((~ 
                                                   ((IData)(vlSelf->__PVT__cpu__DOT__exu_data_dmw0_en) 
                                                    | (IData)(vlSelf->__PVT__cpu__DOT__exu_data_dmw1_en))) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode))
                                                  ? 
                                                 ((0xcU 
                                                   == 
                                                   vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps
                                                   [vlSelf->__PVT__cpu__DOT__exu_tlbsrch_index])
                                                   ? vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s1_ppn
                                                   : 
                                                  ((0xffc00U 
                                                    & vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s1_ppn) 
                                                   | (0x3ffU 
                                                      & (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__data_paddr 
                                                         >> 0xcU))))
                                                  : 
                                                 (vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__data_paddr 
                                                  >> 0xcU)) 
                                                << 0xcU) 
                                               | (0xfffU 
                                                  & vlSelf->__PVT__cpu__DOT__exu_data_vaddr));
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
    vlSelf->csr_ecfg_diff = VL_RAND_RESET_I(32);
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
    vlSelf->__PVT__wire_arready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_rid = VL_RAND_RESET_I(4);
    vlSelf->__PVT__wire_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__wire_rresp = VL_RAND_RESET_I(2);
    vlSelf->__PVT__wire_rlast = VL_RAND_RESET_I(1);
    vlSelf->__PVT__wire_rvalid = VL_RAND_RESET_I(1);
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
    vlSelf->__PVT__cpu__DOT__inst_sram_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__inst_sram_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__data_sram_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_sram_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__data_sram_size = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__data_sram_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__data_sram_data_ok = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__ifu_inst_dmw1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__ifu_inst_da = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ifu_inst_pg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu_rf_raddr2 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu_exu_is_etrn = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu_data_asid = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__exu_data_vaddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu_data_dmw0_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu_data_dmw1_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu_tlbsrch_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__mem_is_ertn = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbrd_en_o = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbelo0_o = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbelo1_o = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__wbu_csr_tlbidx_o = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__wbu_tlbwr_en_o = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__wbu_tlbfill_en_o = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__wbu_invtlb_en_o = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_rd_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_has_int = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_plv_out = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_s0_found = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_s0_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__tlb_s0_ppn = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__tlb_s0_ps = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__tlb_s0_plv = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_s0_mat = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_s0_d = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_s0_v = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_s1_found = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_s1_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__tlb_s1_ppn = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__tlb_s1_ps = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__tlb_s1_plv = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_s1_mat = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_s1_d = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_s1_v = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_r_e = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_r_vppn = VL_RAND_RESET_I(19);
    vlSelf->__PVT__cpu__DOT__tlb_r_ps = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_r_asid = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__tlb_r_g = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_r_ppn0 = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__tlb_r_plv0 = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_r_mat0 = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_r_d0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_r_v0 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_r_ppn1 = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__tlb_r_plv1 = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_r_mat1 = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__tlb_r_d1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__tlb_r_v1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_state = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_state = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_addr_accepted = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_addr_accepted = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_data_received = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_data_received = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_write_done = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_read_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_read_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__o__DOT__handling_inst_request = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__handling_data_request = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_arvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_arid = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_araddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_arsize = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_arlen = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__o__DOT__inst_rready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_arvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_arid = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_araddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_arsize = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_arlen = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__o__DOT__data_rready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__pre_ifu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__pre_ifu__DOT__nextpc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__pre_ifu__DOT__pfs_state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_ready_go = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ifu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__ifu__DOT__pfs_excp_adef = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__ifu__DOT__ifu_state = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__u_regfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpu__DOT__idu__DOT__excp_brk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__fs_excp_num_r = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__idu__DOT__fs_excp_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__reg_condition_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__caculate_done = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_csr_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__alu_op = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__mul_div_op = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__idu__DOT__csr_idx = VL_RAND_RESET_I(14);
    vlSelf->__PVT__cpu__DOT__idu__DOT__csr_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__is_inst_ertn = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__csr_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__dst_is_rj = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__rj_eq_rd = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__jirl_offs = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__op_31_26_d = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__idu__DOT__op_25_22_d = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__idu__DOT__op_19_15_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__rd_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__rj_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__rk_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slti = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltui = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_andi = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ori = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xori = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sll = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srl = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sra = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_b = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_bu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_h = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_ld_hu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_b = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_st_h = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_pcaddu12i = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mul_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mulh_wu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_div_wu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_mod_wu = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrrd = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrwr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_csrxchg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_syscall = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_break = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvl_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_rdcntvh_w = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbsrch = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbrd = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbwr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_tlbfill = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_invtlb = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__src2_is_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__br_taken = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__idu_state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h29275379__0 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h504567f6__0 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_hb28e2988__0 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h1fbcf766__0 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h8b961b55__0 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h52bf9dc3__0 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_hd5810965__0 = 0;
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h19962199__0 = 0;
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_hc7a77381__0 = 0;
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h709b1d5a__0 = 0;
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h2d68c437__0 = 0;
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h95da6b40__0 = 0;
    vlSelf->__PVT__cpu__DOT__exu__DOT__excp_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__ds_excp_num_r = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__exu__DOT__ds_excp_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__excp_ale = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__es_excp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(259, vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mem_op_reg = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__exu__DOT__tlb_inst_bus_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__flush_sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__exu_state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__exu__DOT__reg_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__div = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__div_signed = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__div_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mod_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__wire_complete = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__do_div = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__access_memo = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__invtlb_op_i_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__invtlb_asid_i_r = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__exu__DOT__invtlb_vpn_i_r = VL_RAND_RESET_I(19);
    vlSelf->__PVT__cpu__DOT__exu__DOT__pg_mode = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h9c77f720__0 = 0;
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h1cf29c6f__0 = 0;
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h9616191f__0 = 0;
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h817cd92b__0 = 0;
    vlSelf->cpu__DOT__exu__DOT____VdfgTmp_hd54a942d__0 = 0;
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__res_signed = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__res_unsigned = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp3 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp4 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp5 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp6 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp7 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp8 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp9 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp10 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp11 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp12 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp13 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp14 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp15 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp16 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp17 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp18 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp19 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp20 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp21 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp22 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp23 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp24 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp25 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp26 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp27 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp28 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp29 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp30 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__pp31 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6 = VL_RAND_RESET_I(7);
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0 = 0;
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba801ce4__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf708c3fe__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbb7d496d__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7e4e467__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbadb26f2__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7439dfc__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba8f8829__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7372d37__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbabf5eef__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbaecaf09__0 = 0;
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0 = 0;
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp3 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp4 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp5 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp6 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp7 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp8 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp9 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp10 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp11 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp12 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp13 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp14 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp15 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp16 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp17 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp18 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp19 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp20 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp21 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp22 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp23 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp24 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp25 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp26 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp27 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp28 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp29 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp30 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__pp31 = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT____Vcellout__adder_low__sum = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT____Vcellout__adder_high__sum = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s0 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s0 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s1 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2 = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3 = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4 = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__busy = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__dividend_reg = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__shifted_next = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__divisor_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__count = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__x_neg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__exu__DOT__divider__DOT__o__DOT__y_neg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem__DOT__es_excp_num_r = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__mem__DOT__es_excp_r = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(151, vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r);
    vlSelf->__PVT__cpu__DOT__mem__DOT__reg_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__mem__DOT__mem_op_reg = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpu__DOT__mem__DOT__mem_mask_reg = VL_RAND_RESET_I(4);
    vlSelf->__PVT__cpu__DOT__mem__DOT__tlb_inst_bus_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__mem__DOT__mem_result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__mem__DOT__mem_state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__mem__DOT__tlbsrch_index_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__mem__DOT__tlbsrch_found_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__mem__DOT__invtlb_op_i_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__mem__DOT__invtlb_asid_i_r = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__mem__DOT__invtlb_vpn_i_r = VL_RAND_RESET_I(19);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__csr_ecode = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__excp_tlbrefill = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_num_r = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__ms_excp_r = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(150, vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__tlb_inst_bus_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__last_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__last_waddr = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__last_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__wbu_state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__tlbsrch_index_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__tlbsrch_found_r = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__invtlb_op_i_r = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__invtlb_asid_i_r = VL_RAND_RESET_I(10);
    vlSelf->__PVT__cpu__DOT__wbu__DOT__invtlb_vpn_i_r = VL_RAND_RESET_I(19);
    VL_ZERO_RESET_W(69, vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_hc22b4569__0);
    vlSelf->cpu__DOT__wbu__DOT____VdfgTmp_h82400683__0 = 0;
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__timer_64 = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__timer_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__crmd_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tlbehi_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tcfg_wen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_crmd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_prmd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_ecfg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_estat = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_era = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_eentry = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_badv = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbidx = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbehi = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbelo0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbelo1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_asid = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tlbrentry = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_dmw0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_dmw1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdl = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_pgdh = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tlbrd_valid_wr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__tlbrd_invalid_wr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_save3 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tid = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tcfg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_tval = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_ticlr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_llbctl = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s0_odd_page = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s0_ppn = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s1_odd_page = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__s1_ppn = VL_RAND_RESET_I(20);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__w_index = VL_RAND_RESET_I(5);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__w_e = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_g = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__r_e = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__inst_paddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__data_paddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_index = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_vppn[__Vi0] = VL_RAND_RESET_I(19);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_e[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_asid[__Vi0] = VL_RAND_RESET_I(10);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_g[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ps[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn0[__Vi0] = VL_RAND_RESET_I(20);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_plv0[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_mat0[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_d0[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_v0[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_ppn1[__Vi0] = VL_RAND_RESET_I(20);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_plv1[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_mat1[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_d1[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__tlb_v1[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s0_odd_page_buffer = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cpu__DOT__addr_trans_o__DOT__blt_o__DOT__s1_odd_page_buffer = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__one__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match0__DOT__two__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT____Vcellinp__one__in = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__one__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__addr_trans_o__DOT__blt_o__DOT__en_match1__DOT__two__DOT____Vcellinp__one__in = VL_RAND_RESET_I(4);
    vlSelf->__PVT__axi_ram__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__PVT__axi_ram__DOT__state1 = VL_RAND_RESET_I(4);
    vlSelf->__VdfgTmp_h152a734c__0 = 0;
    vlSelf->__VdfgTmp_h92ff612a__0 = 0;
    vlSelf->__VdfgTmp_hf491859d__0 = 0;
    vlSelf->__VdfgTmp_h8db76367__0 = 0;
    vlSelf->__VdfgTmp_h47e789ee__0 = 0;
    vlSelf->__VdfgTmp_he9aee5e6__0 = 0;
    vlSelf->__VdfgTmp_h22c40758__0 = 0;
    vlSelf->__VdfgTmp_he2db1349__0 = 0;
    vlSelf->__VdfgTmp_h009e5764__0 = 0;
    vlSelf->__VdfgTmp_hc2a96525__0 = 0;
    vlSelf->__VdfgTmp_h0bb51f1b__0 = 0;
    vlSelf->__VdfgTmp_hc7568c01__0 = 0;
    vlSelf->__VdfgTmp_h2279297c__0 = 0;
    vlSelf->__VdfgTmp_h55854117__0 = 0;
    vlSelf->__VdfgTmp_h2b38d13c__0 = 0;
    vlSelf->__VdfgTmp_h0c09fcc4__0 = 0;
    vlSelf->__VdfgTmp_h0c8f67c9__0 = 0;
    vlSelf->__VdfgTmp_h6f00e02f__0 = 0;
    vlSelf->__VdfgTmp_hf0004255__0 = 0;
    vlSelf->__VdfgTmp_h9e962040__0 = 0;
    vlSelf->__VdfgTmp_h8ed8f5cf__0 = 0;
    vlSelf->__VdfgTmp_h12ddb05b__0 = 0;
    vlSelf->__VdfgTmp_he53650ff__0 = 0;
    vlSelf->__VdfgTmp_h7103b3dc__0 = 0;
    vlSelf->__VdfgTmp_h83a26ffc__0 = 0;
    vlSelf->__VdfgTmp_hb229ee02__0 = 0;
    vlSelf->__VdfgTmp_h19e72309__0 = 0;
    vlSelf->__VdfgTmp_h5ea32404__0 = 0;
    vlSelf->__VdfgTmp_h4a1f33f6__0 = 0;
    vlSelf->__VdfgTmp_h9d2405b8__0 = 0;
    vlSelf->__VdfgTmp_ha0f52a79__0 = 0;
    vlSelf->__VdfgTmp_hfe3e0abc__0 = 0;
    vlSelf->__VdfgTmp_h93bf0917__0 = 0;
    vlSelf->__VdfgTmp_ha76d27d4__0 = 0;
    vlSelf->__VdfgTmp_h713b061a__0 = 0;
    vlSelf->__VdfgTmp_h059f3a5a__0 = 0;
    vlSelf->__VdfgTmp_h4bb6f19b__0 = 0;
    vlSelf->__VdfgTmp_h328b4211__0 = 0;
    vlSelf->__VdfgTmp_hded3e9aa__0 = 0;
    vlSelf->__VdfgTmp_h7ab2dec7__0 = 0;
    vlSelf->__VdfgTmp_h7fe385ba__0 = 0;
    vlSelf->__VdfgTmp_h0a6131bd__0 = 0;
    vlSelf->__VdfgTmp_h1ff363f5__0 = 0;
    vlSelf->__VdfgTmp_h44a86401__0 = 0;
    vlSelf->__VdfgTmp_hf99c2a8e__0 = 0;
    vlSelf->__VdfgTmp_h7b3f9024__0 = 0;
    vlSelf->__VdfgTmp_h52b193dd__0 = 0;
    vlSelf->__VdfgTmp_h0fd238d5__0 = 0;
    vlSelf->__VdfgTmp_h25039133__0 = 0;
    vlSelf->__VdfgTmp_heb094a5a__0 = 0;
    vlSelf->__VdfgTmp_hdc5aeeef__0 = 0;
    vlSelf->__VdfgTmp_hea9119cd__0 = 0;
    vlSelf->__VdfgTmp_he07c7f3b__0 = 0;
    vlSelf->__VdfgTmp_h045fbfd5__0 = 0;
    vlSelf->__VdfgTmp_hea5234c1__0 = 0;
    vlSelf->__VdfgTmp_h3d65e3d6__0 = 0;
    vlSelf->__VdfgTmp_h24244f83__0 = 0;
    vlSelf->__VdfgTmp_h84c4f938__0 = 0;
    vlSelf->__VdfgTmp_h379335bd__0 = 0;
    vlSelf->__VdfgTmp_h29af06bc__0 = 0;
    vlSelf->__VdfgTmp_hdea1d3a0__0 = 0;
    vlSelf->__VdfgTmp_h25a631c0__0 = 0;
    vlSelf->__VdfgTmp_h9b2c6fa7__0 = 0;
    vlSelf->__Vdly__cpu__DOT__o__DOT__inst_state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__cpu__DOT__o__DOT__inst_data_received = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__o__DOT__inst_read_data = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__cpu__DOT__o__DOT__handling_inst_request = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__o__DOT__data_state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__cpu__DOT__o__DOT__data_addr_accepted = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__ifu__DOT__ifu_state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cpu__DOT__ifu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__cpu__DOT__idu__DOT__idu_state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cpu__DOT__exu__DOT__exu_state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cpu__DOT__mem__DOT__mem_state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cpu__DOT__mem__DOT__es_excp_r = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__cpu__DOT__exu__DOT__wire_complete = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_arready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_rvalid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_rdata = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__wire_rid = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__wire_awready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_wready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wire_bvalid = VL_RAND_RESET_I(1);
}

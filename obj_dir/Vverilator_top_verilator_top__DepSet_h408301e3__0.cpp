// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top__Syms.h"
#include "Vverilator_top_verilator_top.h"

extern "C" int inst_ram_read(int addr);

VL_INLINE_OPT void Vverilator_top_verilator_top____Vdpiimwrap_inst_ram__DOT__inst_ram_read_TOP__verilator_top(IData/*31:0*/ addr, IData/*31:0*/ &inst_ram_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top____Vdpiimwrap_inst_ram__DOT__inst_ram_read_TOP__verilator_top\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int inst_ram_read__Vfuncrtn__Vcvt;
    inst_ram_read__Vfuncrtn__Vcvt = inst_ram_read(addr__Vcvt);
    inst_ram_read__Vfuncrtn = inst_ram_read__Vfuncrtn__Vcvt;
}

extern "C" int data_ram_read(int addr);

VL_INLINE_OPT void Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_read_TOP__verilator_top(IData/*31:0*/ addr, IData/*31:0*/ &data_ram_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_read_TOP__verilator_top\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int data_ram_read__Vfuncrtn__Vcvt;
    data_ram_read__Vfuncrtn__Vcvt = data_ram_read(addr__Vcvt);
    data_ram_read__Vfuncrtn = data_ram_read__Vfuncrtn__Vcvt;
}

extern "C" void data_ram_write(int addr, int wdata);

VL_INLINE_OPT void Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_write_TOP__verilator_top(IData/*31:0*/ addr, IData/*31:0*/ wdata) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_write_TOP__verilator_top\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    data_ram_write(addr__Vcvt, wdata__Vcvt);
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__0\n"); );
    // Init
    IData/*31:0*/ __Vfunc_inst_ram__DOT__inst_ram_read__0__Vfuncout;
    __Vfunc_inst_ram__DOT__inst_ram_read__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_data_ram__DOT__data_ram_read__2__Vfuncout;
    __Vfunc_data_ram__DOT__data_ram_read__2__Vfuncout = 0;
    CData/*4:0*/ __Vdlyvdim0__cpu__DOT__u_regfile__DOT__rf__v0;
    __Vdlyvdim0__cpu__DOT__u_regfile__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__u_regfile__DOT__rf__v0;
    __Vdlyvval__cpu__DOT__u_regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__u_regfile__DOT__rf__v0;
    __Vdlyvset__cpu__DOT__u_regfile__DOT__rf__v0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_hd50a5ef3__0;
    VlWide<5>/*159:0*/ __Vtemp_h7d71d9e8__0;
    VlWide<5>/*159:0*/ __Vtemp_hfa041f10__0;
    // Body
    if ((2U & ((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                 >> 7U)))) & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__es_valid)))))) {
        Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_write_TOP__verilator_top(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data, 
                                                                                ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                                << 0x19U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                                                                >> 7U)));
    }
    __Vdlyvset__cpu__DOT__u_regfile__DOT__rf__v0 = 0U;
    if (vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr) {
        __Vdlyvval__cpu__DOT__u_regfile__DOT__rf__v0 
            = vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U];
        __Vdlyvset__cpu__DOT__u_regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__u_regfile__DOT__rf__v0 
            = (0x1fU & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U]);
    }
    if (vlSymsp->TOP.rst) {
        vlSelf->__PVT__cpu__DOT__idu__DOT__is_load = 0U;
        vlSelf->__PVT__cpu__DOT__idu__DOT__ds_valid = 0U;
    } else {
        if (((IData)(vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_valid) 
             & (IData)(vlSelf->__PVT__cpu__DOT__idu_ds_allowin))) {
            vlSelf->__PVT__cpu__DOT__idu__DOT__is_load 
                = vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem;
        }
        if (vlSelf->__PVT__cpu__DOT__idu_ds_allowin) {
            vlSelf->__PVT__cpu__DOT__idu__DOT__ds_valid 
                = vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_valid;
        }
    }
    Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_read_TOP__verilator_top(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data, __Vfunc_data_ram__DOT__data_ram_read__2__Vfuncout);
    vlSelf->__PVT__cpu_data_rdata = __Vfunc_data_ram__DOT__data_ram_read__2__Vfuncout;
    vlSelf->__PVT__cpu__DOT__wbu__DOT__ws_valid = (
                                                   (~ (IData)(vlSymsp->TOP.rst)) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__ms_valid));
    if (__Vdlyvset__cpu__DOT__u_regfile__DOT__rf__v0) {
        vlSelf->__PVT__cpu__DOT__u_regfile__DOT__rf[__Vdlyvdim0__cpu__DOT__u_regfile__DOT__rf__v0] 
            = __Vdlyvval__cpu__DOT__u_regfile__DOT__rf__v0;
    }
    if (vlSelf->__PVT__cpu__DOT__mem__DOT__ms_valid) {
        vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data)) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[0U]))));
        vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U] 
            = (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data)) 
                         << 0x20U) | (QData)((IData)(
                                                     vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[0U]))) 
                       >> 0x20U));
        vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
            = (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_regWr) 
                << 5U) | (0x1fU & vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U]));
    }
    vlSelf->debug_wb_pc = vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[0U];
    vlSelf->debug_wb_rf_wnum = (0x1fU & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U]);
    vlSelf->debug_wb_rf_wdata = vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U];
    vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr = 
        ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
          >> 5U) & (IData)(vlSelf->__PVT__cpu__DOT__wbu__DOT__ws_valid));
    if (vlSelf->__PVT__cpu__DOT__exu__DOT__es_valid) {
        vlSelf->__PVT__cpu__DOT__mem__DOT__ms_valid 
            = (1U & (~ (IData)(vlSymsp->TOP.rst)));
        vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[0U] 
            = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
                        << 0x25U) | (0x1fffffffffULL 
                                     & (((QData)((IData)(
                                                         vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U]))))));
        vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
            = ((vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data 
                << 6U) | (IData)(((((QData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
                                    << 0x25U) | (0x1fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U]))))) 
                                  >> 0x20U)));
        vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
            = ((0x40U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U]) 
               | (vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data 
                  >> 0x1aU));
    } else {
        vlSelf->__PVT__cpu__DOT__mem__DOT__ms_valid = 0U;
    }
    vlSelf->debug_wb_rf_we = (0xfU & (- (IData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data = (
                                                   (0x40U 
                                                    & vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U])
                                                    ? vlSelf->__PVT__cpu_data_rdata
                                                    : 
                                                   ((vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                                     << 0x1aU) 
                                                    | (vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
                                                       >> 6U)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__mem_regWr = 
        ((vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
          >> 5U) & (IData)(vlSelf->__PVT__cpu__DOT__mem__DOT__ms_valid));
    if (((IData)(vlSelf->__PVT__cpu__DOT__idu_ds_to_es_valid) 
         & (IData)(vlSelf->__PVT__cpu__DOT__exe_es_allowin))) {
        __Vtemp_hd50a5ef3__0[0U] = (IData)((((QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem)) 
                                             << 0x26U) 
                                            | (((QData)((IData)(
                                                                ((0x15U 
                                                                  == 
                                                                  (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                   >> 0x1aU)) 
                                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                    | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w))))))))))))))))) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   ((0x15U 
                                                                     == 
                                                                     (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                      >> 0x1aU))
                                                                     ? 1U
                                                                     : 
                                                                    (0x1fU 
                                                                     & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg))))));
        __Vtemp_hd50a5ef3__0[1U] = ((vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData 
                                     << 7U) | (IData)(
                                                      ((((QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem)) 
                                                         << 0x26U) 
                                                        | (((QData)((IData)(
                                                                            ((0x15U 
                                                                              == 
                                                                              (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                               >> 0x1aU)) 
                                                                             | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w))))))))))))))))) 
                                                            << 0x25U) 
                                                           | (((QData)((IData)(
                                                                               ((0x15U 
                                                                                == 
                                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU))
                                                                                 ? 1U
                                                                                 : 
                                                                                (0x1fU 
                                                                                & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)))) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg))))) 
                                                       >> 0x20U)));
        __Vtemp_h7d71d9e8__0[3U] = (((IData)((((QData)((IData)(
                                                               ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                 ? vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg
                                                                 : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                   | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                      | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                              | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                                  ? 
                                                                 ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                   ? 4U
                                                                   : 
                                                                  ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                                    ? 
                                                                   (0xfffff000U 
                                                                    & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                       << 7U))
                                                                    : 
                                                                   (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x15U)))) 
                                                                     << 0xcU) 
                                                                    | (0xfffU 
                                                                       & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          >> 0xaU)))))
                                                                  : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData))))) 
                                     >> 0x18U) | ((IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                               ? vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg
                                                                               : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                                                ? 
                                                                               ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                                 ? 4U
                                                                                 : 
                                                                                ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                                                 ? 
                                                                                (0xfffff000U 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                << 7U))
                                                                                 : 
                                                                                (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x15U)))) 
                                                                                << 0xcU) 
                                                                                | (0xfffU 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU)))))
                                                                                : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData)))) 
                                                           >> 0x20U)) 
                                                  << 8U));
        __Vtemp_hfa041f10__0[4U] = ((0xffffff00U & 
                                     (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                       << 0x13U) | 
                                      (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                        << 0x12U) | 
                                       (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                         << 0x11U) 
                                        | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                            << 0x10U) 
                                           | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                               << 0xfU) 
                                              | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                  << 0xeU) 
                                                 | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                     << 0xdU) 
                                                    | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                        << 0xcU) 
                                                       | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                           << 0xbU) 
                                                          | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                              << 0xaU) 
                                                             | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                 << 9U) 
                                                                | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                    | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                       | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                          | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                             | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc))))) 
                                                                   << 8U))))))))))))) 
                                    | ((IData)(((((QData)((IData)(
                                                                  ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                    ? vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg
                                                                    : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                      | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                         | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                                | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                                     ? 
                                                                    ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                      ? 4U
                                                                      : 
                                                                     ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                                       ? 
                                                                      (0xfffff000U 
                                                                       & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          << 7U))
                                                                       : 
                                                                      (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x15U)))) 
                                                                        << 0xcU) 
                                                                       | (0xfffU 
                                                                          & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                             >> 0xaU)))))
                                                                     : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData)))) 
                                                >> 0x20U)) 
                                       >> 0x18U));
        vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U] 
            = __Vtemp_hd50a5ef3__0[0U];
        vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
            = __Vtemp_hd50a5ef3__0[1U];
        vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
            = (((IData)((((QData)((IData)(((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                            ? vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg
                                            : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                          << 0x20U) | (QData)((IData)(
                                                      ((((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                         | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                            | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                        | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                           | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                              | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                 | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                    | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                        ? 
                                                       ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                         ? 4U
                                                         : 
                                                        ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                          ? 
                                                         (0xfffff000U 
                                                          & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                             << 7U))
                                                          : 
                                                         (((- (IData)(
                                                                      (1U 
                                                                       & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          >> 0x15U)))) 
                                                           << 0xcU) 
                                                          | (0xfffU 
                                                             & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                >> 0xaU)))))
                                                        : vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData))))) 
                << 8U) | (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we) 
                           << 7U) | (vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData 
                                     >> 0x19U)));
        vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
            = __Vtemp_h7d71d9e8__0[3U];
        vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
            = __Vtemp_hfa041f10__0[4U];
    }
    if (((IData)(vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_valid) 
         & (IData)(vlSelf->__PVT__cpu__DOT__idu_ds_allowin))) {
        vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg = vlSelf->__PVT__cpu__DOT__ifu__DOT__pc;
        vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
            = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__br_taken)
                ? 0U : vlSelf->__PVT__cpu_inst_rdata);
    }
    if (vlSymsp->TOP.rst) {
        vlSelf->__PVT__cpu__DOT__exu__DOT__es_valid = 0U;
        vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_valid = 0U;
    } else {
        if (vlSelf->__PVT__cpu__DOT__exe_es_allowin) {
            vlSelf->__PVT__cpu__DOT__exu__DOT__es_valid 
                = vlSelf->__PVT__cpu__DOT__idu_ds_to_es_valid;
        }
        if (vlSelf->__PVT__cpu__DOT__ifu_fs_allowin) {
            vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_valid 
                = (1U & (~ (IData)(vlSymsp->TOP.rst)));
        }
    }
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result 
        = (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
             << 0x18U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                          >> 8U)) | ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                      << 0x18U) | (
                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                   >> 8U)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__exu_regWr = 
        ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
          >> 5U) & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__es_valid));
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin 
        = (IData)((0U != (0xe00U & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U])));
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b 
        = ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)
            ? (~ ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                   << 0x18U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                >> 8U))) : ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                             << 0x18U) 
                                            | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                               >> 8U)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result 
        = (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
             << 0x18U) | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                          >> 8U)) + (vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b 
                                     + (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)));
    Vverilator_top_verilator_top____Vdpiimwrap_inst_ram__DOT__inst_ram_read_TOP__verilator_top(
                                                                                ((IData)(vlSelf->__PVT__cpu__DOT__ifu_fs_allowin)
                                                                                 ? vlSelf->__PVT__cpu__DOT__preifu_next_pc
                                                                                 : vlSelf->__PVT__cpu__DOT__ifu__DOT__pc), __Vfunc_inst_ram__DOT__inst_ram_read__0__Vfuncout);
    vlSelf->__PVT__cpu_inst_rdata = __Vfunc_inst_ram__DOT__inst_ram_read__0__Vfuncout;
    vlSelf->__PVT__cpu__DOT__idu__DOT__res_from_mem 
        = (IData)((0x28800000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_lu12i_w 
        = (IData)((0x14000000U == (0xfe000000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_addi_w 
        = (IData)((0x2800000U == (0xffc00000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__src1_is_pc = 
        ((0x13U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                    >> 0x1aU)) | (0x15U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                            >> 0x1aU)));
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
    vlSelf->__PVT__cpu__DOT__idu__DOT__jirl_offs = 
        (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                            >> 0x19U)))) << 0x12U) 
         | (0x3fffcU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                        >> 8U)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0 
        = (IData)((0x400000U == (0xfff00000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h1c4a3e54__0 
        = ((0x15U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                      >> 0x1aU)) | (0x14U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                              >> 0x1aU)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0 
        = (IData)((0x100000U == (0xfff00000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we = (IData)(
                                                        (0x29800000U 
                                                         == 
                                                         (0xffc00000U 
                                                          & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h19962199__0 
        = ((0x16U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                      >> 0x1aU)) | (0x17U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                              >> 0x1aU)));
    vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h3372f28b__0 
        = ((0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                     >> 5U)) == (0x1fU & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U]));
    vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data = (
                                                   ((- (IData)((IData)(
                                                                       (0U 
                                                                        != 
                                                                        (0x300U 
                                                                         & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U]))))) 
                                                    & vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result) 
                                                   | ((1U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                         >> 0xaU)))) 
                                                          & (((~ 
                                                               (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                >> 7U)) 
                                                              & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                 >> 7U)) 
                                                             | ((~ 
                                                                 ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                   ^ 
                                                                   vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U]) 
                                                                  >> 7U)) 
                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result 
                                                                   >> 0x1fU))))) 
                                                      | ((1U 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                            >> 0xbU)))) 
                                                             & (~ (IData)(
                                                                          (1ULL 
                                                                           & (((QData)((IData)(
                                                                                ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                << 0x18U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                                >> 8U)))) 
                                                                               + 
                                                                               ((QData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b)) 
                                                                                + (QData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)))) 
                                                                              >> 0x20U)))))) 
                                                         | (((- (IData)(
                                                                        (1U 
                                                                         & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                            >> 0xcU)))) 
                                                             & (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                  << 0x18U) 
                                                                 | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                    >> 8U)) 
                                                                & ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                    << 0x18U) 
                                                                   | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                      >> 8U)))) 
                                                            | (((~ vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result) 
                                                                & (- (IData)(
                                                                             (1U 
                                                                              & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0xdU))))) 
                                                               | (((- (IData)(
                                                                              (1U 
                                                                               & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0xeU)))) 
                                                                   & vlSelf->__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result) 
                                                                  | (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0xfU)))) 
                                                                      & (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                           << 0x18U) 
                                                                          | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                             >> 8U)) 
                                                                         ^ 
                                                                         ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                           << 0x18U) 
                                                                          | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                             >> 8U)))) 
                                                                     | (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0x13U)))) 
                                                                         & ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                             << 0x18U) 
                                                                            | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                               >> 8U))) 
                                                                        | (((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                >> 0x10U)))) 
                                                                            & (((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                << 0x18U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                                >> 8U)) 
                                                                               << 
                                                                               (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                                >> 8U)))) 
                                                                           | ((- (IData)((IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x60000U 
                                                                                & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U]))))) 
                                                                              & (IData)(
                                                                                ((((QData)((IData)(
                                                                                (- (IData)((IData)(
                                                                                (0x40080U 
                                                                                == 
                                                                                (0x40080U 
                                                                                & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U]))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                                << 0x18U) 
                                                                                | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                                >> 8U))))) 
                                                                                >> 
                                                                                (0x1fU 
                                                                                & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                                >> 8U))))))))))))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srai_w 
        = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0) 
           & (0x88000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_srli_w 
        = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0) 
           & (0x48000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slli_w 
        = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0) 
           & (0x8000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_xor = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
                                                   & (0x58000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_or = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
                                                  & (0x50000U 
                                                     == 
                                                     (0xf8000U 
                                                      & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_nor = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
                                                   & (0x40000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_and = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
                                                   & (0x48000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sltu = 
        ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
         & (0x28000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_slt = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
                                                   & (0x20000U 
                                                      == 
                                                      (0xf8000U 
                                                       & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sub_w = 
        ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
         & (0x10000U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__inst_add_w = 
        ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0) 
         & (0U == (0xf8000U & vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)));
    vlSelf->__PVT__cpu__DOT__idu_rf_raddr2 = (0x1fU 
                                              & (((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                                                  | (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_we))
                                                  ? vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg
                                                  : 
                                                 (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                  >> 0xaU)));
    vlSelf->__PVT__cpu__DOT__idu__DOT__ds_ready_go 
        = ((~ ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__is_load) 
               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_regWr) 
                  & ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h3372f28b__0) 
                     & (0U != (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 5U))))))) 
           & (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__ds_valid));
    vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
        = (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_regWr) 
            & (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h3372f28b__0))
            ? vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data
            : (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_regWr) 
                & ((0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                             >> 5U)) == (0x1fU & vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U])))
                ? vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data
                : (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr) 
                    & ((0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                 >> 5U)) == (0x1fU 
                                             & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])))
                    ? vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U]
                    : ((0U == (0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 5U))) ? 0U
                        : vlSelf->__PVT__cpu__DOT__u_regfile__DOT__rf
                       [(0x1fU & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                  >> 5U))]))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData 
        = (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_regWr) 
            & ((IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2) 
               == (0x1fU & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])))
            ? vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data
            : (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__mem_regWr) 
                & ((IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2) 
                   == (0x1fU & vlSelf->__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U])))
                ? vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data
                : (((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__wbu_regWr) 
                    & ((IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2) 
                       == (0x1fU & vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])))
                    ? vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U]
                    : ((0U == (IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2))
                        ? 0U : vlSelf->__PVT__cpu__DOT__u_regfile__DOT__rf
                       [vlSelf->__PVT__cpu__DOT__idu_rf_raddr2]))));
    vlSelf->__PVT__cpu__DOT__idu_ds_to_es_valid = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__ds_valid) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__ds_ready_go));
    vlSelf->__PVT__cpu__DOT__idu_ds_allowin = (1U & 
                                               ((~ (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__ds_valid)) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__ds_ready_go) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__exe_es_allowin))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__rj_eq_rd = (vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                                                   == vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData);
    vlSelf->__PVT__cpu__DOT__idu__DOT__br_taken = (
                                                   (((0x16U 
                                                      == 
                                                      (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                       >> 0x1aU)) 
                                                     & (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__rj_eq_rd)) 
                                                    | (((~ (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__rj_eq_rd)) 
                                                        & (0x17U 
                                                           == 
                                                           (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                            >> 0x1aU))) 
                                                       | ((0x13U 
                                                           == 
                                                           (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                            >> 0x1aU)) 
                                                          | (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h1c4a3e54__0)))) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__ds_valid));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__1(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__1\n"); );
    // Body
    if (vlSymsp->TOP.rst) {
        vlSelf->__PVT__cpu__DOT__ifu__DOT__pc = 0x1bfffffcU;
    } else if (((~ (IData)(vlSymsp->TOP.rst)) & (IData)(vlSelf->__PVT__cpu__DOT__ifu_fs_allowin))) {
        vlSelf->__PVT__cpu__DOT__ifu__DOT__pc = vlSelf->__PVT__cpu__DOT__preifu_next_pc;
    }
}

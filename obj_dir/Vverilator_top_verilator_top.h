// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vverilator_top.h for the primary calling header

#ifndef VERILATED_VVERILATOR_TOP_VERILATOR_TOP_H_
#define VERILATED_VVERILATOR_TOP_VERILATOR_TOP_H_  // guard

#include "verilated.h"

class Vverilator_top__Syms;

class Vverilator_top_verilator_top final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*3:0*/ debug_wb_rf_we;
        CData/*4:0*/ debug_wb_rf_wnum;
        CData/*0:0*/ __PVT__data_sram_en;
        CData/*0:0*/ __PVT__data_sram_we;
        CData/*0:0*/ __PVT__cpu__DOT__ifu_fs_allowin;
        CData/*4:0*/ __PVT__cpu__DOT__idu_rf_raddr2;
        CData/*0:0*/ __PVT__cpu__DOT__idu_ds_allowin;
        CData/*0:0*/ __PVT__cpu__DOT__idu_ds_to_es_valid;
        CData/*0:0*/ __PVT__cpu__DOT__exu_regWr;
        CData/*4:0*/ __PVT__cpu__DOT__exu_regAddr;
        CData/*0:0*/ __PVT__cpu__DOT__exe_es_allowin;
        CData/*0:0*/ __PVT__cpu__DOT__mem_regWr;
        CData/*4:0*/ __PVT__cpu__DOT__mem_regAddr;
        CData/*0:0*/ __PVT__cpu__DOT__wbu_regWr;
        CData/*4:0*/ __PVT__cpu__DOT__wbu_regAddr;
        CData/*0:0*/ __PVT__cpu__DOT__ifu__DOT__fs_valid;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__mem_regWr;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__wbu_regWr;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__mem_we;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__res_from_mem;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__br_taken;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__src1_is_pc;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__rj_eq_rd;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_add_w;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_sub_w;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_slt;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_sltu;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_nor;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_and;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_or;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_xor;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_slli_w;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_srli_w;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_srai_w;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_addi_w;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__inst_lu12i_w;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__is_load;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__ds_valid;
        CData/*0:0*/ __PVT__cpu__DOT__idu__DOT__ds_ready_go;
        CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h1c4a3e54__0;
        CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h19962199__0;
        CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h3372f28b__0;
        CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h78773bd0__0;
        CData/*0:0*/ cpu__DOT__idu__DOT____VdfgTmp_h7517b185__0;
        CData/*0:0*/ __PVT__cpu__DOT__exu__DOT__exu_regWr;
        CData/*0:0*/ __PVT__cpu__DOT__exu__DOT__es_valid;
        CData/*0:0*/ __PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin;
        CData/*0:0*/ __PVT__cpu__DOT__mem__DOT__ms_valid;
        CData/*0:0*/ __PVT__cpu__DOT__wbu__DOT__ws_valid;
        SData/*15:0*/ __PVT__cpu__DOT__idu__DOT__op_25_22_d;
        IData/*31:0*/ __PVT__cpu_inst_rdata;
        IData/*31:0*/ __PVT__cpu_data_rdata;
        IData/*31:0*/ debug_wb_pc;
        IData/*31:0*/ debug_wb_rf_wdata;
        IData/*31:0*/ __PVT__data_sram_addr;
        IData/*31:0*/ __PVT__data_sram_wdata;
        IData/*31:0*/ __PVT__data_sram_rdata;
        IData/*31:0*/ __PVT__cpu__DOT__preifu_next_pc;
        IData/*31:0*/ __PVT__cpu__DOT__exu_data;
        IData/*31:0*/ __PVT__cpu__DOT__mem_data;
        IData/*31:0*/ __PVT__cpu__DOT__wbu_data;
        IData/*31:0*/ __PVT__cpu__DOT__ifu__DOT__pc;
    };
    struct {
        IData/*31:0*/ __PVT__cpu__DOT__ifu__DOT__inst_ram_data_reg;
        IData/*31:0*/ __PVT__cpu__DOT__idu__DOT__mem_data;
        IData/*31:0*/ __PVT__cpu__DOT__idu__DOT__jirl_offs;
        IData/*31:0*/ __PVT__cpu__DOT__idu__DOT__op_19_15_d;
        IData/*31:0*/ __PVT__cpu__DOT__idu__DOT__conflict_regaData;
        IData/*31:0*/ __PVT__cpu__DOT__idu__DOT__conflict_regbData;
        IData/*31:0*/ __PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg;
        IData/*31:0*/ __PVT__cpu__DOT__idu__DOT__pc_reg;
        IData/*31:0*/ __PVT__cpu__DOT__exu__DOT__exu_data;
        VlWide<5>/*147:0*/ __PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r;
        IData/*31:0*/ __PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result;
        IData/*31:0*/ __PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result;
        IData/*31:0*/ __PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b;
        VlWide<3>/*70:0*/ __PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r;
        VlWide<3>/*69:0*/ __PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r;
        QData/*63:0*/ __PVT__cpu__DOT__idu__DOT__op_31_26_d;
        VlUnpacked<IData/*31:0*/, 32> __PVT__cpu__DOT__u_regfile__DOT__rf;
    };

    // INTERNAL VARIABLES
    Vverilator_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vverilator_top_verilator_top(Vverilator_top__Syms* symsp, const char* v__name);
    ~Vverilator_top_verilator_top();
    VL_UNCOPYABLE(Vverilator_top_verilator_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

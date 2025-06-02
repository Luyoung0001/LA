// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vverilator_top__Syms.h"
#include "Vverilator_top.h"
#include "Vverilator_top___024root.h"
#include "Vverilator_top_verilator_top.h"
#include "Vverilator_top_WallaceTree32X32.h"

// FUNCTIONS
Vverilator_top__Syms::~Vverilator_top__Syms()
{
}

Vverilator_top__Syms::Vverilator_top__Syms(VerilatedContext* contextp, const char* namep, Vverilator_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__verilator_top{this, Verilated::catName(namep, "verilator_top")}
    , TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace{this, Verilated::catName(namep, "verilator_top.cpu.exu.mul.o.o1.wallace")}
    , TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace{this, Verilated::catName(namep, "verilator_top.cpu.exu.mul.o.o.wallace")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.verilator_top = &TOP__verilator_top;
    TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace = &TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace;
    TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace = &TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__verilator_top.__Vconfigure(true);
    TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__Vconfigure(true);
    TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__Vconfigure(false);
    // Setup scopes
    __Vscope_verilator_top.configure(this, name(), "verilator_top", "verilator_top", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_asid_diff", &(TOP__verilator_top.csr_asid_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_badv_diff", &(TOP__verilator_top.csr_badv_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_crmd_diff", &(TOP__verilator_top.csr_crmd_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_dmw0_diff", &(TOP__verilator_top.csr_dmw0_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_dmw1_diff", &(TOP__verilator_top.csr_dmw1_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_ecfg_diff", &(TOP__verilator_top.csr_ecfg_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_eentry_diff", &(TOP__verilator_top.csr_eentry_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_era_diff", &(TOP__verilator_top.csr_era_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_estat_diff", &(TOP__verilator_top.csr_estat_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_llbctl_diff", &(TOP__verilator_top.csr_llbctl_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_pgdh_diff", &(TOP__verilator_top.csr_pgdh_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_pgdl_diff", &(TOP__verilator_top.csr_pgdl_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_prmd_diff", &(TOP__verilator_top.csr_prmd_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_save0_diff", &(TOP__verilator_top.csr_save0_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_save1_diff", &(TOP__verilator_top.csr_save1_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_save2_diff", &(TOP__verilator_top.csr_save2_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_save3_diff", &(TOP__verilator_top.csr_save3_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tcfg_diff", &(TOP__verilator_top.csr_tcfg_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_ticlr_diff", &(TOP__verilator_top.csr_ticlr_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tid_diff", &(TOP__verilator_top.csr_tid_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tlbehi_diff", &(TOP__verilator_top.csr_tlbehi_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tlbelo0_diff", &(TOP__verilator_top.csr_tlbelo0_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tlbelo1_diff", &(TOP__verilator_top.csr_tlbelo1_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tlbidx_diff", &(TOP__verilator_top.csr_tlbidx_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tlbrentry_diff", &(TOP__verilator_top.csr_tlbrentry_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"csr_tval_diff", &(TOP__verilator_top.csr_tval_diff), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_inst", &(TOP__verilator_top.debug_wb_inst), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_pc", &(TOP__verilator_top.debug_wb_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_rf_wdata", &(TOP__verilator_top.debug_wb_rf_wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_rf_we", &(TOP__verilator_top.debug_wb_rf_we), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_rf_wnum", &(TOP__verilator_top.debug_wb_rf_wnum), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
    }
}

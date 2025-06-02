// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_BoothInterBase.h"
#include "Vverilator_top__Syms.h"

void Vverilator_top_BoothInterBase___ctor_var_reset(Vverilator_top_BoothInterBase* vlSelf);

Vverilator_top_BoothInterBase::Vverilator_top_BoothInterBase(Vverilator_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vverilator_top_BoothInterBase___ctor_var_reset(this);
}

void Vverilator_top_BoothInterBase::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vverilator_top_BoothInterBase::~Vverilator_top_BoothInterBase() {
}

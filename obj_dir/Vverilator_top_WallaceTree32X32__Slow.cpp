// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_WallaceTree32X32.h"
#include "Vverilator_top__Syms.h"

void Vverilator_top_WallaceTree32X32___ctor_var_reset(Vverilator_top_WallaceTree32X32* vlSelf);

Vverilator_top_WallaceTree32X32::Vverilator_top_WallaceTree32X32(Vverilator_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vverilator_top_WallaceTree32X32___ctor_var_reset(this);
}

void Vverilator_top_WallaceTree32X32::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vverilator_top_WallaceTree32X32::~Vverilator_top_WallaceTree32X32() {
}

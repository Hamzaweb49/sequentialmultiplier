// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vseqmul.h for the primary calling header

#include "Vseqmul.h"
#include "Vseqmul__Syms.h"

//==========

VL_CTOR_IMP(Vseqmul) {
    Vseqmul__Syms* __restrict vlSymsp = __VlSymsp = new Vseqmul__Syms(this, name());
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vseqmul::__Vconfigure(Vseqmul__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vseqmul::~Vseqmul() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vseqmul::_settle__TOP__5(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_settle__TOP__5\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->product = (((IData)(vlTOPp->Datapath__DOT__shift_accumulator) 
                        << 0x10U) | (IData)(vlTOPp->Datapath__DOT__shift_multiplier));
    vlTOPp->Datapath__DOT__mux_output = ((IData)(vlTOPp->Datapath__02Emux_signal)
                                          ? (IData)(vlTOPp->multiplicand)
                                          : 0U);
}

void Vseqmul::_eval_initial(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval_initial\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__Datapath__02Ereset = vlTOPp->Datapath__02Ereset;
    vlTOPp->__Vclklast__TOP__Datapath__02Eclk = vlTOPp->Datapath__02Eclk;
    vlTOPp->__Vclklast__TOP__Controller__02Eclk = vlTOPp->Controller__02Eclk;
    vlTOPp->__Vclklast__TOP__Controller__02Ereset = vlTOPp->Controller__02Ereset;
}

void Vseqmul::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::final\n"); );
    // Variables
    Vseqmul__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vseqmul::_eval_settle(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval_settle\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

void Vseqmul::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_ctor_var_reset\n"); );
    // Body
    Controller__02Eclk = VL_RAND_RESET_I(1);
    Controller__02Ereset = VL_RAND_RESET_I(1);
    Controller__02Estart = VL_RAND_RESET_I(1);
    Controller__02Emultiplier = VL_RAND_RESET_I(16);
    Controller__02Eadd_signal = VL_RAND_RESET_I(1);
    Controller__02Eshift_signal = VL_RAND_RESET_I(1);
    Controller__02Emux_signal = VL_RAND_RESET_I(1);
    Datapath__02Eclk = VL_RAND_RESET_I(1);
    Datapath__02Ereset = VL_RAND_RESET_I(1);
    Datapath__02Estart = VL_RAND_RESET_I(1);
    Datapath__02Eadd_signal = VL_RAND_RESET_I(1);
    Datapath__02Eshift_signal = VL_RAND_RESET_I(1);
    Datapath__02Emux_signal = VL_RAND_RESET_I(1);
    multiplicand = VL_RAND_RESET_I(16);
    accumulator = VL_RAND_RESET_I(16);
    Datapath__02Emultiplier = VL_RAND_RESET_I(16);
    product = VL_RAND_RESET_I(32);
    Controller__DOT__state = VL_RAND_RESET_I(2);
    Controller__DOT__count = VL_RAND_RESET_I(4);
    Datapath__DOT__shift_accumulator = VL_RAND_RESET_I(16);
    Datapath__DOT__mux_output = VL_RAND_RESET_I(16);
    Datapath__DOT__intermediate_accumulator = VL_RAND_RESET_I(16);
    Datapath__DOT__shift_multiplier = VL_RAND_RESET_I(16);
    Datapath__DOT__carryin = VL_RAND_RESET_I(1);
    Datapath__DOT__carryout = VL_RAND_RESET_I(1);
    Datapath__DOT__shiftcarry = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}

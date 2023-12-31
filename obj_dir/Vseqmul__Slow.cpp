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

void Vseqmul::_settle__TOP__3(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_settle__TOP__3\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->product = (((IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator) 
                        << 0x10U) | (IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier));
    vlTOPp->mux_signal = vlTOPp->TopModule__DOT__mux_signal_int;
    vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output 
        = ((IData)(vlTOPp->TopModule__DOT__mux_signal_int)
            ? (IData)(vlTOPp->multiplicand) : 0U);
    if (vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done) {
        vlTOPp->TopModule__DOT__top_multiplier = vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier;
    } else {
        if ((1U & (~ (IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done)))) {
            vlTOPp->TopModule__DOT__top_multiplier 
                = vlTOPp->multiplier;
        }
    }
    if (vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done) {
        vlTOPp->TopModule__DOT__top_accumulator = vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator;
    } else {
        if ((1U & (~ (IData)(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done)))) {
            vlTOPp->TopModule__DOT__top_accumulator 
                = vlTOPp->accumulator;
        }
    }
    vlTOPp->shift_signal = vlTOPp->TopModule__DOT__shift_signal_int;
    vlTOPp->add_signal = vlTOPp->TopModule__DOT__add_signal_int;
}

void Vseqmul::_eval_initial(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval_initial\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
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
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vseqmul::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    start = VL_RAND_RESET_I(1);
    multiplier = VL_RAND_RESET_I(16);
    multiplicand = VL_RAND_RESET_I(16);
    accumulator = VL_RAND_RESET_I(16);
    add_signal = VL_RAND_RESET_I(1);
    shift_signal = VL_RAND_RESET_I(1);
    mux_signal = VL_RAND_RESET_I(1);
    product = VL_RAND_RESET_I(32);
    TopModule__DOT__add_signal_int = VL_RAND_RESET_I(1);
    TopModule__DOT__shift_signal_int = VL_RAND_RESET_I(1);
    TopModule__DOT__mux_signal_int = VL_RAND_RESET_I(1);
    TopModule__DOT__top_multiplier = VL_RAND_RESET_I(16);
    TopModule__DOT__top_accumulator = VL_RAND_RESET_I(16);
    TopModule__DOT__dp_inst__DOT__shift_accumulator = VL_RAND_RESET_I(16);
    TopModule__DOT__dp_inst__DOT__mux_output = VL_RAND_RESET_I(16);
    TopModule__DOT__dp_inst__DOT__intermediate_accumulator = VL_RAND_RESET_I(16);
    TopModule__DOT__dp_inst__DOT__shift_multiplier = VL_RAND_RESET_I(16);
    TopModule__DOT__dp_inst__DOT__carryin = VL_RAND_RESET_I(1);
    TopModule__DOT__dp_inst__DOT__carryout = VL_RAND_RESET_I(1);
    TopModule__DOT__dp_inst__DOT__shiftcarry = VL_RAND_RESET_I(1);
    TopModule__DOT__dp_inst__DOT__shift_done = VL_RAND_RESET_I(1);
    TopModule__DOT__ctrl_inst__DOT__state = VL_RAND_RESET_I(2);
    TopModule__DOT__ctrl_inst__DOT__count = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
